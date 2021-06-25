#include "StdAfx.h"
#include "Mastercam/Mastercam.h"
#define _USE_MATH_DEFINES 
#include <math.h>
#include "MastercamContourPocket.h"
#include "QueryPath.h"

#include <boost/serialization/string.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>


template <typename T> inline T GetXmlValue(MSXML2::IXMLDOMElementPtr  node, LPCTSTR item, T tDefault)
{
	MSXML2::IXMLDOMElementPtr  subnode= node->selectSingleNode( item);
	T t = tDefault;
	if(subnode==NULL)
		return t;
	_bstr_t bstrText = subnode->text;
	try {
		t =  (T)  _variant_t(bstrText);
	}catch(...)
	{
		return t;
	}
	return t;
}
//
//class random_xml_iarchive 
//{
//public:
//	MSXML2::IXMLDOMElementPtr  node;
//
//// special treatment for name-value pairs.
//template<class T>
//random_xml_iarchive & operator&(const boost::serialization::nvp & t)
//{
//    // write an xml start tag
//    start_tag(t.name());
//
//    // serialize the data as usual
//    *this & t.value();
//
//    // write an xml end tag
//    end_tag(t.name());
//}
//
//};



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

Mastercam::Mastercam(CWorldModel &wm): IWorkCycles(wm) 
{
	_dLengthConversion=1.0;
	_nToolChangenum=-1;
}
long Mastercam::GetToolNumber(CString toolname)
{
	ToolMap::iterator it;
	if((it=ToolSymbols.find(toolname))!= ToolSymbols.end())
		return (*it).second;
	return -1; 

}
Mastercam::~Mastercam(void)
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

int  Mastercam::LookupTool(int type, double length, double radius, double cornerradius)
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
CString Mastercam::PostToolDefinition(int toolnum, int tooledge)
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
CString Mastercam::PostToolChange(int toolnum)
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
CString Mastercam::SpindleCommand(double spindlespeed)
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
IWorkCyclePtr Mastercam::CreateFeature(CANON_FEATURE eType)
{ 

	switch(eType)
	{
	case CONTOURPOCKET:
		return new MastercamContourPocket(this);
#if 0
	case FACEMILL:
		return new SiemensFaceMill(this, _wm);
	case POCKETRECTANGULAR:
		return new SiemensRectangularPocket(this,_wm);
	case DRILLCENTERING:
		return new SiemensCenterDrilling(this, _wm);
	case POCKETCIRCULAR:
		return new SiemensCircularPocket(this, _wm);
	case REAMING:
		return new SiemensReaming(this, _wm);

	case LOADTOOL:
		return new SiememsLoadTool(this, _wm);
		
	case MULTISTEPDRILLING:
		return new SiemensMultistepDrilling(this, _wm);

	case SLOT:
		return new SiemensSlot(this, _wm);
#endif
	default: 
		{
			OUTPUT_DEBUG_STRING(_T("Creating non-feature mastercam feature-based program\n"));
			DebugBreak();
			return NULL;
		}

	}

	return NULL;
}


CString Mastercam::GenerateNCHeader()
{
	_nToolChangenum=-1;
	_wm._nBlockNum=_wm._nBlockIncr;  
	CString tmp;
	CString line;
	time_t rawtime;
	time ( &rawtime );

	tmp+=_T("; STEP-NC ISO 14649 NIST Feature-Based  Siemens 840D NC Generator\n");
	tmp.Append(StrFormat(_T("; Generated: %s\n"),ctime(&rawtime) )); 

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
CString Mastercam::GenerateNCProgram()
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






int Mastercam::ParseMasterCamToolsXML(CString xmlstring)
{

	CQueryPath xml;
	xml.Read(xmlstring);
	MSXML2::IXMLDOMElementPtr  subnode =  xml.QueryNode(_T("Tools")); // node->selectSingleNode((LPCTSTR) name);
	if(subnode==NULL)
		return 0;
	MSXML2::IXMLDOMNodeListPtr  subnodes= subnode->selectNodes((LPCTSTR) StrFormat(_T("Tool")));
	for(int i=0; i<subnodes->Getlength(); i++)
	{
		CVarDefPtr subvardef;
		MSXML2::IXMLDOMNodePtr item = subnodes->Getitem(i);
		MastercamTool tool;
		tool. _nNumber=  GetXmlValue<int>(item, _T("Number"),0);
		tool. _nType=  GetXmlValue<int>(item, _T("Type"),0);
		tool._nRadiustype=  GetXmlValue<int>(item, _T("RadiusType"),0);
		tool._dDiameter=  GetXmlValue<double>(item, _T("Diameter"),0);
		tool._dCornerradius=  GetXmlValue<double>(item, _T("Cornerradius"),0);
		tool._dThreadsperinch=  GetXmlValue<double>(item, _T("Threadsperinch"),0);
		tool._dTipangle=  GetXmlValue<double>(item, _T("Tipangle"),0);
		tool. _dDiameterOffsetNumber=  GetXmlValue<double>(item, _T("DiameterOffsetNumber"),0);
		tool._nLengthOffsetNumber=  GetXmlValue<int>(item, _T("LengthOffsetNumber"),0);
		tool. _dFeedrate=  GetXmlValue<double>(item, _T("Feedrate"),0);
		tool. _dPlungerate=  GetXmlValue<double>(item, _T("Plungerate"),0);
		tool. _dRetractrate=  GetXmlValue<double>(item, _T("Retractrate"),0);
		tool. _dSpindleSpeed=  GetXmlValue<double>(item, _T("SpindleSpeed"),0);
		tool._bUse_css=  GetXmlValue<int>(item, _T("Use_css"),0);
		tool._bFeedisSurfaceFinish=  GetXmlValue<int>(item, _T("FeedisSurfaceFinish"),0);
		tool._bPlungeisSurfaceFinish=  GetXmlValue<int>(item, _T("PlungeisSurfaceFinish"),0);
		tool._nCoolant=  GetXmlValue<int>(item, _T("Coolant"),0);
		tool._nNumberFlutes=  GetXmlValue<int>(item, _T("NumberFlutes"),0);
		tool._sComment= (LPCTSTR) GetXmlValue<_bstr_t>(item, _T("Comment"),_T(""));
		tool._bMetric=  GetXmlValue<int>(item, _T("Metric"),0);
		tool._nSlot=  GetXmlValue<int>(item, _T("Slot"),0);
		tool._dPilotDiameter=  GetXmlValue<double>(item, _T("PilotDiameter"),0);
		tool._dFluteLength=  GetXmlValue<double>(item, _T("FluteLength"),0);
		tool._dOverallLength=  GetXmlValue<double>(item, _T("OverallLength"),0);
		tool._dShoulderLength=  GetXmlValue<double>(item, _T("ShoulderLength"),0);
		tool._dArborDiameter=  GetXmlValue<double>(item, _T("ArborDiameter"),0);
		tool._dHolderDiameter=  GetXmlValue<double>(item, _T("HolderDiameter"),0);
		tool._dSpindleRot=  GetXmlValue<double>(item, _T("SpindleRot"),0);
		tool._dFpPercentToolRev=  GetXmlValue<double>(item, _T("FpPercentToolRev"),0);
		tool._nManufacturerToolCode=  GetXmlValue<int>(item, _T("ManufacturerToolCod"),0);
		tools.push_back(tool);

	}
	return true;

}

void Mastercam::ParseMasterCamXML(CString xmlfilename)
{
	MSXML2::IXMLDOMNodePtr pOperation;
	querypath.Open(xmlfilename);

	CString stocksize = querypath.QueryValue(_T("/PROJECT/Setup/StockSize"), _T("-1,-1,-1"));
	CString materialId = querypath.QueryValue(_T("/PROJECT/Setup/MaterialName"),_T(""));

	//DefineBlockWorkpiece(_T("Workpiece1"), DVal(stocksize, 0, " "), DVal(stocksize, 1, " "), DVal(stocksize, 2, " "),  _T(""), materialId);

	int n = querypath.QuerySize(_T("/PROJECT/Operations"));


	// derive tools


	for(int i=0; i< n; i++)
	{
		CString szOperationPath = StrFormat(_T("/PROJECT/Operations/Operation[%d]"), i+1);
		CString sztype = querypath.QueryValue(szOperationPath+_T("/Type"), StrFormat(_T("No operation %d type"), i+1));
		if(sztype==_T("TP_POCKET"))
		{
			IWorkCyclePtr ncppPocket;
			ncppPocket = CreateFeature(IWorkCycles::CONTOURPOCKET);
			CCannedCycleItems * items = ncppPocket->GetXMLMap();
			pOperation=querypath.QueryNode(szOperationPath);
			items->ExtractXml(pOperation);
			OutputDebugString(items->ToString());

#if 0
			items->SetVariable(_T("RetractPlane"), (LPCTSTR) querypath.QueryValue(StrFormat(_T("/PROJECT/Operations/Operation[%d]/OpCommon/RetractPlane"), i+1) , _T(""))) ;
			items->SetVariable(_T("SafetyPlane"), 2.0) ;
			items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
			items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;

			items->SetVariable(_T("Toolradius"), items->GetValue<double>(_T("Tooldiameter")) / 2.0) ;

#endif
			AddCommand(ncppPocket);
		}
	}

}

