#include <iostream>
#include <string>
#include <vector>
#include "date.h"
//#include "weather.h"

using namespace std;
/*
 * Date class
*/

Date::Date(int d, int m, int y) {
	if ((d < 1) || (d > 31)) throw(d); // throw break out
	if ((m < 1) || (m > 12)) throw(m);
	if ((y < 1800) || (y > 2200)) throw(y);

	day = d;
	month = m;
	year = y;
}

/*
 * output Date code
*/
ostream& operator<<(ostream& os, const Date& date){
	os << date.month << "/" << date.day << "/" << date.year;
	return os;
}

