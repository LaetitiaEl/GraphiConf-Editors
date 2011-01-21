#include "StdAfx.h"
#include "GOCMultiSpace.h"

GOCMultiSpace::GOCMultiSpace(QPointer<GOCMDIView> parentContainer, QPointer<GOCPropertiesView> propertiesView, QPointer<GOCRegister> spRegister, QPointer<GOCXMLEditor> spXMLEditor)
	: GOCSpace(parentContainer,propertiesView,spRegister)
{
	MethodBegin("GOCMultiSpace::GOCMultiSpace");

	//Create the Multi Space View
	m_spSpaceView = new GOCSpaceView(this,parentContainer);

        m_posAvailable.setX(0);
        m_posAvailable.setY(-100);

        //
        m_spXMLEditor = spXMLEditor;
}

GOCMultiSpace::~GOCMultiSpace()
{

}

//! Add a new File Object
HRESULT GOCMultiSpace::goc_addObjectFile(QPointer<GOCMultiObject> gocMultiObject, QString sFileName){
	MethodBegin("GOCMultiSpace::GOCMultiSpace");
	
        TestQPointer(gocMultiObject)

	//Update the object's name
	if(sFileName.isEmpty()){
		gocMultiObject->setObjectName("UnknownFile");
	}
	else{
		QStringList slistFileName;
		slistFileName= sFileName.split("\\");
		if(slistFileName.count()<=1)
			slistFileName= sFileName.split("/");
		gocMultiObject->setObjectName(slistFileName.at(slistFileName.count()-1));
	}

        sFileName.replace("/","\\");
	
        //Set the file's path attribute
        GOCObject* gocObj = qobject_cast<GOCObject*>( gocMultiObject);
        gocMultiObject->goc_AddUserAttribute(GOC_XML_ATTFILEPATH,QVariant(sFileName));

        //Add the object to the space
        GOCSpace::goc_addObject(gocObj);

        //Update the position of the object
        QPointF newPos;
        goc_getAvailablePosition(&newPos);

        gocObj->goc_setObjectPos(newPos);
	return hRes;
}

//! Get the available position
HRESULT GOCMultiSpace::goc_getAvailablePosition(QPointF *newPos){
    MethodBegin("GOCMultiSpace::goc_getAvailablePosition");

    //Last used position
    m_posAvailable.setY(m_posAvailable.y()+40);

    *newPos = m_posAvailable;

    return hRes;
}
//! Get the XMLEditor
HRESULT GOCMultiSpace::goc_getXMLEditor(QPointer<GOCXMLEditor> *spXMLEditor){
    *spXMLEditor = m_spXMLEditor;
    return S_OK;
}

HRESULT GOCMultiSpace::goc_setActiveMdiSpace(QPointer<GOCMDIView> spMdiSpace){
    if(m_spXMLEditor.isNull())
        return GOC_FAIL;

    QPointer<GOCMDIView> spMainView;
    goc_getMainView(&spMainView);

    //Remove the previous MDI Space
    QList<QMdiSubWindow*> listSubView = spMainView->subWindowList();
    for(int i=0; i<listSubView.count();i++){
        QMdiSubWindow* subWin = listSubView.at(i);
        //spMainView->removeSubWindow(subWin);
        //subWin->deleteLater();
        subWin->showMinimized();
    }

    QList<QMdiSubWindow *> listSubWin = spMainView->subWindowList();
    for(int i = 0; i<listSubWin.count();i++){
        QMdiSubWindow *pSubWin = listSubWin.at(i);

        GOCMDIView * pMdiWin = qobject_cast<GOCMDIView *>(pSubWin->widget());
        if(pMdiWin == spMdiSpace.data()){
            spMainView->setActiveSubWindow(pSubWin);
            pSubWin->showMaximized();
            //spMdiSpaceView->showMaximized();

            return S_OK;
        }
    }
}

void	GOCMultiSpace::goc_slotMouseRightClick(QPointF position){

}
