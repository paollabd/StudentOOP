#include <iostream>
#include <string>
#include <vector>
#include "gps.h"

using namespace std;


/*
 * output GPS code
*/
std::ostream& operator<<(std::ostream& os, const GPS& gps){
	os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
	return os;
}

