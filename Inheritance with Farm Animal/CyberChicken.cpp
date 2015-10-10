/**
*	@file : CyberChicken.cpp
*	@author : Hung Nguyen
*	@date : 2014.10.02
*	Purpose: Implementation of CyberChicken class
*/
#include "CyberChicken.h"

CyberChicken::CyberChicken()
{
    m_name = "CyberChicken";
    m_sound = "Resistance is futile";
}

int CyberChicken::getCyberEggs() const
{
    return m_eggs;
}

void CyberChicken::setCyberEggs(int eggs)
{
    m_eggs = eggs;
}
