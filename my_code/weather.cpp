#include <iostream>
#include <string>
#include <vector>
#include <math.h>       /* pow */
#include "date.h"
#include "gps.h"
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * (we pass in a name and a GPS location)
 * */
Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

void Weather::display_images() const{
	for (WReading wr : wreadings)
	{
		wr.display_image();
 	}
}

// To get name, just return the attribute station_nm
string Weather::get_name() const {
    return station_nm;
}

int Weather::get_rating() const{
	return rating;
} 

// To change rating, redefine it to new_rating
void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const Weather& w) {

	os << "Weather for: " << w.get_name() << "; Rating: " << w.get_rating() << "; Location: " << w.my_loc << endl; // here
	for (WReading wr : w.wreadings) {
		os << "   " << wr << endl;
	}
	return os;
}


/*
 * WReading class: weather readings.
 */

// CELSIUS TO FARENHEIT

const double F_TO_C = 5/9;
const double C_TO_F = 9/5;


double WReading::get_tempF() const
{
	return (temperature * C_TO_F) + 32;
}


void WReading::display_image() const
{
	if (!image)
	{ 
		cout << "No image for reading " << date << endl;
	}
	else
	{
		image->display();
	}
}

ostream& operator<<(ostream& os, const WReading& wr){
	// we are delegating the output to that class
	// we don't add endl at the end because we want to give the user a choice
	os << wr.date << ": temperature: " << wr.get_tempF() << "; humidity: " << wr.humidity << "; windspeed: " << wr.windspeed;
	return os;
}

/*
 * IMAGE CLASS
 */

Image::Image(int w, int h, std::string flnm)
	: width(w), height(h), filename(flnm) 
	{
		image_buf = new char[image_sz()];
	}

// Copy Contructor
Image::Image(const Image& img2)
{
	copy_fields(img2);
}

// Destructor
Image::~Image()
{
	if (image_buf != nullptr) delete image_buf;
}

// Assignment Operator
Image& Image::operator=(const Image& img2)
{
	if (&img2 != this)
	{
		if (image_buf != nullptr) delete image_buf;
		copy_fields(img2);
	}
	return *this;
}

int Image::image_sz()
{
	return width * height;
}

void Image::copy_fields(const Image& img2)
{
	height = img2.height;
	width = img2.width;
	filename = img2.filename;
	image_buf = new char[image_sz()];
	for (int i = 0; i < image_sz(); i++)
	{
		image_buf[i] = img2.image_buf[i];
	}
}


void Image::display()
{
	cout << "Now displaying Image " << endl;
}

void Gif::display()
{
	cout << "Now displaying Gif " << endl;
}

void Jpeg::display()
{
	cout << "Now displaying Jpeg "<< endl;
}

void Png::display()
{
	cout << "Now displaying Png " << endl;
}









































// #include <iostream>
// #include <string>
// #include <vector>
// #include <math.h>       /* pow */
// #include "date.h"
// #include "gps.h"
// #include "weather.h"

// using namespace std;

// /*
//  * A constructor for weather class.
//  * (we pass in a name and a GPS location)
//  * */
// Weather::Weather(string nm, GPS loc) :
//     station_nm(nm), my_loc(loc) {
// }

// void Weather::display_images() const{ // here
// 	for (WReading wr : wreadings)
// 	{
// 		wr.display_image();
//  	}
// }

// // To get name, just return the attribute station_nm
// string Weather::get_name() const {
//     return station_nm;
// }

// // To get name, just return the attribute rating_nm
// int Weather::get_rating() const{ //Const keyword here means that the method doesn't change the object (we promisse the computer we won't change it - we save time debugging)
// 	return rating;
// } 

// // To change rating, redefine it to new_rating
// void Weather::set_rating(int new_rating) {
// 	rating = new_rating;
// }

// void Weather::add_reading(WReading wr) {
// 	wreadings.push_back(wr);
// }

// // overloading the output operator
// // operator keyword means you are overwriting/defining it, not using it
// // we use the reference to the ostream(&) because we there is information that is changing constantly, 
// // so we need the reference to it
// ostream& operator<<(ostream& os, const Weather& w) {
// 	//int r = w.get_rating();
// 	//w.set_rating(47); // Here we change rating. Since we said we wouldn't, the compiler doesn't let me
// 	//os << w.station_nm << ": rating " << r; 

// 	os << "Weather for: " << w.get_name() << "; Rating: " << w.get_rating() << "; Location: " << w.my_loc << endl; // here
// 	for (WReading wr : w.wreadings) {
// 		os << "   " << wr << endl;
// 	}
// 	// We return an ostream because we want to have a long chain of these (tie them together)
// 	// We need an ostream on the left-hand-side,
// 	// so we return an ostream object so we can chain them
// 	// cout << irkutsk << endl;
// 	// os << endl;
// 	return os;
// }


// /*
//  * WReading class: weather readings.
//  */

// // CELSIUS TO FARENHEIT

// // constant varibales are usually uppercase in C++
// const double F_TO_C = 5/9;
// const double C_TO_F = 9/5;


// double WReading::get_tempF() const // here (const)
// {
// 	return (temperature * C_TO_F) + 32; // here (9/5)
// }

// // double WReading::get_tempC()
// // {
// // 	return (temperature - 32) * F_TO_C;
// // }

// void WReading::display_image() const // here
// {
// 	if (!image)
// 	{ 
// 		cout << "No image for reading " << date << endl;
// 	}
// 	else
// 	{
// 		image->display("from wreading");
// 	}
// }

// ostream& operator<<(ostream& os, const WReading& wr){
// 	// we are delegating the output to that class
// 	// we don't add endl at the end because we want to give the user a choice
// 	os << wr.date << ": temperature: " << wr.get_tempF() << "; humidity: " << wr.humidity << "; windspeed: " << wr.windspeed;
// 	return os;
// }

// // double WReading::get_heat_index(double T, double H)
// // {
// // 	return T + H;
// // }

// // double WReading::get_windchill(double T, double V)
// // {
// // 	return 35.74 + (0.6215*T) - (35.75*(pow(V, 0.16))) + (0.4275*T*(pow(V, 0.16)));
// // }

// /*
//  * IMAGE CLASS
//  */

// Image::Image(int w, int h, std::string flnm)
// 	: width(w), height(h), filename(flnm) 
// 	{
// 		// filename = flnm;
// 		image_buf = new char[image_sz()];
// 	}

// // Copy Contructor: (copies img reference)
// Image::Image(const Image& img2)
// {
// 	copy_fields(img2);
// }

// // Destructor
// Image::~Image()
// {
// 	if (image_buf != nullptr) delete image_buf; //guaranteed not to be a valid pointer
// }

// // Assignment Operator
// Image& Image::operator=(const Image& img2)
// {
// 	if (&img2 != this)
// 	{
// 		if (image_buf != nullptr) delete image_buf;
// 		copy_fields(img2);
// 	}
// 	return *this;
// }

// int Image::image_sz()
// {
// 	return width * height;
// }

// void Image::copy_fields(const Image& img2)
// {
// 	height = img2.height;
// 	width = img2.width;
// 	filename = img2.filename;
// 	image_buf = new char[image_sz()];
// 	for (int i = 0; i < image_sz(); i++)
// 	{
// 		image_buf[i] = img2.image_buf[i];
// 	}
// }

// /*
//  * Setting 'display() = 0' here makes this an abstract 
//  * class that can't be implemented 
// */
// string Image::display(std::string s)
// {
// 	cout << "Displaying Image " << s << endl;
// 	return s;
// }

// string Gif::display(std::string s)
// {
// 	cout << "Displaying Gif " << s << endl;
// 	return s;
// }

// string Jpeg::display(std::string s)
// {
// 	cout << "Displaying Jpeg " << s << endl;
// 	return s;
// }

// string Png::display(std::string s) // here
// {
// 	cout << "Displaying Png " << s << endl;
// 	return s;
// }
