// File:   Appointment.cpp
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#include "Appointment.h"

Appointment::Appointment() {}

Appointment::Appointment(Time s, Time e, std::string desc) {
    start = s;
    end = e;
    description = desc;
}

void Appointment::print() const {
    std::cout << " " << start.get_hours() << ":";
    if (start.get_minutes() < 10) {
        std::cout << "0";
    }
    std::cout << start.get_minutes() << " - ";

    std::cout << end.get_hours() << ":";
        if (end.get_minutes() < 10) {
        std::cout << "0";
    }
    std::cout << end.get_minutes() << " " << description << std::endl;
}

void Appointment::read() {
    int start_hours;
    int start_mins;
    int end_hours;
    int end_mins;

    std::cout << "Enter start_hours start_mins end_hours end_mins description:" << std::endl;
    std::cin >> start_hours >> start_mins >> end_hours >> end_mins;
    std::getline(std::cin, description);

    start = Time(start_hours, start_mins, 0);
    end = Time(end_hours, end_mins, 0);
}

void Appointment::save(std::ostream& out) const {
    out << start.get_hours() << " " << start.get_minutes() << " " 
        << end.get_hours() << " " << end.get_minutes() << " " 
        << description << std::endl;
}

void Appointment::load(std::istream& in) {
    int start_hours;
    int start_mins;
    int end_hours;
    int end_mins;
    
    in >> start_hours >> start_mins >> end_hours >> end_mins;
    //in.ignore()
    std::getline(in, description);

    start = Time(start_hours, start_mins, 0);
    end = Time(end_hours, end_mins, 0); 
}

Appointment::~Appointment() {

}

