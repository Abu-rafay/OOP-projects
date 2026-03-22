#include <iostream>
#include <vector>
#include <limits>
#include "Files.h"
#include "Passenger.h"
#include "Flight.h"
#include "UserInterface.h"
#include "Passenger_UI.h"   
#include "Employee_UI.h"    

// Fnu Aburafay
void menu(std::vector<Flight*> &flights, std::vector<Passenger*> &passengers) {
    UserInterface* ui = nullptr;
    int option = 0;

    do {
        std::cout << "\nLOGIN AS:\n";
        std::cout << "1) Passenger\n";
        std::cout << "2) Employee\n";
        std::cout << "3) Exit Program\n";
        std::cout << "Select: ";
        std::cin >> option;
        std::cout << std::endl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option.\n";
            continue;
        }

        switch(option) {
            case 1:
                ui = new Passenger_UI();
                break;
            case 2:
                ui = new EmployeeUI();
                break;
            case 3:
                std::cout << "Exiting program...\n";
                return;
            default:
                std::cout << "Invalid option.\n";
                continue;
        }

        if (ui) {
            ui->menu(flights, passengers);
            if (std::cin.fail()) std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            delete ui;
            ui = nullptr;
        }

    } while (option != 3);
}

int main()
{
    std::cout << std::endl;

    std::vector<Passenger*> passengers;

    std::vector<Flight*> flights;

    std::vector<Passenger*>::iterator pIt;

    std::vector<Flight*>::iterator fIt;

    readPassengers("Passenger.csv", passengers);

    readFlights("Flight.csv", flights);

    menu(flights, passengers);

    clear(passengers);
    clear(flights);

    std::cout << std::endl;
    return 0;
}
