/****************************************************************************
** Meta object code from reading C++ file 'clipPlaneDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../include/clipPlaneDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clipPlaneDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_clipPlaneDialog_t {
    QByteArrayData data[6];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_clipPlaneDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_clipPlaneDialog_t qt_meta_stringdata_clipPlaneDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "clipPlaneDialog"
QT_MOC_LITERAL(1, 16, 32), // "clippingPlaneButtonClickedSignal"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 27), // "clippingOnButtonClickedSlot"
QT_MOC_LITERAL(4, 78, 28), // "clippingOffButtonClickedSlot"
QT_MOC_LITERAL(5, 107, 29) // "reversePlaneButtonClickedSlot"

    },
    "clipPlaneDialog\0clippingPlaneButtonClickedSignal\0"
    "\0clippingOnButtonClickedSlot\0"
    "clippingOffButtonClickedSlot\0"
    "reversePlaneButtonClickedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clipPlaneDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void clipPlaneDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        clipPlaneDialog *_t = static_cast<clipPlaneDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clippingPlaneButtonClickedSignal(); break;
        case 1: _t->clippingOnButtonClickedSlot(); break;
        case 2: _t->clippingOffButtonClickedSlot(); break;
        case 3: _t->reversePlaneButtonClickedSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (clipPlaneDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clipPlaneDialog::clippingPlaneButtonClickedSignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject clipPlaneDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_clipPlaneDialog.data,
      qt_meta_data_clipPlaneDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *clipPlaneDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clipPlaneDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_clipPlaneDialog.stringdata0))
        return static_cast<void*>(const_cast< clipPlaneDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int clipPlaneDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void clipPlaneDialog::clippingPlaneButtonClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
