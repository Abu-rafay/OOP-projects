#include "Passenger.h"
#include "Flight.h"
#include <algorithm>
#include <iostream>

// Shafin Awal
Passenger::Passenger() : name(""), id(0), country("") {}
// parameter constructor
Passenger::Passenger(std::string name, int id, std::string country)
    : name(name), id(id), country(country) {}
// empty all the passenger data without distroying it.
void Passenger::clear() {
    name ="";
    id = 0;
    country = "";
    flights.clear();    
}
// checks if any passengers data matches to eacother
bool Passenger::operator==(const Passenger& other) const {
    return (name == other.name) && (id == other.id) && (country == other.country);
}
// printing out the passengers objects.
std::ostream& operator<<(std::ostream& os, const Passenger& p) {
    os << "Passenger Name: " << 
    p.name << ", ID: " << 
    p.id << ", Country: " << 
    p.country << "\n";
    return os;
}
// prints the passengers basic information and the number of flights.
void Passenger::display() const {
    std::cout << "Passenger Name: " << name 
              << ", ID: " << id 
              << ", Country: " << country 
              << ", Number of Flights: " << getNumFlights() << "):" << "\n";
    if (flights.empty()){
                std::cout << " No booked flights.\n";
    } else {
        for (size_t i = 0; i <flights.size(); ++i){ // this goes to every flight that passenger has booked
            if (flights[i] != nullptr) {// this checks if the flight is exist before we use it
                std::cout << "  "<< i + 1 <<". " <<*flights[i] << "\n";
            }
        }
    }
}
// return the list of flight passenger booked
    std::vector<Flight*> Passenger::getFlights() const {
        return flights;
    }
    // it shows how many flights the passenger has booked
    int Passenger::getNumFlights() const {
        return flights.size();
    }
// Books a flight for a passenger while preventing duplicate bookings and unsafe pointer usage.
    void Passenger::bookFlight(Flight* flight) {
        if (flight == nullptr) {
            return;
        }
        bool alreadyBooked = false;
        for (Flight* f : flights){ // range based for loop{ //it goes on each flight passenger has and checks if it is the same flight 
            if (f == flight) {
               alreadyBooked = true;
               break; 
            }
        }
        if (!alreadyBooked) { // if flight is not booked
            flights.push_back(flight);// add it to the passenger flight list
        } else {
            std::cout << "Flight already booked for this passenger.\n";
        
        }
    }
    void Passenger::cancelFlight(Flight* flight) {
        if (flight == nullptr) {
            return;
        }

        auto it = std::find(flights.begin(), flights.end(), flight);
        if (it != flights.end()) { // if the flight was found in the list 
            flights.erase(it); // removes the flight
        }
    }

