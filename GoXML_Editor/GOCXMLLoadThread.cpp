#include "StdAfx.h"
#include "GOCXMLLoadThread.h"

GOCXMLLoadThread::GOCXMLLoadThread(GOCXMLEditor *parent):QThread(parent)
{
	//
	m_iNbLoadedObject	= 0;
	m_iTotalObjectToLoad	= 0;

}

GOCXMLLoadThread::~GOCXMLLoadThread(void)
{
}

//void GOCXMLLoadThread::run(void){
//	
//}

HRESULT GOCXMLLoadThread::goc_slotLoadXMLFile(GOCXMLEditor *mainXMLEditor,
											  QDomDocument *xmlDocument,
											  GOCPropertiesView *gocPropertiesView,
											  QPointer<GOCRegister> spRegister,
											  QPointer<GOCMDIView> spMainView)
{
	MethodBegin("GOCXMLLoadThread::goc_slotLoadXMLFile");

	//Initialize the parameters of the thread to load the file
	m_mainXMLEditor = mainXMLEditor;
	m_xmlDocuement = xmlDocument;
	m_gocPropertiesView = gocPropertiesView;
	m_spRegister = spRegister;
	m_gocMainView = spMainView;	

	return hRes;
}

HRESULT GOCXMLLoadThread::goc_slotObjectCreated(GOCXMLObject* xmlObject){
	MethodBegin("GOCXMLLoadThread::run");
	
	//
	m_iNbLoadedObject++;

	//Notify the loading view
	int percentage;
	if(m_iTotalObjectToLoad != 0)
		percentage = (100 * m_iNbLoadedObject)/m_iTotalObjectToLoad;
	emit goc_sigPercentageLoaded(percentage);

	return hRes;
}
HRESULT GOCXMLLoadThread::goc_countTotalChildNodes(QDomNode domNode,int *iTotalNodes){
	MethodBegin("GOCXMLLoadThread::goc_countTotalChildNodes");
	
	int nbNodes = 0;

	QDomNodeList domNodeList;
	domNodeList = domNode.childNodes();

	nbNodes = domNodeList.count();
	*iTotalNodes += nbNodes;
	
	for(int i = 0; i<nbNodes;i++){
		int iNbNodes = 0;
		goc_countTotalChildNodes(domNodeList.item(i),&iNbNodes);	
		if(domNodeList.item(i).isText()){
			*iTotalNodes = *iTotalNodes-1;
		}
		*iTotalNodes +=	iNbNodes;
	}

	return hRes;
}

void GOCXMLLoadThread::goc_setFileName(QString fileName){
	MethodBegin("GOCXMLLoadThread::goc_setFileName");
	m_sFileName = fileName;
}

void GOCXMLLoadThread::goc_getFileName(QString *fileName){
	MethodBegin("GOCXMLLoadThread::goc_getFileName");
	*fileName =m_sFileName;
}

void GOCXMLLoadThread::run(void){
	MethodBegin("GOCXMLLoadThread::run");
	if(m_xmlDocuement == NULL){
		return;
	}

	//Get the number of nodes(objects) in the xml	
	goc_countTotalChildNodes(*m_xmlDocuement,&m_iTotalObjectToLoad);
	//Here is the loading thread process
	emit goc_sigLoadingStart();

	//Create spaces and objects
	GOCXMLSpace *gocSpace = new GOCXMLSpace(m_xmlDocuement,
		m_gocMainView,m_gocPropertiesView,m_spRegister);

	gocSpace->goc_moveToThread(m_gocMainView);

 	//emit the loading done signal
	emit goc_sigLoadingDone(m_xmlDocuement,gocSpace,m_gocMainView);
	//exec();
}
