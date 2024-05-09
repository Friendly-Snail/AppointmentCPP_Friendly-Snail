// File:   newCxxTest.h
// Copyright 2023
// Author: Rawindhya Hettiarachchi

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>

#include "Time.h"
#include "Appointment.h"
#include "Monthly.h"
#include "Daily.h"
#include "Date.h"
#include "Onetime.h"

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testDaily() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        Daily* dailyName = new Daily();
        TS_ASSERT_EQUALS(dailyName->occurs_on(0, 0, 0), true);
        delete dailyName;

        dailyName = new Daily(Time(1, 1, 1), Time(1, 1, 1), "1");
        std::ofstream outFS("daily.txt");
        dailyName->save(outFS);
        std::ifstream inFS("daily.txt");
        string line;
        std::getline(inFS, line);
        TS_ASSERT_EQUALS(line, "Daily");
        delete dailyName;
    }
    void testMonthly() {
        Monthly* monthyName = new Monthly;
        
    }
};


#endif /* NEWCXXTEST_H */
