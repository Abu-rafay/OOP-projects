
#include <iostream>
#include <fstream>
#include <sstream>
#include "Iterator.h"
#include "Node.h"
#include "List.h"
#include "Person.h"

// read integers from csv
void read(List &list) {
    std::ifstream file("data.csv");
    std::string line;

    while (getline(file, line)) {
        std::stringstream parser(line);
        std::string temp;

        std::string name;
        int age;

        getline(parser, name, ',');
        getline(parser, temp, ',');
        age = std::stoi(temp);

        list.push_back(age);   
    }

    file.close();
}

int main() {

    std::cout << "\nTesting Person class:\n";

    std::string n1 = "Alice";
    std::string n2 = "Alice";
    std::string n3 = "Diaz";

    Person p1(n1, 21);
    Person p2(n2, 21);
    Person p3(n3, 27);

    std::cout << "Person 1: ";
    p1.print();
    std::cout << "Person 2: ";
    p2.print();
    std::cout << "Person 3: ";
    p3.print();

    std::cout << "\nTesting Equivalent(p1, p2): "<< p1.Equivalent(p1, p2) << "\n";

    std::cout << "Testing Equivalent(p1, p3): "<< p1.Equivalent(p1, p3) << "\n\n";

    std::cout << "Testing Compare(p1, p3, true): "<< p1.Compare(p1, p3, true) << "\n";

    std::cout << "Testing Compare(p1, p3, false): "<< p1.Compare(p1, p3, false) << "\n\n";

    std::cout << "Testing setters:\n";
    n1 = "Senior Alice";
    p1.setName(n1);
    p1.setAge(25);
    p1.print();

    std::cout << "\np1.getName(): " << p1.getName() << "\n";
    std::cout << "p1.getAge(): " << p1.getAge() << "\n\n";

    //      TESTING INT LIST

    List list;

    std::cout << "Reading from csv file :\n";
    read(list);
    list.print();

    std::cout << "\nTesting front(): ";
    std::cout << list.front() << "\n";

    std::cout << "\nTesting find() and insertAfter():\n";
    Iterator it = list.find(27);  
    std::cout << "Inserting 26 after 27:\n";
    it = list.insertAfter(it, 26);
    list.print();

    std::cout << "\nTesting eraseAfter():\n";
    it = list.find(26);
    it = list.eraseAfter(it);
    list.print();

    std::cout << "\nTesting pop_front():\n";
    list.pop_front();
    list.print();

    std::cout << "\nTesting duplicate():\n";
    List copiedList;
    list.duplicate(copiedList);
    std::cout << "Original:\n";
    list.print();
    std::cout << "Copy:\n";
    copiedList.print();

    std::cout << "\nTesting empty():\n";
    List emptyList;
    std::cout << "Empty: " << emptyList.empty() << "\n";
    emptyList.push_back(99);
    std::cout << emptyList.front() << "\n";

    return 0;
}
