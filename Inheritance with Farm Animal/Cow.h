/**
*	@file : Cow.h
*	@author : Hung Nguyen
*	@date : 2014.10.02
*	Purpose: Header file of Cow class
*/
#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"

class Cow : public FarmAnimal
{
public:
	/**
	*  @pre None
	*  @post Creates and initializes a cow
	*  @return Initialzed class object with name set to "Cow" and sound set to "Moo"
	*/
    Cow();

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_milkProduced
	*/
    double getMilkProduced() const;

	/**
	*  @pre None
	*  @post If gallons is > 0, assigns the value to m_milkProduced. Set to 0 otherwise
	*  @return None
	*/
    void setMilkProduced(double gallons);

protected:
    double m_milkProduced;
};

#endif // COW_H
