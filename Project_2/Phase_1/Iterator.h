#ifndef Iterator_H
#define Iterator_H

#include <iostream>
#include "Node.h"

class Iterator {
private:
    Node *current;   
 
public:
    Iterator(Node *n);
    
    void next();
    bool hasNext();
    int& getData();
    
    friend class List;

};

#endif