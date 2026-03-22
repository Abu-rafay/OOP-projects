#include "List.h"
#include <iostream>

List::List(): head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    Node *n = head;
    while(n != nullptr) {
        Node *backup = n;
        n = n->next;
        delete backup;
        size--;
    }
    size = 0;
}

Iterator List::begin() { return Iterator(head); }
Iterator List::end() { return Iterator(nullptr); }
bool List::empty() { return head == nullptr; }
int& List::front() { return head->data; }

void List::push_front(const int &d) {
    Node *n = new Node(d);
    n->next = head;
    head = n;
    if(tail == nullptr) tail = n;
    size++;
}

void List::push_back(const int &d) {
    if(empty()) { push_front(d); return; }
    Node *n = new Node(d);
    tail->next = n;
    tail = n;
    size++;
}

void List::pop_front() {
    if(empty()) return;
    Node *n = head;
    head = head->next;
    delete n;
    size--;
    if(head == nullptr) tail = nullptr;
}

Iterator List::insertAfter(Iterator it, const int &d) {
    if(empty() || it.current == nullptr) return it;
    Node *n = new Node(d);
    n->next = it.current->next;
    it.current->next = n;
    if(n->next == nullptr) tail = n;
    size++;
    return Iterator(n);
}

Iterator List::eraseAfter(Iterator it) {
    if(empty() || it.current == nullptr || it.current->next == nullptr) return it;
    Node *n = it.current->next;
    it.current->next = n->next;
    if(n->next == nullptr) tail = it.current;
    delete n;
    size--;
    return Iterator(it.current->next);
}

void List::print() {
    Iterator itr = begin();
    while(itr.hasNext()) {
        std::cout << itr.getData() << " ";
        itr.next();
    }
    std::cout << "\n";
}

void List::duplicate(List &dest) {
    Iterator itr = begin();
    while(itr.hasNext()) {
        dest.push_back(itr.getData());
        itr.next();
    }
}

Iterator List::find(int d) {
    Iterator itr = begin();
    while(itr.hasNext()) {
        if(itr.getData() == d) return itr;
        itr.next();
    }
    return Iterator(nullptr);
}

int List::getSize() const {
    return size;
}

void List::clear() {
    Node* n = head;
    while (n != nullptr) {
        Node* backup = n;
        n = n->next;
        delete backup;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;  
}

