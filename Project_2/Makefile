prog : Driver_Phase3.o Iterator.o List.o Node.o Person.o
	g++ -std=c++11 -o prog Driver_Phase3.o Iterator.o List.o Node.o Person.o

Driver_Phase3.o : Iterator.h List.h Node.h Person.h
	g++ -std=c++11 -c Driver_Phase2.cpp

Iterator.o : Iterator.h Node.h Person.h
	g++ -std=c++11 -c Iterator.cpp
	
List.o : List.h Iterator.h Node.h Person.h
	g++ -std=c++11 -c List.cpp

Node.o : Node.h Person.h
	g++ -std=c++11 -c Node.cpp

Person.o : Person.h
	g++ -std=c++11 -c Person.cpp

clean:
	rm -f *.o
	rm -f prog
