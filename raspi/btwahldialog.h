#ifndef BTWAHLDIALOG_H
#define BTWAHLDIALOG_H

#include <QDialog>
#include <QList>
#include "types.h"
#include "bluetoothdiscovery.h"

namespace Ui {
class BtDeviceDialog;
}

/*
 *This class runs the Bluetooth Discovery Dialog
 *
 */
class BtDeviceDialog : public QDialog
{
    Q_OBJECT
      
public:
    /*
     *defaultDevice - the device we show before we have run the dialog for the first time
     *                This is used to show a selected device from a previous run.
     */
    explicit BtDeviceDialog(Types::BtDevice defaultDevice, QWidget *parent = 0);

    /*
     *returs the selected device
     */
    Types::BtDevice getSelectedDevice();

    /*
     *We prevent the application from terminating until the BT-Discovery has finished
     */
    ~BtDeviceDialog();

private slots:
    /*
     *Start the Discovery Thread
     */
    void discoverBtDevices();

    /*
     *This Slot updates the UI with the new devices
     */
    void btDiscoveryFinished(QList<Types::BtDevice> devs);
    
private:
    Ui::BtDeviceDialog *ui;//handle to the ui class
    BluetoothDiscovery* discoveryThread; //the bluetooth discovery is run in a thread

};

#endif // BTWAHLDIALOG_H
