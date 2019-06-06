#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * (we pass in a name and a GPS location)
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

// To get name, just return the attribute station_nm
string Weather::get_name() const {
    return station_nm;
}

// To get name, just return the attribute rating_nm
int Weather::get_rating() const{ // Const keyword here means that the method doesn't change the object (we promisse the computer we won't change it - we save time debugging)
	return rating;
} 

// To change rating, redefine it to new_rating
void Weather::set_rating(int new_rating){
	rating = new_rating;
}

// overloading the output operator
// operator keyword means you are overwriting/defining it, not using it
// we use the reference to the ostream(&) because we there is information that is changing constantly, 
// so we need the reference to it
ostream& operator<<(ostream& os, const Weather& w){

	//int r = w.get_rating();
	//w.set_rating(47); // Here we change rating. Since we said we wouldn't, the compiler doesn't let me
	//os << w.station_nm << ": rating " << r; 

	os << w.get_name() << ": rating " << w.get_rating() << " " << w.my_loc;;

	// We return an ostream because we want to have a long chain of these (tie them together)
	// We need an ostream on the left-hand-side,
	// so we return an ostream object so we can chain them
	// cout << irkutsk << endl;
	// os << endl;
	return os;
}

/*
 * output GPS code
*/
std::ostream& operator<<(std::ostream& os, const GPS& gps){
	os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
	return os;
}

// /*
//  * Date class
// */
// Date::Date(int d, int m, int y) {
// 	if ((d < 1) || (d > 31)) throw(d); // throw break out
// 	if ((m < 1) || (m > 12)) throw(m);
// 	if ((y < 1800) || (y > 2200)) throw(y);

// 	day = d;
// 	month = m;
// 	year = y;
// }

// /*
//  * output Date code
// */
// ostream& operator<<(ostream& os, const Date& date){
// 	os << date.month << "/" << date.day << "/" << date.year;
// 	return os;
// }