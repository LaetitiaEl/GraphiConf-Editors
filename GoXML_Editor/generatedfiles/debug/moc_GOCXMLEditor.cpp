/****************************************************************************
** Meta object code from reading C++ file 'GOCXMLEditor.h'
**
** Created: Tue Jan 25 13:32:33 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\GOCXMLEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GOCXMLEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GOCXMLEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      88,   22,   14,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     206,  198,   14,   13, 0x0a,
     224,   13,   14,   13, 0x2a,
     238,  198,   14,   13, 0x0a,
     258,   13,   14,   13, 0x2a,
     274,  198,   14,   13, 0x0a,
     292,   13,   14,   13, 0x2a,
     306,  198,   14,   13, 0x0a,
     329,   13,   14,   13, 0x2a,
     348,  198,   14,   13, 0x0a,
     370,   13,   14,   13, 0x2a,
     388,  198,   14,   13, 0x0a,
     410,   13,   14,   13, 0x2a,
     461,  428,   14,   13, 0x0a,
     521,   13,   14,   13, 0x0a,
     551,  544,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GOCXMLEditor[] = {
    "GOCXMLEditor\0\0HRESULT\0"
    "mainXMLEditor,xmlDocument,gocPropertiesView,spRegister,spMainView\0"
    "goc_sigLoadXMLFile(GOCXMLEditor*,QDomDocument*,GOCPropertiesView*,QPoi"
    "nter<GOCRegister>,QPointer<GOCMDIView>)\0"
    "checked\0goc_loadXML(bool)\0goc_loadXML()\0"
    "goc_exportXML(bool)\0goc_exportXML()\0"
    "goc_saveGOX(bool)\0goc_saveGOX()\0"
    "goc_addNewObject(bool)\0goc_addNewObject()\0"
    "goc_copyObjects(bool)\0goc_copyObjects()\0"
    "goc_pastObjects(bool)\0goc_pastObjects()\0"
    "xmlDocument,xmlSpace,gocMainView\0"
    "goc_slotLoadingDone(QDomDocument*,GOCXMLSpace*,GOCMDIView*)\0"
    "goc_slotLoadingStart()\0window\0"
    "goc_updateActiveWindow(QMdiSubWindow*)\0"
};

const QMetaObject GOCXMLEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GOCXMLEditor,
      qt_meta_data_GOCXMLEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GOCXMLEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GOCXMLEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GOCXMLEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GOCXMLEditor))
        return static_cast<void*>(const_cast< GOCXMLEditor*>(this));
    if (!strcmp(_clname, "GOCReferencer"))
        return static_cast< GOCReferencer*>(const_cast< GOCXMLEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GOCXMLEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { HRESULT _r = goc_sigLoadXMLFile((*reinterpret_cast< GOCXMLEditor*(*)>(_a[1])),(*reinterpret_cast< QDomDocument*(*)>(_a[2])),(*reinterpret_cast< GOCPropertiesView*(*)>(_a[3])),(*reinterpret_cast< QPointer<GOCRegister>(*)>(_a[4])),(*reinterpret_cast< QPointer<GOCMDIView>(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 1: { HRESULT _r = goc_loadXML((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 2: { HRESULT _r = goc_loadXML();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 3: { HRESULT _r = goc_exportXML((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 4: { HRESULT _r = goc_exportXML();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 5: { HRESULT _r = goc_saveGOX((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 6: { HRESULT _r = goc_saveGOX();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 7: { HRESULT _r = goc_addNewObject((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 8: { HRESULT _r = goc_addNewObject();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 9: { HRESULT _r = goc_copyObjects((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 10: { HRESULT _r = goc_copyObjects();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 11: { HRESULT _r = goc_pastObjects((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 12: { HRESULT _r = goc_pastObjects();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 13: { HRESULT _r = goc_slotLoadingDone((*reinterpret_cast< QDomDocument*(*)>(_a[1])),(*reinterpret_cast< GOCXMLSpace*(*)>(_a[2])),(*reinterpret_cast< GOCMDIView*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 14: { HRESULT _r = goc_slotLoadingStart();
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        case 15: goc_updateActiveWindow((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
HRESULT GOCXMLEditor::goc_sigLoadXMLFile(GOCXMLEditor * _t1, QDomDocument * _t2, GOCPropertiesView * _t3, QPointer<GOCRegister> _t4, QPointer<GOCMDIView> _t5)
{
    HRESULT _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
