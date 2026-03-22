#include "Passenger_UI.h"
#include <iostream>
#include <limits>

void Passenger_UI::menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers)const{
    while (true){
        auto p_it = selectPassenger(passengers);
        if(p_it == passengers.end()){
            return;
        }
        bool staying = true;
        while(staying){
            std::cout << "\n-------------------------\n";
            std::cout << "PASSSENGER MENU: " << (*p_it)->getName() << "\n";
            std::cout << "-------------------------\n";
            std::cout << "a. Display all flights\n";
            std::cout << "b. Book a flight\n";
            std::cout << "c. Cancel a flight\n";
            std::cout << "d. Display booked flights\n";
            std::cout << "e. Switch to a different passenger\n";
            std::cout << "f. Exit to main menu\n";
            std::cout << "Enter option: ";

            char option;
            std::cin >> option;

            switch (option) {
                case 'a':
                    display(flights);
                    break;
                case 'b':
                    bookFlight(p_it, flights);
                    break;
                case 'c':
                    cancelFlight(p_it);
                    break;
                case 'd':
                    (*p_it)->display();
                    break;
                case 'e':
                    staying = false;
                    break;
                case 'f':
                    return;
                default:
                    std::cout << "Invalid Option. Try again. \n";
            }
        }
    }
}

void Passenger_UI::bookFlight(std::vector<Passenger*>::iterator p_it, std::vector<Flight*>& flights)const{
    std::vector<Flight*>::iterator f_it = selectFlight(flights);
    if (f_it != flights.end()) {
        (*p_it)->bookFlight(*f_it);
        std::cout << "Booking attempt complete. \n";

    } else {
        std::cout << "Booking cancelled.\n";
    }
}
//fnu aburafay
void Passenger_UI::cancelFlight(std::vector<Passenger*>::iterator p_it)const{
    std::vector<Flight*> booked = (*p_it)->getFlights();

    if (booked.empty()) {
        std::cout << "You have no booked flights.\n";
        return;
    }
    UserInterface::display(booked); //show all flights passenger has booked

    int id;
    std::cout << "Enter Flight ID to cancel: ";
    std::cin >> id;

    for (Flight* f : booked) {
        if (f->getID() == id) {

            (*p_it)->cancelFlight(f);       

            f->removePassenger(*p_it);     

            std::cout << "Flight " << id << " cancelled.\n";
            return;
        }
    }

    std::cout << "Flight not found in your booked list.\n";
}