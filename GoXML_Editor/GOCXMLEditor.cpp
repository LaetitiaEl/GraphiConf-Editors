#include "StdAfx.h"
#include "GOCXMLEditor.h"

GOCXMLEditor::GOCXMLEditor(QWidget *parent,QPointer<GOCRegister> spGocRegister,GOCXMLLoadThread *thrXMLLoad, Qt::WFlags flags)
	: QMainWindow(parent, flags),GOCReferencer(spGocRegister)
{
	MethodBegin("GOCXMLEditor::GOCXMLEditor");

	//Init the xml document
	m_xmlDocument = NULL;//= new QDomDocument("GOC XML DOC");

	//Init the loading file thread:
	m_thrLoadFile = thrXMLLoad;

	//Init the loading form:
	m_formLoading = new GOCXMLLoadingForm();	

	//Init properties view
    m_spPropertiesView = new GOCXMLPropertiesView(0);        
	QDockWidget *dockProperties = new QDockWidget("Properties", 0);
    dockProperties->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockProperties->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable );
    dockProperties->setWidget(m_spPropertiesView);    
    addDockWidget(Qt::RightDockWidgetArea, dockProperties);

	
    //
    //Create the main view
    m_spMainView = new GOCMDIView(0, 0); //->DEPRECATED
    //setCentralWidget(m_spMainView);
    //m_spMainView->setViewMode(QMdiArea::TabbedView);
    //m_spMainView->setTabShape(QTabWidget::Triangular);

    //Init the multispace view:
    m_spMultiSpace = new GOCMultiSpace(m_spMainView,m_spPropertiesView,spGocRegister,this);
    QPointer<GOCSpaceView> spMultiSpaceView;
    m_spMultiSpace->goc_getSpaceView(&m_spMultiSpaceView);	
    TestQPointerVoid(m_spMultiSpaceView);
    m_spMultiSpaceView->scene()->setSceneRect(0,0,100,100);

    QDockWidget *dockMultiSpace = new QDockWidget("Loaded Files", this);
    dockMultiSpace->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockMultiSpace->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable );
    dockMultiSpace->setWidget(m_spMultiSpaceView);
    //addDockWidget(Qt::LeftDockWidgetArea, dockMultiSpace);
    dockMultiSpace->setMinimumSize(200,480);

    m_spMultiSpaceView->setMinimumSize(200,480);
    setCentralWidget(m_spMultiSpaceView);


    //Set the ICON of the window
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/media/logo/GoXML_Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
    setWindowIcon(icon);

    //Initialize the Menu Bar element
    hRes = goc_InitMenuElements();
    IfErrorTrace("goc_InitMenuElements Failed");

    setAttribute(Qt::WA_DeleteOnClose);
}

GOCXMLEditor::~GOCXMLEditor()
{
	delete m_xmlDocument;
	delete m_thrLoadFile;
	delete m_spPropertiesView;
        delete m_spMultiSpace;
	if(m_formLoading!=NULL)
		delete m_formLoading;
}

//Initialize the menu bar elements
HRESULT	GOCXMLEditor::goc_InitMenuElements(void){
	MethodBegin("GOCXMLEditor::goc_InitMenuElements");
	
	//->Menu Bar
	m_spMenuBar = menuBar();
	if(m_spMenuBar.isNull()){
		TraceAndReturnError("m_spMenuBar NULL");
	}
	//-->Add File Menu
	m_spMenuFile = m_spMenuBar->addMenu(tr("&File"));
	TestQPointer(m_spMenuFile);

	//--->Action: Load XML
	m_spActLoad = new QAction(tr("&Load File"), this);
	TestQPointer(m_spActLoad);

	m_spActLoad->setShortcuts(QKeySequence::Open);
	m_spActLoad->setStatusTip(tr("Load a new file"));	
	
	m_spMenuFile->addAction(m_spActLoad);	

	connect(m_spActLoad, SIGNAL(triggered(bool)), this, SLOT(goc_loadXML(bool)));

	
	//--->Action: Save GOX
	m_spActSaveGox = new QAction(tr("&Save GOX"), this);
	TestQPointer(m_spActLoad);

	m_spActSaveGox->setShortcuts(QKeySequence::Save);
	m_spActSaveGox->setStatusTip(tr("Save the objects and sub-objects"));	
        m_spActSaveGox->setDisabled(true);
	
	m_spMenuFile->addAction(m_spActSaveGox);	

	connect(m_spActSaveGox, SIGNAL(triggered(bool)), this, SLOT(goc_saveGOX(bool)));

	//--->Action: Export XML
	m_spActExport = new QAction(tr("&Export XML"), this);
	TestQPointer(m_spActExport);

	m_spActExport->setShortcuts(QKeySequence::SaveAs);
	m_spActExport->setStatusTip(tr("Export xml file"));
	m_spActExport->setDisabled(true);

	m_spMenuFile->addAction(m_spActExport);

	connect(m_spActExport, SIGNAL(triggered(bool)), this, SLOT(goc_exportXML(bool)));

        //--->Action: Exit
        m_spActExit = new QAction(tr("&Exit"), this);
        TestQPointer(m_spActExit);

        m_spActExit->setShortcuts(QKeySequence::Quit);
        m_spActExit->setStatusTip(tr("Export xml file"));

        m_spMenuFile->addAction(m_spActExit);

        connect(m_spActExit, SIGNAL(triggered()), this, SLOT(close()));

	//-->Add Edit Menu
	m_spMenuEdit = m_spMenuBar->addMenu(tr("&Edit"));
	TestQPointer(m_spMenuEdit);

	//--->Action: Add Object (XML Node)
	m_spActAdd = new QAction(tr("&Add Node"), this);
	TestQPointer(m_spActAdd);

	m_spActAdd->setShortcuts(QKeySequence::New);
	m_spActAdd->setStatusTip(tr("Add a new node"));	
	
	m_spMenuEdit->addAction(m_spActAdd);	

	connect(m_spActAdd, SIGNAL(triggered(bool)), this, SLOT(goc_addNewObject(bool)));

	//--->Action: Copy Objects
	m_spActCopy = new QAction(tr("&Copy"), this);
	TestQPointer(m_spActCopy);

	m_spActCopy->setShortcuts(QKeySequence::Copy);
	m_spActCopy->setStatusTip(tr("Copy selected object"));	
	
	m_spMenuEdit->addAction(m_spActCopy);	

	connect(m_spActCopy, SIGNAL(triggered(bool)), this, SLOT(goc_copyObjects(bool)));

	//--->Action: Past Objects
	m_spActPast = new QAction(tr("&Past"), this);
	TestQPointer(m_spActPast);

	m_spActPast->setShortcuts(QKeySequence::Paste);
	m_spActPast->setStatusTip(tr("Past copied node"));	
	
	m_spMenuEdit->addAction(m_spActPast);	

	connect(m_spActPast, SIGNAL(triggered(bool)), this, SLOT(goc_pastObjects(bool)));


	return hRes;
}

//SLOTS: Begin
//! Update the active window
void    GOCXMLEditor::goc_updateActiveWindow(QMdiSubWindow * window){
    if(window == NULL)
        return;// we keep only non null sub windows

    m_pLastActiveSubWindow = window;
}

HRESULT GOCXMLEditor::goc_loadXML(bool checked){
	MethodBegin("GOCXMLEditor::goc_loadXML");
	//TODO: if the loading isn't complete, destroy what was created
	
	//Create a thead to load the file
        m_thrLoadFile = new GOCXMLLoadThread();
	
	//Connect the load action to thread
	connect(this,SIGNAL(goc_sigLoadXMLFile(GOCXMLEditor *,QDomDocument*,GOCPropertiesView *,QPointer<GOCRegister>, QPointer<GOCMDIView>)), m_thrLoadFile, SLOT(goc_slotLoadXMLFile(GOCXMLEditor *,QDomDocument*,GOCPropertiesView *,QPointer<GOCRegister>, QPointer<GOCMDIView>)));
	//Connect the loading done to thead
	connect(m_thrLoadFile,SIGNAL(goc_sigLoadingStart()), this, SLOT(goc_slotLoadingStart()));		
	connect(m_thrLoadFile,SIGNAL(goc_sigLoadingDone(QDomDocument *,GOCXMLSpace *,GOCMDIView *)), this, SLOT(goc_slotLoadingDone(QDomDocument *,GOCXMLSpace *,GOCMDIView *)));		
	//Connect the loading thread to the loading form
	connect(m_thrLoadFile,SIGNAL(goc_sigPercentageLoaded(int)), m_formLoading, SLOT(goc_slotPercentageLoaded(int)));				
	
	//Create a new xml doc:	
        QString fileName = QFileDialog::getOpenFileName(0,"Export XML File",m_sLastUsedFolder,"XML file (*.xml);;GOX file (*.gox);;Any file (*.*)");
	if (!fileName.isEmpty()) {
                m_sLastUsedFolder = fileName;
		m_xmlDocument = new QDomDocument();
		//Load the xml
		QFile file(fileName);
		if (file.open(QIODevice::ReadOnly)){

			if (m_xmlDocument->setContent(&file)) {

			}
			file.close();
		}
	}else{
		return GOC_FAIL;
	}

	//Create the MDI Space View
        GOCMDIView *pMdiSpaceView = new GOCMDIView(m_spMainView);
        pMdiSpaceView->setAttribute(Qt::WA_DeleteOnClose, false);
	pMdiSpaceView->setWindowTitle(fileName);
	pMdiSpaceView->setViewMode(QMdiArea::TabbedView);
	pMdiSpaceView->setTabShape(QTabWidget::Triangular);

	//-->init the thread
	m_thrLoadFile->goc_setFileName(fileName);	
	emit goc_sigLoadXMLFile(this,m_xmlDocument,m_spPropertiesView,m_spRegister,pMdiSpaceView);	
	//-->start the thread
	m_thrLoadFile->start();
        m_thrLoadFile->setPriority(QThread::LowPriority);

	return hRes;
}
//Loading start:
HRESULT GOCXMLEditor::goc_slotLoadingStart(void){
	MethodBegin("GOCXMLEditor::goc_slotLoadingDone");
	
	//Display the loading view:
	if(m_formLoading != NULL){
		m_formLoading->show();
	}

	return hRes;
}

//Loading done:
HRESULT GOCXMLEditor::goc_slotLoadingDone(QDomDocument *xmlDocument,
                                                                                  GOCXMLSpace *gocLoadedSpace,
										  GOCMDIView *gocMdiSpaceView)
{
	MethodBegin("GOCXMLEditor::goc_slotLoadingDone");
	
	//Init the XML Doc
	m_xmlDocument = xmlDocument;
	TestPointer(m_xmlDocument);

	//Add the MDI Space view to the main view
	TestPointer(gocMdiSpaceView);	
	//m_spMainView->goc_addMdiSpaceView(gocMdiSpaceView);
	//gocMdiSpaceView->show();

        //->Add the object file to the multi space view
        QPointer<GOCMultiObject>  spGocObject = new GOCMultiObject(m_spMultiSpace.data(),m_spMainView);
        hRes = spGocObject->goc_setObjectSpace(gocLoadedSpace);
	IfErrorTraceReturn("spGocObject->goc_setObjectSpace failed");
	
	QString fileName;
	m_thrLoadFile->goc_getFileName(&fileName);
	m_spMultiSpace->goc_addObjectFile(spGocObject, fileName);

	//->Set the root max objet = 1
	QPointer<GOCSpace> spObjSpace;
	spGocObject->goc_getObjectSpace(&spObjSpace);
	if(!spObjSpace.isNull()){
		spObjSpace->goc_setMaxObjects(1);
		spObjSpace->setObjectName(tr("Main Root"));
	}		

	//Stop the thead which loaded the file
	m_thrLoadFile->terminate();

	//Hide the loading view
	m_formLoading->hide();

	//Display the Export Action:
	m_spActExport->setEnabled(true);
        m_spActSaveGox->setEnabled(true);
	return hRes;
}

HRESULT GOCXMLEditor::goc_exportXML(bool checked){
	MethodBegin("GOCXMLEditor::goc_exportXML");

	QPointer<GOCObject> spLastSelectedObject;
	m_spMultiSpace->goc_getLastSelectedObject(&spLastSelectedObject);
	
	QPointer<GOCObject> spObjectToSave;
	GOCXMLObject	*xmlObject;
	if(!spLastSelectedObject.isNull()){
		spObjectToSave = spLastSelectedObject->goc_getObjectChildren().value(1);
		xmlObject = qobject_cast<GOCXMLObject *>(spObjectToSave.data());
	}else{
		QMessageBox msgBox(QMessageBox::Critical, tr("Error!"),tr("No item selected from Loaded Elements window"),QMessageBox::Ok);
		msgBox.exec();
		TestQPointer(spLastSelectedObject);
	}

	if(spObjectToSave.isNull() || xmlObject == NULL){
		QMessageBox msgBox(QMessageBox::Warning, tr("Warning"),tr("The selected element is empty."),QMessageBox::Ok);
		msgBox.exec();
	}
	

        QString fileName = QFileDialog::getSaveFileName(0,"Export XML File",m_sLastUsedFolder,"XML file (*.XML);;Any file (*.*)");
	if (!fileName.isEmpty()) {
                m_sLastUsedFolder = fileName;
		QFile file(fileName);
		if (file.open(QFile::WriteOnly | QFile::Text) && m_xmlDocument != NULL){

			const int IndentSize = 4;
			
			if(!spObjectToSave.isNull()){
				
				//Build the GOX xml element
				QDomDocument domDoc;
				QDomElement goxElement;
				
				goxElement = domDoc.createElement("GOCObject");			

				hRes = xmlObject->goc_buildGOXElement(goxElement,false);
				IfErrorTraceReturn("goc_buildGOXElement failed");

				//Remove the ObjectNodeName Attributes
				goc_convertToSimpleXML(goxElement);
				domDoc.appendChild(goxElement);

				//Save the xml to the selected file
				const int IndentSize = 4;//??
				QTextStream outXML(&file);
				domDoc.save(outXML, IndentSize);

				//hRes = spObjectToSave->goc_saveObject(fileName,false);
				//IfErrorTraceReturn("spLastSelectedObject->goc_saveObject failed");
			}else{
				//We create an empty file
			}

			file.close();
		}
	}else{
		return GOC_FAIL;
	}	
	
	return hRes;
}


HRESULT GOCXMLEditor::goc_saveGOX(bool checked){
	MethodBegin("GOCXMLEditor::goc_saveGOX");
	
	QPointer<GOCObject> spLastSelectedObject;
	m_spMultiSpace->goc_getLastSelectedObject(&spLastSelectedObject);
	
	QPointer<GOCObject> spObjectToSave;
	if(!spLastSelectedObject.isNull()){
		spObjectToSave = spLastSelectedObject->goc_getObjectChildren().value(1);
	}else{
		QMessageBox msgBox(QMessageBox::Critical, tr("Error!"),tr("No item selected from Loaded Elements window"),QMessageBox::Ok);
		msgBox.exec();
		TestQPointer(spLastSelectedObject);
	}

	if(spObjectToSave.isNull()){
		QMessageBox msgBox(QMessageBox::Warning, tr("Warning"),tr("The selected element is empty."),QMessageBox::Ok);
		msgBox.exec();
	}
	

        QString fileName = QFileDialog::getSaveFileName(0,"Save GOX File",m_sLastUsedFolder,"GOX file (*.gox)");
	if (!fileName.isEmpty()) {
                m_sLastUsedFolder = fileName;
		QFile file(fileName);
		if (file.open(QFile::WriteOnly | QFile::Text) && m_xmlDocument != NULL){

			const int IndentSize = 4;
			
			if(!spObjectToSave.isNull()){
				hRes = spObjectToSave->goc_saveObject(fileName);
				IfErrorTraceReturn("spLastSelectedObject->goc_saveObject failed");
			}else{
				//We create an empty file
			}

			file.close();
		}
	}else{
		return GOC_FAIL;
	}	
	
	return hRes;
}
HRESULT GOCXMLEditor::goc_addNewObject(bool checked){
	MethodBegin("GOCXMLEditor::goc_addNewObject");
	
	//Get the active xmlspace
	QMdiSubWindow *pActiveWindow =  m_spMainView->activeSubWindow();
        if(pActiveWindow == NULL && m_pLastActiveSubWindow.isNull()){
		QMessageBox msgBox(QMessageBox::Warning, tr("Can't create object"),tr("Select a window where to create an object."),QMessageBox::Ok);
		msgBox.exec();
		TestPointer(pActiveWindow);
        }else if(pActiveWindow == NULL){

            pActiveWindow = m_pLastActiveSubWindow.data();
        }

	GOCSpaceView *pSpaceView = qobject_cast<GOCSpaceView*>(pActiveWindow->widget());
	if(pSpaceView == NULL){
		QMessageBox msgBox(QMessageBox::Critical, tr("Unknow Error"),tr("Object can't be created."),QMessageBox::Ok);
		msgBox.exec();
		TestPointer(pSpaceView);
	}

	QPointer<GOCSpace> spGocSpace;
	pSpaceView->goc_getSpace(&spGocSpace);
	TestQPointer(spGocSpace);

	GOCXMLSpace *pXMLSpace = qobject_cast<GOCXMLSpace*>(spGocSpace.data());
	TestPointer(pXMLSpace);
	
        //Check that we didn't reach max object
	int iMaxObject;
	pXMLSpace->goc_getMaxObjects(&iMaxObject);
	int iNbCreated;
	pXMLSpace->goc_getNbCreatedObjects(&iNbCreated);
	
        if(iMaxObject>iNbCreated || iMaxObject == -1){

		//Add object to the active space
		QDomElement xmlElement;
		QDomDocument doc;
		xmlElement = doc.createElement("NewObject");
		pXMLSpace->goc_addXMLObject(xmlElement);

	}else{
		QString sMsg = "We can't create more objects max["+QVariant(iMaxObject).toString()+"] created["+QVariant(iNbCreated).toString()+"].";
		
		QMessageBox msgBox(QMessageBox::Warning, tr("Max Number Objects Reached"),sMsg,QMessageBox::Ok);
		msgBox.exec();
	}

	return hRes;
}

HRESULT GOCXMLEditor::goc_copyObjects(bool checked){
	MethodBegin("GOCXMLEditor::goc_copyObject");
	
	//Get the active xmlspace
	QMdiSubWindow *pActiveWindow =  m_spMainView->activeSubWindow();
	if(pActiveWindow == NULL){
                pActiveWindow = m_pLastActiveSubWindow.data();
            //return GOC_FAIL;
	}

	GOCSpaceView *pSpaceView = qobject_cast<GOCSpaceView*>(pActiveWindow->widget());
	if(pSpaceView == NULL){
		return GOC_FAIL;
	}

	QPointer<GOCSpace> spGocSpace;
	pSpaceView->goc_getSpace(&spGocSpace);
	TestQPointer(spGocSpace);

	GOCXMLSpace *pXMLSpace = qobject_cast<GOCXMLSpace*>(spGocSpace.data());
	TestPointer(pXMLSpace);
	
	//
	pXMLSpace->goc_copySelectedObjects();

	return hRes;
}

HRESULT GOCXMLEditor::goc_pastObjects(bool checked){
	MethodBegin("GOCXMLEditor::goc_pastObjects");
	
	//Get the active xmlspace
	QMdiSubWindow *pActiveWindow =  m_spMainView->activeSubWindow();
	if(pActiveWindow == NULL){
                pActiveWindow = m_pLastActiveSubWindow.data();
            //return GOC_FAIL;
	}

	GOCSpaceView *pSpaceView = qobject_cast<GOCSpaceView*>(pActiveWindow->widget());
	if(pSpaceView == NULL){
		return GOC_FAIL;
	}

	QPointer<GOCSpace> spGocSpace;
	pSpaceView->goc_getSpace(&spGocSpace);
	TestQPointer(spGocSpace);

	GOCXMLSpace *pXMLSpace = qobject_cast<GOCXMLSpace*>(spGocSpace.data());
	TestPointer(pXMLSpace);
	
	//
	pXMLSpace->goc_pastCopiedObjects();

	return hRes;
}
//SLOTS: End

//Convert GOX to simple XML
HRESULT GOCXMLEditor::goc_convertToSimpleXML(QDomElement xmlElement){
	MethodBegin("GOCXMLEditor::goc_convertToSimpleXML");
	
	//Define the NodeName
	QString sTagName = xmlElement.attribute(GOCOBJECT_OBJECTNODENAME);
	if(!sTagName.isEmpty())
		xmlElement.setTagName(sTagName);

	xmlElement.removeAttribute(GOCOBJECT_OBJECTNODENAME);	
	//Define the NodeValue
	QString sTagValue = xmlElement.attribute(GOCOBJECT_OBJECTNODEVALUE);
	if(!sTagValue.isEmpty()){
		
		QDomText domText = xmlElement.toDocument().createTextNode(sTagValue);		
		xmlElement.appendChild(domText);
	}

	xmlElement.removeAttribute(GOCOBJECT_OBJECTNODEVALUE);

	//Dig
	QDomNodeList listNodes = xmlElement.childNodes();
	for(int i = 0; i<listNodes.count();i++){
		goc_convertToSimpleXML(listNodes.at(i).toElement());
	}

	return hRes;
}
