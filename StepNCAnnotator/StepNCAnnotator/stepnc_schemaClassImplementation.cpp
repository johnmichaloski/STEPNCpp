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
	Classname()="Eadaptive_control";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Eadaptive_control*/
////////////////////////////////////////////////////////////////////////////////
Eaddress::Eaddress(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eaddress";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "internal_location" ,(StepNodeType) 22, (DWORD) &(this->internal_location), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "street_number" ,(StepNodeType) 22, (DWORD) &(this->street_number), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "street" ,(StepNodeType) 22, (DWORD) &(this->street), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "postal_box" ,(StepNodeType) 22, (DWORD) &(this->postal_box), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "town" ,(StepNodeType) 22, (DWORD) &(this->town), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "region" ,(StepNodeType) 22, (DWORD) &(this->region), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "postal_code" ,(StepNodeType) 22, (DWORD) &(this->postal_code), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "country" ,(StepNodeType) 22, (DWORD) &(this->country), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "facsimile_number" ,(StepNodeType) 22, (DWORD) &(this->facsimile_number), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "telephone_number" ,(StepNodeType) 22, (DWORD) &(this->telephone_number), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "electronic_mail_address" ,(StepNodeType) 22, (DWORD) &(this->electronic_mail_address), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "telex_number" ,(StepNodeType) 22, (DWORD) &(this->telex_number), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eaddress*/
////////////////////////////////////////////////////////////////////////////////
Eadvanced_brep_shape_representation::Eadvanced_brep_shape_representation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eadvanced_brep_shape_representation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eshape_representation") ; 
	parents.push_back("Erepresentation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->Eshape_representation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eadvanced_brep_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Eadvanced_face::Eadvanced_face(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eadvanced_face";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eface_surface") ; 
	parents.push_back("Eface") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eface_surface" ,(StepNodeType) 1, (DWORD) &(this->Eface_surface::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eadvanced_face*/
////////////////////////////////////////////////////////////////////////////////
Eair_strategy::Eair_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eair_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	supertypes.push_back("Eap_retract_angle") ; 
	supertypes.push_back("Eap_retract_tangent") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eapproach_retract_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eapproach_retract_strategy::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eair_strategy*/
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
////////////////////////////////////////////////////////////////////////////////
Eand_expression::Eand_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eand_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emultiple_arity_boolean_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emultiple_arity_boolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Emultiple_arity_boolean_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eand_expression*/
////////////////////////////////////////////////////////////////////////////////
Eangle_taper::Eangle_taper(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eangle_taper";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "angle" ,(StepNodeType) 22, (DWORD) &(this->angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eangle_taper*/
////////////////////////////////////////////////////////////////////////////////
Eap_lift_path_angle::Eap_lift_path_angle(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eap_lift_path_angle";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eapproach_lift_path") ; 
	parents.push_back("Eparameterised_path") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eapproach_lift_path" ,(StepNodeType) 1, (DWORD) &(this->Eapproach_lift_path::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "angle" ,(StepNodeType) 22, (DWORD) &(this->angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "benddist" ,(StepNodeType) 22, (DWORD) &(this->benddist), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eap_lift_path_angle*/
////////////////////////////////////////////////////////////////////////////////
Eap_lift_path_tangent::Eap_lift_path_tangent(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eap_lift_path_tangent";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eapproach_lift_path") ; 
	parents.push_back("Eparameterised_path") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eapproach_lift_path" ,(StepNodeType) 1, (DWORD) &(this->Eapproach_lift_path::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eap_lift_path_tangent*/
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
////////////////////////////////////////////////////////////////////////////////
Eapproach_lift_path::Eapproach_lift_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eapproach_lift_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eparameterised_path") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	supertypes.push_back("Eap_lift_path_angle") ; 
	supertypes.push_back("Eap_lift_path_tangent") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eparameterised_path" ,(StepNodeType) 1, (DWORD) &(this->Eparameterised_path::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "fix_point" ,(StepNodeType) 22, (DWORD) &(this->fix_point), "Ecartesian_point", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "fix_point_dir" ,(StepNodeType) 22, (DWORD) &(this->fix_point_dir), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eapproach_lift_path*/
////////////////////////////////////////////////////////////////////////////////
Eapproach_retract_strategy::Eapproach_retract_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eapproach_retract_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Eplunge_strategy") ; 
	supertypes.push_back("Eair_strategy") ; 
	supertypes.push_back("Ealong_path") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "tool_orientation" ,(StepNodeType) 22, (DWORD) &(this->tool_orientation), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eapproach_retract_strategy*/
////////////////////////////////////////////////////////////////////////////////
Eapproval::Eapproval(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eapproval";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "status" ,(StepNodeType) 22, (DWORD) &(this->status), "Eapproval_status", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "level" ,(StepNodeType) 22, (DWORD) &(this->level), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eapproval*/
////////////////////////////////////////////////////////////////////////////////
Eapproval_status::Eapproval_status(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eapproval_status";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eapproval_status*/
////////////////////////////////////////////////////////////////////////////////
Eassignment::Eassignment(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eassignment";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprogram_structure") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprogram_structure" ,(StepNodeType) 1, (DWORD) &(this->Eprogram_structure::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_lvalue" ,(StepNodeType) 22, (DWORD) &(this->its_lvalue), "Enc_variable", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_rvalue" ,(StepNodeType) 22, (DWORD) &(this->its_rvalue), "Ervalue", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eassignment*/
////////////////////////////////////////////////////////////////////////////////
Eaxis1_placement::Eaxis1_placement(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eaxis1_placement";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplacement") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplacement" ,(StepNodeType) 1, (DWORD) &(this->Eplacement::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axis" ,(StepNodeType) 22, (DWORD) &(this->axis), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eaxis1_placement*/
////////////////////////////////////////////////////////////////////////////////
Eaxis2_placement_3d::Eaxis2_placement_3d(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eaxis2_placement_3d";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eplacement") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplacement" ,(StepNodeType) 1, (DWORD) &(this->Eplacement::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axis" ,(StepNodeType) 22, (DWORD) &(this->axis), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "ref_direction" ,(StepNodeType) 22, (DWORD) &(this->ref_direction), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eaxis2_placement_3d*/
////////////////////////////////////////////////////////////////////////////////
Eaxis_trajectory::Eaxis_trajectory(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eaxis_trajectory";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etrajectory") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etrajectory" ,(StepNodeType) 1, (DWORD) &(this->Etrajectory::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axis_list" ,(StepNodeType) 13, (DWORD) &(this->axis_list), "EListT<EidentifierPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eidentifier");
	axis_list.ListClassname()="Eidentifier"; 
	axis_list.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "commands" ,(StepNodeType) 13, (DWORD) &(this->commands), "EListT<Ebounded_curvePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ebounded_curve");
	commands.ListClassname()="Ebounded_curve"; 
	commands.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eaxis_trajectory*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_curve::Eb_spline_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eb_spline_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebezier_curve") ; 
	supertypes.push_back("Eb_spline_curve_with_knots") ; 
	supertypes.push_back("Equasi_uniform_curve") ; 
	supertypes.push_back("Erational_b_spline_curve") ; 
	supertypes.push_back("Euniform_curve") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->Ebounded_curve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "degree" ,(StepNodeType) 3, (DWORD) &(this->degree), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "control_points_list" ,(StepNodeType) 13, (DWORD) &(this->control_points_list), "EListT<Ecartesian_pointPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecartesian_point");
	control_points_list.ListClassname()="Ecartesian_point"; 
	control_points_list.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "curve_form" ,(StepNodeType) 22, (DWORD) &(this->curve_form), "Eb_spline_curve_form", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "closed_curve" ,(StepNodeType) 8, (DWORD) &(this->closed_curve), "ELogical", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "self_intersect" ,(StepNodeType) 8, (DWORD) &(this->self_intersect), "ELogical", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eb_spline_curve*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_curve_with_knots::Eb_spline_curve_with_knots(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eb_spline_curve_with_knots";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_curve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "knot_multiplicities" ,(StepNodeType) 13, (DWORD) &(this->knot_multiplicities), "EListT<EIntegerPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  3, "EInteger");
	knot_multiplicities.ListClassname()="EInteger"; 
	knot_multiplicities.ListType()=(StepNodeType)  3; 
	vars.push_back(new CVarDef(this, "knots" ,(StepNodeType) 13, (DWORD) &(this->knots), "EListT<Eparameter_valuePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eparameter_value");
	knots.ListClassname()="Eparameter_value"; 
	knots.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "knot_spec" ,(StepNodeType) 22, (DWORD) &(this->knot_spec), "Eknot_type", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eb_spline_curve_with_knots*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_surface::Eb_spline_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eb_spline_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebezier_surface") ; 
	supertypes.push_back("Eb_spline_surface_with_knots") ; 
	supertypes.push_back("Equasi_uniform_surface") ; 
	supertypes.push_back("Erational_b_spline_surface") ; 
	supertypes.push_back("Euniform_surface") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebounded_surface" ,(StepNodeType) 1, (DWORD) &(this->Ebounded_surface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "u_degree" ,(StepNodeType) 3, (DWORD) &(this->u_degree), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "v_degree" ,(StepNodeType) 3, (DWORD) &(this->v_degree), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "control_points_list" ,(StepNodeType) 15, (DWORD) &(this->control_points_list), "std::vector< EListT<Ecartesian_pointPtr> >", 0));
	vars.back()->Init(2, (StepNodeType)  22, "Ecartesian_point");
	vars.push_back(new CVarDef(this, "surface_form" ,(StepNodeType) 22, (DWORD) &(this->surface_form), "Eb_spline_surface_form", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "u_closed" ,(StepNodeType) 8, (DWORD) &(this->u_closed), "ELogical", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "v_closed" ,(StepNodeType) 8, (DWORD) &(this->v_closed), "ELogical", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "self_intersect" ,(StepNodeType) 8, (DWORD) &(this->self_intersect), "ELogical", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eb_spline_surface*/
////////////////////////////////////////////////////////////////////////////////
Eb_spline_surface_with_knots::Eb_spline_surface_with_knots(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eb_spline_surface_with_knots";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_surface") ; 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_surface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "u_multiplicities" ,(StepNodeType) 13, (DWORD) &(this->u_multiplicities), "EListT<EIntegerPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  3, "EInteger");
	u_multiplicities.ListClassname()="EInteger"; 
	u_multiplicities.ListType()=(StepNodeType)  3; 
	vars.push_back(new CVarDef(this, "v_multiplicities" ,(StepNodeType) 13, (DWORD) &(this->v_multiplicities), "EListT<EIntegerPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  3, "EInteger");
	v_multiplicities.ListClassname()="EInteger"; 
	v_multiplicities.ListType()=(StepNodeType)  3; 
	vars.push_back(new CVarDef(this, "u_knots" ,(StepNodeType) 13, (DWORD) &(this->u_knots), "EListT<Eparameter_valuePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eparameter_value");
	u_knots.ListClassname()="Eparameter_value"; 
	u_knots.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "v_knots" ,(StepNodeType) 13, (DWORD) &(this->v_knots), "EListT<Eparameter_valuePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eparameter_value");
	v_knots.ListClassname()="Eparameter_value"; 
	v_knots.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "knot_spec" ,(StepNodeType) 22, (DWORD) &(this->knot_spec), "Eknot_type", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eb_spline_surface_with_knots*/
////////////////////////////////////////////////////////////////////////////////
Eback_boring::Eback_boring(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eback_boring";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eback_boring*/
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
////////////////////////////////////////////////////////////////////////////////
Ebezier_curve::Ebezier_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebezier_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_curve::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebezier_curve*/
////////////////////////////////////////////////////////////////////////////////
Ebezier_surface::Ebezier_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebezier_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_surface") ; 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_surface::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebezier_surface*/
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
////////////////////////////////////////////////////////////////////////////////
Ebinary_boolean_expression::Ebinary_boolean_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebinary_boolean_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	supertypes.push_back("Exor_expression") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Eboolean_expression::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "operand1" ,(StepNodeType) 22, (DWORD) &(this->operand1), "Eboolean_expression", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "operand2" ,(StepNodeType) 22, (DWORD) &(this->operand2), "Eboolean_expression", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ebinary_boolean_expression*/
////////////////////////////////////////////////////////////////////////////////
Eblind_bottom_condition::Eblind_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eblind_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ehole_bottom_condition") ; 
	supertypes.clear(); 
	supertypes.push_back("Eflat_hole_bottom") ; 
	supertypes.push_back("Eflat_with_radius_hole_bottom") ; 
	supertypes.push_back("Espherical_hole_bottom") ; 
	supertypes.push_back("Econical_hole_bottom") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ehole_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Ehole_bottom_condition::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eblind_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Eblock::Eblock(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eblock";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "position" ,(StepNodeType) 22, (DWORD) &(this->position), "Eaxis2_placement_3d", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "x" ,(StepNodeType) 22, (DWORD) &(this->x), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "y" ,(StepNodeType) 22, (DWORD) &(this->y), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "z" ,(StepNodeType) 22, (DWORD) &(this->z), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eblock*/
////////////////////////////////////////////////////////////////////////////////
Eboolean_expression::Eboolean_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eboolean_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Eunary_boolean_expression") ; 
	supertypes.push_back("Ebinary_boolean_expression") ; 
	supertypes.push_back("Emultiple_arity_boolean_expression") ; 
	supertypes.push_back("Ecomparison_expression") ; 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Eboolean_expression*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboring_operation" ,(StepNodeType) 1, (DWORD) &(this->Eboring_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eboring*/
////////////////////////////////////////////////////////////////////////////////
Eboring_operation::Eboring_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eboring_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Eboring") ; 
	supertypes.push_back("Ereaming") ; 
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
////////////////////////////////////////////////////////////////////////////////
Eboss::Eboss(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eboss";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_boundary" ,(StepNodeType) 22, (DWORD) &(this->its_boundary), "Eclosed_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "slope" ,(StepNodeType) 22, (DWORD) &(this->slope), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eboss*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebottom_and_side_milling" ,(StepNodeType) 1, (DWORD) &(this->Ebottom_and_side_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebottom_and_side_finish_milling*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebottom_and_side_rough_milling") ; 
	supertypes.push_back("Ebottom_and_side_finish_milling") ; 
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebottom_and_side_milling" ,(StepNodeType) 1, (DWORD) &(this->Ebottom_and_side_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebottom_and_side_rough_milling*/
////////////////////////////////////////////////////////////////////////////////
Ebounded_curve::Ebounded_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebounded_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Etrimmed_curve") ; 
	supertypes.push_back("Ecomposite_curve") ; 
	supertypes.push_back("Eb_spline_curve") ; 
	supertypes.push_back("Epolyline") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->Ecurve::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebounded_curve*/
////////////////////////////////////////////////////////////////////////////////
Ebounded_pcurve::Ebounded_pcurve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebounded_pcurve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epcurve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epcurve" ,(StepNodeType) 1, (DWORD) &(this->Epcurve::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebounded_pcurve*/
////////////////////////////////////////////////////////////////////////////////
Ebounded_surface::Ebounded_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebounded_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eb_spline_surface") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->Esurface::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ebounded_surface*/
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
////////////////////////////////////////////////////////////////////////////////
Ecalendar_date::Ecalendar_date(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecalendar_date";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edate") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edate" ,(StepNodeType) 1, (DWORD) &(this->Edate::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "day_component" ,(StepNodeType) 22, (DWORD) &(this->day_component), "Eday_in_month_number", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "month_component" ,(StepNodeType) 22, (DWORD) &(this->month_component), "Emonth_in_year_number", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecalendar_date*/
////////////////////////////////////////////////////////////////////////////////
Ecartesian_point::Ecartesian_point(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecartesian_point";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epoint") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epoint" ,(StepNodeType) 1, (DWORD) &(this->Epoint::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "coordinates" ,(StepNodeType) 13, (DWORD) &(this->coordinates), "EListT<Elength_measurePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Elength_measure");
	coordinates.ListClassname()="Elength_measure"; 
	coordinates.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Ecartesian_point*/
////////////////////////////////////////////////////////////////////////////////
Ecatalogue_thread::Ecatalogue_thread(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecatalogue_thread";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ethread") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ethread" ,(StepNodeType) 1, (DWORD) &(this->Ethread::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "documentation" ,(StepNodeType) 22, (DWORD) &(this->documentation), "Especification", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecatalogue_thread*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecenter_drilling*/
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
////////////////////////////////////////////////////////////////////////////////
Echamfer::Echamfer(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Echamfer";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etransition_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etransition_feature" ,(StepNodeType) 1, (DWORD) &(this->Etransition_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "angle_to_plane" ,(StepNodeType) 22, (DWORD) &(this->angle_to_plane), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "first_offset_amount" ,(StepNodeType) 22, (DWORD) &(this->first_offset_amount), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Echamfer*/
////////////////////////////////////////////////////////////////////////////////
Echannel::Echannel(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Echannel";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Echannel*/
////////////////////////////////////////////////////////////////////////////////
Ecircle::Ecircle(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecircle";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econic") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->Econic::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecircle*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_closed_profile::Ecircular_closed_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecircular_closed_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eclosed_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eclosed_profile" ,(StepNodeType) 1, (DWORD) &(this->Eclosed_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "diameter" ,(StepNodeType) 22, (DWORD) &(this->diameter), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecircular_closed_profile*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_closed_shape_profile::Ecircular_closed_shape_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecircular_closed_shape_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eshape_profile") ; 
	parents.push_back("Eprofile_feature") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eshape_profile" ,(StepNodeType) 1, (DWORD) &(this->Eshape_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "closed_boundary" ,(StepNodeType) 22, (DWORD) &(this->closed_boundary), "Ecircular_closed_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecircular_closed_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_offset::Ecircular_offset(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecircular_offset";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "angular_offset" ,(StepNodeType) 22, (DWORD) &(this->angular_offset), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "index" ,(StepNodeType) 3, (DWORD) &(this->index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecircular_offset*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_omit::Ecircular_omit(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecircular_omit";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "index" ,(StepNodeType) 3, (DWORD) &(this->index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecircular_omit*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_path::Ecircular_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecircular_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etravel_path") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecomplete_circular_path") ; 
	supertypes.push_back("Epartial_circular_path") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etravel_path" ,(StepNodeType) 1, (DWORD) &(this->Etravel_path::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecircular_path*/
////////////////////////////////////////////////////////////////////////////////
Ecircular_pattern::Ecircular_pattern(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecircular_pattern";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ereplicate_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ereplicate_feature" ,(StepNodeType) 1, (DWORD) &(this->Ereplicate_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "angle_increment" ,(StepNodeType) 22, (DWORD) &(this->angle_increment), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "number_of_feature" ,(StepNodeType) 3, (DWORD) &(this->number_of_feature), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "relocated_base_feature" ,(StepNodeType) 13, (DWORD) &(this->relocated_base_feature), "EListT<Ecircular_offsetPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecircular_offset");
	relocated_base_feature.ListClassname()="Ecircular_offset"; 
	relocated_base_feature.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "missing_base_feature" ,(StepNodeType) 13, (DWORD) &(this->missing_base_feature), "EListT<Ecircular_omitPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecircular_omit");
	missing_base_feature.ListClassname()="Ecircular_omit"; 
	missing_base_feature.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "base_feature_diameter" ,(StepNodeType) 22, (DWORD) &(this->base_feature_diameter), "Etoleranced_length_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "base_feature_rotation" ,(StepNodeType) 22, (DWORD) &(this->base_feature_rotation), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecircular_pattern*/
////////////////////////////////////////////////////////////////////////////////
Eclosed_pocket::Eclosed_pocket(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eclosed_pocket";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epocket") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epocket" ,(StepNodeType) 1, (DWORD) &(this->Epocket::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feature_boundary" ,(StepNodeType) 22, (DWORD) &(this->feature_boundary), "Eclosed_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eclosed_pocket*/
////////////////////////////////////////////////////////////////////////////////
Eclosed_profile::Eclosed_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eclosed_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	supertypes.push_back("Erectangular_closed_profile") ; 
	supertypes.push_back("Ecircular_closed_profile") ; 
	supertypes.push_back("Engon_profile") ; 
	supertypes.push_back("Egeneral_closed_profile") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprofile" ,(StepNodeType) 1, (DWORD) &(this->Eprofile::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eclosed_profile*/
////////////////////////////////////////////////////////////////////////////////
Eclosed_shell::Eclosed_shell(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eclosed_shell";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econnected_face_set") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econnected_face_set" ,(StepNodeType) 1, (DWORD) &(this->Econnected_face_set::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eclosed_shell*/
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
////////////////////////////////////////////////////////////////////////////////
Ecomparison_equal::Ecomparison_equal(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomparison_equal";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecomparison_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecomparison_expression" ,(StepNodeType) 1, (DWORD) &(this->Ecomparison_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecomparison_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_expression::Ecomparison_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomparison_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecomparison_equal") ; 
	supertypes.push_back("Ecomparison_not_equal") ; 
	supertypes.push_back("Ecomparison_greater") ; 
	supertypes.push_back("Ecomparison_greater_equal") ; 
	supertypes.push_back("Ecomparison_less") ; 
	supertypes.push_back("Ecomparison_less_equal") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Eboolean_expression::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "operand1" ,(StepNodeType) 22, (DWORD) &(this->operand1), "Enc_variable", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "operand2" ,(StepNodeType) 22, (DWORD) &(this->operand2), "Ervalue", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecomparison_expression*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_greater::Ecomparison_greater(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomparison_greater";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecomparison_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecomparison_expression" ,(StepNodeType) 1, (DWORD) &(this->Ecomparison_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecomparison_greater*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_greater_equal::Ecomparison_greater_equal(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomparison_greater_equal";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecomparison_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecomparison_expression" ,(StepNodeType) 1, (DWORD) &(this->Ecomparison_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecomparison_greater_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_less::Ecomparison_less(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomparison_less";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecomparison_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecomparison_expression" ,(StepNodeType) 1, (DWORD) &(this->Ecomparison_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecomparison_less*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_less_equal::Ecomparison_less_equal(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomparison_less_equal";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecomparison_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecomparison_expression" ,(StepNodeType) 1, (DWORD) &(this->Ecomparison_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecomparison_less_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomparison_not_equal::Ecomparison_not_equal(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomparison_not_equal";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecomparison_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecomparison_expression" ,(StepNodeType) 1, (DWORD) &(this->Ecomparison_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecomparison_not_equal*/
////////////////////////////////////////////////////////////////////////////////
Ecomplete_circular_path::Ecomplete_circular_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomplete_circular_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecircular_path") ; 
	parents.push_back("Etravel_path") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecircular_path" ,(StepNodeType) 1, (DWORD) &(this->Ecircular_path::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecomplete_circular_path*/
////////////////////////////////////////////////////////////////////////////////
Ecomposite_curve::Ecomposite_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomposite_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->Ebounded_curve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "segments" ,(StepNodeType) 13, (DWORD) &(this->segments), "EListT<Ecomposite_curve_segmentPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecomposite_curve_segment");
	segments.ListClassname()="Ecomposite_curve_segment"; 
	segments.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "self_intersect" ,(StepNodeType) 8, (DWORD) &(this->self_intersect), "ELogical", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecomposite_curve*/
////////////////////////////////////////////////////////////////////////////////
Ecomposite_curve_segment::Ecomposite_curve_segment(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecomposite_curve_segment";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "transition" ,(StepNodeType) 22, (DWORD) &(this->transition), "Etransition_code", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "same_sense" ,(StepNodeType) 7, (DWORD) &(this->same_sense), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "parent_curve" ,(StepNodeType) 22, (DWORD) &(this->parent_curve), "Ecurve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecomposite_curve_segment*/
////////////////////////////////////////////////////////////////////////////////
Ecompound_feature::Ecompound_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecompound_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecounterbore_hole") ; 
	supertypes.push_back("Ecountersunk_hole") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_manufacturing_feature" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_manufacturing_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "elements" ,(StepNodeType) 13, (DWORD) &(this->elements), "EListT<Ecompound_feature_selectPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecompound_feature_select");
	elements.ListClassname()="Ecompound_feature_select"; 
	elements.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Ecompound_feature*/
////////////////////////////////////////////////////////////////////////////////
Econic::Econic(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econic";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecircle") ; 
	supertypes.push_back("Eellipse") ; 
	supertypes.push_back("Ehyperbola") ; 
	supertypes.push_back("Eparabola") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->Ecurve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "position" ,(StepNodeType) 22, (DWORD) &(this->position), "Eaxis2_placement_3d", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Econic*/
////////////////////////////////////////////////////////////////////////////////
Econical_hole_bottom::Econical_hole_bottom(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econical_hole_bottom";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eblind_bottom_condition") ; 
	parents.push_back("Ehole_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eblind_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Eblind_bottom_condition::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "tip_angle" ,(StepNodeType) 22, (DWORD) &(this->tip_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "tip_radius" ,(StepNodeType) 22, (DWORD) &(this->tip_radius), "Etoleranced_length_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Econical_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Econnect_direct::Econnect_direct(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econnect_direct";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econnector") ; 
	parents.push_back("Eparameterised_path") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econnector" ,(StepNodeType) 1, (DWORD) &(this->Econnector::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Econnect_direct*/
////////////////////////////////////////////////////////////////////////////////
Econnect_secplane::Econnect_secplane(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econnect_secplane";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econnector") ; 
	parents.push_back("Eparameterised_path") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econnector" ,(StepNodeType) 1, (DWORD) &(this->Econnector::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "up_dir" ,(StepNodeType) 22, (DWORD) &(this->up_dir), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "down_dir" ,(StepNodeType) 22, (DWORD) &(this->down_dir), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Econnect_secplane*/
////////////////////////////////////////////////////////////////////////////////
Econnected_face_set::Econnected_face_set(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econnected_face_set";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eclosed_shell") ; 
	supertypes.push_back("Eopen_shell") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Etopological_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "cfs_faces" ,(StepNodeType) 13, (DWORD) &(this->cfs_faces), "EListT<EfacePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eface");
	cfs_faces.ListClassname()="Eface"; 
	cfs_faces.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Econnected_face_set*/
////////////////////////////////////////////////////////////////////////////////
Econnector::Econnector(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Econnector";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eparameterised_path") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	supertypes.push_back("Econnect_secplane") ; 
	supertypes.push_back("Econnect_direct") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eparameterised_path" ,(StepNodeType) 1, (DWORD) &(this->Eparameterised_path::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Econnector*/
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
////////////////////////////////////////////////////////////////////////////////
Ecoordinated_universal_time_offset::Ecoordinated_universal_time_offset(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecoordinated_universal_time_offset";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "hour_offset" ,(StepNodeType) 3, (DWORD) &(this->hour_offset), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "minute_offset" ,(StepNodeType) 3, (DWORD) &(this->minute_offset), "EInteger", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "sense" ,(StepNodeType) 22, (DWORD) &(this->sense), "Eahead_or_behind", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecoordinated_universal_time_offset*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecounter_sinking*/
////////////////////////////////////////////////////////////////////////////////
Ecounterbore::Ecounterbore(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecounterbore";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebackside_counterbore") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecounterbore*/
////////////////////////////////////////////////////////////////////////////////
Ecounterbore_hole::Ecounterbore_hole(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecounterbore_hole";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecompound_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecompound_feature" ,(StepNodeType) 1, (DWORD) &(this->Ecompound_feature::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecounterbore_hole*/
////////////////////////////////////////////////////////////////////////////////
Ecountersink::Ecountersink(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecountersink";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebackside_countersink") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "countersink_radius" ,(StepNodeType) 22, (DWORD) &(this->countersink_radius), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecountersink*/
////////////////////////////////////////////////////////////////////////////////
Ecountersunk_hole::Ecountersunk_hole(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecountersunk_hole";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecompound_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecompound_feature" ,(StepNodeType) 1, (DWORD) &(this->Ecompound_feature::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecountersunk_hole*/
////////////////////////////////////////////////////////////////////////////////
Ecurve::Ecurve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecurve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebounded_curve") ; 
	supertypes.push_back("Econic") ; 
	supertypes.push_back("Eline") ; 
	supertypes.push_back("Epcurve") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ecurve*/
////////////////////////////////////////////////////////////////////////////////
Ecurve_with_normal_vector::Ecurve_with_normal_vector(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecurve_with_normal_vector";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "basiccurve" ,(StepNodeType) 22, (DWORD) &(this->basiccurve), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "surface_normal" ,(StepNodeType) 22, (DWORD) &(this->surface_normal), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecurve_with_normal_vector*/
////////////////////////////////////////////////////////////////////////////////
Ecutter_contact_trajectory::Ecutter_contact_trajectory(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecutter_contact_trajectory";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etrajectory") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etrajectory" ,(StepNodeType) 1, (DWORD) &(this->Etrajectory::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "basiccurve" ,(StepNodeType) 22, (DWORD) &(this->basiccurve), "Ecurve_with_surface_normal", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_toolaxis" ,(StepNodeType) 22, (DWORD) &(this->its_toolaxis), "Ebounded_curve", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_contact_type" ,(StepNodeType) 22, (DWORD) &(this->its_contact_type), "Econtact_type", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecutter_contact_trajectory*/
////////////////////////////////////////////////////////////////////////////////
Ecutter_location_trajectory::Ecutter_location_trajectory(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecutter_location_trajectory";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etrajectory") ; 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etrajectory" ,(StepNodeType) 1, (DWORD) &(this->Etrajectory::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "basiccurve" ,(StepNodeType) 22, (DWORD) &(this->basiccurve), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_toolaxis" ,(StepNodeType) 22, (DWORD) &(this->its_toolaxis), "Ebounded_curve", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "surface_normal" ,(StepNodeType) 22, (DWORD) &(this->surface_normal), "Ebounded_curve", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecutter_location_trajectory*/
////////////////////////////////////////////////////////////////////////////////
Ecutting_component::Ecutting_component(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecutting_component";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "tool_offset_length" ,(StepNodeType) 22, (DWORD) &(this->tool_offset_length), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_material" ,(StepNodeType) 22, (DWORD) &(this->its_material), "Ematerial", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "technological_data" ,(StepNodeType) 22, (DWORD) &(this->technological_data), "Ecutting_edge_technological_data", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "expected_tool_life" ,(StepNodeType) 22, (DWORD) &(this->expected_tool_life), "Etime_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_technology" ,(StepNodeType) 22, (DWORD) &(this->its_technology), "Emilling_technology", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecutting_component*/
////////////////////////////////////////////////////////////////////////////////
Ecutting_edge_technological_data::Ecutting_edge_technological_data(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecutting_edge_technological_data";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "cutting_angle" ,(StepNodeType) 22, (DWORD) &(this->cutting_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "free_angle" ,(StepNodeType) 22, (DWORD) &(this->free_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "aux_angle" ,(StepNodeType) 22, (DWORD) &(this->aux_angle), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecutting_edge_technological_data*/
////////////////////////////////////////////////////////////////////////////////
Ecutting_tool::Ecutting_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecutting_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_tool") ; 
	supertypes.clear(); 
	supertypes.push_back("Emilling_cutting_tool") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_tool" ,(StepNodeType) 1, (DWORD) &(this->Emachining_tool::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_tool_body" ,(StepNodeType) 22, (DWORD) &(this->its_tool_body), "Etool_body", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_cutting_edge" ,(StepNodeType) 13, (DWORD) &(this->its_cutting_edge), "EListT<Ecutting_componentPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecutting_component");
	its_cutting_edge.ListClassname()="Ecutting_component"; 
	its_cutting_edge.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "overall_assembly_length" ,(StepNodeType) 22, (DWORD) &(this->overall_assembly_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ecutting_tool*/
////////////////////////////////////////////////////////////////////////////////
Edate::Edate(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edate";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Ecalendar_date") ; 
	supertypes.push_back("Eordinal_date") ; 
	supertypes.push_back("Eweek_of_year_and_day_date") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "year_component" ,(StepNodeType) 22, (DWORD) &(this->year_component), "Eyear_number", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edate*/
////////////////////////////////////////////////////////////////////////////////
Edate_and_time::Edate_and_time(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edate_and_time";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "date_component" ,(StepNodeType) 22, (DWORD) &(this->date_component), "Edate", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "time_component" ,(StepNodeType) 22, (DWORD) &(this->time_component), "Elocal_time", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edate_and_time*/
////////////////////////////////////////////////////////////////////////////////
Edefined_thread::Edefined_thread(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edefined_thread";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ethread") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ethread" ,(StepNodeType) 1, (DWORD) &(this->Ethread::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "pitch_diameter" ,(StepNodeType) 22, (DWORD) &(this->pitch_diameter), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "minor_diameter" ,(StepNodeType) 22, (DWORD) &(this->minor_diameter), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "crest" ,(StepNodeType) 22, (DWORD) &(this->crest), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edefined_thread*/
////////////////////////////////////////////////////////////////////////////////
Edefinitional_representation::Edefinitional_representation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edefinitional_representation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Erepresentation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Erepresentation" ,(StepNodeType) 1, (DWORD) &(this->Erepresentation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Edefinitional_representation*/
////////////////////////////////////////////////////////////////////////////////
Edescriptive_parameter::Edescriptive_parameter(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edescriptive_parameter";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eproperty_parameter") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eproperty_parameter" ,(StepNodeType) 1, (DWORD) &(this->Eproperty_parameter::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "descriptive_string" ,(StepNodeType) 22, (DWORD) &(this->descriptive_string), "Etext", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edescriptive_parameter*/
////////////////////////////////////////////////////////////////////////////////
Ediameter_taper::Ediameter_taper(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ediameter_taper";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "final_diameter" ,(StepNodeType) 22, (DWORD) &(this->final_diameter), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ediameter_taper*/
////////////////////////////////////////////////////////////////////////////////
Edirection::Edirection(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edirection";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "direction_ratios" ,(StepNodeType) 13, (DWORD) &(this->direction_ratios), "EListT<ERealPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  4, "EReal");
	direction_ratios.ListClassname()="EReal"; 
	direction_ratios.ListType()=(StepNodeType)  4; 
	BuildInstanceDef(vars, instancevars);
} /* End Edirection*/
////////////////////////////////////////////////////////////////////////////////
Edisplay_message::Edisplay_message(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edisplay_message";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_text" ,(StepNodeType) 22, (DWORD) &(this->its_text), "Etext", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Edisplay_message*/
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
////////////////////////////////////////////////////////////////////////////////
Edrill::Edrill(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrill";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	supertypes.push_back("Etwist_drill") ; 
	supertypes.push_back("Espade_drill") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Edrill*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Edrilling*/
////////////////////////////////////////////////////////////////////////////////
Edrilling_operation::Edrilling_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrilling_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Edrilling") ; 
	supertypes.push_back("Ecenter_drilling") ; 
	supertypes.push_back("Ecounter_sinking") ; 
	supertypes.push_back("Emultistep_drilling") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Edrilling_operation*/
////////////////////////////////////////////////////////////////////////////////
Edrilling_type_operation::Edrilling_type_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Edrilling_type_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Edrilling_operation") ; 
	supertypes.push_back("Eboring_operation") ; 
	supertypes.push_back("Eback_boring") ; 
	supertypes.push_back("Etapping") ; 
	supertypes.push_back("Ethread_drilling") ; 
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
////////////////////////////////////////////////////////////////////////////////
Eedge::Eedge(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eedge";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eedge_curve") ; 
	supertypes.push_back("Eoriented_edge") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Etopological_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "edge_start" ,(StepNodeType) 22, (DWORD) &(this->edge_start), "Evertex", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "edge_end" ,(StepNodeType) 22, (DWORD) &(this->edge_end), "Evertex", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eedge*/
////////////////////////////////////////////////////////////////////////////////
Eedge_curve::Eedge_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eedge_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eedge") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eedge" ,(StepNodeType) 1, (DWORD) &(this->Eedge::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "edge_geometry" ,(StepNodeType) 22, (DWORD) &(this->edge_geometry), "Ecurve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "same_sense" ,(StepNodeType) 7, (DWORD) &(this->same_sense), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eedge_curve*/
////////////////////////////////////////////////////////////////////////////////
Eedge_loop::Eedge_loop(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eedge_loop";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eloop") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eloop" ,(StepNodeType) 1, (DWORD) &(this->Eloop::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eedge_loop*/
////////////////////////////////////////////////////////////////////////////////
Eedge_round::Eedge_round(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eedge_round";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etransition_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etransition_feature" ,(StepNodeType) 1, (DWORD) &(this->Etransition_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "first_offset_amount" ,(StepNodeType) 22, (DWORD) &(this->first_offset_amount), "Etoleranced_length_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "second_offset_amount" ,(StepNodeType) 22, (DWORD) &(this->second_offset_amount), "Etoleranced_length_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eedge_round*/
////////////////////////////////////////////////////////////////////////////////
Eelementary_surface::Eelementary_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eelementary_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eplane") ; 
	supertypes.push_back("Espherical_surface") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->Esurface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "position" ,(StepNodeType) 22, (DWORD) &(this->position), "Eaxis2_placement_3d", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eelementary_surface*/
////////////////////////////////////////////////////////////////////////////////
Eellipse::Eellipse(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eellipse";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econic") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->Econic::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "semi_axis_1" ,(StepNodeType) 22, (DWORD) &(this->semi_axis_1), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "semi_axis_2" ,(StepNodeType) 22, (DWORD) &(this->semi_axis_2), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eellipse*/
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
	supertypes.push_back("Etapered_endmill") ; 
	supertypes.push_back("Eball_endmill") ; 
	supertypes.push_back("Ebullnose_endmill") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_cutter" ,(StepNodeType) 1, (DWORD) &(this->Emilling_cutter::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eendmill*/
////////////////////////////////////////////////////////////////////////////////
Eexchange_pallet::Eexchange_pallet(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eexchange_pallet";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eexchange_pallet*/
////////////////////////////////////////////////////////////////////////////////
Eexecutable::Eexecutable(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eexecutable";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Eworkingstep") ; 
	supertypes.push_back("Enc_function") ; 
	supertypes.push_back("Eprogram_structure") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eexecutable*/
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
////////////////////////////////////////////////////////////////////////////////
Eface::Eface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eface_surface") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Etopological_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "bounds" ,(StepNodeType) 13, (DWORD) &(this->bounds), "EListT<Eface_boundPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eface_bound");
	bounds.ListClassname()="Eface_bound"; 
	bounds.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eface*/
////////////////////////////////////////////////////////////////////////////////
Eface_bound::Eface_bound(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eface_bound";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eface_outer_bound") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Etopological_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "bound" ,(StepNodeType) 22, (DWORD) &(this->bound), "Eloop", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eface_bound*/
////////////////////////////////////////////////////////////////////////////////
Eface_outer_bound::Eface_outer_bound(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eface_outer_bound";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eface_bound") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eface_bound" ,(StepNodeType) 1, (DWORD) &(this->Eface_bound::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eface_outer_bound*/
////////////////////////////////////////////////////////////////////////////////
Eface_surface::Eface_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eface_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eface") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eadvanced_face") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eface" ,(StepNodeType) 1, (DWORD) &(this->Eface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "face_geometry" ,(StepNodeType) 22, (DWORD) &(this->face_geometry), "Esurface", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "same_sense" ,(StepNodeType) 7, (DWORD) &(this->same_sense), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eface_surface*/
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
////////////////////////////////////////////////////////////////////////////////
Efeedstop::Efeedstop(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efeedstop";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etoolpath" ,(StepNodeType) 1, (DWORD) &(this->Etoolpath::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "dwell" ,(StepNodeType) 22, (DWORD) &(this->dwell), "Etime_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Efeedstop*/
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
////////////////////////////////////////////////////////////////////////////////
Eflat_hole_bottom::Eflat_hole_bottom(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eflat_hole_bottom";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eblind_bottom_condition") ; 
	parents.push_back("Ehole_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eblind_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Eblind_bottom_condition::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eflat_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Eflat_slot_end_type::Eflat_slot_end_type(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eflat_slot_end_type";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eslot_end_type") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eslot_end_type" ,(StepNodeType) 1, (DWORD) &(this->Eslot_end_type::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "corner_radius1" ,(StepNodeType) 22, (DWORD) &(this->corner_radius1), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "corner_radius2" ,(StepNodeType) 22, (DWORD) &(this->corner_radius2), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eflat_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Eflat_with_radius_hole_bottom::Eflat_with_radius_hole_bottom(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eflat_with_radius_hole_bottom";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eblind_bottom_condition") ; 
	parents.push_back("Ehole_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eblind_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Eblind_bottom_condition::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "corner_radius" ,(StepNodeType) 22, (DWORD) &(this->corner_radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eflat_with_radius_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Efreeform_operation::Efreeform_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efreeform_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Emilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_machining_strategy" ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy), "Efreeform_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Efreeform_operation*/
////////////////////////////////////////////////////////////////////////////////
Efreeform_strategy::Efreeform_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efreeform_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Euv_strategy") ; 
	supertypes.push_back("Eplane_cc_strategy") ; 
	supertypes.push_back("Eplane_cl_strategy") ; 
	supertypes.push_back("Eleading_line_strategy") ; 
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
////////////////////////////////////////////////////////////////////////////////
Egeneral_closed_profile::Egeneral_closed_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_closed_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eclosed_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eclosed_profile" ,(StepNodeType) 1, (DWORD) &(this->Eclosed_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "closed_profile_shape" ,(StepNodeType) 22, (DWORD) &(this->closed_profile_shape), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_closed_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_outside_profile::Egeneral_outside_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_outside_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprofile_feature") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprofile_feature" ,(StepNodeType) 1, (DWORD) &(this->Eprofile_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feature_boundary" ,(StepNodeType) 22, (DWORD) &(this->feature_boundary), "Eprofile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_outside_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_path::Egeneral_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etravel_path") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etravel_path" ,(StepNodeType) 1, (DWORD) &(this->Etravel_path::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "swept_path" ,(StepNodeType) 22, (DWORD) &(this->swept_path), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_path*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_pattern::Egeneral_pattern(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_pattern";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ereplicate_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ereplicate_feature" ,(StepNodeType) 1, (DWORD) &(this->Ereplicate_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "replicate_locations" ,(StepNodeType) 13, (DWORD) &(this->replicate_locations), "EListT<Eaxis2_placement_3dPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eaxis2_placement_3d");
	replicate_locations.ListClassname()="Eaxis2_placement_3d"; 
	replicate_locations.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_pattern*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_pocket_bottom_condition::Egeneral_pocket_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_pocket_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epocket_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epocket_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Epocket_bottom_condition::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "shape" ,(StepNodeType) 22, (DWORD) &(this->shape), "Eregion", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_profile::Egeneral_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eopen_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eopen_profile" ,(StepNodeType) 1, (DWORD) &(this->Eopen_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_profile" ,(StepNodeType) 22, (DWORD) &(this->its_profile), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_profile_floor::Egeneral_profile_floor(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_profile_floor";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprofile_floor") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprofile_floor" ,(StepNodeType) 1, (DWORD) &(this->Eprofile_floor::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "floor" ,(StepNodeType) 22, (DWORD) &(this->floor), "Eface", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_profile_floor*/
////////////////////////////////////////////////////////////////////////////////
Egeneral_shape_profile::Egeneral_shape_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeneral_shape_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eshape_profile") ; 
	parents.push_back("Eprofile_feature") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eshape_profile" ,(StepNodeType) 1, (DWORD) &(this->Eshape_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "profile_boundary" ,(StepNodeType) 22, (DWORD) &(this->profile_boundary), "Eprofile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeneral_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_representation_context::Egeometric_representation_context(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeometric_representation_context";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Erepresentation_context") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Erepresentation_context" ,(StepNodeType) 1, (DWORD) &(this->Erepresentation_context::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "coordinate_space_dimension" ,(StepNodeType) 22, (DWORD) &(this->coordinate_space_dimension), "Edimension_count", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Egeometric_representation_context*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_representation_item::Egeometric_representation_item(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Egeometric_representation_item";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecurve") ; 
	supertypes.push_back("Edirection") ; 
	supertypes.push_back("Eplacement") ; 
	supertypes.push_back("Epoint") ; 
	supertypes.push_back("Esurface") ; 
	supertypes.push_back("Evector") ; 
	supertypes.push_back("Eblock") ; 
	supertypes.push_back("Eright_circular_cylinder") ; 
	supertypes.push_back("Esolid_model") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Erepresentation_item" ,(StepNodeType) 1, (DWORD) &(this->Erepresentation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Egeometric_representation_item*/
////////////////////////////////////////////////////////////////////////////////
Ehole_bottom_condition::Ehole_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ehole_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Ethrough_bottom_condition") ; 
	supertypes.push_back("Eblind_bottom_condition") ; 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Ehole_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Ehyperbola::Ehyperbola(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ehyperbola";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econic") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->Econic::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "semi_axis" ,(StepNodeType) 22, (DWORD) &(this->semi_axis), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "semi_imag_axis" ,(StepNodeType) 22, (DWORD) &(this->semi_imag_axis), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ehyperbola*/
////////////////////////////////////////////////////////////////////////////////
Eif_statement::Eif_statement(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eif_statement";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprogram_structure") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprogram_structure" ,(StepNodeType) 1, (DWORD) &(this->Eprogram_structure::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "condition" ,(StepNodeType) 22, (DWORD) &(this->condition), "Eboolean_expression", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "true_branch" ,(StepNodeType) 22, (DWORD) &(this->true_branch), "Eexecutable", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "false_branch" ,(StepNodeType) 22, (DWORD) &(this->false_branch), "Eexecutable", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eif_statement*/
////////////////////////////////////////////////////////////////////////////////
Ein_process_geometry::Ein_process_geometry(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ein_process_geometry";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "as_is" ,(StepNodeType) 22, (DWORD) &(this->as_is), "Eadvanced_brep_shape_representation", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "to_be" ,(StepNodeType) 22, (DWORD) &(this->to_be), "Eadvanced_brep_shape_representation", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "removal" ,(StepNodeType) 22, (DWORD) &(this->removal), "Eadvanced_brep_shape_representation", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ein_process_geometry*/
////////////////////////////////////////////////////////////////////////////////
Eindex_pallet::Eindex_pallet(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eindex_pallet";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_index" ,(StepNodeType) 3, (DWORD) &(this->its_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eindex_pallet*/
////////////////////////////////////////////////////////////////////////////////
Eindex_table::Eindex_table(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eindex_table";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_index" ,(StepNodeType) 3, (DWORD) &(this->its_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eindex_table*/
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
////////////////////////////////////////////////////////////////////////////////
Elimits_and_fits::Elimits_and_fits(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Elimits_and_fits";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "deviation" ,(StepNodeType) 22, (DWORD) &(this->deviation), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "grade" ,(StepNodeType) 22, (DWORD) &(this->grade), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_fitting_type" ,(StepNodeType) 22, (DWORD) &(this->its_fitting_type), "Efitting_type", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Elimits_and_fits*/
////////////////////////////////////////////////////////////////////////////////
Eline::Eline(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eline";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->Ecurve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "pnt" ,(StepNodeType) 22, (DWORD) &(this->pnt), "Ecartesian_point", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "dir" ,(StepNodeType) 22, (DWORD) &(this->dir), "Evector", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eline*/
////////////////////////////////////////////////////////////////////////////////
Elinear_path::Elinear_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Elinear_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etravel_path") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etravel_path" ,(StepNodeType) 1, (DWORD) &(this->Etravel_path::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "distance" ,(StepNodeType) 22, (DWORD) &(this->distance), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_direction" ,(StepNodeType) 22, (DWORD) &(this->its_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Elinear_path*/
////////////////////////////////////////////////////////////////////////////////
Elinear_profile::Elinear_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Elinear_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eopen_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eopen_profile" ,(StepNodeType) 1, (DWORD) &(this->Eopen_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "profile_length" ,(StepNodeType) 22, (DWORD) &(this->profile_length), "Enumeric_parameter", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Elinear_profile*/
////////////////////////////////////////////////////////////////////////////////
Eload_tool::Eload_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eload_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_tool" ,(StepNodeType) 22, (DWORD) &(this->its_tool), "Emachining_tool", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eload_tool*/
////////////////////////////////////////////////////////////////////////////////
Elocal_time::Elocal_time(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Elocal_time";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "hour_component" ,(StepNodeType) 22, (DWORD) &(this->hour_component), "Ehour_in_day", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "minute_component" ,(StepNodeType) 22, (DWORD) &(this->minute_component), "Eminute_in_hour", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "second_component" ,(StepNodeType) 22, (DWORD) &(this->second_component), "Esecond_in_minute", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "zone" ,(StepNodeType) 22, (DWORD) &(this->zone), "Ecoordinated_universal_time_offset", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Elocal_time*/
////////////////////////////////////////////////////////////////////////////////
Eloop::Eloop(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eloop";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eedge_loop") ; 
	supertypes.push_back("Evertex_loop") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Etopological_representation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eloop*/
////////////////////////////////////////////////////////////////////////////////
Eloop_slot_end_type::Eloop_slot_end_type(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eloop_slot_end_type";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eslot_end_type") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eslot_end_type" ,(StepNodeType) 1, (DWORD) &(this->Eslot_end_type::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eloop_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Emachine_functions::Emachine_functions(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emachine_functions";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Emilling_machine_functions") ; 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Emachine_functions*/
////////////////////////////////////////////////////////////////////////////////
Emachined_surface::Emachined_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emachined_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_machining_feature" ,(StepNodeType) 22, (DWORD) &(this->its_machining_feature), "Emachining_feature", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "surface_element" ,(StepNodeType) 22, (DWORD) &(this->surface_element), "Ebottom_or_side", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emachined_surface*/
////////////////////////////////////////////////////////////////////////////////
Emachining_feature::Emachining_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emachining_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Eplanar_face") ; 
	supertypes.push_back("Epocket") ; 
	supertypes.push_back("Eslot") ; 
	supertypes.push_back("Estep") ; 
	supertypes.push_back("Eprofile_feature") ; 
	supertypes.push_back("Eround_hole") ; 
	supertypes.push_back("Etoolpath_feature") ; 
	supertypes.push_back("Eboss") ; 
	supertypes.push_back("Espherical_cap") ; 
	supertypes.push_back("Erounded_end") ; 
	supertypes.push_back("Ethread") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_manufacturing_feature" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_manufacturing_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "depth" ,(StepNodeType) 22, (DWORD) &(this->depth), "Eelementary_surface", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emachining_feature*/
////////////////////////////////////////////////////////////////////////////////
Emachining_operation::Emachining_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emachining_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Emilling_machining_operation") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eoperation" ,(StepNodeType) 1, (DWORD) &(this->Eoperation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "retract_plane" ,(StepNodeType) 22, (DWORD) &(this->retract_plane), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "start_point" ,(StepNodeType) 22, (DWORD) &(this->start_point), "Ecartesian_point", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_tool" ,(StepNodeType) 22, (DWORD) &(this->its_tool), "Emachining_tool", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_technology" ,(StepNodeType) 22, (DWORD) &(this->its_technology), "Etechnology", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_machine_functions" ,(StepNodeType) 22, (DWORD) &(this->its_machine_functions), "Emachine_functions", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emachining_operation*/
////////////////////////////////////////////////////////////////////////////////
Emachining_tool::Emachining_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emachining_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Ecutting_tool") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emachining_tool*/
////////////////////////////////////////////////////////////////////////////////
Emachining_workingstep::Emachining_workingstep(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emachining_workingstep";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eworkingstep" ,(StepNodeType) 1, (DWORD) &(this->Eworkingstep::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_feature" ,(StepNodeType) 22, (DWORD) &(this->its_feature), "Emanufacturing_feature", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_operation" ,(StepNodeType) 22, (DWORD) &(this->its_operation), "Emachining_operation", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_effect" ,(StepNodeType) 22, (DWORD) &(this->its_effect), "Ein_process_geometry", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emachining_workingstep*/
////////////////////////////////////////////////////////////////////////////////
Emanifold_solid_brep::Emanifold_solid_brep(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emanifold_solid_brep";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Esolid_model") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Esolid_model" ,(StepNodeType) 1, (DWORD) &(this->Esolid_model::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "outer" ,(StepNodeType) 22, (DWORD) &(this->outer), "Eclosed_shell", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emanifold_solid_brep*/
////////////////////////////////////////////////////////////////////////////////
Emanufacturing_feature::Emanufacturing_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emanufacturing_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Eregion") ; 
	supertypes.push_back("Etwo5d_manufacturing_feature") ; 
	supertypes.push_back("Etransition_feature") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_workpiece" ,(StepNodeType) 22, (DWORD) &(this->its_workpiece), "Eworkpiece", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_operations" ,(StepNodeType) 13, (DWORD) &(this->its_operations), "EListT<Emachining_operationPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Emachining_operation");
	its_operations.ListClassname()="Emachining_operation"; 
	its_operations.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Emanufacturing_feature*/
////////////////////////////////////////////////////////////////////////////////
Ematerial::Ematerial(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ematerial";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "standard_identifier" ,(StepNodeType) 22, (DWORD) &(this->standard_identifier), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "material_identifier" ,(StepNodeType) 22, (DWORD) &(this->material_identifier), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "material_property" ,(StepNodeType) 13, (DWORD) &(this->material_property), "EListT<Eproperty_parameterPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eproperty_parameter");
	material_property.ListClassname()="Eproperty_parameter"; 
	material_property.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Ematerial*/
////////////////////////////////////////////////////////////////////////////////
Emilling_cutter::Emilling_cutter(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_cutter";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	supertypes.push_back("Efacemill") ; 
	supertypes.push_back("Eendmill") ; 
	supertypes.push_back("Et_slot_mill") ; 
	supertypes.push_back("Edovetail_mill") ; 
	supertypes.push_back("Ewoodruff_keyseat_mill") ; 
	supertypes.push_back("Eside_mill") ; 
	supertypes.push_back("Ethread_mill") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_cutter*/
////////////////////////////////////////////////////////////////////////////////
Emilling_cutting_tool::Emilling_cutting_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_cutting_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecutting_tool") ; 
	parents.push_back("Emachining_tool") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecutting_tool" ,(StepNodeType) 1, (DWORD) &(this->Ecutting_tool::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "direction_for_spindle_orientation" ,(StepNodeType) 22, (DWORD) &(this->direction_for_spindle_orientation), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "tool_holder_diameter_for_spindle_orientation" ,(StepNodeType) 22, (DWORD) &(this->tool_holder_diameter_for_spindle_orientation), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_cutting_tool*/
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
	vars.push_back(new CVarDef(this, "axis_clamping" ,(StepNodeType) 13, (DWORD) &(this->axis_clamping), "EListT<EidentifierPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eidentifier");
	axis_clamping.ListClassname()="Eidentifier"; 
	axis_clamping.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "chip_removal" ,(StepNodeType) 7, (DWORD) &(this->chip_removal), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "oriented_spindle_stop" ,(StepNodeType) 22, (DWORD) &(this->oriented_spindle_stop), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_process_model" ,(StepNodeType) 22, (DWORD) &(this->its_process_model), "Eprocess_model_list", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "other_functions" ,(StepNodeType) 13, (DWORD) &(this->other_functions), "EListT<Eproperty_parameterPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eproperty_parameter");
	other_functions.ListClassname()="Eproperty_parameter"; 
	other_functions.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_machine_functions*/
////////////////////////////////////////////////////////////////////////////////
Emilling_machining_operation::Emilling_machining_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_machining_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Emilling_type_operation") ; 
	supertypes.push_back("Edrilling_type_operation") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_operation" ,(StepNodeType) 1, (DWORD) &(this->Emachining_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "overcut_length" ,(StepNodeType) 22, (DWORD) &(this->overcut_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_machining_operation*/
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
////////////////////////////////////////////////////////////////////////////////
Emilling_tool_body::Emilling_tool_body(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_tool_body";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecenter_drill") ; 
	supertypes.push_back("Ecountersink") ; 
	supertypes.push_back("Edrill") ; 
	supertypes.push_back("Emilling_cutter") ; 
	supertypes.push_back("Etap") ; 
	supertypes.push_back("Ethreading_tool") ; 
	supertypes.push_back("Ecounterbore") ; 
	supertypes.push_back("Ereamer") ; 
	supertypes.push_back("Eboring_tool") ; 
	supertypes.push_back("Euser_defined_tool") ; 
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
////////////////////////////////////////////////////////////////////////////////
Emilling_type_operation::Emilling_type_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emilling_type_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Efreeform_operation") ; 
	supertypes.push_back("Etwo5d_milling_operation") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_machining_operation" ,(StepNodeType) 1, (DWORD) &(this->Emilling_machining_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "approach" ,(StepNodeType) 22, (DWORD) &(this->approach), "Eapproach_retract_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "retract" ,(StepNodeType) 22, (DWORD) &(this->retract), "Eapproach_retract_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Emilling_type_operation*/
////////////////////////////////////////////////////////////////////////////////
Emultiple_arity_boolean_expression::Emultiple_arity_boolean_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Emultiple_arity_boolean_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	supertypes.push_back("Eand_expression") ; 
	supertypes.push_back("Eor_expression") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Eboolean_expression::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "operands" ,(StepNodeType) 13, (DWORD) &(this->operands), "EListT<Eboolean_expressionPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eboolean_expression");
	operands.ListClassname()="Eboolean_expression"; 
	operands.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Emultiple_arity_boolean_expression*/
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
	parents.push_back("Eoperation") ; 
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
////////////////////////////////////////////////////////////////////////////////
Enc_constant::Enc_constant(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Enc_constant";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_name" ,(StepNodeType) 22, (DWORD) &(this->its_name), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_value" ,(StepNodeType) 22, (DWORD) &(this->its_value), "Enumber", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Enc_constant*/
////////////////////////////////////////////////////////////////////////////////
Enc_function::Enc_function(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Enc_function";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	supertypes.push_back("Edisplay_message") ; 
	supertypes.push_back("Eoptional_stop") ; 
	supertypes.push_back("Eprogram_stop") ; 
	supertypes.push_back("Eset_mark") ; 
	supertypes.push_back("Ewait_for_mark") ; 
	supertypes.push_back("Eexchange_pallet") ; 
	supertypes.push_back("Eindex_pallet") ; 
	supertypes.push_back("Eindex_table") ; 
	supertypes.push_back("Eload_tool") ; 
	supertypes.push_back("Eunload_tool") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eexecutable" ,(StepNodeType) 1, (DWORD) &(this->Eexecutable::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Enc_function*/
////////////////////////////////////////////////////////////////////////////////
Enc_variable::Enc_variable(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Enc_variable";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_name" ,(StepNodeType) 22, (DWORD) &(this->its_name), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "initial_value" ,(StepNodeType) 22, (DWORD) &(this->initial_value), "Enumber", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Enc_variable*/
////////////////////////////////////////////////////////////////////////////////
Engon_profile::Engon_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Engon_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eclosed_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eclosed_profile" ,(StepNodeType) 1, (DWORD) &(this->Eclosed_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "diameter" ,(StepNodeType) 22, (DWORD) &(this->diameter), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "number_of_sides" ,(StepNodeType) 3, (DWORD) &(this->number_of_sides), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "circumscribed_or_across_flats" ,(StepNodeType) 7, (DWORD) &(this->circumscribed_or_across_flats), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Engon_profile*/
////////////////////////////////////////////////////////////////////////////////
Enon_sequential::Enon_sequential(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Enon_sequential";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprogram_structure") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprogram_structure" ,(StepNodeType) 1, (DWORD) &(this->Eprogram_structure::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_elements" ,(StepNodeType) 13, (DWORD) &(this->its_elements), "EListT<EexecutablePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eexecutable");
	its_elements.ListClassname()="Eexecutable"; 
	its_elements.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Enon_sequential*/
////////////////////////////////////////////////////////////////////////////////
Enot_expression::Enot_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Enot_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eunary_boolean_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eunary_boolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Eunary_boolean_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Enot_expression*/
////////////////////////////////////////////////////////////////////////////////
Enumeric_parameter::Enumeric_parameter(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Enumeric_parameter";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eproperty_parameter") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eproperty_parameter" ,(StepNodeType) 1, (DWORD) &(this->Eproperty_parameter::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_parameter_value" ,(StepNodeType) 22, (DWORD) &(this->its_parameter_value), "Eparameter_value", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_parameter_unit" ,(StepNodeType) 22, (DWORD) &(this->its_parameter_unit), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Enumeric_parameter*/
////////////////////////////////////////////////////////////////////////////////
Eoffset_vector::Eoffset_vector(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eoffset_vector";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "translate" ,(StepNodeType) 13, (DWORD) &(this->translate), "EListT<Enc_variablePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Enc_variable");
	translate.ListClassname()="Enc_variable"; 
	translate.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "rotate" ,(StepNodeType) 13, (DWORD) &(this->rotate), "EListT<Enc_variablePtr>", 1));
	vars.back()->Init(1, (StepNodeType)  22, "Enc_variable");
	rotate.ListClassname()="Enc_variable"; 
	rotate.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eoffset_vector*/
////////////////////////////////////////////////////////////////////////////////
Eopen_pocket::Eopen_pocket(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eopen_pocket";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epocket") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epocket" ,(StepNodeType) 1, (DWORD) &(this->Epocket::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "open_boundary" ,(StepNodeType) 22, (DWORD) &(this->open_boundary), "Eopen_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "wall_boundary" ,(StepNodeType) 22, (DWORD) &(this->wall_boundary), "Eopen_profile", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eopen_pocket*/
////////////////////////////////////////////////////////////////////////////////
Eopen_profile::Eopen_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eopen_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	supertypes.push_back("Elinear_profile") ; 
	supertypes.push_back("Esquare_u_profile") ; 
	supertypes.push_back("Erounded_u_profile") ; 
	supertypes.push_back("Etee_profile") ; 
	supertypes.push_back("Evee_profile") ; 
	supertypes.push_back("Epartial_circular_profile") ; 
	supertypes.push_back("Egeneral_profile") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprofile" ,(StepNodeType) 1, (DWORD) &(this->Eprofile::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eopen_profile*/
////////////////////////////////////////////////////////////////////////////////
Eopen_shell::Eopen_shell(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eopen_shell";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econnected_face_set") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econnected_face_set" ,(StepNodeType) 1, (DWORD) &(this->Econnected_face_set::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eopen_shell*/
////////////////////////////////////////////////////////////////////////////////
Eopen_slot_end_type::Eopen_slot_end_type(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eopen_slot_end_type";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eslot_end_type") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eslot_end_type" ,(StepNodeType) 1, (DWORD) &(this->Eslot_end_type::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eopen_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Eoperation::Eoperation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eoperation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Emachining_operation") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_toolpath" ,(StepNodeType) 22, (DWORD) &(this->its_toolpath), "Etoolpath_list", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_tool_direction" ,(StepNodeType) 22, (DWORD) &(this->its_tool_direction), "Etool_direction", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eoperation*/
////////////////////////////////////////////////////////////////////////////////
Eoptional_stop::Eoptional_stop(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eoptional_stop";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eoptional_stop*/
////////////////////////////////////////////////////////////////////////////////
Eor_expression::Eor_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eor_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emultiple_arity_boolean_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emultiple_arity_boolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Emultiple_arity_boolean_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eor_expression*/
////////////////////////////////////////////////////////////////////////////////
Eordinal_date::Eordinal_date(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eordinal_date";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edate") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edate" ,(StepNodeType) 1, (DWORD) &(this->Edate::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "day_component" ,(StepNodeType) 22, (DWORD) &(this->day_component), "Eday_in_year_number", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eordinal_date*/
////////////////////////////////////////////////////////////////////////////////
Eoriented_edge::Eoriented_edge(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eoriented_edge";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eedge") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eedge" ,(StepNodeType) 1, (DWORD) &(this->Eedge::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "edge_element" ,(StepNodeType) 22, (DWORD) &(this->edge_element), "Eedge", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eoriented_edge*/
////////////////////////////////////////////////////////////////////////////////
Eparabola::Eparabola(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eparabola";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Econic") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->Econic::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "focal_dist" ,(StepNodeType) 22, (DWORD) &(this->focal_dist), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eparabola*/
////////////////////////////////////////////////////////////////////////////////
Eparallel::Eparallel(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eparallel";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprogram_structure") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprogram_structure" ,(StepNodeType) 1, (DWORD) &(this->Eprogram_structure::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "branches" ,(StepNodeType) 13, (DWORD) &(this->branches), "EListT<EexecutablePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eexecutable");
	branches.ListClassname()="Eexecutable"; 
	branches.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eparallel*/
////////////////////////////////////////////////////////////////////////////////
Eparameterised_path::Eparameterised_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eparameterised_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	supertypes.push_back("Econnector") ; 
	supertypes.push_back("Eapproach_lift_path") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etoolpath" ,(StepNodeType) 1, (DWORD) &(this->Etoolpath::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eparameterised_path*/
////////////////////////////////////////////////////////////////////////////////
Epartial_area_definition::Epartial_area_definition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epartial_area_definition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "effective_length" ,(StepNodeType) 22, (DWORD) &(this->effective_length), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "placement" ,(StepNodeType) 22, (DWORD) &(this->placement), "Eaxis2_placement_3d", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "maximum_length" ,(StepNodeType) 22, (DWORD) &(this->maximum_length), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Epartial_area_definition*/
////////////////////////////////////////////////////////////////////////////////
Epartial_circular_path::Epartial_circular_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epartial_circular_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecircular_path") ; 
	parents.push_back("Etravel_path") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecircular_path" ,(StepNodeType) 1, (DWORD) &(this->Ecircular_path::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "sweep_angle" ,(StepNodeType) 22, (DWORD) &(this->sweep_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Epartial_circular_path*/
////////////////////////////////////////////////////////////////////////////////
Epartial_circular_profile::Epartial_circular_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epartial_circular_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eopen_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eopen_profile" ,(StepNodeType) 1, (DWORD) &(this->Eopen_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "sweep_angle" ,(StepNodeType) 22, (DWORD) &(this->sweep_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Epartial_circular_profile*/
////////////////////////////////////////////////////////////////////////////////
Epartial_circular_shape_profile::Epartial_circular_shape_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epartial_circular_shape_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eshape_profile") ; 
	parents.push_back("Eprofile_feature") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eshape_profile" ,(StepNodeType) 1, (DWORD) &(this->Eshape_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "open_boundary" ,(StepNodeType) 22, (DWORD) &(this->open_boundary), "Epartial_circular_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Epartial_circular_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Epath::Epath(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epath";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Etopological_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "edge_list" ,(StepNodeType) 13, (DWORD) &(this->edge_list), "EListT<Eoriented_edgePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eoriented_edge");
	edge_list.ListClassname()="Eoriented_edge"; 
	edge_list.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Epath*/
////////////////////////////////////////////////////////////////////////////////
Epcurve::Epcurve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epcurve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebounded_pcurve") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->Ecurve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "basis_surface" ,(StepNodeType) 22, (DWORD) &(this->basis_surface), "Esurface", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "reference_to_curve" ,(StepNodeType) 22, (DWORD) &(this->reference_to_curve), "Edefinitional_representation", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Epcurve*/
////////////////////////////////////////////////////////////////////////////////
Eperson::Eperson(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eperson";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "last_name" ,(StepNodeType) 22, (DWORD) &(this->last_name), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "first_name" ,(StepNodeType) 22, (DWORD) &(this->first_name), "Elabel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "middle_names" ,(StepNodeType) 13, (DWORD) &(this->middle_names), "EListT<ElabelPtr>", 1));
	vars.back()->Init(1, (StepNodeType)  22, "Elabel");
	middle_names.ListClassname()="Elabel"; 
	middle_names.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "prefix_titles" ,(StepNodeType) 13, (DWORD) &(this->prefix_titles), "EListT<ElabelPtr>", 1));
	vars.back()->Init(1, (StepNodeType)  22, "Elabel");
	prefix_titles.ListClassname()="Elabel"; 
	prefix_titles.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "suffix_titles" ,(StepNodeType) 13, (DWORD) &(this->suffix_titles), "EListT<ElabelPtr>", 1));
	vars.back()->Init(1, (StepNodeType)  22, "Elabel");
	suffix_titles.ListClassname()="Elabel"; 
	suffix_titles.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eperson*/
////////////////////////////////////////////////////////////////////////////////
Eperson_and_address::Eperson_and_address(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eperson_and_address";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_person" ,(StepNodeType) 22, (DWORD) &(this->its_person), "Eperson", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_address" ,(StepNodeType) 22, (DWORD) &(this->its_address), "Eaddress", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eperson_and_address*/
////////////////////////////////////////////////////////////////////////////////
Eplacement::Eplacement(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplacement";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Eaxis1_placement") ; 
	supertypes.push_back("Eaxis2_placement_3d") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "location" ,(StepNodeType) 22, (DWORD) &(this->location), "Ecartesian_point", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplacement*/
////////////////////////////////////////////////////////////////////////////////
Eplanar_face::Eplanar_face(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplanar_face";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "course_of_travel" ,(StepNodeType) 22, (DWORD) &(this->course_of_travel), "Elinear_path", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "removal_boundary" ,(StepNodeType) 22, (DWORD) &(this->removal_boundary), "Elinear_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "face_boundary" ,(StepNodeType) 22, (DWORD) &(this->face_boundary), "Eclosed_profile", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_boss" ,(StepNodeType) 13, (DWORD) &(this->its_boss), "EListT<EbossPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eboss");
	its_boss.ListClassname()="Eboss"; 
	its_boss.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eplanar_face*/
////////////////////////////////////////////////////////////////////////////////
Eplanar_pocket_bottom_condition::Eplanar_pocket_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplanar_pocket_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epocket_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epocket_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Epocket_bottom_condition::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplanar_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Eplanar_profile_floor::Eplanar_profile_floor(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplanar_profile_floor";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprofile_floor") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprofile_floor" ,(StepNodeType) 1, (DWORD) &(this->Eprofile_floor::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "floor" ,(StepNodeType) 22, (DWORD) &(this->floor), "Eplane", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplanar_profile_floor*/
////////////////////////////////////////////////////////////////////////////////
Eplane::Eplane(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplane";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eelementary_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eelementary_surface" ,(StepNodeType) 1, (DWORD) &(this->Eelementary_surface::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplane*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplane_milling" ,(StepNodeType) 1, (DWORD) &(this->Eplane_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_finish_milling*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Eplane_rough_milling") ; 
	supertypes.push_back("Eplane_finish_milling") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_milling_operation" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_milling_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axial_cutting_depth" ,(StepNodeType) 22, (DWORD) &(this->axial_cutting_depth), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "allowance_bottom" ,(StepNodeType) 22, (DWORD) &(this->allowance_bottom), "Elength_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_milling*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eplane_milling" ,(StepNodeType) 1, (DWORD) &(this->Eplane_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplane_rough_milling*/
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
////////////////////////////////////////////////////////////////////////////////
Eplunge_strategy::Eplunge_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplunge_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eapproach_retract_strategy") ; 
	supertypes.clear(); 
	supertypes.push_back("Eplunge_toolaxis") ; 
	supertypes.push_back("Eplunge_ramp") ; 
	supertypes.push_back("Eplunge_helix") ; 
	supertypes.push_back("Eplunge_zigzag") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eapproach_retract_strategy" ,(StepNodeType) 1, (DWORD) &(this->Eapproach_retract_strategy::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eplunge_strategy*/
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
////////////////////////////////////////////////////////////////////////////////
Eplus_minus_value::Eplus_minus_value(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplus_minus_value";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "upper_limit" ,(StepNodeType) 22, (DWORD) &(this->upper_limit), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "lower_limit" ,(StepNodeType) 22, (DWORD) &(this->lower_limit), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "significant_digits" ,(StepNodeType) 3, (DWORD) &(this->significant_digits), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eplus_minus_value*/
////////////////////////////////////////////////////////////////////////////////
Epocket::Epocket(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epocket";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Eclosed_pocket") ; 
	supertypes.push_back("Eopen_pocket") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_boss" ,(StepNodeType) 13, (DWORD) &(this->its_boss), "EListT<EbossPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eboss");
	its_boss.ListClassname()="Eboss"; 
	its_boss.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "slope" ,(StepNodeType) 22, (DWORD) &(this->slope), "Eplane_angle_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "bottom_condition" ,(StepNodeType) 22, (DWORD) &(this->bottom_condition), "Epocket_bottom_condition", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "planar_radius" ,(StepNodeType) 22, (DWORD) &(this->planar_radius), "Etoleranced_length_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "orthogonal_radius" ,(StepNodeType) 22, (DWORD) &(this->orthogonal_radius), "Etoleranced_length_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Epocket*/
////////////////////////////////////////////////////////////////////////////////
Epocket_bottom_condition::Epocket_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epocket_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Ethrough_pocket_bottom_condition") ; 
	supertypes.push_back("Eplanar_pocket_bottom_condition") ; 
	supertypes.push_back("Eradiused_pocket_bottom_condition") ; 
	supertypes.push_back("Egeneral_pocket_bottom_condition") ; 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Epocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Epoint::Epoint(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epoint";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecartesian_point") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Epoint*/
////////////////////////////////////////////////////////////////////////////////
Epolyline::Epolyline(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Epolyline";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->Ebounded_curve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "points" ,(StepNodeType) 13, (DWORD) &(this->points), "EListT<Ecartesian_pointPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecartesian_point");
	points.ListClassname()="Ecartesian_point"; 
	points.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Epolyline*/
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
////////////////////////////////////////////////////////////////////////////////
Eprocess_model_list::Eprocess_model_list(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprocess_model_list";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_list" ,(StepNodeType) 13, (DWORD) &(this->its_list), "EListT<Eprocess_modelPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eprocess_model");
	its_list.ListClassname()="Eprocess_model"; 
	its_list.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eprocess_model_list*/
////////////////////////////////////////////////////////////////////////////////
Eprofile::Eprofile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprofile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Eopen_profile") ; 
	supertypes.push_back("Eclosed_profile") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "placement" ,(StepNodeType) 22, (DWORD) &(this->placement), "Eaxis2_placement_3d", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eprofile*/
////////////////////////////////////////////////////////////////////////////////
Eprofile_feature::Eprofile_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprofile_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Egeneral_outside_profile") ; 
	supertypes.push_back("Eshape_profile") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "profile_swept_shape" ,(StepNodeType) 22, (DWORD) &(this->profile_swept_shape), "Elinear_path", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eprofile_feature*/
////////////////////////////////////////////////////////////////////////////////
Eprofile_floor::Eprofile_floor(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprofile_floor";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Egeneral_profile_floor") ; 
	supertypes.push_back("Eplanar_profile_floor") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "floor_radius" ,(StepNodeType) 22, (DWORD) &(this->floor_radius), "Enumeric_parameter", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "start_or_end" ,(StepNodeType) 7, (DWORD) &(this->start_or_end), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eprofile_floor*/
////////////////////////////////////////////////////////////////////////////////
Eprogram_stop::Eprogram_stop(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprogram_stop";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eprogram_stop*/
////////////////////////////////////////////////////////////////////////////////
Eprogram_structure::Eprogram_structure(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eprogram_structure";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	supertypes.push_back("Eworkplan") ; 
	supertypes.push_back("Eparallel") ; 
	supertypes.push_back("Enon_sequential") ; 
	supertypes.push_back("Eselective") ; 
	supertypes.push_back("Eif_statement") ; 
	supertypes.push_back("Ewhile_statement") ; 
	supertypes.push_back("Eassignment") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eexecutable" ,(StepNodeType) 1, (DWORD) &(this->Eexecutable::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eprogram_structure*/
////////////////////////////////////////////////////////////////////////////////
Eproject::Eproject(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eproject";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "main_workplan" ,(StepNodeType) 22, (DWORD) &(this->main_workplan), "Eworkplan", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_workpieces" ,(StepNodeType) 13, (DWORD) &(this->its_workpieces), "EListT<EworkpiecePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eworkpiece");
	its_workpieces.ListClassname()="Eworkpiece"; 
	its_workpieces.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "its_owner" ,(StepNodeType) 22, (DWORD) &(this->its_owner), "Eperson_and_address", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_release" ,(StepNodeType) 22, (DWORD) &(this->its_release), "Edate_and_time", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_status" ,(StepNodeType) 22, (DWORD) &(this->its_status), "Eapproval", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eproject*/
////////////////////////////////////////////////////////////////////////////////
Eproperty_parameter::Eproperty_parameter(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eproperty_parameter";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Edescriptive_parameter") ; 
	supertypes.push_back("Enumeric_parameter") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "parameter_name" ,(StepNodeType) 22, (DWORD) &(this->parameter_name), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eproperty_parameter*/
////////////////////////////////////////////////////////////////////////////////
Equasi_uniform_curve::Equasi_uniform_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Equasi_uniform_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_curve::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Equasi_uniform_curve*/
////////////////////////////////////////////////////////////////////////////////
Equasi_uniform_surface::Equasi_uniform_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Equasi_uniform_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_surface") ; 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_surface::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Equasi_uniform_surface*/
////////////////////////////////////////////////////////////////////////////////
Eradiused_pocket_bottom_condition::Eradiused_pocket_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eradiused_pocket_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epocket_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epocket_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Epocket_bottom_condition::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "floor_radius_center" ,(StepNodeType) 22, (DWORD) &(this->floor_radius_center), "Ecartesian_point", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "floor_radius" ,(StepNodeType) 22, (DWORD) &(this->floor_radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eradiused_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Eradiused_slot_end_type::Eradiused_slot_end_type(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eradiused_slot_end_type";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eslot_end_type") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eslot_end_type" ,(StepNodeType) 1, (DWORD) &(this->Eslot_end_type::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eradiused_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Erapid_movement::Erapid_movement(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erapid_movement";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	supertypes.push_back("Ereturn_home") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eworkingstep" ,(StepNodeType) 1, (DWORD) &(this->Eworkingstep::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Erapid_movement*/
////////////////////////////////////////////////////////////////////////////////
Erational_b_spline_curve::Erational_b_spline_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erational_b_spline_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_curve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "weights_data" ,(StepNodeType) 13, (DWORD) &(this->weights_data), "EListT<ERealPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  4, "EReal");
	weights_data.ListClassname()="EReal"; 
	weights_data.ListType()=(StepNodeType)  4; 
	BuildInstanceDef(vars, instancevars);
} /* End Erational_b_spline_curve*/
////////////////////////////////////////////////////////////////////////////////
Erational_b_spline_surface::Erational_b_spline_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erational_b_spline_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_surface") ; 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_surface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "weights_data" ,(StepNodeType) 15, (DWORD) &(this->weights_data), "std::vector< EListT<ERealPtr> >", 0));
	vars.back()->Init(2, (StepNodeType)  4, "EReal");
	BuildInstanceDef(vars, instancevars);
} /* End Erational_b_spline_surface*/
////////////////////////////////////////////////////////////////////////////////
Ereamer::Ereamer(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ereamer";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	supertypes.push_back("Etapered_reamer") ; 
	supertypes.push_back("Ecombined_drill_and_reamer") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ereamer*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboring_operation" ,(StepNodeType) 1, (DWORD) &(this->Eboring_operation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ereaming*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_closed_profile::Erectangular_closed_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erectangular_closed_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eclosed_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eclosed_profile" ,(StepNodeType) 1, (DWORD) &(this->Eclosed_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "profile_width" ,(StepNodeType) 22, (DWORD) &(this->profile_width), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "profile_length" ,(StepNodeType) 22, (DWORD) &(this->profile_length), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erectangular_closed_profile*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_closed_shape_profile::Erectangular_closed_shape_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erectangular_closed_shape_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eshape_profile") ; 
	parents.push_back("Eprofile_feature") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eshape_profile" ,(StepNodeType) 1, (DWORD) &(this->Eshape_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "closed_boundary" ,(StepNodeType) 22, (DWORD) &(this->closed_boundary), "Erectangular_closed_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erectangular_closed_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_offset::Erectangular_offset(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erectangular_offset";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "offset_direction" ,(StepNodeType) 22, (DWORD) &(this->offset_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "offset_distance" ,(StepNodeType) 22, (DWORD) &(this->offset_distance), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "row_index" ,(StepNodeType) 3, (DWORD) &(this->row_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "column_index" ,(StepNodeType) 3, (DWORD) &(this->column_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erectangular_offset*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_omit::Erectangular_omit(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erectangular_omit";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "row_index" ,(StepNodeType) 3, (DWORD) &(this->row_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "column_index" ,(StepNodeType) 3, (DWORD) &(this->column_index), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erectangular_omit*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_open_shape_profile::Erectangular_open_shape_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erectangular_open_shape_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eshape_profile") ; 
	parents.push_back("Eprofile_feature") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eshape_profile" ,(StepNodeType) 1, (DWORD) &(this->Eshape_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "open_boundary" ,(StepNodeType) 22, (DWORD) &(this->open_boundary), "Esquare_u_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erectangular_open_shape_profile*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_pattern::Erectangular_pattern(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erectangular_pattern";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ereplicate_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ereplicate_feature" ,(StepNodeType) 1, (DWORD) &(this->Ereplicate_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "spacing" ,(StepNodeType) 22, (DWORD) &(this->spacing), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_direction" ,(StepNodeType) 22, (DWORD) &(this->its_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "number_of_rows" ,(StepNodeType) 3, (DWORD) &(this->number_of_rows), "EInteger", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "number_of_columns" ,(StepNodeType) 3, (DWORD) &(this->number_of_columns), "EInteger", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "row_spacing" ,(StepNodeType) 22, (DWORD) &(this->row_spacing), "Etoleranced_length_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "row_layout_direction" ,(StepNodeType) 22, (DWORD) &(this->row_layout_direction), "Edirection", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "relocated_base_feature" ,(StepNodeType) 13, (DWORD) &(this->relocated_base_feature), "EListT<Erectangular_offsetPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Erectangular_offset");
	relocated_base_feature.ListClassname()="Erectangular_offset"; 
	relocated_base_feature.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "missing_base_feature" ,(StepNodeType) 13, (DWORD) &(this->missing_base_feature), "EListT<Erectangular_omitPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Erectangular_omit");
	missing_base_feature.ListClassname()="Erectangular_omit"; 
	missing_base_feature.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Erectangular_pattern*/
////////////////////////////////////////////////////////////////////////////////
Eregion::Eregion(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eregion";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Eregion_projection") ; 
	supertypes.push_back("Eregion_surface_list") ; 
	supertypes.push_back("Etopological_region") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emanufacturing_feature" ,(StepNodeType) 1, (DWORD) &(this->Emanufacturing_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feature_placement" ,(StepNodeType) 22, (DWORD) &(this->feature_placement), "Eaxis2_placement_3d", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eregion*/
////////////////////////////////////////////////////////////////////////////////
Eregion_projection::Eregion_projection(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eregion_projection";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eregion") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eregion" ,(StepNodeType) 1, (DWORD) &(this->Eregion::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "proj_curve" ,(StepNodeType) 22, (DWORD) &(this->proj_curve), "Ebounded_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "proj_dir" ,(StepNodeType) 22, (DWORD) &(this->proj_dir), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "depth" ,(StepNodeType) 22, (DWORD) &(this->depth), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eregion_projection*/
////////////////////////////////////////////////////////////////////////////////
Eregion_surface_list::Eregion_surface_list(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eregion_surface_list";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eregion") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eregion" ,(StepNodeType) 1, (DWORD) &(this->Eregion::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "surface_list" ,(StepNodeType) 13, (DWORD) &(this->surface_list), "EListT<Ebounded_surfacePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ebounded_surface");
	surface_list.ListClassname()="Ebounded_surface"; 
	surface_list.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eregion_surface_list*/
////////////////////////////////////////////////////////////////////////////////
Ereplicate_feature::Ereplicate_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ereplicate_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecircular_pattern") ; 
	supertypes.push_back("Erectangular_pattern") ; 
	supertypes.push_back("Egeneral_pattern") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etwo5d_manufacturing_feature" ,(StepNodeType) 1, (DWORD) &(this->Etwo5d_manufacturing_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "replicate_base_feature" ,(StepNodeType) 22, (DWORD) &(this->replicate_base_feature), "Etwo5d_manufacturing_feature", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ereplicate_feature*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation::Erepresentation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erepresentation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Eshape_representation") ; 
	supertypes.push_back("Edefinitional_representation") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Erepresentation_itemPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Erepresentation_item");
	items.ListClassname()="Erepresentation_item"; 
	items.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "context_of_items" ,(StepNodeType) 22, (DWORD) &(this->context_of_items), "Erepresentation_context", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erepresentation*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_context::Erepresentation_context(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erepresentation_context";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Egeometric_representation_context") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "context_identifier" ,(StepNodeType) 22, (DWORD) &(this->context_identifier), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "context_type" ,(StepNodeType) 22, (DWORD) &(this->context_type), "Etext", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erepresentation_context*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_item::Erepresentation_item(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erepresentation_item";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Egeometric_representation_item") ; 
	supertypes.push_back("Etopological_representation_item") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erepresentation_item*/
////////////////////////////////////////////////////////////////////////////////
Ereturn_home::Ereturn_home(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ereturn_home";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Erapid_movement") ; 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Erapid_movement" ,(StepNodeType) 1, (DWORD) &(this->Erapid_movement::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ereturn_home*/
////////////////////////////////////////////////////////////////////////////////
Eright_circular_cylinder::Eright_circular_cylinder(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eright_circular_cylinder";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "position" ,(StepNodeType) 22, (DWORD) &(this->position), "Eaxis1_placement", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "height" ,(StepNodeType) 22, (DWORD) &(this->height), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eright_circular_cylinder*/
////////////////////////////////////////////////////////////////////////////////
Eround_hole::Eround_hole(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eround_hole";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "diameter" ,(StepNodeType) 22, (DWORD) &(this->diameter), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "change_in_diameter" ,(StepNodeType) 22, (DWORD) &(this->change_in_diameter), "Etaper_select", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "bottom_condition" ,(StepNodeType) 22, (DWORD) &(this->bottom_condition), "Ehole_bottom_condition", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eround_hole*/
////////////////////////////////////////////////////////////////////////////////
Erounded_end::Erounded_end(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erounded_end";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "course_of_travel" ,(StepNodeType) 22, (DWORD) &(this->course_of_travel), "Elinear_path", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "partial_circular_boundary" ,(StepNodeType) 22, (DWORD) &(this->partial_circular_boundary), "Epartial_circular_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erounded_end*/
////////////////////////////////////////////////////////////////////////////////
Erounded_u_profile::Erounded_u_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Erounded_u_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eopen_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eopen_profile" ,(StepNodeType) 1, (DWORD) &(this->Eopen_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "width" ,(StepNodeType) 22, (DWORD) &(this->width), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Erounded_u_profile*/
////////////////////////////////////////////////////////////////////////////////
Eselective::Eselective(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eselective";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprogram_structure") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprogram_structure" ,(StepNodeType) 1, (DWORD) &(this->Eprogram_structure::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_elements" ,(StepNodeType) 13, (DWORD) &(this->its_elements), "EListT<EexecutablePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eexecutable");
	its_elements.ListClassname()="Eexecutable"; 
	its_elements.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eselective*/
////////////////////////////////////////////////////////////////////////////////
Eset_mark::Eset_mark(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eset_mark";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eset_mark*/
////////////////////////////////////////////////////////////////////////////////
Esetup::Esetup(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esetup";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_origin" ,(StepNodeType) 22, (DWORD) &(this->its_origin), "Eaxis2_placement_3d", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_secplane" ,(StepNodeType) 22, (DWORD) &(this->its_secplane), "Eelementary_surface", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_workpiece_setup" ,(StepNodeType) 13, (DWORD) &(this->its_workpiece_setup), "EListT<Eworkpiece_setupPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eworkpiece_setup");
	its_workpiece_setup.ListClassname()="Eworkpiece_setup"; 
	its_workpiece_setup.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Esetup*/
////////////////////////////////////////////////////////////////////////////////
Esetup_instruction::Esetup_instruction(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esetup_instruction";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "external_document" ,(StepNodeType) 22, (DWORD) &(this->external_document), "Eidentifier", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Esetup_instruction*/
////////////////////////////////////////////////////////////////////////////////
Eshape_profile::Eshape_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eshape_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprofile_feature") ; 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Egeneral_shape_profile") ; 
	supertypes.push_back("Epartial_circular_shape_profile") ; 
	supertypes.push_back("Ecircular_closed_shape_profile") ; 
	supertypes.push_back("Erectangular_open_shape_profile") ; 
	supertypes.push_back("Erectangular_closed_shape_profile") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprofile_feature" ,(StepNodeType) 1, (DWORD) &(this->Eprofile_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "floor_condition" ,(StepNodeType) 22, (DWORD) &(this->floor_condition), "Eprofile_select", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "removal_direction" ,(StepNodeType) 22, (DWORD) &(this->removal_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eshape_profile*/
////////////////////////////////////////////////////////////////////////////////
Eshape_representation::Eshape_representation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eshape_representation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Erepresentation") ; 
	supertypes.clear(); 
	supertypes.push_back("Eadvanced_brep_shape_representation") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Erepresentation" ,(StepNodeType) 1, (DWORD) &(this->Erepresentation::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eshape_representation*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eside_milling" ,(StepNodeType) 1, (DWORD) &(this->Eside_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eside_finish_milling*/
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Eside_rough_milling") ; 
	supertypes.push_back("Eside_finish_milling") ; 
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
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eside_milling" ,(StepNodeType) 1, (DWORD) &(this->Eside_milling::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Eside_rough_milling*/
////////////////////////////////////////////////////////////////////////////////
Eslot::Eslot(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eslot";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "course_of_travel" ,(StepNodeType) 22, (DWORD) &(this->course_of_travel), "Etravel_path", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "swept_shape" ,(StepNodeType) 22, (DWORD) &(this->swept_shape), "Eopen_profile", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "end_conditions" ,(StepNodeType) 13, (DWORD) &(this->end_conditions), "EListT<Eslot_end_typePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eslot_end_type");
	end_conditions.ListClassname()="Eslot_end_type"; 
	end_conditions.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eslot*/
////////////////////////////////////////////////////////////////////////////////
Eslot_end_type::Eslot_end_type(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eslot_end_type";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Ewoodruff_slot_end_type") ; 
	supertypes.push_back("Eradiused_slot_end_type") ; 
	supertypes.push_back("Eflat_slot_end_type") ; 
	supertypes.push_back("Eloop_slot_end_type") ; 
	supertypes.push_back("Eopen_slot_end_type") ; 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Eslot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Esolid_model::Esolid_model(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esolid_model";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Emanifold_solid_brep") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Esolid_model*/
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
////////////////////////////////////////////////////////////////////////////////
Especification::Especification(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Especification";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "constraint" ,(StepNodeType) 13, (DWORD) &(this->constraint), "EListT<Especification_usage_constraintPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Especification_usage_constraint");
	constraint.ListClassname()="Especification_usage_constraint"; 
	constraint.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "specification_id" ,(StepNodeType) 22, (DWORD) &(this->specification_id), "Etext", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "specification_description" ,(StepNodeType) 22, (DWORD) &(this->specification_description), "Etext", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "specification_class" ,(StepNodeType) 22, (DWORD) &(this->specification_class), "Etext", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Especification*/
////////////////////////////////////////////////////////////////////////////////
Especification_usage_constraint::Especification_usage_constraint(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Especification_usage_constraint";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "element" ,(StepNodeType) 22, (DWORD) &(this->element), "Etext", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "class_id" ,(StepNodeType) 22, (DWORD) &(this->class_id), "Etext", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Especification_usage_constraint*/
////////////////////////////////////////////////////////////////////////////////
Espherical_cap::Espherical_cap(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Espherical_cap";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "internal_angle" ,(StepNodeType) 22, (DWORD) &(this->internal_angle), "Enumeric_parameter", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Enumeric_parameter", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Espherical_cap*/
////////////////////////////////////////////////////////////////////////////////
Espherical_hole_bottom::Espherical_hole_bottom(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Espherical_hole_bottom";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eblind_bottom_condition") ; 
	parents.push_back("Ehole_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eblind_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Eblind_bottom_condition::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Espherical_hole_bottom*/
////////////////////////////////////////////////////////////////////////////////
Espherical_surface::Espherical_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Espherical_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eelementary_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eelementary_surface" ,(StepNodeType) 1, (DWORD) &(this->Eelementary_surface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Espherical_surface*/
////////////////////////////////////////////////////////////////////////////////
Esquare_u_profile::Esquare_u_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esquare_u_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eopen_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eopen_profile" ,(StepNodeType) 1, (DWORD) &(this->Eopen_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "width" ,(StepNodeType) 22, (DWORD) &(this->width), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "first_radius" ,(StepNodeType) 22, (DWORD) &(this->first_radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "first_angle" ,(StepNodeType) 22, (DWORD) &(this->first_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "second_radius" ,(StepNodeType) 22, (DWORD) &(this->second_radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "second_angle" ,(StepNodeType) 22, (DWORD) &(this->second_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Esquare_u_profile*/
////////////////////////////////////////////////////////////////////////////////
Estep::Estep(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Estep";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "open_boundary" ,(StepNodeType) 22, (DWORD) &(this->open_boundary), "Elinear_path", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "wall_boundary" ,(StepNodeType) 22, (DWORD) &(this->wall_boundary), "Evee_profile", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_boss" ,(StepNodeType) 13, (DWORD) &(this->its_boss), "EListT<EbossPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eboss");
	its_boss.ListClassname()="Eboss"; 
	its_boss.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Estep*/
////////////////////////////////////////////////////////////////////////////////
Esurface::Esurface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esurface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Ebounded_surface") ; 
	supertypes.push_back("Eelementary_surface") ; 
	supertypes.push_back("Eswept_surface") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Esurface*/
////////////////////////////////////////////////////////////////////////////////
Esurface_of_linear_extrusion::Esurface_of_linear_extrusion(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esurface_of_linear_extrusion";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eswept_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eswept_surface" ,(StepNodeType) 1, (DWORD) &(this->Eswept_surface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "extrusion_axis" ,(StepNodeType) 22, (DWORD) &(this->extrusion_axis), "Evector", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Esurface_of_linear_extrusion*/
////////////////////////////////////////////////////////////////////////////////
Esurface_of_revolution::Esurface_of_revolution(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esurface_of_revolution";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eswept_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eswept_surface" ,(StepNodeType) 1, (DWORD) &(this->Eswept_surface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "axis_position" ,(StepNodeType) 22, (DWORD) &(this->axis_position), "Eaxis1_placement", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Esurface_of_revolution*/
////////////////////////////////////////////////////////////////////////////////
Esurface_texture_parameter::Esurface_texture_parameter(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Esurface_texture_parameter";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_value" ,(StepNodeType) 22, (DWORD) &(this->its_value), "Eparameter_value", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "parameter_name" ,(StepNodeType) 22, (DWORD) &(this->parameter_name), "Elabel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "measuring_method" ,(StepNodeType) 22, (DWORD) &(this->measuring_method), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "parameter_index" ,(StepNodeType) 22, (DWORD) &(this->parameter_index), "Eidentifier", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "applied_surfaces" ,(StepNodeType) 13, (DWORD) &(this->applied_surfaces), "EListT<Emachined_surfacePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Emachined_surface");
	applied_surfaces.ListClassname()="Emachined_surface"; 
	applied_surfaces.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Esurface_texture_parameter*/
////////////////////////////////////////////////////////////////////////////////
Eswept_surface::Eswept_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eswept_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Esurface_of_linear_extrusion") ; 
	supertypes.push_back("Esurface_of_revolution") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->Esurface::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "swept_curve" ,(StepNodeType) 22, (DWORD) &(this->swept_curve), "Ecurve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eswept_surface*/
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
////////////////////////////////////////////////////////////////////////////////
Etap::Etap(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etap";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_tool_body") ; 
	parents.push_back("Etool_body") ; 
	supertypes.clear(); 
	supertypes.push_back("Etapered_tap") ; 
	supertypes.push_back("Ecombined_drill_and_tap") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_tool_body" ,(StepNodeType) 1, (DWORD) &(this->Emilling_tool_body::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etap*/
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
////////////////////////////////////////////////////////////////////////////////
Etapping::Etapping(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etapping";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "compensation_chuck" ,(StepNodeType) 7, (DWORD) &(this->compensation_chuck), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etapping*/
////////////////////////////////////////////////////////////////////////////////
Etechnology::Etechnology(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etechnology";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Emilling_technology") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "feedrate" ,(StepNodeType) 22, (DWORD) &(this->feedrate), "Espeed_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "feedrate_reference" ,(StepNodeType) 22, (DWORD) &(this->feedrate_reference), "Etool_reference_point", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etechnology*/
////////////////////////////////////////////////////////////////////////////////
Etee_profile::Etee_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etee_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eopen_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eopen_profile" ,(StepNodeType) 1, (DWORD) &(this->Eopen_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "first_angle" ,(StepNodeType) 22, (DWORD) &(this->first_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "second_angle" ,(StepNodeType) 22, (DWORD) &(this->second_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "cross_bar_width" ,(StepNodeType) 22, (DWORD) &(this->cross_bar_width), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "cross_bar_depth" ,(StepNodeType) 22, (DWORD) &(this->cross_bar_depth), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "width" ,(StepNodeType) 22, (DWORD) &(this->width), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "first_offset" ,(StepNodeType) 22, (DWORD) &(this->first_offset), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "second_offset" ,(StepNodeType) 22, (DWORD) &(this->second_offset), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etee_profile*/
////////////////////////////////////////////////////////////////////////////////
Ethread::Ethread(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethread";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecatalogue_thread") ; 
	supertypes.push_back("Edefined_thread") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "partial_profile" ,(StepNodeType) 22, (DWORD) &(this->partial_profile), "Epartial_area_definition", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "applied_shape" ,(StepNodeType) 13, (DWORD) &(this->applied_shape), "EListT<Emachining_featurePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Emachining_feature");
	applied_shape.ListClassname()="Emachining_feature"; 
	applied_shape.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "inner_or_outer_thread" ,(StepNodeType) 7, (DWORD) &(this->inner_or_outer_thread), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "qualifier" ,(StepNodeType) 22, (DWORD) &(this->qualifier), "Edescriptive_parameter", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "fit_class" ,(StepNodeType) 22, (DWORD) &(this->fit_class), "Edescriptive_parameter", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "form" ,(StepNodeType) 22, (DWORD) &(this->form), "Edescriptive_parameter", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "major_diameter" ,(StepNodeType) 22, (DWORD) &(this->major_diameter), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "number_of_threads" ,(StepNodeType) 22, (DWORD) &(this->number_of_threads), "Enumeric_parameter", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "thread_hand" ,(StepNodeType) 22, (DWORD) &(this->thread_hand), "Edescriptive_parameter", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ethread*/
////////////////////////////////////////////////////////////////////////////////
Ethread_drilling::Ethread_drilling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethread_drilling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edrilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Edrilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "helical_movement_on_forward" ,(StepNodeType) 7, (DWORD) &(this->helical_movement_on_forward), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ethread_drilling*/
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
////////////////////////////////////////////////////////////////////////////////
Ethree_axes::Ethree_axes(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethree_axes";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_direction") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_direction" ,(StepNodeType) 1, (DWORD) &(this->Etool_direction::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ethree_axes*/
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
////////////////////////////////////////////////////////////////////////////////
Ethrough_bottom_condition::Ethrough_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethrough_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ehole_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ehole_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Ehole_bottom_condition::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ethrough_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Ethrough_pocket_bottom_condition::Ethrough_pocket_bottom_condition(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethrough_pocket_bottom_condition";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Epocket_bottom_condition") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Epocket_bottom_condition" ,(StepNodeType) 1, (DWORD) &(this->Epocket_bottom_condition::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Ethrough_pocket_bottom_condition*/
////////////////////////////////////////////////////////////////////////////////
Ethrough_profile_floor::Ethrough_profile_floor(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ethrough_profile_floor";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Ethrough_profile_floor*/
////////////////////////////////////////////////////////////////////////////////
Etoleranced_length_measure::Etoleranced_length_measure(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etoleranced_length_measure";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "theoretical_size" ,(StepNodeType) 22, (DWORD) &(this->theoretical_size), "Epositive_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "implicit_tolerance" ,(StepNodeType) 22, (DWORD) &(this->implicit_tolerance), "Etolerance_select", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etoleranced_length_measure*/
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
////////////////////////////////////////////////////////////////////////////////
Etool_body::Etool_body(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_body";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Emilling_tool_body") ; 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Etool_body*/
////////////////////////////////////////////////////////////////////////////////
Etool_direction::Etool_direction(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_direction";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Etwo_axes") ; 
	supertypes.push_back("Ethree_axes") ; 
	supertypes.push_back("Etool_direction_for_milling") ; 
	m_bAbstract=false ; 
	BuildInstanceDef(vars, instancevars);
} /* End Etool_direction*/
////////////////////////////////////////////////////////////////////////////////
Etool_direction_for_milling::Etool_direction_for_milling(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_direction_for_milling";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_direction") ; 
	supertypes.clear(); 
	supertypes.push_back("Ethree_axes_tilted_tool") ; 
	supertypes.push_back("Efive_axes_var_tilt_yaw") ; 
	supertypes.push_back("Efive_axes_const_tilt_yaw") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_direction" ,(StepNodeType) 1, (DWORD) &(this->Etool_direction::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etool_direction_for_milling*/
////////////////////////////////////////////////////////////////////////////////
Etool_length_probing::Etool_length_probing(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_length_probing";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_probing") ; 
	parents.push_back("Etouch_probing") ; 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_probing" ,(StepNodeType) 1, (DWORD) &(this->Etool_probing::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etool_length_probing*/
////////////////////////////////////////////////////////////////////////////////
Etool_probing::Etool_probing(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_probing";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etouch_probing") ; 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	supertypes.push_back("Etool_length_probing") ; 
	supertypes.push_back("Etool_radius_probing") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etouch_probing" ,(StepNodeType) 1, (DWORD) &(this->Etouch_probing::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "offset" ,(StepNodeType) 22, (DWORD) &(this->offset), "Ecartesian_point", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "max_wear" ,(StepNodeType) 22, (DWORD) &(this->max_wear), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_tool" ,(StepNodeType) 22, (DWORD) &(this->its_tool), "Emachining_tool", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etool_probing*/
////////////////////////////////////////////////////////////////////////////////
Etool_radius_probing::Etool_radius_probing(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_radius_probing";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_probing") ; 
	parents.push_back("Etouch_probing") ; 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_probing" ,(StepNodeType) 1, (DWORD) &(this->Etool_probing::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etool_radius_probing*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath::Etoolpath(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etoolpath";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Efeedstop") ; 
	supertypes.push_back("Etrajectory") ; 
	supertypes.push_back("Eparameterised_path") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_priority" ,(StepNodeType) 7, (DWORD) &(this->its_priority), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_type" ,(StepNodeType) 22, (DWORD) &(this->its_type), "Etoolpath_type", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_speed" ,(StepNodeType) 22, (DWORD) &(this->its_speed), "Etoolpath_speedprofile", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_technology" ,(StepNodeType) 22, (DWORD) &(this->its_technology), "Etechnology", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_machine_functions" ,(StepNodeType) 22, (DWORD) &(this->its_machine_functions), "Emachine_functions", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etoolpath*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath_feature::Etoolpath_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etoolpath_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emachining_feature") ; 
	parents.push_back("Etwo5d_manufacturing_feature") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emachining_feature" ,(StepNodeType) 1, (DWORD) &(this->Emachining_feature::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etoolpath_feature*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath_list::Etoolpath_list(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etoolpath_list";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_list" ,(StepNodeType) 13, (DWORD) &(this->its_list), "EListT<EtoolpathPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Etoolpath");
	its_list.ListClassname()="Etoolpath"; 
	its_list.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Etoolpath_list*/
////////////////////////////////////////////////////////////////////////////////
Etoolpath_speed::Etoolpath_speed(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etoolpath_speed";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "speed" ,(StepNodeType) 22, (DWORD) &(this->speed), "Eb_spline_curve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etoolpath_speed*/
////////////////////////////////////////////////////////////////////////////////
Etopological_region::Etopological_region(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etopological_region";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eregion") ; 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eregion" ,(StepNodeType) 1, (DWORD) &(this->Eregion::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etopological_region*/
////////////////////////////////////////////////////////////////////////////////
Etopological_representation_item::Etopological_representation_item(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etopological_representation_item";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Econnected_face_set") ; 
	supertypes.push_back("Eedge") ; 
	supertypes.push_back("Eface") ; 
	supertypes.push_back("Eface_bound") ; 
	supertypes.push_back("Eloop") ; 
	supertypes.push_back("Epath") ; 
	supertypes.push_back("Evertex") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Erepresentation_item" ,(StepNodeType) 1, (DWORD) &(this->Erepresentation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etopological_representation_item*/
////////////////////////////////////////////////////////////////////////////////
Etouch_probe::Etouch_probe(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etouch_probe";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etouch_probe*/
////////////////////////////////////////////////////////////////////////////////
Etouch_probing::Etouch_probing(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etouch_probing";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	supertypes.push_back("Eworkpiece_probing") ; 
	supertypes.push_back("Eworkpiece_complete_probing") ; 
	supertypes.push_back("Etool_probing") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eworkingstep" ,(StepNodeType) 1, (DWORD) &(this->Eworkingstep::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "measured_offset" ,(StepNodeType) 22, (DWORD) &(this->measured_offset), "Enc_variable", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etouch_probing*/
////////////////////////////////////////////////////////////////////////////////
Etrajectory::Etrajectory(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etrajectory";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etoolpath") ; 
	supertypes.clear(); 
	supertypes.push_back("Ecutter_location_trajectory") ; 
	supertypes.push_back("Ecutter_contact_trajectory") ; 
	supertypes.push_back("Eaxis_trajectory") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etoolpath" ,(StepNodeType) 1, (DWORD) &(this->Etoolpath::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_direction" ,(StepNodeType) 7, (DWORD) &(this->its_direction), "EBoolean", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etrajectory*/
////////////////////////////////////////////////////////////////////////////////
Etransition_feature::Etransition_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etransition_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Echamfer") ; 
	supertypes.push_back("Eedge_round") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emanufacturing_feature" ,(StepNodeType) 1, (DWORD) &(this->Emanufacturing_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "first_feature" ,(StepNodeType) 22, (DWORD) &(this->first_feature), "Emachining_feature", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "second_feature" ,(StepNodeType) 22, (DWORD) &(this->second_feature), "Emachining_feature", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etransition_feature*/
////////////////////////////////////////////////////////////////////////////////
Etravel_path::Etravel_path(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etravel_path";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Egeneral_path") ; 
	supertypes.push_back("Elinear_path") ; 
	supertypes.push_back("Ecircular_path") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "placement" ,(StepNodeType) 22, (DWORD) &(this->placement), "Eaxis2_placement_3d", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etravel_path*/
////////////////////////////////////////////////////////////////////////////////
Etrimmed_curve::Etrimmed_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etrimmed_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->Ebounded_curve::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "basis_curve" ,(StepNodeType) 22, (DWORD) &(this->basis_curve), "Ecurve", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "trim_1" ,(StepNodeType) 13, (DWORD) &(this->trim_1), "EListT<Etrimming_selectPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Etrimming_select");
	trim_1.ListClassname()="Etrimming_select"; 
	trim_1.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "trim_2" ,(StepNodeType) 13, (DWORD) &(this->trim_2), "EListT<Etrimming_selectPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Etrimming_select");
	trim_2.ListClassname()="Etrimming_select"; 
	trim_2.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "sense_agreement" ,(StepNodeType) 7, (DWORD) &(this->sense_agreement), "EBoolean", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "master_representation" ,(StepNodeType) 22, (DWORD) &(this->master_representation), "Etrimming_preference", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etrimmed_curve*/
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
	supertypes.push_back("Etapered_drill") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edrill" ,(StepNodeType) 1, (DWORD) &(this->Edrill::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etwist_drill*/
////////////////////////////////////////////////////////////////////////////////
Etwo5d_manufacturing_feature::Etwo5d_manufacturing_feature(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etwo5d_manufacturing_feature";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emanufacturing_feature") ; 
	supertypes.clear(); 
	supertypes.push_back("Emachining_feature") ; 
	supertypes.push_back("Ecompound_feature") ; 
	supertypes.push_back("Ereplicate_feature") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emanufacturing_feature" ,(StepNodeType) 1, (DWORD) &(this->Emanufacturing_feature::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "feature_placement" ,(StepNodeType) 22, (DWORD) &(this->feature_placement), "Eaxis2_placement_3d", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etwo5d_manufacturing_feature*/
////////////////////////////////////////////////////////////////////////////////
Etwo5d_milling_operation::Etwo5d_milling_operation(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etwo5d_milling_operation";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Emilling_type_operation") ; 
	parents.push_back("Emilling_machining_operation") ; 
	parents.push_back("Emachining_operation") ; 
	parents.push_back("Eoperation") ; 
	supertypes.clear(); 
	supertypes.push_back("Eplane_milling") ; 
	supertypes.push_back("Eside_milling") ; 
	supertypes.push_back("Ebottom_and_side_milling") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Emilling_type_operation" ,(StepNodeType) 1, (DWORD) &(this->Emilling_type_operation::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_machining_strategy" ,(StepNodeType) 22, (DWORD) &(this->its_machining_strategy), "Etwo5d_milling_strategy", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etwo5d_milling_operation*/
////////////////////////////////////////////////////////////////////////////////
Etwo5d_milling_strategy::Etwo5d_milling_strategy(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etwo5d_milling_strategy";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	supertypes.push_back("Eunidirectional") ; 
	supertypes.push_back("Ebidirectional") ; 
	supertypes.push_back("Econtour_parallel") ; 
	supertypes.push_back("Ebidirectional_contour") ; 
	supertypes.push_back("Econtour_bidirectional") ; 
	supertypes.push_back("Econtour_spiral") ; 
	supertypes.push_back("Ecenter_milling") ; 
	supertypes.push_back("Eexplicit") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "overlap" ,(StepNodeType) 22, (DWORD) &(this->overlap), "Epositive_ratio_measure", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "allow_multiple_passes" ,(StepNodeType) 7, (DWORD) &(this->allow_multiple_passes), "EBoolean", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Etwo5d_milling_strategy*/
////////////////////////////////////////////////////////////////////////////////
Etwo_axes::Etwo_axes(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Etwo_axes";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etool_direction") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etool_direction" ,(StepNodeType) 1, (DWORD) &(this->Etool_direction::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Etwo_axes*/
////////////////////////////////////////////////////////////////////////////////
Eunary_boolean_expression::Eunary_boolean_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eunary_boolean_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	supertypes.push_back("Enot_expression") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eboolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Eboolean_expression::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "operand" ,(StepNodeType) 22, (DWORD) &(this->operand), "Eboolean_expression", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eunary_boolean_expression*/
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
////////////////////////////////////////////////////////////////////////////////
Euniform_curve::Euniform_curve(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Euniform_curve";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_curve::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Euniform_curve*/
////////////////////////////////////////////////////////////////////////////////
Euniform_surface::Euniform_surface(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Euniform_surface";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eb_spline_surface") ; 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->Eb_spline_surface::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Euniform_surface*/
////////////////////////////////////////////////////////////////////////////////
Eunload_tool::Eunload_tool(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eunload_tool";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_tool" ,(StepNodeType) 22, (DWORD) &(this->its_tool), "Emachining_tool", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eunload_tool*/
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
////////////////////////////////////////////////////////////////////////////////
Evector::Evector(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Evector";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Egeometric_representation_item::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 22, (DWORD) &(this->orientation), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "magnitude" ,(StepNodeType) 22, (DWORD) &(this->magnitude), "Elength_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Evector*/
////////////////////////////////////////////////////////////////////////////////
Evee_profile::Evee_profile(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Evee_profile";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eopen_profile") ; 
	parents.push_back("Eprofile") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eopen_profile" ,(StepNodeType) 1, (DWORD) &(this->Eopen_profile::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "profile_radius" ,(StepNodeType) 22, (DWORD) &(this->profile_radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "profile_angle" ,(StepNodeType) 22, (DWORD) &(this->profile_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "tilt_angle" ,(StepNodeType) 22, (DWORD) &(this->tilt_angle), "Eplane_angle_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Evee_profile*/
////////////////////////////////////////////////////////////////////////////////
Evertex::Evertex(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Evertex";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	supertypes.push_back("Evertex_point") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->Etopological_representation_item::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Evertex*/
////////////////////////////////////////////////////////////////////////////////
Evertex_loop::Evertex_loop(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Evertex_loop";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eloop") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eloop" ,(StepNodeType) 1, (DWORD) &(this->Eloop::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "loop_vertex" ,(StepNodeType) 22, (DWORD) &(this->loop_vertex), "Evertex", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Evertex_loop*/
////////////////////////////////////////////////////////////////////////////////
Evertex_point::Evertex_point(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Evertex_point";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Evertex") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Evertex" ,(StepNodeType) 1, (DWORD) &(this->Evertex::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "vertex_geometry" ,(StepNodeType) 22, (DWORD) &(this->vertex_geometry), "Epoint", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Evertex_point*/
////////////////////////////////////////////////////////////////////////////////
Ewait_for_mark::Ewait_for_mark(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ewait_for_mark";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Enc_function") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Enc_function" ,(StepNodeType) 1, (DWORD) &(this->Enc_function::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_channel" ,(StepNodeType) 22, (DWORD) &(this->its_channel), "Echannel", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ewait_for_mark*/
////////////////////////////////////////////////////////////////////////////////
Eweek_of_year_and_day_date::Eweek_of_year_and_day_date(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eweek_of_year_and_day_date";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Edate") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Edate" ,(StepNodeType) 1, (DWORD) &(this->Edate::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "week_component" ,(StepNodeType) 22, (DWORD) &(this->week_component), "Eweek_in_year_number", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "day_component" ,(StepNodeType) 22, (DWORD) &(this->day_component), "Eday_in_week_number", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eweek_of_year_and_day_date*/
////////////////////////////////////////////////////////////////////////////////
Ewhile_statement::Ewhile_statement(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ewhile_statement";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprogram_structure") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprogram_structure" ,(StepNodeType) 1, (DWORD) &(this->Eprogram_structure::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "condition" ,(StepNodeType) 22, (DWORD) &(this->condition), "Eboolean_expression", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "body" ,(StepNodeType) 22, (DWORD) &(this->body), "Eexecutable", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ewhile_statement*/
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
////////////////////////////////////////////////////////////////////////////////
Ewoodruff_slot_end_type::Ewoodruff_slot_end_type(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Ewoodruff_slot_end_type";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eslot_end_type") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eslot_end_type" ,(StepNodeType) 1, (DWORD) &(this->Eslot_end_type::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Ewoodruff_slot_end_type*/
////////////////////////////////////////////////////////////////////////////////
Eworkingstep::Eworkingstep(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eworkingstep";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	supertypes.push_back("Emachining_workingstep") ; 
	supertypes.push_back("Erapid_movement") ; 
	supertypes.push_back("Etouch_probing") ; 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eexecutable" ,(StepNodeType) 1, (DWORD) &(this->Eexecutable::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_secplane" ,(StepNodeType) 22, (DWORD) &(this->its_secplane), "Eelementary_surface", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eworkingstep*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece::Eworkpiece(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eworkpiece";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_id" ,(StepNodeType) 22, (DWORD) &(this->its_id), "Eidentifier", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_material" ,(StepNodeType) 22, (DWORD) &(this->its_material), "Ematerial", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "global_tolerance" ,(StepNodeType) 22, (DWORD) &(this->global_tolerance), "Eshape_tolerance", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_rawpiece" ,(StepNodeType) 22, (DWORD) &(this->its_rawpiece), "Eworkpiece", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_geometry" ,(StepNodeType) 22, (DWORD) &(this->its_geometry), "Eadvanced_brep_shape_representation", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_bounding_geometry" ,(StepNodeType) 22, (DWORD) &(this->its_bounding_geometry), "Ebounding_geometry_select", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "clamping_positions" ,(StepNodeType) 13, (DWORD) &(this->clamping_positions), "EListT<Ecartesian_pointPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Ecartesian_point");
	clamping_positions.ListClassname()="Ecartesian_point"; 
	clamping_positions.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eworkpiece*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece_complete_probing::Eworkpiece_complete_probing(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eworkpiece_complete_probing";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etouch_probing") ; 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etouch_probing" ,(StepNodeType) 1, (DWORD) &(this->Etouch_probing::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_workpiece" ,(StepNodeType) 22, (DWORD) &(this->its_workpiece), "Eworkpiece", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "probing_distance" ,(StepNodeType) 22, (DWORD) &(this->probing_distance), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_probe" ,(StepNodeType) 22, (DWORD) &(this->its_probe), "Etouch_probe", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "computed_offset" ,(StepNodeType) 22, (DWORD) &(this->computed_offset), "Eoffset_vector", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eworkpiece_complete_probing*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece_probing::Eworkpiece_probing(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eworkpiece_probing";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Etouch_probing") ; 
	parents.push_back("Eworkingstep") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Etouch_probing" ,(StepNodeType) 1, (DWORD) &(this->Etouch_probing::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "start_position" ,(StepNodeType) 22, (DWORD) &(this->start_position), "Eaxis2_placement_3d", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_workpiece" ,(StepNodeType) 22, (DWORD) &(this->its_workpiece), "Eworkpiece", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_direction" ,(StepNodeType) 22, (DWORD) &(this->its_direction), "Edirection", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "expected_value" ,(StepNodeType) 22, (DWORD) &(this->expected_value), "Etoleranced_length_measure", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_probe" ,(StepNodeType) 22, (DWORD) &(this->its_probe), "Etouch_probe", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eworkpiece_probing*/
////////////////////////////////////////////////////////////////////////////////
Eworkpiece_setup::Eworkpiece_setup(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eworkpiece_setup";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "its_workpiece" ,(StepNodeType) 22, (DWORD) &(this->its_workpiece), "Eworkpiece", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_origin" ,(StepNodeType) 22, (DWORD) &(this->its_origin), "Eaxis2_placement_3d", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_offset" ,(StepNodeType) 22, (DWORD) &(this->its_offset), "Eoffset_vector", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_restricted_area" ,(StepNodeType) 22, (DWORD) &(this->its_restricted_area), "Erestricted_area_select", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_instructions" ,(StepNodeType) 13, (DWORD) &(this->its_instructions), "EListT<Esetup_instructionPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Esetup_instruction");
	its_instructions.ListClassname()="Esetup_instruction"; 
	its_instructions.ListType()=(StepNodeType)  22; 
	BuildInstanceDef(vars, instancevars);
} /* End Eworkpiece_setup*/
////////////////////////////////////////////////////////////////////////////////
Eworkplan::Eworkplan(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Eworkplan";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Eprogram_structure") ; 
	parents.push_back("Eexecutable") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Eprogram_structure" ,(StepNodeType) 1, (DWORD) &(this->Eprogram_structure::vars),"Baseclass"));
	vars.push_back(new CVarDef(this, "its_elements" ,(StepNodeType) 13, (DWORD) &(this->its_elements), "EListT<EexecutablePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eexecutable");
	its_elements.ListClassname()="Eexecutable"; 
	its_elements.ListType()=(StepNodeType)  22; 
	vars.push_back(new CVarDef(this, "its_channel" ,(StepNodeType) 22, (DWORD) &(this->its_channel), "Echannel", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_setup" ,(StepNodeType) 22, (DWORD) &(this->its_setup), "Esetup", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "its_effect" ,(StepNodeType) 22, (DWORD) &(this->its_effect), "Ein_process_geometry", 1));
	vars.back()->Init(0, (StepNodeType)  0, "");
	BuildInstanceDef(vars, instancevars);
} /* End Eworkplan*/
////////////////////////////////////////////////////////////////////////////////
Exor_expression::Exor_expression(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Exor_expression";
	m_def.m_pVars=&vars;
	parents.clear(); 
	parents.push_back("Ebinary_boolean_expression") ; 
	parents.push_back("Eboolean_expression") ; 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "Ebinary_boolean_expression" ,(StepNodeType) 1, (DWORD) &(this->Ebinary_boolean_expression::vars),"Baseclass"));
	BuildInstanceDef(vars, instancevars);
} /* End Exor_expression*/
Eday_in_month_number::Eday_in_month_number()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eday_in_month_number";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Emonth_in_year_number::Emonth_in_year_number()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Emonth_in_year_number";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Eday_in_year_number::Eday_in_year_number()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eday_in_year_number";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Eweek_in_year_number::Eweek_in_year_number()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eweek_in_year_number";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Eday_in_week_number::Eday_in_week_number()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eday_in_week_number";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Ehour_in_day::Ehour_in_day()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Ehour_in_day";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Eminute_in_hour::Eminute_in_hour()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eminute_in_hour";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Esecond_in_minute::Esecond_in_minute()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Esecond_in_minute";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Eahead_or_behind::Eahead_or_behind()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 3; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eahead_or_behind";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Eyear_number::Eyear_number()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eyear_number";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Eidentifier::Eidentifier()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eidentifier";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EString"); 
}
Elabel::Elabel()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Elabel";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EString"); 
}
Etext::Etext()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Etext";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EString"); 
}
Elength_measure::Elength_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Elength_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Eparameter_value::Eparameter_value()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eparameter_value";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Eplane_angle_measure::Eplane_angle_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eplane_angle_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Epositive_length_measure::Epositive_length_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Epositive_length_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "Elength_measure" ,(StepNodeType) 1, (DWORD) &(this->Elength_measure::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("Elength_measure"); 
}
Epositive_ratio_measure::Epositive_ratio_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Epositive_ratio_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "Eratio_measure" ,(StepNodeType) 1, (DWORD) &(this->Eratio_measure::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("Eratio_measure"); 
}
Eratio_measure::Eratio_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eratio_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Etime_measure::Etime_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Etime_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
	Etrimming_select::Etrimming_select()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Ecartesian_point" ,(StepNodeType) 18, (DWORD) &(this->_Ecartesian_point),"_Ecartesian_point"));

	SetSelection(_Ecartesian_point); 
	vars.push_back(new CVarDef(this, "_Eparameter_value" ,(StepNodeType) 4, (DWORD) &(this->_Eparameter_value),"_Eparameter_value"));
}
Etrimming_preference::Etrimming_preference()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 3; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Etrimming_preference";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Etransition_code::Etransition_code()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 4; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Etransition_code";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Eb_spline_curve_form::Eb_spline_curve_form()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 6; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eb_spline_curve_form";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Eb_spline_surface_form::Eb_spline_surface_form()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 11; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eb_spline_surface_form";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Edimension_count::Edimension_count()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Edimension_count";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EInteger"); 
}
Eknot_type::Eknot_type()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 4; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eknot_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
	Epcurve_or_surface::Epcurve_or_surface()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Epcurve" ,(StepNodeType) 18, (DWORD) &(this->_Epcurve),"_Epcurve"));

	SetSelection(_Epcurve); 
	vars.push_back(new CVarDef(this, "_Esurface" ,(StepNodeType) 18, (DWORD) &(this->_Esurface),"_Esurface"));
}
	Evector_or_direction::Evector_or_direction()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Evector" ,(StepNodeType) 18, (DWORD) &(this->_Evector),"_Evector"));

	SetSelection(_Evector); 
	vars.push_back(new CVarDef(this, "_Edirection" ,(StepNodeType) 18, (DWORD) &(this->_Edirection),"_Edirection"));
}
	Etolerance_select::Etolerance_select()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Eplus_minus_value" ,(StepNodeType) 18, (DWORD) &(this->_Eplus_minus_value),"_Eplus_minus_value"));

	SetSelection(_Eplus_minus_value); 
	vars.push_back(new CVarDef(this, "_Elimits_and_fits" ,(StepNodeType) 18, (DWORD) &(this->_Elimits_and_fits),"_Elimits_and_fits"));
}
Efitting_type::Efitting_type()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 2; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Efitting_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Espeed_measure::Espeed_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Espeed_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Erot_speed_measure::Erot_speed_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Erot_speed_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Epressure_measure::Epressure_measure()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Epressure_measure";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EReal"); 
}
Erot_direction::Erot_direction()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 2; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Erot_direction";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Eshape_tolerance::Eshape_tolerance()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eshape_tolerance";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "Elength_measure" ,(StepNodeType) 1, (DWORD) &(this->Elength_measure::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("Elength_measure"); 
}
	Ebounding_geometry_select::Ebounding_geometry_select()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Eblock" ,(StepNodeType) 18, (DWORD) &(this->_Eblock),"_Eblock"));

	SetSelection(_Eblock); 
	vars.push_back(new CVarDef(this, "_Eright_circular_cylinder" ,(StepNodeType) 18, (DWORD) &(this->_Eright_circular_cylinder),"_Eright_circular_cylinder"));
	vars.push_back(new CVarDef(this, "_Eadvanced_brep_shape_representation" ,(StepNodeType) 18, (DWORD) &(this->_Eadvanced_brep_shape_representation),"_Eadvanced_brep_shape_representation"));
}
	Eprofile_select::Eprofile_select()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Ethrough_profile_floor" ,(StepNodeType) 18, (DWORD) &(this->_Ethrough_profile_floor),"_Ethrough_profile_floor"));

	SetSelection(_Ethrough_profile_floor); 
	vars.push_back(new CVarDef(this, "_Eprofile_floor" ,(StepNodeType) 18, (DWORD) &(this->_Eprofile_floor),"_Eprofile_floor"));
}
	Etaper_select::Etaper_select()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Ediameter_taper" ,(StepNodeType) 18, (DWORD) &(this->_Ediameter_taper),"_Ediameter_taper"));

	SetSelection(_Ediameter_taper); 
	vars.push_back(new CVarDef(this, "_Eangle_taper" ,(StepNodeType) 18, (DWORD) &(this->_Eangle_taper),"_Eangle_taper"));
}
	Ecompound_feature_select::Ecompound_feature_select()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Emachining_feature" ,(StepNodeType) 18, (DWORD) &(this->_Emachining_feature),"_Emachining_feature"));

	SetSelection(_Emachining_feature); 
	vars.push_back(new CVarDef(this, "_Etransition_feature" ,(StepNodeType) 18, (DWORD) &(this->_Etransition_feature),"_Etransition_feature"));
}
Ebottom_or_side::Ebottom_or_side()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 3; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Ebottom_or_side";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
	Erestricted_area_select::Erestricted_area_select()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Ebounded_surface" ,(StepNodeType) 18, (DWORD) &(this->_Ebounded_surface),"_Ebounded_surface"));

	SetSelection(_Ebounded_surface); 
	vars.push_back(new CVarDef(this, "_Ebounding_geometry_select" ,(StepNodeType) 21, (DWORD) &(this->_Ebounding_geometry_select),"_Ebounding_geometry_select"));
}
	Ervalue::Ervalue()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Enc_constant" ,(StepNodeType) 18, (DWORD) &(this->_Enc_constant),"_Enc_constant"));

	SetSelection(_Enc_constant); 
	vars.push_back(new CVarDef(this, "_Enc_variable" ,(StepNodeType) 18, (DWORD) &(this->_Enc_variable),"_Enc_variable"));
}
Etool_reference_point::Etool_reference_point()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 2; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Etool_reference_point";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Etoolpath_type::Etoolpath_type()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 6; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Etoolpath_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
	Etoolpath_speedprofile::Etoolpath_speedprofile()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Etoolpath_speed" ,(StepNodeType) 18, (DWORD) &(this->_Etoolpath_speed),"_Etoolpath_speed"));

	SetSelection(_Etoolpath_speed); 
	vars.push_back(new CVarDef(this, "_Epositive_ratio_measure" ,(StepNodeType) 33, (DWORD) &(this->_Epositive_ratio_measure),"_Epositive_ratio_measure"));
	vars.push_back(new CVarDef(this, "_Espeed_name" ,(StepNodeType) 20, (DWORD) &(this->_Espeed_name),"_Espeed_name"));
}
Espeed_name::Espeed_name()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 1; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Espeed_name";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
	Ecurve_with_surface_normal::Ecurve_with_surface_normal()
{

	this->_eType= select_; 
	vars.push_back(new CVarDef(this, "_Ebounded_pcurve" ,(StepNodeType) 18, (DWORD) &(this->_Ebounded_pcurve),"_Ebounded_pcurve"));

	SetSelection(_Ebounded_pcurve); 
	vars.push_back(new CVarDef(this, "_Ecurve_with_normal_vector" ,(StepNodeType) 18, (DWORD) &(this->_Ecurve_with_normal_vector),"_Ecurve_with_normal_vector"));
}
Econtact_type::Econtact_type()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 2; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Econtact_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Ehand::Ehand()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 3; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Ehand";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Epathmode_type::Epathmode_type()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 2; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Epathmode_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Ecutmode_type::Ecutmode_type()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 2; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Ecutmode_type";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Eleft_or_right::Eleft_or_right()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 2; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eleft_or_right";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
Estroke_connection_strategy::Estroke_connection_strategy()
{
 	this->_eType= enumeration_; 
	this->_nSelection= 4; 
	parents.clear(); 
	parents.push_back("Eenum"); 
	supertypes.clear(); 
	supertypes.push_back("Eenum"); 
	m_def.m_pClass=(DWORD)this;
	Classname()="Estroke_connection_strategy";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
}
IStepNodePtr Createstepnc_schemaClass(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname=="Eadaptive_control") return Eadaptive_control::Create(name);
	if(classname=="Eaddress") return Eaddress::Create(name);
	if(classname=="Eadvanced_brep_shape_representation") return Eadvanced_brep_shape_representation::Create(name);
	if(classname=="Eadvanced_face") return Eadvanced_face::Create(name);
	if(classname=="Eair_strategy") return Eair_strategy::Create(name);
	if(classname=="Ealong_path") return Ealong_path::Create(name);
	if(classname=="Eand_expression") return Eand_expression::Create(name);
	if(classname=="Eangle_taper") return Eangle_taper::Create(name);
	if(classname=="Eap_lift_path_angle") return Eap_lift_path_angle::Create(name);
	if(classname=="Eap_lift_path_tangent") return Eap_lift_path_tangent::Create(name);
	if(classname=="Eap_retract_angle") return Eap_retract_angle::Create(name);
	if(classname=="Eap_retract_tangent") return Eap_retract_tangent::Create(name);
	if(classname=="Eapproach_lift_path") return Eapproach_lift_path::Create(name);
	if(classname=="Eapproach_retract_strategy") return Eapproach_retract_strategy::Create(name);
	if(classname=="Eapproval") return Eapproval::Create(name);
	if(classname=="Eapproval_status") return Eapproval_status::Create(name);
	if(classname=="Eassignment") return Eassignment::Create(name);
	if(classname=="Eaxis1_placement") return Eaxis1_placement::Create(name);
	if(classname=="Eaxis2_placement_3d") return Eaxis2_placement_3d::Create(name);
	if(classname=="Eaxis_trajectory") return Eaxis_trajectory::Create(name);
	if(classname=="Eb_spline_curve") return Eb_spline_curve::Create(name);
	if(classname=="Eb_spline_curve_with_knots") return Eb_spline_curve_with_knots::Create(name);
	if(classname=="Eb_spline_surface") return Eb_spline_surface::Create(name);
	if(classname=="Eb_spline_surface_with_knots") return Eb_spline_surface_with_knots::Create(name);
	if(classname=="Eback_boring") return Eback_boring::Create(name);
	if(classname=="Ebackside_counterbore") return Ebackside_counterbore::Create(name);
	if(classname=="Ebackside_countersink") return Ebackside_countersink::Create(name);
	if(classname=="Eball_endmill") return Eball_endmill::Create(name);
	if(classname=="Ebezier_curve") return Ebezier_curve::Create(name);
	if(classname=="Ebezier_surface") return Ebezier_surface::Create(name);
	if(classname=="Ebidirectional") return Ebidirectional::Create(name);
	if(classname=="Ebidirectional_contour") return Ebidirectional_contour::Create(name);
	if(classname=="Ebinary_boolean_expression") return Ebinary_boolean_expression::Create(name);
	if(classname=="Eblind_bottom_condition") return Eblind_bottom_condition::Create(name);
	if(classname=="Eblock") return Eblock::Create(name);
	if(classname=="Eboolean_expression") return Eboolean_expression::Create(name);
	if(classname=="Eboring") return Eboring::Create(name);
	if(classname=="Eboring_operation") return Eboring_operation::Create(name);
	if(classname=="Eboring_tool") return Eboring_tool::Create(name);
	if(classname=="Eboss") return Eboss::Create(name);
	if(classname=="Ebottom_and_side_finish_milling") return Ebottom_and_side_finish_milling::Create(name);
	if(classname=="Ebottom_and_side_milling") return Ebottom_and_side_milling::Create(name);
	if(classname=="Ebottom_and_side_rough_milling") return Ebottom_and_side_rough_milling::Create(name);
	if(classname=="Ebounded_curve") return Ebounded_curve::Create(name);
	if(classname=="Ebounded_pcurve") return Ebounded_pcurve::Create(name);
	if(classname=="Ebounded_surface") return Ebounded_surface::Create(name);
	if(classname=="Ebullnose_endmill") return Ebullnose_endmill::Create(name);
	if(classname=="Ecalendar_date") return Ecalendar_date::Create(name);
	if(classname=="Ecartesian_point") return Ecartesian_point::Create(name);
	if(classname=="Ecatalogue_thread") return Ecatalogue_thread::Create(name);
	if(classname=="Ecenter_drill") return Ecenter_drill::Create(name);
	if(classname=="Ecenter_drilling") return Ecenter_drilling::Create(name);
	if(classname=="Ecenter_milling") return Ecenter_milling::Create(name);
	if(classname=="Echamfer") return Echamfer::Create(name);
	if(classname=="Echannel") return Echannel::Create(name);
	if(classname=="Ecircle") return Ecircle::Create(name);
	if(classname=="Ecircular_closed_profile") return Ecircular_closed_profile::Create(name);
	if(classname=="Ecircular_closed_shape_profile") return Ecircular_closed_shape_profile::Create(name);
	if(classname=="Ecircular_offset") return Ecircular_offset::Create(name);
	if(classname=="Ecircular_omit") return Ecircular_omit::Create(name);
	if(classname=="Ecircular_path") return Ecircular_path::Create(name);
	if(classname=="Ecircular_pattern") return Ecircular_pattern::Create(name);
	if(classname=="Eclosed_pocket") return Eclosed_pocket::Create(name);
	if(classname=="Eclosed_profile") return Eclosed_profile::Create(name);
	if(classname=="Eclosed_shell") return Eclosed_shell::Create(name);
	if(classname=="Ecombined_drill_and_reamer") return Ecombined_drill_and_reamer::Create(name);
	if(classname=="Ecombined_drill_and_tap") return Ecombined_drill_and_tap::Create(name);
	if(classname=="Ecomparison_equal") return Ecomparison_equal::Create(name);
	if(classname=="Ecomparison_expression") return Ecomparison_expression::Create(name);
	if(classname=="Ecomparison_greater") return Ecomparison_greater::Create(name);
	if(classname=="Ecomparison_greater_equal") return Ecomparison_greater_equal::Create(name);
	if(classname=="Ecomparison_less") return Ecomparison_less::Create(name);
	if(classname=="Ecomparison_less_equal") return Ecomparison_less_equal::Create(name);
	if(classname=="Ecomparison_not_equal") return Ecomparison_not_equal::Create(name);
	if(classname=="Ecomplete_circular_path") return Ecomplete_circular_path::Create(name);
	if(classname=="Ecomposite_curve") return Ecomposite_curve::Create(name);
	if(classname=="Ecomposite_curve_segment") return Ecomposite_curve_segment::Create(name);
	if(classname=="Ecompound_feature") return Ecompound_feature::Create(name);
	if(classname=="Econic") return Econic::Create(name);
	if(classname=="Econical_hole_bottom") return Econical_hole_bottom::Create(name);
	if(classname=="Econnect_direct") return Econnect_direct::Create(name);
	if(classname=="Econnect_secplane") return Econnect_secplane::Create(name);
	if(classname=="Econnected_face_set") return Econnected_face_set::Create(name);
	if(classname=="Econnector") return Econnector::Create(name);
	if(classname=="Econtour_bidirectional") return Econtour_bidirectional::Create(name);
	if(classname=="Econtour_parallel") return Econtour_parallel::Create(name);
	if(classname=="Econtour_spiral") return Econtour_spiral::Create(name);
	if(classname=="Ecoordinated_universal_time_offset") return Ecoordinated_universal_time_offset::Create(name);
	if(classname=="Ecounter_sinking") return Ecounter_sinking::Create(name);
	if(classname=="Ecounterbore") return Ecounterbore::Create(name);
	if(classname=="Ecounterbore_hole") return Ecounterbore_hole::Create(name);
	if(classname=="Ecountersink") return Ecountersink::Create(name);
	if(classname=="Ecountersunk_hole") return Ecountersunk_hole::Create(name);
	if(classname=="Ecurve") return Ecurve::Create(name);
	if(classname=="Ecurve_with_normal_vector") return Ecurve_with_normal_vector::Create(name);
	if(classname=="Ecutter_contact_trajectory") return Ecutter_contact_trajectory::Create(name);
	if(classname=="Ecutter_location_trajectory") return Ecutter_location_trajectory::Create(name);
	if(classname=="Ecutting_component") return Ecutting_component::Create(name);
	if(classname=="Ecutting_edge_technological_data") return Ecutting_edge_technological_data::Create(name);
	if(classname=="Ecutting_tool") return Ecutting_tool::Create(name);
	if(classname=="Edate") return Edate::Create(name);
	if(classname=="Edate_and_time") return Edate_and_time::Create(name);
	if(classname=="Edefined_thread") return Edefined_thread::Create(name);
	if(classname=="Edefinitional_representation") return Edefinitional_representation::Create(name);
	if(classname=="Edescriptive_parameter") return Edescriptive_parameter::Create(name);
	if(classname=="Ediameter_taper") return Ediameter_taper::Create(name);
	if(classname=="Edirection") return Edirection::Create(name);
	if(classname=="Edisplay_message") return Edisplay_message::Create(name);
	if(classname=="Edovetail_mill") return Edovetail_mill::Create(name);
	if(classname=="Edrill") return Edrill::Create(name);
	if(classname=="Edrilling") return Edrilling::Create(name);
	if(classname=="Edrilling_operation") return Edrilling_operation::Create(name);
	if(classname=="Edrilling_type_operation") return Edrilling_type_operation::Create(name);
	if(classname=="Edrilling_type_strategy") return Edrilling_type_strategy::Create(name);
	if(classname=="Eedge") return Eedge::Create(name);
	if(classname=="Eedge_curve") return Eedge_curve::Create(name);
	if(classname=="Eedge_loop") return Eedge_loop::Create(name);
	if(classname=="Eedge_round") return Eedge_round::Create(name);
	if(classname=="Eelementary_surface") return Eelementary_surface::Create(name);
	if(classname=="Eellipse") return Eellipse::Create(name);
	if(classname=="Eendmill") return Eendmill::Create(name);
	if(classname=="Eexchange_pallet") return Eexchange_pallet::Create(name);
	if(classname=="Eexecutable") return Eexecutable::Create(name);
	if(classname=="Eexplicit") return Eexplicit::Create(name);
	if(classname=="Eface") return Eface::Create(name);
	if(classname=="Eface_bound") return Eface_bound::Create(name);
	if(classname=="Eface_outer_bound") return Eface_outer_bound::Create(name);
	if(classname=="Eface_surface") return Eface_surface::Create(name);
	if(classname=="Efacemill") return Efacemill::Create(name);
	if(classname=="Efeedstop") return Efeedstop::Create(name);
	if(classname=="Efive_axes_const_tilt_yaw") return Efive_axes_const_tilt_yaw::Create(name);
	if(classname=="Efive_axes_var_tilt_yaw") return Efive_axes_var_tilt_yaw::Create(name);
	if(classname=="Eflat_hole_bottom") return Eflat_hole_bottom::Create(name);
	if(classname=="Eflat_slot_end_type") return Eflat_slot_end_type::Create(name);
	if(classname=="Eflat_with_radius_hole_bottom") return Eflat_with_radius_hole_bottom::Create(name);
	if(classname=="Efreeform_operation") return Efreeform_operation::Create(name);
	if(classname=="Efreeform_strategy") return Efreeform_strategy::Create(name);
	if(classname=="Egeneral_closed_profile") return Egeneral_closed_profile::Create(name);
	if(classname=="Egeneral_outside_profile") return Egeneral_outside_profile::Create(name);
	if(classname=="Egeneral_path") return Egeneral_path::Create(name);
	if(classname=="Egeneral_pattern") return Egeneral_pattern::Create(name);
	if(classname=="Egeneral_pocket_bottom_condition") return Egeneral_pocket_bottom_condition::Create(name);
	if(classname=="Egeneral_profile") return Egeneral_profile::Create(name);
	if(classname=="Egeneral_profile_floor") return Egeneral_profile_floor::Create(name);
	if(classname=="Egeneral_shape_profile") return Egeneral_shape_profile::Create(name);
	if(classname=="Egeometric_representation_context") return Egeometric_representation_context::Create(name);
	if(classname=="Egeometric_representation_item") return Egeometric_representation_item::Create(name);
	if(classname=="Ehole_bottom_condition") return Ehole_bottom_condition::Create(name);
	if(classname=="Ehyperbola") return Ehyperbola::Create(name);
	if(classname=="Eif_statement") return Eif_statement::Create(name);
	if(classname=="Ein_process_geometry") return Ein_process_geometry::Create(name);
	if(classname=="Eindex_pallet") return Eindex_pallet::Create(name);
	if(classname=="Eindex_table") return Eindex_table::Create(name);
	if(classname=="Eleading_line_strategy") return Eleading_line_strategy::Create(name);
	if(classname=="Elimits_and_fits") return Elimits_and_fits::Create(name);
	if(classname=="Eline") return Eline::Create(name);
	if(classname=="Elinear_path") return Elinear_path::Create(name);
	if(classname=="Elinear_profile") return Elinear_profile::Create(name);
	if(classname=="Eload_tool") return Eload_tool::Create(name);
	if(classname=="Elocal_time") return Elocal_time::Create(name);
	if(classname=="Eloop") return Eloop::Create(name);
	if(classname=="Eloop_slot_end_type") return Eloop_slot_end_type::Create(name);
	if(classname=="Emachine_functions") return Emachine_functions::Create(name);
	if(classname=="Emachined_surface") return Emachined_surface::Create(name);
	if(classname=="Emachining_feature") return Emachining_feature::Create(name);
	if(classname=="Emachining_operation") return Emachining_operation::Create(name);
	if(classname=="Emachining_tool") return Emachining_tool::Create(name);
	if(classname=="Emachining_workingstep") return Emachining_workingstep::Create(name);
	if(classname=="Emanifold_solid_brep") return Emanifold_solid_brep::Create(name);
	if(classname=="Emanufacturing_feature") return Emanufacturing_feature::Create(name);
	if(classname=="Ematerial") return Ematerial::Create(name);
	if(classname=="Emilling_cutter") return Emilling_cutter::Create(name);
	if(classname=="Emilling_cutting_tool") return Emilling_cutting_tool::Create(name);
	if(classname=="Emilling_machine_functions") return Emilling_machine_functions::Create(name);
	if(classname=="Emilling_machining_operation") return Emilling_machining_operation::Create(name);
	if(classname=="Emilling_technology") return Emilling_technology::Create(name);
	if(classname=="Emilling_tool_body") return Emilling_tool_body::Create(name);
	if(classname=="Emilling_tool_dimension") return Emilling_tool_dimension::Create(name);
	if(classname=="Emilling_type_operation") return Emilling_type_operation::Create(name);
	if(classname=="Emultiple_arity_boolean_expression") return Emultiple_arity_boolean_expression::Create(name);
	if(classname=="Emultistep_drilling") return Emultistep_drilling::Create(name);
	if(classname=="Enc_constant") return Enc_constant::Create(name);
	if(classname=="Enc_function") return Enc_function::Create(name);
	if(classname=="Enc_variable") return Enc_variable::Create(name);
	if(classname=="Engon_profile") return Engon_profile::Create(name);
	if(classname=="Enon_sequential") return Enon_sequential::Create(name);
	if(classname=="Enot_expression") return Enot_expression::Create(name);
	if(classname=="Enumeric_parameter") return Enumeric_parameter::Create(name);
	if(classname=="Eoffset_vector") return Eoffset_vector::Create(name);
	if(classname=="Eopen_pocket") return Eopen_pocket::Create(name);
	if(classname=="Eopen_profile") return Eopen_profile::Create(name);
	if(classname=="Eopen_shell") return Eopen_shell::Create(name);
	if(classname=="Eopen_slot_end_type") return Eopen_slot_end_type::Create(name);
	if(classname=="Eoperation") return Eoperation::Create(name);
	if(classname=="Eoptional_stop") return Eoptional_stop::Create(name);
	if(classname=="Eor_expression") return Eor_expression::Create(name);
	if(classname=="Eordinal_date") return Eordinal_date::Create(name);
	if(classname=="Eoriented_edge") return Eoriented_edge::Create(name);
	if(classname=="Eparabola") return Eparabola::Create(name);
	if(classname=="Eparallel") return Eparallel::Create(name);
	if(classname=="Eparameterised_path") return Eparameterised_path::Create(name);
	if(classname=="Epartial_area_definition") return Epartial_area_definition::Create(name);
	if(classname=="Epartial_circular_path") return Epartial_circular_path::Create(name);
	if(classname=="Epartial_circular_profile") return Epartial_circular_profile::Create(name);
	if(classname=="Epartial_circular_shape_profile") return Epartial_circular_shape_profile::Create(name);
	if(classname=="Epath") return Epath::Create(name);
	if(classname=="Epcurve") return Epcurve::Create(name);
	if(classname=="Eperson") return Eperson::Create(name);
	if(classname=="Eperson_and_address") return Eperson_and_address::Create(name);
	if(classname=="Eplacement") return Eplacement::Create(name);
	if(classname=="Eplanar_face") return Eplanar_face::Create(name);
	if(classname=="Eplanar_pocket_bottom_condition") return Eplanar_pocket_bottom_condition::Create(name);
	if(classname=="Eplanar_profile_floor") return Eplanar_profile_floor::Create(name);
	if(classname=="Eplane") return Eplane::Create(name);
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
	if(classname=="Eplus_minus_value") return Eplus_minus_value::Create(name);
	if(classname=="Epocket") return Epocket::Create(name);
	if(classname=="Epocket_bottom_condition") return Epocket_bottom_condition::Create(name);
	if(classname=="Epoint") return Epoint::Create(name);
	if(classname=="Epolyline") return Epolyline::Create(name);
	if(classname=="Eprocess_model") return Eprocess_model::Create(name);
	if(classname=="Eprocess_model_list") return Eprocess_model_list::Create(name);
	if(classname=="Eprofile") return Eprofile::Create(name);
	if(classname=="Eprofile_feature") return Eprofile_feature::Create(name);
	if(classname=="Eprofile_floor") return Eprofile_floor::Create(name);
	if(classname=="Eprogram_stop") return Eprogram_stop::Create(name);
	if(classname=="Eprogram_structure") return Eprogram_structure::Create(name);
	if(classname=="Eproject") return Eproject::Create(name);
	if(classname=="Eproperty_parameter") return Eproperty_parameter::Create(name);
	if(classname=="Equasi_uniform_curve") return Equasi_uniform_curve::Create(name);
	if(classname=="Equasi_uniform_surface") return Equasi_uniform_surface::Create(name);
	if(classname=="Eradiused_pocket_bottom_condition") return Eradiused_pocket_bottom_condition::Create(name);
	if(classname=="Eradiused_slot_end_type") return Eradiused_slot_end_type::Create(name);
	if(classname=="Erapid_movement") return Erapid_movement::Create(name);
	if(classname=="Erational_b_spline_curve") return Erational_b_spline_curve::Create(name);
	if(classname=="Erational_b_spline_surface") return Erational_b_spline_surface::Create(name);
	if(classname=="Ereamer") return Ereamer::Create(name);
	if(classname=="Ereaming") return Ereaming::Create(name);
	if(classname=="Erectangular_closed_profile") return Erectangular_closed_profile::Create(name);
	if(classname=="Erectangular_closed_shape_profile") return Erectangular_closed_shape_profile::Create(name);
	if(classname=="Erectangular_offset") return Erectangular_offset::Create(name);
	if(classname=="Erectangular_omit") return Erectangular_omit::Create(name);
	if(classname=="Erectangular_open_shape_profile") return Erectangular_open_shape_profile::Create(name);
	if(classname=="Erectangular_pattern") return Erectangular_pattern::Create(name);
	if(classname=="Eregion") return Eregion::Create(name);
	if(classname=="Eregion_projection") return Eregion_projection::Create(name);
	if(classname=="Eregion_surface_list") return Eregion_surface_list::Create(name);
	if(classname=="Ereplicate_feature") return Ereplicate_feature::Create(name);
	if(classname=="Erepresentation") return Erepresentation::Create(name);
	if(classname=="Erepresentation_context") return Erepresentation_context::Create(name);
	if(classname=="Erepresentation_item") return Erepresentation_item::Create(name);
	if(classname=="Ereturn_home") return Ereturn_home::Create(name);
	if(classname=="Eright_circular_cylinder") return Eright_circular_cylinder::Create(name);
	if(classname=="Eround_hole") return Eround_hole::Create(name);
	if(classname=="Erounded_end") return Erounded_end::Create(name);
	if(classname=="Erounded_u_profile") return Erounded_u_profile::Create(name);
	if(classname=="Eselective") return Eselective::Create(name);
	if(classname=="Eset_mark") return Eset_mark::Create(name);
	if(classname=="Esetup") return Esetup::Create(name);
	if(classname=="Esetup_instruction") return Esetup_instruction::Create(name);
	if(classname=="Eshape_profile") return Eshape_profile::Create(name);
	if(classname=="Eshape_representation") return Eshape_representation::Create(name);
	if(classname=="Eside_finish_milling") return Eside_finish_milling::Create(name);
	if(classname=="Eside_mill") return Eside_mill::Create(name);
	if(classname=="Eside_milling") return Eside_milling::Create(name);
	if(classname=="Eside_rough_milling") return Eside_rough_milling::Create(name);
	if(classname=="Eslot") return Eslot::Create(name);
	if(classname=="Eslot_end_type") return Eslot_end_type::Create(name);
	if(classname=="Esolid_model") return Esolid_model::Create(name);
	if(classname=="Espade_drill") return Espade_drill::Create(name);
	if(classname=="Especification") return Especification::Create(name);
	if(classname=="Especification_usage_constraint") return Especification_usage_constraint::Create(name);
	if(classname=="Espherical_cap") return Espherical_cap::Create(name);
	if(classname=="Espherical_hole_bottom") return Espherical_hole_bottom::Create(name);
	if(classname=="Espherical_surface") return Espherical_surface::Create(name);
	if(classname=="Esquare_u_profile") return Esquare_u_profile::Create(name);
	if(classname=="Estep") return Estep::Create(name);
	if(classname=="Esurface") return Esurface::Create(name);
	if(classname=="Esurface_of_linear_extrusion") return Esurface_of_linear_extrusion::Create(name);
	if(classname=="Esurface_of_revolution") return Esurface_of_revolution::Create(name);
	if(classname=="Esurface_texture_parameter") return Esurface_texture_parameter::Create(name);
	if(classname=="Eswept_surface") return Eswept_surface::Create(name);
	if(classname=="Et_slot_mill") return Et_slot_mill::Create(name);
	if(classname=="Etap") return Etap::Create(name);
	if(classname=="Etapered_drill") return Etapered_drill::Create(name);
	if(classname=="Etapered_endmill") return Etapered_endmill::Create(name);
	if(classname=="Etapered_reamer") return Etapered_reamer::Create(name);
	if(classname=="Etapered_tap") return Etapered_tap::Create(name);
	if(classname=="Etapping") return Etapping::Create(name);
	if(classname=="Etechnology") return Etechnology::Create(name);
	if(classname=="Etee_profile") return Etee_profile::Create(name);
	if(classname=="Ethread") return Ethread::Create(name);
	if(classname=="Ethread_drilling") return Ethread_drilling::Create(name);
	if(classname=="Ethread_mill") return Ethread_mill::Create(name);
	if(classname=="Ethreading_tool") return Ethreading_tool::Create(name);
	if(classname=="Ethree_axes") return Ethree_axes::Create(name);
	if(classname=="Ethree_axes_tilted_tool") return Ethree_axes_tilted_tool::Create(name);
	if(classname=="Ethrough_bottom_condition") return Ethrough_bottom_condition::Create(name);
	if(classname=="Ethrough_pocket_bottom_condition") return Ethrough_pocket_bottom_condition::Create(name);
	if(classname=="Ethrough_profile_floor") return Ethrough_profile_floor::Create(name);
	if(classname=="Etoleranced_length_measure") return Etoleranced_length_measure::Create(name);
	if(classname=="Etolerances") return Etolerances::Create(name);
	if(classname=="Etool_body") return Etool_body::Create(name);
	if(classname=="Etool_direction") return Etool_direction::Create(name);
	if(classname=="Etool_direction_for_milling") return Etool_direction_for_milling::Create(name);
	if(classname=="Etool_length_probing") return Etool_length_probing::Create(name);
	if(classname=="Etool_probing") return Etool_probing::Create(name);
	if(classname=="Etool_radius_probing") return Etool_radius_probing::Create(name);
	if(classname=="Etoolpath") return Etoolpath::Create(name);
	if(classname=="Etoolpath_feature") return Etoolpath_feature::Create(name);
	if(classname=="Etoolpath_list") return Etoolpath_list::Create(name);
	if(classname=="Etoolpath_speed") return Etoolpath_speed::Create(name);
	if(classname=="Etopological_region") return Etopological_region::Create(name);
	if(classname=="Etopological_representation_item") return Etopological_representation_item::Create(name);
	if(classname=="Etouch_probe") return Etouch_probe::Create(name);
	if(classname=="Etouch_probing") return Etouch_probing::Create(name);
	if(classname=="Etrajectory") return Etrajectory::Create(name);
	if(classname=="Etransition_feature") return Etransition_feature::Create(name);
	if(classname=="Etravel_path") return Etravel_path::Create(name);
	if(classname=="Etrimmed_curve") return Etrimmed_curve::Create(name);
	if(classname=="Etwist_drill") return Etwist_drill::Create(name);
	if(classname=="Etwo5d_manufacturing_feature") return Etwo5d_manufacturing_feature::Create(name);
	if(classname=="Etwo5d_milling_operation") return Etwo5d_milling_operation::Create(name);
	if(classname=="Etwo5d_milling_strategy") return Etwo5d_milling_strategy::Create(name);
	if(classname=="Etwo_axes") return Etwo_axes::Create(name);
	if(classname=="Eunary_boolean_expression") return Eunary_boolean_expression::Create(name);
	if(classname=="Eunidirectional") return Eunidirectional::Create(name);
	if(classname=="Euniform_curve") return Euniform_curve::Create(name);
	if(classname=="Euniform_surface") return Euniform_surface::Create(name);
	if(classname=="Eunload_tool") return Eunload_tool::Create(name);
	if(classname=="Euser_defined_tool") return Euser_defined_tool::Create(name);
	if(classname=="Euv_strategy") return Euv_strategy::Create(name);
	if(classname=="Evector") return Evector::Create(name);
	if(classname=="Evee_profile") return Evee_profile::Create(name);
	if(classname=="Evertex") return Evertex::Create(name);
	if(classname=="Evertex_loop") return Evertex_loop::Create(name);
	if(classname=="Evertex_point") return Evertex_point::Create(name);
	if(classname=="Ewait_for_mark") return Ewait_for_mark::Create(name);
	if(classname=="Eweek_of_year_and_day_date") return Eweek_of_year_and_day_date::Create(name);
	if(classname=="Ewhile_statement") return Ewhile_statement::Create(name);
	if(classname=="Ewoodruff_keyseat_mill") return Ewoodruff_keyseat_mill::Create(name);
	if(classname=="Ewoodruff_slot_end_type") return Ewoodruff_slot_end_type::Create(name);
	if(classname=="Eworkingstep") return Eworkingstep::Create(name);
	if(classname=="Eworkpiece") return Eworkpiece::Create(name);
	if(classname=="Eworkpiece_complete_probing") return Eworkpiece_complete_probing::Create(name);
	if(classname=="Eworkpiece_probing") return Eworkpiece_probing::Create(name);
	if(classname=="Eworkpiece_setup") return Eworkpiece_setup::Create(name);
	if(classname=="Eworkplan") return Eworkplan::Create(name);
	if(classname=="Exor_expression") return Exor_expression::Create(name);
	if(classname=="Eday_in_month_number") return  (IStepNodePtr) new Eday_in_month_number;
	if(classname=="Emonth_in_year_number") return  (IStepNodePtr) new Emonth_in_year_number;
	if(classname=="Eday_in_year_number") return  (IStepNodePtr) new Eday_in_year_number;
	if(classname=="Eweek_in_year_number") return  (IStepNodePtr) new Eweek_in_year_number;
	if(classname=="Eday_in_week_number") return  (IStepNodePtr) new Eday_in_week_number;
	if(classname=="Ehour_in_day") return  (IStepNodePtr) new Ehour_in_day;
	if(classname=="Eminute_in_hour") return  (IStepNodePtr) new Eminute_in_hour;
	if(classname=="Esecond_in_minute") return  (IStepNodePtr) new Esecond_in_minute;
	if(classname=="Eahead_or_behind") return Eahead_or_behind::Create(name);
	if(classname=="Eyear_number") return  (IStepNodePtr) new Eyear_number;
	if(classname=="Eidentifier") return  (IStepNodePtr) new Eidentifier;
	if(classname=="Elabel") return  (IStepNodePtr) new Elabel;
	if(classname=="Etext") return  (IStepNodePtr) new Etext;
	if(classname=="Elength_measure") return  (IStepNodePtr) new Elength_measure;
	if(classname=="Eparameter_value") return  (IStepNodePtr) new Eparameter_value;
	if(classname=="Eplane_angle_measure") return  (IStepNodePtr) new Eplane_angle_measure;
	if(classname=="Epositive_length_measure") return  (IStepNodePtr) new Epositive_length_measure;
	if(classname=="Epositive_ratio_measure") return  (IStepNodePtr) new Epositive_ratio_measure;
	if(classname=="Eratio_measure") return  (IStepNodePtr) new Eratio_measure;
	if(classname=="Etime_measure") return  (IStepNodePtr) new Etime_measure;
	if(classname=="Etrimming_select") return  (IStepNodePtr) new Etrimming_select;
	if(classname=="Etrimming_preference") return Etrimming_preference::Create(name);
	if(classname=="Etransition_code") return Etransition_code::Create(name);
	if(classname=="Eb_spline_curve_form") return Eb_spline_curve_form::Create(name);
	if(classname=="Eb_spline_surface_form") return Eb_spline_surface_form::Create(name);
	if(classname=="Edimension_count") return  (IStepNodePtr) new Edimension_count;
	if(classname=="Eknot_type") return Eknot_type::Create(name);
	if(classname=="Epcurve_or_surface") return  (IStepNodePtr) new Epcurve_or_surface;
	if(classname=="Evector_or_direction") return  (IStepNodePtr) new Evector_or_direction;
	if(classname=="Etolerance_select") return  (IStepNodePtr) new Etolerance_select;
	if(classname=="Efitting_type") return Efitting_type::Create(name);
	if(classname=="Espeed_measure") return  (IStepNodePtr) new Espeed_measure;
	if(classname=="Erot_speed_measure") return  (IStepNodePtr) new Erot_speed_measure;
	if(classname=="Epressure_measure") return  (IStepNodePtr) new Epressure_measure;
	if(classname=="Erot_direction") return Erot_direction::Create(name);
	if(classname=="Eshape_tolerance") return  (IStepNodePtr) new Eshape_tolerance;
	if(classname=="Ebounding_geometry_select") return  (IStepNodePtr) new Ebounding_geometry_select;
	if(classname=="Eprofile_select") return  (IStepNodePtr) new Eprofile_select;
	if(classname=="Etaper_select") return  (IStepNodePtr) new Etaper_select;
	if(classname=="Ecompound_feature_select") return  (IStepNodePtr) new Ecompound_feature_select;
	if(classname=="Ebottom_or_side") return Ebottom_or_side::Create(name);
	if(classname=="Erestricted_area_select") return  (IStepNodePtr) new Erestricted_area_select;
	if(classname=="Ervalue") return  (IStepNodePtr) new Ervalue;
	if(classname=="Etool_reference_point") return Etool_reference_point::Create(name);
	if(classname=="Etoolpath_type") return Etoolpath_type::Create(name);
	if(classname=="Etoolpath_speedprofile") return  (IStepNodePtr) new Etoolpath_speedprofile;
	if(classname=="Espeed_name") return Espeed_name::Create(name);
	if(classname=="Ecurve_with_surface_normal") return  (IStepNodePtr) new Ecurve_with_surface_normal;
	if(classname=="Econtact_type") return Econtact_type::Create(name);
	if(classname=="Ehand") return Ehand::Create(name);
	if(classname=="Epathmode_type") return Epathmode_type::Create(name);
	if(classname=="Ecutmode_type") return Ecutmode_type::Create(name);
	if(classname=="Eleft_or_right") return Eleft_or_right::Create(name);
	if(classname=="Estroke_connection_strategy") return Estroke_connection_strategy::Create(name);
	return NULL; 
}
static int cCcCc = gClassGenerators.AddGenerator(&Createstepnc_schemaClass);
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
