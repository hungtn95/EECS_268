/**
*	@file : Sort.h
*	@author : Hung Nguyen
*	@date : 2014.11.13
*	Purpose: Header file of Sort class
*/

#include <random>
#include <ctime>
#ifndef SORTS_H
#define SORTS_H

template<typename T>
class Sorts
{
public:
	/**
	*  @pre None
	*  @post None
	*  @return None
	*/
    Sorts();

	/**
	*  @pre None
	*  @post Sorts arr using bubble sort algorithm
	*  @return None
	*/
    static void bubbleSort(T arr[], int size);

	/**
	*  @pre None
	*  @post Sorts arr using bogo sort algorithm
	*  @return None
	*/
    static void bogoSort(T arr[], int size);

	/**
	*  @pre None
	*  @post Sorts arr using insertion sort algorithm
	*  @return None
	*/
    static void insertionSort(T arr[], int size);

	/**
	*  @pre None
	*  @post Sorts arr using mergeSort algorithm
	*  @return None
	*/
    static void mergeSort(T arr[], int size);

	/**
	*  @pre None
	*  @post Calls quickSort with median flag set to false
	*  @return None
	*/
    static void quickSort(T arr[], int size);

	/**
	*  @pre None
	*  @post Calls quickSortRec with median flag set to true
	*  @return None
	*/
    static void quickSortMedian(T arr[], int size);

	/**
	*  @pre None
	*  @post Sorts arr using selection sort
	*  @return None
	*/
    static void selectionSort(T arr[], int size);

	/**
	*  @pre None
	*  @post None
	*  @return true is arr is in ascending order, false otherwise
	*/
    static bool isSorted(T arr[], int size);

private:
	/**
	*  @pre None
	*  @post Combine arrays into a single sorted array
	*  @return None
	*/
    static void merge(T* a1, T* a2, int size1, int size2);

	/**
	*  @pre None
	*  @post Partitioning the array, quick sorting left of pivot, and quick sorting right of pivot. Passes median to partition 
	*  @return None
	*/
    static void quickSortRec(T arr[], int first, int last, bool median);

	/**
	*  @pre Called when median is true
	*  @post Puts the median value of the array in the last position
	*  @return None
	*/
    static void setMedianPivot(T arr[], int first, int last);

	/**
	*  @pre None
	*  @post If median is true, use setMedianPivot, otherwise select the last element in the array
	*  @return The index of the pivot
	*/
    static int partition(T arr[], int first, int last, bool median);

	/**
	*  @pre None
	*  @post For each index in the array, swap it the value at another random index
	*  @return None
	*/
    static void shuffle(T arr[], int size);
};

#include "Sorts.hpp"
#endif // SORT_H
