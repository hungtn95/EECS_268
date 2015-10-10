/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.11.13
*	Purpose: Implementation of main function
*/

#include "Sorts.h"
#include "SortInfo.h"
#include <iostream>
#include <string>
#include <chrono>
#include <cassert>
#include <climits>

template<typename T>
double sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> elapsed;
    start = std::chrono::system_clock::now();
    sort(arr, size);
    end = std::chrono::system_clock::now();
    assert( Sorts<T>::isSorted(arr, size) );
    elapsed = (end - start);
    return elapsed.count();
}

template<typename T>
void sortTimingInfo(SortInfo<int>& sortInfo, double timeLimit)
{
    int size = 1;
    double m_time = 0.0;
    bool check = false;
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
    while (!check)
    {
        int* arr = new int[size];
        for  (int i = 0; i < size; i++)
        {
			arr[i] = distribution(generator);
        }
        if (sortTimer<int>(sortInfo.getSort(), arr, size) < timeLimit)
        {
            m_time = sortTimer<int>(sortInfo.getSort(), arr, size);
            size++;
        }
        else
        {
            check = true;
        }
        delete[] arr;
    }
    sortInfo.setCount(size);
    sortInfo.setTime(m_time);
}

int main()
{
    //Stores an array of SortInfo for all the sort methods in the sort class
    SortInfo<int> sorts[] = { SortInfo<int>( Sorts<int>::bogoSort, "Bogo Sort"),
        SortInfo<int>( Sorts<int>::bubbleSort, "Bubble Sort"),
        SortInfo<int>( Sorts<int>::insertionSort, "Insertion Sort"),
        SortInfo<int>( Sorts<int>::selectionSort, "Selection Sort"),
        SortInfo<int>( Sorts<int>::mergeSort, "Merge Sort"),
		SortInfo<int>(Sorts<int>::quickSort, "Quick Sort"),
        SortInfo<int>( Sorts<int>::quickSortMedian, "Quick Sort (median)") };
    int BOGO_LIMIT = 7;
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
    int* bogoArr = new int[BOGO_LIMIT];
    for  (int i = 0; i < BOGO_LIMIT; i++)
    {
        bogoArr[i] = distribution(generator);
    }
    sorts[0].setTime(sortTimer<int>(Sorts<int>::bogoSort, bogoArr, BOGO_LIMIT));
    delete[] bogoArr;
    std::cout << "Welcome to the sort program." << '\n';
    std::cout << "Bogo sort will now attempt to sort 7 numbers..." << '\n' << '\n';
    std::cout << "Bogo sort required " << sorts[0].getTime() << " seconds to sort 7 numbers." << '\n';
    std::cout << "In that same time, the following sorts were able to sort through..." << '\n';
    std::cout << "-------------------------------------------------------------------" << '\n';
    //use this time as the limit for all other sorts
    for (int i = 1; i < 7; i++)
    {
		sortTimingInfo<int>(sorts[i], sorts[0].getTime());
		std::cout << sorts[i].getName() << " sorted " << sorts[i].getCount() << " in " << sorts[i].getTime() << " seconds." << '\n';
    }

    return(0);
}
