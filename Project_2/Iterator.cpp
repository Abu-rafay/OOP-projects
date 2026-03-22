#include "Iterator.h"

Iterator::Iterator(Node *n): current(n) {}

void Iterator::next() {
    if(current) current = current->next;
}

bool Iterator::hasNext() {
    return current != nullptr;
}

int& Iterator::getData() {
    return current->data;
}
