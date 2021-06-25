//
// CreateCPPClasses.h
//

#pragma once
#include "ExpressUtils.h"
#include "atlstr.h"
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>

#include <boost/shared_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include "boost/multi_array.hpp"
#include <boost/spirit/symbols/symbols.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include "Misc.h"


class SymbolTable : public IExpress 
{
	public:
	typedef std::map<CString, IStepNodePtr>::iterator NamedEntityIterator;
	typedef std::map<CString, IStepNodePtr>::iterator NamedTypeIterator;
	
	std::vector<SymbolTable> _includes;

	std::vector<ISymbolPtr> _symbols;
	std::vector<IStepNodePtr>  types;

	std::map<CString, IStepNodePtr>  namedtypes;

	std::vector<IStepNodePtr>  entities;
	std::map<CString, IStepNodePtr>  namedentities;
	std::map<CString, CStringVector>  entitysuperclassesof;
public:
	std::vector<CString> szNamespace;
	CString _szSchema;
	std::vector<CString> _schemas;

	void Clear() 
	{ 
		szNamespace.clear(); _schemas.clear(); 
		types.clear(); namedtypes.clear(); 
		entities.clear(); namedentities.clear();
		_symbols.clear(); _includes.clear(); 
	}

	std::vector<IStepNodePtr> & Types() { return types;}
	std::map<CString, IStepNodePtr> &  NamedTypes() { return  namedtypes; }
	std::map<CString, IStepNodePtr> & NamedEntities() { return namedentities; }
	std::vector<IStepNodePtr> & Entities() { return entities; }
	std::map<CString, CStringVector> & EntitySuperClassesof() { return entitysuperclassesof; }
	void AddSymbol(ISymbolPtr symbol)
	{	
		_symbols.push_back(symbol);	
	}
	ISymbolPtr FindSymbol(CString name, CString anamespace=_T("") )
	{
		for(int i=0; i<_symbols.size(); i++) 
		{
			ISymbolPtr symbol = _symbols.at(i);
			if(symbol->_sName == name)
			{
				if(anamespace=="")
					return symbol;
				if(symbol->_sNamespace == anamespace)
					return symbol;
			}

		}
	}

	IStepNodePtr FindNamedEntity(CString name)
	{
		NamedEntityIterator it = namedentities.find(name);
		if(it!= namedentities.end())
			return (*it).second;
		return NULL;
	}

	StepNodeType FindType(CString name)
	{
		for(int i=0; i<_symbols.size(); i++) 
		{
			ISymbolPtr symbol = _symbols.at(i);
			if(symbol->_sName == name)
				return symbol->_eType;
		}
		return (StepNodeType) 0;
	}

	StepNodeType FindVarType(CString name)
	{
		NamedTypeIterator typeit;
		NamedEntityIterator entityit;
		typeit=namedtypes.find(name);

		if(typeit !=namedtypes.end())
		{
			if((*typeit).second==NULL)
				DebugBreak();
			return (*typeit).second->_eType;
		}

		entityit= namedentities.find(name);
		if(entityit != namedentities.end() )
		{
			if((*entityit).second==NULL)
				DebugBreak();
			return (*entityit).second->_eType;
		}

		return (StepNodeType) 0;
	}

	StepNodeType GetType(ISymbol * symbol) { if(symbol==NULL) return (StepNodeType) 0; return symbol->_eType; }

	CVarDef * CreateVarDef(CString name, CString anamespace, StepNodeType type)
	{
		CVarDef * var = new CVarDef;
		var->_sName=name; 
		var->_eType=type; 
		var->_sNamespace=anamespace; 
		AddSymbol((ISymbol *)var);
		return var;

	}
	IStepNodePtr CreateTypeNode(CString name, CString basetype="", StepNodeType type=unknown_)
	{
		IStepNode * var = new IStepNode;
		name = ExpMangle(name); 
		types.push_back(var);
		var->Name()=name; 
		namedtypes[name]= var; 
		var->_eType=type;
		//var->_basetype=basetype;
		AddSymbol((ISymbol *) var);
		return var;
	}
	IStepNodePtr CreateEntityDef(CString name, CString anamespace, StepNodeType type=unknown_)
	{
		IStepNodePtr var = new IStepNode;
		name = ExpMangle(name); 
		entities.push_back(var);
		var->Name()= name; 
		namedentities[name]= var; 
		var->Namespace()=anamespace;
		var->_eType=type;
		AddSymbol((ISymbolPtr) var);
		return var;
	}
	CString DumpSymbols()
	{
		CString tmp;
		for(int i=0; i< _symbols.size(); i++)
		{
			ISymbolPtr symbol = _symbols.at(i);
			tmp.AppendFormat("%s Type=%d  ClassDef=%s\n", symbol->_sName, symbol->_eType, symbol->m_sClassname);

		}
		return tmp;
	}
	// extern CString DumpEntities ();
};
EXP_DECLARE_SMARTPOINTER(SymbolTable) 
// Declare all classes
// Declare enums and class helpers

class CCreateCPPClasses
{
public: 
	typedef	std::map<CString,IStepNodePtr> NamedEntities;
	typedef	std::map<CString,IStepNodePtr>::iterator NamedEntityIterator;

	CCreateCPPClasses(SymbolTable &symbols);
#if 0
		std::map<CString,IStepNodePtr> &namedentities,
		std::vector<IStepNodePtr> &entities,
		std::map<CString,IStepNodePtr> & namedtypes,
		std::vector<IStepNodePtr>  & types); 
#endif
	void CreateHeaderDeclarationFile(CString szFilename );
	void CreateClassDeclarationFile(CString szFilename);
	void CreateClassImplFile(CString szFilename);
	void CreateClassDeclarationItem(std::fstream &headerdeclfile, IStepNodePtr entity);
	void CreateTypeDeclarationItem(std::fstream &headerdeclfile, IStepNodePtr type);
	void GenerateBaseClasses(std::fstream &headerdeclfile, CVarDefs & vars );
	void GenerateBaseClasses(CVarDefs & vars , CStringVector &classes);

	// Inputs
	SymbolTable & _symbols;
	std::map<CString, IStepNodePtr> & _namedtypes;
	std::map<CString,IStepNodePtr> & _namedentities;
	std::vector<IStepNodePtr>  & _types;
	std::vector<IStepNodePtr> & _entities;
	std::map<CString, CStringVector> & _entitysuperclassesof;
	// Member
	std::map<CString, int>  _enums;

};
