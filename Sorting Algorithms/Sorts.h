/**
*	@file : Sorts.h
*	@author : Hung Nguyen
*	@date : 2014.10.31
*	Purpose: Header file of Sorts class
*/

#ifndef SORTS_H
#define SORTS_H

template<typename T>
class Sorts
{
public:
	/**
	*  @pre None
	*  @post None
	*  @return Constructor
	*/
    Sorts();

	/**
	*  @pre arr is an array of valid Ts and the < operator is overloaded properly
	*  @post None
	*  @return None
	*/
    void bubbleSort(T arr[], int size);

	/**
	*  @pre arr is an array of valid Ts and the < operator is overloaded properly
	*  @post None
	*  @return pointer to sorted array
	*/
    T* mergeSort(T arr[], int size);

private:
	/**
	*  @pre left and right are sorted halves of a larger array
	*  @post None
	*  @return a pointer to a sorted combination of left and right
	*/
    T*merge(T* left, T* right, int sizeLeft, int sizeRight);
};
#include "Sorts.hpp"

#endif // SORTS_H
