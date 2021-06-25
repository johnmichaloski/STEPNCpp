//
// SymbolTable.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#pragma once

#include <map>
#include "comutil.h"
#include <atlpath.h>
#include <boost/tuple/tuple.hpp>
#include "Misc.h"

namespace SymbolTable
{
	typedef enum { ROOT, BRANCH, LEAF} SymbolType;
};
template <class T>
class CSymbolT : public ISmartPointer<T >
{
public:
	SymbolTable::SymbolType m_type;
	CString m_name;
	CString m_section;
	CString m_parameter;

	VARTYPE vt;
	_variant_t m_value;
	_variant_t m_lastvalue;
	_variant_t m_defaultValue;
	FILETIME m_time;

	// Application specific
	CSymbolT(SymbolTable::SymbolType type=LEAF, CString section="", CString tag="")
	{
		m_type=type;
		m_section = section;
		m_name=tag;
		m_value.Clear();
		m_lastvalue.vt=VT_EMPTY;
	}

};

struct UnsortedLSTR
{
  bool operator()(const TCHAR* s1, const TCHAR* s2) const
  {
    return false;
  }
};


class UnsortedStringMap : public TResizingTable<CString> 
{
public:
	std::vector<CString> & Find( CString key)
	{
		for(int i=0; i<size(); i++)
		{
			if(key == this->at(i,0))
			{
				return this->table.at(i);
			}
		}
		push_back(key);
		return this->table.back();
		
	}
	std::vector<CString> Get(CString key)
	{
		std::vector<CString> & vals = Find(key);
		return std::vector<CString>(vals.begin()+1, vals.end());
	}
	void Add(CString key,  CString val)
	{
		std::vector<CString> & vals = Find(key);
		vals.push_back(val);
	}
};




template <class SymbolT>
class CSymbolTableT
{
public:
	typedef boost::intrusive_ptr<SymbolT> CSymbolPtr;              
	typedef boost::intrusive_ptr<const SymbolT> CSymbolConstPtr;

//	typedef boost::tuples::tuple<CString, CSymbolPtr> SymbolsMap;
	typedef std::map<CString,CSymbolPtr> SymbolsMap;
	typedef typename SymbolsMap::iterator SymbolsIterator;
	UnsortedStringMap sectionsmap;

	CSymbolTableT(){}
	virtual ~CSymbolTableT(){}
	virtual int OnAfterReadSection(CString sectionname, CString section) 
	{ 
		return 0;
	}
	virtual int OnBeforeParseLine(CString section, CString line) { return 0; }

	/// rewrite this if you want to change how the line in a section is parsed.
	HRESULT			GetIniSetting(CString section, CString line);


	HRESULT			SetItemValue(CString tag,_variant_t val);
	_variant_t		GetItemValue(CString tag);

	_variant_t		GetSymbolValue(CString section, CString tag, variant_t var=0);
	HRESULT			SetSymbolValue(CString section, CString tag, variant_t var);

	CStringVector	GetSectionSymbols(CString section);
	CStringVector	GetUnsortedSectionSymbols(CString section);

	template<typename T>
	bool GetValue(CString section, CString parameter, T & val);

	_variant_t		GetValue(CString tag);

	//CString			ParseSection(CString iniSection);
	CString			ToString(CString section=L"");
	CString			FromInifile(CString filename);
	CStringVector	ParseIni(CString &contents);
	HRESULT			AddSymbolItem(CString section, 	CString parameter, 	CString value, 	VARTYPE vt, CString sDefaultValue);

	CString			GetIniSection(CString section);
	void			Clear(){ _Sections.clear(); _szSections.clear(); m_symbols.clear(); _contents.Empty(); }

	CStringVector GetLines(CString sectionname);
	CSymbolPtr GetSymbol(CString tag)
	{
		SymbolsIterator it =  m_symbols.find(tag);
		if(it != m_symbols.end())
			return (*it).second;
		return NULL;

	}
	template<typename T>
	bool CSymbolTableT::GetValue(CString section, CString parameter, T & val)
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

private:
	void IniParseIt(CString filename);
	CString GetIniSectionName(CString &line);
	static CStringVector _Tokenize(CString str, CString tokens, int bSave=0)
	{
		CString resToken;
		int curPos= 0;
		CStringVector strs;

		resToken= str.Tokenize(tokens,curPos);
		while (resToken != "")
		{
			strs.push_back((!bSave) ? resToken: resToken+str[curPos-1]);  
			resToken= str.Tokenize(tokens,curPos);
		};
		return strs;
	}

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
	SymbolsMap m_symbols;

	CString _contents;

};
#if 1
class CSymbol : public CSymbolT<CSymbol> 
{
public:
	CSymbol(SymbolTable::SymbolType type=SymbolTable::LEAF, CString section="", CString tag="") :
	  CSymbolT<CSymbol>(type, section,  tag)
	  {

	  }
};
typedef CSymbolTableT<CSymbol> CSymbolTable;

//#define CSYMBOLPTR CSymbol *
typedef boost::intrusive_ptr<CSymbol> CSymbolPtr;              
typedef boost::intrusive_ptr<const CSymbol> CSymbolConstPtr;

#else
#include "SymbolTableWithScripting.h"
#endif

#include "SymbolTable.cpp"