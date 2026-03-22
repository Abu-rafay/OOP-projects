#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <vector>
#include <iostream>
#include <iterator>
#include "Passenger.h"
#include "Flight.h"

class UserInterface // abstract class
{
    public:
    virtual void menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers) const = 0;  
    template<typename T>
    static void display(const std::vector<T*>& container){
        std::cout << "------------------------------" << std::endl;
        if (container.empty()){
            std::cout << "List is empty" << std::endl;

        } else {
            for (size_t i = 0; i < container.size(); ++i){
                std::cout << *container[i] << std::endl;
            }
        }
        std::cout << "------------------------------" << std::endl;
    }
    static std::vector<Passenger*>::iterator selectPassenger(std::vector<Passenger*>& passengers){
        std::cout << "\n--- Select a passenger ---\n"; 
        display(passengers);

        if (passengers.empty()){
            return passengers.end();
        }

        int inputID;
        std::cout << "Enter the ID of the passenger.:";
        std::cin >> inputID;

        for (auto it = passengers.begin(); it != passengers.end(); ++it){
            if ((*it)->getID()== inputID){
                std::cout << "Selected: " << (*it)->getName() << std::endl;
                return it;
            }
        }
        std::cout << "Error: Passenger ID not found ." << std::endl;
        return passengers.end();
    }                 // return an A iterator
    static std::vector<Flight*>::iterator selectFlight(std::vector<Flight*>& flights){

        std::cout << "\n--- Select a flight ---\n";
        display(flights);

        if (flights.empty()){
            return flights.end();
        }

        int inputID;
        std::cout << "Enter Flight ID to select  ";
        std::cin >> inputID;

        for (auto it = flights.begin(); it!= flights.end(); ++it) {
            if ((*it)->getID()== inputID) {
                std::cout << "Flight " << inputID << "selected" << std::endl;
                return it;
            }
        }

        std::cout << "Error: Flight ID not found/" << std::endl;
        return flights.end();

    }                 // return a B iteartor
};

#endif