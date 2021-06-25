//
// MainFrm.h : interface of the CMainFrame class
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "atlsplit.h"

#include "WtlHtmlView.h"
#include "Step21Parser.h"
#include "FeatureCycles.h"
#include "StepNCTreeView.h"
#include "Part21Generator.h"
#include "ToolTipDialog.h"

#define WINDOW_MENU_POSITION	3



class CListBoxView : public CWindowImpl<CListBoxView, CListBox>
{
public:
	DECLARE_WND_SUPERCLASS(NULL, CListBox::GetWndClassName())

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return FALSE;
	}

	BEGIN_MSG_MAP(CListBoxView)
	//	REFLECTED_COMMAND_CODE_HANDLER (LBN_SELCHANGE, OnSelectionChange)
	END_MSG_MAP()

	LRESULT OnSelectionChange(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& bHandled)
	{

		DebugBreak();
		bHandled=false;
		return 1;
	}
// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
};


class CMainFrame : public CFrameWindowImpl<CMainFrame>, public CUpdateUI<CMainFrame>,
		public CMessageFilter, public CIdleHandler

{
public:
	DECLARE_FRAME_WND_CLASS(NULL, IDR_MAINFRAME)
	enum { IDD = IDD_ABOUTBOX };

	CTabView m_tabview; // m_view;
	CWtlHtmlView _vHierarchyView ;
	CWtlHtmlView _vToolView ;
	CWtlHtmlView _vStepsView ;
	CWtlHtmlView _vXMLView ;
	CWtlHtmlView _vP21View ;
	CWtlHtmlView _vFeaturesView ;
	CListBoxView _vCompileListbox;


	CStepNCTreeView _vTreeview;
	//CListViewCtrl * pListview;

	CSplitterWindow  m_splitter; 
	CPaneContainer m_pane;

	CErrPairs _verifyerrors;

	CStep21Parser parser;
	CVarDefPtr projectvardef;  // top level of STEPNC++ Tree variables
	CVarDefs  projectvardefs;
	CPart21Generator _part21gen;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

	BEGIN_UPDATE_UI_MAP(CMainFrame)
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_TREEPANE, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_MOVEDOWN, UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_MOVEUP, UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_DELETEBUTTON, UPDUI_TOOLBAR)
		
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainFrame)
		COMMAND_CODE_HANDLER(LBN_SELCHANGE, OnSelectionChangeHandler)
//		COMMAND_CODE_HANDLER(TVN_SELCHANGED, OnTreeSelectionChangeHandler)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_FILE_NEW, OnFileNew)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(ID_WINDOW_CLOSE, OnWindowClose)
		COMMAND_ID_HANDLER(ID_WINDOW_CLOSE_ALL, OnWindowCloseAll)
		COMMAND_RANGE_HANDLER(ID_WINDOW_TABFIRST, ID_WINDOW_TABLAST, OnWindowActivate)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLTABLE, OnViewTooltable)
		COMMAND_ID_HANDLER(ID_VIEW_WORKINGSTEPS, OnViewWorkingsteps)
		COMMAND_ID_HANDLER(ID_VIEW_XMLTREE, OnViewXmltree)
		COMMAND_ID_HANDLER(ID_VIEW_PART21, OnViewPart21)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLLOOKUP, OnViewToollookup)
		COMMAND_ID_HANDLER(ID_FILE_OPEN, OnFileOpen)
		COMMAND_ID_HANDLER(ID_TOOLS_PARSE, OnToolsParse)
		COMMAND_ID_HANDLER(ID_GENERATENCCODE_SIEMENS, OnGeneratenccodeSiemens)
		COMMAND_ID_HANDLER(ID_TOOLS_RESAVE, OnToolsResave)

		COMMAND_ID_HANDLER(ID_MOVEDOWN, _vTreeview.OnMoveDown)
		COMMAND_ID_HANDLER(ID_MOVEUP, _vTreeview.OnMoveUp)
		COMMAND_ID_HANDLER(ID_DELETEBUTTON, _vTreeview.OnDeleteItem)

		COMMAND_ID_HANDLER(ID_VIEW_TREEPANE, OnViewTreePane)
		COMMAND_ID_HANDLER(ID_PANE_CLOSE, OnTreePaneClose)

		//NOTIFY_CODE_HANDLER(TVN_BEGINLABELEDIT, OnBeginLabelEdit ) 
		REFLECT_NOTIFICATIONS()
		COMMAND_ID_HANDLER(ID_FILE_SAVE_AS, OnFileSaveAs)
		COMMAND_ID_HANDLER(ID_TOOLS_COMPILLE, OnToolsCompille)
		COMMAND_ID_HANDLER(ID_HELP_CONTENTS, OnHelpContents)
		COMMAND_ID_HANDLER(ID_HELP_SEARCH, OnHelpSearch)
		CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
	END_MSG_MAP()

	
// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
	void OnHelpHelpindex();

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowClose(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowCloseAll(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowActivate(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewTooltable(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewWorkingsteps(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewXmltree(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewPart21(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewToollookup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileOpen(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnToolsParse(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnGeneratenccodeSiemens(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnToolsResave(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileSaveAs(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSelectionChangeHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnTreeSelectionChangeHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnBeginLabelEdit(int /*idCtrl*/, LPNMHDR pnmh, BOOL& /*bHandled*/)
	{
		DebugBreak();
		return 0;
	}

	LRESULT OnViewTreePane(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		bool bShow = (m_splitter.GetSinglePaneMode() != SPLIT_PANE_NONE);
		m_splitter.SetSinglePaneMode(bShow ? SPLIT_PANE_NONE : SPLIT_PANE_RIGHT);
		UISetCheck(ID_VIEW_TREEPANE, bShow);

		return 0;
	}

	LRESULT OnTreePaneClose(WORD /*wNotifyCode*/, WORD /*wID*/, HWND hWndCtl, BOOL& /*bHandled*/)
	{
		if(hWndCtl == m_pane.m_hWnd)
		{
			m_splitter.SetSinglePaneMode(SPLIT_PANE_RIGHT);
			UISetCheck(ID_VIEW_TREEPANE, 0);
		}

		return 0;
	}
	LRESULT OnToolsCompille(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnHelpContents(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnHelpSearch(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
