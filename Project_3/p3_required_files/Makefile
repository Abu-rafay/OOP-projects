prog : driver_phase_3.o Passenger.o Flight.o Employee.o Passenger_UI.o Employee_UI.o
	g++ -std=c++11 -o prog driver_phase_3.o Passenger.o Flight.o Employee.o Passenger_UI.o Employee_UI.o

driver_phase_3.o :	Passenger.h Flight.h 
	g++ -std=c++11 -c driver_phase_3.cpp

Passenger.o : Passenger.h 
	g++ -std=c++11 -c Passenger.cpp

Flight.o : Flight.h 
	g++ -std=c++11 -c Flight.cpp

Employee.o : Employee.h 
	g++ -std=c++11 -c Employee.cpp

Passenger_UI.o : Passenger_UI.h 
	g++ -std=c++11 -c Passenger_UI.cpp

Employee_UI.o : Employee_UI.h
	g++ -std=c++11 -c Employee_UI.cpp

# remove all object and executable files
clean:
	rm -f *.o
	rm -f prog

