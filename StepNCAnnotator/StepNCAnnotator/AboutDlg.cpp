// aboutdlg.cpp : implementation of the CAboutDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include "Misc.h"
//IDC_ABOUTINFO

#include "GlobalFunctions.h"

LRESULT CAboutDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
CGlobalFunctions glb;
	CString version =  glb.GetProductVersionX() ;
	TCHAR buf[MAX_PATH];
	GetModuleFileName(NULL, buf, MAX_PATH);
	CString info = "StepNCAnnotator\r\n";
	info+= "  Version:" + version + "\r\n";
	info+= CString("  Release Date:") + __DATE__ + "\r\n";
	GetDlgItem(IDC_ABOUTINFO).SetWindowTextA(info);
	CenterWindow(GetParent());
	return TRUE;
}

LRESULT CAboutDlg::OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	EndDialog(wID);
	return 0;
}
