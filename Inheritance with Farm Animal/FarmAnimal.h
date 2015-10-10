/**
*	@file : FarmAnimal.h
*	@author : Hung Nguyen
*	@date : 2014.10.02
*	Purpose: Header file of FarmAnimal class
*/
#ifndef FARMANIMAL_H
#define FARMANIMAL_H
#include <string>

class FarmAnimal
{
public:
	/**
	*  @pre None
	*  @post Creates and initializes an animal
	*  @return Initialzed class object with name and sound set to the string "unset" by default
	*/
	FarmAnimal();

	/**
	*  @pre None
	*  @post None
	*  @return The value of m_name
	*/
    std::string getName() const;

	/**
	*  @pre None
	*  @post Sets the value of m_name
	*  @return None
	*/
    void setName(std::string name);

	/**
	*  @pre None
	*  @post None
	*  @return The value of m_sound
	*/
    std::string getSound() const;

	/**
	*  @pre None
	*  @post Sets the value of m_sound
	*  @return None
	*/
    void setSound(std::string sound);

protected:
    std::string m_name;
    std::string m_sound;
};

#endif // FARMANIMAL_H
