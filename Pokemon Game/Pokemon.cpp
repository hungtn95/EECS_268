/**
*	@file : Pokemon.cpp
*	@author : Hung Nguyen
*	@date : 2014.09.04
*	Purpose: Implementation of Pokemon Class
*/

#include "Pokemon.h"
#include "Dice.h"
#include <iostream>
#include <string>

Pokemon::Pokemon() {
    this->setHP(0);
    this->setAttack(0);
    this->setDefense(0);
    this->setName("");
    this->d6 = Dice(6);
    this->d20 = Dice(20);
}

void Pokemon::setHP(int HP) {
	this->HP = HP;
}

void Pokemon::setName(std::string name) {
	this->name = name;
}

void Pokemon::setAttack(int attack) {
	this->attackLevel = attack;
}

void Pokemon::setDefense(int defence) {
	this->defenseLevel = defence;
}

int Pokemon::getHP() {
	return (this->HP);
}

std::string Pokemon::getName() {
	return (this->name);
}

int Pokemon::getAttack() {
	return (this->attackLevel);
}

int Pokemon::getDefense() {
	return (this->defenseLevel);
}

void Pokemon::userBuild() {
	std::cout << "Please name your pokemon: ";
	std::cin >> this->name;
	std::cout << '\n';
	std::cout << "How many hit points will it have? (1-50): ";
	std::cin >> this->HP;
	std::cout << '\n';
	while (this->HP > 50 || this->HP < 1) {
		std::cout << "Sorry. The hit points must be between 1 and 50: ";
		std::cin >> this->HP;
		std::cout << '\n';
	}

	std::cout << "Split fifty points between attack level and defense level" << '\n';
	std::cout << "Enter your attack level (1-49): ";
	std::cin >> this->attackLevel;
	std::cout << '\n';
	while (this->attackLevel > 49 || this->attackLevel < 1) {
		std::cout << "Sorry. The attack level must be between 1 and 49: ";
		std::cin >> this->attackLevel;
		std::cout << '\n';
	}

	std::cout << "Enter your defense level (1-" << 50 - this->attackLevel << "): ";
	std::cin >> this->defenseLevel;
	std::cout << '\n';
	while (this->defenseLevel > 50 - this->attackLevel || this->defenseLevel < 1) {
		std::cout << "Sorry. The defence level must be between 1 and " << 50 - this->attackLevel << ": ";
		std::cin >> this->defenseLevel;
		std::cout << '\n';
	}
}

bool Pokemon::attack(Pokemon &opponent) {	
	std::cout << this->getName() << " is attacking " << opponent.getName() << '\n';
	int attackBonus = this->d20.roll();
	std::cout << this->getName() << " rolls an attack bonus of " << attackBonus << '\n';
    int defenseBonus = opponent.d20.roll();
    std::cout << opponent.getName() << " rolls an defence bonus of " << defenseBonus << '\n';

    if (this->getAttack() + attackBonus > opponent.getDefense() + defenseBonus) {
        std::cout << "The attack hits dealing 3-D6 damage!" << '\n';
		int a1 = this->d6.roll();
		int a2 = this->d6.roll();
		int a3 = this->d6.roll();
		std::cout << "The rolls are " << a1 << ", " << a2 << ", and " << a3 << " totaling: " << a1 + a2 + a3 << " damage!" << '\n';
		opponent.setHP(opponent.getHP() - a1 - a2 - a3);
		if (opponent.getHP() <= 0) {
			std::cout << opponent.getName() << " have been defeated!" << '\n';
			return true;
		}
		else {
			std::cout << opponent.getName() << " has " << opponent.getHP() << " hit points left" << '\n';
		}
    }
	else {
		std::cout << "The attack missed!" << '\n';
	}
	return false;
}
