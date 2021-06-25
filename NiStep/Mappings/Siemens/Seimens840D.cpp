#include "StdAfx.h"
#include "Siemens/Seimens840D.h"
#define _USE_MATH_DEFINES 
#include <math.h>




#include "Siemens/SiemensFacing.h"
#include "Siemens/SiemensRectangularPocket.h"
#include "Siemens/SiememsReaming.h"
#include "Siemens/SiemensCenterDrilling.h"
#include "Siemens/SiemensCounterBoring.h"
#include "Siemens/SiemensContourPocket.h"
#include "Siemens/SiemensCircularPocket.h"
#include "Siemens/SiememsLoadTool.h"
#include "Siemens/SiemensMultistepDrilling.h"
#include "Siemens/SiemensSlot.h"

typedef std::map<CString, long> ToolMap;
typedef ToolMap::value_type	 ToolMapPair;
template <typename T, int N> char (&dimension_of(T(&)[N]))[N];

static ToolMapPair iniToolMap [] =
{

	ToolMapPair(_T("endmill"),			120),
	ToolMapPair(_T("tapered_endmill"),	121),
	ToolMapPair(_T("facemill"),			140),
	ToolMapPair(_T("threading_tool"),	145),
	ToolMapPair(_T("thread_mill"),		150),
	ToolMapPair(_T("side_mill"),		150),
	ToolMapPair(_T("twist_drill"),		200),

	ToolMapPair(_T("bullnose_endmill"),	120), /* fixme */
	ToolMapPair(_T("ball_endmill"),	111),  /* fixme */

	ToolMapPair(_T("drill"),			205),
	ToolMapPair(_T("boring_tool"),		210),
	ToolMapPair(_T("center_drill"),		220),
	ToolMapPair(_T("countersink"),		230),
	ToolMapPair(_T("counterbore"),		231),
	ToolMapPair(_T("tap"),				240),
	ToolMapPair(_T("tapered_tap"),		240),
	ToolMapPair(_T("reamer"),			250),
	ToolMapPair(_T("tapered_reamer"),	250),

	ToolMapPair(_T("tapered_drill"),	205)

};
static ToolMap ToolSymbols( iniToolMap, iniToolMap + sizeof (dimension_of ( iniToolMap )) );

////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////

Seimens840D::Seimens840D(CWorldModel &wm): IWorkCycles(wm) 
{
	_dLengthConversion=1.0;
	_nToolChangenum=-1;
}
long Seimens840D::GetToolNumber(CString toolname)
{
	ToolMap::iterator it;
	if((it=ToolSymbols.find(toolname))!= ToolSymbols.end())
		return (*it).second;
	return -1; 

}
Seimens840D::~Seimens840D(void)
{
}

/*
$TC_DP1[6,1]=120 $TC_DP3[6,1]=150 $TC_DP6[6,1]=6
100 Cutter acc. to CLDATA
110 Ballhead cutter
120 End mill (without corner rounding)
121 End mill (with corner rounding)
130 Angle head cutter (without corner rounding)
131 Angle head cutter (with corner rounding)
140 Facing tool
145 Thread cutter
150 Side mill
151 Saw
155 Bevel cutter
160 Drill and thread milling cutter
Group with type 2xy (drills):
200 Twist drill
205 Solid drill
210 Boring bar
220 Center drill
230 Countersink
231 Counterbore
240 Tap, regular
241 Tap, fine
242 Tap, Whitworth
250 Reamer
*/

int  Seimens840D::LookupTool(int type, double length, double radius, double cornerradius)
{
	static int num=0;
	// FIXME: Sanity checks for now:
	if(length<=0)
		length = 100.0;

	for(int i=0; i< _toollist.size(); i++)
	{
		ToolingTuple tooling= _toollist[i];
		if(	get<0>(tooling)== type &&  get<1>(tooling)== length &&  get<2>(tooling)== radius &&  get<3>(tooling)== cornerradius)
			return i+1;
	}
	if(type<0)
	{
		DebugBreak();
	}



	_toollist.push_back( ToolingTuple(type, length, radius, cornerradius));
	num++;
	return num;
}
CString Seimens840D::PostToolDefinition(int toolnum, int tooledge)
{
	CString block;
	// FIXME: handle units: metric vs imperial
	if(toolnum!=0)
	{
		ToolingTuple tooling(_toollist[toolnum-1]);

		block+=StrFormat(_T("$TC_DP1[%d,%d]=%d $TC_DP3[%d,%d]=%.3f $TC_DP6[%d,%d]=%.3f\n"), 
			toolnum, tooledge, (int) boost::get<0>(tooling), 
			toolnum, tooledge,  boost::get<1>(tooling) * _dLengthConversion,
			toolnum, tooledge,  boost::get<2>(tooling) * _dLengthConversion);
	}
	return block;

}
CString Seimens840D::PostToolChange(int toolnum)
{
	CString block;
	if(_nToolChangenum!=toolnum)
	{
		block+=StrFormat(_T("T%d\n"),toolnum) ;
		block+=_T("M6\n");
		_nToolChangenum=toolnum;
	}
	return block;

}
CString Seimens840D::SpindleCommand(double spindlespeed)
{
	CString block;
	if(spindlespeed==0)
		return _T("M05");
	// negative angle is clockwise rotation, typical for machining tools
	if(spindlespeed<0)
		return StrFormat(_T("M03S%d"), (long) fabs(spindlespeed));
	if(spindlespeed>0)
		return StrFormat(_T("M04S%d"), (long) fabs(spindlespeed));

	return block;

}
IWorkCyclePtr Seimens840D::CreateFeature(CANON_FEATURE eType)
{ 
	switch(eType)
	{
	case FACEMILL:
		return new SiemensFaceMill(this);
	case POCKETRECTANGULAR:
		return new SiemensRectangularPocket(this);
	case DRILLCENTERING:
		return new SiemensCenterDrilling(this);
	case POCKETCIRCULAR:
		return new SiemensCircularPocket(this);
	case REAMING:
		return new SiemensReaming(this);
	case CONTOURPOCKET:
		return new SiemensContourPocket(this);

	case LOADTOOL:
		return new SiememsLoadTool(this);
		
	case MULTISTEPDRILLING:
		return new SiemensMultistepDrilling(this);

	case SLOT:
		return new SiemensSlot(this);
		

	default: 
		{
			OUTPUT_DEBUG_STRING(_T("Creating non-feature Siemens feature-based program\n"));
			DebugBreak();
			return NULL;
		}

	}

	return NULL;
}


CString Seimens840D::GenerateNCHeader()
{
	USES_CONVERSION;
	_nToolChangenum=-1;
	_wm._nBlockNum=_wm._nBlockIncr;  
	CString tmp;
	CString line;
	time_t rawtime;
	time ( &rawtime );

	tmp+=_T("; STEP-NC ISO 14649 NIST Feature-Based  Siemens 840D NC Generator\n");
	tmp.Append(StrFormat(_T("; Generated: %s\n"),A2T(ctime(&rawtime)) )); 

	tmp.AppendFormat(_T(";Workpiece stock size: %.2f x %.2f x %.2f \n"), _vStockExtents.x, _vStockExtents.y, _vStockExtents.z);
	tmp.AppendFormat(_T(";Workpiece area(blank cuboid) \n"));
	tmp.AppendFormat(_T(";Place following code in file: DPWP.INI\n"));
	tmp.AppendFormat(_T(";SIM_WPAREA_XMIN=%d\n"), (long) _vStockOrigin.x);
	tmp.AppendFormat(_T(";SIM_WPAREA_XMAX=%d\n"),(long) (_vStockOrigin.x + _vStockExtents.x) );
	tmp.AppendFormat(_T(";SIM_WPAREA_YMIN=%d\n"), (long) (_vStockOrigin.y));
	tmp.AppendFormat(_T(";SIM_WPAREA_YMAX=%d\n"), (long) (_vStockOrigin.y + _vStockExtents.y));
	tmp.AppendFormat(_T(";SIM_WPAREA_ZMIN=%d\n"), (long) ( _vStockOrigin.z));
	tmp.AppendFormat(_T(";SIM_WPAREA_ZMAX=%d\n"), (long) ( _vStockOrigin.z + _vStockExtents.z));

	for(int i=0; i< _toollist.size(); i++)
	{
		tmp+=PostBlock(PostToolDefinition(i+1,1));

	}

	line.AppendFormat(_T(";\n;\nG17")); // G17=xyplane
	line.AppendFormat(_T(" G90")); //  G90 absolute distance ,  
	line.AppendFormat(_T(" G54")); // G54 use preset work coordinate system 1,
	line.AppendFormat(_T(" G94\n")); // G94 units per minute feed rate mode 
	tmp+=PostBlock(line);
	return tmp;
}
CString Seimens840D::GenerateNCProgram()
{

	CString tmp;
	std::vector<IWorkCyclePtr> & _commands=*this;
	std::vector<CString> errors;
	_opnum=0;
	for(int i=0; i< _commands.size(); i++)
	{
		//if(FAILED(_commands[i]->Verify(errors)))
		//{
		//	for(int j=0; j<errors.size(); j++)
		//	{
		//		OUTPUT_DEBUG_STRING(StrFormat(_T("Error in command %s: %s\n"), _commands[i]->GetName(), errors[j]));
		//	}

		//}
		OutputDebugString(_commands[i]->GetComment());
		tmp+=_commands[i]->ToGCode(0);

	}
	tmp+=PostBlock(_T("M30\n"));
	return tmp;
}


HRESULT Seimens840D::ParseStepNC(IStepNodePtr gProject, CStringVector &errors)
{
	int i;
	CString szFeatureId;

	if(gProject==NULL)
	{
		errors.push_back(_T("STEPC Project empty\n"));
		return E_FAIL;
	}

	IWorkCyclesPtr program = this;

	INodeListPtr its_elements= gProject->GetAttributeNodeList(_bstr_t(L"/main_workplan/its_elements"));
	INodeListPtr its_workpieces =	gProject->GetAttributeNodeList(_bstr_t(L"/its_workpieces"));
	int n = its_elements->size();
	int m = its_workpieces->size();
	// workpieces
	for(i=0; i<m; i++)
	{
		IStepNodePtr workpiece=gProject->SelectNode(bstrFormat(_T("/its_workpieces[%d]"), i));
		Vector location;	// position workpiece based? who defined.

		if(!workpiece) 
			continue;
		dTolerance=  workpiece->GetAttributeValue(_bstr_t(L"global_tolerance"), _variant_t(-1.0));
		szStandardMaterialId= workpiece->GetAttributeValue(_bstr_t(L"its_material/standard_identifier"), _variant_t(L"No Standard Material Id given"));
		szMaterialId= workpiece->GetAttributeValue(_bstr_t(L"its_material/material_identifier"), _variant_t(L"No Standard Material Id given"));

	
		if(workpiece->DoesPathExist(_bstr_t(L"its_bounding_geometry"))==VARIANT_FALSE)
			continue;

		// GetAttributeClassname will create bounding geometry if doesn't exist as select
		CString szStockClassname  = (LPCTSTR) workpiece->GetAttributeClassname( _bstr_t(L"its_bounding_geometry"));
		szStockClassname.MakeLower(); 

		if(szStockClassname == "block")
		{
			Vector location= FromComVector( workpiece->ToVector(_bstr_t(L"its_bounding_geometry/position/location/coordinates"))); 
			double dXExtent, dYExtent, dZExtent;

			dXExtent= (double) workpiece->GetAttributeValue(_bstr_t(L"its_bounding_geometry/x"), _variant_t((double) 0.0));
			dYExtent= (double) workpiece->GetAttributeValue(_bstr_t(L"its_bounding_geometry/y"), _variant_t((double) 0.0));
			dZExtent= (double) workpiece->GetAttributeValue(_bstr_t(L"its_bounding_geometry/z"), _variant_t((double) 0.0));

			//OutputDebugString(StrFormat(_T("Stocks %s Extents X(%.3f) Y(%.3f) Z(%.3f)\n"), location.ToString(), dXExtent, dYExtent, dZExtent));
			program->StockDefinition(IWorkCycles::BLOCK, _T(" "),location, Vector(dXExtent, dYExtent, dZExtent));
		}
		else if(szStockClassname == _T("right_circular_cylinder"))
		{

		}
		else
		{

		}
	}


	// elements
	for(i=0; i< n; i++)
	{
		IStepNodePtr pFeature;
		CStringVector row;
		CVarDefPtr vardef;
		_variant_t var;
		CString szOps;
		CString szComment;
		//CString szOperationLabel;
		//CString sExecuteClassname ;
		CString szFeatureClassname;
		CString szOperationClass;		// demangled classname of machining operation
		CString szToolClassname;		// classname of tool

		IStepNodePtr pExecutable  = gProject->SelectNode(bstrFormat(_T("/main_workplan/its_elements[%d]"), i));
		CString szExecutableClassname = CString((LPCTSTR) pExecutable->Classname).MakeLower();

		if(szExecutableClassname ==_T("load_tool"))
		{
#if 0

			IWorkCyclePtr loadtool = program->CreateFeature(IWorkCycles::LOADTOOL).get();// FaceMill(gWm);
			row.push_back(szExecutableClassname);
			if(FAILED(loadtool->DeriveParameters(pExecutable, pExecutable,  NULL)))
			{
				errors.push_back(StrFormat(_T("Error:  LoadTool DeriveParameters\n%s\n"), ToString(loadtool->Errors(),_T(""))));
				continue;
			}
			program->AddCommand(loadtool);
#endif
			continue;
		}


		// feature classname,  planar_face, hole, etc.
		pFeature = pExecutable->SelectNode(bstrFormat(_T("its_feature"), i));
		szFeatureClassname=CString((LPCTSTR) pFeature->Classname).MakeLower(); 

		if(!pFeature)
		{
			pFeature = gProject->SelectNode(bstrFormat(_T("/main_workplan/its_elements[%d]"), i));
	
			errors.push_back(StrFormat(_T("Feature Based machining - not handling %s element\n"), pFeature->Classname));
			continue;

		}

		///////////////////////////////////////////////////////////////////
		// process workingstep operation
		///////////////////////////////////////////////////////////////////
		IStepNodePtr pOpItem = gProject->SelectNode(bstrFormat(_T("/main_workplan/its_elements[%d]/its_operation"), i));
		if(pOpItem==NULL)
		{
			errors.push_back(StrFormat(_T("cast <Emachining_operation>(pOpItem) Failed\n")));
			continue;
		}

		// machining operation classname,  plane_rough_milling, drilling, etc.
		szOperationClass = CString((LPCTSTR) pOpItem->Classname).MakeLower() ; 

		// operation is kinda immaterial of feature...
		if(szOperationClass==_T("plane_rough_milling") || szOperationClass==_T("plane_finish_milling"))
		{
			IWorkCyclePtr facemill = program->CreateFeature(IWorkCycles::FACEMILL).get();// FaceMill(gWm);
			if(FAILED(facemill->DeriveParameters(pExecutable, pFeature, pOpItem)))
			{
				errors.push_back(StrFormat(_T("Failed  Facemill DeriveParameters\n")));
				continue;
			}

			program->AddCommand(facemill);

		}
		// type of drillling_operation
		else if(pOpItem->IsKindOf(_T("Edrilling_type_operation")))
		{ 
			if(szOperationClass==_T("drilling_operation") 
				|| szOperationClass==_T("drilling") 
				|| szOperationClass==_T("center_drilling")
				|| szOperationClass==_T("counter_sinking"))
			{
				IWorkCyclePtr drilling = program->CreateFeature(IWorkCycles::DRILLCENTERING).get();// FaceMill(gWm);
				if(FAILED(drilling->DeriveParameters(pExecutable, pFeature, pOpItem)))
				{
					errors.push_back(StrFormat(_T("Failed  Drilling DeriveParameters\n")));
					continue;
				}

				// Would help to have tool length to make sure depth is achievable
				program->AddCommand(drilling);

			}
			else if(szOperationClass==_T("reaming"))
			{
				IWorkCyclePtr reaming =program->CreateFeature(IWorkCycles::REAMING).get();// FaceMill(gWm);
				if(FAILED(reaming->DeriveParameters(pExecutable, pFeature, pOpItem)))
				{
					errors.push_back(StrFormat(_T("Failed  Reaming DeriveParameters\n")));
					continue;
				}
				// Would help to have tool length to make sure depth is achievable
				program->AddCommand(reaming);
			}
			else if(szOperationClass==_T("multistep_drilling"))
			{
				IWorkCyclePtr drilling =program->CreateFeature(IWorkCycles::MULTISTEPDRILLING).get();// FaceMill(gWm);
				if(FAILED(drilling->DeriveParameters(pExecutable, pFeature, pOpItem)))
				{
					errors.push_back(StrFormat(_T("Failed  Multistep Drilling DeriveParameters\n")));
					continue;
				}
				// Would help to have tool length to make sure depth is achievable
				program->AddCommand(drilling);


			}
			else if(szOperationClass==_T("boring"))
			{
				DebugBreak();


			}

			else if(szOperationClass==_T("back_boring"))
			{

				DebugBreak();

			}
			else if(szOperationClass==_T("tapping"))
			{

				DebugBreak();

			}
			else if(szOperationClass==_T("thread_drilling"))
			{

				DebugBreak();

			}
		}
		// not operation based, try feature for pocket...  distinguish by fcn[feature,op]
		else if(szFeatureClassname==_T("closed_pocket")  || szFeatureClassname==_T("open_pocket"))
		{
			IWorkCyclePtr ncppPocket;

			CString szProfileType = (LPCTSTR) pFeature->GetAttributeClassname(_bstr_t(L"feature_boundary"));
			szProfileType.MakeLower();
			if(szProfileType==_T("rectangular_closed_profile"))
			{
				ncppPocket = program->CreateFeature(IWorkCycles::POCKETRECTANGULAR);
				ncppPocket->DeriveParameters(pExecutable, pFeature,  pOpItem);
				program->AddCommand(ncppPocket);
			}
			else if(szProfileType==_T("general_closed_profile"))
			{
				ncppPocket = program->CreateFeature(IWorkCycles::CONTOURPOCKET);
				ncppPocket->DeriveParameters(pExecutable, pFeature,  pOpItem);
				program->AddCommand(ncppPocket);

			}

		}		
		else 
		{


		}
	}

	return 0;
}



int SiemensTool::DeriveToolParameters(IWorkCyclesPtr _parent, CCannedCycleItems * pItems, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	int _toolnum;
//	T * mySuper = (T*) this;;
	pItems->SetVariable(_T("ToolOffsetNumber"), 1) ;  //  Tool D Number
	pItems->SetVariable(_T("ToolTypeNumber"), Seimens840D::GetToolNumber(pItems->GetValue<tstring>(_T("Tooltype")).c_str())) ;
	pItems->SetVariable(_T("Toolradius"), pItems->GetValue<double>(_T("Tooldiameter")) / 2.0) ;

	// sanity check because same tool radius and corner radius would seem to be ok...
	if(pItems->FindItem(_T("CornerRadius")))
	{
		//mySuper->errmsgs.push_back(StrFormat(_T("Sanity Check fix: Toolradius >= CornerRadius\n")));

		if(pItems->GetValue<double>(_T("Toolradius"))<=pItems->GetValue<double>(_T("CornerRadius")))
			pItems->SetVariable(_T("Toolradius"), (double) pItems->GetValue<double>(_T("CornerRadius")) - 0.5) ;
	}


	int n = pItems->GetValue<long>(_T("ToolTypeNumber"));
	_toolnum= _parent->LookupTool(pItems->GetValue<long>(_T("ToolTypeNumber")),
		pItems->GetValue<double>(_T("Toollength")),
		pItems->GetValue<double>(_T("Toolradius")),
		0);
	pItems->SetVariable(_T("ToolNumber"),(long) _toolnum) ;

	return _toolnum;
}