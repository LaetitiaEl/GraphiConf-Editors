/****************************************************************************
** Meta object code from reading C++ file 'GoSQL_Editor.h'
**
** Created: Tue Jan 25 13:50:46 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\GoSQL_Editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GoSQL_Editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GoSQL_Editor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   22,   14,   13, 0x0a,
      52,   13,   14,   13, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_GoSQL_Editor[] = {
    "GoSQL_Editor\0\0HRESULT\0checked\0"
    "goc_addDatabase(bool)\0goc_addDatabase()\0"
};

const QMetaObject GoSQL_Editor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GoSQL_Editor,
      qt_meta_data_GoSQL_Editor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GoSQL_Editor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GoSQL_Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GoSQL_Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GoSQL_Editor))
        return static_cast<void*>(const_cast< GoSQL_Editor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GoSQL_Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { HRESULT _r = goc_addDatabase((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 1: { HRESULT _r = goc_addDatabase();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
