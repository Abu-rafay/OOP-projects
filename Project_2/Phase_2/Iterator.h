#ifndef Iterator_H
#define Iterator_H

#include "Node.h"

class Iterator {
private:
    Node *current;   
 
public:
    Iterator(Node *n);
    
    void next();
    bool hasNext();
    Employee& getData();
    
    friend class List;

};

#endif