/**
*	@file : StackOfBoxes.h
*	@author : Hung Nguyen
*	@date : 2014.09.12
*	Purpose: Header file of StackOfBoxes class
*/

#ifndef STACKOFBOXES_H
#define STACKOFBOXES_H
#include "Box.h"

class StackOfBoxes
{
    public:
    /**
    *  @pre None
    *  @post Creates and initializes a StackOfBoxes instance
    *  @return Initialzed stack with m_top set to nullptr and m_size set to 0
    */
    StackOfBoxes();

    /**
    *  @pre None
    *  @post Deallocates all boxes in the stack
    *  @return Empty stack with all boxes deallocated
    */
    ~StackOfBoxes();

    /**
    *  @pre None
    *  @post Indicates if the stack is empty
    *  @return true if m_size is zero, false otherwise
    */
    bool isEmpty();

    /**
    *  @pre None
    *  @post None
    *  @return the current size of the stack (the value of m_size)
    */
    int size();

    /**
    *  @pre None
    *  @post Creates a new box, puts the value parameter in that box, adjust size and top pointer
    *  @return None
    */
    void push(int val);

    /**
    *  @pre None
    *  @post Deletes the top, correctly adjust size and top pointer.
    *  @return the value from the top box (m_top)
    */
    int pop();

    private:
    Box* m_top;
    int m_size;
};

#endif // STACKOFBOXES_H
