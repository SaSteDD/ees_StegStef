/****************************************************************************
** Meta object code from reading C++ file 'loggerwidget.h'
**
** Created: Tue May 21 17:05:45 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../loggerwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loggerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoggerWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   36,   40,   40, 0x0a,
      41,   36,   40,   40, 0x0a,
      66,   36,   40,   40, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LoggerWidget[] = {
    "LoggerWidget\0addNxtMessage(QString)\0"
    "msg\0\0addRaspiMessage(QString)\0"
    "addAppMessage(QString)\0"
};

void LoggerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoggerWidget *_t = static_cast<LoggerWidget *>(_o);
        switch (_id) {
        case 0: _t->addNxtMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addRaspiMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addAppMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LoggerWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoggerWidget::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_LoggerWidget,
      qt_meta_data_LoggerWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoggerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoggerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoggerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoggerWidget))
        return static_cast<void*>(const_cast< LoggerWidget*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int LoggerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
