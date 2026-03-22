//Sukhjot
#include <iostream>
#include <fstream>
#include <sstream>
#include "Iterator.h"
#include "Node.h"
#include "List.h"
#include "Employee.h"

void read(List &list) {
    std::ifstream file("data.csv");
    std::string line, temp;

    while (getline(file, line)) {
        std::stringstream parser(line);
        std::string title;
        int salary;

        getline(parser, title, ',');
        getline(parser, temp, ',');
        salary = std::stoi(temp);

        Employee e(title, salary);
        list.push_back(e);
    }

    file.close();
}

int main() {

    std::cout << std::endl;

    std::cout << "Testing Employee class:\n";

    Employee e1("Analyst", 60000);
    Employee e2("Analyst", 60000);
    Employee e3("Director", 130000);

    std::cout << "Employee 1: ";
    e1.print();
    std::cout << "Employee 2: ";
    e2.print();
    std::cout << "Employee 3: ";
    e3.print();
    std::cout << std::endl;

   // Testing Equivalent function
    std::cout << "Testing Equivalent(e1, e2): " << (Equivalent(e1, e2)) << "\n";
    std::cout << "Testing Equivalent(e1, e3): " << (Equivalent(e1, e3)) << "\n";
    std::cout << std::endl;

   // Testing Compare function
    std::cout << "Testing Compare(e1, e3, true): " << (Compare(e1, e3, true)) << "\n";
    std::cout << "Testing Compare(e1, e3, false): " << (Compare(e1, e3, false)) << "\n";
    std::cout << std::endl;

   // Testing Accessor and mutator function
    e1.setTitle("Senior Analyst");
    e1.setSalary(75000);
    std::cout << "After setTitle and setSalary on e1:\n";
    e1.print();
    std::cout << std::endl;

    std::cout << "e1.getTitle(): " << e1.getTitle() << "\n";
    std::cout << "e1.getSalary(): " << e1.getSalary() << "\n";

    std::cout << "\n";
   
    List list;

    std::cout << "Reading from csv file:\n";
    read(list);
    list.print();

    std::cout << "\nTesting front:\n";
    list.front().print();

    std::cout << "\nTesting find() and insert after():\n";
    Iterator it = list.find(Employee("Technician", 60000));
    std::cout << "Inserting between Technician and Developer:\n";
    it = list.insertAfter(it, Employee("Mid Developer", 65000));
    list.print();

    std::cout << "\nTesting Erase after:\n";
    it = list.find(Employee("Mid Developer", 65000));
    it = list.eraseAfter(it);
    list.print();

    std::cout << "\nTesting pop front:\n";
    list.pop_front();
    list.print();

    std::cout << "\nTesting duplicate:\n";
    List copiedList;
    list.duplicate(copiedList);
    std::cout << "Original:\n";
    list.print();
    std::cout << "Copy:\n";
    copiedList.print();

    std::cout << "\nTesting empty:\n";
    List emptyList;
    std::cout << "Empty: " << (emptyList.empty()) << "\n";
    emptyList.push_back(Employee("CEO", 150000));
    emptyList.front().print();
    
    std::cout << std::endl;

    return 0;
}