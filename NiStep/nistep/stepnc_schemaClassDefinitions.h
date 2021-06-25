//
//
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
_T(".ahead."),
_T(".exact."),
_T(".behind.")};
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
_T(".cartesian."),
_T(".parameter."),
_T(".unspecified.")};
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
_T(".discontinuous."),
_T(".continuous."),
_T(".cont_same_gradient."),
_T(".cont_same_gradient_same_curvature.")};
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
_T(".polyline_form."),
_T(".circular_arc."),
_T(".elliptic_arc."),
_T(".parabolic_arc."),
_T(".hyperbolic_arc."),
_T(".unspecified.")};
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
_T(".plane_surf."),
_T(".cylindrical_surf."),
_T(".conical_surf."),
_T(".spherical_surf."),
_T(".toroidal_surf."),
_T(".surf_of_revolution."),
_T(".ruled_surf."),
_T(".generalised_cone."),
_T(".quadric_surf."),
_T(".surf_of_linear_extrusion."),
_T(".unspecified.")};
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
_T(".uniform_knots."),
_T(".quasi_uniform_knots."),
_T(".piecewise_bezier_knots."),
_T(".unspecified.")};
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
_T(".shaft."),
_T(".hole.")};
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
_T(".cw."),
_T(".ccw.")};
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
_T(".bottom."),
_T(".side."),
_T(".bottom_and_side.")};
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
_T(".tcp."),
_T(".ccp.")};
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
_T(".approach."),
_T(".lift."),
_T(".connect."),
_T(".non_contact."),
_T(".contact."),
_T(".trajectory_path.")};
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
_T(".RAPID.")};
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
_T(".side."),
_T(".front.")};
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
_T(".left."),
_T(".right."),
_T(".neutral.")};
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
_T(".forward."),
_T(".zigzag.")};
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
_T(".climb."),
_T(".conventional.")};
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
_T(".left."),
_T(".right.")};
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
_T(".straghtline."),
_T(".lift_shift_plunge."),
_T(".degouge."),
_T(".loop_back.")};
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
class Eapproval : 
	INHERITANCEDEF(Eapproval) 
{ 
	CLASSDEF(Eapproval); 
//// Inherited classes 
	Eapproval_statusPtr status; 
	ElabelPtr level; 
};
class Eapproval_status : 
	INHERITANCEDEF(Eapproval_status) 
{ 
	CLASSDEF(Eapproval_status); 
//// Inherited classes 
	ElabelPtr name; 
};
class Edate_and_time : 
	INHERITANCEDEF(Edate_and_time) 
{ 
	CLASSDEF(Edate_and_time); 
//// Inherited classes 
	EdatePtr date_component; 
	Elocal_timePtr time_component; 
};
class Edate : 
	INHERITANCEDEF(Edate) 
{ 
	CLASSDEF(Edate); 
//// Inherited classes 
	Eyear_numberPtr year_component; 
};
class Ecalendar_date : 
	INHERITANCEDEF(Ecalendar_date) 
{ 
	CLASSDEF(Ecalendar_date); 
//// Inherited classes 
	Edate _date;
	Eday_in_month_numberPtr day_component; 
	Emonth_in_year_numberPtr month_component; 
};
class Eordinal_date : 
	INHERITANCEDEF(Eordinal_date) 
{ 
	CLASSDEF(Eordinal_date); 
//// Inherited classes 
	Edate _date;
	Eday_in_year_numberPtr day_component; 
};
class Eweek_of_year_and_day_date : 
	INHERITANCEDEF(Eweek_of_year_and_day_date) 
{ 
	CLASSDEF(Eweek_of_year_and_day_date); 
//// Inherited classes 
	Edate _date;
	Eweek_in_year_numberPtr week_component; 
	Eday_in_week_numberPtr day_component; 
};
class Elocal_time : 
	INHERITANCEDEF(Elocal_time) 
{ 
	CLASSDEF(Elocal_time); 
//// Inherited classes 
	Ehour_in_dayPtr hour_component; 
	Eminute_in_hourPtr minute_component; 
	Esecond_in_minutePtr second_component; 
	Ecoordinated_universal_time_offsetPtr zone; 
};
class Ecoordinated_universal_time_offset : 
	INHERITANCEDEF(Ecoordinated_universal_time_offset) 
{ 
	CLASSDEF(Ecoordinated_universal_time_offset); 
//// Inherited classes 
	EIntegerPtr hour_offset; 
	EIntegerPtr minute_offset; 
	Eahead_or_behindPtr sense; 
};
class Eperson : 
	INHERITANCEDEF(Eperson) 
{ 
	CLASSDEF(Eperson); 
//// Inherited classes 
	EidentifierPtr id; 
	ElabelPtr last_name; 
	ElabelPtr first_name; 
	EListT<ElabelPtr> middle_names; 
	EListT<ElabelPtr> prefix_titles; 
	EListT<ElabelPtr> suffix_titles; 
};
class Eaddress : 
	INHERITANCEDEF(Eaddress) 
{ 
	CLASSDEF(Eaddress); 
//// Inherited classes 
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
class Erepresentation : 
	INHERITANCEDEF(Erepresentation) 
{ 
	CLASSDEF(Erepresentation); 
//// Inherited classes 
	ElabelPtr name; 
	EListT<Erepresentation_itemPtr> items; 
	Erepresentation_contextPtr context_of_items; 
};
class Eshape_representation : 
	INHERITANCEDEF(Eshape_representation) 
{ 
	CLASSDEF(Eshape_representation); 
//// Inherited classes 
	Erepresentation _representation;
};
class Erepresentation_item : 
	INHERITANCEDEF(Erepresentation_item) 
{ 
	CLASSDEF(Erepresentation_item); 
//// Inherited classes 
	ElabelPtr name; 
};
class Egeometric_representation_item : 
	INHERITANCEDEF(Egeometric_representation_item) 
{ 
	CLASSDEF(Egeometric_representation_item); 
//// Inherited classes 
	Erepresentation_item _representation_item;
};
class Ecurve : 
	INHERITANCEDEF(Ecurve) 
{ 
	CLASSDEF(Ecurve); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
};
class Ebounded_curve : 
	INHERITANCEDEF(Ebounded_curve) 
{ 
	CLASSDEF(Ebounded_curve); 
//// Inherited classes 
	Ecurve _curve;
};
class Etrimmed_curve : 
	INHERITANCEDEF(Etrimmed_curve) 
{ 
	CLASSDEF(Etrimmed_curve); 
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	EcurvePtr basis_curve; 
	EListT<Etrimming_selectPtr> trim_1; 
	EListT<Etrimming_selectPtr> trim_2; 
	EBooleanPtr sense_agreement; 
	Etrimming_preferencePtr master_representation; 
};
class Ecomposite_curve : 
	INHERITANCEDEF(Ecomposite_curve) 
{ 
	CLASSDEF(Ecomposite_curve); 
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	EListT<Ecomposite_curve_segmentPtr> segments; 
	ELogicalPtr self_intersect; 
};
class Ecomposite_curve_segment : 
	INHERITANCEDEF(Ecomposite_curve_segment) 
{ 
	CLASSDEF(Ecomposite_curve_segment); 
//// Inherited classes 
	Etransition_codePtr transition; 
	EBooleanPtr same_sense; 
	EcurvePtr parent_curve; 
};
class Eplacement : 
	INHERITANCEDEF(Eplacement) 
{ 
	CLASSDEF(Eplacement); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	Ecartesian_pointPtr location; 
};
class Eaxis1_placement : 
	INHERITANCEDEF(Eaxis1_placement) 
{ 
	CLASSDEF(Eaxis1_placement); 
//// Inherited classes 
	Eplacement _placement;
	EdirectionPtr axis; 
};
class Eaxis2_placement_3d : 
	INHERITANCEDEF(Eaxis2_placement_3d) 
{ 
	CLASSDEF(Eaxis2_placement_3d); 
//// Inherited classes 
	Eplacement _placement;
	EdirectionPtr axis; 
	EdirectionPtr ref_direction; 
};
class Eb_spline_curve : 
	INHERITANCEDEF(Eb_spline_curve) 
{ 
	CLASSDEF(Eb_spline_curve); 
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	EIntegerPtr degree; 
	EListT<Ecartesian_pointPtr> control_points_list; 
	Eb_spline_curve_formPtr curve_form; 
	ELogicalPtr closed_curve; 
	ELogicalPtr self_intersect; 
};
class Ebezier_curve : 
	INHERITANCEDEF(Ebezier_curve) 
{ 
	CLASSDEF(Ebezier_curve); 
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
};
class Esurface : 
	INHERITANCEDEF(Esurface) 
{ 
	CLASSDEF(Esurface); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
};
class Ebounded_surface : 
	INHERITANCEDEF(Ebounded_surface) 
{ 
	CLASSDEF(Ebounded_surface); 
//// Inherited classes 
	Esurface _surface;
};
class Eb_spline_surface : 
	INHERITANCEDEF(Eb_spline_surface) 
{ 
	CLASSDEF(Eb_spline_surface); 
//// Inherited classes 
	Ebounded_surface _bounded_surface;
	EIntegerPtr u_degree; 
	EIntegerPtr v_degree; 
	std::vector< EListT<Ecartesian_pointPtr> > control_points_list; 
	Eb_spline_surface_formPtr surface_form; 
	ELogicalPtr u_closed; 
	ELogicalPtr v_closed; 
	ELogicalPtr self_intersect; 
};
class Ebezier_surface : 
	INHERITANCEDEF(Ebezier_surface) 
{ 
	CLASSDEF(Ebezier_surface); 
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
};
class Epcurve : 
	INHERITANCEDEF(Epcurve) 
{ 
	CLASSDEF(Epcurve); 
//// Inherited classes 
	Ecurve _curve;
	EsurfacePtr basis_surface; 
	Edefinitional_representationPtr reference_to_curve; 
};
class Ebounded_pcurve : 
	INHERITANCEDEF(Ebounded_pcurve) 
{ 
	CLASSDEF(Ebounded_pcurve); 
//// Inherited classes 
	Epcurve _pcurve;
	Ebounded_curve _bounded_curve;
};
class Eb_spline_curve_with_knots : 
	INHERITANCEDEF(Eb_spline_curve_with_knots) 
{ 
	CLASSDEF(Eb_spline_curve_with_knots); 
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	EListT<EIntegerPtr> knot_multiplicities; 
	EListT<Eparameter_valuePtr> knots; 
	Eknot_typePtr knot_spec; 
};
class Eb_spline_surface_with_knots : 
	INHERITANCEDEF(Eb_spline_surface_with_knots) 
{ 
	CLASSDEF(Eb_spline_surface_with_knots); 
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	EListT<EIntegerPtr> u_multiplicities; 
	EListT<EIntegerPtr> v_multiplicities; 
	EListT<Eparameter_valuePtr> u_knots; 
	EListT<Eparameter_valuePtr> v_knots; 
	Eknot_typePtr knot_spec; 
};
class Epoint : 
	INHERITANCEDEF(Epoint) 
{ 
	CLASSDEF(Epoint); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
};
class Ecartesian_point : 
	INHERITANCEDEF(Ecartesian_point) 
{ 
	CLASSDEF(Ecartesian_point); 
//// Inherited classes 
	Epoint _point;
	EListT<Elength_measurePtr> coordinates; 
};
class Econic : 
	INHERITANCEDEF(Econic) 
{ 
	CLASSDEF(Econic); 
//// Inherited classes 
	Ecurve _curve;
	Eaxis2_placement_3dPtr position; 
};
class Ecircle : 
	INHERITANCEDEF(Ecircle) 
{ 
	CLASSDEF(Ecircle); 
//// Inherited classes 
	Econic _conic;
	Epositive_length_measurePtr radius; 
};
class Edirection : 
	INHERITANCEDEF(Edirection) 
{ 
	CLASSDEF(Edirection); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	EListT<ERealPtr> direction_ratios; 
};
class Eelementary_surface : 
	INHERITANCEDEF(Eelementary_surface) 
{ 
	CLASSDEF(Eelementary_surface); 
//// Inherited classes 
	Esurface _surface;
	Eaxis2_placement_3dPtr position; 
};
class Eellipse : 
	INHERITANCEDEF(Eellipse) 
{ 
	CLASSDEF(Eellipse); 
//// Inherited classes 
	Econic _conic;
	Epositive_length_measurePtr semi_axis_1; 
	Epositive_length_measurePtr semi_axis_2; 
};
class Erepresentation_context : 
	INHERITANCEDEF(Erepresentation_context) 
{ 
	CLASSDEF(Erepresentation_context); 
//// Inherited classes 
	EidentifierPtr context_identifier; 
	EtextPtr context_type; 
};
class Egeometric_representation_context : 
	INHERITANCEDEF(Egeometric_representation_context) 
{ 
	CLASSDEF(Egeometric_representation_context); 
//// Inherited classes 
	Erepresentation_context _representation_context;
	Edimension_countPtr coordinate_space_dimension; 
};
class Ehyperbola : 
	INHERITANCEDEF(Ehyperbola) 
{ 
	CLASSDEF(Ehyperbola); 
//// Inherited classes 
	Econic _conic;
	Epositive_length_measurePtr semi_axis; 
	Epositive_length_measurePtr semi_imag_axis; 
};
class Eline : 
	INHERITANCEDEF(Eline) 
{ 
	CLASSDEF(Eline); 
//// Inherited classes 
	Ecurve _curve;
	Ecartesian_pointPtr pnt; 
	EvectorPtr dir; 
};
class Eparabola : 
	INHERITANCEDEF(Eparabola) 
{ 
	CLASSDEF(Eparabola); 
//// Inherited classes 
	Econic _conic;
	Elength_measurePtr focal_dist; 
};
class Eplane : 
	INHERITANCEDEF(Eplane) 
{ 
	CLASSDEF(Eplane); 
//// Inherited classes 
	Eelementary_surface _elementary_surface;
};
class Epolyline : 
	INHERITANCEDEF(Epolyline) 
{ 
	CLASSDEF(Epolyline); 
//// Inherited classes 
	Ebounded_curve _bounded_curve;
	EListT<Ecartesian_pointPtr> points; 
};
class Equasi_uniform_curve : 
	INHERITANCEDEF(Equasi_uniform_curve) 
{ 
	CLASSDEF(Equasi_uniform_curve); 
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
};
class Equasi_uniform_surface : 
	INHERITANCEDEF(Equasi_uniform_surface) 
{ 
	CLASSDEF(Equasi_uniform_surface); 
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
};
class Erational_b_spline_curve : 
	INHERITANCEDEF(Erational_b_spline_curve) 
{ 
	CLASSDEF(Erational_b_spline_curve); 
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
	EListT<ERealPtr> weights_data; 
};
class Erational_b_spline_surface : 
	INHERITANCEDEF(Erational_b_spline_surface) 
{ 
	CLASSDEF(Erational_b_spline_surface); 
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
	std::vector< EListT<ERealPtr> > weights_data; 
};
class Espherical_surface : 
	INHERITANCEDEF(Espherical_surface) 
{ 
	CLASSDEF(Espherical_surface); 
//// Inherited classes 
	Eelementary_surface _elementary_surface;
	Epositive_length_measurePtr radius; 
};
class Eswept_surface : 
	INHERITANCEDEF(Eswept_surface) 
{ 
	CLASSDEF(Eswept_surface); 
//// Inherited classes 
	Esurface _surface;
	EcurvePtr swept_curve; 
};
class Esurface_of_linear_extrusion : 
	INHERITANCEDEF(Esurface_of_linear_extrusion) 
{ 
	CLASSDEF(Esurface_of_linear_extrusion); 
//// Inherited classes 
	Eswept_surface _swept_surface;
	EvectorPtr extrusion_axis; 
};
class Esurface_of_revolution : 
	INHERITANCEDEF(Esurface_of_revolution) 
{ 
	CLASSDEF(Esurface_of_revolution); 
//// Inherited classes 
	Eswept_surface _swept_surface;
	Eaxis1_placementPtr axis_position; 
};
class Euniform_curve : 
	INHERITANCEDEF(Euniform_curve) 
{ 
	CLASSDEF(Euniform_curve); 
//// Inherited classes 
	Eb_spline_curve _b_spline_curve;
};
class Euniform_surface : 
	INHERITANCEDEF(Euniform_surface) 
{ 
	CLASSDEF(Euniform_surface); 
//// Inherited classes 
	Eb_spline_surface _b_spline_surface;
};
class Evector : 
	INHERITANCEDEF(Evector) 
{ 
	CLASSDEF(Evector); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	EdirectionPtr orientation; 
	Elength_measurePtr magnitude; 
};
class Etopological_representation_item : 
	INHERITANCEDEF(Etopological_representation_item) 
{ 
	CLASSDEF(Etopological_representation_item); 
//// Inherited classes 
	Erepresentation_item _representation_item;
};
class Econnected_face_set : 
	INHERITANCEDEF(Econnected_face_set) 
{ 
	CLASSDEF(Econnected_face_set); 
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	EListT<EfacePtr> cfs_faces; 
};
class Eclosed_shell : 
	INHERITANCEDEF(Eclosed_shell) 
{ 
	CLASSDEF(Eclosed_shell); 
//// Inherited classes 
	Econnected_face_set _connected_face_set;
};
class Eedge : 
	INHERITANCEDEF(Eedge) 
{ 
	CLASSDEF(Eedge); 
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	EvertexPtr edge_start; 
	EvertexPtr edge_end; 
};
class Eedge_curve : 
	INHERITANCEDEF(Eedge_curve) 
{ 
	CLASSDEF(Eedge_curve); 
//// Inherited classes 
	Eedge _edge;
	Egeometric_representation_item _geometric_representation_item;
	EcurvePtr edge_geometry; 
	EBooleanPtr same_sense; 
};
class Eloop : 
	INHERITANCEDEF(Eloop) 
{ 
	CLASSDEF(Eloop); 
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
};
class Epath : 
	INHERITANCEDEF(Epath) 
{ 
	CLASSDEF(Epath); 
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	EListT<Eoriented_edgePtr> edge_list; 
};
class Eedge_loop : 
	INHERITANCEDEF(Eedge_loop) 
{ 
	CLASSDEF(Eedge_loop); 
//// Inherited classes 
	Eloop _loop;
	Epath _path;
};
class Eface : 
	INHERITANCEDEF(Eface) 
{ 
	CLASSDEF(Eface); 
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	EListT<Eface_boundPtr> bounds; 
};
class Eface_bound : 
	INHERITANCEDEF(Eface_bound) 
{ 
	CLASSDEF(Eface_bound); 
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
	EloopPtr bound; 
	EBooleanPtr orientation; 
};
class Eface_outer_bound : 
	INHERITANCEDEF(Eface_outer_bound) 
{ 
	CLASSDEF(Eface_outer_bound); 
//// Inherited classes 
	Eface_bound _face_bound;
};
class Eface_surface : 
	INHERITANCEDEF(Eface_surface) 
{ 
	CLASSDEF(Eface_surface); 
//// Inherited classes 
	Eface _face;
	Egeometric_representation_item _geometric_representation_item;
	EsurfacePtr face_geometry; 
	EBooleanPtr same_sense; 
};
class Eopen_shell : 
	INHERITANCEDEF(Eopen_shell) 
{ 
	CLASSDEF(Eopen_shell); 
//// Inherited classes 
	Econnected_face_set _connected_face_set;
};
class Eoriented_edge : 
	INHERITANCEDEF(Eoriented_edge) 
{ 
	CLASSDEF(Eoriented_edge); 
//// Inherited classes 
	Eedge _edge;
	EedgePtr edge_element; 
	EBooleanPtr orientation; 
};
class Evertex : 
	INHERITANCEDEF(Evertex) 
{ 
	CLASSDEF(Evertex); 
//// Inherited classes 
	Etopological_representation_item _topological_representation_item;
};
class Evertex_loop : 
	INHERITANCEDEF(Evertex_loop) 
{ 
	CLASSDEF(Evertex_loop); 
//// Inherited classes 
	Eloop _loop;
	EvertexPtr loop_vertex; 
};
class Evertex_point : 
	INHERITANCEDEF(Evertex_point) 
{ 
	CLASSDEF(Evertex_point); 
//// Inherited classes 
	Evertex _vertex;
	Egeometric_representation_item _geometric_representation_item;
	EpointPtr vertex_geometry; 
};
class Eblock : 
	INHERITANCEDEF(Eblock) 
{ 
	CLASSDEF(Eblock); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	Eaxis2_placement_3dPtr position; 
	Epositive_length_measurePtr x; 
	Epositive_length_measurePtr y; 
	Epositive_length_measurePtr z; 
};
class Esolid_model : 
	INHERITANCEDEF(Esolid_model) 
{ 
	CLASSDEF(Esolid_model); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
};
class Emanifold_solid_brep : 
	INHERITANCEDEF(Emanifold_solid_brep) 
{ 
	CLASSDEF(Emanifold_solid_brep); 
//// Inherited classes 
	Esolid_model _solid_model;
	Eclosed_shellPtr outer; 
};
class Eright_circular_cylinder : 
	INHERITANCEDEF(Eright_circular_cylinder) 
{ 
	CLASSDEF(Eright_circular_cylinder); 
//// Inherited classes 
	Egeometric_representation_item _geometric_representation_item;
	Eaxis1_placementPtr position; 
	Epositive_length_measurePtr height; 
	Epositive_length_measurePtr radius; 
};
class Edefinitional_representation : 
	INHERITANCEDEF(Edefinitional_representation) 
{ 
	CLASSDEF(Edefinitional_representation); 
//// Inherited classes 
	Erepresentation _representation;
};
class Eadvanced_face : 
	INHERITANCEDEF(Eadvanced_face) 
{ 
	CLASSDEF(Eadvanced_face); 
//// Inherited classes 
	Eface_surface _face_surface;
};
class Eadvanced_brep_shape_representation : 
	INHERITANCEDEF(Eadvanced_brep_shape_representation) 
{ 
	CLASSDEF(Eadvanced_brep_shape_representation); 
//// Inherited classes 
	Eshape_representation _shape_representation;
};
class Etoleranced_length_measure : 
	INHERITANCEDEF(Etoleranced_length_measure) 
{ 
	CLASSDEF(Etoleranced_length_measure); 
//// Inherited classes 
	Epositive_length_measurePtr theoretical_size; 
	Etolerance_selectPtr implicit_tolerance; 
};
class Eplus_minus_value : 
	INHERITANCEDEF(Eplus_minus_value) 
{ 
	CLASSDEF(Eplus_minus_value); 
//// Inherited classes 
	Epositive_length_measurePtr upper_limit; 
	Epositive_length_measurePtr lower_limit; 
	EIntegerPtr significant_digits; 
};
class Elimits_and_fits : 
	INHERITANCEDEF(Elimits_and_fits) 
{ 
	CLASSDEF(Elimits_and_fits); 
//// Inherited classes 
	Elength_measurePtr deviation; 
	Elength_measurePtr grade; 
	Efitting_typePtr its_fitting_type; 
};
class Eproject : 
	INHERITANCEDEF(Eproject) 
{ 
	CLASSDEF(Eproject); 
//// Inherited classes 
	EidentifierPtr its_id; 
	EworkplanPtr main_workplan; 
	EListT<EworkpiecePtr> its_workpieces; 
	Eperson_and_addressPtr its_owner; 
	Edate_and_timePtr its_release; 
	EapprovalPtr its_status; 
};
class Eperson_and_address : 
	INHERITANCEDEF(Eperson_and_address) 
{ 
	CLASSDEF(Eperson_and_address); 
//// Inherited classes 
	EpersonPtr its_person; 
	EaddressPtr its_address; 
};
class Eworkpiece : 
	INHERITANCEDEF(Eworkpiece) 
{ 
	CLASSDEF(Eworkpiece); 
//// Inherited classes 
	EidentifierPtr its_id; 
	EmaterialPtr its_material; 
	Eshape_tolerancePtr global_tolerance; 
	EworkpiecePtr its_rawpiece; 
	Eadvanced_brep_shape_representationPtr its_geometry; 
	Ebounding_geometry_selectPtr its_bounding_geometry; 
	EListT<Ecartesian_pointPtr> clamping_positions; 
};
class Ematerial : 
	INHERITANCEDEF(Ematerial) 
{ 
	CLASSDEF(Ematerial); 
//// Inherited classes 
	ElabelPtr standard_identifier; 
	ElabelPtr material_identifier; 
	EListT<Eproperty_parameterPtr> material_property; 
};
class Eproperty_parameter : 
	INHERITANCEDEF(Eproperty_parameter) 
{ 
	CLASSDEF(Eproperty_parameter); 
//// Inherited classes 
	ElabelPtr parameter_name; 
};
class Edescriptive_parameter : 
	INHERITANCEDEF(Edescriptive_parameter) 
{ 
	CLASSDEF(Edescriptive_parameter); 
//// Inherited classes 
	Eproperty_parameter _property_parameter;
	EtextPtr descriptive_string; 
};
class Enumeric_parameter : 
	INHERITANCEDEF(Enumeric_parameter) 
{ 
	CLASSDEF(Enumeric_parameter); 
//// Inherited classes 
	Eproperty_parameter _property_parameter;
	Eparameter_valuePtr its_parameter_value; 
	ElabelPtr its_parameter_unit; 
};
class Emanufacturing_feature : 
	INHERITANCEDEF(Emanufacturing_feature) 
{ 
	CLASSDEF(Emanufacturing_feature); 
//// Inherited classes 
	EidentifierPtr its_id; 
	EworkpiecePtr its_workpiece; 
	EListT<Emachining_operationPtr> its_operations; 
};
class Eregion : 
	INHERITANCEDEF(Eregion) 
{ 
	CLASSDEF(Eregion); 
//// Inherited classes 
	Emanufacturing_feature _manufacturing_feature;
	Eaxis2_placement_3dPtr feature_placement; 
};
class Eregion_projection : 
	INHERITANCEDEF(Eregion_projection) 
{ 
	CLASSDEF(Eregion_projection); 
//// Inherited classes 
	Eregion _region;
	Ebounded_curvePtr proj_curve; 
	EdirectionPtr proj_dir; 
	Etoleranced_length_measurePtr depth; 
};
class Eregion_surface_list : 
	INHERITANCEDEF(Eregion_surface_list) 
{ 
	CLASSDEF(Eregion_surface_list); 
//// Inherited classes 
	Eregion _region;
	EListT<Ebounded_surfacePtr> surface_list; 
};
class Etopological_region : 
	INHERITANCEDEF(Etopological_region) 
{ 
	CLASSDEF(Etopological_region); 
//// Inherited classes 
	Eregion _region;
	Eopen_shell _open_shell;
};
class Etwo5d_manufacturing_feature : 
	INHERITANCEDEF(Etwo5d_manufacturing_feature) 
{ 
	CLASSDEF(Etwo5d_manufacturing_feature); 
//// Inherited classes 
	Emanufacturing_feature _manufacturing_feature;
	Eaxis2_placement_3dPtr feature_placement; 
};
class Emachining_feature : 
	INHERITANCEDEF(Emachining_feature) 
{ 
	CLASSDEF(Emachining_feature); 
//// Inherited classes 
	Etwo5d_manufacturing_feature _two5d_manufacturing_feature;
	Eelementary_surfacePtr depth; 
};
class Eplanar_face : 
	INHERITANCEDEF(Eplanar_face) 
{ 
	CLASSDEF(Eplanar_face); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Elinear_pathPtr course_of_travel; 
	Elinear_profilePtr removal_boundary; 
	Eclosed_profilePtr face_boundary; 
	EListT<EbossPtr> its_boss; 
};
class Epocket : 
	INHERITANCEDEF(Epocket) 
{ 
	CLASSDEF(Epocket); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	EListT<EbossPtr> its_boss; 
	Eplane_angle_measurePtr slope; 
	Epocket_bottom_conditionPtr bottom_condition; 
	Etoleranced_length_measurePtr planar_radius; 
	Etoleranced_length_measurePtr orthogonal_radius; 
};
class Eclosed_pocket : 
	INHERITANCEDEF(Eclosed_pocket) 
{ 
	CLASSDEF(Eclosed_pocket); 
//// Inherited classes 
	Epocket _pocket;
	Eclosed_profilePtr feature_boundary; 
};
class Eopen_pocket : 
	INHERITANCEDEF(Eopen_pocket) 
{ 
	CLASSDEF(Eopen_pocket); 
//// Inherited classes 
	Epocket _pocket;
	Eopen_profilePtr open_boundary; 
	Eopen_profilePtr wall_boundary; 
};
class Epocket_bottom_condition : 
	INHERITANCEDEF(Epocket_bottom_condition) 
{ 
	CLASSDEF(Epocket_bottom_condition); 
//// Inherited classes 
};
class Ethrough_pocket_bottom_condition : 
	INHERITANCEDEF(Ethrough_pocket_bottom_condition) 
{ 
	CLASSDEF(Ethrough_pocket_bottom_condition); 
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
};
class Eplanar_pocket_bottom_condition : 
	INHERITANCEDEF(Eplanar_pocket_bottom_condition) 
{ 
	CLASSDEF(Eplanar_pocket_bottom_condition); 
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
};
class Eradiused_pocket_bottom_condition : 
	INHERITANCEDEF(Eradiused_pocket_bottom_condition) 
{ 
	CLASSDEF(Eradiused_pocket_bottom_condition); 
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
	Ecartesian_pointPtr floor_radius_center; 
	Etoleranced_length_measurePtr floor_radius; 
};
class Egeneral_pocket_bottom_condition : 
	INHERITANCEDEF(Egeneral_pocket_bottom_condition) 
{ 
	CLASSDEF(Egeneral_pocket_bottom_condition); 
//// Inherited classes 
	Epocket_bottom_condition _pocket_bottom_condition;
	EregionPtr shape; 
};
class Eslot : 
	INHERITANCEDEF(Eslot) 
{ 
	CLASSDEF(Eslot); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Etravel_pathPtr course_of_travel; 
	Eopen_profilePtr swept_shape; 
	EListT<Eslot_end_typePtr> end_conditions; 
};
class Eslot_end_type : 
	INHERITANCEDEF(Eslot_end_type) 
{ 
	CLASSDEF(Eslot_end_type); 
//// Inherited classes 
};
class Ewoodruff_slot_end_type : 
	INHERITANCEDEF(Ewoodruff_slot_end_type) 
{ 
	CLASSDEF(Ewoodruff_slot_end_type); 
//// Inherited classes 
	Eslot_end_type _slot_end_type;
	Etoleranced_length_measurePtr radius; 
};
class Eradiused_slot_end_type : 
	INHERITANCEDEF(Eradiused_slot_end_type) 
{ 
	CLASSDEF(Eradiused_slot_end_type); 
//// Inherited classes 
	Eslot_end_type _slot_end_type;
};
class Eflat_slot_end_type : 
	INHERITANCEDEF(Eflat_slot_end_type) 
{ 
	CLASSDEF(Eflat_slot_end_type); 
//// Inherited classes 
	Eslot_end_type _slot_end_type;
	Etoleranced_length_measurePtr corner_radius1; 
	Etoleranced_length_measurePtr corner_radius2; 
};
class Eloop_slot_end_type : 
	INHERITANCEDEF(Eloop_slot_end_type) 
{ 
	CLASSDEF(Eloop_slot_end_type); 
//// Inherited classes 
	Eslot_end_type _slot_end_type;
};
class Eopen_slot_end_type : 
	INHERITANCEDEF(Eopen_slot_end_type) 
{ 
	CLASSDEF(Eopen_slot_end_type); 
//// Inherited classes 
	Eslot_end_type _slot_end_type;
};
class Estep : 
	INHERITANCEDEF(Estep) 
{ 
	CLASSDEF(Estep); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Elinear_pathPtr open_boundary; 
	Evee_profilePtr wall_boundary; 
	EListT<EbossPtr> its_boss; 
};
class Eprofile_feature : 
	INHERITANCEDEF(Eprofile_feature) 
{ 
	CLASSDEF(Eprofile_feature); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Elinear_pathPtr profile_swept_shape; 
};
class Egeneral_outside_profile : 
	INHERITANCEDEF(Egeneral_outside_profile) 
{ 
	CLASSDEF(Egeneral_outside_profile); 
//// Inherited classes 
	Eprofile_feature _profile_feature;
	EprofilePtr feature_boundary; 
};
class Eshape_profile : 
	INHERITANCEDEF(Eshape_profile) 
{ 
	CLASSDEF(Eshape_profile); 
//// Inherited classes 
	Eprofile_feature _profile_feature;
	Eprofile_selectPtr floor_condition; 
	EdirectionPtr removal_direction; 
};
class Ethrough_profile_floor : 
	INHERITANCEDEF(Ethrough_profile_floor) 
{ 
	CLASSDEF(Ethrough_profile_floor); 
//// Inherited classes 
};
class Eprofile_floor : 
	INHERITANCEDEF(Eprofile_floor) 
{ 
	CLASSDEF(Eprofile_floor); 
//// Inherited classes 
	Enumeric_parameterPtr floor_radius; 
	EBooleanPtr start_or_end; 
};
class Egeneral_profile_floor : 
	INHERITANCEDEF(Egeneral_profile_floor) 
{ 
	CLASSDEF(Egeneral_profile_floor); 
//// Inherited classes 
	Eprofile_floor _profile_floor;
	EfacePtr floor; 
};
class Eplanar_profile_floor : 
	INHERITANCEDEF(Eplanar_profile_floor) 
{ 
	CLASSDEF(Eplanar_profile_floor); 
//// Inherited classes 
	Eprofile_floor _profile_floor;
	EplanePtr floor; 
};
class Egeneral_shape_profile : 
	INHERITANCEDEF(Egeneral_shape_profile) 
{ 
	CLASSDEF(Egeneral_shape_profile); 
//// Inherited classes 
	Eshape_profile _shape_profile;
	EprofilePtr profile_boundary; 
};
class Epartial_circular_shape_profile : 
	INHERITANCEDEF(Epartial_circular_shape_profile) 
{ 
	CLASSDEF(Epartial_circular_shape_profile); 
//// Inherited classes 
	Eshape_profile _shape_profile;
	Epartial_circular_profilePtr open_boundary; 
};
class Ecircular_closed_shape_profile : 
	INHERITANCEDEF(Ecircular_closed_shape_profile) 
{ 
	CLASSDEF(Ecircular_closed_shape_profile); 
//// Inherited classes 
	Eshape_profile _shape_profile;
	Ecircular_closed_profilePtr closed_boundary; 
};
class Erectangular_open_shape_profile : 
	INHERITANCEDEF(Erectangular_open_shape_profile) 
{ 
	CLASSDEF(Erectangular_open_shape_profile); 
//// Inherited classes 
	Eshape_profile _shape_profile;
	Esquare_u_profilePtr open_boundary; 
};
class Erectangular_closed_shape_profile : 
	INHERITANCEDEF(Erectangular_closed_shape_profile) 
{ 
	CLASSDEF(Erectangular_closed_shape_profile); 
//// Inherited classes 
	Eshape_profile _shape_profile;
	Erectangular_closed_profilePtr closed_boundary; 
};
class Eround_hole : 
	INHERITANCEDEF(Eround_hole) 
{ 
	CLASSDEF(Eround_hole); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Etoleranced_length_measurePtr diameter; 
	Etaper_selectPtr change_in_diameter; 
	Ehole_bottom_conditionPtr bottom_condition; 
};
class Ediameter_taper : 
	INHERITANCEDEF(Ediameter_taper) 
{ 
	CLASSDEF(Ediameter_taper); 
//// Inherited classes 
	Etoleranced_length_measurePtr final_diameter; 
};
class Eangle_taper : 
	INHERITANCEDEF(Eangle_taper) 
{ 
	CLASSDEF(Eangle_taper); 
//// Inherited classes 
	Eplane_angle_measurePtr angle; 
};
class Ehole_bottom_condition : 
	INHERITANCEDEF(Ehole_bottom_condition) 
{ 
	CLASSDEF(Ehole_bottom_condition); 
//// Inherited classes 
};
class Ethrough_bottom_condition : 
	INHERITANCEDEF(Ethrough_bottom_condition) 
{ 
	CLASSDEF(Ethrough_bottom_condition); 
//// Inherited classes 
	Ehole_bottom_condition _hole_bottom_condition;
};
class Eblind_bottom_condition : 
	INHERITANCEDEF(Eblind_bottom_condition) 
{ 
	CLASSDEF(Eblind_bottom_condition); 
//// Inherited classes 
	Ehole_bottom_condition _hole_bottom_condition;
};
class Eflat_hole_bottom : 
	INHERITANCEDEF(Eflat_hole_bottom) 
{ 
	CLASSDEF(Eflat_hole_bottom); 
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
};
class Eflat_with_radius_hole_bottom : 
	INHERITANCEDEF(Eflat_with_radius_hole_bottom) 
{ 
	CLASSDEF(Eflat_with_radius_hole_bottom); 
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
	Etoleranced_length_measurePtr corner_radius; 
};
class Espherical_hole_bottom : 
	INHERITANCEDEF(Espherical_hole_bottom) 
{ 
	CLASSDEF(Espherical_hole_bottom); 
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
	Etoleranced_length_measurePtr radius; 
};
class Econical_hole_bottom : 
	INHERITANCEDEF(Econical_hole_bottom) 
{ 
	CLASSDEF(Econical_hole_bottom); 
//// Inherited classes 
	Eblind_bottom_condition _blind_bottom_condition;
	Eplane_angle_measurePtr tip_angle; 
	Etoleranced_length_measurePtr tip_radius; 
};
class Etoolpath_feature : 
	INHERITANCEDEF(Etoolpath_feature) 
{ 
	CLASSDEF(Etoolpath_feature); 
//// Inherited classes 
	Emachining_feature _machining_feature;
};
class Eboss : 
	INHERITANCEDEF(Eboss) 
{ 
	CLASSDEF(Eboss); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Eclosed_profilePtr its_boundary; 
	Eplane_angle_measurePtr slope; 
};
class Espherical_cap : 
	INHERITANCEDEF(Espherical_cap) 
{ 
	CLASSDEF(Espherical_cap); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Enumeric_parameterPtr internal_angle; 
	Enumeric_parameterPtr radius; 
};
class Erounded_end : 
	INHERITANCEDEF(Erounded_end) 
{ 
	CLASSDEF(Erounded_end); 
//// Inherited classes 
	Emachining_feature _machining_feature;
	Elinear_pathPtr course_of_travel; 
	Epartial_circular_profilePtr partial_circular_boundary; 
};
class Ecompound_feature : 
	INHERITANCEDEF(Ecompound_feature) 
{ 
	CLASSDEF(Ecompound_feature); 
//// Inherited classes 
	Etwo5d_manufacturing_feature _two5d_manufacturing_feature;
	EListT<Ecompound_feature_selectPtr> elements; 
};
class Ecounterbore_hole : 
	INHERITANCEDEF(Ecounterbore_hole) 
{ 
	CLASSDEF(Ecounterbore_hole); 
//// Inherited classes 
	Ecompound_feature _compound_feature;
};
class Ecountersunk_hole : 
	INHERITANCEDEF(Ecountersunk_hole) 
{ 
	CLASSDEF(Ecountersunk_hole); 
//// Inherited classes 
	Ecompound_feature _compound_feature;
};
class Ereplicate_feature : 
	INHERITANCEDEF(Ereplicate_feature) 
{ 
	CLASSDEF(Ereplicate_feature); 
//// Inherited classes 
	Etwo5d_manufacturing_feature _two5d_manufacturing_feature;
	Etwo5d_manufacturing_featurePtr replicate_base_feature; 
};
class Ecircular_pattern : 
	INHERITANCEDEF(Ecircular_pattern) 
{ 
	CLASSDEF(Ecircular_pattern); 
//// Inherited classes 
	Ereplicate_feature _replicate_feature;
	Eplane_angle_measurePtr angle_increment; 
	EIntegerPtr number_of_feature; 
	EListT<Ecircular_offsetPtr> relocated_base_feature; 
	EListT<Ecircular_omitPtr> missing_base_feature; 
	Etoleranced_length_measurePtr base_feature_diameter; 
	Eplane_angle_measurePtr base_feature_rotation; 
};
class Ecircular_offset : 
	INHERITANCEDEF(Ecircular_offset) 
{ 
	CLASSDEF(Ecircular_offset); 
//// Inherited classes 
	Eplane_angle_measurePtr angular_offset; 
	EIntegerPtr index; 
};
class Ecircular_omit : 
	INHERITANCEDEF(Ecircular_omit) 
{ 
	CLASSDEF(Ecircular_omit); 
//// Inherited classes 
	EIntegerPtr index; 
};
class Erectangular_pattern : 
	INHERITANCEDEF(Erectangular_pattern) 
{ 
	CLASSDEF(Erectangular_pattern); 
//// Inherited classes 
	Ereplicate_feature _replicate_feature;
	Etoleranced_length_measurePtr spacing; 
	EdirectionPtr its_direction; 
	EIntegerPtr number_of_rows; 
	EIntegerPtr number_of_columns; 
	Etoleranced_length_measurePtr row_spacing; 
	EdirectionPtr row_layout_direction; 
	EListT<Erectangular_offsetPtr> relocated_base_feature; 
	EListT<Erectangular_omitPtr> missing_base_feature; 
};
class Erectangular_offset : 
	INHERITANCEDEF(Erectangular_offset) 
{ 
	CLASSDEF(Erectangular_offset); 
//// Inherited classes 
	EdirectionPtr offset_direction; 
	Elength_measurePtr offset_distance; 
	EIntegerPtr row_index; 
	EIntegerPtr column_index; 
};
class Erectangular_omit : 
	INHERITANCEDEF(Erectangular_omit) 
{ 
	CLASSDEF(Erectangular_omit); 
//// Inherited classes 
	EIntegerPtr row_index; 
	EIntegerPtr column_index; 
};
class Egeneral_pattern : 
	INHERITANCEDEF(Egeneral_pattern) 
{ 
	CLASSDEF(Egeneral_pattern); 
//// Inherited classes 
	Ereplicate_feature _replicate_feature;
	EListT<Eaxis2_placement_3dPtr> replicate_locations; 
};
class Etransition_feature : 
	INHERITANCEDEF(Etransition_feature) 
{ 
	CLASSDEF(Etransition_feature); 
//// Inherited classes 
	Emanufacturing_feature _manufacturing_feature;
	Emachining_featurePtr first_feature; 
	Emachining_featurePtr second_feature; 
};
class Echamfer : 
	INHERITANCEDEF(Echamfer) 
{ 
	CLASSDEF(Echamfer); 
//// Inherited classes 
	Etransition_feature _transition_feature;
	Eplane_angle_measurePtr angle_to_plane; 
	Etoleranced_length_measurePtr first_offset_amount; 
};
class Eedge_round : 
	INHERITANCEDEF(Eedge_round) 
{ 
	CLASSDEF(Eedge_round); 
//// Inherited classes 
	Etransition_feature _transition_feature;
	Etoleranced_length_measurePtr radius; 
	Etoleranced_length_measurePtr first_offset_amount; 
	Etoleranced_length_measurePtr second_offset_amount; 
};
class Ethread : 
	INHERITANCEDEF(Ethread) 
{ 
	CLASSDEF(Ethread); 
//// Inherited classes 
	Emachining_feature _machining_feature;
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
class Epartial_area_definition : 
	INHERITANCEDEF(Epartial_area_definition) 
{ 
	CLASSDEF(Epartial_area_definition); 
//// Inherited classes 
	Elength_measurePtr effective_length; 
	Eaxis2_placement_3dPtr placement; 
	Elength_measurePtr maximum_length; 
};
class Ecatalogue_thread : 
	INHERITANCEDEF(Ecatalogue_thread) 
{ 
	CLASSDEF(Ecatalogue_thread); 
//// Inherited classes 
	Ethread _thread;
	EspecificationPtr documentation; 
};
class Especification : 
	INHERITANCEDEF(Especification) 
{ 
	CLASSDEF(Especification); 
//// Inherited classes 
	EListT<Especification_usage_constraintPtr> constraint; 
	EtextPtr specification_id; 
	EtextPtr specification_description; 
	EtextPtr specification_class; 
};
class Especification_usage_constraint : 
	INHERITANCEDEF(Especification_usage_constraint) 
{ 
	CLASSDEF(Especification_usage_constraint); 
//// Inherited classes 
	EtextPtr element; 
	EtextPtr class_id; 
};
class Edefined_thread : 
	INHERITANCEDEF(Edefined_thread) 
{ 
	CLASSDEF(Edefined_thread); 
//// Inherited classes 
	Ethread _thread;
	Elength_measurePtr pitch_diameter; 
	Elength_measurePtr minor_diameter; 
	Elength_measurePtr crest; 
};
class Eprofile : 
	INHERITANCEDEF(Eprofile) 
{ 
	CLASSDEF(Eprofile); 
//// Inherited classes 
	Eaxis2_placement_3dPtr placement; 
};
class Eopen_profile : 
	INHERITANCEDEF(Eopen_profile) 
{ 
	CLASSDEF(Eopen_profile); 
//// Inherited classes 
	Eprofile _profile;
};
class Elinear_profile : 
	INHERITANCEDEF(Elinear_profile) 
{ 
	CLASSDEF(Elinear_profile); 
//// Inherited classes 
	Eopen_profile _open_profile;
	Enumeric_parameterPtr profile_length; 
};
class Esquare_u_profile : 
	INHERITANCEDEF(Esquare_u_profile) 
{ 
	CLASSDEF(Esquare_u_profile); 
//// Inherited classes 
	Eopen_profile _open_profile;
	Etoleranced_length_measurePtr width; 
	Etoleranced_length_measurePtr first_radius; 
	Eplane_angle_measurePtr first_angle; 
	Etoleranced_length_measurePtr second_radius; 
	Eplane_angle_measurePtr second_angle; 
};
class Erounded_u_profile : 
	INHERITANCEDEF(Erounded_u_profile) 
{ 
	CLASSDEF(Erounded_u_profile); 
//// Inherited classes 
	Eopen_profile _open_profile;
	Etoleranced_length_measurePtr width; 
};
class Etee_profile : 
	INHERITANCEDEF(Etee_profile) 
{ 
	CLASSDEF(Etee_profile); 
//// Inherited classes 
	Eopen_profile _open_profile;
	Eplane_angle_measurePtr first_angle; 
	Eplane_angle_measurePtr second_angle; 
	Etoleranced_length_measurePtr cross_bar_width; 
	Etoleranced_length_measurePtr cross_bar_depth; 
	Etoleranced_length_measurePtr radius; 
	Etoleranced_length_measurePtr width; 
	Etoleranced_length_measurePtr first_offset; 
	Etoleranced_length_measurePtr second_offset; 
};
class Evee_profile : 
	INHERITANCEDEF(Evee_profile) 
{ 
	CLASSDEF(Evee_profile); 
//// Inherited classes 
	Eopen_profile _open_profile;
	Etoleranced_length_measurePtr profile_radius; 
	Eplane_angle_measurePtr profile_angle; 
	Eplane_angle_measurePtr tilt_angle; 
};
class Epartial_circular_profile : 
	INHERITANCEDEF(Epartial_circular_profile) 
{ 
	CLASSDEF(Epartial_circular_profile); 
//// Inherited classes 
	Eopen_profile _open_profile;
	Etoleranced_length_measurePtr radius; 
	Eplane_angle_measurePtr sweep_angle; 
};
class Egeneral_profile : 
	INHERITANCEDEF(Egeneral_profile) 
{ 
	CLASSDEF(Egeneral_profile); 
//// Inherited classes 
	Eopen_profile _open_profile;
	Ebounded_curvePtr its_profile; 
};
class Eclosed_profile : 
	INHERITANCEDEF(Eclosed_profile) 
{ 
	CLASSDEF(Eclosed_profile); 
//// Inherited classes 
	Eprofile _profile;
};
class Erectangular_closed_profile : 
	INHERITANCEDEF(Erectangular_closed_profile) 
{ 
	CLASSDEF(Erectangular_closed_profile); 
//// Inherited classes 
	Eclosed_profile _closed_profile;
	Etoleranced_length_measurePtr profile_width; 
	Etoleranced_length_measurePtr profile_length; 
};
class Ecircular_closed_profile : 
	INHERITANCEDEF(Ecircular_closed_profile) 
{ 
	CLASSDEF(Ecircular_closed_profile); 
//// Inherited classes 
	Eclosed_profile _closed_profile;
	Etoleranced_length_measurePtr diameter; 
};
class Engon_profile : 
	INHERITANCEDEF(Engon_profile) 
{ 
	CLASSDEF(Engon_profile); 
//// Inherited classes 
	Eclosed_profile _closed_profile;
	Etoleranced_length_measurePtr diameter; 
	EIntegerPtr number_of_sides; 
	EBooleanPtr circumscribed_or_across_flats; 
};
class Egeneral_closed_profile : 
	INHERITANCEDEF(Egeneral_closed_profile) 
{ 
	CLASSDEF(Egeneral_closed_profile); 
//// Inherited classes 
	Eclosed_profile _closed_profile;
	Ebounded_curvePtr closed_profile_shape; 
};
class Etravel_path : 
	INHERITANCEDEF(Etravel_path) 
{ 
	CLASSDEF(Etravel_path); 
//// Inherited classes 
	Eaxis2_placement_3dPtr placement; 
};
class Egeneral_path : 
	INHERITANCEDEF(Egeneral_path) 
{ 
	CLASSDEF(Egeneral_path); 
//// Inherited classes 
	Etravel_path _travel_path;
	Ebounded_curvePtr swept_path; 
};
class Elinear_path : 
	INHERITANCEDEF(Elinear_path) 
{ 
	CLASSDEF(Elinear_path); 
//// Inherited classes 
	Etravel_path _travel_path;
	Etoleranced_length_measurePtr distance; 
	EdirectionPtr its_direction; 
};
class Ecircular_path : 
	INHERITANCEDEF(Ecircular_path) 
{ 
	CLASSDEF(Ecircular_path); 
//// Inherited classes 
	Etravel_path _travel_path;
	Etoleranced_length_measurePtr radius; 
};
class Ecomplete_circular_path : 
	INHERITANCEDEF(Ecomplete_circular_path) 
{ 
	CLASSDEF(Ecomplete_circular_path); 
//// Inherited classes 
	Ecircular_path _circular_path;
};
class Epartial_circular_path : 
	INHERITANCEDEF(Epartial_circular_path) 
{ 
	CLASSDEF(Epartial_circular_path); 
//// Inherited classes 
	Ecircular_path _circular_path;
	Eplane_angle_measurePtr sweep_angle; 
};
class Esurface_texture_parameter : 
	INHERITANCEDEF(Esurface_texture_parameter) 
{ 
	CLASSDEF(Esurface_texture_parameter); 
//// Inherited classes 
	Eparameter_valuePtr its_value; 
	ElabelPtr parameter_name; 
	EidentifierPtr measuring_method; 
	EidentifierPtr parameter_index; 
	EListT<Emachined_surfacePtr> applied_surfaces; 
};
class Emachined_surface : 
	INHERITANCEDEF(Emachined_surface) 
{ 
	CLASSDEF(Emachined_surface); 
//// Inherited classes 
	Emachining_featurePtr its_machining_feature; 
	Ebottom_or_sidePtr surface_element; 
};
class Eexecutable : 
	INHERITANCEDEF(Eexecutable) 
{ 
	CLASSDEF(Eexecutable); 
//// Inherited classes 
	EidentifierPtr its_id; 
};
class Eworkingstep : 
	INHERITANCEDEF(Eworkingstep) 
{ 
	CLASSDEF(Eworkingstep); 
//// Inherited classes 
	Eexecutable _executable;
	Eelementary_surfacePtr its_secplane; 
};
class Emachining_workingstep : 
	INHERITANCEDEF(Emachining_workingstep) 
{ 
	CLASSDEF(Emachining_workingstep); 
//// Inherited classes 
	Eworkingstep _workingstep;
	Emanufacturing_featurePtr its_feature; 
	Emachining_operationPtr its_operation; 
	Ein_process_geometryPtr its_effect; 
};
class Ein_process_geometry : 
	INHERITANCEDEF(Ein_process_geometry) 
{ 
	CLASSDEF(Ein_process_geometry); 
//// Inherited classes 
	Eadvanced_brep_shape_representationPtr as_is; 
	Eadvanced_brep_shape_representationPtr to_be; 
	Eadvanced_brep_shape_representationPtr removal; 
};
class Eoperation : 
	INHERITANCEDEF(Eoperation) 
{ 
	CLASSDEF(Eoperation); 
//// Inherited classes 
	Etoolpath_listPtr its_toolpath; 
	Etool_directionPtr its_tool_direction; 
};
class Erapid_movement : 
	INHERITANCEDEF(Erapid_movement) 
{ 
	CLASSDEF(Erapid_movement); 
//// Inherited classes 
	Eworkingstep _workingstep;
	Eoperation _operation;
};
class Ereturn_home : 
	INHERITANCEDEF(Ereturn_home) 
{ 
	CLASSDEF(Ereturn_home); 
//// Inherited classes 
	Erapid_movement _rapid_movement;
};
class Etouch_probing : 
	INHERITANCEDEF(Etouch_probing) 
{ 
	CLASSDEF(Etouch_probing); 
//// Inherited classes 
	Eworkingstep _workingstep;
	Eoperation _operation;
	Enc_variablePtr measured_offset; 
};
class Eworkpiece_probing : 
	INHERITANCEDEF(Eworkpiece_probing) 
{ 
	CLASSDEF(Eworkpiece_probing); 
//// Inherited classes 
	Etouch_probing _touch_probing;
	Eaxis2_placement_3dPtr start_position; 
	EworkpiecePtr its_workpiece; 
	EdirectionPtr its_direction; 
	Etoleranced_length_measurePtr expected_value; 
	Etouch_probePtr its_probe; 
};
class Eworkpiece_complete_probing : 
	INHERITANCEDEF(Eworkpiece_complete_probing) 
{ 
	CLASSDEF(Eworkpiece_complete_probing); 
//// Inherited classes 
	Etouch_probing _touch_probing;
	EworkpiecePtr its_workpiece; 
	Etoleranced_length_measurePtr probing_distance; 
	Etouch_probePtr its_probe; 
	Eoffset_vectorPtr computed_offset; 
};
class Etouch_probe : 
	INHERITANCEDEF(Etouch_probe) 
{ 
	CLASSDEF(Etouch_probe); 
//// Inherited classes 
	EidentifierPtr its_id; 
};
class Eoffset_vector : 
	INHERITANCEDEF(Eoffset_vector) 
{ 
	CLASSDEF(Eoffset_vector); 
//// Inherited classes 
	EListT<Enc_variablePtr> translate; 
	EListT<Enc_variablePtr> rotate; 
};
class Etool_probing : 
	INHERITANCEDEF(Etool_probing) 
{ 
	CLASSDEF(Etool_probing); 
//// Inherited classes 
	Etouch_probing _touch_probing;
	Ecartesian_pointPtr offset; 
	Elength_measurePtr max_wear; 
	Emachining_toolPtr its_tool; 
};
class Emachining_tool : 
	INHERITANCEDEF(Emachining_tool) 
{ 
	CLASSDEF(Emachining_tool); 
//// Inherited classes 
	ElabelPtr its_id; 
};
class Ecutting_tool : 
	INHERITANCEDEF(Ecutting_tool) 
{ 
	CLASSDEF(Ecutting_tool); 
//// Inherited classes 
	Emachining_tool _machining_tool;
	Etool_bodyPtr its_tool_body; 
	EListT<Ecutting_componentPtr> its_cutting_edge; 
	Elength_measurePtr overall_assembly_length; 
};
class Etool_body : 
	INHERITANCEDEF(Etool_body) 
{ 
	CLASSDEF(Etool_body); 
//// Inherited classes 
};
class Ecutting_component : 
	INHERITANCEDEF(Ecutting_component) 
{ 
	CLASSDEF(Ecutting_component); 
//// Inherited classes 
	Elength_measurePtr tool_offset_length; 
	EmaterialPtr its_material; 
	Ecutting_edge_technological_dataPtr technological_data; 
	Etime_measurePtr expected_tool_life; 
	Emilling_technologyPtr its_technology; 
};
class Ecutting_edge_technological_data : 
	INHERITANCEDEF(Ecutting_edge_technological_data) 
{ 
	CLASSDEF(Ecutting_edge_technological_data); 
//// Inherited classes 
	Eplane_angle_measurePtr cutting_angle; 
	Eplane_angle_measurePtr free_angle; 
	Eplane_angle_measurePtr aux_angle; 
};
class Etool_length_probing : 
	INHERITANCEDEF(Etool_length_probing) 
{ 
	CLASSDEF(Etool_length_probing); 
//// Inherited classes 
	Etool_probing _tool_probing;
};
class Etool_radius_probing : 
	INHERITANCEDEF(Etool_radius_probing) 
{ 
	CLASSDEF(Etool_radius_probing); 
//// Inherited classes 
	Etool_probing _tool_probing;
};
class Enc_function : 
	INHERITANCEDEF(Enc_function) 
{ 
	CLASSDEF(Enc_function); 
//// Inherited classes 
	Eexecutable _executable;
};
class Edisplay_message : 
	INHERITANCEDEF(Edisplay_message) 
{ 
	CLASSDEF(Edisplay_message); 
//// Inherited classes 
	Enc_function _nc_function;
	EtextPtr its_text; 
};
class Eoptional_stop : 
	INHERITANCEDEF(Eoptional_stop) 
{ 
	CLASSDEF(Eoptional_stop); 
//// Inherited classes 
	Enc_function _nc_function;
};
class Eprogram_stop : 
	INHERITANCEDEF(Eprogram_stop) 
{ 
	CLASSDEF(Eprogram_stop); 
//// Inherited classes 
	Enc_function _nc_function;
};
class Eset_mark : 
	INHERITANCEDEF(Eset_mark) 
{ 
	CLASSDEF(Eset_mark); 
//// Inherited classes 
	Enc_function _nc_function;
};
class Ewait_for_mark : 
	INHERITANCEDEF(Ewait_for_mark) 
{ 
	CLASSDEF(Ewait_for_mark); 
//// Inherited classes 
	Enc_function _nc_function;
	EchannelPtr its_channel; 
};
class Eprogram_structure : 
	INHERITANCEDEF(Eprogram_structure) 
{ 
	CLASSDEF(Eprogram_structure); 
//// Inherited classes 
	Eexecutable _executable;
};
class Eworkplan : 
	INHERITANCEDEF(Eworkplan) 
{ 
	CLASSDEF(Eworkplan); 
//// Inherited classes 
	Eprogram_structure _program_structure;
	EListT<EexecutablePtr> its_elements; 
	EchannelPtr its_channel; 
	EsetupPtr its_setup; 
	Ein_process_geometryPtr its_effect; 
};
class Echannel : 
	INHERITANCEDEF(Echannel) 
{ 
	CLASSDEF(Echannel); 
//// Inherited classes 
	EidentifierPtr its_id; 
};
class Esetup : 
	INHERITANCEDEF(Esetup) 
{ 
	CLASSDEF(Esetup); 
//// Inherited classes 
	EidentifierPtr its_id; 
	Eaxis2_placement_3dPtr its_origin; 
	Eelementary_surfacePtr its_secplane; 
	EListT<Eworkpiece_setupPtr> its_workpiece_setup; 
};
class Eworkpiece_setup : 
	INHERITANCEDEF(Eworkpiece_setup) 
{ 
	CLASSDEF(Eworkpiece_setup); 
//// Inherited classes 
	EworkpiecePtr its_workpiece; 
	Eaxis2_placement_3dPtr its_origin; 
	Eoffset_vectorPtr its_offset; 
	Erestricted_area_selectPtr its_restricted_area; 
	EListT<Esetup_instructionPtr> its_instructions; 
};
class Esetup_instruction : 
	INHERITANCEDEF(Esetup_instruction) 
{ 
	CLASSDEF(Esetup_instruction); 
//// Inherited classes 
	EtextPtr description; 
	EidentifierPtr external_document; 
};
class Eparallel : 
	INHERITANCEDEF(Eparallel) 
{ 
	CLASSDEF(Eparallel); 
//// Inherited classes 
	Eprogram_structure _program_structure;
	EListT<EexecutablePtr> branches; 
};
class Enon_sequential : 
	INHERITANCEDEF(Enon_sequential) 
{ 
	CLASSDEF(Enon_sequential); 
//// Inherited classes 
	Eprogram_structure _program_structure;
	EListT<EexecutablePtr> its_elements; 
};
class Eselective : 
	INHERITANCEDEF(Eselective) 
{ 
	CLASSDEF(Eselective); 
//// Inherited classes 
	Eprogram_structure _program_structure;
	EListT<EexecutablePtr> its_elements; 
};
class Eif_statement : 
	INHERITANCEDEF(Eif_statement) 
{ 
	CLASSDEF(Eif_statement); 
//// Inherited classes 
	Eprogram_structure _program_structure;
	Eboolean_expressionPtr condition; 
	EexecutablePtr true_branch; 
	EexecutablePtr false_branch; 
};
class Ewhile_statement : 
	INHERITANCEDEF(Ewhile_statement) 
{ 
	CLASSDEF(Ewhile_statement); 
//// Inherited classes 
	Eprogram_structure _program_structure;
	Eboolean_expressionPtr condition; 
	EexecutablePtr body; 
};
class Eassignment : 
	INHERITANCEDEF(Eassignment) 
{ 
	CLASSDEF(Eassignment); 
//// Inherited classes 
	Eprogram_structure _program_structure;
	Enc_variablePtr its_lvalue; 
	ErvaluePtr its_rvalue; 
};
class Enc_variable : 
	INHERITANCEDEF(Enc_variable) 
{ 
	CLASSDEF(Enc_variable); 
//// Inherited classes 
	ElabelPtr its_name; 
	EnumberPtr initial_value; 
};
class Enc_constant : 
	INHERITANCEDEF(Enc_constant) 
{ 
	CLASSDEF(Enc_constant); 
//// Inherited classes 
	ElabelPtr its_name; 
	EnumberPtr its_value; 
};
class Eboolean_expression : 
	INHERITANCEDEF(Eboolean_expression) 
{ 
	CLASSDEF(Eboolean_expression); 
//// Inherited classes 
};
class Eunary_boolean_expression : 
	INHERITANCEDEF(Eunary_boolean_expression) 
{ 
	CLASSDEF(Eunary_boolean_expression); 
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	Eboolean_expressionPtr operand; 
};
class Enot_expression : 
	INHERITANCEDEF(Enot_expression) 
{ 
	CLASSDEF(Enot_expression); 
//// Inherited classes 
	Eunary_boolean_expression _unary_boolean_expression;
};
class Ebinary_boolean_expression : 
	INHERITANCEDEF(Ebinary_boolean_expression) 
{ 
	CLASSDEF(Ebinary_boolean_expression); 
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	Eboolean_expressionPtr operand1; 
	Eboolean_expressionPtr operand2; 
};
class Exor_expression : 
	INHERITANCEDEF(Exor_expression) 
{ 
	CLASSDEF(Exor_expression); 
//// Inherited classes 
	Ebinary_boolean_expression _binary_boolean_expression;
};
class Emultiple_arity_boolean_expression : 
	INHERITANCEDEF(Emultiple_arity_boolean_expression) 
{ 
	CLASSDEF(Emultiple_arity_boolean_expression); 
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	EListT<Eboolean_expressionPtr> operands; 
};
class Eand_expression : 
	INHERITANCEDEF(Eand_expression) 
{ 
	CLASSDEF(Eand_expression); 
//// Inherited classes 
	Emultiple_arity_boolean_expression _multiple_arity_boolean_expression;
};
class Eor_expression : 
	INHERITANCEDEF(Eor_expression) 
{ 
	CLASSDEF(Eor_expression); 
//// Inherited classes 
	Emultiple_arity_boolean_expression _multiple_arity_boolean_expression;
};
class Ecomparison_expression : 
	INHERITANCEDEF(Ecomparison_expression) 
{ 
	CLASSDEF(Ecomparison_expression); 
//// Inherited classes 
	Eboolean_expression _boolean_expression;
	Enc_variablePtr operand1; 
	ErvaluePtr operand2; 
};
class Ecomparison_equal : 
	INHERITANCEDEF(Ecomparison_equal) 
{ 
	CLASSDEF(Ecomparison_equal); 
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
};
class Ecomparison_not_equal : 
	INHERITANCEDEF(Ecomparison_not_equal) 
{ 
	CLASSDEF(Ecomparison_not_equal); 
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
};
class Ecomparison_greater : 
	INHERITANCEDEF(Ecomparison_greater) 
{ 
	CLASSDEF(Ecomparison_greater); 
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
};
class Ecomparison_greater_equal : 
	INHERITANCEDEF(Ecomparison_greater_equal) 
{ 
	CLASSDEF(Ecomparison_greater_equal); 
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
};
class Ecomparison_less : 
	INHERITANCEDEF(Ecomparison_less) 
{ 
	CLASSDEF(Ecomparison_less); 
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
};
class Ecomparison_less_equal : 
	INHERITANCEDEF(Ecomparison_less_equal) 
{ 
	CLASSDEF(Ecomparison_less_equal); 
//// Inherited classes 
	Ecomparison_expression _comparison_expression;
};
class Etoolpath_list : 
	INHERITANCEDEF(Etoolpath_list) 
{ 
	CLASSDEF(Etoolpath_list); 
//// Inherited classes 
	EListT<EtoolpathPtr> its_list; 
};
class Etool_direction : 
	INHERITANCEDEF(Etool_direction) 
{ 
	CLASSDEF(Etool_direction); 
//// Inherited classes 
};
class Etwo_axes : 
	INHERITANCEDEF(Etwo_axes) 
{ 
	CLASSDEF(Etwo_axes); 
//// Inherited classes 
	Etool_direction _tool_direction;
};
class Ethree_axes : 
	INHERITANCEDEF(Ethree_axes) 
{ 
	CLASSDEF(Ethree_axes); 
//// Inherited classes 
	Etool_direction _tool_direction;
};
class Emachining_operation : 
	INHERITANCEDEF(Emachining_operation) 
{ 
	CLASSDEF(Emachining_operation); 
//// Inherited classes 
	Eoperation _operation;
	EidentifierPtr its_id; 
	Elength_measurePtr retract_plane; 
	Ecartesian_pointPtr start_point; 
	Emachining_toolPtr its_tool; 
	EtechnologyPtr its_technology; 
	Emachine_functionsPtr its_machine_functions; 
};
class Etechnology : 
	INHERITANCEDEF(Etechnology) 
{ 
	CLASSDEF(Etechnology); 
//// Inherited classes 
	Espeed_measurePtr feedrate; 
	Etool_reference_pointPtr feedrate_reference; 
};
class Emachine_functions : 
	INHERITANCEDEF(Emachine_functions) 
{ 
	CLASSDEF(Emachine_functions); 
//// Inherited classes 
};
class Etoolpath : 
	INHERITANCEDEF(Etoolpath) 
{ 
	CLASSDEF(Etoolpath); 
//// Inherited classes 
	EBooleanPtr its_priority; 
	Etoolpath_typePtr its_type; 
	Etoolpath_speedprofilePtr its_speed; 
	EtechnologyPtr its_technology; 
	Emachine_functionsPtr its_machine_functions; 
};
class Etoolpath_speed : 
	INHERITANCEDEF(Etoolpath_speed) 
{ 
	CLASSDEF(Etoolpath_speed); 
//// Inherited classes 
	Eb_spline_curvePtr speed; 
};
class Efeedstop : 
	INHERITANCEDEF(Efeedstop) 
{ 
	CLASSDEF(Efeedstop); 
//// Inherited classes 
	Etoolpath _toolpath;
	Etime_measurePtr dwell; 
};
class Etrajectory : 
	INHERITANCEDEF(Etrajectory) 
{ 
	CLASSDEF(Etrajectory); 
//// Inherited classes 
	Etoolpath _toolpath;
	EBooleanPtr its_direction; 
};
class Ecutter_location_trajectory : 
	INHERITANCEDEF(Ecutter_location_trajectory) 
{ 
	CLASSDEF(Ecutter_location_trajectory); 
//// Inherited classes 
	Etrajectory _trajectory;
	Ebounded_curvePtr basiccurve; 
	Ebounded_curvePtr its_toolaxis; 
	Ebounded_curvePtr surface_normal; 
};
class Ecutter_contact_trajectory : 
	INHERITANCEDEF(Ecutter_contact_trajectory) 
{ 
	CLASSDEF(Ecutter_contact_trajectory); 
//// Inherited classes 
	Etrajectory _trajectory;
	Ecurve_with_surface_normalPtr basiccurve; 
	Ebounded_curvePtr its_toolaxis; 
	Econtact_typePtr its_contact_type; 
};
class Ecurve_with_normal_vector : 
	INHERITANCEDEF(Ecurve_with_normal_vector) 
{ 
	CLASSDEF(Ecurve_with_normal_vector); 
//// Inherited classes 
	Ebounded_curvePtr basiccurve; 
	Ebounded_curvePtr surface_normal; 
};
class Eaxis_trajectory : 
	INHERITANCEDEF(Eaxis_trajectory) 
{ 
	CLASSDEF(Eaxis_trajectory); 
//// Inherited classes 
	Etrajectory _trajectory;
	EListT<EidentifierPtr> axis_list; 
	EListT<Ebounded_curvePtr> commands; 
};
class Eparameterised_path : 
	INHERITANCEDEF(Eparameterised_path) 
{ 
	CLASSDEF(Eparameterised_path); 
//// Inherited classes 
	Etoolpath _toolpath;
};
class Econnector : 
	INHERITANCEDEF(Econnector) 
{ 
	CLASSDEF(Econnector); 
//// Inherited classes 
	Eparameterised_path _parameterised_path;
};
class Econnect_secplane : 
	INHERITANCEDEF(Econnect_secplane) 
{ 
	CLASSDEF(Econnect_secplane); 
//// Inherited classes 
	Econnector _connector;
	EdirectionPtr up_dir; 
	EdirectionPtr down_dir; 
};
class Econnect_direct : 
	INHERITANCEDEF(Econnect_direct) 
{ 
	CLASSDEF(Econnect_direct); 
//// Inherited classes 
	Econnector _connector;
};
class Eapproach_lift_path : 
	INHERITANCEDEF(Eapproach_lift_path) 
{ 
	CLASSDEF(Eapproach_lift_path); 
//// Inherited classes 
	Eparameterised_path _parameterised_path;
	Ecartesian_pointPtr fix_point; 
	EdirectionPtr fix_point_dir; 
};
class Eap_lift_path_angle : 
	INHERITANCEDEF(Eap_lift_path_angle) 
{ 
	CLASSDEF(Eap_lift_path_angle); 
//// Inherited classes 
	Eapproach_lift_path _approach_lift_path;
	Eplane_angle_measurePtr angle; 
	Epositive_length_measurePtr benddist; 
};
class Eap_lift_path_tangent : 
	INHERITANCEDEF(Eap_lift_path_tangent) 
{ 
	CLASSDEF(Eap_lift_path_tangent); 
//// Inherited classes 
	Eapproach_lift_path _approach_lift_path;
	Epositive_length_measurePtr radius; 
};
class Emilling_cutting_tool : 
	INHERITANCEDEF(Emilling_cutting_tool) 
{ 
	CLASSDEF(Emilling_cutting_tool); 
//// Inherited classes 
	Ecutting_tool _cutting_tool;
	EdirectionPtr direction_for_spindle_orientation; 
	Elength_measurePtr tool_holder_diameter_for_spindle_orientation; 
};
class Emilling_tool_body : 
	INHERITANCEDEF(Emilling_tool_body) 
{ 
	CLASSDEF(Emilling_tool_body); 
//// Inherited classes 
	Etool_body _tool_body;
	Emilling_tool_dimensionPtr dimension; 
	EIntegerPtr number_of_teeth; 
	EhandPtr hand_of_cut; 
	EBooleanPtr coolant_through_tool; 
	Elength_measurePtr pilot_length; 
};
class Emilling_tool_dimension : 
	INHERITANCEDEF(Emilling_tool_dimension) 
{ 
	CLASSDEF(Emilling_tool_dimension); 
//// Inherited classes 
	Elength_measurePtr diameter; 
	Eplane_angle_measurePtr tool_top_angle; 
	Eplane_angle_measurePtr tool_circumference_angle; 
	Elength_measurePtr cutting_edge_length; 
	Elength_measurePtr edge_radius; 
	Elength_measurePtr edge_center_vertical; 
	Elength_measurePtr edge_center_horizontal; 
};
class Ecenter_drill : 
	INHERITANCEDEF(Ecenter_drill) 
{ 
	CLASSDEF(Ecenter_drill); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Ecountersink : 
	INHERITANCEDEF(Ecountersink) 
{ 
	CLASSDEF(Ecountersink); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	Elength_measurePtr countersink_radius; 
};
class Ebackside_countersink : 
	INHERITANCEDEF(Ebackside_countersink) 
{ 
	CLASSDEF(Ebackside_countersink); 
//// Inherited classes 
	Ecountersink _countersink;
};
class Edrill : 
	INHERITANCEDEF(Edrill) 
{ 
	CLASSDEF(Edrill); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Etwist_drill : 
	INHERITANCEDEF(Etwist_drill) 
{ 
	CLASSDEF(Etwist_drill); 
//// Inherited classes 
	Edrill _drill;
};
class Etapered_drill : 
	INHERITANCEDEF(Etapered_drill) 
{ 
	CLASSDEF(Etapered_drill); 
//// Inherited classes 
	Etwist_drill _twist_drill;
	Eplane_angle_measurePtr taper_angle; 
};
class Espade_drill : 
	INHERITANCEDEF(Espade_drill) 
{ 
	CLASSDEF(Espade_drill); 
//// Inherited classes 
	Edrill _drill;
};
class Emilling_cutter : 
	INHERITANCEDEF(Emilling_cutter) 
{ 
	CLASSDEF(Emilling_cutter); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Efacemill : 
	INHERITANCEDEF(Efacemill) 
{ 
	CLASSDEF(Efacemill); 
//// Inherited classes 
	Emilling_cutter _milling_cutter;
};
class Eendmill : 
	INHERITANCEDEF(Eendmill) 
{ 
	CLASSDEF(Eendmill); 
//// Inherited classes 
	Emilling_cutter _milling_cutter;
};
class Etapered_endmill : 
	INHERITANCEDEF(Etapered_endmill) 
{ 
	CLASSDEF(Etapered_endmill); 
//// Inherited classes 
	Eendmill _endmill;
	Eplane_angle_measurePtr taper_angle; 
};
class Eball_endmill : 
	INHERITANCEDEF(Eball_endmill) 
{ 
	CLASSDEF(Eball_endmill); 
//// Inherited classes 
	Eendmill _endmill;
};
class Ebullnose_endmill : 
	INHERITANCEDEF(Ebullnose_endmill) 
{ 
	CLASSDEF(Ebullnose_endmill); 
//// Inherited classes 
	Eendmill _endmill;
};
class Et_slot_mill : 
	INHERITANCEDEF(Et_slot_mill) 
{ 
	CLASSDEF(Et_slot_mill); 
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	Elength_measurePtr cutting_thickness; 
};
class Edovetail_mill : 
	INHERITANCEDEF(Edovetail_mill) 
{ 
	CLASSDEF(Edovetail_mill); 
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	Eplane_angle_measurePtr included_angle; 
};
class Ewoodruff_keyseat_mill : 
	INHERITANCEDEF(Ewoodruff_keyseat_mill) 
{ 
	CLASSDEF(Ewoodruff_keyseat_mill); 
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	Elength_measurePtr cutter_width; 
};
class Eside_mill : 
	INHERITANCEDEF(Eside_mill) 
{ 
	CLASSDEF(Eside_mill); 
//// Inherited classes 
	Emilling_cutter _milling_cutter;
	Elength_measurePtr cutter_width; 
};
class Ethread_mill : 
	INHERITANCEDEF(Ethread_mill) 
{ 
	CLASSDEF(Ethread_mill); 
//// Inherited classes 
	Emilling_cutter _milling_cutter;
};
class Etap : 
	INHERITANCEDEF(Etap) 
{ 
	CLASSDEF(Etap); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Etapered_tap : 
	INHERITANCEDEF(Etapered_tap) 
{ 
	CLASSDEF(Etapered_tap); 
//// Inherited classes 
	Etap _tap;
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_tap : 
	INHERITANCEDEF(Ecombined_drill_and_tap) 
{ 
	CLASSDEF(Ecombined_drill_and_tap); 
//// Inherited classes 
	Etap _tap;
	Elength_measurePtr drill_length; 
};
class Ethreading_tool : 
	INHERITANCEDEF(Ethreading_tool) 
{ 
	CLASSDEF(Ethreading_tool); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Ecounterbore : 
	INHERITANCEDEF(Ecounterbore) 
{ 
	CLASSDEF(Ecounterbore); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Ebackside_counterbore : 
	INHERITANCEDEF(Ebackside_counterbore) 
{ 
	CLASSDEF(Ebackside_counterbore); 
//// Inherited classes 
	Ecounterbore _counterbore;
};
class Ereamer : 
	INHERITANCEDEF(Ereamer) 
{ 
	CLASSDEF(Ereamer); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Etapered_reamer : 
	INHERITANCEDEF(Etapered_reamer) 
{ 
	CLASSDEF(Etapered_reamer); 
//// Inherited classes 
	Ereamer _reamer;
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_reamer : 
	INHERITANCEDEF(Ecombined_drill_and_reamer) 
{ 
	CLASSDEF(Ecombined_drill_and_reamer); 
//// Inherited classes 
	Ereamer _reamer;
	Elength_measurePtr drill_length; 
};
class Eboring_tool : 
	INHERITANCEDEF(Eboring_tool) 
{ 
	CLASSDEF(Eboring_tool); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
};
class Euser_defined_tool : 
	INHERITANCEDEF(Euser_defined_tool) 
{ 
	CLASSDEF(Euser_defined_tool); 
//// Inherited classes 
	Emilling_tool_body _milling_tool_body;
	ElabelPtr identifier; 
};
class Eexchange_pallet : 
	INHERITANCEDEF(Eexchange_pallet) 
{ 
	CLASSDEF(Eexchange_pallet); 
//// Inherited classes 
	Enc_function _nc_function;
};
class Eindex_pallet : 
	INHERITANCEDEF(Eindex_pallet) 
{ 
	CLASSDEF(Eindex_pallet); 
//// Inherited classes 
	Enc_function _nc_function;
	EIntegerPtr its_index; 
};
class Eindex_table : 
	INHERITANCEDEF(Eindex_table) 
{ 
	CLASSDEF(Eindex_table); 
//// Inherited classes 
	Enc_function _nc_function;
	EIntegerPtr its_index; 
};
class Eload_tool : 
	INHERITANCEDEF(Eload_tool) 
{ 
	CLASSDEF(Eload_tool); 
//// Inherited classes 
	Enc_function _nc_function;
	Emachining_toolPtr its_tool; 
};
class Eunload_tool : 
	INHERITANCEDEF(Eunload_tool) 
{ 
	CLASSDEF(Eunload_tool); 
//// Inherited classes 
	Enc_function _nc_function;
	Emachining_toolPtr its_tool; 
};
class Etool_direction_for_milling : 
	INHERITANCEDEF(Etool_direction_for_milling) 
{ 
	CLASSDEF(Etool_direction_for_milling); 
//// Inherited classes 
	Etool_direction _tool_direction;
};
class Ethree_axes_tilted_tool : 
	INHERITANCEDEF(Ethree_axes_tilted_tool) 
{ 
	CLASSDEF(Ethree_axes_tilted_tool); 
//// Inherited classes 
	Etool_direction_for_milling _tool_direction_for_milling;
	EdirectionPtr tool_direction; 
};
class Efive_axes_var_tilt_yaw : 
	INHERITANCEDEF(Efive_axes_var_tilt_yaw) 
{ 
	CLASSDEF(Efive_axes_var_tilt_yaw); 
//// Inherited classes 
	Etool_direction_for_milling _tool_direction_for_milling;
};
class Efive_axes_const_tilt_yaw : 
	INHERITANCEDEF(Efive_axes_const_tilt_yaw) 
{ 
	CLASSDEF(Efive_axes_const_tilt_yaw); 
//// Inherited classes 
	Etool_direction_for_milling _tool_direction_for_milling;
	Eplane_angle_measurePtr tilt_angle; 
	Eplane_angle_measurePtr yaw_angle; 
};
class Emilling_machining_operation : 
	INHERITANCEDEF(Emilling_machining_operation) 
{ 
	CLASSDEF(Emilling_machining_operation); 
//// Inherited classes 
	Emachining_operation _machining_operation;
	Elength_measurePtr overcut_length; 
};
class Emilling_technology : 
	INHERITANCEDEF(Emilling_technology) 
{ 
	CLASSDEF(Emilling_technology); 
//// Inherited classes 
	Etechnology _technology;
	Espeed_measurePtr cutspeed; 
	Erot_speed_measurePtr spindle; 
	Elength_measurePtr feedrate_per_tooth; 
	EBooleanPtr synchronize_spindle_with_feed; 
	EBooleanPtr inhibit_feedrate_override; 
	EBooleanPtr inhibit_spindle_override; 
	Eadaptive_controlPtr its_adaptive_control; 
};
class Eadaptive_control : 
	INHERITANCEDEF(Eadaptive_control) 
{ 
	CLASSDEF(Eadaptive_control); 
//// Inherited classes 
};
class Emilling_machine_functions : 
	INHERITANCEDEF(Emilling_machine_functions) 
{ 
	CLASSDEF(Emilling_machine_functions); 
//// Inherited classes 
	Emachine_functions _machine_functions;
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
class Eprocess_model_list : 
	INHERITANCEDEF(Eprocess_model_list) 
{ 
	CLASSDEF(Eprocess_model_list); 
//// Inherited classes 
	EListT<Eprocess_modelPtr> its_list; 
};
class Eprocess_model : 
	INHERITANCEDEF(Eprocess_model) 
{ 
	CLASSDEF(Eprocess_model); 
//// Inherited classes 
	ElabelPtr ini_data_file; 
	ElabelPtr its_type; 
};
class Emilling_type_operation : 
	INHERITANCEDEF(Emilling_type_operation) 
{ 
	CLASSDEF(Emilling_type_operation); 
//// Inherited classes 
	Emilling_machining_operation _milling_machining_operation;
	Eapproach_retract_strategyPtr approach; 
	Eapproach_retract_strategyPtr retract; 
};
class Eapproach_retract_strategy : 
	INHERITANCEDEF(Eapproach_retract_strategy) 
{ 
	CLASSDEF(Eapproach_retract_strategy); 
//// Inherited classes 
	EdirectionPtr tool_orientation; 
};
class Eplunge_strategy : 
	INHERITANCEDEF(Eplunge_strategy) 
{ 
	CLASSDEF(Eplunge_strategy); 
//// Inherited classes 
	Eapproach_retract_strategy _approach_retract_strategy;
};
class Eplunge_toolaxis : 
	INHERITANCEDEF(Eplunge_toolaxis) 
{ 
	CLASSDEF(Eplunge_toolaxis); 
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
};
class Eplunge_ramp : 
	INHERITANCEDEF(Eplunge_ramp) 
{ 
	CLASSDEF(Eplunge_ramp); 
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
	Eplane_angle_measurePtr angle; 
};
class Eplunge_helix : 
	INHERITANCEDEF(Eplunge_helix) 
{ 
	CLASSDEF(Eplunge_helix); 
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
	Elength_measurePtr radius; 
	Eplane_angle_measurePtr angle; 
};
class Eplunge_zigzag : 
	INHERITANCEDEF(Eplunge_zigzag) 
{ 
	CLASSDEF(Eplunge_zigzag); 
//// Inherited classes 
	Eplunge_strategy _plunge_strategy;
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr width; 
};
class Eair_strategy : 
	INHERITANCEDEF(Eair_strategy) 
{ 
	CLASSDEF(Eair_strategy); 
//// Inherited classes 
	Eapproach_retract_strategy _approach_retract_strategy;
};
class Eap_retract_angle : 
	INHERITANCEDEF(Eap_retract_angle) 
{ 
	CLASSDEF(Eap_retract_angle); 
//// Inherited classes 
	Eair_strategy _air_strategy;
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr travel_length; 
};
class Eap_retract_tangent : 
	INHERITANCEDEF(Eap_retract_tangent) 
{ 
	CLASSDEF(Eap_retract_tangent); 
//// Inherited classes 
	Eair_strategy _air_strategy;
	Elength_measurePtr radius; 
};
class Ealong_path : 
	INHERITANCEDEF(Ealong_path) 
{ 
	CLASSDEF(Ealong_path); 
//// Inherited classes 
	Eapproach_retract_strategy _approach_retract_strategy;
	Etoolpath_listPtr path; 
};
class Efreeform_operation : 
	INHERITANCEDEF(Efreeform_operation) 
{ 
	CLASSDEF(Efreeform_operation); 
//// Inherited classes 
	Emilling_type_operation _milling_type_operation;
	Efreeform_strategyPtr its_machining_strategy; 
};
class Efreeform_strategy : 
	INHERITANCEDEF(Efreeform_strategy) 
{ 
	CLASSDEF(Efreeform_strategy); 
//// Inherited classes 
	Epathmode_typePtr pathmode; 
	Ecutmode_typePtr cutmode; 
	EtolerancesPtr its_milling_tolerances; 
	Elength_measurePtr stepover; 
};
class Etolerances : 
	INHERITANCEDEF(Etolerances) 
{ 
	CLASSDEF(Etolerances); 
//// Inherited classes 
	Elength_measurePtr chordal_tolerance; 
	Elength_measurePtr scallop_height; 
};
class Euv_strategy : 
	INHERITANCEDEF(Euv_strategy) 
{ 
	CLASSDEF(Euv_strategy); 
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	EdirectionPtr forward_direction; 
	EdirectionPtr sideward_direction; 
};
class Eplane_cc_strategy : 
	INHERITANCEDEF(Eplane_cc_strategy) 
{ 
	CLASSDEF(Eplane_cc_strategy); 
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	EdirectionPtr its_plane_normal; 
};
class Eplane_cl_strategy : 
	INHERITANCEDEF(Eplane_cl_strategy) 
{ 
	CLASSDEF(Eplane_cl_strategy); 
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	EdirectionPtr its_plane_normal; 
};
class Eleading_line_strategy : 
	INHERITANCEDEF(Eleading_line_strategy) 
{ 
	CLASSDEF(Eleading_line_strategy); 
//// Inherited classes 
	Efreeform_strategy _freeform_strategy;
	Ebounded_curvePtr its_line; 
};
class Etwo5d_milling_operation : 
	INHERITANCEDEF(Etwo5d_milling_operation) 
{ 
	CLASSDEF(Etwo5d_milling_operation); 
//// Inherited classes 
	Emilling_type_operation _milling_type_operation;
	Etwo5d_milling_strategyPtr its_machining_strategy; 
};
class Etwo5d_milling_strategy : 
	INHERITANCEDEF(Etwo5d_milling_strategy) 
{ 
	CLASSDEF(Etwo5d_milling_strategy); 
//// Inherited classes 
	Epositive_ratio_measurePtr overlap; 
	EBooleanPtr allow_multiple_passes; 
};
class Eunidirectional : 
	INHERITANCEDEF(Eunidirectional) 
{ 
	CLASSDEF(Eunidirectional); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	EdirectionPtr feed_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional : 
	INHERITANCEDEF(Ebidirectional) 
{ 
	CLASSDEF(Ebidirectional); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Estroke_connection_strategyPtr its_stroke_connection_strategy; 
};
class Econtour_parallel : 
	INHERITANCEDEF(Econtour_parallel) 
{ 
	CLASSDEF(Econtour_parallel); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional_contour : 
	INHERITANCEDEF(Ebidirectional_contour) 
{ 
	CLASSDEF(Ebidirectional_contour); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_bidirectional : 
	INHERITANCEDEF(Econtour_bidirectional) 
{ 
	CLASSDEF(Econtour_bidirectional); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_spiral : 
	INHERITANCEDEF(Econtour_spiral) 
{ 
	CLASSDEF(Econtour_spiral); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ecenter_milling : 
	INHERITANCEDEF(Ecenter_milling) 
{ 
	CLASSDEF(Ecenter_milling); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
};
class Eexplicit : 
	INHERITANCEDEF(Eexplicit) 
{ 
	CLASSDEF(Eexplicit); 
//// Inherited classes 
	Etwo5d_milling_strategy _two5d_milling_strategy;
};
class Eplane_milling : 
	INHERITANCEDEF(Eplane_milling) 
{ 
	CLASSDEF(Eplane_milling); 
//// Inherited classes 
	Etwo5d_milling_operation _two5d_milling_operation;
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr allowance_bottom; 
};
class Eplane_rough_milling : 
	INHERITANCEDEF(Eplane_rough_milling) 
{ 
	CLASSDEF(Eplane_rough_milling); 
//// Inherited classes 
	Eplane_milling _plane_milling;
};
class Eplane_finish_milling : 
	INHERITANCEDEF(Eplane_finish_milling) 
{ 
	CLASSDEF(Eplane_finish_milling); 
//// Inherited classes 
	Eplane_milling _plane_milling;
};
class Eside_milling : 
	INHERITANCEDEF(Eside_milling) 
{ 
	CLASSDEF(Eside_milling); 
//// Inherited classes 
	Etwo5d_milling_operation _two5d_milling_operation;
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
};
class Eside_rough_milling : 
	INHERITANCEDEF(Eside_rough_milling) 
{ 
	CLASSDEF(Eside_rough_milling); 
//// Inherited classes 
	Eside_milling _side_milling;
};
class Eside_finish_milling : 
	INHERITANCEDEF(Eside_finish_milling) 
{ 
	CLASSDEF(Eside_finish_milling); 
//// Inherited classes 
	Eside_milling _side_milling;
};
class Ebottom_and_side_milling : 
	INHERITANCEDEF(Ebottom_and_side_milling) 
{ 
	CLASSDEF(Ebottom_and_side_milling); 
//// Inherited classes 
	Etwo5d_milling_operation _two5d_milling_operation;
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
	Elength_measurePtr allowance_bottom; 
};
class Ebottom_and_side_rough_milling : 
	INHERITANCEDEF(Ebottom_and_side_rough_milling) 
{ 
	CLASSDEF(Ebottom_and_side_rough_milling); 
//// Inherited classes 
	Ebottom_and_side_milling _bottom_and_side_milling;
};
class Ebottom_and_side_finish_milling : 
	INHERITANCEDEF(Ebottom_and_side_finish_milling) 
{ 
	CLASSDEF(Ebottom_and_side_finish_milling); 
//// Inherited classes 
	Ebottom_and_side_milling _bottom_and_side_milling;
};
class Edrilling_type_operation : 
	INHERITANCEDEF(Edrilling_type_operation) 
{ 
	CLASSDEF(Edrilling_type_operation); 
//// Inherited classes 
	Emilling_machining_operation _milling_machining_operation;
	Elength_measurePtr cutting_depth; 
	Elength_measurePtr previous_diameter; 
	Etime_measurePtr dwell_time_bottom; 
	Epositive_ratio_measurePtr feed_on_retract; 
	Edrilling_type_strategyPtr its_machining_strategy; 
};
class Edrilling_type_strategy : 
	INHERITANCEDEF(Edrilling_type_strategy) 
{ 
	CLASSDEF(Edrilling_type_strategy); 
//// Inherited classes 
	Epositive_ratio_measurePtr reduced_cut_at_start; 
	Epositive_ratio_measurePtr reduced_feed_at_start; 
	Elength_measurePtr depth_of_start; 
	Epositive_ratio_measurePtr reduced_cut_at_end; 
	Epositive_ratio_measurePtr reduced_feed_at_end; 
	Elength_measurePtr depth_of_end; 
};
class Edrilling_operation : 
	INHERITANCEDEF(Edrilling_operation) 
{ 
	CLASSDEF(Edrilling_operation); 
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
};
class Edrilling : 
	INHERITANCEDEF(Edrilling) 
{ 
	CLASSDEF(Edrilling); 
//// Inherited classes 
	Edrilling_operation _drilling_operation;
};
class Ecenter_drilling : 
	INHERITANCEDEF(Ecenter_drilling) 
{ 
	CLASSDEF(Ecenter_drilling); 
//// Inherited classes 
	Edrilling_operation _drilling_operation;
};
class Ecounter_sinking : 
	INHERITANCEDEF(Ecounter_sinking) 
{ 
	CLASSDEF(Ecounter_sinking); 
//// Inherited classes 
	Edrilling_operation _drilling_operation;
};
class Emultistep_drilling : 
	INHERITANCEDEF(Emultistep_drilling) 
{ 
	CLASSDEF(Emultistep_drilling); 
//// Inherited classes 
	Edrilling_operation _drilling_operation;
	Elength_measurePtr retract_distance; 
	Elength_measurePtr first_depth; 
	Elength_measurePtr depth_of_step; 
	Etime_measurePtr dwell_time_step; 
};
class Eboring_operation : 
	INHERITANCEDEF(Eboring_operation) 
{ 
	CLASSDEF(Eboring_operation); 
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	EBooleanPtr spindle_stop_at_bottom; 
	Elength_measurePtr depth_of_testcut; 
	Ecartesian_pointPtr waiting_position; 
};
class Eboring : 
	INHERITANCEDEF(Eboring) 
{ 
	CLASSDEF(Eboring); 
//// Inherited classes 
	Eboring_operation _boring_operation;
};
class Ereaming : 
	INHERITANCEDEF(Ereaming) 
{ 
	CLASSDEF(Ereaming); 
//// Inherited classes 
	Eboring_operation _boring_operation;
};
class Eback_boring : 
	INHERITANCEDEF(Eback_boring) 
{ 
	CLASSDEF(Eback_boring); 
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
};
class Etapping : 
	INHERITANCEDEF(Etapping) 
{ 
	CLASSDEF(Etapping); 
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	EBooleanPtr compensation_chuck; 
};
class Ethread_drilling : 
	INHERITANCEDEF(Ethread_drilling) 
{ 
	CLASSDEF(Ethread_drilling); 
//// Inherited classes 
	Edrilling_type_operation _drilling_type_operation;
	EBooleanPtr helical_movement_on_forward; 
};
} /* End namespace Express*/
