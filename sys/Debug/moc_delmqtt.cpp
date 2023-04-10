/****************************************************************************
** Meta object code from reading C++ file 'delmqtt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../delmqtt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'delmqtt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DelMqtt_t {
    QByteArrayData data[9];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DelMqtt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DelMqtt_t qt_meta_stringdata_DelMqtt = {
    {
QT_MOC_LITERAL(0, 0, 7), // "DelMqtt"
QT_MOC_LITERAL(1, 8, 9), // "Mqtt_data"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "info"
QT_MOC_LITERAL(4, 24, 20), // "topicMessageReceived"
QT_MOC_LITERAL(5, 45, 4), // "data"
QT_MOC_LITERAL(6, 50, 14), // "QMqttTopicName"
QT_MOC_LITERAL(7, 65, 5), // "topic"
QT_MOC_LITERAL(8, 71, 6) // "do_run"

    },
    "DelMqtt\0Mqtt_data\0\0info\0topicMessageReceived\0"
    "data\0QMqttTopicName\0topic\0do_run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DelMqtt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   32,    2, 0x0a /* Public */,
       8,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 6,    5,    7,
    QMetaType::Void,

       0        // eod
};

void DelMqtt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DelMqtt *_t = static_cast<DelMqtt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Mqtt_data((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->topicMessageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QMqttTopicName(*)>(_a[2]))); break;
        case 2: _t->do_run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DelMqtt::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DelMqtt::Mqtt_data)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DelMqtt::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DelMqtt.data,
      qt_meta_data_DelMqtt,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DelMqtt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DelMqtt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DelMqtt.stringdata0))
        return static_cast<void*>(const_cast< DelMqtt*>(this));
    return QObject::qt_metacast(_clname);
}

int DelMqtt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DelMqtt::Mqtt_data(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
