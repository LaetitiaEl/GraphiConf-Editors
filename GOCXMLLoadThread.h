#pragma once

//Qt includes
#include <QThread>

//GOC includes
#include "GOCXMLEditor.h"
#include "GOCXMLObject.h"
class GOCXMLEditor;
class GOCXMLObject;

class GOCXMLLoadThread :
	public QThread
{
	Q_OBJECT
public:
	GOCXMLLoadThread(GOCXMLEditor *parent = 0);
	virtual ~GOCXMLLoadThread(void);

public:
	void run(void);
	
	void goc_setFileName(QString fileName);
	void goc_getFileName(QString *fileName);

signals:
	HRESULT goc_sigLoadingDone(QDomDocument *xmlDocument, GOCXMLSpace *xmlSpace, GOCMDIView *gocMainView);
	HRESULT goc_sigPercentageLoaded(int iNbLoaded);
	HRESULT goc_sigLoadingStart(void);
	HRESULT goc_sigLoadingFailed(void);

public slots:
	//Load xml file slot
	HRESULT goc_slotLoadXMLFile(GOCXMLEditor *mainXMLEditor,QDomDocument *xmlDocument, GOCPropertiesView *gocPropertiesView,QPointer<GOCRegister> spRegister, QPointer<GOCMDIView> spMainView);
	//Object created:
	HRESULT goc_slotObjectCreated(GOCXMLObject* xmlObject);

private:
	HRESULT goc_countTotalChildNodes(QDomNode domNode,int *nbNodes);

private:
	GOCXMLEditor *m_mainXMLEditor;
	QDomDocument *m_xmlDocuement;
	GOCPropertiesView *m_gocPropertiesView;
	GOCMDIView *m_gocMainView;
	//The view manager - used to create the GOCSpaceView out of a QThread
	GOCRegister	*m_spRegister;

	//Number of loaded objects
	int			m_iNbLoadedObject;
	int			m_iTotalObjectToLoad;

	//Name of the file to load:
	QString m_sFileName;
};
