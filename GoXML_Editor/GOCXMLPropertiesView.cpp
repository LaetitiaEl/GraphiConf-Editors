#include "StdAfx.h"
#include "GOCXMLPropertiesView.h"

GOCXMLPropertiesView::GOCXMLPropertiesView(QWidget *parent)
	: GOCPropertiesView(parent)
{

}

GOCXMLPropertiesView::~GOCXMLPropertiesView()
{

}

//! Reimplement Dadachanged
void    GOCXMLPropertiesView::dataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight ){

    GOCPropertiesView::dataChanged(topLeft,bottomRight);
}

//! Overload of setModel()
void    GOCXMLPropertiesView::setModel(QAbstractItemModel *model){
    
    if(!model)
        return;

    //Propagate the model
	GOCPropertiesView::setModel(model);

    //Hide the inner attributes
    for(int row = 0; row<model->rowCount(); row++){
        //Get the ID of the attribute
        int attID = 0;
        QModelIndex attIDIndex;
        attIDIndex = model->index(row,OBJECT_ATT_ID);
        attID = model->data(attIDIndex).toInt();
        if(attID == 0){
            //Hide the row
            this->hideRow(row);
        }
    }

    resizeColumnsToContents();
    resizeRowsToContents();
}