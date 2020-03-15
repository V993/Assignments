/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    DoublyLinkedList header, establishes the classs DoublyLinkedList
*/

#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

#include "DoubleNode.hpp"

template<class T>
class DoublyLinkedList {
    DoubleNode();
    DoubleNode(DoubleNode<T> aBag);
    bool insert(const int& position, T item); // inserts item at index position in list
    bool remove(const int& posiiton); // remove node at index position
    DoubleNode<T> getAtPos(const int& position) const; // returns the node at position
    bool isEmpty() const; // returns whether the list is empty
    void clear(); // clears the list
    void display(); const; // prints the contents of the list in order
    void displayBackwards() const; // prints the contents of the list in reverse order
    DoublyLinkedList<T> interleave(const DoublyLinkedList<T>& aList) // alters the calling list
                            // to be  the interleaved list of the original and paremeter lists.
};

#include "DoublyLinkedList.cpp"
#endif
/*
1. Default Constructor
2. Copy Constructor
3. bool insert(const int& position, ItemType item), which is intended to insert item at index
position in your list
Note: Let the list be 1 indexed unlike arrays, which are 0 indexed.
4. bool remove(const int& position), which is intended to remove the node at index position
5. DoubleNode<itemType> getAtPos(const int& position) const, which returns the node at
position
6. bool isEmpty() const, which returns whether the list is empty
7. void clear(), which clears the list
8. void display() const, which prints the contents of the list in order
9. void displayBackwards() const, which prints the contents of the list backwards.
10. DoublyLinkedList<itemType> interleave(const DoublyLinkedList<itemType>& a list), which
alters the calling list to be the interleaved list of the original and parameter lists
*/