/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata[567];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 16),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 17),
QT_MOC_LITERAL(4, 47, 3),
QT_MOC_LITERAL(5, 51, 4),
QT_MOC_LITERAL(6, 56, 24),
QT_MOC_LITERAL(7, 81, 18),
QT_MOC_LITERAL(8, 100, 4),
QT_MOC_LITERAL(9, 105, 21),
QT_MOC_LITERAL(10, 127, 5),
QT_MOC_LITERAL(11, 133, 5),
QT_MOC_LITERAL(12, 139, 26),
QT_MOC_LITERAL(13, 166, 30),
QT_MOC_LITERAL(14, 197, 27),
QT_MOC_LITERAL(15, 225, 34),
QT_MOC_LITERAL(16, 260, 37),
QT_MOC_LITERAL(17, 298, 16),
QT_MOC_LITERAL(18, 315, 26),
QT_MOC_LITERAL(19, 342, 24),
QT_MOC_LITERAL(20, 367, 28),
QT_MOC_LITERAL(21, 396, 33),
QT_MOC_LITERAL(22, 430, 33),
QT_MOC_LITERAL(23, 464, 23),
QT_MOC_LITERAL(24, 488, 42),
QT_MOC_LITERAL(25, 531, 4),
QT_MOC_LITERAL(26, 536, 29)
    },
    "MainWindow\0sigMainWindowCmd\0\0"
    "Controller::cmdId\0cmd\0name\0"
    "controllerNewItemHandler\0Controller::itemId\0"
    "item\0messageFromLowerLayer\0level\0error\0"
    "on_pushButton_Scan_clicked\0"
    "on_pushButton_StopScan_clicked\0"
    "on_pushButton_Clear_clicked\0"
    "on_pushButton_ConfigDevice_clicked\0"
    "on_listWidget_ScanResults_itemClicked\0"
    "QListWidgetItem*\0on_pushButton_Exit_clicked\0"
    "on_actionAbout_triggered\0"
    "on_actionLicenseQt_triggered\0"
    "on_actionLicenseWinDump_triggered\0"
    "on_actionLicenseWinPcap_triggered\0"
    "on_actionExit_triggered\0"
    "on_comboBox_NetInterfaceSelector_activated\0"
    "arg1\0on_actionLoadSensor_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    2,   99,    2, 0x0a,
       9,    2,  104,    2, 0x0a,
      12,    0,  109,    2, 0x08,
      13,    0,  110,    2, 0x08,
      14,    0,  111,    2, 0x08,
      15,    0,  112,    2, 0x08,
      16,    1,  113,    2, 0x08,
      18,    0,  116,    2, 0x08,
      19,    0,  117,    2, 0x08,
      20,    0,  118,    2, 0x08,
      21,    0,  119,    2, 0x08,
      22,    0,  120,    2, 0x08,
      23,    0,  121,    2, 0x08,
      24,    1,  122,    2, 0x08,
      26,    0,  125,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString,    8,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->sigMainWindowCmd((*reinterpret_cast< Controller::cmdId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->controllerNewItemHandler((*reinterpret_cast< Controller::itemId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->messageFromLowerLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_pushButton_Scan_clicked(); break;
        case 4: _t->on_pushButton_StopScan_clicked(); break;
        case 5: _t->on_pushButton_Clear_clicked(); break;
        case 6: _t->on_pushButton_ConfigDevice_clicked(); break;
        case 7: _t->on_listWidget_ScanResults_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_Exit_clicked(); break;
        case 9: _t->on_actionAbout_triggered(); break;
        case 10: _t->on_actionLicenseQt_triggered(); break;
        case 11: _t->on_actionLicenseWinDump_triggered(); break;
        case 12: _t->on_actionLicenseWinPcap_triggered(); break;
        case 13: _t->on_actionExit_triggered(); break;
        case 14: _t->on_comboBox_NetInterfaceSelector_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_actionLoadSensor_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(Controller::cmdId , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sigMainWindowCmd)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sigMainWindowCmd(Controller::cmdId _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
