#pragma once

//QT includes
#include <QDomNode>
//GOC includes
#include "..\GOC_Framework\GOCObject.h"
#include "GOCXMLSpace.h"
#include "GOCXMLLoadThread.h"
class GOCObject;
class GOCXMLSpace;
class GOCXMLLoadThread;

//Defines:
#define GOCXMLOBJECT_DOMDOCTAG	"GOC XML EDITOR Version 1.1"

class GOCXMLObject : public GOCObject
{
	Q_OBJECT

public:
	GOCXMLObject(QDomElement domElement, QPointer<GOCXMLSpace> parent);//An XML Object can't exist outside an XML Space
	virtual ~GOCXMLObject(void);

//BEGIN: PROPERTIES
private:
	QString		m_ObjectNodeName;
	QString		m_ObjectNodeValue;
public:
	//--Object Node Name
	QString		goc_getObjectNodeName() const;
	void		goc_setObjectNodeName(QString objNodeName);
	//--Object Node Value
	QString		goc_getObjectNodeValue() const;
	void		goc_setObjectNodeValue(QString objNodeValue);
//END: PROPERTIES
public:
	// Set the attribute
	HRESULT		goc_setAttribute(QSharedPointer<GOCAttribute> attribute, BOOL bUpdateOnly = false); 
	// Get XML Node as string
	QString		goc_getXMLNode() const;
	// Create XML SubSpace:
        void		goc_setXMLObjectSubbed(bool bIsObjectSubbed);
        void		goc_setObjectSubbed2(bool bIsObjectSubbed);
	bool		goc_getObjectSubbed() const;
	GOCXMLSpace *goc_getXMLObjectSpace() const; 

public slots:
	//--Model Data Changed
	//Slot which filter and process the changing of an attribute
	virtual void goc_slotModelDataChanged(QModelIndex mdlIndex);

private:
	//
	bool			m_bXMLObjectSubbed;
	GOCXMLSpace		*m_spXMLObjectSpace;
	//List of XML Attributes 
        QHash<int,QSharedPointer<GOCAttribute> > m_listXMLAttributes;

};
