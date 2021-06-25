// StepAnnotatorView.h : interface of the CStepAnnotatorView class
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

class CStepAnnotatorView : public CWindowImpl<CStepAnnotatorView, CAxWindow>
{
public:
	DECLARE_WND_SUPERCLASS(NULL, CAxWindow::GetWndClassName())

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(CStepAnnotatorView)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
};
