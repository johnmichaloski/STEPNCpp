//
// c:\Program Files\NIST\proj\Tests\P203Reader\P203Reader\ap203ClassDefinitions.h
//
#pragma once

#include "ExpressUtils.h"
#include "ap203SchemaDeclarations.h"

namespace Express{
// FIXME: Add ClassGenerators::gClassGenerators.AddGenerator(&Createap203Class);
extern IStepNodePtr Createap203Class(CString classname, CString name) ;
extern CStringVector GetAllap203Entities();
class Eset_of_reversible_topology_item : public EListT<Ereversible_topology_itemPtr> /*typedef to list or multilist*/
{
public:
	CLASSDEF(Eset_of_reversible_topology_item); 
};
class Eahead_or_behind : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Eahead_or_behind); 
			enum Eahead_or_behindEnum
	{
	ahead=0,
	behind} ;
	void SetSelection(Eahead_or_behindEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"ahead",
"behind"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eapproved_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eapproved_item); 
	Eproduct_definition_formationPtr _Eproduct_definition_formation;
	Eproduct_definitionPtr _Eproduct_definition;
	Econfiguration_effectivityPtr _Econfiguration_effectivity;
	Econfiguration_itemPtr _Econfiguration_item;
	Esecurity_classificationPtr _Esecurity_classification;
	Echange_requestPtr _Echange_request;
	EchangePtr _Echange;
	Estart_requestPtr _Estart_request;
	Estart_workPtr _Estart_work;
	EcertificationPtr _Ecertification;
	EcontractPtr _Econtract;
};
class Earea_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Earea_measure); 
};
class Eaxis2_placement : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eaxis2_placement); 
	Eaxis2_placement_2dPtr _Eaxis2_placement_2d;
	Eaxis2_placement_3dPtr _Eaxis2_placement_3d;
};
class Eb_spline_curve_form : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Eb_spline_curve_form); 
			enum Eb_spline_curve_formEnum
	{
	elliptic_arc=0,
	polyline_form,
	parabolic_arc,
	circular_arc,
	unspecified,
	hyperbolic_arc} ;
	void SetSelection(Eb_spline_curve_formEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 6;
		static char * szEnums[6]={
"elliptic_arc",
"polyline_form",
"parabolic_arc",
"circular_arc",
"unspecified",
"hyperbolic_arc"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 6;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eb_spline_surface_form : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Eb_spline_surface_form); 
			enum Eb_spline_surface_formEnum
	{
	surf_of_linear_extrusion=0,
	plane_surf,
	generalised_cone,
	toroidal_surf,
	conical_surf,
	spherical_surf,
	unspecified,
	ruled_surf,
	surf_of_revolution,
	cylindrical_surf,
	quadric_surf} ;
	void SetSelection(Eb_spline_surface_formEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 11;
		static char * szEnums[11]={
"surf_of_linear_extrusion",
"plane_surf",
"generalised_cone",
"toroidal_surf",
"conical_surf",
"spherical_surf",
"unspecified",
"ruled_surf",
"surf_of_revolution",
"cylindrical_surf",
"quadric_surf"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 11;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eboolean_operand : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eboolean_operand); 
	Esolid_modelPtr _Esolid_model;
};
class Ecertified_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ecertified_item); 
	Esupplied_part_relationshipPtr _Esupplied_part_relationship;
};
class Echange_request_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Echange_request_item); 
	Eproduct_definition_formationPtr _Eproduct_definition_formation;
};
class Echaracterized_definition : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Echaracterized_definition); 
	Echaracterized_product_definitionPtr _Echaracterized_product_definition;
	Eshape_definitionPtr _Eshape_definition;
};
class Echaracterized_product_definition : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Echaracterized_product_definition); 
	Eproduct_definitionPtr _Eproduct_definition;
	Eproduct_definition_relationshipPtr _Eproduct_definition_relationship;
};
class Eclassified_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eclassified_item); 
	Eproduct_definition_formationPtr _Eproduct_definition_formation;
	Eassembly_component_usagePtr _Eassembly_component_usage;
};
class Econtext_dependent_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Econtext_dependent_measure); 
};
class Econtracted_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Econtracted_item); 
	Eproduct_definition_formationPtr _Eproduct_definition_formation;
};
class Ecount_measure : public ENumber /*typedef*/
{
public:
	CLASSDEF(Ecount_measure); 
};
class Ecurve_on_surface : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ecurve_on_surface); 
	EpcurvePtr _Epcurve;
	Esurface_curvePtr _Esurface_curve;
	Ecomposite_curve_on_surfacePtr _Ecomposite_curve_on_surface;
};
class Edate_time_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Edate_time_item); 
	Eproduct_definitionPtr _Eproduct_definition;
	Echange_requestPtr _Echange_request;
	Estart_requestPtr _Estart_request;
	EchangePtr _Echange;
	Estart_workPtr _Estart_work;
	Eapproval_person_organizationPtr _Eapproval_person_organization;
	EcontractPtr _Econtract;
	Esecurity_classificationPtr _Esecurity_classification;
	EcertificationPtr _Ecertification;
};
class Edate_time_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Edate_time_select); 
	Edate_and_timePtr _Edate_and_time;
};
class Eday_in_month_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_month_number); 
};
class Eday_in_week_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_week_number); 
};
class Eday_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_year_number); 
};
class Edescriptive_measure : public EString /*typedef*/
{
public:
	CLASSDEF(Edescriptive_measure); 
};
class Edimension_count : public EInteger /*typedef*/
{
public:
	CLASSDEF(Edimension_count); 
};
class Egeometric_set_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Egeometric_set_select); 
	EpointPtr _Epoint;
	EcurvePtr _Ecurve;
	EsurfacePtr _Esurface;
};
class Ehour_in_day : public EInteger /*typedef*/
{
public:
	CLASSDEF(Ehour_in_day); 
};
class Eidentifier : public EString /*typedef*/
{
public:
	CLASSDEF(Eidentifier); 
};
class Eknot_type : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Eknot_type); 
			enum Eknot_typeEnum
	{
	uniform_knots=0,
	quasi_uniform_knots,
	piecewise_bezier_knots,
	unspecified} ;
	void SetSelection(Eknot_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static char * szEnums[4]={
"uniform_knots",
"quasi_uniform_knots",
"piecewise_bezier_knots",
"unspecified"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Elabel : public EString /*typedef*/
{
public:
	CLASSDEF(Elabel); 
};
class Elength_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Elength_measure); 
};
class Elist_of_reversible_topology_item : public EListT<Ereversible_topology_itemPtr> /*typedef to list or multilist*/
{
public:
	CLASSDEF(Elist_of_reversible_topology_item); 
};
class Emass_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Emass_measure); 
};
class Emeasure_value : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Emeasure_value); 
	Earea_measurePtr _Earea_measure;
	Econtext_dependent_measurePtr _Econtext_dependent_measure;
	Ecount_measurePtr _Ecount_measure;
	Edescriptive_measurePtr _Edescriptive_measure;
	Elength_measurePtr _Elength_measure;
	Emass_measurePtr _Emass_measure;
	Eplane_angle_measurePtr _Eplane_angle_measure;
	Eparameter_valuePtr _Eparameter_value;
	Epositive_length_measurePtr _Epositive_length_measure;
	Epositive_plane_angle_measurePtr _Epositive_plane_angle_measure;
	Esolid_angle_measurePtr _Esolid_angle_measure;
	Evolume_measurePtr _Evolume_measure;
};
class Eminute_in_hour : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eminute_in_hour); 
};
class Emonth_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Emonth_in_year_number); 
};
class Eparameter_value : public EReal /*typedef*/
{
public:
	CLASSDEF(Eparameter_value); 
};
class Epcurve_or_surface : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Epcurve_or_surface); 
	EpcurvePtr _Epcurve;
	EsurfacePtr _Esurface;
};
class Eperson_organization_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eperson_organization_item); 
	EchangePtr _Echange;
	Estart_workPtr _Estart_work;
	Echange_requestPtr _Echange_request;
	Estart_requestPtr _Estart_request;
	Econfiguration_itemPtr _Econfiguration_item;
	EproductPtr _Eproduct;
	Eproduct_definition_formationPtr _Eproduct_definition_formation;
	Eproduct_definitionPtr _Eproduct_definition;
	EcontractPtr _Econtract;
	Esecurity_classificationPtr _Esecurity_classification;
};
class Eperson_organization_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eperson_organization_select); 
	Eperson_and_organizationPtr _Eperson_and_organization;
};
class Eplane_angle_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Eplane_angle_measure); 
};
class Epositive_length_measure : public Elength_measure /*typedef*/
{
public:
	CLASSDEF(Epositive_length_measure); 
};
class Epositive_plane_angle_measure : public Eplane_angle_measure /*typedef*/
{
public:
	CLASSDEF(Epositive_plane_angle_measure); 
};
class Epreferred_surface_curve_representation : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Epreferred_surface_curve_representation); 
			enum Epreferred_surface_curve_representationEnum
	{
	pcurve_s2=0,
	pcurve_s1,
	curve_3d} ;
	void SetSelection(Epreferred_surface_curve_representationEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static char * szEnums[3]={
"pcurve_s2",
"pcurve_s1",
"curve_3d"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Ereversible_topology : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ereversible_topology); 
	Ereversible_topology_itemPtr _Ereversible_topology_item;
	Elist_of_reversible_topology_itemPtr _Elist_of_reversible_topology_item;
	Eset_of_reversible_topology_itemPtr _Eset_of_reversible_topology_item;
};
class Ereversible_topology_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ereversible_topology_item); 
	EedgePtr _Eedge;
	EpathPtr _Epath;
	EfacePtr _Eface;
	Eface_boundPtr _Eface_bound;
	Eclosed_shellPtr _Eclosed_shell;
	Eopen_shellPtr _Eopen_shell;
};
class Esecond_in_minute : public EReal /*typedef*/
{
public:
	CLASSDEF(Esecond_in_minute); 
};
class Eshape_definition : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eshape_definition); 
	Eproduct_definition_shapePtr _Eproduct_definition_shape;
	Eshape_aspectPtr _Eshape_aspect;
	Eshape_aspect_relationshipPtr _Eshape_aspect_relationship;
};
class Eshell : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eshell); 
	Eopen_shellPtr _Eopen_shell;
	Eclosed_shellPtr _Eclosed_shell;
	Evertex_shellPtr _Evertex_shell;
	Ewire_shellPtr _Ewire_shell;
};
class Esi_prefix : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Esi_prefix); 
			enum Esi_prefixEnum
	{
	exa=0,
	pico,
	mega,
	femto,
	atto,
	centi,
	nano,
	hecto,
	micro,
	tera,
	giga,
	milli,
	peta,
	deci,
	kilo,
	deca} ;
	void SetSelection(Esi_prefixEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 16;
		static char * szEnums[16]={
"exa",
"pico",
"mega",
"femto",
"atto",
"centi",
"nano",
"hecto",
"micro",
"tera",
"giga",
"milli",
"peta",
"deci",
"kilo",
"deca"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 16;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Esi_unit_name : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Esi_unit_name); 
			enum Esi_unit_nameEnum
	{
	hertz=0,
	degree_celsius,
	siemens,
	sievert,
	lux,
	watt,
	ohm,
	second,
	becquerel,
	epascal,
	henry,
	tesla,
	volt,
	joule,
	kelvin,
	ampere,
	gram,
	steradian,
	mole,
	lumen,
	gray,
	candela,
	farad,
	radian,
	newton,
	metre,
	weber,
	coulomb} ;
	void SetSelection(Esi_unit_nameEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 28;
		static char * szEnums[28]={
"hertz",
"degree_celsius",
"siemens",
"sievert",
"lux",
"watt",
"ohm",
"second",
"becquerel",
"pascal",
"henry",
"tesla",
"volt",
"joule",
"kelvin",
"ampere",
"gram",
"steradian",
"mole",
"lumen",
"gray",
"candela",
"farad",
"radian",
"newton",
"metre",
"weber",
"coulomb"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 28;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Esolid_angle_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Esolid_angle_measure); 
};
class Esource : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Esource); 
			enum EsourceEnum
	{
	bought=0,
	not_known,
	made} ;
	void SetSelection(EsourceEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static char * szEnums[3]={
"bought",
"not_known",
"made"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Especified_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Especified_item); 
	Eproduct_definitionPtr _Eproduct_definition;
	Eshape_aspectPtr _Eshape_aspect;
};
class Estart_request_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Estart_request_item); 
	Eproduct_definition_formationPtr _Eproduct_definition_formation;
};
class Esupported_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Esupported_item); 
	Eaction_directivePtr _Eaction_directive;
	EactionPtr _Eaction;
	Eaction_methodPtr _Eaction_method;
};
class Esurface_model : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Esurface_model); 
	Eshell_based_surface_modelPtr _Eshell_based_surface_model;
};
class Etext : public EString /*typedef*/
{
public:
	CLASSDEF(Etext); 
};
class Etransformation : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Etransformation); 
	Eitem_defined_transformationPtr _Eitem_defined_transformation;
	Efunctionally_defined_transformationPtr _Efunctionally_defined_transformation;
};
class Etransition_code : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Etransition_code); 
			enum Etransition_codeEnum
	{
	discontinuous=0,
	cont_same_gradient_same_curvature,
	cont_same_gradient,
	continuous} ;
	void SetSelection(Etransition_codeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static char * szEnums[4]={
"discontinuous",
"cont_same_gradient_same_curvature",
"cont_same_gradient",
"continuous"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etrimming_preference : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Etrimming_preference); 
			enum Etrimming_preferenceEnum
	{
	parameter=0,
	unspecified,
	cartesian} ;
	void SetSelection(Etrimming_preferenceEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static char * szEnums[3]={
"parameter",
"unspecified",
"cartesian"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etrimming_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Etrimming_select); 
	Ecartesian_pointPtr _Ecartesian_point;
	Eparameter_valuePtr _Eparameter_value;
};
class Eunit : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eunit); 
	Enamed_unitPtr _Enamed_unit;
};
class Evector_or_direction : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Evector_or_direction); 
	EvectorPtr _Evector;
	EdirectionPtr _Edirection;
};
class Evolume_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Evolume_measure); 
};
class Eweek_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eweek_in_year_number); 
};
class Ewireframe_model : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ewireframe_model); 
	Eshell_based_wireframe_modelPtr _Eshell_based_wireframe_model;
	Eedge_based_wireframe_modelPtr _Eedge_based_wireframe_model;
};
class Ework_item : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ework_item); 
	Eproduct_definition_formationPtr _Eproduct_definition_formation;
};
class Eyear_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eyear_number); 
};
class Eaction : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction); 
	ElabelPtr name; 
	EtextPtr description; 
	Eaction_methodPtr chosen_method; 
};
class Eaction_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction_assignment); 
	EactionPtr assigned_action; 
};
class Eaction_directive : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction_directive); 
	ElabelPtr name; 
	EtextPtr description; 
	EtextPtr analysis; 
	EtextPtr comment; 
	EListT<Eversioned_action_requestPtr> requests; 
};
class Eaction_method : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction_method); 
	ElabelPtr name; 
	EtextPtr description; 
	EtextPtr consequence; 
	EtextPtr purpose; 
};
class Eaction_request_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction_request_assignment); 
	Eversioned_action_requestPtr assigned_action_request; 
};
class Eaction_request_solution : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction_request_solution); 
	Eaction_methodPtr method; 
	Eversioned_action_requestPtr request; 
};
class Eaction_request_status : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction_request_status); 
	ElabelPtr status; 
	Eversioned_action_requestPtr assigned_request; 
};
class Eaction_status : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaction_status); 
	ElabelPtr status; 
	Eexecuted_actionPtr assigned_action; 
};
class Eaddress : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eaddress); 
	ElabelPtr internal_location; 
	ElabelPtr street_number; 
	ElabelPtr street; 
	ElabelPtr postal_box; 
	ElabelPtr town; 
	ElabelPtr region; 
	ElabelPtr postal_code; 
	ElabelPtr country; 
	ElabelPtr facsimile_number; 
	ElabelPtr telephone_number; 
	ElabelPtr electronic_mail_address; 
	ElabelPtr telex_number; 
};
class Erepresentation : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erepresentation); 
	ElabelPtr name; 
	EListT<Erepresentation_itemPtr> items; 
	Erepresentation_contextPtr context_of_items; 
};
class Eshape_representation : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation _representation;
	CLASSDEF(Eshape_representation); 
};
class Eadvanced_brep_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Eadvanced_brep_shape_representation); 
};
class Erepresentation_item : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erepresentation_item); 
	ElabelPtr name; 
};
class Etopological_representation_item : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_item _representation_item;
	CLASSDEF(Etopological_representation_item); 
};
class Eface : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Eface); 
	EListT<Eface_boundPtr> bounds; 
};
class Egeometric_representation_item : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_item _representation_item;
	CLASSDEF(Egeometric_representation_item); 
};
class Eface_surface : public IStepNode
{
public:
//// Inherited classes 
	Eface _face;
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eface_surface); 
	EsurfacePtr face_geometry; 
	EBooleanPtr same_sense; 
};
class Eadvanced_face : public IStepNode
{
public:
//// Inherited classes 
	Eface_surface _face_surface;
	CLASSDEF(Eadvanced_face); 
};
class Ealternate_product_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ealternate_product_relationship); 
	ElabelPtr name; 
	EtextPtr description; 
	EproductPtr alternate; 
	EproductPtr base; 
	EtextPtr basis; 
};
class Eapplication_context : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapplication_context); 
	EtextPtr application; 
};
class Eapplication_context_element : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapplication_context_element); 
	ElabelPtr name; 
	Eapplication_contextPtr frame_of_reference; 
};
class Eapplication_protocol_definition : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapplication_protocol_definition); 
	ElabelPtr status; 
	ElabelPtr application_interpreted_model_schema_name; 
	Eyear_numberPtr application_protocol_year; 
	Eapplication_contextPtr application; 
};
class Eapproval : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval); 
	Eapproval_statusPtr status; 
	ElabelPtr level; 
};
class Eapproval_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval_assignment); 
	EapprovalPtr assigned_approval; 
};
class Eapproval_date_time : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval_date_time); 
	Edate_time_selectPtr date_time; 
	EapprovalPtr dated_approval; 
};
class Eapproval_person_organization : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval_person_organization); 
	Eperson_organization_selectPtr person_organization; 
	EapprovalPtr authorized_approval; 
	Eapproval_rolePtr role; 
};
class Eapproval_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval_relationship); 
	ElabelPtr name; 
	EtextPtr description; 
	EapprovalPtr relating_approval; 
	EapprovalPtr related_approval; 
};
class Eapproval_role : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval_role); 
	ElabelPtr role; 
};
class Eapproval_status : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval_status); 
	ElabelPtr name; 
};
class Emeasure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Emeasure_with_unit); 
	Emeasure_valuePtr value_component; 
	EunitPtr unit_component; 
};
class Earea_measure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	Emeasure_with_unit _measure_with_unit;
	CLASSDEF(Earea_measure_with_unit); 
};
class Enamed_unit : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Enamed_unit); 
	Edimensional_exponentsPtr dimensions; 
};
class Earea_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Earea_unit); 
};
class Eproduct_definition_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproduct_definition_relationship); 
	EidentifierPtr id; 
	ElabelPtr name; 
	EtextPtr description; 
	Eproduct_definitionPtr relating_product_definition; 
	Eproduct_definitionPtr related_product_definition; 
};
class Eproduct_definition_usage : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition_relationship _product_definition_relationship;
	CLASSDEF(Eproduct_definition_usage); 
};
class Eassembly_component_usage : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition_usage _product_definition_usage;
	CLASSDEF(Eassembly_component_usage); 
	EidentifierPtr reference_designator; 
};
class Eassembly_component_usage_substitute : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eassembly_component_usage_substitute); 
	ElabelPtr name; 
	EtextPtr description; 
	Eassembly_component_usagePtr base; 
	Eassembly_component_usagePtr substitute; 
};
class Eplacement : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eplacement); 
	Ecartesian_pointPtr location; 
};
class Eaxis1_placement : public IStepNode
{
public:
//// Inherited classes 
	Eplacement _placement;
	CLASSDEF(Eaxis1_placement); 
	EdirectionPtr axis; 
};
class Eaxis2_placement_2d : public IStepNode
{
public:
//// Inherited classes 
	Eplacement _placement;
	CLASSDEF(Eaxis2_placement_2d); 
	EdirectionPtr ref_direction; 
};
class Eaxis2_placement_3d : public IStepNode
{
public:
//// Inherited classes 
	Eplacement _placement;
	CLASSDEF(Eaxis2_placement_3d); 
	EdirectionPtr axis; 
	EdirectionPtr ref_direction; 
};
class Ecurve : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Ecurve); 
};
class Ebounded_curve : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Ebounded_curve); 
};
class Eb_spline_curve : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	CLASSDEF(Eb_spline_curve); 
	EIntegerPtr degree; 
	EListT<Ecartesian_pointPtr> control_points_list; 
	Eb_spline_curve_formPtr curve_form; 
	ELogicalPtr closed_curve; 
	ELogicalPtr self_intersect; 
};
class Eb_spline_curve_with_knots : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	CLASSDEF(Eb_spline_curve_with_knots); 
	EListT<EIntegerPtr> knot_multiplicities; 
	EListT<Eparameter_valuePtr> knots; 
	Eknot_typePtr knot_spec; 
};
class Esurface : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Esurface); 
};
class Ebounded_surface : public IStepNode
{
public:
//// Inherited classes 
	Esurface _surface;
	CLASSDEF(Ebounded_surface); 
};
class Eb_spline_surface : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_surface _bounded_surface;
	CLASSDEF(Eb_spline_surface); 
	EIntegerPtr u_degree; 
	EIntegerPtr v_degree; 
	std::vector< EListT<Ecartesian_pointPtr> > control_points_list; 
	Eb_spline_surface_formPtr surface_form; 
	ELogicalPtr u_closed; 
	ELogicalPtr v_closed; 
	ELogicalPtr self_intersect; 
};
class Eb_spline_surface_with_knots : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	CLASSDEF(Eb_spline_surface_with_knots); 
	EListT<EIntegerPtr> u_multiplicities; 
	EListT<EIntegerPtr> v_multiplicities; 
	EListT<Eparameter_valuePtr> u_knots; 
	EListT<Eparameter_valuePtr> v_knots; 
	Eknot_typePtr knot_spec; 
};
class Ebezier_curve : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	CLASSDEF(Ebezier_curve); 
};
class Ebezier_surface : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	CLASSDEF(Ebezier_surface); 
};
class Ecomposite_curve : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	CLASSDEF(Ecomposite_curve); 
	EListT<Ecomposite_curve_segmentPtr> segments; 
	ELogicalPtr self_intersect; 
};
class Ecomposite_curve_on_surface : public IStepNode
{
public:
//// Inherited classes 
	Ecomposite_curve _composite_curve;
	CLASSDEF(Ecomposite_curve_on_surface); 
};
class Eboundary_curve : public IStepNode
{
public:
//// Inherited classes 
	Ecomposite_curve_on_surface _composite_curve_on_surface;
	CLASSDEF(Eboundary_curve); 
};
class Esolid_model : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Esolid_model); 
};
class Emanifold_solid_brep : public IStepNode
{
public:
//// Inherited classes 
	Esolid_model _solid_model;
	CLASSDEF(Emanifold_solid_brep); 
	Eclosed_shellPtr outer; 
};
class Ebrep_with_voids : public IStepNode
{
public:
//// Inherited classes 
	Emanifold_solid_brep _manifold_solid_brep;
	CLASSDEF(Ebrep_with_voids); 
	EListT<Eoriented_closed_shellPtr> voids; 
};
class Edate : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edate); 
	Eyear_numberPtr year_component; 
};
class Ecalendar_date : public IStepNode
{
public:
//// Inherited classes 
	Edate _date;
	CLASSDEF(Ecalendar_date); 
	Eday_in_month_numberPtr day_component; 
	Emonth_in_year_numberPtr month_component; 
};
class Epoint : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Epoint); 
};
class Ecartesian_point : public IStepNode
{
public:
//// Inherited classes 
	Epoint _point;
	CLASSDEF(Ecartesian_point); 
	EListT<Elength_measurePtr> coordinates; 
};
class Efunctionally_defined_transformation : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Efunctionally_defined_transformation); 
	ElabelPtr name; 
	EtextPtr description; 
};
class Ecartesian_transformation_operator : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	Efunctionally_defined_transformation _functionally_defined_transformation;
	CLASSDEF(Ecartesian_transformation_operator); 
	EdirectionPtr axis1; 
	EdirectionPtr axis2; 
	Ecartesian_pointPtr local_origin; 
	ERealPtr scale; 
};
class Ecartesian_transformation_operator_2d : public IStepNode
{
public:
//// Inherited classes 
	Ecartesian_transformation_operator _cartesian_transformation_operator;
	CLASSDEF(Ecartesian_transformation_operator_2d); 
};
class Ecartesian_transformation_operator_3d : public IStepNode
{
public:
//// Inherited classes 
	Ecartesian_transformation_operator _cartesian_transformation_operator;
	CLASSDEF(Ecartesian_transformation_operator_3d); 
	EdirectionPtr axis3; 
};
class Ecc_design_approval : public IStepNode
{
public:
//// Inherited classes 
	Eapproval_assignment _approval_assignment;
	CLASSDEF(Ecc_design_approval); 
	EListT<Eapproved_itemPtr> items; 
};
class Ecertification_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecertification_assignment); 
	EcertificationPtr assigned_certification; 
};
class Ecc_design_certification : public IStepNode
{
public:
//// Inherited classes 
	Ecertification_assignment _certification_assignment;
	CLASSDEF(Ecc_design_certification); 
	EListT<Ecertified_itemPtr> items; 
};
class Econtract_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Econtract_assignment); 
	EcontractPtr assigned_contract; 
};
class Ecc_design_contract : public IStepNode
{
public:
//// Inherited classes 
	Econtract_assignment _contract_assignment;
	CLASSDEF(Ecc_design_contract); 
	EListT<Econtracted_itemPtr> items; 
};
class Edate_and_time_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edate_and_time_assignment); 
	Edate_and_timePtr assigned_date_and_time; 
	Edate_time_rolePtr role; 
};
class Ecc_design_date_and_time_assignment : public IStepNode
{
public:
//// Inherited classes 
	Edate_and_time_assignment _date_and_time_assignment;
	CLASSDEF(Ecc_design_date_and_time_assignment); 
	EListT<Edate_time_itemPtr> items; 
};
class Eperson_and_organization_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eperson_and_organization_assignment); 
	Eperson_and_organizationPtr assigned_person_and_organization; 
	Eperson_and_organization_rolePtr role; 
};
class Ecc_design_person_and_organization_assignment : public IStepNode
{
public:
//// Inherited classes 
	Eperson_and_organization_assignment _person_and_organization_assignment;
	CLASSDEF(Ecc_design_person_and_organization_assignment); 
	EListT<Eperson_organization_itemPtr> items; 
};
class Esecurity_classification_assignment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Esecurity_classification_assignment); 
	Esecurity_classificationPtr assigned_security_classification; 
};
class Ecc_design_security_classification : public IStepNode
{
public:
//// Inherited classes 
	Esecurity_classification_assignment _security_classification_assignment;
	CLASSDEF(Ecc_design_security_classification); 
	EListT<Eclassified_itemPtr> items; 
};
class Edocument_reference : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edocument_reference); 
	EdocumentPtr assigned_document; 
	ElabelPtr source; 
};
class Ecc_design_specification_reference : public IStepNode
{
public:
//// Inherited classes 
	Edocument_reference _document_reference;
	CLASSDEF(Ecc_design_specification_reference); 
	EListT<Especified_itemPtr> items; 
};
class Ecertification : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecertification); 
	ElabelPtr name; 
	EtextPtr purpose; 
	Ecertification_typePtr kind; 
};
class Ecertification_type : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecertification_type); 
	ElabelPtr description; 
};
class Echange : public IStepNode
{
public:
//// Inherited classes 
	Eaction_assignment _action_assignment;
	CLASSDEF(Echange); 
	EListT<Ework_itemPtr> items; 
};
class Echange_request : public IStepNode
{
public:
//// Inherited classes 
	Eaction_request_assignment _action_request_assignment;
	CLASSDEF(Echange_request); 
	EListT<Echange_request_itemPtr> items; 
};
class Econic : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Econic); 
	Eaxis2_placementPtr position; 
};
class Ecircle : public IStepNode
{
public:
//// Inherited classes 
	Econic _conic;
	CLASSDEF(Ecircle); 
	Epositive_length_measurePtr radius; 
};
class Econnected_face_set : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Econnected_face_set); 
	EListT<EfacePtr> cfs_faces; 
};
class Eclosed_shell : public IStepNode
{
public:
//// Inherited classes 
	Econnected_face_set _connected_face_set;
	CLASSDEF(Eclosed_shell); 
};
class Ecomposite_curve_segment : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecomposite_curve_segment); 
	Etransition_codePtr transition; 
	EBooleanPtr same_sense; 
	EcurvePtr parent_curve; 
};
class Econfiguration_design : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Econfiguration_design); 
	Econfiguration_itemPtr configuration; 
	Eproduct_definition_formationPtr design; 
};
class Eeffectivity : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eeffectivity); 
	EidentifierPtr id; 
};
class Eproduct_definition_effectivity : public IStepNode
{
public:
//// Inherited classes 
	Eeffectivity _effectivity;
	CLASSDEF(Eproduct_definition_effectivity); 
	Eproduct_definition_relationshipPtr usage; 
};
class Econfiguration_effectivity : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition_effectivity _product_definition_effectivity;
	CLASSDEF(Econfiguration_effectivity); 
	Econfiguration_designPtr configuration; 
};
class Econfiguration_item : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Econfiguration_item); 
	EidentifierPtr id; 
	ElabelPtr name; 
	EtextPtr description; 
	Eproduct_conceptPtr item_concept; 
	ElabelPtr purpose; 
};
class Eelementary_surface : public IStepNode
{
public:
//// Inherited classes 
	Esurface _surface;
	CLASSDEF(Eelementary_surface); 
	Eaxis2_placement_3dPtr position; 
};
class Econical_surface : public IStepNode
{
public:
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	CLASSDEF(Econical_surface); 
	Elength_measurePtr radius; 
	Eplane_angle_measurePtr semi_angle; 
};
class Econnected_edge_set : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Econnected_edge_set); 
	EListT<EedgePtr> ces_edges; 
};
class Econtext_dependent_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Econtext_dependent_shape_representation); 
	Eshape_representation_relationshipPtr representation_relation; 
	Eproduct_definition_shapePtr represented_product_relation; 
};
class Econtext_dependent_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Econtext_dependent_unit); 
	ElabelPtr name; 
};
class Econtract : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Econtract); 
	ElabelPtr name; 
	EtextPtr purpose; 
	Econtract_typePtr kind; 
};
class Econtract_type : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Econtract_type); 
	ElabelPtr description; 
};
class Econversion_based_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Econversion_based_unit); 
	ElabelPtr name; 
	Emeasure_with_unitPtr conversion_factor; 
};
class Ecoordinated_universal_time_offset : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecoordinated_universal_time_offset); 
	Ehour_in_dayPtr hour_offset; 
	Eminute_in_hourPtr minute_offset; 
	Eahead_or_behindPtr sense; 
};
class Ecurve_bounded_surface : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_surface _bounded_surface;
	CLASSDEF(Ecurve_bounded_surface); 
	EsurfacePtr basis_surface; 
	EListT<Eboundary_curvePtr> boundaries; 
	EBooleanPtr implicit_outer; 
};
class Ecurve_replica : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Ecurve_replica); 
	EcurvePtr parent_curve; 
	Ecartesian_transformation_operatorPtr transformation; 
};
class Ecylindrical_surface : public IStepNode
{
public:
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	CLASSDEF(Ecylindrical_surface); 
	Epositive_length_measurePtr radius; 
};
class Edate_and_time : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edate_and_time); 
	EdatePtr date_component; 
	Elocal_timePtr time_component; 
};
class Edate_time_role : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edate_time_role); 
	ElabelPtr name; 
};
class Edated_effectivity : public IStepNode
{
public:
//// Inherited classes 
	Eeffectivity _effectivity;
	CLASSDEF(Edated_effectivity); 
	Edate_and_timePtr effectivity_start_date; 
	Edate_and_timePtr effectivity_end_date; 
};
class Edefinitional_representation : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation _representation;
	CLASSDEF(Edefinitional_representation); 
};
class Edegenerate_pcurve : public IStepNode
{
public:
//// Inherited classes 
	Epoint _point;
	CLASSDEF(Edegenerate_pcurve); 
	EsurfacePtr basis_surface; 
	Edefinitional_representationPtr reference_to_curve; 
};
class Eproduct_definition_context : public IStepNode
{
public:
//// Inherited classes 
	Eapplication_context_element _application_context_element;
	CLASSDEF(Eproduct_definition_context); 
	ElabelPtr life_cycle_stage; 
};
class Edesign_context : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition_context _product_definition_context;
	CLASSDEF(Edesign_context); 
};
class Edesign_make_from_relationship : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition_relationship _product_definition_relationship;
	CLASSDEF(Edesign_make_from_relationship); 
};
class Edimensional_exponents : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edimensional_exponents); 
	ERealPtr length_exponent; 
	ERealPtr mass_exponent; 
	ERealPtr time_exponent; 
	ERealPtr electric_current_exponent; 
	ERealPtr thermodynamic_temperature_exponent; 
	ERealPtr amount_of_substance_exponent; 
	ERealPtr luminous_intensity_exponent; 
};
class Eexecuted_action : public IStepNode
{
public:
//// Inherited classes 
	Eaction _action;
	CLASSDEF(Eexecuted_action); 
};
class Edirected_action : public IStepNode
{
public:
//// Inherited classes 
	Eexecuted_action _executed_action;
	CLASSDEF(Edirected_action); 
	Eaction_directivePtr directive; 
};
class Edirection : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Edirection); 
	EListT<ERealPtr> direction_ratios; 
};
class Edocument : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edocument); 
	EidentifierPtr id; 
	ElabelPtr name; 
	EtextPtr description; 
	Edocument_typePtr kind; 
};
class Edocument_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edocument_relationship); 
	ElabelPtr name; 
	EtextPtr description; 
	EdocumentPtr relating_document; 
	EdocumentPtr related_document; 
};
class Edocument_type : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edocument_type); 
	ElabelPtr product_data_type; 
};
class Edocument_usage_constraint : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edocument_usage_constraint); 
	EdocumentPtr source; 
	ElabelPtr subject_element; 
	EtextPtr subject_element_value; 
};
class Edocument_with_class : public IStepNode
{
public:
//// Inherited classes 
	Edocument _document;
	CLASSDEF(Edocument_with_class); 
	EidentifierPtr E__class; 
};
class Eedge : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Eedge); 
	EvertexPtr edge_start; 
	EvertexPtr edge_end; 
};
class Eedge_based_wireframe_model : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eedge_based_wireframe_model); 
	EListT<Econnected_edge_setPtr> ebwm_boundary; 
};
class Eedge_based_wireframe_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Eedge_based_wireframe_shape_representation); 
};
class Eedge_curve : public IStepNode
{
public:
//// Inherited classes 
	Eedge _edge;
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eedge_curve); 
	EcurvePtr edge_geometry; 
	EBooleanPtr same_sense; 
};
class Eloop : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Eloop); 
};
class Epath : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Epath); 
	EListT<Eoriented_edgePtr> edge_list; 
};
class Eedge_loop : public IStepNode
{
public:
//// Inherited classes 
	Eloop _loop;
	Epath _path;
	CLASSDEF(Eedge_loop); 
};
class Eellipse : public IStepNode
{
public:
//// Inherited classes 
	Econic _conic;
	CLASSDEF(Eellipse); 
	Epositive_length_measurePtr semi_axis_1; 
	Epositive_length_measurePtr semi_axis_2; 
};
class Eevaluated_degenerate_pcurve : public IStepNode
{
public:
//// Inherited classes 
	Edegenerate_pcurve _degenerate_pcurve;
	CLASSDEF(Eevaluated_degenerate_pcurve); 
	Ecartesian_pointPtr equivalent_point; 
};
class Eface_bound : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Eface_bound); 
	EloopPtr bound; 
	EBooleanPtr orientation; 
};
class Eface_outer_bound : public IStepNode
{
public:
//// Inherited classes 
	Eface_bound _face_bound;
	CLASSDEF(Eface_outer_bound); 
};
class Efaceted_brep : public IStepNode
{
public:
//// Inherited classes 
	Emanifold_solid_brep _manifold_solid_brep;
	CLASSDEF(Efaceted_brep); 
};
class Efaceted_brep_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Efaceted_brep_shape_representation); 
};
class Egeometric_set : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Egeometric_set); 
	EListT<Egeometric_set_selectPtr> elements; 
};
class Egeometric_curve_set : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_set _geometric_set;
	CLASSDEF(Egeometric_curve_set); 
};
class Erepresentation_context : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erepresentation_context); 
	EidentifierPtr context_identifier; 
	EtextPtr context_type; 
};
class Egeometric_representation_context : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_context _representation_context;
	CLASSDEF(Egeometric_representation_context); 
	Edimension_countPtr coordinate_space_dimension; 
};
class Egeometrically_bounded_surface_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Egeometrically_bounded_surface_shape_representation); 
};
class Egeometrically_bounded_wireframe_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Egeometrically_bounded_wireframe_shape_representation); 
};
class Eglobal_uncertainty_assigned_context : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_context _representation_context;
	CLASSDEF(Eglobal_uncertainty_assigned_context); 
	EListT<Euncertainty_measure_with_unitPtr> uncertainty; 
};
class Eglobal_unit_assigned_context : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_context _representation_context;
	CLASSDEF(Eglobal_unit_assigned_context); 
	EListT<EunitPtr> units; 
};
class Ehyperbola : public IStepNode
{
public:
//// Inherited classes 
	Econic _conic;
	CLASSDEF(Ehyperbola); 
	Epositive_length_measurePtr semi_axis; 
	Epositive_length_measurePtr semi_imag_axis; 
};
class Esurface_curve : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Esurface_curve); 
	EcurvePtr curve_3d; 
	EListT<Epcurve_or_surfacePtr> associated_geometry; 
	Epreferred_surface_curve_representationPtr master_representation; 
};
class Eintersection_curve : public IStepNode
{
public:
//// Inherited classes 
	Esurface_curve _surface_curve;
	CLASSDEF(Eintersection_curve); 
};
class Eitem_defined_transformation : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eitem_defined_transformation); 
	ElabelPtr name; 
	EtextPtr description; 
	Erepresentation_itemPtr transform_item_1; 
	Erepresentation_itemPtr transform_item_2; 
};
class Elength_measure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	Emeasure_with_unit _measure_with_unit;
	CLASSDEF(Elength_measure_with_unit); 
};
class Elength_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Elength_unit); 
};
class Eline : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Eline); 
	Ecartesian_pointPtr pnt; 
	EvectorPtr dir; 
};
class Elocal_time : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Elocal_time); 
	Ehour_in_dayPtr hour_component; 
	Eminute_in_hourPtr minute_component; 
	Esecond_in_minutePtr second_component; 
	Ecoordinated_universal_time_offsetPtr zone; 
};
class Elot_effectivity : public IStepNode
{
public:
//// Inherited classes 
	Eeffectivity _effectivity;
	CLASSDEF(Elot_effectivity); 
	EidentifierPtr effectivity_lot_id; 
	Emeasure_with_unitPtr effectivity_lot_size; 
};
class Emanifold_surface_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Emanifold_surface_shape_representation); 
};
class Emapped_item : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_item _representation_item;
	CLASSDEF(Emapped_item); 
	Erepresentation_mapPtr mapping_source; 
	Erepresentation_itemPtr mapping_target; 
};
class Emass_measure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	Emeasure_with_unit _measure_with_unit;
	CLASSDEF(Emass_measure_with_unit); 
};
class Emass_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Emass_unit); 
};
class Eproduct_context : public IStepNode
{
public:
//// Inherited classes 
	Eapplication_context_element _application_context_element;
	CLASSDEF(Eproduct_context); 
	ElabelPtr discipline_type; 
};
class Emechanical_context : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_context _product_context;
	CLASSDEF(Emechanical_context); 
};
class Enext_assembly_usage_occurrence : public IStepNode
{
public:
//// Inherited classes 
	Eassembly_component_usage _assembly_component_usage;
	CLASSDEF(Enext_assembly_usage_occurrence); 
};
class Eoffset_curve_2d : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Eoffset_curve_2d); 
	EcurvePtr basis_curve; 
	Elength_measurePtr distance; 
	ELogicalPtr self_intersect; 
};
class Eoffset_curve_3d : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Eoffset_curve_3d); 
	EcurvePtr basis_curve; 
	Elength_measurePtr distance; 
	ELogicalPtr self_intersect; 
	EdirectionPtr ref_direction; 
};
class Eoffset_surface : public IStepNode
{
public:
//// Inherited classes 
	Esurface _surface;
	CLASSDEF(Eoffset_surface); 
	EsurfacePtr basis_surface; 
	Elength_measurePtr distance; 
	ELogicalPtr self_intersect; 
};
class Eopen_shell : public IStepNode
{
public:
//// Inherited classes 
	Econnected_face_set _connected_face_set;
	CLASSDEF(Eopen_shell); 
};
class Eordinal_date : public IStepNode
{
public:
//// Inherited classes 
	Edate _date;
	CLASSDEF(Eordinal_date); 
	Eday_in_year_numberPtr day_component; 
};
class Eorganization : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eorganization); 
	EidentifierPtr id; 
	ElabelPtr name; 
	EtextPtr description; 
};
class Eorganization_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eorganization_relationship); 
	ElabelPtr name; 
	EtextPtr description; 
	EorganizationPtr relating_organization; 
	EorganizationPtr related_organization; 
};
class Eorganizational_address : public IStepNode
{
public:
//// Inherited classes 
	Eaddress _address;
	CLASSDEF(Eorganizational_address); 
	EListT<EorganizationPtr> organizations; 
	EtextPtr description; 
};
class Eorganizational_project : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eorganizational_project); 
	ElabelPtr name; 
	EtextPtr description; 
	EListT<EorganizationPtr> responsible_organizations; 
};
class Eoriented_closed_shell : public IStepNode
{
public:
//// Inherited classes 
	Eclosed_shell _closed_shell;
	CLASSDEF(Eoriented_closed_shell); 
	Eclosed_shellPtr closed_shell_element; 
	EBooleanPtr orientation; 
};
class Eoriented_edge : public IStepNode
{
public:
//// Inherited classes 
	Eedge _edge;
	CLASSDEF(Eoriented_edge); 
	EedgePtr edge_element; 
	EBooleanPtr orientation; 
};
class Eoriented_face : public IStepNode
{
public:
//// Inherited classes 
	Eface _face;
	CLASSDEF(Eoriented_face); 
	EfacePtr face_element; 
	EBooleanPtr orientation; 
};
class Eoriented_open_shell : public IStepNode
{
public:
//// Inherited classes 
	Eopen_shell _open_shell;
	CLASSDEF(Eoriented_open_shell); 
	Eopen_shellPtr open_shell_element; 
	EBooleanPtr orientation; 
};
class Eoriented_path : public IStepNode
{
public:
//// Inherited classes 
	Epath _path;
	CLASSDEF(Eoriented_path); 
	EpathPtr path_element; 
	EBooleanPtr orientation; 
};
class Eouter_boundary_curve : public IStepNode
{
public:
//// Inherited classes 
	Eboundary_curve _boundary_curve;
	CLASSDEF(Eouter_boundary_curve); 
};
class Eparabola : public IStepNode
{
public:
//// Inherited classes 
	Econic _conic;
	CLASSDEF(Eparabola); 
	Elength_measurePtr focal_dist; 
};
class Eparametric_representation_context : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_context _representation_context;
	CLASSDEF(Eparametric_representation_context); 
};
class Epcurve : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Epcurve); 
	EsurfacePtr basis_surface; 
	Edefinitional_representationPtr reference_to_curve; 
};
class Eperson : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eperson); 
	EidentifierPtr id; 
	ElabelPtr last_name; 
	ElabelPtr first_name; 
	EListT<ElabelPtr> middle_names; 
	EListT<ElabelPtr> prefix_titles; 
	EListT<ElabelPtr> suffix_titles; 
};
class Eperson_and_organization : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eperson_and_organization); 
	EpersonPtr the_person; 
	EorganizationPtr the_organization; 
};
class Eperson_and_organization_role : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eperson_and_organization_role); 
	ElabelPtr name; 
};
class Epersonal_address : public IStepNode
{
public:
//// Inherited classes 
	Eaddress _address;
	CLASSDEF(Epersonal_address); 
	EListT<EpersonPtr> people; 
	EtextPtr description; 
};
class Eplane : public IStepNode
{
public:
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	CLASSDEF(Eplane); 
};
class Eplane_angle_measure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	Emeasure_with_unit _measure_with_unit;
	CLASSDEF(Eplane_angle_measure_with_unit); 
};
class Eplane_angle_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Eplane_angle_unit); 
};
class Epoint_on_curve : public IStepNode
{
public:
//// Inherited classes 
	Epoint _point;
	CLASSDEF(Epoint_on_curve); 
	EcurvePtr basis_curve; 
	Eparameter_valuePtr point_parameter; 
};
class Epoint_on_surface : public IStepNode
{
public:
//// Inherited classes 
	Epoint _point;
	CLASSDEF(Epoint_on_surface); 
	EsurfacePtr basis_surface; 
	Eparameter_valuePtr point_parameter_u; 
	Eparameter_valuePtr point_parameter_v; 
};
class Epoint_replica : public IStepNode
{
public:
//// Inherited classes 
	Epoint _point;
	CLASSDEF(Epoint_replica); 
	EpointPtr parent_pt; 
	Ecartesian_transformation_operatorPtr transformation; 
};
class Epoly_loop : public IStepNode
{
public:
//// Inherited classes 
	Eloop _loop;
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Epoly_loop); 
	EListT<Ecartesian_pointPtr> polygon; 
};
class Epolyline : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	CLASSDEF(Epolyline); 
	EListT<Ecartesian_pointPtr> points; 
};
class Eproduct : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproduct); 
	EidentifierPtr id; 
	ElabelPtr name; 
	EtextPtr description; 
	EListT<Eproduct_contextPtr> frame_of_reference; 
};
class Eproduct_category : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproduct_category); 
	ElabelPtr name; 
	EtextPtr description; 
};
class Eproduct_category_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproduct_category_relationship); 
	ElabelPtr name; 
	EtextPtr description; 
	Eproduct_categoryPtr category; 
	Eproduct_categoryPtr sub_category; 
};
class Eproduct_concept : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproduct_concept); 
	EidentifierPtr id; 
	ElabelPtr name; 
	EtextPtr description; 
	Eproduct_concept_contextPtr market_context; 
};
class Eproduct_concept_context : public IStepNode
{
public:
//// Inherited classes 
	Eapplication_context_element _application_context_element;
	CLASSDEF(Eproduct_concept_context); 
	ElabelPtr market_segment_type; 
};
class Eproduct_definition : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproduct_definition); 
	EidentifierPtr id; 
	EtextPtr description; 
	Eproduct_definition_formationPtr formation; 
	Eproduct_definition_contextPtr frame_of_reference; 
};
class Eproduct_definition_formation : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproduct_definition_formation); 
	EidentifierPtr id; 
	EtextPtr description; 
	EproductPtr of_product; 
};
class Eproduct_definition_formation_with_specified_source : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition_formation _product_definition_formation;
	CLASSDEF(Eproduct_definition_formation_with_specified_source); 
	EsourcePtr make_or_buy; 
};
class Eproperty_definition : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproperty_definition); 
	ElabelPtr name; 
	EtextPtr description; 
	Echaracterized_definitionPtr definition; 
};
class Eproduct_definition_shape : public IStepNode
{
public:
//// Inherited classes 
	Eproperty_definition _property_definition;
	CLASSDEF(Eproduct_definition_shape); 
};
class Eproduct_definition_with_associated_documents : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition _product_definition;
	CLASSDEF(Eproduct_definition_with_associated_documents); 
	EListT<EdocumentPtr> documentation_ids; 
};
class Eproduct_related_product_category : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_category _product_category;
	CLASSDEF(Eproduct_related_product_category); 
	EListT<EproductPtr> products; 
};
class Epromissory_usage_occurrence : public IStepNode
{
public:
//// Inherited classes 
	Eassembly_component_usage _assembly_component_usage;
	CLASSDEF(Epromissory_usage_occurrence); 
};
class Eproperty_definition_representation : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproperty_definition_representation); 
	Eproperty_definitionPtr definition; 
	ErepresentationPtr used_representation; 
};
class Equantified_assembly_component_usage : public IStepNode
{
public:
//// Inherited classes 
	Eassembly_component_usage _assembly_component_usage;
	CLASSDEF(Equantified_assembly_component_usage); 
	Emeasure_with_unitPtr quantity; 
};
class Equasi_uniform_curve : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	CLASSDEF(Equasi_uniform_curve); 
};
class Equasi_uniform_surface : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	CLASSDEF(Equasi_uniform_surface); 
};
class Erational_b_spline_curve : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	CLASSDEF(Erational_b_spline_curve); 
	EListT<ERealPtr> weights_data; 
};
class Erational_b_spline_surface : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	CLASSDEF(Erational_b_spline_surface); 
	std::vector< EListT<ERealPtr> > weights_data; 
};
class Erectangular_composite_surface : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_surface _bounded_surface;
	CLASSDEF(Erectangular_composite_surface); 
	std::vector< EListT<Esurface_patchPtr> > segments; 
};
class Erectangular_trimmed_surface : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_surface _bounded_surface;
	CLASSDEF(Erectangular_trimmed_surface); 
	EsurfacePtr basis_surface; 
	Eparameter_valuePtr u1; 
	Eparameter_valuePtr u2; 
	Eparameter_valuePtr v1; 
	Eparameter_valuePtr v2; 
	EBooleanPtr usense; 
	EBooleanPtr vsense; 
};
class Ereparametrised_composite_curve_segment : public IStepNode
{
public:
//// Inherited classes 
	Ecomposite_curve_segment _composite_curve_segment;
	CLASSDEF(Ereparametrised_composite_curve_segment); 
	Eparameter_valuePtr param_length; 
};
class Erepresentation_map : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erepresentation_map); 
	Erepresentation_itemPtr mapping_origin; 
	ErepresentationPtr mapped_representation; 
};
class Erepresentation_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erepresentation_relationship); 
	ElabelPtr name; 
	EtextPtr description; 
	ErepresentationPtr rep_1; 
	ErepresentationPtr rep_2; 
};
class Erepresentation_relationship_with_transformation : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_relationship _representation_relationship;
	CLASSDEF(Erepresentation_relationship_with_transformation); 
	EtransformationPtr transformation_operator; 
};
class Eseam_curve : public IStepNode
{
public:
//// Inherited classes 
	Esurface_curve _surface_curve;
	CLASSDEF(Eseam_curve); 
};
class Esecurity_classification : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Esecurity_classification); 
	ElabelPtr name; 
	EtextPtr purpose; 
	Esecurity_classification_levelPtr security_level; 
};
class Esecurity_classification_level : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Esecurity_classification_level); 
	ElabelPtr name; 
};
class Eserial_numbered_effectivity : public IStepNode
{
public:
//// Inherited classes 
	Eeffectivity _effectivity;
	CLASSDEF(Eserial_numbered_effectivity); 
	EidentifierPtr effectivity_start_id; 
	EidentifierPtr effectivity_end_id; 
};
class Eshape_aspect : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eshape_aspect); 
	ElabelPtr name; 
	EtextPtr description; 
	Eproduct_definition_shapePtr of_shape; 
	ELogicalPtr product_definitional; 
};
class Eshape_aspect_relationship : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eshape_aspect_relationship); 
	ElabelPtr name; 
	EtextPtr description; 
	Eshape_aspectPtr relating_shape_aspect; 
	Eshape_aspectPtr related_shape_aspect; 
};
class Eshape_definition_representation : public IStepNode
{
public:
//// Inherited classes 
	Eproperty_definition_representation _property_definition_representation;
	CLASSDEF(Eshape_definition_representation); 
};
class Eshape_representation_relationship : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_relationship _representation_relationship;
	CLASSDEF(Eshape_representation_relationship); 
};
class Eshell_based_surface_model : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eshell_based_surface_model); 
	EListT<EshellPtr> sbsm_boundary; 
};
class Eshell_based_wireframe_model : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eshell_based_wireframe_model); 
	EListT<EshellPtr> sbwm_boundary; 
};
class Eshell_based_wireframe_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Eshell_based_wireframe_shape_representation); 
};
class Esi_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Esi_unit); 
	Esi_prefixPtr prefix; 
	Esi_unit_namePtr name; 
};
class Especified_higher_usage_occurrence : public IStepNode
{
public:
//// Inherited classes 
	Eassembly_component_usage _assembly_component_usage;
	CLASSDEF(Especified_higher_usage_occurrence); 
	Eassembly_component_usagePtr upper_usage; 
	Enext_assembly_usage_occurrencePtr next_usage; 
};
class Esolid_angle_measure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	Emeasure_with_unit _measure_with_unit;
	CLASSDEF(Esolid_angle_measure_with_unit); 
};
class Esolid_angle_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Esolid_angle_unit); 
};
class Espherical_surface : public IStepNode
{
public:
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	CLASSDEF(Espherical_surface); 
	Epositive_length_measurePtr radius; 
};
class Estart_request : public IStepNode
{
public:
//// Inherited classes 
	Eaction_request_assignment _action_request_assignment;
	CLASSDEF(Estart_request); 
	EListT<Estart_request_itemPtr> items; 
};
class Estart_work : public IStepNode
{
public:
//// Inherited classes 
	Eaction_assignment _action_assignment;
	CLASSDEF(Estart_work); 
	EListT<Ework_itemPtr> items; 
};
class Esupplied_part_relationship : public IStepNode
{
public:
//// Inherited classes 
	Eproduct_definition_relationship _product_definition_relationship;
	CLASSDEF(Esupplied_part_relationship); 
};
class Eswept_surface : public IStepNode
{
public:
//// Inherited classes 
	Esurface _surface;
	CLASSDEF(Eswept_surface); 
	EcurvePtr swept_curve; 
};
class Esurface_of_linear_extrusion : public IStepNode
{
public:
//// Inherited classes 
	Eswept_surface _swept_surface;
	CLASSDEF(Esurface_of_linear_extrusion); 
	EvectorPtr extrusion_axis; 
};
class Esurface_of_revolution : public IStepNode
{
public:
//// Inherited classes 
	Eswept_surface _swept_surface;
	CLASSDEF(Esurface_of_revolution); 
	Eaxis1_placementPtr axis_position; 
};
class Esurface_patch : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Esurface_patch); 
	Ebounded_surfacePtr parent_surface; 
	Etransition_codePtr u_transition; 
	Etransition_codePtr v_transition; 
	EBooleanPtr u_sense; 
	EBooleanPtr v_sense; 
};
class Esurface_replica : public IStepNode
{
public:
//// Inherited classes 
	Esurface _surface;
	CLASSDEF(Esurface_replica); 
	EsurfacePtr parent_surface; 
	Ecartesian_transformation_operator_3dPtr transformation; 
};
class Etoroidal_surface : public IStepNode
{
public:
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	CLASSDEF(Etoroidal_surface); 
	Epositive_length_measurePtr major_radius; 
	Epositive_length_measurePtr minor_radius; 
};
class Etrimmed_curve : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	CLASSDEF(Etrimmed_curve); 
	EcurvePtr basis_curve; 
	EListT<Etrimming_selectPtr> trim_1; 
	EListT<Etrimming_selectPtr> trim_2; 
	EBooleanPtr sense_agreement; 
	Etrimming_preferencePtr master_representation; 
};
class Euncertainty_measure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	Emeasure_with_unit _measure_with_unit;
	CLASSDEF(Euncertainty_measure_with_unit); 
	ElabelPtr name; 
	EtextPtr description; 
};
class Euniform_curve : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	CLASSDEF(Euniform_curve); 
};
class Euniform_surface : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	CLASSDEF(Euniform_surface); 
};
class Evector : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Evector); 
	EdirectionPtr orientation; 
	Elength_measurePtr magnitude; 
};
class Eversioned_action_request : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eversioned_action_request); 
	EidentifierPtr id; 
	ElabelPtr version; 
	EtextPtr purpose; 
	EtextPtr description; 
};
class Evertex : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Evertex); 
};
class Evertex_loop : public IStepNode
{
public:
//// Inherited classes 
	Eloop _loop;
	CLASSDEF(Evertex_loop); 
	EvertexPtr loop_vertex; 
};
class Evertex_point : public IStepNode
{
public:
//// Inherited classes 
	Evertex _vertex;
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Evertex_point); 
	EpointPtr vertex_geometry; 
};
class Evertex_shell : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Evertex_shell); 
	Evertex_loopPtr vertex_shell_extent; 
};
class Evolume_measure_with_unit : public IStepNode
{
public:
//// Inherited classes 
	Emeasure_with_unit _measure_with_unit;
	CLASSDEF(Evolume_measure_with_unit); 
};
class Evolume_unit : public IStepNode
{
public:
//// Inherited classes 
	Enamed_unit _named_unit;
	CLASSDEF(Evolume_unit); 
};
class Eweek_of_year_and_day_date : public IStepNode
{
public:
//// Inherited classes 
	Edate _date;
	CLASSDEF(Eweek_of_year_and_day_date); 
	Eweek_in_year_numberPtr week_component; 
	Eday_in_week_numberPtr day_component; 
};
class Ewire_shell : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Ewire_shell); 
	EListT<EloopPtr> wire_shell_extent; 
};
} /* End namespace Express*/
