

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue May 10 11:14:40 2011
 */
/* Compiler settings for .\NiStep.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __NiStep_i_h__
#define __NiStep_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INode_FWD_DEFINED__
#define __INode_FWD_DEFINED__
typedef interface INode INode;
#endif 	/* __INode_FWD_DEFINED__ */


#ifndef __IAttribute_FWD_DEFINED__
#define __IAttribute_FWD_DEFINED__
typedef interface IAttribute IAttribute;
#endif 	/* __IAttribute_FWD_DEFINED__ */


#ifndef __IStepPath_FWD_DEFINED__
#define __IStepPath_FWD_DEFINED__
typedef interface IStepPath IStepPath;
#endif 	/* __IStepPath_FWD_DEFINED__ */


#ifndef __IAttributeList_FWD_DEFINED__
#define __IAttributeList_FWD_DEFINED__
typedef interface IAttributeList IAttributeList;
#endif 	/* __IAttributeList_FWD_DEFINED__ */


#ifndef __INodeList_FWD_DEFINED__
#define __INodeList_FWD_DEFINED__
typedef interface INodeList INodeList;
#endif 	/* __INodeList_FWD_DEFINED__ */


#ifndef __IHelpInfo_FWD_DEFINED__
#define __IHelpInfo_FWD_DEFINED__
typedef interface IHelpInfo IHelpInfo;
#endif 	/* __IHelpInfo_FWD_DEFINED__ */


#ifndef __IPart21Header_FWD_DEFINED__
#define __IPart21Header_FWD_DEFINED__
typedef interface IPart21Header IPart21Header;
#endif 	/* __IPart21Header_FWD_DEFINED__ */


#ifndef __StepPath_FWD_DEFINED__
#define __StepPath_FWD_DEFINED__

#ifdef __cplusplus
typedef class StepPath StepPath;
#else
typedef struct StepPath StepPath;
#endif /* __cplusplus */

#endif 	/* __StepPath_FWD_DEFINED__ */


#ifndef __Node_FWD_DEFINED__
#define __Node_FWD_DEFINED__

#ifdef __cplusplus
typedef class Node Node;
#else
typedef struct Node Node;
#endif /* __cplusplus */

#endif 	/* __Node_FWD_DEFINED__ */


#ifndef __Attribute_FWD_DEFINED__
#define __Attribute_FWD_DEFINED__

#ifdef __cplusplus
typedef class Attribute Attribute;
#else
typedef struct Attribute Attribute;
#endif /* __cplusplus */

#endif 	/* __Attribute_FWD_DEFINED__ */


#ifndef __AttributeList_FWD_DEFINED__
#define __AttributeList_FWD_DEFINED__

#ifdef __cplusplus
typedef class AttributeList AttributeList;
#else
typedef struct AttributeList AttributeList;
#endif /* __cplusplus */

#endif 	/* __AttributeList_FWD_DEFINED__ */


#ifndef __NodeList_FWD_DEFINED__
#define __NodeList_FWD_DEFINED__

#ifdef __cplusplus
typedef class NodeList NodeList;
#else
typedef struct NodeList NodeList;
#endif /* __cplusplus */

#endif 	/* __NodeList_FWD_DEFINED__ */


#ifndef __HelpInfo_FWD_DEFINED__
#define __HelpInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class HelpInfo HelpInfo;
#else
typedef struct HelpInfo HelpInfo;
#endif /* __cplusplus */

#endif 	/* __HelpInfo_FWD_DEFINED__ */


#ifndef __Part21Header_FWD_DEFINED__
#define __Part21Header_FWD_DEFINED__

#ifdef __cplusplus
typedef class Part21Header Part21Header;
#else
typedef struct Part21Header Part21Header;
#endif /* __cplusplus */

#endif 	/* __Part21Header_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_NiStep_0000_0000 */
/* [local] */ 






typedef /* [public][public] */ struct __MIDL___MIDL_itf_NiStep_0000_0000_0001
    {
    double x;
    double y;
    double z;
    } 	Vector3d;

typedef /* [public][public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_NiStep_0000_0000_0002
    {	unknown_	= 0,
	special_	= 1,
	this_	= 2,
	integer_	= 3,
	real_	= 4,
	string_	= 5,
	binary_	= 6,
	boolean_	= 7,
	logical_	= 8,
	number_	= 9,
	generic_	= 10,
	aggregate_	= 11,
	array_	= 12,
	bag_	= 13,
	set_	= 14,
	list_	= 15,
	list_item_	= 16,
	oneof_	= 17,
	entity_	= 18,
	entity_list_	= 19,
	enumeration_	= 20,
	select_	= 21,
	reference_	= 22,
	query_	= 23,
	op_	= 24,
	inverse_	= 25,
	identifier_	= 26,
	attribute_	= 27,
	derived_	= 28,
	funcall_	= 29,
	self_	= 31,
	vardef_	= 32,
	typereference_	= 33,
	underlying_type_	= 34,
	constant_	= 35,
	index_	= 36,
	rename_	= 37,
	typelist_	= 38,
	typemultilist_	= 39,
	nulltype_	= -1
    } 	StepNodeType;



extern RPC_IF_HANDLE __MIDL_itf_NiStep_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_NiStep_0000_0000_v0_0_s_ifspec;

#ifndef __INode_INTERFACE_DEFINED__
#define __INode_INTERFACE_DEFINED__

/* interface INode */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F7365B20-1F6C-4310-8E36-A1A2D443BFEC")
    INode : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSimpleType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsListType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Classname( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ StepNodeType *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListType( 
            /* [retval][out] */ StepNodeType *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListClassname( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVarString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVarString( 
            /* [in] */ BSTR bstrVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectNode( 
            /* [in] */ BSTR bstrVal,
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAttributeValue( 
            /* [in] */ BSTR attrname,
            /* [in] */ VARIANT vDefault,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAttribute( 
            /* [in] */ BSTR attrname,
            /* [retval][out] */ IAttribute **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAttributeList( 
            /* [retval][out] */ IAttributeList **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSimpleListType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAttributeClassname( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ BSTR *pBstrClassname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsKindOf( 
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddAttribute( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToVector( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ Vector3d *pVector) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNodeList( 
            /* [retval][out] */ INodeList **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectNodeList( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ INodeList **ppNodeList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAttributeValue( 
            /* [in] */ BSTR bstrPath,
            /* [in] */ VARIANT vValue,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAttributeString( 
            /* [in] */ BSTR bstrPath,
            /* [in] */ BSTR vStrValue,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAttributeNode( 
            /* [in] */ BSTR bstrPath,
            /* [in] */ INode *pNode,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateAttributeNode( 
            /* [in] */ BSTR spath,
            /* [in] */ BSTR classname,
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAttributeNodeList( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ INodeList **pNodeList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DoesPathExist( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INode * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSimpleType )( 
            INode * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsListType )( 
            INode * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            INode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Classname )( 
            INode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            INode * This,
            /* [retval][out] */ StepNodeType *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListType )( 
            INode * This,
            /* [retval][out] */ StepNodeType *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListClassname )( 
            INode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVarString )( 
            INode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVarString )( 
            INode * This,
            /* [in] */ BSTR bstrVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectNode )( 
            INode * This,
            /* [in] */ BSTR bstrVal,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeValue )( 
            INode * This,
            /* [in] */ BSTR attrname,
            /* [in] */ VARIANT vDefault,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAttribute )( 
            INode * This,
            /* [in] */ BSTR attrname,
            /* [retval][out] */ IAttribute **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeList )( 
            INode * This,
            /* [retval][out] */ IAttributeList **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSimpleListType )( 
            INode * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeClassname )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ BSTR *pBstrClassname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsKindOf )( 
            INode * This,
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddAttribute )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ToVector )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ Vector3d *pVector);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNodeList )( 
            INode * This,
            /* [retval][out] */ INodeList **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectNodeList )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ INodeList **ppNodeList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAttributeValue )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [in] */ VARIANT vValue,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAttributeString )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [in] */ BSTR vStrValue,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAttributeNode )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [in] */ INode *pNode,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAttributeNode )( 
            INode * This,
            /* [in] */ BSTR spath,
            /* [in] */ BSTR classname,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeNodeList )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ INodeList **pNodeList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DoesPathExist )( 
            INode * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        END_INTERFACE
    } INodeVtbl;

    interface INode
    {
        CONST_VTBL struct INodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INode_IsSimpleType(This,flag)	\
    ( (This)->lpVtbl -> IsSimpleType(This,flag) ) 

#define INode_IsListType(This,flag)	\
    ( (This)->lpVtbl -> IsListType(This,flag) ) 

#define INode_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define INode_get_Classname(This,pVal)	\
    ( (This)->lpVtbl -> get_Classname(This,pVal) ) 

#define INode_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define INode_get_ListType(This,pVal)	\
    ( (This)->lpVtbl -> get_ListType(This,pVal) ) 

#define INode_get_ListClassname(This,pVal)	\
    ( (This)->lpVtbl -> get_ListClassname(This,pVal) ) 

#define INode_GetVarString(This,pVal)	\
    ( (This)->lpVtbl -> GetVarString(This,pVal) ) 

#define INode_SetVarString(This,bstrVal)	\
    ( (This)->lpVtbl -> SetVarString(This,bstrVal) ) 

#define INode_SelectNode(This,bstrVal,ppNode)	\
    ( (This)->lpVtbl -> SelectNode(This,bstrVal,ppNode) ) 

#define INode_GetAttributeValue(This,attrname,vDefault,pVal)	\
    ( (This)->lpVtbl -> GetAttributeValue(This,attrname,vDefault,pVal) ) 

#define INode_GetAttribute(This,attrname,pVal)	\
    ( (This)->lpVtbl -> GetAttribute(This,attrname,pVal) ) 

#define INode_GetAttributeList(This,pVal)	\
    ( (This)->lpVtbl -> GetAttributeList(This,pVal) ) 

#define INode_IsSimpleListType(This,flag)	\
    ( (This)->lpVtbl -> IsSimpleListType(This,flag) ) 

#define INode_GetAttributeClassname(This,bstrPath,pBstrClassname)	\
    ( (This)->lpVtbl -> GetAttributeClassname(This,bstrPath,pBstrClassname) ) 

#define INode_IsKindOf(This,bstrClassname,flag)	\
    ( (This)->lpVtbl -> IsKindOf(This,bstrClassname,flag) ) 

#define INode_AddAttribute(This,bstrPath,flag)	\
    ( (This)->lpVtbl -> AddAttribute(This,bstrPath,flag) ) 

#define INode_ToVector(This,bstrPath,pVector)	\
    ( (This)->lpVtbl -> ToVector(This,bstrPath,pVector) ) 

#define INode_GetNodeList(This,pVal)	\
    ( (This)->lpVtbl -> GetNodeList(This,pVal) ) 

#define INode_SelectNodeList(This,bstrPath,ppNodeList)	\
    ( (This)->lpVtbl -> SelectNodeList(This,bstrPath,ppNodeList) ) 

#define INode_SetAttributeValue(This,bstrPath,vValue,flag)	\
    ( (This)->lpVtbl -> SetAttributeValue(This,bstrPath,vValue,flag) ) 

#define INode_SetAttributeString(This,bstrPath,vStrValue,flag)	\
    ( (This)->lpVtbl -> SetAttributeString(This,bstrPath,vStrValue,flag) ) 

#define INode_SetAttributeNode(This,bstrPath,pNode,flag)	\
    ( (This)->lpVtbl -> SetAttributeNode(This,bstrPath,pNode,flag) ) 

#define INode_CreateAttributeNode(This,spath,classname,ppNode)	\
    ( (This)->lpVtbl -> CreateAttributeNode(This,spath,classname,ppNode) ) 

#define INode_GetAttributeNodeList(This,bstrPath,pNodeList)	\
    ( (This)->lpVtbl -> GetAttributeNodeList(This,bstrPath,pNodeList) ) 

#define INode_DoesPathExist(This,bstrPath,flag)	\
    ( (This)->lpVtbl -> DoesPathExist(This,bstrPath,flag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INode_INTERFACE_DEFINED__ */


#ifndef __IAttribute_INTERFACE_DEFINED__
#define __IAttribute_INTERFACE_DEFINED__

/* interface IAttribute */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAttribute;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5D46B94-56BE-4F4A-8CFE-E9DD1F79C42B")
    IAttribute : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSimpleType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsListType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Classname( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ StepNodeType *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListType( 
            /* [retval][out] */ StepNodeType *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListClassname( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVarString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStepNode( 
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Atom( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Atom( 
            /* [in] */ LONG pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Owner( 
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dimension( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSimpleListType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStepNode( 
            /* [in] */ INode *pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [in] */ IAttribute *pTo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInheritedAttributeList( 
            /* [retval][out] */ IAttributeList **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNodeList( 
            /* [retval][out] */ INodeList **pNodeList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsASimpleType( 
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateNode( 
            /* [in] */ BSTR classname,
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToXmlString( 
            /* [retval][out] */ BSTR *bstrString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FromXmlString( 
            /* [in] */ BSTR bstrString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TypeCheckXmlString( 
            /* [in] */ BSTR bstrString,
            /* [retval][out] */ VARIANT_BOOL *bResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAttributeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAttribute * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAttribute * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAttribute * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAttribute * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAttribute * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAttribute * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAttribute * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSimpleType )( 
            IAttribute * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsListType )( 
            IAttribute * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAttribute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Classname )( 
            IAttribute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAttribute * This,
            /* [retval][out] */ StepNodeType *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListType )( 
            IAttribute * This,
            /* [retval][out] */ StepNodeType *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListClassname )( 
            IAttribute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVarString )( 
            IAttribute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStepNode )( 
            IAttribute * This,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Atom )( 
            IAttribute * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Atom )( 
            IAttribute * This,
            /* [in] */ LONG pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Owner )( 
            IAttribute * This,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAttribute * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dimension )( 
            IAttribute * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSimpleListType )( 
            IAttribute * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetStepNode )( 
            IAttribute * This,
            /* [in] */ INode *pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAttribute * This,
            /* [in] */ IAttribute *pTo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInheritedAttributeList )( 
            IAttribute * This,
            /* [retval][out] */ IAttributeList **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNodeList )( 
            IAttribute * This,
            /* [retval][out] */ INodeList **pNodeList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsASimpleType )( 
            IAttribute * This,
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNode )( 
            IAttribute * This,
            /* [in] */ BSTR classname,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ToXmlString )( 
            IAttribute * This,
            /* [retval][out] */ BSTR *bstrString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FromXmlString )( 
            IAttribute * This,
            /* [in] */ BSTR bstrString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TypeCheckXmlString )( 
            IAttribute * This,
            /* [in] */ BSTR bstrString,
            /* [retval][out] */ VARIANT_BOOL *bResult);
        
        END_INTERFACE
    } IAttributeVtbl;

    interface IAttribute
    {
        CONST_VTBL struct IAttributeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAttribute_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAttribute_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAttribute_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAttribute_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAttribute_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAttribute_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAttribute_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAttribute_IsSimpleType(This,flag)	\
    ( (This)->lpVtbl -> IsSimpleType(This,flag) ) 

#define IAttribute_IsListType(This,flag)	\
    ( (This)->lpVtbl -> IsListType(This,flag) ) 

#define IAttribute_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IAttribute_get_Classname(This,pVal)	\
    ( (This)->lpVtbl -> get_Classname(This,pVal) ) 

#define IAttribute_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define IAttribute_get_ListType(This,pVal)	\
    ( (This)->lpVtbl -> get_ListType(This,pVal) ) 

#define IAttribute_get_ListClassname(This,pVal)	\
    ( (This)->lpVtbl -> get_ListClassname(This,pVal) ) 

#define IAttribute_GetVarString(This,pVal)	\
    ( (This)->lpVtbl -> GetVarString(This,pVal) ) 

#define IAttribute_GetStepNode(This,ppNode)	\
    ( (This)->lpVtbl -> GetStepNode(This,ppNode) ) 

#define IAttribute_get_Atom(This,pVal)	\
    ( (This)->lpVtbl -> get_Atom(This,pVal) ) 

#define IAttribute_put_Atom(This,pVal)	\
    ( (This)->lpVtbl -> put_Atom(This,pVal) ) 

#define IAttribute_Owner(This,ppNode)	\
    ( (This)->lpVtbl -> Owner(This,ppNode) ) 

#define IAttribute_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IAttribute_get_Dimension(This,pVal)	\
    ( (This)->lpVtbl -> get_Dimension(This,pVal) ) 

#define IAttribute_IsSimpleListType(This,flag)	\
    ( (This)->lpVtbl -> IsSimpleListType(This,flag) ) 

#define IAttribute_SetStepNode(This,pNode)	\
    ( (This)->lpVtbl -> SetStepNode(This,pNode) ) 

#define IAttribute_Clone(This,pTo)	\
    ( (This)->lpVtbl -> Clone(This,pTo) ) 

#define IAttribute_GetInheritedAttributeList(This,pVal)	\
    ( (This)->lpVtbl -> GetInheritedAttributeList(This,pVal) ) 

#define IAttribute_GetNodeList(This,pNodeList)	\
    ( (This)->lpVtbl -> GetNodeList(This,pNodeList) ) 

#define IAttribute_IsASimpleType(This,bstrClassname,flag)	\
    ( (This)->lpVtbl -> IsASimpleType(This,bstrClassname,flag) ) 

#define IAttribute_CreateNode(This,classname,ppNode)	\
    ( (This)->lpVtbl -> CreateNode(This,classname,ppNode) ) 

#define IAttribute_ToXmlString(This,bstrString)	\
    ( (This)->lpVtbl -> ToXmlString(This,bstrString) ) 

#define IAttribute_FromXmlString(This,bstrString)	\
    ( (This)->lpVtbl -> FromXmlString(This,bstrString) ) 

#define IAttribute_TypeCheckXmlString(This,bstrString,bResult)	\
    ( (This)->lpVtbl -> TypeCheckXmlString(This,bstrString,bResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAttribute_INTERFACE_DEFINED__ */


#ifndef __IStepPath_INTERFACE_DEFINED__
#define __IStepPath_INTERFACE_DEFINED__

/* interface IStepPath */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IStepPath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7C5F41C5-8D02-468C-8282-908895DA7720")
    IStepPath : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE loadStep( 
            /* [in] */ BSTR bstrStep,
            /* [retval][out] */ VARIANT_BOOL *isSuccessful) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE loadFile( 
            /* [in] */ BSTR bstrFilename,
            /* [retval][out] */ VARIANT_BOOL *isSuccessful) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Verify( 
            /* [retval][out] */ VARIANT *stringsafearray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRoot( 
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRootAttribute( 
            /* [retval][out] */ IAttribute **ppAttribute) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRootAttributeList( 
            /* [retval][out] */ IAttributeList **ppAttributeList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateNode( 
            /* [in] */ BSTR classname,
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsASimpleType( 
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsASimpleListType( 
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClassSupertypeHierarchy( 
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT *stringsafearray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clearStep( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP21Header( 
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP21HeaderAttribute( 
            /* [retval][out] */ IAttribute **ppAttribute) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP21HeaderAttributeList( 
            /* [retval][out] */ IAttributeList **ppAttributeList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE saveFile( 
            /* [in] */ BSTR bstrFilename,
            /* [retval][out] */ VARIANT_BOOL *isSuccessful) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateNewProject( 
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TranslateP21ToHtml( 
            /* [in] */ BSTR bstrFilename,
            /* [retval][out] */ BSTR *bstrHtml) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStepPathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStepPath * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStepPath * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStepPath * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStepPath * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStepPath * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStepPath * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStepPath * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *loadStep )( 
            IStepPath * This,
            /* [in] */ BSTR bstrStep,
            /* [retval][out] */ VARIANT_BOOL *isSuccessful);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *loadFile )( 
            IStepPath * This,
            /* [in] */ BSTR bstrFilename,
            /* [retval][out] */ VARIANT_BOOL *isSuccessful);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            IStepPath * This,
            /* [retval][out] */ VARIANT *stringsafearray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRoot )( 
            IStepPath * This,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRootAttribute )( 
            IStepPath * This,
            /* [retval][out] */ IAttribute **ppAttribute);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRootAttributeList )( 
            IStepPath * This,
            /* [retval][out] */ IAttributeList **ppAttributeList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNode )( 
            IStepPath * This,
            /* [in] */ BSTR classname,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsASimpleType )( 
            IStepPath * This,
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsASimpleListType )( 
            IStepPath * This,
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClassSupertypeHierarchy )( 
            IStepPath * This,
            /* [in] */ BSTR bstrClassname,
            /* [retval][out] */ VARIANT *stringsafearray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *clearStep )( 
            IStepPath * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP21Header )( 
            IStepPath * This,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP21HeaderAttribute )( 
            IStepPath * This,
            /* [retval][out] */ IAttribute **ppAttribute);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP21HeaderAttributeList )( 
            IStepPath * This,
            /* [retval][out] */ IAttributeList **ppAttributeList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *saveFile )( 
            IStepPath * This,
            /* [in] */ BSTR bstrFilename,
            /* [retval][out] */ VARIANT_BOOL *isSuccessful);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNewProject )( 
            IStepPath * This,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TranslateP21ToHtml )( 
            IStepPath * This,
            /* [in] */ BSTR bstrFilename,
            /* [retval][out] */ BSTR *bstrHtml);
        
        END_INTERFACE
    } IStepPathVtbl;

    interface IStepPath
    {
        CONST_VTBL struct IStepPathVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStepPath_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStepPath_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStepPath_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStepPath_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IStepPath_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IStepPath_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IStepPath_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IStepPath_loadStep(This,bstrStep,isSuccessful)	\
    ( (This)->lpVtbl -> loadStep(This,bstrStep,isSuccessful) ) 

#define IStepPath_loadFile(This,bstrFilename,isSuccessful)	\
    ( (This)->lpVtbl -> loadFile(This,bstrFilename,isSuccessful) ) 

#define IStepPath_Verify(This,stringsafearray)	\
    ( (This)->lpVtbl -> Verify(This,stringsafearray) ) 

#define IStepPath_GetRoot(This,ppNode)	\
    ( (This)->lpVtbl -> GetRoot(This,ppNode) ) 

#define IStepPath_GetRootAttribute(This,ppAttribute)	\
    ( (This)->lpVtbl -> GetRootAttribute(This,ppAttribute) ) 

#define IStepPath_GetRootAttributeList(This,ppAttributeList)	\
    ( (This)->lpVtbl -> GetRootAttributeList(This,ppAttributeList) ) 

#define IStepPath_CreateNode(This,classname,ppNode)	\
    ( (This)->lpVtbl -> CreateNode(This,classname,ppNode) ) 

#define IStepPath_IsASimpleType(This,bstrClassname,flag)	\
    ( (This)->lpVtbl -> IsASimpleType(This,bstrClassname,flag) ) 

#define IStepPath_IsASimpleListType(This,bstrClassname,flag)	\
    ( (This)->lpVtbl -> IsASimpleListType(This,bstrClassname,flag) ) 

#define IStepPath_GetClassSupertypeHierarchy(This,bstrClassname,stringsafearray)	\
    ( (This)->lpVtbl -> GetClassSupertypeHierarchy(This,bstrClassname,stringsafearray) ) 

#define IStepPath_clearStep(This)	\
    ( (This)->lpVtbl -> clearStep(This) ) 

#define IStepPath_GetP21Header(This,ppNode)	\
    ( (This)->lpVtbl -> GetP21Header(This,ppNode) ) 

#define IStepPath_GetP21HeaderAttribute(This,ppAttribute)	\
    ( (This)->lpVtbl -> GetP21HeaderAttribute(This,ppAttribute) ) 

#define IStepPath_GetP21HeaderAttributeList(This,ppAttributeList)	\
    ( (This)->lpVtbl -> GetP21HeaderAttributeList(This,ppAttributeList) ) 

#define IStepPath_saveFile(This,bstrFilename,isSuccessful)	\
    ( (This)->lpVtbl -> saveFile(This,bstrFilename,isSuccessful) ) 

#define IStepPath_CreateNewProject(This,ppNode)	\
    ( (This)->lpVtbl -> CreateNewProject(This,ppNode) ) 

#define IStepPath_TranslateP21ToHtml(This,bstrFilename,bstrHtml)	\
    ( (This)->lpVtbl -> TranslateP21ToHtml(This,bstrFilename,bstrHtml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStepPath_INTERFACE_DEFINED__ */


#ifndef __IAttributeList_INTERFACE_DEFINED__
#define __IAttributeList_INTERFACE_DEFINED__

/* interface IAttributeList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAttributeList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71DCBB22-2655-426E-B2E9-295DA937C3C3")
    IAttributeList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_item( 
            /* [in] */ LONG index,
            /* [retval][out] */ IAttribute **listItem) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE nextAttribute( 
            /* [retval][out] */ IAttribute **nextItem) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__newEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE back( 
            /* [retval][out] */ IAttribute **listItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAttributeListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAttributeList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAttributeList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAttributeList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAttributeList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAttributeList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAttributeList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAttributeList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_item )( 
            IAttributeList * This,
            /* [in] */ LONG index,
            /* [retval][out] */ IAttribute **listItem);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_length )( 
            IAttributeList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *reset )( 
            IAttributeList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *nextAttribute )( 
            IAttributeList * This,
            /* [retval][out] */ IAttribute **nextItem);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__newEnum )( 
            IAttributeList * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *back )( 
            IAttributeList * This,
            /* [retval][out] */ IAttribute **listItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *size )( 
            IAttributeList * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IAttributeListVtbl;

    interface IAttributeList
    {
        CONST_VTBL struct IAttributeListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAttributeList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAttributeList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAttributeList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAttributeList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAttributeList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAttributeList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAttributeList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAttributeList_get_item(This,index,listItem)	\
    ( (This)->lpVtbl -> get_item(This,index,listItem) ) 

#define IAttributeList_get_length(This,pVal)	\
    ( (This)->lpVtbl -> get_length(This,pVal) ) 

#define IAttributeList_reset(This)	\
    ( (This)->lpVtbl -> reset(This) ) 

#define IAttributeList_nextAttribute(This,nextItem)	\
    ( (This)->lpVtbl -> nextAttribute(This,nextItem) ) 

#define IAttributeList_get__newEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__newEnum(This,pVal) ) 

#define IAttributeList_back(This,listItem)	\
    ( (This)->lpVtbl -> back(This,listItem) ) 

#define IAttributeList_size(This,pVal)	\
    ( (This)->lpVtbl -> size(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAttributeList_INTERFACE_DEFINED__ */


#ifndef __INodeList_INTERFACE_DEFINED__
#define __INodeList_INTERFACE_DEFINED__

/* interface INodeList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INodeList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A2860F1F-8647-4EC3-B22B-24F50F96B016")
    INodeList : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSimpleType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsListType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Classname( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ StepNodeType *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListType( 
            /* [retval][out] */ StepNodeType *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListClassname( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_item( 
            /* [in] */ LONG index,
            /* [retval][out] */ INode **listItem) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE nextNode( 
            /* [retval][out] */ INode **nextItem) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__newEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE back( 
            /* [retval][out] */ INode **listItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE push_back( 
            /* [in] */ BSTR bstrClassname,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ INode **newListItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSimpleListType( 
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteChild( 
            /* [in] */ INode *pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIndex( 
            /* [in] */ IAttribute *pNode,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsASimpleListType( 
            /* [in] */ BSTR bstrVal,
            /* [retval][out] */ VARIANT_BOOL *flag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SwapListItems( 
            /* [in] */ LONG index1,
            /* [in] */ LONG index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetListItem( 
            /* [in] */ LONG nVal,
            /* [in] */ INode *pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetListVarString( 
            /* [in] */ BSTR bstrDelimiter,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetListVarString( 
            /* [in] */ BSTR bstrVal,
            /* [in] */ BSTR bstrDelimiter) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStepNode( 
            /* [retval][out] */ INode **ppNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAttributeList( 
            /* [retval][out] */ IAttributeList **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INodeListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INodeList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INodeList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INodeList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INodeList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INodeList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INodeList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INodeList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSimpleType )( 
            INodeList * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsListType )( 
            INodeList * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            INodeList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Classname )( 
            INodeList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            INodeList * This,
            /* [retval][out] */ StepNodeType *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListType )( 
            INodeList * This,
            /* [retval][out] */ StepNodeType *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListClassname )( 
            INodeList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_item )( 
            INodeList * This,
            /* [in] */ LONG index,
            /* [retval][out] */ INode **listItem);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_length )( 
            INodeList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *reset )( 
            INodeList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *nextNode )( 
            INodeList * This,
            /* [retval][out] */ INode **nextItem);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__newEnum )( 
            INodeList * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *back )( 
            INodeList * This,
            /* [retval][out] */ INode **listItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *size )( 
            INodeList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *push_back )( 
            INodeList * This,
            /* [in] */ BSTR bstrClassname,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ INode **newListItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSimpleListType )( 
            INodeList * This,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteChild )( 
            INodeList * This,
            /* [in] */ INode *pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIndex )( 
            INodeList * This,
            /* [in] */ IAttribute *pNode,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsASimpleListType )( 
            INodeList * This,
            /* [in] */ BSTR bstrVal,
            /* [retval][out] */ VARIANT_BOOL *flag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SwapListItems )( 
            INodeList * This,
            /* [in] */ LONG index1,
            /* [in] */ LONG index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetListItem )( 
            INodeList * This,
            /* [in] */ LONG nVal,
            /* [in] */ INode *pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetListVarString )( 
            INodeList * This,
            /* [in] */ BSTR bstrDelimiter,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetListVarString )( 
            INodeList * This,
            /* [in] */ BSTR bstrVal,
            /* [in] */ BSTR bstrDelimiter);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStepNode )( 
            INodeList * This,
            /* [retval][out] */ INode **ppNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeList )( 
            INodeList * This,
            /* [retval][out] */ IAttributeList **pVal);
        
        END_INTERFACE
    } INodeListVtbl;

    interface INodeList
    {
        CONST_VTBL struct INodeListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INodeList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INodeList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INodeList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INodeList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INodeList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INodeList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INodeList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INodeList_IsSimpleType(This,flag)	\
    ( (This)->lpVtbl -> IsSimpleType(This,flag) ) 

#define INodeList_IsListType(This,flag)	\
    ( (This)->lpVtbl -> IsListType(This,flag) ) 

#define INodeList_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define INodeList_get_Classname(This,pVal)	\
    ( (This)->lpVtbl -> get_Classname(This,pVal) ) 

#define INodeList_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define INodeList_get_ListType(This,pVal)	\
    ( (This)->lpVtbl -> get_ListType(This,pVal) ) 

#define INodeList_get_ListClassname(This,pVal)	\
    ( (This)->lpVtbl -> get_ListClassname(This,pVal) ) 

#define INodeList_get_item(This,index,listItem)	\
    ( (This)->lpVtbl -> get_item(This,index,listItem) ) 

#define INodeList_get_length(This,pVal)	\
    ( (This)->lpVtbl -> get_length(This,pVal) ) 

#define INodeList_reset(This)	\
    ( (This)->lpVtbl -> reset(This) ) 

#define INodeList_nextNode(This,nextItem)	\
    ( (This)->lpVtbl -> nextNode(This,nextItem) ) 

#define INodeList_get__newEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__newEnum(This,pVal) ) 

#define INodeList_back(This,listItem)	\
    ( (This)->lpVtbl -> back(This,listItem) ) 

#define INodeList_size(This,pVal)	\
    ( (This)->lpVtbl -> size(This,pVal) ) 

#define INodeList_push_back(This,bstrClassname,bstrName,newListItem)	\
    ( (This)->lpVtbl -> push_back(This,bstrClassname,bstrName,newListItem) ) 

#define INodeList_IsSimpleListType(This,flag)	\
    ( (This)->lpVtbl -> IsSimpleListType(This,flag) ) 

#define INodeList_DeleteChild(This,pNode)	\
    ( (This)->lpVtbl -> DeleteChild(This,pNode) ) 

#define INodeList_GetIndex(This,pNode,pVal)	\
    ( (This)->lpVtbl -> GetIndex(This,pNode,pVal) ) 

#define INodeList_IsASimpleListType(This,bstrVal,flag)	\
    ( (This)->lpVtbl -> IsASimpleListType(This,bstrVal,flag) ) 

#define INodeList_SwapListItems(This,index1,index)	\
    ( (This)->lpVtbl -> SwapListItems(This,index1,index) ) 

#define INodeList_SetListItem(This,nVal,pNode)	\
    ( (This)->lpVtbl -> SetListItem(This,nVal,pNode) ) 

#define INodeList_GetListVarString(This,bstrDelimiter,pVal)	\
    ( (This)->lpVtbl -> GetListVarString(This,bstrDelimiter,pVal) ) 

#define INodeList_SetListVarString(This,bstrVal,bstrDelimiter)	\
    ( (This)->lpVtbl -> SetListVarString(This,bstrVal,bstrDelimiter) ) 

#define INodeList_GetStepNode(This,ppNode)	\
    ( (This)->lpVtbl -> GetStepNode(This,ppNode) ) 

#define INodeList_GetAttributeList(This,pVal)	\
    ( (This)->lpVtbl -> GetAttributeList(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INodeList_INTERFACE_DEFINED__ */


#ifndef __IHelpInfo_INTERFACE_DEFINED__
#define __IHelpInfo_INTERFACE_DEFINED__

/* interface IHelpInfo */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHelpInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("41048A68-9CCF-4EC7-82BB-415BD36625F8")
    IHelpInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariableDescription( 
            /* [in] */ BSTR classname,
            /* [in] */ BSTR variablename,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClassDescription( 
            /* [in] */ BSTR classname,
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHelpInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHelpInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHelpInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHelpInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHelpInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHelpInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHelpInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHelpInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVariableDescription )( 
            IHelpInfo * This,
            /* [in] */ BSTR classname,
            /* [in] */ BSTR variablename,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClassDescription )( 
            IHelpInfo * This,
            /* [in] */ BSTR classname,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IHelpInfoVtbl;

    interface IHelpInfo
    {
        CONST_VTBL struct IHelpInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHelpInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHelpInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHelpInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHelpInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHelpInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHelpInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHelpInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHelpInfo_GetVariableDescription(This,classname,variablename,pVal)	\
    ( (This)->lpVtbl -> GetVariableDescription(This,classname,variablename,pVal) ) 

#define IHelpInfo_GetClassDescription(This,classname,pVal)	\
    ( (This)->lpVtbl -> GetClassDescription(This,classname,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHelpInfo_INTERFACE_DEFINED__ */


#ifndef __IPart21Header_INTERFACE_DEFINED__
#define __IPart21Header_INTERFACE_DEFINED__

/* interface IPart21Header */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPart21Header;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2328777F-0034-4253-84A0-58CD1E4271A1")
    IPart21Header : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IPart21HeaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPart21Header * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPart21Header * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPart21Header * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPart21Header * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPart21Header * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPart21Header * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPart21Header * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IPart21HeaderVtbl;

    interface IPart21Header
    {
        CONST_VTBL struct IPart21HeaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPart21Header_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPart21Header_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPart21Header_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPart21Header_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPart21Header_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPart21Header_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPart21Header_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPart21Header_INTERFACE_DEFINED__ */



#ifndef __NiStepLib_LIBRARY_DEFINED__
#define __NiStepLib_LIBRARY_DEFINED__

/* library NiStepLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NiStepLib;

EXTERN_C const CLSID CLSID_StepPath;

#ifdef __cplusplus

class DECLSPEC_UUID("8FC9FCDD-3859-4753-972C-77C172944511")
StepPath;
#endif

EXTERN_C const CLSID CLSID_Node;

#ifdef __cplusplus

class DECLSPEC_UUID("158E69A1-EFCB-4E9E-8A13-07E19D3E01CB")
Node;
#endif

EXTERN_C const CLSID CLSID_Attribute;

#ifdef __cplusplus

class DECLSPEC_UUID("B93FE105-1C8B-48AD-83C2-675965F9A34C")
Attribute;
#endif

EXTERN_C const CLSID CLSID_AttributeList;

#ifdef __cplusplus

class DECLSPEC_UUID("CA9E9828-9808-4EEA-A050-82C63CD6B300")
AttributeList;
#endif

EXTERN_C const CLSID CLSID_NodeList;

#ifdef __cplusplus

class DECLSPEC_UUID("0CD0DE93-C09D-4259-81CC-F73C40A2F8D0")
NodeList;
#endif

EXTERN_C const CLSID CLSID_HelpInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("EE4E8779-2476-46A6-9CD8-9CD48CF499A3")
HelpInfo;
#endif

EXTERN_C const CLSID CLSID_Part21Header;

#ifdef __cplusplus

class DECLSPEC_UUID("F2F2F428-B6B9-49C3-93F8-984B73D9B085")
Part21Header;
#endif
#endif /* __NiStepLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


