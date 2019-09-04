/****************************************************************************
** Meta object code from reading C++ file 'trunConeDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../include/trunConeDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trunConeDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_trunConeDialog_t {
    QByteArrayData data[5];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_trunConeDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_trunConeDialog_t qt_meta_stringdata_trunConeDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "trunConeDialog"
QT_MOC_LITERAL(1, 15, 27), // "trunConeCreateButtonClicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 26), // "pyramidCreateButtonClicked"
QT_MOC_LITERAL(4, 71, 24) // "trunConeCreateSlotDialog"

    },
    "trunConeDialog\0trunConeCreateButtonClicked\0"
    "\0pyramidCreateButtonClicked\0"
    "trunConeCreateSlotDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_trunConeDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void trunConeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        trunConeDialog *_t = static_cast<trunConeDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trunConeCreateButtonClicked(); break;
        case 1: _t->pyramidCreateButtonClicked(); break;
        case 2: _t->trunConeCreateSlotDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (trunConeDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&trunConeDialog::trunConeCreateButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (trunConeDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&trunConeDialog::pyramidCreateButtonClicked)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject trunConeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_trunConeDialog.data,
      qt_meta_data_trunConeDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *trunConeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *trunConeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_trunConeDialog.stringdata0))
        return static_cast<void*>(const_cast< trunConeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int trunConeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void trunConeDialog::trunConeCreateButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void trunConeDialog::pyramidCreateButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
