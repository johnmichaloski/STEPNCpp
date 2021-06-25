//
//
//
#include "stdafx.h"
#include "ExpressUtils.h"
#include "ap203ClassDefinitions.h"
namespace Express{
////////////////////////////////////////////////////////////////////////////////
Eaction::Eaction(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eexecuted_action") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "chosen_method" ,(StepNodeType) 22, (DWORD) &(this->chosen_method), "Eaction_method", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction*/
////////////////////////////////////////////////////////////////////////////////
Eaction_assignment::Eaction_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Echange") ; 
	 supertypes.push_back("Estart_work") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_action" ,(StepNodeType) 22, (DWORD) &(this->assigned_action), "Eaction", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction_assignment*/
////////////////////////////////////////////////////////////////////////////////
Eaction_directive::Eaction_directive(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction_directive";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "analysis" ,(StepNodeType) 22, (DWORD) &(this->analysis), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "comment" ,(StepNodeType) 22, (DWORD) &(this->comment), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "requests" ,(StepNodeType) 13, (DWORD) &(this->requests), "EListT<Eversioned_action_requestPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eversioned_action_request");
	 requests.ListClassname()="Eversioned_action_request"; 
	 requests.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction_directive*/
////////////////////////////////////////////////////////////////////////////////
Eaction_method::Eaction_method(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction_method";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "consequence" ,(StepNodeType) 22, (DWORD) &(this->consequence), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "purpose" ,(StepNodeType) 22, (DWORD) &(this->purpose), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction_method*/
////////////////////////////////////////////////////////////////////////////////
Eaction_request_assignment::Eaction_request_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction_request_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Echange_request") ; 
	 supertypes.push_back("Estart_request") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_action_request" ,(StepNodeType) 22, (DWORD) &(this->assigned_action_request), "Eversioned_action_request", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction_request_assignment*/
////////////////////////////////////////////////////////////////////////////////
Eaction_request_solution::Eaction_request_solution(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction_request_solution";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "method" ,(StepNodeType) 22, (DWORD) &(this->method), "Eaction_method", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "request" ,(StepNodeType) 22, (DWORD) &(this->request), "Eversioned_action_request", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction_request_solution*/
////////////////////////////////////////////////////////////////////////////////
Eaction_request_status::Eaction_request_status(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction_request_status";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "status" ,(StepNodeType) 22, (DWORD) &(this->status), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "assigned_request" ,(StepNodeType) 22, (DWORD) &(this->assigned_request), "Eversioned_action_request", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction_request_status*/
////////////////////////////////////////////////////////////////////////////////
Eaction_status::Eaction_status(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaction_status";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "status" ,(StepNodeType) 22, (DWORD) &(this->status), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "assigned_action" ,(StepNodeType) 22, (DWORD) &(this->assigned_action), "Eexecuted_action", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaction_status*/
////////////////////////////////////////////////////////////////////////////////
Eaddress::Eaddress(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaddress";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eorganizational_address") ; 
	 supertypes.push_back("Epersonal_address") ; 
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eface_surface" ,(StepNodeType) 1, (DWORD) &(this->_face_surface.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eadvanced_face*/
////////////////////////////////////////////////////////////////////////////////
Ealternate_product_relationship::Ealternate_product_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ealternate_product_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "alternate" ,(StepNodeType) 22, (DWORD) &(this->alternate), "Eproduct", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "base" ,(StepNodeType) 22, (DWORD) &(this->base), "Eproduct", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "basis" ,(StepNodeType) 22, (DWORD) &(this->basis), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ealternate_product_relationship*/
////////////////////////////////////////////////////////////////////////////////
Eapplication_context::Eapplication_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapplication_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "application" ,(StepNodeType) 22, (DWORD) &(this->application), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapplication_context*/
////////////////////////////////////////////////////////////////////////////////
Eapplication_context_element::Eapplication_context_element(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapplication_context_element";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eproduct_concept_context") ; 
	 supertypes.push_back("Eproduct_context") ; 
	 supertypes.push_back("Eproduct_definition_context") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "frame_of_reference" ,(StepNodeType) 22, (DWORD) &(this->frame_of_reference), "Eapplication_context", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapplication_context_element*/
////////////////////////////////////////////////////////////////////////////////
Eapplication_protocol_definition::Eapplication_protocol_definition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapplication_protocol_definition";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "status" ,(StepNodeType) 22, (DWORD) &(this->status), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "application_interpreted_model_schema_name" ,(StepNodeType) 22, (DWORD) &(this->application_interpreted_model_schema_name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "application_protocol_year" ,(StepNodeType) 22, (DWORD) &(this->application_protocol_year), "Eyear_number", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "application" ,(StepNodeType) 22, (DWORD) &(this->application), "Eapplication_context", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapplication_protocol_definition*/
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapproval*/
////////////////////////////////////////////////////////////////////////////////
Eapproval_assignment::Eapproval_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapproval_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecc_design_approval") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_approval" ,(StepNodeType) 22, (DWORD) &(this->assigned_approval), "Eapproval", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapproval_assignment*/
////////////////////////////////////////////////////////////////////////////////
Eapproval_date_time::Eapproval_date_time(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapproval_date_time";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "date_time" ,(StepNodeType) 22, (DWORD) &(this->date_time), "Edate_time_select", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "dated_approval" ,(StepNodeType) 22, (DWORD) &(this->dated_approval), "Eapproval", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapproval_date_time*/
////////////////////////////////////////////////////////////////////////////////
Eapproval_person_organization::Eapproval_person_organization(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapproval_person_organization";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "person_organization" ,(StepNodeType) 22, (DWORD) &(this->person_organization), "Eperson_organization_select", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "authorized_approval" ,(StepNodeType) 22, (DWORD) &(this->authorized_approval), "Eapproval", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "role" ,(StepNodeType) 22, (DWORD) &(this->role), "Eapproval_role", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapproval_person_organization*/
////////////////////////////////////////////////////////////////////////////////
Eapproval_relationship::Eapproval_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapproval_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "relating_approval" ,(StepNodeType) 22, (DWORD) &(this->relating_approval), "Eapproval", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "related_approval" ,(StepNodeType) 22, (DWORD) &(this->related_approval), "Eapproval", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapproval_relationship*/
////////////////////////////////////////////////////////////////////////////////
Eapproval_role::Eapproval_role(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eapproval_role";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "role" ,(StepNodeType) 22, (DWORD) &(this->role), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapproval_role*/
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eapproval_status*/
////////////////////////////////////////////////////////////////////////////////
Earea_measure_with_unit::Earea_measure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Earea_measure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emeasure_with_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emeasure_with_unit" ,(StepNodeType) 1, (DWORD) &(this->_measure_with_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Earea_measure_with_unit*/
////////////////////////////////////////////////////////////////////////////////
Earea_unit::Earea_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Earea_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Earea_unit*/
////////////////////////////////////////////////////////////////////////////////
Eassembly_component_usage::Eassembly_component_usage(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eassembly_component_usage";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition_usage") ; 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Enext_assembly_usage_occurrence") ; 
	 supertypes.push_back("Epromissory_usage_occurrence") ; 
	 supertypes.push_back("Equantified_assembly_component_usage") ; 
	 supertypes.push_back("Especified_higher_usage_occurrence") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition_usage" ,(StepNodeType) 1, (DWORD) &(this->_product_definition_usage.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "reference_designator" ,(StepNodeType) 22, (DWORD) &(this->reference_designator), "Eidentifier", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eassembly_component_usage*/
////////////////////////////////////////////////////////////////////////////////
Eassembly_component_usage_substitute::Eassembly_component_usage_substitute(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eassembly_component_usage_substitute";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "base" ,(StepNodeType) 22, (DWORD) &(this->base), "Eassembly_component_usage", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "substitute" ,(StepNodeType) 22, (DWORD) &(this->substitute), "Eassembly_component_usage", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eassembly_component_usage_substitute*/
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
	 vars.push_back(new CVarDef(this, "Eplacement" ,(StepNodeType) 1, (DWORD) &(this->_placement.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "axis" ,(StepNodeType) 22, (DWORD) &(this->axis), "Edirection", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaxis1_placement*/
////////////////////////////////////////////////////////////////////////////////
Eaxis2_placement_2d::Eaxis2_placement_2d(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eaxis2_placement_2d";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eplacement") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eplacement" ,(StepNodeType) 1, (DWORD) &(this->_placement.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "ref_direction" ,(StepNodeType) 22, (DWORD) &(this->ref_direction), "Edirection", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaxis2_placement_2d*/
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
	 vars.push_back(new CVarDef(this, "Eplacement" ,(StepNodeType) 1, (DWORD) &(this->_placement.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "axis" ,(StepNodeType) 22, (DWORD) &(this->axis), "Edirection", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "ref_direction" ,(StepNodeType) 22, (DWORD) &(this->ref_direction), "Edirection", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eaxis2_placement_3d*/
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
	 supertypes.push_back("Eb_spline_curve_with_knots") ; 
	 supertypes.push_back("Ebezier_curve") ; 
	 supertypes.push_back("Equasi_uniform_curve") ; 
	 supertypes.push_back("Erational_b_spline_curve") ; 
	 supertypes.push_back("Euniform_curve") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.vars),"Baseclass"));
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.vars),"Baseclass"));
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 supertypes.push_back("Eb_spline_surface_with_knots") ; 
	 supertypes.push_back("Ebezier_surface") ; 
	 supertypes.push_back("Equasi_uniform_surface") ; 
	 supertypes.push_back("Erational_b_spline_surface") ; 
	 supertypes.push_back("Euniform_surface") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ebounded_surface" ,(StepNodeType) 1, (DWORD) &(this->_bounded_surface.vars),"Baseclass"));
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.vars),"Baseclass"));
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eb_spline_surface_with_knots*/
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
	 vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ebezier_surface*/
////////////////////////////////////////////////////////////////////////////////
Eboundary_curve::Eboundary_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eboundary_curve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecomposite_curve_on_surface") ; 
	parents.push_back("Ecomposite_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eouter_boundary_curve") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecomposite_curve_on_surface" ,(StepNodeType) 1, (DWORD) &(this->_composite_curve_on_surface.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eboundary_curve*/
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
	 supertypes.push_back("Eb_spline_curve") ; 
	 supertypes.push_back("Ecomposite_curve") ; 
	 supertypes.push_back("Epolyline") ; 
	 supertypes.push_back("Etrimmed_curve") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ebounded_curve*/
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
	 supertypes.push_back("Ecurve_bounded_surface") ; 
	 supertypes.push_back("Erectangular_composite_surface") ; 
	 supertypes.push_back("Erectangular_trimmed_surface") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->_surface.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ebounded_surface*/
////////////////////////////////////////////////////////////////////////////////
Ebrep_with_voids::Ebrep_with_voids(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ebrep_with_voids";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emanifold_solid_brep") ; 
	parents.push_back("Esolid_model") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emanifold_solid_brep" ,(StepNodeType) 1, (DWORD) &(this->_manifold_solid_brep.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "voids" ,(StepNodeType) 13, (DWORD) &(this->voids), "EListT<Eoriented_closed_shellPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eoriented_closed_shell");
	 voids.ListClassname()="Eoriented_closed_shell"; 
	 voids.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ebrep_with_voids*/
////////////////////////////////////////////////////////////////////////////////
Ecalendar_date::Ecalendar_date(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecalendar_date";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Edate") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Edate" ,(StepNodeType) 1, (DWORD) &(this->_date.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "day_component" ,(StepNodeType) 22, (DWORD) &(this->day_component), "Eday_in_month_number", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "month_component" ,(StepNodeType) 22, (DWORD) &(this->month_component), "Emonth_in_year_number", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Epoint" ,(StepNodeType) 1, (DWORD) &(this->_point.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "coordinates" ,(StepNodeType) 13, (DWORD) &(this->coordinates), "EListT<Elength_measurePtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Elength_measure");
	 coordinates.ListClassname()="Elength_measure"; 
	 coordinates.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecartesian_point*/
////////////////////////////////////////////////////////////////////////////////
Ecartesian_transformation_operator::Ecartesian_transformation_operator(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecartesian_transformation_operator";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	parents.push_back("Efunctionally_defined_transformation") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Ecartesian_transformation_operator_2d") ; 
	 supertypes.push_back("Ecartesian_transformation_operator_3d") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "Efunctionally_defined_transformation" ,(StepNodeType) 1, (DWORD) &(this->_functionally_defined_transformation.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "axis1" ,(StepNodeType) 22, (DWORD) &(this->axis1), "Edirection", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "axis2" ,(StepNodeType) 22, (DWORD) &(this->axis2), "Edirection", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "local_origin" ,(StepNodeType) 22, (DWORD) &(this->local_origin), "Ecartesian_point", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "scale" ,(StepNodeType) 4, (DWORD) &(this->scale), "EReal", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecartesian_transformation_operator*/
////////////////////////////////////////////////////////////////////////////////
Ecartesian_transformation_operator_2d::Ecartesian_transformation_operator_2d(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecartesian_transformation_operator_2d";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecartesian_transformation_operator") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	parents.push_back("Efunctionally_defined_transformation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecartesian_transformation_operator" ,(StepNodeType) 1, (DWORD) &(this->_cartesian_transformation_operator.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecartesian_transformation_operator_2d*/
////////////////////////////////////////////////////////////////////////////////
Ecartesian_transformation_operator_3d::Ecartesian_transformation_operator_3d(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecartesian_transformation_operator_3d";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecartesian_transformation_operator") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	parents.push_back("Efunctionally_defined_transformation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecartesian_transformation_operator" ,(StepNodeType) 1, (DWORD) &(this->_cartesian_transformation_operator.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "axis3" ,(StepNodeType) 22, (DWORD) &(this->axis3), "Edirection", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecartesian_transformation_operator_3d*/
////////////////////////////////////////////////////////////////////////////////
Ecc_design_approval::Ecc_design_approval(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecc_design_approval";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eapproval_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eapproval_assignment" ,(StepNodeType) 1, (DWORD) &(this->_approval_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Eapproved_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eapproved_item");
	 items.ListClassname()="Eapproved_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecc_design_approval*/
////////////////////////////////////////////////////////////////////////////////
Ecc_design_certification::Ecc_design_certification(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecc_design_certification";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecertification_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecertification_assignment" ,(StepNodeType) 1, (DWORD) &(this->_certification_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Ecertified_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Ecertified_item");
	 items.ListClassname()="Ecertified_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecc_design_certification*/
////////////////////////////////////////////////////////////////////////////////
Ecc_design_contract::Ecc_design_contract(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecc_design_contract";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Econtract_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Econtract_assignment" ,(StepNodeType) 1, (DWORD) &(this->_contract_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Econtracted_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Econtracted_item");
	 items.ListClassname()="Econtracted_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecc_design_contract*/
////////////////////////////////////////////////////////////////////////////////
Ecc_design_date_and_time_assignment::Ecc_design_date_and_time_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecc_design_date_and_time_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Edate_and_time_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Edate_and_time_assignment" ,(StepNodeType) 1, (DWORD) &(this->_date_and_time_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Edate_time_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Edate_time_item");
	 items.ListClassname()="Edate_time_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecc_design_date_and_time_assignment*/
////////////////////////////////////////////////////////////////////////////////
Ecc_design_person_and_organization_assignment::Ecc_design_person_and_organization_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecc_design_person_and_organization_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eperson_and_organization_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eperson_and_organization_assignment" ,(StepNodeType) 1, (DWORD) &(this->_person_and_organization_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Eperson_organization_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eperson_organization_item");
	 items.ListClassname()="Eperson_organization_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecc_design_person_and_organization_assignment*/
////////////////////////////////////////////////////////////////////////////////
Ecc_design_security_classification::Ecc_design_security_classification(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecc_design_security_classification";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Esecurity_classification_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esecurity_classification_assignment" ,(StepNodeType) 1, (DWORD) &(this->_security_classification_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Eclassified_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eclassified_item");
	 items.ListClassname()="Eclassified_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecc_design_security_classification*/
////////////////////////////////////////////////////////////////////////////////
Ecc_design_specification_reference::Ecc_design_specification_reference(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecc_design_specification_reference";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Edocument_reference") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Edocument_reference" ,(StepNodeType) 1, (DWORD) &(this->_document_reference.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Especified_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Especified_item");
	 items.ListClassname()="Especified_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecc_design_specification_reference*/
////////////////////////////////////////////////////////////////////////////////
Ecertification::Ecertification(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecertification";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "purpose" ,(StepNodeType) 22, (DWORD) &(this->purpose), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "kind" ,(StepNodeType) 22, (DWORD) &(this->kind), "Ecertification_type", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecertification*/
////////////////////////////////////////////////////////////////////////////////
Ecertification_assignment::Ecertification_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecertification_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecc_design_certification") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_certification" ,(StepNodeType) 22, (DWORD) &(this->assigned_certification), "Ecertification", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecertification_assignment*/
////////////////////////////////////////////////////////////////////////////////
Ecertification_type::Ecertification_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecertification_type";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecertification_type*/
////////////////////////////////////////////////////////////////////////////////
Echange::Echange(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Echange";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eaction_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eaction_assignment" ,(StepNodeType) 1, (DWORD) &(this->_action_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Ework_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Ework_item");
	 items.ListClassname()="Ework_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Echange*/
////////////////////////////////////////////////////////////////////////////////
Echange_request::Echange_request(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Echange_request";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eaction_request_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eaction_request_assignment" ,(StepNodeType) 1, (DWORD) &(this->_action_request_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Echange_request_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Echange_request_item");
	 items.ListClassname()="Echange_request_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Echange_request*/
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
	 vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->_conic.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecircle*/
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
	 supertypes.push_back("Eoriented_closed_shell") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Econnected_face_set" ,(StepNodeType) 1, (DWORD) &(this->_connected_face_set.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eclosed_shell*/
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
	 supertypes.push_back("Ecomposite_curve_on_surface") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "segments" ,(StepNodeType) 13, (DWORD) &(this->segments), "EListT<Ecomposite_curve_segmentPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Ecomposite_curve_segment");
	 segments.ListClassname()="Ecomposite_curve_segment"; 
	 segments.ListType()=(StepNodeType)  22; 
	 vars.push_back(new CVarDef(this, "self_intersect" ,(StepNodeType) 8, (DWORD) &(this->self_intersect), "ELogical", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecomposite_curve*/
////////////////////////////////////////////////////////////////////////////////
Ecomposite_curve_on_surface::Ecomposite_curve_on_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecomposite_curve_on_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecomposite_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eboundary_curve") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecomposite_curve" ,(StepNodeType) 1, (DWORD) &(this->_composite_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecomposite_curve_on_surface*/
////////////////////////////////////////////////////////////////////////////////
Ecomposite_curve_segment::Ecomposite_curve_segment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecomposite_curve_segment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ereparametrised_composite_curve_segment") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "transition" ,(StepNodeType) 22, (DWORD) &(this->transition), "Etransition_code", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "same_sense" ,(StepNodeType) 7, (DWORD) &(this->same_sense), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "parent_curve" ,(StepNodeType) 22, (DWORD) &(this->parent_curve), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecomposite_curve_segment*/
////////////////////////////////////////////////////////////////////////////////
Econfiguration_design::Econfiguration_design(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econfiguration_design";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "configuration" ,(StepNodeType) 22, (DWORD) &(this->configuration), "Econfiguration_item", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "design" ,(StepNodeType) 22, (DWORD) &(this->design), "Eproduct_definition_formation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econfiguration_design*/
////////////////////////////////////////////////////////////////////////////////
Econfiguration_effectivity::Econfiguration_effectivity(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econfiguration_effectivity";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition_effectivity") ; 
	parents.push_back("Eeffectivity") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition_effectivity" ,(StepNodeType) 1, (DWORD) &(this->_product_definition_effectivity.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "configuration" ,(StepNodeType) 22, (DWORD) &(this->configuration), "Econfiguration_design", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econfiguration_effectivity*/
////////////////////////////////////////////////////////////////////////////////
Econfiguration_item::Econfiguration_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econfiguration_item";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "item_concept" ,(StepNodeType) 22, (DWORD) &(this->item_concept), "Eproduct_concept", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "purpose" ,(StepNodeType) 22, (DWORD) &(this->purpose), "Elabel", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econfiguration_item*/
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
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "position" ,(StepNodeType) 22, (DWORD) &(this->position), "Eaxis2_placement", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econic*/
////////////////////////////////////////////////////////////////////////////////
Econical_surface::Econical_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econical_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eelementary_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eelementary_surface" ,(StepNodeType) 1, (DWORD) &(this->_elementary_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Elength_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "semi_angle" ,(StepNodeType) 22, (DWORD) &(this->semi_angle), "Eplane_angle_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econical_surface*/
////////////////////////////////////////////////////////////////////////////////
Econnected_edge_set::Econnected_edge_set(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econnected_edge_set";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "ces_edges" ,(StepNodeType) 13, (DWORD) &(this->ces_edges), "EListT<EedgePtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eedge");
	 ces_edges.ListClassname()="Eedge"; 
	 ces_edges.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econnected_edge_set*/
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
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "cfs_faces" ,(StepNodeType) 13, (DWORD) &(this->cfs_faces), "EListT<EfacePtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eface");
	 cfs_faces.ListClassname()="Eface"; 
	 cfs_faces.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econnected_face_set*/
////////////////////////////////////////////////////////////////////////////////
Econtext_dependent_shape_representation::Econtext_dependent_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econtext_dependent_shape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "representation_relation" ,(StepNodeType) 22, (DWORD) &(this->representation_relation), "Eshape_representation_relationship", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "represented_product_relation" ,(StepNodeType) 22, (DWORD) &(this->represented_product_relation), "Eproduct_definition_shape", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econtext_dependent_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Econtext_dependent_unit::Econtext_dependent_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econtext_dependent_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econtext_dependent_unit*/
////////////////////////////////////////////////////////////////////////////////
Econtract::Econtract(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econtract";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "purpose" ,(StepNodeType) 22, (DWORD) &(this->purpose), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "kind" ,(StepNodeType) 22, (DWORD) &(this->kind), "Econtract_type", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econtract*/
////////////////////////////////////////////////////////////////////////////////
Econtract_assignment::Econtract_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econtract_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecc_design_contract") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_contract" ,(StepNodeType) 22, (DWORD) &(this->assigned_contract), "Econtract", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econtract_assignment*/
////////////////////////////////////////////////////////////////////////////////
Econtract_type::Econtract_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econtract_type";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econtract_type*/
////////////////////////////////////////////////////////////////////////////////
Econversion_based_unit::Econversion_based_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Econversion_based_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "conversion_factor" ,(StepNodeType) 22, (DWORD) &(this->conversion_factor), "Emeasure_with_unit", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Econversion_based_unit*/
////////////////////////////////////////////////////////////////////////////////
Ecoordinated_universal_time_offset::Ecoordinated_universal_time_offset(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecoordinated_universal_time_offset";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "hour_offset" ,(StepNodeType) 22, (DWORD) &(this->hour_offset), "Ehour_in_day", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "minute_offset" ,(StepNodeType) 22, (DWORD) &(this->minute_offset), "Eminute_in_hour", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "sense" ,(StepNodeType) 22, (DWORD) &(this->sense), "Eahead_or_behind", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecoordinated_universal_time_offset*/
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
	 supertypes.push_back("Ecurve_replica") ; 
	 supertypes.push_back("Eline") ; 
	 supertypes.push_back("Eoffset_curve_2d") ; 
	 supertypes.push_back("Eoffset_curve_3d") ; 
	 supertypes.push_back("Epcurve") ; 
	 supertypes.push_back("Esurface_curve") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecurve*/
////////////////////////////////////////////////////////////////////////////////
Ecurve_bounded_surface::Ecurve_bounded_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecurve_bounded_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ebounded_surface" ,(StepNodeType) 1, (DWORD) &(this->_bounded_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_surface" ,(StepNodeType) 22, (DWORD) &(this->basis_surface), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "boundaries" ,(StepNodeType) 13, (DWORD) &(this->boundaries), "EListT<Eboundary_curvePtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eboundary_curve");
	 boundaries.ListClassname()="Eboundary_curve"; 
	 boundaries.ListType()=(StepNodeType)  22; 
	 vars.push_back(new CVarDef(this, "implicit_outer" ,(StepNodeType) 7, (DWORD) &(this->implicit_outer), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecurve_bounded_surface*/
////////////////////////////////////////////////////////////////////////////////
Ecurve_replica::Ecurve_replica(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecurve_replica";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "parent_curve" ,(StepNodeType) 22, (DWORD) &(this->parent_curve), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "transformation" ,(StepNodeType) 22, (DWORD) &(this->transformation), "Ecartesian_transformation_operator", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecurve_replica*/
////////////////////////////////////////////////////////////////////////////////
Ecylindrical_surface::Ecylindrical_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ecylindrical_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eelementary_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eelementary_surface" ,(StepNodeType) 1, (DWORD) &(this->_elementary_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ecylindrical_surface*/
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edate_and_time*/
////////////////////////////////////////////////////////////////////////////////
Edate_and_time_assignment::Edate_and_time_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edate_and_time_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecc_design_date_and_time_assignment") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_date_and_time" ,(StepNodeType) 22, (DWORD) &(this->assigned_date_and_time), "Edate_and_time", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "role" ,(StepNodeType) 22, (DWORD) &(this->role), "Edate_time_role", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edate_and_time_assignment*/
////////////////////////////////////////////////////////////////////////////////
Edate_time_role::Edate_time_role(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edate_time_role";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edate_time_role*/
////////////////////////////////////////////////////////////////////////////////
Edated_effectivity::Edated_effectivity(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edated_effectivity";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eeffectivity") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eeffectivity" ,(StepNodeType) 1, (DWORD) &(this->_effectivity.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "effectivity_start_date" ,(StepNodeType) 22, (DWORD) &(this->effectivity_start_date), "Edate_and_time", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "effectivity_end_date" ,(StepNodeType) 22, (DWORD) &(this->effectivity_end_date), "Edate_and_time", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edated_effectivity*/
////////////////////////////////////////////////////////////////////////////////
Edefinitional_representation::Edefinitional_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edefinitional_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation" ,(StepNodeType) 1, (DWORD) &(this->_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edefinitional_representation*/
////////////////////////////////////////////////////////////////////////////////
Edegenerate_pcurve::Edegenerate_pcurve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edegenerate_pcurve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Epoint") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eevaluated_degenerate_pcurve") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Epoint" ,(StepNodeType) 1, (DWORD) &(this->_point.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_surface" ,(StepNodeType) 22, (DWORD) &(this->basis_surface), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "reference_to_curve" ,(StepNodeType) 22, (DWORD) &(this->reference_to_curve), "Edefinitional_representation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edegenerate_pcurve*/
////////////////////////////////////////////////////////////////////////////////
Edesign_context::Edesign_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edesign_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition_context") ; 
	parents.push_back("Eapplication_context_element") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition_context" ,(StepNodeType) 1, (DWORD) &(this->_product_definition_context.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edesign_context*/
////////////////////////////////////////////////////////////////////////////////
Edesign_make_from_relationship::Edesign_make_from_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edesign_make_from_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition_relationship" ,(StepNodeType) 1, (DWORD) &(this->_product_definition_relationship.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edesign_make_from_relationship*/
////////////////////////////////////////////////////////////////////////////////
Edimensional_exponents::Edimensional_exponents(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edimensional_exponents";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "length_exponent" ,(StepNodeType) 4, (DWORD) &(this->length_exponent), "EReal", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "mass_exponent" ,(StepNodeType) 4, (DWORD) &(this->mass_exponent), "EReal", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "time_exponent" ,(StepNodeType) 4, (DWORD) &(this->time_exponent), "EReal", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "electric_current_exponent" ,(StepNodeType) 4, (DWORD) &(this->electric_current_exponent), "EReal", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "thermodynamic_temperature_exponent" ,(StepNodeType) 4, (DWORD) &(this->thermodynamic_temperature_exponent), "EReal", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "amount_of_substance_exponent" ,(StepNodeType) 4, (DWORD) &(this->amount_of_substance_exponent), "EReal", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "luminous_intensity_exponent" ,(StepNodeType) 4, (DWORD) &(this->luminous_intensity_exponent), "EReal", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edimensional_exponents*/
////////////////////////////////////////////////////////////////////////////////
Edirected_action::Edirected_action(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edirected_action";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eexecuted_action") ; 
	parents.push_back("Eaction") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eexecuted_action" ,(StepNodeType) 1, (DWORD) &(this->_executed_action.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "directive" ,(StepNodeType) 22, (DWORD) &(this->directive), "Eaction_directive", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edirected_action*/
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
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "direction_ratios" ,(StepNodeType) 13, (DWORD) &(this->direction_ratios), "EListT<ERealPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  4, "EReal");
	 direction_ratios.ListClassname()="EReal"; 
	 direction_ratios.ListType()=(StepNodeType)  4; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edirection*/
////////////////////////////////////////////////////////////////////////////////
Edocument::Edocument(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edocument";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Edocument_with_class") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "kind" ,(StepNodeType) 22, (DWORD) &(this->kind), "Edocument_type", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edocument*/
////////////////////////////////////////////////////////////////////////////////
Edocument_reference::Edocument_reference(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edocument_reference";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecc_design_specification_reference") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_document" ,(StepNodeType) 22, (DWORD) &(this->assigned_document), "Edocument", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "source" ,(StepNodeType) 22, (DWORD) &(this->source), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edocument_reference*/
////////////////////////////////////////////////////////////////////////////////
Edocument_relationship::Edocument_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edocument_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "relating_document" ,(StepNodeType) 22, (DWORD) &(this->relating_document), "Edocument", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "related_document" ,(StepNodeType) 22, (DWORD) &(this->related_document), "Edocument", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edocument_relationship*/
////////////////////////////////////////////////////////////////////////////////
Edocument_type::Edocument_type(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edocument_type";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "product_data_type" ,(StepNodeType) 22, (DWORD) &(this->product_data_type), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edocument_type*/
////////////////////////////////////////////////////////////////////////////////
Edocument_usage_constraint::Edocument_usage_constraint(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edocument_usage_constraint";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "source" ,(StepNodeType) 22, (DWORD) &(this->source), "Edocument", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "subject_element" ,(StepNodeType) 22, (DWORD) &(this->subject_element), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "subject_element_value" ,(StepNodeType) 22, (DWORD) &(this->subject_element_value), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edocument_usage_constraint*/
////////////////////////////////////////////////////////////////////////////////
Edocument_with_class::Edocument_with_class(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Edocument_with_class";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Edocument") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Edocument" ,(StepNodeType) 1, (DWORD) &(this->_document.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "E__class" ,(StepNodeType) 22, (DWORD) &(this->E__class), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Edocument_with_class*/
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
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "edge_start" ,(StepNodeType) 22, (DWORD) &(this->edge_start), "Evertex", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "edge_end" ,(StepNodeType) 22, (DWORD) &(this->edge_end), "Evertex", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eedge*/
////////////////////////////////////////////////////////////////////////////////
Eedge_based_wireframe_model::Eedge_based_wireframe_model(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eedge_based_wireframe_model";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "ebwm_boundary" ,(StepNodeType) 13, (DWORD) &(this->ebwm_boundary), "EListT<Econnected_edge_setPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Econnected_edge_set");
	 ebwm_boundary.ListClassname()="Econnected_edge_set"; 
	 ebwm_boundary.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eedge_based_wireframe_model*/
////////////////////////////////////////////////////////////////////////////////
Eedge_based_wireframe_shape_representation::Eedge_based_wireframe_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eedge_based_wireframe_shape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eshape_representation") ; 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eedge_based_wireframe_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Eedge_curve::Eedge_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eedge_curve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eedge") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eedge" ,(StepNodeType) 1, (DWORD) &(this->_edge.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "edge_geometry" ,(StepNodeType) 22, (DWORD) &(this->edge_geometry), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "same_sense" ,(StepNodeType) 7, (DWORD) &(this->same_sense), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	parents.push_back("Epath") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eloop" ,(StepNodeType) 1, (DWORD) &(this->_loop.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "Epath" ,(StepNodeType) 1, (DWORD) &(this->_path.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eedge_loop*/
////////////////////////////////////////////////////////////////////////////////
Eeffectivity::Eeffectivity(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eeffectivity";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Edated_effectivity") ; 
	 supertypes.push_back("Elot_effectivity") ; 
	 supertypes.push_back("Eproduct_definition_effectivity") ; 
	 supertypes.push_back("Eserial_numbered_effectivity") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eeffectivity*/
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
	 supertypes.push_back("Econical_surface") ; 
	 supertypes.push_back("Ecylindrical_surface") ; 
	 supertypes.push_back("Eplane") ; 
	 supertypes.push_back("Espherical_surface") ; 
	 supertypes.push_back("Etoroidal_surface") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "position" ,(StepNodeType) 22, (DWORD) &(this->position), "Eaxis2_placement_3d", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->_conic.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "semi_axis_1" ,(StepNodeType) 22, (DWORD) &(this->semi_axis_1), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "semi_axis_2" ,(StepNodeType) 22, (DWORD) &(this->semi_axis_2), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eellipse*/
////////////////////////////////////////////////////////////////////////////////
Eevaluated_degenerate_pcurve::Eevaluated_degenerate_pcurve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eevaluated_degenerate_pcurve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Edegenerate_pcurve") ; 
	parents.push_back("Epoint") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Edegenerate_pcurve" ,(StepNodeType) 1, (DWORD) &(this->_degenerate_pcurve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "equivalent_point" ,(StepNodeType) 22, (DWORD) &(this->equivalent_point), "Ecartesian_point", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eevaluated_degenerate_pcurve*/
////////////////////////////////////////////////////////////////////////////////
Eexecuted_action::Eexecuted_action(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eexecuted_action";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eaction") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Edirected_action") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eaction" ,(StepNodeType) 1, (DWORD) &(this->_action.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eexecuted_action*/
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
	 supertypes.push_back("Eoriented_face") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "bounds" ,(StepNodeType) 13, (DWORD) &(this->bounds), "EListT<Eface_boundPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eface_bound");
	 bounds.ListClassname()="Eface_bound"; 
	 bounds.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "bound" ,(StepNodeType) 22, (DWORD) &(this->bound), "Eloop", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eface_bound" ,(StepNodeType) 1, (DWORD) &(this->_face_bound.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eadvanced_face") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eface" ,(StepNodeType) 1, (DWORD) &(this->_face.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "face_geometry" ,(StepNodeType) 22, (DWORD) &(this->face_geometry), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "same_sense" ,(StepNodeType) 7, (DWORD) &(this->same_sense), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eface_surface*/
////////////////////////////////////////////////////////////////////////////////
Efaceted_brep::Efaceted_brep(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Efaceted_brep";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emanifold_solid_brep") ; 
	parents.push_back("Esolid_model") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emanifold_solid_brep" ,(StepNodeType) 1, (DWORD) &(this->_manifold_solid_brep.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Efaceted_brep*/
////////////////////////////////////////////////////////////////////////////////
Efaceted_brep_shape_representation::Efaceted_brep_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Efaceted_brep_shape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eshape_representation") ; 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Efaceted_brep_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Efunctionally_defined_transformation::Efunctionally_defined_transformation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Efunctionally_defined_transformation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecartesian_transformation_operator") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Efunctionally_defined_transformation*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_curve_set::Egeometric_curve_set(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Egeometric_curve_set";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Egeometric_set") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_set" ,(StepNodeType) 1, (DWORD) &(this->_geometric_set.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Egeometric_curve_set*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_representation_context::Egeometric_representation_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Egeometric_representation_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_context") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_context" ,(StepNodeType) 1, (DWORD) &(this->_representation_context.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "coordinate_space_dimension" ,(StepNodeType) 22, (DWORD) &(this->coordinate_space_dimension), "Edimension_count", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Egeometric_representation_context*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_representation_item::Egeometric_representation_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Egeometric_representation_item";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Ecartesian_transformation_operator") ; 
	 supertypes.push_back("Ecurve") ; 
	 supertypes.push_back("Edirection") ; 
	 supertypes.push_back("Eedge_based_wireframe_model") ; 
	 supertypes.push_back("Eedge_curve") ; 
	 supertypes.push_back("Eface_surface") ; 
	 supertypes.push_back("Egeometric_set") ; 
	 supertypes.push_back("Eplacement") ; 
	 supertypes.push_back("Epoint") ; 
	 supertypes.push_back("Epoly_loop") ; 
	 supertypes.push_back("Eshell_based_surface_model") ; 
	 supertypes.push_back("Eshell_based_wireframe_model") ; 
	 supertypes.push_back("Esolid_model") ; 
	 supertypes.push_back("Esurface") ; 
	 supertypes.push_back("Evector") ; 
	 supertypes.push_back("Evertex_point") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_item" ,(StepNodeType) 1, (DWORD) &(this->_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Egeometric_representation_item*/
////////////////////////////////////////////////////////////////////////////////
Egeometric_set::Egeometric_set(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Egeometric_set";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Egeometric_curve_set") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "elements" ,(StepNodeType) 13, (DWORD) &(this->elements), "EListT<Egeometric_set_selectPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Egeometric_set_select");
	 elements.ListClassname()="Egeometric_set_select"; 
	 elements.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Egeometric_set*/
////////////////////////////////////////////////////////////////////////////////
Egeometrically_bounded_surface_shape_representation::Egeometrically_bounded_surface_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Egeometrically_bounded_surface_shape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eshape_representation") ; 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Egeometrically_bounded_surface_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Egeometrically_bounded_wireframe_shape_representation::Egeometrically_bounded_wireframe_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Egeometrically_bounded_wireframe_shape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eshape_representation") ; 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Egeometrically_bounded_wireframe_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Eglobal_uncertainty_assigned_context::Eglobal_uncertainty_assigned_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eglobal_uncertainty_assigned_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_context") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_context" ,(StepNodeType) 1, (DWORD) &(this->_representation_context.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "uncertainty" ,(StepNodeType) 13, (DWORD) &(this->uncertainty), "EListT<Euncertainty_measure_with_unitPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Euncertainty_measure_with_unit");
	 uncertainty.ListClassname()="Euncertainty_measure_with_unit"; 
	 uncertainty.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eglobal_uncertainty_assigned_context*/
////////////////////////////////////////////////////////////////////////////////
Eglobal_unit_assigned_context::Eglobal_unit_assigned_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eglobal_unit_assigned_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_context") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_context" ,(StepNodeType) 1, (DWORD) &(this->_representation_context.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "units" ,(StepNodeType) 13, (DWORD) &(this->units), "EListT<EunitPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eunit");
	 units.ListClassname()="Eunit"; 
	 units.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eglobal_unit_assigned_context*/
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
	 vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->_conic.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "semi_axis" ,(StepNodeType) 22, (DWORD) &(this->semi_axis), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "semi_imag_axis" ,(StepNodeType) 22, (DWORD) &(this->semi_imag_axis), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ehyperbola*/
////////////////////////////////////////////////////////////////////////////////
Eintersection_curve::Eintersection_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eintersection_curve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Esurface_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esurface_curve" ,(StepNodeType) 1, (DWORD) &(this->_surface_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eintersection_curve*/
////////////////////////////////////////////////////////////////////////////////
Eitem_defined_transformation::Eitem_defined_transformation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eitem_defined_transformation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "transform_item_1" ,(StepNodeType) 22, (DWORD) &(this->transform_item_1), "Erepresentation_item", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "transform_item_2" ,(StepNodeType) 22, (DWORD) &(this->transform_item_2), "Erepresentation_item", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eitem_defined_transformation*/
////////////////////////////////////////////////////////////////////////////////
Elength_measure_with_unit::Elength_measure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Elength_measure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emeasure_with_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emeasure_with_unit" ,(StepNodeType) 1, (DWORD) &(this->_measure_with_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Elength_measure_with_unit*/
////////////////////////////////////////////////////////////////////////////////
Elength_unit::Elength_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Elength_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Elength_unit*/
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
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "pnt" ,(StepNodeType) 22, (DWORD) &(this->pnt), "Ecartesian_point", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "dir" ,(StepNodeType) 22, (DWORD) &(this->dir), "Evector", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eline*/
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 supertypes.push_back("Epoly_loop") ; 
	 supertypes.push_back("Evertex_loop") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eloop*/
////////////////////////////////////////////////////////////////////////////////
Elot_effectivity::Elot_effectivity(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Elot_effectivity";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eeffectivity") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eeffectivity" ,(StepNodeType) 1, (DWORD) &(this->_effectivity.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "effectivity_lot_id" ,(StepNodeType) 22, (DWORD) &(this->effectivity_lot_id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "effectivity_lot_size" ,(StepNodeType) 22, (DWORD) &(this->effectivity_lot_size), "Emeasure_with_unit", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Elot_effectivity*/
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
	 supertypes.push_back("Ebrep_with_voids") ; 
	 supertypes.push_back("Efaceted_brep") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esolid_model" ,(StepNodeType) 1, (DWORD) &(this->_solid_model.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "outer" ,(StepNodeType) 22, (DWORD) &(this->outer), "Eclosed_shell", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Emanifold_solid_brep*/
////////////////////////////////////////////////////////////////////////////////
Emanifold_surface_shape_representation::Emanifold_surface_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Emanifold_surface_shape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eshape_representation") ; 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Emanifold_surface_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Emapped_item::Emapped_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Emapped_item";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_item" ,(StepNodeType) 1, (DWORD) &(this->_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "mapping_source" ,(StepNodeType) 22, (DWORD) &(this->mapping_source), "Erepresentation_map", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "mapping_target" ,(StepNodeType) 22, (DWORD) &(this->mapping_target), "Erepresentation_item", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Emapped_item*/
////////////////////////////////////////////////////////////////////////////////
Emass_measure_with_unit::Emass_measure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Emass_measure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emeasure_with_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emeasure_with_unit" ,(StepNodeType) 1, (DWORD) &(this->_measure_with_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Emass_measure_with_unit*/
////////////////////////////////////////////////////////////////////////////////
Emass_unit::Emass_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Emass_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Emass_unit*/
////////////////////////////////////////////////////////////////////////////////
Emeasure_with_unit::Emeasure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Emeasure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Earea_measure_with_unit") ; 
	 supertypes.push_back("Elength_measure_with_unit") ; 
	 supertypes.push_back("Emass_measure_with_unit") ; 
	 supertypes.push_back("Eplane_angle_measure_with_unit") ; 
	 supertypes.push_back("Esolid_angle_measure_with_unit") ; 
	 supertypes.push_back("Euncertainty_measure_with_unit") ; 
	 supertypes.push_back("Evolume_measure_with_unit") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "value_component" ,(StepNodeType) 22, (DWORD) &(this->value_component), "Emeasure_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "unit_component" ,(StepNodeType) 22, (DWORD) &(this->unit_component), "Eunit", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Emeasure_with_unit*/
////////////////////////////////////////////////////////////////////////////////
Emechanical_context::Emechanical_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Emechanical_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_context") ; 
	parents.push_back("Eapplication_context_element") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_context" ,(StepNodeType) 1, (DWORD) &(this->_product_context.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Emechanical_context*/
////////////////////////////////////////////////////////////////////////////////
Enamed_unit::Enamed_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Enamed_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Earea_unit") ; 
	 supertypes.push_back("Econtext_dependent_unit") ; 
	 supertypes.push_back("Econversion_based_unit") ; 
	 supertypes.push_back("Elength_unit") ; 
	 supertypes.push_back("Emass_unit") ; 
	 supertypes.push_back("Eplane_angle_unit") ; 
	 supertypes.push_back("Esi_unit") ; 
	 supertypes.push_back("Esolid_angle_unit") ; 
	 supertypes.push_back("Evolume_unit") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "dimensions" ,(StepNodeType) 22, (DWORD) &(this->dimensions), "Edimensional_exponents", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Enamed_unit*/
////////////////////////////////////////////////////////////////////////////////
Enext_assembly_usage_occurrence::Enext_assembly_usage_occurrence(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Enext_assembly_usage_occurrence";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eassembly_component_usage") ; 
	parents.push_back("Eproduct_definition_usage") ; 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eassembly_component_usage" ,(StepNodeType) 1, (DWORD) &(this->_assembly_component_usage.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Enext_assembly_usage_occurrence*/
////////////////////////////////////////////////////////////////////////////////
Eoffset_curve_2d::Eoffset_curve_2d(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eoffset_curve_2d";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_curve" ,(StepNodeType) 22, (DWORD) &(this->basis_curve), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "distance" ,(StepNodeType) 22, (DWORD) &(this->distance), "Elength_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "self_intersect" ,(StepNodeType) 8, (DWORD) &(this->self_intersect), "ELogical", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoffset_curve_2d*/
////////////////////////////////////////////////////////////////////////////////
Eoffset_curve_3d::Eoffset_curve_3d(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eoffset_curve_3d";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_curve" ,(StepNodeType) 22, (DWORD) &(this->basis_curve), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "distance" ,(StepNodeType) 22, (DWORD) &(this->distance), "Elength_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "self_intersect" ,(StepNodeType) 8, (DWORD) &(this->self_intersect), "ELogical", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "ref_direction" ,(StepNodeType) 22, (DWORD) &(this->ref_direction), "Edirection", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoffset_curve_3d*/
////////////////////////////////////////////////////////////////////////////////
Eoffset_surface::Eoffset_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eoffset_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_surface" ,(StepNodeType) 22, (DWORD) &(this->basis_surface), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "distance" ,(StepNodeType) 22, (DWORD) &(this->distance), "Elength_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "self_intersect" ,(StepNodeType) 8, (DWORD) &(this->self_intersect), "ELogical", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoffset_surface*/
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
	 supertypes.push_back("Eoriented_open_shell") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Econnected_face_set" ,(StepNodeType) 1, (DWORD) &(this->_connected_face_set.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eopen_shell*/
////////////////////////////////////////////////////////////////////////////////
Eordinal_date::Eordinal_date(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eordinal_date";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Edate") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Edate" ,(StepNodeType) 1, (DWORD) &(this->_date.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "day_component" ,(StepNodeType) 22, (DWORD) &(this->day_component), "Eday_in_year_number", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eordinal_date*/
////////////////////////////////////////////////////////////////////////////////
Eorganization::Eorganization(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eorganization";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eorganization*/
////////////////////////////////////////////////////////////////////////////////
Eorganization_relationship::Eorganization_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eorganization_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "relating_organization" ,(StepNodeType) 22, (DWORD) &(this->relating_organization), "Eorganization", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "related_organization" ,(StepNodeType) 22, (DWORD) &(this->related_organization), "Eorganization", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eorganization_relationship*/
////////////////////////////////////////////////////////////////////////////////
Eorganizational_address::Eorganizational_address(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eorganizational_address";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eaddress") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eaddress" ,(StepNodeType) 1, (DWORD) &(this->_address.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "organizations" ,(StepNodeType) 13, (DWORD) &(this->organizations), "EListT<EorganizationPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eorganization");
	 organizations.ListClassname()="Eorganization"; 
	 organizations.ListType()=(StepNodeType)  22; 
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eorganizational_address*/
////////////////////////////////////////////////////////////////////////////////
Eorganizational_project::Eorganizational_project(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eorganizational_project";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "responsible_organizations" ,(StepNodeType) 13, (DWORD) &(this->responsible_organizations), "EListT<EorganizationPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eorganization");
	 responsible_organizations.ListClassname()="Eorganization"; 
	 responsible_organizations.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eorganizational_project*/
////////////////////////////////////////////////////////////////////////////////
Eoriented_closed_shell::Eoriented_closed_shell(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eoriented_closed_shell";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eclosed_shell") ; 
	parents.push_back("Econnected_face_set") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eclosed_shell" ,(StepNodeType) 1, (DWORD) &(this->_closed_shell.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "closed_shell_element" ,(StepNodeType) 22, (DWORD) &(this->closed_shell_element), "Eclosed_shell", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoriented_closed_shell*/
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
	 vars.push_back(new CVarDef(this, "Eedge" ,(StepNodeType) 1, (DWORD) &(this->_edge.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "edge_element" ,(StepNodeType) 22, (DWORD) &(this->edge_element), "Eedge", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoriented_edge*/
////////////////////////////////////////////////////////////////////////////////
Eoriented_face::Eoriented_face(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eoriented_face";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eface") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eface" ,(StepNodeType) 1, (DWORD) &(this->_face.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "face_element" ,(StepNodeType) 22, (DWORD) &(this->face_element), "Eface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoriented_face*/
////////////////////////////////////////////////////////////////////////////////
Eoriented_open_shell::Eoriented_open_shell(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eoriented_open_shell";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eopen_shell") ; 
	parents.push_back("Econnected_face_set") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eopen_shell" ,(StepNodeType) 1, (DWORD) &(this->_open_shell.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "open_shell_element" ,(StepNodeType) 22, (DWORD) &(this->open_shell_element), "Eopen_shell", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoriented_open_shell*/
////////////////////////////////////////////////////////////////////////////////
Eoriented_path::Eoriented_path(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eoriented_path";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Epath") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Epath" ,(StepNodeType) 1, (DWORD) &(this->_path.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "path_element" ,(StepNodeType) 22, (DWORD) &(this->path_element), "Epath", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 7, (DWORD) &(this->orientation), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eoriented_path*/
////////////////////////////////////////////////////////////////////////////////
Eouter_boundary_curve::Eouter_boundary_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eouter_boundary_curve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eboundary_curve") ; 
	parents.push_back("Ecomposite_curve_on_surface") ; 
	parents.push_back("Ecomposite_curve") ; 
	parents.push_back("Ebounded_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eboundary_curve" ,(StepNodeType) 1, (DWORD) &(this->_boundary_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eouter_boundary_curve*/
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
	 vars.push_back(new CVarDef(this, "Econic" ,(StepNodeType) 1, (DWORD) &(this->_conic.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "focal_dist" ,(StepNodeType) 22, (DWORD) &(this->focal_dist), "Elength_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eparabola*/
////////////////////////////////////////////////////////////////////////////////
Eparametric_representation_context::Eparametric_representation_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eparametric_representation_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_context") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_context" ,(StepNodeType) 1, (DWORD) &(this->_representation_context.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eparametric_representation_context*/
////////////////////////////////////////////////////////////////////////////////
Epath::Epath(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Epath";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eedge_loop") ; 
	 supertypes.push_back("Eoriented_path") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "edge_list" ,(StepNodeType) 13, (DWORD) &(this->edge_list), "EListT<Eoriented_edgePtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eoriented_edge");
	 edge_list.ListClassname()="Eoriented_edge"; 
	 edge_list.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_surface" ,(StepNodeType) 22, (DWORD) &(this->basis_surface), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "reference_to_curve" ,(StepNodeType) 22, (DWORD) &(this->reference_to_curve), "Edefinitional_representation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eperson*/
////////////////////////////////////////////////////////////////////////////////
Eperson_and_organization::Eperson_and_organization(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eperson_and_organization";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "the_person" ,(StepNodeType) 22, (DWORD) &(this->the_person), "Eperson", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "the_organization" ,(StepNodeType) 22, (DWORD) &(this->the_organization), "Eorganization", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eperson_and_organization*/
////////////////////////////////////////////////////////////////////////////////
Eperson_and_organization_assignment::Eperson_and_organization_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eperson_and_organization_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecc_design_person_and_organization_assignment") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_person_and_organization" ,(StepNodeType) 22, (DWORD) &(this->assigned_person_and_organization), "Eperson_and_organization", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "role" ,(StepNodeType) 22, (DWORD) &(this->role), "Eperson_and_organization_role", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eperson_and_organization_assignment*/
////////////////////////////////////////////////////////////////////////////////
Eperson_and_organization_role::Eperson_and_organization_role(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eperson_and_organization_role";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eperson_and_organization_role*/
////////////////////////////////////////////////////////////////////////////////
Epersonal_address::Epersonal_address(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Epersonal_address";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eaddress") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eaddress" ,(StepNodeType) 1, (DWORD) &(this->_address.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "people" ,(StepNodeType) 13, (DWORD) &(this->people), "EListT<EpersonPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eperson");
	 people.ListClassname()="Eperson"; 
	 people.ListType()=(StepNodeType)  22; 
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epersonal_address*/
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
	 supertypes.push_back("Eaxis2_placement_2d") ; 
	 supertypes.push_back("Eaxis2_placement_3d") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "location" ,(StepNodeType) 22, (DWORD) &(this->location), "Ecartesian_point", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eplacement*/
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
	 vars.push_back(new CVarDef(this, "Eelementary_surface" ,(StepNodeType) 1, (DWORD) &(this->_elementary_surface.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eplane*/
////////////////////////////////////////////////////////////////////////////////
Eplane_angle_measure_with_unit::Eplane_angle_measure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eplane_angle_measure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emeasure_with_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emeasure_with_unit" ,(StepNodeType) 1, (DWORD) &(this->_measure_with_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eplane_angle_measure_with_unit*/
////////////////////////////////////////////////////////////////////////////////
Eplane_angle_unit::Eplane_angle_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eplane_angle_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eplane_angle_unit*/
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
	 supertypes.push_back("Edegenerate_pcurve") ; 
	 supertypes.push_back("Epoint_on_curve") ; 
	 supertypes.push_back("Epoint_on_surface") ; 
	 supertypes.push_back("Epoint_replica") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epoint*/
////////////////////////////////////////////////////////////////////////////////
Epoint_on_curve::Epoint_on_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Epoint_on_curve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Epoint") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Epoint" ,(StepNodeType) 1, (DWORD) &(this->_point.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_curve" ,(StepNodeType) 22, (DWORD) &(this->basis_curve), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "point_parameter" ,(StepNodeType) 22, (DWORD) &(this->point_parameter), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epoint_on_curve*/
////////////////////////////////////////////////////////////////////////////////
Epoint_on_surface::Epoint_on_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Epoint_on_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Epoint") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Epoint" ,(StepNodeType) 1, (DWORD) &(this->_point.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_surface" ,(StepNodeType) 22, (DWORD) &(this->basis_surface), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "point_parameter_u" ,(StepNodeType) 22, (DWORD) &(this->point_parameter_u), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "point_parameter_v" ,(StepNodeType) 22, (DWORD) &(this->point_parameter_v), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epoint_on_surface*/
////////////////////////////////////////////////////////////////////////////////
Epoint_replica::Epoint_replica(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Epoint_replica";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Epoint") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Epoint" ,(StepNodeType) 1, (DWORD) &(this->_point.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "parent_pt" ,(StepNodeType) 22, (DWORD) &(this->parent_pt), "Epoint", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "transformation" ,(StepNodeType) 22, (DWORD) &(this->transformation), "Ecartesian_transformation_operator", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epoint_replica*/
////////////////////////////////////////////////////////////////////////////////
Epoly_loop::Epoly_loop(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Epoly_loop";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eloop") ; 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eloop" ,(StepNodeType) 1, (DWORD) &(this->_loop.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "polygon" ,(StepNodeType) 13, (DWORD) &(this->polygon), "EListT<Ecartesian_pointPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Ecartesian_point");
	 polygon.ListClassname()="Ecartesian_point"; 
	 polygon.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epoly_loop*/
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
	 vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "points" ,(StepNodeType) 13, (DWORD) &(this->points), "EListT<Ecartesian_pointPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Ecartesian_point");
	 points.ListClassname()="Ecartesian_point"; 
	 points.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epolyline*/
////////////////////////////////////////////////////////////////////////////////
Eproduct::Eproduct(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "frame_of_reference" ,(StepNodeType) 13, (DWORD) &(this->frame_of_reference), "EListT<Eproduct_contextPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eproduct_context");
	 frame_of_reference.ListClassname()="Eproduct_context"; 
	 frame_of_reference.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_category::Eproduct_category(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_category";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eproduct_related_product_category") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_category*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_category_relationship::Eproduct_category_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_category_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "category" ,(StepNodeType) 22, (DWORD) &(this->category), "Eproduct_category", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "sub_category" ,(StepNodeType) 22, (DWORD) &(this->sub_category), "Eproduct_category", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_category_relationship*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_concept::Eproduct_concept(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_concept";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "market_context" ,(StepNodeType) 22, (DWORD) &(this->market_context), "Eproduct_concept_context", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_concept*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_concept_context::Eproduct_concept_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_concept_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eapplication_context_element") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eapplication_context_element" ,(StepNodeType) 1, (DWORD) &(this->_application_context_element.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "market_segment_type" ,(StepNodeType) 22, (DWORD) &(this->market_segment_type), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_concept_context*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_context::Eproduct_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eapplication_context_element") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Emechanical_context") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eapplication_context_element" ,(StepNodeType) 1, (DWORD) &(this->_application_context_element.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "discipline_type" ,(StepNodeType) 22, (DWORD) &(this->discipline_type), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_context*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition::Eproduct_definition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eproduct_definition_with_associated_documents") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "formation" ,(StepNodeType) 22, (DWORD) &(this->formation), "Eproduct_definition_formation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "frame_of_reference" ,(StepNodeType) 22, (DWORD) &(this->frame_of_reference), "Eproduct_definition_context", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_context::Eproduct_definition_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eapplication_context_element") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Edesign_context") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eapplication_context_element" ,(StepNodeType) 1, (DWORD) &(this->_application_context_element.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "life_cycle_stage" ,(StepNodeType) 22, (DWORD) &(this->life_cycle_stage), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_context*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_effectivity::Eproduct_definition_effectivity(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_effectivity";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eeffectivity") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Econfiguration_effectivity") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eeffectivity" ,(StepNodeType) 1, (DWORD) &(this->_effectivity.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "usage" ,(StepNodeType) 22, (DWORD) &(this->usage), "Eproduct_definition_relationship", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_effectivity*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_formation::Eproduct_definition_formation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_formation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eproduct_definition_formation_with_specified_source") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "of_product" ,(StepNodeType) 22, (DWORD) &(this->of_product), "Eproduct", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_formation*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_formation_with_specified_source::Eproduct_definition_formation_with_specified_source(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_formation_with_specified_source";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition_formation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition_formation" ,(StepNodeType) 1, (DWORD) &(this->_product_definition_formation.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "make_or_buy" ,(StepNodeType) 22, (DWORD) &(this->make_or_buy), "Esource", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_formation_with_specified_source*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_relationship::Eproduct_definition_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Edesign_make_from_relationship") ; 
	 supertypes.push_back("Eproduct_definition_usage") ; 
	 supertypes.push_back("Esupplied_part_relationship") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "relating_product_definition" ,(StepNodeType) 22, (DWORD) &(this->relating_product_definition), "Eproduct_definition", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "related_product_definition" ,(StepNodeType) 22, (DWORD) &(this->related_product_definition), "Eproduct_definition", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_relationship*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_shape::Eproduct_definition_shape(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_shape";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproperty_definition") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproperty_definition" ,(StepNodeType) 1, (DWORD) &(this->_property_definition.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_shape*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_usage::Eproduct_definition_usage(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_usage";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eassembly_component_usage") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition_relationship" ,(StepNodeType) 1, (DWORD) &(this->_product_definition_relationship.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_usage*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_definition_with_associated_documents::Eproduct_definition_with_associated_documents(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_definition_with_associated_documents";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition" ,(StepNodeType) 1, (DWORD) &(this->_product_definition.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "documentation_ids" ,(StepNodeType) 13, (DWORD) &(this->documentation_ids), "EListT<EdocumentPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Edocument");
	 documentation_ids.ListClassname()="Edocument"; 
	 documentation_ids.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_definition_with_associated_documents*/
////////////////////////////////////////////////////////////////////////////////
Eproduct_related_product_category::Eproduct_related_product_category(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproduct_related_product_category";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_category") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_category" ,(StepNodeType) 1, (DWORD) &(this->_product_category.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "products" ,(StepNodeType) 13, (DWORD) &(this->products), "EListT<EproductPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eproduct");
	 products.ListClassname()="Eproduct"; 
	 products.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproduct_related_product_category*/
////////////////////////////////////////////////////////////////////////////////
Epromissory_usage_occurrence::Epromissory_usage_occurrence(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Epromissory_usage_occurrence";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eassembly_component_usage") ; 
	parents.push_back("Eproduct_definition_usage") ; 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eassembly_component_usage" ,(StepNodeType) 1, (DWORD) &(this->_assembly_component_usage.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Epromissory_usage_occurrence*/
////////////////////////////////////////////////////////////////////////////////
Eproperty_definition::Eproperty_definition(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproperty_definition";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eproduct_definition_shape") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "definition" ,(StepNodeType) 22, (DWORD) &(this->definition), "Echaracterized_definition", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproperty_definition*/
////////////////////////////////////////////////////////////////////////////////
Eproperty_definition_representation::Eproperty_definition_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eproperty_definition_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Eshape_definition_representation") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "definition" ,(StepNodeType) 22, (DWORD) &(this->definition), "Eproperty_definition", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "used_representation" ,(StepNodeType) 22, (DWORD) &(this->used_representation), "Erepresentation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eproperty_definition_representation*/
////////////////////////////////////////////////////////////////////////////////
Equantified_assembly_component_usage::Equantified_assembly_component_usage(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Equantified_assembly_component_usage";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eassembly_component_usage") ; 
	parents.push_back("Eproduct_definition_usage") ; 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eassembly_component_usage" ,(StepNodeType) 1, (DWORD) &(this->_assembly_component_usage.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "quantity" ,(StepNodeType) 22, (DWORD) &(this->quantity), "Emeasure_with_unit", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Equantified_assembly_component_usage*/
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
	 vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Equasi_uniform_surface*/
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
	 vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "weights_data" ,(StepNodeType) 13, (DWORD) &(this->weights_data), "EListT<ERealPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  4, "EReal");
	 weights_data.ListClassname()="EReal"; 
	 weights_data.ListType()=(StepNodeType)  4; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "weights_data" ,(StepNodeType) 15, (DWORD) &(this->weights_data), "std::vector< EListT<ERealPtr> >", 0));
	 vars.back()->Init(2, (StepNodeType)  4, "EReal");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erational_b_spline_surface*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_composite_surface::Erectangular_composite_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erectangular_composite_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ebounded_surface" ,(StepNodeType) 1, (DWORD) &(this->_bounded_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "segments" ,(StepNodeType) 15, (DWORD) &(this->segments), "std::vector< EListT<Esurface_patchPtr> >", 0));
	 vars.back()->Init(2, (StepNodeType)  22, "Esurface_patch");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erectangular_composite_surface*/
////////////////////////////////////////////////////////////////////////////////
Erectangular_trimmed_surface::Erectangular_trimmed_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erectangular_trimmed_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ebounded_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ebounded_surface" ,(StepNodeType) 1, (DWORD) &(this->_bounded_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "basis_surface" ,(StepNodeType) 22, (DWORD) &(this->basis_surface), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "u1" ,(StepNodeType) 22, (DWORD) &(this->u1), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "u2" ,(StepNodeType) 22, (DWORD) &(this->u2), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "v1" ,(StepNodeType) 22, (DWORD) &(this->v1), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "v2" ,(StepNodeType) 22, (DWORD) &(this->v2), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "usense" ,(StepNodeType) 7, (DWORD) &(this->usense), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "vsense" ,(StepNodeType) 7, (DWORD) &(this->vsense), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erectangular_trimmed_surface*/
////////////////////////////////////////////////////////////////////////////////
Ereparametrised_composite_curve_segment::Ereparametrised_composite_curve_segment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ereparametrised_composite_curve_segment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecomposite_curve_segment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecomposite_curve_segment" ,(StepNodeType) 1, (DWORD) &(this->_composite_curve_segment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "param_length" ,(StepNodeType) 22, (DWORD) &(this->param_length), "Eparameter_value", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ereparametrised_composite_curve_segment*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation::Erepresentation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erepresentation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Edefinitional_representation") ; 
	 supertypes.push_back("Eshape_representation") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Erepresentation_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Erepresentation_item");
	 items.ListClassname()="Erepresentation_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 vars.push_back(new CVarDef(this, "context_of_items" ,(StepNodeType) 22, (DWORD) &(this->context_of_items), "Erepresentation_context", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erepresentation*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_context::Erepresentation_context(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erepresentation_context";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Egeometric_representation_context") ; 
	 supertypes.push_back("Eglobal_uncertainty_assigned_context") ; 
	 supertypes.push_back("Eglobal_unit_assigned_context") ; 
	 supertypes.push_back("Eparametric_representation_context") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "context_identifier" ,(StepNodeType) 22, (DWORD) &(this->context_identifier), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "context_type" ,(StepNodeType) 22, (DWORD) &(this->context_type), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erepresentation_context*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_item::Erepresentation_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erepresentation_item";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Egeometric_representation_item") ; 
	 supertypes.push_back("Emapped_item") ; 
	 supertypes.push_back("Etopological_representation_item") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erepresentation_item*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_map::Erepresentation_map(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erepresentation_map";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "mapping_origin" ,(StepNodeType) 22, (DWORD) &(this->mapping_origin), "Erepresentation_item", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "mapped_representation" ,(StepNodeType) 22, (DWORD) &(this->mapped_representation), "Erepresentation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erepresentation_map*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_relationship::Erepresentation_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erepresentation_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Erepresentation_relationship_with_transformation") ; 
	 supertypes.push_back("Eshape_representation_relationship") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "rep_1" ,(StepNodeType) 22, (DWORD) &(this->rep_1), "Erepresentation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "rep_2" ,(StepNodeType) 22, (DWORD) &(this->rep_2), "Erepresentation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erepresentation_relationship*/
////////////////////////////////////////////////////////////////////////////////
Erepresentation_relationship_with_transformation::Erepresentation_relationship_with_transformation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Erepresentation_relationship_with_transformation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_relationship" ,(StepNodeType) 1, (DWORD) &(this->_representation_relationship.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "transformation_operator" ,(StepNodeType) 22, (DWORD) &(this->transformation_operator), "Etransformation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Erepresentation_relationship_with_transformation*/
////////////////////////////////////////////////////////////////////////////////
Eseam_curve::Eseam_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eseam_curve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Esurface_curve") ; 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esurface_curve" ,(StepNodeType) 1, (DWORD) &(this->_surface_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eseam_curve*/
////////////////////////////////////////////////////////////////////////////////
Esecurity_classification::Esecurity_classification(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esecurity_classification";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "purpose" ,(StepNodeType) 22, (DWORD) &(this->purpose), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "security_level" ,(StepNodeType) 22, (DWORD) &(this->security_level), "Esecurity_classification_level", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esecurity_classification*/
////////////////////////////////////////////////////////////////////////////////
Esecurity_classification_assignment::Esecurity_classification_assignment(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esecurity_classification_assignment";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 supertypes.push_back("Ecc_design_security_classification") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "assigned_security_classification" ,(StepNodeType) 22, (DWORD) &(this->assigned_security_classification), "Esecurity_classification", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esecurity_classification_assignment*/
////////////////////////////////////////////////////////////////////////////////
Esecurity_classification_level::Esecurity_classification_level(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esecurity_classification_level";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esecurity_classification_level*/
////////////////////////////////////////////////////////////////////////////////
Eserial_numbered_effectivity::Eserial_numbered_effectivity(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eserial_numbered_effectivity";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eeffectivity") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eeffectivity" ,(StepNodeType) 1, (DWORD) &(this->_effectivity.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "effectivity_start_id" ,(StepNodeType) 22, (DWORD) &(this->effectivity_start_id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "effectivity_end_id" ,(StepNodeType) 22, (DWORD) &(this->effectivity_end_id), "Eidentifier", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eserial_numbered_effectivity*/
////////////////////////////////////////////////////////////////////////////////
Eshape_aspect::Eshape_aspect(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshape_aspect";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "of_shape" ,(StepNodeType) 22, (DWORD) &(this->of_shape), "Eproduct_definition_shape", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "product_definitional" ,(StepNodeType) 8, (DWORD) &(this->product_definitional), "ELogical", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshape_aspect*/
////////////////////////////////////////////////////////////////////////////////
Eshape_aspect_relationship::Eshape_aspect_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshape_aspect_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "relating_shape_aspect" ,(StepNodeType) 22, (DWORD) &(this->relating_shape_aspect), "Eshape_aspect", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "related_shape_aspect" ,(StepNodeType) 22, (DWORD) &(this->related_shape_aspect), "Eshape_aspect", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshape_aspect_relationship*/
////////////////////////////////////////////////////////////////////////////////
Eshape_definition_representation::Eshape_definition_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshape_definition_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproperty_definition_representation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproperty_definition_representation" ,(StepNodeType) 1, (DWORD) &(this->_property_definition_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshape_definition_representation*/
////////////////////////////////////////////////////////////////////////////////
Eshape_representation::Eshape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eadvanced_brep_shape_representation") ; 
	 supertypes.push_back("Eedge_based_wireframe_shape_representation") ; 
	 supertypes.push_back("Efaceted_brep_shape_representation") ; 
	 supertypes.push_back("Egeometrically_bounded_surface_shape_representation") ; 
	 supertypes.push_back("Egeometrically_bounded_wireframe_shape_representation") ; 
	 supertypes.push_back("Emanifold_surface_shape_representation") ; 
	 supertypes.push_back("Eshell_based_wireframe_shape_representation") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation" ,(StepNodeType) 1, (DWORD) &(this->_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshape_representation*/
////////////////////////////////////////////////////////////////////////////////
Eshape_representation_relationship::Eshape_representation_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshape_representation_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_relationship" ,(StepNodeType) 1, (DWORD) &(this->_representation_relationship.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshape_representation_relationship*/
////////////////////////////////////////////////////////////////////////////////
Eshell_based_surface_model::Eshell_based_surface_model(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshell_based_surface_model";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "sbsm_boundary" ,(StepNodeType) 13, (DWORD) &(this->sbsm_boundary), "EListT<EshellPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eshell");
	 sbsm_boundary.ListClassname()="Eshell"; 
	 sbsm_boundary.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshell_based_surface_model*/
////////////////////////////////////////////////////////////////////////////////
Eshell_based_wireframe_model::Eshell_based_wireframe_model(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshell_based_wireframe_model";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "sbwm_boundary" ,(StepNodeType) 13, (DWORD) &(this->sbwm_boundary), "EListT<EshellPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eshell");
	 sbwm_boundary.ListClassname()="Eshell"; 
	 sbwm_boundary.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshell_based_wireframe_model*/
////////////////////////////////////////////////////////////////////////////////
Eshell_based_wireframe_shape_representation::Eshell_based_wireframe_shape_representation(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eshell_based_wireframe_shape_representation";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eshape_representation") ; 
	parents.push_back("Erepresentation") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eshape_representation" ,(StepNodeType) 1, (DWORD) &(this->_shape_representation.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eshell_based_wireframe_shape_representation*/
////////////////////////////////////////////////////////////////////////////////
Esi_unit::Esi_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esi_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "prefix" ,(StepNodeType) 22, (DWORD) &(this->prefix), "Esi_prefix", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Esi_unit_name", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esi_unit*/
////////////////////////////////////////////////////////////////////////////////
Esolid_angle_measure_with_unit::Esolid_angle_measure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esolid_angle_measure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emeasure_with_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emeasure_with_unit" ,(StepNodeType) 1, (DWORD) &(this->_measure_with_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esolid_angle_measure_with_unit*/
////////////////////////////////////////////////////////////////////////////////
Esolid_angle_unit::Esolid_angle_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esolid_angle_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esolid_angle_unit*/
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
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esolid_model*/
////////////////////////////////////////////////////////////////////////////////
Especified_higher_usage_occurrence::Especified_higher_usage_occurrence(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Especified_higher_usage_occurrence";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eassembly_component_usage") ; 
	parents.push_back("Eproduct_definition_usage") ; 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eassembly_component_usage" ,(StepNodeType) 1, (DWORD) &(this->_assembly_component_usage.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "upper_usage" ,(StepNodeType) 22, (DWORD) &(this->upper_usage), "Eassembly_component_usage", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "next_usage" ,(StepNodeType) 22, (DWORD) &(this->next_usage), "Enext_assembly_usage_occurrence", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Especified_higher_usage_occurrence*/
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
	 vars.push_back(new CVarDef(this, "Eelementary_surface" ,(StepNodeType) 1, (DWORD) &(this->_elementary_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "radius" ,(StepNodeType) 22, (DWORD) &(this->radius), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Espherical_surface*/
////////////////////////////////////////////////////////////////////////////////
Estart_request::Estart_request(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Estart_request";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eaction_request_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eaction_request_assignment" ,(StepNodeType) 1, (DWORD) &(this->_action_request_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Estart_request_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Estart_request_item");
	 items.ListClassname()="Estart_request_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Estart_request*/
////////////////////////////////////////////////////////////////////////////////
Estart_work::Estart_work(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Estart_work";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eaction_assignment") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eaction_assignment" ,(StepNodeType) 1, (DWORD) &(this->_action_assignment.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "items" ,(StepNodeType) 13, (DWORD) &(this->items), "EListT<Ework_itemPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Ework_item");
	 items.ListClassname()="Ework_item"; 
	 items.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Estart_work*/
////////////////////////////////////////////////////////////////////////////////
Esupplied_part_relationship::Esupplied_part_relationship(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esupplied_part_relationship";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eproduct_definition_relationship") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eproduct_definition_relationship" ,(StepNodeType) 1, (DWORD) &(this->_product_definition_relationship.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esupplied_part_relationship*/
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
	 supertypes.push_back("Eoffset_surface") ; 
	 supertypes.push_back("Esurface_replica") ; 
	 supertypes.push_back("Eswept_surface") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esurface*/
////////////////////////////////////////////////////////////////////////////////
Esurface_curve::Esurface_curve(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esurface_curve";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Ecurve") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Eintersection_curve") ; 
	 supertypes.push_back("Eseam_curve") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Ecurve" ,(StepNodeType) 1, (DWORD) &(this->_curve.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "curve_3d" ,(StepNodeType) 22, (DWORD) &(this->curve_3d), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "associated_geometry" ,(StepNodeType) 13, (DWORD) &(this->associated_geometry), "EListT<Epcurve_or_surfacePtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Epcurve_or_surface");
	 associated_geometry.ListClassname()="Epcurve_or_surface"; 
	 associated_geometry.ListType()=(StepNodeType)  22; 
	 vars.push_back(new CVarDef(this, "master_representation" ,(StepNodeType) 22, (DWORD) &(this->master_representation), "Epreferred_surface_curve_representation", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esurface_curve*/
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
	 vars.push_back(new CVarDef(this, "Eswept_surface" ,(StepNodeType) 1, (DWORD) &(this->_swept_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "extrusion_axis" ,(StepNodeType) 22, (DWORD) &(this->extrusion_axis), "Evector", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eswept_surface" ,(StepNodeType) 1, (DWORD) &(this->_swept_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "axis_position" ,(StepNodeType) 22, (DWORD) &(this->axis_position), "Eaxis1_placement", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esurface_of_revolution*/
////////////////////////////////////////////////////////////////////////////////
Esurface_patch::Esurface_patch(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esurface_patch";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "parent_surface" ,(StepNodeType) 22, (DWORD) &(this->parent_surface), "Ebounded_surface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "u_transition" ,(StepNodeType) 22, (DWORD) &(this->u_transition), "Etransition_code", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "v_transition" ,(StepNodeType) 22, (DWORD) &(this->v_transition), "Etransition_code", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "u_sense" ,(StepNodeType) 7, (DWORD) &(this->u_sense), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "v_sense" ,(StepNodeType) 7, (DWORD) &(this->v_sense), "EBoolean", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esurface_patch*/
////////////////////////////////////////////////////////////////////////////////
Esurface_replica::Esurface_replica(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Esurface_replica";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "parent_surface" ,(StepNodeType) 22, (DWORD) &(this->parent_surface), "Esurface", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "transformation" ,(StepNodeType) 22, (DWORD) &(this->transformation), "Ecartesian_transformation_operator_3d", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Esurface_replica*/
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
	 vars.push_back(new CVarDef(this, "Esurface" ,(StepNodeType) 1, (DWORD) &(this->_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "swept_curve" ,(StepNodeType) 22, (DWORD) &(this->swept_curve), "Ecurve", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eswept_surface*/
////////////////////////////////////////////////////////////////////////////////
Etopological_representation_item::Etopological_representation_item(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Etopological_representation_item";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 supertypes.push_back("Econnected_edge_set") ; 
	 supertypes.push_back("Econnected_face_set") ; 
	 supertypes.push_back("Eedge") ; 
	 supertypes.push_back("Eface") ; 
	 supertypes.push_back("Eface_bound") ; 
	 supertypes.push_back("Eloop") ; 
	 supertypes.push_back("Epath") ; 
	 supertypes.push_back("Evertex") ; 
	 supertypes.push_back("Evertex_shell") ; 
	 supertypes.push_back("Ewire_shell") ; 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Erepresentation_item" ,(StepNodeType) 1, (DWORD) &(this->_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Etopological_representation_item*/
////////////////////////////////////////////////////////////////////////////////
Etoroidal_surface::Etoroidal_surface(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Etoroidal_surface";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Eelementary_surface") ; 
	parents.push_back("Esurface") ; 
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Eelementary_surface" ,(StepNodeType) 1, (DWORD) &(this->_elementary_surface.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "major_radius" ,(StepNodeType) 22, (DWORD) &(this->major_radius), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "minor_radius" ,(StepNodeType) 22, (DWORD) &(this->minor_radius), "Epositive_length_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Etoroidal_surface*/
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
	 vars.push_back(new CVarDef(this, "Ebounded_curve" ,(StepNodeType) 1, (DWORD) &(this->_bounded_curve.vars),"Baseclass"));
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
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Etrimmed_curve*/
////////////////////////////////////////////////////////////////////////////////
Euncertainty_measure_with_unit::Euncertainty_measure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Euncertainty_measure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emeasure_with_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emeasure_with_unit" ,(StepNodeType) 1, (DWORD) &(this->_measure_with_unit.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Euncertainty_measure_with_unit*/
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
	 vars.push_back(new CVarDef(this, "Eb_spline_curve" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_curve.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eb_spline_surface" ,(StepNodeType) 1, (DWORD) &(this->_b_spline_surface.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Euniform_surface*/
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
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "orientation" ,(StepNodeType) 22, (DWORD) &(this->orientation), "Edirection", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "magnitude" ,(StepNodeType) 22, (DWORD) &(this->magnitude), "Elength_measure", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Evector*/
////////////////////////////////////////////////////////////////////////////////
Eversioned_action_request::Eversioned_action_request(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eversioned_action_request";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "id" ,(StepNodeType) 22, (DWORD) &(this->id), "Eidentifier", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "version" ,(StepNodeType) 22, (DWORD) &(this->version), "Elabel", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "purpose" ,(StepNodeType) 22, (DWORD) &(this->purpose), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 22, (DWORD) &(this->description), "Etext", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eversioned_action_request*/
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
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	 vars.push_back(new CVarDef(this, "Eloop" ,(StepNodeType) 1, (DWORD) &(this->_loop.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "loop_vertex" ,(StepNodeType) 22, (DWORD) &(this->loop_vertex), "Evertex", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
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
	parents.push_back("Egeometric_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Evertex" ,(StepNodeType) 1, (DWORD) &(this->_vertex.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "Egeometric_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_geometric_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "vertex_geometry" ,(StepNodeType) 22, (DWORD) &(this->vertex_geometry), "Epoint", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Evertex_point*/
////////////////////////////////////////////////////////////////////////////////
Evertex_shell::Evertex_shell(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Evertex_shell";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "vertex_shell_extent" ,(StepNodeType) 22, (DWORD) &(this->vertex_shell_extent), "Evertex_loop", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Evertex_shell*/
////////////////////////////////////////////////////////////////////////////////
Evolume_measure_with_unit::Evolume_measure_with_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Evolume_measure_with_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Emeasure_with_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Emeasure_with_unit" ,(StepNodeType) 1, (DWORD) &(this->_measure_with_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Evolume_measure_with_unit*/
////////////////////////////////////////////////////////////////////////////////
Evolume_unit::Evolume_unit(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Evolume_unit";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Enamed_unit") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Enamed_unit" ,(StepNodeType) 1, (DWORD) &(this->_named_unit.vars),"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Evolume_unit*/
////////////////////////////////////////////////////////////////////////////////
Eweek_of_year_and_day_date::Eweek_of_year_and_day_date(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Eweek_of_year_and_day_date";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Edate") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Edate" ,(StepNodeType) 1, (DWORD) &(this->_date.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "week_component" ,(StepNodeType) 22, (DWORD) &(this->week_component), "Eweek_in_year_number", 0));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 vars.push_back(new CVarDef(this, "day_component" ,(StepNodeType) 22, (DWORD) &(this->day_component), "Eday_in_week_number", 1));
	 vars.back()->Init(0, (StepNodeType)  0, "");
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Eweek_of_year_and_day_date*/
////////////////////////////////////////////////////////////////////////////////
Ewire_shell::Ewire_shell(){
	 m_def.m_pClass=(DWORD)this;
	 Classname()="Ewire_shell";
	 m_def.m_pVars=&vars;
	 parents.clear(); 
	parents.push_back("Etopological_representation_item") ; 
	parents.push_back("Erepresentation_item") ; 
	 supertypes.clear(); 
	 m_bAbstract=false ; 
	 vars.push_back(new CVarDef(this, "Etopological_representation_item" ,(StepNodeType) 1, (DWORD) &(this->_topological_representation_item.vars),"Baseclass"));
	 vars.push_back(new CVarDef(this, "wire_shell_extent" ,(StepNodeType) 13, (DWORD) &(this->wire_shell_extent), "EListT<EloopPtr>", 0));
	 vars.back()->Init(1, (StepNodeType)  22, "Eloop");
	 wire_shell_extent.ListClassname()="Eloop"; 
	 wire_shell_extent.ListType()=(StepNodeType)  22; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Ewire_shell*/
Eset_of_reversible_topology_item::Eset_of_reversible_topology_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eset_of_reversible_topology_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= typelist_; 
	 this->ListType()= reference_; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eahead_or_behind::Eahead_or_behind()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eahead_or_behind";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 2; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eapproved_item::Eapproved_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eapproved_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_formation" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_formation),"_Eproduct_definition_formation"));

	 SetSelection(_Eproduct_definition_formation); 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition),"_Eproduct_definition"));
	 vars.push_back(new CVarDef(this, "_Econfiguration_effectivity" ,(StepNodeType) 18, (DWORD) &(this->_Econfiguration_effectivity),"_Econfiguration_effectivity"));
	 vars.push_back(new CVarDef(this, "_Econfiguration_item" ,(StepNodeType) 18, (DWORD) &(this->_Econfiguration_item),"_Econfiguration_item"));
	 vars.push_back(new CVarDef(this, "_Esecurity_classification" ,(StepNodeType) 18, (DWORD) &(this->_Esecurity_classification),"_Esecurity_classification"));
	 vars.push_back(new CVarDef(this, "_Echange_request" ,(StepNodeType) 18, (DWORD) &(this->_Echange_request),"_Echange_request"));
	 vars.push_back(new CVarDef(this, "_Echange" ,(StepNodeType) 18, (DWORD) &(this->_Echange),"_Echange"));
	 vars.push_back(new CVarDef(this, "_Estart_request" ,(StepNodeType) 18, (DWORD) &(this->_Estart_request),"_Estart_request"));
	 vars.push_back(new CVarDef(this, "_Estart_work" ,(StepNodeType) 18, (DWORD) &(this->_Estart_work),"_Estart_work"));
	 vars.push_back(new CVarDef(this, "_Ecertification" ,(StepNodeType) 18, (DWORD) &(this->_Ecertification),"_Ecertification"));
	 vars.push_back(new CVarDef(this, "_Econtract" ,(StepNodeType) 18, (DWORD) &(this->_Econtract),"_Econtract"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Earea_measure::Earea_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Earea_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eaxis2_placement::Eaxis2_placement()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eaxis2_placement";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eaxis2_placement_2d" ,(StepNodeType) 18, (DWORD) &(this->_Eaxis2_placement_2d),"_Eaxis2_placement_2d"));

	 SetSelection(_Eaxis2_placement_2d); 
	 vars.push_back(new CVarDef(this, "_Eaxis2_placement_3d" ,(StepNodeType) 18, (DWORD) &(this->_Eaxis2_placement_3d),"_Eaxis2_placement_3d"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eb_spline_curve_form::Eb_spline_curve_form()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eb_spline_curve_form";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 6; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eb_spline_surface_form::Eb_spline_surface_form()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eb_spline_surface_form";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 11; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eboolean_operand::Eboolean_operand()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eboolean_operand";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Esolid_model" ,(StepNodeType) 18, (DWORD) &(this->_Esolid_model),"_Esolid_model"));

	 SetSelection(_Esolid_model); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ecertified_item::Ecertified_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ecertified_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Esupplied_part_relationship" ,(StepNodeType) 18, (DWORD) &(this->_Esupplied_part_relationship),"_Esupplied_part_relationship"));

	 SetSelection(_Esupplied_part_relationship); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Echange_request_item::Echange_request_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Echange_request_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_formation" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_formation),"_Eproduct_definition_formation"));

	 SetSelection(_Eproduct_definition_formation); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Echaracterized_definition::Echaracterized_definition()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Echaracterized_definition";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Echaracterized_product_definition" ,(StepNodeType) 21, (DWORD) &(this->_Echaracterized_product_definition),"_Echaracterized_product_definition"));

	 SetSelection(_Echaracterized_product_definition); 
	 vars.push_back(new CVarDef(this, "_Eshape_definition" ,(StepNodeType) 21, (DWORD) &(this->_Eshape_definition),"_Eshape_definition"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Echaracterized_product_definition::Echaracterized_product_definition()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Echaracterized_product_definition";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition),"_Eproduct_definition"));

	 SetSelection(_Eproduct_definition); 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_relationship" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_relationship),"_Eproduct_definition_relationship"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eclassified_item::Eclassified_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eclassified_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_formation" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_formation),"_Eproduct_definition_formation"));

	 SetSelection(_Eproduct_definition_formation); 
	 vars.push_back(new CVarDef(this, "_Eassembly_component_usage" ,(StepNodeType) 18, (DWORD) &(this->_Eassembly_component_usage),"_Eassembly_component_usage"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Econtext_dependent_measure::Econtext_dependent_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Econtext_dependent_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Econtracted_item::Econtracted_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Econtracted_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_formation" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_formation),"_Eproduct_definition_formation"));

	 SetSelection(_Eproduct_definition_formation); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ecount_measure::Ecount_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ecount_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= number_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "ENumber" ,(StepNodeType) 1, (DWORD) &(this->ENumber::vars),"Baseclass"));
	 parents.push_back("ENumber"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ecurve_on_surface::Ecurve_on_surface()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ecurve_on_surface";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Epcurve" ,(StepNodeType) 18, (DWORD) &(this->_Epcurve),"_Epcurve"));

	 SetSelection(_Epcurve); 
	 vars.push_back(new CVarDef(this, "_Esurface_curve" ,(StepNodeType) 18, (DWORD) &(this->_Esurface_curve),"_Esurface_curve"));
	 vars.push_back(new CVarDef(this, "_Ecomposite_curve_on_surface" ,(StepNodeType) 18, (DWORD) &(this->_Ecomposite_curve_on_surface),"_Ecomposite_curve_on_surface"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Edate_time_item::Edate_time_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Edate_time_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition),"_Eproduct_definition"));

	 SetSelection(_Eproduct_definition); 
	 vars.push_back(new CVarDef(this, "_Echange_request" ,(StepNodeType) 18, (DWORD) &(this->_Echange_request),"_Echange_request"));
	 vars.push_back(new CVarDef(this, "_Estart_request" ,(StepNodeType) 18, (DWORD) &(this->_Estart_request),"_Estart_request"));
	 vars.push_back(new CVarDef(this, "_Echange" ,(StepNodeType) 18, (DWORD) &(this->_Echange),"_Echange"));
	 vars.push_back(new CVarDef(this, "_Estart_work" ,(StepNodeType) 18, (DWORD) &(this->_Estart_work),"_Estart_work"));
	 vars.push_back(new CVarDef(this, "_Eapproval_person_organization" ,(StepNodeType) 18, (DWORD) &(this->_Eapproval_person_organization),"_Eapproval_person_organization"));
	 vars.push_back(new CVarDef(this, "_Econtract" ,(StepNodeType) 18, (DWORD) &(this->_Econtract),"_Econtract"));
	 vars.push_back(new CVarDef(this, "_Esecurity_classification" ,(StepNodeType) 18, (DWORD) &(this->_Esecurity_classification),"_Esecurity_classification"));
	 vars.push_back(new CVarDef(this, "_Ecertification" ,(StepNodeType) 18, (DWORD) &(this->_Ecertification),"_Ecertification"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Edate_time_select::Edate_time_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Edate_time_select";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Edate_and_time" ,(StepNodeType) 18, (DWORD) &(this->_Edate_and_time),"_Edate_and_time"));

	 SetSelection(_Edate_and_time); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eday_in_month_number::Eday_in_month_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eday_in_month_number";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eday_in_week_number::Eday_in_week_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eday_in_week_number";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eday_in_year_number::Eday_in_year_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eday_in_year_number";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Edescriptive_measure::Edescriptive_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Edescriptive_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= string_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	 parents.push_back("EString"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Edimension_count::Edimension_count()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Edimension_count";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Egeometric_set_select::Egeometric_set_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Egeometric_set_select";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Epoint" ,(StepNodeType) 18, (DWORD) &(this->_Epoint),"_Epoint"));

	 SetSelection(_Epoint); 
	 vars.push_back(new CVarDef(this, "_Ecurve" ,(StepNodeType) 18, (DWORD) &(this->_Ecurve),"_Ecurve"));
	 vars.push_back(new CVarDef(this, "_Esurface" ,(StepNodeType) 18, (DWORD) &(this->_Esurface),"_Esurface"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ehour_in_day::Ehour_in_day()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ehour_in_day";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eidentifier::Eidentifier()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eidentifier";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= string_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	 parents.push_back("EString"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eknot_type::Eknot_type()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eknot_type";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 4; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Elabel::Elabel()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Elabel";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= string_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	 parents.push_back("EString"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Elength_measure::Elength_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Elength_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Elist_of_reversible_topology_item::Elist_of_reversible_topology_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Elist_of_reversible_topology_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= typelist_; 
	 this->ListType()= reference_; 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Emass_measure::Emass_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Emass_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Emeasure_value::Emeasure_value()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Emeasure_value";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Earea_measure" ,(StepNodeType) 4, (DWORD) &(this->_Earea_measure),"_Earea_measure"));

	 SetSelection(_Earea_measure); 
	 vars.push_back(new CVarDef(this, "_Econtext_dependent_measure" ,(StepNodeType) 4, (DWORD) &(this->_Econtext_dependent_measure),"_Econtext_dependent_measure"));
	 vars.push_back(new CVarDef(this, "_Ecount_measure" ,(StepNodeType) 9, (DWORD) &(this->_Ecount_measure),"_Ecount_measure"));
	 vars.push_back(new CVarDef(this, "_Edescriptive_measure" ,(StepNodeType) 5, (DWORD) &(this->_Edescriptive_measure),"_Edescriptive_measure"));
	 vars.push_back(new CVarDef(this, "_Elength_measure" ,(StepNodeType) 4, (DWORD) &(this->_Elength_measure),"_Elength_measure"));
	 vars.push_back(new CVarDef(this, "_Emass_measure" ,(StepNodeType) 4, (DWORD) &(this->_Emass_measure),"_Emass_measure"));
	 vars.push_back(new CVarDef(this, "_Eplane_angle_measure" ,(StepNodeType) 4, (DWORD) &(this->_Eplane_angle_measure),"_Eplane_angle_measure"));
	 vars.push_back(new CVarDef(this, "_Eparameter_value" ,(StepNodeType) 4, (DWORD) &(this->_Eparameter_value),"_Eparameter_value"));
	 vars.push_back(new CVarDef(this, "_Epositive_length_measure" ,(StepNodeType) 33, (DWORD) &(this->_Epositive_length_measure),"_Epositive_length_measure"));
	 vars.push_back(new CVarDef(this, "_Epositive_plane_angle_measure" ,(StepNodeType) 33, (DWORD) &(this->_Epositive_plane_angle_measure),"_Epositive_plane_angle_measure"));
	 vars.push_back(new CVarDef(this, "_Esolid_angle_measure" ,(StepNodeType) 4, (DWORD) &(this->_Esolid_angle_measure),"_Esolid_angle_measure"));
	 vars.push_back(new CVarDef(this, "_Evolume_measure" ,(StepNodeType) 4, (DWORD) &(this->_Evolume_measure),"_Evolume_measure"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eminute_in_hour::Eminute_in_hour()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eminute_in_hour";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Emonth_in_year_number::Emonth_in_year_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Emonth_in_year_number";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eparameter_value::Eparameter_value()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eparameter_value";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Epcurve_or_surface::Epcurve_or_surface()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Epcurve_or_surface";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Epcurve" ,(StepNodeType) 18, (DWORD) &(this->_Epcurve),"_Epcurve"));

	 SetSelection(_Epcurve); 
	 vars.push_back(new CVarDef(this, "_Esurface" ,(StepNodeType) 18, (DWORD) &(this->_Esurface),"_Esurface"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eperson_organization_item::Eperson_organization_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eperson_organization_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Echange" ,(StepNodeType) 18, (DWORD) &(this->_Echange),"_Echange"));

	 SetSelection(_Echange); 
	 vars.push_back(new CVarDef(this, "_Estart_work" ,(StepNodeType) 18, (DWORD) &(this->_Estart_work),"_Estart_work"));
	 vars.push_back(new CVarDef(this, "_Echange_request" ,(StepNodeType) 18, (DWORD) &(this->_Echange_request),"_Echange_request"));
	 vars.push_back(new CVarDef(this, "_Estart_request" ,(StepNodeType) 18, (DWORD) &(this->_Estart_request),"_Estart_request"));
	 vars.push_back(new CVarDef(this, "_Econfiguration_item" ,(StepNodeType) 18, (DWORD) &(this->_Econfiguration_item),"_Econfiguration_item"));
	 vars.push_back(new CVarDef(this, "_Eproduct" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct),"_Eproduct"));
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_formation" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_formation),"_Eproduct_definition_formation"));
	 vars.push_back(new CVarDef(this, "_Eproduct_definition" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition),"_Eproduct_definition"));
	 vars.push_back(new CVarDef(this, "_Econtract" ,(StepNodeType) 18, (DWORD) &(this->_Econtract),"_Econtract"));
	 vars.push_back(new CVarDef(this, "_Esecurity_classification" ,(StepNodeType) 18, (DWORD) &(this->_Esecurity_classification),"_Esecurity_classification"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eperson_organization_select::Eperson_organization_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eperson_organization_select";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eperson_and_organization" ,(StepNodeType) 18, (DWORD) &(this->_Eperson_and_organization),"_Eperson_and_organization"));

	 SetSelection(_Eperson_and_organization); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eplane_angle_measure::Eplane_angle_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eplane_angle_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Epositive_length_measure::Epositive_length_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Epositive_length_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= typereference_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "Elength_measure" ,(StepNodeType) 1, (DWORD) &(this->Elength_measure::vars),"Baseclass"));
	 parents.push_back("Elength_measure"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Epositive_plane_angle_measure::Epositive_plane_angle_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Epositive_plane_angle_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= typereference_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "Eplane_angle_measure" ,(StepNodeType) 1, (DWORD) &(this->Eplane_angle_measure::vars),"Baseclass"));
	 parents.push_back("Eplane_angle_measure"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Epreferred_surface_curve_representation::Epreferred_surface_curve_representation()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Epreferred_surface_curve_representation";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 3; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ereversible_topology::Ereversible_topology()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ereversible_topology";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Ereversible_topology_item" ,(StepNodeType) 21, (DWORD) &(this->_Ereversible_topology_item),"_Ereversible_topology_item"));

	 SetSelection(_Ereversible_topology_item); 
	 vars.push_back(new CVarDef(this, "_Elist_of_reversible_topology_item" ,(StepNodeType) 38, (DWORD) &(this->_Elist_of_reversible_topology_item),"_Elist_of_reversible_topology_item"));
	 vars.push_back(new CVarDef(this, "_Eset_of_reversible_topology_item" ,(StepNodeType) 38, (DWORD) &(this->_Eset_of_reversible_topology_item),"_Eset_of_reversible_topology_item"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ereversible_topology_item::Ereversible_topology_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ereversible_topology_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eedge" ,(StepNodeType) 18, (DWORD) &(this->_Eedge),"_Eedge"));

	 SetSelection(_Eedge); 
	 vars.push_back(new CVarDef(this, "_Epath" ,(StepNodeType) 18, (DWORD) &(this->_Epath),"_Epath"));
	 vars.push_back(new CVarDef(this, "_Eface" ,(StepNodeType) 18, (DWORD) &(this->_Eface),"_Eface"));
	 vars.push_back(new CVarDef(this, "_Eface_bound" ,(StepNodeType) 18, (DWORD) &(this->_Eface_bound),"_Eface_bound"));
	 vars.push_back(new CVarDef(this, "_Eclosed_shell" ,(StepNodeType) 18, (DWORD) &(this->_Eclosed_shell),"_Eclosed_shell"));
	 vars.push_back(new CVarDef(this, "_Eopen_shell" ,(StepNodeType) 18, (DWORD) &(this->_Eopen_shell),"_Eopen_shell"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Esecond_in_minute::Esecond_in_minute()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Esecond_in_minute";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eshape_definition::Eshape_definition()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eshape_definition";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_shape" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_shape),"_Eproduct_definition_shape"));

	 SetSelection(_Eproduct_definition_shape); 
	 vars.push_back(new CVarDef(this, "_Eshape_aspect" ,(StepNodeType) 18, (DWORD) &(this->_Eshape_aspect),"_Eshape_aspect"));
	 vars.push_back(new CVarDef(this, "_Eshape_aspect_relationship" ,(StepNodeType) 18, (DWORD) &(this->_Eshape_aspect_relationship),"_Eshape_aspect_relationship"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eshell::Eshell()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eshell";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eopen_shell" ,(StepNodeType) 18, (DWORD) &(this->_Eopen_shell),"_Eopen_shell"));

	 SetSelection(_Eopen_shell); 
	 vars.push_back(new CVarDef(this, "_Eclosed_shell" ,(StepNodeType) 18, (DWORD) &(this->_Eclosed_shell),"_Eclosed_shell"));
	 vars.push_back(new CVarDef(this, "_Evertex_shell" ,(StepNodeType) 18, (DWORD) &(this->_Evertex_shell),"_Evertex_shell"));
	 vars.push_back(new CVarDef(this, "_Ewire_shell" ,(StepNodeType) 18, (DWORD) &(this->_Ewire_shell),"_Ewire_shell"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Esi_prefix::Esi_prefix()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Esi_prefix";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 16; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Esi_unit_name::Esi_unit_name()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Esi_unit_name";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 28; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Esolid_angle_measure::Esolid_angle_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Esolid_angle_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Esource::Esource()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Esource";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 3; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Especified_item::Especified_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Especified_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition),"_Eproduct_definition"));

	 SetSelection(_Eproduct_definition); 
	 vars.push_back(new CVarDef(this, "_Eshape_aspect" ,(StepNodeType) 18, (DWORD) &(this->_Eshape_aspect),"_Eshape_aspect"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Estart_request_item::Estart_request_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Estart_request_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_formation" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_formation),"_Eproduct_definition_formation"));

	 SetSelection(_Eproduct_definition_formation); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Esupported_item::Esupported_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Esupported_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eaction_directive" ,(StepNodeType) 18, (DWORD) &(this->_Eaction_directive),"_Eaction_directive"));

	 SetSelection(_Eaction_directive); 
	 vars.push_back(new CVarDef(this, "_Eaction" ,(StepNodeType) 18, (DWORD) &(this->_Eaction),"_Eaction"));
	 vars.push_back(new CVarDef(this, "_Eaction_method" ,(StepNodeType) 18, (DWORD) &(this->_Eaction_method),"_Eaction_method"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Esurface_model::Esurface_model()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Esurface_model";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eshell_based_surface_model" ,(StepNodeType) 18, (DWORD) &(this->_Eshell_based_surface_model),"_Eshell_based_surface_model"));

	 SetSelection(_Eshell_based_surface_model); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Etext::Etext()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Etext";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= string_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	 parents.push_back("EString"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Etransformation::Etransformation()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Etransformation";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eitem_defined_transformation" ,(StepNodeType) 18, (DWORD) &(this->_Eitem_defined_transformation),"_Eitem_defined_transformation"));

	 SetSelection(_Eitem_defined_transformation); 
	 vars.push_back(new CVarDef(this, "_Efunctionally_defined_transformation" ,(StepNodeType) 18, (DWORD) &(this->_Efunctionally_defined_transformation),"_Efunctionally_defined_transformation"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Etransition_code::Etransition_code()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Etransition_code";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 4; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Etrimming_preference::Etrimming_preference()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Etrimming_preference";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= enumeration_; 
	 this->ListType()= unknown_; 
	 this->_nSelection= 3; 
	 parents.push_back("Eenum"); 
	 supertypes.push_back("Eenum"); 
	 vars.push_back(new CVarDef(this, "EEnum" ,(StepNodeType) enumeration_, (DWORD) this,"Baseclass"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Etrimming_select::Etrimming_select()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Etrimming_select";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Ecartesian_point" ,(StepNodeType) 18, (DWORD) &(this->_Ecartesian_point),"_Ecartesian_point"));

	 SetSelection(_Ecartesian_point); 
	 vars.push_back(new CVarDef(this, "_Eparameter_value" ,(StepNodeType) 4, (DWORD) &(this->_Eparameter_value),"_Eparameter_value"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eunit::Eunit()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eunit";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Enamed_unit" ,(StepNodeType) 18, (DWORD) &(this->_Enamed_unit),"_Enamed_unit"));

	 SetSelection(_Enamed_unit); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Evector_or_direction::Evector_or_direction()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Evector_or_direction";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Evector" ,(StepNodeType) 18, (DWORD) &(this->_Evector),"_Evector"));

	 SetSelection(_Evector); 
	 vars.push_back(new CVarDef(this, "_Edirection" ,(StepNodeType) 18, (DWORD) &(this->_Edirection),"_Edirection"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Evolume_measure::Evolume_measure()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Evolume_measure";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= real_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EReal" ,(StepNodeType) 1, (DWORD) &(this->EReal::vars),"Baseclass"));
	 parents.push_back("EReal"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eweek_in_year_number::Eweek_in_year_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eweek_in_year_number";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ewireframe_model::Ewireframe_model()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ewireframe_model";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eshell_based_wireframe_model" ,(StepNodeType) 18, (DWORD) &(this->_Eshell_based_wireframe_model),"_Eshell_based_wireframe_model"));

	 SetSelection(_Eshell_based_wireframe_model); 
	 vars.push_back(new CVarDef(this, "_Eedge_based_wireframe_model" ,(StepNodeType) 18, (DWORD) &(this->_Eedge_based_wireframe_model),"_Eedge_based_wireframe_model"));
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Ework_item::Ework_item()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Ework_item";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= select_; 
	 this->ListType()= unknown_; 
	 vars.push_back(new CVarDef(this, "_Eproduct_definition_formation" ,(StepNodeType) 18, (DWORD) &(this->_Eproduct_definition_formation),"_Eproduct_definition_formation"));

	 SetSelection(_Eproduct_definition_formation); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
Eyear_number::Eyear_number()
{
	 m_def.m_pClass=(DWORD)this;
	 m_def.m_pVars=&vars;
	 Classname()="Eyear_number";
	 parents.clear(); 
	 supertypes.clear(); 
	 this->Type()= integer_; 
	 this->ListType()= unknown_; 
	 this->Type()= typereference_; 
	 vars.push_back(new CVarDef(this, "EInteger" ,(StepNodeType) 1, (DWORD) &(this->EInteger::vars),"Baseclass"));
	 parents.push_back("EInteger"); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(vars, instancevars, vVisitedClasses);
}
IStepNodePtr Createap203Class(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname=="Eaction") return Eaction::Create(name);
	if(classname=="Eaction_assignment") return Eaction_assignment::Create(name);
	if(classname=="Eaction_directive") return Eaction_directive::Create(name);
	if(classname=="Eaction_method") return Eaction_method::Create(name);
	if(classname=="Eaction_request_assignment") return Eaction_request_assignment::Create(name);
	if(classname=="Eaction_request_solution") return Eaction_request_solution::Create(name);
	if(classname=="Eaction_request_status") return Eaction_request_status::Create(name);
	if(classname=="Eaction_status") return Eaction_status::Create(name);
	if(classname=="Eaddress") return Eaddress::Create(name);
	if(classname=="Eadvanced_brep_shape_representation") return Eadvanced_brep_shape_representation::Create(name);
	if(classname=="Eadvanced_face") return Eadvanced_face::Create(name);
	if(classname=="Ealternate_product_relationship") return Ealternate_product_relationship::Create(name);
	if(classname=="Eapplication_context") return Eapplication_context::Create(name);
	if(classname=="Eapplication_context_element") return Eapplication_context_element::Create(name);
	if(classname=="Eapplication_protocol_definition") return Eapplication_protocol_definition::Create(name);
	if(classname=="Eapproval") return Eapproval::Create(name);
	if(classname=="Eapproval_assignment") return Eapproval_assignment::Create(name);
	if(classname=="Eapproval_date_time") return Eapproval_date_time::Create(name);
	if(classname=="Eapproval_person_organization") return Eapproval_person_organization::Create(name);
	if(classname=="Eapproval_relationship") return Eapproval_relationship::Create(name);
	if(classname=="Eapproval_role") return Eapproval_role::Create(name);
	if(classname=="Eapproval_status") return Eapproval_status::Create(name);
	if(classname=="Earea_measure_with_unit") return Earea_measure_with_unit::Create(name);
	if(classname=="Earea_unit") return Earea_unit::Create(name);
	if(classname=="Eassembly_component_usage") return Eassembly_component_usage::Create(name);
	if(classname=="Eassembly_component_usage_substitute") return Eassembly_component_usage_substitute::Create(name);
	if(classname=="Eaxis1_placement") return Eaxis1_placement::Create(name);
	if(classname=="Eaxis2_placement_2d") return Eaxis2_placement_2d::Create(name);
	if(classname=="Eaxis2_placement_3d") return Eaxis2_placement_3d::Create(name);
	if(classname=="Eb_spline_curve") return Eb_spline_curve::Create(name);
	if(classname=="Eb_spline_curve_with_knots") return Eb_spline_curve_with_knots::Create(name);
	if(classname=="Eb_spline_surface") return Eb_spline_surface::Create(name);
	if(classname=="Eb_spline_surface_with_knots") return Eb_spline_surface_with_knots::Create(name);
	if(classname=="Ebezier_curve") return Ebezier_curve::Create(name);
	if(classname=="Ebezier_surface") return Ebezier_surface::Create(name);
	if(classname=="Eboundary_curve") return Eboundary_curve::Create(name);
	if(classname=="Ebounded_curve") return Ebounded_curve::Create(name);
	if(classname=="Ebounded_surface") return Ebounded_surface::Create(name);
	if(classname=="Ebrep_with_voids") return Ebrep_with_voids::Create(name);
	if(classname=="Ecalendar_date") return Ecalendar_date::Create(name);
	if(classname=="Ecartesian_point") return Ecartesian_point::Create(name);
	if(classname=="Ecartesian_transformation_operator") return Ecartesian_transformation_operator::Create(name);
	if(classname=="Ecartesian_transformation_operator_2d") return Ecartesian_transformation_operator_2d::Create(name);
	if(classname=="Ecartesian_transformation_operator_3d") return Ecartesian_transformation_operator_3d::Create(name);
	if(classname=="Ecc_design_approval") return Ecc_design_approval::Create(name);
	if(classname=="Ecc_design_certification") return Ecc_design_certification::Create(name);
	if(classname=="Ecc_design_contract") return Ecc_design_contract::Create(name);
	if(classname=="Ecc_design_date_and_time_assignment") return Ecc_design_date_and_time_assignment::Create(name);
	if(classname=="Ecc_design_person_and_organization_assignment") return Ecc_design_person_and_organization_assignment::Create(name);
	if(classname=="Ecc_design_security_classification") return Ecc_design_security_classification::Create(name);
	if(classname=="Ecc_design_specification_reference") return Ecc_design_specification_reference::Create(name);
	if(classname=="Ecertification") return Ecertification::Create(name);
	if(classname=="Ecertification_assignment") return Ecertification_assignment::Create(name);
	if(classname=="Ecertification_type") return Ecertification_type::Create(name);
	if(classname=="Echange") return Echange::Create(name);
	if(classname=="Echange_request") return Echange_request::Create(name);
	if(classname=="Ecircle") return Ecircle::Create(name);
	if(classname=="Eclosed_shell") return Eclosed_shell::Create(name);
	if(classname=="Ecomposite_curve") return Ecomposite_curve::Create(name);
	if(classname=="Ecomposite_curve_on_surface") return Ecomposite_curve_on_surface::Create(name);
	if(classname=="Ecomposite_curve_segment") return Ecomposite_curve_segment::Create(name);
	if(classname=="Econfiguration_design") return Econfiguration_design::Create(name);
	if(classname=="Econfiguration_effectivity") return Econfiguration_effectivity::Create(name);
	if(classname=="Econfiguration_item") return Econfiguration_item::Create(name);
	if(classname=="Econic") return Econic::Create(name);
	if(classname=="Econical_surface") return Econical_surface::Create(name);
	if(classname=="Econnected_edge_set") return Econnected_edge_set::Create(name);
	if(classname=="Econnected_face_set") return Econnected_face_set::Create(name);
	if(classname=="Econtext_dependent_shape_representation") return Econtext_dependent_shape_representation::Create(name);
	if(classname=="Econtext_dependent_unit") return Econtext_dependent_unit::Create(name);
	if(classname=="Econtract") return Econtract::Create(name);
	if(classname=="Econtract_assignment") return Econtract_assignment::Create(name);
	if(classname=="Econtract_type") return Econtract_type::Create(name);
	if(classname=="Econversion_based_unit") return Econversion_based_unit::Create(name);
	if(classname=="Ecoordinated_universal_time_offset") return Ecoordinated_universal_time_offset::Create(name);
	if(classname=="Ecurve") return Ecurve::Create(name);
	if(classname=="Ecurve_bounded_surface") return Ecurve_bounded_surface::Create(name);
	if(classname=="Ecurve_replica") return Ecurve_replica::Create(name);
	if(classname=="Ecylindrical_surface") return Ecylindrical_surface::Create(name);
	if(classname=="Edate") return Edate::Create(name);
	if(classname=="Edate_and_time") return Edate_and_time::Create(name);
	if(classname=="Edate_and_time_assignment") return Edate_and_time_assignment::Create(name);
	if(classname=="Edate_time_role") return Edate_time_role::Create(name);
	if(classname=="Edated_effectivity") return Edated_effectivity::Create(name);
	if(classname=="Edefinitional_representation") return Edefinitional_representation::Create(name);
	if(classname=="Edegenerate_pcurve") return Edegenerate_pcurve::Create(name);
	if(classname=="Edesign_context") return Edesign_context::Create(name);
	if(classname=="Edesign_make_from_relationship") return Edesign_make_from_relationship::Create(name);
	if(classname=="Edimensional_exponents") return Edimensional_exponents::Create(name);
	if(classname=="Edirected_action") return Edirected_action::Create(name);
	if(classname=="Edirection") return Edirection::Create(name);
	if(classname=="Edocument") return Edocument::Create(name);
	if(classname=="Edocument_reference") return Edocument_reference::Create(name);
	if(classname=="Edocument_relationship") return Edocument_relationship::Create(name);
	if(classname=="Edocument_type") return Edocument_type::Create(name);
	if(classname=="Edocument_usage_constraint") return Edocument_usage_constraint::Create(name);
	if(classname=="Edocument_with_class") return Edocument_with_class::Create(name);
	if(classname=="Eedge") return Eedge::Create(name);
	if(classname=="Eedge_based_wireframe_model") return Eedge_based_wireframe_model::Create(name);
	if(classname=="Eedge_based_wireframe_shape_representation") return Eedge_based_wireframe_shape_representation::Create(name);
	if(classname=="Eedge_curve") return Eedge_curve::Create(name);
	if(classname=="Eedge_loop") return Eedge_loop::Create(name);
	if(classname=="Eeffectivity") return Eeffectivity::Create(name);
	if(classname=="Eelementary_surface") return Eelementary_surface::Create(name);
	if(classname=="Eellipse") return Eellipse::Create(name);
	if(classname=="Eevaluated_degenerate_pcurve") return Eevaluated_degenerate_pcurve::Create(name);
	if(classname=="Eexecuted_action") return Eexecuted_action::Create(name);
	if(classname=="Eface") return Eface::Create(name);
	if(classname=="Eface_bound") return Eface_bound::Create(name);
	if(classname=="Eface_outer_bound") return Eface_outer_bound::Create(name);
	if(classname=="Eface_surface") return Eface_surface::Create(name);
	if(classname=="Efaceted_brep") return Efaceted_brep::Create(name);
	if(classname=="Efaceted_brep_shape_representation") return Efaceted_brep_shape_representation::Create(name);
	if(classname=="Efunctionally_defined_transformation") return Efunctionally_defined_transformation::Create(name);
	if(classname=="Egeometric_curve_set") return Egeometric_curve_set::Create(name);
	if(classname=="Egeometric_representation_context") return Egeometric_representation_context::Create(name);
	if(classname=="Egeometric_representation_item") return Egeometric_representation_item::Create(name);
	if(classname=="Egeometric_set") return Egeometric_set::Create(name);
	if(classname=="Egeometrically_bounded_surface_shape_representation") return Egeometrically_bounded_surface_shape_representation::Create(name);
	if(classname=="Egeometrically_bounded_wireframe_shape_representation") return Egeometrically_bounded_wireframe_shape_representation::Create(name);
	if(classname=="Eglobal_uncertainty_assigned_context") return Eglobal_uncertainty_assigned_context::Create(name);
	if(classname=="Eglobal_unit_assigned_context") return Eglobal_unit_assigned_context::Create(name);
	if(classname=="Ehyperbola") return Ehyperbola::Create(name);
	if(classname=="Eintersection_curve") return Eintersection_curve::Create(name);
	if(classname=="Eitem_defined_transformation") return Eitem_defined_transformation::Create(name);
	if(classname=="Elength_measure_with_unit") return Elength_measure_with_unit::Create(name);
	if(classname=="Elength_unit") return Elength_unit::Create(name);
	if(classname=="Eline") return Eline::Create(name);
	if(classname=="Elocal_time") return Elocal_time::Create(name);
	if(classname=="Eloop") return Eloop::Create(name);
	if(classname=="Elot_effectivity") return Elot_effectivity::Create(name);
	if(classname=="Emanifold_solid_brep") return Emanifold_solid_brep::Create(name);
	if(classname=="Emanifold_surface_shape_representation") return Emanifold_surface_shape_representation::Create(name);
	if(classname=="Emapped_item") return Emapped_item::Create(name);
	if(classname=="Emass_measure_with_unit") return Emass_measure_with_unit::Create(name);
	if(classname=="Emass_unit") return Emass_unit::Create(name);
	if(classname=="Emeasure_with_unit") return Emeasure_with_unit::Create(name);
	if(classname=="Emechanical_context") return Emechanical_context::Create(name);
	if(classname=="Enamed_unit") return Enamed_unit::Create(name);
	if(classname=="Enext_assembly_usage_occurrence") return Enext_assembly_usage_occurrence::Create(name);
	if(classname=="Eoffset_curve_2d") return Eoffset_curve_2d::Create(name);
	if(classname=="Eoffset_curve_3d") return Eoffset_curve_3d::Create(name);
	if(classname=="Eoffset_surface") return Eoffset_surface::Create(name);
	if(classname=="Eopen_shell") return Eopen_shell::Create(name);
	if(classname=="Eordinal_date") return Eordinal_date::Create(name);
	if(classname=="Eorganization") return Eorganization::Create(name);
	if(classname=="Eorganization_relationship") return Eorganization_relationship::Create(name);
	if(classname=="Eorganizational_address") return Eorganizational_address::Create(name);
	if(classname=="Eorganizational_project") return Eorganizational_project::Create(name);
	if(classname=="Eoriented_closed_shell") return Eoriented_closed_shell::Create(name);
	if(classname=="Eoriented_edge") return Eoriented_edge::Create(name);
	if(classname=="Eoriented_face") return Eoriented_face::Create(name);
	if(classname=="Eoriented_open_shell") return Eoriented_open_shell::Create(name);
	if(classname=="Eoriented_path") return Eoriented_path::Create(name);
	if(classname=="Eouter_boundary_curve") return Eouter_boundary_curve::Create(name);
	if(classname=="Eparabola") return Eparabola::Create(name);
	if(classname=="Eparametric_representation_context") return Eparametric_representation_context::Create(name);
	if(classname=="Epath") return Epath::Create(name);
	if(classname=="Epcurve") return Epcurve::Create(name);
	if(classname=="Eperson") return Eperson::Create(name);
	if(classname=="Eperson_and_organization") return Eperson_and_organization::Create(name);
	if(classname=="Eperson_and_organization_assignment") return Eperson_and_organization_assignment::Create(name);
	if(classname=="Eperson_and_organization_role") return Eperson_and_organization_role::Create(name);
	if(classname=="Epersonal_address") return Epersonal_address::Create(name);
	if(classname=="Eplacement") return Eplacement::Create(name);
	if(classname=="Eplane") return Eplane::Create(name);
	if(classname=="Eplane_angle_measure_with_unit") return Eplane_angle_measure_with_unit::Create(name);
	if(classname=="Eplane_angle_unit") return Eplane_angle_unit::Create(name);
	if(classname=="Epoint") return Epoint::Create(name);
	if(classname=="Epoint_on_curve") return Epoint_on_curve::Create(name);
	if(classname=="Epoint_on_surface") return Epoint_on_surface::Create(name);
	if(classname=="Epoint_replica") return Epoint_replica::Create(name);
	if(classname=="Epoly_loop") return Epoly_loop::Create(name);
	if(classname=="Epolyline") return Epolyline::Create(name);
	if(classname=="Eproduct") return Eproduct::Create(name);
	if(classname=="Eproduct_category") return Eproduct_category::Create(name);
	if(classname=="Eproduct_category_relationship") return Eproduct_category_relationship::Create(name);
	if(classname=="Eproduct_concept") return Eproduct_concept::Create(name);
	if(classname=="Eproduct_concept_context") return Eproduct_concept_context::Create(name);
	if(classname=="Eproduct_context") return Eproduct_context::Create(name);
	if(classname=="Eproduct_definition") return Eproduct_definition::Create(name);
	if(classname=="Eproduct_definition_context") return Eproduct_definition_context::Create(name);
	if(classname=="Eproduct_definition_effectivity") return Eproduct_definition_effectivity::Create(name);
	if(classname=="Eproduct_definition_formation") return Eproduct_definition_formation::Create(name);
	if(classname=="Eproduct_definition_formation_with_specified_source") return Eproduct_definition_formation_with_specified_source::Create(name);
	if(classname=="Eproduct_definition_relationship") return Eproduct_definition_relationship::Create(name);
	if(classname=="Eproduct_definition_shape") return Eproduct_definition_shape::Create(name);
	if(classname=="Eproduct_definition_usage") return Eproduct_definition_usage::Create(name);
	if(classname=="Eproduct_definition_with_associated_documents") return Eproduct_definition_with_associated_documents::Create(name);
	if(classname=="Eproduct_related_product_category") return Eproduct_related_product_category::Create(name);
	if(classname=="Epromissory_usage_occurrence") return Epromissory_usage_occurrence::Create(name);
	if(classname=="Eproperty_definition") return Eproperty_definition::Create(name);
	if(classname=="Eproperty_definition_representation") return Eproperty_definition_representation::Create(name);
	if(classname=="Equantified_assembly_component_usage") return Equantified_assembly_component_usage::Create(name);
	if(classname=="Equasi_uniform_curve") return Equasi_uniform_curve::Create(name);
	if(classname=="Equasi_uniform_surface") return Equasi_uniform_surface::Create(name);
	if(classname=="Erational_b_spline_curve") return Erational_b_spline_curve::Create(name);
	if(classname=="Erational_b_spline_surface") return Erational_b_spline_surface::Create(name);
	if(classname=="Erectangular_composite_surface") return Erectangular_composite_surface::Create(name);
	if(classname=="Erectangular_trimmed_surface") return Erectangular_trimmed_surface::Create(name);
	if(classname=="Ereparametrised_composite_curve_segment") return Ereparametrised_composite_curve_segment::Create(name);
	if(classname=="Erepresentation") return Erepresentation::Create(name);
	if(classname=="Erepresentation_context") return Erepresentation_context::Create(name);
	if(classname=="Erepresentation_item") return Erepresentation_item::Create(name);
	if(classname=="Erepresentation_map") return Erepresentation_map::Create(name);
	if(classname=="Erepresentation_relationship") return Erepresentation_relationship::Create(name);
	if(classname=="Erepresentation_relationship_with_transformation") return Erepresentation_relationship_with_transformation::Create(name);
	if(classname=="Eseam_curve") return Eseam_curve::Create(name);
	if(classname=="Esecurity_classification") return Esecurity_classification::Create(name);
	if(classname=="Esecurity_classification_assignment") return Esecurity_classification_assignment::Create(name);
	if(classname=="Esecurity_classification_level") return Esecurity_classification_level::Create(name);
	if(classname=="Eserial_numbered_effectivity") return Eserial_numbered_effectivity::Create(name);
	if(classname=="Eshape_aspect") return Eshape_aspect::Create(name);
	if(classname=="Eshape_aspect_relationship") return Eshape_aspect_relationship::Create(name);
	if(classname=="Eshape_definition_representation") return Eshape_definition_representation::Create(name);
	if(classname=="Eshape_representation") return Eshape_representation::Create(name);
	if(classname=="Eshape_representation_relationship") return Eshape_representation_relationship::Create(name);
	if(classname=="Eshell_based_surface_model") return Eshell_based_surface_model::Create(name);
	if(classname=="Eshell_based_wireframe_model") return Eshell_based_wireframe_model::Create(name);
	if(classname=="Eshell_based_wireframe_shape_representation") return Eshell_based_wireframe_shape_representation::Create(name);
	if(classname=="Esi_unit") return Esi_unit::Create(name);
	if(classname=="Esolid_angle_measure_with_unit") return Esolid_angle_measure_with_unit::Create(name);
	if(classname=="Esolid_angle_unit") return Esolid_angle_unit::Create(name);
	if(classname=="Esolid_model") return Esolid_model::Create(name);
	if(classname=="Especified_higher_usage_occurrence") return Especified_higher_usage_occurrence::Create(name);
	if(classname=="Espherical_surface") return Espherical_surface::Create(name);
	if(classname=="Estart_request") return Estart_request::Create(name);
	if(classname=="Estart_work") return Estart_work::Create(name);
	if(classname=="Esupplied_part_relationship") return Esupplied_part_relationship::Create(name);
	if(classname=="Esurface") return Esurface::Create(name);
	if(classname=="Esurface_curve") return Esurface_curve::Create(name);
	if(classname=="Esurface_of_linear_extrusion") return Esurface_of_linear_extrusion::Create(name);
	if(classname=="Esurface_of_revolution") return Esurface_of_revolution::Create(name);
	if(classname=="Esurface_patch") return Esurface_patch::Create(name);
	if(classname=="Esurface_replica") return Esurface_replica::Create(name);
	if(classname=="Eswept_surface") return Eswept_surface::Create(name);
	if(classname=="Etopological_representation_item") return Etopological_representation_item::Create(name);
	if(classname=="Etoroidal_surface") return Etoroidal_surface::Create(name);
	if(classname=="Etrimmed_curve") return Etrimmed_curve::Create(name);
	if(classname=="Euncertainty_measure_with_unit") return Euncertainty_measure_with_unit::Create(name);
	if(classname=="Euniform_curve") return Euniform_curve::Create(name);
	if(classname=="Euniform_surface") return Euniform_surface::Create(name);
	if(classname=="Evector") return Evector::Create(name);
	if(classname=="Eversioned_action_request") return Eversioned_action_request::Create(name);
	if(classname=="Evertex") return Evertex::Create(name);
	if(classname=="Evertex_loop") return Evertex_loop::Create(name);
	if(classname=="Evertex_point") return Evertex_point::Create(name);
	if(classname=="Evertex_shell") return Evertex_shell::Create(name);
	if(classname=="Evolume_measure_with_unit") return Evolume_measure_with_unit::Create(name);
	if(classname=="Evolume_unit") return Evolume_unit::Create(name);
	if(classname=="Eweek_of_year_and_day_date") return Eweek_of_year_and_day_date::Create(name);
	if(classname=="Ewire_shell") return Ewire_shell::Create(name);
	if(classname=="Eset_of_reversible_topology_item") return  (IStepNodePtr) new Eset_of_reversible_topology_item;
	if(classname=="Eahead_or_behind") return Eahead_or_behind::Create(name);
	if(classname=="Eapproved_item") return  (IStepNodePtr) new Eapproved_item;
	if(classname=="Earea_measure") return  (IStepNodePtr) new Earea_measure;
	if(classname=="Eaxis2_placement") return  (IStepNodePtr) new Eaxis2_placement;
	if(classname=="Eb_spline_curve_form") return Eb_spline_curve_form::Create(name);
	if(classname=="Eb_spline_surface_form") return Eb_spline_surface_form::Create(name);
	if(classname=="Eboolean_operand") return  (IStepNodePtr) new Eboolean_operand;
	if(classname=="Ecertified_item") return  (IStepNodePtr) new Ecertified_item;
	if(classname=="Echange_request_item") return  (IStepNodePtr) new Echange_request_item;
	if(classname=="Echaracterized_definition") return  (IStepNodePtr) new Echaracterized_definition;
	if(classname=="Echaracterized_product_definition") return  (IStepNodePtr) new Echaracterized_product_definition;
	if(classname=="Eclassified_item") return  (IStepNodePtr) new Eclassified_item;
	if(classname=="Econtext_dependent_measure") return  (IStepNodePtr) new Econtext_dependent_measure;
	if(classname=="Econtracted_item") return  (IStepNodePtr) new Econtracted_item;
	if(classname=="Ecount_measure") return  (IStepNodePtr) new Ecount_measure;
	if(classname=="Ecurve_on_surface") return  (IStepNodePtr) new Ecurve_on_surface;
	if(classname=="Edate_time_item") return  (IStepNodePtr) new Edate_time_item;
	if(classname=="Edate_time_select") return  (IStepNodePtr) new Edate_time_select;
	if(classname=="Eday_in_month_number") return  (IStepNodePtr) new Eday_in_month_number;
	if(classname=="Eday_in_week_number") return  (IStepNodePtr) new Eday_in_week_number;
	if(classname=="Eday_in_year_number") return  (IStepNodePtr) new Eday_in_year_number;
	if(classname=="Edescriptive_measure") return  (IStepNodePtr) new Edescriptive_measure;
	if(classname=="Edimension_count") return  (IStepNodePtr) new Edimension_count;
	if(classname=="Egeometric_set_select") return  (IStepNodePtr) new Egeometric_set_select;
	if(classname=="Ehour_in_day") return  (IStepNodePtr) new Ehour_in_day;
	if(classname=="Eidentifier") return  (IStepNodePtr) new Eidentifier;
	if(classname=="Eknot_type") return Eknot_type::Create(name);
	if(classname=="Elabel") return  (IStepNodePtr) new Elabel;
	if(classname=="Elength_measure") return  (IStepNodePtr) new Elength_measure;
	if(classname=="Elist_of_reversible_topology_item") return  (IStepNodePtr) new Elist_of_reversible_topology_item;
	if(classname=="Emass_measure") return  (IStepNodePtr) new Emass_measure;
	if(classname=="Emeasure_value") return  (IStepNodePtr) new Emeasure_value;
	if(classname=="Eminute_in_hour") return  (IStepNodePtr) new Eminute_in_hour;
	if(classname=="Emonth_in_year_number") return  (IStepNodePtr) new Emonth_in_year_number;
	if(classname=="Eparameter_value") return  (IStepNodePtr) new Eparameter_value;
	if(classname=="Epcurve_or_surface") return  (IStepNodePtr) new Epcurve_or_surface;
	if(classname=="Eperson_organization_item") return  (IStepNodePtr) new Eperson_organization_item;
	if(classname=="Eperson_organization_select") return  (IStepNodePtr) new Eperson_organization_select;
	if(classname=="Eplane_angle_measure") return  (IStepNodePtr) new Eplane_angle_measure;
	if(classname=="Epositive_length_measure") return  (IStepNodePtr) new Epositive_length_measure;
	if(classname=="Epositive_plane_angle_measure") return  (IStepNodePtr) new Epositive_plane_angle_measure;
	if(classname=="Epreferred_surface_curve_representation") return Epreferred_surface_curve_representation::Create(name);
	if(classname=="Ereversible_topology") return  (IStepNodePtr) new Ereversible_topology;
	if(classname=="Ereversible_topology_item") return  (IStepNodePtr) new Ereversible_topology_item;
	if(classname=="Esecond_in_minute") return  (IStepNodePtr) new Esecond_in_minute;
	if(classname=="Eshape_definition") return  (IStepNodePtr) new Eshape_definition;
	if(classname=="Eshell") return  (IStepNodePtr) new Eshell;
	if(classname=="Esi_prefix") return Esi_prefix::Create(name);
	if(classname=="Esi_unit_name") return Esi_unit_name::Create(name);
	if(classname=="Esolid_angle_measure") return  (IStepNodePtr) new Esolid_angle_measure;
	if(classname=="Esource") return Esource::Create(name);
	if(classname=="Especified_item") return  (IStepNodePtr) new Especified_item;
	if(classname=="Estart_request_item") return  (IStepNodePtr) new Estart_request_item;
	if(classname=="Esupported_item") return  (IStepNodePtr) new Esupported_item;
	if(classname=="Esurface_model") return  (IStepNodePtr) new Esurface_model;
	if(classname=="Etext") return  (IStepNodePtr) new Etext;
	if(classname=="Etransformation") return  (IStepNodePtr) new Etransformation;
	if(classname=="Etransition_code") return Etransition_code::Create(name);
	if(classname=="Etrimming_preference") return Etrimming_preference::Create(name);
	if(classname=="Etrimming_select") return  (IStepNodePtr) new Etrimming_select;
	if(classname=="Eunit") return  (IStepNodePtr) new Eunit;
	if(classname=="Evector_or_direction") return  (IStepNodePtr) new Evector_or_direction;
	if(classname=="Evolume_measure") return  (IStepNodePtr) new Evolume_measure;
	if(classname=="Eweek_in_year_number") return  (IStepNodePtr) new Eweek_in_year_number;
	if(classname=="Ewireframe_model") return  (IStepNodePtr) new Ewireframe_model;
	if(classname=="Ework_item") return  (IStepNodePtr) new Ework_item;
	if(classname=="Eyear_number") return  (IStepNodePtr) new Eyear_number;
	return NULL; 
}
	static CStringVector svEntities(252, 
	CString("Eaction"),
	CString("Eaction_assignment"),
	CString("Eaction_directive"),
	CString("Eaction_method"),
	CString("Eaction_request_assignment"),
	CString("Eaction_request_solution"),
	CString("Eaction_request_status"),
	CString("Eaction_status"),
	CString("Eaddress"),
	CString("Eadvanced_brep_shape_representation"),
	CString("Eadvanced_face"),
	CString("Ealternate_product_relationship"),
	CString("Eapplication_context"),
	CString("Eapplication_context_element"),
	CString("Eapplication_protocol_definition"),
	CString("Eapproval"),
	CString("Eapproval_assignment"),
	CString("Eapproval_date_time"),
	CString("Eapproval_person_organization"),
	CString("Eapproval_relationship"),
	CString("Eapproval_role"),
	CString("Eapproval_status"),
	CString("Earea_measure_with_unit"),
	CString("Earea_unit"),
	CString("Eassembly_component_usage"),
	CString("Eassembly_component_usage_substitute"),
	CString("Eaxis1_placement"),
	CString("Eaxis2_placement_2d"),
	CString("Eaxis2_placement_3d"),
	CString("Eb_spline_curve"),
	CString("Eb_spline_curve_with_knots"),
	CString("Eb_spline_surface"),
	CString("Eb_spline_surface_with_knots"),
	CString("Ebezier_curve"),
	CString("Ebezier_surface"),
	CString("Eboundary_curve"),
	CString("Ebounded_curve"),
	CString("Ebounded_surface"),
	CString("Ebrep_with_voids"),
	CString("Ecalendar_date"),
	CString("Ecartesian_point"),
	CString("Ecartesian_transformation_operator"),
	CString("Ecartesian_transformation_operator_2d"),
	CString("Ecartesian_transformation_operator_3d"),
	CString("Ecc_design_approval"),
	CString("Ecc_design_certification"),
	CString("Ecc_design_contract"),
	CString("Ecc_design_date_and_time_assignment"),
	CString("Ecc_design_person_and_organization_assignment"),
	CString("Ecc_design_security_classification"),
	CString("Ecc_design_specification_reference"),
	CString("Ecertification"),
	CString("Ecertification_assignment"),
	CString("Ecertification_type"),
	CString("Echange"),
	CString("Echange_request"),
	CString("Ecircle"),
	CString("Eclosed_shell"),
	CString("Ecomposite_curve"),
	CString("Ecomposite_curve_on_surface"),
	CString("Ecomposite_curve_segment"),
	CString("Econfiguration_design"),
	CString("Econfiguration_effectivity"),
	CString("Econfiguration_item"),
	CString("Econic"),
	CString("Econical_surface"),
	CString("Econnected_edge_set"),
	CString("Econnected_face_set"),
	CString("Econtext_dependent_shape_representation"),
	CString("Econtext_dependent_unit"),
	CString("Econtract"),
	CString("Econtract_assignment"),
	CString("Econtract_type"),
	CString("Econversion_based_unit"),
	CString("Ecoordinated_universal_time_offset"),
	CString("Ecurve"),
	CString("Ecurve_bounded_surface"),
	CString("Ecurve_replica"),
	CString("Ecylindrical_surface"),
	CString("Edate"),
	CString("Edate_and_time"),
	CString("Edate_and_time_assignment"),
	CString("Edate_time_role"),
	CString("Edated_effectivity"),
	CString("Edefinitional_representation"),
	CString("Edegenerate_pcurve"),
	CString("Edesign_context"),
	CString("Edesign_make_from_relationship"),
	CString("Edimensional_exponents"),
	CString("Edirected_action"),
	CString("Edirection"),
	CString("Edocument"),
	CString("Edocument_reference"),
	CString("Edocument_relationship"),
	CString("Edocument_type"),
	CString("Edocument_usage_constraint"),
	CString("Edocument_with_class"),
	CString("Eedge"),
	CString("Eedge_based_wireframe_model"),
	CString("Eedge_based_wireframe_shape_representation"),
	CString("Eedge_curve"),
	CString("Eedge_loop"),
	CString("Eeffectivity"),
	CString("Eelementary_surface"),
	CString("Eellipse"),
	CString("Eevaluated_degenerate_pcurve"),
	CString("Eexecuted_action"),
	CString("Eface"),
	CString("Eface_bound"),
	CString("Eface_outer_bound"),
	CString("Eface_surface"),
	CString("Efaceted_brep"),
	CString("Efaceted_brep_shape_representation"),
	CString("Efunctionally_defined_transformation"),
	CString("Egeometric_curve_set"),
	CString("Egeometric_representation_context"),
	CString("Egeometric_representation_item"),
	CString("Egeometric_set"),
	CString("Egeometrically_bounded_surface_shape_representation"),
	CString("Egeometrically_bounded_wireframe_shape_representation"),
	CString("Eglobal_uncertainty_assigned_context"),
	CString("Eglobal_unit_assigned_context"),
	CString("Ehyperbola"),
	CString("Eintersection_curve"),
	CString("Eitem_defined_transformation"),
	CString("Elength_measure_with_unit"),
	CString("Elength_unit"),
	CString("Eline"),
	CString("Elocal_time"),
	CString("Eloop"),
	CString("Elot_effectivity"),
	CString("Emanifold_solid_brep"),
	CString("Emanifold_surface_shape_representation"),
	CString("Emapped_item"),
	CString("Emass_measure_with_unit"),
	CString("Emass_unit"),
	CString("Emeasure_with_unit"),
	CString("Emechanical_context"),
	CString("Enamed_unit"),
	CString("Enext_assembly_usage_occurrence"),
	CString("Eoffset_curve_2d"),
	CString("Eoffset_curve_3d"),
	CString("Eoffset_surface"),
	CString("Eopen_shell"),
	CString("Eordinal_date"),
	CString("Eorganization"),
	CString("Eorganization_relationship"),
	CString("Eorganizational_address"),
	CString("Eorganizational_project"),
	CString("Eoriented_closed_shell"),
	CString("Eoriented_edge"),
	CString("Eoriented_face"),
	CString("Eoriented_open_shell"),
	CString("Eoriented_path"),
	CString("Eouter_boundary_curve"),
	CString("Eparabola"),
	CString("Eparametric_representation_context"),
	CString("Epath"),
	CString("Epcurve"),
	CString("Eperson"),
	CString("Eperson_and_organization"),
	CString("Eperson_and_organization_assignment"),
	CString("Eperson_and_organization_role"),
	CString("Epersonal_address"),
	CString("Eplacement"),
	CString("Eplane"),
	CString("Eplane_angle_measure_with_unit"),
	CString("Eplane_angle_unit"),
	CString("Epoint"),
	CString("Epoint_on_curve"),
	CString("Epoint_on_surface"),
	CString("Epoint_replica"),
	CString("Epoly_loop"),
	CString("Epolyline"),
	CString("Eproduct"),
	CString("Eproduct_category"),
	CString("Eproduct_category_relationship"),
	CString("Eproduct_concept"),
	CString("Eproduct_concept_context"),
	CString("Eproduct_context"),
	CString("Eproduct_definition"),
	CString("Eproduct_definition_context"),
	CString("Eproduct_definition_effectivity"),
	CString("Eproduct_definition_formation"),
	CString("Eproduct_definition_formation_with_specified_source"),
	CString("Eproduct_definition_relationship"),
	CString("Eproduct_definition_shape"),
	CString("Eproduct_definition_usage"),
	CString("Eproduct_definition_with_associated_documents"),
	CString("Eproduct_related_product_category"),
	CString("Epromissory_usage_occurrence"),
	CString("Eproperty_definition"),
	CString("Eproperty_definition_representation"),
	CString("Equantified_assembly_component_usage"),
	CString("Equasi_uniform_curve"),
	CString("Equasi_uniform_surface"),
	CString("Erational_b_spline_curve"),
	CString("Erational_b_spline_surface"),
	CString("Erectangular_composite_surface"),
	CString("Erectangular_trimmed_surface"),
	CString("Ereparametrised_composite_curve_segment"),
	CString("Erepresentation"),
	CString("Erepresentation_context"),
	CString("Erepresentation_item"),
	CString("Erepresentation_map"),
	CString("Erepresentation_relationship"),
	CString("Erepresentation_relationship_with_transformation"),
	CString("Eseam_curve"),
	CString("Esecurity_classification"),
	CString("Esecurity_classification_assignment"),
	CString("Esecurity_classification_level"),
	CString("Eserial_numbered_effectivity"),
	CString("Eshape_aspect"),
	CString("Eshape_aspect_relationship"),
	CString("Eshape_definition_representation"),
	CString("Eshape_representation"),
	CString("Eshape_representation_relationship"),
	CString("Eshell_based_surface_model"),
	CString("Eshell_based_wireframe_model"),
	CString("Eshell_based_wireframe_shape_representation"),
	CString("Esi_unit"),
	CString("Esolid_angle_measure_with_unit"),
	CString("Esolid_angle_unit"),
	CString("Esolid_model"),
	CString("Especified_higher_usage_occurrence"),
	CString("Espherical_surface"),
	CString("Estart_request"),
	CString("Estart_work"),
	CString("Esupplied_part_relationship"),
	CString("Esurface"),
	CString("Esurface_curve"),
	CString("Esurface_of_linear_extrusion"),
	CString("Esurface_of_revolution"),
	CString("Esurface_patch"),
	CString("Esurface_replica"),
	CString("Eswept_surface"),
	CString("Etopological_representation_item"),
	CString("Etoroidal_surface"),
	CString("Etrimmed_curve"),
	CString("Euncertainty_measure_with_unit"),
	CString("Euniform_curve"),
	CString("Euniform_surface"),
	CString("Evector"),
	CString("Eversioned_action_request"),
	CString("Evertex"),
	CString("Evertex_loop"),
	CString("Evertex_point"),
	CString("Evertex_shell"),
	CString("Evolume_measure_with_unit"),
	CString("Evolume_unit"),
	CString("Eweek_of_year_and_day_date"),
	CString("Ewire_shell"));
 CStringVector GetAllap203Entities(){ return svEntities;}
} /* End namespace Express*/
