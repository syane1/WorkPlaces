/*** Autogenerated by WIDL 1.6 from include/dispex.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __dispex_h__
#define __dispex_h__

/* Forward declarations */

#ifndef __IDispatchEx_FWD_DEFINED__
#define __IDispatchEx_FWD_DEFINED__
typedef interface IDispatchEx IDispatchEx;
#endif

#ifndef __IDispError_FWD_DEFINED__
#define __IDispError_FWD_DEFINED__
typedef interface IDispError IDispError;
#endif

#ifndef __IVariantChangeType_FWD_DEFINED__
#define __IVariantChangeType_FWD_DEFINED__
typedef interface IVariantChangeType IVariantChangeType;
#endif

#ifndef __IObjectIdentity_FWD_DEFINED__
#define __IObjectIdentity_FWD_DEFINED__
typedef interface IObjectIdentity IObjectIdentity;
#endif

#ifndef __ICanHandleException_FWD_DEFINED__
#define __ICanHandleException_FWD_DEFINED__
typedef interface ICanHandleException ICanHandleException;
#endif

#ifndef __IProvideRuntimeContext_FWD_DEFINED__
#define __IProvideRuntimeContext_FWD_DEFINED__
typedef interface IProvideRuntimeContext IProvideRuntimeContext;
#endif

/* Headers for imported files */

#include <ocidl.h>
#include <oleidl.h>
#include <oaidl.h>
#include <servprov.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef __IDispatchEx_FWD_DEFINED__
#define __IDispatchEx_FWD_DEFINED__
typedef interface IDispatchEx IDispatchEx;
#endif

#ifndef __IDispError_FWD_DEFINED__
#define __IDispError_FWD_DEFINED__
typedef interface IDispError IDispError;
#endif

#ifndef __IVariantChangeType_FWD_DEFINED__
#define __IVariantChangeType_FWD_DEFINED__
typedef interface IVariantChangeType IVariantChangeType;
#endif

#ifndef DISPEX_H_
#define DISPEX_H_

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#include "servprov.h"

#ifndef _NO_DISPATCHEX_GUIDS

DEFINE_GUID(SID_VariantConversion, 0x1f101481, 0xbccd, 0x11d0, 0x93, 0x36, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9);
DEFINE_GUID(SID_GetCaller, 0x4717cc40, 0xbcb9, 0x11d0, 0x93, 0x36, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9);
DEFINE_GUID(SID_ProvideRuntimeContext, 0x74a5040c, 0xdd0c, 0x48f0, 0xac, 0x85, 0x19, 0x4c, 0x32, 0x59, 0x18, 0xa);

#define SID_GetScriptSite IID_IActiveScriptSite
#endif

#ifndef _NO_DISPATCHEX_CONSTS

#define fdexNameCaseSensitive 0x1
#define fdexNameEnsure 0x2
#define fdexNameImplicit 0x4
#define fdexNameCaseInsensitive 0x8
#define fdexNameInternal 0x10
#define fdexNameNoDynamicProperties 0x20

#define fdexPropCanGet 0x1
#define fdexPropCannotGet 0x2
#define fdexPropCanPut 0x4
#define fdexPropCannotPut 0x8
#define fdexPropCanPutRef 0x10
#define fdexPropCannotPutRef 0x20
#define fdexPropNoSideEffects 0x40
#define fdexPropDynamicType 0x80
#define fdexPropCanCall 0x100
#define fdexPropCannotCall 0x200
#define fdexPropCanConstruct 0x400
#define fdexPropCannotConstruct 0x800
#define fdexPropCanSourceEvents 0x1000
#define fdexPropCannotSourceEvents 0x02000

#define grfdexPropCanAll (fdexPropCanGet | fdexPropCanPut | fdexPropCanPutRef | fdexPropCanCall | fdexPropCanConstruct | fdexPropCanSourceEvents)
#define grfdexPropCannotAll (fdexPropCannotGet | fdexPropCannotPut | fdexPropCannotPutRef | fdexPropCannotCall | fdexPropCannotConstruct | fdexPropCannotSourceEvents)
#define grfdexPropExtraAll (fdexPropNoSideEffects | fdexPropDynamicType)
#define grfdexPropAll (grfdexPropCanAll | grfdexPropCannotAll | grfdexPropExtraAll)

#define fdexEnumDefault 0x1
#define fdexEnumAll 0x2

#define DISPATCH_CONSTRUCT 0x4000
#define DISPID_THIS (-613)
#define DISPID_STARTENUM DISPID_UNKNOWN
#endif

/*****************************************************************************
 * IDispatchEx interface
 */
#ifndef __IDispatchEx_INTERFACE_DEFINED__
#define __IDispatchEx_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDispatchEx, 0xa6ef9860, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("a6ef9860-c720-11d0-9337-00a0c90dcaa9")
IDispatchEx : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE GetDispID(
        BSTR bstrName,
        DWORD grfdex,
        DISPID *pid) = 0;

    virtual HRESULT STDMETHODCALLTYPE InvokeEx(
        DISPID id,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pdp,
        VARIANT *pvarRes,
        EXCEPINFO *pei,
        IServiceProvider *pspCaller) = 0;

    virtual HRESULT STDMETHODCALLTYPE DeleteMemberByName(
        BSTR bstrName,
        DWORD grfdex) = 0;

    virtual HRESULT STDMETHODCALLTYPE DeleteMemberByDispID(
        DISPID id) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMemberProperties(
        DISPID id,
        DWORD grfdexFetch,
        DWORD *pgrfdex) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMemberName(
        DISPID id,
        BSTR *pbstrName) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetNextDispID(
        DWORD grfdex,
        DISPID id,
        DISPID *pid) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetNameSpaceParent(
        IUnknown **ppunk) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDispatchEx, 0xa6ef9860, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9)
#endif
#else
typedef struct IDispatchExVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDispatchEx* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDispatchEx* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDispatchEx* This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        IDispatchEx* This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        IDispatchEx* This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        IDispatchEx* This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        IDispatchEx* This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** IDispatchEx methods ***/
    HRESULT (STDMETHODCALLTYPE *GetDispID)(
        IDispatchEx* This,
        BSTR bstrName,
        DWORD grfdex,
        DISPID *pid);

    HRESULT (STDMETHODCALLTYPE *InvokeEx)(
        IDispatchEx* This,
        DISPID id,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pdp,
        VARIANT *pvarRes,
        EXCEPINFO *pei,
        IServiceProvider *pspCaller);

    HRESULT (STDMETHODCALLTYPE *DeleteMemberByName)(
        IDispatchEx* This,
        BSTR bstrName,
        DWORD grfdex);

    HRESULT (STDMETHODCALLTYPE *DeleteMemberByDispID)(
        IDispatchEx* This,
        DISPID id);

    HRESULT (STDMETHODCALLTYPE *GetMemberProperties)(
        IDispatchEx* This,
        DISPID id,
        DWORD grfdexFetch,
        DWORD *pgrfdex);

    HRESULT (STDMETHODCALLTYPE *GetMemberName)(
        IDispatchEx* This,
        DISPID id,
        BSTR *pbstrName);

    HRESULT (STDMETHODCALLTYPE *GetNextDispID)(
        IDispatchEx* This,
        DWORD grfdex,
        DISPID id,
        DISPID *pid);

    HRESULT (STDMETHODCALLTYPE *GetNameSpaceParent)(
        IDispatchEx* This,
        IUnknown **ppunk);

    END_INTERFACE
} IDispatchExVtbl;
interface IDispatchEx {
    CONST_VTBL IDispatchExVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDispatchEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDispatchEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDispatchEx_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define IDispatchEx_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDispatchEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDispatchEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDispatchEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** IDispatchEx methods ***/
#define IDispatchEx_GetDispID(This,bstrName,grfdex,pid) (This)->lpVtbl->GetDispID(This,bstrName,grfdex,pid)
#define IDispatchEx_InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller) (This)->lpVtbl->InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)
#define IDispatchEx_DeleteMemberByName(This,bstrName,grfdex) (This)->lpVtbl->DeleteMemberByName(This,bstrName,grfdex)
#define IDispatchEx_DeleteMemberByDispID(This,id) (This)->lpVtbl->DeleteMemberByDispID(This,id)
#define IDispatchEx_GetMemberProperties(This,id,grfdexFetch,pgrfdex) (This)->lpVtbl->GetMemberProperties(This,id,grfdexFetch,pgrfdex)
#define IDispatchEx_GetMemberName(This,id,pbstrName) (This)->lpVtbl->GetMemberName(This,id,pbstrName)
#define IDispatchEx_GetNextDispID(This,grfdex,id,pid) (This)->lpVtbl->GetNextDispID(This,grfdex,id,pid)
#define IDispatchEx_GetNameSpaceParent(This,ppunk) (This)->lpVtbl->GetNameSpaceParent(This,ppunk)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDispatchEx_QueryInterface(IDispatchEx* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IDispatchEx_AddRef(IDispatchEx* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDispatchEx_Release(IDispatchEx* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static FORCEINLINE HRESULT IDispatchEx_GetTypeInfoCount(IDispatchEx* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static FORCEINLINE HRESULT IDispatchEx_GetTypeInfo(IDispatchEx* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static FORCEINLINE HRESULT IDispatchEx_GetIDsOfNames(IDispatchEx* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static FORCEINLINE HRESULT IDispatchEx_Invoke(IDispatchEx* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** IDispatchEx methods ***/
static FORCEINLINE HRESULT IDispatchEx_GetDispID(IDispatchEx* This,BSTR bstrName,DWORD grfdex,DISPID *pid) {
    return This->lpVtbl->GetDispID(This,bstrName,grfdex,pid);
}
static FORCEINLINE HRESULT IDispatchEx_InvokeEx(IDispatchEx* This,DISPID id,LCID lcid,WORD wFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller) {
    return This->lpVtbl->InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller);
}
static FORCEINLINE HRESULT IDispatchEx_DeleteMemberByName(IDispatchEx* This,BSTR bstrName,DWORD grfdex) {
    return This->lpVtbl->DeleteMemberByName(This,bstrName,grfdex);
}
static FORCEINLINE HRESULT IDispatchEx_DeleteMemberByDispID(IDispatchEx* This,DISPID id) {
    return This->lpVtbl->DeleteMemberByDispID(This,id);
}
static FORCEINLINE HRESULT IDispatchEx_GetMemberProperties(IDispatchEx* This,DISPID id,DWORD grfdexFetch,DWORD *pgrfdex) {
    return This->lpVtbl->GetMemberProperties(This,id,grfdexFetch,pgrfdex);
}
static FORCEINLINE HRESULT IDispatchEx_GetMemberName(IDispatchEx* This,DISPID id,BSTR *pbstrName) {
    return This->lpVtbl->GetMemberName(This,id,pbstrName);
}
static FORCEINLINE HRESULT IDispatchEx_GetNextDispID(IDispatchEx* This,DWORD grfdex,DISPID id,DISPID *pid) {
    return This->lpVtbl->GetNextDispID(This,grfdex,id,pid);
}
static FORCEINLINE HRESULT IDispatchEx_GetNameSpaceParent(IDispatchEx* This,IUnknown **ppunk) {
    return This->lpVtbl->GetNameSpaceParent(This,ppunk);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IDispatchEx_GetDispID_Proxy(
    IDispatchEx* This,
    BSTR bstrName,
    DWORD grfdex,
    DISPID *pid);
void __RPC_STUB IDispatchEx_GetDispID_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispatchEx_RemoteInvokeEx_Proxy(
    IDispatchEx* This,
    DISPID id,
    LCID lcid,
    DWORD dwFlags,
    DISPPARAMS *pdp,
    VARIANT *pvarRes,
    EXCEPINFO *pei,
    IServiceProvider *pspCaller,
    UINT cvarRefArg,
    UINT *rgiRefArg,
    VARIANT *rgvarRefArg);
void __RPC_STUB IDispatchEx_RemoteInvokeEx_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispatchEx_DeleteMemberByName_Proxy(
    IDispatchEx* This,
    BSTR bstrName,
    DWORD grfdex);
void __RPC_STUB IDispatchEx_DeleteMemberByName_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispatchEx_DeleteMemberByDispID_Proxy(
    IDispatchEx* This,
    DISPID id);
void __RPC_STUB IDispatchEx_DeleteMemberByDispID_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispatchEx_GetMemberProperties_Proxy(
    IDispatchEx* This,
    DISPID id,
    DWORD grfdexFetch,
    DWORD *pgrfdex);
void __RPC_STUB IDispatchEx_GetMemberProperties_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispatchEx_GetMemberName_Proxy(
    IDispatchEx* This,
    DISPID id,
    BSTR *pbstrName);
void __RPC_STUB IDispatchEx_GetMemberName_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispatchEx_GetNextDispID_Proxy(
    IDispatchEx* This,
    DWORD grfdex,
    DISPID id,
    DISPID *pid);
void __RPC_STUB IDispatchEx_GetNextDispID_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispatchEx_GetNameSpaceParent_Proxy(
    IDispatchEx* This,
    IUnknown **ppunk);
void __RPC_STUB IDispatchEx_GetNameSpaceParent_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IDispatchEx_InvokeEx_Proxy(
    IDispatchEx* This,
    DISPID id,
    LCID lcid,
    WORD wFlags,
    DISPPARAMS *pdp,
    VARIANT *pvarRes,
    EXCEPINFO *pei,
    IServiceProvider *pspCaller);
HRESULT __RPC_STUB IDispatchEx_InvokeEx_Stub(
    IDispatchEx* This,
    DISPID id,
    LCID lcid,
    DWORD dwFlags,
    DISPPARAMS *pdp,
    VARIANT *pvarRes,
    EXCEPINFO *pei,
    IServiceProvider *pspCaller,
    UINT cvarRefArg,
    UINT *rgiRefArg,
    VARIANT *rgvarRefArg);

#endif  /* __IDispatchEx_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDispError interface
 */
#ifndef __IDispError_INTERFACE_DEFINED__
#define __IDispError_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDispError, 0xa6ef9861, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("a6ef9861-c720-11d0-9337-00a0c90dcaa9")
IDispError : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE QueryErrorInfo(
        GUID guidErrorType,
        IDispError **ppde) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetNext(
        IDispError **ppde) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetHresult(
        HRESULT *phr) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetSource(
        BSTR *pbstrSource) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetHelpInfo(
        BSTR *pbstrFileName,
        DWORD *pdwContext) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetDescription(
        BSTR *pbstrDescription) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDispError, 0xa6ef9861, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9)
#endif
#else
typedef struct IDispErrorVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDispError* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDispError* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDispError* This);

    /*** IDispError methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryErrorInfo)(
        IDispError* This,
        GUID guidErrorType,
        IDispError **ppde);

    HRESULT (STDMETHODCALLTYPE *GetNext)(
        IDispError* This,
        IDispError **ppde);

    HRESULT (STDMETHODCALLTYPE *GetHresult)(
        IDispError* This,
        HRESULT *phr);

    HRESULT (STDMETHODCALLTYPE *GetSource)(
        IDispError* This,
        BSTR *pbstrSource);

    HRESULT (STDMETHODCALLTYPE *GetHelpInfo)(
        IDispError* This,
        BSTR *pbstrFileName,
        DWORD *pdwContext);

    HRESULT (STDMETHODCALLTYPE *GetDescription)(
        IDispError* This,
        BSTR *pbstrDescription);

    END_INTERFACE
} IDispErrorVtbl;
interface IDispError {
    CONST_VTBL IDispErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDispError_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDispError_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDispError_Release(This) (This)->lpVtbl->Release(This)
/*** IDispError methods ***/
#define IDispError_QueryErrorInfo(This,guidErrorType,ppde) (This)->lpVtbl->QueryErrorInfo(This,guidErrorType,ppde)
#define IDispError_GetNext(This,ppde) (This)->lpVtbl->GetNext(This,ppde)
#define IDispError_GetHresult(This,phr) (This)->lpVtbl->GetHresult(This,phr)
#define IDispError_GetSource(This,pbstrSource) (This)->lpVtbl->GetSource(This,pbstrSource)
#define IDispError_GetHelpInfo(This,pbstrFileName,pdwContext) (This)->lpVtbl->GetHelpInfo(This,pbstrFileName,pdwContext)
#define IDispError_GetDescription(This,pbstrDescription) (This)->lpVtbl->GetDescription(This,pbstrDescription)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDispError_QueryInterface(IDispError* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IDispError_AddRef(IDispError* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDispError_Release(IDispError* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispError methods ***/
static FORCEINLINE HRESULT IDispError_QueryErrorInfo(IDispError* This,GUID guidErrorType,IDispError **ppde) {
    return This->lpVtbl->QueryErrorInfo(This,guidErrorType,ppde);
}
static FORCEINLINE HRESULT IDispError_GetNext(IDispError* This,IDispError **ppde) {
    return This->lpVtbl->GetNext(This,ppde);
}
static FORCEINLINE HRESULT IDispError_GetHresult(IDispError* This,HRESULT *phr) {
    return This->lpVtbl->GetHresult(This,phr);
}
static FORCEINLINE HRESULT IDispError_GetSource(IDispError* This,BSTR *pbstrSource) {
    return This->lpVtbl->GetSource(This,pbstrSource);
}
static FORCEINLINE HRESULT IDispError_GetHelpInfo(IDispError* This,BSTR *pbstrFileName,DWORD *pdwContext) {
    return This->lpVtbl->GetHelpInfo(This,pbstrFileName,pdwContext);
}
static FORCEINLINE HRESULT IDispError_GetDescription(IDispError* This,BSTR *pbstrDescription) {
    return This->lpVtbl->GetDescription(This,pbstrDescription);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IDispError_QueryErrorInfo_Proxy(
    IDispError* This,
    GUID guidErrorType,
    IDispError **ppde);
void __RPC_STUB IDispError_QueryErrorInfo_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispError_GetNext_Proxy(
    IDispError* This,
    IDispError **ppde);
void __RPC_STUB IDispError_GetNext_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispError_GetHresult_Proxy(
    IDispError* This,
    HRESULT *phr);
void __RPC_STUB IDispError_GetHresult_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispError_GetSource_Proxy(
    IDispError* This,
    BSTR *pbstrSource);
void __RPC_STUB IDispError_GetSource_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispError_GetHelpInfo_Proxy(
    IDispError* This,
    BSTR *pbstrFileName,
    DWORD *pdwContext);
void __RPC_STUB IDispError_GetHelpInfo_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IDispError_GetDescription_Proxy(
    IDispError* This,
    BSTR *pbstrDescription);
void __RPC_STUB IDispError_GetDescription_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IDispError_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IVariantChangeType interface
 */
#ifndef __IVariantChangeType_INTERFACE_DEFINED__
#define __IVariantChangeType_INTERFACE_DEFINED__

DEFINE_GUID(IID_IVariantChangeType, 0xa6ef9862, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("a6ef9862-c720-11d0-9337-00a0c90dcaa9")
IVariantChangeType : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE ChangeType(
        VARIANT *pvarDst,
        VARIANT *pvarSrc,
        LCID lcid,
        VARTYPE vtNew) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IVariantChangeType, 0xa6ef9862, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9)
#endif
#else
typedef struct IVariantChangeTypeVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IVariantChangeType* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IVariantChangeType* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IVariantChangeType* This);

    /*** IVariantChangeType methods ***/
    HRESULT (STDMETHODCALLTYPE *ChangeType)(
        IVariantChangeType* This,
        VARIANT *pvarDst,
        VARIANT *pvarSrc,
        LCID lcid,
        VARTYPE vtNew);

    END_INTERFACE
} IVariantChangeTypeVtbl;
interface IVariantChangeType {
    CONST_VTBL IVariantChangeTypeVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IVariantChangeType_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IVariantChangeType_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IVariantChangeType_Release(This) (This)->lpVtbl->Release(This)
/*** IVariantChangeType methods ***/
#define IVariantChangeType_ChangeType(This,pvarDst,pvarSrc,lcid,vtNew) (This)->lpVtbl->ChangeType(This,pvarDst,pvarSrc,lcid,vtNew)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IVariantChangeType_QueryInterface(IVariantChangeType* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IVariantChangeType_AddRef(IVariantChangeType* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IVariantChangeType_Release(IVariantChangeType* This) {
    return This->lpVtbl->Release(This);
}
/*** IVariantChangeType methods ***/
static FORCEINLINE HRESULT IVariantChangeType_ChangeType(IVariantChangeType* This,VARIANT *pvarDst,VARIANT *pvarSrc,LCID lcid,VARTYPE vtNew) {
    return This->lpVtbl->ChangeType(This,pvarDst,pvarSrc,lcid,vtNew);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IVariantChangeType_ChangeType_Proxy(
    IVariantChangeType* This,
    VARIANT *pvarDst,
    VARIANT *pvarSrc,
    LCID lcid,
    VARTYPE vtNew);
void __RPC_STUB IVariantChangeType_ChangeType_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IVariantChangeType_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IObjectIdentity interface
 */
#ifndef __IObjectIdentity_INTERFACE_DEFINED__
#define __IObjectIdentity_INTERFACE_DEFINED__

DEFINE_GUID(IID_IObjectIdentity, 0xca04b7e6, 0x0d21, 0x11d1, 0x8c,0xc5, 0x00,0xc0,0x4f,0xc2,0xb0,0x85);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("ca04b7e6-0d21-11d1-8cc5-00c04fc2b085")
IObjectIdentity : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE IsEqualObject(
        IUnknown *punk) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IObjectIdentity, 0xca04b7e6, 0x0d21, 0x11d1, 0x8c,0xc5, 0x00,0xc0,0x4f,0xc2,0xb0,0x85)
#endif
#else
typedef struct IObjectIdentityVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IObjectIdentity* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IObjectIdentity* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IObjectIdentity* This);

    /*** IObjectIdentity methods ***/
    HRESULT (STDMETHODCALLTYPE *IsEqualObject)(
        IObjectIdentity* This,
        IUnknown *punk);

    END_INTERFACE
} IObjectIdentityVtbl;
interface IObjectIdentity {
    CONST_VTBL IObjectIdentityVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IObjectIdentity_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IObjectIdentity_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IObjectIdentity_Release(This) (This)->lpVtbl->Release(This)
/*** IObjectIdentity methods ***/
#define IObjectIdentity_IsEqualObject(This,punk) (This)->lpVtbl->IsEqualObject(This,punk)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IObjectIdentity_QueryInterface(IObjectIdentity* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IObjectIdentity_AddRef(IObjectIdentity* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IObjectIdentity_Release(IObjectIdentity* This) {
    return This->lpVtbl->Release(This);
}
/*** IObjectIdentity methods ***/
static FORCEINLINE HRESULT IObjectIdentity_IsEqualObject(IObjectIdentity* This,IUnknown *punk) {
    return This->lpVtbl->IsEqualObject(This,punk);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IObjectIdentity_IsEqualObject_Proxy(
    IObjectIdentity* This,
    IUnknown *punk);
void __RPC_STUB IObjectIdentity_IsEqualObject_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IObjectIdentity_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ICanHandleException interface
 */
#ifndef __ICanHandleException_INTERFACE_DEFINED__
#define __ICanHandleException_INTERFACE_DEFINED__

DEFINE_GUID(IID_ICanHandleException, 0xc5598e60, 0xb307, 0x11d1, 0xb2,0x7d, 0x00,0x60,0x08,0xc3,0xfb,0xfb);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("c5598e60-b307-11d1-b27d-006008c3fbfb")
ICanHandleException : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE CanHandleException(
        EXCEPINFO *pExcepInfo,
        VARIANT *pvar) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ICanHandleException, 0xc5598e60, 0xb307, 0x11d1, 0xb2,0x7d, 0x00,0x60,0x08,0xc3,0xfb,0xfb)
#endif
#else
typedef struct ICanHandleExceptionVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ICanHandleException* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ICanHandleException* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ICanHandleException* This);

    /*** ICanHandleException methods ***/
    HRESULT (STDMETHODCALLTYPE *CanHandleException)(
        ICanHandleException* This,
        EXCEPINFO *pExcepInfo,
        VARIANT *pvar);

    END_INTERFACE
} ICanHandleExceptionVtbl;
interface ICanHandleException {
    CONST_VTBL ICanHandleExceptionVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ICanHandleException_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICanHandleException_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICanHandleException_Release(This) (This)->lpVtbl->Release(This)
/*** ICanHandleException methods ***/
#define ICanHandleException_CanHandleException(This,pExcepInfo,pvar) (This)->lpVtbl->CanHandleException(This,pExcepInfo,pvar)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT ICanHandleException_QueryInterface(ICanHandleException* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG ICanHandleException_AddRef(ICanHandleException* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG ICanHandleException_Release(ICanHandleException* This) {
    return This->lpVtbl->Release(This);
}
/*** ICanHandleException methods ***/
static FORCEINLINE HRESULT ICanHandleException_CanHandleException(ICanHandleException* This,EXCEPINFO *pExcepInfo,VARIANT *pvar) {
    return This->lpVtbl->CanHandleException(This,pExcepInfo,pvar);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE ICanHandleException_CanHandleException_Proxy(
    ICanHandleException* This,
    EXCEPINFO *pExcepInfo,
    VARIANT *pvar);
void __RPC_STUB ICanHandleException_CanHandleException_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __ICanHandleException_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IProvideRuntimeContext interface
 */
#ifndef __IProvideRuntimeContext_INTERFACE_DEFINED__
#define __IProvideRuntimeContext_INTERFACE_DEFINED__

DEFINE_GUID(IID_IProvideRuntimeContext, 0x10e2414a, 0xec59, 0x49d2, 0xbc,0x51, 0x5a,0xdd,0x2c,0x36,0xfe,0xbc);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("10e2414a-ec59-49d2-bc51-5add2c36febc")
IProvideRuntimeContext : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetCurrentSourceContext(
        DWORD_PTR *pdwContext,
        VARIANT_BOOL *pfExecutingGlobalCode) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IProvideRuntimeContext, 0x10e2414a, 0xec59, 0x49d2, 0xbc,0x51, 0x5a,0xdd,0x2c,0x36,0xfe,0xbc)
#endif
#else
typedef struct IProvideRuntimeContextVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IProvideRuntimeContext* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IProvideRuntimeContext* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IProvideRuntimeContext* This);

    /*** IProvideRuntimeContext methods ***/
    HRESULT (STDMETHODCALLTYPE *GetCurrentSourceContext)(
        IProvideRuntimeContext* This,
        DWORD_PTR *pdwContext,
        VARIANT_BOOL *pfExecutingGlobalCode);

    END_INTERFACE
} IProvideRuntimeContextVtbl;
interface IProvideRuntimeContext {
    CONST_VTBL IProvideRuntimeContextVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IProvideRuntimeContext_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IProvideRuntimeContext_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IProvideRuntimeContext_Release(This) (This)->lpVtbl->Release(This)
/*** IProvideRuntimeContext methods ***/
#define IProvideRuntimeContext_GetCurrentSourceContext(This,pdwContext,pfExecutingGlobalCode) (This)->lpVtbl->GetCurrentSourceContext(This,pdwContext,pfExecutingGlobalCode)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IProvideRuntimeContext_QueryInterface(IProvideRuntimeContext* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IProvideRuntimeContext_AddRef(IProvideRuntimeContext* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IProvideRuntimeContext_Release(IProvideRuntimeContext* This) {
    return This->lpVtbl->Release(This);
}
/*** IProvideRuntimeContext methods ***/
static FORCEINLINE HRESULT IProvideRuntimeContext_GetCurrentSourceContext(IProvideRuntimeContext* This,DWORD_PTR *pdwContext,VARIANT_BOOL *pfExecutingGlobalCode) {
    return This->lpVtbl->GetCurrentSourceContext(This,pdwContext,pfExecutingGlobalCode);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IProvideRuntimeContext_GetCurrentSourceContext_Proxy(
    IProvideRuntimeContext* This,
    DWORD_PTR *pdwContext,
    VARIANT_BOOL *pfExecutingGlobalCode);
void __RPC_STUB IProvideRuntimeContext_GetCurrentSourceContext_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IProvideRuntimeContext_INTERFACE_DEFINED__ */

#endif
#endif
/* Begin additional prototypes for all interfaces */

ULONG           __RPC_USER BSTR_UserSize     (ULONG *, ULONG, BSTR *);
unsigned char * __RPC_USER BSTR_UserMarshal  (ULONG *, unsigned char *, BSTR *);
unsigned char * __RPC_USER BSTR_UserUnmarshal(ULONG *, unsigned char *, BSTR *);
void            __RPC_USER BSTR_UserFree     (ULONG *, BSTR *);
ULONG           __RPC_USER VARIANT_UserSize     (ULONG *, ULONG, VARIANT *);
unsigned char * __RPC_USER VARIANT_UserMarshal  (ULONG *, unsigned char *, VARIANT *);
unsigned char * __RPC_USER VARIANT_UserUnmarshal(ULONG *, unsigned char *, VARIANT *);
void            __RPC_USER VARIANT_UserFree     (ULONG *, VARIANT *);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __dispex_h__ */
