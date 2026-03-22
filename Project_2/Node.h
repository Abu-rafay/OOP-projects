#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node *next;
public:
    Node();
    Node(const int &d);

    friend class List;
    friend class Iterator;
};



#endif