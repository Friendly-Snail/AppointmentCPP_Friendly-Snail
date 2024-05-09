// File:   Onetime.cpp
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#include "Onetime.h"

Onetime::Onetime() {}

Onetime::Onetime(Time s, Time e, std::string desc, Date d) : Appointment(s, e, desc) {
    when = d;
}

void Onetime::read() {
    Appointment::read();

    std::cout << "Enter year month day: ";
    int year, month, day;
    std::cin >> year >> month >> day;
    std::cout << std::endl;

    when = Date(year, month, day);
}

void Onetime::save(std::ostream& out) const {
    out << "Onetime" << std::endl;
    out << when << std::endl;
    Appointment::save(out);
}

void Onetime::load(std::istream& in) {
    //std::string appointmentType;
    int year, month, day;

    //getline(in, appointmentType);
    in >> year >> month >> day;
    when = Date(year, month, day);

    Appointment::load(in);
}

bool Onetime::occurs_on(int year, int month, int day) const {
    bool occurance;
    occurance = when == Date(year, month, day);

    return occurance;
}

