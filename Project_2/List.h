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
    int& front();
    int getSize() const;

    void push_front(const int &d);
    void push_back(const int &d);
    void pop_front();

    Iterator insertAfter(Iterator it, const int &d);
    Iterator eraseAfter(Iterator it);

    void clear();

    void print();
    void duplicate(List &dest);
    Iterator find(int d);
};



#endif
