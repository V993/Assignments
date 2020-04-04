/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    test source
*/

#include "DoublyLinkedList.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << endl;

    DoublyLinkedList<int> test;

    test.add(4);
    test.add(2);
    test.add(8);
    test.add(5);
    test.add(8);

    cout <<         "List1            : ";
    test.display();
    cout << endl << "List1 backwards  : ";
    test.displayBackwards();
    cout << endl;

    // DoubleNode<int>* testPosition = test.getAtPos(2);

    // int testPositionItem = testPosition->getItem();

    // cout << "Item 5 should be 5, and is: " << testPositionItem << endl;

    DoublyLinkedList<int> test2;

    test2.add(5);
    test2.add(1);
    test2.add(8);
    test2.add(4);
    test2.add(5);
    test2.add(9);

    cout <<         "List2            : ";
    test2.display();
    cout << endl << "List2 backwards  : ";
    test2.displayBackwards();
    cout << endl;

    DoublyLinkedList<int> interleaved = test.interleave(test2);

    cout <<         "Interleaved Lists: SHOULD BE  : 4 5 2 1 8 8 5 4 8 5 9" << endl;
    cout <<         "                   INTERLEAVE : ";
    interleaved.displayBackwards();
    cout << endl;

/*
Output:

L1 = {4, 2, 8, 5, 8}
L2 = {5, 1, 8, 4, 5, 9}.

Interleaved should output: 
{4, 5, 2, 1, 8, 8, 5, 4, 8, 5, 9}

BUT it outputs this:
{5, 1, 4, 8, 2, 4, 8, 5, 5, 9, 8}

*/
}