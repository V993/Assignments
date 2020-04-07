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

    cout << "First item inserted: " << test.insert(4, 1) << endl;
    cout << "Second item inserted: " << test.insert(2, 2) << endl;
    cout << "Third item inserted: " << test.insert(5, 3) << endl;
    cout << "Fourth item inserted: " << test.insert(8, 4) << endl;
    cout << "New Third inserted, indexes shifted: " << test.insert(8, 3) << endl;

        // should be: 4, 2, 5, 8, 5, 8 and it IS

    cout <<         "List1            : ";
    test.display();
    cout << endl << "List1 backwards  : ";
    test.displayBackwards();
    cout << endl;

    // DoubleNode<int>* testPosition = test.getAtPos(2);

    // int testPositionItem = testPosition->getItem();

    // cout << "Item 5 should be 5, and is: " << testPositionItem << endl;

    DoublyLinkedList<int> test2;

    test2.insert(5, 1);
    test2.insert(1, 2);
    test2.insert(8, 3);
    test2.insert(4, 4);
    test2.insert(5, 5);
    test2.insert(9, 6);

    cout <<         "List2            : ";
    test2.display();
    cout << endl << "List2 backwards  : ";
    test2.displayBackwards();
    cout << endl;

    DoublyLinkedList<int> interleaved = test.interleave(test2);

    cout <<         "Interleaved Lists: SHOULD BE  : 4 5 2 1 8 8 5 4 8 5 9" << endl;
    cout <<         "                   INTERLEAVE : ";
    interleaved.display();
    cout << endl;

    cout << "removing: " << endl;
    cout << "removed: " << interleaved.remove(11) << endl;
    interleaved.display();
    
    cout << "removing: " << endl;
    cout << "removed: " << interleaved.remove(10) << endl;
    interleaved.display();
    
    cout << "removing: " << endl;
    cout << "removed: " << interleaved.remove(9) << endl;
    interleaved.display();



/*

Output:

L1 = {4, 2, 8, 5, 8}
L2 = {5, 1, 8, 4, 5, 9}.

Interleaved should output: 
{4, 5, 2, 1, 8, 8, 5, 4, 8, 5, 9}

BUT it outputs this:
{5, 1, 4, 8, 2, 4, 8, 5, 5, 9, 8}

But with the backwards add system, it'll be {8, 9, 5, 5, 8, 4, 2, 8, 4, 1, 5} which gets outputted as:

{5, 1, 4, 8, 2, 4, 8, 5, 5, 9, 8}

This is incorrect, so we need to fix add method. Not sure how.

Display also apparently doesn't work, but I don't know why.

*/
}