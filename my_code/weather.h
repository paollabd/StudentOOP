#ifndef WEATHER_H
#define WEATHER_H

#include <string>

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

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
 // private attributes
 private:
 	// in general, we want to keep data private
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif