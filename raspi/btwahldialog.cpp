#include "btwahldialog.h"
#include "ui_btwahl.h"
#include <QDebug>
#include "bluetoothdiscovery.h"

BtWahlDialog::BtWahlDialog(Types::BtDevice defaultDevice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::btDeviceDialog)
{
    qRegisterMetaType<QList<BtDevice> >();
    ui->setupUi(this);

    discover=new BluetoothDiscovery(this);
    connect(discover,SIGNAL(discoveryfinished(QList<Types::BtDevice>)),this,SLOT(btDiscoveryFinished(QList<Types::BtDevice>)));
    discoverBtDevices();

    if(! defaultDevice.mac.isEmpty()){
        ui->btDeviceSelector->addItem(defaultDevice.name + " (" + defaultDevice.mac + ")", QVariant::fromValue<BtDevice>(defaultDevice));
        ui->okButton->setEnabled(true);
        ui->btDeviceSelector->setEnabled(true);
    }
}

BtWahlDialog::~BtWahlDialog()
{
    delete ui;
    qDebug() << "Warte noch auf Ende des Bt-Discovery Threads...." ;
    discover->wait();
    qDebug() << "..fertig";
    discover->deleteLater();

}

void BtWahlDialog::discoverBtDevices()
{
    ui->btDeviceSelector->setDisabled(true);
    ui->progressBar->setDisabled(false);
    ui->btSearchButton->setDisabled(true);
    ui->progressBar->setMaximum(0);
    discover->start();
}


void BtWahlDialog::btDiscoveryFinished(QList<BtDevice> devs)
{
    ui->btDeviceSelector->clear();
    for(int i=0; i<devs.size(); i++)
    {
        ui->btDeviceSelector->addItem(devs.at(i).name + " (" + devs.at(i).mac + ")", QVariant::fromValue<BtDevice>(devs.at(i)));
    }

    if(devs.size() > 0) ui->okButton->setEnabled(true);

    ui->btSearchButton->setDisabled(false);
    ui->progressBar->setDisabled(true);
    ui->progressBar->setMaximum(1);
    ui->btDeviceSelector->setDisabled(false);
}

BtDevice BtWahlDialog::getSelectedDevice()
{
    return ui->btDeviceSelector->itemData(ui->btDeviceSelector->currentIndex()).value<BtDevice>();
}
