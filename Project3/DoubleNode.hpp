/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    DoubleNode header, establishes the DoubleNode class.
*/

#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP

template<class T>
class DoubleNode {
    private:
        T item;
        DoubleNode<T>* next;
        DoubleNode<T>* previous;
    public:
        DoubleNode();
        DoubleNode(const T& anItem);
        DoubleNode(const T& anItem, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr);
        void setItem(const T& anItem);
        void setNext(DoubleNode<T>* nextNodePtr);
        void setPrevious(DoubleNode<T>* previousNodePtr);
        T getItem() const;
        DoubleNode<T>* getNext() const;
        DoubleNode<T>* getPrevious() const;
};

#include "DoubleNode.cpp"

#endif