#ifndef GOXSQLDATABASESPACE_H
#define GOXSQLDATABASESPACE_H

//GOX includes
#include "GoSQL_Editor.h"
#include "../GOC_Framework/GOCSpace.h"
#include "../GOC_Framework/GOXDatabase.h"

class GOCSpace;
class GoSQL_Editor;

class GOXSqlDatabaseSpace : public GOCSpace
{
    Q_OBJECT

public:
    GOXSqlDatabaseSpace(QPointer<GOCMDIView> parentContainer = 0, QPointer<GOCPropertiesView> propertiesView = 0, QPointer<GOCRegister> spRegister = 0, QPointer<GoSQL_Editor> spGoSQLEditor = 0);
    virtual ~GOXSqlDatabaseSpace();

public:
    HRESULT gox_addDatabase(QPointer<GOXDatabase> spDatabase);

private:
    
};

#endif // GOXSQLDATABASESPACE_H
