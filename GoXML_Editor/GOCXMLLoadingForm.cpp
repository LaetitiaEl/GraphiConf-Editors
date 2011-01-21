#include "StdAfx.h"
#include "GOCXMLLoadingForm.h"

GOCXMLLoadingForm::GOCXMLLoadingForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

GOCXMLLoadingForm::~GOCXMLLoadingForm()
{

}

//Update the progress bar percentage
HRESULT GOCXMLLoadingForm::goc_slotPercentageLoaded(int iPercentageLoaded){
	MethodBegin("GOCXMLLoadingForm::goc_slotPercentageLoaded");

	ui.progressBar->setValue(iPercentageLoaded);

	return hRes;
}
