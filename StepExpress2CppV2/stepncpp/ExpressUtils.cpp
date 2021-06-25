//
// ExpressUtils.cpp
//
#include "stdafx.h"
#include "ExpressUtils.h"
#include "boost/lexical_cast.hpp"
#include <stdarg.h>
//array_type A(boost::extents[3][4][2]);
CClassGenerators  CClassGenerators::gClassGenerators;

int nDumpIndent=0;
//std::map<CString,IStepNC *> _entities;
EReal::EReal() { Init() ; val=0.0; }
EInteger::EInteger(){ Init() ; val=0; }
EString::EString(){ Init() ; }
EEnum::EEnum(){ Init() ; }
ESelection::ESelection() { Init() ; }
EBoolean::EBoolean(){ Init(); _nSelection=0; }

static IStepNodePtr CreateExpressBaseClass(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname=="Estring") return (IStepNodePtr) new EString;
	if(classname=="Einteger") return (IStepNodePtr) new EInteger;
	if(classname=="Enumber") return (IStepNodePtr) new ENumber;
	if(classname=="Ereal") return (IStepNodePtr) new EReal;
	if(classname=="Elogical") return (IStepNodePtr) new ELogical;
	if(classname=="Ebinary") return (IStepNodePtr) new EBinary;
	if(classname=="Eenum") return (IStepNodePtr) new EEnum;
	if(classname=="Eboolean") return (IStepNodePtr) new EBoolean;

	return NULL;
}
static int cCcCc = CClassGenerators::gClassGenerators.AddGenerator(&CreateExpressBaseClass);

CString CVarDef::GetVarString(CString fmt) 
{
	// FIXME FIXME FIXME
	if(Type() == 	set_ || Type() ==  list_)
	{
		// FIXME: check for size =0 then return $
		return "";

	}

	if(IsSimpleType())
	{
		return _owner->GetVarString();
	}
	if(Type() == 	bag_)
	{
		EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) m_ref;
		return list->GetVarString();
	}
	if(Type() == 	index_)
	{
		IStepNodePtr step=  (IStepNode *) m_ref; 
		return step->GetVarString();
	}
	IStepNodePtr step=  *(IStepNode **) m_ref;
	if(step==NULL)
		return "$";

	return "";
}
void BuildInstanceDef(CVarDefs & vars, CVarDefs &instances, CStringVector &vVisitedClasses)
{
	for(int i=0; i<vars.size(); i++)
	{
		if(vars[i]->_eType == special_)
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
StepNodeType GetBaseType(CVarDefs & vars)
{
	if(vars.size() < 1)
		return unknown_;
	if(vars.size() > 1)
		return unknown_;
	if(vars[0]->Type() == special_)
	{
		return GetBaseType((CVarDefs &) *(CVarDefs*)vars[0]->m_ref);
	}
	if(vars[0]->Type()==entity_ || vars[0]->Type() == reference_)
	{
		IStepNodePtr node = *(IStepNode **) vars[0]->m_ref;
		if(node==NULL)
			node = CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(vars[0]->Classname()), "");
		if(node==NULL)
			DebugBreak();
		return GetBaseType(node->GetVarDefs());
	}
	if( ( vars[0]->Type()>=integer_  &&  vars[0]->Type()<= logical_) || ( vars[0]->Type()<= enumeration_))
		return vars[0]->Type();
	return unknown_;

}

HRESULT Store(CVarDefPtr  vardef, IStepNodePtr  val)
{
	if(vardef==NULL)
		return E_INVALIDARG;
	if(vardef->Type() == 	set_ || vardef->Type() ==  list_ )
	{
		if(vardef->_nDimension==1)
		{
			std::vector<IStepNodePtr > &list= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
			list.push_back( val);
		}
		else if(vardef->_nDimension==2)
		{
			::DebugBreak();
		}

		//should be created, just append to back
		return S_OK;
	}
	else if(vardef->Type() == 	bag_ )
	{
		if(vardef->_nDimension==1)
		{
			EListT<IStepNodePtr > &list= *(EListT<IStepNodePtr > *)  vardef->m_ref;
			list.push_back( val);
		}
		return S_OK;
	}
	// FIXME: do some type checking to detect bad stores.
	IStepNodePtr & step = * (IStepNodePtr *) vardef->m_ref;
	step  = (IStepNodePtr) val;
	return S_OK;
}
void Load(CVarDefs & vars, StepVars & vals)
{
	for(int i=0; i<vals.size(); i++)
	{		
		CString name = vals[i].get<0>();
		IStepNodePtr val = vals[i].get<1>();
		CVarDefPtr  vardef = (CVarDefPtr ) CVarDef::FindVarDef(vars, name);


		//	StoreCVarDef(vardef, val);
		IStepNodePtr * step = (IStepNodePtr *) vardef->m_ref;
		// *(step) is zero, because we have not created the variable on the heap :(
		if(vardef->Type() == 	set_ || vardef->Type() ==  list_ )
		{
			if(vardef->_nDimension==1)
			{
				std::vector<IStepNodePtr> &list= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
				list.push_back((IStepNodePtr) val);
			}
			//should be created, just append to back
			continue;
		}

		*(step)  = (IStepNodePtr) val;
		//intrusive_ptr_add_ref(*step);

	}

}


void StoreCVarDef(CVarDefPtr  vardef, CString & val)
{
	try {
		//tmp.Append("<%s>", vars[i].m_sName, vars[i].m_ref);
		if(vardef->Type() == 	integer_)
		{
			EInteger * nVal=  * (EInteger **) vardef->m_ref;
			nVal->val = boost::lexical_cast<long>(val);
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
			*rVal = boost::lexical_cast<double>(val);
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
			StoreCVarDef(step->vars[0], val);

		}

	}
	catch(...)
	{

	}

}



int GetItemIndex(CString & item)
{
	int n=-1;
	CStringVector items = CStringVector::Tokenize(item, "[]");
	if(items.size() < 2)
	{
		return n;
	}
	else if(items.size() < 3)
	{
		item=items[0];
		n = atoi(items[1]);
	}
	return n; 


}
IStepNodePtr GetVarItem(IStepNodePtr pNode , CString itemBranch)
{
	CStringVector items = CStringVector::Tokenize(itemBranch, "/");
	for(int i=0; i< items.size(); i++)
	{
		int n= GetItemIndex(items[i]);

		CVarDefPtr vardef = CVarDef::FindVarDef( pNode->GetVarDefs(), items[i]);
		if(vardef == NULL)
			return NULL;
		if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
		{
			std::vector<IStepNodePtr > &items= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
			if(n<0 || n>=items.size())
				return NULL;
			pNode = items[n] ;		

		}
		else		if(vardef->Type() == 	bag_ )
		{
			EListT<IStepNodePtr > &items= *(EListT<IStepNodePtr > *)  vardef->m_ref;
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
	return pNode;

}

CVarDefPtr GetVarDef(IStepNodePtr pNode , CString itemBranch)
{
	CStringVector items = CStringVector::Tokenize(itemBranch, "/");
	CVarDefPtr vardef;
	if(pNode==NULL)
		return NULL;
	for(int i=0; i< items.size(); i++)
	{
		int n= GetItemIndex(items[i]);

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
int GetVarItemSize(IStepNodePtr pNode, CString itemBranch)
{
	CStringVector items = CStringVector::Tokenize(itemBranch, "/");
	int i,n,m;
	if(pNode==NULL)
		return 0;
	for(i=0; i< items.size(); i++)
	{
		n = GetItemIndex(items[i]);

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
///////////////////////////////////////////////////////////////

static CString tabs("");
CString DumpCVarDefs(CVarDefs &vars, int bFirst)
{
	CString tmp;
	if(bFirst!=0)
		tabs="";
	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];
		tmp+=DumpCVarDef(vardef);
	}
	return tmp;

}
CString DumpCVarDef(CVarDefPtr  vardef)
{
	CString tmp;
	tabs+="  ";
	OUTPUT_DEBUG_STRING(StrFormat("ENTER: Item = %s Class = %s Type=%d\n",   vardef->Name(),   vardef->m_sClassname, vardef->Type()));
	if(vardef==NULL)
	{
		OUTPUT_DEBUG_STRING("!!!!!!!Bad vardef\n");
	}

	if(vardef->Type() == 	integer_)
	{
		EInteger * nVal=  * (EInteger **) vardef->m_ref;
		if(nVal==NULL)
		{
			if(!vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s logical or boolean\n", vardef->Name()));
			goto done;
		}	

		tmp.AppendFormat("%s<%s> %d </%s>\n",  tabs,  vardef->Name(), nVal->val,  vardef->Name());
		//tmp.AppendFormat("%d",  nVal->val);
	}
	else if(vardef->Type() == 	logical_ ||  vardef->Type() == 	boolean_)
	{
		EInteger * iVal= * (EInteger **) vardef->m_ref;
		if(iVal==NULL)
		{
			if( !vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s logical or boolean\n", vardef->Name()));
			goto done;
		}	

		long val = iVal->val;
		CString str = (val==0) ? "FALSE" : (val==1) ? "TRUE" : "UNKOWN"; 
		tmp.AppendFormat("%s<%s> %s </%s>\n", tabs,   vardef->Name(), str,  vardef->Name());
		//tmp.AppendFormat("%s", str);
	}

	else if(vardef->Type() == 	enumeration_)
	{
		EEnum * eVal=  (EEnum *) vardef->m_ref;
		if(eVal==NULL )
		{
			if( !vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s empty non-optional logical or boolean\n", vardef->Name()));
			goto done;
		}	
		tmp.AppendFormat("%s<%s> %s </%s>\n",   tabs, vardef->Name(), eVal->GetEnum2String(eVal->_nSelection),  vardef->Name() );
		//tmp.AppendFormat("%s",  eVal->GetEnum2String(eVal->_nSelection));
	}
	else if(vardef->Type() == 	select_)
	{
		ESelection * sVal= *(ESelection **) vardef->m_ref;
		IStepNodePtr pSel =sVal-> GetSelection();
		CString szenum = DumpCVarDefs(pSel->GetVarDefs());
		tmp.AppendFormat("%s%s", tabs, szenum);
	}
	//else if(vars[i].Type() == 	select_)
	//{
	//	real * dVal=(real *) vars[i].m_ref;
	//	tmp.Append("<%s>  %f </%s>\n",  vars[i].m_sName, *dVal, vars[i].m_sName );
	//}
	else if(vardef->Type() == 	real_)
	{
		// optional real not handled properly yet.
		double  rVal= *(double *) vardef->m_ref;
		//CString sVal = (rVal!=NULL) ? StrFormat("%f", rVal->val)  : "$";
		tmp.AppendFormat("%s<%s> %f </%s>\n",  tabs, vardef->Name(), rVal,  vardef->Name() );
		//tmp.AppendFormat("%8.3f",  rVal);
	}
	else if(vardef->Type() == 	string_)
	{
		//EString * s= *(EString **)vardef->m_ref;
		CString * s= (CString *)vardef->m_ref;
		if(s==NULL)
		{
			if(!vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s empty non-optional string\n", vardef->Name()));
			goto done;
		}
		tmp.AppendFormat("%s<%s> %s </%s>\n", tabs, vardef->Name(),  *s ,  vardef->Name());
		//tmp.AppendFormat("%s",   *s );
	}
	else if(vardef->Type() == 	entity_ || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		CString szParents = vardef->Classname() ;
		if (step!=NULL && step->parents.size()>0)  
			szParents += CString("::") + step->parents.ToString(L"::");
		tmp.AppendFormat("%s<%s classname=\"%s\">",  tabs, vardef->Name(), szParents); 
		CString sz;
		if(step!=NULL) 
		{
			sz = DumpCVarDefs(step->GetVarDefs());
			if(sz.Find("\n")>=0)
				tmp.AppendFormat("\n", tabs);
			tmp.AppendFormat("%s", sz);
		}
		if(sz.Find("\n")>=0)
			tmp.AppendFormat("%s", tabs);
		tmp.AppendFormat("</%s>\n",vardef->Name());
	}


	else if(vardef->Type() == 	special_)
	{
		//tmp.Append("<%s>\n", vars[i].m_sClassname);
		//nDumpIndent++;
		tmp.AppendFormat("%s", DumpCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref));
		//nDumpIndent--;
		//tmp.Append("</%s>\n", vars[i].m_sClassname);

	}
	else if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
	{
		//		std::vector<IStepNC *> * items=(std::vector<IStepNC *> *)  vars[i].m_ref;
		if(vardef->_nDimension==1)
		{
			IStepNodePtr step;
			std::vector<IStepNodePtr > &list= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
			if(list.size()>0)
				step = list[0] ;
			// FIXME: step derived classname could change between list items. ??
			tmp.AppendFormat("%s<%s baseclassname=\"%s\" classname=\"%s\">\n", tabs, vardef->Name(), vardef->ListClassname(), (step!=NULL)? step->Classname() : "");
			for (int i = 0; i<list.size(); i++)
			{
				step = list[i] ;
				if(step!=NULL)
				{
					tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
				}
				else
				{
					tmp.AppendFormat("BAD LIST ITEM %d\n",i);
					OUTPUT_DEBUG_STRING(StrFormat("ERROR: Bad List <%s baseclassname=\"%s\" classname=\"%s\">\n", vardef->Name(), vardef->ListClassname(), (step!=NULL)? step->Classname() : ""));

				}
			}

		}
		else  if(vardef->_nDimension==2)
		{
			IStepNodePtr step;
			std::vector< std::vector<IStepNodePtr > > &list = *( std::vector< std::vector<IStepNodePtr > > *) vardef->m_ref;
			if(list.size()>0)
				step = list[0][0] ;
			tmp.AppendFormat("%s<%s baseclassname=\"%s\" classname=\"%s\">\n", tabs, vardef->Name(), vardef->ListClassname(), (step!=NULL)? step->Classname() : "");
			for (int i = 0; i<list.size(); i++)
			{
				// how to distinguish  new row/col items
				for (int j = 0; j<list[i].size(); j++) 
				{
					step = list[i][j] ;
					tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
				}
			}
		}
		else if(vardef->_nDimension>2)
		{
			OUTPUT_DEBUG_STRING("Too many list dimensions\n");
			::DebugBreak();
		}
		tmp.AppendFormat("%s</%s>\n",tabs, vardef->Name());


	}
	else
		tmp.AppendFormat("%s<%s>???%x</S>\n", tabs, vardef->Name(),  vardef->m_ref, vardef->Name());
	OUTPUT_DEBUG_STRING(StrFormat("EXIT: Item = %s Class = %s\n",   vardef->Name(),   vardef->m_sClassname));
done:
	tabs=tabs.Mid(0, tabs.GetLength()-2);
	return tmp;

}

//IStepList getElementsById(CString tagname)
//{
//
//}

CVarDefs IStepNode::getElementsByTagName(CString tagname)
{
	CVarDefs list;
	CStringVector visited;
	getElementsByCVarDefs(this->GetVarDefs(), visited, tagname, list);
	return list;
}


void IStepNode::getElementsByCVarDefs(CVarDefs &vars, CStringVector &visited, CString tagname, CVarDefs & list)
{
	CString tmp;
	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];
		getElementByCVarDef(vardef, visited, tagname,  list);
	}

}
void IStepNode::getElementByCVarDef(CVarDefPtr vardef, CStringVector &visited, CString tagname, CVarDefs & list)
{

	visited.push_back('/'+ vardef->Name());
	OUTPUT_DEBUG_STRING(StrFormat("**ENTER: %s  : %s \n",     visited.ToString(""), vardef->Name()));

	// special
	if((vardef->Name() == tagname) || (ExpDemangle( vardef->m_sClassname)== tagname))
	{
			list.push_back(vardef);
			goto done;

	}
	else if(vardef->Name() == tagname)
	{
		IStepNodePtr node = CClassGenerators::gClassGenerators.CreateClass(vardef->Classname(), ""); 
		if(node && node->IsKindOf(tagname))
		{
			list.push_back(vardef);
			goto done;
		}

	}
	else if(vardef->ListClassname() == tagname)
	{
		if(vardef->ListClassname()!="")
		{
			IStepNodePtr node = CClassGenerators::gClassGenerators.CreateClass(vardef->ListClassname(), ""); 

			if(node && node->IsKindOf(tagname))
			{
				list.push_back(vardef);
				goto done;
			}
		}

	}
	//if(vardef->Name()=="Eworkingstep")
	//	DebugBreak();

	if(vardef->Type() == 	special_)
	{
		getElementsByCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref , visited, tagname,  list);
	}
	else if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr child = *(IStepNode **) vardef->m_ref;
		if(child==NULL)
			goto done;
		getElementsByCVarDefs(child->GetVarDefs(), visited, tagname,  list);
	}
	else if((vardef->Type() == 	set_) || (vardef->Type() ==  list_))
	{
		if(vardef->_nDimension==1)
		{
			std::vector<IStepNodePtr > &items= *(std::vector<IStepNodePtr> *)  vardef->m_ref;

			for (int i = 0; i<items.size(); i++)
			{
				if(items[i]==NULL) /* could be optional - but then how appended to list?*/
					continue;
				if(items[i]->Classname() == tagname || items[i]->IsKindOf(tagname) )
				{
					CVarDefPtr listvardef = new CVarDef(vardef->GetOwnerPtr(), vardef->Name(), list_item_,(DWORD) items[i].get(), items[i]->Classname());
					list.push_back(listvardef);
				}
				getElementsByCVarDefs( items[i]->GetVarDefs(), visited, tagname,  list);
			}
		}
	}
done:
	OUTPUT_DEBUG_STRING(StrFormat("**EXIT: %s  : %s \n",     visited.ToString(""), vardef->Name()));
	visited.pop_back();

}


////////////////////////////////////////////////////////////////
int IStepNode::selectElementsByTagName(VarTable &table,CStringVector columns, CString fromnode,  int bDistinct)
{
	int i,j, k;
	VarList varlist;
	table.clear();
	CVarDefs list = getElementsByTagName(fromnode);
#if 1
	VarList values;
#else
	std::vector<VarList> values;
#endif
	for(j=0, k=0; k< list.size(); k++)
	{
		IStepNode  * node = GetThis(list[k]).get();
		values.clear();
		for(i=0; i< columns.size(); i++)
		{
			varlist.clear();
			CStringVector fields=CStringVector::Tokenize(columns[i],".");

			// Case where already a simple type
			if(node==NULL)
				continue;

			getItemByCVarDefs(node->GetVarDefs(),  fields, varlist);
#if 1
			if(varlist.size()>0)
			{
				values.push_back(varlist[0]);
			}
			else
			{
				values.push_back("N/A");

			}
#else
			values.push_back(varlist);
#endif
		}
		if(bDistinct && table.isDuplicate(values))
			continue;
		table[j++]=values;
	}
	return 0;
}

bool IStepNode::getItemByCVarDefs(CVarDefs &vars,  CStringVector tagnames, VarList & list)
{

	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];

		if(vardef->Type() == 	special_)
		{
			if(getItemByCVarDefs(*(CVarDefs *)vardef->m_ref, tagnames,  list))
				return true;
		}
		if(vardef->Name() == tagnames[0])
		{
			if(tagnames.size() == 1 )
			{
				// get value if simpletype
				list.push_back(GetVarDefVal( vardef));
				return true;
			}
			tagnames.erase(tagnames.begin());
			if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_))
			{
				IStepNodePtr child = *(IStepNode **) vardef->m_ref ; 
				if(child==NULL)
					return false;
				return getItemByCVarDefs(child->GetVarDefs(),  tagnames,  list);
			}
			// FIXME: could be list - would need to create a table of instances.
			if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
			{
				std::vector<IStepNodePtr > &items= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
				bool bFlag=false;
				for (int i = 0; i<items.size(); i++)
				{
					IStepNodePtr step = items[i] ;		
					bFlag |=getItemByCVarDefs(step->GetVarDefs(),  tagnames,  list);

				}
				return bFlag;
			}
		}
	}
	return false;
}
_variant_t IStepNode::GetVarDefVal(CVarDefPtr  vardef)
{
	if(vardef==NULL)
	{
		OUTPUT_DEBUG_STRING("WARNING IStepNode::GetVarDefVal - Bad CVarDefPtr for  vardef\n");
		return _variant_t();
	}

	if(vardef->Type() == 	integer_)
	{
		EInteger * nVal=  * (EInteger **) vardef->m_ref;
		if(nVal==NULL)
					return _variant_t("$");
		return _variant_t((int)  nVal->val);
	}
	else if(vardef->Type() == 	logical_ ||  vardef->Type() == 	boolean_)
	{
		EInteger * iVal= * (EInteger **) vardef->m_ref;
		if(iVal==NULL)
		{
					return _variant_t("$");
		}	

		long val = iVal->val;
		CString str = (val==0) ? "FALSE" : (val==1) ? "TRUE" : "UNKOWN"; 
		return _variant_t((const char *)  str);
		//tmp.AppendFormat("%s", str);
	}
	else if(vardef->Type() == 	enumeration_)
	{
		EEnum * eVal=  (EEnum *) vardef->m_ref;
		if(eVal==NULL )
			return _variant_t((const char *)"$");
		return _variant_t((const char *)  eVal->GetEnum2String(eVal->_nSelection).MakeUpper());
	}
	else if(vardef->Type() == 	real_)
	{
		return _variant_t((double)  *(double *) vardef->m_ref);
	}
	//else if(vardef->Type() == 	select_)
	//{
	//	ESelection * sVal= *(ESelection **) vardef->m_ref;
	//	IStepNodePtr pSel =sVal-> GetSelection();
	//	CString szenum = DumpCVarDefs(pSel->GetVarDefs());
	//	tmp.AppendFormat("%s, ", szenum);
	//}
	else if(vardef->Type() == 	string_)
	{
		CString * s= (CString *)vardef->m_ref;
		if(s==NULL)
			return _variant_t((const char *)"$");
		return _variant_t((const char *) *s);
	}
	else if( (vardef->Type() == 	entity_)  || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step==NULL)
			return 0;
		if(step->vars.size() > 0)
			return GetVarDefVal(step->GetVarDef(0));
		else
		{
			// honestly maybe typedefs should be made into separate classes with special_ inheritance chain.
			return _bstr_t(step->GetVarString());
		}
	}
	else if(vardef->Type() == 	list_item_   )
	{
		IStepNodePtr step=  (IStepNode *) vardef->m_ref;
		return GetVarDefVal(step->GetVarDef(0));
	}
	//else if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
	//{
	//	//		std::vector<IStepNC *> * items=(std::vector<IStepNC *> *)  vars[i].m_ref;
	//	tmp.AppendFormat("(");
	//	if(vardef->_nDimension==1)
	//	{

	//		std::vector<IStepNodePtr > &list= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
	//		for (int i = 0; i<list.size(); i++)
	//		{
	//			IStepNodePtr step = list[i] ;
	//			tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
	//		}

	//	}
	//	else  if(vardef->_nDimension==2)
	//	{
	//		std::vector< std::vector<IStepNodePtr > > &list = *( std::vector< std::vector<IStepNodePtr > > *) vardef->m_ref;
	//		for (int i = 0; i<list.size(); i++)
	//		{
	//			// how to distinguish  new row/col items
	//			for (int j = 0; j<list[i].size(); j++) 
	//			{
	//				IStepNodePtr step = list[i][j] ;
	//				tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
	//			}
	//		}
	//	}
	//	else if(vardef->_nDimension>2)
	//	{
	//		OUTPUT_DEBUG_STRING("Too many list dimensions\n");
	//		::DebugBreak();
	//	}
	//	tmp.Trim();
	//	tmp=tmp.Mid(0,tmp.GetLength()-1); // remove last ,
	//	tmp.AppendFormat("), ");


	//}
	return _variant_t(VT_NULL);
}


IStepNodePtr GetThis(CVarDefPtr  vardef)
{
	if(vardef==NULL)
		return NULL;
	try {
		if(vardef->Type() == 	special_)
		{
			CVarDefs & vars = *(CVarDefs *)vardef->m_ref;
			return vars[0]->GetOwnerPtr();
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


extern bool IsSimpleType(CString classname)
{
	IStepNodePtr pDerivedClass=  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(classname), "");
	if(pDerivedClass==NULL)
		return 0;
	return pDerivedClass->IsSimpleType();

}
CStringVector ClassSupertypeHierarchy(CString classname)
{
	IStepNodePtr pDerivedClass=  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(classname), "");
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
		OUTPUT_DEBUG_STRING("!!!!!!!Bad vardef\n");
		return;
	}

	if(fromvardef->IsSimpleType())
	{
		if(fromvardef->_owner==NULL)
		{
			tovardef->_owner=NULL;
			return;
		}
		CString fromstring = fromvardef->_owner->GetVarString();
		tovardef->_owner->SetVarString(fromstring);
	}

	else if(fromvardef->Type() == 	bag_ )
	{
		if(fromvardef->_nDimension==2)
		{
			DebugBreak();
			return;
		}
		EListT<IStepNodePtr> * fromlist=  (EListT<IStepNodePtr> *) fromvardef->m_ref;
		EListT<IStepNodePtr> * tolist=  (EListT<IStepNodePtr> *) tovardef->m_ref;

		if(fromlist->IsSimpleListType(fromvardef->_sListClassname) )
		{
			CString fromstring =  fromlist->GetVarString(",");
			tolist->SetVarString(fromstring);
			return;
		}

		CString szClassname = ExpDemangle(fromvardef->_sListClassname);

		for (int i = 0; i<fromlist->size(); i++)
		{
			IStepNodePtr fromstep = fromlist->at(i);
			CString szClassname = ExpDemangle(fromstep->Classname());
			IStepNodePtr tostep =  (IStepNode *) CClassGenerators::gClassGenerators.CreateClass(szClassname,"").get();
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
		IStepNodePtr tostep  =	(IStepNode *) CClassGenerators::gClassGenerators.CreateClass(szClassname,"").get();
		IStepNodePtr & node = * (IStepNodePtr *) tovardef->m_ref;
		node=tostep;
		CloneCVarDefs(fromstep->GetVarDefs(), tostep->GetVarDefs());

	}
#if 0
	if(fromvardef->Type() == 	integer_ || vardef->Type() == 	logical_)
	{
		EInteger * nfromVal	=  * (EInteger **) fromvardef->m_ref;
		EInteger * ntoVal	=  * (EInteger **) tovardef->m_ref;
		ntoVal=NULL;
		if(nfromVal==NULL)
			return ;
		if(ntoVal==NULL)
			ntoVal = new EInteger;

		ntoVal->val = nfromVal->val;
		return;

	}
	else if( vardef->Type() == 	boolean_)
	{
		EBoolean * nfromVal	=  * (EBoolean **) fromvardef->m_ref;
		EBoolean * ntoVal	=  * (EBoolean **) tovardef->m_ref;
		ntoVal=NULL;
		if(nfromVal==NULL)
			return ;
		if(ntoVal==NULL)
			ntoVal = new EBoolean;

		ntoVal->val = nfromVal->val;
		return;

	}	

	else if(vardef->Type() == 	enumeration_)
	{
		EEnum * nfromVal	=  (EEnum *) fromvardef->m_ref;
		EEnum * ntoVal		=  (EEnum *) tovardef->m_ref;

		ntoVal=NULL;

		if(nfromVal==NULL )
			return ;

		if(ntoVal==NULL)
			ntoVal = new EEnum;
		ntoVal->_nSelection = nfromVal->_nSelection;
	}
	else if(vardef->Type() == 	real_)
	{
		// optional real not handled properly yet.
		double  rFromVal	= *(double *) fromvardef->m_ref;
		double  rToVal		= *(double *) tovardef->m_ref;

		rToVal=rFromVal;

	}
	else if(vardef->Type() == 	string_)
	{
		CString * nfromVal		=  (CString *)fromvardef->m_ref;
		CString * ntoVal		=  (CString *)tovardef->m_ref;
		*ntoVal=NULL;
		if(nfromVal==NULL)
			return;
		*ntoVal=* nfromVal;
	}
#endif





	//else if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
	//{
	//	//		std::vector<IStepNC *> * items=(std::vector<IStepNC *> *)  vars[i].m_ref;
	//	if(vardef->_nDimension==1)
	//	{
	//		IStepNodePtr step;
	//		std::vector<IStepNodePtr > &list= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
	//		if(list.size()>0)
	//			step = list[0] ;
	//		// FIXME: step derived classname could change between list items. ??
	//		tmp.AppendFormat("%s<%s baseclassname=\"%s\" classname=\"%s\">\n", tabs, vardef->Name(), vardef->ListClassname(), (step!=NULL)? step->Classname() : "");
	//		for (int i = 0; i<list.size(); i++)
	//		{
	//			step = list[i] ;
	//			if(step!=NULL)
	//			{
	//				tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
	//			}
	//			else
	//			{
	//				tmp.AppendFormat("BAD LIST ITEM %d\n",i);
	//				OUTPUT_DEBUG_STRING(StrFormat("ERROR: Bad List <%s baseclassname=\"%s\" classname=\"%s\">\n", vardef->Name(), vardef->ListClassname(), (step!=NULL)? step->Classname() : ""));

	//			}
	//		}

	//	}
	//	else  if(vardef->_nDimension==2)
	//	{
	//		IStepNodePtr step;
	//		std::vector< std::vector<IStepNodePtr > > &list = *( std::vector< std::vector<IStepNodePtr > > *) vardef->m_ref;
	//		if(list.size()>0)
	//			step = list[0][0] ;
	//		tmp.AppendFormat("%s<%s baseclassname=\"%s\" classname=\"%s\">\n", tabs, vardef->Name(), vardef->ListClassname(), (step!=NULL)? step->Classname() : "");
	//		for (int i = 0; i<list.size(); i++)
	//		{
	//			// how to distinguish  new row/col items
	//			for (int j = 0; j<list[i].size(); j++) 
	//			{
	//				step = list[i][j] ;
	//				tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
	//			}
	//		}
	//	}
	//	else if(vardef->_nDimension>2)
	//	{
	//		OUTPUT_DEBUG_STRING("Too many list dimensions\n");
	//		::DebugBreak();
	//	}
	//	tmp.AppendFormat("%s</%s>\n",tabs, vardef->Name());


	//}


}
