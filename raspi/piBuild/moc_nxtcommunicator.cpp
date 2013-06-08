/****************************************************************************
** Meta object code from reading C++ file 'nxtcommunicator.h'
**
** Created: Sun May 26 19:54:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nxtcommunicator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nxtcommunicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NxtCommunicator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   39,   39,   39, 0x05,
      40,   39,   39,   39, 0x05,
      63,   39,   39,   39, 0x05,
      88,   39,   39,   39, 0x05,
     121,   39,   39,   39, 0x05,
     140,   39,   39,   39, 0x05,
     159,   39,   39,   39, 0x05,

 // slots: signature, parameters, type, tag, flags
     188,   39,   39,   39, 0x0a,
     200,  264,   39,   39, 0x0a,
     285,   39,   39,   39, 0x0a,
     303,  348,   39,   39, 0x08,
     350,   39,   39,   39, 0x08,
     373,   39,   39,   39, 0x08,
     396,   39,   39,   39, 0x08,
     411,   39,   39,   39, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NxtCommunicator[] = {
    "NxtCommunicator\0appLogMessage(QString)\0"
    "\0nxtLogMessage(QString)\0"
    "raspiLogMessage(QString)\0"
    "nxtStateChanged(Types::NxtState)\0"
    "connectionClosed()\0connectionOpened()\0"
    "connectionStateChanged(bool)\0sendAbort()\0"
    "openConnection(Types::BtDevice,Types::Task,Types::StationSetup)\0"
    "device,task,stations\0closeConnection()\0"
    "rfcommDeviceClosed(int,QProcess::ExitStatus)\0"
    ",\0rfcommProcReadStdErr()\0"
    "rfcommProcReadStdOut()\0tryBtConnect()\0"
    "mainCommunicationLoop()\0"
};

void NxtCommunicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NxtCommunicator *_t = static_cast<NxtCommunicator *>(_o);
        switch (_id) {
        case 0: _t->appLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->nxtLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->raspiLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->nxtStateChanged((*reinterpret_cast< Types::NxtState(*)>(_a[1]))); break;
        case 4: _t->connectionClosed(); break;
        case 5: _t->connectionOpened(); break;
        case 6: _t->connectionStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->sendAbort(); break;
        case 8: _t->openConnection((*reinterpret_cast< Types::BtDevice(*)>(_a[1])),(*reinterpret_cast< const Types::Task(*)>(_a[2])),(*reinterpret_cast< const Types::StationSetup(*)>(_a[3]))); break;
        case 9: _t->closeConnection(); break;
        case 10: _t->rfcommDeviceClosed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 11: _t->rfcommProcReadStdErr(); break;
        case 12: _t->rfcommProcReadStdOut(); break;
        case 13: _t->tryBtConnect(); break;
        case 14: _t->mainCommunicationLoop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NxtCommunicator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NxtCommunicator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NxtCommunicator,
      qt_meta_data_NxtCommunicator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NxtCommunicator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NxtCommunicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NxtCommunicator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NxtCommunicator))
        return static_cast<void*>(const_cast< NxtCommunicator*>(this));
    return QObject::qt_metacast(_clname);
}

int NxtCommunicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void NxtCommunicator::appLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NxtCommunicator::nxtLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NxtCommunicator::raspiLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NxtCommunicator::nxtStateChanged(Types::NxtState _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NxtCommunicator::connectionClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void NxtCommunicator::connectionOpened()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void NxtCommunicator::connectionStateChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
