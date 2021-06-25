// MainFrm.cpp : implmentation of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"
#include "StepAnnotatorView.h"

#include "aboutdlg.h"
#include "MainFrm.h"
#include "Misc.h"
#include "Seimens840D.h"

// For CFindFile
#define _WTL_NO_CSTRING
#define _CSTRING_NS ATL
#include "atlmisc.h"
#include "guiddef.h"

#define INITGUID
DEFINE_GUID(IID_IStepPath,0x7C5F41C5,0x8D02,0x468C,0x82,0x82,0x90,0x88,0x95,0xDA,0x77,0x20);
DEFINE_GUID(CLSID_StepPath,0x8FC9FCDD,0x3859,0x4753,0x97,0x2C,0x77,0xC1,0x72,0x94,0x45,0x11);

IStepPath * gpStepDom;
IStepNode *  gProject;
IHelpInfo * gpHelpInfo;

// Tabbed pages
enum {
	P21VIEW=0, 
	WSVIEW,
	LISTBOXVIEW,
	TOOLVIEW,
	XMLTREEVIEW,
	FEATUREVIEW
};

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	if(CFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))
		return TRUE;

	return m_view.PreTranslateMessage(pMsg);
}

BOOL CMainFrame::OnIdle()
{
	UIUpdateToolBar();
	return FALSE;
}

LRESULT CMainFrame::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	HRESULT hr;
	gpStepDom=NULL;

	CreateSimpleToolBar();

	CreateSimpleStatusBar();

	m_hWndClient = m_splitter.Create(m_hWnd, rcDefault, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	m_pane.SetPaneContainerExtendedStyle(PANECNT_NOBORDER);
	m_pane.Create(m_splitter, _T("Tree"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
	m_treeview.Create(m_pane, rcDefault, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS, WS_EX_CLIENTEDGE);
	m_treeview.SetFont(AtlGetDefaultGuiFont());
	m_pane.SetClient(m_treeview);

	//TODO: Replace with a URL of your choice
	m_view.Create(m_splitter, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);

	_vP21View.Create(m_view, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vP21View.SetFont(AtlGetDefaultGuiFont());
	m_view.AddPage(_vP21View.m_hWnd, _T("Part 21"));

	_vStepsView.Create(m_view, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vStepsView.SetFont(AtlGetDefaultGuiFont());
	m_view.AddPage(_vStepsView.m_hWnd, _T("Working Steps"));
	
	_vCompileListbox.Create(m_view, rcDefault, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL | LBS_NOINTEGRALHEIGHT | LBS_NOTIFY | LBS_WANTKEYBOARDINPUT, WS_EX_CLIENTEDGE);
	m_view.AddPage(_vCompileListbox.m_hWnd, _T("Verify Errors"));

	m_view.SetActivePage(0);

	m_splitter.SetSplitterPanes(m_pane, m_view);
	UpdateLayout();
	m_splitter.SetSplitterPosPct(25);

	UIAddToolBar(m_hWndToolBar);
	UISetCheck(ID_VIEW_TOOLBAR, 1);
	UISetCheck(ID_VIEW_STATUS_BAR, 1);
	UISetCheck(ID_VIEW_TREEPANE, 1);

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	// what if this fails...
	gpStepDom=NULL;
	if(FAILED(hr= CoCreateInstance(CLSID_StepPath, NULL, CLSCTX_ALL, IID_IStepPath, (void**) &gpStepDom)))
	{
		return 0;
	}
	
	if(FAILED(hr= pHelpInfo.CoCreateInstance(__uuidof(HelpInfo))))
	{
		return 0;

	}
	gpHelpInfo=pHelpInfo;
	return 0;
}

LRESULT CMainFrame::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	// unregister message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->RemoveMessageFilter(this);
	pLoop->RemoveIdleHandler(this);

	bHandled = FALSE;
	return 1;
}

LRESULT CMainFrame::OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	PostMessage(WM_CLOSE);
	return 0;
}

LRESULT CMainFrame::OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	 // Clear existing stepnc project and treeview...
	gpStepDom->clearStep();
	gProject = gpStepDom->CreateNewProject();
	m_treeview.DeleteAllItems();
	m_treeview.BuildTree(gpStepDom->GetRootAttributeList());
	return 0;
}
LRESULT CMainFrame::OnFileSaveAs(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if(gProject==NULL)
		return	MessageBox(_T("No parsed file to save"))<0;  // force zero return


	static TCHAR strFilter[] = { _T("Any NC Files (*.txt)|*.txt||") };

	CFileDialog dlg(FALSE,
		_T("*"),
		NULL,
		OFN_OVERWRITEPROMPT|OFN_HIDEREADONLY,
		strFilter);
	if( dlg.DoModal() == IDOK )
	{
		szP21filename = dlg.m_szFileName; 
		gpStepDom->saveFile(dlg.m_szFileName);
	}

	return 0;
}
LRESULT CMainFrame::OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	BOOL bVisible = !::IsWindowVisible(m_hWndToolBar);
	::ShowWindow(m_hWndToolBar, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
	UISetCheck(ID_VIEW_TOOLBAR, bVisible);
	UpdateLayout();
	return 0;
}

LRESULT CMainFrame::OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	BOOL bVisible = !::IsWindowVisible(m_hWndStatusBar);
	::ShowWindow(m_hWndStatusBar, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
	UISetCheck(ID_VIEW_STATUS_BAR, bVisible);
	UpdateLayout();
	return 0;
}

LRESULT CMainFrame::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CAboutDlg dlg;
	dlg.DoModal();
	return 0;
}

LRESULT CMainFrame::OnViewTreePane(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	bool bShow = (m_splitter.GetSinglePaneMode() != SPLIT_PANE_NONE);
	m_splitter.SetSinglePaneMode(bShow ? SPLIT_PANE_NONE : SPLIT_PANE_RIGHT);
	UISetCheck(ID_VIEW_TREEPANE, bShow);

	return 0;
}

LRESULT CMainFrame::OnTreePaneClose(WORD /*wNotifyCode*/, WORD /*wID*/, HWND hWndCtl, BOOL& /*bHandled*/)
{
	if(hWndCtl == m_pane.m_hWnd)
	{
		m_splitter.SetSinglePaneMode(SPLIT_PANE_RIGHT);
		UISetCheck(ID_VIEW_TREEPANE, 0);
	}

	return 0;
}

LRESULT CMainFrame::OnToolsCompile(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CComVariant var;
	_vCompileListbox.ResetContent();

	var = gpStepDom->Verify();
	if(var.vt !=  (VT_ARRAY|VT_BSTR))
		return 0;

	CComSafeArray<BSTR> errmsgs(var.parray);
	for(int i=errmsgs.GetLowerBound(); i<= errmsgs.GetUpperBound(); i++)
	{
		_vCompileListbox.AddString((LPCTSTR) _bstr_t((BSTR) errmsgs.GetAt(i )));
	}

	m_view.SetActivePage(LISTBOXVIEW);

	return 0;
}
LRESULT CMainFrame::OnViewPart21(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CFindFile finder1;
	finder1.FindFile((LPCTSTR) szP21filename);
	CString module;
	module.LoadString(IDR_MAINFRAME);

	this->SetWindowText(module + _T(" - ") + finder1.GetFileTitle() );
	m_view.SetActivePage(P21VIEW);
	_bstr_t szHtml = gpStepDom->TranslateP21ToHtml(_bstr_t(szP21filename));
	CString filename = ::GetExeDirectory()  + finder1.GetFileTitle() + _T(".html");
	if(SaveDocument( filename, (LPCTSTR) szHtml))
		_vP21View.Navigate(CString("file:\\\\") + (LPCTSTR) filename);
	return 0;
}


LRESULT CMainFrame::OnFileOpen(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& bHandled)
{
	static TCHAR strFilter[] = { _T("Any NC Files (*.*)|*.*||") };
	HRESULT hr;

	CFileDialog dlg(TRUE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		strFilter);
	if( dlg.DoModal() != IDOK )
		return 0;
	szP21filename = dlg.m_szFileName; 
	if(szP21filename.GetLength() <= 0)
		return 0;
	 // Clear existing stepnc project and treeview...
	m_treeview.DeleteAllItems();
	if(gpStepDom==NULL)
	{


	}
	gpStepDom->clearStep();

	OnViewPart21(0,0,0, bHandled);

	tifstream ifs((LPCTSTR) szP21filename);
	tstringstream buffer;
	buffer << ifs.rdbuf();

	if(gpStepDom->loadStep(_bstr_t((LPCTSTR) buffer.str().c_str()))!=VARIANT_TRUE)
		return 0;
	//bstrString= pStepDom->ToXmlString();
	gProject=pRootNode=gpStepDom->GetRoot() ;

	//m_treeview.BuildTree(gpStepDom->GetP21HeaderAttributeList());
	m_treeview.BuildTree(gpStepDom->GetRootAttributeList());

	return 0;
}

#include "HtmlTable.h"


LRESULT CMainFrame::OnViewWorkingsteps(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	int i;
	CString szFeatureId;

	CHtmlTable html;
	CString szTestReportStyle = _T("./_UpgradeReport_Files/TestReport.css");
	html.LoadTableHeader(_T("Feature"), _T("Name"),  _T("Operation"), NULL);
	html.LoadColumnsStyle(_T(""), _T(""), _T(""), NULL);

	if(gProject==NULL)
	{
		MessageBox(_T("Please Parse File first\n"));
		return 0;
	}

	program= new Seimens840D(gWm);
	CStringVector errors;
	if(FAILED(program->ParseStepNC(gProject, errors)))
	{
		//MessageBox("StepNC Errors\n"+ errors.ToString(""));

	}
	// Build workingstep list from program parsing.
	for(int i=0; i< program->size(); i++)
	{
		CStringVector row;
		CString szOps;
		CString szFeatureId, szExecutableClassname, szFeatureClassname;
		CString szOperationClass;
		try {

			szExecutableClassname = CString((LPCSTR) program->at(i)->_pExecutable->Classname).MakeLower();
			szFeatureId=(LPCTSTR) program->at(i)->GetItemValue<tstring>(_T("FeatureName")).c_str();
			szFeatureClassname=(LPCTSTR)  program->at(i)->GetItemValue<tstring>(_T("Feature")).c_str();
			row.push_back(szExecutableClassname);
			row.push_back(szFeatureClassname);
			row.push_back(szFeatureId);

			szOps=_T("<OL>\n");
			szOps+=_T("<LI>");

			szOperationClass=program->at(i)->GetItemValue<tstring>(_T("Operation")).c_str();
			szOps+=szOperationClass+_T("=");

			// machining operation identification label
			//szOperationLabel =  pOpItem->GetAttributeValue(_T("its_id"), _T("Unnamed operation"));
			//szOps+=szOperationLabel;
		}
		catch(...) {}
		szOps+=_T("</LI>\n");
		szOps+=_T("</OL>\n");
		row.push_back(szOps) ; 

		html.AppendTableRow(row);

	}

	CString szFramesPath = GetExeDirectory()+ _T("WSReport.html");
	CString szReportPath = GetExeDirectory()+ _T("WSList.html");
	CString szGCodePath = GetExeDirectory()+ _T("GCodes.html");

	CString szFrame(_T("<HTML>\n<HEADER><FRAMESET rows=\"40%,60%\">\n"));
	szFrame.AppendFormat(_T("<FRAME src=\"%s\">\n"), szReportPath);
	szFrame.AppendFormat(_T("<FRAME src=\"%s\">\n"), szGCodePath);
	szFrame.AppendFormat(_T("</FRAMESET>\n"));
	szFrame.AppendFormat(_T("</BODY>\n</HTML>\n"));
	SaveDocument(szFramesPath, szFrame);


	CString szGCode;
	CString prog = program->GenerateNCHeader();
	prog += program->GenerateNCProgram();

#if 1
	tofstream programstream;
	programstream.open(GetExeDirectory() + _T("program.txt"), ios::out);
	programstream  << (LPCTSTR) program->GenerateNCHeader();
	programstream  << (LPCTSTR) program->GenerateNCProgram();
	programstream.flush();
	programstream.close();
#endif


	szGCode.Format(_T("<HTML>\n<BODY>\n<PRE>\n%s\n</PRE>\n</BODY>\n</HTML>\n"), prog);
	//SaveDocument(szGCodePath, szGCode);
	SaveDocument(szReportPath, szGCode);

	CString szErrs = program->GenerateNCErrors();
	CString szHtmlErrs;
	szHtmlErrs.Format(_T("<HTML>\n<BODY>\n<H1>Errors</H1><PRE>\n%s\n</PRE>\n</BODY>\n</HTML>\n"), szErrs);
	SaveDocument(szGCodePath, szHtmlErrs);

	m_view.SetActivePage(WSVIEW);
	_vStepsView.Navigate(szFramesPath);
	return 0;
}



LRESULT CMainFrame::OnToolsSavexml(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	if(program==NULL)
	{
		MessageBox(_T("Generate Working Steps first"));
		return  0;
	}
#if 0
	CFileDialog dlg(FALSE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		lpcstrXmlFilter);
	if( dlg.DoModal() != IDOK )
		return 0;


	CString str = program->GenerateXmlString();
	SaveDocument(dlg.m_szFileName, str);
#endif
	CString str = program->GenerateXmlString();
	SaveFileDialogString(str, lpcstrXmlFilter);
	return 0;
}
static TCHAR  szXmlFilter[] = 
	_T("Xml Files (*.xml)\0*.xml\0\0")
	_T("");
LRESULT CMainFrame::OnToolsLoadxml(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	CFindFile finder1;
	CString module;

	CFileDialog dlg(TRUE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		szXmlFilter);
	if( dlg.DoModal() != IDOK )
		return 0;

	 // Clear existing stepnc project and treeview...
	m_treeview.DeleteAllItems();
	gpStepDom->clearStep();

	 // Parse file...
	IWorkCycles owner(gWm);
	CString str = ReadAFile(dlg.m_szFileName);
	gProject = gpStepDom->CreateNewProject();
	owner.ReadXmlString(str);

	 // Rebuild treeview ..
	//m_treeview.BuildTree(gpStepDom->GetP21HeaderAttributeList());
	m_treeview.BuildTree(gpStepDom->GetRootAttributeList());
	return 0;
}
