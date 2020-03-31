/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    DoubleNode implementation.
*/

#include "DoubleNode.hpp"

template<class T>
DoubleNode<T>::DoubleNode() : next(nullptr), previous(nullptr) {}

template<class T>
DoubleNode<T>::DoubleNode(const T& anItem) : item(anItem), next(nullptr), previous(nullptr) {}

template<class T>
DoubleNode<T>::DoubleNode(const T& anItem, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr) 
: item(anItem), next(nextNodePtr), previous(previousNodePtr) {}

template<class T>
void DoubleNode<T>::setItem(const T& anItem) {
    item = anItem;
}

template<class T>
void DoubleNode<T>::setNext(DoubleNode<T>* nextNodePtr) {
    next = nextNodePtr; 
}

template<class T>
void DoubleNode<T>::setPrevious(DoubleNode<T>* previousNodePtr) {
    previous = previousNodePtr;
}

template<class T>
T DoubleNode<T>::getItem() const {
    return item;
}

template<class T>
DoubleNode<T>* DoubleNode<T>::getNext() const {
    return next;
}

template<class T>
DoubleNode<T>* DoubleNode<T>::getPrevious() const {
    return previous;
}

