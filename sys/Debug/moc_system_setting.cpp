/****************************************************************************
** Meta object code from reading C++ file 'system_setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../home/system_setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'system_setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_System_Setting_t {
    QByteArrayData data[15];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_System_Setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_System_Setting_t qt_meta_stringdata_System_Setting = {
    {
QT_MOC_LITERAL(0, 0, 14), // "System_Setting"
QT_MOC_LITERAL(1, 15, 14), // "Contral_adjust"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "uint8_t"
QT_MOC_LITERAL(4, 39, 2), // "id"
QT_MOC_LITERAL(5, 42, 22), // "on_btn_connect_clicked"
QT_MOC_LITERAL(6, 65, 17), // "on_Modify_clicked"
QT_MOC_LITERAL(7, 83, 23), // "on_btn_Wconnect_clicked"
QT_MOC_LITERAL(8, 107, 21), // "on_Heat_Learn_clicked"
QT_MOC_LITERAL(9, 129, 21), // "on_Cold_Learn_clicked"
QT_MOC_LITERAL(10, 151, 22), // "on_Close_Learn_clicked"
QT_MOC_LITERAL(11, 174, 34), // "on_Room_Choose_currentIndexCh..."
QT_MOC_LITERAL(12, 209, 5), // "index"
QT_MOC_LITERAL(13, 215, 36), // "on_comboBox_wifi_currentIndex..."
QT_MOC_LITERAL(14, 252, 19) // "on_btn_scan_clicked"

    },
    "System_Setting\0Contral_adjust\0\0uint8_t\0"
    "id\0on_btn_connect_clicked\0on_Modify_clicked\0"
    "on_btn_Wconnect_clicked\0on_Heat_Learn_clicked\0"
    "on_Cold_Learn_clicked\0on_Close_Learn_clicked\0"
    "on_Room_Choose_currentIndexChanged\0"
    "index\0on_comboBox_wifi_currentIndexChanged\0"
    "on_btn_scan_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_System_Setting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,
      13,    1,   76,    2, 0x08 /* Private */,
      14,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void System_Setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        System_Setting *_t = static_cast<System_Setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Contral_adjust((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 1: _t->on_btn_connect_clicked(); break;
        case 2: _t->on_Modify_clicked(); break;
        case 3: _t->on_btn_Wconnect_clicked(); break;
        case 4: _t->on_Heat_Learn_clicked(); break;
        case 5: _t->on_Cold_Learn_clicked(); break;
        case 6: _t->on_Close_Learn_clicked(); break;
        case 7: _t->on_Room_Choose_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_comboBox_wifi_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_btn_scan_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (System_Setting::*_t)(uint8_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&System_Setting::Contral_adjust)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject System_Setting::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_System_Setting.data,
      qt_meta_data_System_Setting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *System_Setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *System_Setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_System_Setting.stringdata0))
        return static_cast<void*>(const_cast< System_Setting*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int System_Setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void System_Setting::Contral_adjust(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
