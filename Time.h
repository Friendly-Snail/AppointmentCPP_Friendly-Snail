// File:   Time.h
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;


const int DAYS_PER_MONTH = 30;

//class that describes a time of day
class Time {
private:
   int time_in_secs;
public:
   //constructs a Time object that is set to the time at which the constructor executes
   Time();

   //constructs time of day; hour, minutes, seconds
   Time(int hour, int min, int sec);

   //accessor; gets/returns hours of this time
   int get_hours() const;

   //accessor; gets/returns minutes of this time
   int get_minutes() const;

   //accessor; gets/returns seconds of this time
   int get_seconds() const;

   //computes seconds between this time and another; parem t is the other time
   //returns num of seconds between this time and t
   int seconds_from(Time t) const;

   //adds a number of seconds to this time; parem s the number of seconds to add
   void add_seconds(int s);

};


#endif /* TIME_H */
