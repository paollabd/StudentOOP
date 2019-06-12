#ifndef DATE_H
#define DATE_H

#include <string>
#include <vector>

// Date class
class Date {
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
 // a class is private by default, so we have to make it public
 public:
	Date(int d, int m, int y);
 private:
 	int day;
 	int month;
 	int year;
};

#endif