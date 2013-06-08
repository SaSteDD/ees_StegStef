/****************************************************************************
** Meta object code from reading C++ file 'trackview.h'
**
** Created: Fri May 24 11:52:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../trackview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrackView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,   44,   50,   50, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TrackView[] = {
    "TrackView\0setTrackPosition(Types::NxtState)\0"
    "state\0\0"
};

void TrackView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TrackView *_t = static_cast<TrackView *>(_o);
        switch (_id) {
        case 0: _t->setTrackPosition((*reinterpret_cast< Types::NxtState(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TrackView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TrackView::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_TrackView,
      qt_meta_data_TrackView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TrackView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TrackView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TrackView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrackView))
        return static_cast<void*>(const_cast< TrackView*>(this));
    return QLabel::qt_metacast(_clname);
}

int TrackView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
