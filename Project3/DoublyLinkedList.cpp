/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    DoublyLinkedList source, defines member functions of DoublyLinkedList
*/
 
#include "DoublyLinkedList.hpp"
#include <iostream>

//default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : headPtr(nullptr), tailPtr(nullptr), itemCount(0) {}

//parameterized constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& aBag) {
    itemCount = aBag.itemCount;
    DoubleNode<T>* origChainPtr = aBag.headPtr;

    if (origChainPtr = nullptr) {
        headPtr = nullptr;
    }
    else {
        // copying the first node 
        headPtr = new DoubleNode<T>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        DoubleNode<T>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

        // cycling through remaining nodes to copy  
        while (origChainPtr != nullptr) {
            // get next item from original chain
            T nextItem = origChainPtr->getItem();

            // create new doubleNode containing the next item
            DoubleNode<T>* newDoubleNodePtr = new DoubleNode<T>(nextItem);

            // Link new node to the end of the new chain
            newChainPtr->setNext(newDoubleNodePtr);
            newDoubleNodePtr-setPrevious(newChainPtr);

            // advance pointer to the last node
            newChainPtr = newChainPtr->getNext();

            //advance original chain ptr
            origChainPtr = origChainPtr->getNext();
        }//end while

        newChainPtr->setNext(nullptr);
        
    } // end if
} // end copy

//add method, theoretically works!
template<class T>
bool DoublyLinkedList<T>::add(const T& anItem) {
    DoubleNode<T>* nextNodePtr = new DoubleNode<T>();
    
    if (headPtr == nullptr) {
        std::cout << "There's nothing in this list rn" << std::endl;
    }

    nextNodePtr->setItem(anItem); //set new item
    nextNodePtr->setNext(headPtr); //new node points next to chain
    nextNodePtr->setPrevious(nullptr); //new node points to null in the previous direction
    headPtr = nextNodePtr; //linking new node to chain
    itemCount++;

    return true;
}

template<class T>
bool DoublyLinkedList<T>::insert(const int& position, T item) {

}

//empty test method
template<class T>
bool DoublyLinkedList<T>::isEmpty() const {
    return itemCount == 0;
}

//clear method
template<class T>
void DoublyLinkedList<T>::clear() {
    DoubleNode<T>* nodeToDeletePtr = headPtr;

    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }
    itemCount = 0;
}

//display method
template<class T>
void DoublyLinkedList<T>::display() const {
    DoubleNode<T>* courrierNode = new DoubleNode<T>();
    courrierNode->setNext(headPtr);
    courrierNode = courrierNode->getNext();
    for (int i = 0; i < itemCount; i++) {
        std::cout << courrierNode->getItem() <<  " ";
        courrierNode = courrierNode->getNext();
    }
    std::cout << std::endl;
}

template<class T>
void DoublyLinkedList<T>::displayBackwards() const {
    
}
 