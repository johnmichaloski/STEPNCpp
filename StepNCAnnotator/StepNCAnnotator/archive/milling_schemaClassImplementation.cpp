//
//
//
#include "stdafx.h"
#include "ExpressUtils.h"
#include "machining_schemaClassDefinitions.h"

#include "milling_schemaClassDefinitions.h"
namespace Express{
////////////////////////////////////////////////////////////////////////////////
Eadaptive_control::Eadaptive_control(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eadaptive_control";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Eadaptive_control*/
CStringVector Eadaptive_control::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eair_strategy::Eair_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eair_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eapproach_retract_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eapproach_retract_strategy::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eair_strategy*/
CStringVector Eair_strategy::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ealong_path::Ealong_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ealong_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eapproach_retract_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eapproach_retract_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "path" ,(StepNodeType) 22, (DWORD) &(this->path), "Etoolpath_list", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ealong_path*/
CStringVector Ealong_path::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eap_retract_angle::Eap_retract_angle(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eap_retract_angle";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eair_strategy") ; 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eair_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eair_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "angle" ,(StepNodeType) 22, (DWORD) &(this->angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "travel_length" ,(StepNodeType) 22, (DWORD) &(this->travel_length), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eap_retract_angle*/
CStringVector Eap_retract_angle::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eair_strategy");v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eap_retract_tangent::Eap_retract_tangent(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eap_retract_tangent";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eair_strategy") ; 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eair_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eair_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eap_retract_tangent*/
CStringVector Eap_retract_tangent::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eair_strategy");v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eapproach_retract_strategy::Eapproach_retract_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eapproach_retract_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "tool_orientation" ,(StepNodeType) 22, (DWORD) &(this->tool_orientation), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eapproach_retract_strategy*/
CStringVector Eapproach_retract_strategy::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eback_boring::Eback_boring(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eback_boring";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eback_boring*/
CStringVector Eback_boring::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebackside_counterbore::Ebackside_counterbore(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebackside_counterbore";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecounterbore") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecounterbore" ,(StepNodeType) 1, (DWORD) &(this->Ecounterbore::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebackside_counterbore*/
CStringVector Ebackside_counterbore::GetInheritanceChain(){
	CStringVector v;
v.push_back("Ecounterbore");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebackside_countersink::Ebackside_countersink(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebackside_countersink";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecountersink") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecountersink" ,(StepNodeType) 1, (DWORD) &(this->Ecountersink::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebackside_countersink*/
CStringVector Ebackside_countersink::GetInheritanceChain(){
	CStringVector v;
v.push_back("Ecountersink");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eball_endmill::Eball_endmill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eball_endmill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eendmill") ; 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eendmill" ,(StepNodeType) 1, (DWORD) &(this->Eendmill::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eball_endmill*/
CStringVector Eball_endmill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eendmill");v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebidirectional::Ebidirectional(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebidirectional";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feed_direction" ,(StepNodeType) 22, (DWORD) &(this->feed_direction), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "stepover_direction" ,(StepNodeType) 22, (DWORD) &(this->stepover_direction), "Eleft_or_right", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_stroke_connection_strategy" ,(StepNodeType) 22, (DWORD) &(this->its_stroke_connection_strategy), "Estroke_connection_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ebidirectional*/
CStringVector Ebidirectional::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebidirectional_contour::Ebidirectional_contour(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebidirectional_contour";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feed_direction" ,(StepNodeType) 22, (DWORD) &(this->feed_direction), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "stepover_direction" ,(StepNodeType) 22, (DWORD) &(this->stepover_direction), "Eleft_or_right", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "rotation_direction" ,(StepNodeType) 22, (DWORD) &(this->rotation_direction), "Erot_direction", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "spiral_cutmode" ,(StepNodeType) 22, (DWORD) &(this->spiral_cutmode), "Ecutmode_type", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ebidirectional_contour*/
CStringVector Ebidirectional_contour::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eboring::Eboring(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eboring";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eboring_operation") ; 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboring_operation" ,(StepNodeType) 1, (DWORD) &(this->Eboring_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eboring*/
CStringVector Eboring::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eboring_operation");v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eboring_operation::Eboring_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eboring_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "spindle_stop_at_bottom" ,(StepNodeType) 7, (DWORD) &(this->spindle_stop_at_bottom), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "depth_of_testcut" ,(StepNodeType) 22, (DWORD) &(this->depth_of_testcut), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "waiting_position" ,(StepNodeType) 22, (DWORD) &(this->waiting_position), "Ecartesian_point", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eboring_operation*/
CStringVector Eboring_operation::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eboring_tool::Eboring_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eboring_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eboring_tool*/
CStringVector Eboring_tool::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebottom_and_side_finish_milling::Ebottom_and_side_finish_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebottom_and_side_finish_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebottom_and_side_milling") ; 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebottom_and_side_milling" ,(StepNodeType) 1, (DWORD) &(this->Ebottom_and_side_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebottom_and_side_finish_milling*/
CStringVector Ebottom_and_side_finish_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Ebottom_and_side_milling");v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebottom_and_side_milling::Ebottom_and_side_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebottom_and_side_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_operation" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axial_cutting_depth" ,(StepNodeType) 22, (DWORD) &(this->axial_cutting_depth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "radial_cutting_depth" ,(StepNodeType) 22, (DWORD) &(this->radial_cutting_depth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "allowance_side" ,(StepNodeType) 22, (DWORD) &(this->allowance_side), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "allowance_bottom" ,(StepNodeType) 22, (DWORD) &(this->allowance_bottom), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ebottom_and_side_milling*/
CStringVector Ebottom_and_side_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebottom_and_side_rough_milling::Ebottom_and_side_rough_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebottom_and_side_rough_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebottom_and_side_milling") ; 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebottom_and_side_milling" ,(StepNodeType) 1, (DWORD) &(this->Ebottom_and_side_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebottom_and_side_rough_milling*/
CStringVector Ebottom_and_side_rough_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Ebottom_and_side_milling");v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ebullnose_endmill::Ebullnose_endmill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebullnose_endmill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eendmill") ; 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eendmill" ,(StepNodeType) 1, (DWORD) &(this->Eendmill::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebullnose_endmill*/
CStringVector Ebullnose_endmill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eendmill");v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecenter_drill::Ecenter_drill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecenter_drill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecenter_drill*/
CStringVector Ecenter_drill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecenter_drilling::Ecenter_drilling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecenter_drilling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_operation") ; 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecenter_drilling*/
CStringVector Ecenter_drilling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_operation");v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecenter_milling::Ecenter_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecenter_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecenter_milling*/
CStringVector Ecenter_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecombined_drill_and_reamer::Ecombined_drill_and_reamer(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecombined_drill_and_reamer";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ereamer") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ereamer" ,(StepNodeType) 1, (DWORD) &(this->Ereamer::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "drill_length" ,(StepNodeType) 22, (DWORD) &(this->drill_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecombined_drill_and_reamer*/
CStringVector Ecombined_drill_and_reamer::GetInheritanceChain(){
	CStringVector v;
v.push_back("Ereamer");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecombined_drill_and_tap::Ecombined_drill_and_tap(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecombined_drill_and_tap";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etap") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etap" ,(StepNodeType) 1, (DWORD) &(this->Etap::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "drill_length" ,(StepNodeType) 22, (DWORD) &(this->drill_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecombined_drill_and_tap*/
CStringVector Ecombined_drill_and_tap::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etap");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Econtour_bidirectional::Econtour_bidirectional(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econtour_bidirectional";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feed_direction" ,(StepNodeType) 22, (DWORD) &(this->feed_direction), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "stepover_direction" ,(StepNodeType) 22, (DWORD) &(this->stepover_direction), "Eleft_or_right", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "rotation_direction" ,(StepNodeType) 22, (DWORD) &(this->rotation_direction), "Erot_direction", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "spiral_cutmode" ,(StepNodeType) 22, (DWORD) &(this->spiral_cutmode), "Ecutmode_type", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Econtour_bidirectional*/
CStringVector Econtour_bidirectional::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Econtour_parallel::Econtour_parallel(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econtour_parallel";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "rotation_direction" ,(StepNodeType) 22, (DWORD) &(this->rotation_direction), "Erot_direction", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "cutmode" ,(StepNodeType) 22, (DWORD) &(this->cutmode), "Ecutmode_type", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Econtour_parallel*/
CStringVector Econtour_parallel::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Econtour_spiral::Econtour_spiral(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econtour_spiral";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "rotation_direction" ,(StepNodeType) 22, (DWORD) &(this->rotation_direction), "Erot_direction", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "cutmode" ,(StepNodeType) 22, (DWORD) &(this->cutmode), "Ecutmode_type", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Econtour_spiral*/
CStringVector Econtour_spiral::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecounter_sinking::Ecounter_sinking(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecounter_sinking";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_operation") ; 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecounter_sinking*/
CStringVector Ecounter_sinking::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_operation");v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecounterbore::Ecounterbore(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecounterbore";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecounterbore*/
CStringVector Ecounterbore::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ecountersink::Ecountersink(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecountersink";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "countersink_radius" ,(StepNodeType) 22, (DWORD) &(this->countersink_radius), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecountersink*/
CStringVector Ecountersink::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Edovetail_mill::Edovetail_mill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edovetail_mill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "included_angle" ,(StepNodeType) 22, (DWORD) &(this->included_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edovetail_mill*/
CStringVector Edovetail_mill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Edrill::Edrill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Edrill*/
CStringVector Edrill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Edrilling::Edrilling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrilling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_operation") ; 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Edrilling*/
CStringVector Edrilling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_operation");v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Edrilling_operation::Edrilling_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrilling_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Edrilling_operation*/
CStringVector Edrilling_operation::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Edrilling_type_operation::Edrilling_type_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrilling_type_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_machining_operation" ,(StepNodeType) 1, (DWORD) &(this->Emilling_machining_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "cutting_depth" ,(StepNodeType) 22, (DWORD) &(this->cutting_depth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "previous_diameter" ,(StepNodeType) 22, (DWORD) &(this->previous_diameter), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "dwell_time_bottom" ,(StepNodeType) 22, (DWORD) &(this->dwell_time_bottom), "Etime_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "feed_on_retract" ,(StepNodeType) 22, (DWORD) &(this->feed_on_retract), "Epositive_ratio_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_machining_strategy" ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy), "Edrilling_type_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edrilling_type_operation*/
CStringVector Edrilling_type_operation::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Edrilling_type_strategy::Edrilling_type_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrilling_type_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "reduced_cut_at_start" ,(StepNodeType) 22, (DWORD) &(this->reduced_cut_at_start), "Epositive_ratio_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "reduced_feed_at_start" ,(StepNodeType) 22, (DWORD) &(this->reduced_feed_at_start), "Epositive_ratio_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "depth_of_start" ,(StepNodeType) 22, (DWORD) &(this->depth_of_start), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "reduced_cut_at_end" ,(StepNodeType) 22, (DWORD) &(this->reduced_cut_at_end), "Epositive_ratio_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "reduced_feed_at_end" ,(StepNodeType) 22, (DWORD) &(this->reduced_feed_at_end), "Epositive_ratio_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "depth_of_end" ,(StepNodeType) 22, (DWORD) &(this->depth_of_end), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edrilling_type_strategy*/
CStringVector Edrilling_type_strategy::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eendmill::Eendmill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eendmill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eendmill*/
CStringVector Eendmill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eexchange_pallet::Eexchange_pallet(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eexchange_pallet";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eexchange_pallet*/
CStringVector Eexchange_pallet::GetInheritanceChain(){
	CStringVector v;
v.push_back("Enc_function");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eexplicit::Eexplicit(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eexplicit";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eexplicit*/
CStringVector Eexplicit::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Efacemill::Efacemill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efacemill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Efacemill*/
CStringVector Efacemill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Efive_axes_const_tilt_yaw::Efive_axes_const_tilt_yaw(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efive_axes_const_tilt_yaw";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_direction_for_milling") ; 
	parents.push_back("Etool_direction") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_direction_for_milling" ,(StepNodeType) 1, (DWORD) &(this->Etool_direction_for_milling::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "tilt_angle" ,(StepNodeType) 22, (DWORD) &(this->tilt_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "yaw_angle" ,(StepNodeType) 22, (DWORD) &(this->yaw_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Efive_axes_const_tilt_yaw*/
CStringVector Efive_axes_const_tilt_yaw::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etool_direction_for_milling");v.push_back("Etool_direction");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Efive_axes_var_tilt_yaw::Efive_axes_var_tilt_yaw(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efive_axes_var_tilt_yaw";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_direction_for_milling") ; 
	parents.push_back("Etool_direction") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_direction_for_milling" ,(StepNodeType) 1, (DWORD) &(this->Etool_direction_for_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Efive_axes_var_tilt_yaw*/
CStringVector Efive_axes_var_tilt_yaw::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etool_direction_for_milling");v.push_back("Etool_direction");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Efreeform_operation::Efreeform_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efreeform_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Emilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_machining_strategy" ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy), "Efreeform_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Efreeform_operation*/
CStringVector Efreeform_operation::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Efreeform_strategy::Efreeform_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efreeform_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "pathmode" ,(StepNodeType) 22, (DWORD) &(this->pathmode), "Epathmode_type", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "cutmode" ,(StepNodeType) 22, (DWORD) &(this->cutmode), "Ecutmode_type", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_milling_tolerances" ,(StepNodeType) 22, (DWORD) &(this->its_milling_tolerances), "Etolerances", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "stepover" ,(StepNodeType) 22, (DWORD) &(this->stepover), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Efreeform_strategy*/
CStringVector Efreeform_strategy::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eindex_pallet::Eindex_pallet(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eindex_pallet";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_index" ,(StepNodeType) 3, (DWORD) &(this->its_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eindex_pallet*/
CStringVector Eindex_pallet::GetInheritanceChain(){
	CStringVector v;
v.push_back("Enc_function");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eindex_table::Eindex_table(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eindex_table";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_index" ,(StepNodeType) 3, (DWORD) &(this->its_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eindex_table*/
CStringVector Eindex_table::GetInheritanceChain(){
	CStringVector v;
v.push_back("Enc_function");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eleading_line_strategy::Eleading_line_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eleading_line_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Efreeform_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Efreeform_strategy" ,(StepNodeType) 1, (DWORD) &(this->Efreeform_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_line" ,(StepNodeType) 22, (DWORD) &(this->its_line), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eleading_line_strategy*/
CStringVector Eleading_line_strategy::GetInheritanceChain(){
	CStringVector v;
v.push_back("Efreeform_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eload_tool::Eload_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eload_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_tool" ,(StepNodeType) 22, (DWORD) &(this->its_tool), "Emachining_tool", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eload_tool*/
CStringVector Eload_tool::GetInheritanceChain(){
	CStringVector v;
v.push_back("Enc_function");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_cutter::Emilling_cutter(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_cutter";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_cutter*/
CStringVector Emilling_cutter::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_cutting_tool::Emilling_cutting_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_cutting_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecutting_tool") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecutting_tool" ,(StepNodeType) 1, (DWORD) &(this->Ecutting_tool::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "direction_for_spindle_orientation" ,(StepNodeType) 22, (DWORD) &(this->direction_for_spindle_orientation), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "tool_holder_diameter_for_spindle_orientation" ,(StepNodeType) 22, (DWORD) &(this->tool_holder_diameter_for_spindle_orientation), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_cutting_tool*/
CStringVector Emilling_cutting_tool::GetInheritanceChain(){
	CStringVector v;
v.push_back("Ecutting_tool");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_machine_functions::Emilling_machine_functions(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_machine_functions";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachine_functions") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachine_functions" ,(StepNodeType) 1, (DWORD) &(this->Emachine_functions::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "coolant" ,(StepNodeType) 7, (DWORD) &(this->coolant), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "coolant_pressure" ,(StepNodeType) 22, (DWORD) &(this->coolant_pressure), "Epressure_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "mist" ,(StepNodeType) 7, (DWORD) &(this->mist), "EBoolean", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "through_spindle_coolant" ,(StepNodeType) 7, (DWORD) &(this->through_spindle_coolant), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "through_pressure" ,(StepNodeType) 22, (DWORD) &(this->through_pressure), "Epressure_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "axis_clamping" ,(StepNodeType) 15, (DWORD) &(this->axis_clamping), "std::vector<EidentifierPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eidentifier");
	vars.push_back(new CVarDef(this, "chip_removal" ,(StepNodeType) 7, (DWORD) &(this->chip_removal), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "oriented_spindle_stop" ,(StepNodeType) 22, (DWORD) &(this->oriented_spindle_stop), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_process_model" ,(StepNodeType) 22, (DWORD) &(this->its_process_model), "Eprocess_model_list", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "other_functions" ,(StepNodeType) 14, (DWORD) &(this->other_functions), "std::vector<Eproperty_parameterPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eproperty_parameter");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_machine_functions*/
CStringVector Emilling_machine_functions::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emachine_functions");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_machining_operation::Emilling_machining_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_machining_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_operation" ,(StepNodeType) 1, (DWORD) &(this->Emachining_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "overcut_length" ,(StepNodeType) 22, (DWORD) &(this->overcut_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_machining_operation*/
CStringVector Emilling_machining_operation::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_technology::Emilling_technology(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_technology";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etechnology") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etechnology" ,(StepNodeType) 1, (DWORD) &(this->Etechnology::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "cutspeed" ,(StepNodeType) 22, (DWORD) &(this->cutspeed), "Espeed_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "spindle" ,(StepNodeType) 22, (DWORD) &(this->spindle), "Erot_speed_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "feedrate_per_tooth" ,(StepNodeType) 22, (DWORD) &(this->feedrate_per_tooth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "synchronize_spindle_with_feed" ,(StepNodeType) 7, (DWORD) &(this->synchronize_spindle_with_feed), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "inhibit_feedrate_override" ,(StepNodeType) 7, (DWORD) &(this->inhibit_feedrate_override), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "inhibit_spindle_override" ,(StepNodeType) 7, (DWORD) &(this->inhibit_spindle_override), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_adaptive_control" ,(StepNodeType) 22, (DWORD) &(this->its_adaptive_control), "Eadaptive_control", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_technology*/
CStringVector Emilling_technology::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etechnology");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_tool_body::Emilling_tool_body(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_tool_body";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_body" ,(StepNodeType) 1, (DWORD) &(this->Etool_body::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "dimension" ,(StepNodeType) 22, (DWORD) &(this->dimension), "Emilling_tool_dimension", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "number_of_teeth" ,(StepNodeType) 3, (DWORD) &(this->number_of_teeth), "EInteger", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "hand_of_cut" ,(StepNodeType) 22, (DWORD) &(this->hand_of_cut), "Ehand", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "coolant_through_tool" ,(StepNodeType) 7, (DWORD) &(this->coolant_through_tool), "EBoolean", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "pilot_length" ,(StepNodeType) 22, (DWORD) &(this->pilot_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_tool_body*/
CStringVector Emilling_tool_body::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_tool_dimension::Emilling_tool_dimension(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_tool_dimension";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "diameter" ,(StepNodeType) 22, (DWORD) &(this->diameter), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "tool_top_angle" ,(StepNodeType) 22, (DWORD) &(this->tool_top_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "tool_circumference_angle" ,(StepNodeType) 22, (DWORD) &(this->tool_circumference_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "cutting_edge_length" ,(StepNodeType) 22, (DWORD) &(this->cutting_edge_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "edge_radius" ,(StepNodeType) 22, (DWORD) &(this->edge_radius), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "edge_center_vertical" ,(StepNodeType) 22, (DWORD) &(this->edge_center_vertical), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "edge_center_horizontal" ,(StepNodeType) 22, (DWORD) &(this->edge_center_horizontal), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_tool_dimension*/
CStringVector Emilling_tool_dimension::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emilling_type_operation::Emilling_type_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_type_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_machining_operation" ,(StepNodeType) 1, (DWORD) &(this->Emilling_machining_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "approach" ,(StepNodeType) 22, (DWORD) &(this->approach), "Eapproach_retract_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "retract" ,(StepNodeType) 22, (DWORD) &(this->retract), "Eapproach_retract_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_type_operation*/
CStringVector Emilling_type_operation::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Emultistep_drilling::Emultistep_drilling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emultistep_drilling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_operation") ; 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "retract_distance" ,(StepNodeType) 22, (DWORD) &(this->retract_distance), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "first_depth" ,(StepNodeType) 22, (DWORD) &(this->first_depth), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "depth_of_step" ,(StepNodeType) 22, (DWORD) &(this->depth_of_step), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "dwell_time_step" ,(StepNodeType) 22, (DWORD) &(this->dwell_time_step), "Etime_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emultistep_drilling*/
CStringVector Emultistep_drilling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_operation");v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplane_cc_strategy::Eplane_cc_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplane_cc_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Efreeform_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Efreeform_strategy" ,(StepNodeType) 1, (DWORD) &(this->Efreeform_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_plane_normal" ,(StepNodeType) 22, (DWORD) &(this->its_plane_normal), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_cc_strategy*/
CStringVector Eplane_cc_strategy::GetInheritanceChain(){
	CStringVector v;
v.push_back("Efreeform_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplane_cl_strategy::Eplane_cl_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplane_cl_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Efreeform_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Efreeform_strategy" ,(StepNodeType) 1, (DWORD) &(this->Efreeform_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_plane_normal" ,(StepNodeType) 22, (DWORD) &(this->its_plane_normal), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_cl_strategy*/
CStringVector Eplane_cl_strategy::GetInheritanceChain(){
	CStringVector v;
v.push_back("Efreeform_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplane_finish_milling::Eplane_finish_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplane_finish_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplane_milling") ; 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplane_milling" ,(StepNodeType) 1, (DWORD) &(this->Eplane_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_finish_milling*/
CStringVector Eplane_finish_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eplane_milling");v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplane_milling::Eplane_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplane_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_operation" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axial_cutting_depth" ,(StepNodeType) 22, (DWORD) &(this->axial_cutting_depth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "allowance_bottom" ,(StepNodeType) 22, (DWORD) &(this->allowance_bottom), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_milling*/
CStringVector Eplane_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplane_rough_milling::Eplane_rough_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplane_rough_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplane_milling") ; 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplane_milling" ,(StepNodeType) 1, (DWORD) &(this->Eplane_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_rough_milling*/
CStringVector Eplane_rough_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eplane_milling");v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplunge_helix::Eplunge_helix(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplunge_helix";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplunge_strategy") ; 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplunge_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eplunge_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "angle" ,(StepNodeType) 22, (DWORD) &(this->angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplunge_helix*/
CStringVector Eplunge_helix::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eplunge_strategy");v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplunge_ramp::Eplunge_ramp(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplunge_ramp";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplunge_strategy") ; 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplunge_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eplunge_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "angle" ,(StepNodeType) 22, (DWORD) &(this->angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplunge_ramp*/
CStringVector Eplunge_ramp::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eplunge_strategy");v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplunge_strategy::Eplunge_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplunge_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eapproach_retract_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eapproach_retract_strategy::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplunge_strategy*/
CStringVector Eplunge_strategy::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplunge_toolaxis::Eplunge_toolaxis(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplunge_toolaxis";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplunge_strategy") ; 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplunge_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eplunge_strategy::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplunge_toolaxis*/
CStringVector Eplunge_toolaxis::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eplunge_strategy");v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eplunge_zigzag::Eplunge_zigzag(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplunge_zigzag";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplunge_strategy") ; 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplunge_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eplunge_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "angle" ,(StepNodeType) 22, (DWORD) &(this->angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "width" ,(StepNodeType) 22, (DWORD) &(this->width), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplunge_zigzag*/
CStringVector Eplunge_zigzag::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eplunge_strategy");v.push_back("Eapproach_retract_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eprocess_model::Eprocess_model(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprocess_model";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "ini_data_file" ,(StepNodeType) 22, (DWORD) &(this->ini_data_file), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_type" ,(StepNodeType) 22, (DWORD) &(this->its_type), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eprocess_model*/
CStringVector Eprocess_model::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eprocess_model_list::Eprocess_model_list(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprocess_model_list";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_list" ,(StepNodeType) 15, (DWORD) &(this->its_list), "std::vector<Eprocess_modelPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eprocess_model");
	BuildInstanceDef(vars, instancevars);
} /* End Eprocess_model_list*/
CStringVector Eprocess_model_list::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ereamer::Ereamer(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ereamer";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ereamer*/
CStringVector Ereamer::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ereaming::Ereaming(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ereaming";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eboring_operation") ; 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboring_operation" ,(StepNodeType) 1, (DWORD) &(this->Eboring_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ereaming*/
CStringVector Ereaming::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eboring_operation");v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eside_finish_milling::Eside_finish_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eside_finish_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eside_milling") ; 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eside_milling" ,(StepNodeType) 1, (DWORD) &(this->Eside_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eside_finish_milling*/
CStringVector Eside_finish_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eside_milling");v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eside_mill::Eside_mill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eside_mill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "cutter_width" ,(StepNodeType) 22, (DWORD) &(this->cutter_width), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eside_mill*/
CStringVector Eside_mill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eside_milling::Eside_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eside_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_operation" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axial_cutting_depth" ,(StepNodeType) 22, (DWORD) &(this->axial_cutting_depth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "radial_cutting_depth" ,(StepNodeType) 22, (DWORD) &(this->radial_cutting_depth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "allowance_side" ,(StepNodeType) 22, (DWORD) &(this->allowance_side), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eside_milling*/
CStringVector Eside_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eside_rough_milling::Eside_rough_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eside_rough_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eside_milling") ; 
	parents.push_back("Etwo5d_milling_operation") ; 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eside_milling" ,(StepNodeType) 1, (DWORD) &(this->Eside_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eside_rough_milling*/
CStringVector Eside_rough_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eside_milling");v.push_back("Etwo5d_milling_operation");v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Espade_drill::Espade_drill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Espade_drill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrill") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrill" ,(StepNodeType) 1, (DWORD) &(this->Edrill::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Espade_drill*/
CStringVector Espade_drill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrill");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Et_slot_mill::Et_slot_mill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Et_slot_mill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "cutting_thickness" ,(StepNodeType) 22, (DWORD) &(this->cutting_thickness), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Et_slot_mill*/
CStringVector Et_slot_mill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etap::Etap(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etap";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etap*/
CStringVector Etap::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etapered_drill::Etapered_drill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etapered_drill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwist_drill") ; 
	parents.push_back("Edrill") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwist_drill" ,(StepNodeType) 1, (DWORD) &(this->Etwist_drill::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "taper_angle" ,(StepNodeType) 22, (DWORD) &(this->taper_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etapered_drill*/
CStringVector Etapered_drill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwist_drill");v.push_back("Edrill");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etapered_endmill::Etapered_endmill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etapered_endmill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eendmill") ; 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eendmill" ,(StepNodeType) 1, (DWORD) &(this->Eendmill::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "taper_angle" ,(StepNodeType) 22, (DWORD) &(this->taper_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etapered_endmill*/
CStringVector Etapered_endmill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Eendmill");v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etapered_reamer::Etapered_reamer(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etapered_reamer";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ereamer") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ereamer" ,(StepNodeType) 1, (DWORD) &(this->Ereamer::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "taper_angle" ,(StepNodeType) 22, (DWORD) &(this->taper_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etapered_reamer*/
CStringVector Etapered_reamer::GetInheritanceChain(){
	CStringVector v;
v.push_back("Ereamer");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etapered_tap::Etapered_tap(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etapered_tap";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etap") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etap" ,(StepNodeType) 1, (DWORD) &(this->Etap::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "taper_angle" ,(StepNodeType) 22, (DWORD) &(this->taper_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etapered_tap*/
CStringVector Etapered_tap::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etap");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etapping::Etapping(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etapping";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "compensation_chuck" ,(StepNodeType) 7, (DWORD) &(this->compensation_chuck), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etapping*/
CStringVector Etapping::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ethread_drilling::Ethread_drilling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethread_drilling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "helical_movement_on_forward" ,(StepNodeType) 7, (DWORD) &(this->helical_movement_on_forward), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ethread_drilling*/
CStringVector Ethread_drilling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ethread_mill::Ethread_mill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethread_mill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ethread_mill*/
CStringVector Ethread_mill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ethreading_tool::Ethreading_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethreading_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ethreading_tool*/
CStringVector Ethreading_tool::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ethree_axes_tilted_tool::Ethree_axes_tilted_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethree_axes_tilted_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_direction_for_milling") ; 
	parents.push_back("Etool_direction") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_direction_for_milling" ,(StepNodeType) 1, (DWORD) &(this->Etool_direction_for_milling::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "tool_direction" ,(StepNodeType) 22, (DWORD) &(this->tool_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ethree_axes_tilted_tool*/
CStringVector Ethree_axes_tilted_tool::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etool_direction_for_milling");v.push_back("Etool_direction");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etolerances::Etolerances(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etolerances";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "chordal_tolerance" ,(StepNodeType) 22, (DWORD) &(this->chordal_tolerance), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "scallop_height" ,(StepNodeType) 22, (DWORD) &(this->scallop_height), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etolerances*/
CStringVector Etolerances::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etool_direction_for_milling::Etool_direction_for_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_direction_for_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_direction") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_direction" ,(StepNodeType) 1, (DWORD) &(this->Etool_direction::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etool_direction_for_milling*/
CStringVector Etool_direction_for_milling::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etool_direction");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etwist_drill::Etwist_drill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etwist_drill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrill") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrill" ,(StepNodeType) 1, (DWORD) &(this->Edrill::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etwist_drill*/
CStringVector Etwist_drill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Edrill");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etwo5d_milling_operation::Etwo5d_milling_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etwo5d_milling_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Emilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_machining_strategy" ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy), "Etwo5d_milling_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etwo5d_milling_operation*/
CStringVector Etwo5d_milling_operation::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_type_operation");v.push_back("Emilling_machining_operation");v.push_back("Emachining_operation");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Etwo5d_milling_strategy::Etwo5d_milling_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etwo5d_milling_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "overlap" ,(StepNodeType) 22, (DWORD) &(this->overlap), "Epositive_ratio_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "allow_multiple_passes" ,(StepNodeType) 7, (DWORD) &(this->allow_multiple_passes), "EBoolean", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etwo5d_milling_strategy*/
CStringVector Etwo5d_milling_strategy::GetInheritanceChain(){
	CStringVector v;
	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eunidirectional::Eunidirectional(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eunidirectional";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_milling_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_strategy" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feed_direction" ,(StepNodeType) 22, (DWORD) &(this->feed_direction), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "cutmode" ,(StepNodeType) 22, (DWORD) &(this->cutmode), "Ecutmode_type", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eunidirectional*/
CStringVector Eunidirectional::GetInheritanceChain(){
	CStringVector v;
v.push_back("Etwo5d_milling_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Eunload_tool::Eunload_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eunload_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_tool" ,(StepNodeType) 22, (DWORD) &(this->its_tool), "Emachining_tool", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eunload_tool*/
CStringVector Eunload_tool::GetInheritanceChain(){
	CStringVector v;
v.push_back("Enc_function");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Euser_defined_tool::Euser_defined_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Euser_defined_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "identifier" ,(StepNodeType) 22, (DWORD) &(this->identifier), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Euser_defined_tool*/
CStringVector Euser_defined_tool::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Euv_strategy::Euv_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Euv_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Efreeform_strategy") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Efreeform_strategy" ,(StepNodeType) 1, (DWORD) &(this->Efreeform_strategy::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "forward_direction" ,(StepNodeType) 22, (DWORD) &(this->forward_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "sideward_direction" ,(StepNodeType) 22, (DWORD) &(this->sideward_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Euv_strategy*/
CStringVector Euv_strategy::GetInheritanceChain(){
	CStringVector v;
v.push_back("Efreeform_strategy");	return v;
}/* End GetInheritanceChain()*/ 
////////////////////////////////////////////////////////////////////////////////
Ewoodruff_keyseat_mill::Ewoodruff_keyseat_mill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ewoodruff_keyseat_mill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_cutter") ; 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "cutter_width" ,(StepNodeType) 22, (DWORD) &(this->cutter_width), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ewoodruff_keyseat_mill*/
CStringVector Ewoodruff_keyseat_mill::GetInheritanceChain(){
	CStringVector v;
v.push_back("Emilling_cutter");v.push_back("Emilling_tool_body");v.push_back("Etool_body");	return v;
}/* End GetInheritanceChain()*/ 
Ehand::Ehand()
{
 	this->_eType= enumeration_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Ehand";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Epathmode_type::Epathmode_type()
{
 	this->_eType= enumeration_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Epathmode_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Ecutmode_type::Ecutmode_type()
{
 	this->_eType= enumeration_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecutmode_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Eleft_or_right::Eleft_or_right()
{
 	this->_eType= enumeration_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eleft_or_right";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Estroke_connection_strategy::Estroke_connection_strategy()
{
 	this->_eType= enumeration_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Estroke_connection_strategy";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
IStepNodePtr Createmilling_schemaClass(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname=="Eadaptive_control") return Eadaptive_control::Create(name);
	if(classname=="Eair_strategy") return Eair_strategy::Create(name);
	if(classname=="Ealong_path") return Ealong_path::Create(name);
	if(classname=="Eap_retract_angle") return Eap_retract_angle::Create(name);
	if(classname=="Eap_retract_tangent") return Eap_retract_tangent::Create(name);
	if(classname=="Eapproach_retract_strategy") return Eapproach_retract_strategy::Create(name);
	if(classname=="Eback_boring") return Eback_boring::Create(name);
	if(classname=="Ebackside_counterbore") return Ebackside_counterbore::Create(name);
	if(classname=="Ebackside_countersink") return Ebackside_countersink::Create(name);
	if(classname=="Eball_endmill") return Eball_endmill::Create(name);
	if(classname=="Ebidirectional") return Ebidirectional::Create(name);
	if(classname=="Ebidirectional_contour") return Ebidirectional_contour::Create(name);
	if(classname=="Eboring") return Eboring::Create(name);
	if(classname=="Eboring_operation") return Eboring_operation::Create(name);
	if(classname=="Eboring_tool") return Eboring_tool::Create(name);
	if(classname=="Ebottom_and_side_finish_milling") return Ebottom_and_side_finish_milling::Create(name);
	if(classname=="Ebottom_and_side_milling") return Ebottom_and_side_milling::Create(name);
	if(classname=="Ebottom_and_side_rough_milling") return Ebottom_and_side_rough_milling::Create(name);
	if(classname=="Ebullnose_endmill") return Ebullnose_endmill::Create(name);
	if(classname=="Ecenter_drill") return Ecenter_drill::Create(name);
	if(classname=="Ecenter_drilling") return Ecenter_drilling::Create(name);
	if(classname=="Ecenter_milling") return Ecenter_milling::Create(name);
	if(classname=="Ecombined_drill_and_reamer") return Ecombined_drill_and_reamer::Create(name);
	if(classname=="Ecombined_drill_and_tap") return Ecombined_drill_and_tap::Create(name);
	if(classname=="Econtour_bidirectional") return Econtour_bidirectional::Create(name);
	if(classname=="Econtour_parallel") return Econtour_parallel::Create(name);
	if(classname=="Econtour_spiral") return Econtour_spiral::Create(name);
	if(classname=="Ecounter_sinking") return Ecounter_sinking::Create(name);
	if(classname=="Ecounterbore") return Ecounterbore::Create(name);
	if(classname=="Ecountersink") return Ecountersink::Create(name);
	if(classname=="Edovetail_mill") return Edovetail_mill::Create(name);
	if(classname=="Edrill") return Edrill::Create(name);
	if(classname=="Edrilling") return Edrilling::Create(name);
	if(classname=="Edrilling_operation") return Edrilling_operation::Create(name);
	if(classname=="Edrilling_type_operation") return Edrilling_type_operation::Create(name);
	if(classname=="Edrilling_type_strategy") return Edrilling_type_strategy::Create(name);
	if(classname=="Eendmill") return Eendmill::Create(name);
	if(classname=="Eexchange_pallet") return Eexchange_pallet::Create(name);
	if(classname=="Eexplicit") return Eexplicit::Create(name);
	if(classname=="Efacemill") return Efacemill::Create(name);
	if(classname=="Efive_axes_const_tilt_yaw") return Efive_axes_const_tilt_yaw::Create(name);
	if(classname=="Efive_axes_var_tilt_yaw") return Efive_axes_var_tilt_yaw::Create(name);
	if(classname=="Efreeform_operation") return Efreeform_operation::Create(name);
	if(classname=="Efreeform_strategy") return Efreeform_strategy::Create(name);
	if(classname=="Eindex_pallet") return Eindex_pallet::Create(name);
	if(classname=="Eindex_table") return Eindex_table::Create(name);
	if(classname=="Eleading_line_strategy") return Eleading_line_strategy::Create(name);
	if(classname=="Eload_tool") return Eload_tool::Create(name);
	if(classname=="Emilling_cutter") return Emilling_cutter::Create(name);
	if(classname=="Emilling_cutting_tool") return Emilling_cutting_tool::Create(name);
	if(classname=="Emilling_machine_functions") return Emilling_machine_functions::Create(name);
	if(classname=="Emilling_machining_operation") return Emilling_machining_operation::Create(name);
	if(classname=="Emilling_technology") return Emilling_technology::Create(name);
	if(classname=="Emilling_tool_body") return Emilling_tool_body::Create(name);
	if(classname=="Emilling_tool_dimension") return Emilling_tool_dimension::Create(name);
	if(classname=="Emilling_type_operation") return Emilling_type_operation::Create(name);
	if(classname=="Emultistep_drilling") return Emultistep_drilling::Create(name);
	if(classname=="Eplane_cc_strategy") return Eplane_cc_strategy::Create(name);
	if(classname=="Eplane_cl_strategy") return Eplane_cl_strategy::Create(name);
	if(classname=="Eplane_finish_milling") return Eplane_finish_milling::Create(name);
	if(classname=="Eplane_milling") return Eplane_milling::Create(name);
	if(classname=="Eplane_rough_milling") return Eplane_rough_milling::Create(name);
	if(classname=="Eplunge_helix") return Eplunge_helix::Create(name);
	if(classname=="Eplunge_ramp") return Eplunge_ramp::Create(name);
	if(classname=="Eplunge_strategy") return Eplunge_strategy::Create(name);
	if(classname=="Eplunge_toolaxis") return Eplunge_toolaxis::Create(name);
	if(classname=="Eplunge_zigzag") return Eplunge_zigzag::Create(name);
	if(classname=="Eprocess_model") return Eprocess_model::Create(name);
	if(classname=="Eprocess_model_list") return Eprocess_model_list::Create(name);
	if(classname=="Ereamer") return Ereamer::Create(name);
	if(classname=="Ereaming") return Ereaming::Create(name);
	if(classname=="Eside_finish_milling") return Eside_finish_milling::Create(name);
	if(classname=="Eside_mill") return Eside_mill::Create(name);
	if(classname=="Eside_milling") return Eside_milling::Create(name);
	if(classname=="Eside_rough_milling") return Eside_rough_milling::Create(name);
	if(classname=="Espade_drill") return Espade_drill::Create(name);
	if(classname=="Et_slot_mill") return Et_slot_mill::Create(name);
	if(classname=="Etap") return Etap::Create(name);
	if(classname=="Etapered_drill") return Etapered_drill::Create(name);
	if(classname=="Etapered_endmill") return Etapered_endmill::Create(name);
	if(classname=="Etapered_reamer") return Etapered_reamer::Create(name);
	if(classname=="Etapered_tap") return Etapered_tap::Create(name);
	if(classname=="Etapping") return Etapping::Create(name);
	if(classname=="Ethread_drilling") return Ethread_drilling::Create(name);
	if(classname=="Ethread_mill") return Ethread_mill::Create(name);
	if(classname=="Ethreading_tool") return Ethreading_tool::Create(name);
	if(classname=="Ethree_axes_tilted_tool") return Ethree_axes_tilted_tool::Create(name);
	if(classname=="Etolerances") return Etolerances::Create(name);
	if(classname=="Etool_direction_for_milling") return Etool_direction_for_milling::Create(name);
	if(classname=="Etwist_drill") return Etwist_drill::Create(name);
	if(classname=="Etwo5d_milling_operation") return Etwo5d_milling_operation::Create(name);
	if(classname=="Etwo5d_milling_strategy") return Etwo5d_milling_strategy::Create(name);
	if(classname=="Eunidirectional") return Eunidirectional::Create(name);
	if(classname=="Eunload_tool") return Eunload_tool::Create(name);
	if(classname=="Euser_defined_tool") return Euser_defined_tool::Create(name);
	if(classname=="Euv_strategy") return Euv_strategy::Create(name);
	if(classname=="Ewoodruff_keyseat_mill") return Ewoodruff_keyseat_mill::Create(name);
	if(classname=="Ehand") return Ehand::Create(name);
	if(classname=="Epathmode_type") return Epathmode_type::Create(name);
	if(classname=="Ecutmode_type") return Ecutmode_type::Create(name);
	if(classname=="Eleft_or_right") return Eleft_or_right::Create(name);
	if(classname=="Estroke_connection_strategy") return Estroke_connection_strategy::Create(name);
	return NULL; 
}
static int cCcCc = gClassGenerators.AddGenerator(&Createmilling_schemaClass);
	static CStringVector svEntities(97, 
	CString("Eadaptive_control"),
	CString("Eair_strategy"),
	CString("Ealong_path"),
	CString("Eap_retract_angle"),
	CString("Eap_retract_tangent"),
	CString("Eapproach_retract_strategy"),
	CString("Eback_boring"),
	CString("Ebackside_counterbore"),
	CString("Ebackside_countersink"),
	CString("Eball_endmill"),
	CString("Ebidirectional"),
	CString("Ebidirectional_contour"),
	CString("Eboring"),
	CString("Eboring_operation"),
	CString("Eboring_tool"),
	CString("Ebottom_and_side_finish_milling"),
	CString("Ebottom_and_side_milling"),
	CString("Ebottom_and_side_rough_milling"),
	CString("Ebullnose_endmill"),
	CString("Ecenter_drill"),
	CString("Ecenter_drilling"),
	CString("Ecenter_milling"),
	CString("Ecombined_drill_and_reamer"),
	CString("Ecombined_drill_and_tap"),
	CString("Econtour_bidirectional"),
	CString("Econtour_parallel"),
	CString("Econtour_spiral"),
	CString("Ecounter_sinking"),
	CString("Ecounterbore"),
	CString("Ecountersink"),
	CString("Edovetail_mill"),
	CString("Edrill"),
	CString("Edrilling"),
	CString("Edrilling_operation"),
	CString("Edrilling_type_operation"),
	CString("Edrilling_type_strategy"),
	CString("Eendmill"),
	CString("Eexchange_pallet"),
	CString("Eexplicit"),
	CString("Efacemill"),
	CString("Efive_axes_const_tilt_yaw"),
	CString("Efive_axes_var_tilt_yaw"),
	CString("Efreeform_operation"),
	CString("Efreeform_strategy"),
	CString("Eindex_pallet"),
	CString("Eindex_table"),
	CString("Eleading_line_strategy"),
	CString("Eload_tool"),
	CString("Emilling_cutter"),
	CString("Emilling_cutting_tool"),
	CString("Emilling_machine_functions"),
	CString("Emilling_machining_operation"),
	CString("Emilling_technology"),
	CString("Emilling_tool_body"),
	CString("Emilling_tool_dimension"),
	CString("Emilling_type_operation"),
	CString("Emultistep_drilling"),
	CString("Eplane_cc_strategy"),
	CString("Eplane_cl_strategy"),
	CString("Eplane_finish_milling"),
	CString("Eplane_milling"),
	CString("Eplane_rough_milling"),
	CString("Eplunge_helix"),
	CString("Eplunge_ramp"),
	CString("Eplunge_strategy"),
	CString("Eplunge_toolaxis"),
	CString("Eplunge_zigzag"),
	CString("Eprocess_model"),
	CString("Eprocess_model_list"),
	CString("Ereamer"),
	CString("Ereaming"),
	CString("Eside_finish_milling"),
	CString("Eside_mill"),
	CString("Eside_milling"),
	CString("Eside_rough_milling"),
	CString("Espade_drill"),
	CString("Et_slot_mill"),
	CString("Etap"),
	CString("Etapered_drill"),
	CString("Etapered_endmill"),
	CString("Etapered_reamer"),
	CString("Etapered_tap"),
	CString("Etapping"),
	CString("Ethread_drilling"),
	CString("Ethread_mill"),
	CString("Ethreading_tool"),
	CString("Ethree_axes_tilted_tool"),
	CString("Etolerances"),
	CString("Etool_direction_for_milling"),
	CString("Etwist_drill"),
	CString("Etwo5d_milling_operation"),
	CString("Etwo5d_milling_strategy"),
	CString("Eunidirectional"),
	CString("Eunload_tool"),
	CString("Euser_defined_tool"),
	CString("Euv_strategy"),
	CString("Ewoodruff_keyseat_mill"));
 CStringVector GetAllmilling_schemaEntities(){ return svEntities;}
} /* End namespace Express*/
