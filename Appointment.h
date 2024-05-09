// File:   Appointment.h
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Time.h"
#include <iostream>
#include <string>

//class that describes appointment
class Appointment {
private:
   std::string description;  // appointment description
   Time start;  // start time appointment
   Time end;    // end time appointment

public:
   //constructs an appointment object
   Appointment();

   //constructs an appointment; s-start time of appointment, e-end time of appointment, desc-appointment description
   Appointment(Time s, Time e, std::string desc);

   //print out appoint; format: 5:00 - 6:00 dentist
   void print() const;

   //read in appoint; format: start_hours start_mins end_hours end_mins descript
   //e.g. 5 0 6 0 dentist
   void read();

   //save appointment to file seperate by space 
   //format: start_hours start_mins end_hours end_mins descript
   //e.g. 5 0 6 0 dentist
   virtual void save(std::ostream& out) const;

   //load appointment from file; format: start_hours start_mins end_hours end_mins descript
   //e.g. 5 0 6 0 dentist
   virtual void load(std::istream& in);

   //determines if the appointment occurs on the given date
   //param: year value, month value (1 for Jan, 12 for Dec), day value
   //return true if appointment occurs on the given date
   virtual bool occurs_on(int year, int month, int day) const = 0; //pure virtual function

   //virtual destructor
   virtual ~Appointment();

};


#endif /* APPOINTMENT_H */
