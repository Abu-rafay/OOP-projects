#include "Container.h"
// Fnu Aburafay, Shafin Awal, Joel Adjie

//Fnu Aburafay (phase 1)

IntArray::IntArray(): maxValues(5), numValues(0), data(new int[maxValues]{})            
{}

IntArray::IntArray(int maxSize): maxValues(maxSize), numValues(0), data(new int[maxValues]{})
{}

IntArray::~IntArray()
{
    delete [] data;
}

bool IntArray::empty()
{
    if (numValues == 0) {
        return true;
    } else {
        return false;
    }
}

int IntArray::size()
{
    return numValues;
}

int IntArray::maxSize()
{
    return maxValues;
}

void IntArray::reserve(int n) 

{   
    assert(n >= 0);
    if(n <= maxValues){
        return;
    }
    else{
        assert(n > maxValues);
        int *newData = new int[n]{};
        for(int i = 0; i < numValues; ++i){
        newData[i] = data[i];
        }
        delete [] data;
        data = newData;
        maxValues = n;
        }
}

void IntArray::clear()
{
    delete[] data;
    data = new int[5]{};
    maxValues = 5;
    numValues = 0;
}

void IntArray::push_back(int value) 
{
    assert(numValues >= 0);
    if (numValues == maxValues) {
        reserve(maxValues * 2);
    }
    data[numValues] = value;
    numValues++;
}

void IntArray::print()
{
    for(int i = 0; i < numValues; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// Fnu Aburafay (Phase 2 at, resize)

int& IntArray::at(int index){                                
    assert(index >= 0 && index < numValues);
    return data[index];
}

void IntArray::resize(int n) {                               
    if (n == numValues) { 
        return; 
    }
    if (n > numValues) {  
        if (n > maxValues) {  
            reserve(maxValues * 2);  
        }
        for (int i = numValues; i < n; ++i) {  
            data[i] = 0;
        }
    } else {  
        for (int i = n; i < numValues; ++i) {  
            data[i] = 0;  
        }
    }
    numValues = n;  
}

//Shafin Awal (Phase 2: pop_back, insert, modified erase)

void IntArray::pop_back() {
    assert(numValues > 0 );
        numValues--;
}


void IntArray::insert(int index, int value) {
assert(index >= 0 && index <= maxValues); 
    if(numValues == maxValues){
        reserve (maxValues * 2);
    }
    if(numValues < maxValues && index >=0 && index <= numValues){
        for(int i = numValues-1; i>=index; --i){
            data[i+1]= data[i];        
        }
        data[index]= value;
        numValues++;
    }


}

// Joel Adjie  // Shafin Awal(modified)

void IntArray::erase(int index) {
    assert(index >= 0 && index < numValues);
    for (int i = index + 1 ; i < numValues; ++i) {
        data[i-1]= data[i];
    }
    --numValues;
}

