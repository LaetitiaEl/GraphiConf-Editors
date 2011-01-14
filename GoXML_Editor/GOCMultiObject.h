#ifndef GOCMULTIOBJECT_H
#define GOCMULTIOBJECT_H


//Back ground color of a multiobject
#define GOCMULTIOBJECT_COLOR_BACKGND_SUB		QColor(255,165,74)
#define GOCMULTIOBJECT_COLOR_OUTLINE    		QColor(213,106,0)

#include ".\GOC_Framework\GOCObject.h"
#include "GOCMultiSpace.h"
#include ".\GOC_Framework\GOCPropertiesView.h"
class GOCObject;
class GOCMultiSpace;
class GOCPropertiesView;

class GOCMultiObject : public GOCObject
{
	Q_OBJECT

public:
        GOCMultiObject(QPointer<GOCMultiSpace> parent,QPointer<GOCMDIView> gocMdiMainView);
	virtual ~GOCMultiObject();
protected:
        virtual void	goc_slotMouseRightClick(QPointF position);
public:
	void	goc_slotDoubleClicked(void);
        QPointer<GOCMultiSpace> m_spMultiSpace;
        QPointer<GOCMDIView> m_spMdiMainView;
	QPointer<GOCMDIView> m_spMdiSpaceView;

        QMainWindow *spFileMainWindow;
        GOCPropertiesView *spPropertiesView;
};

#endif // GOCMULTIOBJECT_H
