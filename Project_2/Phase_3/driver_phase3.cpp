//Sukhjot; edited: Sabina
#include <iostream>
#include <fstream>
#include <sstream>
#include "Iterator.h"
#include "Node.h"
#include "List.h"
#include "Employee.h"

void read(List &list) {                 // Sukhjot
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

    std::cout << "\nTesting push_back:\n";
    emptyList.push_back(Employee("CEO", 150000));
    emptyList.push_back(Employee("CFO", 170000));
    emptyList.print();

    std::cout << "\nTesting push_front:\n";
    emptyList.push_front(Employee("Founder", 250000));
    emptyList.print();
    std::cout << "Empty: " << (emptyList.empty()) << "\n";

    std::cout << "\nTesting begin:\n";
    it = emptyList.begin();
    it.getData().print();

     // Phase_3 Testing 

    std::cout<< "\nTesting getSize(): \n";
    std::cout<< "Size: " << emptyList.getSize() << "\n\n";

    std::cout<< "Testing clear: \n";
    emptyList.clear();
    emptyList.print();
    std::cout<< "Size after clear: " << emptyList.getSize() << "\n";

    std::cout << "Empty: " << (emptyList.empty()) << "\n";
    emptyList.print();
    
    
    std::cout << "\nTesting merge:\n";

    Employee s1("Manager", 100000);
    Employee s2("Engineer", 90000);
    Employee s3("Developer", 95000);
    Employee s4("Analyst", 70000);
    
    List l1, l2, mergedList;
    
    l1.push_back(s1);
    l1.push_back(s2);
    l2.push_back(s3);
    l2.push_back(s4);
    
    std::cout << "List 1:\n";
    l1.print();
    std::cout << "List 2:\n";
    l2.print();
    
    std::cout << "Merged List:\n";
    List::merge(l1, l2, mergedList, true);
    mergedList.print();
    
    std::cout << "\nTesting mergeSort (small to large):\n";
    List::mergeSort(mergedList, true);
    mergedList.print();
    
    std::cout << "\nTesting mergeSort (large to small):\n";
    List::mergeSort(mergedList, false);
    mergedList.print();
    
    std::cout << "\nTesting reverse:\n";
    List::reverse(mergedList);
    mergedList.print();
    

    std::cout<< std::endl;

    return 0;
}