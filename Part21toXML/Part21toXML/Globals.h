///
// Globals.h
//
#pragma once


#include <Exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <atlstr.h>
#include <comutil.h>
#include "boost/variant.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/intrusive_ptr.hpp>


extern CString gStartEntity;
extern	std::ofstream debugstream;
extern void GlobalsInit();

#if 0
#include "Part21Generator.h"
class CPart21Generator;
extern CPart21Generator * _gPart21gen;
#endif

#define EXP_EXT_CLASS 
#define EXP_DECLARE_SMARTPOINTER(className)                                             \
	typedef EXP_EXT_CLASS boost::intrusive_ptr<className> className##Ptr;              \
	typedef EXP_EXT_CLASS boost::intrusive_ptr<const className> className##ConstPtr;




struct CClassNode;
class IStepNodeBase;
class CVarsDefsPtr;
class CVarDef;
class CClassGenerators;
class CVarDef2Part21;
class StepTable;
class IStepNode;

EXP_DECLARE_SMARTPOINTER(CVarDef) 
EXP_DECLARE_SMARTPOINTER(IStepNode) 

typedef std::vector<CVarDefPtr> CVarDefs;
typedef boost::variant< long, CString, double  > EXPVariant;


// TODO:
// 1) need to create & assign  _gPart21gen in mainfrm
//  mainfrm.h : 	CPart21Generator _part21gen;
//	mainfrm.cpp: in OnCreate() add _gPart21gen= &this->_part21gen;
//  mainfrm.cpp : add CPart21Generator * _gPart21gen=NULL;
// 2) name the starting entity - should only be one.

class StepNCException: public std::runtime_error
{
    public:
        StepNCException(std::string const& msg):
            std::runtime_error(msg)
        {}
};
namespace Step
{
    class Error
    {
	public:
        static const  int UNAUTHORIZED = 1;
        static const  int PARSE_ERROR  = 2; 
        static const  int INSUFFICENT_INFO  = 3;
        static const  int UNSUPPORTED_FEATURE = 4; 
        static const  int INTERNAL_ERROR  = 5; 
		static const  int INVALID_DATA  = 6 ;
		static const  int EMPTY_FILENAME  = 7 ;
		static LPCOLESTR ErrorLookup(LPCOLESTR errmsg)
		{
			if(errmsg ==  L"Illegal filename")
			{ 
				return errmsg; 
			}
			return errmsg;
		}

		static std::vector<std::string> getErrorCode( int _errorCode)
		{
			std::vector<std::string> error(2);
			switch( _errorCode )
			{
			case UNAUTHORIZED: 
				error[0] = "UNAUTHORIZED";
				error[1] = "The request did not have sufficient permissions to perform the request.";
				break;
			case PARSE_ERROR: 
				error[0] = "PARSE_ERROR";
				error[1] = "The text or file generated a parsing error.";
				break;
			case INSUFFICENT_INFO: 
				error[0] = "INSUFFICENT_INFO";
				error[1] = "The operation requires more information than provided.";
				break;
			case UNSUPPORTED_FEATURE: 
				error[0] = "UNSUPPORTED_FEATURE";
				error[1] = "The feature or operation is not supported.";
				break;
			case EMPTY_FILENAME: 
				error[0] = "EMPTY_FILENAME";
				error[1] = "Filename empty.";
				break;
			}
			return error;
		}

	};

	/* XML Tree - containing error message
	XElement mtxst = Util.createErrorXST();
	String[] errorDescription = getErrorCode(_errorCode);
	XElement error =
	new XElement("Error",
	new XAttribute("errorCode", errorDescription[0]), errorDescription[1] + " " + _extra);
	mtxst.Add(error);
	return mtxst;

	*/
};
