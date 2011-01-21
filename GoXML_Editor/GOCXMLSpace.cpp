#include "StdAfx.h"
#include "GOCXMLSpace.h"

GOCXMLSpace::GOCXMLSpace(QPointer<GOCMDIView> parentContainer, QPointer<GOCPropertiesView> propertiesView,
						 QPointer<GOCRegister> spRegister)
	:GOCSpace(parentContainer,propertiesView,spRegister)
{
	m_domDocument = new QDomDocument();

}

GOCXMLSpace::GOCXMLSpace(QPointer<GOCXMLObject> parent, QPointer<GOCMDIView> parentContainer, 
						 QPointer<GOCPropertiesView> propertiesView, QPointer<GOCRegister> spRegister)
	:GOCSpace(parent.data(),parentContainer,propertiesView,spRegister)
{
	m_domDocument = new QDomDocument();
}

GOCXMLSpace::GOCXMLSpace(QDomDocument *dDomDoc, QPointer<GOCMDIView> parentContainer, 
						 QPointer<GOCPropertiesView> propertiesView, QPointer<GOCRegister> spRegister)
	:GOCSpace(parentContainer,propertiesView,spRegister),m_domDocument(dDomDoc)
{
	
	if(dDomDoc == 0){
		m_domDocument = new QDomDocument();
	}else{
		m_domDocument = dDomDoc;	
		
		//Populate the XML Space
		QDomElement docElem = m_domDocument->documentElement();
		goc_addXMLObject(docElem);
	}
}

GOCXMLSpace::~GOCXMLSpace(void)
{
	
}

//<--SLOTS: Begin
HRESULT GOCXMLSpace::goc_slotSaveSelectedObject(void){
	MethodBegin("GOCXMLSpace::goc_slotSaveSelectedObject");
	
	GOCSpace::goc_slotSaveSelectedObject();

	return hRes;
}

HRESULT GOCXMLSpace::goc_slotSpaceViewCreated(GOCSpaceView *spSpaceView){
	MethodBegin("GOCXMLSpace::goc_slotSpaceViewCreated");
	
	if(spSpaceView == NULL)
		return GOC_FAIL;
	
	//Propagate to GOCSpace
	GOCSpace::goc_slotSpaceViewCreated(spSpaceView);

	//-->Connect Signals
	//Save signal
	connect(spSpaceView,SIGNAL(goc_slotSaveSelectedObject(void)),this,SLOT(goc_slotSaveSelectedObject(void)));

	return S_OK;
}

void GOCXMLSpace::goc_createNewObject(QPointer<GOCObject> *spObjNew){
    MethodBegin("GOCXMLSpace::goc_slotSpaceViewCreated");

    //Check if we are allowed to create a new object in this space
    //->Check that we didn't reach max object
    int iMaxObject;
    goc_getMaxObjects(&iMaxObject);
    int iNbCreated;
    goc_getNbCreatedObjects(&iNbCreated);
    if(iMaxObject<=iNbCreated && iMaxObject != -1)
        return;

    //Create the new object
    //QPointer<GOCXMLObject> objNew;
    //GOCSpace::goc_createNewObject(&objNew);
    QDomElement dummyElement;
    dummyElement.setTagName("");
    GOCXMLObject *objNew = new GOCXMLObject(dummyElement,this);
    //goc_addObject(objNew);
    objNew->setObjectName("NewObject");

//    if(objNew.isNull())
//        return;
    if(spObjNew != NULL)
        *spObjNew = objNew;

    //Add XML Basic attributes
    //->ObjectNodeName:
//    GOCAttribute *gocAttNodeN = new GOCAttribute(objNew);
//    QSharedPointer<GOCAttribute> spAttNN(gocAttNodeN);
//    spAttNN->attName = GOCOBJECT_OBJECTNODENAME;
//    spAttNN->attValue = QVariant("NodeValue");
//    spAttNN->attVisible = true;
//    spAttNN->attRemovable = false;
//    objNew->goc_setAttribute(spAttNN);

//    //->ObjectNodeValue
//    GOCAttribute *gocAttNodeV = new GOCAttribute(objNew);
//    QSharedPointer<GOCAttribute> spAttNV(gocAttNodeV);
//    spAttNV->attName = GOCOBJECT_OBJECTNODEVALUE;
//    spAttNV->attValue = QVariant("");
//    spAttNV->attVisible = true;
//    spAttNV->attRemovable = false;
//    objNew->goc_setAttribute(spAttNV);
}

//SLOTS: End-->

//
void GOCXMLSpace::goc_addObject(GOCXMLObject* gocObject){
	//Add the object to the GOCSpace
	GOCSpace::goc_addObject(gocObject);
}

// Add an object to this space from a dom element
void GOCXMLSpace::goc_addXMLObject(QDomElement xmlObjectElem){
	//Create an XMLObject from the dom element - in this XMLSpace
	GOCXMLObject *xmlObj = new GOCXMLObject(xmlObjectElem,this);
	
	QDomNode nObjNode = xmlObjectElem.firstChild();
	if(!nObjNode.isNull() && !nObjNode.isText()){//TODO: manage the text case and comments
		//Create a sub space of the object - if it has child(ren)
                xmlObj->goc_setXMLObjectSubbed(true);
	}
	GOCXMLSpace *xmlObjSubSpace = xmlObj->goc_getXMLObjectSpace();
	while(!nObjNode.isNull()) {
		
		QDomElement e = nObjNode.toElement(); // try to convert the node to an element.
		
		if(!nObjNode.isText()){
			//Add a new object
			xmlObjSubSpace->goc_addXMLObject(e);
		}else{
			//Update the node value
			QString sNodeValue = nObjNode.nodeValue();
			QVariant vNodeValue = QVariant(sNodeValue);
                        GOCAttribute *gocAtt = new GOCAttribute(xmlObj);
                        QSharedPointer<GOCAttribute> spAtt(gocAtt);
                        spAtt->attName = GOCOBJECT_OBJECTNODEVALUE;
                        spAtt->attValue = vNodeValue;
                        spAtt->attVisible = true;
                        spAtt->attRemovable = false;
			xmlObj->goc_setObjectNodeValue(sNodeValue);		
		}
		nObjNode = nObjNode.nextSibling();
	}

}

// return the dom document of the xml space
QDomDocument *GOCXMLSpace::goc_getDomDocument(){
	return m_domDocument;
}

//update this xml space according to a given document
void GOCXMLSpace::goc_setDomDocument(QDomDocument *domDocument){
	//if(!domDocument)
	//	return;//TODO: trace error
	//
	////-->Update the dom doc of this space
	//m_domDocument = domDocument;

	////-->empty the space:
	////TODO:

	////-->populate the space
	//QDomElement docElem = m_domDocument->documentElement();
	//

	//QDomNode n = docElem.firstChild();
	//while(!n.isNull()) {
	//	QDomElement e = n.toElement(); // try to convert the node to an element.
	//	GOCXMLObject *xmlObj = new GOCXMLObject(e,this);
	//	n = n.nextSibling();
	//}
	
}
