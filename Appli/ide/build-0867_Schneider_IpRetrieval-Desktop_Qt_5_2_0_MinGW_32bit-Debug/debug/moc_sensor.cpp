/****************************************************************************
** Meta object code from reading C++ file 'sensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/src/sensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Sensor_t {
    QByteArrayData data[23];
    char stringdata[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Sensor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Sensor_t qt_meta_stringdata_Sensor = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 22),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 5),
QT_MOC_LITERAL(4, 37, 5),
QT_MOC_LITERAL(5, 43, 29),
QT_MOC_LITERAL(6, 73, 2),
QT_MOC_LITERAL(7, 76, 4),
QT_MOC_LITERAL(8, 81, 30),
QT_MOC_LITERAL(9, 112, 22),
QT_MOC_LITERAL(10, 135, 3),
QT_MOC_LITERAL(11, 139, 21),
QT_MOC_LITERAL(12, 161, 27),
QT_MOC_LITERAL(13, 189, 7),
QT_MOC_LITERAL(14, 197, 27),
QT_MOC_LITERAL(15, 225, 26),
QT_MOC_LITERAL(16, 252, 26),
QT_MOC_LITERAL(17, 279, 19),
QT_MOC_LITERAL(18, 299, 7),
QT_MOC_LITERAL(19, 307, 25),
QT_MOC_LITERAL(20, 333, 4),
QT_MOC_LITERAL(21, 338, 27),
QT_MOC_LITERAL(22, 366, 25)
    },
    "Sensor\0sigMessageToUpperLayer\0\0level\0"
    "error\0sigSensorRequestNetworkChange\0"
    "ip\0mask\0sigSensorRequestNetworkRestore\0"
    "sigSensorConfigChanged\0mac\0"
    "messageFromLowerLayer\0controllerEventNetworkReady\0"
    "success\0on_pushButton_apply_clicked\0"
    "on_pushButton_Undo_clicked\0"
    "on_pushButton_Done_clicked\0"
    "on_checkBox_clicked\0checked\0"
    "on_lineEdit_ip_textEdited\0arg1\0"
    "on_lineEdit_mask_textEdited\0"
    "on_lineEdit_gw_textEdited\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sensor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06,
       5,    2,   84,    2, 0x06,
       8,    0,   89,    2, 0x06,
       9,    1,   90,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    2,   93,    2, 0x0a,
      12,    1,   98,    2, 0x0a,
      14,    0,  101,    2, 0x08,
      15,    0,  102,    2, 0x08,
      16,    0,  103,    2, 0x08,
      17,    1,  104,    2, 0x08,
      19,    1,  107,    2, 0x08,
      21,    1,  110,    2, 0x08,
      22,    1,  113,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,

       0        // eod
};

void Sensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sensor *_t = static_cast<Sensor *>(_o);
        switch (_id) {
        case 0: _t->sigMessageToUpperLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sigSensorRequestNetworkChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->sigSensorRequestNetworkRestore(); break;
        case 3: _t->sigSensorConfigChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->messageFromLowerLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->controllerEventNetworkReady((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_apply_clicked(); break;
        case 7: _t->on_pushButton_Undo_clicked(); break;
        case 8: _t->on_pushButton_Done_clicked(); break;
        case 9: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_ip_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_lineEdit_mask_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_lineEdit_gw_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Sensor::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sensor::sigMessageToUpperLayer)) {
                *result = 0;
            }
        }
        {
            typedef void (Sensor::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sensor::sigSensorRequestNetworkChange)) {
                *result = 1;
            }
        }
        {
            typedef void (Sensor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sensor::sigSensorRequestNetworkRestore)) {
                *result = 2;
            }
        }
        {
            typedef void (Sensor::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sensor::sigSensorConfigChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Sensor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Sensor.data,
      qt_meta_data_Sensor,  qt_static_metacall, 0, 0}
};


const QMetaObject *Sensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sensor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Sensor.stringdata))
        return static_cast<void*>(const_cast< Sensor*>(this));
    return QWidget::qt_metacast(_clname);
}

int Sensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Sensor::sigMessageToUpperLayer(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Sensor::sigSensorRequestNetworkChange(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Sensor::sigSensorRequestNetworkRestore()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Sensor::sigSensorConfigChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
