//
// ScriptParser.cpp
//
#include "StdAfx.h"
#define _USE_MATH_DEFINES 
#include <math.h>

//#define BOOST_SPIRIT_DEBUG
#include "Misc.h"

#include "ScriptParser.h"
#include "OutDebug.h"
#include "atlstr.h"
#include "boost/lexical_cast.hpp"
#include <stack>
tstring str;

int CEvalStack::debug=0;

template <typename T, int N> char (&dimension_of(T(&)[N]))[N];

typedef std::vector<parser_id> TreeNodes;
typedef std::map<CString, double> SymbolsMap;
typedef SymbolsMap::value_type	 SymbolMapPair;

static map<long, function<double (double, double)> > BinaryOps;

typedef  std::map<long, function<double (double)> > UnaryOpMap;
typedef std::map<long, function<double (double)> >::value_type UnaryOpPair;

typedef  std::map<long, function<double (double, double)> > BinaryOpMap;
typedef std::map<long, function<double (double, double)> >::value_type BinaryOpPair;


enum 	{	OpsStartID=50, 
LeftParenID, RightParenID, AddID, SubID, PlusID, NegID, MultID, DivID, OrID, AndID, EqID, NeqID, NotID,
GeID, LeID,GtID, LtID,
IntegerID, DoubleID,

FcnStart1ID=100, 
CosID=101, SinID=102, FabsID=103, TruncID=104, FloorID=105,  AcosID=106 , AsinID=107, AtanID=108, SqrtID=109, TanID=110,
CoshID=111 , SinhID=112, TanhID=113, ExpID=114, LogID=115, Log10ID=116, SignID=117, 

Fcn1LastID=199,

FcnStart2ID=200, 
Atan2ID=201, PowID=202, FmodID=203,HypotID=204,
Fcn2LastID=299,

FcnStart3ID=300, 
VectorID=301, 
Fcn3LastID=399,

FcnStartString2ID=400, 
FindID=401, 
FcnString2LastID=499,

FcnStartVector2ID=500, 
DotID=501, CrossID=502,
FcnVector2LastID=599

};

static double Sign(double x) {  return (x>=0) ? 1 : -1; }
UnaryOpPair initUnaryOpPair[] = {
	UnaryOpPair( CosID, cos ),
	UnaryOpPair( SinID, sin ),
	UnaryOpPair( TanID, tan ),
	UnaryOpPair( FabsID, fabs ),
	UnaryOpPair( AcosID, acos ),
	UnaryOpPair( AsinID, asin ),
	UnaryOpPair( AtanID, atan ),
	UnaryOpPair( SqrtID, sqrt ),
	UnaryOpPair( CoshID, cosh ),
	UnaryOpPair( SinhID, sinh ),
	UnaryOpPair( TanhID, tanh ),
	UnaryOpPair( ExpID, exp ),
	UnaryOpPair( LogID, log ),
	UnaryOpPair( Log10ID, log10 ),
	UnaryOpPair( SignID, Sign ),
};

static UnaryOpMap mapUnaryOps(initUnaryOpPair, initUnaryOpPair + sizeof (dimension_of ( initUnaryOpPair )) );

static double pow2d(double x, double y) { return pow(x,y); }
BinaryOpPair initBinaryOpPair[] = {
	BinaryOpPair( Atan2ID, atan2 ),
	BinaryOpPair( PowID, pow2d ),
	BinaryOpPair( FmodID, fmod ),
	BinaryOpPair( HypotID, _hypot ),
};
static BinaryOpMap mapBinaryOps(initBinaryOpPair, initBinaryOpPair + sizeof (dimension_of ( initBinaryOpPair )) );


SymbolMapPair iniMathMap [] =
{

	SymbolMapPair("M_PI", M_PI),
	SymbolMapPair("M_E", M_E),
	SymbolMapPair("M_LOG2E", M_LOG2E),
	SymbolMapPair("M_LN2", M_LN2),
	SymbolMapPair("M_PI_2", M_PI_2),
	SymbolMapPair("M_PI_4", M_PI_4),
	SymbolMapPair("M_1_PI", M_1_PI),
	SymbolMapPair("M_2_PI", M_2_PI),
	SymbolMapPair("M_2_SQRTPI", M_2_SQRTPI),
	SymbolMapPair("M_SQRT2", M_SQRT2),
	SymbolMapPair("M_SQRT1_2", M_SQRT1_2)

};
SymbolsMap MathSymbols( iniMathMap, iniMathMap + sizeof (dimension_of ( iniMathMap )) );

SymbolMapPair initFcnMap[]= 
{
	SymbolMapPair("cos", CosID),
	SymbolMapPair("sin", SinID),
	SymbolMapPair("tan", TanID),
	SymbolMapPair("abs", FabsID),
	SymbolMapPair("fabs", FabsID),
	SymbolMapPair("acos", AcosID),
	SymbolMapPair("asin", AsinID),
	SymbolMapPair("atan", AtanID),
	SymbolMapPair("sqrt", SqrtID),
	SymbolMapPair("cosh", CoshID),
	SymbolMapPair("sinh", SinhID),
	SymbolMapPair("tanh", TanhID),
	SymbolMapPair("exp", ExpID),
	SymbolMapPair("log", LogID),
	SymbolMapPair("log10", Log10ID),
	SymbolMapPair("hypot", HypotID),
	SymbolMapPair("sign", SignID),
	SymbolMapPair("Integer", IntegerID),
	SymbolMapPair("Double", IntegerID),

	SymbolMapPair("Dot", DotID),
	SymbolMapPair("Find", FindID),
	SymbolMapPair("Cross", CrossID),
	SymbolMapPair("atan2", Atan2ID),
	SymbolMapPair("pow", PowID),
	SymbolMapPair("fmod", FmodID),

	SymbolMapPair("Vector", VectorID)
};

SymbolsMap FcnSymbols ( initFcnMap, initFcnMap + sizeof (dimension_of ( initFcnMap )) );

static CString OpName(int id)
{
	switch(id)
	{
	case LeftParenID:
		return "(";
	case  RightParenID: 
		return ")";
	case AddID:
		return "+";
	case SubID:
		return "-";
	case PlusID:
		return "Plus";
	case  NegID:
		return "Neg";
	case MultID:
		return "*";
	case DivID:
		return "/";
	case OrID: 
		return "||";
	case  AndID:
		return "&&";
	case  EqID:
		return "==";
	case  NeqID:
		return "NEG";
	case NotID:
		return "NOT";
	case GeID:
		return ">=";
	case LeID:
		return "<="; 
	case GtID:
		return ">";
	case LtID:
		return "<"; 
	}

	SymbolsMap::iterator it;
	for(it=FcnSymbols.begin();  it!= FcnSymbols.end(); it++)
	{
		if( it->second == id)
			return it->first;
	}
	return StrFormat(_T("%d"), id);
}


static CString TrimQuotes(CString str)
{
	return str.Mid(1,str.GetLength()-2);

}

static bool ReadFile(tstring filename, tstring &text)
{
	USES_CONVERSION;
#ifdef UNICODE
	FILE * fin = _wfopen(filename.c_str(),_T("rt")); // open read and text mode (not binary)
	std::string intext;
#else
	FILE * fin = fopen(filename.c_str(),_T("rt")); // open read and text mode (not binary)
	std::string &intext(text);
#endif
	fseek(fin,0, SEEK_END);  //_wfopen vs fopen
	int filesize = ftell(fin);
	fseek(fin,0, SEEK_SET);
	
	// asumes ascii input
	intext.clear();
	intext.resize(filesize + 1);
	fread((void *) intext.c_str(), 1,   filesize,  fin);
	intext.resize(strlen(intext.c_str())+1);

	// translate ascii to 
#ifdef UNICODE
	text= A2W(intext.c_str());
#endif
	fclose(fin);
	return true;
}


void CEvalStack::PushOp( int op) 
{ 
	if(CEvalStack::debug)
		OutputDebugString(StrFormat(_T("PushOp %s\n"), OpName(op)));
	if(op == RightParenID)
	{
		opstack.pop_back();  // should be  (
		EvalStack();
		return;
	}
	opstack.push_back(op); 
}
void CEvalStack::PushData(Variant data ) 
{ 
	if(CEvalStack::debug)
		OutputDebugString(StrFormat(_T("PushData %s\n"), data.ToString().c_str()));
	datastack.push_back(data); 
	EvalStack();

}

static CString ToString(std::vector<Variant> & data)
{
	CString tmp;
	for(int i=0; i< data.size(); i++)
		tmp.AppendFormat(_T("%s , "), data[i].ToString().c_str());
	return tmp;
}
void CEvalStack::EvalStack()
{
	if(CEvalStack::debug)
		OutputDebugString(StrFormat(_T("EvalStack \n")));
	if(datastack.size()<1)
		return;
	if(opstack.size()<1)
		return;

	int op = opstack.back();
	if(op == LeftParenID)
		return;
	opstack.pop_back();
	if(CEvalStack::debug)
		OutputDebugString(StrFormat(_T("EvalStack Op	= %s\n"), OpName(op)));
	if(CEvalStack::debug)
		OutputDebugString(StrFormat(_T("EvalStack In Data = %s\n"), ::ToString(datastack))); // v.ToString().c_str()));


	Variant v = datastack.back() ;
	datastack.pop_back();

	if( op>FcnStart1ID && op<Fcn1LastID)
	{
		if(!v.IsType<double>() || mapUnaryOps.find(op)==mapUnaryOps.end())
		{
			// this is an error
		goto done;
		}
		double d = v.get<double>();

		/// Single parameter fcn
		datastack.push_back (mapUnaryOps[op](d));
		EvalStack(); // do it again.
		goto done;

	}
	// Now we move to the two parameter items

	if(datastack.size()<1)
	{
		// This is some error we should never get in due to parsing...
		ATLASSERT(0);
		opstack.push_back (op);
		datastack.push_back(v);
		goto done;
	}

	/// Two parameter fcn
	if( op>FcnStart2ID && op<Fcn2LastID)
	{
		if(!v.IsType<double>() || mapBinaryOps.find(op)==mapBinaryOps.end())
		{
		goto done;
		}
		double d = v.get<double>();
		double d1 = datastack.back().get<double>();
		datastack.back() = mapBinaryOps[op](d1,d); // atan2( d1, d);
		EvalStack(); // do it again.
		goto done;

	}
	if( op>FcnStartVector2ID && op<FcnVector2LastID)
	{
		Variant v2=datastack.back();
		datastack.pop_back();

		if(!v.IsType<Vector>() || !v2.IsType<Vector>())
		goto done;

		Vector vec1 = v.get<Vector>();
		Vector vec2 = v2.get<Vector>();

		if(op==DotID)
			PushData(Variant(Dot(vec2,vec1))); 
		if(op==CrossID)
			PushData(Variant(Cross(vec2,vec1))); 

		goto done;

	}
	if( op>FcnStartString2ID && op<FcnString2LastID)
	{
		Variant v2=datastack.back();
		datastack.pop_back();

		if(!v.IsType<tstring>() || !v2.IsType<tstring>())
		goto done;
		tstring s1 = v.get<tstring>();
		tstring s2 = v2.get<tstring>();

		if(op==FindID)
		{
			PushData(Variant((double) (s2.find(s1) !=  tstring::npos))); 
		}

		goto done;

	}
	if( op>FcnStart3ID && op<Fcn3LastID)
	{
		if(datastack.size()<2)
		{
			// error
		goto done;
		}
		Variant v2=datastack.back();
		datastack.pop_back();
		Variant v3=datastack.back();
		datastack.pop_back();
		if(!v.IsType<double>() || !v2.IsType<double>() || !v3.IsType<double>())
		{
		goto done;
		}		
		double d1 = v.get<double>();
		double d2 = v2.get<double>();
		double d3 = v3.get<double>();

		if(op==VectorID)
			PushData(Variant(Vector(d3,d2,d1))); 

		goto done;

	}

	// Make all ops double double here.. no some vector math too

	if(op==AddID)
		datastack.back() = datastack.back() + v;
	else if(op==SubID)
		datastack.back() = datastack.back() - v;
	else if(op==MultID)
		datastack.back() = datastack.back() * v;
	else if(op==DivID)
		datastack.back() = datastack.back() / v;
	else if(op==EqID)
		datastack.back() = datastack.back() == v;
	else if(op==NeqID)
		datastack.back() = datastack.back() != v;
	else if(op==OrID)
		datastack.back() = datastack.back() || v;
	else if(op==AndID)
		datastack.back() = datastack.back() && v;
	else if(op==LeID)
		datastack.back() = (datastack.back() <= v);
	else if(op==GeID)
		datastack.back() = (datastack.back() >= v);
	else if(op==GtID)
		datastack.back() =  (datastack.back() > v);
	else if(op==LtID)
		datastack.back() = (datastack.back() < v);

	// not sure these will work ...
	else if(op==IntegerID)
		datastack.back() = datastack.back().get<long>();
	else if(op==DoubleID)
		datastack.back() = datastack.back().get<double>();

done:
	if(CEvalStack::debug)
		OutputDebugString(StrFormat(_T("EvalStack Out Data = %s\n"), ::ToString(datastack))); // v.ToString().c_str()));


}

CString CEvalStack::ToString()
{
	CString tmp;
	for(int i=0; i<datastack.size(); i++)
	{
		tmp.AppendFormat(_T("%f\n"), datastack[i]);
	}
	return tmp;

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct  CCmdParser :
	public boost::spirit::grammar<CCmdParser>
{

	CCmdParser(void)
	{
		rule_names[NavigateID]				= _T("Navigate");
		rule_names[SetID]					= _T("Set");
		rule_names[ClickID]					= _T("Click");
		rule_names[SelectID]				= _T("Select");
		rule_names[SleepID]					= _T("Sleep");
		rule_names[DblQuotedStrID]          = _T("DblQuotedStrID");
		rule_names[StmtID]					= _T("Stmt");
		rule_names[ParameterID]             = _T("Parameter");
		rule_names[PushID]					= _T("Push");
		rule_names[WaitID]					= _T("Wait");
		rule_names[EmptyLineID]             = _T("EmptyLine");
		rule_names[ErrorLineID]             = _T("ErrorLine");

	}
	~CCmdParser(void){}

	std::map<parser_id, tstring> rule_names;
	enum { NavigateID=1000, 

		StartID,  VariableID, HEXID,StmtID, IdentifierID, STRING_LITERALID, DblQuotedStrID, 
		INTEGERID, AssignID, REALID, StrVariableID,  ErrorLineID, TermID, 
		factorID, termID, expressionID, ParameterID, FunctionID, Function2ID, Function3ID,
		IfThenElseID, ThenClauseID, ElseClauseID, EndifID,


		SetID, ClickID, SelectID, SleepID,  PropertyID, SetSizeID,
		ExecuteID, PushID, WaitID, MsgBoxID,EmptyLineID,  LaunchID, SetFocusID, SendKeysID,
		SendMessageID,  ClickInputSubmitID, ShowWindowID, 
		ExitID };

	static CStringVector errmsgs;
	static void  do_error(iterator_t first, iterator_t last)
	{
#ifdef UNICODE
		file_position_base<tstring> fpos =  first.get_position();
		tstring  str; // (first, end);
		str.assign(first, last);
		errmsgs.push_back(StrFormat(_T("Line %d:%s\n"), fpos.line,str.c_str() ));
#else
		tstring  str; // (first, end);
		str.assign(first, last);
		errmsgs.push_back(StrFormat(_T("Error: %s\n"), str.c_str() ));

#endif
	}

	template <typename ScannerT>
	struct definition
	{
	public:


		rule<ScannerT, parser_context<>, parser_tag<IdentifierID> > Identifier;
		rule<ScannerT, parser_context<>, parser_tag<StmtID> > Stmt;
		rule<ScannerT, parser_context<>, parser_tag<factorID> > factor;
		rule<ScannerT, parser_context<>, parser_tag<termID> > term;
		rule<ScannerT, parser_context<>, parser_tag<expressionID> > expression;


		rule<ScannerT, parser_context<>, parser_tag<NavigateID> > Navigate;
		rule<ScannerT, parser_context<>, parser_tag<SetID> > Set;
		rule<ScannerT, parser_context<>, parser_tag<ClickID> > Click;
		rule<ScannerT, parser_context<>, parser_tag<SelectID> > Select;
		rule<ScannerT, parser_context<>, parser_tag<SleepID> > Sleep;
		rule<ScannerT, parser_context<>, parser_tag<PropertyID> > Property;
		rule<ScannerT, parser_context<>, parser_tag<STRING_LITERALID> > STRING_LITERAL;
		rule<ScannerT, parser_context<>, parser_tag<DblQuotedStrID> > DblQuotedStr;
		rule<ScannerT, parser_context<>, parser_tag<PushID> > Push;
		rule<ScannerT, parser_context<>, parser_tag<INTEGERID> > INTEGER;
		rule<ScannerT, parser_context<>, parser_tag<HEXID> > HEX;


		rule<ScannerT, parser_context<>, parser_tag<WaitID> > Wait;
		rule<ScannerT, parser_context<>, parser_tag<MsgBoxID> > MsgBox;
		rule<ScannerT, parser_context<>, parser_tag<EmptyLineID> > EmptyLine;
		rule<ScannerT, parser_context<>, parser_tag<ErrorLineID> > ErrorLine;
		rule<ScannerT, parser_context<>, parser_tag<LaunchID> > Launch;
		rule<ScannerT, parser_context<>, parser_tag<SetFocusID> > SetFocus;
		rule<ScannerT, parser_context<>, parser_tag<SendKeysID> > SendKeys;
		rule<ScannerT, parser_context<>, parser_tag<ExitID> > Exit;
		rule<ScannerT, parser_context<>, parser_tag<ExecuteID> > Execute;
		rule<ScannerT, parser_context<>, parser_tag<SetSizeID> > SetSize;
		rule<ScannerT, parser_context<>, parser_tag<ShowWindowID> > ShowWindow;
		rule<ScannerT, parser_context<>, parser_tag<ClickInputSubmitID> > ClickInputSubmit;
		rule<ScannerT, parser_context<>, parser_tag<REALID> > Real;
		rule<ScannerT, parser_context<>, parser_tag<AssignID> > Assign;
		rule<ScannerT, parser_context<>, parser_tag<StrVariableID> > StrVariable;
		rule<ScannerT, parser_context<>, parser_tag<SendMessageID> > SendMessage;
		rule<ScannerT, parser_context<>, parser_tag<VariableID> > Variable;
		rule<ScannerT, parser_context<>, parser_tag<ParameterID> > Parameter;
		rule<ScannerT, parser_context<>, parser_tag<FunctionID> > Function;
		rule<ScannerT, parser_context<>, parser_tag<Function2ID> > Function2;
		rule<ScannerT, parser_context<>, parser_tag<Function3ID> > Function3;

		rule<ScannerT, parser_context<>, parser_tag<IfThenElseID> > IfThenElse;
		rule<ScannerT, parser_context<>, parser_tag<ThenClauseID> > ThenClause;
		rule<ScannerT, parser_context<>, parser_tag<ElseClauseID> > ElseClause;
		rule<ScannerT, parser_context<>, parser_tag<EndifID> > Endif;


		rule<ScannerT, parser_context<>, parser_tag<TermID> > Terminator;
		rule<ScannerT, parser_context<>, parser_tag<LeftParenID> > LeftParen;
		rule<ScannerT, parser_context<>, parser_tag<RightParenID> > RightParen;
		rule<ScannerT, parser_context<>, parser_tag<AddID> > Add;
		rule<ScannerT, parser_context<>, parser_tag<SubID> > Sub;
		rule<ScannerT, parser_context<>, parser_tag<PlusID> > Plus;
		rule<ScannerT, parser_context<>, parser_tag<NegID> > Neg;
		rule<ScannerT, parser_context<>, parser_tag<MultID> > Mult;
		rule<ScannerT, parser_context<>, parser_tag<DivID> > Div;
		rule<ScannerT, parser_context<>, parser_tag<OrID> > Or;
		rule<ScannerT, parser_context<>, parser_tag<AndID> > And;
		rule<ScannerT, parser_context<>, parser_tag<NotID> > Not;
		rule<ScannerT, parser_context<>, parser_tag<EqID> > Eq;
		rule<ScannerT, parser_context<>, parser_tag<NeqID> > Neq;
		rule<ScannerT, parser_context<>, parser_tag<GeID> > Ge;
		rule<ScannerT, parser_context<>, parser_tag<LeID> > Le;
		rule<ScannerT, parser_context<>, parser_tag<GtID> > Gt;
		rule<ScannerT, parser_context<>, parser_tag<LtID> > Lt;
		

		rule<ScannerT> Start;


		const boost::spirit::rule<ScannerT> &start() const { return Start; }

		definition( CCmdParser const &self )
		{   
			STRING_LITERAL		= leaf_node_d[lexeme_d[ chlit<>('\"') >> *(anychar_p - chlit<>('\"') ) >> chlit<>('\"')]]; //[&write]
			DblQuotedStr		= +STRING_LITERAL;	
			HEX					=  leaf_node_d[lexeme_d[ch_p('0') >> ( ch_p('x') | 'X' ) >> *xdigit_p]]   ;
			INTEGER				= leaf_node_d[  int_p  ];
			Real				= leaf_node_d[real_p];
			Terminator			= ch_p(';');

			Identifier			= leaf_node_d[lexeme_d	[alpha_p>> *(alnum_p | ch_p('_')) ]];
			StrVariable			= Identifier | STRING_LITERAL;
			Variable			= Identifier ;
			Parameter			= Variable | STRING_LITERAL | Real | INTEGER ;
			Function			= str_p("cos") | str_p("sin")| str_p("fabs")  | str_p("abs")  | str_p("acos") | str_p("asin") | str_p("sqrt");
			Function2			= str_p("Find") | str_p("Dot") | str_p("Cross")  | str_p("atan2"); 
			Function3			= str_p("Vector"); 

			LeftParen=ch_p('('); RightParen=ch_p(')'); Add=ch_p('+'); Sub=ch_p('-');  Mult=ch_p('*'); Div=ch_p('/'); Or=ch_p('|'); And=ch_p('&'); Not=ch_p('!');
			Eq=str_p("=="); Neq=str_p("!="); Le=str_p("<=");Ge=str_p(">="); Lt=ch_p('<');Gt=ch_p('>');

			Plus=ch_p('+'); Neg=ch_p('-');


			factor				=	
				Function3 >> LeftParen >> expression >> ch_p(',')  >> expression >> ch_p(',') >> expression >> RightParen  // must go before Parameter in spirit
				| Function2 >> LeftParen >> expression >> ch_p(',') >> expression >> RightParen  // must go before Parameter in spirit
				| Function >> LeftParen >> expression >> RightParen  // must go before Parameter in spirit
				| Parameter
				| 	LeftParen >> expression >> RightParen
				| 	( Neg >> factor ) 
				|	( Plus >> factor )
				;
			;
			term				=	factor >> *( ( Mult >> factor) | ( Div >> factor ) );

			expression			=	term >> *(( Add | Sub |  Or | And |  Eq  |  Neq | Le  | Ge |  Lt  |  Gt ) >> term )  ;

			IfThenElse			= discard_node_d[str_p("if")] >> discard_node_d[ch_p('(')] >> expression >>discard_node_d[ch_p(')')]  
			 	>>  ThenClause>> *( ElseClause) >> str_p("endif") >> Terminator;
			//	>> ThenClause >> *( ElseClause) >> str_p("endif") >> Terminator;
			ThenClause			= str_p("then") >> *Assign ;
			ElseClause			= str_p("else") >> *Assign ;

			Stmt    				=	
				Assign
				| IfThenElse
				| MsgBox
				| Terminator;
			//	| ErrorLine[&CCmdParser::do_error]; 

			Start				=  *Stmt >> lexeme_d[*space_p];

			Set					=  str_p("Set")		>>  StrVariable >> ch_p('=') >> STRING_LITERAL >> Terminator;
			Sleep				=  str_p("Sleep")	>>  int_p  >> Terminator;
			MsgBox				=  str_p("MsgBox")	>>	STRING_LITERAL >> Terminator;
			Execute				=  str_p("Execute")	>>  StrVariable >> *( STRING_LITERAL >> "," ) >>	ch_p('\n');
			SendMessage			=  str_p("SendMessage")	>>  Variable  >> repeat_p(2)[  discard_node_d[ch_p(',')]>> Variable  ]  >>  Terminator;
			Assign				=  Identifier >> ch_p('=') >>  expression >> Terminator;


			EmptyLine			=  *blank_p >> Terminator;
			ErrorLine			=  *(anychar_p - chlit<>(';'))  >> Terminator;


			BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL);
			BOOST_SPIRIT_DEBUG_RULE(Navigate);
			BOOST_SPIRIT_DEBUG_RULE(Set);
			BOOST_SPIRIT_DEBUG_RULE(Push);
			BOOST_SPIRIT_DEBUG_RULE(Sleep);
			BOOST_SPIRIT_DEBUG_RULE(Wait);

		}
	};
};

CStringVector CCmdParser::errmsgs;

static std::vector<parser_id> & Nodes(std::vector<parser_id> & nodes, parser_id p1, ...)
{
	va_list list;
	va_start(list,p1); 
	nodes.clear();
	parser_id p=p1;
	for(;;)
	{ 
		nodes.push_back(p); 
		p=va_arg(list,parser_id);
		if(p== 0)
			break;
	}
	va_end(list); // cleanup , set 'lsit' to NULL
	return nodes;
}

template<typename TreeIter>
int findNode(const TreeIter &i, TreeIter& findit, int  n, std::vector<parser_id> & nodes )
{
	for(TreeIter it = i->children.begin();it!=i->children.end(); it++) 
	{  
		if(n>=nodes.size() || n<0)
			return 0;
		// fixme add wild card.
		int node  = it->value.id().to_long();
		if( nodes[n] == node  )
		{
			n++;
			if(n==nodes.size())
			{
				findit=it;
				return 1;
			}
			if (findNode(it, findit, n, nodes))
				return 1;
		}
	}
	return 0;
}


//template<typename TreeIter> int CScriptParser::evaluate(const TreeIter& i)

int CScriptParser::evaluate(const tree_match<iterator_t>::container_t::iterator& i)

{
	int n =  i->value.id().to_long();
	TreeIter findit;
	TreeNodes nodes;
	CString name, text;
	const TreeIter& it = i;

	switch(n)
	{ 

	case CCmdParser::IfThenElseID:
		{

			TreeIter childit=it->children.begin();
			evaluate(childit);
			int boolvalue = evalstack.datastack.back().get<double>()!=0;
			evalstack.datastack.pop_back();

			if(boolvalue && findNode(i, findit, 0, Nodes(nodes, CCmdParser::ThenClauseID,   0)))
			{
				childit = findit->children.begin();
				for(; childit!=findit->children.end(); childit++)
					evaluate(childit);
			}
			if(!boolvalue && findNode(i, findit, 0, Nodes(nodes, CCmdParser::ElseClauseID,   0)))
			{
				childit = findit->children.begin();
				for(; childit!=findit->children.end(); childit++)
					evaluate(childit);
			}
			return 0;
		}


	case CCmdParser::VariableID:
		{
			if(findNode(i, findit, 0, Nodes(nodes, CCmdParser::IdentifierID,   0)))
			{
				TreeIter childit = findit->children.begin();
				Variant v;
				CString szVarname = string(childit->value.begin(), childit->value.end()).c_str();
				SymbolsMap::iterator it;
				if((it=MathSymbols.find(szVarname)) != MathSymbols.end())
				{
					v=Variant((double)(*it).second);
				}
				else
				{
					v = this->GetVariable((LPCTSTR) szVarname);
				}
				evalstack.PushData(v);
			}
			return 0;
		}
	case CCmdParser::HEXID:
		{
			TreeIter childit = it ;
			if(it->children.size() >0)
				childit= it->children.begin();

			tstring szParameter(childit->value.begin(), childit->value.end());
			long int x = _tcstol(szParameter.c_str(), NULL, 16);

			evalstack.PushData((double) x);
			return 0;

		}
	case CCmdParser::INTEGERID:
		{
			TreeIter childit = it ;
			if(it->children.size() >0)
				childit= it->children.begin();

			long nParameter;
			nParameter =    boost::lexical_cast<long>(string(childit->value.begin(), childit->value.end())); 
			evalstack.PushData((double) nParameter);
			return 0;

		}
	case CCmdParser::REALID:
		{
			TreeIter childit = it ;
			if(it->children.size() >0)
				childit= it->children.begin();

			double dParameter;
			dParameter =    boost::lexical_cast<double>(string(childit->value.begin(), childit->value.end())); 
			evalstack.PushData((double) dParameter);
			return 0;

		}
	case CCmdParser::STRING_LITERALID:
		{
			TreeIter childit = it ;
			if(it->children.size() >0)
				childit= it->children.begin();

			tstring str(childit->value.begin(), childit->value.end());
			str =  str.substr(1, str.size() - 2  ); // TrimQuotes(str.c_str());
			evalstack.PushData((tstring) str);
			return 0;
		}	
	case CCmdParser::AssignID:
		{
			tstring szVarname;

			if(findNode(i, findit, 0, Nodes(nodes, CCmdParser::IdentifierID,   0)))
			{
				TreeIter it = findit->children.begin();
				szVarname=  tstring(it->value.begin(), it->value.end());
			}	
			if(i->children.begin()==i->children.end())
				return 0;

			for(TreeIter childit = i->children.begin() + 1; childit!=i->children.end(); childit++)
			{
				evaluate(childit);
			}

			this->SetVariable((LPCTSTR) szVarname.c_str(), evalstack.datastack.back());
			evalstack.datastack.pop_back();
			return 0;

		}

	case CCmdParser::Function3ID:
	case CCmdParser::Function2ID:
	case CCmdParser::FunctionID:
		{
			TreeIter childit = it ;
			if(it->children.size() >0)
				childit= it->children.begin();

			CString szFuncname = string(childit->value.begin(), childit->value.end()).c_str();
			SymbolsMap::iterator it;
			if((it=FcnSymbols.find(szFuncname)) != FcnSymbols.end())
			{
				int opId=(int) (*it).second;
				evalstack.PushOp(opId);
			}
			return 0;

		}
	case LeftParenID:
	case RightParenID:
	case AddID:
	case SubID:
	case PlusID:
	case NegID:
	case MultID:
	case DivID:
	case OrID:
	case AndID:
	case NotID:
	case EqID:
	case NeqID:
	case LeID:
	case GeID:
	case LtID:
	case GtID:

		evalstack.PushOp(n);
		return 0;
	case CCmdParser::MsgBoxID :
		{
			if(findNode(i, findit, 0, Nodes(nodes, CCmdParser::STRING_LITERALID,   0)))
			{
				TreeIter it = findit->children.begin();
				text=  TrimQuotes(tstring(it->value.begin(), it->value.end()).c_str());
				::MessageBox(NULL, text, _T(""), MB_OK);
			}	

		}
		break;
	}


	for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
		evaluate(it);
	return 0;
}


LRESULT CScriptParser::OnTimer(UINT, WPARAM, LPARAM, BOOL&)
{

	return 0;
}
using namespace boost::spirit; 

CScriptParser::CScriptParser()
{

}
CScriptParser::~CScriptParser()
{
}

//CEvalStack  evalstack;
CString CScriptParser::ToString()
{
	CString tmp;
	for(std::map<CString, Variant>::iterator it = _variables.begin(); it!=_variables.end(); it++)
	{
		CString s =  (*it).second.ToString().c_str();
		tmp.AppendFormat(_T("%s=%s\n"), (*it).first, s);
	}
	return tmp;
}


tree_parse_info<iterator_t> CScriptParser::ParseAFile(CString filename)
{
	tstring text;
	ReadFile((LPCTSTR) filename, text);
	return ParseAString(text, (LPCTSTR) filename);

}
CStringVector CScriptParser::GetErrorMessages()
{
	return CCmdParser::errmsgs;
}

tree_parse_info<iterator_t> CScriptParser::ParseAString(tstring text, tstring filename)
{
	USES_CONVERSION;
	//	  if (parse(str.c_str(), iniparser, blank_p).full)
	CCmdParser iniparser;
	ini_skip_grammar skip;

#ifdef DEBUG
	Fstream outputfile(CString(GetExeDirectory() + _T("output.txt")));
	//tstring file = (const char *) ReadAFile(filename);
	std::fstream debugfile;
	debugfile.open (CString(GetExeDirectory() + _T(".\\DebugParsing.txt")), std::fstream::out );
#endif

	iterator_t first(text.c_str(), &text[text.size()-1], (const TCHAR *) filename.c_str());
	iterator_t last;
	first.set_tabchars(8);

	//parse_info<const char*> info =	parse((LPCSTR) file, iniparser, skip);
	CCmdParser::errmsgs.clear();
	tree_parse_info<iterator_t> info =	pt_parse(first, last, iniparser, skip);

#if 0
	if(info.full)
	{
		//tree_to_xml(outputfile.fp, info.trees, (LPCSTR) file, iniparser.rule_names);
		if(	CCmdParser::errmsgs.size()>0	)
		{
			CString tmp(_T("Script Parse Failed - Quitting\n"));
			tmp+=CCmdParser::errmsgs.ToString();
			::MessageBox(NULL, tmp, _T("Script Error"), MB_OK);
			//::PostMessage(hwndMainFrame, WM_CLOSE, 0 , 0);
			//::Sleep(1000);
			return info;

		}
		evaluate(info.trees.begin());
		OutputDebugString(this->ToString());
		OutputDebugString(_T("Script Parse Succeeded \n"));
	}
	else
	{
		OutputDebugString(StrFormat(_T("Script Parse Failed  Unknown Reason at%s\n") , info.stop));

	}
#endif
	return info;
}

