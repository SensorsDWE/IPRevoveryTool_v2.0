/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/src/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[23];
    char stringdata[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Controller_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 20),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 18),
QT_MOC_LITERAL(4, 52, 4),
QT_MOC_LITERAL(5, 57, 4),
QT_MOC_LITERAL(6, 62, 25),
QT_MOC_LITERAL(7, 88, 7),
QT_MOC_LITERAL(8, 96, 22),
QT_MOC_LITERAL(9, 119, 5),
QT_MOC_LITERAL(10, 125, 5),
QT_MOC_LITERAL(11, 131, 20),
QT_MOC_LITERAL(12, 152, 17),
QT_MOC_LITERAL(13, 170, 3),
QT_MOC_LITERAL(14, 174, 19),
QT_MOC_LITERAL(15, 194, 7),
QT_MOC_LITERAL(16, 202, 32),
QT_MOC_LITERAL(17, 235, 31),
QT_MOC_LITERAL(18, 267, 2),
QT_MOC_LITERAL(19, 270, 4),
QT_MOC_LITERAL(20, 275, 24),
QT_MOC_LITERAL(21, 300, 3),
QT_MOC_LITERAL(22, 304, 21)
    },
    "Controller\0sigControllerNewItem\0\0"
    "Controller::itemId\0item\0name\0"
    "sigControllerNetworkReady\0success\0"
    "sigMessageToUpperLayer\0level\0error\0"
    "mainWindowCmdHandler\0Controller::cmdId\0"
    "cmd\0windumpEventHandler\0eventId\0"
    "sensorEventRequestNetworkRestore\0"
    "sensorEventRequestNetworkChange\0ip\0"
    "mask\0sensorEventConfigChanged\0mac\0"
    "messageFromLowerLayer\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06,
       6,    1,   64,    2, 0x06,
       8,    2,   67,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    2,   72,    2, 0x0a,
      14,    1,   77,    2, 0x0a,
      16,    0,   80,    2, 0x0a,
      17,    2,   81,    2, 0x0a,
      20,    1,   86,    2, 0x0a,
      22,    2,   89,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString,   13,    5,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        switch (_id) {
        case 0: _t->sigControllerNewItem((*reinterpret_cast< Controller::itemId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sigControllerNetworkReady((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sigMessageToUpperLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->mainWindowCmdHandler((*reinterpret_cast< Controller::cmdId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->windumpEventHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sensorEventRequestNetworkRestore(); break;
        case 6: _t->sensorEventRequestNetworkChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->sensorEventConfigChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->messageFromLowerLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Controller::*_t)(Controller::itemId , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sigControllerNewItem)) {
                *result = 0;
            }
        }
        {
            typedef void (Controller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sigControllerNetworkReady)) {
                *result = 1;
            }
        }
        {
            typedef void (Controller::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sigMessageToUpperLayer)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, 0, 0}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QThread::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Controller::sigControllerNewItem(Controller::itemId _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::sigControllerNetworkReady(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::sigMessageToUpperLayer(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
