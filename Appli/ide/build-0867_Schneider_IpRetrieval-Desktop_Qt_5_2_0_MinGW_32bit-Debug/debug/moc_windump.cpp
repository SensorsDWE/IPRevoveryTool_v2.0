/****************************************************************************
** Meta object code from reading C++ file 'windump.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Common/NetworkDiagnostic/src/windump.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windump.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Windump_t {
    QByteArrayData data[8];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Windump_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Windump_t qt_meta_stringdata_Windump = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 22),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 5),
QT_MOC_LITERAL(4, 38, 5),
QT_MOC_LITERAL(5, 44, 22),
QT_MOC_LITERAL(6, 67, 7),
QT_MOC_LITERAL(7, 75, 11)
    },
    "Windump\0sigMessageToUpperLayer\0\0level\0"
    "error\0sigWindumpCaptureEvent\0eventId\0"
    "stopCapture\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Windump[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06,
       5,    1,   34,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   37,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Windump::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Windump *_t = static_cast<Windump *>(_o);
        switch (_id) {
        case 0: _t->sigMessageToUpperLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sigWindumpCaptureEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->stopCapture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Windump::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Windump::sigMessageToUpperLayer)) {
                *result = 0;
            }
        }
        {
            typedef void (Windump::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Windump::sigWindumpCaptureEvent)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Windump::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Windump.data,
      qt_meta_data_Windump,  qt_static_metacall, 0, 0}
};


const QMetaObject *Windump::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Windump::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Windump.stringdata))
        return static_cast<void*>(const_cast< Windump*>(this));
    return QThread::qt_metacast(_clname);
}

int Windump::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Windump::sigMessageToUpperLayer(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Windump::sigWindumpCaptureEvent(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
