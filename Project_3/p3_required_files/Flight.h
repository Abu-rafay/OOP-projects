#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

// fnu aburafay
class Passenger;

class Flight {
private:
    std::string airport;
    int id;
    std::string time;
    std::string day;
    int maxSeats;
    std::vector<Passenger*> passengers; // list of a passenger booked on the flight
public:
    Flight();
    Flight(std::string airport, int id, std::string time, std::string day, int maxSeats);
    // allows to read flight information
    std::string getAirport() const { return airport; }
    int getID() const { return id; }
    std::string getTime() const { return time; }
    std::string getDay() const { return day; }
    int getMaxSeats() const { return maxSeats; }
    // allows you to set a data members
    void setAirport(const std::string &a) { airport = a; }
    void setID(int i) { id = i; }
    void setTime(const std::string &t) { time = t; }
    void setDay(const std::string &d) { day = d; }
    void setMaxSeats(int m) { maxSeats = m; }

    void clear();  
    // checks if the flight is same as another flight
    bool operator==(const Flight &other) const;
    friend std::ostream& operator<<(std::ostream &os, const Flight &f);    

    //Fnu Aburafay phase 2
    void display() const;
    std::vector<Passenger*> getPassengers() const;
    int getNumPassengers() const;
    bool isFull() const;
    void overbook();
    void cancelFlight();
    void addPassenger(Passenger* p);
    void removePassenger(Passenger* p);
};

#endif