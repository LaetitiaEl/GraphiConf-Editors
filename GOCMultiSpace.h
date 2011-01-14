#ifndef GOCMULTISPACE_H
#define GOCMULTISPACE_H

#define GOC_XML_ATTFILEPATH "FilePath"

//Qt includes
#include <QtCore>

//GOC includes
#include "GOCXMLSpace.h"
#include "GOCMultiObject.h"
#include "GOCXMLEditor.h"
#include ".\GOC_Framework\GOCMDIView.h"
class GOCXMLEditor;
class GOCMDIView;

class GOCMultiSpace : public GOCSpace
{
	Q_OBJECT

public:	
        //todo to remove the parent container mecanims
        GOCMultiSpace(QPointer<GOCMDIView> parentContainer = 0, QPointer<GOCPropertiesView> propertiesView = 0, QPointer<GOCRegister> spRegister = 0, QPointer<GOCXMLEditor> spXMLEditor = 0);
	virtual ~GOCMultiSpace();

private:
        QPointF m_posAvailable;
private:
        HRESULT goc_getAvailablePosition(QPointF *newPos);

public:
	HRESULT goc_addObjectFile(QPointer<GOCMultiObject> gocMultiObject, QString sFileName);
        HRESULT goc_setActiveMdiSpace(QPointer<GOCMDIView> spMdiSpace);
        HRESULT goc_getXMLEditor(QPointer<GOCXMLEditor> *spXMLEditor);

protected:
        virtual void	goc_slotMouseRightClick(QPointF position);

private:
        QPointer<GOCXMLEditor> m_spXMLEditor;
	
	
};

#endif // GOCMULTISPACE_H
