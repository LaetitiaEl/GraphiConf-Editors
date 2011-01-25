#ifndef GOXSQLDATABASE_H
#define GOXSQLDATABASE_H

#include "../GOC_Framework/GOXDatabase.h"
#include "../GOC_Framework/GOCPropertiesView.h"
#include "GOXSqlDatabaseTableSpace.h"

class GOXSqlDatabase : public GOXDatabase
{
    Q_OBJECT

public:
    GOXSqlDatabase(QPointer<GOCSpace> parent, QString sHost = "localhost", QString sDatabaseName = "gosql_db", QString sType="MYSQL", QString sUserName = "root", QString sPassword = "rootpass", int iPort = 3306);
    virtual ~GOXSqlDatabase();

public:
    virtual HRESULT gox_databaseConnect();
    virtual void	goc_setObjectSubbed2(bool bIsObjectSubbed);
        
    //! double click handler
    virtual void	goc_slotDoubleClicked(void);
    //! Right click handled
    virtual void    goc_slotMouseRightClick(QPointF position);

    //! Init menu QActions
	virtual HRESULT gox_initObjectActions(void);

private:
    HRESULT gox_initDatabaseAttributes(void);

protected:
    //! Actions
    QAction *m_actConnect;
    QAction *m_actDisconnect;

private:
    QPointer<GOCMDIView> m_spMdiTablesView;
    QPointer<GOCPropertiesView> m_spTablesPropertiesView;
    QPointer<QMainWindow> m_spTablesMainWindow;
};

#endif // GOXSQLDATABASE_H
