# executable file to create and its dependancies
prog : driver_phase1.o List.o Iterator.o Node.o
	g++ -std=c++11 -o prog driver_phase1.o List.o Iterator.o Node.o

# file dependencies
driver_phase1.o : List.h Iterator.h Node.h
	g++ -std=c++11 -c driver_phase1.cpp
List.o : List.h
	g++ -std=c++11 -c List.cpp
Iterator.o : Iterator.h
	g++ -std=c++11 -c Iterator.cpp
Node.o: Node.h
	g++ -std=c++11 -c Node.cpp

# remove all object and executable files
clean:
	rm -f *.o
	rm prog