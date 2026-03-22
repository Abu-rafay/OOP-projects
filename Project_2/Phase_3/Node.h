#ifndef Node_H
#define Node_H

#include <iostream>
#include "Employee.h"

class Node {

private:
    Employee data;                                              
    Node *next; 
      
public:
    Node();                   
    Node(const Employee &d);
    
    friend class List;                       
    friend class Iterator;  
};

#endif