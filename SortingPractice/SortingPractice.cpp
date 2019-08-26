// SortingPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
using namespace std;

const int maxSize = 10000;

// array location, length of the array for bounds protection
bool bubbleSort(float*, int);
bool mergeSort(float*, int);
bool quickSort(float*, int);
bool heapSort(float*, int);
bool bstSort(float*, int);
bool avlSort(float*, int);

// heap structure, saved in an array, for heap sort

// binary search tree, for bst sort

// another tree, self balancing, for avl sort

int main()
{
	/*
	//acquire data
	float arr[maxSize];
	int n = 0;
	cout << "Enter size of array: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	*/

	/*
	//test data
	
	float arr[] = { 52, 34, 12.1f, 12, 12, 13, 11 };
	int n = 7;
	*/
	
	int n = maxSize;
	float* arr = new float[maxSize];
	for (int i = 0; i < n; i++)
	{
		arr[i] = (float)(rand() % maxSize);
	}
	

	//sort
	//bubbleSort(&arr[0], n);
	//mergeSort(&arr[0], n);
	quickSort(&arr[0], n);

	//display the sorted data
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;
}

bool mergeSort(float* arry, int siz) // can exceed stack size due to stack depth. VS warns as well.
{
	if (siz > 1)
	{
		//divide into two arrays and sort the halves
		mergeSort(arry, siz / 2);
		mergeSort(arry + (siz / 2), siz - siz / 2);

		//merge properly: need to copy over once
		float temp[maxSize];
		int fingers[] = { 0, 0 };
		for (int i = 0; i < siz; i++)
		{
			if ((fingers[1] >= siz - (siz / 2)) || ((fingers[0] < siz / 2) && *(arry + fingers[0]) <= *(arry + siz / 2 + fingers[1])))
			{
				temp[i] = *(arry + fingers[0]);
				fingers[0]++;
			}
			else
			{
				temp[i] = *(arry + siz/2 + fingers[1]);
				fingers[1]++;
			}
		}
		for (int i = 0; i < siz; i++)
		{
			*(arry + i) = temp[i];
		}
	}
	return true;
}
bool bubbleSort(float* arry, int siz)
{
	for (int i = 0; i < siz; i++)
	{
		for (int j = 0; j < siz-1; j++)
		{
			if (*(arry + j) > *(arry + j + 1))
			{
				float temp = *(arry + j);
				*(arry + j) = *(arry + j + 1);
				*(arry + j + 1) = temp;
			}
		}
	}

	return true;
}

bool quickSort(float* arry, int siz)
{
	if (siz <= 1)
		return true;	// do nothing
	else
	{
		//choose pivot
		int pivot = siz / 2;

		//arrange properly
		int finger[2] = { 0, siz - 1 };

		//swaps
		while (finger[0] != finger[1]) 
		{
			if (finger[0] < pivot && arry[finger[0]] <= arry[pivot])
				finger[0]++;
			else
			{
				//find an element to swap with
				while (finger[1] > pivot && arry[finger[1]] >= arry[pivot])
					finger[1]--;
			}

			if (finger[0] != finger[1])
			{
				if (finger[0] == pivot)
					pivot = finger[1];
				else if (finger[1] == pivot)
					pivot = finger[0];
				//swap
				float temp = arry[finger[0]];
				arry[finger[0]] = arry[finger[1]];
				arry[finger[1]] = temp;
			}
		}

		//sort the remaining halves
		quickSort(&arry[0], pivot);
		quickSort(&arry[pivot], siz - pivot);

		//successful end
		return true;
	}
	
	cout << "wtf you shouldn't have reached this point. Run for your life!\n";
	return true;
}

bool heapSort(float* arry, int siz)
{
	return true;
}

bool bstSort(float* arry, int siz)
{
	return true;
}

bool avlSort(float* arry, int siz)
{
	return true;
}