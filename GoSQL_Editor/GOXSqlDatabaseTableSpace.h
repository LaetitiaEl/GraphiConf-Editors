#ifndef GOXSQLDATABASETABLESPACE_H
#define GOXSQLDATABASETABLESPACE_H

//GOX include
#include "../GOC_Framework/GOCSpace.h"
#include "../GOC_Framework/GOCObject.h"
#include "../GOC_Framework/GOXDatabaseTable.h"
#include "GoSQL_Editor.h"
class GoSQL_Editor;

class GOXSqlDatabaseTableSpace : public GOCSpace
{
    Q_OBJECT

public:
    GOXSqlDatabaseTableSpace(QPointer<GOCMDIView> parentContainer = 0, QPointer<GOCPropertiesView> propertiesView = 0, QPointer<GOCRegister> spRegister = 0, QPointer<GoSQL_Editor> spGoSQLEditor = 0);
    virtual ~GOXSqlDatabaseTableSpace();

public:
    //! DatabaseTable selected
	virtual void goc_slotObjectSelected(QPointer<GOCObject> objectSelected, bool bIsSelected);

private:
    
};

#endif // GOXSQLDATABASETABLESPACE_H
