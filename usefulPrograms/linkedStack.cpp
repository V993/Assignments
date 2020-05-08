/*  *********************************************************
    A stack implementation for use in whatever project may need it
    Possibly irrelevant considering the use of vectors, but a 
    fun excersise nonetheless.

    Includes Link-Based Implementation for stack.

    Author: Leonardo Matone
    Purpose: To establish a stack implementation
    Date: 04.28.20
    Title: linkedStack.hpp
    *********************************************************  */

#include "linkedStack.hpp"

/************************************************************/
/**              Link-Based Implementation:                 */

/**              Note: requires node files                  */

template<class T>
LinkedStack<T>::LinkedStack() : topPtr(nullptr) { } // end default constructor

template<class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& aStack) 
{
    // node to cycle through each node in the origin stack
    Node<T>* originPtr = aStack.topPtr;

    if (originPtr == nullptr) 
        topPtr = nullptr;
    else {
        // copy first node in origin chain to new chain
        topPtr = new Node<ItemType>();
        topPtr->setItem(originPtr->getItem());

        // establish new pointer to point to the top of new our new chain
        Node<T>* newChainPtr = topPtr;

        // increment to next node in original chain
        originPtr = originPtr->getNext();

        while (originPtr != nullptr) {
            // get item from the original chain
            T nextItem = originPtr->getItem();
            // create a new node to contain the item
            Node<T>* newNode = new Node<T>(nextItem);
            // link this new node to our new chain
            newChainPtr->setNext(newNode);
            // increment newChainPtr to the next node
            newChainPtr = newChainPtr->getNext();
            // incremenent the original chain to the next node
            originPtr = originPtr->getNext();
        } // end while
        newChainPtr->setNext(nullptr); // as this is our new end node.
    } // end if
} // end copy. 

template<class T>
LinkedStack<T>::~LinkedStack()
{
    while (!isEmpty) {
        pop();
    }
} //end destructor

template<class T>
bool LinkedStack<T>::push(const T& newItem)
{
    Node<T>* newNodePtr = new Node<T>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
} // end push

template<class T>
bool LinkedStack<T>::pop() 
{
    bool result = false;
    is (!isEmpty())
    {
        Node<T>* nodeToDelete = topPtr;
        topPtr = topPtr->getNext();

        nodeToDelete->setNext(nullptr);
        delete nodeToDelete;
        nodeToDelete = nullptr;

        result = true;
    }
    return result;
} // end pop

template<class T>
bool LinkedStack<T>::peek() const
{
    return topPtr->getItem();
} // end peek

template<class T>
bool LinkedStack<T>::isEmpty() const
{
    return topPtr == nullptr;
} // end isEmpty

template<class T>
