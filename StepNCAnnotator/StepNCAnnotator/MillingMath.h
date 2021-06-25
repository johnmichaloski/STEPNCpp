// 
// MillingMath.h
//


#pragma once

class MillingProcess
{
public:

	double LookupSfm(CString szToolMaterial, CString szPartMaterial) { return 0; }
	double ComputeSpindleSpeed(double sfm, double diameter)
	{
		_rpm = (12.0 * sfm)/( 3.1415926535 * diameter);
		return _rpm;
	}
	double ComputeFeedrate(double spindlespeed /* rpm */, double feedpertooth /*length/tooth*/, int nTeeth)
	{
		_feed = spindlespeed /*rpm*/ * feedpertooth * (double) nTeeth;
		return _feed; // length/min  e.g., mm/min or in/min
	}
	double CuttingSpeed(double inchDiameter) { 
	{

	}
	double CuttingSpeed(double mmDiameter)
	{

	}
	// Qd - Volume of metal remove - input mm units or inch units work  in^3/min
	double RateOfMetalRemoval(double dWidthCut, double dDepthCut,  double feed) 
	{
		double Qm = dWidthCut * dDepthCut * feed; 
		return Qm;
	}

	// return hp given: k metal constant, E is efficiency (around .7-.85) 
	double Horsepower(double k, double Qd, double E) { return (k *Qd )/ E); }

	// return hps - hp = 33,000 ftlb/min = 550 ft lb /sec
	double SpindleTorque(double hp, double rpm /* part rpm*/) { double hps = 550 * hp / 33000; return (63030 * hps )/ rpm; }


		// drilling, milling, turning
	typedef boost::tuple<double, double, double> KHorsepowerTuple; 
	std::map<CString, KHorsepowerTuple> _kHorsepowerlist;

	void InitKHorsepower()
	{
		_toollist.push_back("Mild Steel 25RC", ToolingTuple(1.0, 1.0, .9));
		_toollist.push_back("Mild Steel 30RC", ToolingTuple(1.6, 1.8, 1.3));
		_toollist.push_back("Mild Steel 50RC", ToolingTuple(1.9, 2.1, 1.5));
		_toollist.push_back("Soft Cast Iron", ToolingTuple(.8, .7, .5));
		_toollist.push_back("Hard Cast Iron", ToolingTuple(.9, 1.1, 1.0));
		_toollist.push_back("Aluminum", ToolingTuple(.35, .4, .3));
		_toollist.push_back("Brass", ToolingTuple(.5, .6, .4));
		_toollist.push_back("Bronze", ToolingTuple(.6, .8, .7));
		_toollist.push_back("Stainless 400", ToolingTuple(1.3, 1.3, 1.1));
		_toollist.push_back("Stainless 300", ToolingTuple(1.6, 1.8, 1.7));
		_toollist.push_back("Titanium", ToolingTuple(1.0, 1.0, 1.1));
		_toollist.push_back("Nickel Alloys", ToolingTuple(1.6, 1.6, 1.5));
	}
	double _rpm;
	double _feed;
};

class DrillingProcess
{
public:

	
};