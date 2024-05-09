// File:   Monthly.cpp
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#include "Monthly.h"

Monthly::Monthly() {}

Monthly::Monthly(Time s, Time e, std::string desc, int d) : Appointment(s, e, desc) {
    day = d;
}

void Monthly::read() {
    Appointment::read();
    //std::cin.ignore();

    std::cout << "Enter day: ";
    int d;
    std::cin >> d;
    day = d;
    std::cout << std::endl;
}

void Monthly::save(std::ostream& out) const {
    out << "Monthly" << std::endl;
    out << day << std::endl;
    Appointment::save(out);
}

void Monthly::load(std::istream& in) {
    //std::string appointmentType;
    int day;

    //getline(in, appointmentType);
    in >> day;
    this->day = day;
    Appointment::load(in);
}

bool Monthly::occurs_on(int year, int month, int day) const {
    bool occurance;
    occurance = this->day == day;

    return occurance;
}

