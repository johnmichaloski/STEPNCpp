

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Sat Nov 08 21:35:34 2008
 */
/* Compiler settings for .\OGLVerifier.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
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

#ifndef __OGLVerifier_h__
#define __OGLVerifier_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOglPlotter_FWD_DEFINED__
#define __IOglPlotter_FWD_DEFINED__
typedef interface IOglPlotter IOglPlotter;
#endif 	/* __IOglPlotter_FWD_DEFINED__ */


#ifndef __OglPlotter_FWD_DEFINED__
#define __OglPlotter_FWD_DEFINED__

#ifdef __cplusplus
typedef class OglPlotter OglPlotter;
#else
typedef struct OglPlotter OglPlotter;
#endif /* __cplusplus */

#endif 	/* __OglPlotter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IOglPlotter_INTERFACE_DEFINED__
#define __IOglPlotter_INTERFACE_DEFINED__

/* interface IOglPlotter */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOglPlotter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2907BFE3-2909-437A-86B1-EF515034B98B")
    IOglPlotter : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Color( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BkColor( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BkColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Line( 
            DOUBLE x0,
            /* [in] */ DOUBLE y0,
            /* [in] */ DOUBLE z0,
            DOUBLE x1,
            /* [in] */ DOUBLE y1,
            /* [in] */ DOUBLE z1,
            /* [retval][out] */ LONG *atom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Resolution( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Resolution( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGraphRange( 
            /* [in] */ DOUBLE xmin,
            /* [in] */ DOUBLE ymin,
            /* [in] */ DOUBLE zmin,
            /* [in] */ DOUBLE xmax,
            /* [in] */ DOUBLE ymax,
            /* [in] */ DOUBLE zmax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall Polygon( 
            /* [in] */ SAFEARRAY * psaArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewPolygon( 
            /* [retval][out] */ LONG *atom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPolygonVertex( 
            /* [in] */ LONG atom,
            DOUBLE x0,
            /* [in] */ DOUBLE y0,
            /* [in] */ DOUBLE z0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ LONG atom) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOglPlotterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOglPlotter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOglPlotter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOglPlotter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOglPlotter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOglPlotter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOglPlotter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOglPlotter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IOglPlotter * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IOglPlotter * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BkColor )( 
            IOglPlotter * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BkColor )( 
            IOglPlotter * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Line )( 
            IOglPlotter * This,
            DOUBLE x0,
            /* [in] */ DOUBLE y0,
            /* [in] */ DOUBLE z0,
            DOUBLE x1,
            /* [in] */ DOUBLE y1,
            /* [in] */ DOUBLE z1,
            /* [retval][out] */ LONG *atom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IOglPlotter * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resolution )( 
            IOglPlotter * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Resolution )( 
            IOglPlotter * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGraphRange )( 
            IOglPlotter * This,
            /* [in] */ DOUBLE xmin,
            /* [in] */ DOUBLE ymin,
            /* [in] */ DOUBLE zmin,
            /* [in] */ DOUBLE xmax,
            /* [in] */ DOUBLE ymax,
            /* [in] */ DOUBLE zmax);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *Polygon )( 
            IOglPlotter * This,
            /* [in] */ SAFEARRAY * psaArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewPolygon )( 
            IOglPlotter * This,
            /* [retval][out] */ LONG *atom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPolygonVertex )( 
            IOglPlotter * This,
            /* [in] */ LONG atom,
            DOUBLE x0,
            /* [in] */ DOUBLE y0,
            /* [in] */ DOUBLE z0);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IOglPlotter * This,
            /* [in] */ LONG atom);
        
        END_INTERFACE
    } IOglPlotterVtbl;

    interface IOglPlotter
    {
        CONST_VTBL struct IOglPlotterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOglPlotter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOglPlotter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOglPlotter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOglPlotter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOglPlotter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOglPlotter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOglPlotter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOglPlotter_get_Color(This,pVal)	\
    (This)->lpVtbl -> get_Color(This,pVal)

#define IOglPlotter_put_Color(This,newVal)	\
    (This)->lpVtbl -> put_Color(This,newVal)

#define IOglPlotter_get_BkColor(This,pVal)	\
    (This)->lpVtbl -> get_BkColor(This,pVal)

#define IOglPlotter_put_BkColor(This,newVal)	\
    (This)->lpVtbl -> put_BkColor(This,newVal)

#define IOglPlotter_Line(This,x0,y0,z0,x1,y1,z1,atom)	\
    (This)->lpVtbl -> Line(This,x0,y0,z0,x1,y1,z1,atom)

#define IOglPlotter_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IOglPlotter_get_Resolution(This,pVal)	\
    (This)->lpVtbl -> get_Resolution(This,pVal)

#define IOglPlotter_put_Resolution(This,newVal)	\
    (This)->lpVtbl -> put_Resolution(This,newVal)

#define IOglPlotter_SetGraphRange(This,xmin,ymin,zmin,xmax,ymax,zmax)	\
    (This)->lpVtbl -> SetGraphRange(This,xmin,ymin,zmin,xmax,ymax,zmax)

#define IOglPlotter_Polygon(This,psaArray)	\
    (This)->lpVtbl -> Polygon(This,psaArray)

#define IOglPlotter_NewPolygon(This,atom)	\
    (This)->lpVtbl -> NewPolygon(This,atom)

#define IOglPlotter_AddPolygonVertex(This,atom,x0,y0,z0)	\
    (This)->lpVtbl -> AddPolygonVertex(This,atom,x0,y0,z0)

#define IOglPlotter_Delete(This,atom)	\
    (This)->lpVtbl -> Delete(This,atom)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOglPlotter_get_Color_Proxy( 
    IOglPlotter * This,
    /* [retval][out] */ OLE_COLOR *pVal);


void __RPC_STUB IOglPlotter_get_Color_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOglPlotter_put_Color_Proxy( 
    IOglPlotter * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB IOglPlotter_put_Color_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOglPlotter_get_BkColor_Proxy( 
    IOglPlotter * This,
    /* [retval][out] */ OLE_COLOR *pVal);


void __RPC_STUB IOglPlotter_get_BkColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOglPlotter_put_BkColor_Proxy( 
    IOglPlotter * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB IOglPlotter_put_BkColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOglPlotter_Line_Proxy( 
    IOglPlotter * This,
    DOUBLE x0,
    /* [in] */ DOUBLE y0,
    /* [in] */ DOUBLE z0,
    DOUBLE x1,
    /* [in] */ DOUBLE y1,
    /* [in] */ DOUBLE z1,
    /* [retval][out] */ LONG *atom);


void __RPC_STUB IOglPlotter_Line_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOglPlotter_Clear_Proxy( 
    IOglPlotter * This);


void __RPC_STUB IOglPlotter_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOglPlotter_get_Resolution_Proxy( 
    IOglPlotter * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOglPlotter_get_Resolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOglPlotter_put_Resolution_Proxy( 
    IOglPlotter * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOglPlotter_put_Resolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOglPlotter_SetGraphRange_Proxy( 
    IOglPlotter * This,
    /* [in] */ DOUBLE xmin,
    /* [in] */ DOUBLE ymin,
    /* [in] */ DOUBLE zmin,
    /* [in] */ DOUBLE xmax,
    /* [in] */ DOUBLE ymax,
    /* [in] */ DOUBLE zmax);


void __RPC_STUB IOglPlotter_SetGraphRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT __stdcall IOglPlotter_Polygon_Proxy( 
    IOglPlotter * This,
    /* [in] */ SAFEARRAY * psaArray);


void __RPC_STUB IOglPlotter_Polygon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOglPlotter_NewPolygon_Proxy( 
    IOglPlotter * This,
    /* [retval][out] */ LONG *atom);


void __RPC_STUB IOglPlotter_NewPolygon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOglPlotter_AddPolygonVertex_Proxy( 
    IOglPlotter * This,
    /* [in] */ LONG atom,
    DOUBLE x0,
    /* [in] */ DOUBLE y0,
    /* [in] */ DOUBLE z0);


void __RPC_STUB IOglPlotter_AddPolygonVertex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOglPlotter_Delete_Proxy( 
    IOglPlotter * This,
    /* [in] */ LONG atom);


void __RPC_STUB IOglPlotter_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOglPlotter_INTERFACE_DEFINED__ */



#ifndef __OGLViewLib_LIBRARY_DEFINED__
#define __OGLViewLib_LIBRARY_DEFINED__

/* library OGLViewLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OGLViewLib;

EXTERN_C const CLSID CLSID_OglPlotter;

#ifdef __cplusplus

class DECLSPEC_UUID("89D21FAA-0294-4540-919F-DD432FD2246B")
OglPlotter;
#endif
#endif /* __OGLViewLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


