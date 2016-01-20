/****************************************************************************
** Meta object code from reading C++ file 'tankmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Projects/client/client_app/tankmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tankmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TankModel_t {
    QByteArrayData data[10];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TankModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TankModel_t qt_meta_stringdata_TankModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TankModel"
QT_MOC_LITERAL(1, 10, 11), // "sendMessage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "data"
QT_MOC_LITERAL(4, 28, 13), // "messageSignal"
QT_MOC_LITERAL(5, 42, 16), // "standardTankInfo"
QT_MOC_LITERAL(6, 59, 4), // "info"
QT_MOC_LITERAL(7, 64, 5), // "shoot"
QT_MOC_LITERAL(8, 70, 9), // "timerSlot"
QT_MOC_LITERAL(9, 80, 27) // "disconnectAndStopTimer2Slot"

    },
    "TankModel\0sendMessage\0\0data\0messageSignal\0"
    "standardTankInfo\0info\0shoot\0timerSlot\0"
    "disconnectAndStopTimer2Slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TankModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x08 /* Private */,
       8,    0,   46,    2, 0x08 /* Private */,
       9,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TankModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TankModel *_t = static_cast<TankModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->messageSignal((*reinterpret_cast< standardTankInfo(*)>(_a[1]))); break;
        case 2: _t->shoot(); break;
        case 3: _t->timerSlot(); break;
        case 4: _t->disconnectAndStopTimer2Slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TankModel::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TankModel::sendMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (TankModel::*_t)(standardTankInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TankModel::messageSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TankModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TankModel.data,
      qt_meta_data_TankModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TankModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TankModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TankModel.stringdata0))
        return static_cast<void*>(const_cast< TankModel*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< TankModel*>(this));
    return QObject::qt_metacast(_clname);
}

int TankModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TankModel::sendMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TankModel::messageSignal(standardTankInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
