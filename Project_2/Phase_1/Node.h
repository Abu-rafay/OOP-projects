#ifndef Node_H
#define Node_H

#include <iostream>

class List;
class Iterator;
 
class Node {
 
private:
    int data;                                              
    Node *next; 
       
public:
    Node();                   
    Node(const int &d);
     
    friend class List;                       
    friend class Iterator;  
};

#endif