/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Projects/server/server_lib/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TCPserver_t {
    QByteArrayData data[23];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPserver_t qt_meta_stringdata_TCPserver = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPserver"
QT_MOC_LITERAL(1, 10, 22), // "playerConnectionResult"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "result"
QT_MOC_LITERAL(4, 41, 14), // "writeInGameMSG"
QT_MOC_LITERAL(5, 56, 4), // "data"
QT_MOC_LITERAL(6, 61, 21), // "playerConnectedSignal"
QT_MOC_LITERAL(7, 83, 16), // "standardTankInfo"
QT_MOC_LITERAL(8, 100, 4), // "info"
QT_MOC_LITERAL(9, 105, 17), // "playerMovedSignal"
QT_MOC_LITERAL(10, 123, 24), // "playerDisconnectedSignal"
QT_MOC_LITERAL(11, 148, 4), // "name"
QT_MOC_LITERAL(12, 153, 14), // "bulletMoveSlot"
QT_MOC_LITERAL(13, 168, 14), // "bulletDeadSlot"
QT_MOC_LITERAL(14, 183, 3), // "msg"
QT_MOC_LITERAL(15, 187, 10), // "bulletName"
QT_MOC_LITERAL(16, 198, 13), // "bulletHitSlot"
QT_MOC_LITERAL(17, 212, 13), // "destroyedName"
QT_MOC_LITERAL(18, 226, 22), // "firstConnectionRequest"
QT_MOC_LITERAL(19, 249, 14), // "player_client*"
QT_MOC_LITERAL(20, 264, 6), // "client"
QT_MOC_LITERAL(21, 271, 16), // "clientHasWritten"
QT_MOC_LITERAL(22, 288, 18) // "clientDisconnected"

    },
    "TCPserver\0playerConnectionResult\0\0"
    "result\0writeInGameMSG\0data\0"
    "playerConnectedSignal\0standardTankInfo\0"
    "info\0playerMovedSignal\0playerDisconnectedSignal\0"
    "name\0bulletMoveSlot\0bulletDeadSlot\0"
    "msg\0bulletName\0bulletHitSlot\0destroyedName\0"
    "firstConnectionRequest\0player_client*\0"
    "client\0clientHasWritten\0clientDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPserver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       9,    1,   78,    2, 0x06 /* Public */,
      10,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   84,    2, 0x08 /* Private */,
      13,    2,   87,    2, 0x08 /* Private */,
      16,    3,   92,    2, 0x08 /* Private */,
      18,    2,   99,    2, 0x08 /* Private */,
      21,    2,  104,    2, 0x08 /* Private */,
      22,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   17,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19,   11,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,   11,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void TCPserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TCPserver *_t = static_cast<TCPserver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playerConnectionResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->writeInGameMSG((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->playerConnectedSignal((*reinterpret_cast< standardTankInfo(*)>(_a[1]))); break;
        case 3: _t->playerMovedSignal((*reinterpret_cast< standardTankInfo(*)>(_a[1]))); break;
        case 4: _t->playerDisconnectedSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->bulletMoveSlot((*reinterpret_cast< standardTankInfo(*)>(_a[1]))); break;
        case 6: _t->bulletDeadSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->bulletHitSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->firstConnectionRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< player_client*(*)>(_a[2]))); break;
        case 9: _t->clientHasWritten((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->clientDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
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
            typedef void (TCPserver::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPserver::playerConnectionResult)) {
                *result = 0;
            }
        }
        {
            typedef void (TCPserver::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPserver::writeInGameMSG)) {
                *result = 1;
            }
        }
        {
            typedef void (TCPserver::*_t)(standardTankInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPserver::playerConnectedSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (TCPserver::*_t)(standardTankInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPserver::playerMovedSignal)) {
                *result = 3;
            }
        }
        {
            typedef void (TCPserver::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPserver::playerDisconnectedSignal)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject TCPserver::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TCPserver.data,
      qt_meta_data_TCPserver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TCPserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPserver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TCPserver.stringdata0))
        return static_cast<void*>(const_cast< TCPserver*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int TCPserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TCPserver::playerConnectionResult(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCPserver::writeInGameMSG(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TCPserver::playerConnectedSignal(standardTankInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TCPserver::playerMovedSignal(standardTankInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TCPserver::playerDisconnectedSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
