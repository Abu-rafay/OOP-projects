#include "Flight.h"
#include "Passenger.h"
#include <algorithm>
#include <iostream>
// Fnu Aburafay
Flight::Flight(): airport(""), id(0), time(""), day(""), maxSeats(0) {}
Flight::Flight(std::string airport, int id, std::string time, std::string day, int maxSeats)
    : airport(airport), id(id), time(time), day(day), maxSeats(maxSeats) {}


void Flight::clear(){ // set all the objects data to default
    airport = ""; id = 0, time = ""; day = ""; maxSeats = 0; passengers.clear();
}
bool Flight::operator==(const Flight &other) const { // checks if the one flight is same as another flight
    return (airport == other.airport) &&
           (id == other.id) &&
           (time == other.time) &&
           (day == other.day) &&
           (maxSeats == other.maxSeats);
}
std::ostream& operator<<(std::ostream &os, const Flight &f) { // display the flights objects
    os << "Flight(Airport: " << f.airport
       << ", ID: " << f.id
       << ", Time: " << f.time
       << ", Day: " << f.day
       << ", MaxSeats: " << f.maxSeats
       << ")";
    return os;
}

// phase 2

void Flight::display() const { // prints the id and airport
    std::cout << "Flight " << id <<"("<<airport<<")"
              <<" Passengers: \n";

    if (passengers.empty()) { // if the paa\ssenger is empty then cout 
        std::cout << "No passengers booked. \n";

    } else {
        for (size_t i=0; i < passengers.size(); ++i){ //we have loop that goes through every passengers list who booked this flight
            std::cout<<" "<< i+1<<". " << *passengers[i];
        }
    }
}
std::vector<Passenger*> Flight::getPassengers() const { // returning the list of passengers pointer
    return passengers;
}

bool Flight::isFull() const{ // checks if the flight is full then return true 
    return passengers.size() >= maxSeats;
}
void Flight::cancelFlight(){ // we are cenceling the whole flight 
    for (Passenger* p : passengers){ // this for loop goes through every passenger from this flight
        if (p != nullptr){ //if p is not nullpointer 
            p->cancelFlight(this); // we are telling the passengers to remove this flight from their list 
        }
    }
    passengers.clear();
}
void Flight::addPassenger(Passenger* p) {
    if (p == nullptr) return;

    // Check if passenger already booked
    for (Passenger* pass : passengers) {
        if (pass == p) {
            std::cout << "Passenger already on this flight.\n";
            return;
        }
    }

    if (isFull()) {
        std::cout << "Flight is full! Cannot add passenger.\n";
        return;
    }

    passengers.push_back(p);
    p->bookFlight(this); // arrow means go to a objecct the pointer is pointing to 
}

void Flight::removePassenger(Passenger* p) {
    if (p == nullptr) return;
// it is telling me where the passenger is  
    auto it = std::find(passengers.begin(), passengers.end(), p);
    if (it != passengers.end()) {
        passengers.erase(it);
        p->cancelFlight(this);
    }
}