// File:   Date.cpp
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#include "Date.h"

Date::Date () {
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

bool Date::operator==(Date other) const {
    bool comparison;
    comparison = year == other.year && month == other.month && day == other.day;

    return comparison;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
   out << date.year << " " << date.month << " " << date.day;
   return out;
}
