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
    explicit BtDeviceDialog(Types::BtDevice defaultDevice, QWidget *parent = 0);
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
    BluetoothDiscovery* discoveryThread;

};

#endif // BTWAHLDIALOG_H
