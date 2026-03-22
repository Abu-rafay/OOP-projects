#include "Person.h"

Person::Person(): name("noname"), age(0) {}
Person::Person(std::string &n, int a): name(n), age(a) {}
std::string Person::getName() const{
    return name;
}

int Person::getAge() const{
    return age;
}
void Person::setName(std::string &n){
    name = n;
}
void Person::setAge(int a){
    age = a;
}
void Person::print() const {
    std::cout << "Name: " << name << ", Age: $"<< age <<"\n";
}
bool Person::Equivalent(Person &p1, Person &p2) {
    return p1.name == p2.name && p1.age == p2.age;
}
bool Person::Compare( Person &p1,  Person &p2, bool comparator) {
    if (comparator == true) { 
        return p1.age <= p2.age;
    } else { 
        return p1.age > p2.age;
    }
}