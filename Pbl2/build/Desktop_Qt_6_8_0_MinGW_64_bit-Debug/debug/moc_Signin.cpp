/****************************************************************************
** Meta object code from reading C++ file 'Signin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Signin.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Signin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSigninENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSigninENDCLASS = QtMocHelpers::stringData(
    "Signin",
    "on_Loginbtn_clicked",
    "",
    "on_Signupbtn_clicked",
    "on_backbtn_clicked",
    "on_comboBox_currentIndexChanged",
    "index",
    "on_DKadminbtn_clicked",
    "on_tieptucbtn_clicked",
    "on_Dktenantbtn_clicked",
    "on_tieptucpr_clicked",
    "on_pushButton_clicked",
    "on_backbtn_2_clicked",
    "on_backbtn_3_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSigninENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    1,   83,    2, 0x08,    4 /* Private */,
       7,    0,   86,    2, 0x08,    6 /* Private */,
       8,    0,   87,    2, 0x08,    7 /* Private */,
       9,    0,   88,    2, 0x08,    8 /* Private */,
      10,    0,   89,    2, 0x08,    9 /* Private */,
      11,    0,   90,    2, 0x08,   10 /* Private */,
      12,    0,   91,    2, 0x08,   11 /* Private */,
      13,    0,   92,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Signin::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSSigninENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSigninENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSigninENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Signin, std::true_type>,
        // method 'on_Loginbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Signupbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_backbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_DKadminbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tieptucbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Dktenantbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tieptucpr_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_backbtn_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_backbtn_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Signin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Signin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Loginbtn_clicked(); break;
        case 1: _t->on_Signupbtn_clicked(); break;
        case 2: _t->on_backbtn_clicked(); break;
        case 3: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_DKadminbtn_clicked(); break;
        case 5: _t->on_tieptucbtn_clicked(); break;
        case 6: _t->on_Dktenantbtn_clicked(); break;
        case 7: _t->on_tieptucpr_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_backbtn_2_clicked(); break;
        case 10: _t->on_backbtn_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Signin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Signin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSigninENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Signin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP