#ifndef GOCXMLLOADINGFORM_H
#define GOCXMLLOADINGFORM_H

#include <QWidget>
#include "ui_GOCXMLLoadingForm.h"

class GOCXMLLoadingForm : public QWidget
{
	Q_OBJECT

public:
	GOCXMLLoadingForm(QWidget *parent = 0);
	~GOCXMLLoadingForm();

public slots:
	HRESULT goc_slotPercentageLoaded(int iPercentageLoaded);

private:
	Ui::GOCXMLLoadingFormClass ui;
};

#endif // GOCXMLLOADINGFORM_H
