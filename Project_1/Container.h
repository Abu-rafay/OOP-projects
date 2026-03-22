#ifndef CONTAINER_H
#define CONTAINER_H
#include<iostream>
#include<cassert>
//Fnu Aburafay
//Shafin Awal 
//Joel  Adjie
class IntArray{
private:
    int maxValues;
    int numValues;
    int *data;

public:
    IntArray();                     // Fnu Aburafay
    IntArray(int maxSize); // Fnu Aburafay
    ~IntArray(); // Fnu Aburafay
    bool empty(); // Fnu Aburafay
    int size(); // Fnu Aburafay
    int maxSize(); // Fnu Aburafay
    void reserve(int n); // Fnu Aburafay
    void clear(); //  Fnu Aburafay
    void push_back(int value); // Fnu Aburafay
    void print(); // Fnu Aburafay
    int& at(int index); // Fnu Aburafay
    void resize(int n); // Fnu Aburafay
    void pop_back();                // Shafin Awal
    void insert(int index, int value); // Shafin Awal
    void erase(int index);          // Joel Adjie // modified by Shafin Awal


};


#endif