#include <iostream>
#include <vector>
#include <iomanip>

#include "Files.h"
#include "Passenger.h"
#include "Flight.h"
#include "Employee.h"

// fnu Aburafay(fixed the code)
// shafin awal(fixed the code)
// Joel Adjei
int main() {
    std::vector<Passenger*> passengers;
    std::vector<Flight*> flights;
    std::vector<Employee*> employees;

    readPassengers("Passenger.csv", passengers);
    readFlights("Flight.csv", flights);

    // Print passengers
    std::cout << "Passengers:\n\n";
    std::cout << std::left
              << std::setw(20) << "Name"
              << std::setw(10) << "ID"
              << std::setw(15) << "Country"
              << std::endl;
    print(passengers);

    // Print flights
    std::cout << "\nFlights:\n\n";
    std::cout << std::left
              << std::setw(10) << "Airport"
              << std::setw(8)  << "ID"
              << std::setw(8)  << "Time"
              << std::setw(10) << "Day"
              << std::setw(8)  << "Max"
              << std::endl;
    print(flights);

    // Equality tests
    if (!passengers.empty()) {
        Passenger copyP = *passengers[0];
        std::cout << "Passenger == test: "
                  << (copyP == *passengers[0] ? "true" : "false") << "\n";
    }
    if (!flights.empty()) {
        Flight copyF = *flights[0];
        std::cout << "Flight == test: "
                  << (copyF == *flights[0] ? "true" : "false") << "\n";
    }

    // === Phase 2 Tests ===
    std::cout << "\n=== Phase 2 Function Tests ===\n";

    if (!passengers.empty() && !flights.empty()) {
        Passenger* p = passengers[0];
        Flight* f = flights[0];

        std::cout << "\nBooking passenger onto flight...\n";
        f->addPassenger(p);
        p->display();
        f->display();

        std::cout << "\nRemoving passenger from flight...\n";
        f->removePassenger(p);
        p->display();
        f->display();

        std::cout << "\nRe-booking passenger and testing cancelFlight...\n";
        f->addPassenger(p);
        f->cancelFlight();
        f->display();
        p->display();
    }

   std::cout << "\n phase 2 data type C \n";

    std::cout << "\nEmployee adding new flight (static addFlight)...\n";
    Employee::addFlight(flights, "TestAirport", 999, "12:00", "Friday", 100);

    auto it = Employee::findFlight(flights, 999);
    if (it != flights.end()) {
        std::cout << "Employee found flight 999.\n";

        if (!passengers.empty()) {
            Passenger* p = passengers[0];
            Flight* newF = *it;
            std::cout << "\nBooking passenger on new flight 999 before cancel...\n";
            newF->addPassenger(p);
            newF->display();
            p->display();
        }

        std::cout << "\nEmployee canceling flight 999...\n";
        Employee::cancelFlight(flights, 999);
    } else {
        std::cout << "Could not find flight 999.\n";
    }

    clear(passengers);
    clear(flights);

    std::cout << "\nAll tests completed.\n";
    return 0;
}
