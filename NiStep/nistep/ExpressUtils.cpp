//
// ExpressUtils.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"
#include "ExpressUtils.h"
#include "boost/lexical_cast.hpp"
#include <stdarg.h>
#include <stack>
#include "StepPath.h"
#include "QueryPath.h"

//array_type A(boost::extents[3][4][2]);

int nDumpIndent=0;
//std::map<CString,IStepNC *> _entities;
EReal::EReal() { Init() ; val=0.0; }
EInteger::EInteger(){ Init() ; val=0; }
EString::EString(){ Init() ; }
EEnum::EEnum(){ Init() ; }
ESelection::ESelection() { Init() ; }
EBoolean::EBoolean(){ Init(); m_nSelection=0; }
EStepArray::EStepArray() { Init();}
CString EReal::szDefaultFmt=_T("%.4f");
IStepNodePtr CreateExpressBaseClass(CString classname, CString name) 
{
	classname=ExpMangle(classname.MakeLower());
	if(classname=="Estring") return (IStepNodePtr) new EString;
	if(classname=="Einteger") return (IStepNodePtr) new EInteger;
	if(classname=="Enumber") return (IStepNodePtr) new Enumber;
	if(classname=="Ereal") return (IStepNodePtr) new EReal;
	if(classname=="Elogical") return (IStepNodePtr) new ELogical;
	if(classname=="Ebinary") return (IStepNodePtr) new EBinary;
	if(classname=="Eenum") return (IStepNodePtr) new EEnum;
	if(classname=="Eboolean") return (IStepNodePtr) new EBoolean;
	return NULL;
}

static LPCTSTR TrimLeft(LPCTSTR item)
{
	while(item[0]!=0 && _istspace(item[0]) ) item++; // .TrimLeft();
	return item;
}
bool IsEntityReference(LPCTSTR item)
{
	item=TrimLeft(item);
	if(item[0]==0)
		return false;
	if(item[0]==_T('#'))
		return true;
	else return false;

}
bool IsKeyword(LPCTSTR item)
{
	item=TrimLeft(item);
	if(item[0]!= 0 && !isalpha(item[0]))
		return false;
	if(item[0]==0)
		return false;
	for(int i=1; item[i]!=0; i++)
		if(!isalpha(item[i]) || item[i]!=_T('_'))
			return false;
	 return true;

}

bool IsNumber(LPCTSTR item)
{
	item=TrimLeft(item);
	if(item[0]==0)
		return false;
	TCHAR * endptr;
	LPCTSTR lpstr = (LPCTSTR) item;
	double d = _tcstod (lpstr, &endptr);
	if(lpstr!=endptr)
		return true;
	return false;

}

bool IsString(LPCTSTR item)
{
	item=TrimLeft(item);
	if(item[0]==0)
		return false;
	if(item[0]==_T('\'') && item[_tcslen(item) -1]=='\'')
		return true;
	return false;

}
bool IsEnumeration(LPCTSTR item)
{
	item=TrimLeft(item);
	if(_tcslen(item) < 2)
		return false;
	int n = _tcslen(item) - 1;
	if(item[0]!= _T('.') && item[n] != _T('.'))
		return false;
	if(item[0]== _T('.') && item[n] == _T('.'))
		return true;
	if(item[0]== _T('.') && item[n] != _T('.'))
		throw std::exception("unmatched right .");
	if(item[0]!= _T('.') && item[n] == _T('.'))
		throw std::exception("unmatched left .");
	return false;

}

void StoreInstance(CVarDefPtr vardef, CString sParameter)
{
	IStepNodePtr pDerivedClass;
	CString classname;

	if(sParameter.GetLength() < 1)
	{
		DebugBreak();
	}

	classname=vardef->Classname();
	if(vardef->ISymbolBase::IsListType())
		classname=vardef->ListClassname();
#if 0
	if(IsEntityReference(sParameter))
	{
		// g.g., #123 reference
		if(Entries.find(sParameter)!=Entries.end())
		{
			pDerivedClass=Entries[sParameter];
		}
		else
		{
			DebugBreak();
			throw std::exception("Unresolved Reference\n");
			return;
		}
	}
	else
#endif
	{
		// create simple type class: string, real, integer, etc.
		pDerivedClass =  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle((LPCTSTR) classname), _T(""));
	}

	if(!pDerivedClass)
		DebugBreak();

	if(IsString(sParameter))
	{
		// Fixme: check for badly formed string
		sParameter=sParameter.Mid(1);
		sParameter=sParameter.Left(sParameter.GetLength()-1);
		pDerivedClass->SetVarString((LPCTSTR) sParameter);
	}
	else if( IsNumber(sParameter))
	{
		pDerivedClass->SetVarString((LPCTSTR) sParameter);
	}
	else if(IsEnumeration(sParameter))
	{
		EEnum*instance = (EEnum*) pDerivedClass.get();
		instance->SetString2Enum((LPCTSTR) sParameter);
	}
	else if(sParameter[0]==_T('#') &&  IsNumber(sParameter.Mid(1)))
	{
	}
	else
	{
		DebugBreak();
	}

	Store(vardef, pDerivedClass);
}


void BuildInstanceDef(CVarDefs & vars, CVarDefs &instances, CStringVector &vVisitedClasses)
{
	for(int i=0; i<vars.size(); i++)
	{
		if(vars[i]->Type() == special_)
		{
			if(std::find(vVisitedClasses.begin(), vVisitedClasses.end(), vars[i]->Name())== vVisitedClasses.end())
			{
				vVisitedClasses.push_back(vars[i]->Name());
				BuildInstanceDef((CVarDefs &) *(CVarDefs*)vars[i]->m_ref, instances, vVisitedClasses);
			}
			continue;
		}
		instances.push_back(vars[i]);
	}
}


HRESULT Store(CVarDefPtr  vardef, IStepNodePtr  val)
{
	if(vardef==NULL)
		return E_INVALIDARG;
	if(val!=NULL)
	{
		val->Parent() = vardef->Owner();
		val->Name() = vardef->Name();  // replace #item with real name - what if multiple references...

	}
	if(vardef->Type() == 	bag_ )
	{
		if(vardef->m_nDimension==1)
		{
			EListT<IStepNodePtr > &list= *(EListT<IStepNodePtr > *)  vardef->m_ref;
			list.push_back( val, vardef->Name());
		}
		else if(vardef->m_nDimension==2)
		{
			EStepArray &outerlist = * (EStepArray *) vardef->m_ref;
			EListT<IStepNodePtr > * innerlist=  outerlist.back().get();
			innerlist->push_back( val, vardef->Name());

		}
		return S_OK;
	}
	if(vardef->Type() == 	index_ )
	{
#if 0
		IStepNodePtr  step   = (IStepNode *)  vardef->m_ref;  // should release it 
		vardef->m_ref = (DWORD) val.get();
		vardef->Classname() = val->Classname();
		vardef->ListClassname() = val->ListClassname();
#else
		EListT<IStepNodePtr > * list= (EListT<IStepNodePtr > *) vardef->_parentListPtr;
		if(list==NULL)
			return E_FAIL;
		int j = list->GetIndex(vardef);
		if(j<0)
			return E_FAIL;
		list->Store(j, val);

#endif
		return S_OK;
	}
	// FIXME: do some type checking to detect bad stores.
	IStepNodePtr & step = * (IStepNodePtr *) vardef->m_ref;
	step  = (IStepNodePtr) val;

	// Type checking: works except for Einteger mix up
#if 0
	if(vardef->ExpressClassname() == step->ExpressClassname())
		return S_OK;
    if(std::find(step->Subtypes().begin(), step->Parents().end(), vardef->Classname()) == step->Parents().end())
	{
		IStepNodePtr pDerivedClass =  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle((LPCTSTR) vardef->Classname()), "");

		if(pDerivedClass->Type() == select_)
		{
			if(std::find(pDerivedClass->Subtypes().begin(), pDerivedClass->Parents().end(), step->Classname()) != pDerivedClass->Parents().end())
				return S_OK;
		}
		DebugBreak();
		return E_FAIL;
	
	}
#endif
	return S_OK;
}
#if 0
void StoreCVarDef(CVarDefPtr  vardef, CString & val)
{
	try {
		//tmp.Append("<%s>", vars[i].m_sName, vars[i].m_ref);
		if(vardef->Type() == 	integer_)
		{
			EInteger * nVal=  * (EInteger **) vardef->m_ref;
			nVal->val = _tstoi(val);
		}
		else if(vardef->Type() == 	logical_)
		{
			EInteger * iVal= * (EInteger **) vardef->m_ref;
			*iVal =  (val=="T") ? 1 : (val=="F") ? 0 : -1;
		}
		else if(vardef->Type() == 	boolean_)
		{
			EInteger * bVal= *(EInteger * *) vardef->m_ref;
			*bVal =  (val=="T") ? 1 : 0;
		}
		else if(vardef->Type() == 	enumeration_)
		{
			EEnum * eVal= * (EEnum **) vardef->m_ref;

			//eVal->GetEnumString(eVal->_nSelection)

		}

		else if(vardef->Type() == 	real_)
		{
			double * rVal= (double *) vardef->m_ref;
			*rVal = _tstof(val);
		}
		else if(vardef->Type() == 	string_)
		{
			//EString * s= *(EString **)vardef->m_ref;
			CString * s= (CString *)vardef->m_ref;
			*s=val;
		}
		else if(vardef->Type() == 	reference_)
		{
			IStepNodePtr step;
			// this is zero, because we have not created the variable on the heap :(
			step =  *(IStepNodePtr *) vardef->m_ref;
			StoreCVarDef(step->m_vars[0], val);

		}

	}
	catch(...)
	{

	}

}
#endif
#if 0
CVarDefPtr GetVarDef(IStepNodePtr pNode , CString itemBranch)
{
	CExpQueryParser items(itemBranch);
	CVarDefPtr vardef;
	if(pNode==NULL)
		return NULL;
	for(int i=0; i< items.Size(); i++)
	{
		int n= items.Index(i); // GetItemIndex(items[i]);

		vardef = CVarDef::FindVarDef(pNode->GetVarDefs(), items[i]);
		if(vardef == NULL)
			return NULL;
		if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
		{
			std::vector<IStepNodePtr > &items= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
			if(n<0 || n>=items.size())
				return NULL;
			pNode = items[n] ;		

		}
		else
		{
			// if(n>=0) // FIXME;
			pNode =  *(IStepNode **) vardef->m_ref;
		}
	}
	return vardef;

}
#endif
#if 0
int GetVarItemSize(IStepNodePtr pNode, CString itemBranch)
{
	CExpQueryParser items (itemBranch);
	int i,n,m;
	if(pNode==NULL)
		return 0;
	for(i=0; i< items.size(); i++)
	{
		n = items.Index(i);

		CVarDefPtr vardef = CVarDef::FindVarDef( pNode->GetVarDefs(), items[i]);
		if(vardef == NULL)
			break;;
		if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
		{
			std::vector<IStepNodePtr > &nodes= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
			if(i==(items.size()-1))
			{
				return nodes.size();
			}
			if(n<0 || n>=nodes.size())
				break;
			pNode = nodes[n] ;		

		}
		else if(vardef->Type() == 	bag_ )
		{
			EListT<IStepNodePtr > &nodes= *(EListT<IStepNodePtr > *)  vardef->m_ref;
			if(i==(items.size()-1))
			{
				return nodes.size();
			}
			if(n<0 || n>=nodes.size())
				break;
			pNode = nodes[n] ;		

		}
		else
		{
			// if(n>=0) // FIXME;
			//DebugBreak();
			pNode =  *(IStepNode **) vardef->m_ref;
			m=-1;
		}
	}
	return -1;

}

#endif
///////////////////////////////////////////////////////////////
static CString MakeItemName(CVarDefPtr vardef)
{
	CString name=vardef->Name();
	name = ExpDemangle(name);
	if(vardef->Type() == index_)
	{
		ReplacePattern(name,_T("["), _T("]"), _T("")); // remove indexing field
		name+=_T("_item");
	}
	return name;
}

static CString MakeClassname(CVarDefPtr vardef)
{
	CString name=vardef->Classname();
	if(vardef->ISymbolBase::IsListType())
	{
		name = vardef->ExpressListClassname();
		name+=_T("_list");
	}
	return name;
}
#if 1
CString DumpCVarDefs(CVarDefs &vars, CString &tabs)
{
	CString tmp;
	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];
		tmp+=DumpCVarDef(vardef, tabs);
	}
	return tmp;

}
#endif
CString DumpCVarDef(CVarDefPtr  vardef, CString &tabs)
{
	CString tmp;
	tabs+="    ";
	OUTPUT_DEBUG_STRING(StrFormat(_T("ENTER: Item = %s Class = %s Type=%d\n"),   vardef->Name(),   vardef->m_sClassname, vardef->Type()));
	if(vardef==NULL)
	{
		OUTPUT_DEBUG_STRING(_T("!!!!!!!Bad vardef\n"));
		return _T("");
	}

	if(vardef->IsSimpleType())
	{
		tmp.AppendFormat(_T("%s<%s classname=\"%s\"> %s </%s>\n"),  tabs, 
			ExpDemangle(vardef->Name()),
			ExpDemangle(vardef->Name()),
			vardef->GetVarString(),
			ExpDemangle(vardef->Name())
			);
	}
	else if(vardef->Type() == 	select_)
	{
		ESelection * sVal= *(ESelection **) vardef->m_ref;
		IStepNodePtr pSel =sVal-> GetSelection();
		CString szSel = DumpCVarDefs(pSel->GetVarDefs());
		tmp.AppendFormat(_T("%s%s"), tabs, szSel);
	}
	else if(vardef->Type() == 	entity_ || (vardef->Type() == 	reference_)  || (vardef->Type() == 	index_) )
	{
		IStepNodePtr step=   vardef->GetStepNodePtr();
		CString szParents = vardef->ExpressClassname() ;
		if (step!=NULL && step->Parents().size()>0)  
			szParents += CString("::") + step->Parents().ToString(L"::");

		CString name = MakeItemName(vardef);
		CString sz;
		if(step==NULL) 
			goto done;
		sz = DumpCVarDefs(step->GetVarDefs(), tabs);

		if(sz.GetLength() >0)
		{
			tmp.AppendFormat(_T("%s<%s "),  tabs, name);
			tmp.AppendFormat(_T(" classname=\"%s\">\n"),  (step!=NULL) ? step->ExpressClassname(): vardef->ExpressClassname()); 
			tmp.AppendFormat(_T("%s"), sz);
			tmp.AppendFormat(_T("%s</%s>\n"),tabs, name);
		}
	}
	else if(vardef->Type() == 	special_)
	{
		tabs=tabs.Mid(4);
		tmp.AppendFormat(_T("%s"), DumpCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref, tabs));
		tabs+="    ";
	}
	else if(vardef->Type() == 	bag_)
	{
		IStepNodePtr step;
		CString sHeader;
		CString sTrailer;
		CString sText;

		EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) vardef->GetStepNodePtr();
		if(list->size()>0)
			step = list->at(0) ;

		CString classname = MakeClassname(vardef);
		sHeader.AppendFormat(_T("%s<%s"), tabs, vardef->Name()); 
		sHeader.AppendFormat(_T(" listclassname=\"%s\""), (step!=NULL)? step->ExpressListClassname() : vardef->ExpressListClassname());
		sHeader.AppendFormat(_T(" classname=\"%s\"> "), classname);
		sTrailer.Format(_T(" </%s>\n"),  vardef->Name()); 
		if(list->ISymbolBase::IsSimpleListType())
		{			
			sText=list->GetVarString(_T(" "));

		}
		else if(vardef->m_nDimension==1)
		{
			sHeader+=_T("\n");
			sTrailer=StrFormat(_T("\n%s"), tabs)+sTrailer;
			for(int j=0; j< list->size(); j++)
			{
				sText+=DumpCVarDef(list->GetVarDefs().at(j), tabs);
#if 0
				step=  list->at(j);
				if(step!=NULL)
				{
					tmp.AppendFormat(_T("%s"), DumpCVarDefs(step->GetVarDefs()));
				}
				else
				{
					tmp.AppendFormat(_T("BAD LIST ITEM %d\n"),j);
					OUTPUT_DEBUG_STRING(StrFormat(_T("ERROR: Bad List <%s baseclassname=\"%s\" classname=\"%s\">\n"), 
						vardef->Name(), vardef->ExpressListClassname(), 
						(step!=NULL)? step->ExpressClassname() : _T("")));

				}
#endif

			}
			
		}
		else if(vardef->m_nDimension==2)
		{
			IStepNodePtr step;
			std::vector< std::vector<IStepNodePtr > > &list = *( std::vector< std::vector<IStepNodePtr > > *) vardef->m_ref;
			if(list.size()>0)
				step = list[0][0] ;
			tmp.AppendFormat(_T("%s<%s baseclassname=\"%s\" classname=\"%s\">\n"), tabs, vardef->Name(), vardef->ExpressListClassname(), (step!=NULL)? step->ExpressClassname() : _T(""));
			for (int i = 0; i<list.size(); i++)
			{
				// how to distinguish  new row/col items
				for (int j = 0; j<list[i].size(); j++) 
				{
					step = list[i][j] ;
					tmp.AppendFormat(_T("%s"), DumpCVarDefs(step->GetVarDefs()));
				}
			}
		}
		if(sText.GetLength() > 0)
			tmp+=sHeader+sText+ sTrailer;
	}
	else
		tmp.AppendFormat(_T("%s<%s>???%x????</S>\n"), tabs, vardef->Name(),  vardef->m_ref, vardef->Name());
	OUTPUT_DEBUG_STRING(StrFormat(_T("EXIT: Item = %s Class = %s\n"),   vardef->Name(),   vardef->m_sClassname));
done:
	tabs=tabs.Mid(4);
	return tmp;

}

IStepNodePtr CreateNode(CVarDefPtr vardef, CString classname)
{
	IStepNodePtr	step =   CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) classname, _T(""));
	if(step==NULL)
		return NULL;
	if(vardef==NULL)
		return NULL;
	step->_refs++;
	
	Store(vardef, step);
	return step;
}

typedef std::vector<CStringVector> CTokenStringTable;
static bool GetListElements(CString & line, CTokenStringTable &items, TCHAR  delimiter=_T(','))
{
	line.TrimLeft();
	int i=0, j=0, k=0;

	if(line.GetLength() < 1)
		return false;

	if(line[0]==_T('('))
		i=j=k=1;

	items.push_back(CStringVector());
	for(; j>0 && i<line.GetLength(); i++)
	{
		if(line[i]==_T('('))
		{
			j++; k++;
			items.push_back(CStringVector());
		}
		else if(line[i]==_T(')'))
		{
			j--;
			if(i-k>0)
				items.back().push_back(line.Mid(k, i-k));
			k=i+1;
		}
		else if(line[i]==_T('\''))
		{
			// skip over commas and parens
			i++;
			for(; i<line.GetLength() && line[i]!=_T('\''); i++);
		}
		else if(line[i]==delimiter)
		{
			items.back().push_back(line.Mid(k, i-k));
			k=i+1;
		}
	}
	line = line.Mid(i+1);
	return true;
}

static 	bool IsKindOf(CString baseclassname, CString derivedclassname)
{
	IStepNodePtr node =  CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) bstr_t(derivedclassname), _T(""));
	if(node==NULL)
		return false;
	if(node->Classname() == baseclassname)
		return true;
	CStringVector::iterator it = find(node->m_parents.begin(), node->m_parents.end(),baseclassname);
	if(it!=node->m_parents.end())
		return true;
	return false;
}

/**
Type check the variable definition against the given input XML string to see if the beginning variable name and class matches
the input xml string. If match return true.
*/

bool TypeCheckXmlParameterList(CVarDefPtr vardef, CString xmlstring)
{
	CQueryPath xml;
	MSXML2::IXMLDOMNodePtr  subnode;
	MSXML2::IXMLDOMElementPtr  element;
	variant_t vAttribute; 
	CString name ;
	CString classname ;

	xml.Read(xmlstring);
	name = MakeItemName(vardef);
	subnode =  xml.QueryNode(StrFormat(_T("%s"), name)); // node->selectSingleNode((LPCTSTR) name);
	if(subnode==NULL)
		return false;
	element=subnode;
	// Must check to see if derived type is being used for "baseclass", e.g., derived "machining_workingstep" for based "executable".
	if(vardef->ISymbolBase::IsListType())
	{
		vAttribute = element->getAttribute(_bstr_t(L"listclassname")); 
		classname = (LPCTSTR)_bstr_t(vAttribute);
		if(IsKindOf(vardef->ListClassname(), classname))
			return true;
	}
	else 
	{
		// FIXME: what if index_ item
		vAttribute = element->getAttribute(_bstr_t(L"classname")); 
		classname = (LPCTSTR)_bstr_t(vAttribute);
		if(IsKindOf(vardef->Classname(), classname))
			return true;
	}
	return false;

}

HRESULT ImportXmlParameterList(CVarDefPtr vardef, CString xmlstring)
{
	CQueryPath xml;
	xml.Read(xmlstring);

	MSXML2::IXMLDOMNodePtr  node;
	MSXML2::IXMLDOMElementPtr  element;
	variant_t vAttribute; 
	CString classname ;
	IStepNodePtr step;
	try
	{
		if (vardef->IsSimpleType())
		{
			CString name = MakeItemName(vardef);
			node= xml.QueryNode(name);
			CString str= (LPCTSTR) node->text;
			vardef->Owner()->SetVarString(str.Trim());

		}
		else if(vardef->Type() == 	entity_ || (vardef->Type() == 	reference_) || (vardef->Type() == 	index_) )
		{
			CString name = MakeItemName(vardef);
			node= xml.QueryNode(StrFormat(_T("%s"), name));
			// See if vardef even in XML. If not, might be null.
			if(node==NULL)
				return S_OK;
			element=node;
			vAttribute = element->getAttribute(_bstr_t(L"classname")); 
			classname = (LPCTSTR)_bstr_t(vAttribute);

			step= CreateNode(vardef, classname.Trim());
			if(step==NULL)
				return E_FAIL;

			CVarDefs vars (step->GetInstanceVars());
			//	CVarDefs vars = step->GetInstanceVars();
			for(int i=0; i< vars.size(); i++)
			{
				CString name = MakeItemName(vars[i]);
				MSXML2::IXMLDOMElementPtr  subnode= node->selectSingleNode((LPCTSTR) name);
				if(subnode==NULL)
					continue;
				_bstr_t bstrXML = subnode->xml;
				ImportXmlParameterList(vars[i], (LPCTSTR) bstrXML);
			}

		}
		else if(vardef->ISymbolBase::IsSimpleListType())
		{
			CString name = MakeItemName(vardef);
			MSXML2::IXMLDOMElementPtr  subnode= xml.QueryNode(name); //node->selectSingleNode((LPCTSTR)name);
			if(subnode==NULL)
				return S_OK;

			CString sXML = (LPCTSTR) subnode->text;
			CTokenStringTable items;
			bool bFlag = GetListElements(sXML, items, _T(' '));
			if(items.size() < 1 || !bFlag)
				return S_OK;
#if 1
			CStringVector strings = items[0];
			CString sCommaXml = strings.ToString(_T(",")); 
			vardef->SetVarString(sCommaXml);
#else
			for(int j=0; j< items.size(); j++)
			{
				if(vardef->m_nDimension==2)
				{
					EStepArray &list = * (EStepArray *) vardef->m_ref;
					list.push_back(new EStepNodeList(), vardef);
				}
				CStringVector strings = items[j];
				for(int k=0; k<strings.size(); k++)
					StoreInstance(vardef, strings[k].Trim());
			}
#endif

		}

		else if(vardef->ISymbolBase::IsListType())
		{

#if 1
			CString name = MakeItemName(vardef);
			MSXML2::IXMLDOMElementPtr  subnode =  xml.QueryNode(StrFormat(_T("%s"), name)); // node->selectSingleNode((LPCTSTR) name);
			if(subnode==NULL)
				return S_OK;

			// Don't have to create the list - already exists. Need to get the node pointer
			EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) vardef->GetStepNodePtr();

			// Now we go thru the list pushing the items onto the list
			MSXML2::IXMLDOMNodeListPtr  subnodes= subnode->selectNodes((LPCTSTR) StrFormat(_T("%s_item"), name));
			if(subnodes==NULL)
				return S_OK;
			
			list->clear(); // need to make sure the list is empty first... in case of overwrite...
			for(int i=0; i<subnodes->Getlength(); i++)
			{
				CVarDefPtr subvardef;
				MSXML2::IXMLDOMNodePtr item = subnodes->Getitem(i);
				_bstr_t bstrXML = item->xml;
				element=item;
				vAttribute = element->getAttribute(_bstr_t(L"classname")); 
				// FIXME: check if vAttrbute is bad..
				classname=(LPCTSTR)_bstr_t(vAttribute);
				CreateNode(vardef, classname.Trim());
				subvardef=list->GetVarDefs().back();
				ImportXmlParameterList(subvardef, (LPCTSTR) bstrXML);
			}
#endif
		}
	}
	catch(_com_error err)
	{
		OutputDebugString(err.ErrorMessage());

		return E_FAIL;
	}
	return S_OK;
}


extern bool IsSimpleType(CString classname)
{
	IStepNodePtr pDerivedClass=  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(classname), _T(""));
	if(pDerivedClass==NULL)
		return 0;
	return pDerivedClass->IsSimpleType();

}
CStringVector ClassSupertypeHierarchy(CString classname)
{
	IStepNodePtr pDerivedClass=  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(classname), _T(""));
	if(pDerivedClass==NULL)
		return CStringVector();
	return pDerivedClass->GetSupertypesChain();

}

void CloneCVarDefs(CVarDefs &fromvars, CVarDefs &tovars, int bFirst)
{
	for(int i=0; i<fromvars.size(); i++)
		CloneCVarDef(fromvars[i], tovars[i]);

}
void CloneCVarDef(CVarDefPtr  fromvardef, CVarDefPtr  tovardef)
{
	if(fromvardef==NULL)
	{
		OUTPUT_DEBUG_STRING(_T("!!!!!!!Bad vardef\n"));
		return;
	}

	if(fromvardef->IsSimpleType())
	{
		if(fromvardef->Owner()==NULL)
		{
			tovardef->Owner()=NULL;
			return;
		}
		CString fromstring = fromvardef->Owner()->GetVarString();
		tovardef->Owner()->SetVarString(fromstring);
	}

	else if(fromvardef->Type() == 	bag_ )
	{
		if(fromvardef->m_nDimension==2)
		{
			DebugBreak();
			return;
		}
		EListT<IStepNodePtr> * fromlist=  (EListT<IStepNodePtr> *) fromvardef->m_ref;
		EListT<IStepNodePtr> * tolist=  (EListT<IStepNodePtr> *) tovardef->m_ref;

		if(fromlist->IsASimpleListType(fromvardef->m_sListClassname) )
		{
			CString fromstring =  fromlist->GetVarString(_T(","));
			tolist->SetVarString(fromstring);
			return;
		}

		CString szClassname = ExpDemangle(fromvardef->m_sListClassname);

		for (int i = 0; i<fromlist->size(); i++)
		{
			IStepNodePtr fromstep = fromlist->at(i);
			CString szClassname = ExpDemangle(fromstep->Classname());
			IStepNodePtr tostep =  (IStepNode *) CClassGenerators::gClassGenerators.CreateClass(szClassname,_T("")).get();
			CloneCVarDefs(fromstep->GetVarDefs(), tostep->GetVarDefs());

		}
	}
	else if(fromvardef->Type() == 	special_)
	{
		CloneCVarDefs((CVarDefs) *(CVarDefs*)fromvardef->m_ref, (CVarDefs) *(CVarDefs*)tovardef->m_ref );
	}
	else if(fromvardef->Type() == 	select_)
	{
		ESelection * sfromVal	= *(ESelection **) fromvardef->m_ref;
		ESelection * stoVal		= *(ESelection **) tovardef->m_ref;

		// creation of selection automatically selects one of several alternative classes
		IStepNodePtr pFromSel	=	sfromVal-> GetSelection();
		IStepNodePtr pToSel		=	stoVal-> GetSelection();

		CloneCVarDefs(pFromSel->GetVarDefs(), pToSel->GetVarDefs());
	}
	else if((fromvardef->Type() == 	index_ ) )
	{
		IStepNodePtr fromstep =  (IStepNode *) fromvardef->m_ref;
		IStepNodePtr tostep=  (IStepNode*)  tovardef->m_ref;
		// this should never be null
		if(fromstep==NULL) 
			return;
		CloneCVarDefs(fromstep->GetVarDefs(), tostep->GetVarDefs());
	}
	else if(fromvardef->Type() == 	entity_ || (fromvardef->Type() == 	reference_) || (fromvardef->Type() == 	index_ ) )
	{
		IStepNodePtr fromstep=  *(IStepNode **) fromvardef->m_ref;
		if(fromstep==NULL) 
			return;

		CString szClassname = ExpDemangle(fromstep->Classname());
		IStepNodePtr tostep  =	(IStepNode *) CClassGenerators::gClassGenerators.CreateClass(szClassname,_T("")).get();
		IStepNodePtr & node = * (IStepNodePtr *) tovardef->m_ref;
		node=tostep;
		CloneCVarDefs(fromstep->GetVarDefs(), tostep->GetVarDefs());

	}
}


IStepNodePtr GetThis(CVarDefPtr  vardef)
{
	if(vardef==NULL)
		return NULL;
	try {
		if(vardef->Type() == 	special_)
		{
			CVarDefs & vars = *(CVarDefs *)vardef->m_ref;
			return vars[0]->Owner();
		}
		else if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_) )
		{
			return *(IStepNode **) vardef->m_ref;
		}
		else if(vardef->Type() == 	list_item_  )
		{
			return (IStepNode *) vardef->m_ref;
		}
		// assume simple type
		else return NULL;

	}
	catch(...)
	{

	}
	return NULL;
}


