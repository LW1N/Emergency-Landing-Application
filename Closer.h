// Lucas Nguyen
// 918100160

#ifndef CLOSER_H
#define CLOSER_H
#include "Facility.h"
class Closer{
	public:
		Closer(const double lat, const double lon): curr_lat(lat), curr_long(lon) {}
		bool operator()(Facility* i, Facility* j){
			return i->distance(curr_lat, curr_long) < j->distance(curr_lat, curr_long);
		}

	private:
		const double curr_lat;
		const double curr_long;
};
#endif
