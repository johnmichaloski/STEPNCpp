#include "StdAfx.h"
#include "ap203Specializations.h"
using namespace Express;


void TraverseDraw(CVarDefs & instancevars, IOglPlotter * plotter, CString &tabs)
{
	tabs+="\t";
	for(int i=0; i<instancevars.size(); i++)
	{
		IStepNodePtr step;
		if(instancevars[i]->_eType == special_)
		{
			TraverseDraw((CVarDefs &) *(CVarDefs*)instancevars[i]->m_ref, plotter, tabs);
		}
		else if(instancevars[i]->IsSimpleType())
		{
			///vars[i]->Draw(m_plotter); // no reason to draw int, real, string
		}
		else if(instancevars[i]->Type() == 	bag_)
		{
			EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) instancevars[i]->GetStepNodePtr();
			if(!list->IsSimpleListType())
				for(int j=0; j< list->size(); j++)
				{
					step=  list->at(j);
					if(step!=NULL)
					{
						step->Draw(plotter);
						TraverseDraw(step->GetInstanceVars(), plotter, tabs);
					}

				}
		}
		else if(instancevars[i]->Type() == 	select_)
		{
			IStepNodePtr pSel = instancevars[i]->GetStepNodePtr();
			TraverseDraw(pSel->GetInstanceVars(), plotter, tabs);
		}
		else if(instancevars[i]->Type() == 	index_)
		{
			step=  (IStepNode *) instancevars[i]->GetStepNodePtr();; 
			TraverseDraw(step->GetInstanceVars(), plotter, tabs);
		}
		else if(instancevars[i]->Type() == 	entity_ 
			|| instancevars[i]->Type() == 	typereference_ 
			|| instancevars[i]->Type() == 	reference_)
		{
			step=  (IStepNode *) instancevars[i]->GetStepNodePtr();; 
			step=  *(IStepNode **) instancevars[i]->m_ref;
			if(step!=NULL)
			{
				step->Draw(plotter);
				TraverseDraw(step->GetInstanceVars(), plotter, tabs);
			}
		}
		else
		{
			step=  *(IStepNode **) instancevars[i]->m_ref;
			if(step!=NULL)
			{
				step->Draw(plotter);
				TraverseDraw(step->GetInstanceVars(), plotter, tabs);
			}
		}
//		OutputDebugString(StrFormat("%sInstance=%s class=%s\n", tabs, instancevars[i]->Name(), (step!=NULL)? step->Classname() : instancevars[i]->Classname()));
	}
	tabs=tabs.Mid(1);

}

LONG ap203line::Draw(IOglPlotter * pPlotter) 
{
	HRESULT hr;
	double x0=pnt->coordinates[0]->val;
	double y0=pnt->coordinates[1]->val;
	double z0=pnt->coordinates[2]->val;
	hr = pPlotter->Line(x0, y0, z0, 
		x0 + dir->magnitude->val * dir->orientation->direction_ratios[0]->val,
		y0 + dir->magnitude->val * dir->orientation->direction_ratios[1]->val,
		z0 + dir->magnitude->val * dir->orientation->direction_ratios[2]->val,
		&this->_atom);
	OutputDebugString(StrFormat("Line %4.2f  %4.2f  %4.2f -> %4.2f  %4.2f  %4.2f\n", x0, y0, z0, 
		x0 + dir->magnitude->val * dir->orientation->direction_ratios[0]->val,
		y0 + dir->magnitude->val * dir->orientation->direction_ratios[1]->val,
		z0 + dir->magnitude->val * dir->orientation->direction_ratios[2]->val));


	if(hr<0)
		return PERROR;

	return PDONE;

}


LONG ap203closed_shell::Draw(IOglPlotter * pPlotter)
{ 

	return POK; 
	HRESULT hr;

	for(int i=0; i<  _connected_face_set.cfs_faces.size(); i++)
	{
		EfacePtr face = _connected_face_set.cfs_faces[i];
		hr=face->Draw(pPlotter);

	}

	if(hr<0)
		return PERROR;

	return PDONE; 
}

LONG ap203advanced_face::Draw(IOglPlotter * pPlotter)
{ 
	this;
	return POK; 

	HRESULT hr;

	for(int i=0; i<  _face_surface._face._bounds.size(); i++)
	{
		//Eface_boundPtr face = _face_surface._face.Eface::_bounds[i];
		//face->Draw(pPlotter);

	}

	if(hr<0)
		return PERROR;

	return PDONE; 
	; 
}
LONG ap203edge_loop::Draw(IOglPlotter * pPlotter) 
{

	long atom;
	pPlotter->NewPolygon(&atom);
		// edgelist[..n].edge	.edge_start.	edge_geometry.		curve_3d.	pnt.	coordinates[0..2]
		//               Eedge	edge_curve		Eintersection_curve	line		Point
		//															curve
	for(int i=0; i < _path.edge_list.size(); i++)
	{
		i=i;
		if( _path.edge_list[i]->Classname()=="Eoriented_edge")
		{
			Eoriented_edgePtr oriented_edge = _path.edge_list[i];
			if( oriented_edge->_edge.edge_start->Classname() =="Eedge_curve")
			{
				Eedge_curvePtr startedge =(Eedge_curve *)(Evertex*) oriented_edge->_edge.edge_start.get();
				Eedge_curvePtr endedge =(Eedge_curve *)(Evertex*) oriented_edge->_edge.edge_end.get();
				// *(std::vector<boost::intrusive_ptr<Express::Elength_measure>,std::allocator<boost::intrusive_ptr<Express::Elength_measure> > >*)(&(*(Express::Ecartesian_point*)(((*(Express::Evertex_point*){*}((((*((edge).p_))._edge).edge_start).p_)).vertex_geometry).p_)).coordinates)))._Myfirst)[0x00000000]

				double x0=((Ecartesian_point *) (Epoint *) ((Evertex_point *)(Evertex*) startedge->_edge.edge_start.get())->vertex_geometry.get())->coordinates[0]->val;
				double y0=((Ecartesian_point *) (Epoint *) ((Evertex_point *)(Evertex*) startedge->_edge.edge_start.get())->vertex_geometry.get())->coordinates[1]->val;
				double z0=((Ecartesian_point *) (Epoint *) ((Evertex_point *)(Evertex*) startedge->_edge.edge_start.get())->vertex_geometry.get())->coordinates[2]->val;
				pPlotter->AddPolygonVertex(atom, x0,y0,z0);

				double x1=((Ecartesian_point *) (Epoint *) ((Evertex_point *)(Evertex*) startedge->_edge.edge_start.get())->vertex_geometry.get())->coordinates[0]->val;
				double y1=((Ecartesian_point *) (Epoint *) ((Evertex_point *)(Evertex*) startedge->_edge.edge_start.get())->vertex_geometry.get())->coordinates[1]->val;
				double z1=((Ecartesian_point *) (Epoint *) ((Evertex_point *)(Evertex*) startedge->_edge.edge_start.get())->vertex_geometry.get())->coordinates[2]->val;
				pPlotter->AddPolygonVertex(atom, x1,y1,z1);

			}

		}

		//pPlotter->AddPolygonVertex(atom, 0,0,0);
	}

	return PDONE;
}

IStepNodePtr Createap203SpecializationClass(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname=="Eadvanced_face") return ap203advanced_face::Create(name);
	if(classname=="Eclosed_shell") return ap203closed_shell::Create(name);
	if(classname=="Ewire_shell") return ap203wire_shell::Create(name);
	if(classname=="Eline") return ap203line::Create(name);
	if(classname=="Ecomposite_curve") return ap203composite_curve::Create(name);
	if(classname=="Eedge_loop") return ap203edge_loop::Create(name);

	

	return NULL;
}


