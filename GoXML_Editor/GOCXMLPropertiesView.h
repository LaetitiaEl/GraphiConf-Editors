#ifndef GOCXMLPROPERTIESVIEW_H
#define GOCXMLPROPERTIESVIEW_H

#include "..\GOC_Framework\GOCPropertiesView.h"

class GOCXMLPropertiesView : public GOCPropertiesView
{
	Q_OBJECT

public:
	GOCXMLPropertiesView(QWidget *parent = 0);
	~GOCXMLPropertiesView();

protected :
    virtual void	dataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight );
    virtual void    setModel(QAbstractItemModel *model);
	
};

#endif // GOCXMLPROPERTIESVIEW_H
