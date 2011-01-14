#include ".\GOC_Framework\stdafx.h"

//QT includes
#include <QtGui/QApplication>
//GOC includes
#include "GOCXMLObject.h"
#include "GOCXMLSpace.h"
#include "GOCXMLEditor.h"
#include "GOCXMLLoadingForm.h"
#include ".\GOC_Framework\GOCObjectMgr.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
        //Set the icon of the application
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/media/logo/GoC_XML_Editor_Logo"), QSize(), QIcon::Normal, QIcon::On);
        a.setWindowIcon(icon);

        //Set the application name
        a.setApplicationName("GoXML Editor");

        //Set the application version
        a.setApplicationVersion("1.2.0");


	//-->Create the register
	GOCRegister *pRegister = new GOCRegister(&a);
	QPointer<GOCRegister> spRegister(pRegister);

	//-->GOC Object Manager
	GOCObjectMgr	*pObjMgr = new GOCObjectMgr(&a, spRegister);

	//-->Create the main window
        GOCXMLEditor *mainXMLWindow = new GOCXMLEditor(0,pRegister,0,0);
	mainXMLWindow->show(); 
        mainXMLWindow->setWindowTitle("GoXML Editor");
	
	return a.exec();
}
