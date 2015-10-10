/**
*	@file : AnimalPen.cpp
*	@author : Hung Nguyen
*	@date : 2014.10.02
*	Purpose: Implementation of AnimalPen class
*/
#include "AnimalPen.h"

AnimalPen::AnimalPen()
{
}

AnimalPen::~AnimalPen()
{
	while (!isEmpty())
    {
        pop();
    }
}

void AnimalPen::addAnimal(FarmAnimal* animal)
{
    push(animal);
}

FarmAnimal* AnimalPen::peakAtNextAnimal()
{
    return (peek());
}

void AnimalPen::releaseAnimal()
{
	pop();
}

bool AnimalPen::isPenEmpty()
{
	return(isEmpty());
}
