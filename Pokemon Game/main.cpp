/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.09.04
*	Purpose: Implementation of main function
*/

#pragma once
#include "Pokemon.h"

int main() {
	int count = 1;
	int roll;
	Pokemon P1, P2;
	Dice d10 = Dice(10);
	std::cout << "Player 1, build your Pokemon!" << '\n';
	std::cout << "=====================" << '\n';
	P1.userBuild();
	std::cout << "Player 2, build your Pokemon!" << '\n';
	std::cout << "=====================" << '\n';
	P2.userBuild();
	
	std::cout << "Player 1 will roll a D10, 6 or higher to go first." << '\n';
	roll = d10.roll();
	if (roll >= 6) {
		std::cout << "Player 1 rolls a " << roll << " and will go first" << '\n' << '\n' << '\n';
	}
	else {
		std::cout << "Player 1 rolls a " << roll << " and will go second" << '\n' << '\n' << '\n';
	}

	while (count <= 10) {
		std::cout << "Round " << count << "!" << '\n' << '\n';
		if (roll >= 6) {
            if (P1.attack(P2)) {
				return 0;
			}
            if (P2.attack(P1)) {
				return 0;
			}
        }
		else {
            if (P2.attack(P1)) {
				return 0;
			}
            if (P1.attack(P2)) {
				return 0;
			}
		}
		std::cout << '\n' << '\n';
		count++;
    }

    std::cout << "Both fighters are still standing! It's a draw!" << '\n';

	return 0;
}
