#include "StdAfx.h"
#include "GOXSqlDatabaseTableSpace.h"

GOXSqlDatabaseTableSpace::GOXSqlDatabaseTableSpace(QPointer<GOCMDIView> parentContainer, QPointer<GOCPropertiesView> propertiesView, QPointer<GOCRegister> spRegister, QPointer<GoSQL_Editor> spGoSQLEditor)
    : GOCSpace(parentContainer,propertiesView,spRegister)
{

}

GOXSqlDatabaseTableSpace::~GOXSqlDatabaseTableSpace()
{

}

//! DatabaseTable selected
void GOXSqlDatabaseTableSpace::goc_slotObjectSelected(QPointer<GOCObject> objectSelected, bool bIsSelected){
    MethodBegin("GOXSqlDatabaseTableSpace::goc_slotObjectSelected");
    if(m_spPropertiesView.isNull() || objectSelected.isNull())
		return;//TODO: trace error
	
    //Get the COXDatabaseTable object
    GOXDatabaseTable *pGoxDbTble = qobject_cast<GOXDatabaseTable *>(objectSelected.data());
    TestPointerVoid(pGoxDbTble);
    
    //Get the database table model
    GOXDatabaseTableModel *pDatabaseTableModel = 0;
    pGoxDbTble->gox_getDatabaseTableModel(&pDatabaseTableModel);
    TestPointerVoid(pDatabaseTableModel);

	//Display the content of the table in the properties view
    m_spPropertiesView->setModel(pDatabaseTableModel); 
    QString sTableName;
    pGoxDbTble->gox_getTableName(&sTableName);
    m_spPropertiesView->setWindowTitle(sTableName);    

	//update the selected objects list:
	if(bIsSelected){		
		//Add it to the selected objects' list
		m_listSelectedGOCObject.insert(objectSelected->goc_getObjectID(),objectSelected);
		
		m_spLastSelectedObject = objectSelected;
	}else{
		m_listSelectedGOCObject.remove(objectSelected->goc_getObjectID());
	}
}


