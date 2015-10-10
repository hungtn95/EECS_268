/**
*	@file : Chicken.h
*	@author : Hung Nguyen
*	@date : 2014.10.02
*	Purpose: Header file of Chicken class
*/
#ifndef CHICKEN_H
#define CHICKEN_H
#include "FarmAnimal.h"

class Chicken : public FarmAnimal
{
public:
	/**
	*  @pre None
	*  @post Creates and initializes a chicken
	*  @return Initialzed class object with name set to "Chicken" and sound set to "Cluck"
	*/
    Chicken();

protected:
	/**
	*  @pre None
	*  @post None
	*  @return the value of m_eggs
	*/
    int getEggs() const;

	/**
	*  @pre None
	*  @post Set the value of m_eggs
	*  @return None
	*/
    void setEggs(int eggs);

    int m_eggs;
};

#endif // CHICKEN_H
