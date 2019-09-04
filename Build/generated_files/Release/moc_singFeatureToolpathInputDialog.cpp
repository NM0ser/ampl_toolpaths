/****************************************************************************
** Meta object code from reading C++ file 'singFeatureToolpathInputDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../include/singFeatureToolpathInputDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'singFeatureToolpathInputDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_singFeatureToolpathInputDialog_t {
    QByteArrayData data[10];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_singFeatureToolpathInputDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_singFeatureToolpathInputDialog_t qt_meta_stringdata_singFeatureToolpathInputDialog = {
    {
QT_MOC_LITERAL(0, 0, 30), // "singFeatureToolpathInputDialog"
QT_MOC_LITERAL(1, 31, 43), // "clickedSingFeatureToolpathSta..."
QT_MOC_LITERAL(2, 75, 0), // ""
QT_MOC_LITERAL(3, 76, 31), // "showFirstTimeUserHelpDialogSlot"
QT_MOC_LITERAL(4, 108, 33), // "showIncSheetFormingInfoDialog..."
QT_MOC_LITERAL(5, 142, 37), // "showToolSheetMetalParamHelpDi..."
QT_MOC_LITERAL(6, 180, 31), // "showToolpathParamHelpDialogSlot"
QT_MOC_LITERAL(7, 212, 30), // "showToolpathParamAdvDialogSlot"
QT_MOC_LITERAL(8, 243, 29), // "showToolingParamAdvDialogSlot"
QT_MOC_LITERAL(9, 273, 41) // "clickedSingFeatureToolpathSta..."

    },
    "singFeatureToolpathInputDialog\0"
    "clickedSingFeatureToolpathStartButtonSignal\0"
    "\0showFirstTimeUserHelpDialogSlot\0"
    "showIncSheetFormingInfoDialogSlot\0"
    "showToolSheetMetalParamHelpDialogSlot\0"
    "showToolpathParamHelpDialogSlot\0"
    "showToolpathParamAdvDialogSlot\0"
    "showToolingParamAdvDialogSlot\0"
    "clickedSingFeatureToolpathStartButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_singFeatureToolpathInputDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void singFeatureToolpathInputDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        singFeatureToolpathInputDialog *_t = static_cast<singFeatureToolpathInputDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedSingFeatureToolpathStartButtonSignal(); break;
        case 1: _t->showFirstTimeUserHelpDialogSlot(); break;
        case 2: _t->showIncSheetFormingInfoDialogSlot(); break;
        case 3: _t->showToolSheetMetalParamHelpDialogSlot(); break;
        case 4: _t->showToolpathParamHelpDialogSlot(); break;
        case 5: _t->showToolpathParamAdvDialogSlot(); break;
        case 6: _t->showToolingParamAdvDialogSlot(); break;
        case 7: _t->clickedSingFeatureToolpathStartButtonSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (singFeatureToolpathInputDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&singFeatureToolpathInputDialog::clickedSingFeatureToolpathStartButtonSignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject singFeatureToolpathInputDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_singFeatureToolpathInputDialog.data,
      qt_meta_data_singFeatureToolpathInputDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *singFeatureToolpathInputDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *singFeatureToolpathInputDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_singFeatureToolpathInputDialog.stringdata0))
        return static_cast<void*>(const_cast< singFeatureToolpathInputDialog*>(this));
    if (!strcmp(_clname, "Ui::singFeatureToolpathInputDialog"))
        return static_cast< Ui::singFeatureToolpathInputDialog*>(const_cast< singFeatureToolpathInputDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int singFeatureToolpathInputDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void singFeatureToolpathInputDialog::clickedSingFeatureToolpathStartButtonSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
