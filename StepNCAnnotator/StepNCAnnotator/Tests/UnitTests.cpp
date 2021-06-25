#include "stdafx.h"
#include "UnitTests.h"

#ifdef assert
#undef assert
#endif
#include <assert.h>

#include "ExpressUtils.h"
#include "StepNC.h"

using namespace Express;

CUnitTests::CUnitTests(void)
{
	_regressionLogger.addMode( CLogging::Trace);
	_bGraphUnits=true;

}
void CUnitTests::NewRegression(CString filename)
{
	_regressionLogger.addMode( CLogging::Trace);
	_regressionLogger.openRegressionLogFile(filename, "ippDME Unit Test Regession File");
//	TestAll();
	_regressionLogger.closeLogFile();
}
void CUnitTests::RegressionTest(CString filename)
{
	_regressionLogger.addMode( CLogging::Regression);
	_regressionLogger.useRegressionLogFile(filename);
	_regressionLogger.readRegressionLine(); // skip header line
	// setup callback on finish, error - implement first :)
	
//	TestAll();
	_regressionLogger.closeLogFile();

}
void CUnitTests::TestProject()
{	
	_regressionLogger.log("TestProject\n");
	Eproject  * proj = new Eproject();
	proj->its_owner= new Eperson_and_address();
	proj->its_owner->its_person = new Eperson;
	proj->its_owner->its_person->id= (Eidentifier *) new EString("123-45-6789"); 
	proj->its_owner->its_person->last_name=(Elabel *) new EString("Michaloski");
	proj->its_owner->its_person->first_name= (Elabel *)new EString("John"); 
	proj->its_owner->its_person->prefix_titles.push_back(new Elabel); 
	proj->its_owner->its_person->prefix_titles.back() = (Elabel *) new EString("Mr."); 

	CString tmp = DumpCVarDefs(proj->its_owner->vars);
	_regressionLogger.log(tmp);
}

void CUnitTests::TestList()
{
	Eworkpiece * part = new Eworkpiece();
	part->its_id = (Eidentifier *)  new EString("Stock");
	part->its_material = new Ematerial;

	Load(part->its_material->vars, StepVars(
		TItem("standard_identifier", new EString("ST-50")), 
		TItem("material_identifier" , new EString("STEEL")),
		TItem("material_property" , new Eproperty_parameter)
		));
	part->its_material->material_property[0]->parameter_name= (Elabel*) new EString("E 200000N/M2");


	part->global_tolerance = (Eshape_tolerance *)	new EReal(0.010); 

	Ecartesian_pointPtr pt = new Ecartesian_point;
	Load(pt->vars, StepVars(
		TItem("name", new EString("CLAMPING_POSITION1")), 
		TItem("coordinates" , new EReal(0.000)),
		TItem("coordinates" , new EReal(20.000)),
		TItem("coordinates" , new EReal(25.000))
		));
	part->clamping_positions.push_back(pt); 


	pt = new Ecartesian_point;
	pt->name= (Elabel *) new EString("CLAMPING_POSITION2"); 
	pt->coordinates.push_back((Elength_measure *) new EReal(100.000));
	pt->coordinates.push_back((Elength_measure *) new EReal(20.000));
	pt->coordinates.push_back((Elength_measure *) new EReal(25.000));
	part->clamping_positions.push_back(pt); 

	pt = new Ecartesian_point;
	pt->name=(Elabel *)  new EString("CLAMPING_POSITION3"); 
	pt->coordinates.push_back((Elength_measure *) new EReal(00.000));
	pt->coordinates.push_back((Elength_measure *) new EReal(100.000));
	pt->coordinates.push_back((Elength_measure *) new EReal(25.000));
	part->clamping_positions.push_back(pt); 

	pt = new Ecartesian_point;
	pt->name=(Elabel *)  new EString("CLAMPING_POSITION4"); 
	pt->coordinates.push_back((Elength_measure *) new EReal(100.000));
	pt->coordinates.push_back((Elength_measure *) new EReal(100.000));
	pt->coordinates.push_back((Elength_measure *) new EReal(25.000));
	part->clamping_positions.push_back(pt); 

	CString tmp = DumpCVarDefs(part->vars);
	_regressionLogger.log(tmp);
}

void CUnitTests::TestInheritance()
{	
	Eweek_of_year_and_day_datePtr date = new Eweek_of_year_and_day_date;

	date->year_component = (Eyear_number *) new EInteger(2008); 
	date->week_component = (Eweek_in_year_number *) new EInteger(24); 
	date->day_component  = (Eday_in_week_number *) new EInteger(6); 

	CString tmp = DumpCVarDefs(date->vars);
	_regressionLogger.log(tmp);

}


void CUnitTests::TestSelection()
{	
	/*
	toolpath_speedPtr _toolpath_speed;
	positive_ratio_measurePtr _positive_ratio_measure;
	speed_namePtr _speed_name;
	*/

	Etoolpath_speedprofilePtr profile = new Etoolpath_speedprofile;

	// bounded_curve, degree, control_points_list, curve_form, closed_curve,  self_intersect
	profile->_Etoolpath_speed->speed->closed_curve = new ELogical(0);
	profile->_Etoolpath_speed->speed->degree= new EInteger(3); ;
	profile->_Etoolpath_speed->speed->self_intersect= new ELogical(1); 

	profile->_Espeed_name = new Espeed_name;
	profile->_Espeed_name->SetSelection( Espeed_name::RAPID) ;
	profile->SetSelection(profile->_Espeed_name);
	profile->SetSelection(profile->_Etoolpath_speed);

	CString tmp = DumpCVarDefs(profile->vars);
	//CVarDef * var = (CVarDef * ) CVarDef::FindVarDef(profile->vars,"_speed_name");
	//CString tmp = DumpCVarDef(var);
	_regressionLogger.log(tmp);

}