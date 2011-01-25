#-------------------------------------------------
#
# Project created by QtCreator 2011-01-22T23:08:26
#
#-------------------------------------------------

QT       += core gui xml sql

TARGET = GoSQL_Editor
TEMPLATE = app

OTHER_FILES += \
    GoSQL_Editor/GoSQL_Editor.rc \
    GoSQL_Editor/GoSQL_Editor.ico

HEADERS += \
    GoSQL_Editor/stdafx.h \
    GoSQL_Editor/resource.h \
    GoSQL_Editor/GOXSqlDatabaseTableSpace.h \
    GoSQL_Editor/GOXSqlDatabaseSpace.h \
    GoSQL_Editor/GOXSqlDatabase.h \
    GoSQL_Editor/GoSQL_Editor.h \
    GOC_Framework/stdafx.h \
    GOC_Framework/GOXDatabaseTableModel.h \
    GOC_Framework/GOXDatabaseTable.h \
    GOC_Framework/GOXDatabase.h \
    GOC_Framework/GOCSpaceView.h \
    GOC_Framework/GOCSpaceModel.h \
    GOC_Framework/GOCSpace.h \
    GOC_Framework/GOCRegister.h \
    GOC_Framework/GOCReferencer.h \
    GOC_Framework/GOCPropertiesView.h \
    GOC_Framework/GOCObjectView.h \
    GOC_Framework/GOCObjectModel.h \
    GOC_Framework/GOCObjectMgr.h \
    GOC_Framework/GOCObject.h \
    GOC_Framework/GOCMDIView.h \
    GOC_Framework/GOCHelpers.h \
    GOC_Framework/GOCFrameworkVersion.h \
    GOC_Framework/GOCAttributeView.h \
    GOC_Framework/GOCAttribute.h

SOURCES += \
    GoSQL_Editor/stdafx.cpp \
    GoSQL_Editor/main_GoSQL.cpp \
    GoSQL_Editor/GOXSqlDatabaseTableSpace.cpp \
    GoSQL_Editor/GOXSqlDatabaseSpace.cpp \
    GoSQL_Editor/GOXSqlDatabase.cpp \
    GoSQL_Editor/GoSQL_Editor.cpp \
    GOC_Framework/stdafx.cpp \
    GOC_Framework/GOXDatabaseTableModel.cpp \
    GOC_Framework/GOXDatabaseTable.cpp \
    GOC_Framework/GOXDatabase.cpp \
    GOC_Framework/GOCSpaceView.cpp \
    GOC_Framework/GOCSpaceModel.cpp \
    GOC_Framework/GOCSpace.cpp \
    GOC_Framework/GOCRegister.cpp \
    GOC_Framework/GOCReferencer.cpp \
    GOC_Framework/GOCPropertiesView.cpp \
    GOC_Framework/GOCObjectView.cpp \
    GOC_Framework/GOCObjectModel.cpp \
    GOC_Framework/GOCObjectMgr.cpp \
    GOC_Framework/GOCObject.cpp \
    GOC_Framework/GOCMDIView.cpp \
    GOC_Framework/GOCAttributeView.cpp \
    GOC_Framework/GOCAttribute.cpp

FORMS += \
    GoSQL_Editor/GoSQL_Editor.ui

RESOURCES += \
    GoSQL_Editor/GoSQL_Editor.qrc
