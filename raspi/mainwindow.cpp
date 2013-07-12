#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "types.h"
#include <QDebug>
#include <QSettings>

using Types::TaskStep;
using Types::StationType;
using Types::StationSetup;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    nxtCom(this),
    taskDialog(new TaskDialog(this)),
    statusBarConnectionStateLabel(new QLabel())
{
    ui->setupUi(this);
    ui->trackViewGroupBox->setDisabled(true);

    ui->statusbar->addPermanentWidget(statusBarConnectionStateLabel);
    switchConnectionStatusLabel(false);

    /*
     *Fill station Setup with station types.
     *
     *We  do this manuallly because we want to assaciate the text representation with Values of the StetionType Type
     */
    ui->station1Type->addItem("Bohren", QVariant::fromValue<Types::StationType>(Types::Bohren));
    ui->station1Type->addItem("Drehen", QVariant::fromValue<Types::StationType>(Types::Drehen));
    ui->station1Type->addItem(trUtf8("Fräsen"), QVariant::fromValue<Types::StationType>(Types::Fraesen));

    ui->station2Type->addItem("Drehen", QVariant::fromValue<Types::StationType>(Types::Drehen));
    ui->station2Type->addItem("Bohren", QVariant::fromValue<Types::StationType>(Types::Bohren));
    ui->station2Type->addItem(trUtf8("Fräsen"), QVariant::fromValue<Types::StationType>(Types::Fraesen));

    ui->station3Type->addItem("Bohren", QVariant::fromValue<Types::StationType>(Types::Bohren));
    ui->station3Type->addItem("Drehen", QVariant::fromValue<Types::StationType>(Types::Drehen));
    ui->station3Type->addItem(trUtf8("Fräsen"), QVariant::fromValue<Types::StationType>(Types::Fraesen));


    ui->station4Type->addItem("Drehen", QVariant::fromValue<Types::StationType>(Types::Drehen));
    ui->station4Type->addItem("Bohren", QVariant::fromValue<Types::StationType>(Types::Bohren));
    ui->station4Type->addItem(trUtf8("Fräsen"), QVariant::fromValue<Types::StationType>(Types::Fraesen));

    // create standard Task
    task.taskNumber=2;
    QList<TaskStep> steps;
    TaskStep step;

    //Step 1
    step.type=StationType::Bohren;
    step.quality=2;
    step.time=3;
    steps.append(step);
    //Step 2
    step.type=StationType::Drehen;
    step.quality=3;
    step.time=4;
    steps.append(step);

    task.steps=steps;
        taskDialog->setTask(task);

    /*
     *Logmessages
     */
    connect(&nxtCom,SIGNAL(appLogMessage(QString)),ui->log,SLOT(addAppMessage(QString)));
    connect(&nxtCom,SIGNAL(raspiLogMessage(QString)),ui->log,SLOT(addRaspiMessage(QString)));
    connect(&nxtCom,SIGNAL(nxtLogMessage(QString)),ui->log,SLOT(addNxtMessage(QString)));

    connect(&nxtCom,SIGNAL(taskFinished(bool)),this,SLOT(taskFinished()));
    connect(&nxtCom,SIGNAL(connectionStateChanged(bool)),ui->sendTaskButton,SLOT(setEnabled(bool)));
    connect(&nxtCom,SIGNAL(connectionStateChanged(bool)),ui->trackViewGroupBox,SLOT(setEnabled(bool)));

    connect(&nxtCom,SIGNAL(nxtStateChanged(Types::NxtState)),ui->stateWidget,SLOT(setTaskState(Types::NxtState)));


    /*
     *Only activate NXTStopButton after RFCOMM-connection is established
     */
    connect(&nxtCom,SIGNAL(connectionStateChanged(bool)),ui->nxtStopButton,SLOT(setEnabled(bool)));
    connect(ui->nxtStopButton,SIGNAL(clicked()),&nxtCom,SLOT(sendNxtPauseResume()));

    /*
     *Read Settings for Bluetooth-Selection
     */
    QSettings setting("SteegeSteffen","eesRaspiApp");
    setting.beginGroup("Bluetooth");
    if(setting.contains("DeviceName") && setting.contains("DeviceMac"))
    {
        btDevice.name=setting.value("DeviceName","").toString();
        btDevice.mac=setting.value("DeviceMac","").toString();
     }
    btDialog=new BtDeviceDialog(btDevice,this);
    setting.endGroup();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::runTaskSetup()
{
    //now run the Dialog
    if(taskDialog->exec() == QDialog::Accepted)
    {
        task=taskDialog->getTask();
    } else {
        taskDialog->setTask(task);
    }
}

void MainWindow::runBtSetup()
{
    if(btDialog->exec() == QDialog::Accepted)
    {
        btDevice=btDialog->getSelectedDevice();
       // setBtDeviceLabel();

        QSettings setting("SteegeSteffen","eesRaspiApp");
        setting.beginGroup("Bluetooth");
        setting.setValue("DeviceName",QVariant(btDevice.name));
        setting.setValue("DeviceMac",QVariant(btDevice.mac));
        setting.endGroup();

        openBtConnection();

    }
}

void MainWindow::openBtConnection()
{
    ui->actionVerbindung_aufbauen->setDisabled(true);
    ui->actionVerbindung_trennen->setEnabled(true);

    connect(&nxtCom,SIGNAL(connectionClosed()),ui->actionVerbindung_trennen,SLOT(trigger()));

        nxtCom.openConnection(btDevice);
        switchConnectionStatusLabel(true);
}

void MainWindow::startTask()
{
    ui->sendTaskButton->setDisabled(true);
    ui->stationSetupGroupBox->setEnabled(false);
    ui->taskSetupButton->setEnabled(false);

    StationSetup stations;
    stations.station1.quality=ui->station1Quality->value();
    stations.station1.type=ui->station1Type->itemData(ui->station1Type->currentIndex()).value<Types::StationType>();

    stations.station2.quality=ui->station2Quality->value();
    stations.station2.type=ui->station2Type->itemData(ui->station2Type->currentIndex()).value<Types::StationType>();

    stations.station3.quality=ui->station3Quality->value();
    stations.station3.type=ui->station3Type->itemData(ui->station3Type->currentIndex()).value<Types::StationType>();

    stations.station4.quality=ui->station4Quality->value();
    stations.station4.type=ui->station4Type->itemData(ui->station4Type->currentIndex()).value<Types::StationType>();

    nxtCom.sendTaskData(task,stations);
}

void MainWindow::taskFinished()
{
    ui->sendTaskButton->setEnabled(true);
    ui->stationSetupGroupBox->setEnabled(true);
    ui->taskSetupButton->setEnabled(true);
}

void MainWindow::closeBtConnection()
{
    disconnect(&nxtCom,SIGNAL(connectionClosed()),ui->actionVerbindung_trennen,SLOT(trigger()));
    nxtCom.closeConnection();
    switchConnectionStatusLabel(false);
    ui->actionVerbindung_trennen->setDisabled(true);
    ui->actionVerbindung_aufbauen->setEnabled(true);

    ui->nxtStopButton->setChecked(false);
    ui->stationSetupGroupBox->setEnabled(true);
    ui->taskSetupButton->setEnabled(true);
}

void MainWindow::switchConnectionStatusLabel(bool status)
{
    if(status)
    {
        statusBarConnectionStateLabel->setPixmap(QPixmap(":/icons/bluetoothActive.png"));
    } else {
        statusBarConnectionStateLabel->setPixmap(QPixmap(":/icons/bluetoothInactive.png"));
    }
}
