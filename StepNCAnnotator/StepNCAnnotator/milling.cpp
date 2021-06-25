description["milling_cutting_tool.description"]="";

description["milling_cutting_tool.direction_for_spindle_orientation.description"]="";

description["milling_cutting_tool.tool_holder_diameter_for_spindle_orientation.description"]="";

description["milling_tool_body.description"]="";

description["milling_tool_body.dimension.description"]="";

description["milling_tool_body.number_of_teeth.description"]="";

description["milling_tool_body.hand_of_cut.description"]="";

description["milling_tool_body.coolant_through_tool.description"]="";

description["milling_tool_body.pilot_length.description"]="";

description["milling_tool_dimension.description"]="";

description["milling_tool_dimension.diameter.description"]="";

description["milling_tool_dimension.tool_top_angle.description"]="";

description["milling_tool_dimension.tool_circumference_angle.description"]="";

description["milling_tool_dimension.cutting_edge_length.description"]="";

description["milling_tool_dimension.edge_radius.description"]="";

description["milling_tool_dimension.edge_center_vertical.description"]="";

description["milling_tool_dimension.edge_center_horizontal.description"]="";

description["center_drill.description"]="";

description["countersink.description"]="";

description["countersink.countersink_radius.description"]="";

description["backside_countersink.description"]="";

description["drill.description"]="";

description["twist_drill.description"]="";

description["tapered_drill.description"]="";

description["tapered_drill.taper_angle.description"]="";

description["spade_drill.description"]="";

description["milling_cutter.description"]="";

description["facemill.description"]="";

description["endmill.description"]="";

description["tapered_endmill.description"]="";

description["tapered_endmill.taper_angle.description"]="";

description["ball_endmill.description"]="";

description["bullnose_endmill.description"]="";

description["t_slot_mill.description"]="";

description["t_slot_mill.cutting_thickness.description"]="";

description["dovetail_mill.description"]="";

description["dovetail_mill.included_angle.description"]="";

description["woodruff_keyseat_mill.description"]="";

description["woodruff_keyseat_mill.cutter_width.description"]="";

description["side_mill.description"]="";

description["side_mill.cutter_width.description"]="";

description["thread_mill.description"]="";

description["tap.description"]="";

description["tapered_tap.description"]="";

description["tapered_tap.taper_angle.description"]="";

description["combined_drill_and_tap.description"]="";

description["combined_drill_and_tap.drill_length.description"]="";

description["threading_tool.description"]="";

description["counterbore.description"]="";

description["backside_counterbore.description"]="";

description["reamer.description"]="";

description["tapered_reamer.description"]="";

description["tapered_reamer.taper_angle.description"]="";

description["combined_drill_and_reamer.description"]="";

description["combined_drill_and_reamer.drill_length.description"]="";

description["boring_tool.description"]="";

description["user_defined_tool.description"]="";

description["user_defined_tool.identifier.description"]="";

description["exchange_pallet.description"]="This function is used to execute a pallet exchange.";

description["index_pallet.description"]="This function is used to place the pallet to the indicated position by the parameter index.";

description["index_pallet.its_index.description"]="The parameter index value by which the destined position of the pallet is indicated.";

description["index_table.description"]="This function is used to place the rotation table to the indicated position by the parameter index.";

description["index_table.its_index.description"]="The parameter index value by which the destined position of the rotation table is indicated.";

description["load_tool.description"]="This function is used to load a tool that can be seleted independent from the geometrical information.";

description["load_tool.its_tool.description"]="The tool which has to be loaded.";

description["unload_tool.description"]="This function is used to unload a tool.";

description["unload_tool.its_tool.description"]="The tool which has to be exchanged. In case of an operation where more than one tool is in use at the same time this attribute has to be set.";

description["tool_direction_for_milling.description"]="This is the base class of all tool orientations used for freeform machining. It is subtypes of entity tool_direction defined in ISO 14649-10.";

description["three_axes_tilted_tool.description"]="In this mode of operation, the tool is tilted, so the tool direction is not parallel to any of the three machine axes. However, the tool is clamped to fix the tool angle and motion is still only in the three linear axes. Unlike five_axes_var_tilt_yaw the tilt and/or yaw angles are not variable.";

description["three_axes_tilted_tool.tool_direction.description"]="The direction of the tool in absolute machine co-ordinates.";

description["five_axes_var_tilt_yaw.description"]="Simultaneous tool movements in five axes are used for machining. During motion, the tool direction is adjusted so as to follow the curve given in the toolpath instances.";

description["five_axes_const_tilt_yaw.description"]="This is a special case of five_axes_var_tilt_yaw. The tool is moved so that the tilt and yaw angles are constant in each point of the toolpath, relative to the co-ordinate system given by the surface normal in the cutter contact point and the tangent in feed direction. Tilt and yaw are given as attributes of this entity. Note that these values may be overridden if an explicit tool direction curve is specified for a toolpath.";

description["five_axes_const_tilt_yaw.tilt_angle.description"]="The inclination of the tool in feed direction, measured against the surface normal in the cutter contact point.";

description["five_axes_const_tilt_yaw.yaw_angle.description"]="The rotation of the inclined tool around the surface normal, measured against the surface tangent in feed direction in the cutter contact point.";

description["milling_machining_operation.description"]="This is the base class of all operations described in this part of ISO 14649. It is a subtype of entity machining_operation defined in ISO 14649-10. In case that feedrate_per_tooth of its_technology is chosen, number_of_teeth of its_tool_body of its_tool should be given.";

description["milling_machining_operation.overcut_length.description"]="The overcut on the open side(s) of the feature. It is not allowed for manufacturing of features which are bounded by material on all sides, i. e. pockets. In case of round_hole, this attribute is allowed only for through-bottom holes. If the cutting_depth of drilling_type_operation specifies a conflicting value, overcut_ length is ignored.";

description["milling_technology.description"]="This entity defines the technological parameters of the milling operation. It is a subtype of entity technology defined in ISO 14649-10. Of the four alternatives for specifying speeds, exactly two must be given as indicated by the WHERE rules. If the attribute adaptive_control s invoked, some or all of these values may be ignored.";

description["milling_technology.cutspeed.description"]="Cutting speed of the tool, the speed of spindle converted into a linear speed.";

description["milling_technology.spindle.description"]="Rotational speed of the tool. As defined for rot_speed_measure, positive values indicate tool rotation in mathematical positive direction of the c axis, i. e. counterclockwise motion if looking from the tool holder to the workpiece. Note that usual cutting tools require clockwise motion so the value of this attribute will typically be negative.";

description["milling_technology.feedrate_per_tooth.description"]="Feed of the tool expressed as a distance.";

description["milling_technology.synchronize_spindle_with_feed.description"]="If true, cutting speed and feed of the tool is synchronised. Therefore, the pitch of tap can be kept constant at the bottom of a hole when cutting speed is being decelerated and accelerated.";

description["milling_technology.inhibit_feedrate_override.description"]="If true, the feedrate override through the operating panel or by adaptive control systems is not allowed.";

description["milling_technology.inhibit_spindle_override.description"]="If true, the spindle speed override through the operating panel or by adaptive control systems is not allowed.";

description["milling_technology.its_adaptive_control.description"]="Any kind of vendor specific adaptive control strategy.";

description["adaptive_control.description"]="This entity defines the vendor-specific adaptive control strategy. At a later time, the specific nature of the adaptive control algorithm and further parameters can be specified in appropriate subtypes.";

description["milling_machine_functions.description"]="The entity describes the state of various functions of the machine, like coolant, chip removal, etc. to be applied during the time span of an operation. It is a subtype of entity machine_functions defined in ISO 14649-10.";

description["milling_machine_functions.coolant.description"]="If true, the coolant is activated.";

description["milling_machine_functions.coolant_pressure.description"]="Optional specification of the pressure of the coolant system. Only valid if coolant is true.";

description["milling_machine_functions.mist.description"]="If true, activate mist coolant. Default is false. Only valid if coolant is true.";

description["milling_machine_functions.through_spindle_coolant.description"]="If true, activate coolant through the spindle. Default is false.";

description["milling_machine_functions.through_pressure.description"]="Pressure of coolant through the spindle. Only valid if through_spindle_coolant is true.";

description["milling_machine_functions.axis_clamping.description"]="Describes which axes are to be clamped, e.g. X,Y,A. Note that this information is machine dependent and should be avoided.";

description["milling_machine_functions.chip_removal.description"]="If true, activate chip removal.";

description["milling_machine_functions.oriented_spindle_stop.description"]="If specified, the spindle will stop in the given direction relative to the machine zero position of C-axis in case a spindle stop occurs during or at the end of the workingstep.";

description["milling_machine_functions.its_process_model.description"]="Optional information for process control.";

description["milling_machine_functions.other_functions.description"]="Optional list of other functions of generic type.";

description["process_model_list.description"]="For each workingstep, one or more process models may be started. These are modules for process control like chatter avoidance, thermal compensation, etc.";

description["process_model_list.its_list.description"]="List of process models for the current workingstep";

description["process_model.description"]="Special machine-specific functions to make the machining process more secure and accurate. (e.g. chatter avoidance, thermal compensation, ...)";

description["process_model.ini_data_file.description"]="A filename including path of the file containing the initialisation data of the process model.";

description["process_model.its_type.description"]="The type of process model (e.g. chatter avoidance, thermal compensation, ...)";

description["milling_type_operation.description"]="This is the base class of all operations for milling. It includes all necessary attributes to describe technology and strategy. It is a subtype of entity milling_machining_operation. In general, there are two types of machining operations: roughing and finishing. The roughing is to remove all material from the original raw piece surface down to the bottom or side of the feature minus the finishing allowance in multiple passes. The finishing will then remove the finish allowance to yield the final surface of the feature. In case of pre-cast features, e.g. pre-cast holes and pockets, roughing operation need to be one";

description["milling_type_operation.approach.description"]="By default, the NC controller decides about the approach strategy. It may decide not to use any approach movement at all if the start point of cutting coincides with the end point of cutting for the preceding operation. If its_toolpath is given, this attribute will be ignored.";

description["milling_type_operation.retract.description"]="Optional information about retract strategy after finishing the last cut. By default, the NC controller decides about the retract strategy. It may decide not to use any retract movement at all if the end point of cutting coincides with the start point of cutting for the next operation. If its_toolpath is given, this attribute will be ignored.";

description["approach_retract_strategy.description"]="Base class for the approach (plunge) and retract strategy. All approach and retract strategies are defined relative to the start or end point of the cutting operation, whether this is explicitly given in the operation of determined by the NC controller. The resulting start point of the approach or end point of the retract movement are defined to be the start and end point of the current operation. The feed rate on the approach or retract path is the feed rate specified for the related start or end point, respectively, of cutting.";

description["approach_retract_strategy.tool_orientation.description"]="Only for machines with five-axis positioning capabilities. This specified the tool orientation at the beginning or end, respectively, of the approach or retract movement.";

description["plunge_strategy.description"]="This is the base class for all approach movements which include cutting of material. This is typically the case for pocketing operations where the approach to the depth of the first cutting layer or between cutting layers requires the removal of material in order to create the approach path. All plunge movements are guaranteed to occur within the boundaries of the underlying feature. All plunge movements will start at the retract plane valid for the current operation. They will end in the start point of the cutting operation, with the tangent of its approach path coinciding with the tangent of the ensuing cutting motion.";

description["plunge_toolaxis.description"]="Plunge in the direction of the tool axis.";

description["plunge_ramp.description"]="Plunge on a linear path which forms an angle with the feature surface.";

description["plunge_ramp.angle.description"]="The angle of the ramp movement versus the surface in the end point of the approach.";

description["plunge_helix.description"]="Plunge movement forming a helix. The path is defined by specifying the radius and grade of the helix. A circular movement can be specified by setting grade to zero.";

description["plunge_helix.radius.description"]="Radius of the helical movement.";

description["plunge_helix.angle.description"]="The angle of the helical movement versus the surface in the end point of the approach.";

description["plunge_zigzag.description"]="Plunge movement using a zigzag motion. This is similar to the ramp-type movement, except the cutter changes direction if it touches a feature boundary or if the path length would exceed the specified width of the zigzag pattern.";

description["plunge_zigzag.angle.description"]="The angle of the movement versus the surface in the end point of the approach.";

description["plunge_zigzag.width.description"]="The with of the zigzag path perpendicular to the direction of the descent.";

description["air_strategy.description"]="This is the base class for all approach or retract movements through the air. Unlike the plunge_strategy types these movements are not limited to the inside of the feature. All of these movements shall take place in a plane which is defined by the normal of the machined feature and the tangent of the cutting path in the start or end point, respectively, of the related cutting movement. If the start or end point lies at the intersection of two planes, as may be the case for bottom_and_side_milling operations, the surface normal is deemed to be the intermediate direction between the two normals.";

description["ap_retract_angle.description"]="The movement is heading towards the start or from the end point in an angle to the surface. For plane milling, this may typically be an angle of 0 degrees in order to move straight from outside the workpiece into the material.";

description["ap_retract_angle.angle.description"]="Approach or lift angle versus the surface in the end point of the approach or the start point of the lift, respectively.";

description["ap_retract_angle.travel_length.description"]="The length of the angular approach. After travel_length has been reached, the tool will proceed to the retract plane using the shortest connection and vice versa.";

description["ap_retract_tangent.description"]="The movement is heading towards the start or from the end point in a curve. The motion start or ends in the retract plane valid for the current operation. If the specified radius for this motion is smaller than the distance to the retract plane as specified in the attribute retract_plane of the current operation, the remaining path will be executed in linear motion perpendicular to the retract plane.";

description["ap_retract_tangent.radius.description"]="The radius of the approach or retract movement.";

description["along_path.description"]="Approach or lift movement on a general path. This should be used if full control of the tool orientation during approach is required or for other special purposes.";

description["along_path.path.description"]="Specification of a general path for approach or lift movement. Note that the path is specified in a special co-ordinate system. The origin is the start or end point of the cutting operation, the axes are oriented like the local co-ordinate system of the feature.";

description["freeform_operation.description"]="Derived from the milling type operation, this is the class of operations for freeform milling. Note that only some Hi- Tech NC controllers today will not be able to machine a freeform surface without specifying explicit toolpaths.";

description["freeform_operation.its_machining_strategy.description"]="Description of the strategy to be used when executing the operation. In case the attribute its_toolpath of the supertype operation is specified, the strategy is for information only.";

description["freeform_strategy.description"]="The following entities define the strategy used for milling a freeform surface. If this entity is used, the toolpath is defined only by means of the milling strategy and the tolerances. The CNC itself has to calculate the resulting toolpaths out of these values. If the toolpath and the freeform strategy are defined, the attribute \"freeform_strategy\" is for information only.";

description["freeform_strategy.pathmode.description"]="The feed direction";

description["freeform_strategy.cutmode.description"]="The stepover direction.";

description["freeform_strategy.its_milling_tolerances.description"]="The tolerance values to be used during creation of the toolpaths.";

description["freeform_strategy.stepover.description"]="The distance between two neighboring toolpaths. If given, the stepover calculated by use of its_milling_tolerances will be ignored.";

description["tolerances.description"]="The tolerances which are associated with the free form operation. This does not refer to the general manufacturing tolerances but specifies two parameter which are needed if the NC controllers generates toolpaths for free-form surfaces. Through these values the stepover distance between the toolpaths can be derived.";

description["tolerances.chordal_tolerance.description"]="Geometric error resulting from a linear approximation of a curve.";

description["tolerances.scallop_height.description"]="Height of the grooves caused by the tool radius";

description["uv_strategy.description"]="Milling follows the parameter lines in the local (u,v) coordinate system.";

description["uv_strategy.forward_direction.description"]="The direction used in the first cut.";

description["uv_strategy.sideward_direction.description"]="The direction in which the second cut is offset from the first.";

description["plane_cc_strategy.description"]="The paths are generated by intersecting the target surface with parallel planes. The result of these intersections form the cutter contact paths.";

description["plane_cc_strategy.its_plane_normal.description"]="The normal of the planes used for intersection with the target surface.";

description["plane_cl_strategy.description"]="The paths are generated by intersecting the target surface, offset by the cutter radius, with planes. The result form the cutter location paths. This strategy makes sense with ball end and bullnose cutters.";

description["plane_cl_strategy.its_plane_normal.description"]="The normal of the planes used for intersection with the target surface";

description["leading_line_strategy.description"]="The toolpaths are calculated by projecting a curve on the workpiece surface along the Z-axis of local coordinate system. The curve is given as an attribute.";

description["leading_line_strategy.its_line.description"]="The curve used to calculate the toolpaths.";

description["two5d_milling_operation.description"]="This is the base class of all operations for 2½D milling derived from milling_type_operation.";

description["two5d_milling_operation.its_machining_strategy.description"]="Description of the strategy to be used when executing the operation. In case the attribute its_toolpath of the supertype operation is specified, the strategy is for information only.";

description["two5d_milling_strategy.description"]="This is the base class of all strategies used for creating 2½D milling toolpaths";

description["two5d_milling_strategy.overlap.description"]="The overlap in the path between two neighbouring cutting movements as percentage of the tool diameter.";

description["two5d_milling_strategy.allow_multiple_passes.description"]="Optional flag only for roughing workingsteps. If true, this is the standard roughing operation with multiple passes, i. e. several layers of material are removed sequentially, taking into account the maximum cutting depth. If false, this is the special roughing operation for pre-cast features with one pass. Default is true.";

description["unidirectional.description"]="Milling in a linear fashion, i.e. going from one side to the other, then lifting the tool and going back to the starting point. In this way, the cutting mode (conventional or climb cutting) is not changed like it is in bidirectional milling. The step over direction is automatically derived from feed_direction and cutmode.";

description["unidirectional.feed_direction.description"]="Feed direction of the milling operation. The attribute cutmode, if given, takes precedence over this attribute.";

description["unidirectional.cutmode.description"]="Specifies whether conventional or climb cutting should be used. Default is conventional.";

description["bidirectional.description"]="Milling in a zigzag fashion, i.e. going from one side to the other and back. For further describing the strategy of milling, it may be specified, which are the first and second directions for zigzagging. The cutting mode (conventional or climb cutting) is alternated.";

description["bidirectional.feed_direction.description"]="Feed direction of the first toolpath of the milling operation";

description["bidirectional.stepover_direction.description"]="Stepover direction of the zigzag operation";

description["bidirectional.its_stroke_connection_strategy.description"]="Specification of the behaviour of the tool between strokes";

description["contour_parallel.description"]="Milling in several paths following the contour of the feature. A typical strategy for pocket milling. The step over direction (outside_in or inside_out) is automatically derived from rotation_direction and cutmode.";

description["contour_parallel.rotation_direction.description"]="Direction of the spiral (clockwise or counterclockwise) as seen from the top of the feature. The default is counterclockwise. The attribute cutmode, if given, takes precedence over this attribute.";

description["contour_parallel.cutmode.description"]="Specifies whether conventional or climb cutting should be used. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of of pocket and possible bosses.";

description["bidirectional_contour.description"]="Milling of the contour in bidirectional fashion first, then one final contour-parallel path on the very outside of the feature.";

description["bidirectional_contour.feed_direction.description"]="Feed direction of the first toolpath of the milling operation. The attribute first_cutmode, if given, takes precedence over this attribute.";

description["bidirectional_contour.stepover_direction.description"]="Stepover direction of the zigzag operation.";

description["bidirectional_contour.rotation_direction.description"]="Direction of the spiral (clockwise or counterclockwise) for the final cut as seen from the top of the feature. The default is counterclockwise. The attribute spiral_cutmode, if given, takes precedence over this attribute.";

description["bidirectional_contour.spiral_cutmode.description"]="Specifies whether conventional or climb cutting should be used on the final cut. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of pocket and possible bosses.";

description["contour_bidirectional.description"]="Milling of a contour parallel path on the very outside of the contour first, then bidirectional milling of the remaining center.";

description["contour_bidirectional.feed_direction.description"]="Feed direction of the first toolpath of the zigzag operation. The attribute first_cutmode, if given, takes precedence over this attribute.";

description["contour_bidirectional.stepover_direction.description"]="Stepover direction of the zigzag operation.";

description["contour_bidirectional.rotation_direction.description"]="Direction of the spiral (clockwise or counterclockwise) for the final cut as seen from the top of the feature. The default is counterclockwise. The attribute spiral_cutmode, if given, takes precedence over this attribute.";

description["contour_bidirectional.spiral_cutmode.description"]="Specifies whether conventional or climb cutting should be used. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of pocket and possible bosses.";

description["contour_spiral.description"]="Contour spiral milling is similar to contour parallel milling, with the exception, that in this case the milling path is a truly spiral path rather than concentric paths which are connected by a orthogonal movement. The step over direction (outside_in or inside_out) is automatically derived from rotation_direction and cutmode.";

description["contour_spiral.rotation_direction.description"]="The direction of the spiral path (clockwise or counterclockwise) as seen from the top of the feature. The default is counterclockwise. The attribute cutmode, if given, takes precedence over this attribute.";

description["contour_spiral.cutmode.description"]="Specifies whether conventional or climb cutting should be used. Default is conventional. The cutmode refers to the functional walls of the contour which are produced by side milling, i. e. the outer contour of of pocket and possible bosses.";

description["center_milling.description"]="This entity describes a milling strategy along the center of the feature. This is used e.g. for milling along the center of a slot.";

description["explicit.description"]="Any two5D strategy which can not be described using any of the above given types can be specified using explicit. In this case, an exact definition of all movements needs to be given in the attribute its_toolpath of the entity workingstep.";

description["plane_milling.description"]="Entity to describe the milling of a plane. This is the supertype for roughing and finishing operations.";

description["plane_milling.axial_cutting_depth.description"]="The cutting depth in the direction of the tool axis. This can be given to specify a maximal cutting depth smaller than the material removal required by the feature’s depth. As a result, several layers will be manufactured. If omitted, the selected cutting depth will be implementation dependent.";

description["plane_milling.allowance_bottom.description"]="The allowance is a layer of material which will be left on top of the plane surface defined by the associated manufacturing feature.";

description["plane_rough_milling.description"]="Roughing operation for milling. All material inside the manufacturing feature will be removed using the given tool, except for the allowance_bottom.";

description["plane_finish_milling.description"]="Finishing operation for milling. All material inside the manufacturing feature will be removed, applying an appropriate strategy to maintain the given tolerances. If allowance_bottom is given, other special operation like grinding shall be applied for removing the material left.";

description["side_milling.description"]="Entity to describe a side milling process during which material is removed along the flank of the tool.";

description["side_milling.axial_cutting_depth.description"]="The cutting depth in the direction of the tool axis. See plane milling.";

description["side_milling.radial_cutting_depth.description"]="The cutting depth perpendicular to the tool axis. This can be used to limit the chip thickness. If radial_cutting_depth is smaller than the radial material removal required by the feature, this will cause the execution of the operation in several layers.";

description["side_milling.allowance_side.description"]="The allowance is a layer of material which will be left on side of the surface defined by the associated manufacturing feature.";

description["side_rough_milling.description"]="Roughing operation for side milling. All material inside the manufacturing feature will be removed using the given tool, except for the allowance_side";

description["side_finish_milling.description"]="Finishing operation for side milling. All material inside the manufacturing feature will be removed, applying an appropriate strategy to maintain the given tolerances. If allowance_side is given, other special operation like grinding shall be applied for removing the material left.";

description["bottom_and_side_milling.description"]="Entity to describe a combined bottom and side milling process.";

description["bottom_and_side_milling.axial_cutting_depth.description"]="The cutting depth in the direction of the tool. See plane milling.";

description["bottom_and_side_milling.radial_cutting_depth.description"]="The cutting depth perpendicular to the tool, used in side milling. See side milling.";

description["bottom_and_side_milling.allowance_side.description"]="The allowance is a layer of material which will be left on side of the surface defined by the associated manufacturing feature.";

description["bottom_and_side_milling.allowance_bottom.description"]="The allowance is a layer of material which will be left on top of the plane surface defined by the associated manufacturing feature.";

description["bottom_and_side_rough_milling.description"]="Roughing operation for a combined bottom and side milling workingstep. All material inside the manufacturing feature will be removed using the given tool, except for the allowance_side and allowance_bottom.";

description["bottom_and_side_finish_milling.description"]="Finishing operation for a combined bottom and side milling workingstep. All material inside the manufacturing feature will be removed, applying an appropriate strategy to maintain the given tolerances. If allowance_side and allowance_bottom are given, other special operation like grinding shall be applied for removing the material left.";

description["drilling_type_operation.description"]="This is the base class for all operations concerned with drilling a hole, reaming, sinking, etc. It is a subtype of entity milling_machining_operation. Cutting of a thread is included here also. The base class provides all necessary attributes to describe technology and strategy for drilling type operations. In case of pre-cast holes, the predrilling can be operated before the finish drilling by means of specifying a drilling depth (and an appropriate tool) which is smaller than that of the feature. Subsequent drilling operations can specify the attribute previous_diameter appropriately to allow for the already removed material. The start point is given by the inherited attributes retract_plane and cut_start_point. If cut_start_point is omitted, the centre of the underlying feature will be used instead. From there the tool will advance with drilling feed along the local z axis. Using the prescribed strategy, the tool will drill to the depth of the associated feature, for through holes applying an inherited attribute overcut_length. For pre-drilling operations, the attribute cutting_depth can be used to reduce the depth of a cut to an amount smaller than the hole’s depth. On retract, the tool will return to the retract plane using the drilling feed, or – if specified – the feed_on_retract given by drilling_type_strategy.";

description["drilling_type_operation.cutting_depth.description"]="The depth of the cut of this operation, which may differ from the depth of the hole as such. The NC controller will not check if cutting_depth violates the boundaries of the associated hole feature. If omitted, the total depth of the feature will be drilled. In case of center drilling operation, the cutting_depth is measured from the lowest point of the cutting tip to the highest point of the hole. In other cases, it is measured from the starting point of cylindrical part of the tool.(Or, tapered cylindrical part in case of tapered drill.)";

description["drilling_type_operation.previous_diameter.description"]="If the operation is performed on a pre-drilled or pre-cast hole, this value, if given, specifies the diameter of the existing hole. It thus describes the amount of material which the tool as to remove and is for information only.";

description["drilling_type_operation.dwell_time_bottom.description"]="Possible dwell time at the bottom of the hole.";

description["drilling_type_operation.feed_on_retract.description"]="Feed used for retract to the retract_plane as ratio of the drilling feed. If not specified, the drilling feed is used.";

description["drilling_type_operation.its_machining_strategy.description"]="Description of the strategy to be used when executing the operation. In case the attribute its_toolpath of the supertype operation is specified, the strategy is for information only.";

description["drilling_type_strategy.description"]="This is the specification of a dedicated strategy for drilling. For drilling, this mainly refers to a variation of cutting speed and feed along the movement of the tool.";

description["drilling_type_strategy.reduced_cut_at_start.description"]="Reduced cutting speed at the beginning of the cut as a percentage of the programmed value.";

description["drilling_type_strategy.reduced_feed_at_start.description"]="Reduced feed at the beginning of the cut as a percentage of the programmed value.";

description["drilling_type_strategy.depth_of_start.description"]="Depth to which the reduced values at the start are valid.";

description["drilling_type_strategy.reduced_cut_at_end.description"]="Reduced cutting speed at the end of the cut as a percentage of the programmed value.";

description["drilling_type_strategy.reduced_feed_at_end.description"]="Reduced feed at the end of the cut as a percentage of the programmed value.";

description["drilling_type_strategy.depth_of_end.description"]="Depth from which the reduced values at the end are valid.";

description["drilling_operation.description"]="Base class for drilling operation concerned with drilling, center drilling, counter sinking, and multistep drilling.";

description["drilling.description"]="Workingstep for drilling a regular hole.";

description["center_drilling.description"]="Workingstep for centering a hole.";

description["counter_sinking.description"]="Workingstep for counter sinking a hole.";

description["multistep_drilling.description"]="Workingstep for drilling of deep holes in multiple steps.";

description["multistep_drilling.retract_distance.description"]="If retract_distance is a positive value, the tool is retracted this value between steps to enable chip breaking. If it is zero or negative, the tool is retracted to the retract plane between steps to clear the hole of chips.";

description["multistep_drilling.first_depth.description"]="Depth of the first step.";

description["multistep_drilling.depth_of_step.description"]="Depth of each additional step (repeated until the depth of the hole is reached).";

description["multistep_drilling.dwell_time_step.description"]="Dwell time between steps.";

description["boring_operation.description"]="Base class for boring operation concerned with boring and reaming. The spindle orientation at the bottom should be given.";

description["boring_operation.spindle_stop_at_bottom.description"]="Possible spindle stop at the bottom of the hole. If the attribute oriented_spindle_stop in the workingstep’s technology is set, this will cause an oriented spindle stop.";

description["boring_operation.depth_of_testcut.description"]="Depth of a testcut after which the hole is measured.";

description["boring_operation.waiting_position.description"]="A waiting position for the tool i.e. to allow measuring. The tool moves out of the hole along the tool axis until it reaches the plane of the waiting_position. It then moves to the waiting position itself.";

description["boring.description"]="Workingstep for boring a hole.";

description["reaming.description"]="Workingstep for reaming a hole.";

description["back_boring.description"]="Workingstep for back boring a hole. Backboring is the cutting of the back plane of a through bottom hole. After the tool is positioned at the start point, the spindle stops at the direction_of_spindle_orientation specified as an attribute of milling_cutting_tool. The tool is shifted in the opposite of direction_of_spindle_orientation in order to path through the hole with rapid traverse. At the bottom of the hole, it returns to the cutting position for the shifted value and the spindle starts to rotate. In special tools whose cutting edge can be hidden inside the tool body, the spindle will stop after passing through the hole and will reverse its direction. The attribute oriented_spindle_stop of its_maching_functions is required and will cause an oriented spindle stop which is needed for collapsible backboring tools.";

description["tapping.description"]="Workingstep for tapping (or threading) a hole. This is performed with a special cutter which is rotated and moved along the tool axis.";

description["tapping.compensation_chuck.description"]="If true, a compensation chuck shall be used for tapping the hole.";

description["thread_drilling.description"]="Workingstep for thread drilling a hole. This involves a helical movement of the tool. It is sometimes also called \"thrilling\", short for \"thread drilling\". A helical movement may be needed for the forward movement or not. The feed per revolution is calculated from the thread of the hole. The pitch of the helical movement corresponds to the pitch of the thread. The feedrate is the relative speed between tool tip and material along the helical path.";

description["thread_drilling.helical_movement_on_forward.description"]="Specifies if the helical movement is needed for the forward operation as well.";

