#include ".\GOC_Framework\StdAfx.h"
#include "GOCMultiObject.h"

GOCMultiObject::GOCMultiObject(QPointer<GOCMultiSpace> parent, QPointer<GOCMDIView> gocMdiMainView)
        : GOCObject(parent.data())
{

        m_spMultiSpace = parent;
        m_spMdiMainView = gocMdiMainView;
        m_spMdiSpaceView = new GOCMDIView(m_spMdiMainView);

        //Configure the MdiSpaceView: Tab
        m_spMdiSpaceView->setViewMode(QMdiArea::TabbedView);
        m_spMdiSpaceView->setTabShape(QTabWidget::Triangular);

        //Set the color of the multiobject
        //-->Set default colors
        m_backGroundColorSub = GOCMULTIOBJECT_COLOR_BACKGND_SUB;
        m_backGroundColorNoSub = GOCOBJECT_COLOR_BACKGND_NOSUB;
        m_outlineColor = GOCMULTIOBJECT_COLOR_OUTLINE;
        goc_setOutlineColor(m_outlineColor);
        goc_setBackGroundColor(m_backGroundColorSub);

        //Connect the MdiSpaceView to XMLEditor
        QPointer<GOCXMLEditor> spXmlEditor;
        m_spMultiSpace->goc_getXMLEditor(&spXmlEditor);
        if(!spXmlEditor.isNull())
            connect(m_spMdiSpaceView, SIGNAL(subWindowActivated(QMdiSubWindow *)),spXmlEditor, SLOT(goc_updateActiveWindow(QMdiSubWindow *)));

        //
        spFileMainWindow = NULL;
        spPropertiesView = NULL;
}

GOCMultiObject::~GOCMultiObject()
{
    delete m_spMdiSpaceView;
    if(spPropertiesView != NULL)
        delete spPropertiesView;
    if(spFileMainWindow != NULL)
        delete spFileMainWindow;

}

//! Double click handler
void GOCMultiObject::goc_slotDoubleClicked(void){
        MethodBegin("GOCMultiObject::goc_slotDoubleClicked")


        //Create the MDI View with the XML Root Space view
        QPointer<GOCSpaceView> spSpaceView;
        m_spObjectSpace->goc_setMainView(m_spMdiSpaceView,true);
        hRes = m_spObjectSpace->goc_createSpaceView(&spSpaceView,m_spMdiSpaceView);
        m_spMdiSpaceView->goc_addSpaceView(spSpaceView);
        m_spMdiSpaceView->show();
        m_spMdiSpaceView->activateWindow();        

        //Set the title of the MdiView = path of file
        QVariant vPath = goc_getAttribute(GOC_XML_ATTFILEPATH);
        m_spMdiSpaceView->setWindowFilePath(vPath.toString());

        //Test: create QMainWindow with properties view and GOCMDIView
        //->Main file window
        if(spFileMainWindow == NULL)
                spFileMainWindow = new QMainWindow();
        spFileMainWindow->setCentralWidget(m_spMdiSpaceView);
        spFileMainWindow->setWindowTitle(objectName());

        //->Init properties view
        if(spPropertiesView == NULL){
            spPropertiesView = new GOCPropertiesView(0);
            QDockWidget *dockProperties = new QDockWidget("Properties", 0);
            dockProperties->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
            dockProperties->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable );
            dockProperties->setWidget(spPropertiesView);
            spFileMainWindow->addDockWidget(Qt::RightDockWidgetArea, dockProperties);
        }

        //->Init the space's properties view
        m_spObjectSpace->goc_setPropertiesView(spPropertiesView,true);

        spFileMainWindow->show();

        //Tests arround the MainView
        //m_spMdiMainView->goc_addMdiSpaceView(m_spMdiSpaceView);
        //m_spMultiSpace->goc_setActiveMdiSpace(m_spMdiSpaceView);
}

void GOCMultiObject::goc_slotMouseRightClick(QPointF position){

}
