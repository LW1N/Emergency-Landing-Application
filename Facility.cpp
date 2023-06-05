// Lucas Nguyen
// 918100160
//

#include "Facility.h"
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

Facility::Facility(string s) : site_number_(s.substr(0,10)), type_(s.substr(11, 13)), code_(s.substr(24, 4)), name_((s.substr(130, 50))), latitude_(convert_latitude(s.substr(535, 12))), longitude_(convert_longitude(s.substr(562, 12))) {}

string Facility::site_number(void) const{
	return site_number_;
}

string Facility::type(void) const{
	return type_;
}

string Facility::code(void) const{
	return code_;
}

string Facility::name(void) const{
	return name_;
}

double Facility::latitude(void) const{
	return latitude_;
}

double Facility::longitude(void) const{
	return longitude_;
}

double Facility::distance(double lat, double lon) const{
	// latitudes and longitudes from degrees to radians
	const double lat1r = lat * (M_PI/180.0);
	const double lon1r = lon * (M_PI/180.0);
	const double lat2r = latitude_ * (M_PI/180.0);
	const double lon2r = longitude_ * (M_PI/180.0);
	
	// psi = central angle between points (lat1, lon1) and (lat2, lon2) on a sphere
	double c = cos(lat1r)*cos(lat2r)*cos(lon1r-lon2r) + sin(lat1r)*sin(lat2r);

	// truncate possible numerical errors in cos to [-1, 1] interval
	c = fmin(c, 1.0);
	c = fmax(c, -1.0);
	const double psi = acos(c);

	// Radius of Earth = 6371 km
	// 1 NM = 1.852 km
	// 1 degree = 60.9495 NM on a great circle
	return 60.0405 * psi * (180.0/M_PI);
}

double Facility::convert_latitude(string s) const{
	double x;
	string manip;
	if(!s.empty()){
		manip = s;
	}

	string::size_type found = manip.find("S");
	if(found != string::npos){
		manip.erase(found);

		istringstream is(manip);
		is >> x;

		x /= -3600;
		return x;
	}

	found = manip.find("N");
	manip.erase(found);

	istringstream is(manip);
	is >> x;

	x /= 3600;
	return x;
}

double Facility::convert_longitude(string s) const{
	double x;
	string manip;
	if(!s.empty()){
		manip = s;
	}

	string::size_type found = manip.find("W");
	if(found != string::npos){
		manip.erase(found);

		istringstream is(manip);
		is >> x;

		x /= -3600;
		return x;
	}	

	found = manip.find("E");
	manip.erase(found);

	istringstream is(manip);

	is >> x;

	x /= 3600;
	return x;
}
