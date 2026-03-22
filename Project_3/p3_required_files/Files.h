#ifndef FILES_H
#define FILES_H
#include <fstream>    
#include <sstream>     
#include <vector>      
#include <iostream>   
#include "Passenger.h"
#include "Flight.h"
// Shafin Awal 

void readPassengers(std::string filename, std::vector<Passenger*>& container) {
    std::ifstream file(filename);

    if(!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    // create a variable to store a line and temporary piece of line
    std::string line, temp;

    while(std::getline(file, line)) {
        Passenger* p = new Passenger();
        std::stringstream parser(line);

        std::getline(parser, temp, ',');
        (*p).setName(temp);

        std::getline(parser, temp, ',');
        (*p).setID(std::stoi(temp));

        std::getline(parser, temp, ',');
        (*p).setCountry(temp);

        container.push_back(p);
    }
    file.close();
}
// Fnu Aburafay

void readFlights(const std::string &filename, std::vector<Flight*> &container) {
    std::ifstream file(filename);

    if(!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line, temp;
    while(std::getline(file, line)) {
        if(line.empty()) continue;

        Flight* f = new Flight();
        std::stringstream parser(line);

        std::string airport, time, day;
        int id = 0;
        int maxSeats = 0;

        std::getline(parser, airport, ',');
        f->setAirport(airport);

        std::getline(parser, temp, ',');
        id = std::stoi(temp);
        f->setID(id);

        std::getline(parser, time, ',');
        f->setTime(time);

        std::getline(parser, day, ',');
        f->setDay(day);

        std::getline(parser, temp, ',');
        maxSeats = std::stoi(temp);
        f->setMaxSeats(maxSeats);

        container.push_back(f);
    }
    file.close();
}
// Shafin Awal
template<typename T>
void print(const std::vector<T*> &vec)
{
    auto it = vec.begin();
    while(it != vec.end()) {
        std::cout << **it << " \n"; // the actual object pointer point to
        ++it;
    }
}

// Shafin Awal
template<typename T>
void clear(std::vector<T*> &vec)
{
    auto it = vec.begin();
    while(it != vec.end()) {
        delete *it;
        ++it;
    }
    vec.clear();
    std:: cout << "Container cleared.\n";
}

#endif