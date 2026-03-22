#include <iostream>
#include "List.h"
#include "Iterator.h"

//Shafin Awal

int main() {
    List list;

    std::cout << "PUSH FRONT/BACK\n";
    list.push_front(200);
    list.push_front(100);
    list.push_back(400);
    list.push_back(600);
    list.push_back(800);
    list.print();

    std::cout << "\nPOP FRONT\n";
    list.pop_front();
    list.print();

    std::cout << "\nFRONT\n";
    std::cout << list.front() << "\n";
    list.print();

    Iterator it = list.begin();

    std::cout << "\nFIND/INSERT AFTER\n";
    it = list.find(200);
    std::cout << "Insert 300 after " << it.getData() << "\n";
    it = list.insertAfter(it, 300);
    std::cout << "Insert will return iterator to: " << it.getData() << "\n";
    list.print();

    it = list.find(800);
    std::cout << "Insert 900 after " << it.getData() << "\n";
    it = list.insertAfter(it, 900);
    list.print();

    it = list.find(300);
    it = list.eraseAfter(it);
    list.print();

    it = list.find(800);
    it = list.eraseAfter(it);
    list.print();

    List list_copy;
    list.duplicate(list_copy);
    list.print();
    list_copy.print();

    return 0;
}
