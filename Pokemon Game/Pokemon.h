/**
*	@file : Pokemon.h
*	@author : Hung Nguyen
*	@date : 2014.09.04
*	Purpose: Header file of Pokemon Class
*/

#ifndef POKEMON_H
#define POKEMON_H
#include "Dice.h"
#include <iostream>
#include <string>

class Pokemon
{
    public:
    /**
    *  @pre None
    *  @post Creates and initializes a Pokemon instance
    *  @return Initialzed Pokemon with all numeric data set to zero, strings set to "", and Dice set to appropriate sizes
    */
    Pokemon();

    /**
    *  @pre None
    *  @post Calculates and display all information about the attack
    *  @return True only if the opponent died because of the attack, otherwise returns false
    */
    bool attack(Pokemon &opponent);

    /**
    *  @pre None
    *  @post Creates and initializes a Pokemon instance
    *  @return Initialzed Pokemon with the user's input
    */
    void userBuild();

    /**
    *  @pre attackLevel+defenseLevel must be between 1-50
    *  @post Creates and initializes a Pokemon instance
    *  @return Initialzed Pokemon with attackLevel initialzed to x.
    */
    void setAttack(int x);

    /**
    *  @pre None
    *  @post None
    *  @return the value of attackLevel
    */
    int getAttack();

    /**
    *  @pre attackLevel+defenseLevel must be between 1-50
    *  @post Creates and initializes a Pokemon instance
    *  @return Initialzed Pokemon with defenseLevel initialzed to x.
    */
    void setDefense(int x);

    /**
    *  @pre None
    *  @post None
    *  @return the value of defenseLevel
    */
    int getDefense();

    /**
    *  @pre HP must be between 1-50
    *  @post Creates and initializes a Pokemon instance
    *  @return Initialzed Pokemon with HP initialzed to x.
    */
    void setHP(int x);

    /**
    *  @pre None
    *  @post None
    *  @return the value of HP
    */
    int getHP();

    /**
    *  @pre none
    *  @post Creates and initializes a Pokemon instance
    *  @return Initialzed Pokemon with name initialzed to s.
    */
    void setName(std::string s);

    /**
    *  @pre None
    *  @post None
    *  @return the Pokemon's name
    */
    std::string getName();

    private:
    int HP, attackLevel, defenseLevel;
    std::string name;
    Dice d20;
    Dice d6;
};

#endif // POKEMON_H
