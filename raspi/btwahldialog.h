#ifndef BTWAHLDIALOG_H
#define BTWAHLDIALOG_H

#include <QDialog>
#include <QList>
#include "types.h"
#include "bluetoothdiscovery.h"

namespace Ui {
class btDeviceDialog;
}

class BtWahlDialog : public QDialog
{
    Q_OBJECT
      
public:
    explicit BtWahlDialog(Types::BtDevice defaultDevice, QWidget *parent = 0);
    Types::BtDevice getSelectedDevice();
    ~BtWahlDialog();

private slots:
    void discoverBtDevices();
    void btDiscoveryFinished(QList<Types::BtDevice> devs);
    
private:
    Ui::btDeviceDialog *ui;
    BluetoothDiscovery* discover;

};

#endif // BTWAHLDIALOG_H
