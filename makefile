all: main.o Time.o Date.o Appointment.o Onetime.o Monthly.o Daily.o
	g++ -g -Wall main.o Time.o Date.o Appointment.o Onetime.o Monthly.o Daily.o -o a.exe

main.o: main.cpp
	g++ -c -g -Wall main.cpp -o main.o

Time.o: Time.cpp
	g++ -c -g -Wall Time.cpp -o Time.o

Date.o: Date.cpp
	g++ -c -g -Wall Date.cpp -o Date.o

Appointment.o: Appointment.cpp
	g++ -c -g -Wall Appointment.cpp -o Appointment.o

Onetime.o: Onetime.cpp
	g++ -c -g -Wall Onetime.cpp -o Onetime.o

Monthly.o: Monthly.cpp
	g++ -c -g -Wall Monthly.cpp -o Monthly.o

Daily.o: Daily.cpp
	g++ -c -g -Wall Daily.cpp -o Daily.o
