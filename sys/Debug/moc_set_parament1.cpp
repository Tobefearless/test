/****************************************************************************
** Meta object code from reading C++ file 'set_parament1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../table/set_parament1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_parament1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_set_parament1_t {
    QByteArrayData data[10];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_set_parament1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_set_parament1_t qt_meta_stringdata_set_parament1 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "set_parament1"
QT_MOC_LITERAL(1, 14, 13), // "Table_UnCLOCK"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 32), // "on_tableWidget_itemDoubleClicked"
QT_MOC_LITERAL(4, 62, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(5, 80, 4), // "item"
QT_MOC_LITERAL(6, 85, 22), // "on_button_save_clicked"
QT_MOC_LITERAL(7, 108, 26), // "on_tableWidget_itemChanged"
QT_MOC_LITERAL(8, 135, 21), // "on_butto_back_clicked"
QT_MOC_LITERAL(9, 157, 22) // "on_button_stop_clicked"

    },
    "set_parament1\0Table_UnCLOCK\0\0"
    "on_tableWidget_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_button_save_clicked\0"
    "on_tableWidget_itemChanged\0"
    "on_butto_back_clicked\0on_button_stop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_set_parament1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void set_parament1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        set_parament1 *_t = static_cast<set_parament1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Table_UnCLOCK(); break;
        case 1: _t->on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_button_save_clicked(); break;
        case 3: _t->on_tableWidget_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_butto_back_clicked(); break;
        case 5: _t->on_button_stop_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (set_parament1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&set_parament1::Table_UnCLOCK)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject set_parament1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_set_parament1.data,
      qt_meta_data_set_parament1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *set_parament1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *set_parament1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_set_parament1.stringdata0))
        return static_cast<void*>(const_cast< set_parament1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int set_parament1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void set_parament1::Table_UnCLOCK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
