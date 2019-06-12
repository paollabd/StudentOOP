#include <iostream>
#include <string>
#include <vector>
#include <math.h>       /* pow */
#include "date.h"
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * (we pass in a name and a GPS location)
 * */
Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

// To get name, just return the attribute station_nm
string Weather::get_name() const {
    return station_nm;
}

// To get name, just return the attribute rating_nm
int Weather::get_rating() const{ //Const keyword here means that the method doesn't change the object (we promisse the computer we won't change it - we save time debugging)
	return rating;
} 

// To change rating, redefine it to new_rating
void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

// overloading the output operator
// operator keyword means you are overwriting/defining it, not using it
// we use the reference to the ostream(&) because we there is information that is changing constantly, 
// so we need the reference to it
ostream& operator<<(ostream& os, const Weather& w) {
	//int r = w.get_rating();
	//w.set_rating(47); // Here we change rating. Since we said we wouldn't, the compiler doesn't let me
	//os << w.station_nm << ": rating " << r; 

	os << w.get_name() << ": rating: " << w.get_rating() << "; " << w.my_loc << endl;
	for (WReading wr : w.wreadings) {
		os << "   " << wr << endl;
	}

	// We return an ostream because we want to have a long chain of these (tie them together)
	// We need an ostream on the left-hand-side,
	// so we return an ostream object so we can chain them
	// cout << irkutsk << endl;
	// os << endl;
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

/*
 * output GPS code
*/
std::ostream& operator<<(std::ostream& os, const GPS& gps){
	os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
	return os;
}

/*
 * WReading class: weather readings.
 */
ostream& operator<<(ostream& os, const WReading& wr){
	// we are delegating the output to that class
	// we don't add endl at the end because we want to give the user a choice
	os << wr.date << ": temperature: " << wr.temperature << "; humidity: " << wr.humidity << "; windspeed: " << wr.windspeed;
	return os;
}

// constant varibales are usually uppercase in C++
// const double F_TO_C = 5/9;
// const double C_TO_F = 9/5;


// double WReading::get_tempF()
// {
// 	// return (tempC * (9/5)) + 32;
// 	return (temperature * C_TO_F) + 32;
// }

// double WReading::get_tempC()
// {
// 	return (temperature - 32) * 5/9;
// }

// double WReading::get_heat_index(double T, double H)
// {
// 	return T + H;
// }

// double WReading::get_windchill(double T, double V)
// {
// 	return 35.74 + (0.6215*T) - (35.75*(pow(V, 0.16))) + (0.4275*T*(pow(V, 0.16)));
// }

