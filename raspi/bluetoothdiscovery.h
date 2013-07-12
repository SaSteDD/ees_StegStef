#ifndef BLUETOOTHDISCOVERY_H
#define BLUETOOTHDISCOVERY_H

#include <QThread>
#include <QList>
#include "types.h"

using Types::BtDevice;

/*
 *We cant have all of the required C-Headers for Bt-Discovery in the btwahldialog.h
 *mainly because of naming conflicts
 *
 *Therefore we source it out to this class
 */
class BluetoothDiscovery : public QThread
{
    Q_OBJECT
public:
    explicit BluetoothDiscovery(QObject *parent = 0);
    
signals:
    /*
     *This gets fired when discovey was finished.
     *
     *dev - List of discovered devices
     */
    void discoveryfinished(QList<Types::BtDevice> dev);

private slots:
    void run();
};

#endif // BLUETOOTHDISCOVERY_H
