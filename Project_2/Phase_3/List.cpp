#include "List.h"

List::List(): head(nullptr), tail(nullptr), size(0) {}    

List::~List()                                   
{
    Node *n = head;                        
    Node *backup = nullptr;
    while(n != nullptr) {                  
        backup = n;                         
        n = n->next;                        
        delete backup;                     
    }
    size = 0;
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
    size++; 
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
    size++;                              
}

void List::pop_front()                      
{
    if( empty() ) {                         
        return; 
    }

    Node *n = head;                       
    head = head->next;                
    delete n;
    size--;                                   

    if(head == nullptr) {                  
        tail = nullptr; 
    }   
}

void List::clear(){       //Daniel
    Node* n = head;
    Node* backup = nullptr;

    while (n != nullptr) {
        backup = n;
        n = n ->next;
        delete backup;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
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
    size++;

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
    size--;                                  

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

//Sukhjot
int List::getSize() const{
    return size;
}

// Sabina

void List::merge(List &s1, List &s2, List &list, bool comparator) { 
    Iterator it1 = s1.begin(); 
    Iterator it2 = s2.begin(); 

    while(it1.hasNext() && it2.hasNext()) { 
        if(Compare(it1.getData(), it2.getData(), comparator)) { 
            list.push_back(it1.getData()); 
            it1.next(); 
        } else { 
            list.push_back(it2.getData()); 
            it2.next();
        }
    }

    while(it1.hasNext()) { 
        list.push_back(it1.getData()); 
        it1.next();
    }

    while(it2.hasNext()) { 
        list.push_back(it2.getData()); 
        it2.next(); 
    }
}

void List::mergeSort(List &list, bool comparator) { 
    if(list.getSize() <= 1) { 
        return;
    }

    List list1; 
    List list2; 

    Iterator it = list.begin(); 

    for(int i = 0; i < (list.getSize() / 2); ++i) { 
        list1.push_back(it.getData()); 
        it.next(); 
    }

    for(int i = (list.getSize() / 2); i < list.getSize(); ++i) { 
        list2.push_back(it.getData()); 
        it.next(); 
    }

    list.clear();

    mergeSort(list1, comparator); 
    mergeSort(list2, comparator); 

    merge(list1, list2, list, comparator); 
}

//Sukhjot

void List::reverse(List &list) {   
    Node *current = list.head;
    Node *prev = nullptr;
    Node *temp = nullptr;

    while (current != nullptr) {
        temp = current->next;     
        current->next = prev;     
        prev = current;           
        current = temp;           
    }

    list.tail = list.head;  
    list.head = prev;       
}
