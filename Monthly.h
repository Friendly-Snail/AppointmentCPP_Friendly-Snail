// File:   Monthly.h
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#ifndef MONTHLY_H
#define MONTHLY_H

#include "Time.h"
#include "Appointment.h"
#include <iostream>

//Monthly derived/inherits from Appointment class
class Monthly : public Appointment {
private:
   int day;  // day of the appointment

public:
   //constructs a monthly appointment object
   Monthly();

   //constructs a monthly appointment
   //s-start time of appointment, e-end time of appointment, desc-daily appointment description, d-appointment day
   Monthly(Time s, Time e, std::string desc, int d);

   //read in appointment; format:
   //Enter start_hours start_mins end_hours end_mins descript: (e.g. 5 0 6 0)
   //Enter day: (e.g. 5)
   void read();
  
   //save monthly appointment with a header
   //format: appointment type
   //        day
   //        start_hours start_mins end_hours end_mins descript
   //e.g. Monthly
   //     5
   //     5 0 6 0 dentist
   virtual void save(std::ostream& out) const;

   //load monthly appointment with a header; refer to read() for format
   virtual void load(std::istream& in);

   //determines if the appointment occurs on the given day
   //param: year value, month value (1 for Jan, 12 for Dec), day value
   //return true if appointment occurs on the given date
   virtual bool occurs_on(int year, int month, int day) const;

};


#endif /* MONTHLY_H */
