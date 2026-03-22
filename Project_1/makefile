prog : driver_phase3.o Container.o Files.o Algorithms.o
	g++ -std=c++11 -o prog driver_phase3.o Container.o Files.o Algorithms.o

driver_phase3.o : driver_phase3.cpp Container.h Files.h Algorithms.h			
	g++ -std=c++11 -c driver_phase3.cpp

Container.o : Container.cpp Container.h
	g++ -std=c++11 -c Container.cpp
	
Files.o : Files.cpp Files.h Container.h
	g++ -std=c++11 -c Files.cpp

Algorithms.o : Algorithms.cpp Algorithms.h Container.h
	g++ -std=c++11 -c Algorithms.cpp


clean:
	rm -f *.o
	rm prog
		
