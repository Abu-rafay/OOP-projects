#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
private:
    std::string title;
    int salary;
public:
    Employee();
    Employee(const std::string &t, int s);
    std::string getTitle() const;
    int getSalary() const;
    void setTitle(const std::string &t);
    void setSalary(int s);
    void print() const;

};

bool Equivalent(const Employee &e1, const Employee &e2);
bool Compare(const Employee &e1, const Employee &e2, bool comparator);

#endif