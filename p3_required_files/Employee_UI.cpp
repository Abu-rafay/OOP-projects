#include "Employee_UI.h"
#include "UserInterface.h"
#include <iostream>
#include <limits>
//fnu aburafay
void EmployeeUI::menu(std::vector<Flight*> &flights,
                      std::vector<Passenger*> &passengers) const
{
    int option = 0;

    do {
        std::cout << "\n--- EMPLOYEE MENU ---\n";
        std::cout << "1) Display all flights\n";
        std::cout << "2) Add a flight\n";
        std::cout << "3) Remove a flight\n";
        std::cout << "4) Exit to main menu\n";
        std::cout << "Select: ";
        std::cin >> option;

        switch(option) {
            case 1:
                UserInterface::display(flights);
                break;

            case 2:
                addB(flights);
                break;

            case 3: {
                if (flights.empty()) {
                    std::cout << "No flights to delete.\n";
                    break;
                }
                auto fIt = UserInterface::selectFlight(flights);// which flight you want to rmove 
                dropB(flights, fIt); // it removes the flight from iterator
                break;
            }

            case 4:
                return;

            default:
                std::cout << "Invalid option.\n";
        }

    } while(option != 4);
}

void EmployeeUI::addB(std::vector<Flight*> &flights)
{
    std::string airport, time, day;
    int id, maxSeats;

    std::cout << "Enter flight ID: ";
    std::cin >> id;

    std::cout << "Enter airport: ";
    std::cin >> airport;

    std::cout << "Enter time (XX:XX): ";
    std::cin >> time;

    std::cout << "Enter day: ";
    std::cin >> day;

    std::cout << "Enter max seats: ";
    std::cin >> maxSeats;

    Flight *f = new Flight(airport, id, time, day, maxSeats);
    flights.push_back(f);

    std::cout << "Flight added.\n";
}
void EmployeeUI::dropB(std::vector<Flight*> &flights,
                       std::vector<Flight*>::iterator fIt)
{
    delete *fIt;
    flights.erase(fIt);

    std::cout << "Flight removed.\n";
}