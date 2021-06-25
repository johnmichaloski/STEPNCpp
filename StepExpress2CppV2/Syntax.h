#pragma once


//#define BOOST_SPIRIT_DEBUG

#include <map>
//#include <boost/regex.hpp>
//#include <boost/archive/xml_oarchive.hpp>
#include <boost/spirit.hpp>
#include <boost/version.hpp>
#include <boost/spirit/core.hpp>

#if BOOST_VERSION <= 103200
#define BOOST_SPIRIT_NO_REGEX_LIB
#endif

#include <boost/spirit/tree/parse_tree.hpp>
#include <boost/spirit/tree/ast.hpp>

#include <iostream>
#include <stack>
#include <functional>
#include <string>

//#ifdef BOOST_SPIRIT_DUMP_PARSETREE_AS_XML
#include <boost/spirit/tree/tree_to_xml.hpp>

#include "comdef.h"

using namespace std;
using namespace boost;
using namespace boost::spirit;

extern void ParseIt();
extern stack<long> evaluation_stack;
extern stack<_variant_t> variant_stack;
TypeNode const char * IteratorT; //Obviously, this should be whatever iterator you're using for your spirit parser

struct reporter
{
	reporter(const std::string & errorMessage):_errorMsg(errorMessage) {}
	void operator()(const IteratorT &, const IteratorT &) const
	{
		std::cout << "ERROR:\t" << _errorMsg;
		OutputDebugString(_errorMsg.c_str());
	}
private:
	std::string _errorMsg;
};

struct push_it
{
	void operator()(char const* str, char const*) const
	{
		variant_stack.push(_variant_t((char  const*) str));
	}
};

struct push_int
{
	void operator()(char const* str, char const*) const
	{
		long n = std::strtol(str, 0, 10);
		evaluation_stack.push(n);
	}
};

template <class op>
struct do_op
{
	do_op(op const& the_op) : m_op(the_op) {}
	op m_op;

	void operator()(char const*, char const*) const
	{
		long rhs = evaluation_stack.top();
		evaluation_stack.pop();
		long lhs = evaluation_stack.top();
		evaluation_stack.pop();
		evaluation_stack.push(m_op(lhs, rhs));
	}
};

template <class op>
do_op<op> make_op(op const& the_op)
{
	return do_op<op>(the_op);
}

struct do_negate
{
	void operator()(char const*, char const*) const
	{
		long lhs = evaluation_stack.top();
		evaluation_stack.pop();
		evaluation_stack.push(-lhs);
	}
};
inline void write(char const *begin, char const *end)
{
	std::string str(begin, end );
	//OutputDebugString( str.c_str());
}


struct CSyntax:
	public boost::spirit::grammar<CSyntax>
{
	CSyntax() {}
	virtual ~CSyntax(){}
	template <typename ScannerT>
	struct definition
	{
	public:
		symbols<> sym;
		rule<ScannerT> STRING_LITERAL, dblquoted_string;
		rule<ScannerT> expression, cmd_num, event_num, cmd, eventcmd, voidcommand, stringcommand;
		rule<ScannerT> tool_prop, tool_prop_enum, tool_prop_item;
		rule<ScannerT> part_prop_item, part_prop_enum;
		rule<ScannerT> axis_pos, axis_prop_item, axis_getprop, axis_setprop, axis_getprop_list, axis_setprop_list;
		rule<ScannerT> goto_field, gotopar_enum, gotopar_block, gotopar_item, gotocmd,  gotocmd_item;
		rule<ScannerT> tool_get, get_list;
		rule<ScannerT> ptmeaspar_enum, ptmeas_block, ptmeaspar_item, ptmeas_list;
		rule<ScannerT> csytransformation, coordsystem, lock_position_prop_item, lock_position_prop_get_list,  lock_axis_prop_item, lock_axis_prop_get_list;
		rule<ScannerT> enum_prop_list,  getprop_list, setprop_list;
		rule<ScannerT> on_move_report_list, on_ptmeas_report_item, on_ptmeas_report_list;
		symbols<>voidcommands, stringcommands, csytransformations, coordsystems, ptmeas_props, 
			prop_fields, part_props, tool_props, goto_props,	ptmeasselfcenter_props;
		const boost::spirit::rule<ScannerT> &start() const { return expression; }

		enum { AlignPartID=1, AlignToolID, CenterPartID, EnumAllPropID, EnumPropID, GoToID,
		GetID, GetCsyTransformationID, GetErrorInfoID, GetPropID, LockAxisID, LockPositionID, PtMeasID , PtMeasSelfCenterLockedID,
		OnPtMeasReportID, OnScanReportID,  ScanOnCircleHintID, ScanOnLineHintID, ScanOnCurveHintID,
		ScanUnknownHintID, ScanOnCircleID, ScanOnLineID, ScanInPlaneEndIsSphereID, ScanInPlaneEndIsPlaneID,
		ScanInPlaneEndIsCylID, ScanInCylEndIsSphereID, ScanInCylEndIsPlaneID, ScanOnCurveDensityID, 
		ScanOnCurveID, SetCoordSystemID, SaveNamedCsyTransformationID, SetCsyTransformationID, 
		SetPropID, StopDaemonID, TiltCenterPartID, TiltPartID};

		rule<ScannerT, parser_context<>, parser_tag<AlignPartID> > AlignPart;
		rule<ScannerT, parser_context<>, parser_tag<AlignToolID> > AlignTool;
		rule<ScannerT, parser_context<>, parser_tag<CenterPartID> > CenterPart;
		rule<ScannerT, parser_context<>, parser_tag<EnumAllPropID> > EnumAllProp;
		rule<ScannerT, parser_context<>, parser_tag<EnumPropID> > EnumProp;
		rule<ScannerT, parser_context<>, parser_tag<GoToID> > GoTo;
		rule<ScannerT, parser_context<>, parser_tag<GetID> > Get;
		rule<ScannerT, parser_context<>, parser_tag<GetCsyTransformationID> > GetCsyTransformation;
		rule<ScannerT, parser_context<>, parser_tag<GetErrorInfoID> > GetErrorInfo;
		rule<ScannerT, parser_context<>, parser_tag<GetPropID> > GetProp;
		rule<ScannerT, parser_context<>, parser_tag<LockAxisID> > LockAxis;
		rule<ScannerT, parser_context<>, parser_tag<LockPositionID> > LockPosition;
		rule<ScannerT, parser_context<>, parser_tag<PtMeasID> > PtMeas;
		rule<ScannerT, parser_context<>, parser_tag<PtMeasSelfCenterLockedID> > PtMeasSelfCenterLocked;
		rule<ScannerT, parser_context<>, parser_tag<OnPtMeasReportID> > OnPtMeasReport;
		rule<ScannerT, parser_context<>, parser_tag<OnScanReportID> > OnScanReport;

		

		rule<ScannerT, parser_context<>, parser_tag<ScanOnCircleHintID> > ScanOnCircleHint;
		rule<ScannerT, parser_context<>, parser_tag<ScanOnLineHintID> > ScanOnLineHint;
		rule<ScannerT, parser_context<>, parser_tag<ScanOnCurveHintID> > ScanOnCurveHint;
		rule<ScannerT, parser_context<>, parser_tag<ScanUnknownHintID> > ScanUnknownHint;
		rule<ScannerT, parser_context<>, parser_tag<ScanOnCircleID> > ScanOnCircle;
		rule<ScannerT, parser_context<>, parser_tag<ScanOnLineID> > ScanOnLine;
		rule<ScannerT, parser_context<>, parser_tag<ScanInPlaneEndIsSphereID> > ScanInPlaneEndIsSphere;
		rule<ScannerT, parser_context<>, parser_tag<ScanInPlaneEndIsPlaneID> > ScanInPlaneEndIsPlane;
		rule<ScannerT, parser_context<>, parser_tag<ScanInPlaneEndIsCylID> > ScanInPlaneEndIsCyl;
		rule<ScannerT, parser_context<>, parser_tag<ScanInCylEndIsSphereID> > ScanInCylEndIsSphere;
		rule<ScannerT, parser_context<>, parser_tag<ScanInCylEndIsPlaneID> > ScanInCylEndIsPlane;
		rule<ScannerT, parser_context<>, parser_tag<ScanOnCurveDensityID> > ScanOnCurveDensity;
		rule<ScannerT, parser_context<>, parser_tag<ScanOnCurveID> > ScanOnCurve;
		rule<ScannerT, parser_context<>, parser_tag<SetCoordSystemID> > SetCoordSystem;
		rule<ScannerT, parser_context<>, parser_tag<SaveNamedCsyTransformationID> > SaveNamedCsyTransformation;
		rule<ScannerT, parser_context<>, parser_tag<SetCsyTransformationID> > SetCsyTransformation;
		rule<ScannerT, parser_context<>, parser_tag<SetPropID> > SetProp;
		rule<ScannerT, parser_context<>, parser_tag<StopDaemonID> > StopDaemon;
		rule<ScannerT, parser_context<>, parser_tag<TiltCenterPartID> > TiltCenterPart;
		rule<ScannerT, parser_context<>, parser_tag<TiltPartID> > TiltPart;

		definition( CSyntax const &self )
		{   

			STRING_LITERAL	 = lexeme_d[ch_p('\"') >> *( strlit<>("\\\"") | anychar_p - ch_p('\"') ) >> ch_p('\"')]; //[&write]
			dblquoted_string	= +STRING_LITERAL;
			cmd_num				= lexeme_d[ ( '0' >>digit_p>>digit_p>>digit_p>>digit_p)[push_int()] ];
			event_num			= lexeme_d[ ( 'E' >>digit_p>>digit_p>>digit_p>>digit_p)[push_int()] ];

			axis_prop_item		= str_p("X") | str_p("Y") | str_p("Z") | str_p("R");
			axis_pos			= str_p("X") | str_p("Y") | str_p("Z") | str_p("IJK");
			axis_getprop		= axis_prop_item >> chseq_p("()");
			axis_setprop		= axis_prop_item >> '(' >> real_p  >> ')';
			axis_getprop_list	= list_p(axis_getprop, ',') ;
			axis_setprop_list	= list_p(axis_setprop, ','); 

			tool_get			= str_p("Tool") >> '.' >>( str_p("A") | str_p("B") | str_p("C") ) >> chseq_p("()");
			get_list			= list_p((axis_getprop | tool_get) , ',');  	;

			gotocmd_item		= axis_setprop_list | str_p("Tool") >> '.' >> axis_setprop;

			csytransformations	= "PartCsy", "JogDisplayCsy",  "JogMoveCsy", "SensorCsy", "MoveableMachineCsy", "MultipleArmCsy";
			coordsystems		= "MachineCsy","MoveableMachineCsy","MultipleArmCsy", "PartCsy"	;
			csytransformation	= csytransformations >> (eps_p - alpha_p) >> *space_p;
			coordsystem			= coordsystems >> (eps_p - alpha_p) >> *space_p;

			prop_fields			= "Min","Max","Act","Def" ;
			goto_props			= "Speed", "Accel";

			gotopar_item		= str_p("GoToPar")  >> ( "." >> goto_props >> !( '.' >> prop_fields));
			gotopar_enum		= str_p("GoToPar")  >> !( "." >> goto_props >> !( '.' >> prop_fields));


			ptmeas_props		= "Speed","Accel","Approach","Search","Retract";
			ptmeas_block		= ptmeas_props >> !( '.' >> prop_fields);

			ptmeaspar_item		= str_p("PtMeasPar") >> ('.' >> ptmeas_block);
			ptmeaspar_enum		= str_p("PtMeasPar") >> !('.' >> ptmeas_block);
			ptmeas_list			= list_p(axis_pos >> '(' >> real_p >> ')'
				| str_p("IJK") >> '(' >> real_p >> ',' >> real_p >> ',' >> real_p >> ')'
				, ',');

			ptmeasselfcenter_props			= "X", "Y", "Z", "IJK", "LMN";
			on_ptmeas_report_item =   (str_p("X") | str_p("Y") | str_p("Z") | str_p("R") | str_p("IJKAct") | str_p("IJK") |   "ER" | "Q") >> chseq_p("()");
			on_ptmeas_report_list =   list_p((tool_get | on_ptmeas_report_item ), ',');
			on_move_report_list = list_p(( tool_get | on_ptmeas_report_item | str_p("Time") >> '(' >> real_p >> ')'  | str_p("Dis") >> '(' >> real_p >> ')') , ',');

			tool_props			= "Name", "Id", "CollisionVolume", "AvrOffset", "Alignment", "AvrRadius", "AlignmentVolume", "Collection";
			tool_prop			= tool_props | ptmeaspar_item | gotopar_item;  

			tool_prop_enum		= (str_p("Tool") | str_p("FoundTool"))  >> !('.' >> (tool_props | ptmeaspar_enum | gotopar_enum)) ;
			tool_prop_item		= (str_p("Tool") | str_p("FoundTool"))  >> ('.' >> (tool_props | ptmeaspar_item | gotopar_item)) ;


			part_props			= "Temperature", "XpanCoefficient", "Approach";
			part_prop_enum		=  str_p("Part") >> !('.'>> part_props);
			part_prop_item		=  str_p("Part") >> '.'>> part_props;

			enum_prop_list		= list_p(( part_prop_enum |  tool_prop_enum)>>  chseq_p("()"), ',');

			getprop_list		= list_p( (tool_prop_item | part_prop_item) >> '(' >> *space_p >> ')' , ',');			
			setprop_list		= list_p( (tool_prop_item | part_prop_item) >> '(' >> real_p   >> ')' , ',');

			// make sure we recognize whole words only
			voidcommands	=   "AbortE", "ClearAllErrors", "DisableUser", "EnableUser", "EndSession", "EnumAllProps",
				"EnumCoordSystems", "EnumTools", "GetCoordSystem", "GetDMEVersion", "GetMachineClass", "GetXtdErrStatus",
				"Home", "IsAlignable", "IsHomed", "IsUserEnabled", "PtMeas", "PtMeasSelfCenter", 
				"PtMeasSelfCenterLocked", "ReQualify", "SaveActiveCoordSystem", "StartSession", 
				"StopAllDaemons";
			voidcommand		=   voidcommands >> (eps_p - alpha_p) >> *space_p;
			stringcommands	=  "ChangeTool", "DeleteCoordSystem", "EnumAllToolCollections", "EnumToolCollection", 
				"FindTool", "GetChangeToolAction", "GetNamedCsyTransformation", "LoadCoordSystem",
				"OpenToolCollection", "SetTool";
			stringcommand	=   stringcommands >> (eps_p - alpha_p) >> *space_p;

			lock_axis_prop_item =   str_p("X") | str_p("Y") | str_p("Z") | str_p("A") | str_p("B") | str_p("C")	| str_p("R") | str_p("Phi")	;
			lock_axis_prop_get_list = list_p(  lock_axis_prop_item >> '(' >> *space_p >> ')', ',');

			lock_position_prop_item = str_p("XFR")	| str_p("YFR")	| str_p("ZFR")	| str_p("RFR")	| str_p("PFR")	;
			lock_position_prop_get_list = list_p(  lock_position_prop_item >> '(' >> *space_p >> ')', ',');

			AlignPart= str_p("AlignPart")  >> '(' >>  list_p( real_p , ',') >> ')' ; 
			AlignTool = str_p("AlignTool") >> '(' >>  list_p( real_p , ',') >> ')';
			CenterPart =  str_p("CenterPart")  >> '(' >>  real_p >> ',' >>  real_p >> ',' >>  real_p >> ',' >>  real_p  >> ')';

			EnumAllProp =  str_p("EnumAllProp")  >> '(' >> enum_prop_list >> ')';
			EnumProp = str_p("EnumProp")  >> '(' >> enum_prop_list >> ')';

			GoTo = str_p("GoTo") >> '(' >> list_p( gotocmd_item , ',' ) >> ')';
			Get= str_p("Get") >> '(' >> get_list >> ')' ;
			GetCsyTransformation = str_p("GetCsyTransformation") >>  '(' >> csytransformations >> ')';

			GetErrorInfo=  str_p("GetErrorInfo") >> '(' >>  int_p >>  ')';
			GetProp = str_p("GetProp") >> '(' >>  getprop_list >>  ')';

			PtMeas = str_p("PtMeas") >> '(' >> ptmeas_list >> ')';
			PtMeasSelfCenterLocked=  str_p("PtMeasSelfCenterLocked") >> '(' >> list_p(ptmeasselfcenter_props >>  chseq_p("()"), ',')  >> ')';

			OnPtMeasReport= str_p("OnPtMeasReport") >>  '(' >> on_ptmeas_report_list >> ')';;
			OnScanReport=str_p("OnScanReport") >>  '(' >> on_ptmeas_report_list >> ')';;
			LockAxis= str_p("LockAxis") >> '(' >> lock_axis_prop_get_list >>')';
			LockPosition =  str_p("LockPosition") >> '(' >>lock_position_prop_get_list >> ')';
			ScanOnCircleHint =  str_p("ScanOnCircleHint") >> '('>> real_p /* displacement*/ >> ','>> real_p /*form*/ >> ')';
			ScanOnLineHint =  str_p("ScanOnLineHint") >> '('>> real_p /* angle*/ >> ','>> real_p /*form*/ >> ')';
			ScanOnCurveHint =  str_p("ScanOnCurveHint") >> '('>> real_p /* deviation*/ >> ','>> real_p /*minradiusofcurvature*/ >> ')';
			ScanUnknownHint =  str_p("ScanUnknownHint") >> '('>> real_p /* minradiusofcurvature*/ >> ')';

				// this will catch good and bad scans
			ScanOnCircle = str_p("ScanOnCircle") >> '('>> list_p(real_p, ',') >> ')';
			ScanOnLine = str_p("ScanOnLine") >> '('>> list_p(real_p, ',') >> ')';
			ScanInPlaneEndIsSphere = str_p("ScanInPlaneEndIsSphere") >> '('>> list_p(real_p, ',') >> ')';
			ScanInPlaneEndIsPlane = str_p("ScanInPlaneEndIsPlane") >> '('>> list_p(real_p, ',') >> ')';
			ScanInPlaneEndIsCyl =  str_p("ScanInPlaneEndIsCyl") >> '('>> list_p(real_p, ',') >> ')';
			ScanInCylEndIsSphere = str_p("ScanInCylEndIsSphere") >> '('>> list_p(real_p, ',') >> ')';
			ScanInCylEndIsPlane= str_p("ScanInCylEndIsPlane") >> '('>> list_p(real_p, ',') >> ')';
			ScanOnCurveDensity=  str_p("ScanOnCurveDensity") >>  '(' >>  list_p(
				str_p("Dis") | str_p("Angle") |	str_p("AngleBaseLength") |(str_p("AtNominals") )>> '(' >>real_p>>  ')' , ',') >> ')';

			ScanOnCurve=str_p("ScanOnCurve") >> '(' >> str_p("Closed") >> '(' >> int_p  >> chseq_p("),") >>
				str_p("Format")>> '(' >> list_p(axis_pos>>chseq_p("()"), ',') >>  !(','>> int_p) >>
				!(',' >> real_p >> ',' >> real_p >> ',' >> real_p ) >>  // pi pj pk
				!(',' >> real_p >> ',' >> real_p >> ',' >> real_p ) >>  // si sj sk
				')'>>
				str_p("Data") >>  '(' >>
				list_p(real_p, ',') >> ')';
			SetCoordSystem = str_p("SetCoordSystem")>>'(' >> coordsystem >> ')' ;
			SaveNamedCsyTransformation = str_p("SaveNamedCsyTransformation") >> '(' >> dblquoted_string >> ',' >> repeat_p(6)[',' >> real_p ] >>')';
			SetCsyTransformation = str_p("SetCsyTransformation") >> '(' >> csytransformations >>  repeat_p(6)[',' >> real_p ] >>')';
			SetProp = str_p("SetProp") >> '(' >> setprop_list >> ')';

			StopDaemon= str_p("StopDaemon") >> '(' >> event_num >> ')' ;
			TiltCenterPart = str_p("TiltCenterPart") >> '(' >> real_p >> repeat_p(6)[',' >> real_p ] >>')';
			TiltPart = str_p("TiltPart") >> '(' >> real_p >> repeat_p(3)[',' >> real_p ] >>')';
				;

			eventcmd =
				str_p("AbortE") >> chseq_p("()")
				| str_p("GetErrStatusE") >> chseq_p("()")
				| str_p("GetPropE") >> '(' >>  getprop_list >>  ')'
				| str_p("OnMoveReportE") >>  '(' >> on_move_report_list >> ')'
				;

			cmd = voidcommand >> chseq_p("()") 
				| stringcommand[&write]  >> '(' >> dblquoted_string [&write] >> *space_p >> ')' 
				| 	AlignPart
				| AlignTool 
				| CenterPart
				| EnumAllProp
				| EnumProp
				| GoTo
				| Get
				| GetCsyTransformation 
				| GetErrorInfo
				| GetProp 
				| PtMeas
				| PtMeasSelfCenterLocked
				| OnPtMeasReport
				| OnScanReport
				| LockAxis
				| LockPosition
				| ScanOnCircleHint 
				| ScanOnLineHint 
				| ScanOnCurveHint
				| ScanUnknownHint 
				| ScanOnCircle
				| ScanOnLine 
				| ScanInPlaneEndIsSphere 
				| ScanInPlaneEndIsPlane
				| ScanInPlaneEndIsCyl
				| ScanInCylEndIsSphere 
				| ScanInCylEndIsPlane
				| ScanOnCurveDensity
				| ScanOnCurve
				| SetCoordSystem
				| SaveNamedCsyTransformation 
				| SetCsyTransformation
				| SetProp 
				| StopDaemon
				| TiltCenterPart 
				| TiltPart ;
			expression  =
				cmd_num >> cmd 
				| event_num >> eventcmd; 

		}
	};

};
