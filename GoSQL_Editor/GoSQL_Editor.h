#ifndef GOSQL_EDITOR_H
#define GOSQL_EDITOR_H

//Qt Includes
#include <QtGui/QApplication>
#include <QtSql>
#include "ui_GoSQL_Editor.h"
//GOX Includes
#include "GoSQL_Editor.h"
#include "GOXSqlDatabase.h"
#include "GOXSqlDatabaseSpace.h"
#include "../GOC_Framework/GOXDatabase.h"
#include "../GOC_Framework/GOXDatabaseTable.h"
#include "../GOC_Framework/GOCSpace.h"
#include "../GOC_Framework/GOCMDIView.h"
class GOXSqlDatabaseSpace;

class GoSQL_Editor : public QMainWindow
{
	Q_OBJECT

public:
	GoSQL_Editor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GoSQL_Editor();

public slots:
    //! Add a database to connect to it
	HRESULT goc_addDatabase(bool checked = false);

private:
    HRESULT gox_initMenuElements(void);

private:
	Ui::GoSQL_EditorClass ui;

    //Menu bar:
	QPointer<QMenuBar>			m_spMenuBar;

    //->Menu File
	QPointer<QMenu>				m_spMenuFile;
	//-->Action Loading
	QPointer<QAction>			m_spActAddDB;	
    //-->Action Exit
    QPointer<QAction>			m_spActExit;
    
    //The databases properties view:
    QPointer<GOCPropertiesView> m_spDatabasesPropertiesView;

    //The databases space:
    QPointer<GOXSqlDatabaseSpace> m_spDatabasesSpace;
};

#endif // GOSQL_EDITOR_H
