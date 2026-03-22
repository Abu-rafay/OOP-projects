#ifndef EMPLOYEE_UI_H
#define EMPLOYEE_UI_H

#include <iostream>
#include <vector>
#include "UserInterface.h"
#include "Flight.h"
#include "Passenger.h"
//fnu aburafay
class EmployeeUI : public UserInterface // inherit from UI
{
    public:
    void menu(std::vector<Flight*> &flights, std::vector<Passenger*> &passengers) const;     
    static void addB(std::vector<Flight*> &flights); 
    static void dropB(std::vector<Flight*> &flights, std::vector<Flight*>::iterator fIt);    
};

#endif