/****************************************************************************
** Meta object code from reading C++ file 'co_parenting1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../table/co_parenting1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'co_parenting1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Co_parenting_t {
    QByteArrayData data[10];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Co_parenting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Co_parenting_t qt_meta_stringdata_Co_parenting = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Co_parenting"
QT_MOC_LITERAL(1, 13, 13), // "Table_UnCLOCK"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 32), // "on_tableWidget_itemDoubleClicked"
QT_MOC_LITERAL(4, 61, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(5, 79, 4), // "item"
QT_MOC_LITERAL(6, 84, 22), // "on_button_save_clicked"
QT_MOC_LITERAL(7, 107, 21), // "on_butto_back_clicked"
QT_MOC_LITERAL(8, 129, 22), // "on_button_stop_clicked"
QT_MOC_LITERAL(9, 152, 26) // "on_tableWidget_itemChanged"

    },
    "Co_parenting\0Table_UnCLOCK\0\0"
    "on_tableWidget_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_button_save_clicked\0"
    "on_butto_back_clicked\0on_button_stop_clicked\0"
    "on_tableWidget_itemChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Co_parenting[] = {

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
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void Co_parenting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Co_parenting *_t = static_cast<Co_parenting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Table_UnCLOCK(); break;
        case 1: _t->on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_button_save_clicked(); break;
        case 3: _t->on_butto_back_clicked(); break;
        case 4: _t->on_button_stop_clicked(); break;
        case 5: _t->on_tableWidget_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Co_parenting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Co_parenting::Table_UnCLOCK)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Co_parenting::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Co_parenting.data,
      qt_meta_data_Co_parenting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Co_parenting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Co_parenting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Co_parenting.stringdata0))
        return static_cast<void*>(const_cast< Co_parenting*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Co_parenting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Co_parenting::Table_UnCLOCK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
