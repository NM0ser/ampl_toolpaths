/****************************************************************************
** Meta object code from reading C++ file 'importCSVContactPntsDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../include/importCSVContactPntsDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'importCSVContactPntsDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_importCSVContactPntsDialog_t {
    QByteArrayData data[6];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_importCSVContactPntsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_importCSVContactPntsDialog_t qt_meta_stringdata_importCSVContactPntsDialog = {
    {
QT_MOC_LITERAL(0, 0, 26), // "importCSVContactPntsDialog"
QT_MOC_LITERAL(1, 27, 28), // "showSurfNormalHelpDialogSlot"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 29), // "showInputFormatHelpDialogSlot"
QT_MOC_LITERAL(4, 87, 40), // "clickedTopContactPickDirector..."
QT_MOC_LITERAL(5, 128, 40) // "clickedBotContactPickDirector..."

    },
    "importCSVContactPntsDialog\0"
    "showSurfNormalHelpDialogSlot\0\0"
    "showInputFormatHelpDialogSlot\0"
    "clickedTopContactPickDirectoryButtonSlot\0"
    "clickedBotContactPickDirectoryButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_importCSVContactPntsDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void importCSVContactPntsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        importCSVContactPntsDialog *_t = static_cast<importCSVContactPntsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showSurfNormalHelpDialogSlot(); break;
        case 1: _t->showInputFormatHelpDialogSlot(); break;
        case 2: _t->clickedTopContactPickDirectoryButtonSlot(); break;
        case 3: _t->clickedBotContactPickDirectoryButtonSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject importCSVContactPntsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_importCSVContactPntsDialog.data,
      qt_meta_data_importCSVContactPntsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *importCSVContactPntsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *importCSVContactPntsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_importCSVContactPntsDialog.stringdata0))
        return static_cast<void*>(const_cast< importCSVContactPntsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int importCSVContactPntsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
