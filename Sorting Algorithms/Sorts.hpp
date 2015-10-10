/**
*	@file : Sorts.hpp
*	@author : Hung Nguyen
*	@date : 2014.10.31
*	Purpose: Implementation of Sorts class
*/

template<typename T>
Sorts<T>::Sorts()
{
}

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template<typename T>
T* Sorts<T>::mergeSort(T arr[], int size)
{
	if (size <= 1)
	{
		return (arr);
	}
	else
	{
		int sizeLeft = size / 2;
		int sizeRight = size - sizeLeft;
		T* left = new T[sizeLeft];
		T* right = new T[sizeRight];
		for (int i = 0; i <= sizeLeft - 1; i++)
		{
			left[i] = arr[i];
		}
		for (int i = 0; i <= sizeRight - 1; i++)
		{
			right[i] = arr[sizeLeft + i];
		}
		return (merge(mergeSort(left, sizeLeft), mergeSort(right, sizeRight), sizeLeft, sizeRight));
	}
}

template<typename T>
T* Sorts<T>::merge(T* left, T* right, int sizeLeft, int sizeRight)
{
	T* merged = new T[sizeLeft + sizeRight];
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < sizeLeft && j < sizeRight)
	{
		if (left[i] <= right[j]) 
		{
			merged[count] = left[i];
			i++;
		}
		else
		{
			merged[count] = right[j];
			j++;
		}
		count++;
	}
	if (i == sizeLeft)
	{
		for (int m = j; m <= sizeRight - 1; m++)
		{
			merged[count] = right[m];
			count++;
		}
	}
	if (j == sizeRight)
	{
		for (int m = i; m <= sizeLeft - 1; m++)
		{
			merged[count] = left[m];
			count++;
		}
	}
	return (merged);
}

