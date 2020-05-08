/*  *********************************************************
    A stack implementation for use in whatever project may 
    need it. Possibly irrelevant considering the use of 
    vectors, but a fun excersise nonetheless.

    Includes Array-Based implementation for stack

    Author: Leonardo Matone
    Purpose: To establish a stack implementation
    Date: 04.28.20
    Title: stack.cpp
    *********************************************************  */

#include "stack.hpp"

/************************************************************/
/**             Array-Based Implementation:                 */

template<class T>
Stack<T>::Stack() : top(-1) {} // end default constructor

/** Note: copy constructor and destructor are supplied by
 * the compiler. Thus, they are not included here. */

template<class T>
bool Stack<T>::isEmpty() const 
{
    return top < 0;
} // end isEmpty

template<class T> 
bool Stack<T>::push(const T& newEntry) 
{
    bool result = false;
    if (top < DEFAULT_CAPACITY - 1) 
    {
        top++
        items[top] = newEntry;
        result = true;
    }
    return result;
} // end push

template<class T>
bool Stack<T>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    }
    return result;
} // end pop

template<class T>
T Stack<T>::peek() const 
{
    return items[top];
} // end peek