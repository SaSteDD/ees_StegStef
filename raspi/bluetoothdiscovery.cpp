#include "bluetoothdiscovery.h"
#include <QDebug>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>


/*
 Small reminder for later:
 http://blog.qt.digia.com/blog/2010/06/17/youre-doing-it-wrong/
 */
BluetoothDiscovery::BluetoothDiscovery(QObject *parent) :
    QThread(parent)
{
}

//copy from: http://people.csail.mit.edu/albert/bluez-intro/c404.html#bzi-choosing
void BluetoothDiscovery::run()
{
    qDebug() << "Start Discovery";
    //discovered devices
    QList<Types::BtDevice> devices;

    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };

    dev_id = hci_get_route(NULL);
    sock = hci_open_dev( dev_id );
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    }

    len  = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));

    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    if( num_rsp < 0 ) perror("hci_inquiry");

    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name),
            name, 0) < 0)
        strcpy(name, "[unknown]");
        BtDevice device;
        device.name=QString(name);

        device.mac="";
        for(int n=5; n>=0; n--)
        {
            device.mac.append(QString::number((ii+i)->bdaddr.b[n],16).rightJustified(2,'0'));
            if(n > 0) device.mac.append(":");
        }

        devices.append(device);
        qDebug() << "found " << device.name << " "  << device.mac;
    }

    free( ii );
    close( sock );
    qDebug() << "Discovery done";
    emit discoveryfinished(devices);
}
