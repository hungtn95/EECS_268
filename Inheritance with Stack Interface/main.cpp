/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.09.25
*	Purpose: Implementation of main function
*/

//main.cpp
#include <iostream> //cout cin
#include "StackOfAnything.h" //Template box class
#include <stdexcept>

void printMenu()
{
    std::cout << "Select an action" << std::endl;
    std::cout << "1) Push onto the number stack" << std::endl;
    std::cout << "2) Push onto the character stack" << std::endl;
    std::cout << "3) Peek at top of number stack" << std::endl;
    std::cout << "4) Peek at top of character stack" << std::endl;
    std::cout << "5) Pop top of number stack" << std::endl;
    std::cout << "6) Pop top of character stack" << std::endl;
    std::cout << "7) Check size of number stack" << std::endl;
    std::cout << "8) Check size of character stack" << std::endl;
    std::cout << "9) Quit" << std::endl;
}

int main()
{
    char choice = ' ';
    StackOfAnything<int> intStack;
    StackOfAnything<char> charStack;

    while (choice != '9')
    {
		std::cout << std::endl << std::endl;
		printMenu();
        std::cout << "Enter choice:" << std::endl;
        std::cin >> choice;
        std::cout << "You selected: " << choice << std::endl;
        switch (choice)
        {

		case '1':
		{
			int intVal;
			std::cout << "Enter a number:" << std::endl;
			std::cin >> intVal;
			intStack.push(intVal);
			std::cout << intVal << " added to stack" << std::endl;
			break;
		}    

		case '2':
		{
			char charVal;
			std::cout << "Enter a character:" << std::endl;
			std::cin >> charVal;
			charStack.push(charVal);
			std::cout << charVal << " added to stack" << std::endl;
			break;
		}				

		case '3':
		{
			try
			{
				std::cout << "The top of the stack is " << intStack.peek() << std::endl;
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		}
				
		case '4':
		{
			try
			{
				std::cout << "The top of the stack is " << charStack.peek() << std::endl;
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		}			

		case '5':
		{
			try
			{
				std::cout << intStack.pop() << " has been removed from the stack" << std::endl;
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		}
				
		case '6':
		{
			try
			{
				std::cout << charStack.pop() << " has been removed from the stack" << std::endl;
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		}
				
		case '7':
		{
			std::cout << "The number stack contains " << intStack.size() << " number" << std::endl;
			break;
		}

		case '8':
		{
			std::cout << "The character stack contains " << charStack.size() << " characters" << std::endl;
			break;
		}			

        }
    }
	std::cout << std::endl << "Exiting...";
    
    return(0);
}
