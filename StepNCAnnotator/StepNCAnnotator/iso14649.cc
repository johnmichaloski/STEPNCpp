/* iso14649.cc

This iso14649.cc file contains the source code for (1) the kernel of
an iso14649 interpreters and (2) two of the four sets of interface
functions declared in canon.hh:
1. interface functions to call to tell the interpreter what to do.
   These all return a status value.
2. interface functions to call to get information from the interpreter.

Kernel functions call each other. A few kernel functions are called by
interface functions.

Interface function names all begin with "iso14649_".

Error handling is by returning a status value of either a non-error
code (ISO14649_OK, ISO14649_EXIT, etc.) or some specific error code
from each function where there is a possibility of error.  If an error
occurs, processing is always stopped, and control is passed back up
through the function call hierarchy to an interface function; the
error code is also passed back up. The stack of functions called is
also recorded. The external program calling an interface function may
then handle the error further as it sees fit.

Since returned values are usually used as just described to handle the
possibility of errors, an alternative method of passing calculated
values is required. In general, if function A needs a value for
variable V calculated by function B, this is handled by passing a
pointer to V from A to B, and B calculates and sets V.

To check that a RoseBoolean is true or false, a direct comparison
with ROSE_TRUE or ROSE_FALSE should always be made because
ROSE_NULL_BOOLEAN is 3.

SECURITY PLANE

The handling of security planes is as follows.

1. All security planes are required here to be planes (the spec (Part
10 section 4.6.4.1.2, page 60) requires only elementary surface, which
includes sphere and plane). All security planes are required here to
be parallel to the machine XY plane.

2. A workplan has a setup which has security plane given in the
coordinate system (c_sys) of the setup (section 4.6.4.1.2).

3. A workingstep (Part 10 section 4.6.2, page 51) also has a security
plane. The spec does not say how to deal with two security planes. We
use the workingstep's security plane here whenever possible.

A. If the workingstep is a rapid_movement or transition_feature, the
security plane is supposed to be located in the coordinate system of
the workpiece with which it is associated (section 4.6.2). This works
for transition_feature, which has an associated workpiece. Unfortunately,
there is no association between a rapid_movement and a workpiece, so here
we assume the secplane of a rapid_movement is given in the setupretract distance 
coordinate system.
 
B. If its_feature of the workingstep is a region or
two5D_manufacturing_feature (the only other choices from
transition_feature), the secplane is located in the coordinate system
of the feature.

COORDINATE SYSTEMS

The coordinate system chain (see Part 10 Fig 40, page 60) with axis
placement attribute names in square brackets is:

machine coordinate system
  |
  |
setup [its_origin]
  |
  | (a workpiece_setup is one of the its_workpiece_setup list of a setup)
  |
workpiece_setup[its_origin] (locates the its_workpiece of the workpiece_setup)
  |
  | (a manufacturing_feature has an its_workpiece, which is a workpiece)
  |
region[feature_placement] or two5D_manufacturing_feature[feature_placement]
  |
  |
feature component (depth, bottom, etc) or workingstep security plane

This chain is not appropriate for a program because to run the same
program on different machines, it will usually be necessary to locate
the setup in different places in machine coordinates. This locating
should be done by the machinist, and the controller must be told
where the setup is located. This information should not be in the
program. Thus, here, all coordinate values are being given in setup
coordinates, and (to work around current model), the placement of
the setup must either not be given (which is allowed), or the placement
must be the same as the default placement (in the same place as the
coordinate system to which the placement is referenced).

Since this interpreter is for a 3-axis machining center, it is assumed
that the Z-axis of the setup will always be placed parallel to the
Z-axis of the machine coordinate system.  Before toolpath generation,
the feature for which a toolpath is to be generated is placed in setup
coordinates. The Z-axis of the feature must then be parallel to the
setup Z-axis (and, hence, the machine Z-axis).

To deal with coordinate systems, when a file is read, the location of
the (one and only) workpiece (given in setup coordinates) is stored in
_world.workpiece_place (check_and_store), and each time an operation
on a feature is to be executed, the location of the feature in setup
coordinates is calculated and stored in _world.feature_place
(find_location called by execute_machining).

The _world.feature_place is used in tool-path generating functions in
one of two ways:
1. The feature is located in setup coordinates (by find_location) by
   using the _world.feature_place. Tool-path locations for canonical
   machining function calls are generated directly from the feature.
2. Locations for tool paths are generated initially in a feature's
   coordinate system and the tool paths are saved in pseudocode. Then
   the pseudocode is relocated (by transform_code) using the
   _world.feature_place. Canonical machining function calls are
   generated (by run_code) from the relocated pseudocode.

RESTRICTIONS

The restrictions are all checked. The function that does the checking
is in parentheses.

1. The file must have exactly one project.
   (check_and_store)

2. The file must have exactly one setup.
   (check_and_store)

3. The file must have exactly one workpiece.
   (check_and_store)

4. The file must have exactly one workpiece_setup
   (check_and_store)

5. The one setup must be the its_setup of the main_workplan of the
   one project (but it may be the its_setup of more than one workplan).
   (check_and_store)

6. The its_workpiece_setup list of workpiece_setups in the one setup
   must have exactly one element.
   (check_and_store)

6. The one workpiece in a file must be the its_workpiece of the one
   workpiece_setup.
   (check_and_store)

7. The one project must have exactly one workpiece.
   (check_and_store)

8. The one project's one workpiece must be the file's one workpiece.
   (check_and_store)

9. The one workpiece_setup of the one setup must be the one
   workpiece_setup in the file.
   (check_and_store)

ERROR CODE NAMING CONVENTIONS

1. Errors that result from bad data describe a rule that has been
violated. Rules usually include the word MUST. For example:
COUNTERBORE_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS.

2. Errors that result because the spec is only partially implemented
start with CANNOT_HANDLE or CAN_HANDLE_ONLY. For example:
CANNOT_HANDLE_PROFILE_PLACEMENT or CAN_HANDLE_ONLY_PLUNGE_APPROACH.

3. Errors that can result only if this software has a bug in it
contain the word BUG. For example: BUG_IN_ENTERING_POCKET.

*/

/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "iso14649.hh"

#define DEBUG_EMC

/*
  Tom's original ISO 14649 interpreter uses the 3-axis canonical interface,
  and passes strings as tool identifiers instead of integers. The EMC uses
  the 6-axis canonical interface, and uses integers as tool identifiers.
*/

#define STRAIGHT_TRAVERSE_3(x,y,z) STRAIGHT_TRAVERSE((x),(y),(z),0,0,0)
#define STRAIGHT_FEED_3(x,y,z) STRAIGHT_FEED((x),(y),(z),0,0,0)
#define ARC_FEED_3(fe,se,fa,sa,r,aep) ARC_FEED((fe),(se),(fa),(sa),(r),(aep),0,0,0)
#define SET_ORIGIN_OFFSETS_3(x,y,z) SET_ORIGIN_OFFSETS((x),(y),(z),0,0,0)
#define CHANGE_TOOL_3(s) CHANGE_TOOL_BY_NAME(s)
#define GET_EXTERNAL_TOOL_INDEX GET_EXTERNAL_TOOL_SLOT

/*

Function prototypes for static functions

*/

static int change_tool(machining_tool * the_tool, int set_flag);
static int check_and_store();
static int check_counterbore_hole(counterbore_hole * the_cbore_hole,
  round_hole ** the_hole, double * lower_diameter);
static int check_countersunk_hole(countersunk_hole * the_csunk_hole,
  double * upper_hole_angle, round_hole ** the_hole);
static int check_direction_ratios(ListOfDouble * ratios);
static int check_horizontal_plane(elementary_surface * surf);
static int check_op_center_drilling
  (center_drilling * the_center_drilling, elementary_surface * depth_plane);
static int check_op_counter_boring
  (round_hole * the_hole, boring * the_boring);
static int check_op_counter_sinking
  (round_hole * the_hole, counter_sinking * the_sinking);
static int check_op_drilling(drilling * the_drilling);
static int check_op_finish_both(bottom_and_side_finish_milling * the_finish);
static int check_op_multistep_drilling(drilling * the_drilling);
static int check_op_reaming(reaming * the_reaming);
static int check_op_rough_both(bottom_and_side_rough_milling * the_rough);
static int check_op_rough_plane(plane_rough_milling * the_rough);
static int check_op_two5D(two5D_milling_operation * the_op,
  double axial, double radial, double allow_side, double allow_bottom);
static int check_placement(axis2_placement_3d * place);
static int check_planar_face(planar_face * the_face, double * plane_length,
  double * plane_width, double * plane_depth);
static int check_plane_milling_strategies(plane_milling * the_cut,
 double diameter, approach_retract_strategy ** enter_strategy,
 approach_retract_strategy ** leave_strategy,
 two5D_milling_strategy ** inside_strategy);
static int check_rectangular_pocket(closed_pocket * the_pocket,
  double * pocket_length, double * pocket_width, double * pocket_depth,
  double * pocket_radius);
static int check_rectangular_pocket_strategies(closed_pocket * the_pocket,
  double pocket_length, double pocket_width, double pocket_depth,
  double pocket_radius, bottom_and_side_milling * the_cut,
  endmill * the_endmill, double * stepover, 
  approach_retract_strategy ** enter_strategy,
  approach_retract_strategy ** leave_strategy,
  two5D_milling_strategy ** inside_strategy, int is_finish);
static int check_tool_center_drill
  (machining_tool * the_tool, double * flute_length);
static int check_tool_counterbore(machining_tool * the_tool,
  round_hole * the_hole, double * cut_depth);
static int check_tool_countersink(machining_tool * the_tool,
  round_hole * the_hole, double * cut_depth, double upper_hole_angle);
static int check_tool_dimension(milling_tool_dimension * dimension,
  int edge_radius_flag, int tool_top_angle_flag, int circumference_angle_flag);
static int check_tool_drill(machining_tool * the_tool, double * flute_length);
static int check_tool_endmill
  (machining_tool * the_tool, endmill ** the_endmill);
static int check_tool_plane(machining_tool * the_tool,
  endmill ** the_endmill, facemill ** the_facemill);
static int check_tool_reamer(machining_tool * the_tool, reamer ** the_reamer);
static int check_tools(List (executable) * executables);
static int cut_feature
  (machining_feature * the_feature, machining_operation * the_operation);
static int cut_straight(double length, double depth, double retract_z,
  double pass_depth, approach_retract_strategy * enter,
  approach_retract_strategy * leave, double diameter, double code[][7],
  int * lines);
static int enter_pocket_pass(plunge_strategy * enter, double start_x,
  double start_y, double start_z, double end_x, double end_z, double aux,
  double code[][7], int * lines);
static int enter_pocket_pass_helix(plunge_helix * hely, double start_x,
  double start_y, double start_z, double end_x, double end_z, int turns,
  double code[][7], int * lines);
static int enter_pocket_pass_zigzag(plunge_zigzag * ziggy, double start_x,
  double start_z, double end_x, double end_z, double offset_x,
  double code[][7], int * lines);
static int execute_executable();
static int execute_machining(machining_workingstep * the_machining);
static int execute_nc_function(nc_function * the_nc_function);
static int execute_rapid(rapid_movement * the_rapid);
static int execute_rapid_part(toolpath * a_path);
static int execute_workingstep(workingstep * the_workingstep);
static int find_drill_tip_length
  (machining_tool * the_tool, double * tip_length);
static int find_cutting_depths(double * depth, double * depth1,
  double * depth2, double flute_length, double tip_length,
  elementary_surface * depth_plane, double overcut_length,
  double cutting_depth, drilling_type_strategy * the_strategy);
static int find_if_vertical(direction * axis, int * vertical);
static int find_location(axis2_placement_3d * place1,
  axis2_placement_3d * place2, axis2_placement_3d * place3);
static int find_pocket_plunge_start(double length, double width,
  double plunge_depth, plunge_strategy * enter,
  double * start_x, double * start_y, double * aux);
static int find_pocket_plunge_start_helix(double width, double plunge_depth,
  plunge_helix * hely, double * start_x, double * start_y, double * turns,
  double end_x);
static int find_pocket_plunge_start_ramp(double length, double width,
  double plunge_depth, plunge_ramp * the_ramp, double * start_x,
  double * start_y, double end_x);
static int find_pocket_plunge_start_toolaxis
  (double * start_x, double * start_y, double end_x);
static int find_pocket_plunge_start_zigzag(double length, double width,
  double plunge_depth, plunge_zigzag * ziggy, double * start_x,
  double * start_y, double * offset_x, double end_x);
static int find_retract_z(double top_z, double op_retract,
  double default_retract, double * retract_z);
static int find_tool_index(machining_tool * the_tool, int * index);
static int finish_mill_both_closed_pocket(closed_pocket * the_pocket,
  bottom_and_side_finish_milling * the_finish, endmill * the_endmill);
static int handle_feed
  (double feedrate, double feedrate_per_tooth, machining_tool * the_tool);
static int handle_feed_override(RoseBoolean disable);
static int handle_machine_functions(milling_machine_functions * the_functions);
static int handle_speed
  (double spindle_speed, double surface_speed, machining_tool * the_tool);
static int handle_speed_override(RoseBoolean disable);
static int handle_synch(RoseBoolean synch);
static int handle_technology
  (milling_technology * the_technology, machining_tool * the_tool);
static int handle_tool(machining_tool * the_tool, int set_flag);
static int handle_unload_tool(machining_tool * the_tool);
static int init_place(axis2_placement_3d * place);
static int is_default_placement(axis2_placement_3d * place);
static int mill_circular_pocket(double length, double z_now, double stepover,
  double tool_diameter, int spiral, double code[][7], int * lines);
static int mill_planar(planar_face * the_face, plane_milling * the_milling,
  milling_cutter * the_mill);
static int mill_planar_bi(double length, double width, int passes,
  double diameter, double pass_depth, double stepover, double overage,
  double retract, bidirectional_milling * bi, double code[][7], int * lines);
static int mill_planar_regular(double plane_length, double plane_width,
  double plane_depth, double diameter, double pass_depth, double stepover,
  double overcut, plane_milling * the_cut);
static int mill_planar_uni(double length, double width, int passes,
  double diameter, double pass_depth, double stepover, double overage,
  double retract, unidirectional_milling * uni, double code[][7], int * lines);
static int mill_rectangular_pocket(double pocket_length,
  double pocket_width, double pocket_depth, double pocket_radius,
  double stepover, double tool_diameter, bottom_and_side_milling * the_cut,
  double code[][7], int * lines);
static int mill_rectangular_pocket_regular(double length, double width,
  double depth, double radius, double retract_z, double pass_depth,
  double stepover, approach_retract_strategy * enter,
  approach_retract_strategy * leave, two5D_milling_strategy * inside,
  double tool_diameter, double code[][7], int * lines);
static int mill_regular_pocket(double length, double width, double radius,
  double z_now, double stepover, double tool_diameter, int spiral,
  double code[][7], int * lines);
static int mill_semicircle_end_pocket(double length, double width,
  double z_now, double stepover, double tool_diameter, int spiral,
  double code[][7], int * lines);
static int op_center_drilling
  (machining_feature * the_feature, center_drilling * the_center_drilling);
static int op_counter_boring
  (counterbore_hole * the_cbore_hole, boring * the_boring);
static int op_counter_sinking
  (countersunk_hole * the_csunk_hole, counter_sinking * the_sinking);
static int op_drilling
  (machining_feature * the_feature, drilling * the_drilling);
static int op_finish_milling_both(machining_feature * the_feature,
  bottom_and_side_finish_milling * the_finish);
static int op_finish_milling_plane
  (machining_feature * the_feature, plane_finish_milling * the_finish);
static int op_finish_milling_side
  (machining_feature * the_feature, side_finish_milling * the_finish);
static int op_multistep_drilling
  (machining_feature * the_feature, multistep_drilling * the_drilling);
static int op_reaming
  (machining_feature * the_feature, reaming * the_reaming);
static int op_rough_milling_both
  (machining_feature * the_feature, bottom_and_side_rough_milling * the_rough);
static int op_rough_milling_plane
  (machining_feature * the_feature, plane_rough_milling * the_rough);
static int op_rough_milling_side
  (machining_feature * the_feature, side_rough_milling * the_rough);
static int plunge_pocket(double depth, double retract_z, double code[][7],
  int * lines);
static int reset_place(axis2_placement_3d * place);
static int rough_mill_both_closed_pocket(closed_pocket * the_pocket,
  bottom_and_side_rough_milling * the_rough, endmill * the_endmill);
static int run_code(double code[][7], int lines);
static int set_security_z_now(elementary_surface * secplane);
static int start_cut(double new_x, double new_y, double retract_z);
static double tand(double degrees);
static int transform_code
  (double code[][7], int lines, axis2_placement_3d * place);
static int write_arc(double end_x, double end_y, double center_x,
  double center_y, int rotation, double end_z, double code[][7],
  int * lines);
static int write_feed
  (double x, double y, double z, double code[][7], int * lines);
static int write_feed_y
  (double x, double y, double z, double code[][7], int * lines);
static int write_traverse
  (double x, double y, double z, double code[][7], int * lines);
static int write_traverse_y
  (double x, double y, double z, double code[][7], int * lines);

/***********************************************************************/

/*

Global variable declaration

*/

extern char * _iso14649_errors[];
world _world;

/***********************************************************************/
/***********************************************************************/

/*

The functions in this section are the interpreter kernel functions

*/

/***********************************************************************/

/* change_tool

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_tool_index returns an error code.
   2. If the tool were changed, the new tool would be too long to retract
      above the security plane of the setup:
      TOOL_MUST_NOT_BE_TOO_LONG_TO_RETRACT_TO_SETUP_SECURITY_PLANE.

Side Effects: See below

Called By:
  handle_tool
  handle_unload_tool

If the spindle is turning, this stops it and does not restart it.  If
mist or flood coolant is on, this turns it off and does not turn it
back on.  This calls the canonical CHANGE_TOOL function to change the
tool.  The CHANGE_TOOL function leaves the spindle fully retracted
and, if there is a tool in the spindle when CHANGE_TOOL is called,
that tool is put back into the tool rack.

the_tool may be NULL when this is called. In this case, the tool currently
in the spindle will be removed from the spindle.

Before the call to CHANGE_TOOL, the spindle is fully retracted and, if
_world.change_x and _world.change_y are not ROSE_NULL_REAL, the
controlled point is moved there. The spindle is not moved after the
change (but it may move during the change).

In ISO 14649, the controlled point is at the tool tip. This means, that
in the canonical machining view, the correct tool length offset must
always be used. Hence, this always calls USE_TOOL_LENGTH_OFFSET.

The current location is not updated here because CHANGE_TOOL may move
it later (since the CHANGE_TOOL command may be put on a queue).

If change_tool is called via execute_nc_function, to find where the
controlled point is, the set_flag argument here will be 1, and in this
case, the _world.action_flag is set here to ISO14649_SET_POSITION. See
documentation of iso14649_read for the rest of how this works.

The other way change_tool can be called is in the middle of executing
a workingstep. In this case, although the XY location is temporarily
lost, it is re-found during execution of the workingstep.

*/

static int change_tool(     /* ARGUMENTS                         */
 machining_tool * the_tool, /* the tool to put in the spindle    */
 int set_flag)              /* 1=set _world.action_flag, 0=don't */
{
  static char name[] SET_TO "change_tool";
  int index;
  double length;

  if (_world.spindle_turning ISNT CANON_STOPPED)
    {
      STOP_SPINDLE_TURNING();
      _world.spindle_turning SET_TO CANON_STOPPED;
    }
  if (_world.flood ISNT OFF)
    {
      FLOOD_OFF();
      _world.flood SET_TO OFF;
    }
  if (_world.mist ISNT OFF)
    {
      MIST_OFF();
      _world.mist SET_TO OFF;
    }
  if (_world.current_z ISNT _world.retracted_z)
    SPINDLE_RETRACT();
  USE_TOOL_LENGTH_OFFSET(0.0);
  IFF(find_tool_index(the_tool, &index));
  length SET_TO ((the_tool IS NULL) ? 0.0 : _world.tool_table[index].length);
#if 0				// FMP
  CHK(((_world.retracted_z - length) < _world.security_z_setup),
      TOOL_MUST_NOT_BE_TOO_LONG_TO_RETRACT_TO_SETUP_SECURITY_PLANE);
#endif
  if ((_world.change_x ISNT ROSE_NULL_REAL) AND
      (_world.change_y ISNT ROSE_NULL_REAL))
    STRAIGHT_TRAVERSE_3(_world.change_x, _world.change_y, _world.retracted_z);

  if (the_tool IS NULL)
    CHANGE_TOOL_3("");
  else
    {
      CHANGE_TOOL_3(the_tool->its_id());
      USE_TOOL_LENGTH_OFFSET(length);
    }
  _world.current_tool_index SET_TO index;
  if (set_flag)
    _world.action_flag SET_TO ISO14649_SET_POSITION;
  return ISO14649_OK;
}

/***********************************************************************/

/* check_and_store

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The file does not have exactly one project instance:
      FILE_MUST_HAVE_EXACTLY_ONE_PROJECT.
   2. The file does not have exactly one workpiece instance:
      FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE.
   3. The file does not have exactly one setup instance:
      FILE_MUST_HAVE_EXACTLY_ONE_SETUP.
   4. The file does not have exactly one workpiece_setup instance:
      FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP.
   5. The one project instance does not have exactly one workpiece instance:
      PROJECT_MUST_HAVE_EXACTLY_ONE_WORKPIECE.
   6. The project's one workpiece is not the file's one workpiece
      PROJECT_WORKPIECE_MUST_BE_FILE_WORKPIECE.
   7. The project's main_workplan's setup is not the file's one setup:
      PROJECT_MAIN_WORKPLAN_SETUP_MUST_BE_FILE_SETUP;
   8. The one setup does not have exactly one workpiece_setup:
      THE_SETUP_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP.
   9. The setup's one workpiece_setup is not the file's one workpiece_setup:
      SETUP_WORKPIECE_SETUP_MUST_BE_FILE_WORKPIECE_SETUP.
  10. the_workpiece_setup's its_workpiece is not the file's one workpiece:
      WORKPIECE_SETUP_WORKPIECE_MUST_BE_FILE_WORKPIECE
  11. The main_workplan of the_project is NULL: MAIN_WORKPLAN_MUST_NOT_BE_NULL.
  12. init_place returns an error code.
  13. is_default_placement returns an error code.
  14. check_horizontal_plane returns an error code.

Side Effects: See below

Called By: iso14649_open

This checks things as described above, and:
1. The workpiece is saved in _world.a_workpiece.
2. The project's main workplan is saved in _world.a_workplan.
3. The list of executables of the workplan is saved in _world.execs.
4. The _world.a_exec_index is set to 0.
5. The Z coordinate of the point on the security plane of the setup
      is saved in _world.security_z_setup and _world.security_z_now.
6. The placement in the setup coordinate system of the workpiece is
      saved in _world.workpiece_place.

The its_origin of the_setup may be NULL (Part 10, Section 4.6.4.1.2,
Page 60).  In the spec, this means the setup placement is the machine
coordinate system. But here we diverge from the spec. To be
machine_independent, no placement of the setup in machine coordinates
should be given, so NULL is fine but does not mean anything. If
its_origin is NULL, this function makes a placement with default
values and inserts it as the value of its_origin. This function,
alternatively, allows its_origin to be the default placement, but
that also means nothing.

Notes:

The AP238 interpreter uses the different rules regarding workplans,
workpieces, setups, and workpiece_setups. These are given in the
documentation of that interpreter's check_and_store function. It would
be nice to change this function to follow those rules. Currently, this
function is more restrictive than the rules.

*/

static int check_and_store()  /* NO ARGUMENTS */
{
  static char name[] SET_TO "check_and_store";
  List (project) projects;
  project * the_project;
  List (workpiece) workpieces;
  workpiece * the_workpiece;
  List (setup) setups;
  setup * the_setup;
  List (workpiece_setup) workpiece_setups;
  axis2_placement_3d * a_place;
  workpiece_setup * the_workpiece_setup;

  ROSE.findObjects(&projects, _world.design);
  ROSE.findObjects(&workpieces, _world.design);
  ROSE.findObjects(&setups, _world.design);
  ROSE.findObjects(&workpiece_setups, _world.design);
  CHK((projects.size() ISNT 1), FILE_MUST_HAVE_EXACTLY_ONE_PROJECT);
  the_project SET_TO projects[0];
  CHK((workpieces.size() ISNT 1), FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE);
  the_workpiece SET_TO workpieces[0];
  CHK((setups.size() ISNT 1), FILE_MUST_HAVE_EXACTLY_ONE_SETUP);
  the_setup SET_TO setups[0];
  CHK((workpiece_setups.size() ISNT 1),
      FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP);
  the_workpiece_setup SET_TO workpiece_setups[0];
  CHK((the_project->its_workpieces()->size() ISNT 1),
      PROJECT_MUST_HAVE_EXACTLY_ONE_WORKPIECE);
  CHK(((*(the_project->its_workpieces()))[0] ISNT the_workpiece),
      PROJECT_WORKPIECE_MUST_BE_FILE_WORKPIECE);
  CHK((the_project->main_workplan() IS NULL), MAIN_WORKPLAN_MUST_NOT_BE_NULL);
  CHK((the_project->main_workplan()->its_setup() ISNT the_setup),
      PROJECT_MAIN_WORKPLAN_SETUP_MUST_BE_FILE_SETUP);
  CHK((the_setup->its_workpiece_setup()->size() ISNT 1),
      THE_SETUP_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP);
  CHK(((*(the_setup->its_workpiece_setup()))[0] ISNT the_workpiece_setup),
      SETUP_WORKPIECE_SETUP_MUST_BE_FILE_WORKPIECE_SETUP);
  CHK((the_workpiece_setup->its_workpiece() ISNT the_workpiece),
      WORKPIECE_SETUP_WORKPIECE_MUST_BE_FILE_WORKPIECE);
  if (the_setup->its_origin() IS NULL)
    {
      a_place SET_TO new axis2_placement_3d;
      IFF(init_place(a_place));
      the_setup->its_origin(a_place);
    }
  else
    IFF(is_default_placement(the_setup->its_origin()));
  IFF(check_horizontal_plane(the_setup->its_secplane()));
  _world.security_z_setup SET_TO
    the_setup->its_secplane()->position()->location()->coordinates()->get(2);
  _world.security_z_now SET_TO _world.security_z_setup;
  _world.a_workpiece SET_TO the_workpiece;
  _world.a_workplan SET_TO the_project->main_workplan();
  _world.execs SET_TO _world.a_workplan->its_elements();
  _world.a_exec_index SET_TO 0;
  _world.workpiece_place SET_TO the_workpiece_setup->its_origin();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_counterbore_hole

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The elements list of the counterbore hole is NULL:
      COUNTERBORE_HOLE_ELEMENTS_MUST_NOT_BE_NULL.
   2. The elements list of the counterbore hole does not have exactly two
      elements: COUNTERBORE_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS.
   3. The first element is NULL:
      FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL.
   4. The second element is NULL:
      SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL.
   5. The first subhole is not a round_hole:
      FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE.
   6. The second subhole is not a round_hole:
      SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE.
   7. check_placement applied to either subhole returns an error code.
   8. find_if_vertical applied to either subhole returns an error code.
   9. The first subhole is not vertical:
      FIRST_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL.
  10. The second subhole is not vertical:
      SECOND_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL.
  11. The two subholes are not coaxial:
      SUBHOLES_OF_COUNTERBORE_HOLE_MUST_BE_COAXIAL.
  12. The two subholes are in the same location:
      COUNTERBORE_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE.
  13. The diameter of the upper subhole is not greater than the diameter
      of the lower subhole:
      UPPER_HOLE_DIAMETER_OF_COUNTERBORE_HOLE_MUST_BE_GREATER_THAN_LOWER.
  14. check_horizontal_plane applied to the bottom of the upper subhole
      returns an error code.
  15. The lower subhole does not begin at the bottom of the upper subhole:
      UPPER_AND_LOWER_HOLES_OF_COUNTERBORE_HOLE_MUST_MATE_VERTICALLY.
  16. The change_in_diameter of the upper hole is not NULL:
      UPPER_HOLE_OF_COUNTERBORE_HOLE_MUST_NOT_TAPER.

Side Effects: This sets the value of upper_hole.

Called By: op_counter_boring

This checks a counterbore_hole.

The upper hole of a counterbore_hole must not be tapered. Either the first
or second hole of a counterbore_hole may be the upper hole.

This is requiring that:
1. the first and second holes be co-axial
2. the axes of the first and second holes be vertical.
3. the bottom of the upper hole is at the top of the lower hole.

Remember the placement of the two holes is in terms of the coordinate
system of the counterbore_hole, and the placement of the bottom of each
hole is in the coordinate system of the hole.

It has already been checked that the_feature is not NULL, that its
placement is OK and that the axis of the_feature is vertical in the
setup coordinate system. In principle, the_feature does not need to
have its axis be vertical in the setup coordinate system, as long as
the two holes that make up the_feature have their axes vertical in the
setup coordinate system, but modeling the_feature that way would be
strange and checking it is too much trouble.

*/

static int check_counterbore_hole( /* ARGUMENTS                          */
 counterbore_hole * bore_hole,     /* the counterbore_hole               */
 round_hole ** upper_hole,         /* upper hole, found and set here     */
 double * lower_diameter)          /* diameter of lower hole, set here   */
{
  static char name[] SET_TO "check_counterbore_hole";
  round_hole * lower_hole;
  compound_feature_select * element0;
  compound_feature_select * element1;
  round_hole * hole0;
  round_hole * hole1;
  int vertical;
  double z0;
  double z1;
  double upper_z;         /* Z coordinate of top of upper hole */
  double lower_z;         /* Z coordinate of top of lower hole */
  double height;          /* height of upper hole              */
  double upper_diameter;  /* diameter of upper hole            */

  CHK((bore_hole->elements() IS NULL),
      COUNTERBORE_HOLE_ELEMENTS_MUST_NOT_BE_NULL);
  CHK((bore_hole->elements()->size() ISNT 2),
      COUNTERBORE_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS);
  element0 SET_TO bore_hole->elements()->get(0);
  element1 SET_TO bore_hole->elements()->get(1);
  CHK((element0 IS NULL), FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL);
  CHK((element1 IS NULL), SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL);
  CHK(((NOT(element0->is_machining_feature())) OR
       (NOT(element0->_machining_feature()->isa("round_hole")))),
      FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE);
  CHK(((NOT(element1->is_machining_feature())) OR
       (NOT(element1->_machining_feature()->isa("round_hole")))),
      SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE);
  hole0 SET_TO ROSE_CAST(round_hole, element0->_machining_feature());
  hole1 SET_TO ROSE_CAST(round_hole, element1->_machining_feature());
  IFF(check_placement(hole0->feature_placement()));
  IFF(check_placement(hole1->feature_placement()));
  IFF(find_if_vertical(hole0->feature_placement()->axis(), &vertical));
  CHK((NOT(vertical)), FIRST_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL);
  IFF(find_if_vertical(hole1->feature_placement()->axis(), &vertical));
  CHK((NOT(vertical)), SECOND_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL);
  CHK((hypot((hole0->feature_placement()->location()->coordinates()->get(0) -
	      hole1->feature_placement()->location()->coordinates()->get(0)),
	     (hole0->feature_placement()->location()->coordinates()->get(1) -
	      hole1->feature_placement()->location()->coordinates()->get(1)))
       > ISO14649_TINY),
      SUBHOLES_OF_COUNTERBORE_HOLE_MUST_BE_COAXIAL);
  z0 SET_TO hole0->feature_placement()->location()->coordinates()->get(2);
  z1 SET_TO hole1->feature_placement()->location()->coordinates()->get(2);
  CHK((z0 IS z1), COUNTERBORE_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE);
  if (z0 > z1)
    {
      *upper_hole SET_TO hole0;
      lower_hole SET_TO hole1;
      upper_z SET_TO z0;
      lower_z SET_TO z1;
    }
  else /* if (z1 > z0) */
    {
      *upper_hole SET_TO hole1;
      lower_hole SET_TO hole0;
      upper_z SET_TO z1;
      lower_z SET_TO z0;
    }
  *lower_diameter SET_TO lower_hole->diameter()->theoretical_size();
  upper_diameter SET_TO (*upper_hole)->diameter()->theoretical_size();
  CHK((upper_diameter <= *lower_diameter),
      UPPER_HOLE_DIAMETER_OF_COUNTERBORE_HOLE_MUST_BE_GREATER_THAN_LOWER);
  IFF(check_horizontal_plane((*upper_hole)->depth()));
  height SET_TO 
    -((*upper_hole)->depth()->position()->location()->coordinates()->get(2));
  CHK((fabs((upper_z - height) - lower_z) > ISO14649_TINY),
      UPPER_AND_LOWER_HOLES_OF_COUNTERBORE_HOLE_MUST_MATE_VERTICALLY);
  CHK(((*upper_hole)->change_in_diameter() ISNT NULL),
      UPPER_HOLE_OF_COUNTERBORE_HOLE_MUST_NOT_TAPER);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_countersunk_hole

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The elements list of the countersunk hole is NULL:
      COUNTERSUNK_HOLE_ELEMENTS_MUST_NOT_BE_NULL.
   2. The elements list of the countersunk hole does not have exactly two
      elements: COUNTERSUNK_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS.
   3. The first element is NULL:
      FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL.
   4. The second element is NULL:
      SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL.
   5. The first subhole is not a round_hole:
      FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE.
   6. The second subhole is not a round_hole:
      SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE.
   7. check_placement applied to either subhole returns an error code.
   8. find_if_vertical applied to either subhole returns an error code.
   9. The first subhole is not vertical:
      FIRST_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL.
  10. The second subhole is not vertical:
      SECOND_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL.
  11. The two subholes are not coaxial:
      SUBHOLES_OF_COUNTERSUNK_HOLE_MUST_BE_COAXIAL.
  12. The two subholes are in the same location:
      COUNTERSUNK_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE.
  13. The diameter of the upper subhole is not greater than the diameter
      of the lower subhole:
      UPPER_HOLE_DIAMETER_OF_COUNTERSUNK_HOLE_MUST_BE_GREATER_THAN_LOWER.
  14. check_horizontal_plane applied to the bottom of the upper subhole
      returns an error code.
  15. The lower subhole does not begin at the bottom of the upper subhole:
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_VERTICALLY.
  16. The diameter at the bottom of the upper hole is not the same as
      the diameter at the top of the lower hole.
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_IN_DIAMETER.
  17. The change_in_diameter of the upper hole is NULL:
      UPPER_HOLE_OF_COUNTERSUNK_HOLE_MUST_TAPER.
  18. The change_in_diameter of the upper hole is neither a diameter_taper
      nor an angle_taper:
      UPPER_HOLE_TAPER_MUST_BE_DIAMETER_TAPER_OR_ANGLE_TAPER.

Side Effects: This sets the value of upper_hole.

Called By: op_counter_sinking

This checks a countersunk_hole.

The upper hole of a countersunk_hole must be tapered. Either the first
or second hole of a countersunk_hole may be the upper hole.

This is requiring that:
1. the first and second holes be co-axial
2. the axes of the first and second holes be vertical.
3. the bottom of the upper hole is at the top of the lower hole.

Remember the placement of the two holes is in terms of the coordinate
system of the countersunk_hole, and the placement of the bottom of each
hole is in the coordinate system of the hole.

It has already been checked that the_feature is not NULL, that its
placement is OK and that the axis of the_feature is vertical in the setup
coordinate system. In principle, the_feature does not need to have its axis
be vertical in the setup coordinate system, as long as the two holes that
make up the_feature have their axes vertical in the setup coordinate
system, but modeling the_feature that way would be strange and checking it
is too much trouble.

*/

static int check_countersunk_hole( /* ARGUMENTS                          */
 countersunk_hole * sunk_hole,     /* the countersunk_hole               */
 double * upper_hole_angle,        /* angle from side to horiz, set here */
 round_hole ** upper_hole)         /* upper hole, found and set here     */
{
  static char name[] SET_TO "check_countersunk_hole";
  round_hole * lower_hole;
  compound_feature_select * element0;
  compound_feature_select * element1;
  round_hole * hole0;
  round_hole * hole1;
  int vertical;
  double z0;
  double z1;
  double upper_z;         /* Z coordinate of top of upper hole */
  double lower_z;         /* Z coordinate of top of lower hole */
  double height;          /* height of upper hole              */
  double lower_diameter;  /* diameter of lower hole            */
  double upper_diameter1; /* diameter at top of upper hole     */
  double upper_diameter2; /* diameter at bottom of upper hole  */
  taper_select * taper;   /* taper of upper hole               */

  CHK((sunk_hole->elements() IS NULL),
      COUNTERSUNK_HOLE_ELEMENTS_MUST_NOT_BE_NULL);
  CHK((sunk_hole->elements()->size() ISNT 2),
      COUNTERSUNK_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS);
  element0 SET_TO sunk_hole->elements()->get(0);
  element1 SET_TO sunk_hole->elements()->get(1);
  CHK((element0 IS NULL), FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL);
  CHK((element1 IS NULL), SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL);
  CHK(((NOT(element0->is_machining_feature())) OR
       (NOT(element0->_machining_feature()->isa("round_hole")))),
      FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE);
  CHK(((NOT(element1->is_machining_feature())) OR
       (NOT(element1->_machining_feature()->isa("round_hole")))),
      SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE);
  hole0 SET_TO ROSE_CAST(round_hole, element0->_machining_feature());
  hole1 SET_TO ROSE_CAST(round_hole, element1->_machining_feature());
  IFF(check_placement(hole0->feature_placement()));
  IFF(check_placement(hole1->feature_placement()));
  IFF(find_if_vertical(hole0->feature_placement()->axis(), &vertical));
  CHK((NOT(vertical)), FIRST_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL);
  IFF(find_if_vertical(hole1->feature_placement()->axis(), &vertical));
  CHK((NOT(vertical)), SECOND_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL);
  CHK((hypot((hole0->feature_placement()->location()->coordinates()->get(0) -
	      hole1->feature_placement()->location()->coordinates()->get(0)),
	     (hole0->feature_placement()->location()->coordinates()->get(1) -
	      hole1->feature_placement()->location()->coordinates()->get(1)))
       > ISO14649_TINY),
      SUBHOLES_OF_COUNTERSUNK_HOLE_MUST_BE_COAXIAL);
  z0 SET_TO hole0->feature_placement()->location()->coordinates()->get(2);
  z1 SET_TO hole1->feature_placement()->location()->coordinates()->get(2);
  CHK((z0 IS z1), COUNTERSUNK_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE);
  if (z0 > z1)
    {
      *upper_hole SET_TO hole0;
      lower_hole SET_TO hole1;
      upper_z SET_TO z0;
      lower_z SET_TO z1;
    }
  else /* if (z1 > z0) */
    {
      *upper_hole SET_TO hole1;
      lower_hole SET_TO hole0;
      upper_z SET_TO z1;
      lower_z SET_TO z0;
    }
  lower_diameter SET_TO lower_hole->diameter()->theoretical_size();
  upper_diameter1 SET_TO (*upper_hole)->diameter()->theoretical_size();
  CHK((upper_diameter1 <= lower_diameter),
      UPPER_HOLE_DIAMETER_OF_COUNTERSUNK_HOLE_MUST_BE_GREATER_THAN_LOWER);
  IFF(check_horizontal_plane((*upper_hole)->depth()));
  height SET_TO 
    -((*upper_hole)->depth()->position()->location()->coordinates()->get(2));
  CHK((fabs((upper_z - height) - lower_z) > ISO14649_TINY),
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_VERTICALLY);
  taper SET_TO (*upper_hole)->change_in_diameter();
  CHK((taper IS NULL), UPPER_HOLE_OF_COUNTERSUNK_HOLE_MUST_TAPER);
  if (taper->is_diameter_taper())
    {
      upper_diameter2 SET_TO
	taper->_diameter_taper()->final_diameter()->theoretical_size();
      *upper_hole_angle SET_TO
	((180/M_PI) * atan2(height,((upper_diameter1 - upper_diameter2)/2.0)));
    }
  else if (taper->is_angle_taper())
    {
      upper_diameter2 SET_TO
	(upper_diameter1 -(2 * height * tand(taper->_angle_taper()->angle())));
      *upper_hole_angle SET_TO (90 - taper->_angle_taper()->angle());
    }
  else
    CHK(1, UPPER_HOLE_TAPER_MUST_BE_DIAMETER_TAPER_OR_ANGLE_TAPER);
  CHK((fabs(upper_diameter2 - lower_diameter) > ISO14649_TINY),
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_IN_DIAMETER);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_direction_ratios

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The ratios are NULL: DIRECTION_RATIOS_MUST_NOT_BE_NULL.
   2. There are not exactly 3 elements:
      NUMBER_OF_DIRECTION_RATIOS_MUST_BE_THREE.
   3. All three direction ratios are zero: DIRECTION_RATIOS_ALL_ZERO.

Side Effects: None

Called By:
  check_placement
  check_planar_face
  check_plane_milling_strategies
  find_if_vertical

*/

static int check_direction_ratios(
  ListOfDouble * ratios)
{
  static char name[] SET_TO "check_direction_ratios";

  CHK((ratios IS NULL), DIRECTION_RATIOS_MUST_NOT_BE_NULL);
  CHK((ratios->size() ISNT 3), NUMBER_OF_DIRECTION_RATIOS_MUST_BE_THREE);
  CHK(((ratios->get(0) IS 0.0) AND
       (ratios->get(1) IS 0.0) AND
       (ratios->get(2) IS 0.0)), DIRECTION_RATIOS_ALL_ZERO);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_horizontal_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The surf is NULL: SURFACE_MUST_NOT_BE_NULL.
   2. The surf isn't a plane: SURFACE_MUST_BE_A_PLANE.
   3. check_placement returns an error code.
   4. The plane is not horizontal in the coordinate system in which it
      is located: PLANE_MUST_BE_HORIZONTAL.
   5. find_if_vertical returns an error code.

Side Effects: None

Called By:
  check_and_store
  check_countersunk_hole
  check_counterbore_hole
  check_planar_face
  check_rectangular_pocket
  find_cutting_depths
  op_center_drilling
  set_security_z_now

*/

static int check_horizontal_plane( /* ARGUMENTS                      */
 elementary_surface * surf)        /* the (should be) plane to check */
{
  static char name[] SET_TO "check_horizontal_plane";
  axis2_placement_3d * place;
  int vertical;
  
  CHK((surf IS NULL), SURFACE_MUST_NOT_BE_NULL);
  CHK((NOT(surf->isa("plane"))), SURFACE_MUST_BE_A_PLANE);
  place SET_TO surf->position();
  IFF(check_placement(place))
  IFF(find_if_vertical(place->axis(), &vertical));
  CHK((NOT vertical), PLANE_MUST_BE_HORIZONTAL);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_center_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. its_machining_strategy is not NULL:
      CENTER_DRILLING_MUST_NOT_HAVE_STRATEGY.
   2. overcut_length is not ROSE_NULL_REAL,
      CENTER_DRILLING_MUST_NOT_HAVE_OVERCUT_LENGTH.
   3. The cutting depth is ROSE_NULL_REAL:
      CENTER_DRILLING_MUST_HAVE_CUTTING_DEPTH.
   4. The cutting depth is not positive:
      CUTTING_DEPTH_MUST_BE_POSITIVE
   5.The cutting depth is greater than the feature depth:
      CENTER_DRILLING_CUTTING_DEPTH_MUST_NOT_BE_GREATER_THAN_DEPTH.
   6. The retract_plane is negative: RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   7. The feed on retract ratio is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   8. The dwell time is negative: DWELL_TIME_MUST_NOT_BE_NEGATIVE.

Side Effects: None

Called By: op_center_drilling

*/

static int check_op_center_drilling(    /* ARGUMENTS                        */
 center_drilling * the_center_drilling, /* the center drilling to check     */
 elementary_surface * depth_plane)      /* depth plane of feature being cut */
{
  static char name[] SET_TO "check_op_center_drilling";
  double cutting_depth;

  CHK((the_center_drilling->its_machining_strategy()),
      CENTER_DRILLING_MUST_NOT_HAVE_STRATEGY);
  CHK((the_center_drilling->overcut_length() ISNT ROSE_NULL_REAL),
      CENTER_DRILLING_MUST_NOT_HAVE_OVERCUT_LENGTH);
  cutting_depth SET_TO the_center_drilling->cutting_depth();
  CHK((cutting_depth IS ROSE_NULL_REAL),
      CENTER_DRILLING_MUST_HAVE_CUTTING_DEPTH);
  CHK((cutting_depth <= 0), CUTTING_DEPTH_MUST_BE_POSITIVE);
  CHK((cutting_depth >
       (0 - depth_plane->position()->location()->coordinates()->get(2))),
      CENTER_DRILLING_CUTTING_DEPTH_MUST_NOT_BE_GREATER_THAN_DEPTH);
  CHK(((the_center_drilling->retract_plane() ISNT ROSE_NULL_REAL) AND
       (the_center_drilling->retract_plane() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_center_drilling->feed_on_retract() ISNT ROSE_NULL_REAL) AND
       (the_center_drilling->feed_on_retract() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_center_drilling->dwell_time_bottom() ISNT ROSE_NULL_REAL) AND
       (the_center_drilling->dwell_time_bottom() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_counter_boring

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The counterboring operation does not belong to the hole being
      countersunk: OPERATION_MUST_BELONG_TO_FEATURE;
   2. The operation has a machining_strategy:
      COUNTERBORING_MUST_NOT_HAVE_STRATEGY.
   3. The operation has overcut length:
      COUNTERBORING_MUST_NOT_HAVE_OVERCUT_LENGTH.
   4. A negative retract plane distance is given:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   5. A feed on retract ratio is given that is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   6. A negative dwell time is given:  DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   7. The previous_diameter of the boring differs from lower_diameter:
      PREVIOUS_DIAMETER_MUST_NOT_DIFFER_FROM_LOWER_HOLE_DIAMETER.

Side Effects: None

Called By: op_counter_boring

This checks a boring operation used for counterboring a hole.

This is not checking anything that requires data about the tool.
That is done in check_tool_countersink.

*/

static int check_op_counter_boring( /* ARGUMENTS                        */
 round_hole * the_hole,             /* hole to be made by counterboring */
 boring * the_boring,               /* counterboring operation to check */
 double lower_diameter)             /* diameter of lower hole           */
{
  static char name[] SET_TO "check_op_counter_boring";
  Set (machining_operation) * feature_ops;
  int stop;
  int n;

  feature_ops SET_TO the_hole->its_operations();
  stop SET_TO feature_ops->size();
  for (n SET_TO 0; n < stop; n++)
    {
      if (the_boring IS (*feature_ops)[n])
	break;
    }
  CHK((n IS stop), OPERATION_MUST_BELONG_TO_FEATURE);
  CHK(the_boring->its_machining_strategy(),
      COUNTERBORING_MUST_NOT_HAVE_STRATEGY);
  CHK((the_boring->overcut_length() ISNT ROSE_NULL_REAL),
      COUNTERBORING_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK(((the_boring->retract_plane() ISNT ROSE_NULL_REAL) AND
       (the_boring->retract_plane() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_boring->feed_on_retract() ISNT ROSE_NULL_REAL) AND
       (the_boring->feed_on_retract() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_boring->dwell_time_bottom() ISNT ROSE_NULL_REAL) AND
       (the_boring->dwell_time_bottom() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK(((the_boring->previous_diameter() IS ROSE_NULL_REAL) OR
       (fabs(the_boring->previous_diameter() - lower_diameter) >
	ISO14649_TINY)),
      PREVIOUS_DIAMETER_MUST_NOT_DIFFER_FROM_LOWER_HOLE_DIAMETER);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_counter_sinking

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The countersinking operation does not belong to the hole being
      countersunk: OPERATION_MUST_BELONG_TO_FEATURE;
   2. The operation has a machining_strategy:
      COUNTERSINKING_MUST_NOT_HAVE_STRATEGY.
   3. The operation has overcut length:
      COUNTERSINKING_MUST_NOT_HAVE_OVERCUT_LENGTH.
   4. A negative retract plane distance is given:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   5. A feed on retract ratio is given that is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   6. A negative dwell time is given:  DWELL_TIME_MUST_NOT_BE_NEGATIVE.     

Side Effects: None

Called By: op_counter_sinking

This checks a countersinking operation.

This is not checking anything that requires data about the tool.
That is done in check_tool_countersink.

*/

static int check_op_counter_sinking( /* ARGUMENTS                         */
 round_hole * the_hole,              /* the hole to be countersunk        */
 counter_sinking * the_sinking)      /* countersinking operation to check */
{
  static char name[] SET_TO "check_op_counter_sinking";
  Set (machining_operation) * feature_ops;
  int stop;
  int n;

  feature_ops SET_TO the_hole->its_operations();
  stop SET_TO feature_ops->size();
  for (n SET_TO 0; n < stop; n++)
    {
      if (the_sinking IS (*feature_ops)[n])
	break;
    }
  CHK((n IS stop), OPERATION_MUST_BELONG_TO_FEATURE);
  CHK(the_sinking->its_machining_strategy(),
      COUNTERSINKING_MUST_NOT_HAVE_STRATEGY);
  CHK((the_sinking->overcut_length() ISNT ROSE_NULL_REAL),
      COUNTERSINKING_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK(((the_sinking->retract_plane() ISNT ROSE_NULL_REAL) AND
       (the_sinking->retract_plane() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_sinking->feed_on_retract() ISNT ROSE_NULL_REAL) AND
       (the_sinking->feed_on_retract() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_sinking->dwell_time_bottom() ISNT ROSE_NULL_REAL) AND
       (the_sinking->dwell_time_bottom() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The retract_plane is negative: RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   2. The feed on retract ratio is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   3. The dwell time is negative: DWELL_TIME_MUST_NOT_BE_NEGATIVE.

Side Effects: None

Called By: op_drilling

This checks a drilling operation.

*/

static int check_op_drilling( /* ARGUMENTS                       */
 drilling * the_drilling)     /* the drilling operation to check */
{
  static char name[] SET_TO "check_op_drilling";

  CHK(((the_drilling->retract_plane() ISNT ROSE_NULL_REAL) AND
       (the_drilling->retract_plane() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_drilling->feed_on_retract() ISNT ROSE_NULL_REAL) AND
       (the_drilling->feed_on_retract() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_drilling->dwell_time_bottom() ISNT ROSE_NULL_REAL) AND
       (the_drilling->dwell_time_bottom() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_finish_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. overcut_length is not ROSE_NULL_REAL:
      FINISH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH.
   2. an approach or retract strategy that is not a plunge strategy is used:
      CAN_HANDLE_ONLY_PLUNGE_STRATEGY.
   3. check_op_two5D returns an error code.

Side Effects: None

Called By: op_finish_milling_both

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (bottom_and_side_milling)
radial_cutting_depth:   OPTIONAL length_measure;
allowance_side:         OPTIONAL length_measure;
allowance_bottom:       OPTIONAL length_measure;
                        NO ATTRIBUTES         (bottom_and_side_finish_milling)

This is logically identical to check_op_rough_both. It checks finish
milling of the bottom and sides of a pocket.

*/

static int check_op_finish_both(              /* ARGUMENTS                   */
 bottom_and_side_finish_milling * the_finish) /* finish milling op. to check */
{
  static char name[] SET_TO "check_op_finish_both";

  IFF(check_op_two5D(the_finish, the_finish->axial_cutting_depth(),
		     the_finish->radial_cutting_depth(),
		     the_finish->allowance_side(),
		     the_finish->allowance_bottom()));
  CHK((the_finish->overcut_length() ISNT ROSE_NULL_REAL),
      FINISH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK((the_finish->approach() AND
       (NOT(the_finish->approach()->isa("plunge_strategy")))),
      FINISH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);
  CHK((the_finish->retract() AND
       (NOT(the_finish->retract()->isa("plunge_strategy")))),
      FINISH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_finish_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_two5D returns an error code.

Side Effects: None

Called By: op_finish_milling_plane

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (plane_milling)
allowance_bottom:       OPTIONAL length_measure;
                        NO ATTRIBUTES            (plane_finish_milling)

Notes:

For a plane_finish_milling operation, radial_cutting_depth is not an
attribute (unlike in side_milling and bottom_and_side_milling, which
have it). If its_machining_strategy is given, however, the
radial_cutting_depth follows from its overlap attribute. The
radial_cutting_depth given here to check_op_two5D is 1, a value known
to be OK as far as check_op_two5D is concerned. The overlap is checked
in check_plane_milling_strategies.

The overcut_length is also checked in check_plane_milling_strategies
(not here) because acceptable values depend on the strategy.

*/

static int check_op_finish_plane(   /* ARGUMENTS                         */
 plane_finish_milling * the_finish) /* finish milling operation to check */
{
  static char name[] SET_TO "check_op_finish_plane";

  IFF(check_op_two5D(the_finish, the_finish->axial_cutting_depth(), 1, 1,
		     the_finish->allowance_bottom()));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_multistep_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. retract_plane is not ROSE_NULL_REAL and is negative:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   2. dwell_time_bottom is not ROSE_NULL_REAL and is negative:
      BOTTOM_DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   3. dwell_time_step is not ROSE_NULL_REAL and is negative:
      STEP_DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   4. A drilling strategy is given:
      CANNOT_HANDLE_STRATEGY_FOR_MULTISTEP_DRILLING.
   5. depth_of_step is ROSE_NULL_REAL: PECK_AMOUNT_MUST_BE_GIVEN.
   6. depth_of_step is not positive: PECK_AMOUNT_MUST_BE_POSITIVE.
   7. feed_on_retract is not ROSE_NULL_REAL and not greater
      than ISO14649_TINY: FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.

Side Effects: None

Called By: op_multistep_drilling

This checks a multistep drilling operation.

*/

static int check_op_multistep_drilling( /* ARGUMENTS                       */
 multistep_drilling * the_drilling)     /* the multistep drilling to check */
{
  static char name[] SET_TO "check_op_multistep_drilling";

  CHK((the_drilling->its_machining_strategy() ISNT NULL),
      CANNOT_HANDLE_STRATEGY_FOR_MULTISTEP_DRILLING);
  CHK(((the_drilling->retract_plane() ISNT ROSE_NULL_REAL) AND
       (the_drilling->retract_plane() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_drilling->feed_on_retract() ISNT ROSE_NULL_REAL) AND
       (the_drilling->feed_on_retract() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_drilling->dwell_time_bottom() ISNT ROSE_NULL_REAL) AND
       (the_drilling->dwell_time_bottom() < 0.0)),
      BOTTOM_DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK(((the_drilling->dwell_time_step() ISNT ROSE_NULL_REAL) AND
       (the_drilling->dwell_time_step() < 0.0)),
      STEP_DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK((the_drilling->depth_of_step() IS ROSE_NULL_REAL),
      PECK_AMOUNT_MUST_BE_GIVEN);
  CHK((the_drilling->depth_of_step() <= 0), PECK_AMOUNT_MUST_BE_POSITIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_reaming

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The retract_plane is negative: RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   2. The feed on retract ratio is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   3. The dwell time is negative: DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   4. depth_of_testcut isn't NULL: REAMING_MUST_NOT_HAVE_DEPTH_OF_TESTCUT.
   5. waiting_position isn't NULL: REAMING_MUST_NOT_HAVE_WAITING_POSITION.

Side Effects: None

Called By: op_reaming

This checks a reaming operation.

*/

static int check_op_reaming( /* ARGUMENTS                      */
 reaming * the_reaming)      /* the reaming operation to check */
{
  static char name[] SET_TO "check_op_reaming";

  CHK(((the_reaming->retract_plane() ISNT ROSE_NULL_REAL) AND
       (the_reaming->retract_plane() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_reaming->feed_on_retract() ISNT ROSE_NULL_REAL) AND
       (the_reaming->feed_on_retract() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_reaming->dwell_time_bottom() ISNT ROSE_NULL_REAL) AND
       (the_reaming->dwell_time_bottom() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK((the_reaming->depth_of_testcut() ISNT ROSE_NULL_REAL),
      REAMING_MUST_NOT_HAVE_DEPTH_OF_TESTCUT);
  CHK((the_reaming->waiting_position() ISNT NULL),
      REAMING_MUST_NOT_HAVE_WAITING_POSITION);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_rough_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. overcut_length is not ROSE_NULL_REAL:
      ROUGH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH.
   2. an approach or retract strategy that is not a plunge strategy is used:
      CAN_HANDLE_ONLY_PLUNGE_STRATEGY.
   3. check_op_two5D returns an error code.

Side Effects: None

Called By: op_rough_milling_both

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (bottom_and_side_milling)
radial_cutting_depth:   OPTIONAL length_measure;
allowance_side:         OPTIONAL length_measure;
allowance_bottom:       OPTIONAL length_measure;

This is logically identical to check_op_finish_both. It checks rough
milling of the bottom and sides of a pocket.

*/

static int check_op_rough_both(             /* ARGUMENTS                    */
 bottom_and_side_rough_milling * the_rough) /* rough milling oper. to check */
{
  static char name[] SET_TO "check_op_rough_both";

  IFF(check_op_two5D(the_rough, the_rough->axial_cutting_depth(),
		     the_rough->radial_cutting_depth(),
		     the_rough->allowance_side(),
		     the_rough->allowance_bottom()));
  CHK((the_rough->overcut_length() ISNT ROSE_NULL_REAL),
      ROUGH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK((the_rough->approach() AND
       (NOT(the_rough->approach()->isa("plunge_strategy")))),
      ROUGH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);
  CHK((the_rough->retract() AND
       (NOT(the_rough->retract()->isa("plunge_strategy")))),
      ROUGH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_rough_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_two5D returns an error code.

Side Effects: None

Called By: op_rough_milling_plane

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (plane_milling)
allowance_bottom:       OPTIONAL length_measure;
                        NO ATTRIBUTES            (plane_rough_milling)

Notes:

For a plane_rough_milling operation, radial_cutting_depth is not an
attribute (unlike in side_milling and bottom_and_side_milling, which
have it). If its_machining_strategy is given, however, the
radial_cutting_depth follows from its overlap attribute. The
radial_cutting_depth given here to check_op_two5D is 1, a value known
to be OK as far as check_op_two5D is concerned. The overlap is checked
in check_plane_milling_strategies.

The overcut_length is also checked in check_plane_milling_strategies
(not here) because acceptable values depend on the strategy.

*/

static int check_op_rough_plane(  /* ARGUMENTS                        */
 plane_rough_milling * the_rough) /* rough milling operation to check */
{
  static char name[] SET_TO "check_op_rough_plane";

  IFF(check_op_two5D(the_rough, the_rough->axial_cutting_depth(), 1, 1,
		     the_rough->allowance_bottom()));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_two5D

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. An approach or retract strategy that has a tool_orientation is used:
      TOOL_ORIENTATION_MUST_BE_NULL.
   2. retract_plane is not ROSE_NULL_REAL and is negative:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   3. axial_cutting_depth is not ROSE_NULL_REAL and is negative:
      AXIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE.
   4. radial_cutting_depth is not ROSE_NULL_REAL and is negative:
      RADIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE.
   5. allowance_side is not ROSE_NULL_REAL and is negative:
      ALLOWANCE_SIDE_MUST_NOT_BE_NEGATIVE.
   6. allowance_bottom is not ROSE_NULL_REAL and is negative:
      ALLOWANCE_BOTTOM_MUST_NOT_BE_NEGATIVE.

Side Effects: None

Called By:
  check_op_finish_both
  check_op_finish_plane
  check_op_rough_both
  check_op_rough_plane

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)

*/

static int check_op_two5D(         /* ARGUMENTS                 */
 two5D_milling_operation * the_op, /* operation to check        */
 double axial,                     /* axial depth to check      */
 double radial,                    /* radial depth to check     */
 double allow_side,                /* side allowance to check   */
 double allow_bottom)              /* bottom allowance to check */
{
  static char name[] SET_TO "check_op_two5D";

  CHK((the_op->approach() AND the_op->approach()->tool_orientation()),
      TOOL_ORIENTATION_MUST_BE_NULL);
  CHK((the_op->retract() AND the_op->retract()->tool_orientation()),
      TOOL_ORIENTATION_MUST_BE_NULL);
  CHK(((the_op->retract_plane() ISNT ROSE_NULL_REAL) AND
       (the_op->retract_plane() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((axial ISNT ROSE_NULL_REAL) AND (axial < 0)),
      AXIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE);
  CHK(((radial ISNT ROSE_NULL_REAL) AND (radial < 0)),
      RADIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE);
  CHK(((allow_side ISNT ROSE_NULL_REAL) AND (allow_side < 0)),
      ALLOWANCE_SIDE_MUST_NOT_BE_NEGATIVE);
  CHK(((allow_bottom ISNT ROSE_NULL_REAL) AND (allow_bottom < 0)),
      ALLOWANCE_BOTTOM_MUST_NOT_BE_NEGATIVE);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_placement

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The place is NULL: PLACEMENT_MUST_NOT_BE_NULL
   2. The location of place is NULL: PLACEMENT_LOCATION_MUST_NOT_BE_NULL.
   3. The axis of place is NULL: PLACEMENT_AXIS_MUST_NOT_BE_NULL.
   4. The ref_direction of place is NULL:
      PLACEMENT_REF_DIRECTION_MUST_NOT_BE_NULL.
   5. The coordinates of the location of place is NULL:
      PLACEMENT_COORDINATES_MUST_NOT_BE_NULL.
   6. check_direction_ratios applied to the direction_ratios of the axis
      or the ref_direction of place returns an error code.
   7. There are not exactly three origin coordinates:
      PLACEMENT_ORIGIN_MUST_HAVE_THREE_COORDS.
   8. Any of the coordinates of the origin is ROSE_NULL_REAL:
      PLACEMENT_ORIGIN_COORDINATE_VALUE_MUST_BE_GIVEN.
   9. Any of the coordinates of the axis is ROSE_NULL_REAL:
      PLACEMENT_AXIS_COORDINATE_VALUE_MUST_BE_GIVEN.
  10. Any of the coordinates of the ref_direction is ROSE_NULL_REAL:
      PLACEMENT_REF_DIRECTION_COORDINATE_VALUE_MUST_BE_GIVEN.
  11. The square of the axis length is less than ISO14649_TINY:
      AXIS_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY.
  12. The square of the ref_direction length is less than ISO14649_TINY:
      REF_DIRECTION_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY.
  13. The dot product of the axis and ref_direction is more than ISO14649_TINY:
      AXIS_OF_PLACEMENT_MUST_BE_PERPENDICULAR_TO_REF_DIRECTION.


Side Effects:  None

Called By:
  check_counterbore_hole
  check_countersunk_hole
  check_horizontal_plane
  find_location
  is_default_placement

This checks that an axis2_placement_3d is in good format. This is not
requiring the axis or ref_direction to be normalized.

*/

static int check_placement(  /* ARGUMENTS               */
 axis2_placement_3d * place) /* axis placement to check */
{
  static char name[] SET_TO "check_placement";
  ListOfDouble * origin_coords; 
  ListOfDouble * axis_ratios; 
  ListOfDouble * ref_ratios;
  double axis_x;
  double axis_y;
  double axis_z;
  double ref_x;
  double ref_y;
  double ref_z;

  CHK((place IS NULL), PLACEMENT_MUST_NOT_BE_NULL);
  CHK((place->location() IS NULL), PLACEMENT_LOCATION_MUST_NOT_BE_NULL);
  CHK((place->axis() IS NULL), PLACEMENT_AXIS_MUST_NOT_BE_NULL);
  CHK((place->ref_direction() IS NULL),
      PLACEMENT_REF_DIRECTION_MUST_NOT_BE_NULL);
  origin_coords SET_TO place->location()->coordinates();
  axis_ratios SET_TO place->axis()->direction_ratios();
  ref_ratios SET_TO place->ref_direction()->direction_ratios();
  CHK((origin_coords IS NULL), PLACEMENT_COORDINATES_MUST_NOT_BE_NULL);
  IFF(check_direction_ratios(axis_ratios));
  IFF(check_direction_ratios(ref_ratios));
  CHK((origin_coords->size() ISNT 3), PLACEMENT_ORIGIN_MUST_HAVE_THREE_COORDS);
  CHK(((origin_coords->get(0) IS ROSE_NULL_REAL) OR
       (origin_coords->get(1) IS ROSE_NULL_REAL) OR
       (origin_coords->get(2) IS ROSE_NULL_REAL)), 
      PLACEMENT_ORIGIN_COORDINATE_VALUE_MUST_BE_GIVEN);
  axis_x SET_TO axis_ratios->get(0);
  axis_y SET_TO axis_ratios->get(1);
  axis_z SET_TO axis_ratios->get(2);
  ref_x SET_TO ref_ratios->get(0);
  ref_y SET_TO ref_ratios->get(1);
  ref_z SET_TO ref_ratios->get(2);
  CHK(((axis_x IS ROSE_NULL_REAL) OR
       (axis_y IS ROSE_NULL_REAL) OR
       (axis_z IS ROSE_NULL_REAL)),
      PLACEMENT_AXIS_COORDINATE_VALUE_MUST_BE_GIVEN);
  CHK(((ref_x IS ROSE_NULL_REAL) OR
       (ref_y IS ROSE_NULL_REAL) OR
       (ref_z IS ROSE_NULL_REAL)),
      PLACEMENT_REF_DIRECTION_COORDINATE_VALUE_MUST_BE_GIVEN);
  CHK((((axis_x * axis_x) + (axis_y * axis_y) + (axis_z * axis_z))
       < ISO14649_TINY), AXIS_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY);
  CHK((((ref_x * ref_x) + (ref_y * ref_y) + (ref_z * ref_z))
       < ISO14649_TINY), REF_DIRECTION_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY);
  CHK((fabs((axis_x * ref_x) + (axis_y * ref_y) + (axis_z * ref_z))
       > ISO14649_TINY),
      AXIS_OF_PLACEMENT_MUST_BE_PERPENDICULAR_TO_REF_DIRECTION);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_planar_face

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The course_of_travel of the_face is NULL:
      PLANAR_FACE_COURSE_OF_TRAVEL_MUST_NOT_BE_NULL.
   2. The course_of_travel has a placement:
      CANNOT_HANDLE_PLACEMENT_OF_COURSE_OF_TRAVEL.
   3. The course_of_travel distance is NULL:
      COURSE_OF_TRAVEL_DISTANCE_MUST_NOT_BE_NULL.
   4. The course_of_travel distance its_theoretical_size is not positive:
      WIDTH_OF_PLANAR_FACE_MUST_BE_POSITIVE.
   5. The course_of_travel direction is NULL:
      COURSE_OF_TRAVEL_DIRECTION_MUST_NOT_BE_NULL
   6. check_direction_ratios applied to the direction_ratios in the
      course_of_travel direction returns an error code.
   7. The X and Z direction_ratios in the course_of_travel are not both 0:
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_FEATURE_Y_AXIS.
   8. The Y direction_ratio in the course_of_travel is not positive:
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_POSITIVE_FEATURE_Y_AXIS.
   9. The removal_boundary of the_face is NULL:
      PLANAR_FACE_REMOVAL_BOUNDARY_MUST_NOT_BE_NULL.
  10. The removal_boundary has a placement:
      CANNOT_HANDLE_PLACEMENT_OF_REMOVAL_BOUNDARY.
  11. The removal_boundary profile_length is NULL:
      REMOVAL_BOUNDARY_PROFILE_LENGTH_MUST_NOT_BE_NULL.
  12. The its_parameter_unit of the removal_boundary profile_length is
      NULL or not 'MM' or 'mm': LENGTH_UNITS_MUST_BE_MILLIMETERS.
  13. The its_parameter_value of the removal_boundary profile_length is
      not positive: LENGTH_OF_PLANAR_FACE_MUST_BE_POSITIVE.
  14. The set its_boss is NULL: PLANAR_FACE_ITS_BOSS_MUST_NOT_BE_NULL.
  15. The set its_boss is not empty: CANNOT_HANDLE_BOSS_ON_PLANAR_FACE.
  16. check_horizontal_plane applied to the depth returns an error code.
  17. The depth plane of the_face is not below the top:
      PLANE_DEPTH_MUST_BE_BELOW_PLANE_TOP.

Side Effects: The values of plane_length, plane_width, and plane_depth
              are set.

Called By: mill_planar

Data for planar_face
----------------------
its_id:             identifier; (manufacturing_feature)
its_workpiece:      workpiece;
its_operations:     SET [0:?] OF machining_operation;
feature_placement:  axis2_placement_3d; (two5D_manufacturing_feature)
depth:              elementary_surface (machining_feature)
course_of_travel:   linear_path;
removal_boundary:   linear_profile;
face_boundary:      OPTIONAL closed_profile;
its_boss:           SET [0:?] OF boss;

Data for linear_profile
-----------------------
placement:          OPTIONAL  axis2_placement_3d; (profile)
NO ATTRIBUTES                                     (open_profile)
profile_length:     numeric_parameter (linear_profile);

Data for linear_path
--------------------
placement:          OPTIONAL  axis2_placement_3d; (travel_path)
distance:           toleranced_length_measure; (linear_path)
its_direction:      direction;

Notes:

This is ignoring the face_boundary since it is not used in determining
the tool path.

The removal_boundary lies along the positive X-axis of its native
coordinate system (starting at the origin), so it lies on the feature
X-axis when the placement of the removal_boundary is NULL (which is
required here).

We are requiring the course_of_travel to be along the positive Y-axis
of the feature here. This is done by requiring that its its_direction
be along the Y-axis and its placement be NULL.

*/

static int check_planar_face( /* ARGUMENTS                              */
 planar_face * the_face,      /* the planar face being checked          */
 double * plane_length,       /* length (X-size) of the_face, set here  */
 double * plane_width,        /* width (Y-size) of the_face, set here   */
 double * plane_depth)        /* depth of the_face, set positive here   */
{
  static char name[] SET_TO "check_planar_face";
  ListOfDouble * components;
  numeric_parameter * profile_length;

  CHK((the_face->course_of_travel() IS NULL),
      PLANAR_FACE_COURSE_OF_TRAVEL_MUST_NOT_BE_NULL);
  CHK((the_face->course_of_travel()->placement() ISNT NULL),
      CANNOT_HANDLE_PLACEMENT_OF_COURSE_OF_TRAVEL);
  CHK((the_face->course_of_travel()->distance() IS NULL),
      COURSE_OF_TRAVEL_DISTANCE_MUST_NOT_BE_NULL);
  *plane_width SET_TO
    the_face->course_of_travel()->distance()->theoretical_size();
  CHK((*plane_width <= 0.0), WIDTH_OF_PLANAR_FACE_MUST_BE_POSITIVE);
  CHK((the_face->course_of_travel()->its_direction() IS NULL),
      COURSE_OF_TRAVEL_DIRECTION_MUST_NOT_BE_NULL);
  components SET_TO
    the_face->course_of_travel()->its_direction()->direction_ratios();
  IFF(check_direction_ratios(components));
  CHK(((components->get(0) ISNT 0) OR (components->get(2) ISNT 0)),
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_FEATURE_Y_AXIS);
  CHK((components->get(1) <= 0),
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_POSITIVE_FEATURE_Y_AXIS);
  CHK((the_face->removal_boundary() IS NULL),
      PLANAR_FACE_REMOVAL_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((the_face->removal_boundary()->placement() ISNT NULL),
      CANNOT_HANDLE_PLACEMENT_OF_REMOVAL_BOUNDARY);
  profile_length SET_TO the_face->removal_boundary()->profile_length();
  CHK((profile_length IS NULL),
      REMOVAL_BOUNDARY_PROFILE_LENGTH_MUST_NOT_BE_NULL);
  CHK(((profile_length->its_parameter_unit() IS NULL) OR
       (strcmp(profile_length->its_parameter_unit(), "MM") AND
	strcmp(profile_length->its_parameter_unit(), "mm"))),
      LENGTH_UNITS_MUST_BE_MILLIMETERS);
  *plane_length SET_TO profile_length->its_parameter_value();
  CHK((*plane_length <= 0), LENGTH_OF_PLANAR_FACE_MUST_BE_POSITIVE);
  CHK((the_face->its_boss() IS NULL),
      PLANAR_FACE_ITS_BOSS_MUST_NOT_BE_NULL);
  CHK((the_face->its_boss()->size() ISNT 0),
      CANNOT_HANDLE_BOSS_ON_PLANAR_FACE);
  IFF(check_horizontal_plane(the_face->depth()));
  *plane_depth SET_TO
    -(the_face->depth()->position()->location()->coordinates()->get(2));
  CHK((*plane_depth <= 0), PLANE_DEPTH_MUST_BE_BELOW_PLANE_TOP);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_plane_milling_strategies

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. An approach strategy is given that is not a plunge_toolaxis:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_APPROACH_FOR_PLANE_MILLING.
   2. A unidirectional_milling strategy is given with an overcut_length
      that is not at least 1.2 times the tool diameter:
      OVERCUT_FOR_UNIDIRECTIONAL_MUST_BE_AT_LEAST_1POINT2_TOOL_DIAMETERS.
   3. A bidirectional_milling strategy is given with a connection strategy that
      is not straghtline: CANNOT_HANDLE_NON_STRAIGHTLINE_CONNECTION_STRATEGY.
   4. A bidirectional_milling strategy is given with an overcut_length
      that is not at least 0.5 times the tool diameter:
      OVERCUT_FOR_BIDIRECTIONAL_MUST_BE_AT_LEAST_HALF_A_TOOL_DIAMETER.
   5. A feed_direction is given, but check_direction_ratios applied to
      its direction_ratios returns an error code.
   6. A feed_direction is given that is not parallel to the X of Y-axis
      of the planar_face:
      FEED_DIRECTION_MUST_PARALLEL_X_OR_Y_AXIS_OF_PLANAR_FACE
   7. An inside strategy is given that is neither unidirectional_milling
      nor bidirectional_milling:
      CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING.
   8. An inside strategy is given with an overlap that is not between 0
      and 1: OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE
   9. A retract strategy is given that is not a plunge_toolaxis:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT_FOR_PLANE_MILLING.

Side Effects:  See below

Called By: mill_planar

Some type of strategy is needed for each of the three phases of
milling (enter, inside, leave), but they are optional in the_cut. If a
strategy is missing for any phase, this makes a strategy for that
phase and inserts it in the_cut. The inside strategy this inserts (if
none is given) is bidirectional_milling, with overlap of 0.2, feed_direction
parallel to the positive X-axis of the feature, the stepover direction
to the right of the feed_direction, and a straight line connection
between cuts.

The overlap of 0.2 is used to get the cleanest cut, as well as to
minimize the number of cuts.

If an approach strategy is given, it must be a plunge_toolaxis.

If a retract strategy is given, it must be a plunge_toolaxis.

If an inside strategy is given, it must be a unidirectional_milling or
bidirectional_milling.

It is not clear from Part 11 what coordinate system a milling strategy
uses for specifying directions. The best choice would seem to be the
coordinate system of the feature, so that is what is assumed here.

If the_cut does not give an overcut_length, it is set in mill_planar
as 1.25 times the tool diameter. For unidirectional_milling this is needed
to avoid collisions when plunging. For bidirectional_milling this gets the
tool clear of the planar_face before it changes direction, leaving a
better surface finish than if that is not done. If the_cut does give
an overcut_length, it is checked here that overcut_length at least 1.2
times the tool diameter for unidirectional_milling (to avoid collisions)
and at least 0.5 times tool diameter for bidirectional_milling (to ensure
the entire surface gets cut).  This is assuming that Figure 1 in Part 11
is correct in its depiction of the meaning of overcut_length (I would
not have defined it that way).

data for unidirectional_milling
-------------------------------
overlap:                         OPTIONAL positive_ratio_measure (two5D_m_s)
allow_multiple_passes:           OPTIONAL BOOLEAN
feed_direction:                  OPTIONAL direction (unidirectional_milling) 
cutmode:                         OPTIONAL cutmode_type

data for bidirectional_milling
------------------------------
overlap:                         OPTIONAL positive_ratio_measure (two5D_m_s)
allow_multiple_passes:           OPTIONAL BOOLEAN
feed_direction:                  OPTIONAL direction (bidirectional_milling) 
stepover_direction:              OPTIONAL left_or_right
its_stroke_connection_strategy:  OPTIONAL stroke_connection_strategy

*/

static int check_plane_milling_strategies(    /* ARGUMENTS                  */
 plane_milling * the_cut,                     /* milling operation to do    */
 double diameter,                             /* tool diameter              */
 approach_retract_strategy ** enter_strategy, /* apprch set here if missing */
 approach_retract_strategy ** leave_strategy, /* retrct set here if missing */
 two5D_milling_strategy ** inside_strategy)   /* inside set here if missing */
{
  static char name[] SET_TO "check_plane_milling_strategies";
  ListOfDouble * components;
  stroke_connection_strategy con;
  double overlap;
  double overcut;
  bidirectional_milling * bi;
  unidirectional_milling * uni;


  if (the_cut->approach() IS NULL)
    {
      *enter_strategy SET_TO new plunge_toolaxis(NULL);
      the_cut->approach(*enter_strategy);
    }
  else
    CHK((NOT(the_cut->approach()->isa("plunge_toolaxis"))),
	CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_APPROACH_FOR_PLANE_MILLING);
  if (the_cut->its_machining_strategy() IS NULL)
    {
      components SET_TO new ListOfDouble;
      components->add(1.0);
      components->add(0.0);
      components->add(0.0);
      overlap SET_TO 0.2;
      *inside_strategy SET_TO
	new bidirectional_milling(overlap, ROSE_TRUE,
				  new direction("FIRST_CUT", components),
				  left_or_right_right,
				  stroke_connection_strategy_straghtline);
      the_cut->its_machining_strategy(*inside_strategy);
    }
  else if (the_cut->its_machining_strategy()->isa("unidirectional_milling"))
    {
      uni SET_TO ROSE_CAST(unidirectional_milling,
			   the_cut->its_machining_strategy());
      overlap SET_TO uni->overlap();
      overcut SET_TO the_cut->overcut_length();
      CHK(((overcut ISNT ROSE_NULL_REAL) AND (overcut < (1.2 * diameter))),
	  OVERCUT_FOR_UNIDIRECTIONAL_MUST_BE_AT_LEAST_1POINT2_TOOL_DIAMETERS);
      if (uni->feed_direction())
	{
	  components SET_TO uni->feed_direction()->direction_ratios();
	  IFF(check_direction_ratios(components));
	  CHK(((components->get(2) ISNT 0) OR
	       ((components->get(0) IS   0) AND (components->get(1) IS   0)) OR
	       ((components->get(0) ISNT 0) AND (components->get(1) ISNT 0))),
	      FEED_DIRECTION_MUST_PARALLEL_X_OR_Y_AXIS_OF_PLANAR_FACE);
	}
    }
  else if (the_cut->its_machining_strategy()->isa("bidirectional_milling"))
    {
      bi SET_TO ROSE_CAST(bidirectional_milling,
			  the_cut->its_machining_strategy());
      con SET_TO bi->its_stroke_connection_strategy();
      CHK(((con ISNT stroke_connection_strategy_NULL) AND
	   (con ISNT stroke_connection_strategy_straghtline)),
	  CANNOT_HANDLE_NON_STRAIGHTLINE_CONNECTION_STRATEGY);
      overlap SET_TO bi->overlap();
      overcut SET_TO the_cut->overcut_length();
      CHK(((overcut ISNT ROSE_NULL_REAL) AND (overcut < (0.5 * diameter))),
	  OVERCUT_FOR_BIDIRECTIONAL_MUST_BE_AT_LEAST_HALF_A_TOOL_DIAMETER);
      if (bi->feed_direction())
	{
	  components SET_TO bi->feed_direction()->direction_ratios();
	  IFF(check_direction_ratios(components));
	  CHK(((components->get(2) ISNT 0) OR
	       ((components->get(0) IS   0) AND (components->get(1) IS   0)) OR
	       ((components->get(0) ISNT 0) AND (components->get(1) ISNT 0))),
	      FEED_DIRECTION_MUST_PARALLEL_X_OR_Y_AXIS_OF_PLANAR_FACE);
	}
    }
  else
    CHK(1, CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING);
  CHK(((overlap ISNT ROSE_NULL_REAL) AND ((overlap <= 0) OR (overlap >= 1))),
      OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE);
  if (the_cut->retract() IS NULL)
    {
      *leave_strategy SET_TO new plunge_toolaxis();
      the_cut->retract(*leave_strategy);
    }
  else
    CHK((NOT(the_cut->retract()->isa("plunge_toolaxis"))),
	CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT_FOR_PLANE_MILLING);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_rectangular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The boundary of the pocket is NULL: POCKET_BOUNDARY_MUST_NOT_BE_NULL.
   2. The boundary of the pocket is not a rectangular_closed_profile:
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE.
   3. The placement of the profile is not NULL:
      CANNOT_HANDLE_PROFILE_PLACEMENT.
   4. The profile width is NULL: POCKET_PROFILE_WIDTH_MUST_NOT_BE_NULL.
   5. The profile length is NULL: POCKET_PROFILE_LENGTH_MUST_NOT_BE_NULL.
   6. The profile width is not positive: POCKET_WIDTH_MUST_BE_POSITIVE.
   7. The profile length is not positive: POCKET_LENGTH_MUST_BE_POSITIVE.
   8. The profile width exceeds length: POCKET_WIDTH_MUST_NOT_EXCEED_LENGTH.
   9. The boss set of the pocket is NULL: POCKET_BOSS_SET_MUST_NOT_BE_NULL.
  10. The boss set of the pocket is not empty: CANNOT_HANDLE_BOSSES_IN_POCKET.
  11. The tolerance on the pocket width is NULL:
      POCKET_WIDTH_TOLERANCE_MUST_NOT_BE_NULL.
  12. The tolerance on the pocket length is NULL:
      POCKET_LENGTH_TOLERANCE_MUST_NOT_BE_NULL.
  13. The tolerance on the pocket length, width, or orthogonal_radius is not
      a plus_minus_value: CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE.
  14. A limit in the tolerance on the pocket length, width, or
      orthogonal_radius is negative: TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE.
  15. The sum of upper and lower tolerances on the length, width, or
      orthogonal_radius is less than 0.01:
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM.
  16. check_horizontal_plane applied to the pocket depth returns an error code.
  17. The z-coordinate of the pocket depth location is not negative:
      POCKET_DEPTH_MUST_BE_BELOW_POCKET_TOP.
  18. The pocket slope is neither ROSE_NULL_REAL nor zero:
      CANNOT_HANDLE_SLOPED_POCKET.
  19. The pocket planar_radius is neither ROSE_NULL_REAL nor zero:
      CANNOT_HANDLE_POCKET_WITH_FILLET_AT_BOTTOM.
  20. The pocket othogonal_radius is NULL:
      POCKET_CORNER_RADIUS_MUST_NOT_BE_NULL.
  21. The pocket othogonal_radius is not positive:
      POCKET_CORNER_RADIUS_MUST_BE_POSITIVE.
  22. The pocket othogonal_radius is greater than half the pocket width:
      POCKET_CORNER_RADIUS_MUST_NOT_EXCEED_HALF_POCKET_WIDTH.

Side Effects:  This sets the values of pocket_length, pocket_width,
      pocket_depth, and pocket_radius.

Called By:
  finish_mill_both_closed_pocket
  rough_mill_both_closed_pocket

Data for closed_pocket
----------------------
its_id:             identifier; (manufacturing_feature)
its_workpiece:      workpiece;
its_operations:     SET [0:?] OF machining_operation;
feature_placement:  axis2_placement_3d; (two5D_manufacturing_feature)
depth:              elementary_surface (machining_feature)
its_boss:           SET [0:?] OF boss; (pocket)
slope:              OPTIONAL plane_angle_measure;
bottom_condition:   pocket_bottom_condition;
planar_radius:      OPTIONAL toleranced_length_measure;
othogonal_radius:   OPTIONAL toleranced_length_measure;
feature_boundary:   closed_profile;

Data for rectangular_closed_profile
-----------------------------------
placement:          OPTIONAL axis2_placement_3d; (profile)
<no attributes>     (closed_profile)
profile_width:      toleranced_length_measure; (rectangular_closed_profile)
profile_length:     toleranced_length_measure;

Requiring the placement of the profile to be NULL could be removed, but it
would take a lot of code to deal with a placement.

*/

static int check_rectangular_pocket( /* ARGUMENTS                         */
 closed_pocket * the_pocket,         /* the pocket being checked          */
 double * pocket_length,             /* length of pocket, set here        */
 double * pocket_width,              /* width of pocket, set here         */
 double * pocket_depth,              /* depth of pocket, set here         */
 double * pocket_radius)             /* corner radius of pocket, set here */
{
  static char name[] SET_TO "check_rectangular_pocket";
  rectangular_closed_profile * bound;
  plus_minus_value * tolerate;

  CHK((the_pocket->feature_boundary() IS NULL),
      POCKET_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((NOT(the_pocket->feature_boundary()->isa("rectangular_closed_profile"))),
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE);
  bound SET_TO
    ROSE_CAST(rectangular_closed_profile, the_pocket->feature_boundary());
  CHK((bound->placement() ISNT NULL), CANNOT_HANDLE_PROFILE_PLACEMENT);
  CHK((bound->profile_width() IS NULL),
      POCKET_PROFILE_WIDTH_MUST_NOT_BE_NULL);
  CHK((bound->profile_length() IS NULL),
      POCKET_PROFILE_LENGTH_MUST_NOT_BE_NULL);
  *pocket_width SET_TO bound->profile_width()->theoretical_size();
  *pocket_length SET_TO bound->profile_length()->theoretical_size();
  CHK((*pocket_width <= 0), POCKET_WIDTH_MUST_BE_POSITIVE);
  CHK((*pocket_length <= 0), POCKET_LENGTH_MUST_BE_POSITIVE);
  CHK((*pocket_length < *pocket_width), POCKET_WIDTH_MUST_NOT_EXCEED_LENGTH);
  CHK((the_pocket->its_boss() IS NULL), POCKET_BOSS_SET_MUST_NOT_BE_NULL);
  CHK((the_pocket->its_boss()->size() ISNT 0), CANNOT_HANDLE_BOSSES_IN_POCKET);
  CHK((bound->profile_width()->implicit_tolerance() IS NULL),
      POCKET_WIDTH_TOLERANCE_MUST_NOT_BE_NULL);
  CHK((NOT
       (bound->profile_width()->implicit_tolerance()->is_plus_minus_value())),
      CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE);
  tolerate SET_TO 
    bound->profile_width()->implicit_tolerance()->_plus_minus_value();
  CHK(((tolerate->upper_limit() < 0) OR (tolerate->lower_limit() < 0)),
      TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE);
  CHK(((tolerate->upper_limit() + tolerate->lower_limit()) < 0.01),
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM);
  CHK((bound->profile_length()->implicit_tolerance() IS NULL),
      POCKET_LENGTH_TOLERANCE_MUST_NOT_BE_NULL);
  CHK((NOT
       (bound->profile_length()->implicit_tolerance()->is_plus_minus_value())),
      CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE);
  tolerate SET_TO 
    bound->profile_length()->implicit_tolerance()->_plus_minus_value();
  CHK(((tolerate->upper_limit() < 0) OR (tolerate->lower_limit() < 0)),
      TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE);
  CHK(((tolerate->upper_limit() + tolerate->lower_limit()) < 0.01),
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM);
  IFF(check_horizontal_plane(the_pocket->depth()));
  *pocket_depth SET_TO
    -(the_pocket->depth()->position()->location()->coordinates()->get(2));
  CHK((*pocket_depth <= 0), POCKET_DEPTH_MUST_BE_BELOW_POCKET_TOP);
  CHK(((the_pocket->slope() ISNT ROSE_NULL_REAL) AND
       (the_pocket->slope() ISNT 0.0)), CANNOT_HANDLE_SLOPED_POCKET);
  CHK(((the_pocket->planar_radius() ISNT NULL) AND
       (the_pocket->planar_radius()->theoretical_size() ISNT 0.0)),
      CANNOT_HANDLE_POCKET_WITH_FILLET_AT_BOTTOM);
  CHK((the_pocket->orthogonal_radius() IS NULL),
      POCKET_CORNER_RADIUS_MUST_NOT_BE_NULL);
  *pocket_radius SET_TO the_pocket->orthogonal_radius()->theoretical_size();
  CHK((*pocket_radius <= 0.0), POCKET_CORNER_RADIUS_MUST_BE_POSITIVE);
  CHK((*pocket_radius > ((*pocket_width + ISO14649_TINY) / 2.0)),
      POCKET_CORNER_RADIUS_MUST_NOT_EXCEED_HALF_POCKET_WIDTH);
  CHK((NOT(the_pocket->orthogonal_radius()->implicit_tolerance()->
	   is_plus_minus_value())),
      CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE);
  tolerate SET_TO
    the_pocket->orthogonal_radius()->implicit_tolerance()->_plus_minus_value();
  CHK(((tolerate->upper_limit() < 0) OR (tolerate->lower_limit() < 0)),
      TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE);
  CHK(((tolerate->upper_limit() + tolerate->lower_limit()) < 0.01),
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_rectangular_pocket_strategies

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The endmill will not fit into the pocket and leave the required
      side allowance: POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL.
   2. The endmill will not fit into the corner of the pocket and leave
      the required side allowance: TOOL_MUST_FIT_IN_CORNERS_OF_POCKET.
   3. There is room only to plunge_toolaxis on retract, but some other
      strategy is used:
      MUST_USE_PLUNGE_TOOLAXIS_TO_RETRACT_WHEN_POCKET_SAME_SIZE_AS_TOOL.
   4. There is room only to plunge_toolaxis on approach, but some other
      strategy is used:
      MUST_USE_PLUNGE_TOOLAXIS_TO_APPROACH_WHEN_POCKET_SAME_SIZE_AS_TOOL.
   5. The overlap given in the inside strategy of the_cut is used and
      is not between 0 and 1:  OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE.

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  rough_mill_both_closed_pocket

This is checking that the_endmill can be used to make the_pocket using
the strategies specified in the_cut.

Some type of strategy is needed for each of the three phases of milling
(enter, inside, leave), but they are optional in the_cut. If a strategy is
missing for any phase, this makes a strategy for that phase and inserts it
in the_cut.

The rules for selecting an approach strategy are as follows. Zigzag and
helix angles are 10 degrees in all cases.
1. If the width of the pocket is the width of the tool:
   a. Make a zigzag if the length of the pocket is greater than tool diameter.
   b. Plunge straight down if the length of the pocket is the tool diameter.
2. Otherwise, if width of the pocket is less than 1.4 times the tool diameter:
   a. Make a zigzag if length of pocket is more than 1.5 times tool diameter. 
   b. Make a helix that fits if not.
3. Otherwise, if width of the pocket is less than 1.8 times the tool diameter,
   make the largest helix that fits. The radius will be at least 0.2 times
   the tool diameter.
4. Otherwise, make a helix whose radius is 0.4 times tool diameter.

The endmill must already have been checked by check_tool_endmill when this
is called (because errors caught there will cause the system to crash here).

This assumes that width is not greater than length (which is checked by
check_rectangular_pocket).

This assumes the orthogonal_radius is not NULL (which is checked by
check_rectangular_pocket).

the_cut may be rough milling or finish milling.

This sets the stepover as follows.  The inside_strategy may include an
optional overlap attribute, which may be used to determine stepover.
The stepover, however, is also the optional attribute
radial_cutting_depth of the_cut. The spec does not say which one takes
precedence if both are used. Here, the radial_cutting_depth takes
precedence. If neither is given, the stepover is set here to the
radius of the endmill.

*/

static int check_rectangular_pocket_strategies(/* ARGUMENTS                  */
 double pocket_length,                         /* length of pocket           */
 double pocket_width,                          /* width of pocket            */
 double pocket_depth,                          /* depth of pocket            */
 double pocket_radius,                         /* corner radius of pocket    */
 bottom_and_side_milling * the_cut,            /* milling operation to do    */
 endmill * the_endmill,                        /* endmill to cut pocket with */
 double * stepover,                            /* stepover set here          */
 approach_retract_strategy ** enter_strategy,  /* apprch set here if missing */
 approach_retract_strategy ** leave_strategy,  /* retrct set here if missing */
 two5D_milling_strategy ** inside_strategy,    /* inside set here if missing */
 int is_finish)                                /* 1=finish cut, 0=rough cut  */
{
  static char name[] SET_TO "check_rectangular_pocket_strategies";
  double diameter;       /* endmill diameter */
  double extra_width;    /* amount of space available in width direction  */
  double extra_length;   /* amount of space available in length direction */
  double side;           /* side allowance */
  double overlap;        /* overlap for finding stepover */
  
  diameter SET_TO the_endmill->dimension()->diameter();
  side SET_TO ((the_cut->allowance_side() IS ROSE_NULL_REAL) ?
	       (is_finish ? 0 : ISO14649_ALLOW) : the_cut->allowance_side());
  extra_width  SET_TO (pocket_width  - (diameter + (2 * side)));
  extra_length SET_TO (pocket_length - (diameter + (2 * side)));
  CHK((extra_width < -(ISO14649_TINY)), POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL);
  CHK(((pocket_radius - side) < ((diameter / 2.0) - ISO14649_TINY)),
      TOOL_MUST_FIT_IN_CORNERS_OF_POCKET);
  if (the_cut->its_machining_strategy() IS NULL)
    {
      *inside_strategy SET_TO new contour_parallel(ROSE_NULL_REAL, ROSE_TRUE,
				rot_direction_cw, cutmode_type_conventional);
      the_cut->its_machining_strategy(*inside_strategy);
    }
  *stepover SET_TO the_cut->radial_cutting_depth();
  if (*stepover IS ROSE_NULL_REAL)
    {
      overlap SET_TO the_cut->its_machining_strategy()->overlap();
      if (overlap IS ROSE_NULL_REAL)
	overlap SET_TO 0.5;
      else
	CHK(((overlap < 0) OR (overlap > 1.0)),
	    OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE);
      *stepover SET_TO (diameter * (1 - overlap));
    }     
  if (the_cut->retract() IS NULL)
    {
      *leave_strategy SET_TO new plunge_toolaxis();
      the_cut->retract(*leave_strategy);
    }
  else if (extra_length < ISO14649_TINY)
    CHK((NOT(the_cut->retract()->isa("plunge_toolaxis"))),
        MUST_USE_PLUNGE_TOOLAXIS_TO_RETRACT_WHEN_POCKET_SAME_SIZE_AS_TOOL);
  if (the_cut->approach() IS NULL)
    {
      if (extra_width < ISO14649_TINY)
	{
	  if (extra_length < ISO14649_TINY)
	    *enter_strategy SET_TO new plunge_toolaxis(NULL);
	  else
	    *enter_strategy SET_TO
	      new plunge_zigzag(NULL, 10.0, MIN(extra_length, (3 * diameter)));
	}
      else if (extra_width < (diameter * 0.4))
	{
	  if (extra_length < (1.25 * extra_width))
	    *enter_strategy SET_TO
	      new plunge_helix(NULL, (extra_width / 2.0), 10.0);
	  else
	    *enter_strategy SET_TO
	      new plunge_zigzag(NULL, 10.0, MIN(extra_length, (3 * diameter)));
	}
      else if (extra_width < (diameter * 0.8))
	*enter_strategy SET_TO new plunge_helix(NULL, (extra_width/2.0), 10.0);
      else
	*enter_strategy SET_TO new plunge_helix(NULL, (diameter * 0.4), 10.0);
      the_cut->approach(*enter_strategy);
    }
  else if (extra_length < ISO14649_TINY)
    CHK((NOT(the_cut->approach()->isa("plunge_toolaxis"))),
        MUST_USE_PLUNGE_TOOLAXIS_TO_APPROACH_WHEN_POCKET_SAME_SIZE_AS_TOOL);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_center_drill

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cutting_tool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a center_drill:
      TOOL_BODY_MUST_BE_A_CENTER_DRILL.
   5. check_tool_dimension returns an error code.

Side Effects:  flute_length is set.

Called By: op_center_drilling

data
----

cutting_tool
------------
its_id                   label (machining_tool)
its_tool_body:           tool_body (cutting_tool)
its_cutting_edge:        LIST [1:?] OF cutting_component
overall_assembly_length: OPTIONAL length_measure

twist_drill
-----------
<no attributes>                   (tool_body)
dimension:               milling_tool_dimension (milling_tool_body)
number_of_teeth:         OPTIONAL INTEGER
hand_of_cut:             OPTIONAL hand
coolant_through_tool:    OPTIONAL BOOLEAN
pilot_length:            OPTIONAL length_measure
<no attributes>                   (centerdrill)

The tool_top_angle of the dimension must be given. This is checked in
check_tool_dimension.

*/

static int check_tool_center_drill( /* ARGUMENTS                    */
 machining_tool * the_tool,         /* the (should be) center_drill */
 double * flute_length)             /* flute_length, set here       */
{
  static char name[] SET_TO "check_tool_center_drill";
  tool_body * body;
  milling_tool_dimension * dimension;

  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isa("cutting_tool"))
    body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isa("center_drill"))
    dimension SET_TO (ROSE_CAST(center_drill, body))->dimension();
  else
    CHK(1, TOOL_BODY_MUST_BE_A_CENTER_DRILL);
  IFF(check_tool_dimension(dimension, 0, 1, 0));
  *flute_length SET_TO dimension->cutting_edge_length();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_counterbore

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cutting_tool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not an endmill: TOOL_BODY_MUST_BE_AN_ENDMILL.
   5. The diameter of the hole differs from the diameter of the endmill:
      ENDMILL_DIAMETER_MUST_EQUAL_HOLE_DIAMETER.
   6. The given cut_depth is not ROSE_NULL_REAL and it is the wrong
      depth: COUNTERBORE_DEPTH_MUST_EQUAL_CUTTING_DEPTH.
   7. The edge_length of the endmill is less than the depth of the
      hole: HOLE_MUST_NOT_BE_DEEPER_THAN_ENDMILL_IS_LONG.
   8. check_tool_dimension returns an error code.

Side Effects: See below

Called By: op_counter_boring

data
----

cutting_tool
------------
its_id                   label (machining_tool)
its_tool_body:           tool_body (cutting_tool)
its_cutting_edge:        LIST [1:?] OF cutting_component
overall_assembly_length: OPTIONAL length_measure

endmill
-----------
<no attributes>          (tool_body)
dimension:               milling_tool_dimension (milling_tool_body)
number_of_teeth:         OPTIONAL INTEGER
hand_of_cut:             OPTIONAL hand
coolant_through_tool:    OPTIONAL BOOLEAN
pilot_length:            OPTIONAL length_measure

If the cut_depth is ROSE_NULL_REAL, it is set to the correct depth.
Otherwise, this checks that cut_depth already is the correct depth.

The edge_radius, tool_top_angle, and tool_circumference_angle of the
dimension must all be zero or not given. This is checked in
check_tool_dimension. I.e., the endmill must have a flat end and not
be tapered.

*/

static int check_tool_counterbore( /* ARGUMENTS                         */
 machining_tool * the_tool,        /* tool to check                     */
 round_hole * upper_hole,          /* hole to be counterbored by tool   */
 double * cut_depth)               /* cutting depth given in operation  */
{
  static char name[] SET_TO "check_tool_counterbore";
  tool_body * body;
  endmill * the_endmill;
  milling_tool_dimension * dimension;
  double edge_length;
  double depth;

  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isa("cutting_tool"))
    body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isa("endmill"))
    {
      the_endmill SET_TO (ROSE_CAST(endmill, body));
      dimension SET_TO the_endmill->dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_AN_ENDMILL);
  IFF(check_tool_dimension(dimension, -1, -1, -1));

  edge_length SET_TO dimension->cutting_edge_length();
  depth SET_TO 
    -(upper_hole->depth()->position()->location()->coordinates()->get(2));
  CHK((edge_length < depth), HOLE_MUST_NOT_BE_DEEPER_THAN_ENDMILL_IS_LONG);
  CHK((fabs(dimension->diameter() -
	    upper_hole->diameter()->theoretical_size()) >
       ISO14649_TINY), ENDMILL_DIAMETER_MUST_EQUAL_HOLE_DIAMETER);
  if (*cut_depth IS ROSE_NULL_REAL)
    *cut_depth SET_TO depth;
  else
    CHK((fabs(*cut_depth - depth) > ISO14649_TINY),
	COUNTERBORE_DEPTH_MUST_EQUAL_CUTTING_DEPTH);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_countersink

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cutting_tool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a countersink:
      TOOL_BODY_MUST_BE_A_COUNTERSINK.
   5. The tool_top_angle differs from the upper_hole_angle:
      TOOL_TAPER_MUST_EQUAL_HOLE_TAPER.
   6. The bottom diameter of the hole is smaller than twice the
      countersink_radius of the tool:
      COUNTERSINK_CUTTING_PORTION_MUST_REACH_HOLE_BOTTOM.
   7. The top diameter of the hole is larger than the diameter of the
      countersink: HOLE_DIAMETER_MUST_NOT_EXCEED_COUNTERSINK_DIAMETER.
   8. The given cut_depth is not ROSE_NULL_REAL and it is the wrong
      depth: COUNTERSINK_DEPTH_MUST_MATCH_HOLE_DEPTH.
   9. check_tool_dimension returns an error code.

Side Effects: See below

Called By: op_counter_sinking

data
----

cutting_tool
------------
its_id                   label (machining_tool)
its_tool_body:           tool_body (cutting_tool)
its_cutting_edge:        LIST [1:?] OF cutting_component
overall_assembly_length: OPTIONAL length_measure

countersink
-----------
<no attributes>          (tool_body)
dimension:               milling_tool_dimension (milling_tool_body)
number_of_teeth:         OPTIONAL INTEGER
hand_of_cut:             OPTIONAL hand
coolant_through_tool:    OPTIONAL BOOLEAN
pilot_length:            OPTIONAL length_measure
countersink_radius       OPTIONAL length_measure (countersink)

milling_tool_dimension
----------------------
diameter:                 length_measure
tool_top_angle:           OPTIONAL plane_angle_measure
tool_circumference_angle: OPTIONAL plane_angle_measure
cutting_edge_length:      OPTIONAL length_measure
edge_radius:              OPTIONAL length_measure
edge_center_vertical:     OPTIONAL length_measure
edge_center_horizontal:   OPTIONAL length_measure

Part 111 does not say which parameters from Figure 2 (the
milling_tool_dimension parameters listed immediately above) should be
used to define a countersink. In the case where the cutting portion of
the tool is outside the diameter at an angle given by the tool
circumference angle, all seven parameters could be used; this allows
the non-cutting tip to be shaped many ways. In the case where the
cutting portion of the tool is inside the diameter, it could be done
with tool_top_angle, cutting_edge_length, and diameter; this does not
allow the tip to be shaped. The example in Part 11 uses the second
method, so that method is used here.  Where edge_radius is zero or not
used and tool_circumference_angle is zero or not used, the
tool_top_angle should equal atan2(cutting_edge_length, (diameter /
2)), but that is not being checked here.

If the cut_depth is ROSE_NULL_REAL, it is set to the correct depth.
Otherwise, this checks that cut_depth already is the correct depth. The
correct depth is the depth at which the tool flutes are just touching the
sides of the tapered hole.

The tool_top_angle of the dimension must be given. This is checked in
check_tool_dimension.

The tool_top_angle of the countersink must be the same as the
upper_hole_angle.

*/

static int check_tool_countersink( /* ARGUMENTS                         */
 machining_tool * the_tool,        /* tool to check                     */
 round_hole * upper_hole,          /* hole to be countersunk by tool    */
 double * cut_depth,               /* cutting depth given in operation  */
 double angle)                     /* angle from bottom to side of hole */
{
  static char name[] SET_TO "check_tool_countersink";
  tool_body * body;
  countersink * csinker;
  milling_tool_dimension * dimension;
  double diameter1;
  double diameter2;
  double height;
  double depth;

  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isa("cutting_tool"))
    body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isa("countersink"))
    {
      csinker SET_TO (ROSE_CAST(countersink, body));
      dimension SET_TO csinker->dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_A_COUNTERSINK);
  IFF(check_tool_dimension(dimension, 0, 1, 0));
  CHK((fabs(angle - dimension->tool_top_angle()) > ISO14649_TINY),
      TOOL_TAPER_MUST_EQUAL_HOLE_TAPER);
  diameter1 SET_TO upper_hole->diameter()->theoretical_size();
  height SET_TO 
    -(upper_hole->depth()->position()->location()->coordinates()->get(2));
  diameter2 SET_TO (diameter1 - (2 * (height / tand(angle))));
  CHK((diameter2 < (2 * csinker->countersink_radius())),
      COUNTERSINK_CUTTING_PORTION_MUST_REACH_HOLE_BOTTOM);
  CHK((diameter1 > dimension->diameter()),
      HOLE_DIAMETER_MUST_NOT_EXCEED_COUNTERSINK_DIAMETER);
  depth SET_TO ((diameter1 / 2.0) * tand(angle));
  if (*cut_depth IS ROSE_NULL_REAL)
    *cut_depth SET_TO depth;
  else
    CHK((fabs(*cut_depth - depth) > ISO14649_TINY),
        COUNTERSINK_DEPTH_MUST_MATCH_HOLE_DEPTH);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_dimension

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. dimension is NULL: DIMENSION_MUST_NOT_BE_NULL.
   2. diameter is ROSE_NULL_REAL: TOOL_DIAMETER_MUST_BE_GIVEN.
   3. diameter is not positive: TOOL_DIAMETER_MUST_BE_POSITIVE.
   4. cutting_edge_length is ROSE_NULL_REAL: CUTTING_EDGE_LENGTH_MUST_BE_GIVEN.
   5. cutting_edge_length is not positive:
      CUTTING_EDGE_LENGTH_MUST_BE_POSITIVE.
   6. tool_top_angle is required but is ROSE_NULL_REAL:
      TOOL_TOP_ANGLE_MUST_BE_GIVEN.
   7. tool_top_angle is not ROSE_NULL_REAL but is negative:
      TOOL_TOP_ANGLE_MUST_NOT_BE_NEGATIVE.
   8. tool_top_angle is not ROSE_NULL_REAL but is not less than 90 degrees:
      TOOL_TOP_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES.
   9. tool_top_angle is required to be ROSE_NULL_REAL or zero, but is not:
      TOOL_TOP_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN.
  10. tool_circumference_angle is required but is ROSE_NULL_REAL:
      TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_GIVEN.
  11. tool_circumference_angle is not ROSE_NULL_REAL but is negative:
      TOOL_CIRCUMFERENCE_ANGLE_MUST_NOT_BE_NEGATIVE.
  12. tool_circumference_angle is not ROSE_NULL_REAL but is not less than
      90 degrees: TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES.
  13. tool_circumference_angle is required to be ROSE_NULL_REAL or zero,
      but is not: TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN.
  14. edge_radius is required but is ROSE_NULL_REAL:
      EDGE_RADIUS_MUST_BE_GIVEN
  15. edge_radius is not ROSE_NULL_REAL but is negative:
      EDGE_RADIUS_MUST_NOT_BE_NEGATIVE.
  16. edge_radius is required to be ROSE_NULL_REAL or zero, but is not:
      EDGE_RADIUS_MUST_BE_ZERO_OR_NOT_GIVEN.

Side Effects:  none

Called By:
  check_tool_center_drill
  check_tool_counterbore
  check_tool_countersink
  check_tool_drill
  check_tool_endmill
  check_tool_plane
  check_tool_reamer
  
For each of the three flags, -1 means the value must be ROSE_NULL_REAL or
zero, 1 means the value must be given, and 0 means there is neither
requirement.

Any value that is not ROSE_NULL_REAL must be in range.

This does not check anything about edge_center_vertical or
edge_center_horizontal.

milling_tool_dimension
----------------------
diameter:                 length_measure
tool_top_angle:           OPTIONAL plane_angle_measure
tool_circumference_angle: OPTIONAL plane_angle_measure
cutting_edge_length:      OPTIONAL length_measure
edge_radius:              OPTIONAL length_measure
edge_center_vertical:     OPTIONAL length_measure
edge_center_horizontal:   OPTIONAL length_measure

*/

static int check_tool_dimension(     /* ARGUMENTS                    */
 milling_tool_dimension * dimension, /* the dimension to check       */
 int edge_radius_flag,               /* flag for edge_radius         */
 int tool_top_angle_flag,            /* flag for tool_top_angle      */
 int circumference_angle_flag)       /* flag for circumference_angle */
{
  static char name[] SET_TO "check_tool_dimension";
  double a; /* tool_top_angle           */
  double b; /* tool_circumference_angle */
  double d; /* diameter                 */
  double e; /* cutting_edge_length      */
  double r; /* edge_radius              */

  CHK((dimension IS NULL), DIMENSION_MUST_NOT_BE_NULL);

  d SET_TO dimension->diameter();
  CHK((d IS ROSE_NULL_REAL), TOOL_DIAMETER_MUST_BE_GIVEN);
  CHK((d <= 0), TOOL_DIAMETER_MUST_BE_POSITIVE);

  e SET_TO dimension->cutting_edge_length();
  CHK((e IS ROSE_NULL_REAL), CUTTING_EDGE_LENGTH_MUST_BE_GIVEN);
  CHK((e <= 0), CUTTING_EDGE_LENGTH_MUST_BE_POSITIVE);

  a SET_TO dimension->tool_top_angle();
  if (a IS ROSE_NULL_REAL)
    CHK((tool_top_angle_flag IS 1), TOOL_TOP_ANGLE_MUST_BE_GIVEN);
  else
    {
      CHK((a < 0), TOOL_TOP_ANGLE_MUST_NOT_BE_NEGATIVE);
      CHK((a >= 90), TOOL_TOP_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES);
      CHK(((tool_top_angle_flag IS -1) AND (a ISNT 0)),
	  TOOL_TOP_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN);
    }

  b SET_TO dimension->tool_circumference_angle();
  if (b IS ROSE_NULL_REAL)
    CHK((circumference_angle_flag IS 1),
        TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_GIVEN);
  else
    {
      CHK((b < 0), TOOL_CIRCUMFERENCE_ANGLE_MUST_NOT_BE_NEGATIVE);
      CHK((b >= 90),
	  TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES);
      CHK(((circumference_angle_flag IS -1) AND (b ISNT 0)),
	  TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN);
    }

  r SET_TO dimension->edge_radius();
  if (r IS ROSE_NULL_REAL)
    CHK((edge_radius_flag IS 1), EDGE_RADIUS_MUST_BE_GIVEN);
  else
    {
      CHK((r < 0), EDGE_RADIUS_MUST_NOT_BE_NEGATIVE);
      CHK(((edge_radius_flag IS -1) AND (r ISNT 0)),
	  EDGE_RADIUS_MUST_BE_ZERO_OR_NOT_GIVEN);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_drill

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cutting_tool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a drill: TOOL_BODY_MUST_BE_A_TWIST_DRILL.
   5. check_tool_dimension returns an error code.

Side Effects:  flute_length is set.

Called By:
   op_drilling
   op_multistep_drilling

data
----

cutting_tool
------------
its_id                   label (machining_tool)
its_tool_body:           tool_body (cutting_tool)
its_cutting_edge:        LIST [1:?] OF cutting_component
overall_assembly_length: OPTIONAL length_measure

twist_drill
-----------
<no attributes>                   (tool_body)
dimension:               milling_tool_dimension (milling_tool_body)
number_of_teeth:         OPTIONAL INTEGER
hand_of_cut:             OPTIONAL hand
coolant_through_tool:    OPTIONAL BOOLEAN
pilot_length:            OPTIONAL length_measure
<no attributes>                   (drill)
<no attributes>                   (twist_drill)

The tool_top_angle of the dimension must be given. This is checked in
check_tool_dimension.

*/

static int check_tool_drill( /* ARGUMENTS                   */
 machining_tool * the_tool,  /* the (should be) twist_drill */
 double * flute_length)      /* flute_length, set here      */
{
  static char name[] SET_TO "check_tool_drill";
  tool_body * body;
  milling_tool_dimension * dimension;

  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isa("cutting_tool"))
    body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isa("twist_drill"))
    dimension SET_TO (ROSE_CAST(drill, body))->dimension();
  else
    CHK(1, TOOL_BODY_MUST_BE_A_TWIST_DRILL);
  IFF(check_tool_dimension(dimension, 0, 1, 0));
  *flute_length SET_TO dimension->cutting_edge_length();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_endmill

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cutting_tool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not an endmill: TOOL_BODY_MUST_BE_AN_ENDMILL.
   5. check_tool_dimension returns an error code.

Side Effects: None

Called By:
   op_finish_milling_both
   op_rough_milling_both

data
----

cutting_tool
------------
its_id                   label (machining_tool)
its_tool_body:           tool_body (cutting_tool)
its_cutting_edge:        LIST [1:?] OF cutting_component
overall_assembly_length: OPTIONAL length_measure

endmill
-----------
<no attributes>                   (tool_body)
dimension:               milling_tool_dimension (milling_tool_body)
number_of_teeth:         OPTIONAL INTEGER
hand_of_cut:             OPTIONAL hand
coolant_through_tool:    OPTIONAL BOOLEAN
pilot_length:            OPTIONAL length_measure
<no attributes>                   (milling_cutter)
<no attributes>                   (endmill)

The edge_radius, tool_top_angle, and tool_circumference_angle of the
dimension must all be zero or not given. This is checked in
check_tool_dimension. I.e., the endmill must have a flat end and not
be tapered.

*/

static int check_tool_endmill( /* ARGUMENTS               */
 machining_tool * the_tool,    /* the (should be) endmill */
 endmill ** the_endmill)       /* the endmill, set here   */
{
  static char name[] SET_TO "check_tool_endmill";
  tool_body * body;
  milling_tool_dimension * dimension;
  
  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isa("cutting_tool"))
    body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isa("endmill"))
    {
      *the_endmill SET_TO ROSE_CAST(endmill, body);
      dimension SET_TO (*the_endmill)->dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_AN_ENDMILL);
  IFF(check_tool_dimension(dimension, -1, -1, -1));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cutting_tool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is neither an endmill nor a facemill:
      TOOL_BODY_MUST_BE_AN_ENDMILL_OR_A_FACEMILL.
   5. check_tool_dimension returns an error code.

Side Effects: None

Called By:
  op_finish_milling_plane
  op_rough_milling_plane

Notes:

This is requiring that the edge radius of the endmill or facemill be
zero or not given. This requirement could be relaxed, but checking the
operation would then be a little harder, since the effective cutting
diameter of the tool would be reduced.

*/

static int check_tool_plane( /* ARGUMENTS                                  */
 machining_tool * the_tool,  /* the (should be) endmill or facemill        */
 endmill ** the_endmill,     /* the endmill, set here if tool is endmill   */
 facemill ** the_facemill)   /* the facemill, set here if tool is facemill */
{
  static char name[] SET_TO "check_tool_plane";
  tool_body * body;
  milling_tool_dimension * dimension;
  
  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isa("cutting_tool"))
    body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isa("endmill"))
    {
      *the_endmill SET_TO ROSE_CAST(endmill, body);
      dimension SET_TO (*the_endmill)->dimension();
    }
  else if (body->isa("facemill"))
    {
      *the_facemill SET_TO ROSE_CAST(facemill, body);
      dimension SET_TO (*the_facemill)->dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_AN_ENDMILL_OR_A_FACEMILL);
  IFF(check_tool_dimension(dimension, -1, -1, -1));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_reamer

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cutting_tool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a reamer: TOOL_BODY_MUST_BE_A_REAMER.
   5. check_tool_dimension returns an error code.

Side Effects: None

Called By: op_reaming

data
----

cutting_tool
------------
its_id                   label (machining_tool)
its_tool_body:           tool_body (cutting_tool)
its_cutting_edge:        LIST [1:?] OF cutting_component
overall_assembly_length: OPTIONAL length_measure

reamer
-----------
<no attributes>                   (tool_body)
dimension:               milling_tool_dimension (milling_tool_body)
number_of_teeth:         OPTIONAL INTEGER
hand_of_cut:             OPTIONAL hand
coolant_through_tool:    OPTIONAL BOOLEAN
pilot_length:            OPTIONAL length_measure
<no attributes>                   (reamer)

The edge_radius, tool_top_angle, and tool_circumference_angle of the
dimension must all be zero or not given. This is checked in
check_tool_dimension. I.e., the reamer must have a flat end and not
be tapered.

*/

static int check_tool_reamer( /* ARGUMENTS              */
 machining_tool * the_tool,   /* the (should be) reamer */
 double * flute_length)       /* flute length, set here */
{
  static char name[] SET_TO "check_tool_reamer";
  tool_body * body;
  milling_tool_dimension * dimension;
  
  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isa("cutting_tool"))
    body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isa("reamer"))
    dimension SET_TO (ROSE_CAST(reamer, body))->dimension();
  else
    CHK(1, TOOL_BODY_MUST_BE_A_REAMER);
  IFF(check_tool_dimension(dimension, -1, -1, -1));
  *flute_length SET_TO dimension->cutting_edge_length();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tools

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The tool for a machining_workingstep is not a cutting_tool:
      TOOL_FOR_MACHINING_MUST_BE_A_CUTTING_TOOL.
   2. The tool_body of a tool for machining is not a milling_tool_body:
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY.
   3. The diameter of a tool for machining associated with a
      machining_workingstep is not within 0.001 mm of the diameter of the
      same tool given in the tool table:
      TOOL_DIAMETERS_MUST_BE_SAME_FOR_SAME_TOOL.
   4. The list of cutting_components for a tool does not have exactly one
      member: TOOL_FOR_MACHINING_MUST_HAVE_HAVE_EXACTLY_ONE_COMPONENT.
   5. A tool required by the ISO 14649 program cannot be found in the
      tool table: REQUIRED_TOOL_MUST_BE_IN_TOOL_TABLE.
   6. The handedness of a tool is not given: TOOL_HANDEDNESS_MUST_BE_GIVEN.


Side Effects: See below

Called By: iso14649_open

This checks that:
1. all the tools required by an ISO 14649 program are present on the
   machine (as determined by matching ids with the _world.tool_table).
2. the _world.tool_table has the same diameter for each tool as does the
   program.
3. all the tools in the ISO program have a value for handedness. This
   check is included so that values for spindle speed (negative for
   right-handed tools) can be checked. It is expected that many programs
   will have a mismatch between spindle speed and handedness.

The ISO 14649 program has a number for the tool length offset, but that
number is not expected to be correct. The number is reset to the tool length
offset recorded in the _world.tool_table. (Per discussion with Fred
Proctor in December 2002).

*/

static int check_tools(           /* ARGUMENTS                        */
 List (executable) * executables) /* the list of executables to check */
{
  static char name[] SET_TO "check_tools";
  int n;
  int stop;
  int index;
  machining_workingstep * a_mach;
  executable * an_ex;
  cutting_tool * a_tool;
  milling_tool_body * mill_body;

  stop SET_TO executables->size();
  for (n SET_TO 0; n ISNT stop; n++)
    {
      an_ex SET_TO (*executables)[n];
      if (an_ex->isa("machining_workingstep"))
	{
	  a_mach SET_TO ROSE_CAST(machining_workingstep, an_ex);
	  for (index SET_TO 0; index <= _world.tool_max; index++)
	    {
	      if (strcmp(a_mach->its_operation()->its_tool()->its_id(),
			 _world.tool_table[index].name) IS 0) // FMP
		{
		  CHK((NOT(a_mach->its_operation()->
			    its_tool()->isa("cutting_tool"))),
		      TOOL_FOR_MACHINING_MUST_BE_A_CUTTING_TOOL);
		  a_tool SET_TO ROSE_CAST(cutting_tool,
					  a_mach->its_operation()->its_tool());
		  CHK((NOT(a_tool->its_tool_body()->isa("milling_tool_body"))),
		      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY);
		  mill_body SET_TO ROSE_CAST(milling_tool_body,
					     a_tool->its_tool_body());
		  CHK(((fabs(mill_body->dimension()->diameter() -
			    _world.tool_table[index].diameter)) > 0.001),
		      TOOL_DIAMETERS_MUST_BE_SAME_FOR_SAME_TOOL);
		  CHK((mill_body->hand_of_cut() IS hand_NULL),
		      TOOL_HANDEDNESS_MUST_BE_GIVEN);
		  CHK((a_tool->its_cutting_edge()->size() ISNT 1),
		      TOOL_FOR_MACHINING_MUST_HAVE_EXACTLY_ONE_COMPONENT);
		  // (*(a_tool->its_cutting_edge()))[0]->
		  a_tool->its_cutting_edge()->get(0)->
		    tool_offset_length(_world.tool_table[index].length);
		  break;
		}
	    }
	  CHK((index > _world.tool_max), REQUIRED_TOOL_MUST_BE_IN_TOOL_TABLE);
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* cut_feature

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_feature is NULL: FEATURE_MUST_NOT_BE_NULL.
   2. the_operation is NULL: OPERATION_MUST_NOT_BE_NULL.
   3. the_operation is not one of its_operations of the_feature:
      OPERATION_MUST_BELONG_TO_FEATURE.
   4. the_operation is not one of the types listed below:
      MACHINING_OPERATION_TYPE_MUST_BE_DEFINED_TYPE.
   5. Any of the specific feature cutting functions returns an error code.

Side Effects: See below

Called By: execute_machining

The_operation normally makes part or all of the_feature. If an
explicit toolpath is given, however, the operation may do something
else. In addition, some operations (such as a drilling_type_operation
when cutting_depth is given) may make more or less than the feature,
even if toolpath is not given. The_operation must be one of the 16
instantiable types marked with an asterisk in the hierarchy below.
This checks to see which of the instantiable types of operation
the_operation is and calls a subordinate function to handle that type.

The machining_operation hierarchy (instantiable types marked with *) is:

machining_operation
  milling_machining_operation
    drilling_type_operation
      drilling_operation
        drilling *
        center_drilling *
        counter_sinking *
        multistep_drilling *
      boring_operation
        boring *
        reaming *
      back_boring *
      tapping *
      thread_drilling *
    milling_type_operation
      freeform_operation *
      two5D_milling_operation
        plane_milling
          plane_rough_milling *
          plane_finish_milling *
        side_milling
          side_rough_milling *
          side_finish_milling *
        bottom_and_side_milling
          bottom_and_side_rough_milling *
          bottom_and_side_finish_milling *

This handles only machining_features. Countersunk_hole is not a machining
feature, so this does not do countersinking. That is done elsewhere.

*/

static int cut_feature(               /* ARGUMENTS                          */
 machining_feature * the_feature,     /* feature to make                    */
 machining_operation * the_operation) /* machining op to perform on feature */
{
  static char name[] SET_TO "cut_feature";
  Set (machining_operation) * feature_ops;
  int stop;
  int n;
  
  CHK((the_feature IS NULL), FEATURE_MUST_NOT_BE_NULL);
  CHK((the_operation IS NULL), OPERATION_MUST_NOT_BE_NULL);
  feature_ops SET_TO the_feature->its_operations();
  stop SET_TO feature_ops->size();
  for (n SET_TO 0; n < stop; n++)
    {
      if (the_operation IS (*feature_ops)[n])
	break;
    }
  CHK((n IS stop), OPERATION_MUST_BELONG_TO_FEATURE);
  if (the_operation->isa("back_boring"))
    printf("back_boring\n");
  else if (the_operation->isa("boring"))
    printf("boring\n");
  else if (the_operation->isa("bottom_and_side_finish_milling"))
    IFF(op_finish_milling_both(the_feature,
	     ROSE_CAST(bottom_and_side_finish_milling, the_operation)));
  else if (the_operation->isa("bottom_and_side_rough_milling"))
    IFF(op_rough_milling_both(the_feature,
	     ROSE_CAST(bottom_and_side_rough_milling, the_operation)));
  else if (the_operation->isa("center_drilling"))
    IFF(op_center_drilling(the_feature,
			   ROSE_CAST(center_drilling, the_operation)));
  else if (the_operation->isa("drilling"))
    IFF(op_drilling(the_feature,
		    ROSE_CAST(drilling, the_operation)));
  else if (the_operation->isa("freeform_operation"))
    printf("freeform_milling\n");
  else if (the_operation->isa("multistep_drilling"))
    IFF(op_multistep_drilling(the_feature,
			      ROSE_CAST(multistep_drilling, the_operation)));
  else if (the_operation->isa("plane_finish_milling"))
    IFF(op_finish_milling_plane(the_feature,
			    ROSE_CAST(plane_finish_milling, the_operation)));
  else if (the_operation->isa("plane_rough_milling"))
    IFF(op_rough_milling_plane(the_feature,
			    ROSE_CAST(plane_rough_milling, the_operation)));
  else if (the_operation->isa("reaming"))
    IFF(op_reaming(the_feature, ROSE_CAST(reaming, the_operation)));
  else if (the_operation->isa("side_finish_milling"))
    IFF(op_finish_milling_side(the_feature, /* function is a stub */
			      ROSE_CAST(side_finish_milling, the_operation)));
  else if (the_operation->isa("side_rough_milling"))
    IFF(op_rough_milling_side(the_feature, /* function is a stub */
			      ROSE_CAST(side_rough_milling, the_operation)));
  else if (the_operation->isa("tapping"))
    printf("tapping\n");
  else if (the_operation->isa("thread_drilling"))
    printf("thread_drilling\n");
  else
    CHK(1, MACHINING_OPERATION_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/***********************************************************************/

/* cut_straight

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_traverse returns an error code.
   3. A non-plunge approach strategy is used: CAN_HANDLE_ONLY_PLUNGE_APPROACH
   4. A plunge_helix approach strategy is used:
      POCKET_WIDTH_MUST_EXCEED_TOOL_DIAMETER_FOR_PLUNGE_HELIX.
   5. A non-plunge_toolaxis retract strategy is used:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT.
   6. enter_pocket_pass returns an error code.
   7. find_pocket_plunge_start returns an error code.

Side Effects: See below

Called By: mill_rectangular_pocket

This is for cutting a straight groove the width of the tool. The
actual feature being cut is not required to be a groove. The center
line of the groove lies on the X-axis, and the middle of the groove
is at the origin.

The approach method must be either a plunge_toolaxis, a plunge_ramp,
or a plunge_zigzag. There is no room for a plunge_helix. The first
plunge is from retract above the XY plane to pass_depth below it.
Subsequent plunges are all  to one pass_depth deeper. Each plunge
ends at end2, the -X end of the groove.

After each plunge, the tool cuts to end1, the +X end of the groove.

This is making the minimum number of passes required (as determined
from the depth and the pass_depth), but rather than [making all but
the last pass be exactly pass_depth thick and cutting whatever
thickness is left in the last pass], this makes all passes the same
thickness, which may be less than pass_depth.

This does the approach move to get to the next pass depth at the
beginning of each pass, rather than doing the approach move to full
depth once. This seems to be how the spec wants it. See Part 11,
section 4.2.6.2, for example.

This is not changing the feedrate for slotting or plunging because it
is slotting or plunging all the time. It is assumed the program was
written with the feedrate set appropriately for slotting.

This will do a pure zigzag (with no retract and move between passes)
by setting the zigzag width to the distance between tool centers at
the ends of the groove and setting the zigzag angle to exactly (at
five decimal places) the angle required to move one pass depth in Z while
moving the zigzag width horizontally.

*/

static int cut_straight(            /* ARGUMENTS                     */
 double length,                     /* length of cut                 */
 double depth,                      /* (positive) total depth of cut */
 double retract,                    /* amount of retract at feedrate */
 double pass_depth,                 /* (positive) depth in one pass  */
 approach_retract_strategy * enter, /* approach strategy             */
 approach_retract_strategy * leave, /* retract strategy              */
 double diameter,                   /* diameter of tool              */
 double code[][7],                  /* code array to write in        */
 int * lines)                       /* code array index              */
{
  static char name[] SET_TO "cut_straight";
  int passes;              /* number of passes                          */
  int n;                   /* index for passes                          */
  double end1;             /* tool tip X coordinate at +X end of groove */
  double end2;             /* tool tip X coordinate at -X end of groove */
  double z_now;            /* current Z coordinate                      */
  plunge_strategy * entry; /* plunge entry strategy                     */
  double start_x;          /* X coordinate of start point               */
  double start_y;          /* Y coordinate of start point               */
  double aux;

  CHK((NOT(enter->isa("plunge_strategy"))), CAN_HANDLE_ONLY_PLUNGE_APPROACH);
  CHK((enter->isa("plunge_helix")),
      POCKET_WIDTH_MUST_EXCEED_TOOL_DIAMETER_FOR_PLUNGE_HELIX);
  entry SET_TO ROSE_CAST(plunge_strategy, enter);
  passes SET_TO (1 + (int)((depth - ISO14649_TINY) / pass_depth));
  pass_depth SET_TO (depth / passes);
  end1 SET_TO ((length - diameter) / 2.0);
  end2 SET_TO -end1;
  z_now SET_TO -pass_depth;
  IFF(find_pocket_plunge_start((length - diameter), 0, (retract + pass_depth), 
			       entry, &start_x, &start_y, &aux));
  IFF(write_feed(start_x, start_y, retract, code, lines)); /* start point */
  IFF(enter_pocket_pass(entry, start_x, start_y, retract, end2,
			z_now, aux, code, lines));
  IFF(write_feed(end1, 0, z_now, code, lines));
  if (passes > 1)
    IFF(find_pocket_plunge_start((length - diameter), 0, pass_depth, 
				 entry, &start_x, &start_y, &aux));
  for (n SET_TO 1; n < passes; n++)
    {
      if ((fabs(end1 - start_x) > ISO14649_TINY) OR
	  (fabs(start_y) > ISO14649_TINY))
	{
	  IFF(write_feed(end1, 0, (z_now + pass_depth), code, lines));
	  IFF(write_traverse(start_x, start_y, (z_now + pass_depth),
			     code, lines));
	  IFF(write_feed(start_x, start_y, z_now, code, lines));
	}
      z_now SET_TO (z_now - pass_depth);
      IFF(enter_pocket_pass(entry, start_x, start_y, (z_now + pass_depth),
			    end2, z_now, aux, code, lines));
      IFF(write_feed(end1, 0, z_now, code, lines));
    }
  if (leave->isa("plunge_toolaxis"))
    IFF(write_feed(end1, 0, retract, code, lines));
  else
    CHK(1, CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT);
  return ISO14649_OK;
}

/***********************************************************************/

/* enter_pocket_pass

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. The end of the entry is not at (end_x, 0): BUG_IN_ENTERING_POCKET.
   3. The plunge strategy is not one of the four subtypes:
      PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE.
   4. enter_pocket_pass_helix returns an error code.
   5. enter_pocket_pass_zigzag returns an error code.

Side Effects: See below

Called By:
  cut_straight
  mill_rectangular_pocket_regular

In all cases, the tool tip starts at (start_x, start_y, start_z)

In all cases, the end of the starting motion is
at X = (length - width)/-2.0    Y = 0.0

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

In case of a plunge_toolaxis, the start point X and Y coordinates
are the same as those of end point.

In case of a plunge_ramp, a straight cut is made from the start point
to the end point. See documentation of find_pocket_plunge_start_ramp for
how the start point is selected.

For plunge_zigzag, aux is the X-offset from the start point to
the second point.

For plunge_helix, aux is the number of turns for write_arc, as a double.

The value of aux is irrelevant for plunge_toolaxis and plunge_ramp.

*/

static int enter_pocket_pass( /* ARGUMENTS                    */
 plunge_strategy * enter,     /* plunge entry strategy to use */
 double start_x,              /* X coordinate of start point  */
 double start_y,              /* Y coordinate of start point  */
 double start_z,              /* Z coordinate of start point  */
 double end_x,                /* X coordinate of end point    */
 double end_z,                /* Z coordinate of end point    */
 double aux,                  /* see above                    */
 double code[][7],            /* code array to write in       */
 int * lines)                 /* code array index             */
{
  static char name[] SET_TO "enter_pocket_pass";

  if (enter->isa("plunge_toolaxis"))
    {
      CHK(((start_x ISNT end_x) OR (start_y ISNT 0)), BUG_IN_ENTERING_POCKET);
      IFF(write_feed(end_x, 0, end_z, code, lines));
    }
  else if(enter->isa("plunge_ramp"))
    {
      IFF(write_feed(end_x, 0, end_z, code, lines));
    }
  else if (enter->isa("plunge_zigzag"))
    IFF(enter_pocket_pass_zigzag(ROSE_CAST(plunge_zigzag, enter), start_x,
				start_z, end_x, end_z, aux, code, lines));
  else if (enter->isa("plunge_helix"))
    IFF(enter_pocket_pass_helix(ROSE_CAST(plunge_helix, enter), start_x,
				start_y, start_z, end_x, end_z, (int)aux,
				code, lines));
  else
    CHK(1, PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE);

  return ISO14649_OK;
}

/***********************************************************************/

/* enter_pocket_pass_helix

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_arc returns an error code.

Side Effects: See below

Called By: enter_pocket_pass

The action of this function is coordinated with the action of
find_pocket_plunge_start_helix, which finds the start_x, start_y and
turns used here. See documentation of find_pocket_plunge_start_helix
for how the start point is found.

The helix is clockwise, starts at (start_x, start_y), is centered on
(end_x, 0) and ends at (end_x, -radius), i.e. at 6 o'clock. A
clockwise semicircle is made at constant depth after the helix is
made, with its radius half the helix radius, so that the tool tip ends
at (end_x, 0) traveling in the +X direction.

*/

static int enter_pocket_pass_helix( /* ARGUMENTS                     */
 plunge_helix * hely,               /* zigzag entry strategy         */
 double start_x,                    /* X coordinate of start point   */
 double start_y,                    /* Y coordinate of start point   */
 double start_z,                    /* Z coordinate of start point   */
 double end_x,                      /* X coordinate of end point     */
 double end_z,                      /* Z coordinate of end point     */
 int turns,                         /* number of turns for write_arc */
 double code[][7],                  /* code array to write in        */
 int * lines)                       /* code array index              */
{
  static char name[] SET_TO "enter_pocket_pass_helix";

  IFF(write_arc(end_x, -(hely->radius()), end_x, 0,
		turns, end_z, code, lines));
  IFF(write_arc(end_x, 0, end_x, (hely->radius() / -2),
		-1, end_z, code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* enter_pocket_pass_zigzag

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.

Side Effects: See below

Called By: enter_pocket_pass

The zigzag is on the X axis, starting at start_x. The first move is to
ramp down along the X axis by offset_x (towards +X if offset_x is
positive, towards -X if offset X is negative). The second and
subsequent moves except the last is to ramp down in the opposite
direction by the ramp width. The last move is to ramp down to the
end point.

The action of this function is coordinated with the action of
find_pocket_plunge_start_zigzag, which finds the start_x, start_y, and
offset_x used here. See documentation of find_pocket_plunge_start_zigzag
for how the start point and offset_x are found.

*/

static int enter_pocket_pass_zigzag( /* ARGUMENTS                      */
 plunge_zigzag * ziggy,              /* zigzag entry strategy          */
 double start_x,                     /* X coordinate of start point    */
 double start_z,                     /* Z coordinate of start point    */
 double end_x,                       /* X coordinate of end point      */
 double end_z,                       /* Z coordinate of end point      */
 double offset_x,                    /* X offset, start_x to 2nd point */
 double code[][7],                   /* code array to write in         */
 int * lines)                        /* code array index               */
{
  static char name[] SET_TO "enter_pocket_pass_zigzag";
  double angle;     /* angle of zigzag     */
  double distance;  /* length of zigzag    */
  double x1;        /* zigzag +X end value */
  double x2;        /* zigzag -X end value */
  double z_now;
  double x_now;
  double zig_depth;
  
  angle SET_TO ziggy->angle();
  distance SET_TO ziggy->width();
  if (offset_x > 0)
    {
      x1 SET_TO (start_x + offset_x);
      x2 SET_TO (x1 - distance);
      x_now SET_TO x1;
    }
  else
    {
      x2 SET_TO (start_x + offset_x);
      x1 SET_TO (x2 + distance);
      x_now SET_TO x2;
    }
  zig_depth SET_TO (fabs(offset_x) * tand(angle));
  z_now SET_TO (start_z - zig_depth);
  IFF(write_feed(x_now, 0, z_now, code, lines));
  zig_depth SET_TO (distance * tand(angle));
  z_now SET_TO (z_now - zig_depth);
  for (; z_now > (end_z + ISO14649_TINY); z_now SET_TO (z_now - zig_depth))
    {
      x_now SET_TO ((x_now IS x1) ? x2 : x1);
      IFF(write_feed(x_now, 0, z_now, code, lines));
    }
  if (fabs(x_now - end_x) > ISO14649_TINY)
    IFF(write_feed(end_x, 0, end_z, code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* execute_executable

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. _world.a_exec is NULL: EXECUTABLE_MUST_NOT_BE_NULL.
   2. _world.a_exec is a program_structure: CANNOT_HANDLE_PROGRAM_STRUCTURE.
   3. _world.a_exec is an unknown type: EXECUTABLE_TYPE_MUST_BE_DEFINED_TYPE.
   4. execute_workingstep returns an error code.
   5. execute_nc_function returns an error code.

Side Effects: See below

Called By: iso14649_execute

This executes the executable that is _world.a_exec.
_world.name_text is set to the name of _world.a_exec at the beginning.

*/

static int execute_executable() /* NO ARGUMENTS */
{
  static char name[] SET_TO "execute_executable";
  executable * the_exec;
  
  the_exec SET_TO _world.a_exec;
  CHK((the_exec IS NULL), EXECUTABLE_MUST_NOT_BE_NULL);
  strcpy(_world.name_text, the_exec->its_id());
  if (the_exec->isa("workingstep"))
    IFF(execute_workingstep(ROSE_CAST(workingstep, the_exec)));
  else if (the_exec->isa("nc_function"))
    IFF(execute_nc_function(ROSE_CAST(nc_function, the_exec)));
  else if (the_exec->isa("program_structure"))
    CHK(1, CANNOT_HANDLE_PROGRAM_STRUCTURE);
  else
    CHK(1, EXECUTABLE_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_machining

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The operation to perform is NULL: OPERATION_MUST_NOT_BE_NULL.
   2. The feature to machine is NULL: FEATURE_MUST_NOT_BE_NULL.
   3. The feature to machine is a region: CANNOT_MACHINE_A_REGION.
   4. The feature to machine is a transition_feature:
      CANNOT_HANDLE_TRANSITION_FEATURE.
   5. The feature to machine is a replicate_feature:
      CANNOT_HANDLE_REPLICATE_FEATURE.
   6. The feature to machine is a compound_feature that is not a
      countersunk_hole or a counterbore_hole: CANNOT_HANDLE_COMPOUND_FEATURE.
   7. The feature to machine is of unknown type:
      MANUFACTURING_FEATURE_TYPE_MUST_BE_DEFINED_TYPE.
   8. The machine_functions of the workingstep is not a
      milling_machine_functions:
      MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS.
   9. The technology of the workingstep is not milling_technology:
      TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY.
  10. After being located in setup coordinates, the Z axis of the
      feature is not parallel to the Z axis of the machine:
      FEATURE_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS.
  11. handle_tool returns an error code.
  12. handle_machine_functions returns an error code.
  13. handle_technology returns an error code.
  14. find_location returns an error code.
  15. find_if_vertical returns an error code.
  16. cut_feature returns an error code.
  17. op_counter_sinking returns an error code.
  18. op_counter_boring returns an error code.
  19. The feature is not a machining_feature, a countersunk_hole, or
      a counterbore_hole: CANNOT_PERFORM_OPERATION_ON_FEATURE.
  20. set_security_z_now returns an error code.

Side Effects: See below

Called By: execute_workingstep

the_machining is known not to be NULL when this is called, so that
is not checked here.

This function (hence this interpreter) does not deal with its_effect
of the_machining.

This interpreter is using the setup coordinate system at all times.
This function calculates the position of the feature in the setup
coordinate system and stores it in _world.feature_place. See
discussion of coordinate systems at the beginning of this file. The
axis of the native coordinate system of the placed feature is required
to be parallel to the Z axis of the setup.  That is checked here.

Data
----
its_id:            identifier (executable)
its_secplane:      elementary_surface (workingstep)
its_feature:       manufacturing_feature (machining_workingstep)
its_operation:     machining_operation
its_effect:        OPTIONAL in_process_geometry

*/

static int execute_machining(           /* ARGUMENTS                       */
 machining_workingstep * the_machining) /* the machining_w'step to execute */
{
  static char name[] SET_TO "execute_machining";
  manufacturing_feature * the_feature;
  two5D_manufacturing_feature * the_feat;
  machining_operation * the_operation;
  milling_machine_functions * the_functions;
  milling_technology * the_technology;
  int vertical;

  the_operation SET_TO the_machining->its_operation();
  the_feature SET_TO the_machining->its_feature();
  
  CHK((the_operation IS NULL), OPERATION_MUST_NOT_BE_NULL);
  if (the_operation->its_machine_functions()->isa("milling_machine_functions"))
    the_functions SET_TO ROSE_CAST(milling_machine_functions,
				   the_operation->its_machine_functions());
  else
    CHK(1, MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS);
  CHK((the_feature IS NULL), FEATURE_MUST_NOT_BE_NULL);
  if (the_feature->isa("two5D_manufacturing_feature"))
    {
      the_feat SET_TO ROSE_CAST(two5D_manufacturing_feature, the_feature);
      if (the_feat->isa("machining_feature"));
      else if (the_feat->isa("replicate_feature"))
	CHK(1, CANNOT_HANDLE_REPLICATE_FEATURE);
      else if (the_feat->isa("compound_feature"))
	{
	  if (the_feat->isa("countersunk_hole") AND
	      the_operation->isa("counter_sinking"));
	  else if (the_feat->isa("counterbore_hole") AND
		   the_operation->isa("boring"));
	  else
	    CHK(1, CANNOT_HANDLE_COMPOUND_FEATURE);
	}
      else
	CHK(1, MANUFACTURING_FEATURE_TYPE_MUST_BE_DEFINED_TYPE);
    }
  else if (the_feature->isa("region"))
    CHK(1, CANNOT_MACHINE_A_REGION);
  else if (the_feature->isa("transition_feature"))
    CHK(1, CANNOT_HANDLE_TRANSITION_FEATURE);
  else
    CHK(1, MANUFACTURING_FEATURE_TYPE_MUST_BE_DEFINED_TYPE);
  if (the_operation->its_technology()->isa("milling_technology"))
    the_technology SET_TO ROSE_CAST(milling_technology,
				    the_operation->its_technology());
  else
    CHK(1, TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY);
  
  IFF(handle_tool(the_operation->its_tool(), 0));
  IFF(handle_machine_functions(the_functions));
  IFF(handle_technology(the_technology, the_operation->its_tool()));
  IFF(find_location(_world.workpiece_place, the_feat->feature_placement(),
		    &(_world.feature_place)));
  IFF(find_if_vertical(_world.feature_place.axis(), &vertical));
  CHK((NOT(vertical)), FEATURE_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS);
  IFF(set_security_z_now(the_machining->its_secplane()));
  if (the_feat->isa("machining_feature"))
    IFF(cut_feature(ROSE_CAST(machining_feature, the_feat), the_operation));
  else if (the_feat->isa("countersunk_hole"))
    IFF(op_counter_sinking(ROSE_CAST(countersunk_hole, the_feat),
			   ROSE_CAST(counter_sinking, the_operation)));
  else if (the_feat->isa("counterbore_hole"))
    IFF(op_counter_boring(ROSE_CAST(counterbore_hole, the_feat),
			  ROSE_CAST(boring, the_operation)));
  else
    CHK(1, CANNOT_PERFORM_OPERATION_ON_FEATURE);
  _world.security_z_now SET_TO _world.security_z_setup;
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_nc_function

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The nc_function is a set_mark: CANNOT_HANDLE_SET_MARK.
   2. The nc_function is a wait_for_mark: CANNOT_HANDLE_WAIT_FOR_MARK.
   3. The nc_function is an index_pallet: CANNOT_HANDLE_INDEX_PALLET.
   4. The nc_function is an index_table: CANNOT_HANDLE_INDEX_TABLE.
   5. handle_tool returns an error code.
   6. handle_unload_tool returns an error code.

Side Effects: See below

Called By: execute_executable

This executes the nc_function that is the_nc_function.  If the
nc_function is load_tool or unload_tool and either of those calls
change_tool, the XY-position at the end of the operation is
unknown. For those two nc_functions, this will cause change_tool (if
it is called) to set _world.action_flag to ISO14649_SET_POSITION. Then
when the next iso14649_read starts up, it will get and record the
position.  The Z position after a tool change is always fully
retracted.

*/

static int execute_nc_function( /* ARGUMENTS                  */
 nc_function * the_nc_function) /* the nc_function to execute */
{
  static char name[] SET_TO "execute_nc_function";

  if (the_nc_function->isa("load_tool"))
    IFF(handle_tool(ROSE_CAST(load_tool, the_nc_function)->its_tool(), 1));
  else if (the_nc_function->isa("unload_tool"))
    IFF(handle_unload_tool
	(ROSE_CAST(unload_tool, the_nc_function)->its_tool()));
  else if (the_nc_function->isa("display_message"))
    MESSAGE(ROSE_CAST(display_message, the_nc_function)->its_text());
  else if (the_nc_function->isa("optional_stop"))
    OPTIONAL_PROGRAM_STOP();
  else if (the_nc_function->isa("program_stop"))
    PROGRAM_STOP();
  else if (the_nc_function->isa("set_mark"))
    CHK(1, CANNOT_HANDLE_SET_MARK);
  else if (the_nc_function->isa("wait_for_mark"))
    CHK(1, CANNOT_HANDLE_WAIT_FOR_MARK);
  else if (the_nc_function->isa("exchange_pallet"))
    PALLET_SHUTTLE();
  else if (the_nc_function->isa("index_pallet"))
    CHK(1, CANNOT_HANDLE_INDEX_PALLET);
  else if (the_nc_function->isa("index_table"))
    CHK(1, CANNOT_HANDLE_INDEX_TABLE);
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_rapid

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. No toolpath is given and the security plane is not a plane:
      SECPLANE_MUST_BE_A_PLANE.
   2. execute_rapid_part returns an error code.
   3. A toolpath is given, but the toolpath_list is NULL:
      TOOLPATH_LIST_MUST_NOT_BE_NULL.
   4. A toolpath list is given, but it is empty:
      TOOLPATH_LIST_MUST_NOT_BE_EMPTY.

Side Effects: See below

Called By: execute_workingstep

rapid_movement is a subtype of both workingstep and operation

--------------
14649 data

rapid_movement
   char * its_id (from executable)
   elementary_surface * its_secplane (from workingstep)
   toolpath_list * its_toolpath (optional, from operation)
   tool_direction * its_tool_direction (optional, from operation)

If no toolpath_list is given, all this does is set the _world.rapid_secplane,
which will be used by the next function that moves the tool. If a
toolpath_list is given, this sets _world.rapid_secplane to NULL and follows
the given path.

The tool direction is not used. It might be good to require this to be null,
since if it exists, that may imply 5-axis machining is intended.

*/

static int execute_rapid(    /* ARGUMENTS                   */
 rapid_movement * the_rapid) /* the rapid motion to execute */
{
  static char name[] SET_TO "execute_rapid";
  List (toolpath) * the_path;
  int stop;
  int n;

  if (the_rapid->its_toolpath())
    {
      _world.rapid_secplane SET_TO NULL;
      the_path SET_TO the_rapid->its_toolpath()->its_list();
      CHK((the_path IS NULL), TOOLPATH_LIST_MUST_NOT_BE_NULL);
      stop SET_TO the_path->size();
      CHK((stop IS 0), TOOLPATH_LIST_MUST_NOT_BE_EMPTY);
      for (n SET_TO 0; n < stop; n++)
	{
	  IFF(execute_rapid_part((*the_path)[n]));
	}
    }
  else
    {
      CHK((NOT(the_rapid->its_secplane()->isa("plane"))),
	  SECPLANE_MUST_BE_A_PLANE);
      _world.rapid_secplane SET_TO ROSE_CAST(plane, the_rapid->its_secplane());
    }
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_rapid_part

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. This function is called: CANNOT_HANDLE_RAPID_PATH.

Side Effects: See below

Called By: execute_rapid

FIX. This is a stub.

*/

static int execute_rapid_part( /* ARGUMENTS                   */
 toolpath * a_path)            /* path to follow rapidly      */
{
  static char name[] SET_TO "execute_rapid_part";

  CHK(1, CANNOT_HANDLE_RAPID_PATH);
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_workingstep

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. execute_machining returns an error code.
   2. execute_rapid returns an error code.
   3. The workingstep is a touch_probing: CANNOT_EXECUTE_TOUCH_PROBING.
   4. The workingstep type is bad: WORKINGSTEP_TYPE_MUST_BE_DEFINED_TYPE.

Side Effects: See below

Called By: execute_executable

This executes the workingstep that is the_workingstep. It works by calling
either execute_machining or execute_rapid.

the_workingstep is known not to be NULL when this is called, so that
is not checked here.

*/

static int execute_workingstep( /* ARGUMENTS                  */
 workingstep * the_workingstep) /* the workingstep to execute */
{
  static char name[] SET_TO "execute_workingstep";

  if (the_workingstep->isa("machining_workingstep"))
    IFF(execute_machining(ROSE_CAST(machining_workingstep, the_workingstep)));
  else if (the_workingstep->isa("rapid_movement"))
    IFF(execute_rapid(ROSE_CAST(rapid_movement, the_workingstep)));
  else if (the_workingstep->isa("touch_probing"))
    CHK(1, CANNOT_EXECUTE_TOUCH_PROBING);
  else
    CHK(1, WORKINGSTEP_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_drill_tip_length

Returned Value: int (ISO14649_OK)

Side Effects: tip_length is set.

Called By:
  op_drilling
  op_multistep_drilling

This is not checking data, so check_tool_drill, which performs the checks
required to prevent this function from crashing, must be called first
with the same tool as its first argument.

See Figure 2 in section 4.3.1 of ISO 14649 Part 111. The letter variables
in this function correspond to the figure.

The machining_tool must be a cutting_tool. It therefore has a
tool_body (its_tool_body). The tool_body must be a drill.  The drill
has a dimension (milling_tool_dimension). The tool_dimension has a (diameter)
and an angle (tool_top_angle). The diameter is the diameter at the end
of the cylindrical or upper conical part of the drill before any
edge_radius is applied. If there is an edge_radius, the rounding
caused by the edge radius will make the upper part of the drill
end sooner than otherwise.

The tip_lengths below are all parallel to the drill axis.

let:
h1 = tip_length_before_edge_rounding
h2 = tip_length_from_edge_rounding
R = drill_radius
r = edge_radius
a = tool_top_angle
b = tool_circumference_angle
arm = the distance from where the top part of the drill would end
      without rounding to where it ends after rounding

The equations are:
tip_length = (h1 + h2)
h1 = (R * tan(a))
h2 = (arm * cos(b))
arm = (r / tan((90 + a + b) / 2))

Note that, assuming the toroidal rounding caused by the edge_radius is
tangent to the two surfaces it rounds, the edge_center_vertical and
edge_center_horizontal are redundant information that may be incorrect.
We are ignoring those attributes.

*/

static int find_drill_tip_length( /* ARGUMENTS               */
 machining_tool * the_tool,       /* the (should be) drill   */
 double * tip_length)             /* length of tip, set here */
{
  static char name[] SET_TO "find_drill_tip_length";
  tool_body * body;
  milling_tool_dimension * dimension;
  double arm;
  double h1;
  double h2;
  double a;
  double b;
  double R;
  double r;
  double c;   /* conversion factor to get radians from degrees */

  c SET_TO (M_PI / 180.0);
  body SET_TO (ROSE_CAST(cutting_tool, the_tool))->its_tool_body();
  dimension SET_TO (ROSE_CAST(drill, body))->dimension();
  a SET_TO dimension->tool_top_angle();
  R SET_TO (dimension->diameter() / 2.0);
  r SET_TO dimension->edge_radius();
  h1 SET_TO (R * tan(a * c));
  if ((r IS ROSE_NULL_REAL) OR (r IS 0.0))
    *tip_length SET_TO h1;
  else
    {
      b SET_TO dimension->tool_circumference_angle();
      if (b IS ROSE_NULL_REAL)
	b SET_TO 0.0;
      arm SET_TO (r / tan(((90 + a + b) / 2.0) * c));
      h2 SET_TO (arm * cos(b * c));
      *tip_length SET_TO (h1 + h2);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* find_cutting_depths

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_horizontal_plane returns an error code.
   2. Both cutting_depth and overcut_length have been given:
      MUST_NOT_HAVE_BOTH_CUTTING_DEPTH_AND_OVERCUT_LENGTH.
   3. An overcut length has been given that is not positive:
      OVERCUT_LENGTH_MUST_BE_POSITIVE.
   4. The given or calculated cutting depth is not positive:
      CUTTING_DEPTH_MUST_BE_POSITIVE.
   5. The depth of the start is not less than the cutting_depth:
      START_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH.
   6. The depth of the end is not less than the cutting_depth:
      END_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH.
   7. The depth of the end is not greater than the depth of the start:
      END_DEPTH_MUST_BE_GREATER_THAN_START_DEPTH.
   8. The total amount to cut is more than the flute_length:
      HOLE_MUST_NOT_BE_DEEPER_THAN_FLUTE_LENGTH.

Side Effects: See below

Called By:
   op_drilling
   op_multistep_drilling
   op_reaming

This sets depth, depth1, and depth2.

For the canonical machining commands, the controlled point is at the tip of
the tool. A reamer is required by check_tool_ream to have a flat end, so
the flutes extend to the end of the tool. For a drill, however, the three
depths in the data all refer to the location of the plane where the conical
tip of the drill is joined to the end of the cylindrical part of the
drill. The depth, depth1, and depth2 arguments set here are the values to
put into canonical commands for cutting.

depth is the Z coordinate of the tool tip at which to stop going deeper and
is determined as follows.

1. cutting_depth is checked or set

  If there is a cutting_depth:
  a. There must not be an overcut_length.
  b. The cutting_depth must be positive.

  Otherwise, if there is an overcut_length:
  a. The overcut_length must be positive.
  b. The cutting_depth is set to [the hole depth (the negative of the
     Z-coordinate of a point on depth plane) plus the overcut_length].

  Otherwise, the cutting_depth is set to the hole depth (Z-coordinate of
  point on depth plane).

2. depth is set to [the Z coordinate of the top of the feature minus
   [the cutting_depth plus the length of the tool tip]]. 

If there is a depth_of_start and there is [reduced_cut_at_start and/or
reduced_feed_at_start], depth1 is set. It must be positive above depth.

If there is a depth_of_end and there is [reduced_cut_at_end and/or
reduced_feed_at_end], depth2 is set. If must be above depth and, if
depth1 is set, below depth1.

The depth_plane must exist and be a plane. The placement of the plane is
given in terms of the placement of the feature. It is required here
(but not in the spec) that the axis of the placement of the plane be
vertical. Note that the Z coordinate of the location should be negative.

*/

static int find_cutting_depths(         /* ARGUMENTS                        */
 double * depth,                        /* Z coord of hole bottom set here  */
 double * depth1,                       /* Z coord of end of start set here */
 double * depth2,                       /* Z coord of start of end set here */
 double flute_length,                   /* flute length of tool             */
 double tip_length,                     /* length of tool tip, may be 0     */
 elementary_surface * depth_plane,      /* plane that is depth of hole      */
 double overcut_length,                 /* amount to overcut, may be R_NULL */
 double cutting_depth,                  /* depth to cut to, may be R_NULL   */
 drilling_type_strategy * the_strategy) /* cutting strategy, may be NULL    */
{
  static char name[] SET_TO "find_cutting_depths";
  double top;
  double start;
  double end;

  *depth1 SET_TO ROSE_NULL_REAL;
  *depth2 SET_TO ROSE_NULL_REAL;
  IFF(check_horizontal_plane(depth_plane));
  top SET_TO _world.feature_place.location()->coordinates()->get(2);
  if (cutting_depth ISNT ROSE_NULL_REAL)
    {
      CHK((overcut_length ISNT ROSE_NULL_REAL),
	  CANNOT_HAVE_BOTH_CUTTING_DEPTH_AND_OVERCUT_LENGTH);
    }
  else if (overcut_length ISNT ROSE_NULL_REAL)
    {
      CHK((overcut_length <= 0), OVERCUT_LENGTH_MUST_BE_POSITIVE);
      cutting_depth SET_TO (overcut_length -
	     depth_plane->position()->location()->coordinates()->get(2));
    }
  else
    {
      cutting_depth SET_TO (0 -
	     depth_plane->position()->location()->coordinates()->get(2));
    }
  CHK((cutting_depth <= 0), CUTTING_DEPTH_MUST_BE_POSITIVE);
  CHK(((cutting_depth + tip_length) > flute_length),
      HOLE_MUST_NOT_BE_DEEPER_THAN_FLUTE_LENGTH);
  *depth SET_TO (top - (cutting_depth + tip_length));
  if (the_strategy)
    {
      start SET_TO the_strategy->depth_of_start();
      if (start ISNT ROSE_NULL_REAL)
	{
	  CHK((start >= cutting_depth),
	      START_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH);
	  *depth1 SET_TO (top - (start + tip_length));
	}
      end SET_TO the_strategy->depth_of_end();
      if (end ISNT ROSE_NULL_REAL)
	{
	  CHK((end >= cutting_depth),
	      END_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH);
	  CHK((end <= start), END_DEPTH_MUST_BE_GREATER_THAN_START_DEPTH);
	  *depth2 SET_TO (top - (end + tip_length));
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* find_if_vertical

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. axis is NULL: DIRECTION_MUST_NOT_BE_NULL.
   2. check_direction_ratios applied to the direction ratios of the axis
      returns an error code.

Side Effects: If the X and Y components of the axis are almost 0 and
the Z component is almost 1, vertical is set to 1. Otherwise,
vertical is set to 0. "Almost" means within ISO14649_TINY.

Called By:
  check_counterbore_hole
  check_countersunk_hole
  check_horizontal_plane
  execute_machining
  transform_code

*/

static int find_if_vertical( /* ARGUMENTS                            */
 direction * axis,           /* axis that should be vertical         */
 int * vertical)             /* 0=not vertical, 1=vertical, set here */
{
  static char name[] SET_TO "find_if_vertical";
  ListOfDouble * ratios;

  CHK((axis IS NULL), DIRECTION_MUST_NOT_BE_NULL);
  ratios SET_TO axis->direction_ratios();
  IFF(check_direction_ratios(ratios));
  if ((fabs(ratios->get(0)) > ISO14649_TINY) OR
      (fabs(ratios->get(1)) > ISO14649_TINY) OR
      (fabs(ratios->get(2) - 1.0) > ISO14649_TINY))
    *vertical SET_TO 0;
  else
    *vertical SET_TO 1;
  return ISO14649_OK;
}

/***********************************************************************/

/* find_location

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_placement returns an error code when applied to place1, place2,
      or place3.

Side Effects: See below

Called By:
  execute_machining
  op_counter_boring
  op_counter_sinking

Given place1 (an axis placement for coordinate system B in terms of
coordinate system A) and place2 (an axis placement for coordinate
system C in terms of coordinate system B), this stores in place3 the
correct values for the placement of coordinate system C in terms of
coordinate system A.

It is assumed that all three coordinate systems are fully constructed
before this function is called.

The direction ratios of the y-axis of place1 are computed by taking
the cross product of the z-axis and the x-axis.

place1 and place3 may be the same, since all data is extracted from
place1 before any data is set in place3. Similarly, place2 and place3
may be the same.

It might be useful to check for more things being NULL.

*/

static int find_location(       /* ARGUMENTS                     */
  axis2_placement_3d * place1,  /* placement of B in A           */
  axis2_placement_3d * place2,  /* placement of C in B           */
  axis2_placement_3d * place3)  /* placement of C in A, set here */
{
  static char name[] SET_TO "find_location";

  double tx;
  double ty;
  double tz;
  double ix;
  double iy;
  double iz;
  double kx;
  double ky;
  double kz;
  double jx;
  double jy;
  double jz;
  double ex;
  double wy;
  double ze;
  ListOfDouble * coords;

  IFF(check_placement(place1));
  IFF(check_placement(place2));
  IFF(check_placement(place3));
  coords SET_TO place1->location()->coordinates();
  tx SET_TO coords->get(0);
  ty SET_TO coords->get(1);
  tz SET_TO coords->get(2);
  coords SET_TO place1->ref_direction()->direction_ratios();
  ix SET_TO coords->get(0);
  iy SET_TO coords->get(1);
  iz SET_TO coords->get(2);
  coords SET_TO place1->axis()->direction_ratios();
  kx SET_TO coords->get(0);
  ky SET_TO coords->get(1);
  kz SET_TO coords->get(2);
  jx SET_TO ((ky * iz) - (kz * iy));
  jy SET_TO ((kz * ix) - (kx * iz));
  jz SET_TO ((kx * iy) - (ky * ix));

  coords SET_TO place2->location()->coordinates();
  ex SET_TO coords->get(0);
  wy SET_TO coords->get(1);
  ze SET_TO coords->get(2);

  coords SET_TO place3->location()->coordinates();
  coords->put((tx + (ex * ix) + (wy * jx) + (ze * kx)), 0);
  coords->put((ty + (ex * iy) + (wy * jy) + (ze * ky)), 1);
  coords->put((tz + (ex * iz) + (wy * jz) + (ze * kz)), 2);

  coords SET_TO place2->axis()->direction_ratios();
  ex SET_TO coords->get(0);
  wy SET_TO coords->get(1);
  ze SET_TO coords->get(2);
      
  coords SET_TO place3->axis()->direction_ratios();
  coords->put(((ex * ix) + (wy * jx) + (ze * kx)), 0);
  coords->put(((ex * iy) + (wy * jy) + (ze * ky)), 1);
  coords->put(((ex * iz) + (wy * jz) + (ze * kz)), 2);
      
  coords SET_TO place2->ref_direction()->direction_ratios();
  ex SET_TO coords->get(0);
  wy SET_TO coords->get(1);
  ze SET_TO coords->get(2);
      
  coords SET_TO place3->ref_direction()->direction_ratios();
  coords->put(((ex * ix) + (wy * jx) + (ze * kx)), 0);
  coords->put(((ex * iy) + (wy * jy) + (ze * ky)), 1);
  coords->put(((ex * iz) + (wy * jz) + (ze * kz)), 2);

  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_pocket_plunge_start_toolaxis returns an error code.
   2. find_pocket_plunge_start_ramp returns an error code.
   3. find_pocket_plunge_start_zigzag returns an error code.
   4. find_pocket_plunge_start_helix returns an error code.
   5. The plunge strategy is not one of the four subtypes:
      PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE.

Side Effects: See below

Called By:
  cut_straight
  mill_rectangular_pocket_regular

This finds the start point for rectangular pockets (except plunge
pockets). The pocket has its centerline on the X-axis and has its
middle at the origin.

In all cases, the end of the starting motion should be
at X = (length - width)/-2.0    Y = 0.0

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

For a plunge_zigzag, offset_x is set to the X-offset from the start
point to the second point. The third point can be found from the
length of the zigzag. The value of offset_x is not set by plunge_helix,
plunge_toolaxis, or plunge_ramp.

*/

static int find_pocket_plunge_start( /* ARGUMENTS                           */
 double length,                      /* length of tool path                 */
 double width,                       /* width of tool path                  */
 double plunge_depth,                /* depth of plunge                     */
 plunge_strategy * enter,            /* entry strategy to use               */
 double * start_x,                   /* X coord of start, set here          */
 double * start_y,                   /* Y coord of start, set here          */
 double * aux)                       /* aux value maybe set here, see above */
{
  static char name[] SET_TO "find_pocket_plunge_start";
  double end_x;

  end_x SET_TO ((length - width) / -2.0);
  if (enter->isa("plunge_toolaxis"))
    IFF(find_pocket_plunge_start_toolaxis(start_x, start_y, end_x));
  else if(enter->isa("plunge_ramp"))
    IFF(find_pocket_plunge_start_ramp
	(length, width, plunge_depth, ROSE_CAST(plunge_ramp, enter),
	 start_x, start_y, end_x));
  else if (enter->isa("plunge_zigzag"))
    IFF(find_pocket_plunge_start_zigzag
	(length, width, plunge_depth, ROSE_CAST(plunge_zigzag, enter),
	 start_x, start_y, aux, end_x));
  else if (enter->isa("plunge_helix"))
    IFF(find_pocket_plunge_start_helix
	(width, plunge_depth, ROSE_CAST(plunge_helix, enter),
	 start_x, start_y, aux, end_x));
  else
    CHK(1, PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_helix

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the helix radius is greater than half the tool path width:
      HELIX_MUST_FIT_IN_POCKET.

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass_helix, which uses the start point and number of turns
found here.

The helix goes clockwise so that conventional cutting is done with a
right-handed tool.

The helix ends at (end_x, -radius), i.e. at 6 o'clock. This is so
that the helix may be followed by a clockwise semicircle of half the
radius of the helix with its center at (end_x, -radius/2), so that the
tool ends up at (end_x, 0) travelling in the +X direction. This
function calculates where the helix has to start to end in the right
place.

*/

static int find_pocket_plunge_start_helix(/* ARGUMENTS                       */
 double width,                            /* width of tool path              */
 double plunge_depth,                     /* depth of plunge                 */
 plunge_helix * hely,                     /* helix entry strategy            */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double * turns,                          /* turns for write_arc, set here   */
 double end_x)                            /* X coord of -X end of centerline */
{
  static char name[] SET_TO "find_pocket_plunge_start_helix";
  double turn_depth;
  double radius;
  int whole_turns;
  double fraction;      /* fraction of a turn past whole number of turns */

  radius SET_TO hely->radius();
  CHK((radius > (width / 2)), HELIX_MUST_FIT_IN_POCKET);
  turn_depth SET_TO ((2 * M_PI * radius) * tand(hely->angle()));
  whole_turns SET_TO (int) (plunge_depth / turn_depth);
  fraction SET_TO ((plunge_depth - (whole_turns * turn_depth)) / turn_depth);
  *start_x SET_TO (end_x + (radius * cos((2 * M_PI * fraction) - (M_PI / 2))));
  *start_y SET_TO (radius * sin((2 * M_PI * fraction) - (M_PI / 2)));
  *turns SET_TO (double)(-whole_turns - 1);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_ramp

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The ramp width is greater than the length of the pocket:
      RAMP_MUST_FIT_IN_POCKET.

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass, which uses the start point found here.

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

If there is room to put the whole ramp along the centerline on the -X
side of the end point, it is placed there so that the XY direction of
the tool does not need to change between the ramp and the first cut.
Otherwise, if there is room to put the whole ramp along the centerline
on the +X side of the end point (and end at the end point), it is
placed there. Otherwise, if there is room for the ramp along the
centerline in the pocket, it starts at the +X area and ends as close
to the end as possible. Otherwise the ramp does not fit along the
centerline and it is an error. We could try fitting the ramp
diagonally across the pocket (since there is the most room in that
direction) but are not doing that.

*/

static int find_pocket_plunge_start_ramp( /* ARGUMENTS                       */
 double length,                           /* length of tool path             */
 double width,                            /* width of tool path              */
 double plunge_depth,                     /* depth of plunge                 */
 plunge_ramp * the_ramp,                  /* ramp entry strategy             */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double end_x)                            /* X coord of -X end of centerline */
{
  static char name[] SET_TO "find_pocket_plunge_start_ramp";
  double distance;                        /* ramp length                     */

  *start_y SET_TO 0.0;
  distance SET_TO (plunge_depth / tand(the_ramp->angle()));
  if (distance < (width / 2.0))
    *start_x SET_TO (end_x - distance);
  else if (distance < (length - (width / 2.0)))
    *start_x SET_TO (end_x + distance);
  else if (distance < length)
    *start_x SET_TO (length / 2.0);
  else
    CHK(1, RAMP_MUST_FIT_IN_POCKET);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_toolaxis

Returned Value: int (ISO14649_OK)

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass, which uses the start point found here.

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

start_x and start_y are set. The start point is the end point, since
the tool plunges straight down.

*/

static int find_pocket_plunge_start_toolaxis( /* ARGUMENTS                   */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double end_x)                            /* X coord of -X end of centerline */
{
  static char name[] SET_TO "find_pocket_plunge_start_toolaxis";

  *start_y SET_TO 0.0;
  *start_x SET_TO end_x;
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_zigzag

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The zigzag width is greater than the length of the pocket:
      ZIGZAG_MUST_FIT_IN_POCKET.

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass_zigzag, which uses the start point found here.

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

The zigzag is always placed on the centerline of the pocket as far
towards -X as possible. The final zig is always moving towards +X if
possible (always possible except for a groove pocket). The zigzag is
traced backwards (using the given width and angle) from the bottom up
to find the start point.

Half the width of the tool path is the distance available in the -X
direction from end_x.

offset_x is set to the X offset from the start point to the second
point. The third point can be found from the length of the zigzag.

*/

static int find_pocket_plunge_start_zigzag( /* ARGUMENTS                     */
 double length,                           /* length of tool path             */
 double width,                            /* width of tool path              */
 double plunge_depth,                     /* depth of plunge                 */
 plunge_zigzag * ziggy,                   /* zigzag entry strategy           */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double * offset_x,                       /* X offset start_x to 2nd point   */
 double end_x)                            /* X coord of -X end of centerline */
{
  static char name[] SET_TO "find_pocket_plunge_start_zigzag";
  double angle;                           /* zigzag angle                    */
  double distance;                        /* zigzag length                   */
  double depth;                           /* working depth                   */
  double zig_depth;                       /* depth increment on one zig      */

  *start_y SET_TO 0.0;
  angle SET_TO ziggy->angle();
  distance SET_TO ziggy->width();
  *offset_x SET_TO 1;
  depth SET_TO plunge_depth;
  if (distance < (width / 2.0))
    {
      zig_depth SET_TO (distance * tand(angle));
      for (; depth > (zig_depth + ISO14649_TINY);
	   depth SET_TO (depth - zig_depth))
	*offset_x SET_TO (NOT(*offset_x));
      *start_x SET_TO (*offset_x ? (end_x - (depth / tand(angle))) :
		       ((end_x - distance) + (depth / tand(angle))));
    }
  else if (distance < (length + ISO14649_TINY))
    {
      zig_depth SET_TO ((width / 2.0) * tand(angle));
      if (depth < (zig_depth + ISO14649_TINY))
	*start_x SET_TO (end_x - (depth / tand(angle)));
      else
	{
	  depth SET_TO (depth - zig_depth);
	  zig_depth SET_TO (distance * tand(angle));
	  *offset_x SET_TO 0;
	  for (; depth > (zig_depth + ISO14649_TINY);
	       depth SET_TO (depth - zig_depth))
	    *offset_x SET_TO (NOT(*offset_x));
	  *start_x SET_TO 
	    (*offset_x ? (((length/-2.0) + distance) - (depth / tand(angle))):
	     ((length / -2.0) + (depth / tand(angle))));
	}
    }
  else
    CHK(1, ZIGZAG_MUST_FIT_IN_POCKET);
  *offset_x SET_TO (*offset_x ? (depth / tand(angle)) :
		    -(depth / tand(angle)));
  return ISO14649_OK;
}

/***********************************************************************/

/* find_retract_z

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The retract distance would move the tool tip above the security plane:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.

Side Effects: This sets retract_z to default_retract above top_z if
op_retract is ROSE_NULL_REAL and to op_rectact above top_z if not.

Called By:
  mill_plane_regular
  mill_rectangular_pocket
  op_center_drilling
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_multistep_drilling
  op_reaming

*/

static int find_retract_z( /* ARGUMENTS                         */
 double top_z,             /* z coord of target point           */
 double op_retract,        /* retract amount given in operation */
 double default_retract,   /* default retract amount            */
 double * retract_z)       /* retract location, set here        */
{
  static char name[] SET_TO "find_retract_z";

  *retract_z SET_TO 
    (top_z + ((op_retract IS ROSE_NULL_REAL) ? default_retract : op_retract));
  CHK((*retract_z > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_tool_index

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The id of no tool in the changer matches the id of the_tool:
      TOOL_MUST_BE_IN_TOOLCHANGER.

Side Effects: See below

Called By: change_tool

If the_tool is NULL, this sets *index to 0.

Otherwise, this finds the tool by going through the tool_table in
index order and matching the id of the_tool with the id of the tool in
the tool table at the given index. It sets *index the first time the
two match. It does not check that there are not two or more tools with
the same id.

Tool index numbers start with 1.

*/

static int find_tool_index( /* ARGUMENTS                             */
 machining_tool * the_tool, /* the tool to find in the tool table    */
 int * index)               /* index of tool in tool table, set here */
{
  static char name[] SET_TO "find_tool_index";
  
  if (the_tool IS NULL)
    *index SET_TO 0;
  else
    {
      for (*index SET_TO 1; *index <= _world.tool_max; (*index)++)
	if (strcmp(the_tool->its_id(), _world.tool_table[*index].name) IS 0) // FMP
	  break;
      CHK((*index > _world.tool_max), TOOL_MUST_BE_IN_TOOLCHANGER);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* finish_mill_both_closed_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The boundary of the pocket is NULL: POCKET_BOUNDARY_MUST_NOT_BE_NULL.
   2. The boundary of the pocket is not a rectangular_closed_profile:
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE.
   3. check_rectangular_pocket returns an error code.
   4. check_rectangular_pocket_strategies returns an error code.
   5. mill_rectangular_pocket returns an error code.
   6. transform_code returns an error code.
   7. run_code returns an error code.
   8. start_cut returns an error code.
   9. The final retract goes above the security plane:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.

Side Effects: See below

Called By: op_finish_milling_both

Data for bottom_and_side_milling
--------------------------------
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (bottom_and_side_milling)
radial_cutting_depth:   OPTIONAL length_measure;
allowance_side:         OPTIONAL length_measure;
allowance_bottom:       OPTIONAL length_measure;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPLEMENTED.
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retract_plane is the Z-coordinate of the retract plane in the coordinate
   system of the feature, which is the same as the distance between the
   top of the feature and the point to which to retract.
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
technology is handled before this function is called. This results
   in _world.feed_rate being set.
its_machine_functions is handled before this function is called.
overcut_length must not be used for pockets (Part 11, sec 4.2.3).

Data for closed_pocket
----------------------
its_id:             identifier; (manufacturing_feature)
its_workpiece:      workpiece;
its_operations:     SET [0:?] OF machining_operation;
feature_placement:  axis2_placement_3d; (two5D_manufacturing_feature)
depth:              elementary_surface (machining_feature)
its_boss:           SET [0:?] OF boss; (pocket)
slope:              OPTIONAL plane_angle_measure;
bottom_condition:   pocket_bottom_condition;
planar_radius:      OPTIONAL toleranced_length_measure;
othogonal_radius:   OPTIONAL toleranced_length_measure;
feature_boundary:   closed_profile;

Data for rectangular_closed_profile
-----------------------------------
placement:          OPTIONAL axis2_placement_3d; (profile)
<no attributes>     (closed_profile)
profile_width:      toleranced_length_measure; (rectangular_closed_profile)
profile_length:      toleranced_length_measure;

This requires the pocket to have a rectangular closed profile. It would
be fairly easy to add circular_closed_profile.

The code is generated initially in feature coordinates. Then it is
transformed into setup coordinates.

Each line of code consists of seven doubles. See run_code function
for what they mean.

The first line of code serves only to mark the point above which (by one
retract distance) the tool should be moved by the start_cut function.

Local variables pocket_length, pocket_width, pocket_depth are set in
check_rectangular_pocket, which has to deal with them anyway.

check_rectangular_pocket_strategies may insert milling strategies in
the_finish. After code is generated here, these strategies are removed
from the_finish (since the_finish may be used elsewhere) and deleted.

*/

static int finish_mill_both_closed_pocket(    /* ARGUMENTS                */
 closed_pocket * the_pocket,                  /* pocket to finish mill    */
 bottom_and_side_finish_milling * the_finish, /* finish milling operation */
 endmill * the_endmill)                       /* tool to use              */
{
  static char name[] SET_TO "finish_mill_both_closed_pocket";
  double retract_z;    /* retract z in setup c_sys       */
  double code[ISO14649_CODE_SIZE][7];
  int lines;           /* number of lines of code */
  approach_retract_strategy * enter_strategy;
  approach_retract_strategy * leave_strategy;
  two5D_milling_strategy * inside_strategy;
  double pocket_length;
  double pocket_width;
  double pocket_depth;
  double pocket_radius;
  double stepover;

  lines SET_TO 0;
  enter_strategy SET_TO NULL;
  leave_strategy SET_TO NULL;
  inside_strategy SET_TO NULL;
  CHK((the_pocket->feature_boundary() IS NULL),
      POCKET_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((NOT(the_pocket->feature_boundary()->isa("rectangular_closed_profile"))),
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE);
  IFF(check_rectangular_pocket(the_pocket, &pocket_length, &pocket_width,
			       &pocket_depth, &pocket_radius));
  IFF(check_rectangular_pocket_strategies
      (pocket_length, pocket_width, pocket_depth, pocket_radius, the_finish,
       the_endmill, &stepover, &enter_strategy, &leave_strategy,
       &inside_strategy, 1));
  IFF(mill_rectangular_pocket
      (pocket_length, pocket_width, pocket_depth, pocket_radius, stepover,
       the_endmill->dimension()->diameter(), the_finish, code, &lines));
  IFF(transform_code(code, lines, &(_world.feature_place)));
  CHK((code[0][3] > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  IFF(start_cut(code[0][1], code[0][2], code[0][3]));
  IFF(run_code((code + 1), (lines - 1)));
  if (enter_strategy)
    {
      delete enter_strategy;
      the_finish->approach(NULL);
    }
  if (leave_strategy)
    {
      delete leave_strategy;
      the_finish->retract(NULL);
    }
  if (inside_strategy)
    {
      delete inside_strategy;
      the_finish->its_machining_strategy(NULL);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_feed

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. Both feedrate and feedrate_per_tooth are given:
      MUST_NOT_HAVE_BOTH_FEEDRATE_AND_FEEDRATE_PER_TOOTH.
   2. Neither feedrate nor feedrate_per_tooth is given:
      MUST_HAVE_FEEDRATE_OR_FEEDRATE_PER_TOOTH.
   3. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   4. the_tool is not a cutting_tool: TOOL_MUST_BE_A_CUTTING_TOOL.
   5. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   6. The body of the_tool is not a milling_tool_body:
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY.
   7. The body of the tool does not have a positive number of teeth
      or the number of teeth is ROSE_NULL_INT:
      NUMBER_OF_TEETH_MUST_BE_GIVEN_AND_BE_POSITIVE.

Side Effects: See below

Called By: handle_technology

This deals with setting feed rate from either the given feed rate or
the given surface_speed and the spindle speed (which must have been
set previously). It calls SET_FEED_RATE if the desired feed rate
differs from the currently set feed rate.

ISO 14649, Part 10, section 4.2.1 gives the following (inconsistent) units:
length            millimetres
speed_measure     meters per second
rot_speed_measure revolutions per second (RPS)

Feed rate in meters per second is not consistent with the EMC and the _world,
which use millimeters per minute. If feedrate is given, this function
converts to millimeters per minute.

If feedrate_per_tooth is given, this function calculates the feedrate based
on the number of teeth according to the equation:
  feedrate [in mm/min] =
   (feedrate/tooth [in mm]) * (teeth/revolution) * (fabs(speed [in revs/min]))

The call to fabs in the last term is needed because speed may be negative.

*/

static int handle_feed(     /* ARGUMENTS                                     */
 double feedrate,           /* feedrate to use if not ROSE_NULL_REAL         */
 double feedrate_per_tooth, /* fdrate_per_tooth to use if not ROSE_NULL_REAL */
 machining_tool * the_tool) /* the tool being used                           */
{
  static char name[] SET_TO "handle_feed";
  cutting_tool * a_cutter;
  tool_body * a_body;
  milling_tool_body * mill_body;
  int teeth;

  if (feedrate ISNT ROSE_NULL_REAL)
    {
      CHK((feedrate_per_tooth ISNT ROSE_NULL_REAL),
	  MUST_NOT_HAVE_BOTH_FEEDRATE_AND_FEEDRATE_PER_TOOTH);
      feedrate SET_TO (feedrate * 60000);
    }
  else if (feedrate_per_tooth ISNT ROSE_NULL_REAL)
    {
      CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
      CHK((NOT(the_tool->isa("cutting_tool"))), TOOL_MUST_BE_A_CUTTING_TOOL);
      a_cutter SET_TO ROSE_CAST(cutting_tool, the_tool);
      a_body SET_TO a_cutter->its_tool_body();
      CHK((a_body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
      CHK((NOT(a_body->isa("milling_tool_body"))),
	  TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY);
      mill_body SET_TO ROSE_CAST(milling_tool_body, a_body);
      teeth SET_TO mill_body->number_of_teeth();
      CHK(((teeth IS ROSE_NULL_INT) OR (teeth < 1)),
	  NUMBER_OF_TEETH_MUST_BE_GIVEN_AND_BE_POSITIVE);
      feedrate SET_TO ((feedrate_per_tooth) * teeth * (fabs(_world.speed)));
    }
  else
    CHK(1, MUST_HAVE_FEEDRATE_OR_FEEDRATE_PER_TOOTH);
  if (feedrate ISNT _world.feedrate)
    {
      SET_FEED_RATE(feedrate);
      _world.feedrate SET_TO feedrate;
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_feed_override

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. disable is neither true nor false: DISABLE_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By: handle_technology

If feed_override should be disabled and isn't, it is disabled.
If feed_override should be enabled and isn't, it is enabled.

*/

static int handle_feed_override( /* ARGUMENTS                        */
 RoseBoolean disable)            /* whether to disable feed override */
{
  static char name[] SET_TO "handle_feed_override";

  if (disable IS ROSE_TRUE)
    {
      if (_world.feed_override IS ON)
	{
	  DISABLE_FEED_OVERRIDE();
	  _world.feed_override SET_TO OFF;
	}
    }
  else if (disable IS ROSE_FALSE)
    {
      if (_world.feed_override IS OFF)
	{
	  ENABLE_FEED_OVERRIDE();
	  _world.feed_override SET_TO ON;
	}
    }
  else
    CHK(1, DISABLE_MUST_BE_TRUE_OR_FALSE);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_machine_functions

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The (optional) coolant pressure is present:
      CANNOT_HANDLE_COOLANT_PRESSURE.
   2. The (optional) through pressure is present:
      CANNOT_HANDLE_THROUGH_PRESSURE.
   3. Through spindle coolant is required:
      CANNOT_HANDLE_THROUGH_SPINDLE_COOLANT.
   4. The list of axes to clamp is not empty: CANNOT_HANDLE_AXIS_CLAMPING.
   5. The (optional) process model list is not null or empty:
      CANNOT_HANDLE_PROCESS_MODEL.
   6. The other_functions set is NULL: OTHER_FUNCTIONS_MUST_NOT_BE_NULL.
   7. The other functions set is not empty: CANNOT_HANDLE_OTHER_FUNCTIONS.
   8. Coolant is neither on nor off: COOLANT_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By: execute_machining

This function requires some attributes to have specific values, as follows.
coolant_pressure: not used (i.e. ROSE_NULL_REAL)
through_spindle_coolant: false
axis_clamping: empty list of property_parameter
through_pressure: not used (i.e. ROSE_NULL_REAL)
its_process_model: not used (i.e. NULL)
other_functions: empty set of property_parameter

Other attribute values are used as follows.
coolant: if true, turn flood on if not on; if false, turn flood off if not off.
mist: if true, turn mist on if not on; if false, turn mist off if not off.
oriented_spindle_stop: not handled here, but may be used later.

This is not doing anything with chip_removal; the (boolean) value of
this attribute is irrelevant.

*/

static int handle_machine_functions(        /* ARGUMENTS                    */
 milling_machine_functions * the_functions) /* the machine functions to use */
{
  static char name[] SET_TO "handle_machine_functions";

  if (the_functions->coolant() IS ROSE_TRUE)
    {
      if (_world.flood IS OFF)
	{
	  FLOOD_ON();
	  _world.flood SET_TO ON;
	}
    }
  else if (the_functions->coolant() IS ROSE_FALSE)
    {
      if (_world.flood IS ON)
	{
	  FLOOD_OFF();
	  _world.flood SET_TO OFF;
	}
    }
  else
    CHK(1, COOLANT_MUST_BE_TRUE_OR_FALSE);
  if ((the_functions->mist() IS ROSE_TRUE) AND (_world.mist IS OFF))
    {
      MIST_ON();
      _world.mist SET_TO ON;
    }
  else if ((the_functions->mist() IS ROSE_FALSE) AND (_world.mist IS ON))
    {
      MIST_OFF();
      _world.mist SET_TO OFF;
    }
  CHK((the_functions->coolant_pressure() ISNT ROSE_NULL_REAL),
      CANNOT_HANDLE_COOLANT_PRESSURE);
  CHK((the_functions->through_pressure() ISNT ROSE_NULL_REAL),
      CANNOT_HANDLE_THROUGH_PRESSURE);
  CHK((the_functions->through_spindle_coolant() IS TRUE),
      CANNOT_HANDLE_THROUGH_SPINDLE_COOLANT);
  CHK((the_functions->axis_clamping()->size() ISNT 0),
      CANNOT_HANDLE_AXIS_CLAMPING);
  CHK((the_functions->its_process_model() AND
       the_functions->its_process_model()->size() ISNT 0),
      CANNOT_HANDLE_PROCESS_MODEL);
  CHK((the_functions->other_functions() IS NULL),
      OTHER_FUNCTIONS_MUST_NOT_BE_NULL);
  CHK((the_functions->other_functions()->size() ISNT 0),
      CANNOT_HANDLE_OTHER_FUNCTIONS);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_speed

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. Both surface speed and spindle speed are given:
      MUST_NOT_HAVE_BOTH_SPINDLE_SPEED_AND_SURFACE_SPEED.
   2. Neither surface speed nor spindle speed is given:
      MUST_HAVE_SPINDLE_SPEED_OR_SURFACE_SPEED.
   3. The diameter of the current tool is zero: TOOL_DIAMETER_MUST_NOT_BE_ZERO.
   4. A left-handed tool is to be turned clockwise:
      MUST_NOT_CUT_WITH_LEFT_HAND_TOOL_TURNING_CLOCKWISE.
   5. A right-handed tool is to be turned counterclockwise:
      MUST_NOT_CUT_WITH_RIGHT_HAND_TOOL_TURNING_COUNTERCLOCKWISE.
   6. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   7. the_tool is not a cutting_tool: TOOL_MUST_BE_A_CUTTING_TOOL.
   8. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   9. The body of the_tool is not a milling_tool_body:
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY.

Side Effects: See below

Called By: handle_technology

This deals with setting spindle speed from either the given spindle_speed
or the given surface_speed. It calls SET_SPINDLE_SPEED if the desired
speed differs from the currently set speed.

ISO 14649, Part 10, section 4.2.1 gives the following (inconsistent) units:
length            millimetres
speed_measure     meters per second
rot_speed_measure revolutions per second (RPS)

Rotational speed in RPS is not consistent with the EMC and the _world,
which use revolutions per minute (RPM). This function converts to RPM.
In addition, 14649 speed is positive counterclockwise, while the _world
speed is positive clockwise, so the sign must be switched.
The argument to SET_SPINDLE_SPEED must be positive, however.

This function is starting the spindle in the correct direction if the
speed is not zero. It is not certain in this function is the best place
to start the spindle; spindle starting might be moved elsewhere.

We are assuming here that negative surface speed means clockwise rotation,
although 14649 is not clear about this.

*/

static int handle_speed(    /* ARGUMENTS                                  */
 double spindle_speed,      /* spindle speed to use if not ROSE_NULL_REAL */
 double surface_speed,      /* surface speed to use if not ROSE_NULL_REAL */
 machining_tool * the_tool) /* the tool whose speed is being set          */
{
  static char name[] SET_TO "handle_speed";
  double diameter;
  double old_speed;
  cutting_tool * a_cutter;
  tool_body * a_body;
  milling_tool_body * mill_body;
  
  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  CHK((NOT(the_tool->isa("cutting_tool"))), TOOL_MUST_BE_A_CUTTING_TOOL);
  a_cutter SET_TO ROSE_CAST(cutting_tool, the_tool);
  a_body SET_TO a_cutter->its_tool_body();
  CHK((a_body IS NULL), TOOL_BODY_MUST_NOT_BE_NULL);
  CHK((NOT(a_body->isa("milling_tool_body"))),
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY);
  mill_body SET_TO ROSE_CAST(milling_tool_body, a_body);
  if (spindle_speed ISNT ROSE_NULL_REAL)
    {
      CHK((surface_speed ISNT ROSE_NULL_REAL),
	  MUST_NOT_HAVE_BOTH_SPINDLE_SPEED_AND_SURFACE_SPEED);
      spindle_speed SET_TO (spindle_speed * -60);
    }
  else if (surface_speed ISNT ROSE_NULL_REAL)
    {
      diameter SET_TO _world.tool_table[_world.current_tool_index].diameter;
      CHK((diameter IS 0), TOOL_DIAMETER_MUST_NOT_BE_ZERO);
      spindle_speed SET_TO ((-1000 * surface_speed) / (diameter * M_PI));
    }
  else
    CHK(1, MUST_HAVE_SPINDLE_SPEED_OR_SURFACE_SPEED);
  old_speed SET_TO _world.speed;
  if (spindle_speed ISNT old_speed)
    {
      _world.speed SET_TO spindle_speed;
    }
  if (spindle_speed > 0)
    {
      CHK((mill_body->hand_of_cut() IS hand_left),
	  MUST_NOT_CUT_WITH_LEFT_HAND_TOOL_TURNING_CLOCKWISE);
      if (spindle_speed ISNT fabs(old_speed))
	SET_SPINDLE_SPEED(spindle_speed);
      if (_world.spindle_turning ISNT CANON_CLOCKWISE)
	{
	  START_SPINDLE_CLOCKWISE();
	  _world.spindle_turning SET_TO CANON_CLOCKWISE;
	}
    }
  else if (spindle_speed < 0)
    {
      CHK((mill_body->hand_of_cut() IS hand_right),
	  MUST_NOT_CUT_WITH_RIGHT_HAND_TOOL_TURNING_COUNTERCLOCKWISE);
      if (-spindle_speed ISNT fabs(old_speed))
	SET_SPINDLE_SPEED(-spindle_speed);
      if (_world.spindle_turning ISNT CANON_COUNTERCLOCKWISE)
	{
	  START_SPINDLE_COUNTERCLOCKWISE();
	  _world.spindle_turning SET_TO CANON_COUNTERCLOCKWISE;
	}
    }
  else /* if (spindle_speed IS 0) */
    {
      if (_world.spindle_turning ISNT CANON_STOPPED)
	{
	  STOP_SPINDLE_TURNING();
	  _world.spindle_turning SET_TO CANON_STOPPED;
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_speed_override

Returned Value: int 
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The speed_override is neither enabled nor disabled:
      DISABLE_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By: handle_technology

If speed_override should be disabled and isn't, it is disabled.
If speed_override should be enabled and isn't, it is enabled.

*/

static int handle_speed_override( /* ARGUMENTS                         */
 RoseBoolean disable)             /* whether to disable speed override */
{
  static char name[] SET_TO "handle_speed_override";

  if (disable IS ROSE_TRUE)
    {
      if (_world.speed_override IS ON)
	{
	  DISABLE_SPEED_OVERRIDE();
	  _world.speed_override SET_TO OFF;
	}
    }
  else if (disable IS ROSE_FALSE)
    {
      if (_world.speed_override IS OFF)
	{
	  ENABLE_SPEED_OVERRIDE();
	  _world.speed_override SET_TO ON;
	}
    }
  else
    CHK(1, DISABLE_MUST_BE_TRUE_OR_FALSE);

  return ISO14649_OK;
}

/***********************************************************************/

/* handle_synch

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. synch is neither on nor off: SYNCH_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By: handle_technology

If speed and feed should be synchronized and aren't, they are synchronized.
If speed and feed should be not synchronized and are, they are unsynchronized.

*/

static int handle_synch( /* ARGUMENTS                             */
 RoseBoolean synch)      /* whether to synchronize feed and speed */
{
  static char name[] SET_TO "handle_synch";

  if (synch IS ROSE_TRUE)
    {
      if (_world.speed_feed_mode IS CANON_INDEPENDENT)
	{
	  START_SPEED_FEED_SYNCH();
	  _world.speed_feed_mode SET_TO CANON_SYNCHED;
	}
    }
  else if (synch IS ROSE_FALSE)
    {
      if (_world.speed_feed_mode IS CANON_SYNCHED)
	{
	  STOP_SPEED_FEED_SYNCH();
	  _world.speed_feed_mode SET_TO CANON_INDEPENDENT;
	}
    }
  else
    CHK(1, SYNCH_MUST_BE_TRUE_OR_FALSE);

  return ISO14649_OK;
}

/***********************************************************************/

/* handle_technology

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. handle_speed returns an error code.
   2. handle_feed returns an error code.
   3. handle_synch returns an error code.
   4. handle_feed_override returns an error code.
   5. handle_speed_override returns an error code.
   6. its_adaptive_control is not NULL: CANNOT_HANDLE_ADAPTIVE_CONTROL.

Side Effects: See below

Called By: execute_machining

This deals with: (1) setting spindle speed, (2) setting feed rate,
(3) setting or unsetting feed-speed synchronization, (4) enabling/disabling
feed override, (5) enabling/disabling speed override.

handle_speed must be called before handle_feed, because if feedrate_per_tooth
is given, the feedrate depends on the speed.

data
----
feedrate:                      OPTIONAL speed_measure (technology)
feedrate_reference:            tool_reference_point
cutspeed:                      OPTIONAL speed_measure (milling_technology)
spindle:                       OPTIONAL rot_speed_measure
feedrate_per_tooth:            OPTIONAL length_measure
synchronize_spindle_with_feed: BOOLEAN
inhibit_feedrate_override:     BOOLEAN
inhibit_spindle_override:      BOOLEAN
its_adaptive_control:          OPTIONAL adaptive_control

*/

static int handle_technology(         /* ARGUMENTS             */
 milling_technology * the_technology, /* the technology to use */
 machining_tool * the_tool)           /* the tool to use       */
{
  static char name[] SET_TO "handle_technology";
  
  IFF(handle_speed(the_technology->spindle(), the_technology->cutspeed(),
		   the_tool));
  IFF(handle_feed(the_technology->feedrate(),
		  the_technology->feedrate_per_tooth(), the_tool));
  IFF(handle_synch(the_technology->synchronize_spindle_with_feed()));
  IFF(handle_feed_override(the_technology->inhibit_feedrate_override()));
  IFF(handle_speed_override(the_technology->inhibit_spindle_override()));
  CHK((the_technology->its_adaptive_control() ISNT NULL),
      CANNOT_HANDLE_ADAPTIVE_CONTROL);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_tool

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. change_tool returns an error code.

Side Effects: If the_tool is not the current tool, the tool is changed.

Called By:
  execute_machining
  execute_nc_function

*/

static int handle_tool(     /* ARGUMENTS                             */
 machining_tool * the_tool, /* the tool to use                       */
 int set_flag)              /* whether to set the _world.action_flag */
{
  static char name[] SET_TO "handle_tool";

  CHK((the_tool IS NULL), TOOL_MUST_NOT_BE_NULL);
  if (strcmp(the_tool->its_id(),
	     _world.tool_table[_world.current_tool_index].name) ISNT 0)	// FMP
    IFF(change_tool(the_tool, set_flag));
  return ISO14649_OK;
}

/****************************************************************************/

/* handle_unload_tool

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is not NULL: THE_TOOL_MUST_BE_NULL_IN_UNLOAD_TOOL
   2. change_tool returns an error code.

Side Effects: See below

Called By: execute_nc_function

In ISO 14649, Part 11, section 4.2.1.5, which describes the
unload_tool command, makes the_tool argument optional and says it must
be used if two tools are in use at the same time. In the EMC, only one
tool can be in use at a time, so this data is never needed. To avoid
having to check for the error of trying to unload a tool that is not
in the spindle, this function requires that the_tool be NULL.

If the_tool is null, and the current tool index is not zero (meaning
there is no tool in the spindle), this takes the current tool out
of the spindle and sets the current tool index to zero.

It is not an error to call this function if there is no tool in the
spindle.

*/

static int handle_unload_tool( /* ARGUMENTS               */
 machining_tool * the_tool)    /* must be null, see above */
{
  static char name[] SET_TO "handle_unload_tool";

  CHK((the_tool ISNT NULL), THE_TOOL_MUST_BE_NULL_IN_UNLOAD_TOOL);
  if (_world.current_tool_index)
    IFF(change_tool(NULL, 1));
  return ISO14649_OK;
}

/****************************************************************************/

/* init_place

Returned Value: int (ISO14649_OK)

Side Effects: This sets the place to the default location: origin at
(0,0,0), Z-axis of (0,0,1), X-axis of (1,0,0).  The place, which must
already exist, gets all new components (on the assumption that the
components are all NULL or are garbage pointers or can be discarded).

Called By:
  check_and_store
  iso14649_init
  op_counter_boring
  op_counter_sinking

*/

static int init_place(        /* ARGUMENTS                   */
 axis2_placement_3d * place)  /* placement filled out here   */
{
  static char name[] SET_TO "init_place";
  cartesian_point * origin;            /* origin for placement, built here  */
  direction * axis;                    /* z-axis for placement, built here  */
  direction * ref;                     /* x-axis for placement, built here  */
  ListOfDouble * origin_coords; 
  ListOfDouble * axis_ratios; 
  ListOfDouble * ref_ratios; 

  origin_coords SET_TO new ListOfDouble;
  origin_coords->add(0.0);
  origin_coords->add(0.0);
  origin_coords->add(0.0);
  axis_ratios SET_TO new ListOfDouble;
  axis_ratios->add(0.0);
  axis_ratios->add(0.0);
  axis_ratios->add(1.0);
  ref_ratios SET_TO new ListOfDouble;
  ref_ratios->add(1.0);
  ref_ratios->add(0.0);
  ref_ratios->add(0.0);
  place->location(new cartesian_point("point", origin_coords));
  place->axis(new direction("direction", axis_ratios));
  place->ref_direction(new direction("direction", ref_ratios));
  return ISO14649_OK;
}

/***********************************************************************/

/* is_default_placement

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_placement returns an error code.
   2. The origin is not at (0, 0, 0):
      DEFAULT_PLACEMENT_ORIGIN_MUST_BE_AT_ZERO_ZERO_ZERO,
   3. The axis is not (0, 0, 1):
      DEFAULT_PLACEMENT_AXIS_MUST_BE_ZERO_ZERO_ONE.
   4. The ref_direction is not (1, 0, 0):
      DEFAULT_PLACEMENT_REF_DIRECTION_MUST_BE_ONE_ZERO_ZERO.

Side Effects:  None

Called By:  check_and_store

Note that this is checking exact values, not using a tolerance. This may
need to be changed.

*/

static int is_default_placement( /* ARGUMENTS               */
 axis2_placement_3d * place)     /* axis placement to check */
{
  static char name[] SET_TO "is_default_placement";
  ListOfDouble * origin_coords; 
  ListOfDouble * axis_ratios; 
  ListOfDouble * ref_ratios; 

  IFF(check_placement(place));
  origin_coords SET_TO place->location()->coordinates();
  axis_ratios SET_TO place->axis()->direction_ratios();
  ref_ratios SET_TO place->ref_direction()->direction_ratios();
  CHK(((origin_coords->get(0) ISNT 0.0) OR (origin_coords->get(1) ISNT 0.0) OR
       (origin_coords->get(2) ISNT 0.0)),
      DEFAULT_PLACEMENT_ORIGIN_MUST_BE_AT_ZERO_ZERO_ZERO);
  CHK(((axis_ratios->get(0) ISNT 0.0) OR (axis_ratios->get(1) ISNT 0.0) OR
       (axis_ratios->get(2) ISNT 1.0)),
      DEFAULT_PLACEMENT_AXIS_MUST_BE_ZERO_ZERO_ONE);
  CHK(((ref_ratios->get(0) ISNT 1.0) OR (ref_ratios->get(1) ISNT 0.0) OR
       (ref_ratios->get(2) ISNT 0.0)),
      DEFAULT_PLACEMENT_REF_DIRECTION_MUST_BE_ONE_ZERO_ZERO);
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_circular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_arc returns an error code.

Side Effects:  the code array is written into, and the lines index is
   increased.

Called By: mill_rectangular_pocket_regular

When this starts up, the tool tip is at the center of the circular
pocket and inserted to the correct depth.

This recalculates stepover so that all stepovers are the same size
(rather then having one last one be smaller than the others if
necessary).

When spiral is 1, this moves one stepover towards +X, makes a circle
counterclockwise, etc, until it is done.

When spiral is -1, the direction of path rotation is switched to
clockwise by reversing the direction of arcs.

*/

static int mill_circular_pocket( /* ARGUMENTS                        */
 double length,                  /* length (and width) of pocket     */
 double z_now,                   /* Z coordinate at cutting depth    */
 double stepover,                /* horizontal stepover              */
 double tool_diameter,           /* diameter of tool                 */
 int spiral,                     /* 1=counterclockwise, -1=clockwise */
 double code[][7],               /* code array to write in           */
 int * lines)                    /* code array index                 */
{
  static char name[] SET_TO "mill_circular_pocket";
  double total;      /* total of all stepovers   */
  double radius_now; /* radius of current circle */
  int passes;        /* number of stepovers      */
  int n;

  total SET_TO ((length - tool_diameter) / 2.0);
  passes SET_TO (1 + (int)((total - ISO14649_TINY) / stepover));
  stepover SET_TO (total / passes);
  radius_now SET_TO 0;
  for (n SET_TO 0; n < passes; n++)
    {
      radius_now SET_TO (radius_now + stepover);
      IFF(write_feed(radius_now, 0, z_now, code, lines));
      IFF(write_arc(radius_now, 0, 0, 0, spiral, z_now, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_planar_face returns an error code.
   2. check_plane_milling_strategies returns an error code.
   3. mill_planar_regular returns an error code.

Side Effects: See below

Called By:
  op_finish_milling_plane
  op_rough_milling_plane

Data for plane_milling
--------------------------------
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (plane_milling)
allowance_bottom:       OPTIONAL length_measure;

check_plane_milling_strategies may insert milling strategies in
the_milling. After code is generated here, these strategies are removed
from the_milling (since the_milling may be used elsewhere) and deleted.

If the_cut does not give an overcut_length, it is set here as 1.25
times the tool diameter. For unidirectional_milling this is needed to avoid
collisions when plunging. For bidirectional_milling this gets the tool
clear of the planar_face before it changes direction, leaving a better
surface finish than if that is not done.

If the cut does not have a pass_depth, pass_depth is set to half of
the diameter or half of the edge_length, whichever is less. This is
to make the pass_depth reasonable for either an endmill (for which
diameter is usually much less than edge_length) or a facemill (for
which edge_length is usually much less than diameter).

Notes:

This is assuming that there is no material to collide with to the sides
of the bottom of the face being milled. A solid modeler would be needed
to verify that this is a correct assumption.

Since only a plunge_toolaxis strategy is currently being handled for
approach and retract, the enter_strategy and leave_strategy are not
really required; their existence can be assumed. If it becomes
possible to handle other approach and retract strategies, the
enter_strategy and leave_strategy will be needed.

*/

static int mill_planar(     /* ARGUMENTS                                   */
 planar_face * the_face,    /* planar face to make                         */
 plane_milling * the_cut,   /* plane_finish_milling or plane_rough_milling */
 milling_cutter * the_mill) /* an endmill or facemill                      */
{
  static char name[] SET_TO "mill_planar";
  approach_retract_strategy * enter_strategy;
  approach_retract_strategy * leave_strategy;
  two5D_milling_strategy * inside_strategy;
  double stepover;
  double overlap;      /* overlap used to find horizontal stepover      */
  double diameter;     /* diameter of cutter                            */
  double plane_length; /* X-size of rectangle, set in check_planar_face */
  double plane_width;  /* Y-size of rectangle, set in check_planar_face */
  double plane_depth;  /* positive depth set in check_planar_face       */
  double pass_depth;   /* see above                                     */
  double edge_length;  /* edge length of the_mill                       */
  double overcut;      /* as given, or 1.25 times diameter if NULL      */

  diameter SET_TO the_mill->dimension()->diameter();
  edge_length SET_TO the_mill->dimension()->cutting_edge_length();
  enter_strategy SET_TO NULL;
  leave_strategy SET_TO NULL;
  inside_strategy SET_TO NULL;
  IFF(check_planar_face(the_face, &plane_length, &plane_width, &plane_depth));
  IFF(check_plane_milling_strategies(the_cut, diameter, &enter_strategy,
				     &leave_strategy, &inside_strategy));
  overlap SET_TO the_cut->its_machining_strategy()->overlap();
  if (overlap IS ROSE_NULL_REAL)
    overlap SET_TO 0.2;
  stepover SET_TO (diameter * (1 - overlap));
  pass_depth SET_TO the_cut->axial_cutting_depth();
  if (pass_depth IS ROSE_NULL_REAL)
    pass_depth SET_TO MIN((diameter / 2.0), (edge_length / 2.0));
  overcut SET_TO the_cut->overcut_length();
  if (overcut IS ROSE_NULL_REAL)
    overcut SET_TO (diameter * 1.25);
  IFF(mill_planar_regular(plane_length, plane_width, plane_depth, diameter,
			  pass_depth, stepover, overcut, the_cut));
  if (enter_strategy)
    {
      delete enter_strategy;
      the_cut->approach(NULL);
    }
  if (leave_strategy)
    {
      delete leave_strategy;
      the_cut->retract(NULL);
    }
  if (inside_strategy)
    {
      delete inside_strategy;
      the_cut->its_machining_strategy(NULL);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar_bi

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The function pointed at by feeder returns an error code.
   2. The function pointed at by traverser returns an error code.

Side Effects: See below

Called By: mill_planar_regular

This generates pseudocode in feature coordinates for milling a
rectangular patch of planar_face in the first quadrant with a side on
the X-axis and another side on the Y-axis.

data for bidirectional_milling
------------------------------
overlap:                         OPTIONAL positive_ratio_measure (two5D_m_s)
allow_multiple_passes:           OPTIONAL BOOLEAN;
feed_direction:                  OPTIONAL direction (bidirectional_milling) 
stepover_direction:              OPTIONAL left_or_right;
its_stroke_connection_strategy:  OPTIONAL stroke_connection_strategy

Section 4.2.8.1.2 of Part 11 says feed_direction is the direction of the
first cut (we are assuming the directions are in terms of the coordinate
system of the feature).

It has already been checked that if the feed_direction exists it is parallel
to the +X, -X, +Y, or -Y axis, but it might not exist.

The pass_depth has been selected so that the mill_depth is divisible
evenly by the pass_depth.

This handles 8 cases (the 4 possible starting directions times the 2
first stepover sides).

This is moving the cutter at the given feed rate (not at traverse rate)
between horizontal cuts. Traverse rate could be used instead. That would
save time but is more risky. Between vertical passes, a traverse is made
while retracted from the last XY location back to the first. That is not
risky because anything that might be collided with has been milled away
or already hit.

On each cut except (probably) the last this cuts a horizontal strip one
stepover wide.

This is not being clever about the last horizontal cut of each pass, which
could, for example, be made down the center of the last strip of material
or be made so that only a small part of the cutter sticks off the edge
of material.

*/

static int mill_planar_bi(   /* ARGUMENTS                      */
 double length,              /* length (X-size) of face to cut */
 double width,               /* width (Y-size) of face to cut  */
 int passes,                 /* number of passes to make       */
 double diameter,            /* diameter of cutter             */
 double pass_depth,          /* positive vertical pass_depth   */
 double stepover,            /* horizontal stepover            */
 double overage,             /* clearance tool center to edge  */
 double retract,             /* amount by which to retract     */
 bidirectional_milling * bi, /* bidirectional milling strategy */
 double code[][7],           /* code array to write in         */
 int * lines)                /* code array index               */
{
  static char name[] SET_TO "mill_planar_bi";
  int cuts;                  /* number of horizontal cuts to make      */
  double x1;                 /* first (and odd numbered) X position    */
  double x2;                 /* second (and even numbered) X position  */
  double y1;                 /* first Y position                       */
  double x_now;              /* current X position, gets updated       */
  double y_now;              /* current Y position, gets updated       */
  double z_now;              /* current Z position, gets updated       */
  ListOfDouble * components; /* components of first direction          */
  int direction1;            /* 1=+X, 2=-X, 3=+Y, 4=-Y                 */
  int n;                     /* vertical pass counter                  */
  int m;                     /* horizontal cut counter                 */
  int sign;                  /* set to +1 or -1 for Y increments       */
  int (*feeder)(double, double, double, double[][7], int *);
  int (*traverser)(double, double, double, double[][7], int *);

  if (bi->feed_direction())
    components SET_TO bi->feed_direction()->direction_ratios();
  direction1 SET_TO ((bi->feed_direction() IS NULL) ? 1 :
		     (components->get(0) > 0)       ? 1 :
		     (components->get(0) < 0)       ? 2 :
		     (components->get(1) > 0)       ? 3 : 4);
  if (direction1 < 3) /* cuts parallel to X-axis */
    {
      feeder SET_TO write_feed;
      traverser SET_TO write_traverse;
      cuts SET_TO (1 + (int)((width - ISO14649_TINY) / stepover));
      if (direction1 IS 1) /* first cut in +X direction */
	{
	  x1 SET_TO -overage;
	  x2 SET_TO (length + overage);
	  if (bi->stepover_direction() IS left_or_right_left)
	    {
	      sign SET_TO +1;
	      y1 SET_TO (stepover - (diameter / 2.0));
	    }
	  else /* if bi->stepover_direction IS right or not given */
	    {
	      sign SET_TO -1;
	      y1 SET_TO (width - (stepover - (diameter / 2.0)));
	    }
	}
      else /* if (direction1 IS 2), first cut in -X direction */
	{
	  x1 SET_TO (length + overage);
	  x2 SET_TO -overage;
	  if (bi->stepover_direction() IS left_or_right_left)
	    {
	      sign SET_TO -1;
	      y1 SET_TO (width - (stepover - (diameter / 2.0)));
	    }
	  else /* if bi->stepover_direction() IS right or not given */
	    {
	      sign SET_TO +1;
	      y1 SET_TO (stepover - (diameter / 2.0));
	    }
	}
    }
  else /* cuts parallel to Y-axis */
    {
      feeder SET_TO write_feed_y;
      traverser SET_TO write_traverse_y;
      cuts SET_TO (1 + (int)((length - ISO14649_TINY) / stepover));
      if (direction1 IS 3) /* first cut in +Y direction */
	{
	  x1 SET_TO -overage;
	  x2 SET_TO (width + overage);
	  if (bi->stepover_direction() IS left_or_right_left)
	    {
	      sign SET_TO +1;
	      y1 SET_TO (-length + (stepover - (diameter / 2.0)));
	    }
	  else /* if bi->stepover_direction() IS right or not given */
	    {
	      sign SET_TO -1;
	      y1 SET_TO -(stepover - (diameter / 2.0));
	    }
	}
      else /* if (direction1 IS 4), first cut in -Y direction */
	{
	  x1 SET_TO (width + overage);
	  x2 SET_TO -overage;
	  if (bi->stepover_direction() IS left_or_right_left)
	    {
	      sign SET_TO -1;
	      y1 SET_TO -(stepover - (diameter / 2.0));
	    }
	  else /* if bi->stepover_direction() IS right or not given */
	    {
	      sign SET_TO +1;
	      y1 SET_TO (-length + (stepover - (diameter / 2.0)));
	    }
	}
    }
  IFF(feeder(x1, y1, retract, code, lines));
  z_now SET_TO 0;
  for (n SET_TO 0; n < passes; n++)
    {
      y_now SET_TO y1;
      x_now SET_TO x1;
      z_now SET_TO (z_now - pass_depth);
      IFF(feeder(x_now, y_now, z_now, code, lines));
      for (m SET_TO 0; m < cuts; m++)
	{
	  x_now SET_TO ((x_now IS x1) ? x2: x1);
	  IFF(feeder(x_now, y_now, z_now, code, lines));
	  if (m < (cuts - 1))
	    {
	      y_now SET_TO (y_now + (sign * stepover));
	      IFF(feeder(x_now, y_now, z_now, code, lines));
	    }
	}
      IFF(traverser(x_now, y_now, retract, code, lines));
      if (n < (passes - 1))
	IFF(traverser(x1, y1, retract, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar_regular

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. A retract above the current security plane is programmed:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.
   2. A milling strategy not unidirectional_milling or
      bidirectional_milling is given:
      CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING.
   3. mill_planar_bi returns an error code.
   4. mill_planar_uni returns an error code.
   5. start_cut returns an error code.
   6. run_code returns an error code.
   7. find_retract_z returns an error code.
   8. transform_code returns an error code.

Side Effects: See below

Called By: mill_planar

This cuts a rectangular patch of planar face in the first quadrant. One
side of the rectangle lies on the X-axis, another on the Y-axis. First
it generates pseudocode; then it executes the pseudocode.

The plane_depth is positive.

Notes:

The current location is not explicitly updated here since run_code
(which is called here) does the updating.

*/

static int mill_planar_regular( /* ARGUMENTS                       */
 double plane_length,           /* length (X-size) of face to cut  */
 double plane_width,            /* width (Y-size) of face to cut   */
 double plane_depth,            /* depth without bottom allowance  */
 double diameter,               /* diameter of cutter              */
 double pass_depth,             /* given pass_depth, reset here    */
 double stepover,               /* horizontal stepover             */
 double overcut,                /* amount of overcut to use        */
 plane_milling * the_cut)       /* plane milling operation to do   */   
{
  static char name[] SET_TO "mill_planar_regular";
  double code[ISO14649_CODE_SIZE][7]; /* lines of code          */
  int lines;                      /* number of lines of code    */
  double mill_depth;              /* depth to which to cut      */
  int passes;                     /* number of passes to make   */
  double retract;                 /* amount by which to retract */
  two5D_milling_strategy * strat; /* strategy to use            */
  
  lines SET_TO 0;
  mill_depth SET_TO
    ((the_cut->allowance_bottom() ISNT ROSE_NULL_REAL) ?
     (plane_depth - the_cut->allowance_bottom()) :
     (the_cut->isa("plane_rough_milling")) ?
     (plane_depth - ISO14649_ALLOW) : plane_depth);
  passes SET_TO (1 + (int)((mill_depth - ISO14649_TINY) / pass_depth));
  pass_depth SET_TO (mill_depth / passes);
  IFF(find_retract_z(0, the_cut->retract_plane(), ISO14649_UP, &retract));
  strat SET_TO the_cut->its_machining_strategy();
  if (strat->isa("bidirectional_milling"))
    IFF(mill_planar_bi(plane_length, plane_width, passes, diameter,
		       pass_depth, stepover, (overcut - (diameter/2)), retract,
		       ROSE_CAST(bidirectional_milling, strat), code, &lines));
  else if (strat->isa("unidirectional_milling"))
    IFF(mill_planar_uni(plane_length, plane_width, passes, diameter,
			pass_depth, stepover, (overcut -(diameter/2)),
			retract, ROSE_CAST(unidirectional_milling, strat),
			code, &lines));
  else
    CHK(1, CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING);
  IFF(transform_code(code, lines, &(_world.feature_place)));
  CHK((code[0][3] > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  IFF(start_cut(code[0][1], code[0][2], code[0][3]));
  IFF(run_code((code + 1), (lines - 1)));
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar_uni

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The function pointed at by feeder returns an error code.
   2. The function pointed at by traverser returns an error code.

Side Effects: See below

Called By: mill_planar_regular

This generates pseudocode in feature coordinates for milling a
rectangular patch of planar_face in the first quadrant with a side on
the X-axis and another side on the Y-axis.

data for unidirectional_milling
-------------------------------
overlap:                OPTIONAL positive_ratio_measure (two5D_m_s)
allow_multiple_passes:  OPTIONAL BOOLEAN
feed_direction:         OPTIONAL direction (unidirectional_milling) 
cutmode:                OPTIONAL cutmode_type

Section 4.2.8.1.2 of Part 11 says feed_direction is the direction of the
first cut (we are assuming the directions are in terms of the coordinate
system of the feature).

It has already been checked that if the feed_direction exists it is parallel
to the +X, -X, +Y, or -Y axis, but it might not exist.

The pass_depth has been selected so that the mill_depth is divisible
evenly by the pass_depth.

This handles 8 cases (the 4 possible starting directions times the 2
first stepover sides).

On each cut except (probably) the last, this cuts a horizontal strip one
stepover wide.

If cutmode is not given, this defaults to conventional.

This is not being clever about the last horizontal cut of each pass, which
could, for example, be made down the center of the last strip of material
or be made so that only a small part of the cutter sticks off the edge
of material.

This is assuming a right-handed tool. This could be checked.

*/
static int mill_planar_uni(    /* ARGUMENTS                       */
 double length,                /* length (X-size) of face to cut  */
 double width,                 /* width (Y-size) of face to cut   */
 int passes,                   /* number of passes to make        */
 double diameter,              /* diameter of cutter              */
 double pass_depth,            /* positive vertical pass_depth    */
 double stepover,              /* horizontal stepover             */
 double overage,               /* clearance tool center to edge   */
 double retract,               /* amount by which to retract      */
 unidirectional_milling * uni, /* unidirectional milling strategy */
 double code[][7],             /* code array to write in          */
 int * lines)                  /* code array index                */
{
  static char name[] SET_TO "mill_planar_uni";
  int cuts;                  /* number of horizontal cuts to make      */
  double x1;                 /* first (and odd numbered) X position    */
  double x2;                 /* second (and even numbered) X position  */
  double y1;                 /* first Y position                       */
  double y_now;              /* current Y position, gets updated       */
  double z_now;              /* current Z position, gets updated       */
  ListOfDouble * components; /* components of first direction          */
  int direction1;            /* 1=+X, 2=-X, 3=+Y, 4=-Y                 */
  int n;                     /* vertical pass counter                  */
  int m;                     /* horizontal cut counter                 */
  int sign;                  /* set to +1 or -1 for Y increments       */
  int (*feeder)(double, double, double, double[][7], int *);
  int (*traverser)(double, double, double, double[][7], int *);

  if (uni->feed_direction())
    components SET_TO uni->feed_direction()->direction_ratios();
  direction1 SET_TO ((uni->feed_direction() IS NULL) ? 1 :
		     (components->get(0) > 0)        ? 1 :
		     (components->get(0) < 0)        ? 2 :
		     (components->get(1) > 0)        ? 3 : 4);
  if (direction1 < 3) /* cuts parallel to X-axis */
    {
      feeder SET_TO write_feed;
      traverser SET_TO write_traverse;
      cuts SET_TO (1 + (int)((width - ISO14649_TINY) / stepover));
      if (direction1 IS 1) /* first cut in +X direction */
	{
	  x1 SET_TO -overage;
	  x2 SET_TO (length + overage);
	  if (uni->cutmode() IS cutmode_type_climb)
	    {
	      sign SET_TO -1;
	      y1 SET_TO (width - (stepover - (diameter / 2.0)));
	    }
	  else /* if uni->cutmode() IS conventional or not given */
	    {
	      sign SET_TO +1;
	      y1 SET_TO (stepover - (diameter / 2.0));
	    }
	}
      else /* if (direction1 IS 2), first cut in -X direction */
	{
	  x1 SET_TO (length + overage);
	  x2 SET_TO -overage;
	  if (uni->cutmode() IS cutmode_type_climb)
	    {
	      sign SET_TO +1;
	      y1 SET_TO (stepover - (diameter / 2.0));
	    }
	  else /* if uni->cutmode() IS conventional or not given */
	    {
	      sign SET_TO -1;
	      y1 SET_TO (width - (stepover - (diameter / 2.0)));
	    }
	}
    }
  else /* cuts parallel to Y-axis */
    {
      feeder SET_TO write_feed_y;
      traverser SET_TO write_traverse_y;
      cuts SET_TO (1 + (int)((length - ISO14649_TINY) / stepover));
      if (direction1 IS 3) /* first cut in +Y direction */
	{
	  x1 SET_TO -overage;
	  x2 SET_TO (width + overage);
	  if (uni->cutmode() IS cutmode_type_climb)
	    {
	      sign SET_TO -1;
	      y1 SET_TO -(stepover - (diameter / 2.0));
	    }
	  else /* if uni->cutmode() IS conventional or not given */
	    {
	      sign SET_TO +1;
	      y1 SET_TO (-length + (stepover - (diameter / 2.0)));
	    }
	}
      else /* if (direction1 IS 4), first cut in -Y direction */
	{
	  x1 SET_TO (width + overage);
	  x2 SET_TO -overage;
	  if (uni->cutmode() IS cutmode_type_climb)
	    {
	      sign SET_TO +1;
	      y1 SET_TO (-length + (stepover - (diameter / 2.0)));
	    }
	  else /* if uni->cutmode() IS conventional or not given */
	    {
	      sign SET_TO -1;
	      y1 SET_TO -(stepover - (diameter / 2.0));
	    }
	}
    }
  IFF(feeder(x1, y1, retract, code, lines));
  z_now SET_TO 0;
  for (n SET_TO 0; n < passes; n++)
    {
      y_now SET_TO y1;
      z_now SET_TO (z_now - pass_depth);
      IFF(feeder(x1, y_now, z_now, code, lines));
      for (m SET_TO 0; m < cuts; m++)
	{
	  IFF(feeder(x2, y_now, z_now, code, lines));
	  IFF(traverser(x2, y_now, retract, code, lines));
	  if (m < (cuts - 1))
	    {
	      y_now SET_TO (y_now + (sign * stepover));
	      IFF(traverser(x1, y_now, retract, code, lines));
	      IFF(feeder(x1, y_now, z_now, code, lines));
	    }
	}
      if (n < (passes - 1))
	IFF(traverser(x1, y1, retract, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_rectangular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The pocket depth is not positive: POCKET_DEPTH_MUST_BE_POSITIVE.
   2. find_retract_z returns an error code.
   3. The pocket width is less than the tool diameter:
      POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL.
   4. plunge_pocket returns an error code.
   5. cut_straight returns an error code.
   6. mill_rectangular_pocket_regular returns an error code.

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  rough_mill_both_closed_pocket

Data for closed_pocket
----------------------
its_id:             identifier; (manufacturing_feature)
its_workpiece:      workpiece;
its_operations:     SET [0:?] OF machining_operation;
feature_placement:  axis2_placement_3d; (two5D_manufacturing_feature)
depth:              elementary_surface (machining_feature)
its_boss:           SET [0:?] OF boss; (pocket)
slope:              OPTIONAL plane_angle_measure;
bottom_condition:   pocket_bottom_condition;
planar_radius:      OPTIONAL toleranced_length_measure;
othogonal_radius:   OPTIONAL toleranced_length_measure;
feature_boundary:   closed_profile;

Data for rectangular_closed_profile
-----------------------------------
placement:          OPTIONAL axis2_placement_3d; (profile)
<no attributes>     (closed_profile)
profile_width:      toleranced_length_measure; (rectangular_closed_profile)
profile_length:      toleranced_length_measure;

Data for bottom_and_side_milling
--------------------------------
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (bottom_and_side_milling)
radial_cutting_depth:   OPTIONAL length_measure;
allowance_side:         OPTIONAL length_measure;
allowance_bottom:       OPTIONAL length_measure;

This writes code into the code argument assuming the pocket is in default
position (at the origin).

The first point in the code must be the highest point reached during
machining so that checking that the transformed first point is below
the security plane will insure that all tool motion is below the
security plane.

axial_cutting_depth (pass_depth) and radial_cutting_depth (stepover)
may be ROSE_NULL_REAL. check_op_finish_both or check_op_rough_both has
already checked that they are positive if they are not ROSE_NULL_REAL.
This sets each to one tool radius if it is ROSE_NULL_REAL. It would be
better to implement rules for setting them here, as is done in FBICS.

If the allowance_bottom is not ROSE_NULL_REAL, the cutting depth is set
allowance_bottom less than the pocket depth.
If the allowance_bottom is ROSE_NULL_REAL, and this is rough milling, the
cutting depth is set to ISO14649_ALLOW less than the pocket depth.
If the allowance_bottom is ROSE_NULL_REAL, and this is finish milling, the
cutting depth is set to the pocket depth.

The allowance_side may be ROSE_NULL_REAL. If so, and this is rough
milling, the side allowance is set to ISO14649_ALLOW. If so and
this is finish milling, the side allowance is set to zero.

*/

static int mill_rectangular_pocket(  /* ARGUMENTS              */
 double pocket_length,               /* length of final pocket */
 double pocket_width,                /* width of final pocket  */
 double pocket_depth,                /* depth of final pocket  */
 double pocket_radius,               /* radius of final pocket */
 double stepover,                    /* stepover for cutting   */
 double tool_diameter,               /* diameter of tool       */
 bottom_and_side_milling * the_cut,  /* operation to execute   */
 double code[][7],                   /* code array to write in */
 int * lines)                        /* code array index       */
{
  static char name[] SET_TO "mill_rectangular_pocket";
  double side;         /* thickness to leave on sides */
  double retract;      /* amount by which to retract  */
  double mill_length;  /* length of pocket to make    */
  double mill_width;   /* width of pocket to make     */
  double mill_depth;   /* depth of pocket to make     */
  double extra_length; /* length of toolpath          */
  double extra_width;  /* width of toolpath           */
  double pass_depth;

  mill_depth SET_TO
    ((the_cut->allowance_bottom() ISNT ROSE_NULL_REAL) ?
     (pocket_depth - the_cut->allowance_bottom()) :
     (the_cut->isa("bottom_and_side_rough_milling")) ?
     (pocket_depth - ISO14649_ALLOW) : pocket_depth);
  CHK((mill_depth <= 0), POCKET_DEPTH_MUST_BE_POSITIVE);
  side SET_TO
    ((the_cut->allowance_side() ISNT ROSE_NULL_REAL) ?
     the_cut->allowance_side() :
     (the_cut->isa("bottom_and_side_rough_milling")) ?
     ISO14649_ALLOW : 0.0);
  mill_length SET_TO (pocket_length - (2 * side));
  mill_width  SET_TO (pocket_width  - (2 * side));
  extra_length SET_TO (mill_length - tool_diameter);
  extra_width  SET_TO (mill_width  - tool_diameter);
  pass_depth SET_TO ((the_cut->axial_cutting_depth() IS ROSE_NULL_REAL) ?
		     (tool_diameter / 2.0) : the_cut->axial_cutting_depth());
  CHK((extra_width < -(ISO14649_TINY)), POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL);
  IFF(find_retract_z(0, the_cut->retract_plane(), ISO14649_UP, &retract));
  if (extra_width < ISO14649_TINY)
    {
      if (extra_length < ISO14649_TINY)
	IFF(plunge_pocket(mill_depth, retract, code, lines));
      else
	IFF(cut_straight(mill_length, mill_depth, retract, pass_depth,
			 the_cut->approach(), the_cut->retract(),
			 tool_diameter, code, lines));
    }
  else
    IFF(mill_rectangular_pocket_regular
	(mill_length, mill_width, mill_depth, (pocket_radius - side),
	 retract, pass_depth, stepover, the_cut->approach(),
	 the_cut->retract(), the_cut->its_machining_strategy(),
	 tool_diameter, code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_rectangular_pocket_regular

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The milling strategy is not contour_parallel:
      CAN_HANDLE_ONLY_CONTOUR_PARALLEL_MILLING_STRATEGY.
   2. The approach strategy is not a subtype of plunge_strategy:
      CAN_HANDLE_ONLY_PLUNGE_APPROACH.
   3. The retract strategy is not plunge_toolaxis:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT.
   4. The combination of path direction and cutmode would require cutting
      outside in (rather then inside out): CANNOT_HANDLE_OUTSIDE_IN_CUTTING.
   5. find_pocket_plunge_start returns an error code.
   6. write_feed returns an error code.
   7. enter_pocket_pass returns an error code.
   8. mill_circular_pocket returns an error code.
   9. mill_semicircle_end_pocket returns an error code.
  10. mill_regular_pocket returns an error code.
  11. write_traverse returns an error code.

Side Effects: See below

Called By: mill_rectangular_pocket

This generates code to mill a rectangular pocket.

This is assuming a right-handed tool is being used.

It would be helpful if the inside_strategy included a reduced feed for
slotting, which occurs intermittently during rough milling (on
stepovers and during entry, for example). This is cutting the feed
rate in half for for slotting (which may not be necessary during
finish milling but should not be harmful).

All entry strategies result in the tool tip getting to (end2, 0).

*/

static int mill_rectangular_pocket_regular( /* ARGUMENTS                   */
 double length,                             /* length of pocket to make    */
 double width,                              /* width of pocket to make     */
 double depth,                              /* depth of pocket to make     */
 double radius,                             /* corner radius of p. to make */
 double retract,                            /* amount by which to retract  */
 double pass_depth,                         /* vertical pass depth         */
 double stepover,                           /* horizontal stepover         */
 approach_retract_strategy * enter,         /* approach strategy to use    */
 approach_retract_strategy * leave,         /* retract strategy to use     */
 two5D_milling_strategy * inside_strategy,  /* millings strategy to use    */
 double tool_diameter,                      /* diameter of endmill         */
 double code[][7],                          /* code array to write in      */
 int * lines)                               /* code array index            */
{
  static char name[] SET_TO "mill_rectangular_pocket_regular";
  contour_parallel * inside;
  int spiral;              /* 1=ccw,          -1=cw                 */
  int mode;                /* 1=conventional, -1=climb              */
  double end1;             /* X coordinate of +X end of centerline  */
  double end2;             /* X coordinate of -X end of centerline  */
  int passes;              /* number of vertical passes to make     */
  double start_x;          /* X coordinate of start point of plunge */
  double start_y;          /* Y coordinate of start point of plunge */
  double z_now;            /* current Z coordinate                  */
  plunge_strategy * entry; /* plunge entry strategy                 */
  int n;
  double aux;              /* offset_x or turns                     */

  CHK((NOT(inside_strategy->isa("contour_parallel"))),
      CAN_HANDLE_ONLY_CONTOUR_PARALLEL_MILLING_STRATEGY);
  CHK((NOT(enter->isa("plunge_strategy"))),
      CAN_HANDLE_ONLY_PLUNGE_APPROACH);
  CHK((NOT(leave->isa("plunge_toolaxis"))),
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT);
  entry SET_TO ROSE_CAST(plunge_strategy, enter);
  inside SET_TO ROSE_CAST(contour_parallel, inside_strategy);
  if (inside->rotation_direction() IS rot_direction_cw)
    {
      CHK((inside->cutmode() IS cutmode_type_climb),
	  CANNOT_HANDLE_OUTSIDE_IN_CUTTING);
      spiral SET_TO -1;
      mode SET_TO 1;
    }
  else if (inside->rotation_direction() IS rot_direction_ccw)
    {
      CHK((inside->cutmode() IS cutmode_type_conventional),
	  CANNOT_HANDLE_OUTSIDE_IN_CUTTING);
      spiral SET_TO 1;
      mode SET_TO -1;
    }
  else // if (inside->rotation_direction() IS rot_direction_NULL)
    {
      if (inside->cutmode() IS cutmode_type_climb)
	{
	  spiral SET_TO 1;
	  mode SET_TO -1;
	}
      else
	{
	  spiral SET_TO -1;
	  mode SET_TO 1;
	}
    }
  passes SET_TO (1 + (int)((depth - ISO14649_TINY) / pass_depth));
  pass_depth SET_TO (depth / passes);
  end1 SET_TO ((length - width) / 2.0);
  end2 SET_TO -end1;
  z_now SET_TO -pass_depth;
  IFF(find_pocket_plunge_start
      ((length - tool_diameter), (width - tool_diameter),
       (retract + pass_depth), entry, &start_x, &start_y, &aux));
  IFF(write_feed(start_x, start_y, retract, code, lines)); /* first point */
  IFF(enter_pocket_pass(entry, start_x, start_y, retract,
			end2, z_now, aux, code, lines));
  if ((width - (2 * radius)) < ISO14649_TINY)
    {
      if ((end1 - end2) < ISO14649_TINY)
	IFF(mill_circular_pocket(length, z_now, stepover, tool_diameter,
				 spiral, code, lines));
      else
	IFF(mill_semicircle_end_pocket(length, width, z_now, stepover,
				       tool_diameter, spiral, code, lines));
    }
  else
    IFF(mill_regular_pocket(length, width, radius, z_now, stepover,
			    tool_diameter, spiral, code, lines));
  if (passes > 1)
    IFF(find_pocket_plunge_start
	((length - tool_diameter), (width - tool_diameter), pass_depth, 
	 entry, &start_x, &start_y, &aux));
  for (n SET_TO 1; n < passes; n++)
    {
      IFF(write_feed(code[*lines - 1][1], code[*lines - 1][2],
		     (z_now + pass_depth), code, lines));
      IFF(write_traverse(start_x, start_y, (z_now + pass_depth),
			     code, lines));
      IFF(write_feed(start_x, start_y, z_now, code, lines));
      z_now SET_TO (z_now - pass_depth);
      IFF(enter_pocket_pass(entry, start_x, start_y, (z_now + pass_depth),
			    end2, z_now, aux, code, lines));
      if ((width - (2 * radius)) < ISO14649_TINY)
	{
	  if ((end1 - end2) < ISO14649_TINY)
	    IFF(mill_circular_pocket(length, z_now, stepover, tool_diameter,
				     spiral, code, lines));
	  else
	    IFF(mill_semicircle_end_pocket(length, width, z_now, stepover,
					  tool_diameter, spiral, code, lines));
	}
      else
	IFF(mill_regular_pocket(length, width, radius, z_now, stepover,
				tool_diameter, spiral, code, lines));
    }
  if (leave->isa("plunge_toolaxis"))
    IFF(write_feed(code[*lines - 1][1], code[*lines - 1][2],
		   retract, code, lines));
  else; /* currently cannot happen because of check above */

  return ISO14649_OK;
}

/***********************************************************************/

/* mill_regular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_arc returns an error code.

Side Effects:  the code array is written into, and the lines index is
   increased.

Called By: mill_rectangular_pocket_regular

The entry routine is expected to have left the tool tip at
X=(length - width)/-2.0, Y=0, Z=Z_now, which is at one end of
the (Voronoi) centerline of the pocket.

Center_offset is the offset along X or Y (they are the same) of the
center of the corner arc from the end of the centerline. This is
((width / 2.0) - corner_radius). Radius_now is set initially to minus
center_offset.  Offset_now is set initially to zero.

When spiral is 1, this cuts straight towards +X to the other end of
the centerline (X=end1) and then does the following repeatedly.
1. increase offset_now and radius_now by one stepover
2. cut straight towards +X to X = (end1 + offset_now); distance is one stepover
3. While corner arcs are not needed (radius_now is not positive):
  a. cut straight towards +Y to Y = offset_now
  b. cut straight towards -X to X = (end2 - offset_now)
  c. cut straight towards -Y to Y = -offset_now
  d. cut straight towards +X to X = (end1 + offset_now)
  e. cut straight towards +Y to Y = 0

3. When corner arcs are needed (radius_now is positive):
  a. cut straight towards +Y to Y = center_offset
  b. cut a quarter circle counterclockwise using (end1, 0) as center
  c. cut cut straight towards -X to X = (end2 - center_offset)
  d. cut a quarter circle counterclockwise using (end2, 0) as center
  e. cut straight towards -Y to Y = -center_offset
  f. cut a quarter circle counterclockwise using (end2, 0) as center
  g. cut straight towards +X to X = (end1 + center_offset)
  h. cut a quarter circle counterclockwise using (end1, 0) as center
  i. cut straight towards +Y to Y = 0

When spiral is -1, the direction of path rotation is switched to clockwise
by reversing the sign of all Y values and the direction of arcs.

It would be good to reduce the feedrate for the initial cut, since that
is slotting.

*/
static int mill_regular_pocket( /* ARGUMENTS                        */
 double length,                 /* length of pocket                 */
 double width,                  /* width of pocket                  */
 double radius,                 /* corner radius of pocket          */
 double z_now,                  /* Z coordinate at cutting depth    */
 double stepover,               /* horizontal stepover              */
 double tool_diameter,          /* diameter of tool                 */
 int spiral,                    /* 1=counterclockwise, -1=clockwise */
 double code[][7],              /* code array to write in           */
 int * lines)                   /* code array index                 */
{
  static char name[] SET_TO "mill_regular_pocket";
  double total;         /* total of all stepovers                */
  double radius_now;    /* radius of current arc                 */
  double offset_now;    /* current sum of stepovers              */
  double end1;          /* +X end of centerline                  */
  double end2;          /* -X end of centerline                  */
  double center_offset; /* X or Y offset of arc center from end1 */
  int passes;           /* number of stepovers                   */
  int n;                /* pass index                            */

  total SET_TO ((width - tool_diameter) / 2.0);
  passes SET_TO (1 + (int)((total - ISO14649_TINY) / stepover));
  stepover SET_TO (total / passes);
  end1 SET_TO ((length - width) / 2.0);
  end2 SET_TO -end1;
  center_offset SET_TO ((width / 2.0) - radius);
  radius_now SET_TO -center_offset;
  offset_now SET_TO 0;
  IFF(write_feed(end1, 0, z_now, code, lines));
  for (n SET_TO 0; n < passes; n++)
    {
      radius_now SET_TO (radius_now + stepover);
      offset_now SET_TO (offset_now + stepover);
      IFF(write_feed((end1 + offset_now), 0, z_now, code, lines));
      if (radius_now < ISO14649_TINY)
	{
	  IFF(write_feed((end1+offset_now), (offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end2-offset_now), (offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end2-offset_now), (-offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end1+offset_now), (-offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end1+offset_now), 0, z_now, code, lines));
	}
      else
	{
	  IFF(write_feed((end1 + offset_now), (center_offset * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end1 + center_offset), (offset_now * spiral),
			(end1 + center_offset), (center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end2 - center_offset), (offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end2 - offset_now), (center_offset * spiral),
			(end2 - center_offset), (center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end2 - offset_now), (-center_offset * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end2 - center_offset), (-offset_now * spiral),
			(end2 - center_offset), (-center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end1 + center_offset), (-offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end1 + offset_now), (-center_offset * spiral),
			(end1 + center_offset), (-center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end1 + offset_now), 0, z_now, code, lines));
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_semicircle_end_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_arc returns an error code.

Side Effects:  the code array is written into, and the lines index is
   increased.

Called By: mill_rectangular_pocket_regular

The entry routine is expected to have left the tool tip at
X=(length - width)/-2.0, Y=0, Z=Z_now, which is at one end of
the (Voronoi) centerline of the pocket.

When spiral is 1, this cuts straight towards +X to the other end of the
centerline (X=end1) and then does the following repeatedly:
1. cut straight towards +X to X = (end1 + radius_now); distance is one stepover
2. cut a quarter circle counterclockwise using (end1, 0) as center
3. cut straight towards -X to X = end2
4. cut a semicircle counterclockwise using (end2, 0) as center
5. cut straight towards -X to X = end1
6. cut a quarter circle counterclockwise using (end1, 0) as center

When spiral is -1, the direction of path rotation is switched to clockwise
by reversing the sign of all Y values and the direction of arcs.

It would be good to reduce the feedrate for the initial cut, since that
is slotting.

*/

static int mill_semicircle_end_pocket( /* ARGUMENTS                        */
 double length,                        /* length of pocket                 */
 double width,                         /* width of pocket                  */
 double z_now,                         /* Z coordinate at cutting depth    */
 double stepover,                      /* horizontal stepover              */
 double tool_diameter,                 /* diameter of tool                 */
 int spiral,                           /* 1=counterclockwise, -1=clockwise */
 double code[][7],                     /* code array to write in           */
 int * lines)                          /* code array index                 */
{
  static char name[] SET_TO "mill_semicircle_end_pocket";
  double total;      /* total of all stepovers */
  double radius_now; /* radius of current arc  */
  double end1;       /* +X end of centerline   */
  double end2;       /* -X end of centerline   */
  int passes;        /* number of stepovers    */
  int n;             /* pass index             */

  total SET_TO ((width - tool_diameter) / 2.0);
  passes SET_TO (1 + (int)((total - ISO14649_TINY) / stepover));
  stepover SET_TO (total / passes);
  end1 SET_TO ((length - width) / 2.0);
  end2 SET_TO -end1;
  radius_now SET_TO 0;
  IFF(write_feed(end1, 0, z_now, code, lines));
  for (n SET_TO 0; n < passes; n++)
    {
      radius_now SET_TO (radius_now + stepover);
      IFF(write_feed((end1 + radius_now), 0, z_now, code, lines));
      IFF(write_arc(end1, (radius_now * spiral), end1, 0, spiral,
		    z_now, code, lines));
      IFF(write_feed(end2, (radius_now * spiral), z_now, code, lines));
      IFF(write_arc(end2, (-radius_now * spiral), end2, 0, spiral,
		    z_now, code, lines));
      IFF(write_feed(end1, (-radius_now * spiral), z_now, code, lines));
      IFF(write_arc((end1 + radius_now), 0, end1, 0, spiral,
		    z_now, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* op_center_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_center_drilling returns an error code.
   2. check_tool_center_drill returns an error code.
   3. check_horizontal_plane returns an error code.
   4. find_retract_z returns an error code.
   5. The center drilling depth is more than the flute length of the center
      drill: CENTER_DRILLING_DEPTH_MUST_NOT_EXCEED_CENTER_DRILL_FLUTE_LENGTH.
   6. start_cut returns an error code.

Side Effects: See below

Called By: cut_feature

This center_drills the given feature. Any type of feature may be
center_drilled.

The sequence of actions (and calculations) is:

1. Rapid vertical up to current security_z if not retracted.
2. Rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be center_drilled.
3. Rapid vertical down to retract_z.
4. Cut vertically down to (top_of_feature - cutting_depth).
5. If there is a dwell time, dwell for that amount of time.
6. Reset feed if the retract feed differs from the current feed.
7. Retract vertically up to the retract_z.
8. Update current location and feed.

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
cutting_depth:          OPTIONAL length_measure; (drilling_type_operation)
previous_diameter:      OPTIONAL length_measure;
dwell_time_bottom:      OPTIONAL time_measure;
feed_on_retract:        OPTIONAL positive_ratio_measure;
its_machining_strategy: OPTIONAL drilling_type_strategy;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPLEMENTED
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retract_plane is the Z-coordinate of the retract plane in the feature
   coordinate system.
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
technology is handled before this function is called.
its_machine_functions is handled before this function is called.
overcut_length is required here (not in the spec) to be ROSE_NULL_REAL.
cutting_depth here (not in the spec) must be given, must be positive,
   and must be less than the feature depth.
previous_diameter is ignored; it is for information only.
dwell_time_bottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feed_on_retract is used
its_machining_strategy is required here (not in the spec) to be NULL.

If the optional retract_plane is given, retract_z is set to that
amount above the top of the hole.  If not, retract_z is set to ISO14649_UP
millimeters above the top of the hole.

*/

static int op_center_drilling(           /* ARGUMENTS                      */
 machining_feature * the_feature,        /* feature to center drill        */
 center_drilling * the_center_drilling)  /* center drilling op to perform  */
{
  static char name[] SET_TO "op_center_drilling";
  elementary_surface * depth_plane;    /* plane that is depth of hole    */
  double feat_x;    /* in setup c_sys */
  double feat_y;    /* in setup c_sys */
  double feat_z;    /* in setup c_sys */
  double retract_z; /* in setup c_sys */
  double feedrate;
  double flute_length;

  depth_plane SET_TO the_feature->depth();
  IFF(check_horizontal_plane(depth_plane));
  feat_x SET_TO _world.feature_place.location()->coordinates()->get(0);
  feat_y SET_TO _world.feature_place.location()->coordinates()->get(1);
  feat_z SET_TO _world.feature_place.location()->coordinates()->get(2);
  IFF(check_op_center_drilling(the_center_drilling, depth_plane));
  IFF(check_tool_center_drill(the_center_drilling->its_tool(), &flute_length));
  CHK((the_center_drilling->cutting_depth() > flute_length),
      CENTER_DRILLING_DEPTH_MUST_NOT_EXCEED_CENTER_DRILL_FLUTE_LENGTH);
  IFF(find_retract_z(feat_z, the_center_drilling->retract_plane(),
		     ISO14649_UP, &retract_z));
  IFF(start_cut(feat_x, feat_y, retract_z));
  STRAIGHT_FEED_3(feat_x, feat_y,
		(feat_z - the_center_drilling->cutting_depth()));
  if ((the_center_drilling->feed_on_retract() ISNT ROSE_NULL_REAL) AND
      (the_center_drilling->feed_on_retract() ISNT 1.0))
    {
      feedrate SET_TO
	(the_center_drilling->feed_on_retract() * _world.feedrate);
      SET_FEED_RATE(feedrate);
      _world.feedrate SET_TO feedrate;      
    }
  if (the_center_drilling->dwell_time_bottom() ISNT ROSE_NULL_REAL)
    DWELL(the_center_drilling->dwell_time_bottom());
  STRAIGHT_FEED_3(feat_x, feat_y, retract_z);
  _world.current_x SET_TO feat_x;
  _world.current_y SET_TO feat_y;
  _world.current_z SET_TO retract_z;

  return ISO14649_OK;
}

/***********************************************************************/

/* op_counter_boring

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_cbore_hole is NULL: FEATURE_MUST_NOT_BE_NULL.
   2. the_boring is NULL: OPERATION_MUST_NOT_BE_NULL.
   3. the_boring is not one of the operations belonging to the_cbore_hole:
      OPERATION_MUST_BELONG_TO_FEATURE.
   4. init_place returns an error code.
   5. check_counterbore_hole returns an error code.
   6. check_op_counter_boring returns an error code.
   7. check_tool_counterbore returns an error code.
   8. find_location returns an error code.
   9. find_retract_z returns an error code.
  10. start_cut returns an error code.

Side Effects: See below

Called By: execute_machining

This is an operation on a compound_feature. The counterbore_hole should
have this operation in its list of operations. The upper hole of the
counterbore_hole should also have this operation in its list of
operations.

If the boring operation is applied to a counterbore hole, it is
considered to be a counter_boring operation (a plunge with an endmill
to enlarge an existing hole, but not the the full depth of the
existing hole).  The counter_boring operation forms the geometry of the
upper hole. The diameters of the hole and tool must match, and if the
cutting depth is given, it must be the correct value for making the
upper hole to its full depth.

There are more coordinate systems to deal with in a counterbore_hole
than with other feature types, since the holes are placed in terms of
the coordinate system of the feature. The two component holes must
be co-axial and their Z-axes must be (0, 0, 1). This helps. The origins
of the holes are not required to be anwhere in particular, except that
the coaxial and mating requirements must be satisfied. The find_location
function is used to deal with the coordinate systems.

This is not checking that the lower hole of a counterbore hole is made
before the upper hole, but that is a requirement. The plunge movement
of counterboring may be a disaster (broken tool, melted material, etc.)
if the lower hole does not already exist.

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
cutting_depth:          OPTIONAL length_measure; (drilling_type_operation)
previous_diameter:      OPTIONAL length_measure;
dwell_time_bottom:      OPTIONAL time_measure;
feed_on_retract:        OPTIONAL positive_ratio_measure;
its_machining_strategy: OPTIONAL drilling_type_strategy;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPLEMENTED.
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retract_plane is the Z-coordinate of the retract plane in the
   coordinate system of the upper hole (not of the counterbore_hole).
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
technology is handled before this function is called.
its_machine_functions is handled before this function is called.
overcut_length is required (in check_op_counter_boring, not in the spec)
   to be ROSE_NULL_REAL.
cutting_depth, if given, must be the depth required to make the upper
   hole of the counterbore hole. It is assumed that for counterboring
   (like center drilling - see description of cutting depth for
    drilling_type_operation, sec. 4.2.12, p 25) cutting depth is
   measured from the lowest point of the cutting tip to the highest
   part of the hole.
previous_diameter must be the diameter of the lower hole. It is not
   used for anything, but the hope is that having to provide a value
   will remind the program author to make the lower hole first.
dwell_time_bottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feed_on_retract is used
its_machining_strategy is required (in check_op_counter_boring) to be NULL.
   The strategy data could be used, however, so it might be used in
   future versions. It would be unusual but not unthinkable to use strategy
   data for counterboring.

If the optional retract_plane is given, retract_z is set to that
amount above the origin of the coordinate system of upper_hole.  If not,
retract_z is set to ISO14649_UP millimeters above the top of upper_hole.

The sequence of actions is:

1. Rapid vertical up to current security_z if not retracted.
2. Rapid horizontal to above the center of the hole.
3. Rapid vertical down to retract_z.
4. Cut vertically down to (top_of_hole - cutting_depth).
5. If there is a dwell time, dwell for that amount of time.
6. Reset feed if the retract feed differs from the current feed.
7. Retract vertically up to the retract_z.
8. Update current location and feed.


*/

static int op_counter_boring(        /* ARGUMENTS                   */
 counterbore_hole * the_cbore_hole,  /* counterbore_hole to bore    */
 boring * the_boring)                /* counterboring op to perform */
{
  static char name[] SET_TO "op_counter_boring";
  round_hole * upper_hole;  /* hole to cbore, found in check_cbore_hole */
  double cut_depth;
  double retract_z;     /* in setup c_sys             */
  double cbore_x;       /* in setup c_sys             */
  double cbore_y;       /* in setup c_sys             */
  double cbore_z;       /* in setup c_sys             */
  axis2_placement_3d cbore_place;
  Set (machining_operation) * feature_ops;
  int stop;
  int n;
  double feedrate;
  double lower_diameter;
  
  CHK((the_cbore_hole IS NULL), FEATURE_MUST_NOT_BE_NULL);
  CHK((the_boring IS NULL), OPERATION_MUST_NOT_BE_NULL);
  feature_ops SET_TO the_cbore_hole->its_operations();
  stop SET_TO feature_ops->size();
  for (n SET_TO 0; n < stop; n++)
    {
      if (the_boring IS (*feature_ops)[n])
	break;
    }
  CHK((n IS stop), OPERATION_MUST_BELONG_TO_FEATURE);
  IFF(init_place(&cbore_place));
  cut_depth SET_TO the_boring->cutting_depth();
  IFF(check_counterbore_hole(the_cbore_hole, &upper_hole, &lower_diameter));
  IFF(check_op_counter_boring(upper_hole, the_boring, lower_diameter));
  IFF(check_tool_counterbore(the_boring->its_tool(), upper_hole, &cut_depth));
  IFF(find_location(&(_world.feature_place),
		    upper_hole->feature_placement(), &cbore_place))
  cbore_x SET_TO cbore_place.location()->coordinates()->get(0);
  cbore_y SET_TO cbore_place.location()->coordinates()->get(1);
  cbore_z SET_TO cbore_place.location()->coordinates()->get(2);
  IFF(find_retract_z(cbore_z, the_boring->retract_plane(),
		     ISO14649_UP, &retract_z));
  IFF(start_cut(cbore_x, cbore_y, retract_z));
  STRAIGHT_FEED_3(cbore_x, cbore_y, (cbore_z - cut_depth));
  if ((the_boring->feed_on_retract() ISNT ROSE_NULL_REAL) AND
      (the_boring->feed_on_retract() ISNT 1.0))
    {
      feedrate SET_TO (the_boring->feed_on_retract() * _world.feedrate);
      SET_FEED_RATE(feedrate);
      _world.feedrate SET_TO feedrate;      
    }
  if (the_boring->dwell_time_bottom() ISNT ROSE_NULL_REAL)
    DWELL(the_boring->dwell_time_bottom());
  STRAIGHT_FEED_3(cbore_x, cbore_y, retract_z);
  _world.current_x SET_TO cbore_x;
  _world.current_y SET_TO cbore_y;
  _world.current_z SET_TO retract_z;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_counter_sinking

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_csunk_hole is NULL: FEATURE_MUST_NOT_BE_NULL.
   2. the_sinking is NULL: OPERATION_MUST_NOT_BE_NULL.
   3. the_sinking is not one of the operations belonging to the_csunk_hole:
      OPERATION_MUST_BELONG_TO_FEATURE.
   4. init_place returns an error code.
   5. check_countersunk_hole returns an error code.
   6. check_op_counter_sinking returns an error code.
   7. check_tool_countersink returns an error code.
   8. find_location returns an error code.
   9. find_retract_z returns an error code.
  10. start_cut returns an error code.

Side Effects: See below

Called By: execute_machining

This is an operation on a compound_feature. The countersunk_hole should
have this operation in its list of operations. The upper hole of the
countersunk_hole should also have this operation in its list of
operations.

Unlike the other subtypes of drilling, this is allowing only countersunk
holes to have the counter_sinking operation applied to them, and only in
such a way as to form the geometry of the upper hole. In particular, the
taper angles of the hole and tool must match, and if the cutting depth
is given, it must be the correct value for making the upper diameter.

There are more coordinate systems to deal with in a countersunk_hole
than with other feature types, since the holes are placed in terms of
the coordinate system of the feature. The two component holes must
be co-axial and their Z-axes must be (0, 0, 1). This helps. The origins
of the holes are not required to be anwhere in particular, except that
the coaxial and mating requirements must be satisfied. The find_location
function is used to deal with the coordinate systems.

This is not requiring the lower hole of a countersunk hole be made before
the upper hole.

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
cutting_depth:          OPTIONAL length_measure; (drilling_type_operation)
previous_diameter:      OPTIONAL length_measure;
dwell_time_bottom:      OPTIONAL time_measure;
feed_on_retract:        OPTIONAL positive_ratio_measure;
its_machining_strategy: OPTIONAL drilling_type_strategy;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPLEMENTED.
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retract_plane is the Z-coordinate of the retract plane in the
   coordinate system of the upper hole (not of the countersunk_hole).
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
technology is handled before this function is called.
its_machine_functions is handled before this function is called.
overcut_length is required (in check_op_counter_sinking, not in the spec)
   to be ROSE_NULL_REAL.
cutting_depth, if given, must be the depth required to make the upper
   hole of the countersunk hole. It is assumed that for countersinking
   (like center drilling - see description of cutting depth for
    drilling_type_operation, sec. 4.2.12, p 25) cutting depth is
   measured from the lowest point of the cutting tip to the highest
   part of the hole.
previous_diameter is ignored; it is for information only.
dwell_time_bottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feed_on_retract is used
its_machining_strategy is required (in check_op_counter_sinking) to be NULL.
   The strategy data could be used, however, so it might be used in
   future versions. It would be unusual but not unthinkable to use strategy
   data for countersinking.

If the optional retract_plane is given, retract_z is set to that
amount above the origin of the coordinate system of upper_hole.  If not,
retract_z is set to ISO14649_UP millimeters above the top of upper_hole.

The sequence of actions is:

1. Rapid vertical up to current security_z if not retracted.
2. Rapid horizontal to above the center of the hole.
3. Rapid vertical down to retract_z.
4. Cut vertically down to (top_of_hole - cutting_depth).
5. If there is a dwell time, dwell for that amount of time.
6. Reset feed if the retract feed differs from the current feed.
7. Retract vertically up to the retract_z.
8. Update current location and feed.


*/

static int op_counter_sinking(       /* ARGUMENTS                       */
 countersunk_hole * the_csunk_hole,  /* countersunk_hole to countersink */
 counter_sinking * the_sinking)      /* countersinking op to perform    */
{
  static char name[] SET_TO "op_counter_sinking";
  round_hole * upper_hole;  /* hole to csink, found in check_csunk_hole */
  double cut_depth;
  double retract_z;     /* in setup c_sys             */
  double csink_x;       /* in setup c_sys             */
  double csink_y;       /* in setup c_sys             */
  double csink_z;       /* in setup c_sys             */
  axis2_placement_3d csink_place;
  Set (machining_operation) * feature_ops;
  int stop;
  int n;
  double feedrate;
  double upper_hole_angle; /* angle from bottom to side */
  
  CHK((the_csunk_hole IS NULL), FEATURE_MUST_NOT_BE_NULL);
  CHK((the_sinking IS NULL), OPERATION_MUST_NOT_BE_NULL);
  feature_ops SET_TO the_csunk_hole->its_operations();
  stop SET_TO feature_ops->size();
  for (n SET_TO 0; n < stop; n++)
    {
      if (the_sinking IS (*feature_ops)[n])
	break;
    }
  CHK((n IS stop), OPERATION_MUST_BELONG_TO_FEATURE);
  IFF(init_place(&csink_place));
  cut_depth SET_TO the_sinking->cutting_depth();
  IFF(check_countersunk_hole(the_csunk_hole, &upper_hole_angle, &upper_hole));
  IFF(check_op_counter_sinking(upper_hole, the_sinking));
  IFF(check_tool_countersink(the_sinking->its_tool(), upper_hole, &cut_depth,
			     upper_hole_angle));
  IFF(find_location(&(_world.feature_place),
		    upper_hole->feature_placement(), &csink_place))
  csink_x SET_TO csink_place.location()->coordinates()->get(0);
  csink_y SET_TO csink_place.location()->coordinates()->get(1);
  csink_z SET_TO csink_place.location()->coordinates()->get(2);
  IFF(find_retract_z(csink_z, the_sinking->retract_plane(),
		     ISO14649_UP, &retract_z));
  IFF(start_cut(csink_x, csink_y, retract_z));
  STRAIGHT_FEED_3(csink_x, csink_y, (csink_z - cut_depth));
  if ((the_sinking->feed_on_retract() ISNT ROSE_NULL_REAL) AND
      (the_sinking->feed_on_retract() ISNT 1.0))
    {
      feedrate SET_TO (the_sinking->feed_on_retract() * _world.feedrate);
      SET_FEED_RATE(feedrate);
      _world.feedrate SET_TO feedrate;      
    }
  if (the_sinking->dwell_time_bottom() ISNT ROSE_NULL_REAL)
    DWELL(the_sinking->dwell_time_bottom());
  STRAIGHT_FEED_3(csink_x, csink_y, retract_z);
  _world.current_x SET_TO csink_x;
  _world.current_y SET_TO csink_y;
  _world.current_z SET_TO retract_z;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_drill_tip_length returns an error code.
   2. find_cutting_depths returns an error code.
   3. check_tool_drill return an error code.
   4. check_op_drilling return an error code.
   5. find_retract_z returns an error code.
   6. start_cut returns an error code.

Side Effects: See below

Called By: cut_feature

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

See documentation of find_cutting_depths for how depth, depth1, and
depth2 are set. If depth1 or depth2 is set to ROSE_NULL_REAL, that is
regarded as not being set at all. After these depths are found, the
sequence of actions (and calculations) is:

1. rapid vertical up to current security_z if not retracted.
2. rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be drilled.
3. rapid vertical down to retract_z.
4A. If depth1 is set
    a. Set feed and/or speed and cut vertically down to depth1.
    b. If depth2 is set and equals depth1 set feed and/or speed and cut
       vertically down to depth.
    c. If depth2 is set and does not equal depth1, set feed and/or
       speed and cut vertically down to depth2. Then reset feed and/or
       speed and cut vertically down to depth.
    d. if depth2 is not set, reset feed and/or speed and cut vertically
       down to depth.
4B. Otherwise if depth2 is set
    a. Cut vertically down to depth2.
    b. Set feed and/or speed and cut vertically down to depth.
4C. Otherwise cut vertically down to depth.
5. If there is a dwell time, dwell for that amount of time.
6. Reset feed if the retract feed differs from the current feed
   (which might happen if there is a feed_on_retract and/or a
    reduced_feed_at_end).
7. Retract vertically up to retract_z.
8. Update current location, feed, and speed.

Note that feed and speed canonical commands may have just been issued
(by handle_technology) that will be negated immediately by other feed
and speed canonical commands issued here. It may be worth the trouble
to avoid this, but we are living with it for now.

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
cutting_depth:          OPTIONAL length_measure; (drilling_type_operation)
previous_diameter:      OPTIONAL length_measure;
dwell_time_bottom:      OPTIONAL time_measure;
feed_on_retract:        OPTIONAL positive_ratio_measure;
its_machining_strategy: OPTIONAL drilling_type_strategy;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPLEMENTED.
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
its_id is ignored.
retract_plane is the Z-coordinate of the retract plane in the feature
   coordinate system.
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
its_technology is handled before this function is called.
its_machine_functions is handled before this function is called.
overcut_length is for through features (Part 11, sec 4.2.3). We are requiring
   here that if given: (1) it must be positive and (2) cutting_depth may
   not be used.
cutting_depth, if given, may specify drilling less or more than the hole.
   We are requiring here that it must be positive if given.
previous_diameter is ignored; it is for information only.
dwell_time_bottom, if given, is used as the time in seconds for which the
   tool dwells at the bottom of the hole.
feed_on_retract, if given, is used as a multiplier for the feed rate
   during the retract motion.

The drilling strategy has:
reduced_cut_at_start:       OPTIONAL positive_ratio_measure; 
reduced_feed_at_start:      OPTIONAL positive_ratio_measure; 
depth_of_start:             OPTIONAL length_measure;
reduced_cut_at_end:         OPTIONAL positive_ratio_measure; 
reduced_feed_at_end:        OPTIONAL positive_ratio_measure; 
depth_of_end:               OPTIONAL length_measure;
WHERE
WR1: EXISTS(depth_of_start) OR
     NOT (EXISTS(reduced_cut_at_start) OR EXISTS(reduced_feed_at_start));
WR2: EXISTS(depth_of_end) OR
     NOT (EXISTS(reduced_cut_at_end) OR EXISTS(reduced_feed_at_end));

The find_cutting depths function checks the attributes of the drilling
strategy, so they are not rechecked here.

During the operation, _world.feedrate is kept fixed, since it is
needed as the basis for calculating current feedrate. When all motion
is finished, _world.feedrate is set to the feedrate in use at the end
of the operation. Similarly for spindle speed.

If the optional retract_plane is given, retract_z is set to that
amount above the top of the hole.  If not, retract_z is set to one
drill tip length above the top of the hole.

*/

static int op_drilling(            /* ARGUMENTS                         */
 machining_feature * the_feature,  /* feature to make                   */
 drilling * the_drilling)          /* drilling op to perform on feature */
{
  static char name[] SET_TO "op_drilling";
  double tip_length;
  double feat_x;       /* in setup c_sys                                  */
  double feat_y;       /* in setup c_sys                                  */
  double feat_z;       /* in setup c_sys                                  */
  double retract_z;    /* retract z in setup c_sys                        */
  double feedrate;     /* current feed rate                               */
  double speed;        /* current spindle speed                           */
  double depth;        /* tip z coordinate at bottom in setup  c_sys      */
  double depth1;       /* tip z coordinate at end of start in setup c_sys */
  double depth2;       /* tip z coordinate at start of end in setup c_sys */
  double flute_length; /* drill flute length to drill tip                 */
  drilling_type_strategy * strat; /* drilling strategy to use, NULL OK    */

  feat_x SET_TO _world.feature_place.location()->coordinates()->get(0);
  feat_y SET_TO _world.feature_place.location()->coordinates()->get(1);
  feat_z SET_TO _world.feature_place.location()->coordinates()->get(2);
  strat SET_TO the_drilling->its_machining_strategy();
  feedrate SET_TO _world.feedrate;
  speed SET_TO _world.speed;
  IFF(check_op_drilling(the_drilling));
  IFF(check_tool_drill(the_drilling->its_tool(), &flute_length));
  IFF(find_drill_tip_length(the_drilling->its_tool(), &tip_length));
  IFF(find_cutting_depths(&depth, &depth1, &depth2, flute_length, tip_length,
			  the_feature->depth(), the_drilling->overcut_length(),
			  the_drilling->cutting_depth(), strat));
  IFF(find_retract_z(feat_z, the_drilling->retract_plane(),
		     tip_length, &retract_z));
  IFF(start_cut(feat_x, feat_y, retract_z));
  if (depth1 ISNT ROSE_NULL_REAL) 
    {
      if (strat->reduced_cut_at_start() ISNT ROSE_NULL_REAL)
	{
	  speed SET_TO (_world.speed * strat->reduced_cut_at_start());
	  SET_SPINDLE_SPEED(speed);
	}
      if (strat->reduced_feed_at_start() ISNT ROSE_NULL_REAL)
	{
	  feedrate SET_TO (_world.feedrate * strat->reduced_feed_at_start());
	  SET_FEED_RATE(feedrate);
	}
      STRAIGHT_FEED_3(feat_x, feat_y, depth1);
      if (feedrate ISNT _world.feedrate)
	{
	  feedrate SET_TO _world.feedrate;
	  SET_FEED_RATE(feedrate);
	}
      if (speed ISNT _world.speed)
	{
	  speed SET_TO _world.speed;
	  SET_SPINDLE_SPEED(speed);
	}
    }
  if (depth2 ISNT ROSE_NULL_REAL)
    {
      STRAIGHT_FEED_3(feat_x, feat_y, depth2);
      if (strat->reduced_cut_at_end() ISNT ROSE_NULL_REAL)
	{
	  speed SET_TO (_world.speed * strat->reduced_cut_at_end());
	  SET_SPINDLE_SPEED(speed);
	}
      if (strat->reduced_feed_at_end() ISNT ROSE_NULL_REAL)
	{
	  feedrate SET_TO (_world.feedrate * strat->reduced_feed_at_end());
	  SET_FEED_RATE(feedrate);
	}
    }
  STRAIGHT_FEED_3(feat_x, feat_y, depth);
  if (the_drilling->feed_on_retract() IS ROSE_NULL_REAL)
    {
      if (feedrate ISNT _world.feedrate)
	{
	  feedrate SET_TO _world.feedrate;
	  SET_FEED_RATE(feedrate);
	}
    }
  else if (feedrate ISNT (the_drilling->feed_on_retract() * _world.feedrate))
    {
      feedrate SET_TO (the_drilling->feed_on_retract() * _world.feedrate);
      SET_FEED_RATE(feedrate);
    }
  if (the_drilling->dwell_time_bottom() ISNT ROSE_NULL_REAL)
    DWELL(the_drilling->dwell_time_bottom());
  STRAIGHT_FEED_3(feat_x, feat_y, retract_z);
  _world.current_x SET_TO feat_x;
  _world.current_y SET_TO feat_y;
  _world.current_z SET_TO retract_z;
  _world.feedrate SET_TO feedrate;
  _world.speed SET_TO speed;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_finish_milling_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_finish_both returns an error code.
   2. check_tool_endmill returns an error code.
   3. finish_mill_both_closed_pocket returns an error code.
   4. the_feature is not a closed_pocket:
      CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_FINISH_MILL_BOTTOM_AND_SIDE.

Side Effects: Code is generated to finish mill the sides and bottom of
   the feature, which must be a closed pocket.

Called By: cut_feature

*/

static int op_finish_milling_both(            /* ARGUMENTS                */
 machining_feature * the_feature,             /* feature to finish mill   */
 bottom_and_side_finish_milling * the_finish) /* finish milling operation */
{
  static char name[] SET_TO "op_finish_milling_both";
  endmill * the_endmill;

  IFF(check_op_finish_both(the_finish));
  IFF(check_tool_endmill(the_finish->its_tool(), &the_endmill));
  if (the_feature->isa("closed_pocket"))
    IFF(finish_mill_both_closed_pocket(ROSE_CAST(closed_pocket, the_feature),
				      the_finish, the_endmill));
  else
    CHK(1, CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_FINISH_MILL_BOTTOM_AND_SIDE);
  return ISO14649_OK;
}

/***********************************************************************/

/* op_finish_milling_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_finish_plane returns an error code.
   2. check_tool_plane returns an error code.
   3. The_feature is not a planar_face:
      FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE
   4. The tool is neither an endmill nor a facemill:
      TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL.
   5. mill_planar returns an error code.

Side Effects: Code is generated to cut the plane face.

Called By: cut_feature

Notes:

Plane_milling may be done using either a facemill or an endmill. Using a
facemill is feasible when entry from the side is possible. Plane_milling
could also be done with a fly_cutter, but fly_cutter is not among the
tools provided by Part 111.

Error 4 above should never happen, since check_tool_plane checks the
same thing.

*/

static int op_finish_milling_plane( /* ARGUMENTS                */
 machining_feature * the_feature,   /* feature to finish mill   */
 plane_finish_milling * the_finish) /* finish milling operation */
{
  static char name[] SET_TO "op_finish_milling_plane";
  endmill * the_endmill;
  facemill * the_facemill;

  the_endmill SET_TO NULL;
  the_facemill SET_TO NULL;
  IFF(check_op_finish_plane(the_finish));
  IFF(check_tool_plane(the_finish->its_tool(), &the_endmill, &the_facemill));
  if (the_feature->isa("planar_face"))
    {
      if (the_endmill)
	IFF(mill_planar(ROSE_CAST(planar_face, the_feature),
			       the_finish, the_endmill));
      else if (the_facemill)
	IFF(mill_planar(ROSE_CAST(planar_face, the_feature),
			       the_finish, the_facemill));
      else
	CHK(1, TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL);
    }
  else
    CHK(1, FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE);
  return ISO14649_OK;
}

/***********************************************************************/

/* op_finish_milling_side

Returned Value: int (ISO14649_OK)

Side Effects: None

Called By: cut_feature

This is a stub.

*/

static int op_finish_milling_side( /* ARGUMENTS                      */
 machining_feature * the_feature,  /* feature to finish mill         */
 side_finish_milling * the_finish) /* finish milling operation to do */
{
  static char name[] SET_TO "op_finish_milling_side";

  printf("side_finish_milling\n");
  return ISO14649_OK;
}


/***********************************************************************/

/* op_multistep_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_multistep_drilling returns an error code.
   2. check_tool_drill returns an error code.
   3. find_cutting_depths returns an error code.
   4. find_drill_tip_length returns an error code.
   5. find_retract_z returns an error code.
   6. start_cut returns an error code.

Side Effects: See below

Called By: cut_feature

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

See documentation of find_cutting_depths for how depth and depth1 are
set.  After these depths are found, checks are made as described above.

1. If (optional double) retract_plane is not ROSE_NULL_REAL, retract_z
   is set to be that distance above the top of the feature; otherwise,
   retract_z is set to be one tool tip length above the top of the
   feature.
2. dwell_time is set initially to dwell_time_step and later to 
   dwell_time_bottom.
3. retract_by is set initially to retract_distance from the_drilling
   and later to -1 (to cause a retract to the retract plane).
4. peck is set to depth_of_step from the_drilling.
5. If retract_feed is set to feed_on_retract from the_drilling if
   that is not ROSE_NULL_REAL, and to 1 if it is.


The sequence of actions (including settings and calculations) is:

1. rapid vertical up to current security_z if not retracted.
2. rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be drilled.
3. rapid vertical down to retract_plane.
4. Start a "for" loop which does the following.
   A. If depth1 is below or at depth, set depth1 to depth, set dwell_time
      to dwell_time_bottom, and set retract_by to -1.
   B. Cut vertically down to depth1.
   C. If dwell_time isnt ROSE_NULL_REAL, dwell for that amount of time.
   D. If retract_feed is not equal to 1, reset feed.
   E. If retract_by is positive, retract vertically up by that
      amount; otherwise, retract vertically up to the retract plane.
   F. If retract_feed is not equal to 1, reset feed.
   G. If depth1 is depth, get out of the loop, otherwise, make depth1
      deeper by peck.
5. Update current location.

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
cutting_depth:          OPTIONAL length_measure; (drilling_type_operation)
previous_diameter:      OPTIONAL length_measure;
dwell_time_bottom:      OPTIONAL time_measure;
feed_on_retract:        OPTIONAL positive_ratio_measure;
its_machining_strategy: OPTIONAL drilling_type_strategy;
retract_distance:       length_measure; (multistep_drilling)
first_depth:            length_measure;
depth_of_step:          length_measure;
dwell_time_step:        OPTIONAL time_measure;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPELEMENTED.
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retract_plane is the Z-coordinate of the retract plane in the coordinate
   system of the feature, which is the same as the distance between the
   top of the feature and the point to which to retract.
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
technology is handled before this function is called. This results
   in _world.feed_rate being set.
its_machine_functions is handled before this function is called.
overcut_length is for through holes (Part 11, sec 4.2.3). We are requiring
   here that if given: (1) it must be positive and (2) cutting_depth may
   not be used.
cutting_depth, if given, may specify drilling less or more than the hole.
   We are requiring here that it must be positive if given.
previous_diameter is ignored; it is for information only.
dwell_time_bottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feed_on_retract is used.
its_machining_strategy is required here (not in the spec) to be NULL for
   multistep drilling. It could be used, but to use it simultaneously
   with the multistep_drilling attributes (the last four from the list
   above) would be a major pain. A dummy machining strategy is
   constructed here so that find_cutting_depths will calculate
   depth1.
retract_distance is used.
first_depth is used.
depth_of_step is used.
dwell_time_step is used.

There are two reasonable ways to use depth_of_step. The first is to
add depth_of_step to the depth at each step until the result to too
big and then make the last step whatever is needed to get to the
bottom. The second is to calculate how many steps would be needed if
the first procedure were followed and then divide the total depth
to be cut in steps by that number to get an actual step depth (which
is usually a little smaller than depth_of_step, and the last step is
no smaller than the other steps). We are using the first procedure
here.

*/

static int op_multistep_drilling(    /* ARGUMENTS                         */
 machining_feature * the_feature,    /* feature to make                   */
 multistep_drilling * the_drilling)  /* drilling op to perform on feature */
{
  static char name[] SET_TO "op_multistep_drilling";
  double tip_length;
  double flute_length;
  double feat_x;
  double feat_y;
  double feat_z;
  double retract_z;    /* retract z in setup c_cys                     */
  double depth;        /* tip z coordinate at bottom in setup c_sys    */
  double depth1;       /* resettable depth                              */
  double depth2;       /* dummy needed by find_cutting_depths          */
  double peck;         /* depth_of_step from the_drilling               */
  double retract_by;   /* retract distance from the_drilling or -1      */
  double retract_feed; /* feed_on_retract from the_drilling or 1        */
  double dwell_time;   /* dwell time of step or bottom                  */
  drilling_type_strategy strategy;  /* needed by find_cutting_depths   */

  feat_x SET_TO _world.feature_place.location()->coordinates()->get(0);
  feat_y SET_TO _world.feature_place.location()->coordinates()->get(1);
  feat_z SET_TO _world.feature_place.location()->coordinates()->get(2);
  IFF(check_op_multistep_drilling(the_drilling));
  IFF(check_tool_drill(the_drilling->its_tool(), &flute_length));
  IFF(find_drill_tip_length(the_drilling->its_tool(), &tip_length));
  dwell_time SET_TO the_drilling->dwell_time_step();
  peck SET_TO the_drilling->depth_of_step();
  retract_feed SET_TO the_drilling->feed_on_retract();
  if (retract_feed IS ROSE_NULL_REAL)
    retract_feed SET_TO 1.0;
  retract_by SET_TO the_drilling->retract_distance();
  strategy.depth_of_start(the_drilling->first_depth());
  strategy.depth_of_end(ROSE_NULL_REAL);
  IFF(find_cutting_depths(&depth, &depth1, &depth2, flute_length, tip_length,
			   the_feature->depth(),
			   the_drilling->overcut_length(),
			   the_drilling->cutting_depth(), &strategy));
  IFF(find_retract_z(feat_z, the_drilling->retract_plane(),
		     tip_length, &retract_z));
  IFF(start_cut(feat_x, feat_y, retract_z));
  for (; ; depth1 SET_TO (depth1 - peck))
    {
      if (depth1 <= (depth + ISO14649_TINY))
	{
	  depth1 SET_TO depth;
	  dwell_time SET_TO the_drilling->dwell_time_bottom();
	  retract_by SET_TO -1.0;
	}
      STRAIGHT_FEED_3(feat_x, feat_y, depth1);
      if (dwell_time ISNT ROSE_NULL_REAL)
	DWELL(dwell_time);
      if (retract_feed ISNT 1.0)
	SET_FEED_RATE(retract_feed * _world.feedrate);
      STRAIGHT_FEED_3(feat_x, feat_y,
		    ((retract_by > 0) ? (depth1 + retract_by) : retract_z));
      if (retract_feed ISNT 1.0)
	SET_FEED_RATE(_world.feedrate);
      if (depth1 IS depth)
	break;
    }
  _world.current_x SET_TO feat_x;
  _world.current_y SET_TO feat_y;
  _world.current_z SET_TO retract_z;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_reaming

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. spindle_stop_at_bottom is neither true nor false:
      SPINDLE_STOP_AT_BOTTOM_MUST_BE_TRUE_OR_FALSE.
   2. check_op_reaming returns an error code.
   3. check_tool_reamer returns an error code.
   4. find_cutting_depths returns an error code.
   5. find_retract_z returns an error code.
   6. start_cut returns an error code.

Side Effects: Code is generated to ream

Called By: cut_feature

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

See documentation of find_cutting_depths for how depth, depth1, and
depth2 are set. If depth1 or depth2 is set to ROSE_NULL_REAL, that is
regarded as not being set at all. After these depths are found, the
sequence of actions (and calculations) is:

1. rapid vertical up to current security_z if not retracted.
2. rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be drilled.
3. rapid vertical down to retract_z.
4A. If depth1 is set
    a. Set feed and/or speed and cut vertically down to depth1.
    b. If depth2 is set and equals depth1 set feed and/or speed and cut
       vertically down to depth.
    c. If depth2 is set and does not equal depth1, set feed and/or
       speed and cut vertically down to depth2. Then reset feed and/or
       speed and cut vertically down to depth.
    d. if depth2 is not set, reset feed and/or speed and cut vertically
       down to depth.
4B. Otherwise if depth2 is set
    a. Cut vertically down to depth2.
    b. Set feed and/or speed and cut vertically down to depth.
4C. Otherwise cut vertically down to depth.
5. If there is a dwell time, dwell for that amount of time.
6. Stop the spindle is there is a spindle stop at the bottom.
7. Reset feed if the retract feed differs from the current feed
   (which might happen if there is a feed_on_retract and/or a
    reduced_feed_at_end).
8. Retract vertically up to retract_z.
9. Update current location, feed, and speed.

Note that feed and speed canonical commands may have just been issued
(by handle_technology) that will be negated immediately by other feed
and speed canonical commands issued here. It may be worth the trouble
to avoid this, but we are living with it for now.

Data
----
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
cutting_depth:          OPTIONAL length_measure; (drilling_type_operation)
previous_diameter:      OPTIONAL length_measure;
dwell_time_bottom:      OPTIONAL time_measure;
feed_on_retract:        OPTIONAL positive_ratio_measure;
its_machining_strategy: OPTIONAL drilling_type_strategy;
spindle_stop_at_bottom: BOOLEAN;                 (boring_operation)
depth_of_testcut:       OPTIONAL length_measure;
waiting_position:       OPTIONAL cartesian_point;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPLEMENTED.
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
its_id is ignored.
retract_plane is the Z-coordinate of the retract plane in the feature
   coordinate system.
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
its_technology is handled before this function is called.
its_machine_functions is handled before this function is called.
overcut_length is for through features (Part 11, sec 4.2.3). We are requiring
   here that if given: (1) it must be positive and (2) cutting_depth may
   not be used.
cutting_depth, if given, may specify reaming less or more than the hole.
   We are requiring here that it must be positive if given.
previous_diameter is ignored; it is for information only. It might be
   a good idea to require that the previous diameter be given and that
   it be no more than a tiny bit smaller than the reaming tool diameter.
dwell_time_bottom, if given, is used as the time in seconds for which the
   tool dwells at the bottom of the hole.
feed_on_retract, if given, is used as a multiplier for the feed rate
   during the retract motion.
spindle_stop_at_bottom if true means stop the spindle at the bottom.
depth_of_testcut is for boring. Here it is required to be NULL.
waiting_position is for boring. Here it is required to be NULL.

The drilling strategy has:
reduced_cut_at_start:       OPTIONAL positive_ratio_measure; 
reduced_feed_at_start:      OPTIONAL positive_ratio_measure; 
depth_of_start:             OPTIONAL length_measure;
reduced_cut_at_end:         OPTIONAL positive_ratio_measure; 
reduced_feed_at_end:        OPTIONAL positive_ratio_measure; 
depth_of_end:               OPTIONAL length_measure;
WHERE
WR1: EXISTS(depth_of_start) OR
     NOT (EXISTS(reduced_cut_at_start) OR EXISTS(reduced_feed_at_start));
WR2: EXISTS(depth_of_end) OR
     NOT (EXISTS(reduced_cut_at_end) OR EXISTS(reduced_feed_at_end));

The find_cutting depths function checks the attributes of the drilling
strategy, so they are not rechecked here.

During the operation, _world.feedrate is kept fixed, since it is
needed as the basis for calculating current feedrate. When all motion
is finished, _world.feedrate is set to the feedrate in use at the end
of the operation. Similarly for spindle speed.

If the optional retract_plane is given, retract_z is set to that
amount above the top of the hole.  If not, retract_z is set to
ISO14649_UP above the top of the hole.

*/

static int op_reaming(            /* ARGUMENTS         */
 machining_feature * the_feature, /* feature to ream   */
 reaming * the_reaming)           /* reaming operation */
{
  static char name[] SET_TO "op_reaming";

  double feat_x;       /* in setup c_sys                                  */
  double feat_y;       /* in setup c_sys                                  */
  double feat_z;       /* in setup c_sys                                  */
  double retract_z;    /* retract z in setup c_sys                        */
  double feedrate;     /* current feed rate                               */
  double speed;        /* current spindle speed                           */
  double depth;        /* tip z coordinate at bottom in setup  c_sys      */
  double depth1;       /* tip z coordinate at end of start in setup c_sys */
  double depth2;       /* tip z coordinate at start of end in setup c_sys */
  double flute_length; /* reamer flute length to reamer tip               */
  drilling_type_strategy * strat; /* cutting strategy to use              */

  feat_x SET_TO _world.feature_place.location()->coordinates()->get(0);
  feat_y SET_TO _world.feature_place.location()->coordinates()->get(1);
  feat_z SET_TO _world.feature_place.location()->coordinates()->get(2);
  strat SET_TO the_reaming->its_machining_strategy();
  feedrate SET_TO _world.feedrate;
  speed SET_TO _world.speed;
  IFF(check_op_reaming(the_reaming));
  IFF(check_tool_reamer(the_reaming->its_tool(), &flute_length));
  IFF(find_cutting_depths(&depth, &depth1, &depth2, flute_length, 0,
			  the_feature->depth(), the_reaming->overcut_length(),
			  the_reaming->cutting_depth(), strat));
  IFF(find_retract_z(feat_z, the_reaming->retract_plane(),
		     ISO14649_UP, &retract_z));
  IFF(start_cut(feat_x, feat_y, retract_z));
  if (depth1 ISNT ROSE_NULL_REAL)
    {
      if (strat->reduced_cut_at_start() ISNT ROSE_NULL_REAL)
	{
	  speed SET_TO (_world.speed * strat->reduced_cut_at_start());
	  SET_SPINDLE_SPEED(speed);
	}
      if (strat->reduced_feed_at_start() ISNT ROSE_NULL_REAL)
	{
	  feedrate SET_TO (_world.feedrate * strat->reduced_feed_at_start());
	  SET_FEED_RATE(feedrate);
	}
      STRAIGHT_FEED_3(feat_x, feat_y, depth1);
      if (feedrate ISNT _world.feedrate)
	{
	  feedrate SET_TO _world.feedrate;
	  SET_FEED_RATE(feedrate);
	}
      if (speed ISNT _world.speed)
	{
	  speed SET_TO _world.speed;
	  SET_SPINDLE_SPEED(speed);
	}
    }
  if (depth2 ISNT ROSE_NULL_REAL)
    {
      STRAIGHT_FEED_3(feat_x, feat_y, depth2);
      if (strat->reduced_cut_at_end() ISNT ROSE_NULL_REAL)
	{
	  speed SET_TO (_world.speed * strat->reduced_cut_at_end());
	  SET_SPINDLE_SPEED(speed);
	}
      if (strat->reduced_feed_at_end() ISNT ROSE_NULL_REAL)
	{
	  feedrate SET_TO (_world.feedrate * strat->reduced_feed_at_end());
	  SET_FEED_RATE(feedrate);
	}
    }
  STRAIGHT_FEED_3(feat_x, feat_y, depth);
  if (the_reaming->feed_on_retract() IS ROSE_NULL_REAL)
    {
      if (feedrate ISNT _world.feedrate)
	{
	  feedrate SET_TO _world.feedrate;
	  SET_FEED_RATE(feedrate);
	}
    }
  else if (feedrate ISNT (the_reaming->feed_on_retract() * _world.feedrate))
    {
      feedrate SET_TO (the_reaming->feed_on_retract() * _world.feedrate);
      SET_FEED_RATE(feedrate);
    }
  if (the_reaming->dwell_time_bottom() ISNT ROSE_NULL_REAL)
    DWELL(the_reaming->dwell_time_bottom());
  if (the_reaming->spindle_stop_at_bottom() IS ROSE_TRUE)
    {
      STOP_SPINDLE_TURNING();
      _world.spindle_turning SET_TO CANON_STOPPED;
    }
  else
    CHK((the_reaming->spindle_stop_at_bottom() ISNT ROSE_FALSE),
        SPINDLE_STOP_AT_BOTTOM_MUST_BE_TRUE_OR_FALSE);
  STRAIGHT_FEED_3(feat_x, feat_y, retract_z);
  _world.current_x SET_TO feat_x;
  _world.current_y SET_TO feat_y;
  _world.current_z SET_TO retract_z;
  _world.feedrate SET_TO feedrate;
  _world.speed SET_TO speed;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_rough_milling_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_rough_both returns an error code.
   2. check_tool_endmill returns an error code.
   3. rough_mill_both_closed_pocket returns an error code.
   4. the_feature is not a closed_pocket:
      CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_ROUGH_MILL_BOTTOM_AND_SIDE.

Side Effects: Code is generated to rough mill the sides and bottom of
   the feature, which must be a closed pocket.

Called By: cut_feature

*/

static int op_rough_milling_both(           /* ARGUMENTS               */
 machining_feature * the_feature,           /* feature to rough mill   */
 bottom_and_side_rough_milling * the_rough) /* rough milling operation */
{
  static char name[] SET_TO "op_rough_milling_both";
  endmill * the_endmill;

  IFF(check_op_rough_both(the_rough));
  IFF(check_tool_endmill(the_rough->its_tool(), &the_endmill));
  if (the_feature->isa("closed_pocket"))
    IFF(rough_mill_both_closed_pocket(ROSE_CAST(closed_pocket, the_feature),
				      the_rough, the_endmill));
  else
    CHK(1, CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_ROUGH_MILL_BOTTOM_AND_SIDE);
  return ISO14649_OK;
}


/***********************************************************************/

/* op_rough_milling_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_rough_plane returns an error code.
   2. check_tool_plane returns an error code.
   3. The_feature is not a planar_face:
      FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE
   4. The tool is neither an endmill nor a facemill:
      TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL.
   5. mill_planar returns an error code.

Side Effects: Code is generated to cut the plane face.

Called By: cut_feature

Notes:

Plane_milling may be done using either a facemill or an endmill. Using a
facemill is feasible when entry from the side is possible.

Error 4 above should never happen, since check_tool_plane checks the
same thing.

*/

static int op_rough_milling_plane(  /* ARGUMENTS               */
 machining_feature * the_feature,   /* feature to rough mill   */
 plane_rough_milling * the_rough)   /* rough milling operation */
{
  static char name[] SET_TO "op_rough_milling_plane";
  endmill * the_endmill;
  facemill * the_facemill;

  the_endmill SET_TO NULL;
  the_facemill SET_TO NULL;
  IFF(check_op_rough_plane(the_rough));
  IFF(check_tool_plane(the_rough->its_tool(), &the_endmill, &the_facemill));
  if (the_feature->isa("planar_face"))
    {
      if (the_endmill)
	IFF(mill_planar(ROSE_CAST(planar_face, the_feature),
			       the_rough, the_endmill));
      else if (the_facemill)
	IFF(mill_planar(ROSE_CAST(planar_face, the_feature),
			       the_rough, the_facemill));
      else
	CHK(1, TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL);
    }
  else
    CHK(1, FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE);
  return ISO14649_OK;
}

/***********************************************************************/

/* op_rough_milling_side

Returned Value: int (ISO14649_OK)

Side Effects: None

Called By: cut_feature

This is a stub.

*/

static int op_rough_milling_side( /* ARGUMENTS                     */
 machining_feature * the_feature, /* feature to rough mill         */
 side_rough_milling * the_rough)  /* rough milling operation to do */
{
  static char name[] SET_TO "op_rough_milling_side";

  printf("side_rough_milling\n");
  return ISO14649_OK;
}


/***********************************************************************/

/* plunge_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.

Side Effects: This writes three lines of code to plunge into and back
out of a pocket whose center is at X=0, Y=0.

Called By: mill_rectangular_pocket

*/

static int plunge_pocket( /* ARGUMENTS                        */
 double depth,            /* Z coordinate to which to plunge  */
 double retract_z,        /* Z coordinate to which to retract */
 double code[][7],        /* code array to write in           */
 int * lines)             /* code array index                 */
{
  static char name[] SET_TO "plunge_pocket";

  IFF(write_feed(0, 0, retract_z, code, lines));
  IFF(write_feed(0, 0, -depth, code, lines));
  IFF(write_feed(0, 0, retract_z, code, lines));
  return ISO14649_OK;
}


/***********************************************************************/

/* reset_place

Returned Value: int (ISO14649_OK)

Side Effects: This resets the place to the default location:
origin at (0,0,0), Z-axis of (0,0,1), X-axis of (1,0,0). The
coordinates and direction_ratios must already exist.

Called By: Not currently in use.

*/

static int reset_place(      /* ARGUMENTS                   */
 axis2_placement_3d * place) /* the axis placement to reset */
{
  static char name[] SET_TO "reset_place";

  place->location()->coordinates()->put(0.0, 0);
  place->location()->coordinates()->put(0.0, 1);
  place->location()->coordinates()->put(0.0, 2);
  place->axis()->direction_ratios()->put(0.0, 0);
  place->axis()->direction_ratios()->put(0.0, 1);
  place->axis()->direction_ratios()->put(1.0, 2);
  place->ref_direction()->direction_ratios()->put(1.0, 0);
  place->ref_direction()->direction_ratios()->put(0.0, 1);
  place->ref_direction()->direction_ratios()->put(0.0, 2);

  return ISO14649_OK;
}

/***********************************************************************/

/* rough_mill_both_closed_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The boundary of the pocket is NULL: POCKET_BOUNDARY_MUST_NOT_BE_NULL.
   2. The boundary of the pocket is not a rectangular_closed_profile:
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE.
   3. check_rectangular_pocket returns an error code.
   4. check_rectangular_pocket_strategies returns an error code.
   5. mill_rectangular_pocket returns an error code.
   6. transform_code returns an error code.
   7. run_code returns an error code.
   8. start_cut returns an error code.
   9. The final retract goes above the security plane:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.

Side Effects: See below

Called By: op_rough_milling_both

Data for bottom_and_side_milling
--------------------------------
its_toolpath:           OPTIONAL toolpath_list;  (operation)
its_tool_direction:     OPTIONAL tool_direction;
its_id:                 identifier;              (machining_operation)
retract_plane:          OPTIONAL length_measure;
start_point:            OPTIONAL cartesian_point;
its_tool:               machining_tool;
its_technology:         technology;
its_machine_functions:  machine_functions;
overcut_length:         OPTIONAL length_measure; (milling_machining_operation)
approach:               OPTIONAL approach_retract_strategy; (milling_type_op.)
retract:                OPTIONAL approach_retract_strategy;
its_machining_strategy: OPTIONAL two5D_milling_strategy; (two5D_milling_op.)
axial_cutting_depth:    OPTIONAL length_measure; (bottom_and_side_milling)
radial_cutting_depth:   OPTIONAL length_measure;
allowance_side:         OPTIONAL length_measure;
allowance_bottom:       OPTIONAL length_measure;

its_toolpath is used if given (and in this case, all other data regarding
   the path of the tool is ignored). FIX. NOT YET IMPLEMENTED.
its_tool_direction (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retract_plane is the Z-coordinate of the retract plane in the coordinate
   system of the feature, which is the same as the distance between the
   top of the feature and the point to which to retract.
start_point is ignored. The spec (Part 10, sec 4.7.2) allows this.
its_tool is handled before this function is called.
technology is handled before this function is called. This results
   in _world.feed_rate being set.
its_machine_functions is handled before this function is called.
overcut_length must not be used for pockets (Part 11, sec 4.2.3).

Data for closed_pocket
----------------------
its_id:             identifier; (manufacturing_feature)
its_workpiece:      workpiece;
its_operations:     SET [0:?] OF machining_operation;
feature_placement:  axis2_placement_3d; (two5D_manufacturing_feature)
depth:              elementary_surface (machining_feature)
its_boss:           SET [0:?] OF boss; (pocket)
slope:              OPTIONAL plane_angle_measure;
bottom_condition:   pocket_bottom_condition;
planar_radius:      OPTIONAL toleranced_length_measure;
othogonal_radius:   OPTIONAL toleranced_length_measure;
feature_boundary:   closed_profile;

Data for rectangular_closed_profile
-----------------------------------
placement:          OPTIONAL axis2_placement_3d; (profile)
<no attributes>     (closed_profile)
profile_width:      toleranced_length_measure; (rectangular_closed_profile)
profile_length:      toleranced_length_measure;

This requires the pocket to have a rectangular closed profile. It would
be fairly easy to add circular_closed_profile.

The code is generated initially in feature coordinates. Then it is
transformed into setup coordinates.

Each line of code consists of seven doubles. See run_code function
for what they mean.

The first line of code serves only to mark the point above which (by one
retract distance) the tool should be moved by the start_cut function.

Local variables pocket_length, pocket_width, pocket_depth are set in
check_rectangular_pocket, which has to deal with them anyway.

check_rectangular_pocket_strategies may insert milling strategies in
the_rough. After code is generated here, these strategies are removed
from the_rough (since the_rough may be used elsewhere) and deleted.

*/

static int rough_mill_both_closed_pocket(   /* ARGUMENTS                   */
 closed_pocket * the_pocket,                /* closed pocket to rough mill */
 bottom_and_side_rough_milling * the_rough, /* rough milling operation     */
 endmill * the_endmill)                     /* endmill to use              */
{
  static char name[] SET_TO "rough_mill_both_closed_pocket";
  double retract_z;    /* retract z in setup c_sys       */
  double code[ISO14649_CODE_SIZE][7];
  int lines;           /* number of lines of code */
  approach_retract_strategy * enter_strategy;
  approach_retract_strategy * leave_strategy;
  two5D_milling_strategy * inside_strategy;
  double pocket_length;
  double pocket_width;
  double pocket_depth;
  double pocket_radius;
  double stepover;

  lines SET_TO 0;
  enter_strategy SET_TO NULL;
  leave_strategy SET_TO NULL;
  inside_strategy SET_TO NULL;
  CHK((the_pocket->feature_boundary() IS NULL),
      POCKET_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((NOT(the_pocket->feature_boundary()->isa("rectangular_closed_profile"))),
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE);
  IFF(check_rectangular_pocket(the_pocket, &pocket_length, &pocket_width,
			       &pocket_depth, &pocket_radius));
  IFF(check_rectangular_pocket_strategies
      (pocket_length, pocket_width, pocket_depth, pocket_radius, the_rough,
       the_endmill, &stepover, &enter_strategy, &leave_strategy,
       &inside_strategy, 0));
  IFF(mill_rectangular_pocket
      (pocket_length, pocket_width, pocket_depth, pocket_radius, stepover,
       the_endmill->dimension()->diameter(), the_rough, code, &lines));
  IFF(transform_code(code, lines, &(_world.feature_place)));
  CHK((code[0][3] > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  IFF(start_cut(code[0][1], code[0][2], code[0][3]));
  IFF(run_code((code + 1), (lines - 1)));
  if (enter_strategy)
    {
      delete enter_strategy;
      the_rough->approach(NULL);
    }
  if (leave_strategy)
    {
      delete leave_strategy;
      the_rough->retract(NULL);
    }
  if (inside_strategy)
    {
      delete inside_strategy;
      the_rough->its_machining_strategy(NULL);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* run_code

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. An unknown command code is used:
      COMMAND_CODE_TYPE_MUST_BE_MOTION_SPEED_OR_FEED
   2. The last command is not a motion command:
      LAST_COMMAND_CODE_TYPE_MUST_BE_FEED_OR_TRAVERSE.

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  mill_planar_regular
  rough_mill_both_closed_pocket

This takes an array of coded commands and executes them in order.

This requires that the last line of code be a motion command (straight
feed, straight traverse, or arc) so that the current position can be
updated from the last line of code. The current position is updated.

*/

static int run_code( /* ARGUMENTS               */
 double code[][7],   /* code array to write in  */
 int lines)          /* number of lines of code */
{
  static char name[] SET_TO "run_code";
  int n;

  for (n SET_TO 0; n < lines; n++)
    {
      switch ((int)code[n][0])
	{
	case CANON_STRAIGHT_FEED:
	  STRAIGHT_FEED_3(code[n][1], code[n][2], code[n][3]);
	  break;
	case CANON_ARC_FEED:
	  ARC_FEED_3(code[n][1], code[n][2], code[n][3],
		   code[n][4], (int)code[n][5], code[n][6]);
	  break;
	case CANON_STRAIGHT_TRAVERSE:
	  STRAIGHT_TRAVERSE_3(code[n][1], code[n][2], code[n][3]);
	  break;
	case CANON_SET_FEED_RATE:
	  SET_FEED_RATE(code[n][1]);
	  break;
	case CANON_SET_SPINDLE_SPEED:
	  SET_SPINDLE_SPEED(code[n][1]);
	  break;
	default:
	  CHK(1, COMMAND_CODE_TYPE_MUST_BE_MOTION_SPEED_OR_FEED);
	  break;
	}
    }
  n--;
  if (((int)code[n][0] IS CANON_STRAIGHT_FEED) OR
      ((int)code[n][0] IS CANON_STRAIGHT_TRAVERSE))
    {
      _world.current_x SET_TO code[n][1];
      _world.current_y SET_TO code[n][2];
      _world.current_z SET_TO code[n][3];
    }
  else if ((int)code[n][0] IS CANON_ARC_FEED)
    {
      _world.current_x SET_TO code[n][1];
      _world.current_y SET_TO code[n][2];
      _world.current_z SET_TO code[n][6];
    }
  else
    CHK(1, LAST_COMMAND_CODE_TYPE_MUST_BE_FEED_OR_TRAVERSE);
  
  return ISO14649_OK;
}

/***********************************************************************/

/* set_security_z_now

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_horizontal_plane returns an error code.

Side Effects: See below

Called By: execute_machining

This checks that the secplane is a plane and its normal is vertical in
the coordinate system in which it is located (which is the feature
coordinate system, which is already known to have its Z axis
vertical).  Then it sets _world.security_z_now to the sum of the Z
values of (1) the location of the feature in the setup coordinate
system and (2) the location of the secplane in the feature coordinate
system.

*/

static int set_security_z_now(  /* ARGUMENTS                      */
 elementary_surface * secplane) /* the (should be) plane to check */
{
  static char name[] SET_TO "set_security_z_now";
  
  IFF(check_horizontal_plane(secplane));
  _world.security_z_now SET_TO
    (_world.feature_place.location()->coordinates()->get(2) +
     secplane->position()->location()->coordinates()->get(2));
  return ISO14649_OK;
}

/***********************************************************************/

/* start_cut

Returned Value: int (ISO14649_OK)

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  mill_planar_regular
  op_center_drilling
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_multistep_drilling
  op_reaming
  rough_mill_both_closed_pocket

This:
1. retracts at traverse rate towards +Z (if necessary) from the current
   location to the security plane.
2. traverses (if necessary) on the security plane to above the end point.
3. traverses along -Z (if necessary) to the end point.

*/

static int start_cut(  /* ARGUMENTS                 */
 double end_x,         /* x coordinate of end point */
 double end_y,         /* y coordinate of end point */
 double end_z)         /* z coordinate of end point */
{
  static char name[] SET_TO "start_cut";

  if ((_world.current_x ISNT end_x) OR (_world.current_y ISNT end_y))
    {
      if (_world.current_z < _world.security_z_now)
	{
	  STRAIGHT_TRAVERSE_3(_world.current_x, _world.current_y,
			    _world.security_z_now);
	  _world.current_z SET_TO _world.security_z_now;
	}
      STRAIGHT_TRAVERSE_3(end_x, end_y, _world.current_z);
    }
  if (_world.current_z ISNT end_z)
    STRAIGHT_TRAVERSE_3(end_x, end_y, end_z);
  return ISO14649_OK;
}

/***********************************************************************/

/* tand

Returned Value: double (the tangent of the "degrees" angle)

Side Effects: None

Called By:
  check_countersunk_hole
  check_tool_countersink
  enter_pocket_pass_zigzag
  find_pocket_plunge_start_helix
  find_pocket_plunge_start_ramp
  find_pocket_plunge_start_zigzag

This is not checking for the argument being a multiple of 90 degrees,
which is a little risky. The caller should check.

*/

static double tand( /* ARGUMENTS        */
 double degrees)    /* angle in degrees */
{
  return tan((M_PI / 180.0) * degrees);
}

/***********************************************************************/

/* transform_code

Returned Value:
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_if_vertical returns an error code.
   2. The Z axis of the place to which to move the code is not vertical:
      Z_AXIS_MUST_BE_VERTICAL

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  mill_planar_regular
  rough_mill_both_closed_pocket

This takes an array of code and changes the coordinate values (which
are originally in the "place" coordinate system) so they are in the
setup coordinate system. Only those code lines whose first entry
is CANON_STRAIGHT_FEED, CANON_ARC_FEED, or CANON_STRAIGHT_TRAVERSE
get their values changed. The place coordinate system must have its
Z-axis vertical in the setup coordinate system.

*/

static int transform_code(    /* ARGUMENTS                */
 double code[][7],            /* code array to transform  */
 int lines,                   /* number of lines of code  */
 axis2_placement_3d * place)  /* place to move code to    */
{
  static char name[] SET_TO "transform_code";
  int vertical;
  double place_angle;
  double point_angle;
  double dx;
  double dy;
  double dz;
  double arm;
  int n;

  dx SET_TO place->location()->coordinates()->get(0);
  dy SET_TO place->location()->coordinates()->get(1);
  dz SET_TO place->location()->coordinates()->get(2);
  place_angle SET_TO atan2(place->ref_direction()->direction_ratios()->get(1),
			   place->ref_direction()->direction_ratios()->get(0));
  IFF(find_if_vertical(place->axis(), &vertical));
  CHK((NOT vertical), Z_AXIS_MUST_BE_VERTICAL);
  for (n SET_TO 0; n < lines; n++)
    {
      if (((int)code[n][0] IS CANON_STRAIGHT_FEED) OR
	  ((int)code[n][0] IS CANON_STRAIGHT_TRAVERSE))
	{
	  arm SET_TO hypot(code[n][1], code[n][2]);
	  point_angle SET_TO atan2(code[n][2], code[n][1]);
	  code[n][1] SET_TO (dx + (arm * cos(place_angle + point_angle)));
	  code[n][2] SET_TO (dy + (arm * sin(place_angle + point_angle)));
	  code[n][3] SET_TO (dz + code[n][3]);
	}
      else if ((int)code[n][0] IS CANON_ARC_FEED)
	{
	  arm SET_TO hypot(code[n][1], code[n][2]);
	  point_angle SET_TO atan2(code[n][2], code[n][1]);
	  code[n][1] SET_TO (dx + (arm * cos(place_angle + point_angle)));
	  code[n][2] SET_TO (dy + (arm * sin(place_angle + point_angle)));
	  arm SET_TO hypot(code[n][3], code[n][4]);
	  point_angle SET_TO atan2(code[n][4], code[n][3]);
	  code[n][3] SET_TO (dx + (arm * cos(place_angle + point_angle)));
	  code[n][4] SET_TO (dy + (arm * sin(place_angle + point_angle)));
	  code[n][6] SET_TO (dz + code[n][6]);
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* write_arc

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  enter_pocket_pass_helix
  mill_circular_pocket
  mill_regular_pocket
  mill_semicircle_end_pocket

This writes one line of code representing cutting a circular or
helical arc.  Lines is increased by one.

The arc written here is conceptually the same as a CANON_ARC with a
vertical axis.

If rotation is positive, the arc is traversed counterclockwise as
viewed from the positive Z axis. If rotation is negative, the arc is
traversed clockwise. If rotation is 0, end_x and end_y must
be the same as the corresponding coordinates of the current point and
no arc is made (but there may be translation parallel to the Z axis).
If rotation is 1, more than 0 but not more than 360 degrees of arc
should be made. In general, if rotation is n, the amount of rotation
in the arc should be more than ([n-1] x 360) but not more than (n x
360).

*/

static int write_arc( /* ARGUMENTS                  */
 double end_x,        /* X coordinate at end        */
 double end_y,        /* Y coordinate at end        */
 double center_x,     /* X coordinate at center     */
 double center_y,     /* Y coordinate at center     */
 int rotation,        /* number of turns, see above */ 
 double end_z,        /* Z coordinate at end        */
 double code[][7],    /* code array to write in     */
 int * lines)         /* code array index           */
{
  static char name[] SET_TO "write_arc";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] SET_TO CANON_ARC_FEED;
  code[*lines][1] SET_TO end_x;
  code[*lines][2] SET_TO end_y;
  code[*lines][3] SET_TO center_x;
  code[*lines][4] SET_TO center_y;
  code[*lines][5] SET_TO (double)rotation;
  code[*lines][6] SET_TO end_z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/

/* write_feed

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  cut_straight
  enter_pocket_pass
  enter_pocket_pass_zigzag
  mill_circular_pocket
  mill_planar_bi
  mill_planar_uni
  mill_rectangular_pocket_regular
  mill_regular_pocket
  mill_semicircle_end_pocket
  plunge_pocket

This writes one line of code representing a straight feed cut. Lines
is increased by one.

*/

static int write_feed( /* ARGUMENTS               */
 double x,             /* X coordinate at end     */
 double y,             /* Y coordinate at end     */
 double z,             /* Z coordinate at end     */
 double code[][7],     /* code array to write in  */
 int * lines)          /* code array index        */
{
  static char name[] SET_TO "write_feed";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] SET_TO CANON_STRAIGHT_FEED;
  code[*lines][1] SET_TO x;
  code[*lines][2] SET_TO y;
  code[*lines][3] SET_TO z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/

/* write_feed_y

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  mill_planar_bi (via "feeder" function pointer)
  mill_planar_uni (via "feeder" function pointer)

This writes one line of code representing a straight feed cut rotated
90 degrees counterclockwise. This function exists so that rotated code
may be generated directly. To do the rotation, x is put into
code[*lines][2], and -y is put into code[*lines][1].

Lines is increased by one. 

*/

static int write_feed_y( /* ARGUMENTS               */
 double x,               /* X coordinate at end     */
 double y,               /* Y coordinate at end     */
 double z,               /* Z coordinate at end     */
 double code[][7],       /* code array to write in  */
 int * lines)            /* code array index        */
{
  static char name[] SET_TO "write_feed_y";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] SET_TO CANON_STRAIGHT_FEED;
  code[*lines][1] SET_TO -y;
  code[*lines][2] SET_TO x;
  code[*lines][3] SET_TO z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/

/* write_traverse

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  cut_straight
  mill_planar_bi
  mill_planar_uni
  mill_rectangular_pocket_regular

This writes one line of code representing a straight traverse. Lines
is increased by one.

*/

static int write_traverse( /* ARGUMENTS               */
 double x,                 /* X coordinate at end     */
 double y,                 /* Y coordinate at end     */
 double z,                 /* Z coordinate at end     */
 double code[][7],         /* code array to write in  */
 int * lines)              /* code array index        */
{
  static char name[] SET_TO "write_traverse";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] SET_TO CANON_STRAIGHT_TRAVERSE;
  code[*lines][1] SET_TO x;
  code[*lines][2] SET_TO y;
  code[*lines][3] SET_TO z;
  (*lines)++;
  return ISO14649_OK;
}


/***********************************************************************/

/* write_traverse_y

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  mill_planar_bi (via "traverser" function pointer)
  mill_planar_uni (via "traverser" function pointer)

This writes one line of code representing a straight traverse rotated
90 degrees counterclockwise. This function exists so that rotated code
may be generated directly. To do the rotation, x is put into
code[*lines][2], and -y is put into code[*lines][1].

Lines is increased by one.

*/

static int write_traverse_y( /* ARGUMENTS               */
 double x,                   /* X coordinate at end     */
 double y,                   /* Y coordinate at end     */
 double z,                   /* Z coordinate at end     */
 double code[][7],           /* code array to write in  */
 int * lines)                /* code array index        */
{
  static char name[] SET_TO "write_traverse_y";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] SET_TO CANON_STRAIGHT_TRAVERSE;
  code[*lines][1] SET_TO -y;
  code[*lines][2] SET_TO x;
  code[*lines][3] SET_TO z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/
/***********************************************************************/

/*

The functions in this section of this file are functions for
external programs to call to tell the iso14649 interpreter
what to do. They are declared in iso14649.hh.

*/

/***********************************************************************/

/* iso14649_close

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, this returns ISO14649_OK.
   1. iso14649_reset returns an error code.

Side Effects: See below

Called By: external programs

PROGRAM_END is called.

iso14649_reset is called (see documentation of that function).
This does not need to close the iso14649 file because it is closed
automatically immediately after it is read.

*/

int iso14649_close() /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_close";
  PROGRAM_END();
  IFF(iso14649_reset());

  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_execute

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   If _world.action_flag is ISO14649_NO_ACTION, this returns ISO14649_OK.
   Otherwise, this returns ISO14649_FINISH.
   1. execute_executable returns an error code.

Side Effects: See below

Called By: external programs

This executes the most recently selected executable.
Calls to canonical machining commands are made.

The only kernel function that sets the _world.action_flag to something other
than ISO14649_NO_ACTION is change_tool.

*/

int iso14649_execute()  /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_execute";

  IFF(execute_executable());
  return ((_world.action_flag IS ISO14649_NO_ACTION) ? ISO14649_OK :
	  ISO14649_FINISH);
}

/***********************************************************************/

/* iso14649_exit

Returned Value: int (ISO14649_OK)

Side Effects: None

Called By: external programs

Nothing needs to be done on exiting.

*/

int iso14649_exit() /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_exit";
  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_init

Returned Value: int ISO14649_OK

Side Effects: See below

Called By: external programs

All values in the _world structure are reset.
All STEP data is wiped out.
A USE_LENGTH_UNITS canonical command call is made.
A SET_FEED_REFERENCE canonical command call is made.
A SET_ORIGIN_OFFSETS canonical command call is made.
An INIT_CANON call is made.

Some Z values set here (e.g. retracted_z and security_z_now) are based
on having the machine origin on the machine table. Actual machines
usually have Z=0 where the spindle is fully retracted, so that all
other Z values are negative.

*/

int iso14649_init() /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_init";

  ROSE.quiet(ROSE_TRUE);
  ROSE.clearWorkspace();
  machining_schema_force_load();
  milling_schema_force_load();
  INIT_CANON();
  USE_LENGTH_UNITS(CANON_UNITS_MM);
  SET_ORIGIN_OFFSETS_3(0.0, 0.0, 0.0);
  SET_FEED_REFERENCE(CANON_XYZ);
  _world.a_exec SET_TO NULL;
  _world.a_exec_index SET_TO 0;
  _world.a_workpiece SET_TO NULL;
  _world.a_workplan SET_TO NULL;
  _world.action_flag SET_TO ISO14649_NO_ACTION;
  _world.change_x SET_TO ROSE_NULL_REAL;
  _world.change_y SET_TO ROSE_NULL_REAL;
//_world.control_mode set in iso14649_synch
//_world.current_tool_index set in iso14649_synch
//_world.current_x set in iso14649_synch
//_world.current_y set in iso14649_synch
//_world.current_z set in iso14649_synch
  _world.design SET_TO NULL;
  _world.endfile SET_TO 0;
  _world.execs SET_TO NULL;
  _world.exit SET_TO 0;
  init_place(&(_world.feature_place));
  _world.feed_override SET_TO ON;
//_world.feedrate set in iso14649_synch
  _world.filename[0] SET_TO 0;
//_world.flood set in iso14649_synch
//_world.mist set in iso14649_synch
  _world.name_text[0] SET_TO 0;
  _world.rapid_secplane SET_TO NULL;
  _world.retracted_z SET_TO 250.0; //
  _world.security_z_now SET_TO 0.0;
  _world.security_z_setup SET_TO 0.0;
//_world.speed set in iso14649_synch
  _world.speed_feed_mode SET_TO CANON_INDEPENDENT;
  _world.speed_override SET_TO ON;
//_world.spindle_turning set in iso14649_synch
  _world.stack[0][0] SET_TO 0; // does not actually need initialization
  _world.stack_index SET_TO 0;
  _world.status SET_TO ISO14649_OK;
  _world.tool_length_offset SET_TO 0.0;
//_world.tool_max set in iso14649_synch
//_world.tool_table set in iso14649_synch
//_world.traverse_rate set in iso14649_synch
  _world.workpiece_place SET_TO NULL;

  // Synch rest of settings to external world
  iso14649_synch();

  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_load_tool_table

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, this returns ISO14649_OK.
   1. _world.tool_max is larger than CANON_TOOL_MAX:
      TOOL_MAX_MUST_NOT_EXCEED_CANON_TOOL_MAX.

Side Effects:
   _world.tool_table[] is modified.

Called By:
   iso14649_synch
   external programs

This function copies tool tables from the external world into the
tool_table array in the _world.

The CANON_TOOL_MAX is an upper limit for this software. The
_world.tool_max is intended to be set for a particular machine.

*/

int iso14649_load_tool_table() /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_load_tool_table";
  int n;
  CANON_TOOL_TABLE a_table;

  CHK((_world.tool_max > CANON_TOOL_MAX),
      TOOL_MAX_MUST_NOT_EXCEED_CANON_TOOL_MAX);
  for (n SET_TO 0; n <= _world.tool_max; n++)
    {
      a_table SET_TO GET_EXTERNAL_TOOL_TABLE(n);
      strcpy(_world.tool_table[n].name, a_table.name); // FMP
      _world.tool_table[n].length SET_TO a_table.length;
      _world.tool_table[n].diameter SET_TO a_table.diameter;
    }
  for(; n <= CANON_TOOL_MAX; n++)
    {
      _world.tool_table[n].name[0] SET_TO 0; // FMP
      _world.tool_table[n].length SET_TO 0;
      _world.tool_table[n].diameter SET_TO 0;
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_open

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise it returns ISO14649_FINISH.
   1. A file is already open: A_FILE_MUST_NOT_BE_ALREADY_OPEN.
   2. The name of the file is too long: FILE_NAME_MUST_NOT_BE_TOO_LONG.
   3. The file cannot be read: INPUT_FILE_MUST_BE_READABLE.

Side Effects: See below

Called By: external programs

The file is opened and read into a working structure.
The working structure is saved in _world.design.
The file name is copied into _world.filename.
It is checked that all the tools required by the program are
in the machine.

See documentation of iso14649_read regarding the setting of the
action_flag and the return value.

*/

int iso14649_open(       /* ARGUMENTS                                 */
 const char * file_name) /* name of input ISO 14649 STEP Part 21 file */
{
  static char name[] SET_TO "iso14649_open";

  // FMP
  (void) iso14649_init();

  CHK((_world.design ISNT NULL), A_FILE_MUST_NOT_BE_ALREADY_OPEN);
  CHK((strlen(file_name) > (ISO14649_TEXT_SIZE - 1)),
      FILE_NAME_MUST_NOT_BE_TOO_LONG);
  _world.design SET_TO ROSE.useDesign(file_name);
  CHK((_world.design IS NULL), INPUT_FILE_MUST_BE_READABLE);
  IFF(check_and_store());
  IFF(check_tools(_world.execs));
  SPINDLE_RETRACT();
  _world.action_flag SET_TO ISO14649_SET_RETRACT;

  strcpy(_world.filename, file_name);
  return ISO14649_FINISH;
}

/***********************************************************************/

/* iso14649_read

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, if all workingsteps have been executed, this returns
   ISO14649_ENDFILE.
   Otherwise it returns ISO14649_OK.
   1. The external queue is not empty: EXTERNAL_QUEUE_MUST_BE_EMPTY
   2. When the spindle is fully retracted, the tool tip is below the
      setup security plane:
      TOOL_MUST_BE_ABLE_TO_RETRACT_TO_SETUP_SECURITY_PLANE.
   3. The value of the action_flag is not ISO14649_SET_RETRACT,
      ISO14649_SET_POSITION, or ISO14649_NO_ACTION:
      ACTION_FLAG_VALUE_MUST_HAVE_KNOWN_MEANING.

Side Effects: See below

Called By: external programs

This does not actually read anything. It sets _world.a_exec to the next
workingstep to be executed. If all workingsteps have been executed,
that will be NULL, which serves as the signal to return ISO14649_ENDFILE.
This also increments _world.a_exec_index by one.

If the _world.action_flag is set to ISO14649_SET_RETRACT, this sets
the current position and sets _world.retracted_z to the current
z_position plus the current tool length offset (so that retracted_z
represents the fully retracted position when no tool is being
used). _world.action_flag is set to ISO14649_SET_RETRACT only by
ISO14649_open, since the location of the setup is changed when and
only when a new program is opened (changing the location has the side
effect of changing the value of the fully retracted position). To
insure that the spindle is fully retracted when this function is
called, the last motion commanded by iso14649_open is a
SPINDLE_RETRACT.  Also, iso14649_open returns ISO14649_FINISH so that
the controller will empty the motion queue before calling
iso14649_read. It may happen that the spindle cannot be retracted far
enough to get the tool above security_z_setup (which is also set while
executing iso14649_open). That is checked here.

If the _world.action_flag is set to ISO14649_SET_POSITION, this sets
the current position. The flag is set that way when change_tool is
called. The tool change operation may change the position of the
controlled point.

*/

int iso14649_read() /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_read";

  if ((_world.action_flag IS ISO14649_SET_RETRACT) OR
      (_world.action_flag IS ISO14649_SET_POSITION))
    {
      CHK((NOT(GET_EXTERNAL_QUEUE_EMPTY())), EXTERNAL_QUEUE_MUST_BE_EMPTY);
      _world.current_x SET_TO GET_EXTERNAL_POSITION_X();
      _world.current_y SET_TO GET_EXTERNAL_POSITION_Y();
      _world.current_z SET_TO GET_EXTERNAL_POSITION_Z();
      if (_world.action_flag IS ISO14649_SET_RETRACT)
	{
	  _world.retracted_z SET_TO
	    (_world.current_z + GET_EXTERNAL_TOOL_LENGTH_OFFSET());
	  printf("current z = %f, retracted z = %f, security z = %f\n", _world.current_z, _world.retracted_z, _world.security_z_setup); // FMP
	  // BUG? should this be a comparison with _world.retracted_z?
#if 0				// FMP
	  CHK((_world.current_z < _world.security_z_setup),
	      TOOL_MUST_BE_ABLE_TO_RETRACT_TO_SETUP_SECURITY_PLANE);
#endif
	}
      _world.action_flag SET_TO ISO14649_NO_ACTION;
    }
  else if (_world.action_flag ISNT ISO14649_NO_ACTION)
    CHK(1, ACTION_FLAG_VALUE_MUST_HAVE_KNOWN_MEANING);
  _world.a_exec SET_TO (*(_world.execs))[_world.a_exec_index++];
  return (_world.a_exec ? ISO14649_OK : ISO14649_ENDFILE);
}

/***********************************************************************/

/* iso14649_reset

Returned Value: int (ISO14649_OK)

Side Effects: See below

Called By:
  external programs
  iso14649_close

This resets only those parts of the world model that need to be reset
after executing one workingstep (successfully or not).

Currently (while the interpreter is being built) there is nothing that
needs to be reset, and this does nothing. If this still does nothing
after the interpreter is finished, it might be eliminated.

*/

int iso14649_reset() /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_reset";
  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_synch

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise it returns ISO14649_OK.
   1. iso14649_load_tool_table returns an error code.

Side Effects: See below

Called By:
  external programs
  iso14649_init

Values in the _world model that may be obtained by calling
GET_EXTERNAL... functions are updated by calling those functions.
Also, the tool table is reloaded.

*/

int iso14649_synch() /* NO ARGUMENTS */
{
  static char name[] SET_TO "iso14649_synch";
  _world.control_mode SET_TO GET_EXTERNAL_MOTION_CONTROL_MODE();
  _world.current_tool_index SET_TO GET_EXTERNAL_TOOL_INDEX();
  _world.current_x SET_TO GET_EXTERNAL_POSITION_X();
  _world.current_y SET_TO GET_EXTERNAL_POSITION_Y();
  _world.current_z SET_TO GET_EXTERNAL_POSITION_Z();
  _world.feedrate SET_TO GET_EXTERNAL_FEED_RATE();
  _world.flood SET_TO (GET_EXTERNAL_FLOOD() ISNT 0) ? ON : OFF;
  _world.mist SET_TO (GET_EXTERNAL_MIST() ISNT 0) ? ON : OFF;
  _world.speed SET_TO GET_EXTERNAL_SPEED();
  _world.spindle_turning SET_TO GET_EXTERNAL_SPINDLE();
  _world.tool_max SET_TO GET_EXTERNAL_TOOL_MAX();
  _world.traverse_rate SET_TO GET_EXTERNAL_TRAVERSE_RATE();

  IFF(iso14649_load_tool_table());
  return ISO14649_OK;
}

/****************************************************************************/
/****************************************************************************/

/*

The functions in this section of this file are functions for external
programs to call to get information from the iso14649 interpreter. They
are declared in iso14649.hh.

*/

/***********************************************************************/

/* iso14649_current_action

Returned Value: none

Side Effects: See below

Called By: external programs

This makes a string describing the state of the _world and (if the
string is shorter than max_size) copies it into action_text. If the
string not shorter than max_size, this copies an empty string into
action_text.

*/

void iso14649_current_action( /* ARGUMENTS                            */
 char * action_text,          /* string to copy file name into        */
 int max_size)                /* maximum number of characters to copy */
{
  char buffer[1000];
  sprintf(buffer, "Executed workingstep %s\n", _world.a_exec->its_id());
  if (strlen(buffer) < max_size)
    strcpy(action_text, buffer);
  else
    action_text[0] SET_TO 0;
}

/***********************************************************************/

/* iso14649_error_text

Returned Value: none

Side Effects: see below

Called By: external programs

This copies the error string whose index in the _iso14649_errors array
is error_code into the error_text array -- unless the error_code is
an out-of-bounds index or the length of the error string is not less
than max_size, in which case an empty string is put into the
error_text. The length of the error_text array should be at least
max_size.

*/

void iso14649_error_text( /* ARGUMENTS                            */
 int error_code,          /* code number of error                 */
 char * error_text,       /* char array to copy error text into   */
 int max_size)            /* maximum number of characters to copy */
{
  if (((error_code > -1) AND (error_code <= ISO14649_MAX_ERROR)) AND
      (strlen(_iso14649_errors[error_code]) < max_size))
    {
      strcpy(error_text, _iso14649_errors[error_code]);
    }
  else
    error_text[0] SET_TO 0;
}

/***********************************************************************/

/* iso14649_file_name

Returned Value: none

Side Effects: See below

Called By: external programs

If the name of the currently open ISO 14649 file is shorter than max_size,
this copies it into action_text. If not, this copies as much of 
"name too long" as will fit into action_text.

If no ISO 14649 file is open, the file name will be the empty string.

*/

void iso14649_file_name( /* ARGUMENTS                            */
 char * file_name,       /* string to copy into                  */
 int max_size)           /* maximum number of characters to copy */
{
  int n;
  char buffer[14];

  if (strlen(_world.filename) < max_size)
    strcpy(file_name, _world.filename);
  else
    {
      strcpy(buffer, "name too long");
      for (n SET_TO 0; ((n < 14) && (n < (max_size - 1))); n++)
	file_name[n] SET_TO buffer[n];
      file_name[n] SET_TO 0;
    }
}

/***********************************************************************/

/* iso14649_name_text

Returned Value: none

Side Effects: See below

Called By: external programs

If the name of the currently selected workingstep is shorter than
max_size, this copies it into name_text. If not, this copies an empty
string into name_text.

*/

void iso14649_name_text( /* ARGUMENTS                            */
 char * name_text,       /* string to copy into                  */
 int max_size)           /* maximum number of characters to copy */
{
  char buffer[1000];
  
  if(_world.a_exec)
    sprintf(buffer, "%s", _world.a_exec->its_id());
  else
    buffer[0] SET_TO 0;
  if (strlen(buffer) < max_size)
    strcpy(name_text, buffer);
  else
    name_text[0] SET_TO 0;
}

/***********************************************************************/

/* iso14649_stack_name

Returned Value: none

Side Effects: see below

Called By: external programs

This copies at most (max_size - 1) non-null characters from the
string whose index in the _world.stack array is stack_index into the
function_name string and puts a NULL after the last non-null character --
unless the stack_index is an out-of-bounds index, in which case an
empty string is put into the function_name.

This function is intended to be used several times in a row to get the
stack of function calls that existed when the most recent error
occurred. It should be called first with stack_index equal to 0,
next with stack_index equal to 1, and so on, stopping when an
empty string is returned for the name.

*/

void iso14649_stack_name( /* ARGUMENTS                            */
 int stack_index,         /* index into stack of function names   */
 char * function_name,    /* string: to copy function name into   */
 int max_size)            /* maximum number of characters to copy */
{
  int n;
  char * the_name;

  if ((stack_index > -1) AND (stack_index < 20))
    {
      the_name SET_TO _world.stack[stack_index];
      for (n SET_TO 0; n < (max_size - 1); n++)
        {
          if (the_name[n] ISNT 0)
            function_name[n] SET_TO the_name[n];
          else
            break;
        }
      function_name[n] SET_TO 0;
    }
  else
    function_name[0] SET_TO 0;
}

/***********************************************************************/
