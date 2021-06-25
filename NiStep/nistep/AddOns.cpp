#include "StdAfx.h"
#include "AddOns.h"
#include "Misc.h"



EHelix::EHelix() 
{ 
	this->Type()= entity_;
	this->ExpressClassname() = _T("helix");
	this->Classname() = _T("EHelix");
	m_vars.push_back(new CVarDef(this, _T("Ecurve") ,(StepNodeType) 1, (DWORD) &(this->_curve.m_vars),_T("Baseclass")));
	m_vars.push_back(new CVarDef(this, _T("position") ,(StepNodeType) 22, (DWORD) &(this->position), _T("Eaxis2_placement_3d"), 0));
	 m_vars.push_back(new CVarDef(this, _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius), _T("Epositive_length_measure"), 0));
	 m_vars.push_back(new CVarDef(this, _T("pitch") ,(StepNodeType) 22, (DWORD) &(this->pitch), _T("Elength_measure"), 0));

	Parents().clear(); 
	Supertypes().clear(); 

	Parents().push_back(_T("Ecurve")) ; 
	Parents().push_back(_T("Egeometric_representation_item")) ; 
	Parents().push_back(_T("Erepresentation_item")) ; 

	m_bAbstract=false ; 
	CStringVector vVisitedClasses;
	BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}

Earc::Earc() 
{ 
	this->Type()= entity_;
	this->ExpressClassname() = _T("arc");
	this->Classname() = _T("Earc");
	m_vars.push_back(new CVarDef(this, _T("Ecurve") ,(StepNodeType) 1, (DWORD) &(this->_curve.m_vars),_T("Baseclass")));
	m_vars.push_back(new CVarDef(this, _T("start_point") ,(StepNodeType) 22, (DWORD) &(this->start_point), _T("Eaxis2_placement_3d"), 0));
	m_vars.push_back(new CVarDef(this, _T("end_point") ,(StepNodeType) 22, (DWORD) &(this->end_point), _T("Eaxis2_placement_3d"), 0));
	m_vars.push_back(new CVarDef(this, _T("center") ,(StepNodeType) 22, (DWORD) &(this->center), _T("Eaxis2_placement_3d"), 0));
    m_vars.push_back(new CVarDef(this, _T("radius" ),(StepNodeType) 22, (DWORD) &(this->radius), _T("Eplane_angle_measure"), 0));
    m_vars.push_back(new CVarDef(this, _T("start_angle") ,(StepNodeType) 22, (DWORD) &(this->start_angle), _T("Eplane_angle_measure"), 0));
    m_vars.push_back(new CVarDef(this, _T("sweep_angle") ,(StepNodeType) 22, (DWORD) &(this->sweep_angle), _T("Eplane_angle_measure"), 0));

	Parents().clear(); 
	Supertypes().clear(); 

	Parents().push_back(_T("Ecurve")) ; 
	Parents().push_back(_T("Egeometric_representation_item")) ; 
	Parents().push_back(_T("Erepresentation_item")) ; 

	m_bAbstract=false ; 
	CStringVector vVisitedClasses;
	BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);

}


IStepNodePtr CreateExpressAddons(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname==_T("Ehelix")) return (IStepNodePtr) new EHelix;
	if(classname==_T("Earc")) return (IStepNodePtr) new Earc;

	return NULL;
}

