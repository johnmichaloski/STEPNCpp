// MainFrm.cpp : implmentation of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include "StepNCAnnotatorView.h"
#include "MainFrm.h"
#include "HtmlTable.h"
#include "Step21Parser.h"
#include "DBStepNC.h"

#include "FeatureCycles.h"
#include "Seimens840D.h"
#include "Part21Generator.h"
#include "StepNC.h"

CPart21Generator * _gPart21gen=NULL;
//#include "machining_schemaClassDefinitions.h"
//#include "milling_schemaClassDefinitions.h"
using namespace Express;

#define HIERARCHYVIEW 0
#define P21VIEW 1
#define WSVIEW 2
#define TOOLVIEW 3
#define XMLTREEVIEW 4
#define FEATUREVIEW 5
#define LISTBOXVIEW 6
static BOOL bflag;

template<typename T>
static Vector ToVector(std::vector<T> &direction_ratios )
{
	Vector v;
	v.x= direction_ratios[0]->val;
	v.y= direction_ratios[1]->val;
	if(direction_ratios.size()> 2)
		v.z= direction_ratios[2]->val;
	return v;
};
static CString GetTempDirectory()
{
	// replace with temp later
	return GetExeDirectory();
}
BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	if(CFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))
		return TRUE;

	// FIXME
	return m_tabview.PreTranslateMessage(pMsg);
}

BOOL CMainFrame::OnIdle()
{

	UIEnable(ID_MOVEDOWN,  _vTreeview.IsMoveDownEnabled());
	UIEnable(ID_MOVEUP,  _vTreeview.IsMoveUpEnabled());
	UIEnable(ID_DELETEBUTTON,  _vTreeview.IsDeleteEnabled());

	UIUpdateToolBar();
	return FALSE;
}

LRESULT CMainFrame::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	_gPart21gen= &this->_part21gen;
	CreateSimpleToolBar();

	CreateSimpleStatusBar();

	UIAddToolBar(m_hWndToolBar);
	UISetCheck(ID_VIEW_TOOLBAR, 1);
	UISetCheck(ID_VIEW_STATUS_BAR, 1);
	UISetCheck(ID_VIEW_TREEPANE, 1);

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);


	const DWORD dwSplitStyle = WS_CHILD | WS_VISIBLE | 	WS_CLIPCHILDREN | WS_CLIPSIBLINGS,	dwSplitExStyle = WS_EX_CLIENTEDGE;
	 m_hWndClient = m_splitter.Create (m_hWnd, rcDefault, NULL,  dwSplitStyle, dwSplitExStyle );

	m_pane.Create(m_splitter, _T("Tree"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);	

	//pListview = new CListViewCtrl;
	//pListview->Create ( m_splitter, rcDefault, NULL, WS_CHILD | WS_VISIBLE | LVS_SINGLESEL |  LVS_REPORT );

	_vTreeview.Create(m_pane); 
	_vTreeview.SetFont(AtlGetDefaultGuiFont());
	m_pane.SetClient(_vTreeview);

	m_tabview.Create(m_splitter, rcDefault, _T("http://www.microsoft.com"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN , 0);

	m_splitter.SetSplitterPanes ( m_pane, m_tabview.m_hWnd  );
	m_splitter.m_cxyMin = 285; // minimum size - THIS SETS THE SIZE. A BUG IN SPLITTER in TABBED VIEW?
	m_splitter.SetSplitterPos(295); // from left

	UpdateLayout();

	CMenuHandle menuMain = GetMenu();
	m_tabview.SetWindowMenu(menuMain.GetSubMenu(WINDOW_MENU_POSITION));
	
	_vHierarchyView.Create(m_tabview, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vHierarchyView.SetFont(AtlGetDefaultGuiFont());
	m_tabview.AddPage(_vHierarchyView.m_hWnd, _T("STEPNC Hierarchy"));

	_vP21View.Create(m_tabview, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vP21View.SetFont(AtlGetDefaultGuiFont());
	m_tabview.AddPage(_vP21View.m_hWnd, _T("Part 21"));

	_vStepsView.Create(m_tabview, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vStepsView.SetFont(AtlGetDefaultGuiFont());
	m_tabview.AddPage(_vStepsView.m_hWnd, _T("Working Steps"));

	_vToolView.Create(m_tabview, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vToolView.SetFont(AtlGetDefaultGuiFont());
	m_tabview.AddPage(_vToolView.m_hWnd, _T("Tools"));

	_vXMLView.Create(m_tabview, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vXMLView.SetFont(AtlGetDefaultGuiFont());
	m_tabview.AddPage(_vXMLView.m_hWnd, _T("XML Tree"));

	_vFeaturesView.Create(m_tabview, rcDefault, _T("about:blank"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	_vFeaturesView.SetFont(AtlGetDefaultGuiFont());
	m_tabview.AddPage(_vFeaturesView.m_hWnd, _T("Features"));

	_vCompileListbox.Create(m_tabview, rcDefault, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL | LBS_NOINTEGRALHEIGHT | LBS_NOTIFY | LBS_WANTKEYBOARDINPUT, WS_EX_CLIENTEDGE);
	m_tabview.AddPage(_vCompileListbox.m_hWnd, _T("Verify Errors"));

	CString szPath = GetExeDirectory() + "STEPNCHierarchy.htm";
	_vHierarchyView.Navigate(szPath);
	

	m_tabview.SetActivePage(0);

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



LRESULT CMainFrame::OnWindowClose(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	int nActivePage = m_tabview.GetActivePage();
	if(nActivePage != -1)
		m_tabview.RemovePage(nActivePage);
	else
		::MessageBeep((UINT)-1);

	return 0;
}

LRESULT CMainFrame::OnWindowCloseAll(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_tabview.RemoveAllPages();

	return 0;
}

LRESULT CMainFrame::OnWindowActivate(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	int nPage = wID - ID_WINDOW_TABFIRST;
	m_tabview.SetActivePage(nPage);

	return 0;
}

LRESULT CMainFrame::OnViewTooltable(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CString tmp;
	CHtmlTable html;
	CString szTestReportStyle = "./_UpgradeReport_Files/TestReport.css";
	html.LoadTableHeader(_T("Tool"), _T("Length"), _T("Diameter"),_T("Material"), _T("Teeth"),  _T("Hand"), NULL);
	html.LoadColumnsStyle(_T(""), _T("valign=middle align=right"), _T("valign=middle align=right"),_T("valign=middle align=center"),  _T("valign=middle align=center"), _T("valign=middle align=center"), NULL);
 
	//CVarDefs list = project->getElementsByTagName(CString("Ecutting_tool"));
	VarTable tooltable;
	CStringVector columns;
	columns.push_back("its_id");
	columns.push_back("its_cutting_edge.tool_offset_length");
	columns.push_back("its_tool_body.dimension.diameter");
	columns.push_back("its_cutting_edge.its_material.standard_identifier");
	columns.push_back("its_tool_body.number_of_teeth");
	columns.push_back("its_tool_body.hand_of_cut");


	CVarDefs list = project->getElementsByTagName(CString("Ecutting_tool"));
	CVarDefs seen; 
	for(int i=0; i< list.size(); i++)
	{
		CStringVector row;
		CVarDefPtr vardef;
		_variant_t var;

		// Check if already looked up the information for this tool node
		if( std::find(seen.begin(), seen.end(), list[i]) != seen.end())
			continue;
		seen.push_back(list[i]);

		IStepNodePtr pItem = GetThis(list[i]);
		if(pItem==NULL)
			DebugBreak();

		vardef = GetVarDef(pItem , "its_tool_body");
		IStepNodePtr pItem1=GetThis(vardef); 
		if(pItem1)
			row.push_back(ExpDemangle(pItem1->Classname())) ; 


		vardef = GetVarDef(pItem , "its_cutting_edge[0]/tool_offset_length");
		var = pItem->GetVarDefVal( vardef);
		try { row.push_back((char *) (bstr_t) var);} catch(...){}

		vardef = GetVarDef(pItem , "its_tool_body/dimension/diameter");
		var = pItem->GetVarDefVal( vardef);
		try { row.push_back((char *) (bstr_t) var);} catch(...){}

		vardef = GetVarDef(pItem , "its_cutting_edge[0]/its_material/standard_identifier");
		var = pItem->GetVarDefVal( vardef);
		try { row.push_back((char *) (bstr_t) var);} catch(...){}

		vardef = GetVarDef(pItem , "its_tool_body/number_of_teeth");
		var = pItem->GetVarDefVal( vardef);
		try { row.push_back((char *) (bstr_t) var);} catch(...){}

		vardef = GetVarDef(pItem , "its_tool_body/hand_of_cut");
		var = pItem->GetVarDefVal( vardef);
		try { row.push_back((char *) (bstr_t) var);} catch(...){}

		// Check if alreay added identical tool information
		if(find(html.m_strTableData.begin(),html.m_strTableData.end() , row) == html.m_strTableData.end())
			html.AppendTableRow(row);


	}
#if 0
	project->selectElementsByTagName(tooltable, columns, CString("Ecutting_tool"), true);
	for(int i=0; i< tooltable.size(); i++)
	{
		CStringVector row;
		for(int j=0; j<columns.size(); j++)
		{
			row.push_back(tooltable(i,j));  
		}
		html.AppendTableRow(row);
	}
#endif
	tmp+=_T("<HTML>\n");
	tmp+=_T("<HEADER>\n");
	 tmp.AppendFormat("<LINK href=\"%s\" rel=\"stylesheet\" type=\"text/css\">\n", szTestReportStyle);
	tmp.AppendFormat("<TITLE>%s</TITLE>", "Tool Table");
	//tmp.AppendFormat(" <meta http-equiv=\"Page-Exit\" content=\"progid:DXImageTransform.Microsoft.Fade(duration=.3)\" />");
	tmp+=_T("</HEADER>\n");
	tmp+=_T("<BODY>\n");
	tmp+=StrFormat("<script language=\"Javascript1.2\">	function set_CSS(el_id, CSS_attr, CSS_val) { var el = document.getElementById(el_id); if (el) el.style[CSS_attr] = CSS_val; }  </script>");
	tmp.AppendFormat("<H1>%S</H1>", Str2W("Tools"));
	tmp+=html.ToHtmlTable();
	tmp+=_T("</BODY></HTML>");
	CString szPath = GetExeDirectory()+ "ToolReport.html";
	SaveDocument(szPath, tmp);

//	pToolView -> SetDocumentText(tmp);
	m_tabview.SetActivePage(TOOLVIEW );
	_vToolView.Navigate(szPath);
	return 0;
}
struct FeatureMapping : public std::map<CString, CFeatureCycles::CANON_FEATURE> {
FeatureMapping();
};

FeatureMapping::FeatureMapping()
{ 
	insert(value_type("plane_rough_milling", CFeatureCycles::FACEMILL));
	insert(value_type("plane_finish_milling", CFeatureCycles::FACEMILL));
	insert(value_type("drilling_operation", CFeatureCycles::DRILLCENTERING));
	insert(value_type("drilling", CFeatureCycles::DRILLCENTERING));
}
static FeatureMapping eFeatureMap;

LRESULT CMainFrame::OnViewWorkingsteps(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CHtmlTable html;
	int i;
	CString szTestReportStyle = "./_UpgradeReport_Files/TestReport.css";
	CString szFeatureClassname;
	CString szFeatureId;
	CFeatureCyclesPtr program;


	html.LoadTableHeader(_T("Feature"), _T("Name"),  _T("Operations"), NULL);
	html.LoadColumnsStyle(_T(""), _T(""), _T(""), NULL);
	if(project==NULL)
	{
		MessageBox("Please Parse File first\n");
		return 0;
	}

	program= new Seimens840D(gWm);

	int n = GetVarItemSize(project, "/main_workplan/its_elements");
	int m=	GetVarItemSize(project, "/its_workpieces");
	for(i=0; i<m; i++)
	{
		EworkpiecePtr workpiece=(Eworkpiece*) GetVarItem(project, StrFormat("/its_workpieces[%d]", i)).get();
		CString szStandardMaterialId;
		CString szMaterialId;
		double dTolerance;   // global workpiece tolerance
		Vector position;	// position workpiece based? who defined.

		if(!workpiece)
			continue;
		dTolerance = (workpiece->global_tolerance) ? workpiece->global_tolerance->val : -1.0;
		gWm.SetGlobalTolerance(dTolerance);

		szStandardMaterialId = "No Standard Material Id given";
		szMaterialId = "No Material Identifier given";
		if(workpiece->its_material)
		{			
			szStandardMaterialId = (workpiece->its_material->standard_identifier) ? workpiece->its_material->standard_identifier->val : "";
			szMaterialId = (workpiece->its_material->material_identifier) ? workpiece->its_material->material_identifier->val : "";
		}
	
		// THIS WILL NEED TESTING: IT IS A CLASS SELECT Ebounding_geometry_select either
		// EblockPtr _Eblock;
		// Eright_circular_cylinderPtr _Eright_circular_cylinder;

		IStepNodePtr pStock = workpiece->its_bounding_geometry;
		if(pStock && pStock->Classname() == "Eblock")
		{
			EblockPtr pBlock= (Eblock*) pStock.get();
			double dXExtent, dYExtent, dZExtent;
			if(!pBlock ||! pBlock->position ||! pBlock->position->location)
			{
				OutputDebugString("ERROR: back workpiece stock location\n");
				continue;
			}
			position=ToVector(pBlock->position->location->coordinates); 
			dXExtent=(pBlock->x) ? pBlock->x->val : 0; 
			dYExtent=(pBlock->y) ? pBlock->y->val : 0; 
			dZExtent=(pBlock->z) ? pBlock->z->val : 0; 

			OutputDebugString(StrFormat("Stocks %s Extents X(%.3f) Y(%.3f) Z(%.3f)\n", position.ToString(), dXExtent, dYExtent, dZExtent));

			program->StockDefinition(CFeatureCycles::BLOCK, " ", position, Vector(dXExtent, dYExtent, dZExtent));

		}
		else if(pStock &&  pStock->Classname() == "Eright_circular_cylinder")
		{

		}
		else
		{


		}
	}
	for(i=0; i< n; i++)
	{
		IStepNodePtr pFeature;
		CStringVector row;
		CVarDefPtr vardef;
		_variant_t var;
		CString szOps;
		CString szComment;
		CString szOperationLabel;

		pFeature = GetVarItem(project, StrFormat("/main_workplan/its_elements[%d]/its_feature", i));

		if(!pFeature)
		{
			pFeature = GetVarItem(project, StrFormat("/main_workplan/its_elements[%d]", i));
	
			OutputDebugString(StrFormat("Feature Based machining - not handling %s element\n", pFeature->Classname()));
			continue;

		}

		// feature classname,  planar_face, hole, etc.
		szFeatureClassname=ExpDemangle(pFeature->Classname());
		row.push_back(szFeatureClassname) ; 
		szFeatureClassname.MakeLower();
		vardef = GetVarDef(pFeature , "its_id");

		// feature identification label
		var = pFeature->GetVarDefVal( vardef);
		try {szFeatureId.Empty(); szFeatureId=(char *) (bstr_t) var;} catch(...){} 
		row.push_back(szFeatureId);

		// retrieve number of feature operations
		int m = GetVarItemSize(pFeature, StrFormat("its_operations", i));

		// Prepare html display list of operations
		szOps="<OL>\n";

		// process each feature operation
		for(int j=0; j<m; j++)
		{
			Emachining_operationPtr pOpItem; // pointer to operation
			Ecutting_toolPtr its_tool;		 // tool
			CString szMachineopClass;		// demangled classname of machining operation
			CString szToolClassname;		// classname of tool
			double dToolRadius;
			CVarDefPtr vardef;
			_variant_t var;
			double dFeedrate=0.0;  
			long nCuttercomp;
			double dSpindleSpeed=0.0;  

			// Retrieve pointer to machining operation
			pOpItem = (Emachining_operation*) GetVarItem(pFeature, StrFormat("its_operations[%d]", j)).get();
			szOps+="<LI>";
			if(pOpItem==NULL)
			{
				OutputDebugString("cast <Emachining_operation>(pOpItem) Failed\n");
				continue;
			}

			// machining operation classname,  plane_rough_milling, drilling, etc.
			szMachineopClass = ExpDemangle(pOpItem->Classname()).MakeLower() ; 
			szOps+=szMachineopClass+"=";

			// machining operation identification label
			vardef = GetVarDef(pOpItem , "its_id");
			var = pOpItem->GetVarDefVal( vardef);
			try {szOperationLabel =(char *) (bstr_t) var;} catch(...){}  
			szOps+=szOperationLabel;
#if 0
			// all optional... none used.
			double dX0		=	pOpItem->start_point->coordinates[0]->val;
			double dY0		=	pOpItem->start_point->coordinates[1]->val;
			double dZ0		=	pOpItem->start_point->coordinates[2]->val;
			double dRetract =  (pOpItem->retract_plane!=NULL) ? pOpItem->retract_plane->val: dZ0+10;
#endif
			// machining operation tooling information
			its_tool=(Ecutting_tool *) pOpItem->its_tool.get();
			
			// tooling classname,  drill, endmill, etc.
			szToolClassname=(its_tool->its_tool_body) ? ExpDemangle(its_tool->its_tool_body->Classname()): "None specified";
#if 0
			vardef = GetVarDef(its_tool , "its_tool_body/dimension/diameter");
			if(vardef==NULL)
				OutputDebugString("Tool selected without diameter. Feature guessing enabled :)\n");
			var = pOpItem->GetVarDefVal( vardef);
			try { dToolRadius= (double) var;} catch(...){ dToolRadius=0.0;}  
			dToolRadius/=2.0;
#endif
			szComment=StrFormat("WS(%d) %s Feature=%s Operation(%d)=%s Tool=%s", i, szFeatureId,  szFeatureClassname,j, szMachineopClass,  szToolClassname);
			OutputDebugString(szComment); OutputDebugString("\n");


			// Feedrate is in base technology
			if(pOpItem->its_technology && pOpItem->its_technology->feedrate )
			{
				dFeedrate=pOpItem->its_technology->feedrate->val;
				nCuttercomp=pOpItem->its_technology->feedrate_reference->_nSelection;
			}
			// Spindle speed is int millingtechnology
			Emilling_technologyPtr pMillingTechnology = (Emilling_technology *) pOpItem->its_technology.get();
			if(pMillingTechnology)
			{
				dSpindleSpeed=(pMillingTechnology->spindle)? pMillingTechnology->spindle->val : 0; // sign determines cw, ccw

			}

			// operation is kinda immaterial of feature...
			if(szMachineopClass=="plane_rough_milling" || szMachineopClass=="plane_finish_milling")
			{
				FaceMillPtr facemill =(FaceMill *)  program->CreateFeature(CFeatureCycles::FACEMILL).get();// FaceMill(gWm);
				facemill->SetComment(szComment);
				if(FAILED(facemill->DeriveParameters(pFeature, pOpItem)))
				{
					OutputDebugString("Failed  Facemill DeriveParameters\n");
					continue;
				}

				program->AddCommand(facemill);
			}
	
			// type of drillling_operation
			else if(pOpItem->IsKindOf("Edrilling_type_operation"))
			{ 
				Eround_holePtr pHole= (Eround_hole*) pFeature.get();

				if(szMachineopClass=="drilling_operation" 
					|| szMachineopClass=="drilling" 
					|| szMachineopClass=="center_drilling"
					|| szMachineopClass=="counter_sinking")
				{
					DrillCenteringPtr drilling =(DrillCentering *)  program->CreateFeature(CFeatureCycles::DRILLCENTERING).get();// FaceMill(gWm);
					drilling->SetComment(szComment);
					if(FAILED(drilling->DeriveParameters(pFeature, pOpItem)))
					{
						OutputDebugString("Failed  Reaming DeriveParameters\n");
						continue;
					}

					// Would help to have tool length to make sure depth is achievable
					program->AddCommand(drilling);

				}
				else if(szMachineopClass=="reaming")
				{

					ReamingPtr reaming =(Reaming *)  program->CreateFeature(CFeatureCycles::REAMING).get();// FaceMill(gWm);
					reaming->SetComment(szComment);
					if(FAILED(reaming->DeriveParameters(pFeature, pOpItem)))
					{
						OutputDebugString("Failed  Reaming DeriveParameters\n"); 
						continue;
					}
					// Would help to have tool length to make sure depth is achievable
					program->AddCommand(reaming);


				}
				else if(szMachineopClass=="multistep_drilling")
				{


				}
				else if(szMachineopClass=="boring")
				{


				}

				else if(szMachineopClass=="back_boring")
				{


				}
				else if(szMachineopClass=="tapping")
				{


				}
				else if(szMachineopClass=="thread_drilling")
				{


				}
			}
			// not operation based, try feature for pocket...  distinguish by fcn[feature,op]
			else if(szFeatureClassname=="closed_pocket"  || szFeatureClassname=="open_pocket")
			{
				IFeatureCyclePtr pocketing;
				if(pocketing=SiemensBasicPocketing::DerivePocketingCycle(program, pFeature, pOpItem))
				{
					pocketing->SetComment(szComment);
					program->AddCommand(pocketing);
				}

			}		
			else 
			{


			}



			szOps+="</LI>\n";
		}
		szOps+="</OL>\n";
		row.push_back(szOps) ; 


		html.AppendTableRow(row);
	}

	CString szFramesPath = GetExeDirectory()+ "WSReport.html";
	CString szReportPath = GetExeDirectory()+ "WSList.html";
	CString szGCodePath = GetExeDirectory()+ "GCodes.html";

	CString szFrame("<HTML>\n<HEADER><FRAMESET rows=\"40%,60%\">\n");
	szFrame.AppendFormat("<FRAME src=\"%s\">\n", szReportPath);
	szFrame.AppendFormat("<FRAME src=\"%s\">\n", szGCodePath);
	szFrame.AppendFormat("</FRAMESET>\n");
	szFrame.AppendFormat("</BODY>\n</HTML>\n");
	SaveDocument(szFramesPath, szFrame);

	CString szWorkingSteps;
	szWorkingSteps+=_T("<HTML>\n");
	szWorkingSteps+=_T("<HEADER>\n");
	szWorkingSteps.AppendFormat("<LINK href=\"%s\" rel=\"stylesheet\" type=\"text/css\">\n", szTestReportStyle);
	szWorkingSteps.AppendFormat("<TITLE>%s</TITLE>", "Working Steps Table");
	szWorkingSteps.AppendFormat(" <meta http-equiv=\"Page-Exit\" content=\"progid:DXImageTransform.Microsoft.Fade(duration=.3)\" />");
	szWorkingSteps+=_T("</HEADER>\n");
	szWorkingSteps+=_T("<BODY>\n");
	szWorkingSteps+=StrFormat("<script language=\"Javascript1.2\">	function set_CSS(el_id, CSS_attr, CSS_val) { var el = document.getElementById(el_id); if (el) el.style[CSS_attr] = CSS_val; }  </script>");
	szWorkingSteps.AppendFormat("<H1>%S</H1>", Str2W("Working Steps"));
	szWorkingSteps+=html.ToHtmlTable();
	szWorkingSteps+=_T("</BODY></HTML>");
	SaveDocument(szReportPath, szWorkingSteps);

	CString szGCode;
	szGCode.Format("<HTML>\n<BODY>\n<PRE>\n%s\n</PRE>\n</BODY>\n</HTML>\n", program->GenerateNCProgram());
	SaveDocument(szGCodePath, szGCode);

	m_tabview.SetActivePage(WSVIEW);
	_vStepsView.Navigate(szFramesPath);
	return 0;
}

LRESULT CMainFrame::OnViewXmltree(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CString tmp;
	tmp=_T("<project>\n");
	
	tmp+=DumpCVarDefs(project->GetVarDefs(), true);
	tmp+=_T("</project>\n");
	CString szPath = GetExeDirectory()+ "XMLTree.xml";
	SaveDocument(szPath, tmp);

	m_tabview.SetActivePage(XMLTREEVIEW);
	_vXMLView.Navigate(szPath);
	return 0;
}

LRESULT CMainFrame::OnViewPart21(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_tabview.SetActivePage(P21VIEW);
	_vP21View.Navigate(CString("file:\\\\") + parser.P21filename());
	return 0;
}
extern std::vector<CDBCutterAccessor> gCutters;
LRESULT CMainFrame::OnViewToollookup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	// look up naming match of tools: end drill
	// look up stepnc variable mapped into dbbase column name.
	//
	//
	//

	CString tmp;

	VarTable tooltable;
	CStringVector columns;
	CDBStepNC db;
	try
	{
		columns.push_back("its_id");
		columns.push_back("its_cutting_edge.tool_offset_length");  //"flute_length"
		columns.push_back("its_tool_body.dimension.diameter");   // tip_diameter
		columns.push_back("its_tool_body.number_of_teeth");  // number_of_teeth
		columns.push_back("its_tool_body.hand_of_cut");  // hand_of_cut
		project->selectElementsByTagName(tooltable, columns, CString("Ecutting_tool"), true);
		if(tooltable.size() < 1)
			throw StrFormat("No tools found");

		db.SetConnection("Microsoft.Jet.OLEDB.4.0");
		db.SetDataSource("C:\\Program Files\\NIST\\proj\\Tests\\StepNCAnnotator\\stepnc.mdb");
		if(FAILED(db.Connect()))
			throw StrFormat("Database %s connection Failed", db._DataSource);
		db.ExecuteSelectToolsSql("SELECT * FROM milling_cutter", gCutters );
		for(int i=0; i< gCutters.size();  i++)
		{
			OutputDebugString(StrFormat("%s\n", gCutters[i].m_name));

		}
		//db.ExecuteSelectSql(tszSQL, szColumnTable, szDataTable);

	}
	catch(CString errmsg)
	{
		OutputDebugString(errmsg);
	}
	db.Close();
	return 0;
}

LRESULT CMainFrame::OnFileOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	static TCHAR strFilter[] = { "Any NC Files (*.*)|*.*||" };

	CFileDialog dlg(TRUE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		strFilter);
	if( dlg.DoModal() == IDOK )
	{
		parser.P21filename() = dlg.m_szFileName; 
		OnViewPart21(wNotifyCode, wID, hWndCtl, bHandled);

	}
	return 0;
}

LRESULT CMainFrame::OnToolsParse(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	if(parser.P21filename().GetLength() > 0)
	{
		parser.Step21ParseIt(parser.P21filename());
		// FIXME: tree should use part 21 info not hard coded? maybe 
		_vTreeview.BuildTree(_part21gen.GetVarDefs());
		projectvardef = new CVarDef(NULL, "project",entity_, (DWORD) &project, "Eproject", 0 );
		projectvardefs.push_back(projectvardef);
		_vTreeview.BuildTree(projectvardefs);
	}
	else
	{
		MessageBox("Load file first");
	}

	return 0;
}

LRESULT CMainFrame::OnGeneratenccodeSiemens(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
#if 0
	int n = GetVarItemSize(project, "/main_workplan/its_elements");
	for(int i=0; i< n; i++)
	{
		IStepNodePtr pItem = GetVarItem(project, StrFormat("/main_workplan/its_elements[%d]/its_feature", i));
		CStringVector row;
		row.push_back(pItem->Classname()) ; 
		CVarDefPtr vardef = GetVarDef(pItem , "its_id");

		_variant_t var = pItem->GetVarDefVal( vardef);
		try { row.push_back((char *) (bstr_t) var);} catch(...){}  
		html.AppendTableRow(row);
	}
#endif
	return 0;
}

LRESULT CMainFrame::OnToolsResave(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	parser.Step21ParseIt(parser.P21filename());

	CString filename = parser.P21filename();
	filename.Replace(".", "_1.");

	_part21gen.SaveP21(project, filename);

	return 0;
}

LRESULT CMainFrame::OnFileSaveAs(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if(projectvardef==NULL)
		return	MessageBox("No parsed file to save")<0;  // force zero return


	static TCHAR strFilter[] = { "Any NC Files (*.txt)|*.txt||" };

	CFileDialog dlg(FALSE,
		_T("*"),
		NULL,
		OFN_OVERWRITEPROMPT|OFN_HIDEREADONLY,
		strFilter);
	if( dlg.DoModal() == IDOK )
	{
		_part21gen.SaveP21(project, dlg.m_szFileName);
		parser.P21filename() = dlg.m_szFileName; 
	}

	return 0;
}

LRESULT CMainFrame::OnToolsCompille(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	_verifyerrors.clear();
	_part21gen.CompileCVarDefs(projectvardefs, _verifyerrors, "");
	_vCompileListbox.ResetContent();
	for(int i=0; i< _verifyerrors.size(); i++)
		_vCompileListbox.AddString(_verifyerrors[i].errmsg);
	m_tabview.SetActivePage(LISTBOXVIEW);

	return 0;
}


LRESULT CMainFrame::OnSelectionChangeHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	int i = _vCompileListbox.GetCurSel();
	CVarDefPtr vardef = _verifyerrors[i].vardef;
	CTreeItem ti((HTREEITEM) vardef->m_dwAtom);
	CTreeItem lastti= _vTreeview.GetSelectedItem();
	_vTreeview.SelectItem(ti);
	_vTreeview.EnsureVisible(ti);
	_vTreeview.SetItemState(ti,TVIS_SELECTED, TVIS_SELECTED);

	return 0;
}

#include "htmlhelp.h"
#pragma comment(lib, "htmlhelp.lib")
void CMainFrame::OnHelpHelpindex()
{
	
	
}
LRESULT CMainFrame::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	CAboutDlg dlg;
	dlg.DoModal();
	return 0;
}


LRESULT CMainFrame::OnTreeSelectionChangeHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CTreeItem lastti= _vTreeview.GetSelectedItem();

	return 0;
}	


LRESULT CMainFrame::OnHelpContents(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CString pUrlAbout;
	pUrlAbout+=GetExeDirectory();
	pUrlAbout+=_T("htmlhelp.chm");

	::HtmlHelp(m_hWnd, pUrlAbout,HH_DISPLAY_TOC, NULL);

	return 0;
}

LRESULT CMainFrame::OnHelpSearch(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CString pUrlAbout;
	pUrlAbout+=GetExeDirectory();
	pUrlAbout+=_T("htmlhelp.chm");

	::HtmlHelp(m_hWnd, pUrlAbout,HH_DISPLAY_SEARCH, NULL);

	return 0;
}
