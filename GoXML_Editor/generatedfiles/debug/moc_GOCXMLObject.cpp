/****************************************************************************
** Meta object code from reading C++ file 'GOCXMLObject.h'
**
** Created: Thu Jan 20 17:25:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\GOCXMLObject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GOCXMLObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GOCXMLObject[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GOCXMLObject[] = {
    "GOCXMLObject\0\0mdlIndex\0"
    "goc_slotModelDataChanged(QModelIndex)\0"
};

const QMetaObject GOCXMLObject::staticMetaObject = {
    { &GOCObject::staticMetaObject, qt_meta_stringdata_GOCXMLObject,
      qt_meta_data_GOCXMLObject, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GOCXMLObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GOCXMLObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GOCXMLObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GOCXMLObject))
        return static_cast<void*>(const_cast< GOCXMLObject*>(this));
    return GOCObject::qt_metacast(_clname);
}

int GOCXMLObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GOCObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: goc_slotModelDataChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
