#include <iostream>
#include "Container.h"
#include "Files.h"
using namespace std;
// Fnu Aburafay(Tests all the functions for Phase_1)
// Shafin Awal(modified)
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
    
    return 0;
}