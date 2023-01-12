/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Common/Tcp/src/tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tcpclient_t {
    QByteArrayData data[9];
    char stringdata[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Tcpclient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Tcpclient_t qt_meta_stringdata_Tcpclient = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 22),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 5),
QT_MOC_LITERAL(4, 40, 5),
QT_MOC_LITERAL(5, 46, 26),
QT_MOC_LITERAL(6, 73, 29),
QT_MOC_LITERAL(7, 103, 29),
QT_MOC_LITERAL(8, 133, 32)
    },
    "Tcpclient\0sigMessageToUpperLayer\0\0"
    "level\0error\0on_pushButton_send_clicked\0"
    "on_pushButton_receive_clicked\0"
    "on_pushButton_connect_clicked\0"
    "on_pushButton_disconnect_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcpclient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x08,
       6,    0,   45,    2, 0x08,
       7,    0,   46,    2, 0x08,
       8,    0,   47,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tcpclient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tcpclient *_t = static_cast<Tcpclient *>(_o);
        switch (_id) {
        case 0: _t->sigMessageToUpperLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_send_clicked(); break;
        case 2: _t->on_pushButton_receive_clicked(); break;
        case 3: _t->on_pushButton_connect_clicked(); break;
        case 4: _t->on_pushButton_disconnect_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tcpclient::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tcpclient::sigMessageToUpperLayer)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Tcpclient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tcpclient.data,
      qt_meta_data_Tcpclient,  qt_static_metacall, 0, 0}
};


const QMetaObject *Tcpclient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcpclient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tcpclient.stringdata))
        return static_cast<void*>(const_cast< Tcpclient*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tcpclient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tcpclient::sigMessageToUpperLayer(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
