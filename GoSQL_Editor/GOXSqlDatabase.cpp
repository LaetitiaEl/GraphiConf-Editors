#include "StdAfx.h"
#include "GOXSqlDatabase.h"

GOXSqlDatabase::GOXSqlDatabase(QPointer<GOCSpace> parent,QString sHost, QString sDatabaseName, QString sType, QString sUserName, QString sPassword, int iPort)
    : GOXDatabase(parent,sHost, sDatabaseName, sType, sUserName, sPassword, iPort)
{   

    //Create the main window
    m_spTablesMainWindow = new QMainWindow(0);
    
    //Create the container of the data tables objects
    m_spMdiTablesView = new GOCMDIView(0,m_spTablesMainWindow);
    
    //Create the tables' data view
    m_spTablesPropertiesView = new GOCPropertiesView(m_spTablesMainWindow);
    
    //Add the tables properties view to the main view
    QDockWidget *dockProperties = new QDockWidget("Table Data", 0);
    dockProperties->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockProperties->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable );
    dockProperties->setWidget(m_spTablesPropertiesView);
    m_spTablesMainWindow->addDockWidget(Qt::RightDockWidgetArea, dockProperties);

    //Create the user's attributes for the database:
    gox_initDatabaseAttributes();
}

GOXSqlDatabase::~GOXSqlDatabase()
{
    //Todo destroy pointers
    if(!m_spTablesMainWindow.isNull())
        delete m_spTablesMainWindow;
}

//! Connection/disconnection to database
HRESULT GOXSqlDatabase::gox_databaseConnect(){
    MethodBegin("GOXSqlDatabase::gox_databaseConnect");

    if(m_sqlDataBase.isOpen())
        return S_OK;

    bool ok = m_sqlDataBase.open();

    if(!ok)
        return GOC_FAIL;

    //Check if there are tables in the database:
    QSqlQuery query(QSqlDatabase::database(m_sConnectionName));
    if(!query.exec("SHOW TABLES")){
        QString stest = query.lastError().text();
        TraceAndReturnError(query.lastError());
    }
    
    //Create a subspace of the object
    goc_setObjectSubbed2(false);//Temporary solution
    goc_setObjectSubbed2(true);
    QPointer<GOCSpace> spObjectSpace;
    goc_getObjectSpace(&spObjectSpace);
    TestQPointer(spObjectSpace);

    //Create the GOXDatabaseTables in the subspace
    while (query.next()) {
        QString sTableName = query.value(0).toString();
        qDebug()<< sTableName;
        
        GOXDatabaseTable *goxDataTable = new GOXDatabaseTable(spObjectSpace,sTableName,m_sConnectionName);
        GOXDatabaseTableModel *pDatabaseTableModel;
        goxDataTable->gox_getDatabaseTableModel(&pDatabaseTableModel);    

        pDatabaseTableModel->gox_databaseTableModelRefresh();

        //Access strategy to the database
        pDatabaseTableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        
        spObjectSpace->goc_addObject(goxDataTable);
    }

    //Propagate to object model - "Connected" attribute
    goc_setAttribute(GOX_ATT_CONNECTED,QVariant(true),true);
    return hRes;
}

//! Set object subbed
void GOXSqlDatabase::goc_setObjectSubbed2(bool bIsObjectSubbed){
	if(m_ObjectSubbed == bIsObjectSubbed)
		return;

        if(bIsObjectSubbed){
            //create a subspace
            QPointer<GOCSpace> spParentSpace;
            goc_getSpaceParent(&spParentSpace);
            if(spParentSpace.isNull())
                return;//TODO: trace
            if(m_spObjectSpace.isNull()){
                QPointer<GOCMDIView> spMainView;
                spParentSpace->goc_getMainView(&spMainView);

                QPointer<GOCPropertiesView> spPropView;
                spParentSpace->goc_getPropertiesView(&spPropView);

                QPointer<GOCRegister> spRegister;
                spParentSpace->goc_getRegister(&spRegister);

                GOXSqlDatabaseTableSpace *spObjectSpace = new GOXSqlDatabaseTableSpace(spMainView,spPropView,spRegister);
                m_spObjectSpace = qobject_cast<GOCSpace*>(spObjectSpace);
            }

            //set background color to gray
            goc_setBackGroundColor(m_backGroundColorSub);
        }else{
            m_spObjectSpace->goc_deleteObjectAll();

            //set background color to white
            goc_setBackGroundColor(m_backGroundColorNoSub);
        }

	m_ObjectSubbed = bIsObjectSubbed;
}

//! Double click handler
void GOXSqlDatabase::goc_slotDoubleClicked(void){
    MethodBegin("GOCMultiObject::goc_slotDoubleClicked")

    //Init the view container of the space and create the space view if it doesn't exist
    QPointer<GOCSpaceView> spSpaceView;
    m_spObjectSpace->goc_setMainView(m_spMdiTablesView,true);
    hRes = m_spObjectSpace->goc_createSpaceView(&spSpaceView,m_spMdiTablesView);

    //Add the space view to the MDI view which is the container view of the space
    m_spMdiTablesView->goc_addSpaceView(spSpaceView);
    m_spMdiTablesView->show();
    m_spMdiTablesView->activateWindow();        
    //->Doc the MDI view to the main view
    m_spTablesMainWindow->setCentralWidget(m_spMdiTablesView);
    m_spTablesMainWindow->setWindowTitle(objectName());

    //Set the properties view of the data tables objects
    m_spObjectSpace->goc_setPropertiesView(m_spTablesPropertiesView,true);

    //Display the Tables Main view
    m_spTablesMainWindow->show();     

}

//! Rightclick handled
void	GOXSqlDatabase::goc_slotMouseRightClick(QPointF position){
    MethodBegin("GOXSqlDatabase::goc_slotMouseRightClick");
    
    QMenu menuObject("Database");
	
    //Initialize the actions
    gox_initObjectActions();
	
    //Connect/Disconnect
	bool bIsConnected = false;
    bIsConnected =m_sqlDataBase.isOpen();
	if(!bIsConnected){		
		//Connect
		menuObject.addAction(m_actConnect);	
	}else{		
		//Disconnect
		menuObject.addAction(m_actDisconnect);	

	}			
	
	//Display
	QPoint point = QCursor::pos();
	menuObject.exec(point);

}

//Create the user's attributes of the database:
HRESULT GOXSqlDatabase::gox_initDatabaseAttributes(void){    
    MethodBegin("GOXSqlDatabase::gox_initDatabaseAttributes");
    //TODO remove?
    return hRes;
}

//! Init database menu's actions
HRESULT GOXSqlDatabase::gox_initObjectActions(void){
	MethodBegin("GOCObject::gox_initObjectActions");
	if(m_bIsActInit)
        return S_OK;
    
    //Init m_actConnect
    m_actConnect = new QAction(tr("&Connect"), this);
	m_actConnect->setStatusTip(tr("Connect the database"));
	connect(m_actConnect, SIGNAL(triggered()), this, SLOT(gox_databaseConnect()));

    //Init m_actDisconnect
    m_actDisconnect = new QAction(tr("&Disconnect"), this);
	m_actDisconnect->setStatusTip(tr("Disconnect the database"));
	connect(m_actDisconnect, SIGNAL(triggered()), this, SLOT(gox_databaseDisconnect()));
    
    m_bIsActInit = true;
	return hRes;
}
