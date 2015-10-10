/**
*	@file : BoxOfAnything.h
*	@author : Hung Nguyen
*	@date : 2014.09.25
*	Purpose: Header file of BoxOfAnything class
*/

#ifndef BOX_OF_ANYTHING_H
#define BOX_OF_ANYTHING_H

template<typename T>
class BoxOfAnything
{
    public:
	/**
    *  @pre None
    *  @post Creates and initializes a BoxOfAnything instance
    *  @return Initialzed BoxOfAnything with m_previous set to nullptr and m_value set to the passed in value 
    */
    BoxOfAnything(T value);

	/**
	*  @pre none
	*  @post none
	*  @return the value of m_previous
	*/
    BoxOfAnything<T>* getPrevious();

	/**
	*  @pre none
	*  @post none
	*  @return the value of m_value
	*/
    T getValue();

	/**
	*  @pre none
	*  @post Creates and initializes a BoxOfAnything instance
	*  @return Initialzed BoxOfAnything with m_value set to value
	*/
    void setValue(T value);

	/**
	*  @pre none
	*  @post Creates and initializes a BoxOfAnything instance
	*  @return Initialzed Box with m_previous initialzed to next
	*/
    void setPrevious(BoxOfAnything<T>* next);

    private:
    BoxOfAnything<T>* m_previous;
    T m_value;
};

#include "BoxOfAnything.hpp"
#endif
