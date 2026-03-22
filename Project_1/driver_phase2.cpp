#include <iostream>
#include "Container.h"
#include "Files.h"
using namespace std;
// Shafin Awal
// Fnu Aburafay()
int main() {

    std::cout << std::endl;
    std::cout << "creating default IntArray;\n";
    IntArray arr1;
    std::cout << "size: " << arr1.size() << ", Max size: " << arr1.maxSize() << "\n";
    std::cout << "checking if it is empty(1 means empty and 0 means not empty): " << arr1.empty() << "\n\n";

    std::cout << "creating IntArray with max size 10;\n";
    IntArray arr2(10);
    std::cout << "size: " << arr2.size() << ", Max size: " << arr2.maxSize() << "\n";
    std::cout << "checking if it is empty: " << arr2.empty() << "\n\n";//
    std::cout << "adding elements using push back;\n";
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(4);
    arr2.push_back(5);
    arr2.push_back(6);
    arr2.push_back(7);
    std::cout << "array after push back: ";
    std::cout << "Size: " << arr2.size() << ", Max size: " << arr2.maxSize() << "\n";
    std::cout << "checking if it is empty: " << arr2.empty() << "\n\n";//
    arr2.print();
    arr2.push_back(8);
    arr2.push_back(9);
    arr2.push_back(100);  
    arr2.push_back(110);
    std::cout << "Size after more push back values: " << arr2.size() << ", Max size after push back: " << arr2.maxSize() << "\n";
    std::cout << "Size: " << arr2.size() << ", Max size: " << arr2.maxSize() << "\n";
    std::cout << "checking if it is empty: " << arr2.empty() << "\n\n";//
    arr2.print();
    std::cout << "testing Reserve function: \n";
    arr2.reserve(15);
    std::cout << "array after Reserve function: ";
    std::cout << "size: " << arr2.size() << ", Max size: " << arr2.maxSize() << "\n\n";

    std::cout << "Reading data from data.csv file:\n";
    read(arr1);
    std::cout << "Array after reading data from data.csv file: ";
    arr1.print();
    std::cout << "Size: " << arr1.size() << ", Max size: " << arr1.maxSize() << "\n\n";

    std::cout << "testing clear function: \n";
    std::cout << "array before using clear function: ";
    arr2.print();
    arr2.clear();
    std::cout << "array after clear function: ";
    arr2.print();
    std::cout << "Size after clear function: " << arr2.size() << ", Max size after clear function: " << arr2.maxSize() << "\n";
    std::cout << "checking if it is empty: " << arr2.empty() << "\n\n";

    //Shafin Awal (Tests all the functions of Driver_Phase 2)
    std::cout << "\n--- Testing at() ---\n";
    IntArray arr3;
    arr3.push_back(10);
    arr3.push_back(20);
    arr3.push_back(30);

    // Valid accesses
    std::cout << "arr1.at(0): " << arr3.at(0) << std::endl; 
    std::cout << "arr1.at(2): " << arr3.at(2) << std::endl; 

    arr3.at(1) = 99;
    arr3.print();

    std::cout << "\n--- Testing resize() ---\n";
    IntArray arr4;
    arr4.push_back(1);
    arr4.push_back(2);
    arr4.push_back(3);
    arr4.print();

    arr4.resize(5);
    arr4.print(); 

    arr4.resize(2);
    arr4.print(); 


    arr4.resize(20);
    std::cout << "New size: " << arr2.size() << "  Max: " << arr2.maxSize() << std::endl;

    std::cout << "\n--- Testing pop_back() ---\n";
    IntArray arr5;
    arr5.push_back(10);
    arr5.push_back(20);
    arr5.push_back(30);

    arr5.print(); 
    arr5.pop_back(); 
    arr5.print();
    arr5.pop_back(); 
    arr5.print(); 
    arr5.pop_back(); 
    arr5.print(); 

    
    std::cout << "\n--- Testing insert() ---\n";
    IntArray arr6;
    arr6.push_back(1);
    arr6.push_back(2);
    arr6.push_back(3);
    arr6.print(); 

    arr6.insert(1, 99);
    arr6.print(); 


    arr6.insert(0, 50);
    arr6.print(); 


    arr6.insert(arr6.size(), 77);
    arr6.print(); 


    std::cout << "\n--- Testing erase() ---\n";
    IntArray arr7;
    arr7.push_back(10);
    arr7.push_back(20);
    arr7.push_back(30);
    arr7.push_back(40);
    arr7.print(); 


    arr7.erase(1); 
    arr7.print(); 


    arr7.erase(0);
    arr7.print(); 


    arr7.erase(arr7.size() - 1);
    arr7.print(); 

    return 0;
}
