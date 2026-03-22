#include "Employee.h"
#include "Flight.h"
#include "Passenger.h"
#include <algorithm>
#include<iostream>

// Shafin Awal
void Employee::addFlight(std::vector<Flight*>& flights,const std::string &airport,int id,const std::string &time,const std::string &day,int maxSeats){
    Flight* newFlight = new Flight (airport, id, time, day, maxSeats);
    flights.push_back(newFlight);
}

// Cancel Flight function:
void Employee::cancelFlight(std::vector<Flight*>& flights, int flightID){
    auto it = findFlight(flights, flightID);

    if (it == flights.end()) {
        std::cout << "Flight not found.\n";
        return;
    }
// we get the flight from itrator
    Flight* f = *it;

    // 1. Remove this flight from all passengers
    f->cancelFlight();   
    // 2. Remove from flights container
    flights.erase(it);

    // 3. Delete dynamic memory
    delete f;

    std::cout << "Flight " << flightID << " canceled successfully.\n";
}
// Shafin Awal
std::vector<Flight*>::iterator Employee::findFlight(std::vector<Flight*>& flights, int flightID){
    for (auto it = flights.begin(); it != flights.end(); ++it){
        if ((*it)->getID() == flightID){
            return it;
        }
    }
    return flights.end();
}

