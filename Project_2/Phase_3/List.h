#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Iterator.h"

class List {  
private:                                             
    Node *head;               
    Node *tail;
    int size;   
    
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
    void clear();
    Iterator insertAfter(Iterator it, const Employee &d);
    Iterator eraseAfter(Iterator it);
        
    void print();
    void duplicate(List &b);

    Iterator find(const Employee &d);
    int getSize() const;               //Sukhjot
    
    static void merge(List &s1, List &s2, List &list, bool comparator);
    static void mergeSort(List &list, bool comparator);
    static void reverse(List &list);  
    
};   

#endif