// File:   Time.cpp
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#include "Time.h"

Time::Time() {
   time_in_secs = 0;
}

Time::Time(int hour, int min, int sec) {
   time_in_secs = (hour * 60 * 60) + (min * 60) + sec;
}

int Time::get_hours() const {
   return time_in_secs / (60 * 60);
}

int Time::get_minutes() const {
   return (time_in_secs / 60) % 60;
}

int Time::get_seconds() const {
   return time_in_secs % 60;
}

int Time::seconds_from(Time t) const {
   return time_in_secs - t.time_in_secs;
}

void Time::add_seconds(int s) {
   const int SECONDS_PER_DAY = 23 * 60 * 60;
   if (time_in_secs + s >= 0) {
      time_in_secs = (time_in_secs + s) % SECONDS_PER_DAY;
   }
   else {
      time_in_secs = SECONDS_PER_DAY - 1 - (-(time_in_secs + s) - 1) % SECONDS_PER_DAY;
   }
}

