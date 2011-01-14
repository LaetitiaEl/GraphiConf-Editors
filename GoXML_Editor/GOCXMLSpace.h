#pragma once

//Qt includes
#include <QDomDocument>
//GOC includes
#include ".\GOC_Framework\GOCSpace.h"
#include "GOCXMLObject.h"
class GOCXMLObject;

class GOCXMLSpace :
	public GOCSpace
{
	Q_OBJECT

public:
	GOCXMLSpace(QPointer<GOCMDIView> parentContainer = 0, QPointer<GOCPropertiesView> propertiesView = 0, QPointer<GOCRegister> spRegister = 0);
	GOCXMLSpace(QPointer<GOCXMLObject> parent, QPointer<GOCMDIView> parentContainer = 0, QPointer<GOCPropertiesView> propertiesView = 0, QPointer<GOCRegister> spRegister = 0);
	GOCXMLSpace(QDomDocument *dDomDoc, QPointer<GOCMDIView> parentContainer = 0, QPointer<GOCPropertiesView> propertiesView = 0, QPointer<GOCRegister> spRegister = 0);
	virtual ~GOCXMLSpace(void);

public slots:
	//
	HRESULT		goc_slotSaveSelectedObject(void);
	//
	HRESULT		goc_slotSpaceViewCreated(GOCSpaceView *spSpaceView);
        //
        void goc_createNewObject(QPointer<GOCObject> *spObjNew = NULL);
public:
	void goc_addObject(GOCXMLObject* gocObject);
	void goc_addXMLObject(QDomElement xmlObjectElem);
	//Returns the dom document of this space
	QDomDocument *goc_getDomDocument();
	//update this xml space according to a given document - Deprecated
	void goc_setDomDocument(QDomDocument *domDocument);

private:
	QDomDocument *m_domDocument;
};
