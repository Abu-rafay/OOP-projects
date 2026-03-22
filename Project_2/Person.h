#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>


class Person {
private:
    std::string name;
    int age;


public:
    Person();
    Person(std::string &n, int a);
    std::string getName() const;
    int getAge() const;
    void setName(std::string &t);
    void setAge(int a);
    void print() const;
    bool Equivalent(Person &p1, Person &p2);
    bool Compare(Person &p1,  Person &p2, bool comparator);
};






#endif