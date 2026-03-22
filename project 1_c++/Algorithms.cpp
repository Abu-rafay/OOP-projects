#include "Algorithms.h"
#include <iostream>
#include <cassert>
//Shafin Awal 
void rotate(IntArray &data, int n){
    
    int numValues = data.size();

    if(numValues <= 1){
          return;

    }

    n = n % numValues;
    if(n==0){
        return;
    }

    int *temp = new int[numValues];
    int newData;

    for(int i =0; i<numValues; ++i){
        if (n > 0){
            newData = (i+n) % numValues;
        }
        else{
            newData = (i + n + numValues) % numValues;
        }
        temp[newData] = data.at(i);  

    }   
    for(int i =0; i<numValues; ++i){
        data.at(i) = temp[i];
    }

    delete[] temp;
}

//Fnu Aburafay

bool isRotated(IntArray &A, IntArray &B)
{
    if (A.size() != B.size()) {
        return false;
    }

    int size = A.size();
    if (size == 0) return true; 
    int startIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (B.at(i) == A.at(0)) {
            startIndex = i;
            break;
        }
    }
    if (startIndex == -1) {
        return false; 
    }

    for (int i = 0; i < size; ++i) {
        int indexB = (startIndex + i) % size;
        if (A.at(i) != B.at(indexB)) {
            return false; 
        }
    }

    return true;
}


