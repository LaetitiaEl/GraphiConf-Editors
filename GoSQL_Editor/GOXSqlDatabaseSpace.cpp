#include "StdAfx.h"
#include "GOXSqlDatabaseSpace.h"

GOXSqlDatabaseSpace::GOXSqlDatabaseSpace(QPointer<GOCMDIView> parentContainer, QPointer<GOCPropertiesView> propertiesView, QPointer<GOCRegister> spRegister, QPointer<GoSQL_Editor> spGoSQLEditor)
    : GOCSpace(parentContainer,propertiesView,spRegister)
{

}

GOXSqlDatabaseSpace::~GOXSqlDatabaseSpace()
{

}

HRESULT GOXSqlDatabaseSpace::gox_addDatabase(QPointer<GOXDatabase> spDatabase){
    MethodBegin("GOXSqlDatabaseSpace::gox_addDatabase");

    TestQPointer(spDatabase);

    //Set database's attributes
    GOCObject* gocObj = qobject_cast<GOCObject*>( spDatabase);
    QString sDatabaseName; spDatabase->gox_getDatabaseName(&sDatabaseName);    

    //Add the object to the space
    GOCSpace::goc_addObject(gocObj);

    ////Update the position of the object
    //QPointF newPos;
    //goc_getAvailablePosition(&newPos);

    //gocObj->goc_setObjectPos(newPos);

    return hRes;
}