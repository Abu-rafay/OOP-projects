#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <vector>
#include <string> 
// Shafin Awal 
class Flight;


class Employee {
    public:
        // Shafin Awal // we use static because we are adding a flight to a system and it is not an employee data 
        static void addFlight(std::vector<Flight*>& flights,const std::string &airport,int id,const std::string &time,const std::string &day,int maxSeats);

        //Fnu Aburafay
        // cancelFlight Function:
        static void cancelFlight(std::vector<Flight*>& flights, int flightID);
        
        // Shafin Awal
        static std::vector<Flight*>::iterator findFlight(std::vector<Flight*>& flights, int flightID);   
};

#endif