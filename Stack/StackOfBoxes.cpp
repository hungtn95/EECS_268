/**
*	@file : StackOfBoxes.cpp
*	@author : Hung Nguyen
*	@date : 2014.09.12
*	Purpose: Implementation of StackOfBoxes Class
*/

#include "Box.h"
#include "StackOfBoxes.h"

StackOfBoxes::StackOfBoxes()
{
    this->m_top = nullptr;
    this->m_size = 0;
}

StackOfBoxes::~StackOfBoxes()
{
    while (this->m_top != nullptr)
    {
        pop();
    }
}

bool StackOfBoxes::isEmpty()
{
    if (this->m_size == 0)
    {
        return true;
    }
    return false;
}

int StackOfBoxes::size()
{
    return (m_size);
}

void StackOfBoxes::push(int val)
{
    Box* temp = this->m_top;
    m_top = new Box();
    m_top->setValue(val);
    m_top->setPrevious(temp);
    m_size ++;
}

int StackOfBoxes::pop()
{
    if  (this->m_top != nullptr)
    {
        int tempval = m_top->getValue();
        Box* tempPtr = m_top->getPrevious();
        delete m_top;
        m_top = tempPtr;
        m_size --;
        return (tempval);
    }
}
