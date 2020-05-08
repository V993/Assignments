/*  *********************************************************
    A stack interface for use in whatever project may need it
    Possibly irrelevant considering the use of vectors, but a 
    fun excersise nonetheless.

    Includes Link-Based interface for stack.

    Author: Leonardo Matone
    Purpose: To establish a stack interface
    Date: 04.28.20
    Title: linkedStack.hpp
    *********************************************************  */       */

#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include "stack.hpp"
#include "Node.hpp"

template<class T>
class LinkedStack : public Stack<T>
{
    private:
        Node<T>* topPtr; // Pointer to first node in the chain. (TOP)

    private:
        LinkedStack();
        LinkedStack(const LinkedStack<T>& aStack);
        virtual ~LinkedStack();

        bool isEmpty() const;
        bool push(const T& aItem);
        bool pop();
        T peek() const;
}; // end LinkedStack

#include "linkedStack.cpp"
#endif 