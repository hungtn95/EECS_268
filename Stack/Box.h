/**
*	@file : Box.h
*	@author : Hung Nguyen
*	@date : 2014.09.12
*	Purpose: Header file of Box class
*/

#ifndef BOX_H
#define BOX_H

class Box
{
    public:
    /**
    *  @pre None
    *  @post Creates and initializes a Box instance
    *  @return Initialzed Box with m_value set to zero and m_previous set to nullptr
    */
    Box();

    /**
    *  @pre none
    *  @post Creates and initializes a Box instance
    *  @return Initialzed Box with m_value initialzed to val
    */
    void setValue(int val);

    /**
    *  @pre none
    *  @post none
    *  @return the value of m_value
    */
    int getValue();

    /**
    *  @pre none
    *  @post Creates and initializes a Box instance
    *  @return Initialzed Box with m_previous initialzed to prev
    */
    void setPrevious(Box* prev);

    /**
    *  @pre none
    *  @post none
    *  @return the value of m_previous
    */
    Box* getPrevious();

    private:
    int m_value;
    Box* m_previous;
};

#endif // BOX_H
