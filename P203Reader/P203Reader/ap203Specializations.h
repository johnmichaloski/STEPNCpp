//
// ap203Specializations.h
//
#pragma once

#include "ap203ClassDefinitions.h"
#include "OGLVerifier.h"


#define CREATECLASS(X)\
	static IStepNodePtr Create(const char * name) {IStepNode  * ptr= (IStepNode  *) new X(); ptr->Name()=name; return ptr;}\


extern IStepNodePtr Createap203SpecializationClass(CString classname, CString name) ;


// next draw oriented_edge + fix if done with tree return so, and stop tree traversal
class  ap203line  : public Express::Eline
{
public:
	CREATECLASS(ap203line);
	virtual LONG Draw(IOglPlotter * pPlotter) ;
};


/**
An object is a wire_shell if and only if:<BR>
•	it is a finite_set; <BR>
•	each member of the set is a closed_path that is connected directly or indirectly to each other member of the set; <BR>
•	each directed_edge in each closed_path has an opposite_sense relationship with a directed_edge in the same closed_path or in a different closed_path. <BR>
*/
class ap203wire_shell: public Express::Ewire_shell
{
public:
	CREATECLASS(ap203wire_shell);
	virtual LONG Draw(IOglPlotter * pPlotter) { return 0; }

};

/*
Closed_shell is the fundamental structure defining an evaluated solid model, also called a boundary_ representation. 
*/
class ap203closed_shell: public Express::Eclosed_shell
{
public:
	CREATECLASS(ap203closed_shell);
	virtual LONG Draw(IOglPlotter * pPlotter) ;
};


class ap203advanced_face: public Express::Eadvanced_face
{
public:
	CREATECLASS(ap203advanced_face);
	virtual LONG Draw(IOglPlotter * pPlotter) ;

};

class ap203edge_loop: public Express::Eedge_loop
{
public:
	CREATECLASS(ap203edge_loop);
	virtual LONG Draw(IOglPlotter * pPlotter) ;

};


class ap203composite_curve: public Express::Ecomposite_curve
{
public:
	CREATECLASS(ap203composite_curve);
	virtual LONG Draw(IOglPlotter * pPlotter) 
	{
		return PDONE;
	}

};


