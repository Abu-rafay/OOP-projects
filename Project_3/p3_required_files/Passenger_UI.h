#ifndef PASSENGER_UI_H
#define PASSENGER_UI_H

#include "UserInterface.h"
#include "Passenger.h"
#include "Flight.h"
#include <vector>
//shafin Awal

class Passenger_UI : public UserInterface// inherit from UI
{
    public:
    void menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers) const override; 

    void bookFlight(std::vector<Passenger*>::iterator p_it, std::vector<Flight*>& flights) const;
    //fnu Aburafay
    void cancelFlight(std::vector<Passenger*>::iterator p_it)const;         
};

#endif