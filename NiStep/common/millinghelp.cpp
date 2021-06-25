description[_T("milling_cutting_tool.description")]=_T("");

description[_T("milling_cutting_tool.direction_for_spindle_orientation.description")]=_T("");

description[_T("milling_cutting_tool.tool_holder_diameter_for_spindle_orientation.description")]=_T("");

description[_T("milling_tool_body.description")]=_T("");

description[_T("milling_tool_body.dimension.description")]=_T("");

description[_T("milling_tool_body.number_of_teeth.description")]=_T("");

description[_T("milling_tool_body.hand_of_cut.description")]=_T("");

description[_T("milling_tool_body.coolant_through_tool.description")]=_T("");

description[_T("milling_tool_body.pilot_length.description")]=_T("");

description[_T("milling_tool_dimension.description")]=_T("");

description[_T("milling_tool_dimension.diameter.description")]=_T("");

description[_T("milling_tool_dimension.tool_top_angle.description")]=_T("");

description[_T("milling_tool_dimension.tool_circumference_angle.description")]=_T("");

description[_T("milling_tool_dimension.cutting_edge_length.description")]=_T("");

description[_T("milling_tool_dimension.edge_radius.description")]=_T("");

description[_T("milling_tool_dimension.edge_center_vertical.description")]=_T("");

description[_T("milling_tool_dimension.edge_center_horizontal.description")]=_T("");

description[_T("center_drill.description")]=_T("");

description[_T("countersink.description")]=_T("");

description[_T("countersink.countersink_radius.description")]=_T("");

description[_T("backside_countersink.description")]=_T("");

description[_T("drill.description")]=_T("");

description[_T("twist_drill.description")]=_T("");

description[_T("tapered_drill.description")]=_T("");

description[_T("tapered_drill.taper_angle.description")]=_T("");

description[_T("spade_drill.description")]=_T("");

description[_T("milling_cutter.description")]=_T("");

description[_T("facemill.description")]=_T("");

description[_T("endmill.description")]=_T("");

description[_T("tapered_endmill.description")]=_T("");

description[_T("tapered_endmill.taper_angle.description")]=_T("");

description[_T("ball_endmill.description")]=_T("");

description[_T("bullnose_endmill.description")]=_T("");

description[_T("t_slot_mill.description")]=_T("");

description[_T("t_slot_mill.cutting_thickness.description")]=_T("");

description[_T("dovetail_mill.description")]=_T("");

description[_T("dovetail_mill.included_angle.description")]=_T("");

description[_T("woodruff_keyseat_mill.description")]=_T("");

description[_T("woodruff_keyseat_mill.cutter_width.description")]=_T("");

description[_T("side_mill.description")]=_T("");

description[_T("side_mill.cutter_width.description")]=_T("");

description[_T("thread_mill.description")]=_T("");

description[_T("tap.description")]=_T("");

description[_T("tapered_tap.description")]=_T("");

description[_T("tapered_tap.taper_angle.description")]=_T("");

description[_T("combined_drill_and_tap.description")]=_T("");

description[_T("combined_drill_and_tap.drill_length.description")]=_T("");

description[_T("threading_tool.description")]=_T("");

description[_T("counterbore.description")]=_T("");

description[_T("backside_counterbore.description")]=_T("");

description[_T("reamer.description")]=_T("");

description[_T("tapered_reamer.description")]=_T("");

description[_T("tapered_reamer.taper_angle.description")]=_T("");

description[_T("combined_drill_and_reamer.description")]=_T("");

description[_T("combined_drill_and_reamer.drill_length.description")]=_T("");

description[_T("boring_tool.description")]=_T("");

description[_T("user_defined_tool.description")]=_T("");

description[_T("user_defined_tool.identifier.description")]=_T("");

description[_T("exchange_pallet.description")]=_T("This function is used to execute a pallet exchange.");

description[_T("index_pallet.description")]=_T("This function is used to place the pallet to the indicated position by the parameter index.");

description[_T("index_pallet.its_index.description")]=_T("The parameter index value by which the destined position of the pallet is indicated.");

description[_T("index_table.description")]=_T("This function is used to place the rotation table to the indicated position by the parameter index.");

description[_T("index_table.its_index.description")]=_T("The parameter index value by which the destined position of the rotation table is indicated.");

description[_T("load_tool.description")]=_T("This function is used to load a tool that can be seleted independent from the geometrical information.");

description[_T("load_tool.its_tool.description")]=_T("The tool which has to be loaded.");

description[_T("unload_tool.description")]=_T("This function is used to unload a tool.");

description[_T("unload_tool.its_tool.description")]=_T("The tool which has to be exchanged. In case of an operation where more than one tool is in use at the same time this attribute has to be set.");

description[_T("tool_direction_for_milling.description")]=_T("This is the base class of all tool orientations used for freeform machining. It is subtypes of entity tool_direction defined in ISO 14649-10.");

description[_T("three_axes_tilted_tool.description")]=_T("In this mode of operation, the tool is tilted, so the tool direction is not parallel to any of the three machine axes. However, the tool is clamped to fix the tool angle and motion is still only in the three linear axes. Unlike five_axes_var_tilt_yaw the tilt and/or yaw angles are not variable.");

description[_T("three_axes_tilted_tool.tool_direction.description")]=_T("The direction of the tool in absolute machine co-ordinates.");

description[_T("five_axes_var_tilt_yaw.description")]=_T("Simultaneous tool movements in five axes are used for machining. During motion, the tool direction is adjusted so as to follow the curve given in the toolpath instances.");

description[_T("five_axes_const_tilt_yaw.description")]=_T("This is a special case of five_axes_var_tilt_yaw. The tool is moved so that the tilt and yaw angles are constant in each point of the toolpath, relative to the co-ordinate system given by the surface normal in the cutter contact point and the tangent in feed direction. Tilt and yaw are given as attributes of this entity. Note that these values may be overridden if an explicit tool direction curve is specified for a toolpath.");

description[_T("five_axes_const_tilt_yaw.tilt_angle.description")]=_T("The inclination of the tool in feed direction, measured against the surface normal in the cutter contact point.");

description[_T("five_axes_const_tilt_yaw.yaw_angle.description")]=_T("The rotation of the inclined tool around the surface normal, measured against the surface tangent in feed direction in the cutter contact point.");

description[_T("milling_machining_operation.description")]=_T("This is the base class of all operations described in this part of ISO 14649. It is a subtype of entity machining_operation defined in ISO 14649-10. In case that feedrate_per_tooth of its_technology is chosen, number_of_teeth of its_tool_body of its_tool should be given.");

description[_T("milling_machining_operation.overcut_length.description")]=_T("The overcut on the open side(s) of the feature. It is not allowed for manufacturing of features which are bounded by material on all sides, i. e. pockets. In case of round_hole, this attribute is allowed only for through-bottom holes. If the cutting_depth of drilling_type_operation specifies a conflicting value, overcut_ length is ignored.");

description[_T("milling_technology.description")]=_T("This entity defines the technological parameters of the milling operation. It is a subtype of entity technology defined in ISO 14649-10. Of the four alternatives for specifying speeds, exactly two must be given as indicated by the WHERE rules. If the attribute adaptive_control s invoked, some or all of these values may be ignored.");

description[_T("milling_technology.cutspeed.description")]=_T("Cutting speed of the tool, the speed of spindle converted into a linear speed.");

description[_T("milling_technology.spindle.description")]=_T("Rotational speed of the tool. As defined for rot_speed_measure, positive values indicate tool rotation in mathematical positive direction of the c axis, i. e. counterclockwise motion if looking from the tool holder to the workpiece. Note that usual cutting tools require clockwise motion so the value of this attribute will typically be negative.");

description[_T("milling_technology.feedrate_per_tooth.description")]=_T("Feed of the tool expressed as a distance.");

description[_T("milling_technology.synchronize_spindle_with_feed.description")]=_T("If true, cutting speed and feed of the tool is synchronised. Therefore, the pitch of tap can be kept constant at the bottom of a hole when cutting speed is being decelerated and accelerated.");

description[_T("milling_technology.inhibit_feedrate_override.description")]=_T("If true, the feedrate override through the operating panel or by adaptive control systems is not allowed.");

description[_T("milling_technology.inhibit_spindle_override.description")]=_T("If true, the spindle speed override through the operating panel or by adaptive control systems is not allowed.");

description[_T("milling_technology.its_adaptive_control.description")]=_T("Any kind of vendor specific adaptive control strategy.");

description[_T("adaptive_control.description")]=_T("This entity defines the vendor-specific adaptive control strategy. At a later time, the specific nature of the adaptive control algorithm and further parameters can be specified in appropriate subtypes.");

description[_T("milling_machine_functions.description")]=_T("The entity describes the state of various functions of the machine, like coolant, chip removal, etc. to be applied during the time span of an operation. It is a subtype of entity machine_functions defined in ISO 14649-10.");

description[_T("milling_machine_functions.coolant.description")]=_T("If true, the coolant is activated.");

description[_T("milling_machine_functions.coolant_pressure.description")]=_T("Optional specification of the pressure of the coolant system. Only valid if coolant is true.");

description[_T("milling_machine_functions.mist.description")]=_T("If true, activate mist coolant. Default is false. Only valid if coolant is true.");

description[_T("milling_machine_functions.through_spindle_coolant.description")]=_T("If true, activate coolant through the spindle. Default is false.");

description[_T("milling_machine_functions.through_pressure.description")]=_T("Pressure of coolant through the spindle. Only valid if through_spindle_coolant is true.");

description[_T("milling_machine_functions.axis_clamping.description")]=_T("Describes which axes are to be clamped, e.g. X,Y,A. Note that this information is machine dependent and should be avoided.");

description[_T("milling_machine_functions.chip_removal.description")]=_T("If true, activate chip removal.");

description[_T("milling_machine_functions.oriented_spindle_stop.description")]=_T("If specified, the spindle will stop in the given direction relative to the machine zero position of C-axis in case a spindle stop occurs during or at the end of the workingstep.");

description[_T("milling_machine_functions.its_process_model.description")]=_T("Optional information for process control.");

description[_T("milling_machine_functions.other_functions.description")]=_T("Optional list of other functions of generic type.");

description[_T("process_model_list.description")]=_T("For each workingstep, one or more process models may be started. These are modules for process control like chatter avoidance, thermal compensation, etc.");

description[_T("process_model_list.its_list.description")]=_T("List of process models for the current workingstep");

description[_T("process_model.description")]=_T("Special machine-specific functions to make the machining process more secure and accurate. (e.g. chatter avoidance, thermal compensation, ...)");

description[_T("process_model.ini_data_file.description")]=_T("A filename including path of the file containing the initialisation data of the process model.");

description[_T("process_model.its_type.description")]=_T("The type of process model (e.g. chatter avoidance, thermal compensation, ...)");

description[_T("milling_type_operation.description")]=_T("This is the base class of all operations for milling. It includes all necessary attributes to describe technology and strategy. It is a subtype of entity milling_machining_operation. In general, there are two types of machining operations: roughing and finishing. The roughing is to remove all material from the original raw piece surface down to the bottom or side of the feature minus the finishing allowance in multiple passes. The finishing will then remove the finish allowance to yield the final surface of the feature. In case of pre-cast features, e.g. pre-cast holes and pockets, roughing operation need to be one");

description[_T("milling_type_operation.approach.description")]=_T("By default, the NC controller decides about the approach strategy. It may decide not to use any approach movement at all if the start point of cutting coincides with the end point of cutting for the preceding operation. If its_toolpath is given, this attribute will be ignored.");

description[_T("milling_type_operation.retract.description")]=_T("Optional information about retract strategy after finishing the last cut. By default, the NC controller decides about the retract strategy. It may decide not to use any retract movement at all if the end point of cutting coincides with the start point of cutting for the next operation. If its_toolpath is given, this attribute will be ignored.");

description[_T("approach_retract_strategy.description")]=_T("Base class for the approach (plunge) and retract strategy. All approach and retract strategies are defined relative to the start or end point of the cutting operation, whether this is explicitly given in the operation of determined by the NC controller. The resulting start point of the approach or end point of the retract movement are defined to be the start and end point of the current operation. The feed rate on the approach or retract path is the feed rate specified for the related start or end point, respectively, of cutting.");

description[_T("approach_retract_strategy.tool_orientation.description")]=_T("Only for machines with five-axis positioning capabilities. This specified the tool orientation at the beginning or end, respectively, of the approach or retract movement.");

description[_T("plunge_strategy.description")]=_T("This is the base class for all approach movements which include cutting of material. This is typically the case for pocketing operations where the approach to the depth of the first cutting layer or between cutting layers requires the removal of material in order to create the approach path. All plunge movements are guaranteed to occur within the boundaries of the underlying feature. All plunge movements will start at the retract plane valid for the current operation. They will end in the start point of the cutting operation, with the tangent of its approach path coinciding with the tangent of the ensuing cutting motion.");

description[_T("plunge_toolaxis.description")]=_T("Plunge in the direction of the tool axis.");

description[_T("plunge_ramp.description")]=_T("Plunge on a linear path which forms an angle with the feature surface.");

description[_T("plunge_ramp.angle.description")]=_T("The angle of the ramp movement versus the surface in the end point of the approach.");

description[_T("plunge_helix.description")]=_T("Plunge movement forming a helix. The path is defined by specifying the radius and grade of the helix. A circular movement can be specified by setting grade to zero.");

description[_T("plunge_helix.radius.description")]=_T("Radius of the helical movement.");

description[_T("plunge_helix.angle.description")]=_T("The angle of the helical movement versus the surface in the end point of the approach.");

description[_T("plunge_zigzag.description")]=_T("Plunge movement using a zigzag motion. This is similar to the ramp-type movement, except the cutter changes direction if it touches a feature boundary or if the path length would exceed the specified width of the zigzag pattern.");

description[_T("plunge_zigzag.angle.description")]=_T("The angle of the movement versus the surface in the end point of the approach.");

description[_T("plunge_zigzag.width.description")]=_T("The with of the zigzag path perpendicular to the direction of the descent.");

description[_T("air_strategy.description")]=_T("This is the base class for all approach or retract movements through the air. Unlike the plunge_strategy types these movements are not limited to the inside of the feature. All of these movements shall take place in a plane which is defined by the normal of the machined feature and the tangent of the cutting path in the start or end point, respectively, of the related cutting movement. If the start or end point lies at the intersection of two planes, as may be the case for bottom_and_side_milling operations, the surface normal is deemed to be the intermediate direction between the two normals.");

description[_T("ap_retract_angle.description")]=_T("The movement is heading towards the start or from the end point in an angle to the surface. For plane milling, this may typically be an angle of 0 degrees in order to move straight from outside the workpiece into the material.");

description[_T("ap_retract_angle.angle.description")]=_T("Approach or lift angle versus the surface in the end point of the approach or the start point of the lift, respectively.");

description[_T("ap_retract_angle.travel_length.description")]=_T("The length of the angular approach. After travel_length has been reached, the tool will proceed to the retract plane using the shortest connection and vice versa.");

description[_T("ap_retract_tangent.description")]=_T("The movement is heading towards the start or from the end point in a curve. The motion start or ends in the retract plane valid for the current operation. If the specified radius for this motion is smaller than the distance to the retract plane as specified in the attribute retract_plane of the current operation, the remaining path will be executed in linear motion perpendicular to the retract plane.");

description[_T("ap_retract_tangent.radius.description")]=_T("The radius of the approach or retract movement.");

description[_T("along_path.description")]=_T("Approach or lift movement on a general path. This should be used if full control of the tool orientation during approach is required or for other special purposes.");

description[_T("along_path.path.description")]=_T("Specification of a general path for approach or lift movement. Note that the path is specified in a special co-ordinate system. The origin is the start or end point of the cutting operation, the axes are oriented like the local co-ordinate system of the feature.");

description[_T("freeform_operation.description")]=_T("Derived from the milling type operation, this is the class of operations for freeform milling. Note that only some Hi- Tech NC controllers today will not be able to machine a freeform surface without specifying explicit toolpaths.");

description[_T("freeform_operation.its_machining_strategy.description")]=_T("Description of the strategy to be used when executing the operation. In case the attribute its_toolpath of the supertype operation is specified, the strategy is for information only.");

description[_T("freeform_strategy.description")]=_T("The following entities define the strategy used for milling a freeform surface. If this entity is used, the toolpath is defined only by means of the milling strategy and the tolerances. The CNC itself has to calculate the resulting toolpaths out of these values. If the toolpath and the freeform strategy are defined, the attribute \")freeform_strategy\" is for information only.");

description[_T("freeform_strategy.pathmode.description")]=_T("The feed direction");

description[_T("freeform_strategy.cutmode.description")]=_T("The stepover direction.");

description[_T("freeform_strategy.its_milling_tolerances.description")]=_T("The tolerance values to be used during creation of the toolpaths.");

description[_T("freeform_strategy.stepover.description")]=_T("The distance between two neighboring toolpaths. If given, the stepover calculated by use of its_milling_tolerances will be ignored.");

description[_T("tolerances.description")]=_T("The tolerances which are associated with the free form operation. This does not refer to the general manufacturing tolerances but specifies two parameter which are needed if the NC controllers generates toolpaths for free-form surfaces. Through these values the stepover distance between the toolpaths can be derived.");

description[_T("tolerances.chordal_tolerance.description")]=_T("Geometric error resulting from a linear approximation of a curve.");

description[_T("tolerances.scallop_height.description")]=_T("Height of the grooves caused by the tool radius");

description[_T("uv_strategy.description")]=_T("Milling follows the parameter lines in the local (u,v) coordinate system.");

description[_T("uv_strategy.forward_direction.description")]=_T("The direction used in the first cut.");

description[_T("uv_strategy.sideward_direction.description")]=_T("The direction in which the second cut is offset from the first.");

description[_T("plane_cc_strategy.description")]=_T("The paths are generated by intersecting the target surface with parallel planes. The result of these intersections form the cutter contact paths.");

description[_T("plane_cc_strategy.its_plane_normal.description")]=_T("The normal of the planes used for intersection with the target surface.");

description[_T("plane_cl_strategy.description")]=_T("The paths are generated by intersecting the target surface, offset by the cutter radius, with planes. The result form the cutter location paths. This strategy makes sense with ball end and bullnose cutters.");

description[_T("plane_cl_strategy.its_plane_normal.description")]=_T("The normal of the planes used for intersection with the target surface");

description[_T("leading_line_strategy.description")]=_T("The toolpaths are calculated by projecting a curve on the workpiece surface along the Z-axis of local coordinate system. The curve is given as an attribute.");

description[_T("leading_line_strategy.its_line.description")]=_T("The curve used to calculate the toolpaths.");

description[_T("two5d_milling_operation.description")]=_T("This is the base class of all operations for 2½D milling derived from milling_type_operation.");

description[_T("two5d_milling_operation.its_machining_strategy.description")]=_T("Description of the strategy to be used when executing the operation. In case the attribute its_toolpath of the supertype operation is specified, the strategy is for information only.");

description[_T("two5d_milling_strategy.description")]=_T("This is the base class of all strategies used for creating 2½D milling toolpaths");

description[_T("two5d_milling_strategy.overlap.description")]=_T("The overlap in the path between two neighbouring cutting movements as percentage of the tool diameter.");

description[_T("two5d_milling_strategy.allow_multiple_passes.description")]=_T("Optional flag only for roughing workingsteps. If true, this is the standard roughing operation with multiple passes, i. e. several layers of material are removed sequentially, taking into account the maximum cutting depth. If false, this is the special roughing operation for pre-cast features with one pass. Default is true.");

description[_T("unidirectional.description")]=_T("Milling in a linear fashion, i.e. going from one side to the other, then lifting the tool and going back to the starting point. In this way, the cutting mode (conventional or climb cutting) is not changed like it is in bidirectional milling. The step over direction is automatically derived from feed_direction and cutmode.");

description[_T("unidirectional.feed_direction.description")]=_T("Feed direction of the milling operation. The attribute cutmode, if given, takes precedence over this attribute.");

description[_T("unidirectional.cutmode.description")]=_T("Specifies whether conventional or climb cutting should be used. Default is conventional.");

description[_T("bidirectional.description")]=_T("Milling in a zigzag fashion, i.e. going from one side to the other and back. For further describing the strategy of milling, it may be specified, which are the first and second directions for zigzagging. The cutting mode (conventional or climb cutting) is alternated.");

description[_T("bidirectional.feed_direction.description")]=_T("Feed direction of the first toolpath of the milling operation");

description[_T("bidirectional.stepover_direction.description")]=_T("Stepover direction of the zigzag operation");

description[_T("bidirectional.its_stroke_connection_strategy.description")]=_T("Specification of the behaviour of the tool between strokes");

description[_T("contour_parallel.description")]=_T("Milling in several paths following the contour of the feature. A typical strategy for pocket milling. The step over direction (outside_in or inside_out) is automatically derived from rotation_direction and cutmode.");

description[_T("contour_parallel.rotation_direction.description")]=_T("Direction of the spiral (clockwise or counterclockwise) as seen from the top of the feature. The default is counterclockwise. The attribute cutmode, if given, takes precedence over this attribute.");

description[_T("contour_parallel.cutmode.description")]=_T("Specifies whether conventional or climb cutting should be used. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of of pocket and possible bosses.");

description[_T("bidirectional_contour.description")]=_T("Milling of the contour in bidirectional fashion first, then one final contour-parallel path on the very outside of the feature.");

description[_T("bidirectional_contour.feed_direction.description")]=_T("Feed direction of the first toolpath of the milling operation. The attribute first_cutmode, if given, takes precedence over this attribute.");

description[_T("bidirectional_contour.stepover_direction.description")]=_T("Stepover direction of the zigzag operation.");

description[_T("bidirectional_contour.rotation_direction.description")]=_T("Direction of the spiral (clockwise or counterclockwise) for the final cut as seen from the top of the feature. The default is counterclockwise. The attribute spiral_cutmode, if given, takes precedence over this attribute.");

description[_T("bidirectional_contour.spiral_cutmode.description")]=_T("Specifies whether conventional or climb cutting should be used on the final cut. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of pocket and possible bosses.");

description[_T("contour_bidirectional.description")]=_T("Milling of a contour parallel path on the very outside of the contour first, then bidirectional milling of the remaining center.");

description[_T("contour_bidirectional.feed_direction.description")]=_T("Feed direction of the first toolpath of the zigzag operation. The attribute first_cutmode, if given, takes precedence over this attribute.");

description[_T("contour_bidirectional.stepover_direction.description")]=_T("Stepover direction of the zigzag operation.");

description[_T("contour_bidirectional.rotation_direction.description")]=_T("Direction of the spiral (clockwise or counterclockwise) for the final cut as seen from the top of the feature. The default is counterclockwise. The attribute spiral_cutmode, if given, takes precedence over this attribute.");

description[_T("contour_bidirectional.spiral_cutmode.description")]=_T("Specifies whether conventional or climb cutting should be used. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of pocket and possible bosses.");

description[_T("contour_spiral.description")]=_T("Contour spiral milling is similar to contour parallel milling, with the exception, that in this case the milling path is a truly spiral path rather than concentric paths which are connected by a orthogonal movement. The step over direction (outside_in or inside_out) is automatically derived from rotation_direction and cutmode.");

description[_T("contour_spiral.rotation_direction.description")]=_T("The direction of the spiral path (clockwise or counterclockwise) as seen from the top of the feature. The default is counterclockwise. The attribute cutmode, if given, takes precedence over this attribute.");

description[_T("contour_spiral.cutmode.description")]=_T("Specifies whether conventional or climb cutting should be used. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of of pocket and possible bosses.");

description[_T("center_milling.description")]=_T("This entity describes a milling strategy along the center of the feature. This is used e.g. for milling along the center of a slot.");

description[_T("explicit.description")]=_T("Any two5D strategy which can not be described using any of the above given types can be specified using explicit. In this case, an exact definition of all movements needs to be given in the attribute its_toolpath of the entity workingstep.");

description[_T("plane_milling.description")]=_T("Entity to describe the milling of a plane. This is the supertype for roughing and finishing operations.");

description[_T("plane_milling.axial_cutting_depth.description")]=_T("The cutting depth in the direction of the tool axis. This can be given to specify a maximal cutting depth smaller than the material removal required by the feature’s depth. As a result, several layers will be manufactured. If omitted, the selected cutting depth will be implementation dependent.");

description[_T("plane_milling.allowance_bottom.description")]=_T("The allowance is a layer of material which will be left on top of the plane surface defined by the associated manufacturing feature.");

description[_T("plane_rough_milling.description")]=_T("Roughing operation for milling. All material inside the manufacturing feature will be removed using the given tool, except for the allowance_bottom.");

description[_T("plane_finish_milling.description")]=_T("Finishing operation for milling. All material inside the manufacturing feature will be removed, applying an appropriate strategy to maintain the given tolerances. If allowance_bottom is given, other special operation like grinding shall be applied for removing the material left.");

description[_T("side_milling.description")]=_T("Entity to describe a side milling process during which material is removed along the flank of the tool.");

description[_T("side_milling.axial_cutting_depth.description")]=_T("The cutting depth in the direction of the tool axis. See plane milling.");

description[_T("side_milling.radial_cutting_depth.description")]=_T("The cutting depth perpendicular to the tool axis. This can be used to limit the chip thickness. If radial_cutting_depth is smaller than the radial material removal required by the feature, this will cause the execution of the operation in several layers.");

description[_T("side_milling.allowance_side.description")]=_T("The allowance is a layer of material which will be left on side of the surface defined by the associated manufacturing feature.");

description[_T("side_rough_milling.description")]=_T("Roughing operation for side milling. All material inside the manufacturing feature will be removed using the given tool, except for the allowance_side");

description[_T("side_finish_milling.description")]=_T("Finishing operation for side milling. All material inside the manufacturing feature will be removed, applying an appropriate strategy to maintain the given tolerances. If allowance_side is given, other special operation like grinding shall be applied for removing the material left.");

description[_T("bottom_and_side_milling.description")]=_T("Entity to describe a combined bottom and side milling process.");

description[_T("bottom_and_side_milling.axial_cutting_depth.description")]=_T("The cutting depth in the direction of the tool. See plane milling.");

description[_T("bottom_and_side_milling.radial_cutting_depth.description")]=_T("The cutting depth perpendicular to the tool, used in side milling. See side milling.");

description[_T("bottom_and_side_milling.allowance_side.description")]=_T("The allowance is a layer of material which will be left on side of the surface defined by the associated manufacturing feature.");

description[_T("bottom_and_side_milling.allowance_bottom.description")]=_T("The allowance is a layer of material which will be left on top of the plane surface defined by the associated manufacturing feature.");

description[_T("bottom_and_side_rough_milling.description")]=_T("Roughing operation for a combined bottom and side milling workingstep. All material inside the manufacturing feature will be removed using the given tool, except for the allowance_side and allowance_bottom.");

description[_T("bottom_and_side_finish_milling.description")]=_T("Finishing operation for a combined bottom and side milling workingstep. All material inside the manufacturing feature will be removed, applying an appropriate strategy to maintain the given tolerances. If allowance_side and allowance_bottom are given, other special operation like grinding shall be applied for removing the material left.");

description[_T("drilling_type_operation.description")]=_T("This is the base class for all operations concerned with drilling a hole, reaming, sinking, etc. It is a subtype of entity milling_machining_operation. Cutting of a thread is included here also. The base class provides all necessary attributes to describe technology and strategy for drilling type operations. In case of pre-cast holes, the predrilling can be operated before the finish drilling by means of specifying a drilling depth (and an appropriate tool) which is smaller than that of the feature. Subsequent drilling operations can specify the attribute previous_diameter appropriately to allow for the already removed material. The start point is given by the inherited attributes retract_plane and cut_start_point. If cut_start_point is omitted, the centre of the underlying feature will be used instead. From there the tool will advance with drilling feed along the local z axis. Using the prescribed strategy, the tool will drill to the depth of the associated feature, for through holes applying an inherited attribute overcut_length. For pre-drilling operations, the attribute cutting_depth can be used to reduce the depth of a cut to an amount smaller than the hole’s depth. On retract, the tool will return to the retract plane using the drilling feed, or – if specified – the feed_on_retract given by drilling_type_strategy.");

description[_T("drilling_type_operation.cutting_depth.description")]=_T("The depth of the cut of this operation, which may differ from the depth of the hole as such. The NC controller will not check if cutting_depth violates the boundaries of the associated hole feature. If omitted, the total depth of the feature will be drilled. In case of center drilling operation, the cutting_depth is measured from the lowest point of the cutting tip to the highest point of the hole. In other cases, it is measured from the starting point of cylindrical part of the tool.(Or, tapered cylindrical part in case of tapered drill.)");

description[_T("drilling_type_operation.previous_diameter.description")]=_T("If the operation is performed on a pre-drilled or pre-cast hole, this value, if given, specifies the diameter of the existing hole. It thus describes the amount of material which the tool as to remove and is for information only.");

description[_T("drilling_type_operation.dwell_time_bottom.description")]=_T("Possible dwell time at the bottom of the hole.");

description[_T("drilling_type_operation.feed_on_retract.description")]=_T("Feed used for retract to the retract_plane as ratio of the drilling feed. If not specified, the drilling feed is used.");

description[_T("drilling_type_operation.its_machining_strategy.description")]=_T("Description of the strategy to be used when executing the operation. In case the attribute its_toolpath of the supertype operation is specified, the strategy is for information only.");

description[_T("drilling_type_strategy.description")]=_T("This is the specification of a dedicated strategy for drilling. For drilling, this mainly refers to a variation of cutting speed and feed along the movement of the tool.");

description[_T("drilling_type_strategy.reduced_cut_at_start.description")]=_T("Reduced cutting speed at the beginning of the cut as a percentage of the programmed value.");

description[_T("drilling_type_strategy.reduced_feed_at_start.description")]=_T("Reduced feed at the beginning of the cut as a percentage of the programmed value.");

description[_T("drilling_type_strategy.depth_of_start.description")]=_T("Depth to which the reduced values at the start are valid.");

description[_T("drilling_type_strategy.reduced_cut_at_end.description")]=_T("Reduced cutting speed at the end of the cut as a percentage of the programmed value.");

description[_T("drilling_type_strategy.reduced_feed_at_end.description")]=_T("Reduced feed at the end of the cut as a percentage of the programmed value.");

description[_T("drilling_type_strategy.depth_of_end.description")]=_T("Depth from which the reduced values at the end are valid.");

description[_T("drilling_operation.description")]=_T("Base class for drilling operation concerned with drilling, center drilling, counter sinking, and multistep drilling.");

description[_T("drilling.description")]=_T("Workingstep for drilling a regular hole.");

description[_T("center_drilling.description")]=_T("Workingstep for centering a hole.");

description[_T("counter_sinking.description")]=_T("Workingstep for counter sinking a hole.");

description[_T("multistep_drilling.description")]=_T("Workingstep for drilling of deep holes in multiple steps.");

description[_T("multistep_drilling.retract_distance.description")]=_T("If retract_distance is a positive value, the tool is retracted this value between steps to enable chip breaking. If it is zero or negative, the tool is retracted to the retract plane between steps to clear the hole of chips.");

description[_T("multistep_drilling.first_depth.description")]=_T("Depth of the first step.");

description[_T("multistep_drilling.depth_of_step.description")]=_T("Depth of each additional step (repeated until the depth of the hole is reached).");

description[_T("multistep_drilling.dwell_time_step.description")]=_T("Dwell time between steps.");

description[_T("boring_operation.description")]=_T("Base class for boring operation concerned with boring and reaming. The spindle orientation at the bottom should be given.");

description[_T("boring_operation.spindle_stop_at_bottom.description")]=_T("Possible spindle stop at the bottom of the hole. If the attribute oriented_spindle_stop in the workingstep’s technology is set, this will cause an oriented spindle stop.");

description[_T("boring_operation.depth_of_testcut.description")]=_T("Depth of a testcut after which the hole is measured.");

description[_T("boring_operation.waiting_position.description")]=_T("A waiting position for the tool i.e. to allow measuring. The tool moves out of the hole along the tool axis until it reaches the plane of the waiting_position. It then moves to the waiting position itself.");

description[_T("boring.description")]=_T("Workingstep for boring a hole.");

description[_T("reaming.description")]=_T("Workingstep for reaming a hole.");

description[_T("back_boring.description")]=_T("Workingstep for back boring a hole. Backboring is the cutting of the back plane of a through bottom hole. After the tool is positioned at the start point, the spindle stops at the direction_of_spindle_orientation specified as an attribute of milling_cutting_tool. The tool is shifted in the opposite of direction_of_spindle_orientation in order to path through the hole with rapid traverse. At the bottom of the hole, it returns to the cutting position for the shifted value and the spindle starts to rotate. In special tools whose cutting edge can be hidden inside the tool body, the spindle will stop after passing through the hole and will reverse its direction. The attribute oriented_spindle_stop of its_maching_functions is required and will cause an oriented spindle stop which is needed for collapsible backboring tools.");

description[_T("tapping.description")]=_T("Workingstep for tapping (or threading) a hole. This is performed with a special cutter which is rotated and moved along the tool axis.");

description[_T("tapping.compensation_chuck.description")]=_T("If true, a compensation chuck shall be used for tapping the hole.");

description[_T("thread_drilling.description")]=_T("Workingstep for thread drilling a hole. This involves a helical movement of the tool. It is sometimes also called \")thrilling\", short for \")thread drilling\". A helical movement may be needed for the forward movement or not. The feed per revolution is calculated from the thread of the hole. The pitch of the helical movement corresponds to the pitch of the thread. The feedrate is the relative speed between tool tip and material along the helical path.");

description[_T("thread_drilling.helical_movement_on_forward.description")]=_T("Specifies if the helical movement is needed for the forward operation as well.");

