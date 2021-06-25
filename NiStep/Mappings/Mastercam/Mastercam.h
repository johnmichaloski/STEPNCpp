//
// Mastercam.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#pragma once
#include "FeatureCycles.h"
#include "boost/tuple/tuple.hpp"
#include "QueryPath.h"
#include <boost/config.hpp> 
#include <boost/archive/binary_oarchive.hpp> 
#include <boost/archive/binary_iarchive.hpp> 
#include <boost/serialization/map.hpp> 
#include <boost/serialization/string.hpp> 

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/detail/common_iarchive.hpp>
class Mastercam;

class MastercamTool
{
public:
	int  _nNumber;
	int  _nType;
	int _nRadiustype;
	double _dDiameter;
	double _dCornerradius;
	double _dThreadsperinch;
	double _dTipangle;
	double  _dDiameterOffsetNumber;
	int _nLengthOffsetNumber;
	double  _dFeedrate;
	double  _dPlungerate;
	double  _dRetractrate;
	double  _dSpindleSpeed;
	int _bUse_css;
	int _bFeedisSurfaceFinish;
	int _bPlungeisSurfaceFinish;
	int _nCoolant;
	int _nNumberFlutes;
	std::wstring _sComment;
	int _bMetric;
	int _nSlot;
	double _dPilotDiameter;
	double _dFluteLength;
	double _dOverallLength;
	double _dShoulderLength;
	double _dArborDiameter;
	double _dHolderDiameter;
	double _dSpindleRot;
	double _dFpPercentToolRev;
	long _nManufacturerToolCode;

	MastercamTool() {}
};

namespace boost {
	namespace serialization {


		template<class archive>
		inline void serialize(archive& ar, MastercamTool & t, const unsigned int version)
		{
			using boost::serialization::make_nvp;
			ar & make_nvp("Number", t._nNumber);
			ar & make_nvp("Type", t._nType);
			ar & make_nvp("RadiusType", t._nRadiustype);
			ar & make_nvp("Diameter", t._dDiameter);
			ar & make_nvp("CornerRadius", t._dCornerradius);
			ar & make_nvp("ThreadsPerInch", t._dThreadsperinch);
			ar & make_nvp("TipAngle", t._dTipangle);
			ar & make_nvp("DiameterOffsetNumber", t._dDiameterOffsetNumber);
			ar & make_nvp("LengthOffsetNumber", t._nLengthOffsetNumber);
			ar & make_nvp("Feedrate", t._dFeedrate);
			ar & make_nvp("Plungerate", t._dPlungerate);
			ar & make_nvp("Retractrate", t._dRetractrate);
			ar & make_nvp("SpindleSpeed", t._dSpindleSpeed);
			ar & make_nvp("FeedisSurfaceFinish", t._bFeedisSurfaceFinish);
			ar & make_nvp("PlungeisSurfaceFinish", t._bPlungeisSurfaceFinish);
			ar & make_nvp("Coolant", t._nCoolant);
			ar & make_nvp("NumberFlutes", t._nNumberFlutes);
			ar & make_nvp("Comment", t._sComment);
			ar & make_nvp("Metric", t._bMetric);
			ar & make_nvp("Slot", t._nSlot);
			ar & make_nvp("PilotDiameter", t._dPilotDiameter);
			ar & make_nvp("FluteLength", t._dFluteLength);
			ar & make_nvp("OverallLength", t._dOverallLength);
			ar & make_nvp("ShoulderLength", t._dShoulderLength);
			ar & make_nvp("ArborDiameter", t._dArborDiameter);
			ar & make_nvp("HolderDiameter", t._dHolderDiameter);
			ar & make_nvp("SpindleRot", t._dSpindleRot);
			ar & make_nvp("FpPercentToolRev", t._dFpPercentToolRev);
			ar & make_nvp("ManufacturerToolCode", t._nManufacturerToolCode);
		}
	}
}

template<typename T>
class MastercamTooling  : 
	public T
{
public:
	MastercamTooling(IWorkCycles * owner) :T(owner)
	{
		_parent=owner;
		MastercamTooling::InitMastercamItems(this);
		MastercamTooling::InitTests(this);
	}

	virtual ~MastercamTooling(){}
	FEATURECLASSDEF(MastercamTooling);  // prevents copy constructors

	int DeriveToolParameters(IStepNodePtr pFeature, IStepNodePtr pOpItem);

	BEGIN_XML_PARAMETER_MAP(MastercamTooling)

		STEPNC_XML_ENTRY(_T("ToolNumber"),				Cycle::Operation,	Cycle::Length,		_T("ToolInfo/Number"))
		STEPNC_XML_ENTRY(_T("ToolTypeNumber"),			Cycle::Operation,	Cycle::Length,		_T("ToolInfo/Type"))
		STEPNC_XML_ENTRY(_T("ToolLengthOffsetNumber"),	Cycle::Operation,	Cycle::Long,		_T("ToolInfo/LengthOffsetNumber"))  // 
		STEPNC_XML_ENTRY(_T("ToolDiameterOffsetNumber"),Cycle::Operation,	Cycle::Long,		_T("ToolInfo/DiameterOffsetNumber"))  // D number
		STEPNC_XML_ENTRY(_T("ToolDiameter"),			Cycle::Operation,	Cycle::Length,		_T("ToolInfo/Diameter"))
		//STEPNC_XML_ENTRY(_T("Toolname"),				Cycle::Operation,	Cycle::String,		_T("its_tool/its_tool_body"))
		//STEPNC_XML_ENTRY(_T("Toollength"),				Cycle::Operation,	Cycle::Length,		_T("its_tool/its_cutting_edge[0]/tool_offset_length"))
		//STEPNC_XML_ENTRY(_T("ToolAngleTorus"),			Cycle::Operation,	Cycle::Double,		_T("ToolInfo/TipAngle"))
		//STEPNC_XML_ENTRY(_T("ToolCornerRadius"),		Cycle::Operation,	Cycle::Length,		_T("ToolInfo/CornerRadius"))
		//STEPNC_XML_ENTRY(_T("ToolRadius"),				Cycle::Compute,		Cycle::Length,		_T("ToolDiameter/2.0;"))


	END_XML_PARAMETER_MAP(MastercamTooling)



	BEGIN_VERIFY_PARAMETER_MAP(MastercamTooling)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius <= 0.0") , _T(""))

	END_VERIFY_PARAMETER_MAP(MastercamTooling)

};
class MastercamToolCatalog 
{
public:
	std::vector<MastercamTool> tools;
	template<class archive>
	inline void save(archive& ar,  const unsigned int version) const
	{
		using boost::serialization::make_nvp;
		for(int i=0; i< tools.size(); i++)
			ar << make_nvp("Tool", tools[i]);
	}
	template<class archive>
	inline void load(archive& ar,  const unsigned int version)
	{
		using boost::serialization::make_nvp;
		bool bFlag=true;
		for(int i=0; bFlag; i++)
		{
			try{
				tools.push_back(MastercamTool());
				ar >> make_nvp("Tool", tools[i]);
			}
			catch(...)
			{
				tools.pop_back();
				bFlag=false;
			}
		}
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER() ;
};


class Mastercam : 
	public IWorkCycles, 
	public MastercamToolCatalog
{
public:
	Mastercam(CWorldModel &wm);
	virtual ~Mastercam(void);

	// input step nc tool class name, return matching tool number
	// FIXME: No handling of edge data yet.
	static long GetToolNumber(CString toolname);

	// Feature defining helpers
	virtual void NewWorkingStep(){}
	virtual IWorkCyclePtr CreateFeature(CANON_FEATURE eType);

	// Program helpers
	virtual CString GenerateNCProgram();
	virtual CString GenerateNCHeader();
	virtual CString SpindleCommand(double spindlespeed);
	virtual CString PostToolDefinition(int toolnum, int tooledge=1);
	CString PostToolChange(int toolnum);

	virtual int  LookupTool(int type, double length, double radius, double cornerradius);
	void ParseMasterCamXML(CString xmlfilename);
	int ParseMasterCamToolsXML(CString xmlstring);

	typedef boost::tuple<int, double, double, double> ToolingTuple; 
	std::vector<ToolingTuple> _toollist;
	double _dLengthConversion;
	double _dSpeedConversion;
	int _nToolChangenum;

	IStepNodePtr _project;
	CQueryPath querypath;
	std::vector<MastercamTool> tools;

};
FEATURE_DECLARE_SMARTPOINTER(Mastercam);

template<typename T>
inline int MastercamTooling<T>::DeriveToolParameters(IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	int _toolnum;
	T * mySuper = (T*) this;;
	items.SetVariable(_T("ToolOffsetNumber"), 1) ;  //  Tool D Number
	items.SetVariable(_T("ToolTypeNumber"), Mastercam::GetToolNumber(items.GetValue<tstring>(_T("Tooltype")).c_str())) ;
	items.SetVariable(_T("Toolradius"), items.GetValue<double>(_T("Tooldiameter")) / 2.0) ;

	// sanity check because same tool radius and corner radius would seem to be ok...
	if(items.FindItem(_T("CornerRadius")))
	{
		mySuper->errmsgs.push_back(StrFormat(_T("Sanity Check fix: Toolradius >= CornerRadius\n")));

		if(items.GetValue<double>(_T("Toolradius"))<=items.GetValue<double>(_T("CornerRadius")))
			items.SetVariable(_T("Toolradius"), (double) items.GetValue<double>(_T("CornerRadius")) - 0.5) ;
	}


	_toolnum= _parent->LookupTool(items.GetValue<long>(_T("ToolTypeNumber")),
		items.GetValue<double>(_T("Toollength")),
		items.GetValue<double>(_T("Toolradius")),
		0);
	items.SetVariable(_T("ToolNumber"),(long) _toolnum) ;

	return _toolnum;

}