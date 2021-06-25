//
// CannedCyles.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#include "StdAfx.h"
#include "CannedCyles.h"
#include "Misc.h"
#include "AddOns.h"

extern IStepNode * gProject;


//long CCannedCycleItems::_nBlocknum=10;


//typedef boost::variant< long, CString, double, Vector  > CNCVariant;



void CCannedCycleItem::ExtractValue(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{

	//if(this->m_ncdataname == _T("Tooltype"))
	//{
	//	DebugBreak(); 
	//}
	if(m_step==_T("Compute"))
		return;
	IStepNodePtr pStep;
	try {

		
		if(m_step== Cycle::Project) 
			pStep = gProject; // <--- FIXME

		if(m_step== Cycle::Feature)
			pStep = pFeature;

		if(m_step== Cycle::Operation)
			pStep = pOpItem;

		if(m_step== Cycle::Executable)
			pStep = pExecutable;

		if(pStep==NULL)
			return;

		if(Type() == Cycle::Vector)
		{	 
			_v  = FromComVector(pStep->ToVector(_bstr_t((LPCTSTR) m_steppath))); 
		}
		else if(Type()== Cycle::Double || Type()== Cycle::Position || Type()== Cycle::Length || Type()== Cycle::Angle || Type()==Cycle::Speed || Type()==Cycle::Feed)
		{
			//OutputDebugString(StrFormat(_T("%s\n"),m_steppath));
			_d = (double) pStep->GetAttributeValue((LPCTSTR) m_steppath, (double) 0.0); 
		}
		else if(Type() == Cycle::Long)
		{
			_l = (long) pStep->GetAttributeValue((LPCTSTR)m_steppath, (long) 0); 
		}
		else if(Type() == Cycle::String)
		{
			_str = (LPCTSTR)(_bstr_t) pStep->GetAttributeValue((LPCTSTR)m_steppath, (long) 0); 
		}
		
		else if(Type() == Cycle::Boolean)
		{
			_l=-1;
			CString tmp = (LPCTSTR)(_bstr_t) pStep->GetAttributeValue((LPCTSTR)m_steppath, (long) -1); 
			if(tmp==_T(".T.")) _l = 1;
			if(tmp==_T(".F.")) _l = 0;
		}
		else if(Type() == Cycle::Classname)
		{
			IStepNodePtr pStepClass = pStep->SelectNode((LPCTSTR)m_steppath); 
			if(pStepClass==NULL)
			{
				OutputDebugString(StrFormat(_T("Error pStepClass->ExpressClassname %s NULL\n"), m_steppath));
				return;
			}
			if(pStepClass->IsSimpleListType())
			{
				_str =  CString((LPCTSTR) pStepClass->GetListClassname()).MakeLower();
			}
			else
			{
				_str =  CString((LPCTSTR)pStepClass->GetClassname()).MakeLower();

			}

		}
		else if(Type() == Cycle::Polyline)
		{
			IStepNodePtr pStepClass = pStep->SelectNode((LPCTSTR) m_steppath); 
			tstring szCurveType;
			if(pStepClass==NULL)
			{
				OutputDebugString(StrFormat(_T("Error pStepClass->Polyline %s NULL\n"), m_steppath));
				return;
			}
			if(pStepClass->IsSimpleListType())
				szCurveType =   CString((LPCTSTR) pStepClass->GetListClassname()).MakeLower();
			else
				szCurveType =   CString((LPCTSTR) pStepClass->GetClassname()).MakeLower();

			if(szCurveType == _T("polyline"))
			{
				//EpolylinePtr pCurve = (Epolyline *) pStepClass.get();

				// There will be points, as this is not a pointer, may be empty though
				//EListT<Ecartesian_pointPtr> points = pCurve->points;
				IStepNodePtr step = pStepClass->SelectNode(_T("points"));
				INodeListPtr points = step->GetNodeList();

				// Change vector of pointer to doubles to actual math vector
				for(int i=0; i< points->Getlength(); i++) 
				{ 
					IStepNodePtr point = points->Getitem(i);
					Vector v = 	FromComVector(point->ToVector(_bstr_t((LPCTSTR) _T("coordinates")))); 
					curve.AddEntity(Iges::Point(v));

				}
			}
			else if(szCurveType == _T("composite_curve"))
			{
				//Ecomposite_curvePtr pCurve = (Ecomposite_curve *) pStepClass.get();
				// There will be points, as this is not a pointer, may be empty though
				// EListT<Ecomposite_curve_segmentPtr> segments = pCurve->segments;
				INodeListPtr segments = pStepClass->SelectNodeList(_bstr_t("segments"));

				// Change vector of pointer to doubles to actual math vector
				for(int i=0; i< segments->size(); i++) 
				{ 
					//EcurvePtr pCurve = segments[i]->parent_curve;
					INodePtr pCurve = segments->Getitem(i)->SelectNode(_T("parent_curve"));
					CString szCurveType =   CString((LPCTSTR) pCurve->GetClassname()).MakeLower();
					if(szCurveType == _T("line"))
					{
						Line3D line = CAddons(NULL).DeriveLine(pCurve); 
						curve.AddEntity(Iges::Line(line.e1, line.e2));

					}
					else if(szCurveType == _T("arc"))
					{

						Iges::Arc3D arc;
						arc.ep1 = FromComVector(pCurve->ToVector(_T("start_point/coordinates")));
						arc.ep2 = FromComVector(pCurve->ToVector(_T("end_point/coordinates")));
						arc.c = FromComVector(pCurve->ToVector(_T("center/coordinates")));

						arc.radius = pCurve->GetAttributeValue(_T("radius"), 0);
						arc.sa = pCurve->GetAttributeValue(_T("start_angle"), 0);
						arc.sw = pCurve->GetAttributeValue(_T("sweep_angle"), 0);
						curve.AddEntity(arc);

					}
					else if(szCurveType == _T("partial_circular_profile"))
					{
#ifdef FIXME
						Arc3D arc = CAddons(NULL).DeriveArc((Epartial_circular_profile *) pCurve.get()); 
						curve.AddEntity(Iges::Arc3D(arc.ep1, arc.ep2, arc.c, arc.r,arc.sa, arc.sw));
#endif
					}
				}
			}
			OutputDebugString(curve.ToXmlString());
		}
	}
	catch (_com_error &e)
	{
		OutputDebugString(StrFormat(_T("ExtractValue Variant Exception attribute %s\n"), m_steppath));
		OutputDebugString(dump_com_error(e));
	}
	catch (...)
	{
		OutputDebugString(StrFormat(_T("ExtractValue Variant Exception attribute %s\n"), m_ncdataname));
	}
}

void CCannedCycleItem::InjectValue(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{

	//if(this->m_ncdataname == _T(_T("Toollength")))
	//{
	//	DebugBreak(); 
	//}
	if(m_step==_T("Compute"))
		return;
	IStepNodePtr pStep;
	try {

		if(m_step== Cycle::Project)
			pStep = gProject; // <--- FIXME

		if(m_step== Cycle::Feature)
			pStep = pFeature;

		if(m_step== Cycle::Operation)
			pStep = pOpItem;

		if(m_step== Cycle::Executable)
			pStep = pExecutable;

		if(pStep==NULL)
			return;

		if(Type()== Cycle::Double || Type()== Cycle::Position || Type()== Cycle::Length || Type()== Cycle::Angle || Type()==Cycle::Speed || Type()==Cycle::Feed)
		{
			//OutputDebugString(StrFormat(_T("%s\n"),m_steppath));
			pStep->SetAttributeValue(_bstr_t(m_steppath), bstrFormat(_T("%f"), _d )); 
		}
		else if(Type() == Cycle::Long)
		{
			pStep->SetAttributeValue(_bstr_t(m_steppath), bstrFormat(_T("%d"), _l )); 
		}
		else if(Type() == Cycle::String)
		{
			pStep->SetAttributeValue(_bstr_t(m_steppath), _bstr_t(_str)); 
		}

		else if(Type() == Cycle::Boolean)
		{
			CString str;
			if(_l == 1) str=_T(".T.");
			else str==_T(".F.");
			pStep->SetAttributeValue(_bstr_t(m_steppath), _bstr_t(str)); 
		}
		else if(Type() == Cycle::Classname)
		{

		}
		else if(Type() == Cycle::Vector)
		{
			// FIXME: could be vector of length...
			_bstr_t bstr = bstrFormat(_T("%f,%f,%f"), _v.x, _v.y, _v.z);
			pStep->SetAttributeValue(_bstr_t(m_steppath), bstr); 
		}
		else if(Type() == Cycle::Polyline)
		{
			IStepNodePtr pStepClass = pStep->SelectNode(_bstr_t(m_steppath));
			CString szCurveType;

			if(pStepClass==NULL)
			{
				// Get the node - if null add generic composite_curve
				pStepClass = pStep->SelectNode(_bstr_t(m_steppath));
			}
			if(pStepClass->IsSimpleListType())
				szCurveType =  CString((LPCTSTR) pStepClass->GetListClassname()).MakeLower();
			else
				szCurveType =  CString((LPCTSTR) pStepClass->GetClassname()).MakeLower();

			if(szCurveType == _T("polyline"))
			{
				// There will be points, as this is not a pointer, may be empty though
				//EpolylinePtr pCurve = (Epolyline *) pStepClass.get();
				// pCurve should exist....
				//EListT<Ecartesian_pointPtr> points = pCurve->points;
				INodeListPtr  points = pStepClass->SelectNodeList(_bstr_t(L"points"));

				for(int i=0; i< curve.size(); i++) 
				{ 
					IStepNodePtr pPt = points->push_back(_bstr_t(L"cartesian_point"), bstrFormat(_T("%d"), i));
					Iges::Point * p = (Iges::Point *) curve[i];
					pPt->SetAttributeString(_bstr_t(L"coordinates"), bstrFormat(_T("%.3f, %.3f, %.3f"), p->X1, p->Y1, p->Z1));
				}
			}
			else if(szCurveType == _T("composite_curve"))
			{
			
				//Ecomposite_curvePtr pCurve = (Ecomposite_curve *) pStepClass.get();

				// There will be points, as this is not a pointer, may be empty though
				//EListT<Ecomposite_curve_segmentPtr> &segments(pCurve->segments);
				INodeListPtr  segments = pStepClass->SelectNodeList(_bstr_t(L"segments"));

				// Change vector of pointer to doubles to actual math vector
				for(int i=0; i< curve.size(); i++) 
				{ 
					IStepNodePtr pSegment = segments->push_back(_bstr_t(L"composite_curve_segment"), bstrFormat(_T("%d"), i));
					 
					if( curve[i]->IsLine())
					{
						Iges::Line * line = (Iges::Line *) curve[i];
						IStepNodePtr pStepLine = pSegment->CreateAttributeNode(_bstr_t(L"parent_curve"), _bstr_t(L"line"));
						
						pStepLine->SetAttributeValue(_bstr_t(L"name"), _bstr_t(L"Line")); 
						pStepLine->SetAttributeValue(_bstr_t(L"pnt/coordinates"),_bstr_t( line->_pt1.ToString(_T(",")))); 
						pStepLine->SetAttributeValue(_bstr_t(L"dir/magnitude"), bstrFormat(_T("%.3f"), line->Magnitude())); 
						pStepLine->SetAttributeValue(_bstr_t(L"dir/orientation/direction_ratios"),_bstr_t( line->Direction().ToString(_T(",")))); 

					}
					else if(curve[i]->IsArc())
					{
						Iges::Arc3D * arc = (Iges::Arc3D *) curve[i];
						IStepNodePtr pStepArc = pSegment->CreateAttributeNode(_bstr_t(L"parent_curve"), _bstr_t(L"arc"));

						pStepArc->SetAttributeValue(_bstr_t(L"name"), bstrFormat(_T("Arc"))); 
						pStepArc->SetAttributeValue(_bstr_t(L"start_point/coordinates"),_bstr_t( arc->ep1.ToString(_T(",")))); 
						pStepArc->SetAttributeValue(_bstr_t(L"end_point/coordinates"), _bstr_t(arc->ep2.ToString(_T(",")))); 
						pStepArc->SetAttributeValue(_bstr_t(L"center/coordinates"), _bstr_t(arc->c.ToString(_T(",")))); 
						pStepArc->SetAttributeValue(_bstr_t(L"radius"), bstrFormat(_T("%.3f"), arc->radius)); 
						pStepArc->SetAttributeValue(_bstr_t(L"start_angle"), bstrFormat(_T("%.3f"), arc->sa)); 
						pStepArc->SetAttributeValue(_bstr_t(L"sweep_angle"), bstrFormat(_T("%.3f"), arc->sw)); 
					}
#if 0
					else if(szCurveType == _T("partial_circular_profile"))
					{
						Arc3D arc = CAddons(NULL).DeriveArc((Epartial_circular_profile *) pCurve.get()); 
						curve.AddEntity(Iges::Arc3D(arc.ep1, arc.ep2, arc.c, arc.r,arc.sa, arc.sw));
					}
#endif
				}
			}
			OutputDebugString(curve.ToXmlString());
		}
	}
	catch (_com_error &e)
	{
		OutputDebugString(StrFormat(_T("ExtractValue Variant Exception attribute %s\n"), m_steppath));
		OutputDebugString(dump_com_error(e));
	}
	catch (...)
	{
		OutputDebugString(StrFormat(_T("ExtractValue Variant Exception attribute %s\n"), m_ncdataname));
	}
}

Variant CCannedCycleItem::GetValue() 
{

	if(Type()== Cycle::Double ||  Type()== Cycle::Angle || Type()==Cycle::Speed || Type()==Cycle::Feed)
		return Variant(  _d ); 
	else if(Type()== Cycle::Position || Type()== Cycle::Length)
		return Variant( _d ); 
	else if(Type() == Cycle::Long || Type() == Cycle::Boolean)
		return Variant( _l ); 
	else if(Type() == Cycle::String)
		return Variant((LPCTSTR) _str ); 
	else if(Type() == Cycle::Classname)
		return Variant( (LPCTSTR) _str ); 
	else if(Type() == Cycle::Vector)
	{
		return Variant( (Vector) _v ); 
	}
	else if(Type() == Cycle::Polyline)
	{
		return	 Variant((Iges::CompositeCurve) curve);
	} 


	return Variant(); 

}

void CCannedCycleItem::SetValue(Variant val) 
{
	USES_CONVERSION;
	SetDirty();
	try{
		if(Type() == Cycle::Double || Type()== Cycle::Angle || Type()==_T("Speed") || Type()==_T("Feed"))
			_d =   val.get<double>(); 
		else if(Type()== Cycle::Position || Type()== Cycle::Length)
			_d =  val.get<double>(); 
		else if(Type() == Cycle::Long || Type() == Cycle::Boolean)
			_l =   val.get<long>(); 
		else if(Type() == Cycle::String)
			_str =  val.get<tstring>().c_str(); 
		else if(Type() == Cycle::Classname)
			_str =  val.get<tstring>().c_str(); 
		else if(Type() == Cycle::Vector)
			_v =  val.get<Vector>(); 
		else if(Type() == Cycle::Polyline && val.IsType<Iges::CompositeCurve>())
		{
			curve =  val.get<Iges::CompositeCurve>();   
		}
	}
	catch(...)
	{
		OutputDebugString(StrFormat(_T("SetValue Variant Exception attribute %s\n"), this->m_ncdataname));

	}

}

CString CCannedCycleItem::ToString(CString fmt)
{

	CString tmp;

	if(Type() == Cycle::Double || Type()== Cycle::Position || Type()== Cycle::Length  || Type()== Cycle::Angle || Type()==_T("Speed") || Type()==_T("Feed"))
	{
		if(fmt==_T("")) fmt = _T("%f");
		return StrFormat(fmt, _d ); 
	}
	else if(Type() == Cycle::Long || Type() == Cycle::Boolean)
	{
		if(fmt==_T("")) fmt = _T("%d");
		return StrFormat(fmt, _l ); 
	}
	else if(Type() == Cycle::String)
	{
		if(fmt==_T("")) fmt = _T("%s");
		return StrFormat(fmt, _str ); 
	}
	else if(Type() == Cycle::Classname)
	{
		if(fmt==_T("")) fmt = _T("{%s}");
		return StrFormat(fmt, _str ); 
	}
	else if(Type() == Cycle::Enum)
	{
		if(fmt==_T("")) fmt = _T("%s");
		CString  section = _T("Enumeration.") + this->m_steppath;
		CCannedCycleItem * item = _parent->FindItem((LPCTSTR) this->m_steppath);
		CString tmp = (LPCTSTR) (_bstr_t)_parent->_IniSymbols.GetSymbolValue(section, item!=NULL? item->ToString(): _T(""));
		return StrFormat(fmt, tmp ); 
	}
	else if(Type()==_T("Vector"))
	{
		return _v.ToString(); 
	}
	else 
	{
		if(fmt==_T("")) fmt = _T("%s");
		return StrFormat(fmt, _str ); 
	}
	return _T(""); 
}

//////////////////////////////////////////////////////////////////////////////////////////

CCannedCycleItems::CCannedCycleItems()
{
	AddItem(_T("Test"), Cycle::Double, _T(""),  _T(""), (double) 0.0);
	_nUnits=cMM;
}	
	
void CCannedCycleItems::Inches() 
{ 
	if(_nUnits==cMM)
	{
		for(int i=0; i< this->size(); i++)
		{
			CCannedCycleItem * item = at(i);
			if(item->Type()== Cycle::Position || item->Type()== Cycle::Length)
				item->SetValue(item->GetValue().get<double>() / 25.4);
		}
	}
	_nUnits=cINCHES;
}
void CCannedCycleItems::MM() 
{ 
	if(_nUnits==cINCHES)
	{
		for(int i=0; i< this->size(); i++)
		{
			CCannedCycleItem * item = at(i);
			if(item->Type()== Cycle::Position || item->Type()== Cycle::Length)
				item->SetValue(item->GetValue().get<double>() * 25.4);
		}
	}
	_nUnits=cMM;
}

CString CCannedCycleItems::ToString()
{
	CStringVector tmp;
	for(int i=0; i< this->size(); i++)
	{
		//REMOVED : this->at(i)->m_steppath,
		tmp.push_back(StrFormat(_T("%s=%s\n"), this->at(i)->m_ncdataname,  this->at(i)->ToString()));
	}
	sort(tmp.begin(), tmp.end());
	return tmp.ToString(_T(""));
}

CString CCannedCycleItems::ToXmlString()
{
	CString tmp;
	for(int i=0; i< this->size(); i++)
	{
		//REMOVED : this->at(i)->m_steppath,
		tmp +=StrFormat(_T("<%s>%s</%s>\n"), this->at(i)->m_ncdataname,  this->at(i)->ToString(), this->at(i)->m_ncdataname);
	}
	return tmp;
}
void CCannedCycleItems::Extract(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	for(int i=0; i< this->size(); i++)
		this->at(i)->ExtractValue(pExecutable, pFeature, pOpItem);
}


void CCannedCycleItems::Inject(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	for(int i=0; i< this->size(); i++)
		this->at(i)->InjectValue(pExecutable, pFeature, pOpItem);
}

CCannedCycleItem * CCannedCycleItems::FindItem(CString itemname)
{
	for(int i=0; i< size(); i++)
	{
		CCannedCycleItem * item = this->at(i);
		if(item->m_ncdataname == itemname)
			return item;

	}
	return NULL;
}

CString CCannedCycleItems::OutputDataToString()
{
	CString tmp;
	long n; 
	long nCycleType= GetItemValue(_T("CycleType"), (long) -1).get<long>() ;

	for(int i=0; i< Outputs.size(); i++) // it = Outputs.begin(); it!= Outputs.end(); it++)
	{
		OutputLine tuple = Outputs[i]; // (*it).second;
		//for(int j=0; j< tuples.size(); j++)
		//{
		CCannedCycleItem *  item = FindItem((LPCTSTR) tuple[nVarIndex]);
		CString field;
		//if(item->m_ncdataname== _T(_T("ToolType")))
		//{
		//	DebugBreak();
		//}
		if(item!=NULL)
			field = item->ToString(tuple[nFormatIndex]);
		else
			field=StrFormat(tuple[nFormatIndex], tuple[nVarIndex]);

		CString block;
		block=field;

#if 0
		if(!_bBlocknums)
			block=field;

		if(_bBlocknums && i==0)
		{
			block+=StrFormat(_T("N%-*d "), _nBlockspace,  _nBlocknum);
			_nBlocknum+=_nBlockinc;
		}

		while(_bBlocknums && (n=field.Find(_T(_T('\n'))))>0)
		{
			block+=field.Mid(0,n+1);
			if(i!=Outputs.size()-1)
				block+=StrFormat(_T("N%-*d "), _nBlockspace,  _nBlocknum);
			field=field.Mid(n+1);
			_nBlocknum+=_nBlockinc;
		}
		block+=field;
#endif
		if((nCycleType  == 2 ) && (tuple[nOutputTypeIndex]==_T("Both") || tuple[nOutputTypeIndex]==_T("Finish")))
		{
			tmp+=block;
		}
		else  if((nCycleType == 1) && (tuple[nOutputTypeIndex]==_T("Both") || tuple[nOutputTypeIndex]==_T("Rough")))
		{
			tmp+=block;
		}
		else
		{
			// skip if not involved, example lots of finishing parameters not used in roughing
			//DebugBreak();
		}
		//}

	}
	return tmp;

}

CString CCannedCycleItems::OutputSetupToString()
{
	CString tmp;
	std::vector<std::vector<CString> >::iterator it;

	for(int i=0; i< Outputs.size(); i++) // it = Outputs.begin(); it!= Outputs.end(); it++)
	{
		std::vector<CString> tuples = Outputs[i];
		//for(int i=0; i< tuples.size(); i++)
		{
			tmp+=StrFormat(_T("%s, %s\n"), tuples[0],tuples[1]);
		}

	}
	return tmp;

}


CStringVector CCannedCycleItems::Verify()
{
	CStringVector tmp;
	long nCycleType= GetItemValue(_T("CycleType"), (long) -1).get<long>() ;

	for(int i=0; i< Tests.size(); i++) 
	{
		OutputLine tuple = Tests[i]; 
		CString str = StrFormat(_T("Test = %s;\n"), tuple[2]);

		this->at(i)->scripttree=ParseAString((LPCTSTR) str, _T(""));
		if(this->at(i)->scripttree.full)
		{
			evaluate(this->at(i)->scripttree.trees.begin());
		}
		else
		{
			OutputDebugString(StrFormat(_T("Script Parse Failed  Unknown Reason at%s\n") , this->at(i)->scripttree.stop));


		}
		long bFail = (long) GetItemValue(_T("Test"), (double) 0.0).get<double>() ;
		if(bFail)
			tmp.push_back(StrFormat(_T("Failed: %s\n"), tuple[2]));

	}

	return tmp;

}



void CCannedCycleItems::ExtractXml(MSXML2::IXMLDOMNodePtr pOperation)
{
	for(int i=0; i< this->size(); i++)
		this->at(i)->ExtractXmlValue(pOperation);
}	

void CCannedCycleItem::ExtractXmlValue(MSXML2::IXMLDOMNodePtr pOperation)
{

	CString prefix;

	if(this->m_step==_T("Compute"))
		return;

	if(m_step== Cycle::Feature)
		return;

	if(m_step== Cycle::Executable)
		return;
	if(pOperation==NULL)
		return;

	try {
		CString text =	(LPCTSTR) pOperation->selectSingleNode((LPCTSTR) m_steppath)->text;
		if(Type() == Cycle::Vector)
		{
			_v = Vector(DVal(text,0,_T(" ")), DVal(text,1,_T(" ")), DVal(text,2,_T(" "))); 
		}
		else if(Type()== Cycle::Double || Type()== Cycle::Position || Type()== Cycle::Length || Type()== Cycle::Angle || Type()==Cycle::Speed || Type()==Cycle::Feed)
		{
			//OutputDebugString(StrFormat(_T("%s\n"),m_steppath));
			_d = (double) _tstof(text); 
		}
		else if(Type() == Cycle::Long)
		{
			_l = (long) _tstoi(text); 
		}
		else if(Type() == Cycle::String)
		{
			_str = text;
		}

		else if(Type() == Cycle::Boolean)
		{
			_l=-1;
			if(text.MakeLower()==_T("true")) _l = 1;
			if(text.MakeLower()==_T("false")) _l = 0;
		}
		else if(Type() == Cycle::Classname)
		{
			DebugBreak();
		}
	}
	catch (_com_error &e)
	{
		OutputDebugString(StrFormat(_T("ExtractXMLValue Variant Exception attribute %s\n"), m_steppath));
		OutputDebugString(dump_com_error(e));
	}
	catch (...)
	{
		OutputDebugString(StrFormat(_T("ExtractXMLValue Variant Exception attribute %s\n"), m_ncdataname));
	}
}