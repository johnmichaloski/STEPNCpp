// MainFrm.cpp : implmentation of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include "P203ReaderView.h"
#include "MainFrm.h"
#include "Globals.h"
#include "Misc.h"

static const IID IID_IOglPlotter ={	0x2907BFE3,0x2909,0x437A,	{ 0x86,0xB1,0xEF, 0x51,0x50,0x34,0xB9,0x8B}};

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
	_gPart21gen= &this->_part21gen;
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

	CLSID clsid;
	_bstr_t lpszData(L"OGLServer.OglPlotter");
	CLSIDFromString(lpszData, &clsid);

	HRESULT hr=CoCreateInstance(clsid, NULL, CLSCTX_SERVER, IID_IOglPlotter, (void**)&m_plotter);


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
	// TODO: add code to initialize document

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

LRESULT CMainFrame::OnFileOpen(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	static TCHAR strFilter[] = { "Step Files (*.stp)|*.stp||" };

	CFileDialog dlg(TRUE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		strFilter);
	if( dlg.DoModal() == IDOK )
	{
		m_szP21file=dlg.m_szFileName; 
		CString title = dlg.m_szFileTitle;
		int	idx = title.ReverseFind('.');
		CString extension = title.Mid(idx);
		title = title.Left(idx);
		if(idx >0)
		{    
			if(extension==".stp")
			{
				parser.P21filename() = ::GetExeDirectory()+ title + ".txt";  // has extension on it


				ShellFileOp().CopyFileToFolder(m_szP21file.c_str(), parser.P21filename());
				m_view.Navigate("file:\\\\" + parser.P21filename());
			}

		}

	}
	return 0;
}


LRESULT CMainFrame::OnToolsParse(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if(parser.P21filename().GetLength() > 0)
	{

		// Econtext_dependent_shape_representation
		parser.Step21ParseIt(parser.P21filename());
		// FIXME: tree should use part 21 info not hard coded? maybe 

		m_treeview.BuildTree(_part21gen.GetVarDefs());  // header info...

		projectvardef = new CVarDef(NULL, gStartEntity ,entity_, (DWORD) &project, "E"+gStartEntity, 0 );
		projectvardefs.push_back(projectvardef);

		m_treeview.BuildTree(projectvardefs);

	}
	else
	{
		MessageBox("Load file first");
	}

	return 0;
}


LRESULT CMainFrame::OnViewSpiral(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	HRESULT hr;
//	CPlotter * m_plotter = (CPlotter *) new	COGLPlotter;
//	m_plotter->SetResolution(0.1);
//	m_plotter->SetDisplayList((IPnts*)gFeatureList);

	double ee = 0.08;
	double x1=0;  
	double y1=0;
	double x2=10;  
	double y2=0;
	double x3=5;  
	double y3=5*sqrt(3.0);
	LONG atom;
	m_plotter->put_BkColor( RGB(255,255,255));
	//gTransform  = (CFeature *) (IFeature *) ((CFeatureList*)m_plotter->pts)->AddFeature(CFeature::TRANSFORM) ;
	//gTransform->transform = RotateY(0);

	m_plotter->Line(x1,y1, 0., x2, y2, 0., &atom);  // Vector(x1,y1,0), Vector(x2,y2,0));
	m_plotter->Line(x2, y2, 0., x3, y3, 0., &atom); // Vector(x2,y2,0), Vector(x3,y3,0));
	m_plotter->Line(x3, y3, 0., x1,y1, 0., &atom);

	double x0=0,y0=0; 
	for (double t=0;t<100;t++)  
	{
		double x4 = ee*x2 + (1-ee)*x3;
		double  y4 = ee*y2 + (1-ee)*y3;
		m_plotter->put_Color(RGB( sin(t/4)*255.,0.,cos(t/4)*255.)); // color
		m_plotter->Line(x0,y0,0., x4,y4,0., &atom);

		x0=x4; y0=y4;
		x3=x2;  y3=y2;
		x2=x1;  y2=y1;
		x1=x4;  y1=y4;	
	}
	return 0;
}

LRESULT CMainFrame::OnViewClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_plotter->Clear();
	return 0;
}


extern void TraverseDraw(CVarDefs & instancevars, IOglPlotter * plotter, CString &tabs);

LRESULT CMainFrame::OnViewPlot(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	CString tabs;
	m_plotter->SetGraphRange(-10.,-10.,-10, 10.0,10.0, 10.0);
	TraverseDraw(projectvardefs, m_plotter, tabs);
	return 0;
}
