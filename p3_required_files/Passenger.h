#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
// Shafin Awal
class Flight;
// Shafin Awal
class Passenger {
private:
    std::string name;
    int id;
    std::string country;
    std::vector<Flight*> flights;
public:
    Passenger();
    Passenger(std::string name, int id, std::string country);
    //accessor data- only read this private data can't modify
    std::string getName() const{return name;}
    int getID() const {return id;}
    std::string getCountry() const {return country;}
    // mutators, setter functions used to update a passenger’s private data safely.
    void setName(const std::string& n) { name = n;}
    void setID(int i) {id = i;}
    void setCountry(std::string c) { country = c;}

    
    void clear();  
    bool operator==(const Passenger& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Passenger& p);    

    void display() const;
    std::vector<Flight*> getFlights() const; 
    int getNumFlights() const;

    void bookFlight(Flight* flight);
    void cancelFlight(Flight* flight);
};

#endif
