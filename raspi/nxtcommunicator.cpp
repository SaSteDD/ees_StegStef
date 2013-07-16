#include "nxtcommunicator.h"
#include <QDebug>
#include <QFile>
#include <QCoreApplication>
#include <QMessageBox>

namespace btCom {
    #include "btCom.h"
}

const int NxtCommunicator::waitTimeMs=50;

const QStringList NxtCommunicator::graphicalSudoCommands({"/usr/bin/kdesudo", "/usr/bin/gksu"});

NxtCommunicator::NxtCommunicator(QObject *parent) :
    QObject(parent),
    rfCommProcess(this),
    isRunning(false),
    sendNxtPauseChar(false),
    writeTask(false),
    timer(),
    task(),
    stationSetup()
{
    connect(&rfCommProcess,SIGNAL(readyReadStandardError()),this,SLOT(rfcommProcReadStdErr()));
    connect(&rfCommProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(rfcommProcReadStdOut()));
    connect(&rfCommProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(rfcommDeviceClosed(int,QProcess::ExitStatus)));

    timer.setInterval(waitTimeMs);
    timer.setSingleShot(true);
    connect(&timer,SIGNAL(timeout()),this,SLOT(mainCommunicationLoop()));
}

void NxtCommunicator::openConnection(Types::BtDevice device)
{
    if(rfCommProcess.state() == QProcess::Running)
    {
        emit appLogMessage(trUtf8("Kann keine neue rfcomm-Verbindung aufbauen, da alte noch läuft."));
        return;
    }

    QString suCmd=getGraphicalSudoCommand();
    if(suCmd.isEmpty())
    {
        emit appLogMessage(trUtf8("Kann rfcomm nicht starten, da keine Möglichkeit besteht root-Rechte zu bekommen."));
        return;
    }

    QStringList args;
    args <<  "/usr/bin/rfcomm" << "connect" <<  "rfcomm0" << device.mac << "1";
    rfCommProcess.start(suCmd, args);
    isRunning=true;
    emit appLogMessage(trUtf8("rfcomm-Befehl gestartet für Gerät: ")  + device.name + " (" + device.mac + ")");

    tryBtConnect();
}

void NxtCommunicator::rfcommDeviceClosed(int,QProcess::ExitStatus)
{
    emit appLogMessage("RFCOMM-Verbindung geschlossen");
    closeConnection();
}


QString NxtCommunicator::readDataFromProc()
{
    QString data;
    while(rfCommProcess.canReadLine())
    {
        data.append(QString::fromUtf8(rfCommProcess.readLine()));
    }
    return data;
}

void NxtCommunicator::rfcommProcReadStdOut()
{
    rfCommProcess.setReadChannel(QProcess::StandardOutput);
    QString read=readDataFromProc();
    if(read.isEmpty()) return;
    emit appLogMessage("rfcomm-Befehl: " + read);
}

void NxtCommunicator::rfcommProcReadStdErr()
{
    rfCommProcess.setReadChannel(QProcess::StandardError);
    QString read=readDataFromProc();
    if(read.isEmpty()) return;
    emit appLogMessage("rfcomm-Befehl Fehler: " + read);
}

void NxtCommunicator::closeConnection()
{
    isRunning=false;
    timer.stop();
    btCom::btDisconnect();
    rfcommProcReadStdOut();
    rfcommProcReadStdErr();
    rfCommProcess.close();
    emit appLogMessage("rfcomm Prozess geschlossen.");
    emit connectionClosed();
    emit connectionStateChanged(false);
}

QString NxtCommunicator::getGraphicalSudoCommand()
{
    QString cmd("");
    foreach (QString sCmd , graphicalSudoCommands) {
        if(QFile(sCmd).exists())
        {
            cmd=sCmd;
            break;
        }
    }

    return cmd;
}

void NxtCommunicator::tryBtConnect()
{
    bool erg= btCom::btConnect();
    if(!erg && rfCommProcess.state() != QProcess::NotRunning)
    {
        QTimer::singleShot(waitTimeMs,this,SLOT(tryBtConnect()));
    } else if (rfCommProcess.state() == QProcess::NotRunning){
        closeConnection();
    } else {
        emit connectionStateChanged(true);
        emit connectionOpened();
        emit appLogMessage(trUtf8("Serielle Schnittstelle geöffnet."));
        QTimer::singleShot(1000,this,SLOT(mainCommunicationLoop())); //we need to wait a little before we read, after we open the device
    }
}

bool NxtCommunicator::readChar(char *ch)
{
    return readChars(ch,1);
}

bool NxtCommunicator::readChars(char *ch, int len)
{
    int read=btCom::btReadBytes(ch,len);
    if(read==len)
    {
        return true;
    } else if(read < 0) {
        closeConnection();
    }
    return false;
}

void NxtCommunicator::mainCommunicationLoop()
{
    if(isRunning)
    {
            /*
             *Do we want to abort?
             */
            if(sendNxtPauseChar)
            {
                sendNxtPauseChar=!sendChar('a', "Pause/Weiter");
            }

            if(writeTask)
            {
                writeTaskData();
                writeTask=false;
            }

            /*
             *the first char we read will tell us what we need to do
             */
            char b=0;
            if(readChar(&b))
            {
                if(b=='s'){
                    readStateData();
                } else if(b=='q') {
                    sendStationData();
                } else if(b=='f') {
                    runTaskFinished(false);
                } else if(b=='F') {
                    runTaskFinished(true);
                } else {
                    emit nxtLogMessage(chToHexString(b) + " (Fehler. Zeichen kann an dieser Stelle im Programmablauf nicht ausgewertet werden)");
                }
            }

        timer.start();
    }
}

void NxtCommunicator::sendTaskData(const Types::Task &task, const Types::StationSetup &stations)
{
    this->task=task;
    this->stationSetup=stations;
    writeTask=true;
}

void NxtCommunicator::sendStationData()
{// TODO errors not handled, we expect the nxt to request a resend
    char num;
    if(readChar( &num)) //char read?
    {
        emit nxtLogMessage(QString("q" + chToHexString(num) + trUtf8(" ( Qualitätsanfrage)")));
            char stationQualityData[3];
            stationQualityData[0]='q';

            switch (static_cast<int>(num)) {// we expect 1-4
            case 1:
                stationQualityData[1]=stationSetup.station1.type;
                stationQualityData[2]=stationSetup.station1.quality;
                 break;
            case 2:
                stationQualityData[1]=stationSetup.station2.type;
                stationQualityData[2]=stationSetup.station2.quality;
                 break;
            case 3:
                stationQualityData[1]=stationSetup.station3.type;
                stationQualityData[2]=stationSetup.station3.quality;
                 break;
            case 4:
                stationQualityData[1]=stationSetup.station4.type;
                stationQualityData[2]=stationSetup.station4.quality;
                 break;
            default:
                return;
            }

            //send Data
            if(btCom::btWriteBytes(stationQualityData,3)<0)
            {
                closeConnection();
            } else {
                emit raspiLogMessage(trUtf8("Qualitätsparameter gesendet: ") + QString(stationQualityData[0]) + chToHexString(stationQualityData[1]) + chToHexString(stationQualityData[2])  );
            }
    }
}

void NxtCommunicator::dummySlot()
{

}

void NxtCommunicator::runTaskFinished(bool success)
{
    QMessageBox msgBox;

    emit taskFinished(success);
    if(success){
        emit nxtLogMessage("F (Auftrag erfolgreich bearbeitet)");
        msgBox.setText( "Der Auftrag wurde erfolgreich bearbeitet.");
    } else {
        emit nxtLogMessage("f (Auftragsbearbeitung fehlgeschlagen)");
        msgBox.setText( "Die Auftragsbearbeitung ist fehlgeschlagen.");
    }

    msgBox.open(this,SLOT(dummySlot()));
}

void NxtCommunicator::readStateData()
{
  Types::NxtState state;

  char st[5]={};

  if(readChars(st,5))
  {
      if(st[0]<= Types::unknown){
          state.section=static_cast<Types::TrackSection>(st[0]);

          state.stepNum.byte0=st[1];
          state.stepNum.byte1=st[2];
          state.stepNum.byte2=st[3];
          state.stepNum.byte3=st[4];

      emit nxtStateChanged(state);
          emit nxtLogMessage(QString("s (NXT-Status): " + chToHexString(st[0])
              + chToHexString(st[1])
              + chToHexString(st[2])
              + chToHexString(st[3])
              + chToHexString(st[4])
              + " (" + QString::number(state.stepNum.num) + ")"));
      } else {
          nxtLogMessage(trUtf8("Statuswert für NXT ist falsch: ") + chToHexString(st[0]));
          state.section=Types::unknown;
          state.stepNum.num=0;
          emit nxtStateChanged(state);
      }
  } else {
      emit nxtLogMessage(trUtf8("Fehler beim lesen des NXT Status."));
  }

}

bool NxtCommunicator::sendChar(char ch , QString str)
{
    int res=btCom::btWriteBytes(&ch,1);
    if(res == 1) {
        emit raspiLogMessage(ch + " (" + str + ")");
        sendNxtPauseChar=false;
        return true;
    } else if( res < 0) {
        closeConnection();
    }
    return false;
}

QString NxtCommunicator::chToHexString(const char ch)
{
    return " 0x" + QString::number(ch,16).rightJustified(2,'0');
}

void NxtCommunicator::writeTaskData()
{
    if(isRunning)
    {
        Types::StepNumType stepNum;
        stepNum.num=task.steps.size();

        char taskData[6+3*task.steps.size()];

        taskData[0]='t';
        taskData[1]=static_cast<u_int8_t>(task.taskNumber);
        taskData[2]=stepNum.byte0;
        taskData[3]=stepNum.byte1;
        taskData[4]=stepNum.byte2;
        taskData[5]=stepNum.byte3;

        QString logMessage= taskData[0]  + chToHexString(taskData[1])
                               + chToHexString(taskData[2])
                               + chToHexString(taskData[3])
                               + chToHexString(taskData[4])
                               + chToHexString(taskData[5]);


        taskData[sizeof(taskData)-1]='T';
        
        for(int i=0; i<task.steps.size(); i++)
        {
            //Type
            taskData[6+i*3]= static_cast<u_int8_t>(task.steps.at(i).type);
            //Quality
            taskData[6+i*3+1]=static_cast<u_int8_t>(task.steps.at(i).quality);
            //Time
            taskData[6+i*3+2]=static_cast<u_int8_t>(task.steps.at(i).time);

            logMessage= logMessage + "\n" + chToHexString(taskData[6+i*3])
                                   + chToHexString(taskData[6+i*3+1])
                                   + chToHexString(taskData[6+i*3+2]);
        }

        if(btCom::btWriteBytes(taskData,sizeof(taskData))<0)
        {
            closeConnection();
        } else {
            emit raspiLogMessage(trUtf8("Task:\n") + logMessage);
        }
    }
}

void NxtCommunicator::sendNxtPauseResume()
{
    if(isRunning)
    {
        sendNxtPauseChar=true;
    }
}
