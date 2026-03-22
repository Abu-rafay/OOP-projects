#include <iostream>
#include <vector>
#include <iomanip>
#include "Files.h"      
#include "Passenger.h"
#include "Flight.h"


int main() 
{   
    std::cout << std::endl;

    std::cout << std::endl;

    std::vector<Passenger*> passengers;

    std::vector<Flight*> flights;

    std::vector<Passenger*>::iterator pit;

    std::vector<Flight*>::iterator fit;

   
    readPassengers("Passenger.csv", passengers);


    readFlights("Flight.csv", flights);


    std::cout << "Passengers:\n\n";
    std::cout << std::left
              << std::setw(20) << "Name"
              << std::setw(10) << "ID"
              << std::setw(15) << "Country"
              << std::endl;
    print(passengers);      

    std::cout << "Flights:\n\n";
    std::cout << std::left
              << std::setw(10) << "Airport"
              << std::setw(8)  << "ID"
              << std::setw(8)  << "Time"
              << std::setw(10) << "Day"
              << std::setw(8)  << "Max"
              << std::endl;
    print(flights);         

    if (!passengers.empty()) {
        Passenger copyP = *passengers[0];
        std::cout << "Passenger == test: "
                  << (copyP == *passengers[0] ? "true" : "false") << "\n";
    }

    if (!flights.empty()) {
        Flight copyF = *flights[0];
        std::cout << "Flight == test: "
                  << (copyF == *flights[0] ? "true" : "false") << "\n";
    }

    clear(passengers);   
    clear(flights);      


    std::cout << std::endl;
    return 0;
}