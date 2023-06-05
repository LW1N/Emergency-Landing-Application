// Lucas Nguyen
// 918100160

#ifndef SITENUMBER_H
#define SITENUMBER_H
#include "Facility.h"
#include "Runway.h"
#include <string>
#include <vector>

using namespace std;

//class SiteNumber{
//	public:
		vector<Runway*>SiteNumber(string s, vector<Runway*>runways){
			vector<Runway*>good_runways;
			for(unsigned int i = 0; i < runways.size(); i++){
				if(runways[i]->site_number() == s){
					good_runways.push_back(runways[i]);
				}
			}
			return good_runways;
		}
		/*SiteNumber(const string sn, const int len): site_n(sn), min_rlen(len) {}
		bool operator()(Runway* i){
			return ((i->site_number() == site_n) && (i->length() >= min_rlen));
		}
		*/
//	private:
//		const string site_n;
//		const int min_rlen;
//};
#endif
