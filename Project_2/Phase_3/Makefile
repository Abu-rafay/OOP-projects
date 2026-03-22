# executable file to create and its dependancies
prog : driver_phase3.o List.o Iterator.o Node.o Employee.o
	g++ -std=c++11 -o prog driver_phase3.o List.o Iterator.o Node.o Employee.o

# file dependencies
driver_phase3.o : List.h Iterator.h Node.h Employee.h
	g++ -std=c++11 -c driver_phase3.cpp
List.o : List.h
	g++ -std=c++11 -c List.cpp
Iterator.o : Iterator.h
	g++ -std=c++11 -c Iterator.cpp
Node.o: Node.h
	g++ -std=c++11 -c Node.cpp
Employee.o: Employee.h
	g++ -std=c++11 -c Employee.cpp

# remove all object and executable files
clean:
	rm -f *.o
	rm prog