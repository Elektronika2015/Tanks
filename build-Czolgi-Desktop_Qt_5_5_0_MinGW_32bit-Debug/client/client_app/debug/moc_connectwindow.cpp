/****************************************************************************
** Meta object code from reading C++ file 'connectwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Projects/client/client_app/connectwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConnectWindow_t {
    QByteArrayData data[9];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectWindow_t qt_meta_stringdata_ConnectWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ConnectWindow"
QT_MOC_LITERAL(1, 14, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(4, 62, 22), // "connectionAcceptedSlot"
QT_MOC_LITERAL(5, 85, 21), // "nameAlreadyExistsSlot"
QT_MOC_LITERAL(6, 107, 21), // "serverSendMessageSlot"
QT_MOC_LITERAL(7, 129, 4), // "data"
QT_MOC_LITERAL(8, 134, 31) // "on_nameLineEdit_editingFinished"

    },
    "ConnectWindow\0on_backButton_clicked\0"
    "\0on_connectButton_clicked\0"
    "connectionAcceptedSlot\0nameAlreadyExistsSlot\0"
    "serverSendMessageSlot\0data\0"
    "on_nameLineEdit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void ConnectWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectWindow *_t = static_cast<ConnectWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_backButton_clicked(); break;
        case 1: _t->on_connectButton_clicked(); break;
        case 2: _t->connectionAcceptedSlot(); break;
        case 3: _t->nameAlreadyExistsSlot(); break;
        case 4: _t->serverSendMessageSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_nameLineEdit_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObject ConnectWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConnectWindow.data,
      qt_meta_data_ConnectWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConnectWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectWindow.stringdata0))
        return static_cast<void*>(const_cast< ConnectWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConnectWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
