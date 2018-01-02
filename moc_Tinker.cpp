/****************************************************************************
** Meta object code from reading C++ file 'Tinker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tinker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tinker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tinker_t {
    QByteArrayData data[22];
    char stringdata0[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tinker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tinker_t qt_meta_stringdata_Tinker = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Tinker"
QT_MOC_LITERAL(1, 7, 18), // "setUnitCellClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 22), // "setAxisOnScreenClicked"
QT_MOC_LITERAL(4, 50, 20), // "setBeamCentreClicked"
QT_MOC_LITERAL(5, 71, 17), // "setDetDistClicked"
QT_MOC_LITERAL(6, 89, 20), // "setWavelengthClicked"
QT_MOC_LITERAL(7, 110, 17), // "setRlpSizeClicked"
QT_MOC_LITERAL(8, 128, 20), // "setDegreeStepClicked"
QT_MOC_LITERAL(9, 149, 11), // "identifyHkl"
QT_MOC_LITERAL(10, 161, 9), // "openImage"
QT_MOC_LITERAL(11, 171, 10), // "saveMatrix"
QT_MOC_LITERAL(12, 182, 10), // "loadMatrix"
QT_MOC_LITERAL(13, 193, 9), // "beamXPlus"
QT_MOC_LITERAL(14, 203, 9), // "beamYPlus"
QT_MOC_LITERAL(15, 213, 10), // "beamXMinus"
QT_MOC_LITERAL(16, 224, 10), // "beamYMinus"
QT_MOC_LITERAL(17, 235, 14), // "fixAxisClicked"
QT_MOC_LITERAL(18, 250, 13), // "refineClicked"
QT_MOC_LITERAL(19, 264, 13), // "changeLattice"
QT_MOC_LITERAL(20, 278, 18), // "BravaisLatticeType"
QT_MOC_LITERAL(21, 297, 4) // "type"

    },
    "Tinker\0setUnitCellClicked\0\0"
    "setAxisOnScreenClicked\0setBeamCentreClicked\0"
    "setDetDistClicked\0setWavelengthClicked\0"
    "setRlpSizeClicked\0setDegreeStepClicked\0"
    "identifyHkl\0openImage\0saveMatrix\0"
    "loadMatrix\0beamXPlus\0beamYPlus\0"
    "beamXMinus\0beamYMinus\0fixAxisClicked\0"
    "refineClicked\0changeLattice\0"
    "BravaisLatticeType\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tinker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    1,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void Tinker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tinker *_t = static_cast<Tinker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setUnitCellClicked(); break;
        case 1: _t->setAxisOnScreenClicked(); break;
        case 2: _t->setBeamCentreClicked(); break;
        case 3: _t->setDetDistClicked(); break;
        case 4: _t->setWavelengthClicked(); break;
        case 5: _t->setRlpSizeClicked(); break;
        case 6: _t->setDegreeStepClicked(); break;
        case 7: _t->identifyHkl(); break;
        case 8: _t->openImage(); break;
        case 9: _t->saveMatrix(); break;
        case 10: _t->loadMatrix(); break;
        case 11: _t->beamXPlus(); break;
        case 12: _t->beamYPlus(); break;
        case 13: _t->beamXMinus(); break;
        case 14: _t->beamYMinus(); break;
        case 15: _t->fixAxisClicked(); break;
        case 16: _t->refineClicked(); break;
        case 17: _t->changeLattice((*reinterpret_cast< BravaisLatticeType(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Tinker::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Tinker.data,
      qt_meta_data_Tinker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tinker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tinker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tinker.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Tinker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
