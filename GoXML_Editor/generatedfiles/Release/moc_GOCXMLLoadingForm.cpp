/****************************************************************************
** Meta object code from reading C++ file 'GOCXMLLoadingForm.h'
**
** Created: Fri Jan 21 15:59:14 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\GOCXMLLoadingForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GOCXMLLoadingForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GOCXMLLoadingForm[] = {

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
      45,   27,   19,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GOCXMLLoadingForm[] = {
    "GOCXMLLoadingForm\0\0HRESULT\0iPercentageLoaded\0"
    "goc_slotPercentageLoaded(int)\0"
};

const QMetaObject GOCXMLLoadingForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GOCXMLLoadingForm,
      qt_meta_data_GOCXMLLoadingForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GOCXMLLoadingForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GOCXMLLoadingForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GOCXMLLoadingForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GOCXMLLoadingForm))
        return static_cast<void*>(const_cast< GOCXMLLoadingForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int GOCXMLLoadingForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { HRESULT _r = goc_slotPercentageLoaded((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HRESULT*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
