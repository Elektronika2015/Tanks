/****************************************************************************
** Meta object code from reading C++ file 'player_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Projects/server/server_lib/player_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_player_client_t {
    QByteArrayData data[18];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_player_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_player_client_t qt_meta_stringdata_player_client = {
    {
QT_MOC_LITERAL(0, 0, 13), // "player_client"
QT_MOC_LITERAL(1, 14, 5), // "error"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 23), // "QTcpSocket::SocketError"
QT_MOC_LITERAL(4, 45, 11), // "socketError"
QT_MOC_LITERAL(5, 57, 15), // "playerConnected"
QT_MOC_LITERAL(6, 73, 4), // "name"
QT_MOC_LITERAL(7, 78, 14), // "player_client*"
QT_MOC_LITERAL(8, 93, 6), // "client"
QT_MOC_LITERAL(9, 100, 14), // "clientSendData"
QT_MOC_LITERAL(10, 115, 4), // "data"
QT_MOC_LITERAL(11, 120, 18), // "clientDisconnected"
QT_MOC_LITERAL(12, 139, 15), // "firstConnection"
QT_MOC_LITERAL(13, 155, 21), // "playerConnectedResult"
QT_MOC_LITERAL(14, 177, 6), // "result"
QT_MOC_LITERAL(15, 184, 12), // "disconnected"
QT_MOC_LITERAL(16, 197, 9), // "readyRead"
QT_MOC_LITERAL(17, 207, 5) // "write"

    },
    "player_client\0error\0\0QTcpSocket::SocketError\0"
    "socketError\0playerConnected\0name\0"
    "player_client*\0client\0clientSendData\0"
    "data\0clientDisconnected\0firstConnection\0"
    "playerConnectedResult\0result\0disconnected\0"
    "readyRead\0write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_player_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    2,   62,    2, 0x06 /* Public */,
       9,    2,   67,    2, 0x06 /* Public */,
      11,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   75,    2, 0x0a /* Public */,
      13,    1,   76,    2, 0x0a /* Public */,
      15,    0,   79,    2, 0x0a /* Public */,
      16,    0,   80,    2, 0x0a /* Public */,
      17,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void player_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        player_client *_t = static_cast<player_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->playerConnected((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< player_client*(*)>(_a[2]))); break;
        case 2: _t->clientSendData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->clientDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->firstConnection(); break;
        case 5: _t->playerConnectedResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->disconnected(); break;
        case 7: _t->readyRead(); break;
        case 8: _t->write((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< player_client* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (player_client::*_t)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player_client::error)) {
                *result = 0;
            }
        }
        {
            typedef void (player_client::*_t)(QString , player_client * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player_client::playerConnected)) {
                *result = 1;
            }
        }
        {
            typedef void (player_client::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player_client::clientSendData)) {
                *result = 2;
            }
        }
        {
            typedef void (player_client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player_client::clientDisconnected)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject player_client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_player_client.data,
      qt_meta_data_player_client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *player_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *player_client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_player_client.stringdata0))
        return static_cast<void*>(const_cast< player_client*>(this));
    return QObject::qt_metacast(_clname);
}

int player_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void player_client::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void player_client::playerConnected(QString _t1, player_client * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void player_client::clientSendData(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void player_client::clientDisconnected(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
