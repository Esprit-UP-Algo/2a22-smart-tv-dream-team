/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "on_ok_2_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "on_ok_3_clicked"
QT_MOC_LITERAL(4, 44, 15), // "on_ku_3_clicked"
QT_MOC_LITERAL(5, 60, 15), // "on_ku_2_clicked"
QT_MOC_LITERAL(6, 76, 16), // "on_ok_13_clicked"
QT_MOC_LITERAL(7, 93, 16), // "on_ok_15_clicked"
QT_MOC_LITERAL(8, 110, 16), // "on_ok_14_clicked"
QT_MOC_LITERAL(9, 127, 16), // "on_ku_13_clicked"
QT_MOC_LITERAL(10, 144, 16), // "authenticateUser"
QT_MOC_LITERAL(11, 161, 8), // "Username"
QT_MOC_LITERAL(12, 170, 8), // "Password"
QT_MOC_LITERAL(13, 179, 8), // "QString&"
QT_MOC_LITERAL(14, 188, 4), // "Role"
QT_MOC_LITERAL(15, 193, 8), // "sendMail"
QT_MOC_LITERAL(16, 202, 8), // "mailSent"
QT_MOC_LITERAL(17, 211, 6), // "status"
QT_MOC_LITERAL(18, 218, 5), // "Smtp*"
QT_MOC_LITERAL(19, 224, 1), // "s"
QT_MOC_LITERAL(20, 226, 16), // "on_ok_16_clicked"
QT_MOC_LITERAL(21, 243, 15) // "confirm_accesss"

    },
    "MainWindow\0on_ok_2_clicked\0\0on_ok_3_clicked\0"
    "on_ku_3_clicked\0on_ku_2_clicked\0"
    "on_ok_13_clicked\0on_ok_15_clicked\0"
    "on_ok_14_clicked\0on_ku_13_clicked\0"
    "authenticateUser\0Username\0Password\0"
    "QString&\0Role\0sendMail\0mailSent\0status\0"
    "Smtp*\0s\0on_ok_16_clicked\0confirm_accesss"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    3,   87,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    2,   95,    2, 0x08 /* Private */,
      20,    0,  100,    2, 0x08 /* Private */,
      21,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 13,   11,   12,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,   17,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ok_2_clicked(); break;
        case 1: _t->on_ok_3_clicked(); break;
        case 3: _t->on_ku_2_clicked(); break;
        case 4: _t->on_ok_13_clicked(); break;
        case 5: _t->on_ok_15_clicked(); break;
        case 6: _t->on_ok_14_clicked(); break;
        case 7: _t->on_ku_13_clicked(); break;
        case 8: { bool _r = _t->authenticateUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->sendMail(); break;
        case 10: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Smtp*(*)>(_a[2]))); break;
        case 11: _t->on_ok_16_clicked(); break;
        case 12: _t->confirm_accesss(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Smtp* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
