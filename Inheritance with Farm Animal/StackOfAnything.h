/**
*	@file : StackOfAnything.h
*	@author : Hung Nguyen
*	@date : 2014.09.25
*	Purpose: Header file of StackOfAnything class
*/

#ifndef STACKOFANYTHING_H
#define STACKOFANYTHING_H
#include "BoxOfAnything.h"
#include <stdexcept>

template<typename T>
class StackOfAnything
{
    public:
	/**
    *  @pre None
    *  @post Creates and initializes a stack of type T
    *  @return Initialzed stack with m_top set to nullptr and m_size set to 0
    */
    StackOfAnything();

	/**
	*  @pre None
	*  @post Deallocates all boxes in the stack
	*  @return Empty stack with all boxes deallocated
	*/
    ~StackOfAnything();

	/**
	*  @pre None
	*  @post Indicates if the stack is empty
	*  @return true if m_size is zero, false otherwise
	*/
    bool isEmpty() const;

	/**
	*  @pre None
	*  @post None
	*  @return the current size of the stack (the value of m_size)
	*/
    int size() const;

	/**
	*  @pre None
	*  @post Creates a new box and puts in the value parameter, adjust size and top pointer, being able tho throw an exception
	*  @return None
	*/
    void push(T value);

	/**
	*  @pre None
	*  @post if attempted on an empty stack, throws an exception
	*  @return the value at the top of the stack
	*/
    T peek() const throw(std::runtime_error);

	/**
	*  @pre None
	*  @post Deletes the top, correctly adjust size and top pointer, being able to throws an exception
	*  @return the value from the top node
	*/
    T pop() throw(std::runtime_error);

	/**
	*  @pre None
	*  @post None
	*  @return a pointer to the next box
	*/

    private:
    BoxOfAnything<T>* m_top;
    int m_size;

};

#include "StackOfAnything.hpp"
#endif // STACKOFANYTHING_H
