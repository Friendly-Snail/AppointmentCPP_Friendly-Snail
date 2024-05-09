// File:   Onetime.h
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#ifndef ONETIME_H
#define ONETIME_H

#include "Appointment.h"
#include "Date.h"

//Onetime derived/inherits from Appointment class
class Onetime : public Appointment {
private:
   Date when;  // date of onetime appointment

public:

   //constructs a onetime appointment object
   Onetime();

   //constructs a onetime appointment
   //s-start time of appointment, e-end time of appointment, desc-daily appointment description, d-appointment day
   Onetime(Time s, Time e, std::string desc, Date d);

   //read in appointment; format:
   //Enter start_hours start_mins end_hours end_mins descript: (e.g. 5 0 6 0 dentist)
   //Enter date: (e.g. 2018 5 10)
   void read();

   //save monthly appointment with a header
   //format: appointment type
   //        date
   //        start_hours start_mins end_hours end_mins descript
   //e.g. Onetime
   //     2018 5 10
   //     5 0 6 0 dentist
   virtual void save(std::ostream& out) const;

   //load onetime appointment with a header; refer to read() for format
   virtual void load(std::istream& in);

   //determines if the appointment occurs on the given day
   //param: year value, month value (1 for Jan, 12 for Dec), day value
   //return true if appointment occurs on the given date
   virtual bool occurs_on(int year, int month, int day) const;

};


#endif /* ONETIME_H */
