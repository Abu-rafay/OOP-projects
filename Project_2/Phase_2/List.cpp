#include "List.h"

List::List(): head(nullptr), tail(nullptr) {}    

List::~List()                                   
{
    Node *n = head;                        
    Node *backup = nullptr;
    while(n != nullptr) {                  
        backup = n;                         
        n = n->next;                        
        delete backup;                     
    }
}   

Iterator List::begin() {                          
    return Iterator(head);
}  

Iterator List::end() {                            
    return Iterator(nullptr);
}  

bool List::empty()                          
{
    if(head == nullptr) {                      
        return true;
    } else {
        return false;
    }
}

Employee& List::front() {
    return head->data;
}
   
void List::push_front(const Employee& d)            
{
    Node *n = new Node(d);                                                         
    n->next = head;                             
    head = n;                              

    if(tail == nullptr) { tail = n; } 
}

void List::push_back(const Employee &d)                               
{
    
    if(empty()) {                         
        push_front(d);
        return;
    }
    
    Node *n = new Node(d);                      
    tail->next = n;                                              
    tail = n;                              
}

void List::pop_front()                      
{
    if( empty() ) {                         
        return; 
    }

    Node *n = head;                       
    head = head->next;                
    delete n;                                   

    if(head == nullptr) {                  
        tail = nullptr; 
    }   
}

Iterator List::insertAfter(Iterator it, const Employee& d)
{   
    if( empty() || it.current == nullptr) {  
        return it;                              
    }

    Node *n = new Node(d);                      
    n->next = it.current->next;                 
    it.current->next = n;                       

    if(n->next == nullptr) { tail = n; }   

    return Iterator(n);                         
}

Iterator List::eraseAfter(Iterator it){
    if( empty() || it.current == nullptr || it.current->next == nullptr) { 
        return it;                                          
    }                                              

    Node *n = it.current->next;                 
    it.current->next = n->next;                 

    if( n->next == nullptr ) { tail = it.current; } 

    delete n;                                  

    return Iterator(it.current->next);          
}

void List::print()
{
    Iterator itr = begin();                        
    while( itr.hasNext() ) {                     
        itr.getData().print();      
        itr.next();                             
    }   
    std::cout << "\n";    
}

void List::duplicate(List &b)                          
{
    Iterator itr = begin();                       
    while( itr.hasNext() ) {                      
        b.push_back(itr.getData());             
        itr.next();                             
    }   
}

Iterator List::find(const Employee& d)             
{
    Iterator itr = begin();                      
    while( itr.hasNext() ) {                      
        if(Equivalent (itr.getData(), d )){              
            return itr;                         
        }
        itr.next();                             
    }   
    return Iterator(nullptr);                   
}   
