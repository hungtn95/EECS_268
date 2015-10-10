/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.10.31
*	Purpose: Implementation of main function of the sorting program
*/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <random>
#include <ctime>
#include <chrono>
#include "Sorts.h"

int main(int argc, char** argv)
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	std::ifstream input(argv[1]);
	std::ofstream bubble("bubble.txt");
	std::ofstream merge("merge.txt");
	int size;
	input >> size;
	int* arr = new int[size];
	Sorts<int>* sort = new Sorts<int>();
	for (int i = 0; i < size; i++)
	{
		input >> arr[i];
	}
	input.close();
	int* arr1 = arr;
	int* arr2 = arr;

	start = std::chrono::system_clock::now();
	sort->bubbleSort(arr1, size);
	for (int i = 0; i < size; i++)
	{
		bubble << arr1[i]  << '\n';
	}
	end = std::chrono::system_clock::now();
	elapsed = (end - start);
	std::cout << "Bubble sort completed in " << elapsed.count() << " seconds\n";
	bubble.close();

	start = std::chrono::system_clock::now();
	arr2 = sort->mergeSort(arr2, size);
	for (int i = 0; i < size; i++)
	{
		merge << arr2[i]  << '\n';
	}
	end = std::chrono::system_clock::now();
	elapsed = (end - start);
	std::cout << "Merge sort completed in " << elapsed.count() << " seconds\n";
	merge.close();
	delete[] arr;
	delete sort;
}