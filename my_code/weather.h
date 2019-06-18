#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"

/*
 * This will be the base class for all types of images.
 * */
class Image {
 public:
    Image(int w, int h, std::string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();

    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    std::string display(std::string s);
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */

    int get_height() { return height; }
    int get_width() { return width; }

 private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};


struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
    WReading(Date dt, double temp, double hum, double ws)
       : date(dt), temperature(temp), humidity(hum), windspeed(ws) {}

    double get_tempF();
    double get_tempC();
    // double get_tempC() { return temperature; }

 private:
    Date date;
    double temperature;  // stored temp in C
    double humidity;
    double windspeed;
};


const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    // << should output name, rating, and use the GPS << to output my_loc
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif



















/*
#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);


class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
    WReading(Date dt, double temp, double hum, double ws) :
        date(dt), temperature(temp), humidity(hum), windspeed(ws)
    {
    }

    double get_tempF();
    double get_tempC() { return temperature; }

 private:
    Date date;
    double temperature;  // stored temp in C
    double humidity;
    double windspeed;
};


const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    // << should output name, rating, and use the GPS << to output my_loc
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};

class Image{
 public:
 	Image(int w, int h, string flnm);
 	// copy contructor:
 	Image(const Image& img2);
 	~Image();
 	Image& operator = (const Image& img2);
 	int image_sz();

 	std::string display(std::string s);

 	int get_height() {return height };
 	int get_width() {return width };

 private:
 	int width;
 	int height;
 	std::string flnm;
 	char* image_buf;
 	void copy_fields(const Image& img2);

};

#endif
*/

/*

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
*/