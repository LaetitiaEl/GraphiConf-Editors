#pragma once

#include "WinError.h"

//Qt includes
#include <QPointer>


//Traces Macro:
#ifdef GOC_DEBUG
	//->Functional Traces
	#define MethodBegin(methodname)			QString sMethodName = methodname; HRESULT hRes = S_OK;	qDebug()<<sMethodName;
	//->Error Traces
	#define IfErrorTraceReturn(TraceValue)	if(hRes == GOC_FAIL){	qDebug()<<"ERROR : "<<sMethodName<<" : "<<TraceValue;	return hRes;};
	#define TraceAndReturnError(TraceValue)	hRes = GOC_FAIL;		qDebug()<<"ERROR : "<<sMethodName<<" : "<<TraceValue;	return hRes;
	#define TraceError(TraceValue)									qDebug()<<"ERROR : "<<sMethodName<<" : "<<TraceValue;
	#define IfErrorTrace(TraceValue)	if(hRes == GOC_FAIL){	qDebug()<<"ERROR : "<<sMethodName<<" : "<<TraceValue;};
    #define Trace(TraceValue)									qDebug()<<"TRACE : "<<sMethodName<<" : "<<TraceValue;

#else
	//->Functional Traces
	#define MethodBegin(methodname)			QString sMethodName = methodname; HRESULT hRes = S_OK;
	//->Error Traces
	#define IfErrorTraceReturn(TraceValue)	if(hRes == GOC_FAIL){	return hRes;};
	#define TraceAndReturnError(TraceValue)	hRes = GOC_FAIL;		return hRes;
	#define TraceError(TraceValue)									
	#define IfErrorTrace(TraceValue)	if(hRes == GOC_FAIL){	};
    #define Trace(TraceValue)

#endif

//->Test Pointer
#define TestQPointer(p) { \
	if (p.isNull()) { \
                hRes = GOC_POINTER; qDebug()<<"ERROR : Pointer["<<#p<<"] is Null"; return hRes;\
	} \
} 
#define TestQPointerVoid(p) { \
	if (p.isNull()) { \
		hRes = GOC_POINTER; qDebug()<<"ERROR : Pointer["<<#p<<"] is Null"; return;\
	} \
} 
#define TestPointer(p) { \
	if (!p) { \
		hRes = GOC_POINTER; qDebug()<<"ERROR : Pointer["<<#p<<"] is Null"; return hRes;\
	} \
} 
#define TestPointerVoid(p) { \
	if (!p) { \
		hRes = GOC_POINTER; qDebug()<<"ERROR : Pointer["<<#p<<"] is Null"; return;\
	} \
} 


//Get Objects manager
#define GET_OBJECT_MGR(spObjMgr) QPointer<QObject>	pQObjMgr = 0;\
	goc_getRegisteredObject(GOCOBJECTMGR_REG_ID,&pQObjMgr);\
	GOCObjectMgr *pObjMgr = qobject_cast<GOCObjectMgr*>(pQObjMgr);\
	QPointer<GOCObjectMgr>	spObjMgr;\
	spObjMgr = pObjMgr;\
	

//GOC Object Inner attributes Macros
#define GOCOBJECT_OBJECTNAME	"ObjectName"
#define GOCOBJECT_OBJECTID		"ObjectID"
#define GOCOBJECT_OBJECTGUID	"ObjectGUID"
#define GOCOBJECT_OBJECTRECT	"ObjectRect"
#define GOCOBJECT_OBJECSUBBED	"ObjectSubbed"
#define GOCOBJECT_OBJECTMAXSUBS "ObjectMaxSubs"
//XML Object Innter Attributes Macros
#define GOCOBJECT_OBJECTNODENAME	"ObjectNodeName"
#define GOCOBJECT_OBJECTNODEVALUE	"ObjectNodeValue"

//GOC Space Properties Macros
#define GOCSPACE_WIDTH			500
#define GOCSPACE_HEIGHT			500

//Style
#define GOCOBJECT_COLOR_OUTLINE			QColor(101,177,255)
#define GOCOBJECT_COLOR_BACKGND_SUB		QColor(178,216,255)
#define GOCOBJECT_COLOR_BACKGND_NOSUB	Qt::white

//Data model define
#define OBJECT_ATT_ID			0
#define OBJECT_ATT_NAME			1
#define OBJECT_ATT_VALUE		2
#define OBJECT_ATT_VISIBLE		3
#define OBJECT_ATT_NAMEMODIFIABLE       4
#define OBJECT_ATT_GUID			5

#define OBJECT_COLUMN_NUMBER           6   //The number of columns in the object model

#define SPACE_COLUMN_ATT		0
#define SPACE_COLUMN_VAL		1

//Types define
typedef int                 BOOL;

//Returns define
#ifndef HRESULT
#define HRESULT		long
#endif
#ifndef S_OK
#define S_OK		0x00000000
#endif
#define GOC_FAIL	0xffffffff
#define GOC_POINTER	0x10000001
