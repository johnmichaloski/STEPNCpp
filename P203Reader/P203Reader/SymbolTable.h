//
// SymbolTable.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#pragma once
#include "Misc.h"
#include <map>
#include "comutil.h"


class VarTypes
{
public:
	typedef std::map<CString,VARTYPE> VARTYPES;
	VARTYPES types;
	typedef std::map<CString,VARTYPE>::iterator VarTypeIterator;
	bool ValidVT(CString svt)
	{
		svt.Trim();
		return types.find( svt)==types.end();
	}

	CString Lookup(VARTYPE  vt)
	{
		VARTYPES::iterator it;
		for(it=types.begin(); it!=types.end(); it++)
			if((*it).second == vt)
				return (*it).first;
		return "VT_UNDEFINED";
	}
	VARTYPE Lookup(CString svt)
	{
		VARTYPES::iterator it;
		svt.Trim();
		it=types.find(svt);
		if(it==types.end())
			return 0;
		return (*it).second;
	}
	VarTypes()
	{
		types["VT_EMPTY"]  = 0;
		types["VT_NUL"]  = 1;
		types["VT_I2"]  = 2;
		types["VT_I4"]  = 3;
		types["VT_R4"]  = 4;
		types["VT_R8"]  = 5;
		types["VT_CY"]  = 6;
		types["VT_DATE"]  = 7;
		types["VT_BSTR"]  = 8;
		types["VT_DISPATCH"]  = 9;
		types["VT_ERROR"]  = 10;
		types["VT_BOO"]  = 11;
		types["VT_VARIANT"]  = 12;
		types["VT_UNKNOWN"]  = 13;
		types["VT_DECIMA"]  = 14;
		types["VT_I1"]  = 16;
		types["VT_UI1"]  = 17;
		types["VT_UI2"]  = 18;
		types["VT_UI4"]  = 19;
		types["VT_I8"]  = 20;
		types["VT_UI8"]  = 21;
		types["VT_INT"]  = 22;
		types["VT_UINT"]  = 23;
		types["VT_VOID"]  = 24;
		types["VT_HRESULT"]   = 25;
		types["VT_PTR"]  = 26;
		types["VT_SAFEARRAY"]  = 27;
		types["VT_CARRAY"]  = 28;
		types["VT_USERDEFINED"]  = 29;
		types["VT_LPSTR"]  = 30;
		types["VT_LPWSTR"]  = 31;
		types["VT_FILETIME"]  = 64;
		types["VT_BLOB"]  = 65;
		types["VT_STREAM"]  = 66;
		types["VT_STORAGE"]  = 67;
		types["VT_STREAMED_OBJECT"]  = 68;
		types["VT_STORED_OBJECT"]  = 69;
		types["VT_BLOB_OBJECT"]  = 70;
		types["VT_CF"]  = 71;
		types["VT_CLSID"]  = 72;
		types["VT_VECTOR"]  = 0x1000;
		types["VT_ARRAY"]  = 0x2000;
		types["VT_BYREF"]  = 0x4000;
		types["VT_RESERVED"]  = 0x8000;
		types["VT_ILLEGA"]  = 0xffff;
		types["VT_ILLEGALMASKED"]  = 0xfff;
		types["VT_TYPEMASK"] = 0xfff;
	}
};
class CSymbol : public ISmartPointer<CSymbol>
{
public:
	typedef enum { ROOT, BRANCH, LEAF} SymbolType;
	SymbolType m_type;
	CString m_name;
	CString m_section;
	CString m_parameter;

	VARTYPE vt;
	_variant_t m_value;
	_variant_t m_lastvalue;
	_variant_t m_defaultValue;
	FILETIME m_time;

	// Application specific
	CSymbol(SymbolType type=LEAF, CString section="", CString tag="")
	{
		m_type=type;
		m_section = section;
		m_name=tag;
		m_value.Clear();
		m_lastvalue.vt=VT_EMPTY;
	}

};
//#define CSYMBOLPTR CSymbol *
#define CSYMBOLPTR CSymbolPtr
typedef boost::intrusive_ptr<CSymbol> CSYMBOLPTR;              
typedef boost::intrusive_ptr<const CSymbol> CSymbolConstPtr;

class CSymbolTable
{
public:
	typedef std::map<CString,CSymbolPtr> SymbolsType;
	typedef std::map<CString,CSymbolPtr>::iterator SymbolsIterator;

	CSymbolTable();
	~CSymbolTable();

	/// rewrite this if you want to change how the line in a section is parsed.
	HRESULT			GetIniSetting(CString section, CString line);


	HRESULT			SetItemValue(CString tag,_variant_t val);
	_variant_t		GetItemValue(CString tag);

	_variant_t		GetSymbolValue(CString section, CString tag, variant_t var=0);
	HRESULT			SetSymbolValue(CString section, CString tag, variant_t var);

	CStringVector	GetSectionSymbols(CString section);

	template<typename T>
	bool GetValue(CString section, CString parameter, T & val);

	_variant_t		GetValue(CString tag);
	CSymbolPtr		GetSymbol(CString tag);

	CString			ParseSection(CString iniSection);
	CString			ToString();
	CString			FromInifile(CString filename);
	CStringVector	ParseIni(CString &contents);
	HRESULT			AddSymbolItem(CString section, 	CString parameter, 	CString value, 	VARTYPE vt, CString sDefaultValue);

	CString			GetIniSection(CString section);

private:
	void IniParseIt(CString filename);
	CString GetIniSectionName(CString &line);

	struct Section
	{
		Section(CString name, int start, int first=-1, int end=-1) : _name(name) ,  _start(start) ,  _first(first),  _end(end) {}
		CString _name;
		int _start;
		int _first;
		int _end;
	};
	std::vector<Section> _Sections;
	CStringVector _szSections;

	// Map rep
	SymbolsType m_symbols;

	CString _contents;

};


template<typename T>
bool CSymbolTable::GetValue(CString section, CString parameter, T & val)
{ 
	if(parameter.GetLength()>0)
		parameter="." + parameter;

	_variant_t var = GetItemValue(section+parameter);
	try 
	{
		val =(T) var;
	}
	catch(...)
	{
		return false;
	}
	return true; 
}
