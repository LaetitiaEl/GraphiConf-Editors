#include "stdafx.h"
//Qt Includes
#include <QtGui/QApplication>
#include <QtSql>
//GOX Includes
#include "GoSQL_Editor.h"
#include "GOXSqlDatabase.h"
#include "GOXSqlDatabaseSpace.h"
#include "../GOC_Framework/GOXDatabase.h"
#include "../GOC_Framework/GOXDatabaseTable.h"
#include "../GOC_Framework/GOCSpace.h"
#include "../GOC_Framework/GOCMDIView.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    GoSQL_Editor *w = new GoSQL_Editor();
    w->show();  
    
	return a.exec();
}
