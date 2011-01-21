/****************************************************************************
** Meta object code from reading C++ file 'GOCXMLSpace.h'
**
** Created: Thu Jan 20 17:25:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\GOCXMLSpace.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GOCXMLSpace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GOCXMLSpace[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   12,   13,   12, 0x0a,
      62,   50,   13,   12, 0x0a,
     111,  102,   12,   12, 0x0a,
     153,   12,   12,   12, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_GOCXMLSpace[] = {
    "GOCXMLSpace\0\0HRESULT\0goc_slotSaveSelectedObject()\0"
    "spSpaceView\0goc_slotSpaceViewCreated(GOCSpaceView*)\0"
    "spObjNew\0goc_createNewObject(QPointer<GOCObject>*)\0"
    "goc_createNewObject()\0"
};

const QMetaObject GOCXMLSpace::staticMetaObject = {
    { &GOCSpace::staticMetaObject, qt_meta_stringdata_GOCXMLSpace,
      qt_meta_data_GOCXMLSpace, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GOCXMLSpace::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GOCXMLSpace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GOCXMLSpace::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GOCXMLSpace))
        return static_cast<void*>(const_cast< GOCXMLSpace*>(this));
    return GOCSpace::qt_metacast(_clname);
}

int GOCXMLSpace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GOCSpace::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { HRESULT _r = goc_slotSaveSelectedObject();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 1: { HRESULT _r = goc_slotSpaceViewCreated((*reinterpret_cast< GOCSpaceView*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 2: goc_createNewObject((*reinterpret_cast< QPointer<GOCObject>*(*)>(_a[1]))); break;
        case 3: goc_createNewObject(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
