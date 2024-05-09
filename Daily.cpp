// File:   Daily.cpp
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#include "Daily.h"

Daily::Daily() {}

Daily::Daily(Time s, Time e, std::string desc) : Appointment(s, e, desc) {}

void Daily::save(std::ostream& out) const {
    out << "Daily" << std::endl;
    Appointment::save(out);
}

bool Daily::occurs_on(int year, int month, int day) const {
    return true;
}

