description[_T("approval.description")]=_T("An approval is a confirmation of the quality of the product data that it is related to. Application protocols that use this resource construct shall specify the extent of the approval.");

description[_T("approval.status.description")]=_T("the status of the approval in terms of whether or not the approval has been granted.");

description[_T("approval.level.description")]=_T("the type or level of approval in terms of its usage. This usage may be implied rather than explicit.");

description[_T("approval_status.description")]=_T("An approval_status is the ranking that gives an indication of the state of an approval.");

description[_T("approval_status.name.description")]=_T("the name of the ranking of an approval.");

description[_T("date_and_time.description")]=_T("A date_and_time is a moment of time on a particular day.");

description[_T("date_and_time.date_component.description")]=_T("the date element of the date time combination.");

description[_T("date_and_time.time_component.description")]=_T("the time element of the date time combination.");

description[_T("date.description")]=_T("A date is the identification of a day or week in a year.");

description[_T("date.year_component.description")]=_T("the year in which the date occurs.");

description[_T("calendar_date.description")]=_T("A calendar_date is a date which is identified by a day in a month of a year.");

description[_T("calendar_date.day_component.description")]=_T("the day element of the date.");

description[_T("calendar_date.month_component.description")]=_T("the month element of the date.");

description[_T("ordinal_date.description")]=_T("An ordinal_date is a date which is identified by a day of a year.");

description[_T("ordinal_date.day_component.description")]=_T("the day element of the date.");

description[_T("week_of_year_and_day_date.description")]=_T("A week_of_year_and_date is a date which is identified by a day in a week of a year.");

description[_T("week_of_year_and_day_date.week_component.description")]=_T("the week element of the date.");

description[_T("week_of_year_and_day_date.day_component.description")]=_T("the day element of the date.");

description[_T("local_time.description")]=_T("time on a 24 hour clock. NOTE - This construct is used to represent a moment of time whereas time measures (see clause 20.4.1) represent amounts of time. EXAMPLE - 1500 hours is an instant in time whereas 15 hours is an amount of time.");

description[_T("local_time.hour_component.description")]=_T("the number of hours.");

description[_T("local_time.minute_component.description")]=_T("the number of minutes.");

description[_T("local_time.second_component.description")]=_T("the number of seconds.");

description[_T("local_time.zone.description")]=_T("the relationship of the time to coordinated universal time.");

description[_T("coordinated_universal_time_offset.description")]=_T("A coordinated_universal_time_offset is used to relate a time to coordinated universal time by an offset (specified in hours and minutes) and a direction.");

description[_T("coordinated_universal_time_offset.hour_offset.description")]=_T("the number of hours by which a time is offset from coordinated universal time.");

description[_T("coordinated_universal_time_offset.minute_offset.description")]=_T("the number of minutes by which a time is offset from coordinated universal time.");

description[_T("coordinated_universal_time_offset.sense.description")]=_T("the direction of the offset.");

description[_T("person.description")]=_T("A person is an individual human being.");

description[_T("person.id.description")]=_T("a means by which the person may be identified.");

description[_T("person.last_name.description")]=_T("the person's surname.");

description[_T("person.first_name.description")]=_T("the first element of the person's list of forenames.");

description[_T("person.middle_names.description")]=_T("the person's other forenames, if there are any.");

description[_T("person.prefix_titles.description")]=_T("the word, or group of words, which specify the person's social and/or professional standing and appear before his or her names.");

description[_T("person.suffix_titles.description")]=_T("the word, or group of words, which specify the person's social and/or professional standing and appear after his or her names.");

description[_T("address.description")]=_T("An address is the place where people and organizations are located.");

description[_T("address.internal_location.description")]=_T("an organization-defined address for internal mail delivery.");

description[_T("address.street_number.description")]=_T("the number of a building in a street.");

description[_T("address.street.description")]=_T("the name of a street.");

description[_T("address.postal_box.description")]=_T("the number of a postal box.");

description[_T("address.town.description")]=_T("the name of a town.");

description[_T("address.region.description")]=_T("the name of a region. EXAMPLE - The counties of Great Britain and the states of the United States of America are examples of regions.");

description[_T("address.postal_code.description")]=_T("the code that is used by the country's postal service.");

description[_T("address.country.description")]=_T("the name of a country.");

description[_T("address.facsimile_number.description")]=_T("the number at which facsimiles may be received.");

description[_T("address.telephone_number.description")]=_T("the name of a country.");

description[_T("address.electronic_mail_address.description")]=_T("");

description[_T("address.telex_number.description")]=_T("");

description[_T("shape_representation.description")]=_T("A shape_representation is a specific kind of representation that represents a shape.");

description[_T("trimmed_curve.description")]=_T("A trimmed curve is a bounded curve which is created by taking a se­ lected portion, between two identified points, of the associated basis curve. The basis curve itself is unaltered and more than one trimmed curve may reference the same basis curve.");

description[_T("trimmed_curve.basis_curve.description")]=_T("");

description[_T("trimmed_curve.trim_1.description")]=_T("The first trimming point which may be specified as a cartesian point (point 1), as a real parameter value (parameter 1 = t 1 ), or both.");

description[_T("trimmed_curve.trim_2.description")]=_T("The second trimming point which may be specified as a cartesian point (point 2), as a real parameter value (parameter 2 = t 2 ), or both.");

description[_T("trimmed_curve.sense_agreement.description")]=_T("Flag to indicate whether the direction of the trimmed curve agrees with or is opposed to the direction of basis curve.");

description[_T("trimmed_curve.master_representation.description")]=_T("Where both parameter and point are present at either end of the curve this indicates the preferred form. Multiple representations provide the ability to communicate data in more than one form, even though the data are expected to be geometrically");

description[_T("composite_curve.description")]=_T("A composite curve is a collection of curves joined end­to­end. The individual segments of the curve are themselves defined as composite curve segments. The parametrisation of the composite curve is an accumulation of the parametric ranges of the referenced bounded curves.");

description[_T("composite_curve.segments.description")]=_T("The component bounded curves, their transitions and senses. The transition attribute for the last segment defines the transition between the end of the last segment and the start of the first; this transition attribute may take the value discontinuous, which indicates an open curve.");

description[_T("composite_curve.self_intersect.description")]=_T("Indication of whether the curve intersects itself or not; this is for information only.");

description[_T("composite_curve_segment.description")]=_T("A composite curve segment is a bounded curve together with transition information which is used to construct a composite curve.");

description[_T("composite_curve_segment.transition.description")]=_T("The state of transition (i.e., geometric continuity from the last point of this segment to the first point of the next segment) in a composite curve.");

description[_T("composite_curve_segment.same_sense.description")]=_T("An indicator of whether or not the sense of the segment agrees with, or opposes, that of the parent curve. If same sense is false, the point with highest parameter value is taken as the first point of the segment.");

description[_T("composite_curve_segment.parent_curve.description")]=_T("The bounded curve which defines the geometry of the segment.");

description[_T("axis1_placement.description")]=_T("The direction and location in three­dimensional space of a single axis. An axis1 placement is defined in terms of a locating point (inherited from the placement supertype) and an axis direction; this is either the direction of axis or defaults to (0.0,0.0,1.0). The actual direction for the axis placement is given by the derived attribute z.");

description[_T("axis1_placement.axis.description")]=_T("The direction of the local Z axis.");

description[_T("axis2_placement_3d.description")]=_T("The location and orientation in three­dimensional space of two mutually perpendicular axes. An axis2 placement 3d is defined in terms of a point, (inherited from the placement supertype), and two (ideally orthogonal) axes. It can be used to locate and orientate a non axi­symmetric object in space and to define a placement coordinate system. The entity includes a point which forms the origin of the placement coordinate system. Two direction vectors are required to complete the definition of the placement coordinate system. The axis is the placement Z axis direction and the ref direction is an approximation to the placement X axis direction.");

description[_T("axis2_placement_3d.axis.description")]=_T("The exact direction of the local Z axis");

description[_T("axis2_placement_3d.ref_direction.description")]=_T("The direction used to determine the direction of the local X axis. If necessary an adjustment is made to maintain orthogonality to the axis direction. If axis and/or ref ­ direction is omitted, these directions are taken from the geometric coordinate system.");

description[_T("bezier_curve.description")]=_T("This subtype represents in the most general case a piecewise B'ezier curve. This is a special type of curve which can be represented as a type of b spline curve in which the knots are evenly spaced and have high multiplicities. Suitable default values for the knots and knot multiplicities are derived in this case. A B­spline curve is a piecewise B'ezier curve if it is quasi­uniform except that the interior knots have multiplicity degree rather than having multiplicity one. In this subtype the knot spacing is 1.0, starting at 0.0. A piecewise B'ezier curve which has only two knots, 0.0 and 1.0, each of multiplicity (degree+1), is a simple B'ezier curve.");

description[_T("bezier_surface.description")]=_T("");

description[_T("bounded_curve.description")]=_T("");

description[_T("bounded_pcurve.description")]=_T("");

description[_T("bounded_surface.description")]=_T("A bounded surface is a surface of finite area with identifiable boundaries.");

description[_T("b_spline_curve.description")]=_T("A B­spline curve is a piecewise parametric polynomial or rational curve described in terms of control points and basis functions. The B­spline curve has been selected as the most stable format to represent all types of polynomial or rational parametric curves. With appropriate attribute values it is capable of representing single span or spline curves of explicit polynomial, rational, B'ezier or B­spline type. The b spline curve has three special subtypes where the knots and knot multiplicities can be derived to provide simple default capabilities.");

description[_T("b_spline_curve.degree.description")]=_T("The algebraic degree of the basis functions.");

description[_T("b_spline_curve.control_points_list.description")]=_T("The list of control points for the curve.");

description[_T("b_spline_curve.curve_form.description")]=_T("Used to identify particular types of curve; it is for information only.");

description[_T("b_spline_curve.closed_curve.description")]=_T("Indication of whether the curve is closed; it is for information only.");

description[_T("b_spline_curve.self_intersect.description")]=_T("Flag to indicate whether the curve self­intersects or not; it is for information only.");

description[_T("b_spline_curve_with_knots.description")]=_T("This is the type of b spline curve for which the knot values are explicitly given. This subtype shall be used to represent non­uniform B­spline curves and may be used for other knot types.");

description[_T("b_spline_curve_with_knots.knot_multiplicities.description")]=_T("The multiplicities of the knots. This list defines the number of times each knot in the knots list is to be repeated in constructing the knot array.");

description[_T("b_spline_curve_with_knots.knots.description")]=_T("The list of distinct knots used to define the B­spline basis functions.");

description[_T("b_spline_curve_with_knots.knot_spec.description")]=_T("The description of the knot type.");

description[_T("b_spline_surface.description")]=_T("A b spline surface is a general form of rational or polynomial parametric surface which is represented by control points, basis functions, and possibly, weights. As with the corresponding curve entity it has some special subtypes where some of the data can be derived.");

description[_T("b_spline_surface.u_degree.description")]=_T("Algebraic degree of basis functions in u.");

description[_T("b_spline_surface.v_degree.description")]=_T("Algebraic degree of basis functions in v.");

description[_T("b_spline_surface.control_points_list.description")]=_T("This is a list of lists of control points.");

description[_T("b_spline_surface.surface_form.description")]=_T("Indicator of special surface types.");

description[_T("b_spline_surface.u_closed.description")]=_T("Indication of whether the surface is closed in the u direction; this is for information only.");

description[_T("b_spline_surface.v_closed.description")]=_T("Indication of whether the surface is closed in the v direction; this is for information only.");

description[_T("b_spline_surface.self_intersect.description")]=_T("Flag to indicate whether, or not, surface is self­intersecting; this is for information only.");

description[_T("b_spline_surface_with_knots.description")]=_T("This is a B­spline surface in which the knot values are explicitly given. This subtype shall be used to represent non­uniform B­spline surfaces, and may also be used for other knot types.");

description[_T("b_spline_surface_with_knots.u_multiplicities.description")]=_T("The multiplicities of the knots in the u parameter direction.");

description[_T("b_spline_surface_with_knots.v_multiplicities.description")]=_T("The multiplicities of the knots in the v parameter direction.");

description[_T("b_spline_surface_with_knots.u_knots.description")]=_T("The list of the distinct knots in the u parameter direction.");

description[_T("b_spline_surface_with_knots.v_knots.description")]=_T("The list of the distinct knots in the v parameter direction.");

description[_T("b_spline_surface_with_knots.knot_spec.description")]=_T("The description of the knot type.");

description[_T("cartesian_point.description")]=_T("A cartesian point is a point defined by its coordinates in a rectan­ gular Cartesian coordinate system, or in a parameter space. The entity is defined in a one, two or three­dimensional space as determined by the number of coordinates in the list.");

description[_T("cartesian_point.coordinates.description")]=_T("The coordinates of the point location.");

description[_T("circle.description")]=_T("A circle is a conic section defined by a radius and the location and orientation of the circle.");

description[_T("circle.radius.description")]=_T("radius of the circle, which shall be greater than zero.");

description[_T("conic.description")]=_T("A conic is a planar curve which could be produced by intersecting a plane with a cone. A conic curve is defined in terms of its intrinsic geometric properties rather than being described in terms of other geometry. A conic entity always has a placement coordinate system defined by axis2 placement; the parametric representation is defined in terms of this placement coordinate system.");

description[_T("conic.position.description")]=_T("The location and orientation of the conic. Further details of the interpretation of this attribute are given for the individual subtypes.");

description[_T("curve.description")]=_T("A curve can be envisioned as the path of a point moving in its coordinate space.");

description[_T("direction.description")]=_T("");

description[_T("direction.direction_ratios.description")]=_T("");

description[_T("elementary_surface.description")]=_T("");

description[_T("elementary_surface.position.description")]=_T("");

description[_T("ellipse.description")]=_T("An ellipse is a conic section defined by the lengths of the semi­major and semi­ minor diameters and the position (center or mid point of the line joining the foci) and orientation of the curve.");

description[_T("ellipse.semi_axis_1.description")]=_T("");

description[_T("ellipse.semi_axis_2.description")]=_T("");

description[_T("geometric_representation_context.description")]=_T("");

description[_T("geometric_representation_context.coordinate_space_dimension.description")]=_T("");

description[_T("geometric_representation_item.description")]=_T("");

description[_T("hyperbola.description")]=_T("A hyperbola is a conic section defined by the lengths of the major and minor radii and the position (mid­point of the line joining two foci) and orientation of the curve.");

description[_T("hyperbola.semi_axis.description")]=_T(": The length of the semi­axis of the hyperbola. This is positive and is half the minimum distance between the two branches of the hyperbola.");

description[_T("hyperbola.semi_imag_axis.description")]=_T("The length of the semi­imaginary axis of the hyperbola which shall be positive.");

description[_T("line.description")]=_T("A line is an unbounded curve with constant tangent direction. A line is defined by a point and a direction. The positive direction of the line is in the direction of the dir vector.");

description[_T("line.pnt.description")]=_T("The location of the line.");

description[_T("line.dir.description")]=_T("The direction of the line; the magnitude and units of dir affect the parametrisation of the line.");

description[_T("parabola.description")]=_T("A parabola is a conic section defined by its focal length, position (apex), and orientation.");

description[_T("parabola.focal_dist.description")]=_T("The distance of the focal point from the apex point.");

description[_T("pcurve.description")]=_T("A pcurve is a 3D curve defined by means of a 2D curve in the parameter space of a surface. If the curve is parametrised by the function (u; v) = f(t), and the surface is parametrised by the function (x; y; z) = g(u; v), the pcurve is parametrised by the function (x; y; z) = g(f(t)). A pcurve definition contains a reference to its basis surface and an indirect reference to a 2D curve through a definitional representation entity. The 2D curve, being in parameter space, is not in the context of the basis surface. Thus a direct reference is not possible. For the 2D curve the variables involved are u and v, which occur in the parametric representation of the basis surface rather than x; y Cartesian coordinates. The curve is only defined within the parametric range of the surface.");

description[_T("pcurve.basis_surface.description")]=_T("The surface in whose parameter space the curve is defined. reference to curve: The reference to the parameter space curve which defines the pcurve.");

description[_T("pcurve.reference_to_curve.description")]=_T("");

description[_T("placement.description")]=_T("A placement locates a geometric item with respect to the coordinate system of its geometric context. It locates the item to be defined and, in the case of the axis placement subtypes, gives its orientation.");

description[_T("placement.location.description")]=_T("The geometric position of a reference point, such as the centre of a circle, of the item to be located.");

description[_T("plane.description")]=_T("A plane is an unbounded surface with a constant normal. A plane is defined by a point on the plane and the normal direction to the plane.");

description[_T("point.description")]=_T("A point is a location in some real Cartesian coordinate space R m , for m = 1; 2 or 3.");

description[_T("polyline.description")]=_T("A polyline is a bounded curve of n \Gamma 1 linear segments, defined by a list of n points,");

description[_T("polyline.points.description")]=_T("The cartesian points defining the polyline.");

description[_T("quasi_uniform_curve.description")]=_T("");

description[_T("quasi_uniform_surface.description")]=_T("This is a special type of b spline surface in which the knots are evenly spaced, and except for the first and last, have multiplicity 1. Suitable default values for the knots and knot multiplicities are derived in this case. A B­spline is quasi­uniform if and only if the knots are of multiplicity (degree + 1) at the ends, of multiplicity 1 elsewhere, and they differ by a positive constant from the preceding knot. In this subtype the knot spacing is 1.0, starting from 0.0.");

description[_T("rational_b_spline_curve.description")]=_T("A rational b spline curve is a piecewise parametric ratio­ nal curve described in terms of control points and basis functions. This subtype is instantiated with one of the other subtypes of b spline curve which explicitly or implicitly provide the knot values used to define the basis functions.");

description[_T("rational_b_spline_curve.weights_data.description")]=_T("The supplied values of the weights. See the derived attribute weights.");

description[_T("rational_b_spline_surface.description")]=_T("A rational b spline surface is a piecewise parametric rational surface described in terms of control points, associated weight values and basis func­ tions. It is instantiated with any of the other subtypes of b spline surface, which provide explicit or implicit knot values from which the basis functions are defined.");

description[_T("rational_b_spline_surface.weights_data.description")]=_T("The weights associated with the control points in the rational case.");

description[_T("spherical_surface.description")]=_T("A spherical surface is a surface which is at a constant distance (the radius) from a central point. A spherical surface is defined by the radius and the location and orientation of the surface.");

description[_T("spherical_surface.radius.description")]=_T("The radius of the sphere.");

description[_T("surface.description")]=_T("");

description[_T("surface_of_linear_extrusion.description")]=_T("This surface is a simple swept surface or a generalised cylinder obtained by sweeping a curve in a given direction.");

description[_T("surface_of_linear_extrusion.extrusion_axis.description")]=_T("The direction of extrusion, the magnitude of this vector determines the parameterization.");

description[_T("surface_of_revolution.description")]=_T("A surface of revolution is the surface obtained by rotating a curve one complete revolution about an axis.");

description[_T("surface_of_revolution.axis_position.description")]=_T("A point on the axis of revolution and the direction of the axis of revolution.");

description[_T("swept_surface.description")]=_T("A swept surface is one that is constructed by sweeping a curve along another curve");

description[_T("swept_surface.swept_curve.description")]=_T("The curve to be swept in defining the surface. If the swept curve is a pcurve, it is the image of this curve in 3D geometric space which is swept, not the parameter space curve.");

description[_T("uniform_curve.description")]=_T("This is a special type of b spline surface in which the knots are evenly spaced. Suitable default values for the knots and knot multiplicities can be derived in this case. A B­spline is uniform if and only if all knots are of multiplicity 1 and they differ by a positive constant from the preceding knot.");

description[_T("uniform_surface.description")]=_T("");

description[_T("vector.description")]=_T("");

description[_T("vector.orientation.description")]=_T("");

description[_T("vector.magnitude.description")]=_T("");

description[_T("closed_shell.description")]=_T("");

description[_T("connected_face_set.description")]=_T("");

description[_T("connected_face_set.cfs_faces.description")]=_T("");

description[_T("edge.description")]=_T("");

description[_T("edge.edge_start.description")]=_T("");

description[_T("edge.edge_end.description")]=_T("");

description[_T("edge_curve.description")]=_T("");

description[_T("edge_curve.edge_geometry.description")]=_T("");

description[_T("edge_curve.same_sense.description")]=_T("");

description[_T("edge_loop.description")]=_T("An edge loop is a loop with nonzero extent. It is a path in which the start and end vertices are the same. Its domain, if present, is a closed curve. An edge loop may overlap itself.");

description[_T("face.description")]=_T("A face is a topological entity of dimensionality 2 corresponding to the intuitive notion of a piece of surface bounded by loops. Its domain, if present, is an oriented, connected, finite 2­manifold in R m . A face domain shall not have handles, but it may have holes, each hole bounded by a loop. The domain of the underlying geometry of the face, if present, does not contain its bounds, and 0 ! \Xi ! 1. A face is represented by its bounding loops, which are defined as face bounds. A face shall have at least one bound, and the bounds shall be distinct and shall not intersect. One loop is optionally distinguished, using the face outer bound subtype, as the “outer” loop of the face. If so, it establishes a preferred way of embedding the face domain in the plane, in which the other bounding loops of the face are “inside” the outer loop. Because the face domain is arcwise connected, no inner loop shall contain any other loop. This is true regardless of which embedding in the plane is chosen. A geometric surface may be associated with the face. This may be done explicitly through the face surface subtype, or implicitly if the faces are defined by poly loops. In the latter case, the surface is the plane containing the points of the poly loops. In either case, a topological normal n is associated with the face, such that the cross product n \Theta t points toward the interior of the face, where t is the tangent to a bounding loop. That is, each loop runs counter­clockwise around the face when viewed from above, if we consider the normal n to point up. Each loop is associated through a face bound entity with a BOOLEAN flag to signify whether the loop direction is oriented correctly with respect to the face normal (TRUE) or should be reversed (FALSE). For a face of the subtype face surface, the topological normal n is defined from the normal of the underlying surface, together with the BOOLEAN attribute same sense, and this in turn, determines on which side of the loop the face interior lies, using the cross­product rule described above. When a vertex loop is used as a face bound the sense of the topological normal is derived from any other bounding loops, or, in the case of a face surface, from the face geometry and the same sense flag. If the face has only one bound and this is of type vertex loop, then the interior of the face is the domain of the face surface.face geometry. In such a case the underlying surface shall be closed (e.g. a spherical surface.) The situation is different for a face on an implicit planar surface, such as one defined by poly ­ loops, which has no unique surface normal. Since the face and its bounding loops lie in a plane, the outer loop can always be found without ambiguity. Since the face is required to be finite, the face interior must lie inside the outer loop, and outside each of the remaining loops. These conditions, together with the specified loop orientations, define the topological normal n using the cross­product rule described above. All poly loop orientations for a given face shall produce the same value for n.");

description[_T("face.bounds.description")]=_T("Boundaries of the face; no more than one of these shall be a face outer bound.");

description[_T("face_bound.description")]=_T("A face bound is a loop which is intended to be used for bounding a face.");

description[_T("face_bound.bound.description")]=_T("The loop which will be used as a face boundary.");

description[_T("face_bound.orientation.description")]=_T("This indicates whether (TRUE), or not (FALSE) the loop has the same sense when used to bound the face as when first defined. If orientation is FALSE, the senses of all its component oriented edges are implicitly reversed when used in");

description[_T("face_outer_bound.description")]=_T("A face outer bound is a special subtype of face bound which carries the additional semantics of defining an outer boundary on the face. A face outer ­ bound shall separate the interior of the face from the exterior and shall enclose the interior domain of the face. No more than one boundary of a face shall be of this type.");

description[_T("face_surface.description")]=_T("A face surface is a subtype of face in which the geometry is defined by an associated surface. The portion of the surface used by the face shall be embeddable in the plane as an open disk, possibly with holes. However, the union of the face with the edges and vertices of its bounding loops need not be embeddable in the plane. It may, for example, cover an entire sphere or torus. As both a face and a geometric surface have defined normal directions, a BOOLEAN flag (the orientation attribute) is used to indicate whether the surface normal agrees with (TRUE) or is opposed to (FALSE) the face normal direction. The geometry associated with any component of the loops of the face shall be consistent with the surface geometry, in the sense that the domains of all the vertex points and edge curves are contained in the face geometry surface. A surface may be referenced by more than one face surface.");

description[_T("face_surface.face_geometry.description")]=_T("The surface which defines the internal shape of the face. This surface may be unbounded. The domain of the face is defined by this surface and the bounding loops in the inherited attribute SELFnface.bounds.");

description[_T("face_surface.same_sense.description")]=_T("This flag indicates whether the sense of the surface normal agrees with (TRUE), or opposes (FALSE), the sense of the topological normal to the face.");

description[_T("loop.description")]=_T("A loop is a topological entity constructed from a single vertex, or by stringing together connected (oriented) edges, or linear segments beginning and ending at the same vertex. A loop has dimensionality 0 or 1. The domain of a 0­dimensional loop is a single point. The domain of a 1­dimensional loop is a connected, oriented curve, but need not be a manifold. As the loop is a cycle, the location of its beginning/ending point is arbitrary. The domain of the loop includes its bounds, and 0 Ÿ \Xi ! 1. A loop is represented by a single vertex, or by an ordered collection of oriented edges, or by an ordered collection of points.");

description[_T("open_shell.description")]=_T("An open shell is a shell of dimensionality 2. Its domain, if present, is a finite, connected, oriented, 2­manifold with boundary, but is not a closed surface. It can be thought of as a closed shell with one or more holes punched in it. The domain of an open shell satisfies 0 ! \Xi ! 1. An open shell is functionally more general than a face because its domain can have handles. The shell is defined by a collection of faces, which may be oriented faces. The sense of each face, after taking account of the orientation, shall agree with the shell normal as defined below. The orientation can be supplied directly as a BOOLEAN attribute of an oriented face, or be defaulted to TRUE if the shell member is a face without the orientation attribute.");

description[_T("oriented_edge.description")]=_T("An oriented edge is an edge constructed from another edge and contains a BOOLEAN orientation flag to indicate whether or not the orientation of the constructed edge agrees with the orientation of the original edge. Except for possible re­orientation, the oriented edge is equivalent to the original edge. NOTE A common practice in solid modelling systems is to have an entity that represents the “use” or “traversal” of an edge. This “use” entity explicitly represents the requirement in a manifold solid that each edge must be traversed exactly twice, once in each direction. The “use” functionality is provided by the edge subtype oriented edge.");

description[_T("oriented_edge.edge_element.description")]=_T("edge entity used to construct this oriented edge.");

description[_T("oriented_edge.orientation.description")]=_T("If TRUE, the topological orientation as used coincides with the orientation, from start vertex to end vertex, of the edge element.");

description[_T("path.description")]=_T("A path is a topological entity consisting of an ordered collection of oriented ­ edges, such that the edge start vertex of each edge coincides with the edge end of its predecessor. The path is ordered from the edge start of its first oriented edge to the edge end of its last oriented edge. The BOOLEAN value orientation in the oriented edge indicates whether the edge direction agrees with the direction of the path (TRUE) or is in the opposite direction (FALSE). An individual edge can only be referenced once by an individual path. An edge can be referenced by multiple paths. An edge can exist independently of a path.");

description[_T("path.edge_list.description")]=_T("List of oriented edge entities which are concatenated together to form this path.");

description[_T("topological_representation_item.description")]=_T("");

description[_T("vertex.description")]=_T("A vertex is the topological construct corresponding to a point. It has dimensionality 0 and extent 0. The domain of a vertex, if present, is a point in m dimensional real space R m ; this is represented by the vertex point subtype.");

description[_T("vertex_loop.description")]=_T("A vertex loop is a loop of zero genus consisting of a single vertex.");

description[_T("vertex_loop.loop_vertex.description")]=_T("The vertex which defines the entire loop.");

description[_T("vertex_point.description")]=_T("A vertex point is a vertex which has its geometry defined as a point.");

description[_T("vertex_point.vertex_geometry.description")]=_T("The geometric point which defines the position in geometric space of the vertex.");

description[_T("block.description")]=_T("A block is a solid rectangular parallelepiped, defined with a location and placement coordinate system. The block is specified by the positive lengths x, y, and z along the axes of the placement coordinate system, and has one vertex at the origin of the placement coordinate system.");

description[_T("block.position.description")]=_T("The location and orientation of the axis system for the primitive. The block has one vertex at position location and its edges aligned with the placement axes in the positive sense.");

description[_T("block.x.description")]=_T("size of the block along the placement X axis,");

description[_T("block.y.description")]=_T("The size of the block along the placement Y axis");

description[_T("block.z.description")]=_T("size of the block along the placement Z axis");

description[_T("manifold_solid_brep.description")]=_T("");

description[_T("manifold_solid_brep.outer.description")]=_T("");

description[_T("right_circular_cylinder.description")]=_T("");

description[_T("right_circular_cylinder.position.description")]=_T("");

description[_T("right_circular_cylinder.height.description")]=_T("");

description[_T("right_circular_cylinder.radius.description")]=_T("");

description[_T("solid_model.description")]=_T("");

description[_T("definitional_representation.description")]=_T("");

description[_T("representation.description")]=_T("");

description[_T("representation.name.description")]=_T("");

description[_T("representation.items.description")]=_T("");

description[_T("representation.context_of_items.description")]=_T("");

description[_T("representation_context.description")]=_T("");

description[_T("representation_context.context_identifier.description")]=_T("");

description[_T("representation_context.context_type.description")]=_T("");

description[_T("representation_item.description")]=_T("");

description[_T("representation_item.name.description")]=_T("");

description[_T("advanced_face.description")]=_T("");

description[_T("advanced_brep_shape_representation.description")]=_T("");

description[_T("toleranced_length_measure.description")]=_T("Length measure with tolerance. Note that all geometric properties of the workpiece are specified using toleranced_length_measure. If the NC controller has the ability to generate toolpaths or to make decisions about the tool used, it is the controller's responsibility to meet these tolerance requirements. On the other hand, data provided to the NC controller for explicit specification of movements will have no tolerances as the controller cannot do more than try to follow the given theoretical values to the best of its abilities. The same is true for offsets and other data referring to already toleranced dimensions.");

description[_T("toleranced_length_measure.theoretical_size.description")]=_T("The theoretical length.");

description[_T("toleranced_length_measure.implicit_tolerance.description")]=_T("The type of tolerance to apply to theoretical_size.");

description[_T("plus_minus_value.description")]=_T("The plus_minuns_value describes the upper and lower limits valid for a scalar dimension referencing this entity.");

description[_T("plus_minus_value.upper_limit.description")]=_T("The value of the tolerance that shall be added to the exact value to establish the maximum allowed value.");

description[_T("plus_minus_value.lower_limit.description")]=_T("the value of the tolerance that shall be subtracted from the exact value to establish the minimum allowed value.");

description[_T("plus_minus_value.significant_digits.description")]=_T("The number of decimal digits indicating the accuracy of the lower_bound and upper_bound values.");

description[_T("limits_and_fits.description")]=_T("A Limits_and_fits contains the necessary information to express a tolerance of the limits-and-fits system standardized by ISO 286.");

description[_T("limits_and_fits.deviation.description")]=_T("The difference between a measured actual size and the corresponding basic size as defined in ISO 286-1.grade:The grade specifies the quality or the accuracy grade of a toler");

description[_T("limits_and_fits.grade.description")]=_T("");

description[_T("limits_and_fits.its_fitting_type.description")]=_T("");

description[_T("project.description")]=_T("Each part programme, i.e. data model, based on ISO14649 must include exactly one top-level entity, called project. The project indicates the workplan to be executed upon interpretation of this model (as several workplans might be included), and it may also provide the workpiece(s) upon which actions are to be performed.");

description[_T("project.its_id.description")]=_T("The project’s identifier. It shall be unique within the part programme.");

description[_T("project.main_workplan.description")]=_T("The top-level workplan in this model.");

description[_T("project.its_workpieces.description")]=_T("The workpieces upon which actions are to be performed.");

description[_T("project.its_owner.description")]=_T("Optional information on the owner of the project.");

description[_T("project.its_release.description")]=_T("Optional date and time reference of the project.");

description[_T("project.its_status.description")]=_T("Optional attribute to indicate the current status of the project.");

description[_T("person_and_address.description")]=_T("Entity includes data to name and reference a person, who for instance is responsable for creating a project.");

description[_T("person_and_address.its_person.description")]=_T("");

description[_T("person_and_address.its_address.description")]=_T("");

description[_T("workpiece.description")]=_T("The workpiece entity contains the entire description of the workpiece, if available. This includes material, surface condition and geometric data. Each workpiece has only one surface condition and one material. Dependent on the conformance class the workpiece entity includes the raw part dimension only as an including box or cylinder, or, in a higher class, as a representation which can be a complete geometric model, e.g. the state after previous manufacturing operations. All attribute’s locations, directions and geometrical information are defined relatively to the workpiece’s coordinate system.");

description[_T("workpiece.its_id.description")]=_T("The unique identification of a workpiece.");

description[_T("workpiece.its_material.description")]=_T("The material attribute identifies the workpiece material. This data shall be used for determining the technological process parameters for the manufacturing process. It can be done by the machine operator or by an automatic feed rate/cutting condition selection (from a table or a data base on the CNC).");

description[_T("workpiece.global_tolerance.description")]=_T("Tolerance for the workpiece, valid where no other tolerances are specified.");

description[_T("workpiece.its_rawpiece.description")]=_T("The rawpiece geometry of the workpiece may be described here. A recursive description is used, i.e. the rawpiece is of type workpiece itself.");

description[_T("workpiece.its_geometry.description")]=_T("An exact description of the final workpiece geometry according to ISO 10303-514.");

description[_T("workpiece.its_bounding_geometry.description")]=_T("By this attribute the workpiece´s bounding geometry might be defined as a box, a cylinder or a geometry according to the definition of the entity advanced_brep_shape_representation (ISO 10303--514).");

description[_T("workpiece.clamping_positions.description")]=_T("Positions of the clamping device on the workpiece’s surface.");

description[_T("material.description")]=_T("This entity is for identifying the workpiece material.");

description[_T("material.standard_identifier.description")]=_T("The standard used for identifying the material. This can be a national standard or one used internally in the company.");

description[_T("material.material_identifier.description")]=_T("The name which identifies the material.");

description[_T("material.material_property.description")]=_T("The parameter which describes the properties of material. Since the demand for material properties varies, a generic type „property parameter” is used.");

description[_T("property_parameter.description")]=_T("Generic property parameter which may be used to characterise any kind of property any kind of parameter might have. Subtypes are descriptive parameters (strings) and numeric parameters.");

description[_T("property_parameter.parameter_name.description")]=_T("The name of the parameter to be described.");

description[_T("descriptive_parameter.description")]=_T("A parameter description using a string to characterise the parameter.");

description[_T("descriptive_parameter.descriptive_string.description")]=_T("String value which describes the parameter.");

description[_T("numeric_parameter.description")]=_T("A parameter description using a numeric value. Both the number and the unit shall be given.");

description[_T("numeric_parameter.its_parameter_value.description")]=_T("The value which describes the parameter.");

description[_T("numeric_parameter.its_parameter_unit.description")]=_T("The units associated with the value.");

description[_T("manufacturing_feature.description")]=_T("This entity is the supertype of all manufacturing features. When considering 2½D-manufacturing, features are of type two5D_manufacturing_feature and may be holes, pockets, etc. When considering freeform manufacturing, regions are used in the same sense. The manufacturing feature describes the feature as such, e.g. by its geometric properties. It does not give any instruction on how the workpiece is manufactured. Such process related information is contained only in the operations and depends on the manufacturing method. The methods are described in the technology specific parts of ISO 14649. For example, plunging into a pocket, roughing the pocket and finishing the pocket bottom may all be individual operations, as well as the finishing of a portion of a freeform surface.");

description[_T("manufacturing_feature.its_id.description")]=_T("Each feature has an unique identifier.");

description[_T("manufacturing_feature.its_workpiece.description")]=_T("The workpiece which the feature is part of.");

description[_T("manufacturing_feature.its_operations.description")]=_T("A set of all operations associated with the feature required for the manufacturing of the feature. Note that the operations are not necessarily executed immediately after each other. Only the workplan determines the final order of operations of all operations included in a given programme, and manufacturing will typically not occur feature by feature but rather according to technological criteria like minimised tool change. However, it should be guaranteed by the CAM system (or by the controller, if the order of execution is determined by an intelligent CNC) that the order given in this attribute is never violated.");

description[_T("region.description")]=_T("The region is the equivalent of a feature in freeform machining. It describes a bounded area of the final workpiece surface to which the associated operations will be applied. Note that for freeform surfaces the regions for different operations (e.g. roughing, finishing) may have different shapes based upon technological decisions.");

description[_T("region.feature_placement.description")]=_T("The placement of the feature relative to the workpiece co-ordinate system. The placement is a translation and/or a rotation which transforms the origin of the workpiece co-ordinate system origin into the origin of the feature’s local co-ordinate system. If no feature_placement is given, the region will use workpiece co-ordinates. Regarding coordinate systems");

description[_T("region_projection.description")]=_T("A type of bounded region generated by projecting a closed curve on a surface. Thus, a region can easily be defined on an existing surface description. The region projection applies to any workpiece surface it hits when moving in space along proj_dir. This is a very simplistic region definition for situations where the use of topology is not desired.");

description[_T("region_projection.proj_curve.description")]=_T("A curve in space, used for specifying the boundary for a surface through its projection on the surface. It must be a closed curve and will usually be in one plane.");

description[_T("region_projection.proj_dir.description")]=_T("");

description[_T("region_projection.depth.description")]=_T("The depth is a positive scalar value. It describes the distance of material removal into negative z-direction of the region’s local coordinate system. The depth is measured from the raw piece’s surface, onto which the proj_curve has been projected, to the bottom to be machined. The depth is equal for the whole region. In case the bottom’s shape shall not be equal to the raw piece’s surface, the entity pocket and its subtypes have to be used.");

description[_T("region_surface_list.description")]=_T("A type of region specified by a list of surfaces. This allows for the most general description of regions. The region is bounded by the borders of the surfaces it encloses.");

description[_T("region_surface_list.surface_list.description")]=_T("List of general surfaces, allowing for various descriptions.");

description[_T("topological_region.description")]=_T("A type of region specified by a topological representation. Only faces of type advanced_face are allowed as they are certain to carry their own geometric representation.");

description[_T("two5d_manufacturing_feature.description")]=_T("The entity two5D_manufacturing_feature is the abstract supertype of all 2½D features. This structure is defined in close resemblance to ISO 10303-224.");

description[_T("two5d_manufacturing_feature.feature_placement.description")]=_T("The placement of the feature relative to the workpiece co-ordinate system. The placement is a translation and/or a rotation which transforms the origin of the workpiece co-ordinate system origin into the origin of the feature’s local co-ordinate system. For information on coordinate systems refer to Section 4.6.4.1.2. If the manufacturing feature is part of a compound_feature, then its placement is defined relative to the compound_feature´s origin.");

description[_T("machining_feature.description")]=_T("The entity machining_feature is the abstract supertype of all features used for feature based 2½D machining. In this part the following features are foreseen as they are used in different technology specific parts of ISO 14649: planar face, pocket, slot, step, hole, generic feature, and compound feature. The features are defined in close resemblance to ISO 10303-224. 2½D machining is characterised by the fact that most tool movements occur only in the xy plane while the z axis is preset to a certain depth in order to remove a layer of material. For this reason, all machining features have a depth. All feature geometry, e.g. the contour describing the outline of a pocket, is described in a local xyz co-ordinate system. The definition of the coordinate system’s orientation is given in the machining method specific parts. The surrounding surface of the workpiece and the definition of the planar contour of the feature are assumed to lie in the xy plane (z = 0). The material is assumed to be in negative z direction of the xy-plane. In other words, a positive depth within a machining operation requires the tool to advance in negative z direction into the material’s direction. As ISO 14649 allows for a 3D description of the overall workpiece geometry, the inherited attribute feature_placement specifies the actual location of the feature within the workpiece co-ordinate system.");

description[_T("machining_feature.depth.description")]=_T("The depth of the feature is described by a plane which includes the lowest points of the feature (z.LT.0) measured in the feautre’s local cartesian-cooridnate system. If the depth is not an orthogonal plane to the z-axis this implies, that the bottom of the feature is inclined. Depending on the explicit features there can be described more complex bottom shapes.");

description[_T("planar_face.description")]=_T("The planar face is used to describe machining of the outer face of a workpiece. The geometry of the planar face is given through the boundary and the depth (defined by the supertype). The depth denotes the the bottom of the material that needs to be taken away from the workpiece to reach the final shape of the feature. The elementary surface describing the depth can be inclined or orthogonal to the feature’s local z-axis. The planar face may also have one or more bosses where no cutting will be done.");

description[_T("planar_face.removal_direction.description")]=_T("The direction of material removal.");

description[_T("planar_face.course_of_travel.description")]=_T("A straight line with magnitude and direction.");

description[_T("planar_face.removal_boundary.description")]=_T("A line with direction and magnitude that when swept along a path defines the area on a workpiece for volume removal.");

description[_T("planar_face.face_boundary.description")]=_T("The complete or partial outside final shape of the workpiece after the planar cut has been applied.");

description[_T("planar_face.its_boss.description")]=_T("An optional list of entities which describe one or more bosses. A boss of a planar_face defines a part of the planar_face which is not cut during manufacturing of the planar_face.");

description[_T("pocket.description")]=_T("This is the abstract supertype for different implicit and explicit pockets. Open and closed pockets are derived from this supertype. The geometry of the pocket is defined by its contour on the outer face of the workpiece and its depth. A pocket may possess one or more bosses.");

description[_T("pocket.its_boss.description")]=_T("Optional list of bosses. This defines one or more parts of the pocket which are not cut during manufacturing of the pocket. With the cutting of the pocket, the boss is cut simultaneously.");

description[_T("pocket.slope.description")]=_T("Optional angle of the border of the pocket measured against the local z axis. Default is 0 degrees.");

description[_T("pocket.bottom_condition.description")]=_T("Possible bottom conditions of the pocket.");

description[_T("pocket.planar_radius.description")]=_T("The planar radius of a fillet, if existing within a pocket. This may be used to check against the radius of the tool tip.");

description[_T("pocket.orthogonal_radius.description")]=_T("The orthogonal radius of a fillet, if existing within a pocket. This may be used to check against the radius of the tool.");

description[_T("closed_pocket.description")]=_T("Derived from the class pocket. A closed pocket is a pocket which is surrounded by material everywhere along its circumference. Its feature boundary is given by a closed profile.");

description[_T("closed_pocket.feature_boundary.description")]=_T("The shape or outline that describes the upper edge of the pocket. It is an enclosed area that has a completely closed profile. The profile specifies the area required by a closed pocket.");

description[_T("open_pocket.description")]=_T("Derived from the class pocket. An open pocket is a pocket which is not a closed pocket. Its feature boundary is given by a wall contour.");

description[_T("open_pocket.open_boundary.description")]=_T("The outline or shape that forms the upper edge of the open_pocket. The profile specifies the area required by open pocket. When travelling along the profile based as defined by its sense, the material lies on the left side of the profile. The open_boundary lies within the features xy-plane (z=0).");

description[_T("open_pocket.wall_boundary.description")]=_T("The outline or shape that forms the side edge of the open_pocket. It forms a closed profile together with open_boundary. Note that this contour will be most likely defined implicitly by the selected tool and the fillet options inherited from machining_feature. If given, it will be informative only.");

description[_T("pocket_bottom_condition.description")]=_T("This entity describes the shape of the bottom of a pocket.");

description[_T("through_pocket_bottom_condition.description")]=_T("The pocket extends fully through the workpiece.");

description[_T("planar_pocket_bottom_condition.description")]=_T("The pocket has a plane bottom.");

description[_T("radiused_pocket_bottom_condition.description")]=_T("The pocket has a radiused bottom. As opposed to the use of the attribute planar_radius of the machining feature, which may be used to specify a fillet, the entire bottom surface will be continuously curved.");

description[_T("radiused_pocket_bottom_condition.floor_radius_center.description")]=_T("Center of the radius of the pocket floor. It is defined within the features coordinate system.");

description[_T("radiused_pocket_bottom_condition.floor_radius.description")]=_T("Radius of the pocket floor. The radius creates a portion of a sphere on the pocket floor. Concave or convex behaviour depends upon the position of floor_radius_center. Note that the diameter of the sphere must span at least the perimeter of the pocket floor, or the result will be undefined. Note that the depth of the pocket is determined by the combination of floor_radius_center and floor_radius");

description[_T("general_pocket_bottom_condition.description")]=_T("Any bottom condition not covered by planar_bottom_condition or through_bottom_condition. General pocket bottom condition defines a free-form surface at the bottom of a pocket. Similar to the compound feature, the region referenced by the attribute shape is not allowed to be associated with machining operations of its own. All machining operations to manufacture the pocket must be defined by the attribute its_operations of the pocket itself.");

description[_T("general_pocket_bottom_condition.shape.description")]=_T("Description of the pocket floor as 3D surface in local xyz co-ordinates. Note that the feature_placement attribute of shape will specify its position relative to the local coordinate system of the pocket, not relative to the workpiece co-ordinates. The pocket’s attribute depth should specify the maximum depth of the pocket. Note that the actual depth of the pocket will be determined by the shape of the surface which is defined in 3D space. It will override any conflicting data given in the attribute depth.");

description[_T("slot.description")]=_T("The entity slot is closely related to the entity pocket. Generally speaking, a slot is a special kind of pocket. ISO 10303-224 lists slot as a separate entity. To be compatible, the entity slot is also included in this schema. The attribute course_of_travel describes the location and extension of the slot. Typically, the slot will be manufactured by a single sweep of a tool along the course of travel. In this case, the width of the slot equals the shape of the tool. In case of a milling operation the shape is given by the tool’s diameter. If a workingstep which manufactures this slot calls for a smaller tool, more than one cut will have to be made.");

description[_T("slot.course_of_travel.description")]=_T("Center line of the slot. The tool is moved along this path to achieve the manufacturing of the slot. As with the entity pocket, the upper edge is given.");

description[_T("slot.swept_shape.description")]=_T("The (contoured) cross-section generated by a the tool, required for the selection of the proper tool For simple rectangular slot profiles, a square_u_profile should be specified giving only the width of the slot.");

description[_T("slot.end_conditions.description")]=_T("For a slot closed on one side, end conditions may be given here. The sequence is oriented conformable to the direction of the course_of_travel.");

description[_T("slot_end_type.description")]=_T("Supertype of slot end types.");

description[_T("woodruff_slot_end_type.description")]=_T("The end of slot shall be a radius tangent to the slot bottom and curved upward about an axis.");

description[_T("woodruff_slot_end_type.radius.description")]=_T("Radius of the slot end type. The radius continues tangential from the bottom of the slot. It starts at the bottom of the slot where the course_of_travel ends. The radius does not necessarily equal to the depth of the slot.");

description[_T("radiused_slot_end_type.description")]=_T("The end of the slot consists of an arc. The diameter equals the width of the slot. The center of the arc is identical with the end point of course_of_travel.");

description[_T("flat_slot_end_type.description")]=_T("The end of the slot consists of a flat line with two arcs connecting the end to the sides of the slot. The radii of the two arcs are given. When traversing the slot along its center line from start to finish, the radius on the left side of the center line is corner_radius1, the radius on the right side of the center line is corner_radius2. The end point of course_of_travel is in the flat end of the slot.");

description[_T("flat_slot_end_type.corner_radius1.description")]=_T("Radius of the first arc.");

description[_T("flat_slot_end_type.corner_radius2.description")]=_T("Radius of the second arc.");

description[_T("loop_slot_end_type.description")]=_T("The slot forms a loop. The attribute depth is used to determinde the scalar profoundness of the slot. The profoundness is equal to the smallest distance between the course_of_travel and the planar face described by the feature’s attribute “depth”.");

description[_T("open_slot_end_type.description")]=_T("The end of the slot is open.");

description[_T("step.description")]=_T("A step (or shoulder) is a volume of material removed from the top and the sides of the workpiece. Like an open pocket, its contour is open to its sides. The part of the V-profile describing the step’s bottom lies in the elementary surface defined by the feature’s attribute depth. The step may have one or more bosses as given by the optional attribute.");

description[_T("step.open_boundary.description")]=_T("The outline or shape that forms the upper edge of the step. When travelling along the curve based as defined by its sense, the material is to the left of the curve.");

description[_T("step.wall_boundary.description")]=_T("The outline or shape that forms the side edge of the step, i. e. the “profile” of the cut.");

description[_T("step.its_boss.description")]=_T("A step may have one or more bosses..");

description[_T("profile_feature.description")]=_T("A profile feature is a volume of material removed from the boundary shape of a workpiece. This is an abstract supertype of general outside profile and shape profile.");

description[_T("profile_feature.profile_swept_shape.description")]=_T("An 2D line, when combined with a profile, which creates the shape of the profile feature. The placement of the linear path shall be the same as the profile feature. The direction of linear shall be with the Z-axis toward the direction of travel of the profile boundary.");

description[_T("general_outside_profile.description")]=_T("A general outside profile is the removal volume of arbitrary shape from the outside shape of a workpiece. It may remove material from the entire outside shape or some portion of the shape. The contour of the shape is given by the attribute feature_boundary.");

description[_T("general_outside_profile.feature_boundary.description")]=_T("The contour of the profile to be followed by the tool. Note that this attribute describes the profile itself, not the tool path. When travelling along the profile based as defined by its sense, the material lies to the left of the profile.");

description[_T("shape_profile.description")]=_T("A shape profile is the removal volume of shaped profile from the boundary shape of a workpiece. The bottom of the boundary shape is limited by a floor condition. This is an abstract supertype of general shape profile, partial circular shape profile, circular closed shape profile, rectangular open shape profile, and rectangular closed shape profile.");

description[_T("shape_profile.floor_condition.description")]=_T("Specification of the shape of the bottom.");

description[_T("shape_profile.removal_direction.description")]=_T("A vector that points in the general direction away from the material.");

description[_T("through_profile_floor.description")]=_T("A through profile floor describes the bottom condition of a shape profile which is open.");

description[_T("profile_floor.description")]=_T("A profile floor describes the bottom condition of a shape profile which may be flat or any arbitrary shape.");

description[_T("profile_floor.floor_radius.description")]=_T("The radius of curvature for an arc between the bottom and the sides.");

description[_T("profile_floor.start_or_end.description")]=_T("If true, the profile_floor is positioned at the end of a shape_profile. If false, its is at the start of the shape_profile.");

description[_T("general_profile_floor.description")]=_T("A general_profile_floor is a type of profile_floor that specifies an enclosed area bounded by an arbitrary shape.");

description[_T("general_profile_floor.floor.description")]=_T("Specification of the face at the bottom of a shape_profile, adjacent to all the shape_profile walls.");

description[_T("planar_profile_floor.description")]=_T("A planar_profile_floor is a type of a profile_floor that characterises the bottom of a shape_profile which is flat.");

description[_T("planar_profile_floor.floor.description")]=_T("Specification of a planar face at the bottom of a shape_profile.");

description[_T("general_shape_profile.description")]=_T("A general_shape_profile is a type of shape_profile that is a volume of arbitrary shape which defines a portion of the workpiece.");

description[_T("general_shape_profile.profile_boundary.description")]=_T("Specification of the outline of the shape_profile feature. It defines an area that may or may not be entirely enclosed.");

description[_T("partial_circular_shape_profile.description")]=_T("A partial_circular_shape_profile is a type of shape_profile that defines a volume that is not enclosed on all sides.");

description[_T("partial_circular_shape_profile.open_boundary.description")]=_T("Specification of the outline of the shape_profile feature. It defines an area that shall be circular and shall not be enclosed.");

description[_T("circular_closed_shape_profile.description")]=_T("A circular_closed_shape_profile is a type of shape_profile that defines a completely enclosed volume. This may have a thread.");

description[_T("circular_closed_shape_profile.closed_boundary.description")]=_T("Specification of the outline of the shape_profile feature. It defines an area that shall be enclosed and circular.");

description[_T("rectangular_open_shape_profile.description")]=_T("A rectangular_open_shape_profile is a type of shape_profile that is an open profile with opposite sides that are of equal length and with one side that does not make contact with the workpiece.");

description[_T("rectangular_open_shape_profile.open_boundary.description")]=_T("Specification of the outline or shape that is an enclosed area that is open on one side.");

description[_T("rectangular_closed_shape_profile.description")]=_T("A rectangular_closed_shape_profile is a type of shape_profile that is an enclosed volume with opposite sides that are equal in length.");

description[_T("rectangular_closed_shape_profile.closed_boundary.description")]=_T("Specification of the outline or shape that is an enclosed area that has a completely closed profile.");

description[_T("round_hole.description")]=_T("This entity defines both holes and threaded holes. The feature_placement of a hole is the center point at the surface, i. e. the hole is located at x = y = 0 in the local co-ordinate system. The specified (positive) depth causes the tool to advance into the hole in negative z direction.");

description[_T("round_hole.diameter.description")]=_T("The diameter of the hole. The diameter is measured in the xy-plane where z = 0.");

description[_T("round_hole.change_in_diameter.description")]=_T("An optional parameter used to specify holes with a taper.");

description[_T("round_hole.bottom_condition.description")]=_T("Specification of the bottom of a hole.");

description[_T("diameter_taper.description")]=_T("Entity to describe a taper by its final diameter.");

description[_T("diameter_taper.final_diameter.description")]=_T("The final diameter of the tapered hole at the indicated depth.");

description[_T("angle_taper.description")]=_T("Entity to describe a taper by its half angle.");

description[_T("angle_taper.angle.description")]=_T("The angle of the tapered hole.");

description[_T("hole_bottom_condition.description")]=_T("Abstract supertype for the description of a bottom of a hole.");

description[_T("through_bottom_condition.description")]=_T("Entity which describes a hole bottom which is open.");

description[_T("blind_bottom_condition.description")]=_T("Supertype to describe different types of blind bottom conditions. The bottom may break through the bottom of the workpiece, but is not entirely open. The depth of the hole is the length of the cylindrical section of the hole.");

description[_T("flat_hole_bottom.description")]=_T("A hole with a flat bottom.");

description[_T("flat_with_radius_hole_bottom.description")]=_T("A hole with a flat bottom which has a radius.");

description[_T("flat_with_radius_hole_bottom.corner_radius.description")]=_T("The radius of the corner in the bottom.");

description[_T("spherical_hole_bottom.description")]=_T("A hole with a spherical bottom.");

description[_T("spherical_hole_bottom.radius.description")]=_T("The radius of the spherical hole bottom.");

description[_T("conical_hole_bottom.description")]=_T("A hole with a conical bottom, as manufactured with a standard drill. A conical bottom is a constant decrease in diameter until the diameter is ‘zero’, or until it becomes tangent to a tip radius.");

description[_T("conical_hole_bottom.tip_angle.description")]=_T("The angle of the tip.");

description[_T("conical_hole_bottom.tip_radius.description")]=_T("Optional attribute for specification of a tip radius. Default is zero.");

description[_T("toolpath_feature.description")]=_T("To enable the definition of tool movements not covered by the previously listed features, the toolpath_ feature has been introduced. Explicit toolpaths shall be assigned to the operations associated with this feature.");

description[_T("boss.description")]=_T("A boss is a feature which has to be related to an other feature. No separate workingstep can be assigned to manufacture a boss (i.e. it is not possible to first cut the feature and then cut the boss). Instead, the boss is that material which remains unworked after the machining of a feature with a boss. For this reason, boss is not an independent machining feature but exists only as an attribute.");

description[_T("boss.its_boundary.description")]=_T("The contour of the boss at the top of the boss. The contour at the bottom may be calculated by traversing the slope along the contour. Also, for the boss to have a well-defined height, its_boundary should be parallel to the bottom of the parent feature. When travelling along the profile based as defined by its sense, the material is to the left of the profile.");

description[_T("boss.slope.description")]=_T("The slope of the contour of the boss relative to the local z axis of the parent feature. The default is 0 degrees.");

description[_T("spherical_cap.description")]=_T("This feature is circular about an axis of rotation. It consists of all points at a given distance from a point constituting its center. The center is defined by it's placement, that is not located in the feature's highest point, but in the sphere's center.");

description[_T("spherical_cap.internal_angle.description")]=_T("The size of an angle from an axis for defining a portion of a sphere.");

description[_T("spherical_cap.radius.description")]=_T("The constant distance from a point for defining a sphere.");

description[_T("rounded_end.description")]=_T("A rounded end is a partially circular shape passed along a linear path.");

description[_T("rounded_end.course_of_travel.description")]=_T("A straight line with magnitude and direction.");

description[_T("rounded_end.partial_circular_boundary.description")]=_T("The arc that when swept along a path defines the area on a workpiece for volume removel.");

description[_T("compound_feature.description")]=_T("A compound feature is a feature composed of two or more features. As opposed to the replicate feature, there is no regular spacing between the elements of the compound feature. In general, they will also not be of the same type. The volume of removed material of the compound feature is the union of all volumes of the elements of the compound feature. It is illegal to create a compound feature where the volumes of the elements are not connected in such a way that their union can be machined. Note that the individual elements of the compound feature are associated with machining operation. In addition the compound feature includes by the attribute its_operations all operations of its minor elements.");

description[_T("compound_feature.elements.description")]=_T("Set of features composing the compound feature. Note that the feature_placement attribute of the elements will specify their position relative to the local co-ordinate system of the compound feature, not relative to the workpiece co-ordinates.");

description[_T("counterbore_hole.description")]=_T("The counterbore hole is a type of compound feature that consists of two round_holes. The round hole closer to the counterbore’s placement has to have a larger diameter than the one more inside of the material. The bottom of the former round_hole shall mate with the top of the latter round_hole. The orientation of counterbore_hole shall be the same as the orientation of the latter round_hole. Both round_holes shall be co-axial.");

description[_T("countersunk_hole.description")]=_T("The countersunk hole is a type of compound feature that consists of two round_holes. The bottom of the round_hole closer to the countersunk’s placement shall mate with the top of the round_hole more inside of material. The taper of the former round_hole shall be larger than the diameter of the latter round_hole, decreasing to the same diameter at the point where the two holes join. The orientation of countersunk_hole shall be the same as the orientation of the latter round_hole. Both round_holes shall be co-axial.");

description[_T("replicate_feature.description")]=_T("A replicate is an assembly of a number of similar features, e.g. a circle of holes or a mesh of holes. The feature is described only once and the number and spacing of the feature is described. Note that the attribute");

description[_T("replicate_feature.replicate_base_feature.description")]=_T("The feature which forms the basis of the replicate feature.");

description[_T("circular_pattern.description")]=_T("A circular pattern of features. A complete circle of features is a special case of circular pattern.");

description[_T("circular_pattern.angle_increment.description")]=_T("Angle between two elements of the pattern. A positive angle means a counterclockwise increment when looking towards the plane in negative z direction.");

description[_T("circular_pattern.number_of_feature.description")]=_T("The total number of features in the replicate_feature. The maximum index of the circular pattern is calculated from number_of_feature plus the number of elements in the missing_base_feature set. The maximum index times angle_increment should not exceed 360° or the behaviour will be undefined.");

description[_T("circular_pattern.relocated_base_feature.description")]=_T("Optional description of relocated features.");

description[_T("circular_pattern.missing_base_feature.description")]=_T("Optional description of omitted features.");

description[_T("circular_pattern.base_feature_diameter.description")]=_T("The diameter of the circular pattern. It has to be specified if rotate_feature is \")false\". If it is \")true\", the diameter can be calculated from the feature position and the location of the center.");

description[_T("circular_pattern.base_feature_rotation.description")]=_T("Specification of the angle to rotate one element in regard to the orientation of the previous element. The previous element is located in mathematical negative direction (counter-clockwise) to the current element.");

description[_T("circular_offset.description")]=_T("Definition of elements offset from the circle of elements.");

description[_T("circular_offset.angular_offset.description")]=_T("Offset of angle of the relocated element.");

description[_T("circular_offset.index.description")]=_T("Number of the relocated element.");

description[_T("circular_omit.description")]=_T("Definition of elements omitted from the circle of elements.");

description[_T("circular_omit.index.description")]=_T("Number of the element to be omitted.");

description[_T("rectangular_pattern.description")]=_T("The description of elements arranged in a rectangular pattern. This may be either a grid of elements with n rows and m columns and a total number of n x m elements or a single line of m elements (n=1).");

description[_T("rectangular_pattern.spacing.description")]=_T("The spacing of the columns of the pattern. If there is only one row, this is also the spacing between the elements.");

description[_T("rectangular_pattern.its_direction.description")]=_T("Direction of the first row measured from the direction given in feature_placement. It points into the direction of the row, describing the order to manufacture the replicated feature.");

description[_T("rectangular_pattern.number_of_rows.description")]=_T("The number of rows. Default is one, i. e. the rectangular pattern is a line of features. If number_of_rows is larger than one, the attributes row_spacing and row_layout_direction need to be specified.");

description[_T("rectangular_pattern.number_of_columns.description")]=_T("The number of columns.");

description[_T("rectangular_pattern.row_spacing.description")]=_T("The spacing of the rows (optional, needed if number_of_rows is larger than one). row_layout_direction: Optional description of the direction of the first column measured from the direction given in feature_placement. It points into the direction of the next row");

description[_T("rectangular_pattern.row_layout_direction.description")]=_T("");

description[_T("rectangular_pattern.relocated_base_feature.description")]=_T("Optional description of relocated features.");

description[_T("rectangular_pattern.missing_base_feature.description")]=_T("Optional description of missing features. Note that the number of features can be calculated from the number_of_rows, number_of_columns, missing_base_feature, and relocated_base_feature.");

description[_T("rectangular_offset.description")]=_T("Entity to describe the position of a single relocated element whitin a rectangular pattern of elements.");

description[_T("rectangular_offset.offset_direction.description")]=_T("Direction of the offset of the element.");

description[_T("rectangular_offset.offset_distance.description")]=_T("Amount of offset of the element.");

description[_T("rectangular_offset.row_index.description")]=_T("Row of the offset element.");

description[_T("rectangular_offset.column_index.description")]=_T("Column of the offset element.");

description[_T("rectangular_omit.description")]=_T("Entity to omit one or more elements of a rectangular pattern of elements.");

description[_T("rectangular_omit.row_index.description")]=_T("ow of the omitted element.");

description[_T("rectangular_omit.column_index.description")]=_T("Column of the omitted element.");

description[_T("general_pattern.description")]=_T("Definition of a general list of identical elements (used i.e. for identical holes positioned arbitrarily).");

description[_T("general_pattern.replicate_locations.description")]=_T("List of the placement of the features relative to the local co-ordinate system of general_pattern. The order of the features to be machined is given by the sequence of the features’ placements within the list.");

description[_T("transition_feature.description")]=_T("A transition feature may be added at the border of two features. Example: An edge round or a chamfer between two planar faces or between a planar face and a pocket. Unlike in ISO 10303-224, only those transition features which are generated using additional tool movements are considered here. Example: An edge round between a pocket and a planar face needs an additional manufacturing operation (workingstep). On the contrary, a fillet between the sides and the bottom of a pocket results from the geometry of the tool and thus needs no additional tool movement. It is therefore not considered in this context.");

description[_T("transition_feature.first_feature.description")]=_T("The first of the two features connected by the transition feature.");

description[_T("transition_feature.second_feature.description")]=_T("The second of the two features connected by the transition feature.");

description[_T("chamfer.description")]=_T("A chamfer is one of the two defined transition features for 2½D-machining This chamfer is always an outer chamfer as only this can be generated in an separate manufacturing operation.");

description[_T("chamfer.angle_to_plane.description")]=_T("Angle between the first feature and the chamfer face measured from the first feature.");

description[_T("chamfer.first_offset_amount.description")]=_T("The offset of the chamfer measure from the edge of the first feature.");

description[_T("edge_round.description")]=_T("An edge round is the other of the two defined transition features. In 2½D-machining, it is generated using a contoured tool which has to be selected according to the given fillet radius. The edge_round is always an outer fillet, since only this type of fillet can be manufactured in an extra manufacturing operation.");

description[_T("edge_round.radius.description")]=_T("Radius of the edge round.");

description[_T("edge_round.first_offset_amount.description")]=_T("The edge_round may or may not be tangent to the two features, this attribute specifies the location of the edge round");

description[_T("edge_round.second_offset_amount.description")]=_T("A non-tangent edge_round may or may not be symmetrical to the two features. If it is not symmetrical, this feature specifies the location of the edge round");

description[_T("thread.description")]=_T("A thread is a ridge of a uniform section on the form of a helix on the external or internal surface of a cylinder. Each thread is either a catalogue_thread or a defined_thread.");

description[_T("thread.partial_profile.description")]=_T("Specification of limitations of a surface to be applied on the thread.");

description[_T("thread.applied_shape.description")]=_T("Physical shape of the workpiece that will define where the thread will be applied.");

description[_T("thread.inner_or_outer_thread.description")]=_T("A flag specifies whether or not a thread is applied as an internal thread or an external thread.");

description[_T("thread.qualifier.description")]=_T("Additional text information that describes a thread.");

description[_T("thread.fit_class.description")]=_T("The value for the type of fit specification. These types are distinguished from each other by the amount of the tolerance and allowance.");

description[_T("thread.form.description")]=_T("The definition of the shape of the thread. Various forms of threads are used to hold parts together, to adjust parts with reference to each other, or to transmit power.");

description[_T("thread.major_diameter.description")]=_T("The dimension of the largest diameter of the thread and is applied to both an internal and external thread.");

description[_T("thread.number_of_threads.description")]=_T("The thread pitch when used with metric unit of measure and the density of threads per inch when used with English unit of measure.");

description[_T("thread.thread_hand.description")]=_T("A description of whether the thread is right or left handed. When viewed toward an end, a right hand winds in a clockwise direction and a left hand winds in a counterclockwise direction.");

description[_T("partial_area_definition.description")]=_T("A partial_area_definition includes the limitations of a surface for applying a thread. It places a limitation on how much and where to apply the thread on the cylindrical shape.");

description[_T("partial_area_definition.effective_length.description")]=_T("The length of the thread which is usable.");

description[_T("partial_area_definition.placement.description")]=_T("The location and direction of the partial_area_definition.");

description[_T("partial_area_definition.maximum_length.description")]=_T("The dimension along a surface to apply a thread. It limits The dimensional distance limits the length along the surface axis for defining a thread.");

description[_T("catalogue_thread.description")]=_T("A catalogue_thread is a type of thread that is defined by a document containing the information to create threads on a workpiece.");

description[_T("catalogue_thread.documentation.description")]=_T("Specification of the document that defines information pertaining to a thread.");

description[_T("specification.description")]=_T("A specification is a document that defines information pertaining to properties or processes for a workpiece or an aspect of a workpiece.");

description[_T("specification.constraint.description")]=_T("A set of the restrictions on the specification.");

description[_T("specification.specification_id.description")]=_T("A unigue identifier of the document.");

description[_T("specification.specification_description.description")]=_T("A description of the content of the specification and any notes in human interpretable prose.");

description[_T("specification.specification_class.description")]=_T("A section within a specification that is divided into classes.");

description[_T("specification_usage_constraint.description")]=_T("A specification_usage_constraint is a restriction on the application of information defined within a specification.");

description[_T("specification_usage_constraint.element.description")]=_T("The particular piece specification. or area of information that is being restricted");

description[_T("specification_usage_constraint.class_id.description")]=_T("The data or range of data with respect to the element that defines the restriction imposed on the usage of the specification.");

description[_T("defined_thread.description")]=_T("A defined_thread is a type of thread that is specified explicitly.");

description[_T("defined_thread.pitch_diameter.description")]=_T("The dimension of an imaginary cylinder passing through the thread so as to make equal the widths of the threads and the widths of the spaces cut by the cylinder.");

description[_T("defined_thread.minor_diameter.description")]=_T("The dimension of the smallest diameter of the defined_thread and is applied to both an internal and external thread.");

description[_T("defined_thread.crest.description")]=_T("The distance between the opposing points of the thread. It is formed by the intersection of the sides of the thread if extended, if necessary, beyond the top of the thread.");

description[_T("profile.description")]=_T("A profile is a planar outline used in the definition of a feature. A profile may be either open or closed. A profile shall be in the X-Y plane and may have an orientation that will position it in reference to the local coordinate system of a manufacturing_feature, which may require a profile as a part of its definition.");

description[_T("profile.placement.description")]=_T("Specification where to locate the profile in reference to the orientation of the manufacturing_feature. If not given, the orientation is at the zero point of the manufacturing_feature.");

description[_T("open_profile.description")]=_T("An open_profile is a type of profile that is an outline or shape with no enclosing or confining bounds. The open ends of the profile may extend infinitely.");

description[_T("linear_profile.description")]=_T("A linear_profile is a type of open_profile that is a straight line of a specified length. The linear_profile shall have orientation parallel to the X-axis.");

description[_T("linear_profile.profile_length.description")]=_T("The length of the profile.");

description[_T("square_u_profile.description")]=_T("A square U profile is a type of open profile that is bounded by three lines. One is the base line and has a defined length. The other two lines begin at the ends of the base line, and extend infinitely at any obtuse or acute angle that is equal to or larger than a right angle. The corners of the square U profile need not be blended by a radius.");

description[_T("square_u_profile.width.description")]=_T("he size of the base line for a square U profile.");

description[_T("square_u_profile.first_radius.description")]=_T("The radius shape blend between one side of the profile and the base.");

description[_T("square_u_profile.first_angle.description")]=_T("The angle of the one side of the profile measured against the local z axis.");

description[_T("square_u_profile.second_radius.description")]=_T("The radius shape blend between the second side of the profile and the base.");

description[_T("square_u_profile.second_angle.description")]=_T("The angle of the another side of the profile measured against the local z axis.");

description[_T("rounded_u_profile.description")]=_T("A rounded U profile is a type of open profile that is a shape bounded by two parallel lines and a semicircle.");

description[_T("rounded_u_profile.width.description")]=_T("Distance across the rounded u profile.");

description[_T("tee_profile.description")]=_T("A T profile is a type of open profile the cross-section of which has the shape of the letter \")T\". The attributes are");

description[_T("tee_profile.first_angle.description")]=_T("Angular measurement for creating a chamfer on the open end.");

description[_T("tee_profile.second_angle.description")]=_T("Angular measurement for creating a chamfer between the stem and the cross bar parts of a T profile.");

description[_T("tee_profile.cross_bar_width.description")]=_T("Width of the T cross bar.");

description[_T("tee_profile.cross_bar_depth.description")]=_T("Depth of the T cross bar.");

description[_T("tee_profile.radius.description")]=_T("Arc size for blending the sides of a tee cross bar.");

description[_T("tee_profile.width.description")]=_T("Width of the T stem.");

description[_T("tee_profile.first_offset.description")]=_T("Distance from the edge of the T stem to create a chamfer on the open end.");

description[_T("tee_profile.second_offset.description")]=_T("Distance from the edge of the T stem to create a chamfer a distance from the edge of a surface to the finish of a chamfer.");

description[_T("vee_profile.description")]=_T("A V profile is a type of open profile that is a shape bounded by two lines that connect at a point and extend infinitely. The enclosed angle is less than 180 degrees.");

description[_T("vee_profile.profile_radius.description")]=_T("Size of the blend radius at the point of the V or where the two sides come together.");

description[_T("vee_profile.profile_angle.description")]=_T("The size of the angle between the two sides of the V profile.");

description[_T("vee_profile.tilt_angle.description")]=_T("The size of the angle between one side of the V profile and the surrounding workpiece surface.");

description[_T("partial_circular_profile.description")]=_T("A partial circular profile is a type of open_profile that is specified by an arc. The arc shall be a constant radius swept about a point. The orientation of the profile shall be positioned at the origin of the are, with one end point of the arc on the X-axis.");

description[_T("partial_circular_profile.radius.description")]=_T("The size of the arc to define a partial circular profile");

description[_T("partial_circular_profile.sweep_angle.description")]=_T("The size of the angle to define a circular shaped profile.");

description[_T("general_profile.description")]=_T("Any profile as defined by an arbitrary contour.");

description[_T("general_profile.its_profile.description")]=_T("A contour describing the general profile.");

description[_T("closed_profile.description")]=_T("A closed_profile is a type of profile that is an outline or shape that bounds an enclosed area with no opening.");

description[_T("rectangular_closed_profile.description")]=_T("A rectangular_closed_profile is a type of closed_profile that is an enclosed area bounded by four sides with opposite sides equal in length and corners at 90 degrees. The orientation is at the center of the rectangle, the X- axis is parallel to the length of the rectangle and the Y-axis is parallel to the width.");

description[_T("rectangular_closed_profile.profile_width.description")]=_T("The size of the shortest side of the rectangular_profile.");

description[_T("rectangular_closed_profile.profile_length.description")]=_T("The size of the longest side of the rectangular_profile.");

description[_T("circular_closed_profile.description")]=_T("A circular_closed_profile is a type of closed_profile that is an enclosed area bounded by a circle. The orientation is at the center of the circle.");

description[_T("circular_closed_profile.diameter.description")]=_T("The distance across the circular_closed_profile.");

description[_T("ngon_profile.description")]=_T("An ngon_ profile is a type of closed_profile that is an enclosed area bounded by three or more connected straight line sides. The orientation is at the center of the profile with one side of the ngon parallel to the X-axis crossing the Y-axis at a negative value.");

description[_T("ngon_profile.diameter.description")]=_T("The size of the circle which surrounds the ngon or is surrounded by the ngon. It depends on the flag of circumscribed_or_across_flats.");

description[_T("ngon_profile.number_of_sides.description")]=_T("Number of sides needed for the ngon.");

description[_T("ngon_profile.circumscribed_or_across_flats.description")]=_T("If false, the ngon is surrounded by a circle with the specified diameter. If true, the ngon surrounds a circle with the specified diameter.");

description[_T("general_closed_profile.description")]=_T("A general_closed_profile is a type of closed_profile that is an enclosed area bounded by a arbitrary shape. The orientation is defined by the explicit geometry of the shape.");

description[_T("general_closed_profile.closed_profile_shape.description")]=_T("A bounded curve that defines the arbitrary shape of the profile.");

description[_T("travel_path.description")]=_T("A travel_path is a continuous set of curves that define a direction of travel. These curves do not intersect or duplicate themselves. A travel_path may have its own orientation in reference to the local coordinate system of the machining_feature which requires it as a part of a feature definition.");

description[_T("travel_path.placement.description")]=_T("Specification where to locate the travel_path in referencmanufacturing_feature. If not given, the orientation ismanufacturing_feature.");

description[_T("general_path.description")]=_T("A General_path is a type of path that is a direction of travel along an arbitrary curve.");

description[_T("general_path.swept_path.description")]=_T("A continuous set of curves that define an arbitrary direction of travel.");

description[_T("linear_path.description")]=_T("A linear_path is a type of path that is a direction of travel along a line.");

description[_T("linear_path.distance.description")]=_T("The length of the path.");

description[_T("linear_path.its_direction.description")]=_T("A vector which indicates the direction of the path starting from the path placement.");

description[_T("circular_path.description")]=_T("The cicular_path is a type of path that is a direction of travel along an arc of constant radius around the Z-axis of the feature.");

description[_T("circular_path.radius.description")]=_T("The constant distance from an axis for the circular_path");

description[_T("complete_circular_path.description")]=_T("A complete_circular_path is a type of circular_path that is a direction of travel that begins and ends the same point on the arc.");

description[_T("partial_circular_path.description")]=_T("A partical_circular_path is a type of circular_path that is a direction of travel along an arc of constant radius around an axis. The path shall begin and end at different points on the arc.");

description[_T("partial_circular_path.sweep_angle.description")]=_T("The size of the angle to define an arc shaped path.");

description[_T("surface_texture_parameter.description")]=_T("A Surface_texture_parameter is a combination of a parameter name and possibly indices describing one particular parameter of a surface texture such as roughness or waviness");

description[_T("surface_texture_parameter.its_value.description")]=_T("The value of the surface_texture_parameter.");

description[_T("surface_texture_parameter.parameter_name.description")]=_T("The name of the surface_tex");

description[_T("surface_texture_parameter.measuring_method.description")]=_T("The measuring_method specifies the method or standard that describes the method used to characterize the Surface_texture. Where applicable the following values shall be used: 'ISO 4287': The used surface texture parameters are defined in ISO 4287; 'ISO 12085': The used surface texture parameters are defined in ISO 12085; 'ISO 13565': The used surface texture parameters are defined in ISO 13565.");

description[_T("surface_texture_parameter.parameter_index.description")]=_T("An index that specifies the name of the measuring_method further.");

description[_T("surface_texture_parameter.applied_surfaces.description")]=_T("Physical surface of machining_feature that will define where the surface_texture_parameter will be applied.");

description[_T("machined_surface.description")]=_T("The physical surface of machining_feature where the surface_texture_parameter will be applied.");

description[_T("machined_surface.its_machining_feature.description")]=_T("The physical shape of the workpiece where the machined_surface belongs.");

description[_T("machined_surface.surface_element.description")]=_T("The selection of the location of the machined_surface in reference to its_machining_feature");

description[_T("executable.description")]=_T("Executable is the base entity of all executable objects. They initiate actions on a machine and shall be arranged in a defined order. There are three types of executable objects: workplans, nc_function, and workingstep.");

description[_T("executable.its_id.description")]=_T("The executable’s identifier. It shall be unique within the part program.");

description[_T("workingstep.description")]=_T("The workingsteps represent the essential building blocks of an ISO 14649 NC programme. They can either be technology-independent actions, like rapid movements or probing operations, or machining workingsteps which relate to the different technologies like milling, drilling, turning etc. The actual content of the workingsteps is specified in the entity operation and its subtypes. The reason for this design is the possibility to re-use the information specified for an operation for several features of the workpiece. An operation can be associated with multiple features and can be used in different locations. A workingstep, on the other hand, is unique. Duplicating a workingstep in a workplan will replicate the exact same physical machine action. For more information on operations");

description[_T("workingstep.its_secplane.description")]=_T("The security plane for the workingstep. On or above this plane, i. e. for z values greater than those of the elementary_surface, a safe movement of the tool without danger of collision is possible. The dimensions given are relative coordinates as measured from the workpiece co-ordinate system or, if this workingstep is associated with a manufacturing_feature, in the local co-ordinate system of the feature.");

description[_T("machining_workingstep.description")]=_T("Machining workingsteps represent the machining process for a specified area of the workpiece. As opposed to the other workingsteps, machining workingsteps cannot exist independent of a feature. Rather, they specify the association between a distinct feature and an operation to be performed on the feature. This removes the ambiguity of the n:1 relation between features and operations, thus creating an unambiguous specification which can be executed by the machine. As the underlying operation, the machining workingstep is characterised by the use of a single tool and a set of technological parameters which normally remain constant during the reign of this machining workingstep. Upon the execution of a machining workingstep the first operation will be, if necessary, a tool change. During the machining workingstep, no tool change is possible. The machine is instructed to reach the operating conditions specified by its_operation (attributes its_tool and its_technology) before the operation of the workingstep commences. If the machine is unable to reach these conditions during the preceding workingstep (e.g. during a preceding rapid movement) a halt will occur before the execution of the workingstep until all parameters are stable. See the technology specific parts of ISO 14649 for details on operations, especially on how the association between the feature and the operation will change the interpretation of the operation.");

description[_T("machining_workingstep.its_feature.description")]=_T("The manufacturing_feature upon which the workingstep operates. its_operation:The opera");

description[_T("machining_workingstep.its_operation.description")]=_T("The operation.");

description[_T("machining_workingstep.its_effect.description")]=_T("The change to the geometry of the workpiece effected by the operation. A CAM system can use this attribute to describe the predicted effect of this operation on the geometry of the workpiece. If given the controller can compare the geometry change described by this attribute with the geometry change predicted by its internal algorithm. ISO 14649 does not describe how closely the two geometries must match in order for the controller to be considered to be in conformance.");

description[_T("in_process_geometry.description")]=_T("Entity to represent in-process geometry for additional checking routines. A CAM system can use this information to describe the predicted effect of an operation on one feature. The controller can compare the geometry given in this entity with the geometry change predicted by its internal algorithm. ISO 14649 does not describe how closely the two geometries must match in order for the controller to be considered to be in conformance.");

description[_T("in_process_geometry.as_is.description")]=_T("Attribute to describe the geometry before an operation is executed.");

description[_T("in_process_geometry.to_be.description")]=_T("Attribute to describe the desired effect of an operation.");

description[_T("in_process_geometry.removal.description")]=_T("Volume removed by an operation.");

description[_T("rapid_movement.description")]=_T("For rapid movements between two workingsteps the entity rapid_movement is used. If no toolpath is given, i. e. the inherited attribute its_toolpath is not set, the NC controller will move the tool in rapid motion from the current position to the beginning of the next workingstep which needs to have a defined starting point. The connection will be done via the security plane. If a toolpath is specified, this toolpath will be executed in rapid motion. Note that a toolpath of type parameterised path can be used so as to avoid an explicit toolpath definition in cartesian space. This will provide greater flexibility in case of changing start and/or end points of the neighbouring workingsteps. Unlike a machining workingstep, the rapid movement by itself has no well-defined start and end point unless an explicit toolpath is specified in cartesian space. If rapid_movement is used during a five-axis machining operation, it will interpolate the tool direction between the previous and the next workingstep. In this case, the tool will retract in the tool direction from the last point of the previous workingstep. On the security plane the tool will rotate to the new tool direction, and then it will move down in the tool direction for the first point of the next workingstep. No change of the tool direction takes place during the lift and approach to and from the security plane. However, if a toolpath is specified and the toolpath contains an explicit definition of the toolaxis then this definition will prevail.");

description[_T("return_home.description")]=_T("This workingstep positions all machine axes to the machine-defined home position in the absolute machine coordinate system with a pre-defined sequence. This should normally be the last operation in a workplan.");

description[_T("touch_probing.description")]=_T("This is the supertype of touch probe workingsteps. Unlike other workingsteps, touch_probing returns a value for further consideration by the NC programme. In future releases of this part of ISO 14649, touch_probing may be moved to a separate part specifying operations for measurement equipment. In this case it will become a subtype of machining_operation and needs to be associated with an appropriate measurement feature.");

description[_T("touch_probing.measured_offset.description")]=_T("The measured value of probing.");

description[_T("workpiece_probing.description")]=_T("Probing of a dimension with one axis movement. Probing tool movement starts at start_position in the direction \")direction\" towards the workpiece. When the probe tool touches the workpiece, the machine stops and the difference of expected_value and tool position is stored in the inherited attribute measured_offset. Like machining_workingstep, workpiece_probing has a well defined start point and cannot be the first element in a workplan.");

description[_T("workpiece_probing.start_position.description")]=_T("The starting position for the probing operation.");

description[_T("workpiece_probing.its_workpiece.description")]=_T("The workpiece to be probed.");

description[_T("workpiece_probing.its_direction.description")]=_T("The direction of the probing movement.");

description[_T("workpiece_probing.expected_value.description")]=_T("The approximate value for probing.");

description[_T("workpiece_probing.its_probe.description")]=_T("The identification of the probe which has to be used.");

description[_T("workpiece_complete_probing.description")]=_T("This entity is similar to workpiece probing only that a complete measurement cycle at six locations of the given workpiece is automatically performed and the translation and rotational offset of the detected workpiece position compared to the given workpiece is computed. The locations of probing are automatically determined by the NC controller based on the geometry of the workpiece. The offset vector is returned in computed_offset while the inherited attributed measured_offset will hold the average of all (six) measured offsets. Based on the automatic determination of the probing locations, workpiece_complete_probing does not have a well defined start point.");

description[_T("workpiece_complete_probing.its_workpiece.description")]=_T("The workpiece to be probed.");

description[_T("workpiece_complete_probing.probing_distance.description")]=_T("The distance between the probe’s tip and the workpiece normal to its surface at the beginning of each probing movement. This value should be well above the maximum expected deviation between the actual position and the workpiece position specified by its_workpiece.");

description[_T("workpiece_complete_probing.its_probe.description")]=_T("The identification of the probe which has to be used.");

description[_T("workpiece_complete_probing.computed_offset.description")]=_T("The attributes ‘translation’ and ‘rotate’ describe the actual workpiece position compared to the position specified by the respective setup. It is computed as a result of the (six) measurements performed by this workingstep.");

description[_T("touch_probe.description")]=_T("This gives an identification of touch probe which has to be used for workpiece probing.");

description[_T("touch_probe.its_id.description")]=_T("The identification of touch probe used.");

description[_T("offset_vector.description")]=_T("This entity is used to store the offset resulting from a workpiece probing operation. All variables must have initial values, most likely zeros.");

description[_T("offset_vector.translate.description")]=_T("Variables to store the translation required in each co-ordinate direction (x-, y-, z- axis) in order to move from the theoretical position to the actual position, measured in millimetres.");

description[_T("offset_vector.rotate.description")]=_T("Variables to store the rotation around the x-, y-, and z-axis, respectively, in order to move from the theoretical position to the actual position, measured in degrees. If omitted, only the translational offset will be considered.");

description[_T("tool_probing.description")]=_T("Probing of the length and width/diameter of a tool. The selected tool starts its movement at a machine dependent start position. From that position the tool position is shifted to a fixed sensor position by the offset. Then the tool is moved in direction to the sensor until contact. This is done in longitudinal and perpendicular direction of the tool- axis. The result of probing is stored in the inherited attribute measured_offset and the NC controllers tool database is automatically updated. NC controllers providing tool correction algorithms are expected to use the updated information of its_tool from the moment the tool_probing workingstep has been completed.");

description[_T("tool_probing.offset.description")]=_T("location of the sensor.");

description[_T("tool_probing.max_wear.description")]=_T("maximum permissible wear in length direction.");

description[_T("tool_probing.its_tool.description")]=_T("The tool which has to be probed.");

description[_T("machining_tool.description")]=_T("This is the supertype for all tools which are needed for machining. They are to be specified in the technology- specific parts of ISO 14649 or future standards might be referenced.");

description[_T("machining_tool.its_id.description")]=_T("An unique label to exactly identify the tool.");

description[_T("cutting_tool.description")]=_T("Entity to describe the basic information needed for cutting tool description, which includes all type tools for chipping technologies (e.g. lathe tool, milling cutter, reamer, drill, tap, boring tool). As Part 10 cannot be implemented without at least one specific technology dependent part this Entity only includes general data and therefore is an abstract supertype.");

description[_T("cutting_tool.its_tool_body.description")]=_T("The information describing the kind of cutting tool and it’s corresponding characteristics.");

description[_T("cutting_tool.its_cutting_edge.description")]=_T("The information describing the cutting edge(s) of the cutting tool.");

description[_T("cutting_tool.overall_assembly_length.description")]=_T("The entire length of the assembled tooling measured along the tooling axis for tool collision check.");

description[_T("tool_body.description")]=_T("This is the abstract supertype for all types of tool bodies. These tools may be of any kind used for chipping technologies. The subtypes will be defined in the technology specific parts of ISO 14649.");

description[_T("cutting_component.description")]=_T("Entity to describe the name of the material composing the cutting edge of a solid tool or the insert and it’s technological data.");

description[_T("cutting_component.tool_offset_length.description")]=_T("The measured distance from the cutting tip to a designated standard reference point on the tool holding assembly for tool presetting.");

description[_T("cutting_component.its_material.description")]=_T("The identification of the material composing the cutting edge of a solid tool or the insert. (Examples: The attribute material_identifier of the entity material can be High speed steel(HSS), Carbide, or Polycrystalline diamond(PCD) [ISO/CD 13399-3, Table 8]");

description[_T("cutting_component.technological_data.description")]=_T("Technological information about the cutting edge.");

description[_T("cutting_component.expected_tool_life.description")]=_T("The expected number of hours that a given cutting tool can be used before tool wear significantly impacts the performance parameters. This value will also be dependent on a number of external factors, including workpiece material, desired part tolerances, and selected cutting parameters.");

description[_T("cutting_component.its_technology.description")]=_T("The technology defines the spindle speed and the feed of the tool which guarantee expected_tool_life.");

description[_T("cutting_edge_technological_data.description")]=_T("Entity to describe the technological data associated with the cutting edge.");

description[_T("cutting_edge_technological_data.cutting_angle.description")]=_T("The angle of the edges of the cutting tool.");

description[_T("cutting_edge_technological_data.free_angle.description")]=_T("The free angle of the cutting edges.");

description[_T("cutting_edge_technological_data.aux_angle.description")]=_T("The auxiliary angle of the cutting edges.");

description[_T("tool_length_probing.description")]=_T("The entity can be used for probing the tool length.");

description[_T("tool_radius_probing.description")]=_T("The entity can be used for probing the tool radius.");

description[_T("nc_function.description")]=_T("A NC function is an executable object. It describes manufacturing or handling operations which do not involve interpolation of axes. It shall be switching operations or other singular-event machine functionality.");

description[_T("display_message.description")]=_T("This function is used to display a message on the operator's screen.");

description[_T("display_message.its_text.description")]=_T("The message to be displayed on the operator's screen, until the next message is sent. To clear the screen, send an empty message.");

description[_T("optional_stop.description")]=_T("This function is used to stop executing the NC program until the operator presses the start button. The optional stop permits the user to guide the tool. The controller has to consider the changed axis positions etc. after the optional stop is released. However, it is only effective under the condition that the operating mode “optional stop” is enabled on the NC controllers operating panel.");

description[_T("program_stop.description")]=_T("This function is used to stop executing the NC program until the operator presses the start button.");

description[_T("set_mark.description")]=_T("This function is used to synchronize the multiple channel operation. When it is invoked in the channel specified by the attribute its_channel of the entity wait_for_mark, the operation in that channel is started.,");

description[_T("wait_for_mark.description")]=_T("This function is used to synchronize the multiple channel operation. When it is invoked, the specified channel start to wait until the mark is read from another channel's program or from the main program.");

description[_T("wait_for_mark.its_channel.description")]=_T("The identification of the channel engaged in a synchronized operation.");

description[_T("program_structure.description")]=_T("A program structure is an executable object which includes other executables. The included executables can be executed depending on conditions or in manners determined by the program structure object.");

description[_T("workplan.description")]=_T("The entity workplan allows to combine several workingsteps and NC functions in a linear order. It also serves as an attribute of the top level entity project which has to be provided in each ISO 14649 data model exactly once. The recursive definition of workplan as subtype of executable allows to group manufacturing operations into larger units, e.g. to summarise all turning operations and all grinding operations if a workpiece is to undergo several different processes.");

description[_T("workplan.its_elements.description")]=_T("An ordered sequence of executable objects. The workplan cannot contain itself as element. It can only contain itself indirectly within a control structure which allows to skip this workplan in order to prevent an infinite loop.");

description[_T("workplan.its_channel.description")]=_T("The identifier of the channel used for the execution of workplan. This is only for machine control systems which support multiple channel operation.");

description[_T("workplan.its_setup.description")]=_T("The setup includes the workplan’s global security plane and a zero offset where all feature placements are referred to.");

description[_T("workplan.its_effect.description")]=_T("The change to the geometry of the workpiece effected by the operation. A CAM system can use this attribute to describe the predicted effect of this operation on the geometry of the workpiece. If given the controller can compare the geometry change described by this attribute with the geometry change predicted by its internal algorithm. ISO 14649 does not describe how closely the two geometries must match in order for the controller to be considered to be in conformance.");

description[_T("channel.description")]=_T("his entity is used to identify the channel when multiple channel operation is engaged. It is currently a primitive implementation and cannot be used for machine independent programs. Further attributes, like special kinematical descriptions, can be added to this entity in the future. For simple synchronisation, the NC functions set_mark and wait_for_mark can be used.");

description[_T("channel.its_id.description")]=_T("The identification of the channel.");

description[_T("setup.description")]=_T("This entity includes information concerning the location of the workpieces’ coordinate systems. As one setup might include several workpieces of which each one might have its own coordinate system there is one more hierarchical level of frame of reference: By the setup’s attribute its_origin a cartesian coordinate system is defined relative to the machine coordinate system. It is the frame of reference for the location of each workpiece related to the setup. The setup’s origin is only valid within this particular setup and is not referenced by any other setup.");

description[_T("setup.its_id.description")]=_T("The identification of the setup.");

description[_T("setup.its_origin.description")]=_T("Position and orientation of the setup’s cartesian coordinate system relative to the machine coordinate system.");

description[_T("setup.its_secplane.description")]=_T("The security plane for the whole setup. On or above this plane, i. e. for z values greater than those of the elementary_surface, a safe movement of the tool without danger of collision is possible. The dimensions given are relative coordinates as measured from the origin of the setup");

description[_T("setup.its_workpiece_setup.description")]=_T("Each workpiece which is included within the setup and which will be machined within the respective workplan is listed with its placement and additional informations for its setup.");

description[_T("workpiece_setup.description")]=_T("This entity allows to specify for a workpiece its placement relative to the setup’s origin.");

description[_T("workpiece_setup.its_workpiece.description")]=_T("affected workpiece");

description[_T("workpiece_setup.its_origin.description")]=_T("the workpiece’s cartesian system relative to the setup’s cartesian system.");

description[_T("workpiece_setup.its_offset.description")]=_T("The translational and rotational offset of the actual workpiece compared to the position specified by its_origin. It is used to adjust the positions due to a measurement operation. The offset can be changed by a measurement operation");

description[_T("workpiece_setup.its_restricted_area.description")]=_T("Area or volume within which tool-movements are forbidden due tocollisions. Generally used to avoid collisions with fixtures or machine parts. possible");

description[_T("workpiece_setup.its_instructions.description")]=_T("Contains optional setup instructions suchreference etc. as description or external documents");

description[_T("setup_instruction.description")]=_T("The Setup_instruction includes operator instructions for the setup of its workpiece.");

description[_T("setup_instruction.description")]=_T("");

description[_T("setup_instruction.external_document.description")]=_T("Identifier used to identify external document reference such as tables, guidelines etc.");

description[_T("parallel.description")]=_T("The parallel entity allows to run several executables in parallel. All branches are started at the same time; the execution of the parallel entity ends when the last branch has finished. If the NC controller determines that the branches cannot be executed in parallel the machine will stop with an error condition. Note that normally parallel execution will require the use of different channels in each branch. NC functions can be used to synchronise events across different channels.");

description[_T("parallel.branches.description")]=_T("Executables to be executed in parallel. The parallel entity allows to define the general processing of execuables in parallel. To define the delay of single executalbes etc. we concede that there have to be defined more detailed subtypes of parallel.");

description[_T("non_sequential.description")]=_T("The non_sequential entity allows to define a set of executables which all shall be executed but which’s order is not prescribed. In contrast to the workplan entity the non_sequential does not define a sequence.");

description[_T("non_sequential.its_elements.description")]=_T("An set of executable objects. The non_sequential cannot contain itself as element. It can only contain itself indirectly within a control structure which allows to skip itself in order to prevent an infinite loop.");

description[_T("selective.description")]=_T("The selective entity contains a set of executables from which only “one” will be executed. The other executables are to be omitted.");

description[_T("selective.its_elements.description")]=_T("A set of executable objects of which exactly one has to be selected and executed by the controller of the machine tool.");

description[_T("if_statement.description")]=_T("The if statement runs an executable if a given condition is fulfilled; it may include an alternative option.");

description[_T("if_statement.condition.description")]=_T("Expression to be tested based on the rules given below.");

description[_T("if_statement.true_branch.description")]=_T("Executable to be executed if the condition evaluates to be true.");

description[_T("if_statement.false_branch.description")]=_T("Executable to be executed if the condition evaluates to be false.");

description[_T("while_statement.description")]=_T("The while statement runs and repeats an executable as long a given condition is fulfilled. Note that all executables are defined statically so the operation in the body of the while statement cannot be modified during the execution of the loop.");

description[_T("while_statement.condition.description")]=_T("Expression to be tested based on the rules given below. It is tested before attempting the first execution of the body and then each time after the execution of body has been completed.");

description[_T("while_statement.body.description")]=_T("Executable to be executed as long as the condition is true. If the condition is not true upon the initial encounter of the while statement, no action occurs at all.");

description[_T("assignment.description")]=_T("Assigns a value to a nc_variable.");

description[_T("assignment.its_lvalue.description")]=_T("The nc_variable which will be assigned a value.");

description[_T("assignment.its_rvalue.description")]=_T("The value to be assigned to its_lvalue. This is either a numeric constant or a reference to another nc_variable.");

description[_T("nc_variable.description")]=_T("The variable concept introduced here is primitive. Only numeric variables are allowed. The NC controller will map the variable name given by this entity to an internal storage. The attribute its_name must therefore be unique throughout the entire model supplied by an ISO 14649 physical file. Not that several nc_variable entities using the same name will actually refer to the same storage location. Accessing nc_variables in a program_structure entity may take place only after the previous program_structure has been completely executed by the machine. Note that due to the pipeline concept of most NC controllers there can be a significant time gap between the interpretation of the program and the actual execution. It is there the responsibility of the NC controller to halt interpretation until the value of the nc_variable(s) used are available. This is especially true for the lvalue in an assignment operation because the premature execution of the assignment would allow an ongoing NC process to overwrite the assigned nc_variable before it is used, leading to unexpected and possibly fatal results. Note also that there is no guarantee at which time a certain value from any parallel branch would be available. If timing matters, a synchronising NC function has to be inserted before the use of a nc_variable. Variables can be used to access controller-internal information, like sensor readings. This, however, would be controller-dependent and implemented by the use of reserved names as specified by the control vendor.");

description[_T("nc_variable.its_name.description")]=_T("The unique reference to an internal storage provided by the NC controller. All characters in LABEL are significant. The number of different nc_variable names allowed is controller dependent.");

description[_T("nc_variable.initial_value.description")]=_T("The value of the nc_variable before it is accessed the first time. If omitted, the initial value is undefined.");

description[_T("nc_constant.description")]=_T("The nc_constant is used to assign a constant value to an attribute. Its value is determined by the NC-Program and cannot be modified within the process.");

description[_T("nc_constant.its_name.description")]=_T("Name of the constant. It shall be unique within the program.");

description[_T("nc_constant.its_value.description")]=_T("The value of the nc_constant.");

description[_T("boolean_expression.description")]=_T("The Boolean expression entity is used to determine whether a given condition is met. At this time, it can either be a numeric comparison or a composition of several other Boolean expressions.");

description[_T("unary_boolean_expression.description")]=_T("Unary operators perform Boolean algebra on one arguments and produce a false or true value.");

description[_T("unary_boolean_expression.operand.description")]=_T("");

description[_T("not_expression.description")]=_T("Logical negation 'NOT': NOT 0 = 1 and NOT 1 = 0.");

description[_T("binary_boolean_expression.description")]=_T("Binary operators perform Boolean algebra on two arguments and produce a false or true value.");

description[_T("binary_boolean_expression.operand1.description")]=_T("");

description[_T("binary_boolean_expression.operand2.description")]=_T("");

description[_T("xor_expression.description")]=_T("Logical \")not equal to\"function: 0 XOR 0 = 0, 0 XOR 1 = 1, 1 XOR 0 = 1, and 1 XOR 1 = 0.");

description[_T("multiple_arity_boolean_expression.description")]=_T("Binary operators perform Boolean algebra on multiple arguments and produce a false or true value: AND(a,b,c, ...) is true if a,b,c,etc are all true and OR(a,b,c, ...) true if one of a,b,c,etc is true.");

description[_T("multiple_arity_boolean_expression.operands.description")]=_T("");

description[_T("and_expression.description")]=_T("Logical conjunction: 0 AND 0 = 0, 0 AND 1 = 0, 1 AND 0 = 0, 1 AND 1 = 1.");

description[_T("or_expression.description")]=_T("Logical disjunction: 0 OR 0 = 0, 0 OR 1 = 1, 1 OR 0 = 1, 1 OR 1 = 1.");

description[_T("comparison_expression.description")]=_T("The comparison establishes a relationship between the values of two operands. Carefully observe the note on the time-critical behaviour of variables.");

description[_T("comparison_expression.operand1.description")]=_T("");

description[_T("comparison_expression.operand2.description")]=_T("");

description[_T("comparison_equal.description")]=_T("");

description[_T("comparison_not_equal.description")]=_T("");

description[_T("comparison_greater.description")]=_T("");

description[_T("comparison_greater_equal.description")]=_T("");

description[_T("comparison_less.description")]=_T("");

description[_T("comparison_less_equal.description")]=_T("");

description[_T("operation.description")]=_T("Operations are used to specify the content of a workingstep. Unlike a workingstep, an operation cannot be executed by itself – unless it is also a workingstep by means of multiple inheritance, like rapid_movement or touch_probing. The latter do not require the presence of a feature for unambiguous interpretation. However, the most typical operation, machining operation, needs an association with a manufacturing feature in order to be interpreted. It relies on the geometric information provided by the feature, namely its placement in the workpiece co-ordinate system. Such association can either be established through a reference from a manufacturing_feature or through a reference from a machining_workingstep which references in turn a manufacturing_feature. The important difference between a workingstep and an operation is in the number of associated features. The workingstep is associated with zero or one features. So at the time of execution the NC controller will know unambiguously which feature to use for geometric placement (or to use workpiece co-ordinates if no feature is associated). A workingstep is thus unique. Duplicating a workingstep in a workplan will replicate the exact same physical machine action. The operation on the other hand can be associated with zero or multiple features. The same operation can thus be used in different locations. The NC controller would be unable to decide on which of the associated features to execute the operation, so an execution of a “naked” operation is not possible. The reason for this design is the possible re-use of operation data for several manufacturing features. Consider ten identical holes in different positions around the workpiece. They can all share the operation data, but they can not share the workingsteps which represent an operation at a certain instance in time and space. As the “heavyweight” operation entities can be shared, this may reduce the volume of data to be exchanged. The supertype operation specifies the generic data required by all operations. All operations have the option of specifying an explicit toolpath. For 2½D machining operations, many numerical controls will specify cycles for generating their own toolpaths. However, for older controls which are not able to generate toolpaths or if technological reasons require the communication of exactly prescribed toolpaths, the attribute its_toolpath may be used. Also, the 3-to 5-axis milling of freeform surfaces will typically require the explicit specification of toolpaths by a CAM system.");

description[_T("operation.its_toolpath.description")]=_T("Its_toolpath defines a list of all toolpaths in this operation. Note: If its_toolpath exists, the attribute its_machining_strategy in the subtype machining_operation is for information only. Also, all semantics or parameters provided by the operation will be overridden by its_toolpath. The toolpaths are given in coordinates as measured from the workpiece co-ordinate system or, if this operation is associated with a manufacturing_feature, in the local co-ordinate system of the feature.");

description[_T("operation.its_tool_direction.description")]=_T("Specification of the type of tool orientation used. If none is given, a technology specific default is assumed. Therefore refer to the technology specific parts of ISO 14649. Note that the operation is geometrically linked with the associated manufacturing_feature, if such an association exists. If the feature has a feature_placement attribute, this transformation will also apply to all geometry specified here, i. e. its_toolpath and to all other geometric information like directions or orientations which may be used in subtypes of operation. In other words, all geometry and parameters of the machining_operation are defined in the local co-ordinate system of the feature. As the operation may be associated with multiple manufacturing_features it can only be interpreted in the context of such feature. For features without a feature_placement attribute or for operations without an associated feature, all data is to be interpreted in workpiece co-ordinates as specified by the attribute its_origin of the workplan which uses this operation.");

description[_T("toolpath_list.description")]=_T("The entity toolpath_list contains a list of toolpaths (trajectories) which will be executed by the CNC one after the other.");

description[_T("toolpath_list.its_list.description")]=_T("A list of toolpaths. These toolpaths shall be executed in the defined order.");

description[_T("tool_direction.description")]=_T("The following entities define the tool direction for freeform machining.");

description[_T("two_axes.description")]=_T("Only two axes can be simultaneously active.");

description[_T("three_axes.description")]=_T("Simultaneous tool movements in three axes are used for machining. The tool orientation is always parallel to the third axis (generally, the z axis) in the machine co-ordinate system. Therefore the tool direction will not be affected by any workpiece placements or workingstep transformation.");

description[_T("machining_operation.description")]=_T("Machining operations define the machining process for a limited area of the workpiece, i. e. the contents of a machining workingstep. For the feature to which they refer they specify, at a minimum, the tool to be used, and a set of technological parameters. This data forms an integral part of the operation and cannot be normally changed during its scope. However, for special operations, and if an explicit toolpath is provided in the inherited attribute its_toolpath, it is also possible to specify certain deviating parameters along portions of the toolpath. In this case, the data given in machining_operation serves as default data in case no specific technological information for a toolpath is provided. Note that any parameters or semantics specified by this operation or the associated feature will be overridden by the toolpath definition, even if the actions defined by the toolpath contradict the intuitive notion of this operation of the associated feature. In other words, you can even use a pocket operation to bore a hole. The first tool movement within a machining_operation will typically be an approach movement to the defined start point, allowing the machine to reach its operating speed. This can be either be defined explicitly in a toolpath, or by means of a parameterised path, or it can be defined within the strategy for the operation where the exact definition of the path is left to the NC controller. The last tool movement will typically be a retract or lift movement. The tool movement within the machining_operation, unless defined by an explicit toolpath, will be determined by the technology-dependent strategy and additional parameters as defined by subtypes of machining_operation. Machining_operation is the supertype for all technologies included in ISO 14649. For each of these technologies, specific machining strategies are defined in separate, technology depending parts. They may be used to instruct the NC controller on how to generate toolpaths if no toolpath is explicitly specified for this operation.");

description[_T("machining_operation.its_id.description")]=_T("A unique identifier of the operation.");

description[_T("machining_operation.retract_plane.description")]=_T("The height of a retract plane associated with this operation. This is not the security plane. The start and the end point of the operation – as discussed in Section 4.6.2.1 – shall be within z-direction at the length given by the attribute retract_plane. It is guaranteed that the approach movement from the retract plane to the first cut and the lift movement from the last cut to the retract plane are executed in cutting feed as specified for the operation. A change to rapid feed, e.g. to reach the security plane, can only occur above this plane, and only in the context of a new operation which should be of type rapid_movement. If not given, and if the inherited attribute its_toolpath is not given, the NC controller will determine an appropriate retract plane which may be the security plane. If its_toolpath is given, or if approach or retract strategies are given which do not make use of a retract plane, this attribute will be ignored. Depending on the type of operation, the attribute will be interpreted as follows: • For plane milling or drilling operations, retract_plane is the z coordinate of the retract plane from which the tool starts (for approach) and to which it is retracted (for retract movements). • For side milling, retract_plane indicates a distance perpendicular to the manufacutred surface. • For freeform milling, retract_plane is the distance between the workpiece surface and the retract plane which is oriented perpendicular to the surface normal in the first cutting point (for approach) or the last cutting point (for lift).");

description[_T("machining_operation.start_point.description")]=_T("Optional starting point of the cutting process specified as tool centre point in the local xy plane. The z co-ordinate of start_point is determined depending on the type of operation: • For milling, the z co-ordinate is the depth of the first cut, excluding any plunge or approach movements. If an approach or plunge movement is used, the actual start point of the operation will be the start point of that approach or plunge movement which can be calculated based on this attribute. The start_point will be reached at the end of such approach or plunge. Thus the x and y co-ordinates of start_point not necessarily coincide with those of the start point of the operation, depending on the type of approach or plunge. • For drilling, the start_point is identical with the start point of the operation as no approach or plunge is foreseen here. Therefore, the z co-ordinate is given by the attribute retract_plane. If this attribute is given, the operation has a defined start point as discussed in Section 4.6.2.1, otherwise not. In the latter case, the NC controller will determine a reasonable default. If its_toolpath is given, or if start_point specifies a point violating the feature’s boundary or otherwise incompatible with the machining strategy, this attribute will be ignored.");

description[_T("machining_operation.its_tool.description")]=_T("The tool which has to be used for this workingstep. For the definition of machining_tool, please refer to technology-specific parts of ISO 14649. It is important to understand that the tool data given describes the ideal required tool. If this attribute calls for a tool with diameter 10.0 mm, the NC controller may select a tool with diameter 9.983 mm provided that it has the ability for on-line tool correction and has the actual value of the tool stored in its tool memory data, and provided that the result of the operation remains within the given tolerances of the feature. (In other words, the NC controller is not allowed to select a 9.983 mm drill if the hole has the toleranced dimension 10.0-0.01 mm.) The possibility to find a suitable tool in the machine’s tool magazine is reduced the more details for the tool are specified. So only the technologically necessary parameters should be given. (In other words, do not specify a tool length if only the diameter is of importance.) If a tool id is specified, only an exact match can be selected.");

description[_T("machining_operation.its_technology.description")]=_T("The technological parameters of the machining operation, like spindle speed and feed of the tool.");

description[_T("machining_operation.its_machine_functions.description")]=_T("Indicates the state of various machine functions, like coolant, chip removal, etc. to be applied during the time span of this operation.");

description[_T("technology.description")]=_T("This entity is the supertype for the technologies defined in the following parts of ISO 14649.");

description[_T("technology.feedrate.description")]=_T("Feed of the tool expressed as a linear speed. The feed rate specified applies to the motion of the tool center point.");

description[_T("technology.feedrate_reference.description")]=_T("Specifies whether the feed rate given above is to be calculated with regard to the tool center point or the cutter contact point.");

description[_T("machine_functions.description")]=_T("Each technology has its specific machine functions. This entity is their abstract supertype.");

description[_T("toolpath.description")]=_T("This is the supertype for all explicit toolpaths. If needed, the toolpaths can have technological parameters and the machine functions which override the default value specified at the operation level. If the attributes its_technology and/or its_machine_functions are given, the machine is instructed to reach the specified operating conditions before entering the toolpath. Unlike the similar case for workingsteps, no halt is allowed between toolpaths in an operation’s toolpath list. So the previous toolpath may be adversely affected if a significant change of parameters occurs and the controller tries to provide run up to these parameters prior to the current toolpath. Also, if the time span of the previous toolpath is insufficient to reach stable parameters, there is no guarantee that the new toolpath will be using these parameters from the start. Caution is therefore advised when using technological parameters at the toolpath level. If required, e.g. for special operations requiring a reversing of the spindle rotation, a feedstop toolpath should be inserted in order to grant the machine sufficient time for changing the parameters.");

description[_T("toolpath.its_priority.description")]=_T("As a toolpath may contain all necessary movements to manufacture a feature the priority of execution between the toolpath and the feature has to be determined. In case there is a toolpath of higher priority (true) than the geometry of the path generation based on the manufacturing feature is subordinated to this toolpath.");

description[_T("toolpath.its_type.description")]=_T("Type of the toolpath.");

description[_T("toolpath.its_speed.description")]=_T("A means to influence the feed rate. This factor will be multiplied into the feed rate defined in the operation. It can be either a fixed value or a curve specifying a velocity profile along the toolpath.");

description[_T("toolpath.its_technology.description")]=_T("The technology defines the spindle and the feed of the tool.");

description[_T("toolpath.its_machine_functions.description")]=_T("Various machine functions, like coolant, chip removal, etc.");

description[_T("toolpath_speed.description")]=_T("This is a one-dimensional curve specifying the speed profile as defined by type positive_ratio_measure. If the attribute basiccurve of the toolpath exists, the parameterisation of speed must be the same as basiccurve. Otherwise, speed must be parameterised by the path length of the underlying toolpath, i. e. the first parameter is 0, the last parameter equals the length of the underlying toolpath as defined by type length_measure.");

description[_T("toolpath_speed.speed.description")]=_T("");

description[_T("feedstop.description")]=_T("Feedstop is a toolpath element with no feed motion. The spindle remains in the selected speed while the execution of the subsequent toolpath is delayed for the specified time.");

description[_T("feedstop.dwell.description")]=_T("The time to stop the feed axis.");

description[_T("trajectory.description")]=_T("Supertype for all explicit trajectories.");

description[_T("trajectory.its_direction.description")]=_T("If true or omitted, the tool has to be moved from the beginning to the end of the referenced geometric curve. Otherwise, it will be moved from the end point to the start point of the referenced geometric curve.");

description[_T("cutter_location_trajectory.description")]=_T("Cutter location paths define a tool movement with respect to the tool center point. This is the point where the rotational axis of the tool leaves the tool tip.");

description[_T("cutter_location_trajectory.basiccurve.description")]=_T("A 3D curve defining the cartesian co-ordinates of the cutter location point in the workpiece co-ordinate system or the local co-ordinate system of the feature, respectively.");

description[_T("cutter_location_trajectory.its_toolaxis.description")]=_T("A 3D curve defining the toolaxis of the tool. The three co-ordinates of the curve represent the three components of the vector in the workpiece co-ordinate system or the local co-ordinate system of the feature, respectively. If given, the parameterisation of the toolaxis curve must correspond to that of the basiccurve.");

description[_T("cutter_location_trajectory.surface_normal.description")]=_T("A curve in space defining the surface normal. It has to be of the same type and has to have the same parameterisation than the basiccurve.");

description[_T("cutter_contact_trajectory.description")]=_T("Cutter contact paths define a tool movement with respect to the cutter contact point.");

description[_T("cutter_contact_trajectory.basiccurve.description")]=_T("A 3D curve defining the cartesian co-ordinates of the cutter contact point in the workpiece co");

description[_T("cutter_contact_trajectory.its_toolaxis.description")]=_T("A 2D curve defining the toolaxis of the tool. The first co-ordinate represents the yaw angle, the second co-ordinate the tilt angle in degrees. For the definition of tilt and yaw angles, see Section 5.2.2.3 of ISO 14649-11.. If given, the parameterisation of the toolaxis curve must correspond to that of the basiccurve. Note that this attribute will override any information about the tool orientation given by the its_tool_direction attribute of the workingstep.");

description[_T("cutter_contact_trajectory.its_contact_type.description")]=_T("");

description[_T("curve_with_normal_vector.description")]=_T("A bounded curve which has a second curve defining the surface normal.");

description[_T("curve_with_normal_vector.basiccurve.description")]=_T("The reference to the geometric curve in the geometry description.");

description[_T("curve_with_normal_vector.surface_normal.description")]=_T("A 3D curve in space defining the surface normal. The three co-ordinates of the curve represent the three components of the surface normal vector in the co-ordinate system of the basiccurve. It has to be of the same type and has to have the same parameterisation than the basiccurve.");

description[_T("axis_trajectory.description")]=_T("Axis trajectories do not directly define a tool movement, but rather the movement of the machine axis. They are comparable to the G0/G1 commands of ISO 6983. They should not be used because the resulting NC programme will no longer be machine independent.");

description[_T("axis_trajectory.axis_list.description")]=_T("A list with axis names defining these axes which will be moved by the trajectory.");

description[_T("axis_trajectory.commands.description")]=_T("A list of one-dimensional curves. The array contains one curve per axis whose name is given by the respective index in the axis_list. The values represent axis positions in units as defined for length_measure (for linear axes) or planar_angle_measure (for rotary axes).");

description[_T("parameterised_path.description")]=_T("This subtype of the toolpath entity is used to define help movements like connectors, approach and lift movements without giving the actual tool path. The movement is rather described by a movement type and its parameters. The CNC itself then has to calculate the resulting toolpath for the actual tool. This concept is especially useful when working with cutter contact trajectories for the milling operations. As cutter contact trajectories can only be used for motions on the workpiece surface itself there is a need for defining the connecting movements between the individual toolpaths in an indirect way. Also, the parameterised paths given here can be used to connect cutter contact and cutter location trajectories. Note that even though the parameterised paths are named for their most frequent use they can be used for any portion of a toolpath description just as any other form of toolpath. Their actual use is not indicated by the entity names but rather by the inherited its_type attribute.");

description[_T("connector.description")]=_T("The connector entity defines a connection path between a lift and a following approach movement. This path type if typically needed to implement a rapid_movement operation but can also be used within a machining operation for connecting several cutting paths.");

description[_T("connect_secplane.description")]=_T("The security plane connector moves the tool up to the security plane until the cutter location point reaches the security plane, then linear to the projected starting point of the following movement and again from the security plane down to this starting point. This type of connection may be needed for unidirectional machining of freeform surface. For bidirectional machining, a connect_direct between the preceding lift and the following approach movement will be more efficient.");

description[_T("connect_secplane.up_dir.description")]=_T("specification of the direction of the upward movement. If none is given, the motion will be in tool direction.");

description[_T("connect_secplane.down_dir.description")]=_T("specification of the direction of the downward movement. If none is given, the motion will be in tool direction.");

description[_T("connect_direct.description")]=_T("The direct connector moves the tool in a straight line from the end point of the previous toolpath to the starting point of the next toolpath.");

description[_T("approach_lift_path.description")]=_T("This subtype of parameterised path describes the lift and approach movement in terms of angles or tangential movements. See also Section 4.8.1. The strategy will initiate the generation of toolpath based on the surrounding feature. This entity, on the other hand, specifies a distinct path in cartesian space. It can be the result of a path generation based on an air strategy in which case the fix_point would lie in the retract_plane of the associated operation.");

description[_T("approach_lift_path.fix_point.description")]=_T("The starting point for the approach movement or the destination for the lift movement in the workpiece co-ordinate system, or the feature’s local co-ordinate system, respectively. The reference point on the tool is the tool center point (tcp), which is the point where the rotational axis of the tool leaves the tip.");

description[_T("approach_lift_path.fix_point_dir.description")]=_T("The tool direction in fix_point as 3D vector in the workpiece co-ordinate system, or the feature’s local co-ordinate system, respectively. If given, the machine will attempt to interpolate between the tool direction in the fix point and the tool direction in the start (approach) or end (lift) point of the connecting toolpath during the approach/lift movement. If not given, the tool direction will not be changed during the approach/lift movement.");

description[_T("ap_lift_path_angle.description")]=_T("Approach or lift at an angle to the path using a linear approach");

description[_T("ap_lift_path_angle.angle.description")]=_T("Approach or lift angle.");

description[_T("ap_lift_path_angle.benddist.description")]=_T("The length of the angular approach angle.");

description[_T("ap_lift_path_tangent.description")]=_T("Approach or lift to the path using a tangential approach (see figure).");

description[_T("ap_lift_path_tangent.radius.description")]=_T("The radius of the approach movement.");

