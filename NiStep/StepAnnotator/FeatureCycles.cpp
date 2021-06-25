//
// FeatureCycles.cpp
//

// DISCLAIMER: 
//  This software was produced by the National Institute of Standards 
//  and Technology (NIST), an agency of the U.S. government, and by statute is 
//  not subject to copyright in the United States.  Recipients of this 
//  software assume all responsibility associated with its operation,
//  modification,maintenance, and subsequent redistribution. 
//
//  See NIST Administration Manual 4.09.07 b and Appendix I. 


#include "StdAfx.h"
#include "FeatureCycles.h"
#include <math.h>
#include <atlfile.h>
#include "iges.h"

//#include "StepNCCenterDrilling.h"

CWorldModel  gWm;

int IWorkCycles::_nContour=1;

//#include "boost/lexical_cast.hpp"
//boost::lexical_cast<long>(string(it->value.begin(), it->value.end()));
template<typename T>
HRESULT GetSimpleValue(CVarDefs &instanceVars, CString item, T & val)
{
	CVarDef vardef = FindVarDef(instanceVars, item);

	try {
		if(vardef->IsSimpleType())
		{
			EXPVariant v = vardef->Owner()->GetValue();
			val=boost::geLogMessage(v);
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}


CString IWorkCycle::ToGCode(int nDialect, int eRoughFinish) 
{ 
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	
	CString  block;
	block+=StrFormat(_T(";\n;OP%d - "), _parent->_opnum++) + this->GetComment()+ _T("\n;\n");
	block += _parent->PostToolChange(_toolnum);
	if(items!=NULL)
		block += items->OutputDataToString();

	return _parent->PostBlock(block);
}

HRESULT IWorkCycle::Verify(std::vector<CString>& errors)
{
	CCannedCycleItems * items = GetStepMap();
	errors.clear();
	//errors = items->Verify();
	if(errors.size() > 0)
		return E_FAIL;
	return S_OK; 
}

HRESULT IWorkCycle::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	_pExecutable=pExecutable;
	_pFeature=pFeature;
	_pOpItem=pOpItem;

	CCannedCycleItems * items = GetStepMap();
	items->ClearDirtyFlags();  // can now see if some aren't 
	items->Extract(pExecutable, pFeature, pOpItem); 
	CString id = (LPCTSTR)(_bstr_t) pExecutable->GetAttributeValue(_T("its_id"), _T("")); 

	SetName((LPCTSTR) items->GetItemValue(_T("FeatureName"), _T("")).get<tstring>().c_str());
	this->SetComment(StrFormat(_T("OP: %s ID: %s  FEATURE: %s  OPERATION: %s TOOL: %s\n"), 
		id,
		items->GetValue<tstring>(_T("FeatureName")).c_str(), 
		items->GetValue<tstring>(_T("Feature")).c_str(), 
		items->GetValue<tstring>(_T("Operation")).c_str(), 
		items->GetValue<tstring>(_T("Tooltype")).c_str()));


	return S_OK;
}

HRESULT IWorkCycle::SanityCheck() 
{

	CCannedCycleItems * items = GetStepMap();
	// These are here since there is some discrepancy as to what is to be done
	double dReferencePlane = items->GetValue<double>(_T("ReferencePlane")) ;
	double dRetractionPlane = items->GetValue<double>(_T("RetractPlane")) ;
	if(dRetractionPlane<dReferencePlane)
	{
		errmsgs.push_back(StrFormat(_T("Sanity Check fixed: Retract Plane < Reference Plane\n")));
		items->SetVariable(_T("RetractPlane"), dReferencePlane+10.0) ; //??
	}

	return S_OK;

}


HRESULT IWorkCycle::SetVariablePairs(LPCTSTR szVar,...)
{
	HRESULT hr=S_OK;
	va_list marker; 
	LPCTSTR val;
	LPCTSTR var=szVar;
	va_start(marker, szVar);
	while(1)
	{
        val = va_arg( marker, LPCTSTR);
		if(val==NULL)
			break;
		if(FAILED(SetVariable(var, val)))
			hr= E_FAIL;
        var = va_arg( marker, LPCTSTR);
		if(var==NULL)
			break;
	}
	va_end( marker );              
  return hr;
}


HRESULT IWorkCycles::StockDefinition(CANON_STOCK type, CString szMaterial, Vector origin, Vector extents)
{
	_eStockType=type;
	SetStockMaterial(szMaterial);
	_vStockOrigin=origin;
	_vStockExtents=extents;
	return S_OK;
}


IWorkCyclePtr IWorkCycles::CreateFeature(CANON_FEATURE eType)
{
	return NULL;
}	


CString IWorkCycles::GenerateNCProgram()
{
	CString tmp;
	std::vector<IWorkCyclePtr> & _commands=*this;

	for(int i=0; i< _commands.size(); i++)
	{
		//if(FAILED(_commands[i]->Verify()))
		//{
		//	OUTPUT_DEBUG_STRING(StrFormat("Error in command %s\n", _commands[i]->GetName()));

		//}

		tmp+=_commands[i]->ToGCode(0);
	}

	return tmp;
}

CString IWorkCycles::GenerateIniString()
{
	CString tmp;
	std::vector<IWorkCyclePtr> & _commands=*this;

	for(int i=0; i< _commands.size(); i++)
	{
		tmp+=StrFormat(_T("[%d]\n"), i);
		tmp+=_commands[i]->ToString();
	}

	return tmp;
}

CString IWorkCycles::GenerateXmlString()
{
	CString tmp;
	std::vector<IWorkCyclePtr> & _commands=*this;

	tmp+=StrFormat(_T("<CYCLES> \n"));
	for(int i=0; i< _commands.size(); i++)
	{
		tmp+=StrFormat(_T("<CYCLE> \n"), i);
		tmp+=_commands[i]->ToXmlString();
		tmp+=StrFormat(_T("</CYCLE> \n"), i);
	}

	tmp+=StrFormat(_T("</CYCLES> \n"));
	return tmp;
}

CString IWorkCycles::GenerateNCErrors()
{
	CString tmp;
	std::vector<IWorkCyclePtr> & _commands=*this;
	for(int i=0; i< _commands.size(); i++)
	{
		std::vector<CString> errors;
		_commands[i]->Verify(errors);
		if(errors.size()>0 || _commands[i]->errmsgs.size() > 0)
		{
			tmp+=_T("<BR>&nbsp;<BR><U>") + _commands[i]->GetComment()  +_T("</U>")  ;
			for(int j=0; j< _commands[i]->errmsgs.size(); j++)
				tmp+=_T("<BR>") + _commands[i]->errmsgs[j];
			for(int j=0; j< errors.size(); j++)
				tmp+=_T("<BR>") + errors[j];

		}
	}

	return tmp;
}

//
// FIXME: add handle for multiline comments
//

CString IWorkCycles::PostBlock(CString line)
{
	CString block;

	if(line.GetLength() < 1)
		return block;
	if(!_wm._bUseBlockNums)
		return line;

	CStringVector lines = CStringVector::Tokenize(line, "\n",1);
	for(int i=0; i< lines.size(); i++)
	{
		if(lines[i].Find(_T(";"))==0)
		{
			block+=lines[i];
			continue;
		}
		block.AppendFormat(_T("N%03d "), _wm._nBlockNum);
		block.AppendFormat(_T("%s"),  lines[i]);
		_wm._nBlockNum+=_wm._nBlockIncr;
		if(lines[i].ReverseFind(_T('\n'))<0)
			block+=_T("\n");
	}
	return block;

}
HRESULT IWorkCycle::LoadWSIntoStep(IStepNodePtr project) 
{ 

	items.SetVariable(_T("StepFeedrate"), items.GetValue<double>(_T("Feedrate"),-1) / 1000.0 / 60.0) ;
	items.SetVariable(_T("StepSpeed"), -items.GetValue<double>(_T("Speed"), -999)) ;  // FIXME: get ccw value

	for(int i=0; i< this->items.size(); i++)
	{
		if(items.at(i)->Type() == Cycle::Classname)
		{
			_pExecutable->AddAttribute(_bstr_t(StrFormat(_T("%s%s"), items.at(i)->StepPath(), items.at(i)->_str)));
		}

	}
#ifdef FIXME
	// Check that project is indeed of type project
	CAddons addons((Eproject *) project.get());
	for(int i=0; i< this->items.size(); i++)
	{

		if(items.at(i)->Type() == Cycle::StepPosition)
		{
			IStepNodePtr step = StepRoot(items.at(i));
			if(step==NULL)
				continue;
			addons.DefineAxis2_placement_3d(step,items.at(i)->StepPath(), items.at(i)->Name());
		}
	}
#endif
	_pFeature= _pExecutable->SelectNode((LPCTSTR) StrFormat(_T("its_feature")));
	_pOpItem= _pExecutable->SelectNode((LPCTSTR) StrFormat(_T("its_operation")));

	items.Inject( _pExecutable,  _pFeature,  _pOpItem);
	return S_OK; 
}

#include "StepNCRectangularPocket.h"
#include "StepNCCenterDrilling.h"
#include "StepNCFacing.h"
#include "StepNCContourPocket.h"

void IWorkCycles::ReadIniString(CString inistring)
{
	// Parse file...
	IWorkCycles owner(gWm);

	CSymbolTable table;
	//table.FromInifile(dlg.m_szFileName); 
	table.ParseIni( inistring);

	for(int i=0; i<table.sectionsmap.size(); i++) 
	{
		std::vector<CString> row = table.sectionsmap[i];
		CString type = (LPCTSTR) (_bstr_t) table.GetSymbolValue(row[0], _T("Type"));
		StepNCCenterDrilling drilling(&owner);
		StepNCReaming reaming(&owner);
		StepNCRectangularPocket rectpocket(&owner);
		StepNCFacing facing(&owner);
		StepNCWorkpiece workpiece;
		CStepNCItems * items;
		if(type ==  _T("CenterDrilling"))
		{
			drilling.Create(gProject);
			items=&drilling;

		}
		else if(type ==  _T("Reaming"))
		{
			reaming.Create(gProject);
			items=&reaming;

		}		
		else if(type ==  _T("Facing"))
		{
			facing.Create(gProject);
			items=&facing;

		}	
		else if(type ==  _T("Workpiece"))
		{
			workpiece.Create(gProject);
			items=&workpiece;

		}	
		else if(type ==  _T("RectangularPocket"))
		{
			rectpocket.Create(gProject, "WS");
			items=&rectpocket;

		}		
		else
		{
			continue;
		}
		for(int j=1; j< row.size(); j++)
			items->SetVariable((LPCTSTR) row[j], (LPCTSTR) _bstr_t(table.GetSymbolValue(row[0], row[j])));
		items->LoadIntoStep();

		OutputDebugString(row[0]);
	}
}
#include "QueryPath.h"

void IWorkCycles::ReadXmlString(CString xmlstring)
{
	// Parse file...
	IWorkCycles owner(gWm);
	CQueryPath xml;
	xml.Read(xmlstring);

	MSXML2::IXMLDOMNodeListPtr  nodes= xml.QueryNodes(_T("//CYCLES/CYCLE"));
	if(nodes==NULL)
		return;
	for(int i=0; i<nodes->Getlength(); i++)
	{
		MSXML2::IXMLDOMNodePtr node = nodes->Getitem(i);
		MSXML2::IXMLDOMNodePtr xType =  xml.QueryNode(_T("Type"), node);
		bstr_t bstr = node->Gettext();
		OutputDebugString(StrFormat(_T("node=%S\n"), (BSTR) bstr));
		CString type =(LPCTSTR) xType->Gettext();


		StepNCCenterDrilling drilling(&owner);
		StepNCReaming reaming(&owner);
		StepNCRectangularPocket rectpocket(&owner);
		StepNCFacing facing(&owner);
		StepNCContourPocket pocket(&owner);
		StepNCWorkpiece workpiece;
		CStepNCItems * items;

		if(type ==  _T("CenterDrilling"))
		{
			drilling.Create(gProject);
			items=&drilling;

		}
		else if(type ==  _T("Reaming"))
		{
			reaming.Create(gProject);
			items=&reaming;

		}		
		else if(type ==  _T("Facing"))
		{
			facing.Create(gProject);
			items=&facing;

		}	
		else if(type ==  _T("Workpiece"))
		{
			workpiece.Create(gProject);
			items=&workpiece;

		}	
		else if(type ==  _T("RectangularPocket"))
		{
			rectpocket.Create(gProject, "WS");
			items=&rectpocket;

		}		
		else if(type ==  _T("ContourPocket"))
		{
			pocket.Create(gProject, _T("WS"));
			items=&pocket;
			items->SetVariable(_T("FeatureBoundary"), _T("general_closed_profile"));

		}		
		

		else
		{
			continue;
		}

		MSXML2::IXMLDOMNodeListPtr  children = node->GetchildNodes ( );
		for(int k=0; children!=NULL && k< children->Getlength(); k++)
		{
			MSXML2::IXMLDOMNodePtr child = children->Getitem(k);
			CString name = (LPCTSTR) child->baseName; 
			if(items->IsVariable((LPCTSTR) name.Trim()))
			{
				CString value =(LPCTSTR) child->Gettext();
				items->SetVariable((LPCTSTR) name, (LPCTSTR) value.Trim());
			}

		}


		//project/main_workplan/its_elements/its_elements[0]/its_feature/feature_boundary/placement/

		MSXML2::IXMLDOMNodeListPtr toolpaths =  xml.QueryNodes(_T("Toolpath"), node);
		Iges::CompositeCurve contour; 
		for(int j=0; toolpaths!=NULL &&  j<toolpaths->Getlength(); j++)
		{
			MSXML2::IXMLDOMNodePtr toolpath = toolpaths->Getitem(j);
			contour.AddXmlEntity((LPCTSTR) toolpath->xml);
		}
		if(items->IsVariable((LPCTSTR) _T("Contour")))
		{
			items->SetVariable(_T("Contour"), contour);
		}
		items->LoadIntoStep();
		items->SetVariable(_T("CycleType"), (long) 1); // hack for rough type - if string throws

		OutputDebugString(contour.ToXmlString());

	}

}