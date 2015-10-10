/**
*	@file : CyberChicken.h
*	@author : Hung Nguyen
*	@date : 2014.10.02
*	Purpose: Header file of CyberChicken class
*/
#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H
#include "Chicken.h"

class CyberChicken : public Chicken
{
public:
	/**
	*  @pre None
	*  @post Creates and initializes a cow
	*  @return Initialzed class object with name set to "Cyber Chicken" and sound set to "Resistance is futile"
	*/
    CyberChicken();

	/**
	*  @pre None
	*  @post None
	*  @return The value of the inherited member variable, m_eggs
	*/
    int getCyberEggs() const;

	/**
	*  @pre None
	*  @post Sets the value of the inherited member variable, m_eggs
	*  @return None
	*/
    void setCyberEggs(int eggs);
};

#endif // CYBERCHICKEN_H
