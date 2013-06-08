/****************************************************************************
** Meta object code from reading C++ file 'btwahldialog.h'
**
** Created: Sun May 26 19:52:46 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../btwahldialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btwahldialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BtWahlDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   33,   33,   33, 0x08,
      34,   78,   33,   33, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BtWahlDialog[] = {
    "BtWahlDialog\0discoverBtDevices()\0\0"
    "btDiscoveryFinished(QList<Types::BtDevice>)\0"
    "devs\0"
};

void BtWahlDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BtWahlDialog *_t = static_cast<BtWahlDialog *>(_o);
        switch (_id) {
        case 0: _t->discoverBtDevices(); break;
        case 1: _t->btDiscoveryFinished((*reinterpret_cast< QList<Types::BtDevice>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BtWahlDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BtWahlDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BtWahlDialog,
      qt_meta_data_BtWahlDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BtWahlDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BtWahlDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BtWahlDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BtWahlDialog))
        return static_cast<void*>(const_cast< BtWahlDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BtWahlDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
