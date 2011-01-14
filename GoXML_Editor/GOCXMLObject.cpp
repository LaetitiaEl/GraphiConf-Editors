#include ".\GOC_Framework\StdAfx.h"
#include "GOCXMLObject.h"

//To attach this object to an existing XML
GOCXMLObject::GOCXMLObject(QDomElement domElement, QPointer<GOCXMLSpace> parent):GOCObject(parent.data())
{
	QString objName = objectName();	

	//Add the xml Object to the xml Space
	parent->goc_addObject(this);

	//Init the node name:	
        QString strNodeName;
        if(!domElement.hasAttribute(GOCOBJECT_OBJECTNODENAME)){
		//Value from XML
                strNodeName = domElement.tagName();if(strNodeName.isEmpty())strNodeName = "NewNode";
		QVariant vNodeName = QVariant(strNodeName);
		GOCAttribute *gocAtt = new GOCAttribute(this);
		QSharedPointer<GOCAttribute> spAtt(gocAtt);
		spAtt->attName = GOCOBJECT_OBJECTNODENAME;
		spAtt->attValue = vNodeName;
                spAtt->attVisible = true;
                spAtt->attRemovable = false;
                spAtt->attNameModifiable = true;
		GOCObject::goc_setAttribute(spAtt);
		goc_setObjectNodeName(strNodeName);
	}else{
		//Value from GOX
                strNodeName = domElement.attribute(GOCOBJECT_OBJECTNODENAME);
		goc_setObjectNodeName(strNodeName);
	}	

	//Init the node value	
	if(!domElement.hasAttribute(GOCOBJECT_OBJECTNODEVALUE)){
		//Value from XML
		//Create the attribute if it isn't created in GOCXMLSpace
		QString sNodeValue = goc_getObjectNodeValue();
		if(sNodeValue.isEmpty() && !domElement.hasAttribute(GOCOBJECT_OBJECTNODEVALUE)){
			//Node text
			QVariant vNodeValue = QVariant(sNodeValue);
			GOCAttribute *gocAtt = new GOCAttribute(this);
			QSharedPointer<GOCAttribute> spAtt(gocAtt);
			spAtt->attName = GOCOBJECT_OBJECTNODEVALUE;
			spAtt->attValue = vNodeValue;
			spAtt->attVisible = true;
                        spAtt->attRemovable = false;
                        spAtt->attNameModifiable = true;
			GOCObject::goc_setAttribute(spAtt);
			goc_setObjectNodeValue(sNodeValue);
		}
	}else{
		//Value from GOX
		QString strNodeValue = domElement.attribute(GOCOBJECT_OBJECTNODEVALUE);
                goc_setObjectNodeValue(strNodeValue);
	}	

	//
	m_bXMLObjectSubbed = false;
        m_ObjectSubbed = false;
	
	//We initialize the object name with the node name
	setObjectName(strNodeName);

	//Update the position of the object - Default
	QPointF newObjectPos = QPointF(qrand()%GOCSPACE_WIDTH, qrand()%GOCSPACE_HEIGHT);
	goc_setObjectPos(newObjectPos);

	//Init the attributes:
	if(domElement.hasAttributes()){
		QDomNamedNodeMap attMap = domElement.attributes();
		for(int i = 0;i<attMap.count();i++){
			QDomNode attNode = attMap.item(i);
			GOCAttribute *gocAtt = new GOCAttribute(this);
			QSharedPointer<GOCAttribute> spAtt(gocAtt);
			
			spAtt->attName = attNode.nodeName();
			spAtt->attValue = QVariant(attNode.nodeValue());
			goc_setAttribute(spAtt);
		}
	}	

	//Notify the loading thread:
	GOCXMLLoadThread* thrLoadingThread = NULL;
	thrLoadingThread = qobject_cast<GOCXMLLoadThread*>(thread());
	if(thrLoadingThread != NULL){
		thrLoadingThread->goc_slotObjectCreated(this);
	}

}

GOCXMLObject::~GOCXMLObject(void)
{
	
}

////BEGIN: META
//const QMetaObject * GOCXMLObject::metaObject () const{
//	return GOCObject::metaObject();
//}
//
//void *GOCXMLObject::qt_metacast(char const *className){
//	return GOCObject::qt_metacast(className);
//}
//
//int GOCXMLObject::qt_metacall(QMetaObject::Call call, int id,	void **arguments){
//	return GOCObject::qt_metacall(call,id,arguments);
//}
////END: META

//BEGIN: ATTRIBUTES HANDLING

//--Object Node Name
QString GOCXMLObject::goc_getObjectNodeName() const{
	return m_ObjectNodeName;
}
void GOCXMLObject::goc_setObjectNodeName(QString objNodeName){
	
	if(objNodeName.isNull())
		return;

	//check that the given value is different
	if(objNodeName == m_ObjectNodeName)
		return;//TODO:trace
	else
		m_ObjectNodeName = objNodeName;

	//Propagate the object name to the model -> view
	QVariant vNodeName = QVariant(objNodeName);
        GOCObject::goc_setAttribute(GOCOBJECT_OBJECTNODENAME,vNodeName,true);


}
//--Object Node Value
QString GOCXMLObject::goc_getObjectNodeValue() const{
	return m_ObjectNodeValue;
}
void GOCXMLObject::goc_setObjectNodeValue(QString objNodeValue){
	
	if(objNodeValue.isNull())
		return;

	//check that the given value is different
	if(objNodeValue == m_ObjectNodeValue)
		return;//TODO:trace
	else
		m_ObjectNodeValue = objNodeValue;
	
	//Propagate the object name to the model -> view
	QVariant vNodeValue = QVariant(objNodeValue);
	GOCObject::goc_setAttribute(GOCOBJECT_OBJECTNODEVALUE,vNodeValue,true);

}
//Slot which filter and process the changing of an attribute - deprecated: all the attributes (inner or user are handeled
void GOCXMLObject::goc_slotModelDataChanged(QModelIndex mdlIndex){	
	
	QModelIndex indxAttName;
	QModelIndex indxAttVal;
	QString sAttName;
	QVariant vValueMdl;

	///Get the object model
	QPointer<GOCObjectModel> spObjectModel;
	goc_getObjectModel(&spObjectModel);
	if(spObjectModel == NULL)
		return;//TODO: trace Error
	
	//--Handle inner attributes (objectName, objectID,objectPos...)
	GOCObject::goc_slotModelDataChanged(mdlIndex);

	//--Handle the NodeName
	if(mdlIndex.column() == OBJECT_ATT_VALUE){
		indxAttName = spObjectModel->index(mdlIndex.row(), OBJECT_ATT_NAME, QModelIndex());
		sAttName = spObjectModel->data(indxAttName).toString();	
		if(sAttName == GOCOBJECT_OBJECTNODENAME){
			indxAttVal  = spObjectModel->index(mdlIndex.row(), OBJECT_ATT_VALUE, QModelIndex());
			vValueMdl = spObjectModel->data(indxAttVal);	
			goc_setObjectNodeName(vValueMdl.toString());
		}
	}

	//--Handle the NodeValue
	if(mdlIndex.column() == OBJECT_ATT_VALUE){
		indxAttName = spObjectModel->index(mdlIndex.row(), OBJECT_ATT_NAME, QModelIndex());
		sAttName = spObjectModel->data(indxAttName).toString();	
		if(sAttName == GOCOBJECT_OBJECTNODEVALUE){
			indxAttVal  = spObjectModel->index(mdlIndex.row(), OBJECT_ATT_VALUE, QModelIndex());
			vValueMdl = spObjectModel->data(indxAttVal);	
			goc_setObjectNodeValue(vValueMdl.toString());
		}
	}
	
	//--Handle XML attributes
	//We allow only attribute's Value and Name modification
	if(mdlIndex.column() != OBJECT_ATT_VALUE && mdlIndex.column() != OBJECT_ATT_NAME)
		return; //todo: trace	
	
	//We allow only the update of the attributes with non null ID (XML Attributes)
	QModelIndex indxAttID =spObjectModel->index(mdlIndex.row(), OBJECT_ATT_ID, QModelIndex());
	int iAttID = spObjectModel->data(indxAttID).toInt();
	if(iAttID < 1)
		return; //attribute is an inner one- already handled

	//--Check if the value or the name are different from the property
	//Get the name and the value of the attribute
	indxAttName = spObjectModel->index(mdlIndex.row(), OBJECT_ATT_NAME, QModelIndex());
	indxAttVal  = spObjectModel->index(mdlIndex.row(), OBJECT_ATT_VALUE, QModelIndex());

	sAttName = spObjectModel->data(indxAttName).toString();	
	vValueMdl = spObjectModel->data(indxAttVal);	
	
	//Get the attribute from the nodes attributes list
	QSharedPointer<GOCAttribute> gocAtt;
	HRESULT hRes = goc_getAttribute(iAttID,&gocAtt);

	//Update the goc attribute
	gocAtt->attName = sAttName;
	gocAtt->attValue = vValueMdl;

}

//! Set attributes of the object using the name of the attribute:
HRESULT GOCXMLObject::goc_setAttribute(QSharedPointer<GOCAttribute> attribute, BOOL bUpdateOnly) {
	
	//Setting the attribute in the model
	GOCObject::goc_setAttribute(attribute,bUpdateOnly);
	
	return S_OK;
}

//END: ATTRIBUTES HANDELING

//Set the object XML Sub Space
void GOCXMLObject::goc_setXMLObjectSubbed(bool bIsObjectSubbed){
	
        if(m_ObjectSubbed == bIsObjectSubbed)
		return;

	//TODO: improve with QPointer
	if(bIsObjectSubbed){
		//create a subspace
		QPointer<GOCSpace> spParentSpace;
		goc_getSpaceParent(&spParentSpace);
		if(spParentSpace.isNull())
			return;//TODO: trace
		QPointer<GOCMDIView> spMainView;
		spParentSpace->goc_getMainView(&spMainView);
		QPointer<GOCPropertiesView> spPropView;
		spParentSpace->goc_getPropertiesView(&spPropView);
		QPointer<GOCRegister> spRegister;
		spParentSpace->goc_getRegister(&spRegister);

                m_spXMLObjectSpace = new GOCXMLSpace(this,spMainView,spPropView,spRegister);
                m_spObjectSpace = m_spXMLObjectSpace;
                //TODO: check and set the m_spObjectSpace, remove m_spXMLObjectSpace

                //set background color
                goc_setBackGroundColor(m_backGroundColorSub);
	}else{
		//remove the subspace
                delete m_spObjectSpace;

                //set background color to white
                goc_setBackGroundColor(m_backGroundColorNoSub);
	}
	m_bXMLObjectSubbed = bIsObjectSubbed;
        m_ObjectSubbed = m_bXMLObjectSubbed;
}

void GOCXMLObject::goc_setObjectSubbed2(bool bIsObjectSubbed){
//Temorary patch: use virtual GOC and GOCXML
    //GOCObject::goc_setObjectSubbed2(bIsObjectSubbed);
    goc_setXMLObjectSubbed(bIsObjectSubbed);

}

bool GOCXMLObject::goc_getObjectSubbed() const{
	//We dont use GOCXMLObject::goc_getObjectSubbed
        return m_ObjectSubbed;
        //return m_bXMLObjectSubbed;
}

//! returns the subspace of the object
GOCXMLSpace *GOCXMLObject::goc_getXMLObjectSpace() const{
	return m_spXMLObjectSpace;
}
