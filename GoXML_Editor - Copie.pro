#-------------------------------------------------
#
# Project created by QtCreator 2010-12-25T12:30:00
#
#-------------------------------------------------

QT       += core gui xml sql

TARGET = GoXML
TEMPLATE = app

RC_FILE = .\GoXML_Editor\GoXML.rc

SOURCES += .\GOC_Framework\stdafx.cpp \
    .\GOC_Framework\GOCSpaceView.cpp \
    .\GOC_Framework\GOCSpaceModel.cpp \
    .\GOC_Framework\GOCSpace.cpp \
    .\GOC_Framework\GOCRegister.cpp \
    .\GOC_Framework\GOCReferencer.cpp \
    .\GOC_Framework\GOCPropertiesView.cpp \
    .\GOC_Framework\GOCObjectView.cpp \
    .\GOC_Framework\GOCObjectModel.cpp \
    .\GOC_Framework\GOCObjectMgr.cpp \
    .\GOC_Framework\GOCObject.cpp \
    .\GOC_Framework\GOCMDIView.cpp \
    .\GOC_Framework\GOCAttributeView.cpp \
    .\GOC_Framework\GOCAttribute.cpp \
    .\GoXML_Editor\GOCXMLSpace.cpp \
    .\GoXML_Editor\GOCXMLObjectThread.cpp \
    .\GoXML_Editor\GOCXMLObject.cpp \
    .\GoXML_Editor\GOCXMLLoadThread.cpp \
    .\GoXML_Editor\GOCXMLLoadingForm.cpp \
    .\GoXML_Editor\GOCXMLEditor.cpp \
    .\GoXML_Editor\GOCMultiSpace.cpp \
    .\GoXML_Editor\GOCMultiObject.cpp \
    .\GoXML_Editor\main.cpp\
    .\GoXML_Editor\GOCXMLPropertiesView.cpp \
    GoXML_Editor/stdafx.cpp \
    GOC_Framework/main_gox.cpp

HEADERS  += \
    .\GOC_Framework\stdafx.h \
    .\GOC_Framework\GOCSpaceView.h \
    .\GOC_Framework\GOCSpaceModel.h \
    .\GOC_Framework\GOCSpace.h \
    .\GOC_Framework\GOCRegister.h \
    .\GOC_Framework\GOCReferencer.h \
    .\GOC_Framework\GOCPropertiesView.h \
    .\GOC_Framework\GOCObjectView.h \
    .\GOC_Framework\GOCObjectModel.h \
    .\GOC_Framework\GOCObjectMgr.h \
    .\GOC_Framework\GOCObject.h \
    .\GOC_Framework\GOCMDIView.h \
    .\GOC_Framework\GOCHelpers.h \
    .\GOC_Framework\GOCFrameworkVersion.h \
    .\GOC_Framework\GOCAttributeView.h \
    .\GOC_Framework\GOCAttribute.h \
    .\GoXML_Editor\GOCXMLSpace.h \
    .\GoXML_Editor\GOCXMLObjectThread.h \
    .\GoXML_Editor\GOCXMLObject.h \
    .\GoXML_Editor\GOCXMLLoadThread.h \
    .\GoXML_Editor\GOCXMLLoadingForm.h \
    .\GoXML_Editor\GOCXMLEditor.h \
    .\GoXML_Editor\GOCMultiSpace.h \
    .\GoXML_Editor\GOCMultiObject.h \
    .\GoXML_Editor\GOCXMLPropertiesView.h \
    GoXML_Editor/stdafx.h

FORMS    += .\GoXML_Editor\GOCXMLEditor.ui \
    .\GoXML_Editor\GOCXMLLoadingForm.ui

OTHER_FILES += \
    .\GoXML_Editor\GoXML.rc \
    GoX Evolution.txt \

RESOURCES += \
    .\GoXML_Editor\GOC_XML_Editor_Ressource.qrc
