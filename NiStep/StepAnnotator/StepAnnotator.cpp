// StepAnnotator.cpp : main source file for StepAnnotator.exe
//

#include "stdafx.h"

#include "resource.h"

#include "StepAnnotatorView.h"
#include "aboutdlg.h"
#include "MainFrm.h"
#include "Mappings/Mastercam/Mastercam.h"

CAppModule _Module;

#include <string> 
#include <map> 
#include <iostream> 
#include <fstream> 


#include "common/xml_irandarchive.hpp"
#include <boost/archive/impl/basic_xml_iarchive.ipp>

using namespace boost::archive;
using boost::serialization::make_nvp;


int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
	USES_CONVERSION;
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	CMainFrame wndMain;



	MastercamTool t;
	MastercamToolCatalog tools;
#if 0
	std::ofstream ofs ("test.txt", std::ios::trunc ); 
	//boost::archive::binary_oarchive oa(ofs); 
	boost::archive::xml_oarchive oa(ofs); 
	assert (ofs.good()); 
	//t[L"asd"]=L"test"; 
#endif
	

	CQueryPath query;
	std::string xmlfilename = "C:\\Program Files\\NIST\\proj\\TestFiles\\ISO14649 Tests\\Tom K 14649\\mastercam.xml";
	std::string xmlmarkup = fileToText(xmlfilename);
	query.Read(xmlmarkup.c_str());

	std::string szTools = T2A( query.QueryXML(_T("/PROJECT/Tools")));


	std::string filename = "C:\\Program Files\\NIST\\proj\\TestFiles\\ISO14649 Tests\\Tom K 14649\\tools.xml";
	//std::string filename = "C:\\Program Files\\NIST\\proj\\TestFiles\\ISO14649 Tests\\Tom K 14649\\tool.xml";
	//std::string filename = "C:\\Program Files\\NIST\\proj\\Tests\\NiStep\\StepAnnotator\\test.txt";
  // open the archive
    ifstream ifs(filename.c_str());
	if(ifs.bad())
	{

	}
	//xml_iarchive ta(ifs,0);
	std::string str = fileToText(filename);


	xml_irandarchive ta(szTools,0);
	try {
	 ta &  make_nvp("Tools", tools); 
	}
	catch(std::exception e) {}
	//oa << t; 
	//ofs.close(); 
#if 1
	 ostringstream ofs;
	 boost::archive::xml_oarchive oa(ofs); 
	 oa &  make_nvp("Tools", tools); 
	 _bstr_t bstr = (LPCSTR) ofs.str().c_str();
	 OutputDebugString(bstr);
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

	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	AtlAxWinInit();

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
