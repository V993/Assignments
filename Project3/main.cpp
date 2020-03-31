/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    test source
*/

#include "DoublyLinkedList.hpp"
#include <iostream>

using namespace std;

int main() {
    DoublyLinkedList<int> test;

    test.add(20);
    test.add(30);
    test.add(40);
    test.add(50);
    test.add(60);

    cout << test.isEmpty() << endl;
    test.display();

    // test.displayBackwards();

}