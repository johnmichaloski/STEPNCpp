// Spirit.cpp : main source file for Spirit.exe
//

#include "stdafx.h"

#include "resource.h"
#include "OutDebug.h"

#include "EBNFParser.h"
//#include "ExpressParser.h"
#include "StepParser.h"


#include "SpiritView.h"
#include "aboutdlg.h" 
#include "MainFrm.h"
#include "atlstr.h"
#include "Misc.h"


CAppModule _Module;

static std::string str="<xarg> ::= X '(' <real_val>  ')';\n"
"<yarg> ::= Y '(' <real_val>  ')';\n"
"<zarg> ::= Z '(' <real_val>  ')';\n"

;


int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	CMainFrame wndMain;
	DebugFileOut debugfile(CString(GetExeDirectory() + "debug.txt"));
	
	basic_debugbuf debugbuf(2048);
	std::cout.rdbuf(&debugfile);
	cout<< "Test Me" << endl;
	//CExpressParser	step;
	CStepParser step;
	step.ExpressParseIt();
	//CEBNFParser ebnfparser;
	//ebnfparser.EbnfParseIt();
	if(wndMain.CreateEx() == NULL)
	{
		ATLTRACE(_T("Main window creation failed!\n"));
		return 0;
	}

	wndMain.ShowWindow(nCmdShow);

	int nRet = theLoop.Run();

	_Module.RemoveMessageLoop();
	return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
