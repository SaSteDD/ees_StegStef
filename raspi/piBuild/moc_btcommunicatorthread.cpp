/****************************************************************************
** Meta object code from reading C++ file 'btcommunicatorthread.h'
**
** Created: Wed May 22 16:19:47 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../btcommunicatorthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btcommunicatorthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BtCommunicatorThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   44,   44,   44, 0x05,
      45,   44,   44,   44, 0x05,
      70,   44,   44,   44, 0x05,
      93,   44,   44,   44, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,   44,   44,   44, 0x0a,
     114,  144,  158,   44, 0x0a,
     163,   44,   44,   44, 0x0a,
     176,   44,   44,   44, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BtCommunicatorThread[] = {
    "BtCommunicatorThread\0nxtLogMessage(QString)\0"
    "\0raspiLogMessage(QString)\0"
    "appLogMessage(QString)\0disConnected()\0"
    "run()\0tryConnect(Task,StationSetup)\0"
    "task,stations\0bool\0disconnect()\0"
    "runWriteTask()\0"
};

void BtCommunicatorThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BtCommunicatorThread *_t = static_cast<BtCommunicatorThread *>(_o);
        switch (_id) {
        case 0: _t->nxtLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->raspiLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->appLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->disConnected(); break;
        case 4: _t->run(); break;
        case 5: { bool _r = _t->tryConnect((*reinterpret_cast< const Task(*)>(_a[1])),(*reinterpret_cast< const StationSetup(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->disconnect(); break;
        case 7: _t->runWriteTask(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BtCommunicatorThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BtCommunicatorThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BtCommunicatorThread,
      qt_meta_data_BtCommunicatorThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BtCommunicatorThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BtCommunicatorThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BtCommunicatorThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BtCommunicatorThread))
        return static_cast<void*>(const_cast< BtCommunicatorThread*>(this));
    return QObject::qt_metacast(_clname);
}

int BtCommunicatorThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BtCommunicatorThread::nxtLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BtCommunicatorThread::raspiLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BtCommunicatorThread::appLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BtCommunicatorThread::disConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
