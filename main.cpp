#include "Time.h"
#include "Appointment.h"
#include "Monthly.h"
#include "Daily.h"
#include "Date.h"
#include "Onetime.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

int main() {
   char inputChar;
   string userInput;
   string fileName;
   vector<Appointment*> vectorApp;

   while (true) {
      cout << "Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): ";
      cin >> inputChar;
      //cout << inputChar << endl;

      if (inputChar == 'q') { //quit; break while loop
         break;
      }

      if (inputChar == 'd') { //daily
         Daily* d = new Daily();
         d->read();
         vectorApp.push_back(d);

         continue;
      }
      else if (inputChar == 'm') { //monthly
         Monthly* m = new Monthly();
         m->read();
         vectorApp.push_back(m);

         continue;
      }
      else if (inputChar == 'o') { //onetime
         Onetime* o = new Onetime();
         o->read();
         vectorApp.push_back(o);

         continue;
      }
      else if (inputChar == 'c') { //check
         cout << "Enter year month day: " << endl;
         int year, month, day;
         cin >> year >> month >> day;

         cout << "You have these appointments:" << endl;
         for (Appointment* element : vectorApp) {
            if (element->occurs_on(year, month, day)) {
               element->print();
            }
         }
         continue;
      }
      else if (inputChar == 's') { //save
         cout << "File name: ";
         cin >> fileName;
         ofstream outFS(fileName);
         
         if (outFS.is_open()) {
            for (Appointment* appointment : vectorApp) {
               appointment->save(outFS);
            }
            outFS.close();
         }
         cout << endl;
         continue;
      }
      else if (inputChar == 'l') { //load
         cout << "File name: ";
         cin >> fileName;
         ifstream inFS(fileName);

         if (inFS.is_open()) {
            while (!inFS.eof()) {
               string appointmentType;
               getline(inFS, appointmentType);
               if (appointmentType == "") {
                  break;
               }
               
               Appointment* appointment = nullptr;
         
               if (appointmentType == "Daily") {
                  appointment = new Daily();
               }
               else if (appointmentType == "Monthly") {
                  appointment = new Monthly();
               }
               else if (appointmentType == "Onetime") {
                  appointment = new Onetime();
               }

               appointment->load(inFS);
               vectorApp.push_back(appointment);
            }
            inFS.close();
         }
         continue;
      }

   }

   return 0;
}
