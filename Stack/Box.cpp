/**
*	@file : Box.cpp
*	@author : Hung Nguyen
*	@date : 2014.09.12
*	Purpose: Implementation of Box Class
*/

#include "Box.h"

Box::Box()
{
    this->m_value = 0;
    this->m_previous = nullptr;
}

void Box::setValue(int val)
{
    this->m_value = val;
}

int Box::getValue()
{
    return (this->m_value);
}

void Box::setPrevious(Box* prev)
{
    this->m_previous = prev;
}

Box* Box::getPrevious()
{
    return (this->m_previous);
}

