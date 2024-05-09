// File:   Daily.h
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#ifndef DAILY_H
#define DAILY_H

#include "Time.h"
#include "Appointment.h"

//Daily derived/inherits from Appointment class
class Daily : public Appointment {
public:

   //constructs a daily appointment object
   Daily();

   //constructs a daily appointment
   //s-start time of appointment, e-end time of appointment, desc-daily appointment description 
   Daily(Time s, Time e, std::string desc);    
  
   //save daily appointment with a header
   //format: appointment type
   //        start_hours start_mins end_hours end_mins descript
   //e.g. Daily
   //     5 0 6 0 dentist
   virtual void save(std::ostream& out) const;

   //determines if the appointment occurs on the given day
   //param: year value, month value (1 for Jan, 12 for Dec), day value
   //return true if appointment occurs on the given date
   virtual bool occurs_on(int year, int month, int day) const;
};


#endif /* DAILY_H */
