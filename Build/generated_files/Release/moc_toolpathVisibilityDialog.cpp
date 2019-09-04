/****************************************************************************
** Meta object code from reading C++ file 'toolpathVisibilityDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../include/toolpathVisibilityDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolpathVisibilityDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_toolpathVisibilityDialog_t {
    QByteArrayData data[5];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_toolpathVisibilityDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_toolpathVisibilityDialog_t qt_meta_stringdata_toolpathVisibilityDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "toolpathVisibilityDialog"
QT_MOC_LITERAL(1, 25, 35), // "toolpathVisibilityApplyButton..."
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 33), // "toolpathVisibilityApplyDialog..."
QT_MOC_LITERAL(4, 96, 32) // "toolpathVisibilityHideDialogSlot"

    },
    "toolpathVisibilityDialog\0"
    "toolpathVisibilityApplyButtonPushed\0"
    "\0toolpathVisibilityApplyDialogSlot\0"
    "toolpathVisibilityHideDialogSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_toolpathVisibilityDialog[] = {

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
       3,    0,   32,    2, 0x08 /* Private */,
       4,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void toolpathVisibilityDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        toolpathVisibilityDialog *_t = static_cast<toolpathVisibilityDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toolpathVisibilityApplyButtonPushed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->toolpathVisibilityApplyDialogSlot(); break;
        case 2: _t->toolpathVisibilityHideDialogSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (toolpathVisibilityDialog::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&toolpathVisibilityDialog::toolpathVisibilityApplyButtonPushed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject toolpathVisibilityDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_toolpathVisibilityDialog.data,
      qt_meta_data_toolpathVisibilityDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *toolpathVisibilityDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *toolpathVisibilityDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_toolpathVisibilityDialog.stringdata0))
        return static_cast<void*>(const_cast< toolpathVisibilityDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int toolpathVisibilityDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void toolpathVisibilityDialog::toolpathVisibilityApplyButtonPushed(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
