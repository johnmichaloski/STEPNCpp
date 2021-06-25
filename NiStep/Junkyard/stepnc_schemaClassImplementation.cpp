//
//
//
#include "stdafx.h"
#include "ExpressUtils.h"
#include "stepnc_schemaClassDefinitions.h"
namespace Express{
////////////////////////////////////////////////////////////////////////////////
Eadaptive_control::Eadaptive_control(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eadaptive_control");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eadaptive_control*/
////////////////////////////////////////////////////////////////////////////////
Eaddress::Eaddress(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eaddress");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("internal_location") ,(StepNodeType) 22, (DWORD) &(this->internal_location),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("street_number") ,(StepNodeType) 22, (DWORD) &(this->street_number),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("street") ,(StepNodeType) 22, (DWORD) &(this->street),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("postal_box") ,(StepNodeType) 22, (DWORD) &(this->postal_box),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("town") ,(StepNodeType) 22, (DWORD) &(this->town),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("region") ,(StepNodeType) 22, (DWORD) &(this->region),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("postal_code") ,(StepNodeType) 22, (DWORD) &(this->postal_code),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("country") ,(StepNodeType) 22, (DWORD) &(this->country),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("facsimile_number") ,(StepNodeType) 22, (DWORD) &(this->facsimile_number),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("telephone_number") ,(StepNodeType) 22, (DWORD) &(this->telephone_number),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("electronic_mail_address") ,(StepNodeType) 22, (DWORD) &(this->electronic_mail_address),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("telex_number") ,(StepNodeType) 22, (DWORD) &(this->telex_number),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eaddress*/
////////////////////////////////////////////////////////////////////////////////
Eadvanced_brep_shape_representation::Eadvanced_brep_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eadvanced_brep_shape_representation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eshape_representation")) ; 
	m_parents.push_back(_T("Erepresentation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eshape_representation") ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eadvanced_brep_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Eadvanced_face::Eadvanced_face(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eadvanced_face");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eface_surface")) ; 
	m_parents.push_back(_T("Eface")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eface_surface") ,(StepNodeType) 1, (DWORD) &(this->_face_surface.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eadvanced_face*/
////////////////////////////////////////////////////////////////////////////////
Eair_strategy::Eair_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eair_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eap_retract_angle")) ; 
	 Supertypes().push_back(_T("Eap_retract_tangent")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eapproach_retract_strategy") ,(StepNodeType) 1, (DWORD) &(this->_approach_retract_strategy.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eair_strategy*/
////////////////////////////////////////////////////////////////////////////////
Ealong_path::Ealong_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ealong_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eapproach_retract_strategy") ,(StepNodeType) 1, (DWORD) &(this->_approach_retract_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("path") ,(StepNodeType) 22, (DWORD) &(this->path),  _T("Etoolpath_list") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ealong_path*/
////////////////////////////////////////////////////////////////////////////////
Eand_expression::Eand_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eand_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emultiple_arity_boolean_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emultiple_arity_boolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_multiple_arity_boolean_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eand_expression*/
////////////////////////////////////////////////////////////////////////////////
Eangle_taper::Eangle_taper(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eangle_taper");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("angle") ,(StepNodeType) 22, (DWORD) &(this->angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eangle_taper*/
////////////////////////////////////////////////////////////////////////////////
Eap_lift_path_angle::Eap_lift_path_angle(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eap_lift_path_angle");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eapproach_lift_path")) ; 
	m_parents.push_back(_T("Eparameterised_path")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eapproach_lift_path") ,(StepNodeType) 1, (DWORD) &(this->_approach_lift_path.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("angle") ,(StepNodeType) 22, (DWORD) &(this->angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("benddist") ,(StepNodeType) 22, (DWORD) &(this->benddist),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eap_lift_path_angle*/
////////////////////////////////////////////////////////////////////////////////
Eap_lift_path_tangent::Eap_lift_path_tangent(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eap_lift_path_tangent");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eapproach_lift_path")) ; 
	m_parents.push_back(_T("Eparameterised_path")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eapproach_lift_path") ,(StepNodeType) 1, (DWORD) &(this->_approach_lift_path.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eap_lift_path_tangent*/
////////////////////////////////////////////////////////////////////////////////
Eap_retract_angle::Eap_retract_angle(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eap_retract_angle");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eair_strategy")) ; 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eair_strategy") ,(StepNodeType) 1, (DWORD) &(this->_air_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("angle") ,(StepNodeType) 22, (DWORD) &(this->angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("travel_length") ,(StepNodeType) 22, (DWORD) &(this->travel_length),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eap_retract_angle*/
////////////////////////////////////////////////////////////////////////////////
Eap_retract_tangent::Eap_retract_tangent(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eap_retract_tangent");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eair_strategy")) ; 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eair_strategy") ,(StepNodeType) 1, (DWORD) &(this->_air_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eap_retract_tangent*/
////////////////////////////////////////////////////////////////////////////////
Eapproach_lift_path::Eapproach_lift_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eapproach_lift_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eparameterised_path")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eap_lift_path_angle")) ; 
	 Supertypes().push_back(_T("Eap_lift_path_tangent")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eparameterised_path") ,(StepNodeType) 1, (DWORD) &(this->_parameterised_path.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("fix_point") ,(StepNodeType) 22, (DWORD) &(this->fix_point),  _T("Ecartesian_point") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("fix_point_dir") ,(StepNodeType) 22, (DWORD) &(this->fix_point_dir),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eapproach_lift_path*/
////////////////////////////////////////////////////////////////////////////////
Eapproach_retract_strategy::Eapproach_retract_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eapproach_retract_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eplunge_strategy")) ; 
	 Supertypes().push_back(_T("Eair_strategy")) ; 
	 Supertypes().push_back(_T("Ealong_path")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("tool_orientation") ,(StepNodeType) 22, (DWORD) &(this->tool_orientation),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eapproach_retract_strategy*/
////////////////////////////////////////////////////////////////////////////////
Eapproval::Eapproval(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eapproval");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("status") ,(StepNodeType) 22, (DWORD) &(this->status),  _T("Eapproval_status") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("level") ,(StepNodeType) 22, (DWORD) &(this->level),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eapproval*/
////////////////////////////////////////////////////////////////////////////////
Eapproval_status::Eapproval_status(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eapproval_status");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("name") ,(StepNodeType) 22, (DWORD) &(this->name),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eapproval_status*/
////////////////////////////////////////////////////////////////////////////////
Eassignment::Eassignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eassignment");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprogram_structure")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprogram_structure") ,(StepNodeType) 1, (DWORD) &(this->_program_structure.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_lvalue") ,(StepNodeType) 22, (DWORD) &(this->its_lvalue),  _T("Enc_variable") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_rvalue") ,(StepNodeType) 22, (DWORD) &(this->its_rvalue),  _T("Ervalue") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eassignment*/
////////////////////////////////////////////////////////////////////////////////
Eaxis1_placement::Eaxis1_placement(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eaxis1_placement");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplacement")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplacement") ,(StepNodeType) 1, (DWORD) &(this->_placement.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("axis") ,(StepNodeType) 22, (DWORD) &(this->axis),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eaxis1_placement*/
////////////////////////////////////////////////////////////////////////////////
Eaxis2_placement_3d::Eaxis2_placement_3d(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eaxis2_placement_3d");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplacement")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplacement") ,(StepNodeType) 1, (DWORD) &(this->_placement.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("axis") ,(StepNodeType) 22, (DWORD) &(this->axis),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("ref_direction") ,(StepNodeType) 22, (DWORD) &(this->ref_direction),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eaxis2_placement_3d*/
////////////////////////////////////////////////////////////////////////////////
Eaxis_trajectory::Eaxis_trajectory(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eaxis_trajectory");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etrajectory")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etrajectory") ,(StepNodeType) 1, (DWORD) &(this->_trajectory.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("axis_list") ,(StepNodeType) 13, (DWORD) &(this->axis_list),  _T("EListT<EidentifierPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eidentifier"));
	 axis_list.ListClassname()=_T("Eidentifier"); 
	 axis_list.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("commands") ,(StepNodeType) 13, (DWORD) &(this->commands),  _T("EListT<Ebounded_curvePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ebounded_curve"));
	 commands.ListClassname()=_T("Ebounded_curve"); 
	 commands.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eaxis_trajectory*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_curve::Eb_spline_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eb_spline_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebezier_curve")) ; 
	 Supertypes().push_back(_T("Eb_spline_curve_with_knots")) ; 
	 Supertypes().push_back(_T("Equasi_uniform_curve")) ; 
	 Supertypes().push_back(_T("Erational_b_spline_curve")) ; 
	 Supertypes().push_back(_T("Euniform_curve")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebounded_curve") ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("degree") ,(StepNodeType) entity_, (DWORD) &(this->degree),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("control_points_list") ,(StepNodeType) 13, (DWORD) &(this->control_points_list),  _T("EListT<Ecartesian_pointPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecartesian_point"));
	 control_points_list.ListClassname()=_T("Ecartesian_point"); 
	 control_points_list.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("curve_form") ,(StepNodeType) 22, (DWORD) &(this->curve_form),  _T("Eb_spline_curve_form") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("closed_curve") ,(StepNodeType) entity_, (DWORD) &(this->closed_curve),_T("ELogical")));
	 m_vars.push_back(new CVarDef(this,  _T("self_intersect") ,(StepNodeType) entity_, (DWORD) &(this->self_intersect),_T("ELogical")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eb_spline_curve*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_curve_with_knots::Eb_spline_curve_with_knots(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eb_spline_curve_with_knots");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_curve")) ; 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_curve") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("knot_multiplicities") ,(StepNodeType) 13, (DWORD) &(this->knot_multiplicities),  _T("EListT<EIntegerPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  3,  _T("EInteger"));
	 knot_multiplicities.ListClassname()=_T("EInteger"); 
	 knot_multiplicities.ListType()=(StepNodeType)  3; 
	 m_vars.push_back(new CVarDef(this,  _T("knots") ,(StepNodeType) 13, (DWORD) &(this->knots),  _T("EListT<Eparameter_valuePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eparameter_value"));
	 knots.ListClassname()=_T("Eparameter_value"); 
	 knots.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("knot_spec") ,(StepNodeType) 22, (DWORD) &(this->knot_spec),  _T("Eknot_type") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eb_spline_curve_with_knots*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_surface::Eb_spline_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eb_spline_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebounded_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebezier_surface")) ; 
	 Supertypes().push_back(_T("Eb_spline_surface_with_knots")) ; 
	 Supertypes().push_back(_T("Equasi_uniform_surface")) ; 
	 Supertypes().push_back(_T("Erational_b_spline_surface")) ; 
	 Supertypes().push_back(_T("Euniform_surface")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebounded_surface") ,(StepNodeType) 1, (DWORD) &(this->_bounded_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("u_degree") ,(StepNodeType) entity_, (DWORD) &(this->u_degree),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("v_degree") ,(StepNodeType) entity_, (DWORD) &(this->v_degree),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("control_points_list") ,(StepNodeType) 13, (DWORD) &(this->control_points_list),  _T("std::vector< EListT<Ecartesian_pointPtr> >") , 0));
	 m_vars.back()->Init(2, (StepNodeType)  22,  _T("Ecartesian_point"));
	 m_vars.push_back(new CVarDef(this,  _T("surface_form") ,(StepNodeType) 22, (DWORD) &(this->surface_form),  _T("Eb_spline_surface_form") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("u_closed") ,(StepNodeType) entity_, (DWORD) &(this->u_closed),_T("ELogical")));
	 m_vars.push_back(new CVarDef(this,  _T("v_closed") ,(StepNodeType) entity_, (DWORD) &(this->v_closed),_T("ELogical")));
	 m_vars.push_back(new CVarDef(this,  _T("self_intersect") ,(StepNodeType) entity_, (DWORD) &(this->self_intersect),_T("ELogical")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eb_spline_surface*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_surface_with_knots::Eb_spline_surface_with_knots(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eb_spline_surface_with_knots");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_surface")) ; 
	m_parents.push_back(_T("Ebounded_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_surface") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("u_multiplicities") ,(StepNodeType) 13, (DWORD) &(this->u_multiplicities),  _T("EListT<EIntegerPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  3,  _T("EInteger"));
	 u_multiplicities.ListClassname()=_T("EInteger"); 
	 u_multiplicities.ListType()=(StepNodeType)  3; 
	 m_vars.push_back(new CVarDef(this,  _T("v_multiplicities") ,(StepNodeType) 13, (DWORD) &(this->v_multiplicities),  _T("EListT<EIntegerPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  3,  _T("EInteger"));
	 v_multiplicities.ListClassname()=_T("EInteger"); 
	 v_multiplicities.ListType()=(StepNodeType)  3; 
	 m_vars.push_back(new CVarDef(this,  _T("u_knots") ,(StepNodeType) 13, (DWORD) &(this->u_knots),  _T("EListT<Eparameter_valuePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eparameter_value"));
	 u_knots.ListClassname()=_T("Eparameter_value"); 
	 u_knots.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("v_knots") ,(StepNodeType) 13, (DWORD) &(this->v_knots),  _T("EListT<Eparameter_valuePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eparameter_value"));
	 v_knots.ListClassname()=_T("Eparameter_value"); 
	 v_knots.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("knot_spec") ,(StepNodeType) 22, (DWORD) &(this->knot_spec),  _T("Eknot_type") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eb_spline_surface_with_knots*/
////////////////////////////////////////////////////////////////////////////////
Eback_boring::Eback_boring(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eback_boring");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_type_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_type_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eback_boring*/
////////////////////////////////////////////////////////////////////////////////
Ebackside_counterbore::Ebackside_counterbore(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebackside_counterbore");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecounterbore")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecounterbore") ,(StepNodeType) 1, (DWORD) &(this->_counterbore.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebackside_counterbore*/
////////////////////////////////////////////////////////////////////////////////
Ebackside_countersink::Ebackside_countersink(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebackside_countersink");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecountersink")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecountersink") ,(StepNodeType) 1, (DWORD) &(this->_countersink.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebackside_countersink*/
////////////////////////////////////////////////////////////////////////////////
Eball_endmill::Eball_endmill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eball_endmill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eendmill")) ; 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eendmill") ,(StepNodeType) 1, (DWORD) &(this->_endmill.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eball_endmill*/
////////////////////////////////////////////////////////////////////////////////
Ebezier_curve::Ebezier_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebezier_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_curve")) ; 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_curve") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebezier_curve*/
////////////////////////////////////////////////////////////////////////////////
Ebezier_surface::Ebezier_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebezier_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_surface")) ; 
	m_parents.push_back(_T("Ebounded_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_surface") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebezier_surface*/
////////////////////////////////////////////////////////////////////////////////
Ebidirectional::Ebidirectional(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebidirectional");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feed_direction") ,(StepNodeType) 22, (DWORD) &(this->feed_direction),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("stepover_direction") ,(StepNodeType) 22, (DWORD) &(this->stepover_direction),  _T("Eleft_or_right") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_stroke_connection_strategy") ,(StepNodeType) 22, (DWORD) &(this->its_stroke_connection_strategy),  _T("Estroke_connection_strategy") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebidirectional*/
////////////////////////////////////////////////////////////////////////////////
Ebidirectional_contour::Ebidirectional_contour(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebidirectional_contour");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feed_direction") ,(StepNodeType) 22, (DWORD) &(this->feed_direction),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("stepover_direction") ,(StepNodeType) 22, (DWORD) &(this->stepover_direction),  _T("Eleft_or_right") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("rotation_direction") ,(StepNodeType) 22, (DWORD) &(this->rotation_direction),  _T("Erot_direction") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("spiral_cutmode") ,(StepNodeType) 22, (DWORD) &(this->spiral_cutmode),  _T("Ecutmode_type") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebidirectional_contour*/
////////////////////////////////////////////////////////////////////////////////
Ebinary_boolean_expression::Ebinary_boolean_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebinary_boolean_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Exor_expression")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eboolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_boolean_expression.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("operand1") ,(StepNodeType) 22, (DWORD) &(this->operand1),  _T("Eboolean_expression") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("operand2") ,(StepNodeType) 22, (DWORD) &(this->operand2),  _T("Eboolean_expression") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebinary_boolean_expression*/
////////////////////////////////////////////////////////////////////////////////
Eblind_bottom_condition::Eblind_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eblind_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ehole_bottom_condition")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eflat_hole_bottom")) ; 
	 Supertypes().push_back(_T("Eflat_with_radius_hole_bottom")) ; 
	 Supertypes().push_back(_T("Espherical_hole_bottom")) ; 
	 Supertypes().push_back(_T("Econical_hole_bottom")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ehole_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_hole_bottom_condition.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eblind_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Eblock::Eblock(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eblock");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("position") ,(StepNodeType) 22, (DWORD) &(this->position),  _T("Eaxis2_placement_3d") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("x") ,(StepNodeType) 22, (DWORD) &(this->x),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("y") ,(StepNodeType) 22, (DWORD) &(this->y),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("z") ,(StepNodeType) 22, (DWORD) &(this->z),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eblock*/
////////////////////////////////////////////////////////////////////////////////
Eboolean_expression::Eboolean_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eboolean_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eunary_boolean_expression")) ; 
	 Supertypes().push_back(_T("Ebinary_boolean_expression")) ; 
	 Supertypes().push_back(_T("Emultiple_arity_boolean_expression")) ; 
	 Supertypes().push_back(_T("Ecomparison_expression")) ; 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eboolean_expression*/
////////////////////////////////////////////////////////////////////////////////
Eboring::Eboring(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eboring");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eboring_operation")) ; 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eboring_operation") ,(StepNodeType) 1, (DWORD) &(this->_boring_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eboring*/
////////////////////////////////////////////////////////////////////////////////
Eboring_operation::Eboring_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eboring_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eboring")) ; 
	 Supertypes().push_back(_T("Ereaming")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_type_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_type_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("spindle_stop_at_bottom") ,(StepNodeType) entity_, (DWORD) &(this->spindle_stop_at_bottom),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("depth_of_testcut") ,(StepNodeType) 22, (DWORD) &(this->depth_of_testcut),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("waiting_position") ,(StepNodeType) 22, (DWORD) &(this->waiting_position),  _T("Ecartesian_point") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eboring_operation*/
////////////////////////////////////////////////////////////////////////////////
Eboring_tool::Eboring_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eboring_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eboring_tool*/
////////////////////////////////////////////////////////////////////////////////
Eboss::Eboss(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eboss");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_boundary") ,(StepNodeType) 22, (DWORD) &(this->its_boundary),  _T("Eclosed_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("slope") ,(StepNodeType) 22, (DWORD) &(this->slope),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eboss*/
////////////////////////////////////////////////////////////////////////////////
Ebottom_and_side_finish_milling::Ebottom_and_side_finish_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebottom_and_side_finish_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebottom_and_side_milling")) ; 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebottom_and_side_milling") ,(StepNodeType) 1, (DWORD) &(this->_bottom_and_side_milling.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebottom_and_side_finish_milling*/
////////////////////////////////////////////////////////////////////////////////
Ebottom_and_side_milling::Ebottom_and_side_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebottom_and_side_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebottom_and_side_rough_milling")) ; 
	 Supertypes().push_back(_T("Ebottom_and_side_finish_milling")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_operation") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("axial_cutting_depth") ,(StepNodeType) 22, (DWORD) &(this->axial_cutting_depth),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("radial_cutting_depth") ,(StepNodeType) 22, (DWORD) &(this->radial_cutting_depth),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("allowance_side") ,(StepNodeType) 22, (DWORD) &(this->allowance_side),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("allowance_bottom") ,(StepNodeType) 22, (DWORD) &(this->allowance_bottom),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebottom_and_side_milling*/
////////////////////////////////////////////////////////////////////////////////
Ebottom_and_side_rough_milling::Ebottom_and_side_rough_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebottom_and_side_rough_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebottom_and_side_milling")) ; 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebottom_and_side_milling") ,(StepNodeType) 1, (DWORD) &(this->_bottom_and_side_milling.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebottom_and_side_rough_milling*/
////////////////////////////////////////////////////////////////////////////////
Ebounded_curve::Ebounded_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebounded_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etrimmed_curve")) ; 
	 Supertypes().push_back(_T("Ecomposite_curve")) ; 
	 Supertypes().push_back(_T("Ebounded_pcurve")) ; 
	 Supertypes().push_back(_T("Eb_spline_curve")) ; 
	 Supertypes().push_back(_T("Epolyline")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecurve") ,(StepNodeType) 1, (DWORD) &(this->_curve.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebounded_curve*/
////////////////////////////////////////////////////////////////////////////////
Ebounded_pcurve::Ebounded_pcurve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebounded_pcurve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epcurve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epcurve") ,(StepNodeType) 1, (DWORD) &(this->_pcurve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Ebounded_curve") ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebounded_pcurve*/
////////////////////////////////////////////////////////////////////////////////
Ebounded_surface::Ebounded_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebounded_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eb_spline_surface")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Esurface") ,(StepNodeType) 1, (DWORD) &(this->_surface.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebounded_surface*/
////////////////////////////////////////////////////////////////////////////////
Ebullnose_endmill::Ebullnose_endmill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ebullnose_endmill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eendmill")) ; 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eendmill") ,(StepNodeType) 1, (DWORD) &(this->_endmill.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ebullnose_endmill*/
////////////////////////////////////////////////////////////////////////////////
Ecalendar_date::Ecalendar_date(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecalendar_date");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edate")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edate") ,(StepNodeType) 1, (DWORD) &(this->_date.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("day_component") ,(StepNodeType) 22, (DWORD) &(this->day_component),  _T("Eday_in_month_number") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("month_component") ,(StepNodeType) 22, (DWORD) &(this->month_component),  _T("Emonth_in_year_number") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecalendar_date*/
////////////////////////////////////////////////////////////////////////////////
Ecartesian_point::Ecartesian_point(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecartesian_point");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epoint")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epoint") ,(StepNodeType) 1, (DWORD) &(this->_point.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("coordinates") ,(StepNodeType) 13, (DWORD) &(this->coordinates),  _T("EListT<Elength_measurePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Elength_measure"));
	 coordinates.ListClassname()=_T("Elength_measure"); 
	 coordinates.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecartesian_point*/
////////////////////////////////////////////////////////////////////////////////
Ecatalogue_thread::Ecatalogue_thread(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecatalogue_thread");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ethread")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ethread") ,(StepNodeType) 1, (DWORD) &(this->_thread.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("documentation") ,(StepNodeType) 22, (DWORD) &(this->documentation),  _T("Especification") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecatalogue_thread*/
////////////////////////////////////////////////////////////////////////////////
Ecenter_drill::Ecenter_drill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecenter_drill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecenter_drill*/
////////////////////////////////////////////////////////////////////////////////
Ecenter_drilling::Ecenter_drilling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecenter_drilling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_operation")) ; 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecenter_drilling*/
////////////////////////////////////////////////////////////////////////////////
Ecenter_milling::Ecenter_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecenter_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecenter_milling*/
////////////////////////////////////////////////////////////////////////////////
Echamfer::Echamfer(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Echamfer");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etransition_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etransition_feature") ,(StepNodeType) 1, (DWORD) &(this->_transition_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("angle_to_plane") ,(StepNodeType) 22, (DWORD) &(this->angle_to_plane),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("first_offset_amount") ,(StepNodeType) 22, (DWORD) &(this->first_offset_amount),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Echamfer*/
////////////////////////////////////////////////////////////////////////////////
Echannel::Echannel(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Echannel");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Echannel*/
////////////////////////////////////////////////////////////////////////////////
Ecircle::Ecircle(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecircle");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econic")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econic") ,(StepNodeType) 1, (DWORD) &(this->_conic.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecircle*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_closed_profile::Ecircular_closed_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecircular_closed_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eclosed_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eclosed_profile") ,(StepNodeType) 1, (DWORD) &(this->_closed_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("diameter") ,(StepNodeType) 22, (DWORD) &(this->diameter),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecircular_closed_profile*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_closed_shape_profile::Ecircular_closed_shape_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecircular_closed_shape_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eshape_profile")) ; 
	m_parents.push_back(_T("Eprofile_feature")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eshape_profile") ,(StepNodeType) 1, (DWORD) &(this->_shape_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("closed_boundary") ,(StepNodeType) 22, (DWORD) &(this->closed_boundary),  _T("Ecircular_closed_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecircular_closed_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_offset::Ecircular_offset(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecircular_offset");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("angular_offset") ,(StepNodeType) 22, (DWORD) &(this->angular_offset),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("index") ,(StepNodeType) entity_, (DWORD) &(this->index),_T("EInteger")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecircular_offset*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_omit::Ecircular_omit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecircular_omit");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("index") ,(StepNodeType) entity_, (DWORD) &(this->index),_T("EInteger")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecircular_omit*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_path::Ecircular_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecircular_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etravel_path")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecomplete_circular_path")) ; 
	 Supertypes().push_back(_T("Epartial_circular_path")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etravel_path") ,(StepNodeType) 1, (DWORD) &(this->_travel_path.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecircular_path*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_pattern::Ecircular_pattern(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecircular_pattern");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ereplicate_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ereplicate_feature") ,(StepNodeType) 1, (DWORD) &(this->_replicate_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("angle_increment") ,(StepNodeType) 22, (DWORD) &(this->angle_increment),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("number_of_feature") ,(StepNodeType) entity_, (DWORD) &(this->number_of_feature),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("relocated_base_feature") ,(StepNodeType) 13, (DWORD) &(this->relocated_base_feature),  _T("EListT<Ecircular_offsetPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecircular_offset"));
	 relocated_base_feature.ListClassname()=_T("Ecircular_offset"); 
	 relocated_base_feature.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("missing_base_feature") ,(StepNodeType) 13, (DWORD) &(this->missing_base_feature),  _T("EListT<Ecircular_omitPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecircular_omit"));
	 missing_base_feature.ListClassname()=_T("Ecircular_omit"); 
	 missing_base_feature.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("base_feature_diameter") ,(StepNodeType) 22, (DWORD) &(this->base_feature_diameter),  _T("Etoleranced_length_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("base_feature_rotation") ,(StepNodeType) 22, (DWORD) &(this->base_feature_rotation),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecircular_pattern*/
////////////////////////////////////////////////////////////////////////////////
Eclosed_pocket::Eclosed_pocket(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eclosed_pocket");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epocket")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epocket") ,(StepNodeType) 1, (DWORD) &(this->_pocket.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feature_boundary") ,(StepNodeType) 22, (DWORD) &(this->feature_boundary),  _T("Eclosed_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eclosed_pocket*/
////////////////////////////////////////////////////////////////////////////////
Eclosed_profile::Eclosed_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eclosed_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Erectangular_closed_profile")) ; 
	 Supertypes().push_back(_T("Ecircular_closed_profile")) ; 
	 Supertypes().push_back(_T("Engon_profile")) ; 
	 Supertypes().push_back(_T("Egeneral_closed_profile")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprofile") ,(StepNodeType) 1, (DWORD) &(this->_profile.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eclosed_profile*/
////////////////////////////////////////////////////////////////////////////////
Eclosed_shell::Eclosed_shell(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eclosed_shell");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econnected_face_set")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econnected_face_set") ,(StepNodeType) 1, (DWORD) &(this->_connected_face_set.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eclosed_shell*/
////////////////////////////////////////////////////////////////////////////////
Ecombined_drill_and_reamer::Ecombined_drill_and_reamer(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecombined_drill_and_reamer");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ereamer")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ereamer") ,(StepNodeType) 1, (DWORD) &(this->_reamer.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("drill_length") ,(StepNodeType) 22, (DWORD) &(this->drill_length),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecombined_drill_and_reamer*/
////////////////////////////////////////////////////////////////////////////////
Ecombined_drill_and_tap::Ecombined_drill_and_tap(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecombined_drill_and_tap");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etap")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etap") ,(StepNodeType) 1, (DWORD) &(this->_tap.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("drill_length") ,(StepNodeType) 22, (DWORD) &(this->drill_length),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecombined_drill_and_tap*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_equal::Ecomparison_equal(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomparison_equal");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecomparison_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecomparison_expression") ,(StepNodeType) 1, (DWORD) &(this->_comparison_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomparison_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_expression::Ecomparison_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomparison_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecomparison_equal")) ; 
	 Supertypes().push_back(_T("Ecomparison_not_equal")) ; 
	 Supertypes().push_back(_T("Ecomparison_greater")) ; 
	 Supertypes().push_back(_T("Ecomparison_greater_equal")) ; 
	 Supertypes().push_back(_T("Ecomparison_less")) ; 
	 Supertypes().push_back(_T("Ecomparison_less_equal")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eboolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_boolean_expression.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("operand1") ,(StepNodeType) 22, (DWORD) &(this->operand1),  _T("Enc_variable") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("operand2") ,(StepNodeType) 22, (DWORD) &(this->operand2),  _T("Ervalue") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomparison_expression*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_greater::Ecomparison_greater(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomparison_greater");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecomparison_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecomparison_expression") ,(StepNodeType) 1, (DWORD) &(this->_comparison_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomparison_greater*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_greater_equal::Ecomparison_greater_equal(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomparison_greater_equal");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecomparison_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecomparison_expression") ,(StepNodeType) 1, (DWORD) &(this->_comparison_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomparison_greater_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_less::Ecomparison_less(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomparison_less");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecomparison_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecomparison_expression") ,(StepNodeType) 1, (DWORD) &(this->_comparison_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomparison_less*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_less_equal::Ecomparison_less_equal(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomparison_less_equal");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecomparison_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecomparison_expression") ,(StepNodeType) 1, (DWORD) &(this->_comparison_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomparison_less_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_not_equal::Ecomparison_not_equal(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomparison_not_equal");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecomparison_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecomparison_expression") ,(StepNodeType) 1, (DWORD) &(this->_comparison_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomparison_not_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomplete_circular_path::Ecomplete_circular_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomplete_circular_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecircular_path")) ; 
	m_parents.push_back(_T("Etravel_path")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecircular_path") ,(StepNodeType) 1, (DWORD) &(this->_circular_path.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomplete_circular_path*/
////////////////////////////////////////////////////////////////////////////////
Ecomposite_curve::Ecomposite_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomposite_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebounded_curve") ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("segments") ,(StepNodeType) 13, (DWORD) &(this->segments),  _T("EListT<Ecomposite_curve_segmentPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecomposite_curve_segment"));
	 segments.ListClassname()=_T("Ecomposite_curve_segment"); 
	 segments.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("self_intersect") ,(StepNodeType) entity_, (DWORD) &(this->self_intersect),_T("ELogical")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomposite_curve*/
////////////////////////////////////////////////////////////////////////////////
Ecomposite_curve_segment::Ecomposite_curve_segment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecomposite_curve_segment");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("transition") ,(StepNodeType) 22, (DWORD) &(this->transition),  _T("Etransition_code") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("same_sense") ,(StepNodeType) entity_, (DWORD) &(this->same_sense),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("parent_curve") ,(StepNodeType) 22, (DWORD) &(this->parent_curve),  _T("Ecurve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecomposite_curve_segment*/
////////////////////////////////////////////////////////////////////////////////
Ecompound_feature::Ecompound_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecompound_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecounterbore_hole")) ; 
	 Supertypes().push_back(_T("Ecountersunk_hole")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_manufacturing_feature") ,(StepNodeType) 1, (DWORD) &(this->_two5d_manufacturing_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("elements") ,(StepNodeType) 13, (DWORD) &(this->elements),  _T("EListT<Ecompound_feature_selectPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecompound_feature_select"));
	 elements.ListClassname()=_T("Ecompound_feature_select"); 
	 elements.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecompound_feature*/
////////////////////////////////////////////////////////////////////////////////
Econic::Econic(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econic");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecircle")) ; 
	 Supertypes().push_back(_T("Eellipse")) ; 
	 Supertypes().push_back(_T("Ehyperbola")) ; 
	 Supertypes().push_back(_T("Eparabola")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecurve") ,(StepNodeType) 1, (DWORD) &(this->_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("position") ,(StepNodeType) 22, (DWORD) &(this->position),  _T("Eaxis2_placement_3d") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econic*/
////////////////////////////////////////////////////////////////////////////////
Econical_hole_bottom::Econical_hole_bottom(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econical_hole_bottom");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eblind_bottom_condition")) ; 
	m_parents.push_back(_T("Ehole_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eblind_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_blind_bottom_condition.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("tip_angle") ,(StepNodeType) 22, (DWORD) &(this->tip_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("tip_radius") ,(StepNodeType) 22, (DWORD) &(this->tip_radius),  _T("Etoleranced_length_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econical_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Econnect_direct::Econnect_direct(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econnect_direct");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econnector")) ; 
	m_parents.push_back(_T("Eparameterised_path")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econnector") ,(StepNodeType) 1, (DWORD) &(this->_connector.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econnect_direct*/
////////////////////////////////////////////////////////////////////////////////
Econnect_secplane::Econnect_secplane(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econnect_secplane");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econnector")) ; 
	m_parents.push_back(_T("Eparameterised_path")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econnector") ,(StepNodeType) 1, (DWORD) &(this->_connector.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("up_dir") ,(StepNodeType) 22, (DWORD) &(this->up_dir),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("down_dir") ,(StepNodeType) 22, (DWORD) &(this->down_dir),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econnect_secplane*/
////////////////////////////////////////////////////////////////////////////////
Econnected_face_set::Econnected_face_set(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econnected_face_set");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eclosed_shell")) ; 
	 Supertypes().push_back(_T("Eopen_shell")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etopological_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("cfs_faces") ,(StepNodeType) 13, (DWORD) &(this->cfs_faces),  _T("EListT<EfacePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eface"));
	 cfs_faces.ListClassname()=_T("Eface"); 
	 cfs_faces.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econnected_face_set*/
////////////////////////////////////////////////////////////////////////////////
Econnector::Econnector(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econnector");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eparameterised_path")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Econnect_secplane")) ; 
	 Supertypes().push_back(_T("Econnect_direct")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eparameterised_path") ,(StepNodeType) 1, (DWORD) &(this->_parameterised_path.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econnector*/
////////////////////////////////////////////////////////////////////////////////
Econtour_bidirectional::Econtour_bidirectional(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econtour_bidirectional");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feed_direction") ,(StepNodeType) 22, (DWORD) &(this->feed_direction),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("stepover_direction") ,(StepNodeType) 22, (DWORD) &(this->stepover_direction),  _T("Eleft_or_right") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("rotation_direction") ,(StepNodeType) 22, (DWORD) &(this->rotation_direction),  _T("Erot_direction") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("spiral_cutmode") ,(StepNodeType) 22, (DWORD) &(this->spiral_cutmode),  _T("Ecutmode_type") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econtour_bidirectional*/
////////////////////////////////////////////////////////////////////////////////
Econtour_parallel::Econtour_parallel(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econtour_parallel");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("rotation_direction") ,(StepNodeType) 22, (DWORD) &(this->rotation_direction),  _T("Erot_direction") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("cutmode") ,(StepNodeType) 22, (DWORD) &(this->cutmode),  _T("Ecutmode_type") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econtour_parallel*/
////////////////////////////////////////////////////////////////////////////////
Econtour_spiral::Econtour_spiral(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Econtour_spiral");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("rotation_direction") ,(StepNodeType) 22, (DWORD) &(this->rotation_direction),  _T("Erot_direction") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("cutmode") ,(StepNodeType) 22, (DWORD) &(this->cutmode),  _T("Ecutmode_type") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Econtour_spiral*/
////////////////////////////////////////////////////////////////////////////////
Ecoordinated_universal_time_offset::Ecoordinated_universal_time_offset(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecoordinated_universal_time_offset");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("hour_offset") ,(StepNodeType) entity_, (DWORD) &(this->hour_offset),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("minute_offset") ,(StepNodeType) entity_, (DWORD) &(this->minute_offset),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("sense") ,(StepNodeType) 22, (DWORD) &(this->sense),  _T("Eahead_or_behind") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecoordinated_universal_time_offset*/
////////////////////////////////////////////////////////////////////////////////
Ecounter_sinking::Ecounter_sinking(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecounter_sinking");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_operation")) ; 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecounter_sinking*/
////////////////////////////////////////////////////////////////////////////////
Ecounterbore::Ecounterbore(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecounterbore");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebackside_counterbore")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecounterbore*/
////////////////////////////////////////////////////////////////////////////////
Ecounterbore_hole::Ecounterbore_hole(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecounterbore_hole");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecompound_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecompound_feature") ,(StepNodeType) 1, (DWORD) &(this->_compound_feature.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecounterbore_hole*/
////////////////////////////////////////////////////////////////////////////////
Ecountersink::Ecountersink(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecountersink");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebackside_countersink")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("countersink_radius") ,(StepNodeType) 22, (DWORD) &(this->countersink_radius),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecountersink*/
////////////////////////////////////////////////////////////////////////////////
Ecountersunk_hole::Ecountersunk_hole(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecountersunk_hole");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecompound_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecompound_feature") ,(StepNodeType) 1, (DWORD) &(this->_compound_feature.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecountersunk_hole*/
////////////////////////////////////////////////////////////////////////////////
Ecurve::Ecurve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecurve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebounded_curve")) ; 
	 Supertypes().push_back(_T("Econic")) ; 
	 Supertypes().push_back(_T("Eline")) ; 
	 Supertypes().push_back(_T("Epcurve")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecurve*/
////////////////////////////////////////////////////////////////////////////////
Ecurve_with_normal_vector::Ecurve_with_normal_vector(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecurve_with_normal_vector");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("basiccurve") ,(StepNodeType) 22, (DWORD) &(this->basiccurve),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("surface_normal") ,(StepNodeType) 22, (DWORD) &(this->surface_normal),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecurve_with_normal_vector*/
////////////////////////////////////////////////////////////////////////////////
Ecutter_contact_trajectory::Ecutter_contact_trajectory(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecutter_contact_trajectory");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etrajectory")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etrajectory") ,(StepNodeType) 1, (DWORD) &(this->_trajectory.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("basiccurve") ,(StepNodeType) 22, (DWORD) &(this->basiccurve),  _T("Ecurve_with_surface_normal") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_toolaxis") ,(StepNodeType) 22, (DWORD) &(this->its_toolaxis),  _T("Ebounded_curve") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_contact_type") ,(StepNodeType) 22, (DWORD) &(this->its_contact_type),  _T("Econtact_type") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecutter_contact_trajectory*/
////////////////////////////////////////////////////////////////////////////////
Ecutter_location_trajectory::Ecutter_location_trajectory(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecutter_location_trajectory");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etrajectory")) ; 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etrajectory") ,(StepNodeType) 1, (DWORD) &(this->_trajectory.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("basiccurve") ,(StepNodeType) 22, (DWORD) &(this->basiccurve),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_toolaxis") ,(StepNodeType) 22, (DWORD) &(this->its_toolaxis),  _T("Ebounded_curve") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("surface_normal") ,(StepNodeType) 22, (DWORD) &(this->surface_normal),  _T("Ebounded_curve") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecutter_location_trajectory*/
////////////////////////////////////////////////////////////////////////////////
Ecutting_component::Ecutting_component(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecutting_component");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("tool_offset_length") ,(StepNodeType) 22, (DWORD) &(this->tool_offset_length),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_material") ,(StepNodeType) 22, (DWORD) &(this->its_material),  _T("Ematerial") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("technological_data") ,(StepNodeType) 22, (DWORD) &(this->technological_data),  _T("Ecutting_edge_technological_data") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("expected_tool_life") ,(StepNodeType) 22, (DWORD) &(this->expected_tool_life),  _T("Etime_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_technology") ,(StepNodeType) 22, (DWORD) &(this->its_technology),  _T("Emilling_technology") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecutting_component*/
////////////////////////////////////////////////////////////////////////////////
Ecutting_edge_technological_data::Ecutting_edge_technological_data(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecutting_edge_technological_data");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("cutting_angle") ,(StepNodeType) 22, (DWORD) &(this->cutting_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("free_angle") ,(StepNodeType) 22, (DWORD) &(this->free_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("aux_angle") ,(StepNodeType) 22, (DWORD) &(this->aux_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecutting_edge_technological_data*/
////////////////////////////////////////////////////////////////////////////////
Ecutting_tool::Ecutting_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ecutting_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_tool")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emilling_cutting_tool")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_tool") ,(StepNodeType) 1, (DWORD) &(this->_machining_tool.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_tool_body") ,(StepNodeType) 22, (DWORD) &(this->its_tool_body),  _T("Etool_body") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_cutting_edge") ,(StepNodeType) 13, (DWORD) &(this->its_cutting_edge),  _T("EListT<Ecutting_componentPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecutting_component"));
	 its_cutting_edge.ListClassname()=_T("Ecutting_component"); 
	 its_cutting_edge.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("overall_assembly_length") ,(StepNodeType) 22, (DWORD) &(this->overall_assembly_length),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ecutting_tool*/
////////////////////////////////////////////////////////////////////////////////
Edate::Edate(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edate");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecalendar_date")) ; 
	 Supertypes().push_back(_T("Eordinal_date")) ; 
	 Supertypes().push_back(_T("Eweek_of_year_and_day_date")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("year_component") ,(StepNodeType) 22, (DWORD) &(this->year_component),  _T("Eyear_number") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edate*/
////////////////////////////////////////////////////////////////////////////////
Edate_and_time::Edate_and_time(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edate_and_time");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("date_component") ,(StepNodeType) 22, (DWORD) &(this->date_component),  _T("Edate") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("time_component") ,(StepNodeType) 22, (DWORD) &(this->time_component),  _T("Elocal_time") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edate_and_time*/
////////////////////////////////////////////////////////////////////////////////
Edefined_thread::Edefined_thread(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edefined_thread");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ethread")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ethread") ,(StepNodeType) 1, (DWORD) &(this->_thread.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("pitch_diameter") ,(StepNodeType) 22, (DWORD) &(this->pitch_diameter),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("minor_diameter") ,(StepNodeType) 22, (DWORD) &(this->minor_diameter),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("crest") ,(StepNodeType) 22, (DWORD) &(this->crest),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edefined_thread*/
////////////////////////////////////////////////////////////////////////////////
Edefinitional_representation::Edefinitional_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edefinitional_representation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Erepresentation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Erepresentation") ,(StepNodeType) 1, (DWORD) &(this->_representation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edefinitional_representation*/
////////////////////////////////////////////////////////////////////////////////
Edescriptive_parameter::Edescriptive_parameter(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edescriptive_parameter");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eproperty_parameter")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eproperty_parameter") ,(StepNodeType) 1, (DWORD) &(this->_property_parameter.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("descriptive_string") ,(StepNodeType) 22, (DWORD) &(this->descriptive_string),  _T("Etext") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edescriptive_parameter*/
////////////////////////////////////////////////////////////////////////////////
Ediameter_taper::Ediameter_taper(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ediameter_taper");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("final_diameter") ,(StepNodeType) 22, (DWORD) &(this->final_diameter),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ediameter_taper*/
////////////////////////////////////////////////////////////////////////////////
Edirection::Edirection(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edirection");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("direction_ratios") ,(StepNodeType) 13, (DWORD) &(this->direction_ratios),  _T("EListT<ERealPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  4,  _T("EReal"));
	 direction_ratios.ListClassname()=_T("EReal"); 
	 direction_ratios.ListType()=(StepNodeType)  4; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edirection*/
////////////////////////////////////////////////////////////////////////////////
Edisplay_message::Edisplay_message(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edisplay_message");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_text") ,(StepNodeType) 22, (DWORD) &(this->its_text),  _T("Etext") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edisplay_message*/
////////////////////////////////////////////////////////////////////////////////
Edovetail_mill::Edovetail_mill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edovetail_mill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_cutter") ,(StepNodeType) 1, (DWORD) &(this->_milling_cutter.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("included_angle") ,(StepNodeType) 22, (DWORD) &(this->included_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edovetail_mill*/
////////////////////////////////////////////////////////////////////////////////
Edrill::Edrill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edrill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etwist_drill")) ; 
	 Supertypes().push_back(_T("Espade_drill")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edrill*/
////////////////////////////////////////////////////////////////////////////////
Edrilling::Edrilling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edrilling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_operation")) ; 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edrilling*/
////////////////////////////////////////////////////////////////////////////////
Edrilling_operation::Edrilling_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edrilling_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Edrilling")) ; 
	 Supertypes().push_back(_T("Ecenter_drilling")) ; 
	 Supertypes().push_back(_T("Ecounter_sinking")) ; 
	 Supertypes().push_back(_T("Emultistep_drilling")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_type_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_type_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edrilling_operation*/
////////////////////////////////////////////////////////////////////////////////
Edrilling_type_operation::Edrilling_type_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edrilling_type_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Edrilling_operation")) ; 
	 Supertypes().push_back(_T("Eboring_operation")) ; 
	 Supertypes().push_back(_T("Eback_boring")) ; 
	 Supertypes().push_back(_T("Etapping")) ; 
	 Supertypes().push_back(_T("Ethread_drilling")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_machining_operation") ,(StepNodeType) 1, (DWORD) &(this->_milling_machining_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("cutting_depth") ,(StepNodeType) 22, (DWORD) &(this->cutting_depth),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("previous_diameter") ,(StepNodeType) 22, (DWORD) &(this->previous_diameter),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("dwell_time_bottom") ,(StepNodeType) 22, (DWORD) &(this->dwell_time_bottom),  _T("Etime_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("feed_on_retract") ,(StepNodeType) 22, (DWORD) &(this->feed_on_retract),  _T("Epositive_ratio_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_machining_strategy") ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy),  _T("Edrilling_type_strategy") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edrilling_type_operation*/
////////////////////////////////////////////////////////////////////////////////
Edrilling_type_strategy::Edrilling_type_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Edrilling_type_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("reduced_cut_at_start") ,(StepNodeType) 22, (DWORD) &(this->reduced_cut_at_start),  _T("Epositive_ratio_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("reduced_feed_at_start") ,(StepNodeType) 22, (DWORD) &(this->reduced_feed_at_start),  _T("Epositive_ratio_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("depth_of_start") ,(StepNodeType) 22, (DWORD) &(this->depth_of_start),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("reduced_cut_at_end") ,(StepNodeType) 22, (DWORD) &(this->reduced_cut_at_end),  _T("Epositive_ratio_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("reduced_feed_at_end") ,(StepNodeType) 22, (DWORD) &(this->reduced_feed_at_end),  _T("Epositive_ratio_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("depth_of_end") ,(StepNodeType) 22, (DWORD) &(this->depth_of_end),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Edrilling_type_strategy*/
////////////////////////////////////////////////////////////////////////////////
Eedge::Eedge(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eedge");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eedge_curve")) ; 
	 Supertypes().push_back(_T("Eoriented_edge")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etopological_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("edge_start") ,(StepNodeType) 22, (DWORD) &(this->edge_start),  _T("Evertex") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("edge_end") ,(StepNodeType) 22, (DWORD) &(this->edge_end),  _T("Evertex") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eedge*/
////////////////////////////////////////////////////////////////////////////////
Eedge_curve::Eedge_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eedge_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eedge")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eedge") ,(StepNodeType) 1, (DWORD) &(this->_edge.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("edge_geometry") ,(StepNodeType) 22, (DWORD) &(this->edge_geometry),  _T("Ecurve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("same_sense") ,(StepNodeType) entity_, (DWORD) &(this->same_sense),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eedge_curve*/
////////////////////////////////////////////////////////////////////////////////
Eedge_loop::Eedge_loop(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eedge_loop");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eloop")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	m_parents.push_back(_T("Epath")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eloop") ,(StepNodeType) 1, (DWORD) &(this->_loop.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Epath") ,(StepNodeType) 1, (DWORD) &(this->_path.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eedge_loop*/
////////////////////////////////////////////////////////////////////////////////
Eedge_round::Eedge_round(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eedge_round");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etransition_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etransition_feature") ,(StepNodeType) 1, (DWORD) &(this->_transition_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("first_offset_amount") ,(StepNodeType) 22, (DWORD) &(this->first_offset_amount),  _T("Etoleranced_length_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("second_offset_amount") ,(StepNodeType) 22, (DWORD) &(this->second_offset_amount),  _T("Etoleranced_length_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eedge_round*/
////////////////////////////////////////////////////////////////////////////////
Eelementary_surface::Eelementary_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eelementary_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eplane")) ; 
	 Supertypes().push_back(_T("Espherical_surface")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Esurface") ,(StepNodeType) 1, (DWORD) &(this->_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("position") ,(StepNodeType) 22, (DWORD) &(this->position),  _T("Eaxis2_placement_3d") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eelementary_surface*/
////////////////////////////////////////////////////////////////////////////////
Eellipse::Eellipse(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eellipse");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econic")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econic") ,(StepNodeType) 1, (DWORD) &(this->_conic.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("semi_axis_1") ,(StepNodeType) 22, (DWORD) &(this->semi_axis_1),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("semi_axis_2") ,(StepNodeType) 22, (DWORD) &(this->semi_axis_2),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eellipse*/
////////////////////////////////////////////////////////////////////////////////
Eendmill::Eendmill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eendmill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etapered_endmill")) ; 
	 Supertypes().push_back(_T("Eball_endmill")) ; 
	 Supertypes().push_back(_T("Ebullnose_endmill")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_cutter") ,(StepNodeType) 1, (DWORD) &(this->_milling_cutter.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eendmill*/
////////////////////////////////////////////////////////////////////////////////
Eexchange_pallet::Eexchange_pallet(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eexchange_pallet");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eexchange_pallet*/
////////////////////////////////////////////////////////////////////////////////
Eexecutable::Eexecutable(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eexecutable");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eworkingstep")) ; 
	 Supertypes().push_back(_T("Enc_function")) ; 
	 Supertypes().push_back(_T("Eprogram_structure")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eexecutable*/
////////////////////////////////////////////////////////////////////////////////
Eexplicit::Eexplicit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eexplicit");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eexplicit*/
////////////////////////////////////////////////////////////////////////////////
Eface::Eface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eface_surface")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etopological_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("bounds") ,(StepNodeType) 13, (DWORD) &(this->bounds),  _T("EListT<Eface_boundPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eface_bound"));
	 bounds.ListClassname()=_T("Eface_bound"); 
	 bounds.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eface*/
////////////////////////////////////////////////////////////////////////////////
Eface_bound::Eface_bound(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eface_bound");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eface_outer_bound")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etopological_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("bound") ,(StepNodeType) 22, (DWORD) &(this->bound),  _T("Eloop") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("orientation") ,(StepNodeType) entity_, (DWORD) &(this->orientation),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eface_bound*/
////////////////////////////////////////////////////////////////////////////////
Eface_outer_bound::Eface_outer_bound(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eface_outer_bound");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eface_bound")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eface_bound") ,(StepNodeType) 1, (DWORD) &(this->_face_bound.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eface_outer_bound*/
////////////////////////////////////////////////////////////////////////////////
Eface_surface::Eface_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eface_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eface")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eadvanced_face")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eface") ,(StepNodeType) 1, (DWORD) &(this->_face.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("face_geometry") ,(StepNodeType) 22, (DWORD) &(this->face_geometry),  _T("Esurface") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("same_sense") ,(StepNodeType) entity_, (DWORD) &(this->same_sense),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eface_surface*/
////////////////////////////////////////////////////////////////////////////////
Efacemill::Efacemill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Efacemill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_cutter") ,(StepNodeType) 1, (DWORD) &(this->_milling_cutter.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Efacemill*/
////////////////////////////////////////////////////////////////////////////////
Efeedstop::Efeedstop(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Efeedstop");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etoolpath") ,(StepNodeType) 1, (DWORD) &(this->_toolpath.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("dwell") ,(StepNodeType) 22, (DWORD) &(this->dwell),  _T("Etime_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Efeedstop*/
////////////////////////////////////////////////////////////////////////////////
Efive_axes_const_tilt_yaw::Efive_axes_const_tilt_yaw(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Efive_axes_const_tilt_yaw");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_direction_for_milling")) ; 
	m_parents.push_back(_T("Etool_direction")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_direction_for_milling") ,(StepNodeType) 1, (DWORD) &(this->_tool_direction_for_milling.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("tilt_angle") ,(StepNodeType) 22, (DWORD) &(this->tilt_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("yaw_angle") ,(StepNodeType) 22, (DWORD) &(this->yaw_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Efive_axes_const_tilt_yaw*/
////////////////////////////////////////////////////////////////////////////////
Efive_axes_var_tilt_yaw::Efive_axes_var_tilt_yaw(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Efive_axes_var_tilt_yaw");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_direction_for_milling")) ; 
	m_parents.push_back(_T("Etool_direction")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_direction_for_milling") ,(StepNodeType) 1, (DWORD) &(this->_tool_direction_for_milling.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Efive_axes_var_tilt_yaw*/
////////////////////////////////////////////////////////////////////////////////
Eflat_hole_bottom::Eflat_hole_bottom(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eflat_hole_bottom");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eblind_bottom_condition")) ; 
	m_parents.push_back(_T("Ehole_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eblind_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_blind_bottom_condition.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eflat_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Eflat_slot_end_type::Eflat_slot_end_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eflat_slot_end_type");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eslot_end_type")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eslot_end_type") ,(StepNodeType) 1, (DWORD) &(this->_slot_end_type.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("corner_radius1") ,(StepNodeType) 22, (DWORD) &(this->corner_radius1),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("corner_radius2") ,(StepNodeType) 22, (DWORD) &(this->corner_radius2),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eflat_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Eflat_with_radius_hole_bottom::Eflat_with_radius_hole_bottom(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eflat_with_radius_hole_bottom");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eblind_bottom_condition")) ; 
	m_parents.push_back(_T("Ehole_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eblind_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_blind_bottom_condition.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("corner_radius") ,(StepNodeType) 22, (DWORD) &(this->corner_radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eflat_with_radius_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Efreeform_operation::Efreeform_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Efreeform_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_type_operation") ,(StepNodeType) 1, (DWORD) &(this->_milling_type_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_machining_strategy") ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy),  _T("Efreeform_strategy") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Efreeform_operation*/
////////////////////////////////////////////////////////////////////////////////
Efreeform_strategy::Efreeform_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Efreeform_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Euv_strategy")) ; 
	 Supertypes().push_back(_T("Eplane_cc_strategy")) ; 
	 Supertypes().push_back(_T("Eplane_cl_strategy")) ; 
	 Supertypes().push_back(_T("Eleading_line_strategy")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("pathmode") ,(StepNodeType) 22, (DWORD) &(this->pathmode),  _T("Epathmode_type") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("cutmode") ,(StepNodeType) 22, (DWORD) &(this->cutmode),  _T("Ecutmode_type") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_milling_tolerances") ,(StepNodeType) 22, (DWORD) &(this->its_milling_tolerances),  _T("Etolerances") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("stepover") ,(StepNodeType) 22, (DWORD) &(this->stepover),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Efreeform_strategy*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_closed_profile::Egeneral_closed_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_closed_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eclosed_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eclosed_profile") ,(StepNodeType) 1, (DWORD) &(this->_closed_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("closed_profile_shape") ,(StepNodeType) 22, (DWORD) &(this->closed_profile_shape),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_closed_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_outside_profile::Egeneral_outside_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_outside_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprofile_feature")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprofile_feature") ,(StepNodeType) 1, (DWORD) &(this->_profile_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feature_boundary") ,(StepNodeType) 22, (DWORD) &(this->feature_boundary),  _T("Eprofile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_outside_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_path::Egeneral_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etravel_path")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etravel_path") ,(StepNodeType) 1, (DWORD) &(this->_travel_path.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("swept_path") ,(StepNodeType) 22, (DWORD) &(this->swept_path),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_path*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_pattern::Egeneral_pattern(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_pattern");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ereplicate_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ereplicate_feature") ,(StepNodeType) 1, (DWORD) &(this->_replicate_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("replicate_locations") ,(StepNodeType) 13, (DWORD) &(this->replicate_locations),  _T("EListT<Eaxis2_placement_3dPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eaxis2_placement_3d"));
	 replicate_locations.ListClassname()=_T("Eaxis2_placement_3d"); 
	 replicate_locations.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_pattern*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_pocket_bottom_condition::Egeneral_pocket_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_pocket_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epocket_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epocket_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_pocket_bottom_condition.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("shape") ,(StepNodeType) 22, (DWORD) &(this->shape),  _T("Eregion") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_profile::Egeneral_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eopen_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_profile") ,(StepNodeType) 1, (DWORD) &(this->_open_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_profile") ,(StepNodeType) 22, (DWORD) &(this->its_profile),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_profile_floor::Egeneral_profile_floor(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_profile_floor");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprofile_floor")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprofile_floor") ,(StepNodeType) 1, (DWORD) &(this->_profile_floor.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("floor") ,(StepNodeType) 22, (DWORD) &(this->floor),  _T("Eface") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_profile_floor*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_shape_profile::Egeneral_shape_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeneral_shape_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eshape_profile")) ; 
	m_parents.push_back(_T("Eprofile_feature")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eshape_profile") ,(StepNodeType) 1, (DWORD) &(this->_shape_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("profile_boundary") ,(StepNodeType) 22, (DWORD) &(this->profile_boundary),  _T("Eprofile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeneral_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_representation_context::Egeometric_representation_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeometric_representation_context");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Erepresentation_context")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Erepresentation_context") ,(StepNodeType) 1, (DWORD) &(this->_representation_context.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("coordinate_space_dimension") ,(StepNodeType) 22, (DWORD) &(this->coordinate_space_dimension),  _T("Edimension_count") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeometric_representation_context*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_representation_item::Egeometric_representation_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Egeometric_representation_item");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecurve")) ; 
	 Supertypes().push_back(_T("Edirection")) ; 
	 Supertypes().push_back(_T("Eplacement")) ; 
	 Supertypes().push_back(_T("Epoint")) ; 
	 Supertypes().push_back(_T("Esurface")) ; 
	 Supertypes().push_back(_T("Evector")) ; 
	 Supertypes().push_back(_T("Eedge_curve")) ; 
	 Supertypes().push_back(_T("Eface_surface")) ; 
	 Supertypes().push_back(_T("Evertex_point")) ; 
	 Supertypes().push_back(_T("Eblock")) ; 
	 Supertypes().push_back(_T("Eright_circular_cylinder")) ; 
	 Supertypes().push_back(_T("Esolid_model")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Erepresentation_item") ,(StepNodeType) 1, (DWORD) &(this->_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Egeometric_representation_item*/
////////////////////////////////////////////////////////////////////////////////
Ehole_bottom_condition::Ehole_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ehole_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ethrough_bottom_condition")) ; 
	 Supertypes().push_back(_T("Eblind_bottom_condition")) ; 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ehole_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Ehyperbola::Ehyperbola(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ehyperbola");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econic")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econic") ,(StepNodeType) 1, (DWORD) &(this->_conic.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("semi_axis") ,(StepNodeType) 22, (DWORD) &(this->semi_axis),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("semi_imag_axis") ,(StepNodeType) 22, (DWORD) &(this->semi_imag_axis),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ehyperbola*/
////////////////////////////////////////////////////////////////////////////////
Eif_statement::Eif_statement(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eif_statement");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprogram_structure")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprogram_structure") ,(StepNodeType) 1, (DWORD) &(this->_program_structure.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("condition") ,(StepNodeType) 22, (DWORD) &(this->condition),  _T("Eboolean_expression") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("true_branch") ,(StepNodeType) 22, (DWORD) &(this->true_branch),  _T("Eexecutable") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("false_branch") ,(StepNodeType) 22, (DWORD) &(this->false_branch),  _T("Eexecutable") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eif_statement*/
////////////////////////////////////////////////////////////////////////////////
Ein_process_geometry::Ein_process_geometry(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ein_process_geometry");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("as_is") ,(StepNodeType) 22, (DWORD) &(this->as_is),  _T("Eadvanced_brep_shape_representation") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("to_be") ,(StepNodeType) 22, (DWORD) &(this->to_be),  _T("Eadvanced_brep_shape_representation") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("removal") ,(StepNodeType) 22, (DWORD) &(this->removal),  _T("Eadvanced_brep_shape_representation") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ein_process_geometry*/
////////////////////////////////////////////////////////////////////////////////
Eindex_pallet::Eindex_pallet(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eindex_pallet");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_index") ,(StepNodeType) entity_, (DWORD) &(this->its_index),_T("EInteger")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eindex_pallet*/
////////////////////////////////////////////////////////////////////////////////
Eindex_table::Eindex_table(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eindex_table");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_index") ,(StepNodeType) entity_, (DWORD) &(this->its_index),_T("EInteger")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eindex_table*/
////////////////////////////////////////////////////////////////////////////////
Eleading_line_strategy::Eleading_line_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eleading_line_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Efreeform_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Efreeform_strategy") ,(StepNodeType) 1, (DWORD) &(this->_freeform_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_line") ,(StepNodeType) 22, (DWORD) &(this->its_line),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eleading_line_strategy*/
////////////////////////////////////////////////////////////////////////////////
Elimits_and_fits::Elimits_and_fits(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Elimits_and_fits");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("deviation") ,(StepNodeType) 22, (DWORD) &(this->deviation),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("grade") ,(StepNodeType) 22, (DWORD) &(this->grade),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_fitting_type") ,(StepNodeType) 22, (DWORD) &(this->its_fitting_type),  _T("Efitting_type") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Elimits_and_fits*/
////////////////////////////////////////////////////////////////////////////////
Eline::Eline(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eline");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecurve") ,(StepNodeType) 1, (DWORD) &(this->_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("pnt") ,(StepNodeType) 22, (DWORD) &(this->pnt),  _T("Ecartesian_point") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("dir") ,(StepNodeType) 22, (DWORD) &(this->dir),  _T("Evector") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eline*/
////////////////////////////////////////////////////////////////////////////////
Elinear_path::Elinear_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Elinear_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etravel_path")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etravel_path") ,(StepNodeType) 1, (DWORD) &(this->_travel_path.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("distance") ,(StepNodeType) 22, (DWORD) &(this->distance),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_direction") ,(StepNodeType) 22, (DWORD) &(this->its_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Elinear_path*/
////////////////////////////////////////////////////////////////////////////////
Elinear_profile::Elinear_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Elinear_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eopen_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_profile") ,(StepNodeType) 1, (DWORD) &(this->_open_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("profile_length") ,(StepNodeType) 22, (DWORD) &(this->profile_length),  _T("Enumeric_parameter") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Elinear_profile*/
////////////////////////////////////////////////////////////////////////////////
Eload_tool::Eload_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eload_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_tool") ,(StepNodeType) 22, (DWORD) &(this->its_tool),  _T("Emachining_tool") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eload_tool*/
////////////////////////////////////////////////////////////////////////////////
Elocal_time::Elocal_time(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Elocal_time");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("hour_component") ,(StepNodeType) 22, (DWORD) &(this->hour_component),  _T("Ehour_in_day") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("minute_component") ,(StepNodeType) 22, (DWORD) &(this->minute_component),  _T("Eminute_in_hour") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("second_component") ,(StepNodeType) 22, (DWORD) &(this->second_component),  _T("Esecond_in_minute") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("zone") ,(StepNodeType) 22, (DWORD) &(this->zone),  _T("Ecoordinated_universal_time_offset") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Elocal_time*/
////////////////////////////////////////////////////////////////////////////////
Eloop::Eloop(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eloop");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eedge_loop")) ; 
	 Supertypes().push_back(_T("Evertex_loop")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etopological_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eloop*/
////////////////////////////////////////////////////////////////////////////////
Eloop_slot_end_type::Eloop_slot_end_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eloop_slot_end_type");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eslot_end_type")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eslot_end_type") ,(StepNodeType) 1, (DWORD) &(this->_slot_end_type.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eloop_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Emachine_functions::Emachine_functions(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emachine_functions");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emilling_machine_functions")) ; 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emachine_functions*/
////////////////////////////////////////////////////////////////////////////////
Emachined_surface::Emachined_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emachined_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_machining_feature") ,(StepNodeType) 22, (DWORD) &(this->its_machining_feature),  _T("Emachining_feature") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("surface_element") ,(StepNodeType) 22, (DWORD) &(this->surface_element),  _T("Ebottom_or_side") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emachined_surface*/
////////////////////////////////////////////////////////////////////////////////
Emachining_feature::Emachining_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emachining_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eplanar_face")) ; 
	 Supertypes().push_back(_T("Epocket")) ; 
	 Supertypes().push_back(_T("Eslot")) ; 
	 Supertypes().push_back(_T("Estep")) ; 
	 Supertypes().push_back(_T("Eprofile_feature")) ; 
	 Supertypes().push_back(_T("Eround_hole")) ; 
	 Supertypes().push_back(_T("Etoolpath_feature")) ; 
	 Supertypes().push_back(_T("Eboss")) ; 
	 Supertypes().push_back(_T("Espherical_cap")) ; 
	 Supertypes().push_back(_T("Erounded_end")) ; 
	 Supertypes().push_back(_T("Ethread")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_manufacturing_feature") ,(StepNodeType) 1, (DWORD) &(this->_two5d_manufacturing_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("depth") ,(StepNodeType) 22, (DWORD) &(this->depth),  _T("Eelementary_surface") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emachining_feature*/
////////////////////////////////////////////////////////////////////////////////
Emachining_operation::Emachining_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emachining_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emilling_machining_operation")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eoperation") ,(StepNodeType) 1, (DWORD) &(this->_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("retract_plane") ,(StepNodeType) 22, (DWORD) &(this->retract_plane),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("start_point") ,(StepNodeType) 22, (DWORD) &(this->start_point),  _T("Ecartesian_point") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_tool") ,(StepNodeType) 22, (DWORD) &(this->its_tool),  _T("Emachining_tool") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_technology") ,(StepNodeType) 22, (DWORD) &(this->its_technology),  _T("Etechnology") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_machine_functions") ,(StepNodeType) 22, (DWORD) &(this->its_machine_functions),  _T("Emachine_functions") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emachining_operation*/
////////////////////////////////////////////////////////////////////////////////
Emachining_tool::Emachining_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emachining_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecutting_tool")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emachining_tool*/
////////////////////////////////////////////////////////////////////////////////
Emachining_workingstep::Emachining_workingstep(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emachining_workingstep");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eworkingstep") ,(StepNodeType) 1, (DWORD) &(this->_workingstep.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_feature") ,(StepNodeType) 22, (DWORD) &(this->its_feature),  _T("Emanufacturing_feature") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_operation") ,(StepNodeType) 22, (DWORD) &(this->its_operation),  _T("Emachining_operation") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_effect") ,(StepNodeType) 22, (DWORD) &(this->its_effect),  _T("Ein_process_geometry") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emachining_workingstep*/
////////////////////////////////////////////////////////////////////////////////
Emanifold_solid_brep::Emanifold_solid_brep(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emanifold_solid_brep");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Esolid_model")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Esolid_model") ,(StepNodeType) 1, (DWORD) &(this->_solid_model.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("outer") ,(StepNodeType) 22, (DWORD) &(this->outer),  _T("Eclosed_shell") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emanifold_solid_brep*/
////////////////////////////////////////////////////////////////////////////////
Emanufacturing_feature::Emanufacturing_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emanufacturing_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eregion")) ; 
	 Supertypes().push_back(_T("Etwo5d_manufacturing_feature")) ; 
	 Supertypes().push_back(_T("Etransition_feature")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_workpiece") ,(StepNodeType) 22, (DWORD) &(this->its_workpiece),  _T("Eworkpiece") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_operations") ,(StepNodeType) 13, (DWORD) &(this->its_operations),  _T("EListT<Emachining_operationPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Emachining_operation"));
	 its_operations.ListClassname()=_T("Emachining_operation"); 
	 its_operations.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emanufacturing_feature*/
////////////////////////////////////////////////////////////////////////////////
Ematerial::Ematerial(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ematerial");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("standard_identifier") ,(StepNodeType) 22, (DWORD) &(this->standard_identifier),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("material_identifier") ,(StepNodeType) 22, (DWORD) &(this->material_identifier),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("material_property") ,(StepNodeType) 13, (DWORD) &(this->material_property),  _T("EListT<Eproperty_parameterPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eproperty_parameter"));
	 material_property.ListClassname()=_T("Eproperty_parameter"); 
	 material_property.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ematerial*/
////////////////////////////////////////////////////////////////////////////////
Emilling_cutter::Emilling_cutter(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_cutter");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Efacemill")) ; 
	 Supertypes().push_back(_T("Eendmill")) ; 
	 Supertypes().push_back(_T("Et_slot_mill")) ; 
	 Supertypes().push_back(_T("Edovetail_mill")) ; 
	 Supertypes().push_back(_T("Ewoodruff_keyseat_mill")) ; 
	 Supertypes().push_back(_T("Eside_mill")) ; 
	 Supertypes().push_back(_T("Ethread_mill")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_cutter*/
////////////////////////////////////////////////////////////////////////////////
Emilling_cutting_tool::Emilling_cutting_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_cutting_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecutting_tool")) ; 
	m_parents.push_back(_T("Emachining_tool")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecutting_tool") ,(StepNodeType) 1, (DWORD) &(this->_cutting_tool.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("direction_for_spindle_orientation") ,(StepNodeType) 22, (DWORD) &(this->direction_for_spindle_orientation),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("tool_holder_diameter_for_spindle_orientation") ,(StepNodeType) 22, (DWORD) &(this->tool_holder_diameter_for_spindle_orientation),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_cutting_tool*/
////////////////////////////////////////////////////////////////////////////////
Emilling_machine_functions::Emilling_machine_functions(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_machine_functions");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachine_functions")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachine_functions") ,(StepNodeType) 1, (DWORD) &(this->_machine_functions.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("coolant") ,(StepNodeType) entity_, (DWORD) &(this->coolant),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("coolant_pressure") ,(StepNodeType) 22, (DWORD) &(this->coolant_pressure),  _T("Epressure_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("mist") ,(StepNodeType) entity_, (DWORD) &(this->mist),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("through_spindle_coolant") ,(StepNodeType) entity_, (DWORD) &(this->through_spindle_coolant),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("through_pressure") ,(StepNodeType) 22, (DWORD) &(this->through_pressure),  _T("Epressure_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("axis_clamping") ,(StepNodeType) 13, (DWORD) &(this->axis_clamping),  _T("EListT<EidentifierPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eidentifier"));
	 axis_clamping.ListClassname()=_T("Eidentifier"); 
	 axis_clamping.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("chip_removal") ,(StepNodeType) entity_, (DWORD) &(this->chip_removal),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("oriented_spindle_stop") ,(StepNodeType) 22, (DWORD) &(this->oriented_spindle_stop),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_process_model") ,(StepNodeType) 22, (DWORD) &(this->its_process_model),  _T("Eprocess_model_list") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("other_functions") ,(StepNodeType) 13, (DWORD) &(this->other_functions),  _T("EListT<Eproperty_parameterPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eproperty_parameter"));
	 other_functions.ListClassname()=_T("Eproperty_parameter"); 
	 other_functions.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_machine_functions*/
////////////////////////////////////////////////////////////////////////////////
Emilling_machining_operation::Emilling_machining_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_machining_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emilling_type_operation")) ; 
	 Supertypes().push_back(_T("Edrilling_type_operation")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_operation") ,(StepNodeType) 1, (DWORD) &(this->_machining_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("overcut_length") ,(StepNodeType) 22, (DWORD) &(this->overcut_length),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_machining_operation*/
////////////////////////////////////////////////////////////////////////////////
Emilling_technology::Emilling_technology(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_technology");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etechnology")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etechnology") ,(StepNodeType) 1, (DWORD) &(this->_technology.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("cutspeed") ,(StepNodeType) 22, (DWORD) &(this->cutspeed),  _T("Espeed_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("spindle") ,(StepNodeType) 22, (DWORD) &(this->spindle),  _T("Erot_speed_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("feedrate_per_tooth") ,(StepNodeType) 22, (DWORD) &(this->feedrate_per_tooth),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("synchronize_spindle_with_feed") ,(StepNodeType) entity_, (DWORD) &(this->synchronize_spindle_with_feed),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("inhibit_feedrate_override") ,(StepNodeType) entity_, (DWORD) &(this->inhibit_feedrate_override),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("inhibit_spindle_override") ,(StepNodeType) entity_, (DWORD) &(this->inhibit_spindle_override),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("its_adaptive_control") ,(StepNodeType) 22, (DWORD) &(this->its_adaptive_control),  _T("Eadaptive_control") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_technology*/
////////////////////////////////////////////////////////////////////////////////
Emilling_tool_body::Emilling_tool_body(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_tool_body");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecenter_drill")) ; 
	 Supertypes().push_back(_T("Ecountersink")) ; 
	 Supertypes().push_back(_T("Edrill")) ; 
	 Supertypes().push_back(_T("Emilling_cutter")) ; 
	 Supertypes().push_back(_T("Etap")) ; 
	 Supertypes().push_back(_T("Ethreading_tool")) ; 
	 Supertypes().push_back(_T("Ecounterbore")) ; 
	 Supertypes().push_back(_T("Ereamer")) ; 
	 Supertypes().push_back(_T("Eboring_tool")) ; 
	 Supertypes().push_back(_T("Euser_defined_tool")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_body") ,(StepNodeType) 1, (DWORD) &(this->_tool_body.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("dimension") ,(StepNodeType) 22, (DWORD) &(this->dimension),  _T("Emilling_tool_dimension") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("number_of_teeth") ,(StepNodeType) entity_, (DWORD) &(this->number_of_teeth),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("hand_of_cut") ,(StepNodeType) 22, (DWORD) &(this->hand_of_cut),  _T("Ehand") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("coolant_through_tool") ,(StepNodeType) entity_, (DWORD) &(this->coolant_through_tool),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("pilot_length") ,(StepNodeType) 22, (DWORD) &(this->pilot_length),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_tool_body*/
////////////////////////////////////////////////////////////////////////////////
Emilling_tool_dimension::Emilling_tool_dimension(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_tool_dimension");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("diameter") ,(StepNodeType) 22, (DWORD) &(this->diameter),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("tool_top_angle") ,(StepNodeType) 22, (DWORD) &(this->tool_top_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("tool_circumference_angle") ,(StepNodeType) 22, (DWORD) &(this->tool_circumference_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("cutting_edge_length") ,(StepNodeType) 22, (DWORD) &(this->cutting_edge_length),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("edge_radius") ,(StepNodeType) 22, (DWORD) &(this->edge_radius),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("edge_center_vertical") ,(StepNodeType) 22, (DWORD) &(this->edge_center_vertical),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("edge_center_horizontal") ,(StepNodeType) 22, (DWORD) &(this->edge_center_horizontal),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_tool_dimension*/
////////////////////////////////////////////////////////////////////////////////
Emilling_type_operation::Emilling_type_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emilling_type_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Efreeform_operation")) ; 
	 Supertypes().push_back(_T("Etwo5d_milling_operation")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_machining_operation") ,(StepNodeType) 1, (DWORD) &(this->_milling_machining_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("approach") ,(StepNodeType) 22, (DWORD) &(this->approach),  _T("Eapproach_retract_strategy") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("retract") ,(StepNodeType) 22, (DWORD) &(this->retract),  _T("Eapproach_retract_strategy") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emilling_type_operation*/
////////////////////////////////////////////////////////////////////////////////
Emultiple_arity_boolean_expression::Emultiple_arity_boolean_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emultiple_arity_boolean_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eand_expression")) ; 
	 Supertypes().push_back(_T("Eor_expression")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eboolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_boolean_expression.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("operands") ,(StepNodeType) 13, (DWORD) &(this->operands),  _T("EListT<Eboolean_expressionPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eboolean_expression"));
	 operands.ListClassname()=_T("Eboolean_expression"); 
	 operands.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emultiple_arity_boolean_expression*/
////////////////////////////////////////////////////////////////////////////////
Emultistep_drilling::Emultistep_drilling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Emultistep_drilling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_operation")) ; 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("retract_distance") ,(StepNodeType) 22, (DWORD) &(this->retract_distance),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("first_depth") ,(StepNodeType) 22, (DWORD) &(this->first_depth),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("depth_of_step") ,(StepNodeType) 22, (DWORD) &(this->depth_of_step),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("dwell_time_step") ,(StepNodeType) 22, (DWORD) &(this->dwell_time_step),  _T("Etime_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Emultistep_drilling*/
////////////////////////////////////////////////////////////////////////////////
Enc_constant::Enc_constant(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Enc_constant");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_name") ,(StepNodeType) 22, (DWORD) &(this->its_name),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_value") ,(StepNodeType) 22, (DWORD) &(this->its_value),  _T("Enumber") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Enc_constant*/
////////////////////////////////////////////////////////////////////////////////
Enc_function::Enc_function(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Enc_function");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Edisplay_message")) ; 
	 Supertypes().push_back(_T("Eoptional_stop")) ; 
	 Supertypes().push_back(_T("Eprogram_stop")) ; 
	 Supertypes().push_back(_T("Eset_mark")) ; 
	 Supertypes().push_back(_T("Ewait_for_mark")) ; 
	 Supertypes().push_back(_T("Eexchange_pallet")) ; 
	 Supertypes().push_back(_T("Eindex_pallet")) ; 
	 Supertypes().push_back(_T("Eindex_table")) ; 
	 Supertypes().push_back(_T("Eload_tool")) ; 
	 Supertypes().push_back(_T("Eunload_tool")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eexecutable") ,(StepNodeType) 1, (DWORD) &(this->_executable.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Enc_function*/
////////////////////////////////////////////////////////////////////////////////
Enc_variable::Enc_variable(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Enc_variable");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_name") ,(StepNodeType) 22, (DWORD) &(this->its_name),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("initial_value") ,(StepNodeType) 22, (DWORD) &(this->initial_value),  _T("Enumber") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Enc_variable*/
////////////////////////////////////////////////////////////////////////////////
Engon_profile::Engon_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Engon_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eclosed_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eclosed_profile") ,(StepNodeType) 1, (DWORD) &(this->_closed_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("diameter") ,(StepNodeType) 22, (DWORD) &(this->diameter),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("number_of_sides") ,(StepNodeType) entity_, (DWORD) &(this->number_of_sides),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("circumscribed_or_across_flats") ,(StepNodeType) entity_, (DWORD) &(this->circumscribed_or_across_flats),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Engon_profile*/
////////////////////////////////////////////////////////////////////////////////
Enon_sequential::Enon_sequential(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Enon_sequential");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprogram_structure")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprogram_structure") ,(StepNodeType) 1, (DWORD) &(this->_program_structure.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_elements") ,(StepNodeType) 13, (DWORD) &(this->its_elements),  _T("EListT<EexecutablePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eexecutable"));
	 its_elements.ListClassname()=_T("Eexecutable"); 
	 its_elements.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Enon_sequential*/
////////////////////////////////////////////////////////////////////////////////
Enot_expression::Enot_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Enot_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eunary_boolean_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eunary_boolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_unary_boolean_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Enot_expression*/
////////////////////////////////////////////////////////////////////////////////
Enumeric_parameter::Enumeric_parameter(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Enumeric_parameter");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eproperty_parameter")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eproperty_parameter") ,(StepNodeType) 1, (DWORD) &(this->_property_parameter.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_parameter_value") ,(StepNodeType) 22, (DWORD) &(this->its_parameter_value),  _T("Eparameter_value") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_parameter_unit") ,(StepNodeType) 22, (DWORD) &(this->its_parameter_unit),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Enumeric_parameter*/
////////////////////////////////////////////////////////////////////////////////
Eoffset_vector::Eoffset_vector(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eoffset_vector");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("translate") ,(StepNodeType) 13, (DWORD) &(this->translate),  _T("EListT<Enc_variablePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Enc_variable"));
	 translate.ListClassname()=_T("Enc_variable"); 
	 translate.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("rotate") ,(StepNodeType) 13, (DWORD) &(this->rotate),  _T("EListT<Enc_variablePtr>") , 1));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Enc_variable"));
	 rotate.ListClassname()=_T("Enc_variable"); 
	 rotate.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eoffset_vector*/
////////////////////////////////////////////////////////////////////////////////
Eopen_pocket::Eopen_pocket(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eopen_pocket");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epocket")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epocket") ,(StepNodeType) 1, (DWORD) &(this->_pocket.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("open_boundary") ,(StepNodeType) 22, (DWORD) &(this->open_boundary),  _T("Eopen_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("wall_boundary") ,(StepNodeType) 22, (DWORD) &(this->wall_boundary),  _T("Eopen_profile") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eopen_pocket*/
////////////////////////////////////////////////////////////////////////////////
Eopen_profile::Eopen_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eopen_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Elinear_profile")) ; 
	 Supertypes().push_back(_T("Esquare_u_profile")) ; 
	 Supertypes().push_back(_T("Erounded_u_profile")) ; 
	 Supertypes().push_back(_T("Etee_profile")) ; 
	 Supertypes().push_back(_T("Evee_profile")) ; 
	 Supertypes().push_back(_T("Epartial_circular_profile")) ; 
	 Supertypes().push_back(_T("Egeneral_profile")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprofile") ,(StepNodeType) 1, (DWORD) &(this->_profile.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eopen_profile*/
////////////////////////////////////////////////////////////////////////////////
Eopen_shell::Eopen_shell(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eopen_shell");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econnected_face_set")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etopological_region")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econnected_face_set") ,(StepNodeType) 1, (DWORD) &(this->_connected_face_set.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eopen_shell*/
////////////////////////////////////////////////////////////////////////////////
Eopen_slot_end_type::Eopen_slot_end_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eopen_slot_end_type");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eslot_end_type")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eslot_end_type") ,(StepNodeType) 1, (DWORD) &(this->_slot_end_type.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eopen_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Eoperation::Eoperation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eoperation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Erapid_movement")) ; 
	 Supertypes().push_back(_T("Etouch_probing")) ; 
	 Supertypes().push_back(_T("Emachining_operation")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_toolpath") ,(StepNodeType) 22, (DWORD) &(this->its_toolpath),  _T("Etoolpath_list") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_tool_direction") ,(StepNodeType) 22, (DWORD) &(this->its_tool_direction),  _T("Etool_direction") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eoperation*/
////////////////////////////////////////////////////////////////////////////////
Eoptional_stop::Eoptional_stop(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eoptional_stop");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eoptional_stop*/
////////////////////////////////////////////////////////////////////////////////
Eor_expression::Eor_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eor_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emultiple_arity_boolean_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emultiple_arity_boolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_multiple_arity_boolean_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eor_expression*/
////////////////////////////////////////////////////////////////////////////////
Eordinal_date::Eordinal_date(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eordinal_date");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edate")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edate") ,(StepNodeType) 1, (DWORD) &(this->_date.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("day_component") ,(StepNodeType) 22, (DWORD) &(this->day_component),  _T("Eday_in_year_number") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eordinal_date*/
////////////////////////////////////////////////////////////////////////////////
Eoriented_edge::Eoriented_edge(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eoriented_edge");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eedge")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eedge") ,(StepNodeType) 1, (DWORD) &(this->_edge.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("edge_element") ,(StepNodeType) 22, (DWORD) &(this->edge_element),  _T("Eedge") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("orientation") ,(StepNodeType) entity_, (DWORD) &(this->orientation),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eoriented_edge*/
////////////////////////////////////////////////////////////////////////////////
Eparabola::Eparabola(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eparabola");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Econic")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Econic") ,(StepNodeType) 1, (DWORD) &(this->_conic.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("focal_dist") ,(StepNodeType) 22, (DWORD) &(this->focal_dist),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eparabola*/
////////////////////////////////////////////////////////////////////////////////
Eparallel::Eparallel(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eparallel");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprogram_structure")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprogram_structure") ,(StepNodeType) 1, (DWORD) &(this->_program_structure.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("branches") ,(StepNodeType) 13, (DWORD) &(this->branches),  _T("EListT<EexecutablePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eexecutable"));
	 branches.ListClassname()=_T("Eexecutable"); 
	 branches.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eparallel*/
////////////////////////////////////////////////////////////////////////////////
Eparameterised_path::Eparameterised_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eparameterised_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Econnector")) ; 
	 Supertypes().push_back(_T("Eapproach_lift_path")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etoolpath") ,(StepNodeType) 1, (DWORD) &(this->_toolpath.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eparameterised_path*/
////////////////////////////////////////////////////////////////////////////////
Epartial_area_definition::Epartial_area_definition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epartial_area_definition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("effective_length") ,(StepNodeType) 22, (DWORD) &(this->effective_length),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("placement") ,(StepNodeType) 22, (DWORD) &(this->placement),  _T("Eaxis2_placement_3d") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("maximum_length") ,(StepNodeType) 22, (DWORD) &(this->maximum_length),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epartial_area_definition*/
////////////////////////////////////////////////////////////////////////////////
Epartial_circular_path::Epartial_circular_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epartial_circular_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecircular_path")) ; 
	m_parents.push_back(_T("Etravel_path")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecircular_path") ,(StepNodeType) 1, (DWORD) &(this->_circular_path.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("sweep_angle") ,(StepNodeType) 22, (DWORD) &(this->sweep_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epartial_circular_path*/
////////////////////////////////////////////////////////////////////////////////
Epartial_circular_profile::Epartial_circular_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epartial_circular_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eopen_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_profile") ,(StepNodeType) 1, (DWORD) &(this->_open_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("sweep_angle") ,(StepNodeType) 22, (DWORD) &(this->sweep_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epartial_circular_profile*/
////////////////////////////////////////////////////////////////////////////////
Epartial_circular_shape_profile::Epartial_circular_shape_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epartial_circular_shape_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eshape_profile")) ; 
	m_parents.push_back(_T("Eprofile_feature")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eshape_profile") ,(StepNodeType) 1, (DWORD) &(this->_shape_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("open_boundary") ,(StepNodeType) 22, (DWORD) &(this->open_boundary),  _T("Epartial_circular_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epartial_circular_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Epath::Epath(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epath");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eedge_loop")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etopological_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("edge_list") ,(StepNodeType) 13, (DWORD) &(this->edge_list),  _T("EListT<Eoriented_edgePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eoriented_edge"));
	 edge_list.ListClassname()=_T("Eoriented_edge"); 
	 edge_list.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epath*/
////////////////////////////////////////////////////////////////////////////////
Epcurve::Epcurve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epcurve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebounded_pcurve")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ecurve") ,(StepNodeType) 1, (DWORD) &(this->_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("basis_surface") ,(StepNodeType) 22, (DWORD) &(this->basis_surface),  _T("Esurface") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("reference_to_curve") ,(StepNodeType) 22, (DWORD) &(this->reference_to_curve),  _T("Edefinitional_representation") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epcurve*/
////////////////////////////////////////////////////////////////////////////////
Eperson::Eperson(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eperson");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("id") ,(StepNodeType) 22, (DWORD) &(this->id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("last_name") ,(StepNodeType) 22, (DWORD) &(this->last_name),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("first_name") ,(StepNodeType) 22, (DWORD) &(this->first_name),  _T("Elabel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("middle_names") ,(StepNodeType) 13, (DWORD) &(this->middle_names),  _T("EListT<ElabelPtr>") , 1));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Elabel"));
	 middle_names.ListClassname()=_T("Elabel"); 
	 middle_names.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("prefix_titles") ,(StepNodeType) 13, (DWORD) &(this->prefix_titles),  _T("EListT<ElabelPtr>") , 1));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Elabel"));
	 prefix_titles.ListClassname()=_T("Elabel"); 
	 prefix_titles.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("suffix_titles") ,(StepNodeType) 13, (DWORD) &(this->suffix_titles),  _T("EListT<ElabelPtr>") , 1));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Elabel"));
	 suffix_titles.ListClassname()=_T("Elabel"); 
	 suffix_titles.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eperson*/
////////////////////////////////////////////////////////////////////////////////
Eperson_and_address::Eperson_and_address(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eperson_and_address");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_person") ,(StepNodeType) 22, (DWORD) &(this->its_person),  _T("Eperson") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_address") ,(StepNodeType) 22, (DWORD) &(this->its_address),  _T("Eaddress") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eperson_and_address*/
////////////////////////////////////////////////////////////////////////////////
Eplacement::Eplacement(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplacement");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eaxis1_placement")) ; 
	 Supertypes().push_back(_T("Eaxis2_placement_3d")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("location") ,(StepNodeType) 22, (DWORD) &(this->location),  _T("Ecartesian_point") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplacement*/
////////////////////////////////////////////////////////////////////////////////
Eplanar_face::Eplanar_face(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplanar_face");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("course_of_travel") ,(StepNodeType) 22, (DWORD) &(this->course_of_travel),  _T("Elinear_path") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("removal_boundary") ,(StepNodeType) 22, (DWORD) &(this->removal_boundary),  _T("Elinear_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("face_boundary") ,(StepNodeType) 22, (DWORD) &(this->face_boundary),  _T("Eclosed_profile") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_boss") ,(StepNodeType) 13, (DWORD) &(this->its_boss),  _T("EListT<EbossPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eboss"));
	 its_boss.ListClassname()=_T("Eboss"); 
	 its_boss.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplanar_face*/
////////////////////////////////////////////////////////////////////////////////
Eplanar_pocket_bottom_condition::Eplanar_pocket_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplanar_pocket_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epocket_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epocket_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_pocket_bottom_condition.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplanar_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Eplanar_profile_floor::Eplanar_profile_floor(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplanar_profile_floor");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprofile_floor")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprofile_floor") ,(StepNodeType) 1, (DWORD) &(this->_profile_floor.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("floor") ,(StepNodeType) 22, (DWORD) &(this->floor),  _T("Eplane") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplanar_profile_floor*/
////////////////////////////////////////////////////////////////////////////////
Eplane::Eplane(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplane");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eelementary_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eelementary_surface") ,(StepNodeType) 1, (DWORD) &(this->_elementary_surface.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplane*/
////////////////////////////////////////////////////////////////////////////////
Eplane_cc_strategy::Eplane_cc_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplane_cc_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Efreeform_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Efreeform_strategy") ,(StepNodeType) 1, (DWORD) &(this->_freeform_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_plane_normal") ,(StepNodeType) 22, (DWORD) &(this->its_plane_normal),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplane_cc_strategy*/
////////////////////////////////////////////////////////////////////////////////
Eplane_cl_strategy::Eplane_cl_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplane_cl_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Efreeform_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Efreeform_strategy") ,(StepNodeType) 1, (DWORD) &(this->_freeform_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_plane_normal") ,(StepNodeType) 22, (DWORD) &(this->its_plane_normal),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplane_cl_strategy*/
////////////////////////////////////////////////////////////////////////////////
Eplane_finish_milling::Eplane_finish_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplane_finish_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplane_milling")) ; 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplane_milling") ,(StepNodeType) 1, (DWORD) &(this->_plane_milling.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplane_finish_milling*/
////////////////////////////////////////////////////////////////////////////////
Eplane_milling::Eplane_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplane_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eplane_rough_milling")) ; 
	 Supertypes().push_back(_T("Eplane_finish_milling")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_operation") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("axial_cutting_depth") ,(StepNodeType) 22, (DWORD) &(this->axial_cutting_depth),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("allowance_bottom") ,(StepNodeType) 22, (DWORD) &(this->allowance_bottom),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplane_milling*/
////////////////////////////////////////////////////////////////////////////////
Eplane_rough_milling::Eplane_rough_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplane_rough_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplane_milling")) ; 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplane_milling") ,(StepNodeType) 1, (DWORD) &(this->_plane_milling.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplane_rough_milling*/
////////////////////////////////////////////////////////////////////////////////
Eplunge_helix::Eplunge_helix(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplunge_helix");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplunge_strategy")) ; 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplunge_strategy") ,(StepNodeType) 1, (DWORD) &(this->_plunge_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("angle") ,(StepNodeType) 22, (DWORD) &(this->angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplunge_helix*/
////////////////////////////////////////////////////////////////////////////////
Eplunge_ramp::Eplunge_ramp(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplunge_ramp");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplunge_strategy")) ; 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplunge_strategy") ,(StepNodeType) 1, (DWORD) &(this->_plunge_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("angle") ,(StepNodeType) 22, (DWORD) &(this->angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplunge_ramp*/
////////////////////////////////////////////////////////////////////////////////
Eplunge_strategy::Eplunge_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplunge_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eplunge_toolaxis")) ; 
	 Supertypes().push_back(_T("Eplunge_ramp")) ; 
	 Supertypes().push_back(_T("Eplunge_helix")) ; 
	 Supertypes().push_back(_T("Eplunge_zigzag")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eapproach_retract_strategy") ,(StepNodeType) 1, (DWORD) &(this->_approach_retract_strategy.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplunge_strategy*/
////////////////////////////////////////////////////////////////////////////////
Eplunge_toolaxis::Eplunge_toolaxis(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplunge_toolaxis");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplunge_strategy")) ; 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplunge_strategy") ,(StepNodeType) 1, (DWORD) &(this->_plunge_strategy.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplunge_toolaxis*/
////////////////////////////////////////////////////////////////////////////////
Eplunge_zigzag::Eplunge_zigzag(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplunge_zigzag");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eplunge_strategy")) ; 
	m_parents.push_back(_T("Eapproach_retract_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eplunge_strategy") ,(StepNodeType) 1, (DWORD) &(this->_plunge_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("angle") ,(StepNodeType) 22, (DWORD) &(this->angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("width") ,(StepNodeType) 22, (DWORD) &(this->width),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplunge_zigzag*/
////////////////////////////////////////////////////////////////////////////////
Eplus_minus_value::Eplus_minus_value(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eplus_minus_value");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("upper_limit") ,(StepNodeType) 22, (DWORD) &(this->upper_limit),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("lower_limit") ,(StepNodeType) 22, (DWORD) &(this->lower_limit),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("significant_digits") ,(StepNodeType) entity_, (DWORD) &(this->significant_digits),_T("EInteger")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eplus_minus_value*/
////////////////////////////////////////////////////////////////////////////////
Epocket::Epocket(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epocket");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eclosed_pocket")) ; 
	 Supertypes().push_back(_T("Eopen_pocket")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_boss") ,(StepNodeType) 13, (DWORD) &(this->its_boss),  _T("EListT<EbossPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eboss"));
	 its_boss.ListClassname()=_T("Eboss"); 
	 its_boss.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("slope") ,(StepNodeType) 22, (DWORD) &(this->slope),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("bottom_condition") ,(StepNodeType) 22, (DWORD) &(this->bottom_condition),  _T("Epocket_bottom_condition") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("planar_radius") ,(StepNodeType) 22, (DWORD) &(this->planar_radius),  _T("Etoleranced_length_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("orthogonal_radius") ,(StepNodeType) 22, (DWORD) &(this->orthogonal_radius),  _T("Etoleranced_length_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epocket*/
////////////////////////////////////////////////////////////////////////////////
Epocket_bottom_condition::Epocket_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epocket_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ethrough_pocket_bottom_condition")) ; 
	 Supertypes().push_back(_T("Eplanar_pocket_bottom_condition")) ; 
	 Supertypes().push_back(_T("Eradiused_pocket_bottom_condition")) ; 
	 Supertypes().push_back(_T("Egeneral_pocket_bottom_condition")) ; 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Epoint::Epoint(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epoint");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecartesian_point")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epoint*/
////////////////////////////////////////////////////////////////////////////////
Epolyline::Epolyline(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Epolyline");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebounded_curve") ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("points") ,(StepNodeType) 13, (DWORD) &(this->points),  _T("EListT<Ecartesian_pointPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecartesian_point"));
	 points.ListClassname()=_T("Ecartesian_point"); 
	 points.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Epolyline*/
////////////////////////////////////////////////////////////////////////////////
Eprocess_model::Eprocess_model(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eprocess_model");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("ini_data_file") ,(StepNodeType) 22, (DWORD) &(this->ini_data_file),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_type") ,(StepNodeType) 22, (DWORD) &(this->its_type),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eprocess_model*/
////////////////////////////////////////////////////////////////////////////////
Eprocess_model_list::Eprocess_model_list(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eprocess_model_list");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_list") ,(StepNodeType) 13, (DWORD) &(this->its_list),  _T("EListT<Eprocess_modelPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eprocess_model"));
	 its_list.ListClassname()=_T("Eprocess_model"); 
	 its_list.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eprocess_model_list*/
////////////////////////////////////////////////////////////////////////////////
Eprofile::Eprofile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eprofile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eopen_profile")) ; 
	 Supertypes().push_back(_T("Eclosed_profile")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("placement") ,(StepNodeType) 22, (DWORD) &(this->placement),  _T("Eaxis2_placement_3d") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eprofile*/
////////////////////////////////////////////////////////////////////////////////
Eprofile_feature::Eprofile_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eprofile_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Egeneral_outside_profile")) ; 
	 Supertypes().push_back(_T("Eshape_profile")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("profile_swept_shape") ,(StepNodeType) 22, (DWORD) &(this->profile_swept_shape),  _T("Elinear_path") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eprofile_feature*/
////////////////////////////////////////////////////////////////////////////////
Eprofile_floor::Eprofile_floor(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eprofile_floor");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Egeneral_profile_floor")) ; 
	 Supertypes().push_back(_T("Eplanar_profile_floor")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("floor_radius") ,(StepNodeType) 22, (DWORD) &(this->floor_radius),  _T("Enumeric_parameter") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("start_or_end") ,(StepNodeType) entity_, (DWORD) &(this->start_or_end),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eprofile_floor*/
////////////////////////////////////////////////////////////////////////////////
Eprogram_stop::Eprogram_stop(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eprogram_stop");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eprogram_stop*/
////////////////////////////////////////////////////////////////////////////////
Eprogram_structure::Eprogram_structure(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eprogram_structure");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eworkplan")) ; 
	 Supertypes().push_back(_T("Eparallel")) ; 
	 Supertypes().push_back(_T("Enon_sequential")) ; 
	 Supertypes().push_back(_T("Eselective")) ; 
	 Supertypes().push_back(_T("Eif_statement")) ; 
	 Supertypes().push_back(_T("Ewhile_statement")) ; 
	 Supertypes().push_back(_T("Eassignment")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eexecutable") ,(StepNodeType) 1, (DWORD) &(this->_executable.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eprogram_structure*/
////////////////////////////////////////////////////////////////////////////////
Eproject::Eproject(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eproject");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("main_workplan") ,(StepNodeType) 22, (DWORD) &(this->main_workplan),  _T("Eworkplan") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_workpieces") ,(StepNodeType) 13, (DWORD) &(this->its_workpieces),  _T("EListT<EworkpiecePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eworkpiece"));
	 its_workpieces.ListClassname()=_T("Eworkpiece"); 
	 its_workpieces.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("its_owner") ,(StepNodeType) 22, (DWORD) &(this->its_owner),  _T("Eperson_and_address") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_release") ,(StepNodeType) 22, (DWORD) &(this->its_release),  _T("Edate_and_time") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_status") ,(StepNodeType) 22, (DWORD) &(this->its_status),  _T("Eapproval") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eproject*/
////////////////////////////////////////////////////////////////////////////////
Eproperty_parameter::Eproperty_parameter(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eproperty_parameter");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Edescriptive_parameter")) ; 
	 Supertypes().push_back(_T("Enumeric_parameter")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("parameter_name") ,(StepNodeType) 22, (DWORD) &(this->parameter_name),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eproperty_parameter*/
////////////////////////////////////////////////////////////////////////////////
Equasi_uniform_curve::Equasi_uniform_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Equasi_uniform_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_curve")) ; 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_curve") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Equasi_uniform_curve*/
////////////////////////////////////////////////////////////////////////////////
Equasi_uniform_surface::Equasi_uniform_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Equasi_uniform_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_surface")) ; 
	m_parents.push_back(_T("Ebounded_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_surface") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Equasi_uniform_surface*/
////////////////////////////////////////////////////////////////////////////////
Eradiused_pocket_bottom_condition::Eradiused_pocket_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eradiused_pocket_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epocket_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epocket_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_pocket_bottom_condition.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("floor_radius_center") ,(StepNodeType) 22, (DWORD) &(this->floor_radius_center),  _T("Ecartesian_point") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("floor_radius") ,(StepNodeType) 22, (DWORD) &(this->floor_radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eradiused_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Eradiused_slot_end_type::Eradiused_slot_end_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eradiused_slot_end_type");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eslot_end_type")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eslot_end_type") ,(StepNodeType) 1, (DWORD) &(this->_slot_end_type.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eradiused_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Erapid_movement::Erapid_movement(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erapid_movement");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ereturn_home")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eworkingstep") ,(StepNodeType) 1, (DWORD) &(this->_workingstep.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Eoperation") ,(StepNodeType) 1, (DWORD) &(this->_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erapid_movement*/
////////////////////////////////////////////////////////////////////////////////
Erational_b_spline_curve::Erational_b_spline_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erational_b_spline_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_curve")) ; 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_curve") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("weights_data") ,(StepNodeType) 13, (DWORD) &(this->weights_data),  _T("EListT<ERealPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  4,  _T("EReal"));
	 weights_data.ListClassname()=_T("EReal"); 
	 weights_data.ListType()=(StepNodeType)  4; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erational_b_spline_curve*/
////////////////////////////////////////////////////////////////////////////////
Erational_b_spline_surface::Erational_b_spline_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erational_b_spline_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_surface")) ; 
	m_parents.push_back(_T("Ebounded_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_surface") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("weights_data") ,(StepNodeType) 13, (DWORD) &(this->weights_data),  _T("std::vector< EListT<ERealPtr> >") , 0));
	 m_vars.back()->Init(2, (StepNodeType)  4,  _T("EReal"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erational_b_spline_surface*/
////////////////////////////////////////////////////////////////////////////////
Ereamer::Ereamer(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ereamer");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etapered_reamer")) ; 
	 Supertypes().push_back(_T("Ecombined_drill_and_reamer")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ereamer*/
////////////////////////////////////////////////////////////////////////////////
Ereaming::Ereaming(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ereaming");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eboring_operation")) ; 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eboring_operation") ,(StepNodeType) 1, (DWORD) &(this->_boring_operation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ereaming*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_closed_profile::Erectangular_closed_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erectangular_closed_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eclosed_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eclosed_profile") ,(StepNodeType) 1, (DWORD) &(this->_closed_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("profile_width") ,(StepNodeType) 22, (DWORD) &(this->profile_width),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("profile_length") ,(StepNodeType) 22, (DWORD) &(this->profile_length),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erectangular_closed_profile*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_closed_shape_profile::Erectangular_closed_shape_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erectangular_closed_shape_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eshape_profile")) ; 
	m_parents.push_back(_T("Eprofile_feature")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eshape_profile") ,(StepNodeType) 1, (DWORD) &(this->_shape_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("closed_boundary") ,(StepNodeType) 22, (DWORD) &(this->closed_boundary),  _T("Erectangular_closed_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erectangular_closed_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_offset::Erectangular_offset(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erectangular_offset");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("offset_direction") ,(StepNodeType) 22, (DWORD) &(this->offset_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("offset_distance") ,(StepNodeType) 22, (DWORD) &(this->offset_distance),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("row_index") ,(StepNodeType) entity_, (DWORD) &(this->row_index),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("column_index") ,(StepNodeType) entity_, (DWORD) &(this->column_index),_T("EInteger")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erectangular_offset*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_omit::Erectangular_omit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erectangular_omit");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("row_index") ,(StepNodeType) entity_, (DWORD) &(this->row_index),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("column_index") ,(StepNodeType) entity_, (DWORD) &(this->column_index),_T("EInteger")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erectangular_omit*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_open_shape_profile::Erectangular_open_shape_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erectangular_open_shape_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eshape_profile")) ; 
	m_parents.push_back(_T("Eprofile_feature")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eshape_profile") ,(StepNodeType) 1, (DWORD) &(this->_shape_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("open_boundary") ,(StepNodeType) 22, (DWORD) &(this->open_boundary),  _T("Esquare_u_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erectangular_open_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_pattern::Erectangular_pattern(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erectangular_pattern");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ereplicate_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ereplicate_feature") ,(StepNodeType) 1, (DWORD) &(this->_replicate_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("spacing") ,(StepNodeType) 22, (DWORD) &(this->spacing),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_direction") ,(StepNodeType) 22, (DWORD) &(this->its_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("number_of_rows") ,(StepNodeType) entity_, (DWORD) &(this->number_of_rows),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("number_of_columns") ,(StepNodeType) entity_, (DWORD) &(this->number_of_columns),_T("EInteger")));
	 m_vars.push_back(new CVarDef(this,  _T("row_spacing") ,(StepNodeType) 22, (DWORD) &(this->row_spacing),  _T("Etoleranced_length_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("row_layout_direction") ,(StepNodeType) 22, (DWORD) &(this->row_layout_direction),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("relocated_base_feature") ,(StepNodeType) 13, (DWORD) &(this->relocated_base_feature),  _T("EListT<Erectangular_offsetPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Erectangular_offset"));
	 relocated_base_feature.ListClassname()=_T("Erectangular_offset"); 
	 relocated_base_feature.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("missing_base_feature") ,(StepNodeType) 13, (DWORD) &(this->missing_base_feature),  _T("EListT<Erectangular_omitPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Erectangular_omit"));
	 missing_base_feature.ListClassname()=_T("Erectangular_omit"); 
	 missing_base_feature.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erectangular_pattern*/
////////////////////////////////////////////////////////////////////////////////
Eregion::Eregion(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eregion");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eregion_projection")) ; 
	 Supertypes().push_back(_T("Eregion_surface_list")) ; 
	 Supertypes().push_back(_T("Etopological_region")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emanufacturing_feature") ,(StepNodeType) 1, (DWORD) &(this->_manufacturing_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feature_placement") ,(StepNodeType) 22, (DWORD) &(this->feature_placement),  _T("Eaxis2_placement_3d") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eregion*/
////////////////////////////////////////////////////////////////////////////////
Eregion_projection::Eregion_projection(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eregion_projection");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eregion")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eregion") ,(StepNodeType) 1, (DWORD) &(this->_region.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("proj_curve") ,(StepNodeType) 22, (DWORD) &(this->proj_curve),  _T("Ebounded_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("proj_dir") ,(StepNodeType) 22, (DWORD) &(this->proj_dir),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("depth") ,(StepNodeType) 22, (DWORD) &(this->depth),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eregion_projection*/
////////////////////////////////////////////////////////////////////////////////
Eregion_surface_list::Eregion_surface_list(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eregion_surface_list");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eregion")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eregion") ,(StepNodeType) 1, (DWORD) &(this->_region.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("surface_list") ,(StepNodeType) 13, (DWORD) &(this->surface_list),  _T("EListT<Ebounded_surfacePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ebounded_surface"));
	 surface_list.ListClassname()=_T("Ebounded_surface"); 
	 surface_list.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eregion_surface_list*/
////////////////////////////////////////////////////////////////////////////////
Ereplicate_feature::Ereplicate_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ereplicate_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecircular_pattern")) ; 
	 Supertypes().push_back(_T("Erectangular_pattern")) ; 
	 Supertypes().push_back(_T("Egeneral_pattern")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_manufacturing_feature") ,(StepNodeType) 1, (DWORD) &(this->_two5d_manufacturing_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("replicate_base_feature") ,(StepNodeType) 22, (DWORD) &(this->replicate_base_feature),  _T("Etwo5d_manufacturing_feature") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ereplicate_feature*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation::Erepresentation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erepresentation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eshape_representation")) ; 
	 Supertypes().push_back(_T("Edefinitional_representation")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("name") ,(StepNodeType) 22, (DWORD) &(this->name),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("items") ,(StepNodeType) 13, (DWORD) &(this->items),  _T("EListT<Erepresentation_itemPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Erepresentation_item"));
	 items.ListClassname()=_T("Erepresentation_item"); 
	 items.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("context_of_items") ,(StepNodeType) 22, (DWORD) &(this->context_of_items),  _T("Erepresentation_context") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erepresentation*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_context::Erepresentation_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erepresentation_context");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Egeometric_representation_context")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("context_identifier") ,(StepNodeType) 22, (DWORD) &(this->context_identifier),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("context_type") ,(StepNodeType) 22, (DWORD) &(this->context_type),  _T("Etext") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erepresentation_context*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_item::Erepresentation_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erepresentation_item");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Egeometric_representation_item")) ; 
	 Supertypes().push_back(_T("Etopological_representation_item")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("name") ,(StepNodeType) 22, (DWORD) &(this->name),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erepresentation_item*/
////////////////////////////////////////////////////////////////////////////////
Ereturn_home::Ereturn_home(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ereturn_home");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Erapid_movement")) ; 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Erapid_movement") ,(StepNodeType) 1, (DWORD) &(this->_rapid_movement.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ereturn_home*/
////////////////////////////////////////////////////////////////////////////////
Eright_circular_cylinder::Eright_circular_cylinder(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eright_circular_cylinder");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("position") ,(StepNodeType) 22, (DWORD) &(this->position),  _T("Eaxis1_placement") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("height") ,(StepNodeType) 22, (DWORD) &(this->height),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eright_circular_cylinder*/
////////////////////////////////////////////////////////////////////////////////
Eround_hole::Eround_hole(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eround_hole");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("diameter") ,(StepNodeType) 22, (DWORD) &(this->diameter),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("change_in_diameter") ,(StepNodeType) 22, (DWORD) &(this->change_in_diameter),  _T("Etaper_select") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("bottom_condition") ,(StepNodeType) 22, (DWORD) &(this->bottom_condition),  _T("Ehole_bottom_condition") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eround_hole*/
////////////////////////////////////////////////////////////////////////////////
Erounded_end::Erounded_end(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erounded_end");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("course_of_travel") ,(StepNodeType) 22, (DWORD) &(this->course_of_travel),  _T("Elinear_path") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("partial_circular_boundary") ,(StepNodeType) 22, (DWORD) &(this->partial_circular_boundary),  _T("Epartial_circular_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erounded_end*/
////////////////////////////////////////////////////////////////////////////////
Erounded_u_profile::Erounded_u_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Erounded_u_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eopen_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_profile") ,(StepNodeType) 1, (DWORD) &(this->_open_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("width") ,(StepNodeType) 22, (DWORD) &(this->width),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Erounded_u_profile*/
////////////////////////////////////////////////////////////////////////////////
Eselective::Eselective(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eselective");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprogram_structure")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprogram_structure") ,(StepNodeType) 1, (DWORD) &(this->_program_structure.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_elements") ,(StepNodeType) 13, (DWORD) &(this->its_elements),  _T("EListT<EexecutablePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eexecutable"));
	 its_elements.ListClassname()=_T("Eexecutable"); 
	 its_elements.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eselective*/
////////////////////////////////////////////////////////////////////////////////
Eset_mark::Eset_mark(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eset_mark");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eset_mark*/
////////////////////////////////////////////////////////////////////////////////
Esetup::Esetup(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esetup");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_origin") ,(StepNodeType) 22, (DWORD) &(this->its_origin),  _T("Eaxis2_placement_3d") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_secplane") ,(StepNodeType) 22, (DWORD) &(this->its_secplane),  _T("Eelementary_surface") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_workpiece_setup") ,(StepNodeType) 13, (DWORD) &(this->its_workpiece_setup),  _T("EListT<Eworkpiece_setupPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eworkpiece_setup"));
	 its_workpiece_setup.ListClassname()=_T("Eworkpiece_setup"); 
	 its_workpiece_setup.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esetup*/
////////////////////////////////////////////////////////////////////////////////
Esetup_instruction::Esetup_instruction(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esetup_instruction");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("description") ,(StepNodeType) 22, (DWORD) &(this->description),  _T("Etext") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("external_document") ,(StepNodeType) 22, (DWORD) &(this->external_document),  _T("Eidentifier") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esetup_instruction*/
////////////////////////////////////////////////////////////////////////////////
Eshape_profile::Eshape_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eshape_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprofile_feature")) ; 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Egeneral_shape_profile")) ; 
	 Supertypes().push_back(_T("Epartial_circular_shape_profile")) ; 
	 Supertypes().push_back(_T("Ecircular_closed_shape_profile")) ; 
	 Supertypes().push_back(_T("Erectangular_open_shape_profile")) ; 
	 Supertypes().push_back(_T("Erectangular_closed_shape_profile")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprofile_feature") ,(StepNodeType) 1, (DWORD) &(this->_profile_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("floor_condition") ,(StepNodeType) 22, (DWORD) &(this->floor_condition),  _T("Eprofile_select") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("removal_direction") ,(StepNodeType) 22, (DWORD) &(this->removal_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eshape_profile*/
////////////////////////////////////////////////////////////////////////////////
Eshape_representation::Eshape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eshape_representation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Erepresentation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eadvanced_brep_shape_representation")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Erepresentation") ,(StepNodeType) 1, (DWORD) &(this->_representation.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eshape_representation*/
////////////////////////////////////////////////////////////////////////////////
Eside_finish_milling::Eside_finish_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eside_finish_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eside_milling")) ; 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eside_milling") ,(StepNodeType) 1, (DWORD) &(this->_side_milling.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eside_finish_milling*/
////////////////////////////////////////////////////////////////////////////////
Eside_mill::Eside_mill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eside_mill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_cutter") ,(StepNodeType) 1, (DWORD) &(this->_milling_cutter.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("cutter_width") ,(StepNodeType) 22, (DWORD) &(this->cutter_width),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eside_mill*/
////////////////////////////////////////////////////////////////////////////////
Eside_milling::Eside_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eside_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eside_rough_milling")) ; 
	 Supertypes().push_back(_T("Eside_finish_milling")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_operation") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("axial_cutting_depth") ,(StepNodeType) 22, (DWORD) &(this->axial_cutting_depth),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("radial_cutting_depth") ,(StepNodeType) 22, (DWORD) &(this->radial_cutting_depth),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("allowance_side") ,(StepNodeType) 22, (DWORD) &(this->allowance_side),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eside_milling*/
////////////////////////////////////////////////////////////////////////////////
Eside_rough_milling::Eside_rough_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eside_rough_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eside_milling")) ; 
	m_parents.push_back(_T("Etwo5d_milling_operation")) ; 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eside_milling") ,(StepNodeType) 1, (DWORD) &(this->_side_milling.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eside_rough_milling*/
////////////////////////////////////////////////////////////////////////////////
Eslot::Eslot(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eslot");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("course_of_travel") ,(StepNodeType) 22, (DWORD) &(this->course_of_travel),  _T("Etravel_path") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("swept_shape") ,(StepNodeType) 22, (DWORD) &(this->swept_shape),  _T("Eopen_profile") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("end_conditions") ,(StepNodeType) 13, (DWORD) &(this->end_conditions),  _T("EListT<Eslot_end_typePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eslot_end_type"));
	 end_conditions.ListClassname()=_T("Eslot_end_type"); 
	 end_conditions.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eslot*/
////////////////////////////////////////////////////////////////////////////////
Eslot_end_type::Eslot_end_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eslot_end_type");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ewoodruff_slot_end_type")) ; 
	 Supertypes().push_back(_T("Eradiused_slot_end_type")) ; 
	 Supertypes().push_back(_T("Eflat_slot_end_type")) ; 
	 Supertypes().push_back(_T("Eloop_slot_end_type")) ; 
	 Supertypes().push_back(_T("Eopen_slot_end_type")) ; 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eslot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Esolid_model::Esolid_model(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esolid_model");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emanifold_solid_brep")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esolid_model*/
////////////////////////////////////////////////////////////////////////////////
Espade_drill::Espade_drill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Espade_drill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrill")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrill") ,(StepNodeType) 1, (DWORD) &(this->_drill.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Espade_drill*/
////////////////////////////////////////////////////////////////////////////////
Especification::Especification(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Especification");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("constraint") ,(StepNodeType) 13, (DWORD) &(this->constraint),  _T("EListT<Especification_usage_constraintPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Especification_usage_constraint"));
	 constraint.ListClassname()=_T("Especification_usage_constraint"); 
	 constraint.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("specification_id") ,(StepNodeType) 22, (DWORD) &(this->specification_id),  _T("Etext") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("specification_description") ,(StepNodeType) 22, (DWORD) &(this->specification_description),  _T("Etext") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("specification_class") ,(StepNodeType) 22, (DWORD) &(this->specification_class),  _T("Etext") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Especification*/
////////////////////////////////////////////////////////////////////////////////
Especification_usage_constraint::Especification_usage_constraint(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Especification_usage_constraint");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("element") ,(StepNodeType) 22, (DWORD) &(this->element),  _T("Etext") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("class_id") ,(StepNodeType) 22, (DWORD) &(this->class_id),  _T("Etext") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Especification_usage_constraint*/
////////////////////////////////////////////////////////////////////////////////
Espherical_cap::Espherical_cap(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Espherical_cap");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("internal_angle") ,(StepNodeType) 22, (DWORD) &(this->internal_angle),  _T("Enumeric_parameter") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Enumeric_parameter") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Espherical_cap*/
////////////////////////////////////////////////////////////////////////////////
Espherical_hole_bottom::Espherical_hole_bottom(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Espherical_hole_bottom");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eblind_bottom_condition")) ; 
	m_parents.push_back(_T("Ehole_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eblind_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_blind_bottom_condition.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Espherical_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Espherical_surface::Espherical_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Espherical_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eelementary_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eelementary_surface") ,(StepNodeType) 1, (DWORD) &(this->_elementary_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Espherical_surface*/
////////////////////////////////////////////////////////////////////////////////
Esquare_u_profile::Esquare_u_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esquare_u_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eopen_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_profile") ,(StepNodeType) 1, (DWORD) &(this->_open_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("width") ,(StepNodeType) 22, (DWORD) &(this->width),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("first_radius") ,(StepNodeType) 22, (DWORD) &(this->first_radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("first_angle") ,(StepNodeType) 22, (DWORD) &(this->first_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("second_radius") ,(StepNodeType) 22, (DWORD) &(this->second_radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("second_angle") ,(StepNodeType) 22, (DWORD) &(this->second_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esquare_u_profile*/
////////////////////////////////////////////////////////////////////////////////
Estep::Estep(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Estep");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("open_boundary") ,(StepNodeType) 22, (DWORD) &(this->open_boundary),  _T("Elinear_path") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("wall_boundary") ,(StepNodeType) 22, (DWORD) &(this->wall_boundary),  _T("Evee_profile") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_boss") ,(StepNodeType) 13, (DWORD) &(this->its_boss),  _T("EListT<EbossPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eboss"));
	 its_boss.ListClassname()=_T("Eboss"); 
	 its_boss.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Estep*/
////////////////////////////////////////////////////////////////////////////////
Esurface::Esurface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esurface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ebounded_surface")) ; 
	 Supertypes().push_back(_T("Eelementary_surface")) ; 
	 Supertypes().push_back(_T("Eswept_surface")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esurface*/
////////////////////////////////////////////////////////////////////////////////
Esurface_of_linear_extrusion::Esurface_of_linear_extrusion(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esurface_of_linear_extrusion");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eswept_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eswept_surface") ,(StepNodeType) 1, (DWORD) &(this->_swept_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("extrusion_axis") ,(StepNodeType) 22, (DWORD) &(this->extrusion_axis),  _T("Evector") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esurface_of_linear_extrusion*/
////////////////////////////////////////////////////////////////////////////////
Esurface_of_revolution::Esurface_of_revolution(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esurface_of_revolution");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eswept_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eswept_surface") ,(StepNodeType) 1, (DWORD) &(this->_swept_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("axis_position") ,(StepNodeType) 22, (DWORD) &(this->axis_position),  _T("Eaxis1_placement") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esurface_of_revolution*/
////////////////////////////////////////////////////////////////////////////////
Esurface_texture_parameter::Esurface_texture_parameter(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Esurface_texture_parameter");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_value") ,(StepNodeType) 22, (DWORD) &(this->its_value),  _T("Eparameter_value") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("parameter_name") ,(StepNodeType) 22, (DWORD) &(this->parameter_name),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("measuring_method") ,(StepNodeType) 22, (DWORD) &(this->measuring_method),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("parameter_index") ,(StepNodeType) 22, (DWORD) &(this->parameter_index),  _T("Eidentifier") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("applied_surfaces") ,(StepNodeType) 13, (DWORD) &(this->applied_surfaces),  _T("EListT<Emachined_surfacePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Emachined_surface"));
	 applied_surfaces.ListClassname()=_T("Emachined_surface"); 
	 applied_surfaces.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Esurface_texture_parameter*/
////////////////////////////////////////////////////////////////////////////////
Eswept_surface::Eswept_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eswept_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Esurface_of_linear_extrusion")) ; 
	 Supertypes().push_back(_T("Esurface_of_revolution")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Esurface") ,(StepNodeType) 1, (DWORD) &(this->_surface.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("swept_curve") ,(StepNodeType) 22, (DWORD) &(this->swept_curve),  _T("Ecurve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eswept_surface*/
////////////////////////////////////////////////////////////////////////////////
Et_slot_mill::Et_slot_mill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Et_slot_mill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_cutter") ,(StepNodeType) 1, (DWORD) &(this->_milling_cutter.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("cutting_thickness") ,(StepNodeType) 22, (DWORD) &(this->cutting_thickness),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Et_slot_mill*/
////////////////////////////////////////////////////////////////////////////////
Etap::Etap(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etap");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etapered_tap")) ; 
	 Supertypes().push_back(_T("Ecombined_drill_and_tap")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etap*/
////////////////////////////////////////////////////////////////////////////////
Etapered_drill::Etapered_drill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etapered_drill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwist_drill")) ; 
	m_parents.push_back(_T("Edrill")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwist_drill") ,(StepNodeType) 1, (DWORD) &(this->_twist_drill.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("taper_angle") ,(StepNodeType) 22, (DWORD) &(this->taper_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etapered_drill*/
////////////////////////////////////////////////////////////////////////////////
Etapered_endmill::Etapered_endmill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etapered_endmill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eendmill")) ; 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eendmill") ,(StepNodeType) 1, (DWORD) &(this->_endmill.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("taper_angle") ,(StepNodeType) 22, (DWORD) &(this->taper_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etapered_endmill*/
////////////////////////////////////////////////////////////////////////////////
Etapered_reamer::Etapered_reamer(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etapered_reamer");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ereamer")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ereamer") ,(StepNodeType) 1, (DWORD) &(this->_reamer.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("taper_angle") ,(StepNodeType) 22, (DWORD) &(this->taper_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etapered_reamer*/
////////////////////////////////////////////////////////////////////////////////
Etapered_tap::Etapered_tap(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etapered_tap");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etap")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etap") ,(StepNodeType) 1, (DWORD) &(this->_tap.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("taper_angle") ,(StepNodeType) 22, (DWORD) &(this->taper_angle),  _T("Eplane_angle_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etapered_tap*/
////////////////////////////////////////////////////////////////////////////////
Etapping::Etapping(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etapping");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_type_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_type_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("compensation_chuck") ,(StepNodeType) entity_, (DWORD) &(this->compensation_chuck),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etapping*/
////////////////////////////////////////////////////////////////////////////////
Etechnology::Etechnology(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etechnology");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emilling_technology")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("feedrate") ,(StepNodeType) 22, (DWORD) &(this->feedrate),  _T("Espeed_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("feedrate_reference") ,(StepNodeType) 22, (DWORD) &(this->feedrate_reference),  _T("Etool_reference_point") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etechnology*/
////////////////////////////////////////////////////////////////////////////////
Etee_profile::Etee_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etee_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eopen_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_profile") ,(StepNodeType) 1, (DWORD) &(this->_open_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("first_angle") ,(StepNodeType) 22, (DWORD) &(this->first_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("second_angle") ,(StepNodeType) 22, (DWORD) &(this->second_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("cross_bar_width") ,(StepNodeType) 22, (DWORD) &(this->cross_bar_width),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("cross_bar_depth") ,(StepNodeType) 22, (DWORD) &(this->cross_bar_depth),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("width") ,(StepNodeType) 22, (DWORD) &(this->width),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("first_offset") ,(StepNodeType) 22, (DWORD) &(this->first_offset),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("second_offset") ,(StepNodeType) 22, (DWORD) &(this->second_offset),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etee_profile*/
////////////////////////////////////////////////////////////////////////////////
Ethread::Ethread(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethread");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecatalogue_thread")) ; 
	 Supertypes().push_back(_T("Edefined_thread")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("partial_profile") ,(StepNodeType) 22, (DWORD) &(this->partial_profile),  _T("Epartial_area_definition") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("applied_shape") ,(StepNodeType) 13, (DWORD) &(this->applied_shape),  _T("EListT<Emachining_featurePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Emachining_feature"));
	 applied_shape.ListClassname()=_T("Emachining_feature"); 
	 applied_shape.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("inner_or_outer_thread") ,(StepNodeType) entity_, (DWORD) &(this->inner_or_outer_thread),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("qualifier") ,(StepNodeType) 22, (DWORD) &(this->qualifier),  _T("Edescriptive_parameter") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("fit_class") ,(StepNodeType) 22, (DWORD) &(this->fit_class),  _T("Edescriptive_parameter") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("form") ,(StepNodeType) 22, (DWORD) &(this->form),  _T("Edescriptive_parameter") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("major_diameter") ,(StepNodeType) 22, (DWORD) &(this->major_diameter),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("number_of_threads") ,(StepNodeType) 22, (DWORD) &(this->number_of_threads),  _T("Enumeric_parameter") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("thread_hand") ,(StepNodeType) 22, (DWORD) &(this->thread_hand),  _T("Edescriptive_parameter") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethread*/
////////////////////////////////////////////////////////////////////////////////
Ethread_drilling::Ethread_drilling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethread_drilling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrilling_type_operation") ,(StepNodeType) 1, (DWORD) &(this->_drilling_type_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("helical_movement_on_forward") ,(StepNodeType) entity_, (DWORD) &(this->helical_movement_on_forward),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethread_drilling*/
////////////////////////////////////////////////////////////////////////////////
Ethread_mill::Ethread_mill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethread_mill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_cutter") ,(StepNodeType) 1, (DWORD) &(this->_milling_cutter.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethread_mill*/
////////////////////////////////////////////////////////////////////////////////
Ethreading_tool::Ethreading_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethreading_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethreading_tool*/
////////////////////////////////////////////////////////////////////////////////
Ethree_axes::Ethree_axes(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethree_axes");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_direction")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_direction") ,(StepNodeType) 1, (DWORD) &(this->_tool_direction.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethree_axes*/
////////////////////////////////////////////////////////////////////////////////
Ethree_axes_tilted_tool::Ethree_axes_tilted_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethree_axes_tilted_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_direction_for_milling")) ; 
	m_parents.push_back(_T("Etool_direction")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_direction_for_milling") ,(StepNodeType) 1, (DWORD) &(this->_tool_direction_for_milling.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("tool_direction") ,(StepNodeType) 22, (DWORD) &(this->tool_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethree_axes_tilted_tool*/
////////////////////////////////////////////////////////////////////////////////
Ethrough_bottom_condition::Ethrough_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethrough_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ehole_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ehole_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_hole_bottom_condition.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethrough_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Ethrough_pocket_bottom_condition::Ethrough_pocket_bottom_condition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethrough_pocket_bottom_condition");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Epocket_bottom_condition")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Epocket_bottom_condition") ,(StepNodeType) 1, (DWORD) &(this->_pocket_bottom_condition.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethrough_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Ethrough_profile_floor::Ethrough_profile_floor(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ethrough_profile_floor");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ethrough_profile_floor*/
////////////////////////////////////////////////////////////////////////////////
Etoleranced_length_measure::Etoleranced_length_measure(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etoleranced_length_measure");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("theoretical_size") ,(StepNodeType) 22, (DWORD) &(this->theoretical_size),  _T("Epositive_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("implicit_tolerance") ,(StepNodeType) 22, (DWORD) &(this->implicit_tolerance),  _T("Etolerance_select") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etoleranced_length_measure*/
////////////////////////////////////////////////////////////////////////////////
Etolerances::Etolerances(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etolerances");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("chordal_tolerance") ,(StepNodeType) 22, (DWORD) &(this->chordal_tolerance),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("scallop_height") ,(StepNodeType) 22, (DWORD) &(this->scallop_height),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etolerances*/
////////////////////////////////////////////////////////////////////////////////
Etool_body::Etool_body(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etool_body");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emilling_tool_body")) ; 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etool_body*/
////////////////////////////////////////////////////////////////////////////////
Etool_direction::Etool_direction(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etool_direction");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etwo_axes")) ; 
	 Supertypes().push_back(_T("Ethree_axes")) ; 
	 Supertypes().push_back(_T("Etool_direction_for_milling")) ; 
	 m_bAbstract=false ; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etool_direction*/
////////////////////////////////////////////////////////////////////////////////
Etool_direction_for_milling::Etool_direction_for_milling(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etool_direction_for_milling");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_direction")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ethree_axes_tilted_tool")) ; 
	 Supertypes().push_back(_T("Efive_axes_var_tilt_yaw")) ; 
	 Supertypes().push_back(_T("Efive_axes_const_tilt_yaw")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_direction") ,(StepNodeType) 1, (DWORD) &(this->_tool_direction.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etool_direction_for_milling*/
////////////////////////////////////////////////////////////////////////////////
Etool_length_probing::Etool_length_probing(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etool_length_probing");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_probing")) ; 
	m_parents.push_back(_T("Etouch_probing")) ; 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_probing") ,(StepNodeType) 1, (DWORD) &(this->_tool_probing.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etool_length_probing*/
////////////////////////////////////////////////////////////////////////////////
Etool_probing::Etool_probing(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etool_probing");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etouch_probing")) ; 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etool_length_probing")) ; 
	 Supertypes().push_back(_T("Etool_radius_probing")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etouch_probing") ,(StepNodeType) 1, (DWORD) &(this->_touch_probing.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("offset") ,(StepNodeType) 22, (DWORD) &(this->offset),  _T("Ecartesian_point") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("max_wear") ,(StepNodeType) 22, (DWORD) &(this->max_wear),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_tool") ,(StepNodeType) 22, (DWORD) &(this->its_tool),  _T("Emachining_tool") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etool_probing*/
////////////////////////////////////////////////////////////////////////////////
Etool_radius_probing::Etool_radius_probing(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etool_radius_probing");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_probing")) ; 
	m_parents.push_back(_T("Etouch_probing")) ; 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_probing") ,(StepNodeType) 1, (DWORD) &(this->_tool_probing.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etool_radius_probing*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath::Etoolpath(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etoolpath");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Efeedstop")) ; 
	 Supertypes().push_back(_T("Etrajectory")) ; 
	 Supertypes().push_back(_T("Eparameterised_path")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_priority") ,(StepNodeType) entity_, (DWORD) &(this->its_priority),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("its_type") ,(StepNodeType) 22, (DWORD) &(this->its_type),  _T("Etoolpath_type") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_speed") ,(StepNodeType) 22, (DWORD) &(this->its_speed),  _T("Etoolpath_speedprofile") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_technology") ,(StepNodeType) 22, (DWORD) &(this->its_technology),  _T("Etechnology") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_machine_functions") ,(StepNodeType) 22, (DWORD) &(this->its_machine_functions),  _T("Emachine_functions") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etoolpath*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath_feature::Etoolpath_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etoolpath_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emachining_feature")) ; 
	m_parents.push_back(_T("Etwo5d_manufacturing_feature")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emachining_feature") ,(StepNodeType) 1, (DWORD) &(this->_machining_feature.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etoolpath_feature*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath_list::Etoolpath_list(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etoolpath_list");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_list") ,(StepNodeType) 13, (DWORD) &(this->its_list),  _T("EListT<EtoolpathPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Etoolpath"));
	 its_list.ListClassname()=_T("Etoolpath"); 
	 its_list.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etoolpath_list*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath_speed::Etoolpath_speed(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etoolpath_speed");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("speed") ,(StepNodeType) 22, (DWORD) &(this->speed),  _T("Eb_spline_curve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etoolpath_speed*/
////////////////////////////////////////////////////////////////////////////////
Etopological_region::Etopological_region(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etopological_region");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eregion")) ; 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	m_parents.push_back(_T("Eopen_shell")) ; 
	m_parents.push_back(_T("Econnected_face_set")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eregion") ,(StepNodeType) 1, (DWORD) &(this->_region.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_shell") ,(StepNodeType) 1, (DWORD) &(this->_open_shell.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etopological_region*/
////////////////////////////////////////////////////////////////////////////////
Etopological_representation_item::Etopological_representation_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etopological_representation_item");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Econnected_face_set")) ; 
	 Supertypes().push_back(_T("Eedge")) ; 
	 Supertypes().push_back(_T("Eface")) ; 
	 Supertypes().push_back(_T("Eface_bound")) ; 
	 Supertypes().push_back(_T("Eloop")) ; 
	 Supertypes().push_back(_T("Epath")) ; 
	 Supertypes().push_back(_T("Evertex")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Erepresentation_item") ,(StepNodeType) 1, (DWORD) &(this->_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etopological_representation_item*/
////////////////////////////////////////////////////////////////////////////////
Etouch_probe::Etouch_probe(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etouch_probe");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etouch_probe*/
////////////////////////////////////////////////////////////////////////////////
Etouch_probing::Etouch_probing(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etouch_probing");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eworkpiece_probing")) ; 
	 Supertypes().push_back(_T("Eworkpiece_complete_probing")) ; 
	 Supertypes().push_back(_T("Etool_probing")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eworkingstep") ,(StepNodeType) 1, (DWORD) &(this->_workingstep.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Eoperation") ,(StepNodeType) 1, (DWORD) &(this->_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("measured_offset") ,(StepNodeType) 22, (DWORD) &(this->measured_offset),  _T("Enc_variable") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etouch_probing*/
////////////////////////////////////////////////////////////////////////////////
Etrajectory::Etrajectory(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etrajectory");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etoolpath")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Ecutter_location_trajectory")) ; 
	 Supertypes().push_back(_T("Ecutter_contact_trajectory")) ; 
	 Supertypes().push_back(_T("Eaxis_trajectory")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etoolpath") ,(StepNodeType) 1, (DWORD) &(this->_toolpath.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_direction") ,(StepNodeType) entity_, (DWORD) &(this->its_direction),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etrajectory*/
////////////////////////////////////////////////////////////////////////////////
Etransition_feature::Etransition_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etransition_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Echamfer")) ; 
	 Supertypes().push_back(_T("Eedge_round")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emanufacturing_feature") ,(StepNodeType) 1, (DWORD) &(this->_manufacturing_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("first_feature") ,(StepNodeType) 22, (DWORD) &(this->first_feature),  _T("Emachining_feature") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("second_feature") ,(StepNodeType) 22, (DWORD) &(this->second_feature),  _T("Emachining_feature") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etransition_feature*/
////////////////////////////////////////////////////////////////////////////////
Etravel_path::Etravel_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etravel_path");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Egeneral_path")) ; 
	 Supertypes().push_back(_T("Elinear_path")) ; 
	 Supertypes().push_back(_T("Ecircular_path")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("placement") ,(StepNodeType) 22, (DWORD) &(this->placement),  _T("Eaxis2_placement_3d") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etravel_path*/
////////////////////////////////////////////////////////////////////////////////
Etrimmed_curve::Etrimmed_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etrimmed_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebounded_curve") ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("basis_curve") ,(StepNodeType) 22, (DWORD) &(this->basis_curve),  _T("Ecurve") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("trim_1") ,(StepNodeType) 13, (DWORD) &(this->trim_1),  _T("EListT<Etrimming_selectPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Etrimming_select"));
	 trim_1.ListClassname()=_T("Etrimming_select"); 
	 trim_1.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("trim_2") ,(StepNodeType) 13, (DWORD) &(this->trim_2),  _T("EListT<Etrimming_selectPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Etrimming_select"));
	 trim_2.ListClassname()=_T("Etrimming_select"); 
	 trim_2.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("sense_agreement") ,(StepNodeType) entity_, (DWORD) &(this->sense_agreement),_T("EBoolean")));
	 m_vars.push_back(new CVarDef(this,  _T("master_representation") ,(StepNodeType) 22, (DWORD) &(this->master_representation),  _T("Etrimming_preference") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etrimmed_curve*/
////////////////////////////////////////////////////////////////////////////////
Etwist_drill::Etwist_drill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etwist_drill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edrill")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Etapered_drill")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edrill") ,(StepNodeType) 1, (DWORD) &(this->_drill.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etwist_drill*/
////////////////////////////////////////////////////////////////////////////////
Etwo5d_manufacturing_feature::Etwo5d_manufacturing_feature(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etwo5d_manufacturing_feature");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emanufacturing_feature")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emachining_feature")) ; 
	 Supertypes().push_back(_T("Ecompound_feature")) ; 
	 Supertypes().push_back(_T("Ereplicate_feature")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emanufacturing_feature") ,(StepNodeType) 1, (DWORD) &(this->_manufacturing_feature.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feature_placement") ,(StepNodeType) 22, (DWORD) &(this->feature_placement),  _T("Eaxis2_placement_3d") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etwo5d_manufacturing_feature*/
////////////////////////////////////////////////////////////////////////////////
Etwo5d_milling_operation::Etwo5d_milling_operation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etwo5d_milling_operation");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_type_operation")) ; 
	m_parents.push_back(_T("Emilling_machining_operation")) ; 
	m_parents.push_back(_T("Emachining_operation")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eplane_milling")) ; 
	 Supertypes().push_back(_T("Eside_milling")) ; 
	 Supertypes().push_back(_T("Ebottom_and_side_milling")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_type_operation") ,(StepNodeType) 1, (DWORD) &(this->_milling_type_operation.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_machining_strategy") ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy),  _T("Etwo5d_milling_strategy") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etwo5d_milling_operation*/
////////////////////////////////////////////////////////////////////////////////
Etwo5d_milling_strategy::Etwo5d_milling_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etwo5d_milling_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Eunidirectional")) ; 
	 Supertypes().push_back(_T("Ebidirectional")) ; 
	 Supertypes().push_back(_T("Econtour_parallel")) ; 
	 Supertypes().push_back(_T("Ebidirectional_contour")) ; 
	 Supertypes().push_back(_T("Econtour_bidirectional")) ; 
	 Supertypes().push_back(_T("Econtour_spiral")) ; 
	 Supertypes().push_back(_T("Ecenter_milling")) ; 
	 Supertypes().push_back(_T("Eexplicit")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("overlap") ,(StepNodeType) 22, (DWORD) &(this->overlap),  _T("Epositive_ratio_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("allow_multiple_passes") ,(StepNodeType) entity_, (DWORD) &(this->allow_multiple_passes),_T("EBoolean")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etwo5d_milling_strategy*/
////////////////////////////////////////////////////////////////////////////////
Etwo_axes::Etwo_axes(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Etwo_axes");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etool_direction")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etool_direction") ,(StepNodeType) 1, (DWORD) &(this->_tool_direction.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Etwo_axes*/
////////////////////////////////////////////////////////////////////////////////
Eunary_boolean_expression::Eunary_boolean_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eunary_boolean_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Enot_expression")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eboolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_boolean_expression.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("operand") ,(StepNodeType) 22, (DWORD) &(this->operand),  _T("Eboolean_expression") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eunary_boolean_expression*/
////////////////////////////////////////////////////////////////////////////////
Eunidirectional::Eunidirectional(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eunidirectional");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etwo5d_milling_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etwo5d_milling_strategy") ,(StepNodeType) 1, (DWORD) &(this->_two5d_milling_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("feed_direction") ,(StepNodeType) 22, (DWORD) &(this->feed_direction),  _T("Edirection") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("cutmode") ,(StepNodeType) 22, (DWORD) &(this->cutmode),  _T("Ecutmode_type") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eunidirectional*/
////////////////////////////////////////////////////////////////////////////////
Euniform_curve::Euniform_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Euniform_curve");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_curve")) ; 
	m_parents.push_back(_T("Ebounded_curve")) ; 
	m_parents.push_back(_T("Ecurve")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_curve") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Euniform_curve*/
////////////////////////////////////////////////////////////////////////////////
Euniform_surface::Euniform_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Euniform_surface");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eb_spline_surface")) ; 
	m_parents.push_back(_T("Ebounded_surface")) ; 
	m_parents.push_back(_T("Esurface")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eb_spline_surface") ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Euniform_surface*/
////////////////////////////////////////////////////////////////////////////////
Eunload_tool::Eunload_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eunload_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_tool") ,(StepNodeType) 22, (DWORD) &(this->its_tool),  _T("Emachining_tool") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eunload_tool*/
////////////////////////////////////////////////////////////////////////////////
Euser_defined_tool::Euser_defined_tool(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Euser_defined_tool");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_tool_body") ,(StepNodeType) 1, (DWORD) &(this->_milling_tool_body.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("identifier") ,(StepNodeType) 22, (DWORD) &(this->identifier),  _T("Elabel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Euser_defined_tool*/
////////////////////////////////////////////////////////////////////////////////
Euv_strategy::Euv_strategy(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Euv_strategy");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Efreeform_strategy")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Efreeform_strategy") ,(StepNodeType) 1, (DWORD) &(this->_freeform_strategy.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("forward_direction") ,(StepNodeType) 22, (DWORD) &(this->forward_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("sideward_direction") ,(StepNodeType) 22, (DWORD) &(this->sideward_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Euv_strategy*/
////////////////////////////////////////////////////////////////////////////////
Evector::Evector(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Evector");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("orientation") ,(StepNodeType) 22, (DWORD) &(this->orientation),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("magnitude") ,(StepNodeType) 22, (DWORD) &(this->magnitude),  _T("Elength_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Evector*/
////////////////////////////////////////////////////////////////////////////////
Evee_profile::Evee_profile(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Evee_profile");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eopen_profile")) ; 
	m_parents.push_back(_T("Eprofile")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eopen_profile") ,(StepNodeType) 1, (DWORD) &(this->_open_profile.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("profile_radius") ,(StepNodeType) 22, (DWORD) &(this->profile_radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("profile_angle") ,(StepNodeType) 22, (DWORD) &(this->profile_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("tilt_angle") ,(StepNodeType) 22, (DWORD) &(this->tilt_angle),  _T("Eplane_angle_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Evee_profile*/
////////////////////////////////////////////////////////////////////////////////
Evertex::Evertex(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Evertex");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Evertex_point")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etopological_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Evertex*/
////////////////////////////////////////////////////////////////////////////////
Evertex_loop::Evertex_loop(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Evertex_loop");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eloop")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eloop") ,(StepNodeType) 1, (DWORD) &(this->_loop.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("loop_vertex") ,(StepNodeType) 22, (DWORD) &(this->loop_vertex),  _T("Evertex") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Evertex_loop*/
////////////////////////////////////////////////////////////////////////////////
Evertex_point::Evertex_point(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Evertex_point");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Evertex")) ; 
	m_parents.push_back(_T("Etopological_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	m_parents.push_back(_T("Egeometric_representation_item")) ; 
	m_parents.push_back(_T("Erepresentation_item")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Evertex") ,(StepNodeType) 1, (DWORD) &(this->_vertex.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("Egeometric_representation_item") ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("vertex_geometry") ,(StepNodeType) 22, (DWORD) &(this->vertex_geometry),  _T("Epoint") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Evertex_point*/
////////////////////////////////////////////////////////////////////////////////
Ewait_for_mark::Ewait_for_mark(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ewait_for_mark");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Enc_function")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Enc_function") ,(StepNodeType) 1, (DWORD) &(this->_nc_function.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_channel") ,(StepNodeType) 22, (DWORD) &(this->its_channel),  _T("Echannel") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ewait_for_mark*/
////////////////////////////////////////////////////////////////////////////////
Eweek_of_year_and_day_date::Eweek_of_year_and_day_date(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eweek_of_year_and_day_date");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Edate")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Edate") ,(StepNodeType) 1, (DWORD) &(this->_date.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("week_component") ,(StepNodeType) 22, (DWORD) &(this->week_component),  _T("Eweek_in_year_number") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("day_component") ,(StepNodeType) 22, (DWORD) &(this->day_component),  _T("Eday_in_week_number") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eweek_of_year_and_day_date*/
////////////////////////////////////////////////////////////////////////////////
Ewhile_statement::Ewhile_statement(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ewhile_statement");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprogram_structure")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprogram_structure") ,(StepNodeType) 1, (DWORD) &(this->_program_structure.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("condition") ,(StepNodeType) 22, (DWORD) &(this->condition),  _T("Eboolean_expression") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("body") ,(StepNodeType) 22, (DWORD) &(this->body),  _T("Eexecutable") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ewhile_statement*/
////////////////////////////////////////////////////////////////////////////////
Ewoodruff_keyseat_mill::Ewoodruff_keyseat_mill(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ewoodruff_keyseat_mill");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Emilling_cutter")) ; 
	m_parents.push_back(_T("Emilling_tool_body")) ; 
	m_parents.push_back(_T("Etool_body")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Emilling_cutter") ,(StepNodeType) 1, (DWORD) &(this->_milling_cutter.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("cutter_width") ,(StepNodeType) 22, (DWORD) &(this->cutter_width),  _T("Elength_measure") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ewoodruff_keyseat_mill*/
////////////////////////////////////////////////////////////////////////////////
Ewoodruff_slot_end_type::Ewoodruff_slot_end_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Ewoodruff_slot_end_type");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eslot_end_type")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eslot_end_type") ,(StepNodeType) 1, (DWORD) &(this->_slot_end_type.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("radius") ,(StepNodeType) 22, (DWORD) &(this->radius),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Ewoodruff_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Eworkingstep::Eworkingstep(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eworkingstep");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 Supertypes().push_back(_T("Emachining_workingstep")) ; 
	 Supertypes().push_back(_T("Erapid_movement")) ; 
	 Supertypes().push_back(_T("Etouch_probing")) ; 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eexecutable") ,(StepNodeType) 1, (DWORD) &(this->_executable.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_secplane") ,(StepNodeType) 22, (DWORD) &(this->its_secplane),  _T("Eelementary_surface") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eworkingstep*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece::Eworkpiece(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eworkpiece");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_id") ,(StepNodeType) 22, (DWORD) &(this->its_id),  _T("Eidentifier") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_material") ,(StepNodeType) 22, (DWORD) &(this->its_material),  _T("Ematerial") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("global_tolerance") ,(StepNodeType) 22, (DWORD) &(this->global_tolerance),  _T("Eshape_tolerance") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_rawpiece") ,(StepNodeType) 22, (DWORD) &(this->its_rawpiece),  _T("Eworkpiece") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_geometry") ,(StepNodeType) 22, (DWORD) &(this->its_geometry),  _T("Eadvanced_brep_shape_representation") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_bounding_geometry") ,(StepNodeType) 22, (DWORD) &(this->its_bounding_geometry),  _T("Ebounding_geometry_select") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("clamping_positions") ,(StepNodeType) 13, (DWORD) &(this->clamping_positions),  _T("EListT<Ecartesian_pointPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Ecartesian_point"));
	 clamping_positions.ListClassname()=_T("Ecartesian_point"); 
	 clamping_positions.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eworkpiece*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece_complete_probing::Eworkpiece_complete_probing(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eworkpiece_complete_probing");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etouch_probing")) ; 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etouch_probing") ,(StepNodeType) 1, (DWORD) &(this->_touch_probing.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_workpiece") ,(StepNodeType) 22, (DWORD) &(this->its_workpiece),  _T("Eworkpiece") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("probing_distance") ,(StepNodeType) 22, (DWORD) &(this->probing_distance),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_probe") ,(StepNodeType) 22, (DWORD) &(this->its_probe),  _T("Etouch_probe") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("computed_offset") ,(StepNodeType) 22, (DWORD) &(this->computed_offset),  _T("Eoffset_vector") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eworkpiece_complete_probing*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece_probing::Eworkpiece_probing(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eworkpiece_probing");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Etouch_probing")) ; 
	m_parents.push_back(_T("Eworkingstep")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	m_parents.push_back(_T("Eoperation")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Etouch_probing") ,(StepNodeType) 1, (DWORD) &(this->_touch_probing.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("start_position") ,(StepNodeType) 22, (DWORD) &(this->start_position),  _T("Eaxis2_placement_3d") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_workpiece") ,(StepNodeType) 22, (DWORD) &(this->its_workpiece),  _T("Eworkpiece") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_direction") ,(StepNodeType) 22, (DWORD) &(this->its_direction),  _T("Edirection") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("expected_value") ,(StepNodeType) 22, (DWORD) &(this->expected_value),  _T("Etoleranced_length_measure") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_probe") ,(StepNodeType) 22, (DWORD) &(this->its_probe),  _T("Etouch_probe") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eworkpiece_probing*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece_setup::Eworkpiece_setup(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eworkpiece_setup");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("its_workpiece") ,(StepNodeType) 22, (DWORD) &(this->its_workpiece),  _T("Eworkpiece") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_origin") ,(StepNodeType) 22, (DWORD) &(this->its_origin),  _T("Eaxis2_placement_3d") , 0));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_offset") ,(StepNodeType) 22, (DWORD) &(this->its_offset),  _T("Eoffset_vector") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_restricted_area") ,(StepNodeType) 22, (DWORD) &(this->its_restricted_area),  _T("Erestricted_area_select") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_instructions") ,(StepNodeType) 13, (DWORD) &(this->its_instructions),  _T("EListT<Esetup_instructionPtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Esetup_instruction"));
	 its_instructions.ListClassname()=_T("Esetup_instruction"); 
	 its_instructions.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eworkpiece_setup*/
////////////////////////////////////////////////////////////////////////////////
Eworkplan::Eworkplan(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Eworkplan");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Eprogram_structure")) ; 
	m_parents.push_back(_T("Eexecutable")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Eprogram_structure") ,(StepNodeType) 1, (DWORD) &(this->_program_structure.m_vars),_T("Baseclass")));
	 m_vars.push_back(new CVarDef(this,  _T("its_elements") ,(StepNodeType) 13, (DWORD) &(this->its_elements),  _T("EListT<EexecutablePtr>") , 0));
	 m_vars.back()->Init(1, (StepNodeType)  22,  _T("Eexecutable"));
	 its_elements.ListClassname()=_T("Eexecutable"); 
	 its_elements.ListType()=(StepNodeType)  22; 
	 m_vars.push_back(new CVarDef(this,  _T("its_channel") ,(StepNodeType) 22, (DWORD) &(this->its_channel),  _T("Echannel") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_setup") ,(StepNodeType) 22, (DWORD) &(this->its_setup),  _T("Esetup") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 m_vars.push_back(new CVarDef(this,  _T("its_effect") ,(StepNodeType) 22, (DWORD) &(this->its_effect),  _T("Ein_process_geometry") , 1));
	 m_vars.back()->Init(0, (StepNodeType)  0,  _T(""));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Eworkplan*/
////////////////////////////////////////////////////////////////////////////////
Exor_expression::Exor_expression(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()=_T("Exor_expression");
	 m_def.m_pVars=&m_vars;
	 Parents().clear(); 
	m_parents.push_back(_T("Ebinary_boolean_expression")) ; 
	m_parents.push_back(_T("Eboolean_expression")) ; 
	 Supertypes().clear(); 
	 m_bAbstract=false ; 
	 m_vars.push_back(new CVarDef(this,  _T("Ebinary_boolean_expression") ,(StepNodeType) 1, (DWORD) &(this->_binary_boolean_expression.m_vars),_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Exor_expression*/
Eday_in_month_number::Eday_in_month_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eday_in_month_number");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Emonth_in_year_number::Emonth_in_year_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Emonth_in_year_number");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eday_in_year_number::Eday_in_year_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eday_in_year_number");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eweek_in_year_number::Eweek_in_year_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eweek_in_year_number");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eday_in_week_number::Eday_in_week_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eday_in_week_number");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ehour_in_day::Ehour_in_day()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ehour_in_day");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eminute_in_hour::Eminute_in_hour()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eminute_in_hour");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Esecond_in_minute::Esecond_in_minute()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Esecond_in_minute");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eahead_or_behind::Eahead_or_behind()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eahead_or_behind");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 3; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eyear_number::Eyear_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eyear_number");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eidentifier::Eidentifier()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eidentifier");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= string_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EString") ,(StepNodeType) 1, (DWORD) &(this->EString::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EString")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Elabel::Elabel()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Elabel");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= string_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EString") ,(StepNodeType) 1, (DWORD) &(this->EString::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EString")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etext::Etext()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etext");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= string_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EString") ,(StepNodeType) 1, (DWORD) &(this->EString::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EString")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Elength_measure::Elength_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Elength_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eparameter_value::Eparameter_value()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eparameter_value");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eplane_angle_measure::Eplane_angle_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eplane_angle_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Epositive_length_measure::Epositive_length_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Epositive_length_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= typereference_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("Elength_measure") ,(StepNodeType) 1, (DWORD) &(this->Elength_measure::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("Elength_measure")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Epositive_ratio_measure::Epositive_ratio_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Epositive_ratio_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= typereference_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("Eratio_measure") ,(StepNodeType) 1, (DWORD) &(this->Eratio_measure::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("Eratio_measure")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eratio_measure::Eratio_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eratio_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etime_measure::Etime_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etime_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etrimming_select::Etrimming_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etrimming_select");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Ecartesian_point") ,(StepNodeType) 18, (DWORD) &(this->_Ecartesian_point),_T("_Ecartesian_point")));

	 SetSelection(_Ecartesian_point); 
	 m_vars.push_back(new CVarDef(this,  _T("_Eparameter_value") ,(StepNodeType) 4, (DWORD) &(this->_Eparameter_value),_T("_Eparameter_value")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etrimming_preference::Etrimming_preference()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etrimming_preference");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 3; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etransition_code::Etransition_code()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etransition_code");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 4; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eb_spline_curve_form::Eb_spline_curve_form()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eb_spline_curve_form");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 6; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eb_spline_surface_form::Eb_spline_surface_form()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eb_spline_surface_form");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 11; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Edimension_count::Edimension_count()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Edimension_count");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EInteger") ,(StepNodeType) 1, (DWORD) &(this->EInteger::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EInteger")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eknot_type::Eknot_type()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eknot_type");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 4; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Epcurve_or_surface::Epcurve_or_surface()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Epcurve_or_surface");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Epcurve") ,(StepNodeType) 18, (DWORD) &(this->_Epcurve),_T("_Epcurve")));

	 SetSelection(_Epcurve); 
	 m_vars.push_back(new CVarDef(this,  _T("_Esurface") ,(StepNodeType) 18, (DWORD) &(this->_Esurface),_T("_Esurface")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Evector_or_direction::Evector_or_direction()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Evector_or_direction");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Evector") ,(StepNodeType) 18, (DWORD) &(this->_Evector),_T("_Evector")));

	 SetSelection(_Evector); 
	 m_vars.push_back(new CVarDef(this,  _T("_Edirection") ,(StepNodeType) 18, (DWORD) &(this->_Edirection),_T("_Edirection")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etolerance_select::Etolerance_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etolerance_select");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Eplus_minus_value") ,(StepNodeType) 18, (DWORD) &(this->_Eplus_minus_value),_T("_Eplus_minus_value")));

	 SetSelection(_Eplus_minus_value); 
	 m_vars.push_back(new CVarDef(this,  _T("_Elimits_and_fits") ,(StepNodeType) 18, (DWORD) &(this->_Elimits_and_fits),_T("_Elimits_and_fits")));
	 Parents().push_back(_T("Elimits_and_fits"));
	 Parents().push_back(_T("Eplus_minus_value"));

	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Efitting_type::Efitting_type()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Efitting_type");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 2; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Espeed_measure::Espeed_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Espeed_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Erot_speed_measure::Erot_speed_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Erot_speed_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Epressure_measure::Epressure_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Epressure_measure");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("EReal") ,(StepNodeType) 1, (DWORD) &(this->EReal::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("EReal")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Erot_direction::Erot_direction()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Erot_direction");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 2; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eshape_tolerance::Eshape_tolerance()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eshape_tolerance");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= typereference_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 m_vars.push_back(new CVarDef(this,  _T("Elength_measure") ,(StepNodeType) 1, (DWORD) &(this->Elength_measure::m_vars),_T("Baseclass")));
	 Parents().push_back(_T("Elength_measure")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ebounding_geometry_select::Ebounding_geometry_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ebounding_geometry_select");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Eblock") ,(StepNodeType) 18, (DWORD) &(this->_Eblock),_T("_Eblock")));

	 SetSelection(_Eblock); 
	 m_vars.push_back(new CVarDef(this,  _T("_Eright_circular_cylinder") ,(StepNodeType) 18, (DWORD) &(this->_Eright_circular_cylinder),_T("_Eright_circular_cylinder")));
	 m_vars.push_back(new CVarDef(this,  _T("_Eadvanced_brep_shape_representation") ,(StepNodeType) 18, (DWORD) &(this->_Eadvanced_brep_shape_representation),_T("_Eadvanced_brep_shape_representation")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eprofile_select::Eprofile_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eprofile_select");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Ethrough_profile_floor") ,(StepNodeType) 18, (DWORD) &(this->_Ethrough_profile_floor),_T("_Ethrough_profile_floor")));

	 SetSelection(_Ethrough_profile_floor); 
	 m_vars.push_back(new CVarDef(this,  _T("_Eprofile_floor") ,(StepNodeType) 18, (DWORD) &(this->_Eprofile_floor),_T("_Eprofile_floor")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etaper_select::Etaper_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etaper_select");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Ediameter_taper") ,(StepNodeType) 18, (DWORD) &(this->_Ediameter_taper),_T("_Ediameter_taper")));

	 SetSelection(_Ediameter_taper); 
	 m_vars.push_back(new CVarDef(this,  _T("_Eangle_taper") ,(StepNodeType) 18, (DWORD) &(this->_Eangle_taper),_T("_Eangle_taper")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ecompound_feature_select::Ecompound_feature_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ecompound_feature_select");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Emachining_feature") ,(StepNodeType) 18, (DWORD) &(this->_Emachining_feature),_T("_Emachining_feature")));

	 SetSelection(_Emachining_feature); 
	 m_vars.push_back(new CVarDef(this,  _T("_Etransition_feature") ,(StepNodeType) 18, (DWORD) &(this->_Etransition_feature),_T("_Etransition_feature")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ebottom_or_side::Ebottom_or_side()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ebottom_or_side");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 3; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Erestricted_area_select::Erestricted_area_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Erestricted_area_select");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Ebounded_surface") ,(StepNodeType) 18, (DWORD) &(this->_Ebounded_surface),_T("_Ebounded_surface")));

	 SetSelection(_Ebounded_surface); 
	 m_vars.push_back(new CVarDef(this,  _T("_Ebounding_geometry_select") ,(StepNodeType) 21, (DWORD) &(this->_Ebounding_geometry_select),_T("_Ebounding_geometry_select")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ervalue::Ervalue()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ervalue");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Enc_constant") ,(StepNodeType) 18, (DWORD) &(this->_Enc_constant),_T("_Enc_constant")));

	 SetSelection(_Enc_constant); 
	 m_vars.push_back(new CVarDef(this,  _T("_Enc_variable") ,(StepNodeType) 18, (DWORD) &(this->_Enc_variable),_T("_Enc_variable")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etool_reference_point::Etool_reference_point()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etool_reference_point");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 2; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etoolpath_type::Etoolpath_type()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etoolpath_type");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 6; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Etoolpath_speedprofile::Etoolpath_speedprofile()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Etoolpath_speedprofile");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Etoolpath_speed") ,(StepNodeType) 18, (DWORD) &(this->_Etoolpath_speed),_T("_Etoolpath_speed")));

	 SetSelection(_Etoolpath_speed); 
	 m_vars.push_back(new CVarDef(this,  _T("_Epositive_ratio_measure") ,(StepNodeType) 33, (DWORD) &(this->_Epositive_ratio_measure),_T("_Epositive_ratio_measure")));
	 m_vars.push_back(new CVarDef(this,  _T("_Espeed_name") ,(StepNodeType) 20, (DWORD) &(this->_Espeed_name),_T("_Espeed_name")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Espeed_name::Espeed_name()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Espeed_name");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 1; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ecurve_with_surface_normal::Ecurve_with_surface_normal()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ecurve_with_surface_normal");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 m_vars.push_back(new CVarDef(this,  _T("_Ebounded_pcurve") ,(StepNodeType) 18, (DWORD) &(this->_Ebounded_pcurve),_T("_Ebounded_pcurve")));

	 SetSelection(_Ebounded_pcurve); 
	 m_vars.push_back(new CVarDef(this,  _T("_Ecurve_with_normal_vector") ,(StepNodeType) 18, (DWORD) &(this->_Ecurve_with_normal_vector),_T("_Ecurve_with_normal_vector")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Econtact_type::Econtact_type()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Econtact_type");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 2; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ehand::Ehand()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ehand");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 3; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Epathmode_type::Epathmode_type()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Epathmode_type");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 2; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Ecutmode_type::Ecutmode_type()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Ecutmode_type");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 2; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eleft_or_right::Eleft_or_right()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Eleft_or_right");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 2; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Estroke_connection_strategy::Estroke_connection_strategy()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&m_vars;
	 Classname()=_T("Estroke_connection_strategy");
	 Parents().clear(); 
	 Supertypes().clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->m_nSelection= 4; 
	 Parents().push_back(_T("Eenum")); 
	 Supertypes().push_back(_T("Eenum")); 
	 m_vars.push_back(new CVarDef(this,  _T("EEnum") ,(StepNodeType) enumeration_, (DWORD) this,_T("Baseclass")));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
IStepNodePtr Createstepnc_schemaClass(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname==_T("Eadaptive_control")) return Eadaptive_control::Create(name);
	if(classname==_T("Eaddress")) return Eaddress::Create(name);
	if(classname==_T("Eadvanced_brep_shape_representation")) return Eadvanced_brep_shape_representation::Create(name);
	if(classname==_T("Eadvanced_face")) return Eadvanced_face::Create(name);
	if(classname==_T("Eair_strategy")) return Eair_strategy::Create(name);
	if(classname==_T("Ealong_path")) return Ealong_path::Create(name);
	if(classname==_T("Eand_expression")) return Eand_expression::Create(name);
	if(classname==_T("Eangle_taper")) return Eangle_taper::Create(name);
	if(classname==_T("Eap_lift_path_angle")) return Eap_lift_path_angle::Create(name);
	if(classname==_T("Eap_lift_path_tangent")) return Eap_lift_path_tangent::Create(name);
	if(classname==_T("Eap_retract_angle")) return Eap_retract_angle::Create(name);
	if(classname==_T("Eap_retract_tangent")) return Eap_retract_tangent::Create(name);
	if(classname==_T("Eapproach_lift_path")) return Eapproach_lift_path::Create(name);
	if(classname==_T("Eapproach_retract_strategy")) return Eapproach_retract_strategy::Create(name);
	if(classname==_T("Eapproval")) return Eapproval::Create(name);
	if(classname==_T("Eapproval_status")) return Eapproval_status::Create(name);
	if(classname==_T("Eassignment")) return Eassignment::Create(name);
	if(classname==_T("Eaxis1_placement")) return Eaxis1_placement::Create(name);
	if(classname==_T("Eaxis2_placement_3d")) return Eaxis2_placement_3d::Create(name);
	if(classname==_T("Eaxis_trajectory")) return Eaxis_trajectory::Create(name);
	if(classname==_T("Eb_spline_curve")) return Eb_spline_curve::Create(name);
	if(classname==_T("Eb_spline_curve_with_knots")) return Eb_spline_curve_with_knots::Create(name);
	if(classname==_T("Eb_spline_surface")) return Eb_spline_surface::Create(name);
	if(classname==_T("Eb_spline_surface_with_knots")) return Eb_spline_surface_with_knots::Create(name);
	if(classname==_T("Eback_boring")) return Eback_boring::Create(name);
	if(classname==_T("Ebackside_counterbore")) return Ebackside_counterbore::Create(name);
	if(classname==_T("Ebackside_countersink")) return Ebackside_countersink::Create(name);
	if(classname==_T("Eball_endmill")) return Eball_endmill::Create(name);
	if(classname==_T("Ebezier_curve")) return Ebezier_curve::Create(name);
	if(classname==_T("Ebezier_surface")) return Ebezier_surface::Create(name);
	if(classname==_T("Ebidirectional")) return Ebidirectional::Create(name);
	if(classname==_T("Ebidirectional_contour")) return Ebidirectional_contour::Create(name);
	if(classname==_T("Ebinary_boolean_expression")) return Ebinary_boolean_expression::Create(name);
	if(classname==_T("Eblind_bottom_condition")) return Eblind_bottom_condition::Create(name);
	if(classname==_T("Eblock")) return Eblock::Create(name);
	if(classname==_T("Eboolean_expression")) return Eboolean_expression::Create(name);
	if(classname==_T("Eboring")) return Eboring::Create(name);
	if(classname==_T("Eboring_operation")) return Eboring_operation::Create(name);
	if(classname==_T("Eboring_tool")) return Eboring_tool::Create(name);
	if(classname==_T("Eboss")) return Eboss::Create(name);
	if(classname==_T("Ebottom_and_side_finish_milling")) return Ebottom_and_side_finish_milling::Create(name);
	if(classname==_T("Ebottom_and_side_milling")) return Ebottom_and_side_milling::Create(name);
	if(classname==_T("Ebottom_and_side_rough_milling")) return Ebottom_and_side_rough_milling::Create(name);
	if(classname==_T("Ebounded_curve")) return Ebounded_curve::Create(name);
	if(classname==_T("Ebounded_pcurve")) return Ebounded_pcurve::Create(name);
	if(classname==_T("Ebounded_surface")) return Ebounded_surface::Create(name);
	if(classname==_T("Ebullnose_endmill")) return Ebullnose_endmill::Create(name);
	if(classname==_T("Ecalendar_date")) return Ecalendar_date::Create(name);
	if(classname==_T("Ecartesian_point")) return Ecartesian_point::Create(name);
	if(classname==_T("Ecatalogue_thread")) return Ecatalogue_thread::Create(name);
	if(classname==_T("Ecenter_drill")) return Ecenter_drill::Create(name);
	if(classname==_T("Ecenter_drilling")) return Ecenter_drilling::Create(name);
	if(classname==_T("Ecenter_milling")) return Ecenter_milling::Create(name);
	if(classname==_T("Echamfer")) return Echamfer::Create(name);
	if(classname==_T("Echannel")) return Echannel::Create(name);
	if(classname==_T("Ecircle")) return Ecircle::Create(name);
	if(classname==_T("Ecircular_closed_profile")) return Ecircular_closed_profile::Create(name);
	if(classname==_T("Ecircular_closed_shape_profile")) return Ecircular_closed_shape_profile::Create(name);
	if(classname==_T("Ecircular_offset")) return Ecircular_offset::Create(name);
	if(classname==_T("Ecircular_omit")) return Ecircular_omit::Create(name);
	if(classname==_T("Ecircular_path")) return Ecircular_path::Create(name);
	if(classname==_T("Ecircular_pattern")) return Ecircular_pattern::Create(name);
	if(classname==_T("Eclosed_pocket")) return Eclosed_pocket::Create(name);
	if(classname==_T("Eclosed_profile")) return Eclosed_profile::Create(name);
	if(classname==_T("Eclosed_shell")) return Eclosed_shell::Create(name);
	if(classname==_T("Ecombined_drill_and_reamer")) return Ecombined_drill_and_reamer::Create(name);
	if(classname==_T("Ecombined_drill_and_tap")) return Ecombined_drill_and_tap::Create(name);
	if(classname==_T("Ecomparison_equal")) return Ecomparison_equal::Create(name);
	if(classname==_T("Ecomparison_expression")) return Ecomparison_expression::Create(name);
	if(classname==_T("Ecomparison_greater")) return Ecomparison_greater::Create(name);
	if(classname==_T("Ecomparison_greater_equal")) return Ecomparison_greater_equal::Create(name);
	if(classname==_T("Ecomparison_less")) return Ecomparison_less::Create(name);
	if(classname==_T("Ecomparison_less_equal")) return Ecomparison_less_equal::Create(name);
	if(classname==_T("Ecomparison_not_equal")) return Ecomparison_not_equal::Create(name);
	if(classname==_T("Ecomplete_circular_path")) return Ecomplete_circular_path::Create(name);
	if(classname==_T("Ecomposite_curve")) return Ecomposite_curve::Create(name);
	if(classname==_T("Ecomposite_curve_segment")) return Ecomposite_curve_segment::Create(name);
	if(classname==_T("Ecompound_feature")) return Ecompound_feature::Create(name);
	if(classname==_T("Econic")) return Econic::Create(name);
	if(classname==_T("Econical_hole_bottom")) return Econical_hole_bottom::Create(name);
	if(classname==_T("Econnect_direct")) return Econnect_direct::Create(name);
	if(classname==_T("Econnect_secplane")) return Econnect_secplane::Create(name);
	if(classname==_T("Econnected_face_set")) return Econnected_face_set::Create(name);
	if(classname==_T("Econnector")) return Econnector::Create(name);
	if(classname==_T("Econtour_bidirectional")) return Econtour_bidirectional::Create(name);
	if(classname==_T("Econtour_parallel")) return Econtour_parallel::Create(name);
	if(classname==_T("Econtour_spiral")) return Econtour_spiral::Create(name);
	if(classname==_T("Ecoordinated_universal_time_offset")) return Ecoordinated_universal_time_offset::Create(name);
	if(classname==_T("Ecounter_sinking")) return Ecounter_sinking::Create(name);
	if(classname==_T("Ecounterbore")) return Ecounterbore::Create(name);
	if(classname==_T("Ecounterbore_hole")) return Ecounterbore_hole::Create(name);
	if(classname==_T("Ecountersink")) return Ecountersink::Create(name);
	if(classname==_T("Ecountersunk_hole")) return Ecountersunk_hole::Create(name);
	if(classname==_T("Ecurve")) return Ecurve::Create(name);
	if(classname==_T("Ecurve_with_normal_vector")) return Ecurve_with_normal_vector::Create(name);
	if(classname==_T("Ecutter_contact_trajectory")) return Ecutter_contact_trajectory::Create(name);
	if(classname==_T("Ecutter_location_trajectory")) return Ecutter_location_trajectory::Create(name);
	if(classname==_T("Ecutting_component")) return Ecutting_component::Create(name);
	if(classname==_T("Ecutting_edge_technological_data")) return Ecutting_edge_technological_data::Create(name);
	if(classname==_T("Ecutting_tool")) return Ecutting_tool::Create(name);
	if(classname==_T("Edate")) return Edate::Create(name);
	if(classname==_T("Edate_and_time")) return Edate_and_time::Create(name);
	if(classname==_T("Edefined_thread")) return Edefined_thread::Create(name);
	if(classname==_T("Edefinitional_representation")) return Edefinitional_representation::Create(name);
	if(classname==_T("Edescriptive_parameter")) return Edescriptive_parameter::Create(name);
	if(classname==_T("Ediameter_taper")) return Ediameter_taper::Create(name);
	if(classname==_T("Edirection")) return Edirection::Create(name);
	if(classname==_T("Edisplay_message")) return Edisplay_message::Create(name);
	if(classname==_T("Edovetail_mill")) return Edovetail_mill::Create(name);
	if(classname==_T("Edrill")) return Edrill::Create(name);
	if(classname==_T("Edrilling")) return Edrilling::Create(name);
	if(classname==_T("Edrilling_operation")) return Edrilling_operation::Create(name);
	if(classname==_T("Edrilling_type_operation")) return Edrilling_type_operation::Create(name);
	if(classname==_T("Edrilling_type_strategy")) return Edrilling_type_strategy::Create(name);
	if(classname==_T("Eedge")) return Eedge::Create(name);
	if(classname==_T("Eedge_curve")) return Eedge_curve::Create(name);
	if(classname==_T("Eedge_loop")) return Eedge_loop::Create(name);
	if(classname==_T("Eedge_round")) return Eedge_round::Create(name);
	if(classname==_T("Eelementary_surface")) return Eelementary_surface::Create(name);
	if(classname==_T("Eellipse")) return Eellipse::Create(name);
	if(classname==_T("Eendmill")) return Eendmill::Create(name);
	if(classname==_T("Eexchange_pallet")) return Eexchange_pallet::Create(name);
	if(classname==_T("Eexecutable")) return Eexecutable::Create(name);
	if(classname==_T("Eexplicit")) return Eexplicit::Create(name);
	if(classname==_T("Eface")) return Eface::Create(name);
	if(classname==_T("Eface_bound")) return Eface_bound::Create(name);
	if(classname==_T("Eface_outer_bound")) return Eface_outer_bound::Create(name);
	if(classname==_T("Eface_surface")) return Eface_surface::Create(name);
	if(classname==_T("Efacemill")) return Efacemill::Create(name);
	if(classname==_T("Efeedstop")) return Efeedstop::Create(name);
	if(classname==_T("Efive_axes_const_tilt_yaw")) return Efive_axes_const_tilt_yaw::Create(name);
	if(classname==_T("Efive_axes_var_tilt_yaw")) return Efive_axes_var_tilt_yaw::Create(name);
	if(classname==_T("Eflat_hole_bottom")) return Eflat_hole_bottom::Create(name);
	if(classname==_T("Eflat_slot_end_type")) return Eflat_slot_end_type::Create(name);
	if(classname==_T("Eflat_with_radius_hole_bottom")) return Eflat_with_radius_hole_bottom::Create(name);
	if(classname==_T("Efreeform_operation")) return Efreeform_operation::Create(name);
	if(classname==_T("Efreeform_strategy")) return Efreeform_strategy::Create(name);
	if(classname==_T("Egeneral_closed_profile")) return Egeneral_closed_profile::Create(name);
	if(classname==_T("Egeneral_outside_profile")) return Egeneral_outside_profile::Create(name);
	if(classname==_T("Egeneral_path")) return Egeneral_path::Create(name);
	if(classname==_T("Egeneral_pattern")) return Egeneral_pattern::Create(name);
	if(classname==_T("Egeneral_pocket_bottom_condition")) return Egeneral_pocket_bottom_condition::Create(name);
	if(classname==_T("Egeneral_profile")) return Egeneral_profile::Create(name);
	if(classname==_T("Egeneral_profile_floor")) return Egeneral_profile_floor::Create(name);
	if(classname==_T("Egeneral_shape_profile")) return Egeneral_shape_profile::Create(name);
	if(classname==_T("Egeometric_representation_context")) return Egeometric_representation_context::Create(name);
	if(classname==_T("Egeometric_representation_item")) return Egeometric_representation_item::Create(name);
	if(classname==_T("Ehole_bottom_condition")) return Ehole_bottom_condition::Create(name);
	if(classname==_T("Ehyperbola")) return Ehyperbola::Create(name);
	if(classname==_T("Eif_statement")) return Eif_statement::Create(name);
	if(classname==_T("Ein_process_geometry")) return Ein_process_geometry::Create(name);
	if(classname==_T("Eindex_pallet")) return Eindex_pallet::Create(name);
	if(classname==_T("Eindex_table")) return Eindex_table::Create(name);
	if(classname==_T("Eleading_line_strategy")) return Eleading_line_strategy::Create(name);
	if(classname==_T("Elimits_and_fits")) return Elimits_and_fits::Create(name);
	if(classname==_T("Eline")) return Eline::Create(name);
	if(classname==_T("Elinear_path")) return Elinear_path::Create(name);
	if(classname==_T("Elinear_profile")) return Elinear_profile::Create(name);
	if(classname==_T("Eload_tool")) return Eload_tool::Create(name);
	if(classname==_T("Elocal_time")) return Elocal_time::Create(name);
	if(classname==_T("Eloop")) return Eloop::Create(name);
	if(classname==_T("Eloop_slot_end_type")) return Eloop_slot_end_type::Create(name);
	if(classname==_T("Emachine_functions")) return Emachine_functions::Create(name);
	if(classname==_T("Emachined_surface")) return Emachined_surface::Create(name);
	if(classname==_T("Emachining_feature")) return Emachining_feature::Create(name);
	if(classname==_T("Emachining_operation")) return Emachining_operation::Create(name);
	if(classname==_T("Emachining_tool")) return Emachining_tool::Create(name);
	if(classname==_T("Emachining_workingstep")) return Emachining_workingstep::Create(name);
	if(classname==_T("Emanifold_solid_brep")) return Emanifold_solid_brep::Create(name);
	if(classname==_T("Emanufacturing_feature")) return Emanufacturing_feature::Create(name);
	if(classname==_T("Ematerial")) return Ematerial::Create(name);
	if(classname==_T("Emilling_cutter")) return Emilling_cutter::Create(name);
	if(classname==_T("Emilling_cutting_tool")) return Emilling_cutting_tool::Create(name);
	if(classname==_T("Emilling_machine_functions")) return Emilling_machine_functions::Create(name);
	if(classname==_T("Emilling_machining_operation")) return Emilling_machining_operation::Create(name);
	if(classname==_T("Emilling_technology")) return Emilling_technology::Create(name);
	if(classname==_T("Emilling_tool_body")) return Emilling_tool_body::Create(name);
	if(classname==_T("Emilling_tool_dimension")) return Emilling_tool_dimension::Create(name);
	if(classname==_T("Emilling_type_operation")) return Emilling_type_operation::Create(name);
	if(classname==_T("Emultiple_arity_boolean_expression")) return Emultiple_arity_boolean_expression::Create(name);
	if(classname==_T("Emultistep_drilling")) return Emultistep_drilling::Create(name);
	if(classname==_T("Enc_constant")) return Enc_constant::Create(name);
	if(classname==_T("Enc_function")) return Enc_function::Create(name);
	if(classname==_T("Enc_variable")) return Enc_variable::Create(name);
	if(classname==_T("Engon_profile")) return Engon_profile::Create(name);
	if(classname==_T("Enon_sequential")) return Enon_sequential::Create(name);
	if(classname==_T("Enot_expression")) return Enot_expression::Create(name);
	if(classname==_T("Enumeric_parameter")) return Enumeric_parameter::Create(name);
	if(classname==_T("Eoffset_vector")) return Eoffset_vector::Create(name);
	if(classname==_T("Eopen_pocket")) return Eopen_pocket::Create(name);
	if(classname==_T("Eopen_profile")) return Eopen_profile::Create(name);
	if(classname==_T("Eopen_shell")) return Eopen_shell::Create(name);
	if(classname==_T("Eopen_slot_end_type")) return Eopen_slot_end_type::Create(name);
	if(classname==_T("Eoperation")) return Eoperation::Create(name);
	if(classname==_T("Eoptional_stop")) return Eoptional_stop::Create(name);
	if(classname==_T("Eor_expression")) return Eor_expression::Create(name);
	if(classname==_T("Eordinal_date")) return Eordinal_date::Create(name);
	if(classname==_T("Eoriented_edge")) return Eoriented_edge::Create(name);
	if(classname==_T("Eparabola")) return Eparabola::Create(name);
	if(classname==_T("Eparallel")) return Eparallel::Create(name);
	if(classname==_T("Eparameterised_path")) return Eparameterised_path::Create(name);
	if(classname==_T("Epartial_area_definition")) return Epartial_area_definition::Create(name);
	if(classname==_T("Epartial_circular_path")) return Epartial_circular_path::Create(name);
	if(classname==_T("Epartial_circular_profile")) return Epartial_circular_profile::Create(name);
	if(classname==_T("Epartial_circular_shape_profile")) return Epartial_circular_shape_profile::Create(name);
	if(classname==_T("Epath")) return Epath::Create(name);
	if(classname==_T("Epcurve")) return Epcurve::Create(name);
	if(classname==_T("Eperson")) return Eperson::Create(name);
	if(classname==_T("Eperson_and_address")) return Eperson_and_address::Create(name);
	if(classname==_T("Eplacement")) return Eplacement::Create(name);
	if(classname==_T("Eplanar_face")) return Eplanar_face::Create(name);
	if(classname==_T("Eplanar_pocket_bottom_condition")) return Eplanar_pocket_bottom_condition::Create(name);
	if(classname==_T("Eplanar_profile_floor")) return Eplanar_profile_floor::Create(name);
	if(classname==_T("Eplane")) return Eplane::Create(name);
	if(classname==_T("Eplane_cc_strategy")) return Eplane_cc_strategy::Create(name);
	if(classname==_T("Eplane_cl_strategy")) return Eplane_cl_strategy::Create(name);
	if(classname==_T("Eplane_finish_milling")) return Eplane_finish_milling::Create(name);
	if(classname==_T("Eplane_milling")) return Eplane_milling::Create(name);
	if(classname==_T("Eplane_rough_milling")) return Eplane_rough_milling::Create(name);
	if(classname==_T("Eplunge_helix")) return Eplunge_helix::Create(name);
	if(classname==_T("Eplunge_ramp")) return Eplunge_ramp::Create(name);
	if(classname==_T("Eplunge_strategy")) return Eplunge_strategy::Create(name);
	if(classname==_T("Eplunge_toolaxis")) return Eplunge_toolaxis::Create(name);
	if(classname==_T("Eplunge_zigzag")) return Eplunge_zigzag::Create(name);
	if(classname==_T("Eplus_minus_value")) return Eplus_minus_value::Create(name);
	if(classname==_T("Epocket")) return Epocket::Create(name);
	if(classname==_T("Epocket_bottom_condition")) return Epocket_bottom_condition::Create(name);
	if(classname==_T("Epoint")) return Epoint::Create(name);
	if(classname==_T("Epolyline")) return Epolyline::Create(name);
	if(classname==_T("Eprocess_model")) return Eprocess_model::Create(name);
	if(classname==_T("Eprocess_model_list")) return Eprocess_model_list::Create(name);
	if(classname==_T("Eprofile")) return Eprofile::Create(name);
	if(classname==_T("Eprofile_feature")) return Eprofile_feature::Create(name);
	if(classname==_T("Eprofile_floor")) return Eprofile_floor::Create(name);
	if(classname==_T("Eprogram_stop")) return Eprogram_stop::Create(name);
	if(classname==_T("Eprogram_structure")) return Eprogram_structure::Create(name);
	if(classname==_T("Eproject")) return Eproject::Create(name);
	if(classname==_T("Eproperty_parameter")) return Eproperty_parameter::Create(name);
	if(classname==_T("Equasi_uniform_curve")) return Equasi_uniform_curve::Create(name);
	if(classname==_T("Equasi_uniform_surface")) return Equasi_uniform_surface::Create(name);
	if(classname==_T("Eradiused_pocket_bottom_condition")) return Eradiused_pocket_bottom_condition::Create(name);
	if(classname==_T("Eradiused_slot_end_type")) return Eradiused_slot_end_type::Create(name);
	if(classname==_T("Erapid_movement")) return Erapid_movement::Create(name);
	if(classname==_T("Erational_b_spline_curve")) return Erational_b_spline_curve::Create(name);
	if(classname==_T("Erational_b_spline_surface")) return Erational_b_spline_surface::Create(name);
	if(classname==_T("Ereamer")) return Ereamer::Create(name);
	if(classname==_T("Ereaming")) return Ereaming::Create(name);
	if(classname==_T("Erectangular_closed_profile")) return Erectangular_closed_profile::Create(name);
	if(classname==_T("Erectangular_closed_shape_profile")) return Erectangular_closed_shape_profile::Create(name);
	if(classname==_T("Erectangular_offset")) return Erectangular_offset::Create(name);
	if(classname==_T("Erectangular_omit")) return Erectangular_omit::Create(name);
	if(classname==_T("Erectangular_open_shape_profile")) return Erectangular_open_shape_profile::Create(name);
	if(classname==_T("Erectangular_pattern")) return Erectangular_pattern::Create(name);
	if(classname==_T("Eregion")) return Eregion::Create(name);
	if(classname==_T("Eregion_projection")) return Eregion_projection::Create(name);
	if(classname==_T("Eregion_surface_list")) return Eregion_surface_list::Create(name);
	if(classname==_T("Ereplicate_feature")) return Ereplicate_feature::Create(name);
	if(classname==_T("Erepresentation")) return Erepresentation::Create(name);
	if(classname==_T("Erepresentation_context")) return Erepresentation_context::Create(name);
	if(classname==_T("Erepresentation_item")) return Erepresentation_item::Create(name);
	if(classname==_T("Ereturn_home")) return Ereturn_home::Create(name);
	if(classname==_T("Eright_circular_cylinder")) return Eright_circular_cylinder::Create(name);
	if(classname==_T("Eround_hole")) return Eround_hole::Create(name);
	if(classname==_T("Erounded_end")) return Erounded_end::Create(name);
	if(classname==_T("Erounded_u_profile")) return Erounded_u_profile::Create(name);
	if(classname==_T("Eselective")) return Eselective::Create(name);
	if(classname==_T("Eset_mark")) return Eset_mark::Create(name);
	if(classname==_T("Esetup")) return Esetup::Create(name);
	if(classname==_T("Esetup_instruction")) return Esetup_instruction::Create(name);
	if(classname==_T("Eshape_profile")) return Eshape_profile::Create(name);
	if(classname==_T("Eshape_representation")) return Eshape_representation::Create(name);
	if(classname==_T("Eside_finish_milling")) return Eside_finish_milling::Create(name);
	if(classname==_T("Eside_mill")) return Eside_mill::Create(name);
	if(classname==_T("Eside_milling")) return Eside_milling::Create(name);
	if(classname==_T("Eside_rough_milling")) return Eside_rough_milling::Create(name);
	if(classname==_T("Eslot")) return Eslot::Create(name);
	if(classname==_T("Eslot_end_type")) return Eslot_end_type::Create(name);
	if(classname==_T("Esolid_model")) return Esolid_model::Create(name);
	if(classname==_T("Espade_drill")) return Espade_drill::Create(name);
	if(classname==_T("Especification")) return Especification::Create(name);
	if(classname==_T("Especification_usage_constraint")) return Especification_usage_constraint::Create(name);
	if(classname==_T("Espherical_cap")) return Espherical_cap::Create(name);
	if(classname==_T("Espherical_hole_bottom")) return Espherical_hole_bottom::Create(name);
	if(classname==_T("Espherical_surface")) return Espherical_surface::Create(name);
	if(classname==_T("Esquare_u_profile")) return Esquare_u_profile::Create(name);
	if(classname==_T("Estep")) return Estep::Create(name);
	if(classname==_T("Esurface")) return Esurface::Create(name);
	if(classname==_T("Esurface_of_linear_extrusion")) return Esurface_of_linear_extrusion::Create(name);
	if(classname==_T("Esurface_of_revolution")) return Esurface_of_revolution::Create(name);
	if(classname==_T("Esurface_texture_parameter")) return Esurface_texture_parameter::Create(name);
	if(classname==_T("Eswept_surface")) return Eswept_surface::Create(name);
	if(classname==_T("Et_slot_mill")) return Et_slot_mill::Create(name);
	if(classname==_T("Etap")) return Etap::Create(name);
	if(classname==_T("Etapered_drill")) return Etapered_drill::Create(name);
	if(classname==_T("Etapered_endmill")) return Etapered_endmill::Create(name);
	if(classname==_T("Etapered_reamer")) return Etapered_reamer::Create(name);
	if(classname==_T("Etapered_tap")) return Etapered_tap::Create(name);
	if(classname==_T("Etapping")) return Etapping::Create(name);
	if(classname==_T("Etechnology")) return Etechnology::Create(name);
	if(classname==_T("Etee_profile")) return Etee_profile::Create(name);
	if(classname==_T("Ethread")) return Ethread::Create(name);
	if(classname==_T("Ethread_drilling")) return Ethread_drilling::Create(name);
	if(classname==_T("Ethread_mill")) return Ethread_mill::Create(name);
	if(classname==_T("Ethreading_tool")) return Ethreading_tool::Create(name);
	if(classname==_T("Ethree_axes")) return Ethree_axes::Create(name);
	if(classname==_T("Ethree_axes_tilted_tool")) return Ethree_axes_tilted_tool::Create(name);
	if(classname==_T("Ethrough_bottom_condition")) return Ethrough_bottom_condition::Create(name);
	if(classname==_T("Ethrough_pocket_bottom_condition")) return Ethrough_pocket_bottom_condition::Create(name);
	if(classname==_T("Ethrough_profile_floor")) return Ethrough_profile_floor::Create(name);
	if(classname==_T("Etoleranced_length_measure")) return Etoleranced_length_measure::Create(name);
	if(classname==_T("Etolerances")) return Etolerances::Create(name);
	if(classname==_T("Etool_body")) return Etool_body::Create(name);
	if(classname==_T("Etool_direction")) return Etool_direction::Create(name);
	if(classname==_T("Etool_direction_for_milling")) return Etool_direction_for_milling::Create(name);
	if(classname==_T("Etool_length_probing")) return Etool_length_probing::Create(name);
	if(classname==_T("Etool_probing")) return Etool_probing::Create(name);
	if(classname==_T("Etool_radius_probing")) return Etool_radius_probing::Create(name);
	if(classname==_T("Etoolpath")) return Etoolpath::Create(name);
	if(classname==_T("Etoolpath_feature")) return Etoolpath_feature::Create(name);
	if(classname==_T("Etoolpath_list")) return Etoolpath_list::Create(name);
	if(classname==_T("Etoolpath_speed")) return Etoolpath_speed::Create(name);
	if(classname==_T("Etopological_region")) return Etopological_region::Create(name);
	if(classname==_T("Etopological_representation_item")) return Etopological_representation_item::Create(name);
	if(classname==_T("Etouch_probe")) return Etouch_probe::Create(name);
	if(classname==_T("Etouch_probing")) return Etouch_probing::Create(name);
	if(classname==_T("Etrajectory")) return Etrajectory::Create(name);
	if(classname==_T("Etransition_feature")) return Etransition_feature::Create(name);
	if(classname==_T("Etravel_path")) return Etravel_path::Create(name);
	if(classname==_T("Etrimmed_curve")) return Etrimmed_curve::Create(name);
	if(classname==_T("Etwist_drill")) return Etwist_drill::Create(name);
	if(classname==_T("Etwo5d_manufacturing_feature")) return Etwo5d_manufacturing_feature::Create(name);
	if(classname==_T("Etwo5d_milling_operation")) return Etwo5d_milling_operation::Create(name);
	if(classname==_T("Etwo5d_milling_strategy")) return Etwo5d_milling_strategy::Create(name);
	if(classname==_T("Etwo_axes")) return Etwo_axes::Create(name);
	if(classname==_T("Eunary_boolean_expression")) return Eunary_boolean_expression::Create(name);
	if(classname==_T("Eunidirectional")) return Eunidirectional::Create(name);
	if(classname==_T("Euniform_curve")) return Euniform_curve::Create(name);
	if(classname==_T("Euniform_surface")) return Euniform_surface::Create(name);
	if(classname==_T("Eunload_tool")) return Eunload_tool::Create(name);
	if(classname==_T("Euser_defined_tool")) return Euser_defined_tool::Create(name);
	if(classname==_T("Euv_strategy")) return Euv_strategy::Create(name);
	if(classname==_T("Evector")) return Evector::Create(name);
	if(classname==_T("Evee_profile")) return Evee_profile::Create(name);
	if(classname==_T("Evertex")) return Evertex::Create(name);
	if(classname==_T("Evertex_loop")) return Evertex_loop::Create(name);
	if(classname==_T("Evertex_point")) return Evertex_point::Create(name);
	if(classname==_T("Ewait_for_mark")) return Ewait_for_mark::Create(name);
	if(classname==_T("Eweek_of_year_and_day_date")) return Eweek_of_year_and_day_date::Create(name);
	if(classname==_T("Ewhile_statement")) return Ewhile_statement::Create(name);
	if(classname==_T("Ewoodruff_keyseat_mill")) return Ewoodruff_keyseat_mill::Create(name);
	if(classname==_T("Ewoodruff_slot_end_type")) return Ewoodruff_slot_end_type::Create(name);
	if(classname==_T("Eworkingstep")) return Eworkingstep::Create(name);
	if(classname==_T("Eworkpiece")) return Eworkpiece::Create(name);
	if(classname==_T("Eworkpiece_complete_probing")) return Eworkpiece_complete_probing::Create(name);
	if(classname==_T("Eworkpiece_probing")) return Eworkpiece_probing::Create(name);
	if(classname==_T("Eworkpiece_setup")) return Eworkpiece_setup::Create(name);
	if(classname==_T("Eworkplan")) return Eworkplan::Create(name);
	if(classname==_T("Exor_expression")) return Exor_expression::Create(name);
	if(classname==_T("Eday_in_month_number")) return  (IStepNodePtr) new Eday_in_month_number;
	if(classname==_T("Emonth_in_year_number")) return  (IStepNodePtr) new Emonth_in_year_number;
	if(classname==_T("Eday_in_year_number")) return  (IStepNodePtr) new Eday_in_year_number;
	if(classname==_T("Eweek_in_year_number")) return  (IStepNodePtr) new Eweek_in_year_number;
	if(classname==_T("Eday_in_week_number")) return  (IStepNodePtr) new Eday_in_week_number;
	if(classname==_T("Ehour_in_day")) return  (IStepNodePtr) new Ehour_in_day;
	if(classname==_T("Eminute_in_hour")) return  (IStepNodePtr) new Eminute_in_hour;
	if(classname==_T("Esecond_in_minute")) return  (IStepNodePtr) new Esecond_in_minute;
	if(classname==_T("Eahead_or_behind")) return Eahead_or_behind::Create(name);
	if(classname==_T("Eyear_number")) return  (IStepNodePtr) new Eyear_number;
	if(classname==_T("Eidentifier")) return  (IStepNodePtr) new Eidentifier;
	if(classname==_T("Elabel")) return  (IStepNodePtr) new Elabel;
	if(classname==_T("Etext")) return  (IStepNodePtr) new Etext;
	if(classname==_T("Elength_measure")) return  (IStepNodePtr) new Elength_measure;
	if(classname==_T("Eparameter_value")) return  (IStepNodePtr) new Eparameter_value;
	if(classname==_T("Eplane_angle_measure")) return  (IStepNodePtr) new Eplane_angle_measure;
	if(classname==_T("Epositive_length_measure")) return  (IStepNodePtr) new Epositive_length_measure;
	if(classname==_T("Epositive_ratio_measure")) return  (IStepNodePtr) new Epositive_ratio_measure;
	if(classname==_T("Eratio_measure")) return  (IStepNodePtr) new Eratio_measure;
	if(classname==_T("Etime_measure")) return  (IStepNodePtr) new Etime_measure;
	if(classname==_T("Etrimming_select")) return  (IStepNodePtr) new Etrimming_select;
	if(classname==_T("Etrimming_preference")) return Etrimming_preference::Create(name);
	if(classname==_T("Etransition_code")) return Etransition_code::Create(name);
	if(classname==_T("Eb_spline_curve_form")) return Eb_spline_curve_form::Create(name);
	if(classname==_T("Eb_spline_surface_form")) return Eb_spline_surface_form::Create(name);
	if(classname==_T("Edimension_count")) return  (IStepNodePtr) new Edimension_count;
	if(classname==_T("Eknot_type")) return Eknot_type::Create(name);
	if(classname==_T("Epcurve_or_surface")) return  (IStepNodePtr) new Epcurve_or_surface;
	if(classname==_T("Evector_or_direction")) return  (IStepNodePtr) new Evector_or_direction;
	if(classname==_T("Etolerance_select")) return  (IStepNodePtr) new Etolerance_select;
	if(classname==_T("Efitting_type")) return Efitting_type::Create(name);
	if(classname==_T("Espeed_measure")) return  (IStepNodePtr) new Espeed_measure;
	if(classname==_T("Erot_speed_measure")) return  (IStepNodePtr) new Erot_speed_measure;
	if(classname==_T("Epressure_measure")) return  (IStepNodePtr) new Epressure_measure;
	if(classname==_T("Erot_direction")) return Erot_direction::Create(name);
	if(classname==_T("Eshape_tolerance")) return  (IStepNodePtr) new Eshape_tolerance;
	if(classname==_T("Ebounding_geometry_select")) return  (IStepNodePtr) new Ebounding_geometry_select;
	if(classname==_T("Eprofile_select")) return  (IStepNodePtr) new Eprofile_select;
	if(classname==_T("Etaper_select")) return  (IStepNodePtr) new Etaper_select;
	if(classname==_T("Ecompound_feature_select")) return  (IStepNodePtr) new Ecompound_feature_select;
	if(classname==_T("Ebottom_or_side")) return Ebottom_or_side::Create(name);
	if(classname==_T("Erestricted_area_select")) return  (IStepNodePtr) new Erestricted_area_select;
	if(classname==_T("Ervalue")) return  (IStepNodePtr) new Ervalue;
	if(classname==_T("Etool_reference_point")) return Etool_reference_point::Create(name);
	if(classname==_T("Etoolpath_type")) return Etoolpath_type::Create(name);
	if(classname==_T("Etoolpath_speedprofile")) return  (IStepNodePtr) new Etoolpath_speedprofile;
	if(classname==_T("Espeed_name")) return Espeed_name::Create(name);
	if(classname==_T("Ecurve_with_surface_normal")) return  (IStepNodePtr) new Ecurve_with_surface_normal;
	if(classname==_T("Econtact_type")) return Econtact_type::Create(name);
	if(classname==_T("Ehand")) return Ehand::Create(name);
	if(classname==_T("Epathmode_type")) return Epathmode_type::Create(name);
	if(classname==_T("Ecutmode_type")) return Ecutmode_type::Create(name);
	if(classname==_T("Eleft_or_right")) return Eleft_or_right::Create(name);
	if(classname==_T("Estroke_connection_strategy")) return Estroke_connection_strategy::Create(name);
	return NULL; 
}
	static CStringVector svEntities(358, 
	CString("Eadaptive_control"),
	CString("Eaddress"),
	CString("Eadvanced_brep_shape_representation"),
	CString("Eadvanced_face"),
	CString("Eair_strategy"),
	CString("Ealong_path"),
	CString("Eand_expression"),
	CString("Eangle_taper"),
	CString("Eap_lift_path_angle"),
	CString("Eap_lift_path_tangent"),
	CString("Eap_retract_angle"),
	CString("Eap_retract_tangent"),
	CString("Eapproach_lift_path"),
	CString("Eapproach_retract_strategy"),
	CString("Eapproval"),
	CString("Eapproval_status"),
	CString("Eassignment"),
	CString("Eaxis1_placement"),
	CString("Eaxis2_placement_3d"),
	CString("Eaxis_trajectory"),
	CString("Eb_spline_curve"),
	CString("Eb_spline_curve_with_knots"),
	CString("Eb_spline_surface"),
	CString("Eb_spline_surface_with_knots"),
	CString("Eback_boring"),
	CString("Ebackside_counterbore"),
	CString("Ebackside_countersink"),
	CString("Eball_endmill"),
	CString("Ebezier_curve"),
	CString("Ebezier_surface"),
	CString("Ebidirectional"),
	CString("Ebidirectional_contour"),
	CString("Ebinary_boolean_expression"),
	CString("Eblind_bottom_condition"),
	CString("Eblock"),
	CString("Eboolean_expression"),
	CString("Eboring"),
	CString("Eboring_operation"),
	CString("Eboring_tool"),
	CString("Eboss"),
	CString("Ebottom_and_side_finish_milling"),
	CString("Ebottom_and_side_milling"),
	CString("Ebottom_and_side_rough_milling"),
	CString("Ebounded_curve"),
	CString("Ebounded_pcurve"),
	CString("Ebounded_surface"),
	CString("Ebullnose_endmill"),
	CString("Ecalendar_date"),
	CString("Ecartesian_point"),
	CString("Ecatalogue_thread"),
	CString("Ecenter_drill"),
	CString("Ecenter_drilling"),
	CString("Ecenter_milling"),
	CString("Echamfer"),
	CString("Echannel"),
	CString("Ecircle"),
	CString("Ecircular_closed_profile"),
	CString("Ecircular_closed_shape_profile"),
	CString("Ecircular_offset"),
	CString("Ecircular_omit"),
	CString("Ecircular_path"),
	CString("Ecircular_pattern"),
	CString("Eclosed_pocket"),
	CString("Eclosed_profile"),
	CString("Eclosed_shell"),
	CString("Ecombined_drill_and_reamer"),
	CString("Ecombined_drill_and_tap"),
	CString("Ecomparison_equal"),
	CString("Ecomparison_expression"),
	CString("Ecomparison_greater"),
	CString("Ecomparison_greater_equal"),
	CString("Ecomparison_less"),
	CString("Ecomparison_less_equal"),
	CString("Ecomparison_not_equal"),
	CString("Ecomplete_circular_path"),
	CString("Ecomposite_curve"),
	CString("Ecomposite_curve_segment"),
	CString("Ecompound_feature"),
	CString("Econic"),
	CString("Econical_hole_bottom"),
	CString("Econnect_direct"),
	CString("Econnect_secplane"),
	CString("Econnected_face_set"),
	CString("Econnector"),
	CString("Econtour_bidirectional"),
	CString("Econtour_parallel"),
	CString("Econtour_spiral"),
	CString("Ecoordinated_universal_time_offset"),
	CString("Ecounter_sinking"),
	CString("Ecounterbore"),
	CString("Ecounterbore_hole"),
	CString("Ecountersink"),
	CString("Ecountersunk_hole"),
	CString("Ecurve"),
	CString("Ecurve_with_normal_vector"),
	CString("Ecutter_contact_trajectory"),
	CString("Ecutter_location_trajectory"),
	CString("Ecutting_component"),
	CString("Ecutting_edge_technological_data"),
	CString("Ecutting_tool"),
	CString("Edate"),
	CString("Edate_and_time"),
	CString("Edefined_thread"),
	CString("Edefinitional_representation"),
	CString("Edescriptive_parameter"),
	CString("Ediameter_taper"),
	CString("Edirection"),
	CString("Edisplay_message"),
	CString("Edovetail_mill"),
	CString("Edrill"),
	CString("Edrilling"),
	CString("Edrilling_operation"),
	CString("Edrilling_type_operation"),
	CString("Edrilling_type_strategy"),
	CString("Eedge"),
	CString("Eedge_curve"),
	CString("Eedge_loop"),
	CString("Eedge_round"),
	CString("Eelementary_surface"),
	CString("Eellipse"),
	CString("Eendmill"),
	CString("Eexchange_pallet"),
	CString("Eexecutable"),
	CString("Eexplicit"),
	CString("Eface"),
	CString("Eface_bound"),
	CString("Eface_outer_bound"),
	CString("Eface_surface"),
	CString("Efacemill"),
	CString("Efeedstop"),
	CString("Efive_axes_const_tilt_yaw"),
	CString("Efive_axes_var_tilt_yaw"),
	CString("Eflat_hole_bottom"),
	CString("Eflat_slot_end_type"),
	CString("Eflat_with_radius_hole_bottom"),
	CString("Efreeform_operation"),
	CString("Efreeform_strategy"),
	CString("Egeneral_closed_profile"),
	CString("Egeneral_outside_profile"),
	CString("Egeneral_path"),
	CString("Egeneral_pattern"),
	CString("Egeneral_pocket_bottom_condition"),
	CString("Egeneral_profile"),
	CString("Egeneral_profile_floor"),
	CString("Egeneral_shape_profile"),
	CString("Egeometric_representation_context"),
	CString("Egeometric_representation_item"),
	CString("Ehole_bottom_condition"),
	CString("Ehyperbola"),
	CString("Eif_statement"),
	CString("Ein_process_geometry"),
	CString("Eindex_pallet"),
	CString("Eindex_table"),
	CString("Eleading_line_strategy"),
	CString("Elimits_and_fits"),
	CString("Eline"),
	CString("Elinear_path"),
	CString("Elinear_profile"),
	CString("Eload_tool"),
	CString("Elocal_time"),
	CString("Eloop"),
	CString("Eloop_slot_end_type"),
	CString("Emachine_functions"),
	CString("Emachined_surface"),
	CString("Emachining_feature"),
	CString("Emachining_operation"),
	CString("Emachining_tool"),
	CString("Emachining_workingstep"),
	CString("Emanifold_solid_brep"),
	CString("Emanufacturing_feature"),
	CString("Ematerial"),
	CString("Emilling_cutter"),
	CString("Emilling_cutting_tool"),
	CString("Emilling_machine_functions"),
	CString("Emilling_machining_operation"),
	CString("Emilling_technology"),
	CString("Emilling_tool_body"),
	CString("Emilling_tool_dimension"),
	CString("Emilling_type_operation"),
	CString("Emultiple_arity_boolean_expression"),
	CString("Emultistep_drilling"),
	CString("Enc_constant"),
	CString("Enc_function"),
	CString("Enc_variable"),
	CString("Engon_profile"),
	CString("Enon_sequential"),
	CString("Enot_expression"),
	CString("Enumeric_parameter"),
	CString("Eoffset_vector"),
	CString("Eopen_pocket"),
	CString("Eopen_profile"),
	CString("Eopen_shell"),
	CString("Eopen_slot_end_type"),
	CString("Eoperation"),
	CString("Eoptional_stop"),
	CString("Eor_expression"),
	CString("Eordinal_date"),
	CString("Eoriented_edge"),
	CString("Eparabola"),
	CString("Eparallel"),
	CString("Eparameterised_path"),
	CString("Epartial_area_definition"),
	CString("Epartial_circular_path"),
	CString("Epartial_circular_profile"),
	CString("Epartial_circular_shape_profile"),
	CString("Epath"),
	CString("Epcurve"),
	CString("Eperson"),
	CString("Eperson_and_address"),
	CString("Eplacement"),
	CString("Eplanar_face"),
	CString("Eplanar_pocket_bottom_condition"),
	CString("Eplanar_profile_floor"),
	CString("Eplane"),
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
	CString("Eplus_minus_value"),
	CString("Epocket"),
	CString("Epocket_bottom_condition"),
	CString("Epoint"),
	CString("Epolyline"),
	CString("Eprocess_model"),
	CString("Eprocess_model_list"),
	CString("Eprofile"),
	CString("Eprofile_feature"),
	CString("Eprofile_floor"),
	CString("Eprogram_stop"),
	CString("Eprogram_structure"),
	CString("Eproject"),
	CString("Eproperty_parameter"),
	CString("Equasi_uniform_curve"),
	CString("Equasi_uniform_surface"),
	CString("Eradiused_pocket_bottom_condition"),
	CString("Eradiused_slot_end_type"),
	CString("Erapid_movement"),
	CString("Erational_b_spline_curve"),
	CString("Erational_b_spline_surface"),
	CString("Ereamer"),
	CString("Ereaming"),
	CString("Erectangular_closed_profile"),
	CString("Erectangular_closed_shape_profile"),
	CString("Erectangular_offset"),
	CString("Erectangular_omit"),
	CString("Erectangular_open_shape_profile"),
	CString("Erectangular_pattern"),
	CString("Eregion"),
	CString("Eregion_projection"),
	CString("Eregion_surface_list"),
	CString("Ereplicate_feature"),
	CString("Erepresentation"),
	CString("Erepresentation_context"),
	CString("Erepresentation_item"),
	CString("Ereturn_home"),
	CString("Eright_circular_cylinder"),
	CString("Eround_hole"),
	CString("Erounded_end"),
	CString("Erounded_u_profile"),
	CString("Eselective"),
	CString("Eset_mark"),
	CString("Esetup"),
	CString("Esetup_instruction"),
	CString("Eshape_profile"),
	CString("Eshape_representation"),
	CString("Eside_finish_milling"),
	CString("Eside_mill"),
	CString("Eside_milling"),
	CString("Eside_rough_milling"),
	CString("Eslot"),
	CString("Eslot_end_type"),
	CString("Esolid_model"),
	CString("Espade_drill"),
	CString("Especification"),
	CString("Especification_usage_constraint"),
	CString("Espherical_cap"),
	CString("Espherical_hole_bottom"),
	CString("Espherical_surface"),
	CString("Esquare_u_profile"),
	CString("Estep"),
	CString("Esurface"),
	CString("Esurface_of_linear_extrusion"),
	CString("Esurface_of_revolution"),
	CString("Esurface_texture_parameter"),
	CString("Eswept_surface"),
	CString("Et_slot_mill"),
	CString("Etap"),
	CString("Etapered_drill"),
	CString("Etapered_endmill"),
	CString("Etapered_reamer"),
	CString("Etapered_tap"),
	CString("Etapping"),
	CString("Etechnology"),
	CString("Etee_profile"),
	CString("Ethread"),
	CString("Ethread_drilling"),
	CString("Ethread_mill"),
	CString("Ethreading_tool"),
	CString("Ethree_axes"),
	CString("Ethree_axes_tilted_tool"),
	CString("Ethrough_bottom_condition"),
	CString("Ethrough_pocket_bottom_condition"),
	CString("Ethrough_profile_floor"),
	CString("Etoleranced_length_measure"),
	CString("Etolerances"),
	CString("Etool_body"),
	CString("Etool_direction"),
	CString("Etool_direction_for_milling"),
	CString("Etool_length_probing"),
	CString("Etool_probing"),
	CString("Etool_radius_probing"),
	CString("Etoolpath"),
	CString("Etoolpath_feature"),
	CString("Etoolpath_list"),
	CString("Etoolpath_speed"),
	CString("Etopological_region"),
	CString("Etopological_representation_item"),
	CString("Etouch_probe"),
	CString("Etouch_probing"),
	CString("Etrajectory"),
	CString("Etransition_feature"),
	CString("Etravel_path"),
	CString("Etrimmed_curve"),
	CString("Etwist_drill"),
	CString("Etwo5d_manufacturing_feature"),
	CString("Etwo5d_milling_operation"),
	CString("Etwo5d_milling_strategy"),
	CString("Etwo_axes"),
	CString("Eunary_boolean_expression"),
	CString("Eunidirectional"),
	CString("Euniform_curve"),
	CString("Euniform_surface"),
	CString("Eunload_tool"),
	CString("Euser_defined_tool"),
	CString("Euv_strategy"),
	CString("Evector"),
	CString("Evee_profile"),
	CString("Evertex"),
	CString("Evertex_loop"),
	CString("Evertex_point"),
	CString("Ewait_for_mark"),
	CString("Eweek_of_year_and_day_date"),
	CString("Ewhile_statement"),
	CString("Ewoodruff_keyseat_mill"),
	CString("Ewoodruff_slot_end_type"),
	CString("Eworkingstep"),
	CString("Eworkpiece"),
	CString("Eworkpiece_complete_probing"),
	CString("Eworkpiece_probing"),
	CString("Eworkpiece_setup"),
	CString("Eworkplan"),
	CString("Exor_expression"));
 CStringVector GetAllstepnc_schemaEntities(){ return svEntities;}
} /* End namespace Express*/
