/****************************************************************************
** Meta object code from reading C++ file 'GOCXMLLoadThread.h'
**
** Created: Fri Jan 21 15:59:14 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\GOCXMLLoadThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GOCXMLLoadThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GOCXMLLoadThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      59,   26,   18,   17, 0x05,
     128,  118,   18,   17, 0x05,
     157,   17,   18,   17, 0x05,
     179,   17,   18,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     268,  202,   18,   17, 0x0a,
     389,  379,   18,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GOCXMLLoadThread[] = {
    "GOCXMLLoadThread\0\0HRESULT\0"
    "xmlDocument,xmlSpace,gocMainView\0"
    "goc_sigLoadingDone(QDomDocument*,GOCXMLSpace*,GOCMDIView*)\0"
    "iNbLoaded\0goc_sigPercentageLoaded(int)\0"
    "goc_sigLoadingStart()\0goc_sigLoadingFailed()\0"
    "mainXMLEditor,xmlDocument,gocPropertiesView,spRegister,spMainView\0"
    "goc_slotLoadXMLFile(GOCXMLEditor*,QDomDocument*,GOCPropertiesView*,QPo"
    "inter<GOCRegister>,QPointer<GOCMDIView>)\0"
    "xmlObject\0goc_slotObjectCreated(GOCXMLObject*)\0"
};

const QMetaObject GOCXMLLoadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GOCXMLLoadThread,
      qt_meta_data_GOCXMLLoadThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GOCXMLLoadThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GOCXMLLoadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GOCXMLLoadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GOCXMLLoadThread))
        return static_cast<void*>(const_cast< GOCXMLLoadThread*>(this));
    return QThread::qt_metacast(_clname);
}

int GOCXMLLoadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { HRESULT _r = goc_sigLoadingDone((*reinterpret_cast< QDomDocument*(*)>(_a[1])),(*reinterpret_cast< GOCXMLSpace*(*)>(_a[2])),(*reinterpret_cast< GOCMDIView*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 1: { HRESULT _r = goc_sigPercentageLoaded((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 2: { HRESULT _r = goc_sigLoadingStart();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 3: { HRESULT _r = goc_sigLoadingFailed();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 4: { HRESULT _r = goc_slotLoadXMLFile((*reinterpret_cast< GOCXMLEditor*(*)>(_a[1])),(*reinterpret_cast< QDomDocument*(*)>(_a[2])),(*reinterpret_cast< GOCPropertiesView*(*)>(_a[3])),(*reinterpret_cast< QPointer<GOCRegister>(*)>(_a[4])),(*reinterpret_cast< QPointer<GOCMDIView>(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 5: { HRESULT _r = goc_slotObjectCreated((*reinterpret_cast< GOCXMLObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
HRESULT GOCXMLLoadThread::goc_sigLoadingDone(QDomDocument * _t1, GOCXMLSpace * _t2, GOCMDIView * _t3)
{
    HRESULT _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
HRESULT GOCXMLLoadThread::goc_sigPercentageLoaded(int _t1)
{
    HRESULT _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
HRESULT GOCXMLLoadThread::goc_sigLoadingStart()
{
    HRESULT _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
HRESULT GOCXMLLoadThread::goc_sigLoadingFailed()
{
    HRESULT _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
