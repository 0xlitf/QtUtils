/****************************************************************************
** Meta object code from reading C++ file 'ExpandToolButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CustomControllers/ExpandToolButton/ExpandToolButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExpandToolButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExpandToolButton_t {
    QByteArrayData data[7];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExpandToolButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExpandToolButton_t qt_meta_stringdata_ExpandToolButton = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ExpandToolButton"
QT_MOC_LITERAL(1, 17, 8), // "collapse"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "eventFilter"
QT_MOC_LITERAL(4, 39, 3), // "obj"
QT_MOC_LITERAL(5, 43, 7), // "QEvent*"
QT_MOC_LITERAL(6, 51, 5) // "event"

    },
    "ExpandToolButton\0collapse\0\0eventFilter\0"
    "obj\0QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExpandToolButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    2,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 5,    4,    6,

       0        // eod
};

void ExpandToolButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExpandToolButton *_t = static_cast<ExpandToolButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->collapse(); break;
        case 1: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject ExpandToolButton::staticMetaObject = {
    { &CustomToolButton::staticMetaObject, qt_meta_stringdata_ExpandToolButton.data,
      qt_meta_data_ExpandToolButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExpandToolButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpandToolButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExpandToolButton.stringdata0))
        return static_cast<void*>(const_cast< ExpandToolButton*>(this));
    return CustomToolButton::qt_metacast(_clname);
}

int ExpandToolButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
