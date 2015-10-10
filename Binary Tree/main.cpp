/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.12.05
*	Purpose: Implementation of main function
*/

#include "BinarySearchTree.h"
#include <fstream>
#include <random>
#include <stdexcept>
#include <string>
#include <ctime>
#include <climits>

void printTree(BinarySearchTree<int>* tree)
{
	int print_choice;
	std::cout << "print order options:" << '\n'
		<< "	0 - pre-order" << '\n'
		<< "	1 - in-order" << '\n'
		<< "	2 - post-order" << '\n'
		<< "Choice: ";
	std::cin >> print_choice;
	std::cout << "You chose: " << print_choice << '\n';
	if (print_choice == 0)
	{
		tree->printTree(PRE_ORDER);
	}
	if (print_choice == 1)
	{
		tree->printTree(IN_ORDER);
	}
	if (print_choice == 2)
	{
		tree->printTree(POST_ORDER);
	}
}

void searchTree(BinarySearchTree<int>* tree)
{
	int searchValue;
	std::cout << "Input a value to search: ";
	std::cin >> searchValue;
	if (tree->search(searchValue) == nullptr)
	{
		std::cout << "The value doesn't exist in the tree." << '\n';
	}
	else
	{
		std::cout << "The value exists in the tree." << '\n';
	}
}

int main(int argc, char** argv)
{
	int size = 0;
	int choice = 0;
	int user_input;
	BinarySearchTree<int>* original = new BinarySearchTree<int>();
	BinarySearchTree<int>* copy = nullptr;
	try
	{
		if (argc == 3)
		{
			throw (std::runtime_error("Input Invalid"));
		}
		else
		{
			if (argc == 2)
			{
				size = std::stoi(argv[1]);
				if (size <= 0)
				{
					throw (std::runtime_error("Invalid size"));
				}
			}
		}
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << '\n';
		return 0;
	}
	std::cout << "Arg count: " << argc << '\n';
	std::cout << "Node count: " << size << '\n';
	if (size != 0) 
	{
		std::cout << '\n' << "Filling original array with " << size << " value" << '\n';
		std::default_random_engine generator(time(nullptr));
		std::uniform_int_distribution<int> distribution(0, 1000);
		int rand = 0;
		for (int i = 0; i < size; i++)
		{
			rand = distribution(generator);
			std::cout << "Adding " << rand << " to original tree" << '\n';
			original->add(rand);
		}
	}
	while (choice != 8)
	{
		std::cout << '\n' << "Input a selection" << '\n'
			<< "1) Add more values to original tree" << '\n'
			<< "2) Copy the original tree" << '\n'
			<< "3) Delete the original tree (one time only)" << '\n'
			<< "4) Print original tree" << '\n'
			<< "5) Print copy" << '\n'
			<< "6) Search original tree" << '\n'
			<< "7) Search copy" << '\n'
			<< "8) Exit" << '\n';
		std::cout << "Your choice: ";
		std::cin >> choice;
		std::cout << "You chose " << choice << '\n';
		switch (choice)
		{
		case 1:
			if (original == nullptr)
			{
				std::cout << "Original doesn't exits." << '\n';
			}
			else
			{
				std::cout << "Input a value to add to the original: ";
				std::cin >> user_input;
				original->add(user_input);
				std::cout << "Adding " << user_input << " to the original tree." << '\n';
			}
			break;

		case 2:
			std::cout << "Copying the original tree." << '\n';
			delete copy;
			copy = new BinarySearchTree<int>(*original);
			break;

		case 3:
			std::cout << "Original Tree deleted." << '\n';
			delete original;
			original = nullptr;
			break;

		case 4:
			if (original == nullptr)
			{
				std::cout << "Original doesn't exits." << '\n';
			}
			else
			{
				printTree(original);
			}
			break;

		case 5:
			if (copy == nullptr)
			{
				std::cout << "This tree doesn't exist. Cannot print." << '\n';
			}
			else
			{
				printTree(copy);
			}
			break;

		case 6:
			if (original == nullptr)
			{
				std::cout << "Original doesn't exits." << '\n';
			}
			else
			{
				searchTree(original);
			}
			break;

		case 7:
			if (copy == nullptr)
			{
				std::cout << "This tree doesn't exist. Cannot search." << '\n';
			}
			else
			{
				searchTree(copy);
			}
			break;

		case 8:
			std::cout << "Exiting..." << '\n';
			break;
		}
	}
	if (original != nullptr)
	{
		delete original;
	}
	if (copy != nullptr)
	{
		delete copy;
	}
}
