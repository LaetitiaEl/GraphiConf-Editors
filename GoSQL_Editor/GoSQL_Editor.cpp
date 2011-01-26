#include "stdafx.h"
#include "GoSQL_Editor.h"

GoSQL_Editor::GoSQL_Editor(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
//	ui.setupUi(this);
    MethodBegin("GoSQL_Editor::GoSQL_Editor");

    //Create the databases properties view
    m_spDatabasesPropertiesView = new GOCPropertiesView(this);

    //Create the databases space view
    m_spDatabasesSpace = new GOXSqlDatabaseSpace(0,m_spDatabasesPropertiesView,0,this);
    QPointer<GOCSpaceView> spSpaceView;
    m_spDatabasesSpace->goc_createSpaceView(&spSpaceView);
 
    //Add the Databases properties view and the space view to the main view
    //-->Properties View:
    QDockWidget *dockProperties = new QDockWidget("Database Properties", this);
    dockProperties->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockProperties->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable );
    dockProperties->setWidget(m_spDatabasesPropertiesView);
    this->addDockWidget(Qt::RightDockWidgetArea, dockProperties);
    //->Mdi databases view
    QDockWidget *dockMultiSpace = new QDockWidget("Loaded Databases", this);
    dockMultiSpace->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockMultiSpace->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable );
    dockMultiSpace->setWidget(spSpaceView);
    this->setCentralWidget(dockMultiSpace);    

    //Set the ICON of the window
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/GoSQL_Editor/Resources/GoSQL_Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
    setWindowIcon(icon);

    //Initialize the Menu Bar element
    hRes = gox_initMenuElements();
    IfErrorTrace("gox_initMenuElements Failed");

    setAttribute(Qt::WA_DeleteOnClose);
   
}

GoSQL_Editor::~GoSQL_Editor()
{
    if(!m_spDatabasesPropertiesView.isNull())
        delete m_spDatabasesPropertiesView;

    if(!m_spDatabasesSpace.isNull())
        delete m_spDatabasesSpace;

    delete m_spActAddDB;
    delete m_spActExit;
}


//! Init the menu bar elements:
HRESULT GoSQL_Editor::gox_initMenuElements(void){
    MethodBegin("GoSQL_Editor::gox_initMenuElements");
    
    //->Menu Bar
	m_spMenuBar = menuBar();
	if(m_spMenuBar.isNull()){
		TraceAndReturnError("m_spMenuBar NULL");
	}
	//-->Add File Menu
	m_spMenuFile = m_spMenuBar->addMenu(tr("&File"));
	TestQPointer(m_spMenuFile);

	//--->Action: Load XML
	m_spActAddDB = new QAction(tr("&Add Database"), this);
	TestQPointer(m_spActAddDB);

	m_spActAddDB->setShortcuts(QKeySequence::Open);
	m_spActAddDB->setStatusTip(tr("Add a database connection"));	
	
	m_spMenuFile->addAction(m_spActAddDB);	

	connect(m_spActAddDB, SIGNAL(triggered(bool)), this, SLOT(goc_addDatabase(bool)));

    //--->Action: Exit
    m_spActExit = new QAction(tr("&Exit"), this);
    TestQPointer(m_spActExit);

    m_spActExit->setShortcuts(QKeySequence::Quit);
    m_spActExit->setStatusTip(tr("Export xml file"));

    m_spMenuFile->addAction(m_spActExit);

    connect(m_spActExit, SIGNAL(triggered()), this, SLOT(close()));

    return hRes;
}

//! Add a database to connect to it
HRESULT GoSQL_Editor::goc_addDatabase(bool checked){
    MethodBegin("GoSQL_Editor::goc_addDatabase");
    
    //Create and add a database object to the databases space
    QPointer<GOXSqlDatabase> goxDatabase = new GOXSqlDatabase(m_spDatabasesSpace.data());
    m_spDatabasesSpace->gox_addDatabase(goxDatabase.data());    
    
    //TODO: make it an UnderUserObperation
    //goxDatabase->gox_databaseConnect();

    return hRes;
}
