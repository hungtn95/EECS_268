/**
*	@file : Chicken.cpp
*	@author : Hung Nguyen
*	@date : 2014.10.02
*	Purpose: Implementation of Chicken class
*/
#include "Chicken.h"

Chicken::Chicken()
{
    m_name = "Chicken";
    m_sound = "Cluck";
}

int Chicken::getEggs() const
{
    return m_eggs;
}

void Chicken::setEggs(int eggs)
{
    m_eggs = eggs;
}
