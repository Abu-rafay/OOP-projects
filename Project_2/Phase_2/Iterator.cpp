#include "Iterator.h"

Iterator::Iterator(Node *n): current(n) {}                

void Iterator::next() {                                      
    current = current->next;
}

bool Iterator::hasNext() {                                    
    if(current != nullptr) { 
        return true; 
    } else {
        return false;
    }
} 

Employee& Iterator::getData() {                                   
    return current->data;
}
