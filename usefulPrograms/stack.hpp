/*  *********************************************************
    A stack interface for use in whatever project may need it
    Possibly irrelevant considering the use of vectors, but a 
    fun excersise nonetheless.

    Includes Array-Based interface for stack

    Author: Leonardo Matone
    Purpose: To establish a stack interface
    Date: 04.28.20
    Title: stack.hpp
    *********************************************************  */

#ifndef STACK_HPP_
#define STACK_HPP_

template<class T>
class Stack
{
    public:
        Stack(); //default constructor
        /** tests if stack is empty.
         *@return True if the stack is empty, or false if not. **/
        virtual bool isEmpty() const = 0;
        /** Adds a new entry to the top of the stack.
         * @param newEntry, the object of type T to be added to the stack
         * @post If the operation was successful, newEntry is put at the top of the stack.
         * @return True if the addition was successful or false if not. */
        virtual bool push(const T& newEntry) = 0;
        /** Removes the top of this stack.
         * @post If the operation was successful, the top of the stack has been removed.
         * @return True if the removal is successful or false if not. */
        virtual bool pop() = 0;
        /** Returns a copy of the top of the stack.
         * @pre The stack is not empty.
         * @post A copy of the top of the stack has been returned, and the stack is unchanged.
         * @return A copy of the top of the stack. */
        virtual T peek() const = 0; 
        /** Returns the number of elements in the stack. 
         * @return An integer with the number of elements in the stack. */
        int size() const; // returns the number of elements in the stack
        /** Destroys this stack and frees assigned memory. */
        virtual ~Stack() { } ;
    private:

}; //end Stack

#include "stack.cpp"
#endif // STACK_HPP_