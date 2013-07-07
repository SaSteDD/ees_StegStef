#ifndef NXTCOMMUNICATOR_H
#define NXTCOMMUNICATOR_H

#include <QObject>
#include <QProcess>
#include "types.h"
#include <QTimer>
#include <QPair>

class NxtCommunicator : public QObject
{
    Q_OBJECT
public:
     explicit NxtCommunicator(QObject *parent = 0);
    void openConnection(Types::BtDevice device);


signals:
    void appLogMessage(QString);
    void nxtLogMessage(QString);
    void raspiLogMessage(QString);

    void nxtStateChanged(Types::NxtState);

    /*
     *true on success
     *false on error
     */
    void taskFinished(bool);

    void connectionClosed();
    void connectionOpened();

    /*
     *true on connect
     *false on disconnect
     */
    void connectionStateChanged(bool);
public slots:
    /*
     *The abort-character will be sent the next the main Communication loop is executed
     */
    void sendNxtPauseResume();

    /*
     *Sends Task Data
     */
    void sendTaskData(const Types::Task& task, const Types::StationSetup& stationSetup);

    void closeConnection();
private slots:
    void rfcommDeviceClosed(int,QProcess::ExitStatus);
    void rfcommProcReadStdErr();
    void rfcommProcReadStdOut();
    void tryBtConnect();
    void mainCommunicationLoop();

private:
    static inline QString chToHexString(const char ch);
    QString getGraphicalSudoCommand();
    QString readDataFromProc();
    void runTaskFinished(bool success);

    /*
     *returns true on success
     */
    bool readChar(char* ch);
    //only returns true if exactly len chars could be read
    bool readChars(char *ch, int len);


    /*
     *returns true on success
     */
    bool sendChar(QPair<char, QString>);

    /*
     *Read State Data NXT sends
     *Format for NXT-Message:
     *      [StateChar]  [state (0-15)] [  StepNr   ]
     *Nr:        1              2          3 4 5 6
     */
    void readStateData();

    /*
     *Format: (we expect sizeof(int) to be 4 -> 32bit integers
     *     t [Nr] [Steps n(u_int16_t lttle endian)] {[Type (0-2)][Quality (0-3)][time (3-20)]}*n
     *BNr: 1  2      3 4 5 6                            i*3+7         i*3+8        i*3+9
     *Example:
     * t  0x02 0x0002 0x01 0x04 0xA0   0x00  0x03 0x09   T
     *    (Nr) (Steps)  (Ty) (Qu) (Tim)  (Ty)  (Qu) (Tim)
     */
    void writeTaskData();

    /*
     *Send Data for requested stations
     *Format for Message of nxt(Receive):
     *     [qualityChar]  [Station-Nr (1-4)]
     *BNr.      1                 2
     *
     *Example:  q                  1
     *
     *Format for Message of RasPi (send):
     *     [qualityChar] [StationType]  [Quality]
     *
     *BNr:           1           2              3
     *Example:       q           2              4
     */
    void sendStationData();

    QProcess rfCommProcess;
    bool isRunning, sendNxtPauseChar, writeTask;
    QTimer timer;

    const static int waitTimeMs;
    /*
     *rfcomm can only be executed by root.
     *This is is a list of graphical versions of "sudo"
     *if one of these commands exists, it will be used to execute rfcomm
     */
    const static QStringList graphicalSudoCommands;

    /*
     *constants
     */
    static const QPair<char, QString>  stopPauseChar;
    static const QPair<char, QString> qualityChar;
    static const QPair<char, QString> stateChar;
    static const QPair<char, QString> taskChar;
    static const QPair<char, QString> taskEndSuccessChar;
    static const QPair<char, QString> taskEndErrorChar;



    Types::Task task;
    Types::StationSetup stationSetup;
};

#endif // NXTCOMMUNICATOR_H
