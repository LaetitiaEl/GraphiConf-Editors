/********************************************************************************
** Form generated from reading UI file 'GOCXMLLoadingForm.ui'
**
** Created: Thu Jan 20 17:25:35 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOCXMLLOADINGFORM_H
#define UI_GOCXMLLOADINGFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GOCXMLLoadingFormClass
{
public:
    QProgressBar *progressBar;

    void setupUi(QWidget *GOCXMLLoadingFormClass)
    {
        if (GOCXMLLoadingFormClass->objectName().isEmpty())
            GOCXMLLoadingFormClass->setObjectName(QString::fromUtf8("GOCXMLLoadingFormClass"));
        GOCXMLLoadingFormClass->resize(443, 112);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/media/logo/GoC_XML_Editor_Logo"), QSize(), QIcon::Normal, QIcon::Off);
        GOCXMLLoadingFormClass->setWindowIcon(icon);
        progressBar = new QProgressBar(GOCXMLLoadingFormClass);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 40, 341, 23));
        progressBar->setValue(0);

        retranslateUi(GOCXMLLoadingFormClass);

        QMetaObject::connectSlotsByName(GOCXMLLoadingFormClass);
    } // setupUi

    void retranslateUi(QWidget *GOCXMLLoadingFormClass)
    {
        GOCXMLLoadingFormClass->setWindowTitle(QApplication::translate("GOCXMLLoadingFormClass", "GOCXMLLoadingForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GOCXMLLoadingFormClass: public Ui_GOCXMLLoadingFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOCXMLLOADINGFORM_H
