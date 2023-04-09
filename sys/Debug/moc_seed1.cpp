/****************************************************************************
** Meta object code from reading C++ file 'seed1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../table/seed1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'seed1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Seed_t {
    QByteArrayData data[10];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Seed_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Seed_t qt_meta_stringdata_Seed = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Seed"
QT_MOC_LITERAL(1, 5, 13), // "Table_UnCLOCK"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 21), // "on_butto_back_clicked"
QT_MOC_LITERAL(4, 42, 32), // "on_tableWidget_itemDoubleClicked"
QT_MOC_LITERAL(5, 75, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(6, 93, 4), // "item"
QT_MOC_LITERAL(7, 98, 22), // "on_button_save_clicked"
QT_MOC_LITERAL(8, 121, 22), // "on_button_stop_clicked"
QT_MOC_LITERAL(9, 144, 26) // "on_tableWidget_itemChanged"

    },
    "Seed\0Table_UnCLOCK\0\0on_butto_back_clicked\0"
    "on_tableWidget_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_button_save_clicked\0"
    "on_button_stop_clicked\0"
    "on_tableWidget_itemChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Seed[] = {

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
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void Seed::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Seed *_t = static_cast<Seed *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Table_UnCLOCK(); break;
        case 1: _t->on_butto_back_clicked(); break;
        case 2: _t->on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_button_save_clicked(); break;
        case 4: _t->on_button_stop_clicked(); break;
        case 5: _t->on_tableWidget_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Seed::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Seed::Table_UnCLOCK)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Seed::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Seed.data,
      qt_meta_data_Seed,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Seed::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Seed::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Seed.stringdata0))
        return static_cast<void*>(const_cast< Seed*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Seed::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Seed::Table_UnCLOCK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
