#ifndef GOCXMLEDITOR_H
#define GOCXMLEDITOR_H

#include <QtGui/QMainWindow>
#include "ui_GOCXMLEditor.h"

//GOC includes
#include ".\GOC_Framework\GOCRegister.h"
#include ".\GOC_Framework\GOCReferencer.h"
#include ".\GOC_Framework\GOCPropertiesView.h"
#include "GOCXMLObject.h"
#include "GOCXMLSpace.h"
#include "GOCXMLEditor.h"
#include "GOCXMLLoadThread.h"
#include "GOCXMLLoadingForm.h"
#include "GOCMultiSpace.h"
#include "GOCMultiObject.h"

class GOCXMLLoadThread;
class GOCXMLSpace;
class GOCXMLEditor;
class GOCXMLLoadingForm;
class GOCMultiSpace;
class GOCMDIView;
class GOCMultiObject;

class GOCXMLEditor : public QMainWindow, public GOCReferencer
{
	Q_OBJECT

public:
	GOCXMLEditor(QWidget *parent = 0,QPointer<GOCRegister> spRegister = 0, GOCXMLLoadThread *thrXMLLoad = 0,Qt::WFlags flags = 0);
	virtual ~GOCXMLEditor();
	
public slots:
	HRESULT goc_loadXML(bool checked = false);
	HRESULT goc_exportXML(bool checked = false);
	HRESULT goc_saveGOX(bool checked = false);
	HRESULT goc_addNewObject(bool checked = false);
	HRESULT goc_copyObjects(bool checked = false);
	HRESULT goc_pastObjects(bool checked = false);
	
	//Loading has finished
	HRESULT goc_slotLoadingDone(QDomDocument *xmlDocument,GOCXMLSpace *xmlSpace,GOCMDIView *gocMainView);
	HRESULT goc_slotLoadingStart(void);
        void    goc_updateActiveWindow(QMdiSubWindow * window);

signals:
	HRESULT goc_sigLoadXMLFile(GOCXMLEditor *mainXMLEditor,QDomDocument *xmlDocument, GOCPropertiesView *gocPropertiesView, QPointer<GOCRegister> spRegister, QPointer<GOCMDIView> spMainView);

private:
	HRESULT goc_convertToSimpleXML(QDomElement xmlElement);

private:
	//Ui::GOCXMLEditorClass ui;
	QString m_xmlFileToLoad;
	//
	QDomDocument *m_xmlDocument;
	//Main View
	QPointer<GOCMDIView>		m_spMainView;
	//Prperties view
	QPointer<GOCPropertiesView> m_spPropertiesView;
	//Thread used to load the file
	GOCXMLLoadThread			*m_thrLoadFile;
	//The loading form
	GOCXMLLoadingForm			*m_formLoading;
	//The multi space
	QPointer<GOCMultiSpace>		m_spMultiSpace;
	QPointer<GOCSpaceView>		m_spMultiSpaceView;

        //Last active subwindow
        QPointer<QMdiSubWindow>         m_pLastActiveSubWindow;

        //Last used folder
        QString m_sLastUsedFolder;

private://Menus,Actions,...
	//Initialize the menu bar elements
	HRESULT	goc_InitMenuElements(void);
	//Menu Bar
	QPointer<QMenuBar>			m_spMenuBar;

        //->Menu File
	QPointer<QMenu>				m_spMenuFile;
	//-->Action Loading
	QPointer<QAction>			m_spActLoad;
	//-->Action Export		
	QPointer<QAction>			m_spActExport;
	//-->Actio Save GOX		
	QPointer<QAction>			m_spActSaveGox;
        //-->Action Exit
        QPointer<QAction>			m_spActExit;

        //->Menu Edit
	QPointer<QMenu>				m_spMenuEdit;
	//-->Action Add
	QPointer<QAction>			m_spActAdd;
	QPointer<QAction>			m_spActCopy;
	QPointer<QAction>			m_spActPast;
};

#endif // GOCXMLEDITOR_H
