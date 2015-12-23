/****************************************************************************
** Meta object code from reading C++ file 'client_socket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Projects/client/client_app/client_socket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client_socket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_client_socket_t {
    QByteArrayData data[11];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_socket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_socket_t qt_meta_stringdata_client_socket = {
    {
QT_MOC_LITERAL(0, 0, 13), // "client_socket"
QT_MOC_LITERAL(1, 14, 17), // "nameAlreadyExists"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "connectionAccepted"
QT_MOC_LITERAL(4, 52, 17), // "serverSendMessage"
QT_MOC_LITERAL(5, 70, 4), // "data"
QT_MOC_LITERAL(6, 75, 9), // "connected"
QT_MOC_LITERAL(7, 85, 12), // "disconnected"
QT_MOC_LITERAL(8, 98, 9), // "readyRead"
QT_MOC_LITERAL(9, 108, 12), // "bytesWritten"
QT_MOC_LITERAL(10, 121, 5) // "bytes"

    },
    "client_socket\0nameAlreadyExists\0\0"
    "connectionAccepted\0serverSendMessage\0"
    "data\0connected\0disconnected\0readyRead\0"
    "bytesWritten\0bytes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client_socket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   10,

       0        // eod
};

void client_socket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        client_socket *_t = static_cast<client_socket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nameAlreadyExists(); break;
        case 1: _t->connectionAccepted(); break;
        case 2: _t->serverSendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->connected(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->readyRead(); break;
        case 6: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (client_socket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client_socket::nameAlreadyExists)) {
                *result = 0;
            }
        }
        {
            typedef void (client_socket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client_socket::connectionAccepted)) {
                *result = 1;
            }
        }
        {
            typedef void (client_socket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client_socket::serverSendMessage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject client_socket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_client_socket.data,
      qt_meta_data_client_socket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *client_socket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client_socket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_client_socket.stringdata0))
        return static_cast<void*>(const_cast< client_socket*>(this));
    return QObject::qt_metacast(_clname);
}

int client_socket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void client_socket::nameAlreadyExists()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void client_socket::connectionAccepted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void client_socket::serverSendMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
