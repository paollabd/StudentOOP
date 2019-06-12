#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

// // Date class
// class Date {
// 	friend std::ostream& operator<<(std::ostream& os, const Date& date);
//  // a class is private by default, so we have to make it public
//  public:
// 	Date(int d, int m, int y);
//  private:
//  	int day;
//  	int month;
//  	int year;
// };

// Weather Reading class
class WReading {
	friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
 	WReading(Date dt, double temp, double hum, double ws) :
	date(dt), temperature(temp), humidity(hum), windspeed(ws)
	{
	}

 private: 
	Date date;
	double temperature; // stored temp in C
	double humidity;
	double windspeed;
};

const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

// class Weather and its attributes
class Weather {
	// << should output name, rating, and use the GPS << to output my_location
	
	// overloading the output operator
	friend std::ostream& operator<<(std::ostream& os, const Weather& w); // friend keyword --> this function can access the private data of the class
 // public attributes
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const; // const here means that the method doesn't change the object
    void set_rating(int new_rating);
    void add_reading(WReading wr); // linker error because we have a declaration but not a definition
 // private attributes
 private:
 	std::vector<WReading> wreadings; // by default we get an empty vector
 	// in general, we want to keep data private
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};



#endif