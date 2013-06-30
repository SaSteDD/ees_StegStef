#ifndef BTWAHLDIALOG_H
#define BTWAHLDIALOG_H

#include <QDialog>
#include <QList>
#include "types.h"
#include "bluetoothdiscovery.h"

namespace Ui {
class BtDeviceDialog;
}

class BtDeviceDialog : public QDialog
{
    Q_OBJECT
      
public:
    explicit BtDeviceDialog(Types::BtDevice defaultDevice, QWidget *parent = 0);
    Types::BtDevice getSelectedDevice();
    ~BtDeviceDialog();

private slots:
    void discoverBtDevices();
    void btDiscoveryFinished(QList<Types::BtDevice> devs);
    
private:
    Ui::BtDeviceDialog *ui;
    BluetoothDiscovery* discoveryThread;

};

#endif // BTWAHLDIALOG_H
