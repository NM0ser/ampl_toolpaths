/****************************************************************************
** Meta object code from reading C++ file 'calc2SurfDeviationErrorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../include/calc2SurfDeviationErrorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calc2SurfDeviationErrorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calc2SurfDeviationErrorDialog_t {
    QByteArrayData data[8];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calc2SurfDeviationErrorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calc2SurfDeviationErrorDialog_t qt_meta_stringdata_calc2SurfDeviationErrorDialog = {
    {
QT_MOC_LITERAL(0, 0, 29), // "calc2SurfDeviationErrorDialog"
QT_MOC_LITERAL(1, 30, 18), // "importSurf1StpSlot"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 18), // "importSurf1IgsSlot"
QT_MOC_LITERAL(4, 69, 18), // "importSurf2StpSlot"
QT_MOC_LITERAL(5, 88, 18), // "importSurf2IgsSlot"
QT_MOC_LITERAL(6, 107, 25), // "regionParamDefinitionSlot"
QT_MOC_LITERAL(7, 133, 30) // "clickedPickDirectoryButtonSlot"

    },
    "calc2SurfDeviationErrorDialog\0"
    "importSurf1StpSlot\0\0importSurf1IgsSlot\0"
    "importSurf2StpSlot\0importSurf2IgsSlot\0"
    "regionParamDefinitionSlot\0"
    "clickedPickDirectoryButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calc2SurfDeviationErrorDialog[] = {

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
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void calc2SurfDeviationErrorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calc2SurfDeviationErrorDialog *_t = static_cast<calc2SurfDeviationErrorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->importSurf1StpSlot(); break;
        case 1: _t->importSurf1IgsSlot(); break;
        case 2: _t->importSurf2StpSlot(); break;
        case 3: _t->importSurf2IgsSlot(); break;
        case 4: _t->regionParamDefinitionSlot(); break;
        case 5: _t->clickedPickDirectoryButtonSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject calc2SurfDeviationErrorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_calc2SurfDeviationErrorDialog.data,
      qt_meta_data_calc2SurfDeviationErrorDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *calc2SurfDeviationErrorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calc2SurfDeviationErrorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_calc2SurfDeviationErrorDialog.stringdata0))
        return static_cast<void*>(const_cast< calc2SurfDeviationErrorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int calc2SurfDeviationErrorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
