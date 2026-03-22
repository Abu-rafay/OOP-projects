#include "Node.h"

Node::Node(): data(), next(nullptr) {}  
                 
Node::Node(const Employee &d): data(d), next(nullptr) {}