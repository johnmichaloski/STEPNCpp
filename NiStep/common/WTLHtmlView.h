//
// WtlHtmlView.h : interface of the CWtlHtmlView class
//

// DISCLAIMER: 
//  This software was produced by the National Institute of Standards 
//  and Technology (NIST), an agency of the U.S. government, and by statute is 
//  not subject to copyright in the United States.  Recipients of this 
//  software assume all responsibility associated with its operation,
//  modification,maintenance, and subsequent redistribution. 
//
//  See NIST Administration Manual 4.09.07 b and Appendix I. 


#pragma once
#include <mshtml.h>
#include "atlstr.h"
#include <mshtml.h>
#include <exdisp.h>
#include "atliface.h"
#include "exdispid.h"

#include "docobj.h"
#include "comutil.h"

/////////////////////////////////////////////////////////////////////////////
// Info structs used by the event sink map

__declspec(selectany) _ATL_FUNC_INFO BeforeNavigate2Info =
{ CC_STDCALL, VT_EMPTY, 7,
{ VT_DISPATCH, VT_VARIANT|VT_BYREF, VT_VARIANT|VT_BYREF, 
VT_VARIANT|VT_BYREF, VT_VARIANT|VT_BYREF, VT_VARIANT|VT_BYREF, 
VT_BOOL|VT_BYREF }
};

__declspec(selectany) _ATL_FUNC_INFO NavigateComplete2Info =
{ CC_STDCALL, VT_EMPTY, 2, { VT_DISPATCH, VT_VARIANT|VT_BYREF } 
};

__declspec(selectany) _ATL_FUNC_INFO StatusChangeInfo =
{ CC_STDCALL, VT_EMPTY, 1, { VT_BSTR }
};

__declspec(selectany) _ATL_FUNC_INFO CommandStateChangeInfo =
{ CC_STDCALL, VT_EMPTY, 2, { VT_I4, VT_BOOL }
};

__declspec(selectany) _ATL_FUNC_INFO DownloadInfo =
{ CC_STDCALL, VT_EMPTY, 0 
};


class CWtlHtmlView :
	public CWindowImpl<CWtlHtmlView, CAxWindow>,
	public IDispEventSimpleImpl<37, CWtlHtmlView, &DIID_DWebBrowserEvents2>
{
public:
	DECLARE_WND_SUPERCLASS(NULL, CAxWindow::GetWndClassName())


	CComPtr<IHTMLElement> m_pBody;
	CComPtr<IHTMLDocument2> m_spHTMLDocument;
	CComPtr<IWebBrowser2> m_spWebBrowser2;
	CComPtr<IWebBrowser> m_spWebBrowser;
	bool bBackEnable;
	bool bForwardEnable;


	CWtlHtmlView()
	{
		m_pBody = NULL;
		m_spHTMLDocument= NULL;
		m_spWebBrowser2= NULL;
		m_spWebBrowser= NULL;
		bBackEnable=true;
		bForwardEnable=true;

	}
	~CWtlHtmlView()
	{
		if(m_spWebBrowser2!=NULL)
		{
			DispEventUnadvise ( m_spWebBrowser2 );
		}
	}	
	BOOL CWtlHtmlView::PreTranslateMessage(MSG* pMsg)
	{
		if((pMsg->message < WM_KEYFIRST || pMsg->message > WM_KEYLAST) &&
			(pMsg->message < WM_MOUSEFIRST || pMsg->message > WM_MOUSELAST))
			return FALSE;

		// give HTML page a chance to translate this message
		return (BOOL)SendMessage(WM_FORWARDMSG, 0, (LPARAM)pMsg);
	}
	LRESULT CWtlHtmlView::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		return 0;
	}
	BEGIN_MSG_MAP(CWtlHtmlView)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	END_MSG_MAP()


	LRESULT TurnOffContextMenu()
	{
		HRESULT hr;
		CAxWindow wnd(m_hWnd);
		CComPtr<IUnknown> spUnk;					
		AtlAxGetHost(m_hWnd, &spUnk);				
		CComQIPtr<IAxWinAmbientDispatch> spWinAmb(spUnk);
		hr=spWinAmb->put_AllowContextMenu(VARIANT_FALSE);
		return SUCCEEDED(hr) ? 0 : -1;
	}

	BEGIN_SINK_MAP(CWtlHtmlView)
		SINK_ENTRY_INFO(37, DIID_DWebBrowserEvents2, DISPID_BEFORENAVIGATE2, OnBeforeNavigate2, &BeforeNavigate2Info)
		SINK_ENTRY_INFO(37, DIID_DWebBrowserEvents2, DISPID_NAVIGATECOMPLETE2, OnNavigateComplete2, &NavigateComplete2Info)
		SINK_ENTRY_INFO(37, DIID_DWebBrowserEvents2, DISPID_STATUSTEXTCHANGE, OnStatusChange, &StatusChangeInfo)
		SINK_ENTRY_INFO(37, DIID_DWebBrowserEvents2, DISPID_COMMANDSTATECHANGE, OnCommandStateChange, &CommandStateChangeInfo)
		SINK_ENTRY_INFO(37, DIID_DWebBrowserEvents2, DISPID_DOWNLOADBEGIN, OnDownloadBegin, &DownloadInfo)
		SINK_ENTRY_INFO(37, DIID_DWebBrowserEvents2, DISPID_DOWNLOADCOMPLETE, OnDownloadComplete, &DownloadInfo)
	END_SINK_MAP()

	virtual void __stdcall OnBeforeNavigate2 (
		IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName,
		VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel ){}
	virtual void __stdcall OnNavigateComplete2 ( IDispatch* pDisp, VARIANT * URL ){}
	virtual void __stdcall OnStatusChange ( BSTR bsText ){}
	virtual void __stdcall OnDownloadBegin(){}
	virtual void __stdcall OnDownloadComplete(){}
	virtual void __stdcall OnCommandStateChange ( long lCmd, VARIANT_BOOL vbEnabled )
	{
		bool bFlag = (vbEnabled != VARIANT_FALSE);

		if ( CSC_NAVIGATEBACK == lCmd )
		{
			bBackEnable = bFlag;
			OutputDebugString(CString("OnCommandStateChange Back=%d\n" , bBackEnable));

		}
		else if ( CSC_NAVIGATEFORWARD == lCmd )
		{
			bForwardEnable = bFlag;
			OutputDebugString(CString("OnCommandStateChange Forward=%d\n" , bForwardEnable));
		}
	}

	BOOL GetBody()
	{
		CComPtr<IDispatch> pDisp;
		CComVariant ve;
		// navOpenInNewWindow, navNoHistory,navNoReadFromCache,navNoWriteToCache
		// navAllowAutosearch,navBrowserBar,navHyperlink
		CComVariant vBrowserNav; 
		if(m_spHTMLDocument!=NULL)
			return 0;
		// Get the browser interface from the embedded HTML control
		if((m_spWebBrowser==NULL) && FAILED(QueryControl(__uuidof(IWebBrowser), reinterpret_cast<void**>(&m_spWebBrowser))) )
			m_spWebBrowser=NULL;

		if( SUCCEEDED(QueryControl(__uuidof(m_spWebBrowser2), reinterpret_cast<void**>(&m_spWebBrowser2))) )
		{
			if(m_spWebBrowser2!=NULL)
			{
				DispEventAdvise ( m_spWebBrowser2 );
				if(FAILED(m_spWebBrowser2->get_Document( &pDisp)))
					OutputDebugString(_T("get_Document Failed"));
				if(pDisp!=NULL) 
				{
					if(FAILED(pDisp->QueryInterface(IID_IHTMLDocument2, (void**)&m_spHTMLDocument))) 
						OutputDebugString(_T("QI IID_IHTMLDocument2 Failed"));
				}

			}

		}
		return FALSE;
	}
	HRESULT SetDocumentText( CString cstr)
	{
		_bstr_t str(cstr);
		HRESULT hr = S_OK;
		VARIANT *param;
		SAFEARRAY *sfArray;
		IHTMLDocument2 *document;
		BSTR bstr = str.Detach();

		// Creates a new one-dimensional array
		sfArray = SafeArrayCreateVector(VT_VARIANT, 0, 1);

		if(m_spHTMLDocument==NULL)
			this->GetBody();

		document= m_spHTMLDocument;
		if (sfArray == NULL || document == NULL) {
			hr=E_FAIL;
			goto cleanup;
		}

		hr = SafeArrayAccessData(sfArray,(LPVOID*) & param);
		param->vt = VT_BSTR;
		param->bstrVal = bstr;
		hr = SafeArrayUnaccessData(sfArray);
		hr = document->write(sfArray);

cleanup:
		if (sfArray != NULL) {
			SafeArrayDestroy(sfArray);
		}
		return hr;
	}
	HRESULT Navigate(CString url)
	{
		USES_CONVERSION;
		CComVariant vurl((LPCWSTR) _bstr_t((LPCTSTR) url));
		CComVariant ve;
		CComVariant vBrowserNav; 
		GetBody();
		return m_spWebBrowser2->Navigate2(&vurl,
			&vBrowserNav, 
			&ve, //TargetFrameName _BLANK  _PARENT  _SELF _TOP  
			&ve, &ve);

	}

	bool QueryStatus( OLECMDID nCmdID, int value) 
	{
		OLECMDF eQuery ; //      'return value type for QueryStatusWB
		if(m_spWebBrowser2==NULL)
			return false;

		if(FAILED( m_spWebBrowser2->QueryStatusWB(OLECMDID_PRINT, &eQuery))) //  'get print command status
			return false;

		if(( eQuery & value) )
			return true;
		return false;
	}



	//OLECMDID_PRINT	= 6,
	HRESULT ExecCommand( OLECMDID nCmdID, OLECMDEXECOPT nCmdExecOpt, VARIANTARG* pvarargIn, VARIANTARG* pvarargOut) 
	{
		HRESULT hr=S_OK;
		LPDISPATCH lpDispatch = NULL;
		LPOLECOMMANDTARGET lpOleCommandTarget = NULL;
		try {

			m_spWebBrowser->get_Document(&lpDispatch);
			if(lpDispatch==NULL)
				throw;
			OLECMDF eQuery ; //      'return value type for QueryStatusWB

			if(FAILED( m_spWebBrowser2->QueryStatusWB(OLECMDID_PRINT, &eQuery))) //  'get print command status
				throw;

			if(!( eQuery & OLECMDF_ENABLED) )
				throw;

			lpDispatch->QueryInterface(IID_IOleCommandTarget, (void**)&lpOleCommandTarget);
			if(lpOleCommandTarget==NULL)
				throw;

			// Print contents of WebBrowser control.
			hr=lpOleCommandTarget->Exec(NULL, nCmdID, nCmdExecOpt, pvarargIn, pvarargOut);
		}
		catch(...)
		{
			hr=E_FAIL;
		}
		if(lpDispatch)
			lpDispatch->Release();
		if(lpOleCommandTarget)
			lpOleCommandTarget->Release();
		return hr;
	}

	//OLECMDID_PRINT	= 6,
	HRESULT OnExecCommand( OLECMDID nCmdID, OLECMDEXECOPT nCmdExecOpt, VARIANTARG* pvarargIn, VARIANTARG* pvarargOut) 
	{
		return m_spWebBrowser2->ExecWB(nCmdID, nCmdExecOpt, pvarargIn, pvarargOut);

	}

	void GoBack() 
	{
		if(m_spWebBrowser==NULL && FAILED(QueryControl(__uuidof(IWebBrowser), reinterpret_cast<void**>(&m_spWebBrowser))) )
			return;
		m_spWebBrowser->GoBack();


	}
	void GoForward() 
	{
		if(m_spWebBrowser==NULL && FAILED(QueryControl(__uuidof(IWebBrowser), reinterpret_cast<void**>(&m_spWebBrowser))) )
			return;
		m_spWebBrowser->GoForward();

	}
};
