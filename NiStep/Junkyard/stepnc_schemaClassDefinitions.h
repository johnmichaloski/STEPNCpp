//
// stepnc_schemaClassDefinitions.h
//
#pragma once

#include "ExpressUtils.h"
#include "stepnc_schemaSchemaDeclarations.h"

namespace Express{
// FIXME: Add ClassGenerators::gClassGenerators.AddGenerator(&Createstepnc_schemaClass);
extern IStepNodePtr Createstepnc_schemaClass(CString classname, CString name) ;
extern CStringVector GetAllstepnc_schemaEntities();
class Eday_in_month_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_month_number); 
};
class Emonth_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Emonth_in_year_number); 
};
class Eday_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_year_number); 
};
class Eweek_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eweek_in_year_number); 
};
class Eday_in_week_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_week_number); 
};
class Ehour_in_day : public EInteger /*typedef*/
{
public:
	CLASSDEF(Ehour_in_day); 
};
class Eminute_in_hour : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eminute_in_hour); 
};
class Esecond_in_minute : public EReal /*typedef*/
{
public:
	CLASSDEF(Esecond_in_minute); 
};
class Eahead_or_behind : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Eahead_or_behind); 
			enum Eahead_or_behindEnum
	{
	ahead=0,
	exact,
	behind} ;
	void SetSelection(Eahead_or_behindEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static TCHAR * szEnums[3]={
_T("ahead"),
_T("exact"),
_T("behind")};
	if(e>=nEnums) return _T("$_T("); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eyear_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eyear_number); 
};
class Eidentifier : public EString /*typedef*/
{
public:
	CLASSDEF(Eidentifier); 
};
class Elabel : public EString /*typedef*/
{
public:
	CLASSDEF(Elabel); 
};
class Etext : public EString /*typedef*/
{
public:
	CLASSDEF(Etext); 
};
class Elength_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Elength_measure); 
};
class Eparameter_value : public EReal /*typedef*/
{
public:
	CLASSDEF(Eparameter_value); 
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
class Eratio_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Eratio_measure); 
};
class Epositive_ratio_measure : public Eratio_measure /*typedef*/
{
public:
	CLASSDEF(Epositive_ratio_measure); 
};
class Etime_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Etime_measure); 
};
class Etrimming_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Etrimming_select); 
	Ecartesian_pointPtr _Ecartesian_point;
	Eparameter_valuePtr _Eparameter_value;
};
class Etrimming_preference : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Etrimming_preference); 
			enum Etrimming_preferenceEnum
	{
	cartesian=0,
	parameter,
	unspecified} ;
	void SetSelection(Etrimming_preferenceEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static TCHAR * szEnums[3]={
_T("cartesian"),
_T("parameter"),
_T("unspecified")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etransition_code : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Etransition_code); 
			enum Etransition_codeEnum
	{
	discontinuous=0,
	continuous,
	cont_same_gradient,
	cont_same_gradient_same_curvature} ;
	void SetSelection(Etransition_codeEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static TCHAR * szEnums[4]={
_T("discontinuous"),
_T("continuous"),
_T("cont_same_gradient"),
_T("cont_same_gradient_same_curvature")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eb_spline_curve_form : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Eb_spline_curve_form); 
			enum Eb_spline_curve_formEnum
	{
	polyline_form=0,
	circular_arc,
	elliptic_arc,
	parabolic_arc,
	hyperbolic_arc,
	unspecified} ;
	void SetSelection(Eb_spline_curve_formEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 6;
		static TCHAR * szEnums[6]={
_T("polyline_form"),
_T("circular_arc"),
_T("elliptic_arc"),
_T("parabolic_arc"),
_T("hyperbolic_arc"),
_T("unspecified")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
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
	plane_surf=0,
	cylindrical_surf,
	conical_surf,
	spherical_surf,
	toroidal_surf,
	surf_of_revolution,
	ruled_surf,
	generalised_cone,
	quadric_surf,
	surf_of_linear_extrusion,
	unspecified} ;
	void SetSelection(Eb_spline_surface_formEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 11;
		static TCHAR * szEnums[11]={
_T("plane_surf"),
_T("cylindrical_surf"),
_T("conical_surf"),
_T("spherical_surf"),
_T("toroidal_surf"),
_T("surf_of_revolution"),
_T("ruled_surf"),
_T("generalised_cone"),
_T("quadric_surf"),
_T("surf_of_linear_extrusion"),
_T("unspecified")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 11;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Edimension_count : public EInteger /*typedef*/
{
public:
	CLASSDEF(Edimension_count); 
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
	void SetSelection(Eknot_typeEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static TCHAR * szEnums[4]={
_T("uniform_knots"),
_T("quasi_uniform_knots"),
_T("piecewise_bezier_knots"),
_T("unspecified")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Epcurve_or_surface : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Epcurve_or_surface); 
	EpcurvePtr _Epcurve;
	EsurfacePtr _Esurface;
};
class Evector_or_direction : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Evector_or_direction); 
	EvectorPtr _Evector;
	EdirectionPtr _Edirection;
};
class Etolerance_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Etolerance_select); 
	Eplus_minus_valuePtr _Eplus_minus_value;
	Elimits_and_fitsPtr _Elimits_and_fits;
};
class Efitting_type : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Efitting_type); 
			enum Efitting_typeEnum
	{
	shaft=0,
	hole} ;
	void SetSelection(Efitting_typeEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static TCHAR * szEnums[2]={
_T("shaft"),
_T("hole")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Espeed_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Espeed_measure); 
};
class Erot_speed_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Erot_speed_measure); 
};
class Epressure_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Epressure_measure); 
};
class Erot_direction : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Erot_direction); 
			enum Erot_directionEnum
	{
	cw=0,
	ccw} ;
	void SetSelection(Erot_directionEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static TCHAR * szEnums[2]={
_T("cw"),
_T("ccw")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eshape_tolerance : public Elength_measure /*typedef*/
{
public:
	CLASSDEF(Eshape_tolerance); 
};
class Ebounding_geometry_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ebounding_geometry_select); 
	EblockPtr _Eblock;
	Eright_circular_cylinderPtr _Eright_circular_cylinder;
	Eadvanced_brep_shape_representationPtr _Eadvanced_brep_shape_representation;
};
class Eprofile_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Eprofile_select); 
	Ethrough_profile_floorPtr _Ethrough_profile_floor;
	Eprofile_floorPtr _Eprofile_floor;
};
class Etaper_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Etaper_select); 
	Ediameter_taperPtr _Ediameter_taper;
	Eangle_taperPtr _Eangle_taper;
};
class Ecompound_feature_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ecompound_feature_select); 
	Emachining_featurePtr _Emachining_feature;
	Etransition_featurePtr _Etransition_feature;
};
class Ebottom_or_side : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Ebottom_or_side); 
			enum Ebottom_or_sideEnum
	{
	bottom=0,
	side,
	bottom_and_side} ;
	void SetSelection(Ebottom_or_sideEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static TCHAR * szEnums[3]={
_T("bottom"),
_T("side"),
_T("bottom_and_side")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Erestricted_area_select : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Erestricted_area_select); 
	Ebounded_surfacePtr _Ebounded_surface;
	Ebounding_geometry_selectPtr _Ebounding_geometry_select;
};
class Ervalue : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ervalue); 
	Enc_constantPtr _Enc_constant;
	Enc_variablePtr _Enc_variable;
};
class Etool_reference_point : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Etool_reference_point); 
			enum Etool_reference_pointEnum
	{
	tcp=0,
	ccp} ;
	void SetSelection(Etool_reference_pointEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static TCHAR * szEnums[2]={
_T("tcp"),
_T("ccp")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etoolpath_type : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Etoolpath_type); 
			enum Etoolpath_typeEnum
	{
	approach=0,
	lift,
	connect,
	non_contact,
	contact,
	trajectory_path} ;
	void SetSelection(Etoolpath_typeEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 6;
		static TCHAR * szEnums[6]={
_T("approach"),
_T("lift"),
_T("connect"),
_T("non_contact"),
_T("contact"),
_T("trajectory_path")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 6;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etoolpath_speedprofile : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Etoolpath_speedprofile); 
	Etoolpath_speedPtr _Etoolpath_speed;
	Epositive_ratio_measurePtr _Epositive_ratio_measure;
	Espeed_namePtr _Espeed_name;
};
class Espeed_name : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Espeed_name); 
			enum Espeed_nameEnum
	{
	RAPID=0} ;
	void SetSelection(Espeed_nameEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 1;
		static TCHAR * szEnums[1]={
_T("RAPID")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 1;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Ecurve_with_surface_normal : /*select*/ 
	public ESelection
{
public:
	CLASSDEF(Ecurve_with_surface_normal); 
	Ebounded_pcurvePtr _Ebounded_pcurve;
	Ecurve_with_normal_vectorPtr _Ecurve_with_normal_vector;
};
class Econtact_type : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Econtact_type); 
			enum Econtact_typeEnum
	{
	side=0,
	front} ;
	void SetSelection(Econtact_typeEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static TCHAR * szEnums[2]={
_T("side"),
_T("front")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Ehand : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Ehand); 
			enum EhandEnum
	{
	left=0,
	right,
	neutral} ;
	void SetSelection(EhandEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static TCHAR * szEnums[3]={
_T("left"),
_T("right"),
_T("neutral")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Epathmode_type : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Epathmode_type); 
			enum Epathmode_typeEnum
	{
	forward=0,
	zigzag} ;
	void SetSelection(Epathmode_typeEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static TCHAR * szEnums[2]={
_T("forward"),
_T("zigzag")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Ecutmode_type : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Ecutmode_type); 
			enum Ecutmode_typeEnum
	{
	climb=0,
	conventional} ;
	void SetSelection(Ecutmode_typeEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static TCHAR * szEnums[2]={
_T("climb"),
_T("conventional")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eleft_or_right : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Eleft_or_right); 
			enum Eleft_or_rightEnum
	{
	left=0,
	right} ;
	void SetSelection(Eleft_or_rightEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static TCHAR * szEnums[2]={
_T("left"),
_T("right")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Estroke_connection_strategy : /*enumeration*/ 
	public EEnum
{
public:
			CLASSDEF(Estroke_connection_strategy); 
			enum Estroke_connection_strategyEnum
	{
	straghtline=0,
	lift_shift_plunge,
	degouge,
	loop_back} ;
	void SetSelection(Estroke_connection_strategyEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static TCHAR * szEnums[4]={
_T("straghtline"),
_T("lift_shift_plunge"),
_T("degouge"),
_T("loop_back")};
	if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eapproval : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval); 
	Eapproval_statusPtr status; 
	ElabelPtr level; 
};
class Eapproval_status : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproval_status); 
	ElabelPtr name; 
};
class Edate_and_time : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edate_and_time); 
	EdatePtr date_component; 
	Elocal_timePtr time_component; 
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
class Eordinal_date : public IStepNode
{
public:
//// Inherited classes 
	Edate _date;
	CLASSDEF(Eordinal_date); 
	Eday_in_year_numberPtr day_component; 
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
class Ecoordinated_universal_time_offset : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecoordinated_universal_time_offset); 
	EIntegerPtr hour_offset; 
	EIntegerPtr minute_offset; 
	Eahead_or_behindPtr sense; 
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
class Erepresentation_item : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erepresentation_item); 
	ElabelPtr name; 
};
class Egeometric_representation_item : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_item _representation_item;
	CLASSDEF(Egeometric_representation_item); 
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
class Ecomposite_curve : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	CLASSDEF(Ecomposite_curve); 
	EListT<Ecomposite_curve_segmentPtr> segments; 
	ELogicalPtr self_intersect; 
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
class Eaxis2_placement_3d : public IStepNode
{
public:
//// Inherited classes 
	Eplacement _placement;
	CLASSDEF(Eaxis2_placement_3d); 
	EdirectionPtr axis; 
	EdirectionPtr ref_direction; 
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
class Ebezier_curve : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	CLASSDEF(Ebezier_curve); 
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
	EStepArray control_points_list; 
	Eb_spline_surface_formPtr surface_form; 
	ELogicalPtr u_closed; 
	ELogicalPtr v_closed; 
	ELogicalPtr self_intersect; 
};
class Ebezier_surface : public IStepNode
{
public:
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	CLASSDEF(Ebezier_surface); 
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
class Ebounded_pcurve : public IStepNode
{
public:
//// Inherited classes 
	Epcurve _pcurve;
	Ebounded_curve _bounded_curve;
	CLASSDEF(Ebounded_pcurve); 
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
class Econic : public IStepNode
{
public:
//// Inherited classes 
	Ecurve _curve;
	CLASSDEF(Econic); 
	Eaxis2_placement_3dPtr position; 
};
class Ecircle : public IStepNode
{
public:
//// Inherited classes 
	Econic _conic;
	CLASSDEF(Ecircle); 
	Epositive_length_measurePtr radius; 
};
class Edirection : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Edirection); 
	EListT<ERealPtr> direction_ratios; 
};
class Eelementary_surface : public IStepNode
{
public:
//// Inherited classes 
	Esurface _surface;
	CLASSDEF(Eelementary_surface); 
	Eaxis2_placement_3dPtr position; 
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
class Ehyperbola : public IStepNode
{
public:
//// Inherited classes 
	Econic _conic;
	CLASSDEF(Ehyperbola); 
	Epositive_length_measurePtr semi_axis; 
	Epositive_length_measurePtr semi_imag_axis; 
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
class Eparabola : public IStepNode
{
public:
//// Inherited classes 
	Econic _conic;
	CLASSDEF(Eparabola); 
	Elength_measurePtr focal_dist; 
};
class Eplane : public IStepNode
{
public:
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	CLASSDEF(Eplane); 
};
class Epolyline : public IStepNode
{
public:
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	CLASSDEF(Epolyline); 
	EListT<Ecartesian_pointPtr> points; 
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
	EStepArray weights_data; 
};
class Espherical_surface : public IStepNode
{
public:
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	CLASSDEF(Espherical_surface); 
	Epositive_length_measurePtr radius; 
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
class Etopological_representation_item : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation_item _representation_item;
	CLASSDEF(Etopological_representation_item); 
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
class Eedge : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Eedge); 
	EvertexPtr edge_start; 
	EvertexPtr edge_end; 
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
class Eface : public IStepNode
{
public:
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	CLASSDEF(Eface); 
	EListT<Eface_boundPtr> bounds; 
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
class Eopen_shell : public IStepNode
{
public:
//// Inherited classes 
	Econnected_face_set _connected_face_set;
	CLASSDEF(Eopen_shell); 
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
class Eblock : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eblock); 
	Eaxis2_placement_3dPtr position; 
	Epositive_length_measurePtr x; 
	Epositive_length_measurePtr y; 
	Epositive_length_measurePtr z; 
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
class Eright_circular_cylinder : public IStepNode
{
public:
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	CLASSDEF(Eright_circular_cylinder); 
	Eaxis1_placementPtr position; 
	Epositive_length_measurePtr height; 
	Epositive_length_measurePtr radius; 
};
class Edefinitional_representation : public IStepNode
{
public:
//// Inherited classes 
	Erepresentation _representation;
	CLASSDEF(Edefinitional_representation); 
};
class Eadvanced_face : public IStepNode
{
public:
//// Inherited classes 
	Eface_surface _face_surface;
	CLASSDEF(Eadvanced_face); 
};
class Eadvanced_brep_shape_representation : public IStepNode
{
public:
//// Inherited classes 
	Eshape_representation _shape_representation;
	CLASSDEF(Eadvanced_brep_shape_representation); 
};
class Etoleranced_length_measure : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etoleranced_length_measure); 
	Epositive_length_measurePtr theoretical_size; 
	Etolerance_selectPtr implicit_tolerance; 
};
class Eplus_minus_value : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eplus_minus_value); 
	Epositive_length_measurePtr upper_limit; 
	Epositive_length_measurePtr lower_limit; 
	EIntegerPtr significant_digits; 
};
class Elimits_and_fits : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Elimits_and_fits); 
	Elength_measurePtr deviation; 
	Elength_measurePtr grade; 
	Efitting_typePtr its_fitting_type; 
};
class Eproject : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproject); 
	EidentifierPtr its_id; 
	EworkplanPtr main_workplan; 
	EListT<EworkpiecePtr> its_workpieces; 
	Eperson_and_addressPtr its_owner; 
	Edate_and_timePtr its_release; 
	EapprovalPtr its_status; 
};
class Eperson_and_address : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eperson_and_address); 
	EpersonPtr its_person; 
	EaddressPtr its_address; 
};
class Eworkpiece : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eworkpiece); 
	EidentifierPtr its_id; 
	EmaterialPtr its_material; 
	Eshape_tolerancePtr global_tolerance; 
	EworkpiecePtr its_rawpiece; 
	Eadvanced_brep_shape_representationPtr its_geometry; 
	Ebounding_geometry_selectPtr its_bounding_geometry; 
	EListT<Ecartesian_pointPtr> clamping_positions; 
};
class Ematerial : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ematerial); 
	ElabelPtr standard_identifier; 
	ElabelPtr material_identifier; 
	EListT<Eproperty_parameterPtr> material_property; 
};
class Eproperty_parameter : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eproperty_parameter); 
	ElabelPtr parameter_name; 
};
class Edescriptive_parameter : public IStepNode
{
public:
//// Inherited classes 
	Eproperty_parameter _property_parameter;
	CLASSDEF(Edescriptive_parameter); 
	EtextPtr descriptive_string; 
};
class Enumeric_parameter : public IStepNode
{
public:
//// Inherited classes 
	Eproperty_parameter _property_parameter;
	CLASSDEF(Enumeric_parameter); 
	Eparameter_valuePtr its_parameter_value; 
	ElabelPtr its_parameter_unit; 
};
class Emanufacturing_feature : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Emanufacturing_feature); 
	EidentifierPtr its_id; 
	EworkpiecePtr its_workpiece; 
	EListT<Emachining_operationPtr> its_operations; 
};
class Eregion : public IStepNode
{
public:
//// Inherited classes 
	Emanufacturing_feature _manufacturing_feature;
	CLASSDEF(Eregion); 
	Eaxis2_placement_3dPtr feature_placement; 
};
class Eregion_projection : public IStepNode
{
public:
//// Inherited classes 
	Eregion _region;
	CLASSDEF(Eregion_projection); 
	Ebounded_curvePtr proj_curve; 
	EdirectionPtr proj_dir; 
	Etoleranced_length_measurePtr depth; 
};
class Eregion_surface_list : public IStepNode
{
public:
//// Inherited classes 
	Eregion _region;
	CLASSDEF(Eregion_surface_list); 
	EListT<Ebounded_surfacePtr> surface_list; 
};
class Etopological_region : public IStepNode
{
public:
//// Inherited classes 
	Eregion _region;
	Eopen_shell _open_shell;
	CLASSDEF(Etopological_region); 
};
class Etwo5d_manufacturing_feature : public IStepNode
{
public:
//// Inherited classes 
	Emanufacturing_feature _manufacturing_feature;
	CLASSDEF(Etwo5d_manufacturing_feature); 
	Eaxis2_placement_3dPtr feature_placement; 
};
class Emachining_feature : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_manufacturing_feature _two5d_manufacturing_feature;
	CLASSDEF(Emachining_feature); 
	Eelementary_surfacePtr depth; 
};
class Eplanar_face : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Eplanar_face); 
	Elinear_pathPtr course_of_travel; 
	Elinear_profilePtr removal_boundary; 
	Eclosed_profilePtr face_boundary; 
	EListT<EbossPtr> its_boss; 
};
class Epocket : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Epocket); 
	EListT<EbossPtr> its_boss; 
	Eplane_angle_measurePtr slope; 
	Epocket_bottom_conditionPtr bottom_condition; 
	Etoleranced_length_measurePtr planar_radius; 
	Etoleranced_length_measurePtr orthogonal_radius; 
};
class Eclosed_pocket : public IStepNode
{
public:
//// Inherited classes 
	Epocket _pocket;
	CLASSDEF(Eclosed_pocket); 
	Eclosed_profilePtr feature_boundary; 
};
class Eopen_pocket : public IStepNode
{
public:
//// Inherited classes 
	Epocket _pocket;
	CLASSDEF(Eopen_pocket); 
	Eopen_profilePtr open_boundary; 
	Eopen_profilePtr wall_boundary; 
};
class Epocket_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Epocket_bottom_condition); 
};
class Ethrough_pocket_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
	CLASSDEF(Ethrough_pocket_bottom_condition); 
};
class Eplanar_pocket_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
	CLASSDEF(Eplanar_pocket_bottom_condition); 
};
class Eradiused_pocket_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
	CLASSDEF(Eradiused_pocket_bottom_condition); 
	Ecartesian_pointPtr floor_radius_center; 
	Etoleranced_length_measurePtr floor_radius; 
};
class Egeneral_pocket_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
	CLASSDEF(Egeneral_pocket_bottom_condition); 
	EregionPtr shape; 
};
class Eslot : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Eslot); 
	Etravel_pathPtr course_of_travel; 
	Eopen_profilePtr swept_shape; 
	EListT<Eslot_end_typePtr> end_conditions; 
};
class Eslot_end_type : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eslot_end_type); 
};
class Ewoodruff_slot_end_type : public IStepNode
{
public:
//// Inherited classes 
	Eslot_end_type _slot_end_type;
	CLASSDEF(Ewoodruff_slot_end_type); 
	Etoleranced_length_measurePtr radius; 
};
class Eradiused_slot_end_type : public IStepNode
{
public:
//// Inherited classes 
	Eslot_end_type _slot_end_type;
	CLASSDEF(Eradiused_slot_end_type); 
};
class Eflat_slot_end_type : public IStepNode
{
public:
//// Inherited classes 
	Eslot_end_type _slot_end_type;
	CLASSDEF(Eflat_slot_end_type); 
	Etoleranced_length_measurePtr corner_radius1; 
	Etoleranced_length_measurePtr corner_radius2; 
};
class Eloop_slot_end_type : public IStepNode
{
public:
//// Inherited classes 
	Eslot_end_type _slot_end_type;
	CLASSDEF(Eloop_slot_end_type); 
};
class Eopen_slot_end_type : public IStepNode
{
public:
//// Inherited classes 
	Eslot_end_type _slot_end_type;
	CLASSDEF(Eopen_slot_end_type); 
};
class Estep : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Estep); 
	Elinear_pathPtr open_boundary; 
	Evee_profilePtr wall_boundary; 
	EListT<EbossPtr> its_boss; 
};
class Eprofile_feature : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Eprofile_feature); 
	Elinear_pathPtr profile_swept_shape; 
};
class Egeneral_outside_profile : public IStepNode
{
public:
//// Inherited classes 
	Eprofile_feature _profile_feature;
	CLASSDEF(Egeneral_outside_profile); 
	EprofilePtr feature_boundary; 
};
class Eshape_profile : public IStepNode
{
public:
//// Inherited classes 
	Eprofile_feature _profile_feature;
	CLASSDEF(Eshape_profile); 
	Eprofile_selectPtr floor_condition; 
	EdirectionPtr removal_direction; 
};
class Ethrough_profile_floor : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ethrough_profile_floor); 
};
class Eprofile_floor : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eprofile_floor); 
	Enumeric_parameterPtr floor_radius; 
	EBooleanPtr start_or_end; 
};
class Egeneral_profile_floor : public IStepNode
{
public:
//// Inherited classes 
	Eprofile_floor _profile_floor;
	CLASSDEF(Egeneral_profile_floor); 
	EfacePtr floor; 
};
class Eplanar_profile_floor : public IStepNode
{
public:
//// Inherited classes 
	Eprofile_floor _profile_floor;
	CLASSDEF(Eplanar_profile_floor); 
	EplanePtr floor; 
};
class Egeneral_shape_profile : public IStepNode
{
public:
//// Inherited classes 
	Eshape_profile _shape_profile;
	CLASSDEF(Egeneral_shape_profile); 
	EprofilePtr profile_boundary; 
};
class Epartial_circular_shape_profile : public IStepNode
{
public:
//// Inherited classes 
	Eshape_profile _shape_profile;
	CLASSDEF(Epartial_circular_shape_profile); 
	Epartial_circular_profilePtr open_boundary; 
};
class Ecircular_closed_shape_profile : public IStepNode
{
public:
//// Inherited classes 
	Eshape_profile _shape_profile;
	CLASSDEF(Ecircular_closed_shape_profile); 
	Ecircular_closed_profilePtr closed_boundary; 
};
class Erectangular_open_shape_profile : public IStepNode
{
public:
//// Inherited classes 
	Eshape_profile _shape_profile;
	CLASSDEF(Erectangular_open_shape_profile); 
	Esquare_u_profilePtr open_boundary; 
};
class Erectangular_closed_shape_profile : public IStepNode
{
public:
//// Inherited classes 
	Eshape_profile _shape_profile;
	CLASSDEF(Erectangular_closed_shape_profile); 
	Erectangular_closed_profilePtr closed_boundary; 
};
class Eround_hole : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Eround_hole); 
	Etoleranced_length_measurePtr diameter; 
	Etaper_selectPtr change_in_diameter; 
	Ehole_bottom_conditionPtr bottom_condition; 
};
class Ediameter_taper : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ediameter_taper); 
	Etoleranced_length_measurePtr final_diameter; 
};
class Eangle_taper : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eangle_taper); 
	Eplane_angle_measurePtr angle; 
};
class Ehole_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ehole_bottom_condition); 
};
class Ethrough_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	Ehole_bottom_condition _hole_bottom_condition;
	CLASSDEF(Ethrough_bottom_condition); 
};
class Eblind_bottom_condition : public IStepNode
{
public:
//// Inherited classes 
	Ehole_bottom_condition _hole_bottom_condition;
	CLASSDEF(Eblind_bottom_condition); 
};
class Eflat_hole_bottom : public IStepNode
{
public:
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
	CLASSDEF(Eflat_hole_bottom); 
};
class Eflat_with_radius_hole_bottom : public IStepNode
{
public:
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
	CLASSDEF(Eflat_with_radius_hole_bottom); 
	Etoleranced_length_measurePtr corner_radius; 
};
class Espherical_hole_bottom : public IStepNode
{
public:
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
	CLASSDEF(Espherical_hole_bottom); 
	Etoleranced_length_measurePtr radius; 
};
class Econical_hole_bottom : public IStepNode
{
public:
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
	CLASSDEF(Econical_hole_bottom); 
	Eplane_angle_measurePtr tip_angle; 
	Etoleranced_length_measurePtr tip_radius; 
};
class Etoolpath_feature : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Etoolpath_feature); 
};
class Eboss : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Eboss); 
	Eclosed_profilePtr its_boundary; 
	Eplane_angle_measurePtr slope; 
};
class Espherical_cap : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Espherical_cap); 
	Enumeric_parameterPtr internal_angle; 
	Enumeric_parameterPtr radius; 
};
class Erounded_end : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Erounded_end); 
	Elinear_pathPtr course_of_travel; 
	Epartial_circular_profilePtr partial_circular_boundary; 
};
class Ecompound_feature : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_manufacturing_feature _two5d_manufacturing_feature;
	CLASSDEF(Ecompound_feature); 
	EListT<Ecompound_feature_selectPtr> elements; 
};
class Ecounterbore_hole : public IStepNode
{
public:
//// Inherited classes 
	Ecompound_feature _compound_feature;
	CLASSDEF(Ecounterbore_hole); 
};
class Ecountersunk_hole : public IStepNode
{
public:
//// Inherited classes 
	Ecompound_feature _compound_feature;
	CLASSDEF(Ecountersunk_hole); 
};
class Ereplicate_feature : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_manufacturing_feature _two5d_manufacturing_feature;
	CLASSDEF(Ereplicate_feature); 
	Etwo5d_manufacturing_featurePtr replicate_base_feature; 
};
class Ecircular_pattern : public IStepNode
{
public:
//// Inherited classes 
	Ereplicate_feature _replicate_feature;
	CLASSDEF(Ecircular_pattern); 
	Eplane_angle_measurePtr angle_increment; 
	EIntegerPtr number_of_feature; 
	EListT<Ecircular_offsetPtr> relocated_base_feature; 
	EListT<Ecircular_omitPtr> missing_base_feature; 
	Etoleranced_length_measurePtr base_feature_diameter; 
	Eplane_angle_measurePtr base_feature_rotation; 
};
class Ecircular_offset : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecircular_offset); 
	Eplane_angle_measurePtr angular_offset; 
	EIntegerPtr index; 
};
class Ecircular_omit : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecircular_omit); 
	EIntegerPtr index; 
};
class Erectangular_pattern : public IStepNode
{
public:
//// Inherited classes 
	Ereplicate_feature _replicate_feature;
	CLASSDEF(Erectangular_pattern); 
	Etoleranced_length_measurePtr spacing; 
	EdirectionPtr its_direction; 
	EIntegerPtr number_of_rows; 
	EIntegerPtr number_of_columns; 
	Etoleranced_length_measurePtr row_spacing; 
	EdirectionPtr row_layout_direction; 
	EListT<Erectangular_offsetPtr> relocated_base_feature; 
	EListT<Erectangular_omitPtr> missing_base_feature; 
};
class Erectangular_offset : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erectangular_offset); 
	EdirectionPtr offset_direction; 
	Elength_measurePtr offset_distance; 
	EIntegerPtr row_index; 
	EIntegerPtr column_index; 
};
class Erectangular_omit : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Erectangular_omit); 
	EIntegerPtr row_index; 
	EIntegerPtr column_index; 
};
class Egeneral_pattern : public IStepNode
{
public:
//// Inherited classes 
	Ereplicate_feature _replicate_feature;
	CLASSDEF(Egeneral_pattern); 
	EListT<Eaxis2_placement_3dPtr> replicate_locations; 
};
class Etransition_feature : public IStepNode
{
public:
//// Inherited classes 
	Emanufacturing_feature _manufacturing_feature;
	CLASSDEF(Etransition_feature); 
	Emachining_featurePtr first_feature; 
	Emachining_featurePtr second_feature; 
};
class Echamfer : public IStepNode
{
public:
//// Inherited classes 
	Etransition_feature _transition_feature;
	CLASSDEF(Echamfer); 
	Eplane_angle_measurePtr angle_to_plane; 
	Etoleranced_length_measurePtr first_offset_amount; 
};
class Eedge_round : public IStepNode
{
public:
//// Inherited classes 
	Etransition_feature _transition_feature;
	CLASSDEF(Eedge_round); 
	Etoleranced_length_measurePtr radius; 
	Etoleranced_length_measurePtr first_offset_amount; 
	Etoleranced_length_measurePtr second_offset_amount; 
};
class Ethread : public IStepNode
{
public:
//// Inherited classes 
	Emachining_feature _machining_feature;
	CLASSDEF(Ethread); 
	Epartial_area_definitionPtr partial_profile; 
	EListT<Emachining_featurePtr> applied_shape; 
	EBooleanPtr inner_or_outer_thread; 
	Edescriptive_parameterPtr qualifier; 
	Edescriptive_parameterPtr fit_class; 
	Edescriptive_parameterPtr form; 
	Elength_measurePtr major_diameter; 
	Enumeric_parameterPtr number_of_threads; 
	Edescriptive_parameterPtr thread_hand; 
};
class Epartial_area_definition : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Epartial_area_definition); 
	Elength_measurePtr effective_length; 
	Eaxis2_placement_3dPtr placement; 
	Elength_measurePtr maximum_length; 
};
class Ecatalogue_thread : public IStepNode
{
public:
//// Inherited classes 
	Ethread _thread;
	CLASSDEF(Ecatalogue_thread); 
	EspecificationPtr documentation; 
};
class Especification : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Especification); 
	EListT<Especification_usage_constraintPtr> constraint; 
	EtextPtr specification_id; 
	EtextPtr specification_description; 
	EtextPtr specification_class; 
};
class Especification_usage_constraint : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Especification_usage_constraint); 
	EtextPtr element; 
	EtextPtr class_id; 
};
class Edefined_thread : public IStepNode
{
public:
//// Inherited classes 
	Ethread _thread;
	CLASSDEF(Edefined_thread); 
	Elength_measurePtr pitch_diameter; 
	Elength_measurePtr minor_diameter; 
	Elength_measurePtr crest; 
};
class Eprofile : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eprofile); 
	Eaxis2_placement_3dPtr placement; 
};
class Eopen_profile : public IStepNode
{
public:
//// Inherited classes 
	Eprofile _profile;
	CLASSDEF(Eopen_profile); 
};
class Elinear_profile : public IStepNode
{
public:
//// Inherited classes 
	Eopen_profile _open_profile;
	CLASSDEF(Elinear_profile); 
	Enumeric_parameterPtr profile_length; 
};
class Esquare_u_profile : public IStepNode
{
public:
//// Inherited classes 
	Eopen_profile _open_profile;
	CLASSDEF(Esquare_u_profile); 
	Etoleranced_length_measurePtr width; 
	Etoleranced_length_measurePtr first_radius; 
	Eplane_angle_measurePtr first_angle; 
	Etoleranced_length_measurePtr second_radius; 
	Eplane_angle_measurePtr second_angle; 
};
class Erounded_u_profile : public IStepNode
{
public:
//// Inherited classes 
	Eopen_profile _open_profile;
	CLASSDEF(Erounded_u_profile); 
	Etoleranced_length_measurePtr width; 
};
class Etee_profile : public IStepNode
{
public:
//// Inherited classes 
	Eopen_profile _open_profile;
	CLASSDEF(Etee_profile); 
	Eplane_angle_measurePtr first_angle; 
	Eplane_angle_measurePtr second_angle; 
	Etoleranced_length_measurePtr cross_bar_width; 
	Etoleranced_length_measurePtr cross_bar_depth; 
	Etoleranced_length_measurePtr radius; 
	Etoleranced_length_measurePtr width; 
	Etoleranced_length_measurePtr first_offset; 
	Etoleranced_length_measurePtr second_offset; 
};
class Evee_profile : public IStepNode
{
public:
//// Inherited classes 
	Eopen_profile _open_profile;
	CLASSDEF(Evee_profile); 
	Etoleranced_length_measurePtr profile_radius; 
	Eplane_angle_measurePtr profile_angle; 
	Eplane_angle_measurePtr tilt_angle; 
};
class Epartial_circular_profile : public IStepNode
{
public:
//// Inherited classes 
	Eopen_profile _open_profile;
	CLASSDEF(Epartial_circular_profile); 
	Etoleranced_length_measurePtr radius; 
	Eplane_angle_measurePtr sweep_angle; 
};
class Egeneral_profile : public IStepNode
{
public:
//// Inherited classes 
	Eopen_profile _open_profile;
	CLASSDEF(Egeneral_profile); 
	Ebounded_curvePtr its_profile; 
};
class Eclosed_profile : public IStepNode
{
public:
//// Inherited classes 
	Eprofile _profile;
	CLASSDEF(Eclosed_profile); 
};
class Erectangular_closed_profile : public IStepNode
{
public:
//// Inherited classes 
	Eclosed_profile _closed_profile;
	CLASSDEF(Erectangular_closed_profile); 
	Etoleranced_length_measurePtr profile_width; 
	Etoleranced_length_measurePtr profile_length; 
};
class Ecircular_closed_profile : public IStepNode
{
public:
//// Inherited classes 
	Eclosed_profile _closed_profile;
	CLASSDEF(Ecircular_closed_profile); 
	Etoleranced_length_measurePtr diameter; 
};
class Engon_profile : public IStepNode
{
public:
//// Inherited classes 
	Eclosed_profile _closed_profile;
	CLASSDEF(Engon_profile); 
	Etoleranced_length_measurePtr diameter; 
	EIntegerPtr number_of_sides; 
	EBooleanPtr circumscribed_or_across_flats; 
};
class Egeneral_closed_profile : public IStepNode
{
public:
//// Inherited classes 
	Eclosed_profile _closed_profile;
	CLASSDEF(Egeneral_closed_profile); 
	Ebounded_curvePtr closed_profile_shape; 
};
class Etravel_path : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etravel_path); 
	Eaxis2_placement_3dPtr placement; 
};
class Egeneral_path : public IStepNode
{
public:
//// Inherited classes 
	Etravel_path _travel_path;
	CLASSDEF(Egeneral_path); 
	Ebounded_curvePtr swept_path; 
};
class Elinear_path : public IStepNode
{
public:
//// Inherited classes 
	Etravel_path _travel_path;
	CLASSDEF(Elinear_path); 
	Etoleranced_length_measurePtr distance; 
	EdirectionPtr its_direction; 
};
class Ecircular_path : public IStepNode
{
public:
//// Inherited classes 
	Etravel_path _travel_path;
	CLASSDEF(Ecircular_path); 
	Etoleranced_length_measurePtr radius; 
};
class Ecomplete_circular_path : public IStepNode
{
public:
//// Inherited classes 
	Ecircular_path _circular_path;
	CLASSDEF(Ecomplete_circular_path); 
};
class Epartial_circular_path : public IStepNode
{
public:
//// Inherited classes 
	Ecircular_path _circular_path;
	CLASSDEF(Epartial_circular_path); 
	Eplane_angle_measurePtr sweep_angle; 
};
class Esurface_texture_parameter : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Esurface_texture_parameter); 
	Eparameter_valuePtr its_value; 
	ElabelPtr parameter_name; 
	EidentifierPtr measuring_method; 
	EidentifierPtr parameter_index; 
	EListT<Emachined_surfacePtr> applied_surfaces; 
};
class Emachined_surface : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Emachined_surface); 
	Emachining_featurePtr its_machining_feature; 
	Ebottom_or_sidePtr surface_element; 
};
class Eexecutable : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eexecutable); 
	EidentifierPtr its_id; 
};
class Eworkingstep : public IStepNode
{
public:
//// Inherited classes 
	Eexecutable _executable;
	CLASSDEF(Eworkingstep); 
	Eelementary_surfacePtr its_secplane; 
};
class Emachining_workingstep : public IStepNode
{
public:
//// Inherited classes 
	Eworkingstep _workingstep;
	CLASSDEF(Emachining_workingstep); 
	Emanufacturing_featurePtr its_feature; 
	Emachining_operationPtr its_operation; 
	Ein_process_geometryPtr its_effect; 
};
class Ein_process_geometry : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ein_process_geometry); 
	Eadvanced_brep_shape_representationPtr as_is; 
	Eadvanced_brep_shape_representationPtr to_be; 
	Eadvanced_brep_shape_representationPtr removal; 
};
class Eoperation : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eoperation); 
	Etoolpath_listPtr its_toolpath; 
	Etool_directionPtr its_tool_direction; 
};
class Erapid_movement : public IStepNode
{
public:
//// Inherited classes 
	Eworkingstep _workingstep;
	Eoperation _operation;
	CLASSDEF(Erapid_movement); 
};
class Ereturn_home : public IStepNode
{
public:
//// Inherited classes 
	Erapid_movement _rapid_movement;
	CLASSDEF(Ereturn_home); 
};
class Etouch_probing : public IStepNode
{
public:
//// Inherited classes 
	Eworkingstep _workingstep;
	Eoperation _operation;
	CLASSDEF(Etouch_probing); 
	Enc_variablePtr measured_offset; 
};
class Eworkpiece_probing : public IStepNode
{
public:
//// Inherited classes 
	Etouch_probing _touch_probing;
	CLASSDEF(Eworkpiece_probing); 
	Eaxis2_placement_3dPtr start_position; 
	EworkpiecePtr its_workpiece; 
	EdirectionPtr its_direction; 
	Etoleranced_length_measurePtr expected_value; 
	Etouch_probePtr its_probe; 
};
class Eworkpiece_complete_probing : public IStepNode
{
public:
//// Inherited classes 
	Etouch_probing _touch_probing;
	CLASSDEF(Eworkpiece_complete_probing); 
	EworkpiecePtr its_workpiece; 
	Etoleranced_length_measurePtr probing_distance; 
	Etouch_probePtr its_probe; 
	Eoffset_vectorPtr computed_offset; 
};
class Etouch_probe : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etouch_probe); 
	EidentifierPtr its_id; 
};
class Eoffset_vector : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eoffset_vector); 
	EListT<Enc_variablePtr> translate; 
	EListT<Enc_variablePtr> rotate; 
};
class Etool_probing : public IStepNode
{
public:
//// Inherited classes 
	Etouch_probing _touch_probing;
	CLASSDEF(Etool_probing); 
	Ecartesian_pointPtr offset; 
	Elength_measurePtr max_wear; 
	Emachining_toolPtr its_tool; 
};
class Emachining_tool : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Emachining_tool); 
	ElabelPtr its_id; 
};
class Ecutting_tool : public IStepNode
{
public:
//// Inherited classes 
	Emachining_tool _machining_tool;
	CLASSDEF(Ecutting_tool); 
	Etool_bodyPtr its_tool_body; 
	EListT<Ecutting_componentPtr> its_cutting_edge; 
	Elength_measurePtr overall_assembly_length; 
};
class Etool_body : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etool_body); 
};
class Ecutting_component : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecutting_component); 
	Elength_measurePtr tool_offset_length; 
	EmaterialPtr its_material; 
	Ecutting_edge_technological_dataPtr technological_data; 
	Etime_measurePtr expected_tool_life; 
	Emilling_technologyPtr its_technology; 
};
class Ecutting_edge_technological_data : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecutting_edge_technological_data); 
	Eplane_angle_measurePtr cutting_angle; 
	Eplane_angle_measurePtr free_angle; 
	Eplane_angle_measurePtr aux_angle; 
};
class Etool_length_probing : public IStepNode
{
public:
//// Inherited classes 
	Etool_probing _tool_probing;
	CLASSDEF(Etool_length_probing); 
};
class Etool_radius_probing : public IStepNode
{
public:
//// Inherited classes 
	Etool_probing _tool_probing;
	CLASSDEF(Etool_radius_probing); 
};
class Enc_function : public IStepNode
{
public:
//// Inherited classes 
	Eexecutable _executable;
	CLASSDEF(Enc_function); 
};
class Edisplay_message : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Edisplay_message); 
	EtextPtr its_text; 
};
class Eoptional_stop : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eoptional_stop); 
};
class Eprogram_stop : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eprogram_stop); 
};
class Eset_mark : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eset_mark); 
};
class Ewait_for_mark : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Ewait_for_mark); 
	EchannelPtr its_channel; 
};
class Eprogram_structure : public IStepNode
{
public:
//// Inherited classes 
	Eexecutable _executable;
	CLASSDEF(Eprogram_structure); 
};
class Eworkplan : public IStepNode
{
public:
//// Inherited classes 
	Eprogram_structure _program_structure;
	CLASSDEF(Eworkplan); 
	EListT<EexecutablePtr> its_elements; 
	EchannelPtr its_channel; 
	EsetupPtr its_setup; 
	Ein_process_geometryPtr its_effect; 
};
class Echannel : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Echannel); 
	EidentifierPtr its_id; 
};
class Esetup : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Esetup); 
	EidentifierPtr its_id; 
	Eaxis2_placement_3dPtr its_origin; 
	Eelementary_surfacePtr its_secplane; 
	EListT<Eworkpiece_setupPtr> its_workpiece_setup; 
};
class Eworkpiece_setup : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eworkpiece_setup); 
	EworkpiecePtr its_workpiece; 
	Eaxis2_placement_3dPtr its_origin; 
	Eoffset_vectorPtr its_offset; 
	Erestricted_area_selectPtr its_restricted_area; 
	EListT<Esetup_instructionPtr> its_instructions; 
};
class Esetup_instruction : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Esetup_instruction); 
	EtextPtr description; 
	EidentifierPtr external_document; 
};
class Eparallel : public IStepNode
{
public:
//// Inherited classes 
	Eprogram_structure _program_structure;
	CLASSDEF(Eparallel); 
	EListT<EexecutablePtr> branches; 
};
class Enon_sequential : public IStepNode
{
public:
//// Inherited classes 
	Eprogram_structure _program_structure;
	CLASSDEF(Enon_sequential); 
	EListT<EexecutablePtr> its_elements; 
};
class Eselective : public IStepNode
{
public:
//// Inherited classes 
	Eprogram_structure _program_structure;
	CLASSDEF(Eselective); 
	EListT<EexecutablePtr> its_elements; 
};
class Eif_statement : public IStepNode
{
public:
//// Inherited classes 
	Eprogram_structure _program_structure;
	CLASSDEF(Eif_statement); 
	Eboolean_expressionPtr condition; 
	EexecutablePtr true_branch; 
	EexecutablePtr false_branch; 
};
class Ewhile_statement : public IStepNode
{
public:
//// Inherited classes 
	Eprogram_structure _program_structure;
	CLASSDEF(Ewhile_statement); 
	Eboolean_expressionPtr condition; 
	EexecutablePtr body; 
};
class Eassignment : public IStepNode
{
public:
//// Inherited classes 
	Eprogram_structure _program_structure;
	CLASSDEF(Eassignment); 
	Enc_variablePtr its_lvalue; 
	ErvaluePtr its_rvalue; 
};
class Enc_variable : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Enc_variable); 
	ElabelPtr its_name; 
	EnumberPtr initial_value; 
};
class Enc_constant : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Enc_constant); 
	ElabelPtr its_name; 
	EnumberPtr its_value; 
};
class Eboolean_expression : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eboolean_expression); 
};
class Eunary_boolean_expression : public IStepNode
{
public:
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	CLASSDEF(Eunary_boolean_expression); 
	Eboolean_expressionPtr operand; 
};
class Enot_expression : public IStepNode
{
public:
//// Inherited classes 
	Eunary_boolean_expression _unary_boolean_expression;
	CLASSDEF(Enot_expression); 
};
class Ebinary_boolean_expression : public IStepNode
{
public:
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	CLASSDEF(Ebinary_boolean_expression); 
	Eboolean_expressionPtr operand1; 
	Eboolean_expressionPtr operand2; 
};
class Exor_expression : public IStepNode
{
public:
//// Inherited classes 
	Ebinary_boolean_expression _binary_boolean_expression;
	CLASSDEF(Exor_expression); 
};
class Emultiple_arity_boolean_expression : public IStepNode
{
public:
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	CLASSDEF(Emultiple_arity_boolean_expression); 
	EListT<Eboolean_expressionPtr> operands; 
};
class Eand_expression : public IStepNode
{
public:
//// Inherited classes 
	Emultiple_arity_boolean_expression _multiple_arity_boolean_expression;
	CLASSDEF(Eand_expression); 
};
class Eor_expression : public IStepNode
{
public:
//// Inherited classes 
	Emultiple_arity_boolean_expression _multiple_arity_boolean_expression;
	CLASSDEF(Eor_expression); 
};
class Ecomparison_expression : public IStepNode
{
public:
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	CLASSDEF(Ecomparison_expression); 
	Enc_variablePtr operand1; 
	ErvaluePtr operand2; 
};
class Ecomparison_equal : public IStepNode
{
public:
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
	CLASSDEF(Ecomparison_equal); 
};
class Ecomparison_not_equal : public IStepNode
{
public:
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
	CLASSDEF(Ecomparison_not_equal); 
};
class Ecomparison_greater : public IStepNode
{
public:
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
	CLASSDEF(Ecomparison_greater); 
};
class Ecomparison_greater_equal : public IStepNode
{
public:
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
	CLASSDEF(Ecomparison_greater_equal); 
};
class Ecomparison_less : public IStepNode
{
public:
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
	CLASSDEF(Ecomparison_less); 
};
class Ecomparison_less_equal : public IStepNode
{
public:
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
	CLASSDEF(Ecomparison_less_equal); 
};
class Etoolpath_list : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etoolpath_list); 
	EListT<EtoolpathPtr> its_list; 
};
class Etool_direction : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etool_direction); 
};
class Etwo_axes : public IStepNode
{
public:
//// Inherited classes 
	Etool_direction _tool_direction;
	CLASSDEF(Etwo_axes); 
};
class Ethree_axes : public IStepNode
{
public:
//// Inherited classes 
	Etool_direction _tool_direction;
	CLASSDEF(Ethree_axes); 
};
class Emachining_operation : public IStepNode
{
public:
//// Inherited classes 
	Eoperation _operation;
	CLASSDEF(Emachining_operation); 
	EidentifierPtr its_id; 
	Elength_measurePtr retract_plane; 
	Ecartesian_pointPtr start_point; 
	Emachining_toolPtr its_tool; 
	EtechnologyPtr its_technology; 
	Emachine_functionsPtr its_machine_functions; 
};
class Etechnology : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etechnology); 
	Espeed_measurePtr feedrate; 
	Etool_reference_pointPtr feedrate_reference; 
};
class Emachine_functions : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Emachine_functions); 
};
class Etoolpath : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etoolpath); 
	EBooleanPtr its_priority; 
	Etoolpath_typePtr its_type; 
	Etoolpath_speedprofilePtr its_speed; 
	EtechnologyPtr its_technology; 
	Emachine_functionsPtr its_machine_functions; 
};
class Etoolpath_speed : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etoolpath_speed); 
	Eb_spline_curvePtr speed; 
};
class Efeedstop : public IStepNode
{
public:
//// Inherited classes 
	Etoolpath _toolpath;
	CLASSDEF(Efeedstop); 
	Etime_measurePtr dwell; 
};
class Etrajectory : public IStepNode
{
public:
//// Inherited classes 
	Etoolpath _toolpath;
	CLASSDEF(Etrajectory); 
	EBooleanPtr its_direction; 
};
class Ecutter_location_trajectory : public IStepNode
{
public:
//// Inherited classes 
	Etrajectory _trajectory;
	CLASSDEF(Ecutter_location_trajectory); 
	Ebounded_curvePtr basiccurve; 
	Ebounded_curvePtr its_toolaxis; 
	Ebounded_curvePtr surface_normal; 
};
class Ecutter_contact_trajectory : public IStepNode
{
public:
//// Inherited classes 
	Etrajectory _trajectory;
	CLASSDEF(Ecutter_contact_trajectory); 
	Ecurve_with_surface_normalPtr basiccurve; 
	Ebounded_curvePtr its_toolaxis; 
	Econtact_typePtr its_contact_type; 
};
class Ecurve_with_normal_vector : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Ecurve_with_normal_vector); 
	Ebounded_curvePtr basiccurve; 
	Ebounded_curvePtr surface_normal; 
};
class Eaxis_trajectory : public IStepNode
{
public:
//// Inherited classes 
	Etrajectory _trajectory;
	CLASSDEF(Eaxis_trajectory); 
	EListT<EidentifierPtr> axis_list; 
	EListT<Ebounded_curvePtr> commands; 
};
class Eparameterised_path : public IStepNode
{
public:
//// Inherited classes 
	Etoolpath _toolpath;
	CLASSDEF(Eparameterised_path); 
};
class Econnector : public IStepNode
{
public:
//// Inherited classes 
	Eparameterised_path _parameterised_path;
	CLASSDEF(Econnector); 
};
class Econnect_secplane : public IStepNode
{
public:
//// Inherited classes 
	Econnector _connector;
	CLASSDEF(Econnect_secplane); 
	EdirectionPtr up_dir; 
	EdirectionPtr down_dir; 
};
class Econnect_direct : public IStepNode
{
public:
//// Inherited classes 
	Econnector _connector;
	CLASSDEF(Econnect_direct); 
};
class Eapproach_lift_path : public IStepNode
{
public:
//// Inherited classes 
	Eparameterised_path _parameterised_path;
	CLASSDEF(Eapproach_lift_path); 
	Ecartesian_pointPtr fix_point; 
	EdirectionPtr fix_point_dir; 
};
class Eap_lift_path_angle : public IStepNode
{
public:
//// Inherited classes 
	Eapproach_lift_path _approach_lift_path;
	CLASSDEF(Eap_lift_path_angle); 
	Eplane_angle_measurePtr angle; 
	Epositive_length_measurePtr benddist; 
};
class Eap_lift_path_tangent : public IStepNode
{
public:
//// Inherited classes 
	Eapproach_lift_path _approach_lift_path;
	CLASSDEF(Eap_lift_path_tangent); 
	Epositive_length_measurePtr radius; 
};
class Emilling_cutting_tool : public IStepNode
{
public:
//// Inherited classes 
	Ecutting_tool _cutting_tool;
	CLASSDEF(Emilling_cutting_tool); 
	EdirectionPtr direction_for_spindle_orientation; 
	Elength_measurePtr tool_holder_diameter_for_spindle_orientation; 
};
class Emilling_tool_body : public IStepNode
{
public:
//// Inherited classes 
	Etool_body _tool_body;
	CLASSDEF(Emilling_tool_body); 
	Emilling_tool_dimensionPtr dimension; 
	EIntegerPtr number_of_teeth; 
	EhandPtr hand_of_cut; 
	EBooleanPtr coolant_through_tool; 
	Elength_measurePtr pilot_length; 
};
class Emilling_tool_dimension : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Emilling_tool_dimension); 
	Elength_measurePtr diameter; 
	Eplane_angle_measurePtr tool_top_angle; 
	Eplane_angle_measurePtr tool_circumference_angle; 
	Elength_measurePtr cutting_edge_length; 
	Elength_measurePtr edge_radius; 
	Elength_measurePtr edge_center_vertical; 
	Elength_measurePtr edge_center_horizontal; 
};
class Ecenter_drill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Ecenter_drill); 
};
class Ecountersink : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Ecountersink); 
	Elength_measurePtr countersink_radius; 
};
class Ebackside_countersink : public IStepNode
{
public:
//// Inherited classes 
	Ecountersink _countersink;
	CLASSDEF(Ebackside_countersink); 
};
class Edrill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Edrill); 
};
class Etwist_drill : public IStepNode
{
public:
//// Inherited classes 
	Edrill _drill;
	CLASSDEF(Etwist_drill); 
};
class Etapered_drill : public IStepNode
{
public:
//// Inherited classes 
	Etwist_drill _twist_drill;
	CLASSDEF(Etapered_drill); 
	Eplane_angle_measurePtr taper_angle; 
};
class Espade_drill : public IStepNode
{
public:
//// Inherited classes 
	Edrill _drill;
	CLASSDEF(Espade_drill); 
};
class Emilling_cutter : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Emilling_cutter); 
};
class Efacemill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	CLASSDEF(Efacemill); 
};
class Eendmill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	CLASSDEF(Eendmill); 
};
class Etapered_endmill : public IStepNode
{
public:
//// Inherited classes 
	Eendmill _endmill;
	CLASSDEF(Etapered_endmill); 
	Eplane_angle_measurePtr taper_angle; 
};
class Eball_endmill : public IStepNode
{
public:
//// Inherited classes 
	Eendmill _endmill;
	CLASSDEF(Eball_endmill); 
};
class Ebullnose_endmill : public IStepNode
{
public:
//// Inherited classes 
	Eendmill _endmill;
	CLASSDEF(Ebullnose_endmill); 
};
class Et_slot_mill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	CLASSDEF(Et_slot_mill); 
	Elength_measurePtr cutting_thickness; 
};
class Edovetail_mill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	CLASSDEF(Edovetail_mill); 
	Eplane_angle_measurePtr included_angle; 
};
class Ewoodruff_keyseat_mill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	CLASSDEF(Ewoodruff_keyseat_mill); 
	Elength_measurePtr cutter_width; 
};
class Eside_mill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	CLASSDEF(Eside_mill); 
	Elength_measurePtr cutter_width; 
};
class Ethread_mill : public IStepNode
{
public:
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	CLASSDEF(Ethread_mill); 
};
class Etap : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Etap); 
};
class Etapered_tap : public IStepNode
{
public:
//// Inherited classes 
	Etap _tap;
	CLASSDEF(Etapered_tap); 
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_tap : public IStepNode
{
public:
//// Inherited classes 
	Etap _tap;
	CLASSDEF(Ecombined_drill_and_tap); 
	Elength_measurePtr drill_length; 
};
class Ethreading_tool : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Ethreading_tool); 
};
class Ecounterbore : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Ecounterbore); 
};
class Ebackside_counterbore : public IStepNode
{
public:
//// Inherited classes 
	Ecounterbore _counterbore;
	CLASSDEF(Ebackside_counterbore); 
};
class Ereamer : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Ereamer); 
};
class Etapered_reamer : public IStepNode
{
public:
//// Inherited classes 
	Ereamer _reamer;
	CLASSDEF(Etapered_reamer); 
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_reamer : public IStepNode
{
public:
//// Inherited classes 
	Ereamer _reamer;
	CLASSDEF(Ecombined_drill_and_reamer); 
	Elength_measurePtr drill_length; 
};
class Eboring_tool : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Eboring_tool); 
};
class Euser_defined_tool : public IStepNode
{
public:
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	CLASSDEF(Euser_defined_tool); 
	ElabelPtr identifier; 
};
class Eexchange_pallet : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eexchange_pallet); 
};
class Eindex_pallet : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eindex_pallet); 
	EIntegerPtr its_index; 
};
class Eindex_table : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eindex_table); 
	EIntegerPtr its_index; 
};
class Eload_tool : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eload_tool); 
	Emachining_toolPtr its_tool; 
};
class Eunload_tool : public IStepNode
{
public:
//// Inherited classes 
	Enc_function _nc_function;
	CLASSDEF(Eunload_tool); 
	Emachining_toolPtr its_tool; 
};
class Etool_direction_for_milling : public IStepNode
{
public:
//// Inherited classes 
	Etool_direction _tool_direction;
	CLASSDEF(Etool_direction_for_milling); 
};
class Ethree_axes_tilted_tool : public IStepNode
{
public:
//// Inherited classes 
	Etool_direction_for_milling _tool_direction_for_milling;
	CLASSDEF(Ethree_axes_tilted_tool); 
	EdirectionPtr tool_direction; 
};
class Efive_axes_var_tilt_yaw : public IStepNode
{
public:
//// Inherited classes 
	Etool_direction_for_milling _tool_direction_for_milling;
	CLASSDEF(Efive_axes_var_tilt_yaw); 
};
class Efive_axes_const_tilt_yaw : public IStepNode
{
public:
//// Inherited classes 
	Etool_direction_for_milling _tool_direction_for_milling;
	CLASSDEF(Efive_axes_const_tilt_yaw); 
	Eplane_angle_measurePtr tilt_angle; 
	Eplane_angle_measurePtr yaw_angle; 
};
class Emilling_machining_operation : public IStepNode
{
public:
//// Inherited classes 
	Emachining_operation _machining_operation;
	CLASSDEF(Emilling_machining_operation); 
	Elength_measurePtr overcut_length; 
};
class Emilling_technology : public IStepNode
{
public:
//// Inherited classes 
	Etechnology _technology;
	CLASSDEF(Emilling_technology); 
	Espeed_measurePtr cutspeed; 
	Erot_speed_measurePtr spindle; 
	Elength_measurePtr feedrate_per_tooth; 
	EBooleanPtr synchronize_spindle_with_feed; 
	EBooleanPtr inhibit_feedrate_override; 
	EBooleanPtr inhibit_spindle_override; 
	Eadaptive_controlPtr its_adaptive_control; 
};
class Eadaptive_control : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eadaptive_control); 
};
class Emilling_machine_functions : public IStepNode
{
public:
//// Inherited classes 
	Emachine_functions _machine_functions;
	CLASSDEF(Emilling_machine_functions); 
	EBooleanPtr coolant; 
	Epressure_measurePtr coolant_pressure; 
	EBooleanPtr mist; 
	EBooleanPtr through_spindle_coolant; 
	Epressure_measurePtr through_pressure; 
	EListT<EidentifierPtr> axis_clamping; 
	EBooleanPtr chip_removal; 
	EdirectionPtr oriented_spindle_stop; 
	Eprocess_model_listPtr its_process_model; 
	EListT<Eproperty_parameterPtr> other_functions; 
};
class Eprocess_model_list : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eprocess_model_list); 
	EListT<Eprocess_modelPtr> its_list; 
};
class Eprocess_model : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eprocess_model); 
	ElabelPtr ini_data_file; 
	ElabelPtr its_type; 
};
class Emilling_type_operation : public IStepNode
{
public:
//// Inherited classes 
	Emilling_machining_operation _milling_machining_operation;
	CLASSDEF(Emilling_type_operation); 
	Eapproach_retract_strategyPtr approach; 
	Eapproach_retract_strategyPtr retract; 
};
class Eapproach_retract_strategy : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Eapproach_retract_strategy); 
	EdirectionPtr tool_orientation; 
};
class Eplunge_strategy : public IStepNode
{
public:
//// Inherited classes 
	Eapproach_retract_strategy _approach_retract_strategy;
	CLASSDEF(Eplunge_strategy); 
};
class Eplunge_toolaxis : public IStepNode
{
public:
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
	CLASSDEF(Eplunge_toolaxis); 
};
class Eplunge_ramp : public IStepNode
{
public:
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
	CLASSDEF(Eplunge_ramp); 
	Eplane_angle_measurePtr angle; 
};
class Eplunge_helix : public IStepNode
{
public:
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
	CLASSDEF(Eplunge_helix); 
	Elength_measurePtr radius; 
	Eplane_angle_measurePtr angle; 
};
class Eplunge_zigzag : public IStepNode
{
public:
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
	CLASSDEF(Eplunge_zigzag); 
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr width; 
};
class Eair_strategy : public IStepNode
{
public:
//// Inherited classes 
	Eapproach_retract_strategy _approach_retract_strategy;
	CLASSDEF(Eair_strategy); 
};
class Eap_retract_angle : public IStepNode
{
public:
//// Inherited classes 
	Eair_strategy _air_strategy;
	CLASSDEF(Eap_retract_angle); 
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr travel_length; 
};
class Eap_retract_tangent : public IStepNode
{
public:
//// Inherited classes 
	Eair_strategy _air_strategy;
	CLASSDEF(Eap_retract_tangent); 
	Elength_measurePtr radius; 
};
class Ealong_path : public IStepNode
{
public:
//// Inherited classes 
	Eapproach_retract_strategy _approach_retract_strategy;
	CLASSDEF(Ealong_path); 
	Etoolpath_listPtr path; 
};
class Efreeform_operation : public IStepNode
{
public:
//// Inherited classes 
	Emilling_type_operation _milling_type_operation;
	CLASSDEF(Efreeform_operation); 
	Efreeform_strategyPtr its_machining_strategy; 
};
class Efreeform_strategy : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Efreeform_strategy); 
	Epathmode_typePtr pathmode; 
	Ecutmode_typePtr cutmode; 
	EtolerancesPtr its_milling_tolerances; 
	Elength_measurePtr stepover; 
};
class Etolerances : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etolerances); 
	Elength_measurePtr chordal_tolerance; 
	Elength_measurePtr scallop_height; 
};
class Euv_strategy : public IStepNode
{
public:
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	CLASSDEF(Euv_strategy); 
	EdirectionPtr forward_direction; 
	EdirectionPtr sideward_direction; 
};
class Eplane_cc_strategy : public IStepNode
{
public:
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	CLASSDEF(Eplane_cc_strategy); 
	EdirectionPtr its_plane_normal; 
};
class Eplane_cl_strategy : public IStepNode
{
public:
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	CLASSDEF(Eplane_cl_strategy); 
	EdirectionPtr its_plane_normal; 
};
class Eleading_line_strategy : public IStepNode
{
public:
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	CLASSDEF(Eleading_line_strategy); 
	Ebounded_curvePtr its_line; 
};
class Etwo5d_milling_operation : public IStepNode
{
public:
//// Inherited classes 
	Emilling_type_operation _milling_type_operation;
	CLASSDEF(Etwo5d_milling_operation); 
	Etwo5d_milling_strategyPtr its_machining_strategy; 
};
class Etwo5d_milling_strategy : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Etwo5d_milling_strategy); 
	Epositive_ratio_measurePtr overlap; 
	EBooleanPtr allow_multiple_passes; 
};
class Eunidirectional : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Eunidirectional); 
	EdirectionPtr feed_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Ebidirectional); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Estroke_connection_strategyPtr its_stroke_connection_strategy; 
};
class Econtour_parallel : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Econtour_parallel); 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional_contour : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Ebidirectional_contour); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_bidirectional : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Econtour_bidirectional); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_spiral : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Econtour_spiral); 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ecenter_milling : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Ecenter_milling); 
};
class Eexplicit : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	CLASSDEF(Eexplicit); 
};
class Eplane_milling : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_operation _two5d_milling_operation;
	CLASSDEF(Eplane_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr allowance_bottom; 
};
class Eplane_rough_milling : public IStepNode
{
public:
//// Inherited classes 
	Eplane_milling _plane_milling;
	CLASSDEF(Eplane_rough_milling); 
};
class Eplane_finish_milling : public IStepNode
{
public:
//// Inherited classes 
	Eplane_milling _plane_milling;
	CLASSDEF(Eplane_finish_milling); 
};
class Eside_milling : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_operation _two5d_milling_operation;
	CLASSDEF(Eside_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
};
class Eside_rough_milling : public IStepNode
{
public:
//// Inherited classes 
	Eside_milling _side_milling;
	CLASSDEF(Eside_rough_milling); 
};
class Eside_finish_milling : public IStepNode
{
public:
//// Inherited classes 
	Eside_milling _side_milling;
	CLASSDEF(Eside_finish_milling); 
};
class Ebottom_and_side_milling : public IStepNode
{
public:
//// Inherited classes 
	Etwo5d_milling_operation _two5d_milling_operation;
	CLASSDEF(Ebottom_and_side_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
	Elength_measurePtr allowance_bottom; 
};
class Ebottom_and_side_rough_milling : public IStepNode
{
public:
//// Inherited classes 
	Ebottom_and_side_milling _bottom_and_side_milling;
	CLASSDEF(Ebottom_and_side_rough_milling); 
};
class Ebottom_and_side_finish_milling : public IStepNode
{
public:
//// Inherited classes 
	Ebottom_and_side_milling _bottom_and_side_milling;
	CLASSDEF(Ebottom_and_side_finish_milling); 
};
class Edrilling_type_operation : public IStepNode
{
public:
//// Inherited classes 
	Emilling_machining_operation _milling_machining_operation;
	CLASSDEF(Edrilling_type_operation); 
	Elength_measurePtr cutting_depth; 
	Elength_measurePtr previous_diameter; 
	Etime_measurePtr dwell_time_bottom; 
	Epositive_ratio_measurePtr feed_on_retract; 
	Edrilling_type_strategyPtr its_machining_strategy; 
};
class Edrilling_type_strategy : public IStepNode
{
public:
//// Inherited classes 
	CLASSDEF(Edrilling_type_strategy); 
	Epositive_ratio_measurePtr reduced_cut_at_start; 
	Epositive_ratio_measurePtr reduced_feed_at_start; 
	Elength_measurePtr depth_of_start; 
	Epositive_ratio_measurePtr reduced_cut_at_end; 
	Epositive_ratio_measurePtr reduced_feed_at_end; 
	Elength_measurePtr depth_of_end; 
};
class Edrilling_operation : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	CLASSDEF(Edrilling_operation); 
};
class Edrilling : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_operation _drilling_operation;
	CLASSDEF(Edrilling); 
};
class Ecenter_drilling : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_operation _drilling_operation;
	CLASSDEF(Ecenter_drilling); 
};
class Ecounter_sinking : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_operation _drilling_operation;
	CLASSDEF(Ecounter_sinking); 
};
class Emultistep_drilling : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_operation _drilling_operation;
	CLASSDEF(Emultistep_drilling); 
	Elength_measurePtr retract_distance; 
	Elength_measurePtr first_depth; 
	Elength_measurePtr depth_of_step; 
	Etime_measurePtr dwell_time_step; 
};
class Eboring_operation : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	CLASSDEF(Eboring_operation); 
	EBooleanPtr spindle_stop_at_bottom; 
	Elength_measurePtr depth_of_testcut; 
	Ecartesian_pointPtr waiting_position; 
};
class Eboring : public IStepNode
{
public:
//// Inherited classes 
	Eboring_operation _boring_operation;
	CLASSDEF(Eboring); 
};
class Ereaming : public IStepNode
{
public:
//// Inherited classes 
	Eboring_operation _boring_operation;
	CLASSDEF(Ereaming); 
};
class Eback_boring : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	CLASSDEF(Eback_boring); 
};
class Etapping : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	CLASSDEF(Etapping); 
	EBooleanPtr compensation_chuck; 
};
class Ethread_drilling : public IStepNode
{
public:
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	CLASSDEF(Ethread_drilling); 
	EBooleanPtr helical_movement_on_forward; 
};
} /* End namespace Express*/
