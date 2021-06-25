#pragma once


typedef enum {CANON_PLANE_XY=1, CANON_PLANE_YZ, CANON_PLANE_XZ} CANON_PLANE;
typedef enum {CANON_UNITS_INCHES=1, CANON_UNITS_MM, CANON_UNITS_CM} CANON_UNITS;
typedef enum {CANON_EXACT_STOP=1, CANON_EXACT_PATH, CANON_CONTINUOUS}
             CANON_MOTION_MODE;
typedef enum {CANON_SYNCHED=1, CANON_INDEPENDENT} CANON_SPEED_FEED_MODE;
typedef enum {CANON_STOPPED, CANON_CLOCKWISE, CANON_COUNTERCLOCKWISE}
             CANON_DIRECTION;
typedef enum {CANON_WORKPIECE=1, CANON_XYZ} CANON_FEED_REFERENCE;
typedef enum {CANON_SIDE_RIGHT=1, CANON_SIDE_LEFT, CANON_SIDE_OFF} CANON_SIDE;
typedef enum {CANON_AXIS_X=1, CANON_AXIS_Y, CANON_AXIS_Z, CANON_AXIS_A,
              CANON_AXIS_B, CANON_AXIS_C} CANON_AXIS;

struct CANON_VECTOR
{
  CANON_VECTOR() {}
  CANON_VECTOR(double _x, double _y, double _z) {x = _x; y = _y; z = _z;}
  double x, y, z;
};

struct CANON_POSITION
{
  CANON_POSITION() {}
  CANON_POSITION(double _x, double _y, double _z)
  {
    x = _x; y = _y; z = _z;
  }
  double x, y, z;
};


#define CANON_TOOL_MAX 128      // max number of tools handled
#define CANON_TOOL_ENTRY_LEN 256 // how long each file line can be

struct CANON_TOOL_TABLE
{
  char id[80];       /* TK changed Dec 2002, was int */
  double length;     /* use this for tool length offset */
  double diameter;
};
extern void INIT_CANON();
extern void SET_ORIGIN_OFFSETS(double x, double y, double z);
extern void USE_LENGTH_UNITS(CANON_UNITS u);
extern void SELECT_PLANE(CANON_PLANE pl);
extern void SET_TRAVERSE_RATE(double rate);
extern void STRAIGHT_TRAVERSE(double x, double y, double z);
extern void SET_FEED_RATE(double rate);
extern void SET_FEED_REFERENCE(CANON_FEED_REFERENCE reference);
extern void SET_MOTION_CONTROL_MODE(CANON_MOTION_MODE mode);
extern void SET_CUTTER_RADIUS_COMPENSATION(double radius);
extern void START_CUTTER_RADIUS_COMPENSATION(int direction);
extern void STOP_CUTTER_RADIUS_COMPENSATION();
extern void START_SPEED_FEED_SYNCH();
extern void STOP_SPEED_FEED_SYNCH();
extern void ARC_FEED(
					 double first_end,
					 double second_end,
					 double first_axis,
					 double second_axis,
					 int rotation,
					 double axis_end_point);  
extern void STRAIGHT_FEED(double x, double y, double z);
extern void STRAIGHT_PROBE (double x, double y, double z);
extern void STOP();
extern void DWELL(double seconds);
extern void SPINDLE_RETRACT_TRAVERSE();
extern void START_SPINDLE_CLOCKWISE();
extern void START_SPINDLE_COUNTERCLOCKWISE();
extern void SET_SPINDLE_SPEED(double r);
extern void STOP_SPINDLE_TURNING();
extern void SPINDLE_RETRACT();
extern void ORIENT_SPINDLE(double orientation, CANON_DIRECTION direction);
extern void LOCK_SPINDLE_Z();
extern void USE_SPINDLE_FORCE();
extern void USE_NO_SPINDLE_FORCE();
extern void USE_TOOL_LENGTH_OFFSET(double length);
extern void CHANGE_TOOL(char * tool_id);
extern void SELECT_TOOL(char * tool_id);
extern void CLAMP_AXIS(CANON_AXIS axis);
extern void COMMENT(char *s);
extern void DISABLE_FEED_OVERRIDE();
extern void ENABLE_FEED_OVERRIDE();
extern void DISABLE_SPEED_OVERRIDE();
extern void ENABLE_SPEED_OVERRIDE();
extern void FLOOD_OFF();
extern void FLOOD_ON();
extern void MESSAGE(char *s);
extern void MIST_OFF();
extern void MIST_ON();
extern void PALLET_SHUTTLE();
extern void TURN_PROBE_OFF();
extern void TURN_PROBE_ON();
extern void UNCLAMP_AXIS(CANON_AXIS axis);
extern void NURB_KNOT_VECTOR(); /* double knot values, -1.0 signals done */
extern void NURB_CONTROL_POINT(int i, double x, double y, double z, double w );
extern void NURB_FEED(double sStart, double sEnd);
extern void OPTIONAL_PROGRAM_STOP();
extern void PROGRAM_END();
extern void PROGRAM_STOP();
extern double GET_EXTERNAL_ANGLE_UNIT_FACTOR();
extern double GET_EXTERNAL_FEED_RATE();
extern int GET_EXTERNAL_FLOOD();
extern double GET_EXTERNAL_LENGTH_UNIT_FACTOR();
CANON_UNITS GET_EXTERNAL_LENGTH_UNIT_TYPE();
extern int GET_EXTERNAL_MIST();
extern CANON_MOTION_MODE GET_EXTERNAL_MOTION_CONTROL_MODE();
extern CANON_TOOL_TABLE _tools[];   /* in canon.cc */
extern int _tool_max;               /* in canon.cc */

class CCanonCmds
{
public:
	CCanonCmds(void);
	~CCanonCmds(void);
};
