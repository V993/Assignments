/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    DoublyLinkedList header, establishes the classs DoublyLinkedList
*/

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "DoubleNode.hpp"

template<class T>
class DoublyLinkedList {
    public:
        //done
        DoublyLinkedList(); 
        DoublyLinkedList(const DoublyLinkedList<T>& aBag);
        ~DoublyLinkedList();
        bool add(const T& anItem); //adds item into linkedlist
        bool insert(T item, const int& position); // inserts item at index position in list
        bool remove(const int& posiiton); // remove node at index position
        int getSize() const; //returns the number of nodes in the list
        DoubleNode<T> *getHeadPtr() const; // returns a copy of the headPtr
        DoubleNode<T> *getAtPos(const int& position) const; // returns the node at position
        bool isEmpty() const; // returns whether the list is empty
        void clear(); // clears the list
        void display() const; // prints the contents of the list in order
        void displayBackwards() const; // prints the contents of the list in reverse order
        DoublyLinkedList<T> interleave(const DoublyLinkedList<T>& a_list); // alters the calling list
                                // to be  the interleaved list of the original and paremeter lists.
    private:
        DoubleNode<T>* headPtr; // Pointer to first node
        DoubleNode<T>* tailPtr; // Pointer to last node
        int itemCount;
        DoubleNode<T>* getPointerTo(const T& target) const;
};


#include "DoublyLinkedList.cpp"
#endif
