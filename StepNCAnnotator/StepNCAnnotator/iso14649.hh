/*
    File: iso14649.hh

    Declarations for the iso14649 interpreter.

*/

#ifndef ISO14649_HH
#define ISO14649_HH


/**********************/
/* INCLUDE DIRECTIVES */
/**********************/

#include <stdio.h>
#include "machining_schema.h"
#include "machining_schema_ROSE_LOAD.h"
#include "milling_schema.h"
#include "milling_schema_ROSE_LOAD.h"
#include "canon.hh"
#include "iso14649_err.h"

/**********************/
/*   COMPILER MACROS  */
/**********************/

#define AND              &&
#define IS               ==
#define ISNT             !=
#define MAX(x, y)        ((x) > (y) ? (x) : (y))
#define MIN(x, y)        ((x) < (y) ? (x) : (y))
#define NOT              !
#define OR               ||
#define SET_TO           =
#define ON               1
#define OFF              0

#define ISO14649_OK           0
#define ISO14649_EXIT         1
#define ISO14649_FINISH       2
#define ISO14649_ENDFILE      3

#define ISO14649_ALLOW        0.2
#define ISO14649_CODE_SIZE  2048
#define ISO14649_TEXT_SIZE  256
#define ISO14649_TINY         0.0001
#define ISO14649_UP           5.0

/* action_flag values */
#define ISO14649_NO_ACTION 0
#define ISO14649_SET_POSITION 1
#define ISO14649_SET_RETRACT 2

/* Canonical machining functions for pseudocode */
#define CANON_STRAIGHT_FEED      1
#define CANON_ARC_FEED           2
#define CANON_STRAIGHT_TRAVERSE  3
#define CANON_SET_FEED_RATE      4
#define CANON_SET_SPINDLE_SPEED  5

/*

ISO14649_UP is the distance (in millimeters) above the feature being
cut at which to start moving at feed rate on the approach (and at
which to start moving at traverse rate on the retract).

ISO14649_TINY is error allowed in length of unit vectors and
in components of axis unit vectors (such as (0,0,1)).

*/

typedef int ON_OFF;

/*

The _setup model includes a stack array for the names of function
calls. This stack is written into if an error occurs. Just before each
function returns an error code, it writes its name in the next
available string, initializes the following string, and increments
the array index. The following four macros do the work.

The size of the stack array is 50. An error in the middle of a very
complex expression would cause the IFF macro to write past the
bounds of the array if a check were not provided. No real program
would contain such a thing, but the check is included to make the
macros totally crash-proof. If the function call stack is deeper than
49, the top of the stack will be missing.

*/

#define CHK(bad, error_code) if (bad) {             \
  _world.stack_index SET_TO 0;                      \
  strcpy(_world.stack[_world.stack_index++], name); \
  _world.stack[_world.stack_index][0] SET_TO 0;     \
  _world.status SET_TO error_code;                  \
  return error_code;                                \
  } else

#define IFF(try_this)                                      \
  if ((try_this) && (_world.status ISNT ISO14649_OK)) {    \
     if (_world.stack_index < 49)                          \
        {strcpy(_world.stack[_world.stack_index++], name); \
         _world.stack[_world.stack_index][0] SET_TO 0;}    \
     return _world.status;}                                \
  else

/*

The current_x, current_y, and current_z are the location of the tool
in the current coordinate system.  current_z is the position of the
tool tip in program coordinates when tool length compensation is using
the actual tool length; it is the position of the spindle when tool
length is zero.

The net origin offset uses both axis_offset values and origin_offset
values and is not represented here.

*/

typedef struct world_struct {
  executable * a_exec;               // current workingstep or nc_function
  int a_exec_index;                  // 0-based index in execs of a_exec
  workpiece * a_workpiece;           // current workpiece
  workplan * a_workplan;             // current workplan
  int action_flag;                   // flag for action in ISO14649_read 
  double change_x;                   // X coord of change, may be ROSE_NULL_R
  double change_y;                   // Y coord of change, may be ROSE_NULL_R
  CANON_MOTION_MODE control_mode;    // exact path or cutting mode
  int current_tool_index;            // index in tool_table of current tool
  double current_x;                  // current X-axis position, setup coords
  double current_y;                  // current Y-axis position, setup coords
  double current_z;                  // current Z-axis position, setup coords
  RoseDesign * design;               // pointer for open iso14649 file model
  int endfile;                       // non-zero means file is ended
  List (executable) * execs;         // list of all things to do in workplan
  int exit;                          // set to 1 when done, else 0
  axis2_placement_3d feature_place;  // feature location in machine coordinates
  ON_OFF feed_override;              // whether feed_override enabled
  double feedrate;                   // feed rate in current units/min
  char filename[ISO14649_TEXT_SIZE]; // name of currently open iso14649 file
  ON_OFF flood;                      // whether flood coolant is on
  ON_OFF mist;                       // whether mist coolant is on
  char name_text[ISO14649_TEXT_SIZE];// name of most recently exec'd worknstp
  plane * rapid_secplane;            // security plane for rapid, may be NULL
  double retracted_z;                // fully retracted z, setup coords
  double security_z_now;             // current security z, setup coords
  double security_z_setup;           // security z given in setup, setup coords
  double speed;                      // current spindle speed in rpm
  CANON_SPEED_FEED_MODE speed_feed_mode;   // independent or synched
  ON_OFF speed_override;             // whether speed override is enabled
  CANON_DIRECTION spindle_turning;   // direction spindle is turning
  char stack[50][80];                // stack of calls for error reporting
  int stack_index;                   // index into the stack
  int status;                        // status of last executed workingstep
  double tool_length_offset;         // current tool length offset
  int tool_max;                      // highest tool index
  CANON_TOOL_TABLE tool_table
       [CANON_TOOL_MAX + 1];         // description of current tools
  double traverse_rate;              // rate for traverse motions
  axis2_placement_3d * workpiece_place; // workpiece location, setup coords
} world;

/*************************************************************************/

/*

Interface functions to call to tell the interpreter what to do.
Return values indicate status of execution.
These functions may change the state of the interpreter.

*/

// Close the currently open iso14649 file.
extern int iso14649_close();

// Execute the next workingstep from the currently open iso14649 file.
extern int iso14649_execute();

// Stop running.
extern int iso14649_exit();

// Get ready to run.
extern int iso14649_init();

// Load a tool table.
extern int iso14649_load_tool_table();

// open an iso14649 file
// This will cause the entire file to be read into active memory.
extern int iso14649_open(const char *filename);

// Get the next workingstep of the open iso14649 file.
extern int iso14649_read();

// reset yourself
extern int iso14649_reset();

// synchronize your internal model with the external world
extern int iso14649_synch();


/*************************************************************************/

/*

Interface functions to call to get information from the interpreter.
If a function has a return value, the return value contains the information.
If a function returns nothing, information is copied into one of the
arguments to the function. These functions do not change the state of
the interpreter.

*/

// Copy the text of the error message whose number is error_code into the
// error_text array, but stop at max_size if the text is longer.
extern void iso14649_error_text(int error_code, char * error_text,
                                int max_size);

// Copy the name of the currently executing workingstep into the
// name_text array, but stop at max_size if the name is longer.
extern void iso14649_name_text(char * name_text, int max_size);

// Copy the name of the currently open file into the file_name array,
// but stop at max_size if the name is longer
extern void iso14649_file_name(char * file_name, int max_size);

// Copy information about what went on in the most recently executed
// workingstep into the action_text array, but stop at max_size if the
// text is longer. THIS NEEDS FURTHER DEFINITION.
extern void iso14649_current_action(char * action_text, int max_size);

// Copy the function name from the stack_index'th position of the
// function call stack at the time of the most recent error into
// the function name string, but stop at max_size if the name is longer
extern void iso14649_stack_name(int stack_index, char * function_name,
                                int max_size);

#endif /* #ifndef ISO14649_HH */
