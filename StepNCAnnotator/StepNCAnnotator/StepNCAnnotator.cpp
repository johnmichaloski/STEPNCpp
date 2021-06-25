//
// StepNCAnnotator.cpp : main source file for StepNCAnnotator.exe
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"

#include "resource.h"

#include "StepNCAnnotatorView.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "aboutdlg.h"
#include "MainFrm.h"
#include "UnitTests.h"
#include "Express2Sql.h"
#include "stepnc_schemaClassDefinitions.h"
//#include "machining_schemaClassDefinitions.h"
//#include "milling_schemaClassDefinitions.h"
#include "DBStepNC.h"
#include "FeatureCycles.h"
#include "SymbolTable.h"
#include "PropertyManager.h"


#pragma comment(lib,"Version.lib")// For GetFileVersion fcn


CAppModule _Module;


static bool ReadFile(CString filename, CString &text)
{
	FILE * fin = fopen(filename,"rt"); // open read and text mode (not binary)
	fseek(fin,0, SEEK_END);
	int filesize = ftell(fin);
	fseek(fin,0, SEEK_SET);
	text.Empty();
	text.GetBufferSetLength(filesize + 1);
	//char * buffer = (char *)calloc(filesize + 1, 1 );
	fread(text.GetBuffer(), filesize, 1, fin);
	text.ReleaseBuffer();
	fclose(fin);
	return true;
}

int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	CMainFrame wndMain;
//	CWorldModel wm;
//	FaceMill facemill(wm);
//	OutputDebugString(facemill.TestCode());





#if 0
	CStringVector columns, values;
	columns.push_back ("name"); values.push_back("twist_drill");
	columns.push_back ("serialnumber"); values.push_back("999");
	columns.push_back ("diameter"); values.push_back("12.5");
	columns.push_back ("cutting_edge_length"); values.push_back("90.0");
	

	StringTable szColumnTable;
	StringTable szDataTable;
	CDBStepNC db;
	db.SetConnection("Microsoft.Jet.OLEDB.4.0");
	db.SetDataSource("C:\\Program Files\\NIST\\proj\\Tests\\StepNCAnnotator\\stepncmm.mdb");
	db.Connect();
	//db.CreateToolDbTable();
	db.LoadMasterCAMTool("C:\\Mcam9\\Mill\\Tools\\TOOLS_MM.TXT");
	//db.SelectTable("milling_cutter", szColumnTable,  szTable);
	//db.ExecuteSelectSql("SELECT * FROM milling_cutter",szColumnTable,  szDataTable);
	//CComBSTR bstrQuery( _T( "SELECT distinct milling_cutter.[Author Last Name], milling_cutter.[Author First Name] FROM milling_cutter" );
	//db.ExecuteSelectSql("SELECT * FROM milling_cutter WHERE millingtooltype='Endmill'", szColumnTable, szDataTable);
	//db.InsertRow("milling_cutter",  columns,  values);

	db.Close();
#endif


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
	AtlInitCommonControls(ICC_COOL_CLASSES|ICC_WIN95_CLASSES|ICC_USEREX_CLASSES|ICC_LISTVIEW_CLASSES|ICC_TAB_CLASSES|ICC_BAR_CLASSES|ICC_INTERNET_CLASSES);	// add flags to support other controls


	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	AtlAxWinInit();

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
