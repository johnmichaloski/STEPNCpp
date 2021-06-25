//
//
//
#pragma once

#include "ExpressUtils.h"
#include "machining_schemaSchemaDeclarations.h"

#include "milling_schemaSchemaDeclarations.h"

namespace Express{
extern CStringVector GetAllmilling_schemaEntities();
class Emilling_cutting_tool :
	public  Ecutting_tool
{
public:
	CLASSDEF(Emilling_cutting_tool); 
	EdirectionPtr direction_for_spindle_orientation; 
	Elength_measurePtr tool_holder_diameter_for_spindle_orientation; 
};
class Emilling_tool_body :
	public  Etool_body
{
public:
	CLASSDEF(Emilling_tool_body); 
	Emilling_tool_dimensionPtr dimension; 
	EIntegerPtr number_of_teeth; 
	EhandPtr hand_of_cut; 
	EBooleanPtr coolant_through_tool; 
	Elength_measurePtr pilot_length; 
};
class Emilling_tool_dimension :
		public IStepNode
{
public:
	CLASSDEF(Emilling_tool_dimension); 
	Elength_measurePtr diameter; 
	Eplane_angle_measurePtr tool_top_angle; 
	Eplane_angle_measurePtr tool_circumference_angle; 
	Elength_measurePtr cutting_edge_length; 
	Elength_measurePtr edge_radius; 
	Elength_measurePtr edge_center_vertical; 
	Elength_measurePtr edge_center_horizontal; 
};
class Ecenter_drill :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ecenter_drill); 
};
class Ecountersink :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ecountersink); 
	Elength_measurePtr countersink_radius; 
};
class Ebackside_countersink :
	public  Ecountersink
{
public:
	CLASSDEF(Ebackside_countersink); 
};
class Edrill :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Edrill); 
};
class Etwist_drill :
	public  Edrill
{
public:
	CLASSDEF(Etwist_drill); 
};
class Etapered_drill :
	public  Etwist_drill
{
public:
	CLASSDEF(Etapered_drill); 
	Eplane_angle_measurePtr taper_angle; 
};
class Espade_drill :
	public  Edrill
{
public:
	CLASSDEF(Espade_drill); 
};
class Emilling_cutter :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Emilling_cutter); 
};
class Efacemill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Efacemill); 
};
class Eendmill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Eendmill); 
};
class Etapered_endmill :
	public  Eendmill
{
public:
	CLASSDEF(Etapered_endmill); 
	Eplane_angle_measurePtr taper_angle; 
};
class Eball_endmill :
	public  Eendmill
{
public:
	CLASSDEF(Eball_endmill); 
};
class Ebullnose_endmill :
	public  Eendmill
{
public:
	CLASSDEF(Ebullnose_endmill); 
};
class Et_slot_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Et_slot_mill); 
	Elength_measurePtr cutting_thickness; 
};
class Edovetail_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Edovetail_mill); 
	Eplane_angle_measurePtr included_angle; 
};
class Ewoodruff_keyseat_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Ewoodruff_keyseat_mill); 
	Elength_measurePtr cutter_width; 
};
class Eside_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Eside_mill); 
	Elength_measurePtr cutter_width; 
};
class Ethread_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Ethread_mill); 
};
class Etap :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Etap); 
};
class Etapered_tap :
	public  Etap
{
public:
	CLASSDEF(Etapered_tap); 
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_tap :
	public  Etap
{
public:
	CLASSDEF(Ecombined_drill_and_tap); 
	Elength_measurePtr drill_length; 
};
class Ethreading_tool :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ethreading_tool); 
};
class Ecounterbore :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ecounterbore); 
};
class Ebackside_counterbore :
	public  Ecounterbore
{
public:
	CLASSDEF(Ebackside_counterbore); 
};
class Ereamer :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ereamer); 
};
class Etapered_reamer :
	public  Ereamer
{
public:
	CLASSDEF(Etapered_reamer); 
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_reamer :
	public  Ereamer
{
public:
	CLASSDEF(Ecombined_drill_and_reamer); 
	Elength_measurePtr drill_length; 
};
class Eboring_tool :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Eboring_tool); 
};
class Euser_defined_tool :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Euser_defined_tool); 
	ElabelPtr identifier; 
};
class Eexchange_pallet :
	public  Enc_function
{
public:
	CLASSDEF(Eexchange_pallet); 
};
class Eindex_pallet :
	public  Enc_function
{
public:
	CLASSDEF(Eindex_pallet); 
	EIntegerPtr its_index; 
};
class Eindex_table :
	public  Enc_function
{
public:
	CLASSDEF(Eindex_table); 
	EIntegerPtr its_index; 
};
class Eload_tool :
	public  Enc_function
{
public:
	CLASSDEF(Eload_tool); 
	Emachining_toolPtr its_tool; 
};
class Eunload_tool :
	public  Enc_function
{
public:
	CLASSDEF(Eunload_tool); 
	Emachining_toolPtr its_tool; 
};
class Etool_direction_for_milling :
	public  Etool_direction
{
public:
	CLASSDEF(Etool_direction_for_milling); 
};
class Ethree_axes_tilted_tool :
	public  Etool_direction_for_milling
{
public:
	CLASSDEF(Ethree_axes_tilted_tool); 
	EdirectionPtr tool_direction; 
};
class Efive_axes_var_tilt_yaw :
	public  Etool_direction_for_milling
{
public:
	CLASSDEF(Efive_axes_var_tilt_yaw); 
};
class Efive_axes_const_tilt_yaw :
	public  Etool_direction_for_milling
{
public:
	CLASSDEF(Efive_axes_const_tilt_yaw); 
	Eplane_angle_measurePtr tilt_angle; 
	Eplane_angle_measurePtr yaw_angle; 
};
class Emilling_machining_operation :
	public  Emachining_operation
{
public:
	CLASSDEF(Emilling_machining_operation); 
	Elength_measurePtr overcut_length; 
};
class Emilling_technology :
	public  Etechnology
{
public:
	CLASSDEF(Emilling_technology); 
	Espeed_measurePtr cutspeed; 
	Erot_speed_measurePtr spindle; 
	Elength_measurePtr feedrate_per_tooth; 
	EBooleanPtr synchronize_spindle_with_feed; 
	EBooleanPtr inhibit_feedrate_override; 
	EBooleanPtr inhibit_spindle_override; 
	Eadaptive_controlPtr its_adaptive_control; 
};
class Eadaptive_control :
		public IStepNode
{
public:
	CLASSDEF(Eadaptive_control); 
};
class Emilling_machine_functions :
	public  Emachine_functions
{
public:
	CLASSDEF(Emilling_machine_functions); 
	EBooleanPtr coolant; 
	Epressure_measurePtr coolant_pressure; 
	EBooleanPtr mist; 
	EBooleanPtr through_spindle_coolant; 
	Epressure_measurePtr through_pressure; 
	std::vector<EidentifierPtr> axis_clamping; 
	EBooleanPtr chip_removal; 
	EdirectionPtr oriented_spindle_stop; 
	Eprocess_model_listPtr its_process_model; 
	std::vector<Eproperty_parameterPtr> other_functions; 
};
class Eprocess_model_list :
		public IStepNode
{
public:
	CLASSDEF(Eprocess_model_list); 
	std::vector<Eprocess_modelPtr> its_list; 
};
class Eprocess_model :
		public IStepNode
{
public:
	CLASSDEF(Eprocess_model); 
	ElabelPtr ini_data_file; 
	ElabelPtr its_type; 
};
class Emilling_type_operation :
	public  Emilling_machining_operation
{
public:
	CLASSDEF(Emilling_type_operation); 
	Eapproach_retract_strategyPtr approach; 
	Eapproach_retract_strategyPtr retract; 
};
class Eapproach_retract_strategy :
		public IStepNode
{
public:
	CLASSDEF(Eapproach_retract_strategy); 
	EdirectionPtr tool_orientation; 
};
class Eplunge_strategy :
	public  Eapproach_retract_strategy
{
public:
	CLASSDEF(Eplunge_strategy); 
};
class Eplunge_toolaxis :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_toolaxis); 
};
class Eplunge_ramp :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_ramp); 
	Eplane_angle_measurePtr angle; 
};
class Eplunge_helix :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_helix); 
	Elength_measurePtr radius; 
	Eplane_angle_measurePtr angle; 
};
class Eplunge_zigzag :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_zigzag); 
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr width; 
};
class Eair_strategy :
	public  Eapproach_retract_strategy
{
public:
	CLASSDEF(Eair_strategy); 
};
class Eap_retract_angle :
	public  Eair_strategy
{
public:
	CLASSDEF(Eap_retract_angle); 
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr travel_length; 
};
class Eap_retract_tangent :
	public  Eair_strategy
{
public:
	CLASSDEF(Eap_retract_tangent); 
	Elength_measurePtr radius; 
};
class Ealong_path :
	public  Eapproach_retract_strategy
{
public:
	CLASSDEF(Ealong_path); 
	Etoolpath_listPtr path; 
};
class Efreeform_operation :
	public  Emilling_type_operation
{
public:
	CLASSDEF(Efreeform_operation); 
	Efreeform_strategyPtr its_machining_strategy; 
};
class Efreeform_strategy :
		public IStepNode
{
public:
	CLASSDEF(Efreeform_strategy); 
	Epathmode_typePtr pathmode; 
	Ecutmode_typePtr cutmode; 
	EtolerancesPtr its_milling_tolerances; 
	Elength_measurePtr stepover; 
};
class Etolerances :
		public IStepNode
{
public:
	CLASSDEF(Etolerances); 
	Elength_measurePtr chordal_tolerance; 
	Elength_measurePtr scallop_height; 
};
class Euv_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Euv_strategy); 
	EdirectionPtr forward_direction; 
	EdirectionPtr sideward_direction; 
};
class Eplane_cc_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Eplane_cc_strategy); 
	EdirectionPtr its_plane_normal; 
};
class Eplane_cl_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Eplane_cl_strategy); 
	EdirectionPtr its_plane_normal; 
};
class Eleading_line_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Eleading_line_strategy); 
	Ebounded_curvePtr its_line; 
};
class Etwo5d_milling_operation :
	public  Emilling_type_operation
{
public:
	CLASSDEF(Etwo5d_milling_operation); 
	Etwo5d_milling_strategyPtr its_machining_strategy; 
};
class Etwo5d_milling_strategy :
		public IStepNode
{
public:
	CLASSDEF(Etwo5d_milling_strategy); 
	Epositive_ratio_measurePtr overlap; 
	EBooleanPtr allow_multiple_passes; 
};
class Eunidirectional :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Eunidirectional); 
	EdirectionPtr feed_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Ebidirectional); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Estroke_connection_strategyPtr its_stroke_connection_strategy; 
};
class Econtour_parallel :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Econtour_parallel); 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional_contour :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Ebidirectional_contour); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_bidirectional :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Econtour_bidirectional); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_spiral :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Econtour_spiral); 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ecenter_milling :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Ecenter_milling); 
};
class Eexplicit :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Eexplicit); 
};
class Eplane_milling :
	public  Etwo5d_milling_operation
{
public:
	CLASSDEF(Eplane_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr allowance_bottom; 
};
class Eplane_rough_milling :
	public  Eplane_milling
{
public:
	CLASSDEF(Eplane_rough_milling); 
};
class Eplane_finish_milling :
	public  Eplane_milling
{
public:
	CLASSDEF(Eplane_finish_milling); 
};
class Eside_milling :
	public  Etwo5d_milling_operation
{
public:
	CLASSDEF(Eside_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
};
class Eside_rough_milling :
	public  Eside_milling
{
public:
	CLASSDEF(Eside_rough_milling); 
};
class Eside_finish_milling :
	public  Eside_milling
{
public:
	CLASSDEF(Eside_finish_milling); 
};
class Ebottom_and_side_milling :
	public  Etwo5d_milling_operation
{
public:
	CLASSDEF(Ebottom_and_side_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
	Elength_measurePtr allowance_bottom; 
};
class Ebottom_and_side_rough_milling :
	public  Ebottom_and_side_milling
{
public:
	CLASSDEF(Ebottom_and_side_rough_milling); 
};
class Ebottom_and_side_finish_milling :
	public  Ebottom_and_side_milling
{
public:
	CLASSDEF(Ebottom_and_side_finish_milling); 
};
class Edrilling_type_operation :
	public  Emilling_machining_operation
{
public:
	CLASSDEF(Edrilling_type_operation); 
	Elength_measurePtr cutting_depth; 
	Elength_measurePtr previous_diameter; 
	Etime_measurePtr dwell_time_bottom; 
	Epositive_ratio_measurePtr feed_on_retract; 
	Edrilling_type_strategyPtr its_machining_strategy; 
};
class Edrilling_type_strategy :
		public IStepNode
{
public:
	CLASSDEF(Edrilling_type_strategy); 
	Epositive_ratio_measurePtr reduced_cut_at_start; 
	Epositive_ratio_measurePtr reduced_feed_at_start; 
	Elength_measurePtr depth_of_start; 
	Epositive_ratio_measurePtr reduced_cut_at_end; 
	Epositive_ratio_measurePtr reduced_feed_at_end; 
	Elength_measurePtr depth_of_end; 
};
class Edrilling_operation :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Edrilling_operation); 
};
class Edrilling :
	public  Edrilling_operation
{
public:
	CLASSDEF(Edrilling); 
};
class Ecenter_drilling :
	public  Edrilling_operation
{
public:
	CLASSDEF(Ecenter_drilling); 
};
class Ecounter_sinking :
	public  Edrilling_operation
{
public:
	CLASSDEF(Ecounter_sinking); 
};
class Emultistep_drilling :
	public  Edrilling_operation
{
public:
	CLASSDEF(Emultistep_drilling); 
	Elength_measurePtr retract_distance; 
	Elength_measurePtr first_depth; 
	Elength_measurePtr depth_of_step; 
	Etime_measurePtr dwell_time_step; 
};
class Eboring_operation :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Eboring_operation); 
	EBooleanPtr spindle_stop_at_bottom; 
	Elength_measurePtr depth_of_testcut; 
	Ecartesian_pointPtr waiting_position; 
};
class Eboring :
	public  Eboring_operation
{
public:
	CLASSDEF(Eboring); 
};
class Ereaming :
	public  Eboring_operation
{
public:
	CLASSDEF(Ereaming); 
};
class Eback_boring :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Eback_boring); 
};
class Etapping :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Etapping); 
	EBooleanPtr compensation_chuck; 
};
class Ethread_drilling :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Ethread_drilling); 
	EBooleanPtr helical_movement_on_forward; 
};
class Ehand : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Ehand); 
	enum EhandEnum
	{
	left=0,
	right,
	neutral} ;
	void SetSelection(EhandEnum nSelection) {   _nSelection=(int) nSelection;; }
virtual CString GetEnum2String(int e) {
	static int nEnums = 3;static char * szEnums[3]={"left",
"right",
"neutral"};
	if(e>=nEnums) return ""; return szEnums[(int) e];
	}
virtual long GetString2Enum(CString szEnum) {
	szEnum.MakeLower();
	static int nEnums = 3;	for(int i=0; i<nEnums; i++){
		if(GetEnum2String(i)==szEnum) return i; 
	}
	return 0;
	}
};
class Epathmode_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Epathmode_type); 
	enum Epathmode_typeEnum
	{
	forward=0,
	zigzag} ;
	void SetSelection(Epathmode_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
virtual CString GetEnum2String(int e) {
	static int nEnums = 2;static char * szEnums[2]={"forward",
"zigzag"};
	if(e>=nEnums) return ""; return szEnums[(int) e];
	}
virtual long GetString2Enum(CString szEnum) {
	szEnum.MakeLower();
	static int nEnums = 2;	for(int i=0; i<nEnums; i++){
		if(GetEnum2String(i)==szEnum) return i; 
	}
	return 0;
	}
};
class Ecutmode_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Ecutmode_type); 
	enum Ecutmode_typeEnum
	{
	climb=0,
	conventional} ;
	void SetSelection(Ecutmode_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
virtual CString GetEnum2String(int e) {
	static int nEnums = 2;static char * szEnums[2]={"climb",
"conventional"};
	if(e>=nEnums) return ""; return szEnums[(int) e];
	}
virtual long GetString2Enum(CString szEnum) {
	szEnum.MakeLower();
	static int nEnums = 2;	for(int i=0; i<nEnums; i++){
		if(GetEnum2String(i)==szEnum) return i; 
	}
	return 0;
	}
};
class Eleft_or_right : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Eleft_or_right); 
	enum Eleft_or_rightEnum
	{
	left=0,
	right} ;
	void SetSelection(Eleft_or_rightEnum nSelection) {   _nSelection=(int) nSelection;; }
virtual CString GetEnum2String(int e) {
	static int nEnums = 2;static char * szEnums[2]={"left",
"right"};
	if(e>=nEnums) return ""; return szEnums[(int) e];
	}
virtual long GetString2Enum(CString szEnum) {
	szEnum.MakeLower();
	static int nEnums = 2;	for(int i=0; i<nEnums; i++){
		if(GetEnum2String(i)==szEnum) return i; 
	}
	return 0;
	}
};
class Estroke_connection_strategy : /*select headache*/ 
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
	void SetSelection(Estroke_connection_strategyEnum nSelection) {   _nSelection=(int) nSelection;; }
virtual CString GetEnum2String(int e) {
	static int nEnums = 4;static char * szEnums[4]={"straghtline",
"lift_shift_plunge",
"degouge",
"loop_back"};
	if(e>=nEnums) return ""; return szEnums[(int) e];
	}
virtual long GetString2Enum(CString szEnum) {
	szEnum.MakeLower();
	static int nEnums = 4;	for(int i=0; i<nEnums; i++){
		if(GetEnum2String(i)==szEnum) return i; 
	}
	return 0;
	}
};
} /* End namespace Express*/
