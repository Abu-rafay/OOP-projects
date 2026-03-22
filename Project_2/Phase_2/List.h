#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Iterator.h"

class List {  
private:                                             
    Node *head;               
    Node *tail;   
    
public:
    List(); 
    ~List(); 

    Iterator begin();
    Iterator end();
    
    bool empty();    
    Employee& front();    
    void push_front(const Employee &d);  
    void push_back(const Employee &d);   
    void pop_front();

    Iterator insertAfter(Iterator it, const Employee &d);
    Iterator eraseAfter(Iterator it);
        
    void print();
    void duplicate(List &b);

    Iterator find(const Employee &d);
    
};   

#endif