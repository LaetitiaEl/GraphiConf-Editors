/********************************************************************************
** Form generated from reading UI file 'GOCXMLEditor.ui'
**
** Created: Thu Jan 20 17:25:35 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOCXMLEDITOR_H
#define UI_GOCXMLEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GOCXMLEditor
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GOCXMLEditor)
    {
        if (GOCXMLEditor->objectName().isEmpty())
            GOCXMLEditor->setObjectName(QString::fromUtf8("GOCXMLEditor"));
        GOCXMLEditor->resize(400, 300);
        menuBar = new QMenuBar(GOCXMLEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GOCXMLEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GOCXMLEditor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GOCXMLEditor->addToolBar(mainToolBar);
        centralWidget = new QWidget(GOCXMLEditor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GOCXMLEditor->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GOCXMLEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GOCXMLEditor->setStatusBar(statusBar);

        retranslateUi(GOCXMLEditor);

        QMetaObject::connectSlotsByName(GOCXMLEditor);
    } // setupUi

    void retranslateUi(QMainWindow *GOCXMLEditor)
    {
        GOCXMLEditor->setWindowTitle(QApplication::translate("GOCXMLEditor", "GOCXMLEditor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GOCXMLEditor: public Ui_GOCXMLEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOCXMLEDITOR_H
