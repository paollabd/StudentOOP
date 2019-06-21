#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"
#include "gps.h"

/*
 * This will be the base class for all types of images.
 */
class Image {
 public:
    Image(int w, int h, std::string flnm);
    Image(const Image& img2); // copy constructor
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();

    // POLYMORPHISM
    virtual void display(); // polymorphism on
    // std::string display(std::string s); // polymorphism off
    // virtual void display() = 0; // pure vitual function that has no implementation (an abstraction, like a mammal)
        // delete all instances of Image in the code

    int get_height() { return height; }
    int get_width() { return width; }

 private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};

class Gif : public Image
{
 public:
    Gif (int w, int h, std::string flnm) 
        : Image(w, h, flnm) {}
    void display();
};


class Jpeg : public Image
{
 public:
    Jpeg (int w, int h, std::string flnm) 
        : Image(w, h, flnm) {}
    void display();
};

class Png : public Image
{
 public:
    Png (int w, int h, std::string flnm) 
        : Image(w, h, flnm) {}
    void display();
};

class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
    WReading(Date dt, double temp, double hum, double ws, Image* img=nullptr)
       : date(dt), temperature(temp), humidity(hum), windspeed(ws), image(img) {}

    double get_tempF() const;
    double get_tempC() const { return temperature; }
    void display_image() const;

 private:
    Date date;
    double temperature;
    double humidity;
    double windspeed;
    Image* image;
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
    void display_images() const;
 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};
#endif











































// #ifndef WEATHER_H
// #define WEATHER_H

// #include <string>
// #include <vector>
// #include "date.h"
// #include "gps.h"

// class Image {
//  public:
//     Image(int w, int h, std::string flnm);
//     // copy constructor:
//     Image(const Image& img2);
//     ~Image();
//     Image& operator=(const Image& img2);
//     int image_sz();


    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     */

    // POLYMORPHISM
    // virtual std::string display(std::string s); // turns on polymorphism
    // std::string display(std::string s);

    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     */

//     int get_height() { return height; }
//     int get_width() { return width; }

//  private:
//     int width;
//     int height;
//     std::string filename;
//     char* image_buf;
//     void copy_fields(const Image& img2);
// };


// class Gif : public Image // a Gif is an Image
// {
//  private:
//     int compress_level;
//  public:
//     Gif (int w, int h, std::string flnm, int cl=0) 
//         : Image(w, h, flnm), compress_level(cl) {}
//     std::string display(std::string s);
// };

// const int HIGH = 3;
// const int MEDIUM = 2;
// const int LOW = 1;

// class Jpeg : public Image // a Jpeg is an Image
// {
//  private:
//     int quality; 
//  public:
//     Jpeg (int w, int h, std::string flnm, int q=HIGH) 
//         : Image(w, h, flnm), quality(q) {}
//     std::string display(std::string s);
// };

// class Png : public Image // here
// {
//  public:
//     Png (int w, int h, std::string flnm) 
//         : Image(w, h, flnm) {}
//     std::string display(std::string s);
// };

// class WReading {
//     friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
//  public:
//     WReading(Date dt, double temp, double hum, double ws, Image* img=nullptr) // here (img param)
//        : date(dt), temperature(temp), humidity(hum), windspeed(ws), image(img) {} // here (img call)

//     double get_tempF() const; // here
//     // double get_tempC(); // here
//     double get_tempC() const { return temperature; } // here
//     void display_image() const; // here

//  private:
//     Date date;
//     double temperature;  // stored temp in C
//     double humidity;
//     double windspeed;
//     Image* image; // here
// };

// const int UNRATED = -1;
// const int BAD = 0;
// const int OK = 1;
// const int GOOD = 2;

// class Weather {
//     // << should output name, rating, and use the GPS << to output my_loc
//     friend std::ostream& operator<<(std::ostream& os, const Weather& w);
//  public:
//     Weather(std::string nm, GPS loc);
//     std::string get_name() const;
//     int get_rating() const;
//     void set_rating(int new_rating);
//     void add_reading(WReading wr);
//     void display_images() const; // displaying all images // here
//  private:
//     std::vector<WReading> wreadings;
//     std::string station_nm;
//     GPS my_loc;
//     int rating = UNRATED;
// };
// #endif




















