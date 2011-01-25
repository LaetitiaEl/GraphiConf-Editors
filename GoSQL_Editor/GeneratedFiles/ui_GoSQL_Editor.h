/********************************************************************************
** Form generated from reading UI file 'GoSQL_Editor.ui'
**
** Created: Tue Jan 25 13:06:29 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOSQL_EDITOR_H
#define UI_GOSQL_EDITOR_H

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

class Ui_GoSQL_EditorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GoSQL_EditorClass)
    {
        if (GoSQL_EditorClass->objectName().isEmpty())
            GoSQL_EditorClass->setObjectName(QString::fromUtf8("GoSQL_EditorClass"));
        GoSQL_EditorClass->resize(600, 400);
        menuBar = new QMenuBar(GoSQL_EditorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GoSQL_EditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GoSQL_EditorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GoSQL_EditorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GoSQL_EditorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GoSQL_EditorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GoSQL_EditorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GoSQL_EditorClass->setStatusBar(statusBar);

        retranslateUi(GoSQL_EditorClass);

        QMetaObject::connectSlotsByName(GoSQL_EditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *GoSQL_EditorClass)
    {
        GoSQL_EditorClass->setWindowTitle(QApplication::translate("GoSQL_EditorClass", "GoSQL_Editor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GoSQL_EditorClass: public Ui_GoSQL_EditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOSQL_EDITOR_H
