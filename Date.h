// File:   Date.h
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#ifndef DATE_H
#define DATE_H

#include <iostream>

//class that describes a date
class Date {
private:
   int year;
   int month;
   int day;  

public:
   //constructs a date object that is set to the date at which the constructor executes
   Date();

   //constructs a date; year, month, day
   Date(int y, int m, int d);

   //accessor; gets/returns the year
   int get_year() const;

   //accessor; gets/returns the month
   int get_month() const;

   //accessor; gets/returns the day
   int get_day() const;

   //compare this date with other date
   bool operator==(Date other) const;

   friend std::ostream& operator<<(std::ostream& out, const Date& date);
   
};


#endif /* DATE_H */
