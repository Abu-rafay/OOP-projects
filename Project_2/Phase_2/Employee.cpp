#include "Employee.h"

Employee::Employee(): title("noname"), salary(0) {}
Employee::Employee(const std::string &t, int s): title(t), salary(s) {}
std::string Employee::getTitle() const { 
    return title; 
}
int Employee::getSalary() const { 
    return salary; 
}
void Employee::setTitle(const std::string &t) { 
    title = t; 
}
void Employee::setSalary(int s) { 
    salary = s; 
}
void Employee::print() const { 
    std::cout << "Title: " << title << ", Salary: $" << salary << "\n"; 
}

bool Equivalent(const Employee &e1, const Employee &e2) {
    return e1.getTitle() == e2.getTitle() && e2.getSalary() == e2.getSalary();
}

bool Compare(const Employee &e1, const Employee &e2, bool comparator) {
    if(comparator == true) {
        return e1.getSalary() <= e2.getSalary();
    } else {
        return e1.getSalary() > e2.getSalary();
    }
}
