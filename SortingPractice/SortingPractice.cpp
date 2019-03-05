// SortingPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

const int maxSize = 10000;

bool bubbleSort(float*, int);
bool mergeSort(float*, int);

int main()
{
	
	//acquire data
	float arr[maxSize];
	int n = 0;
	cout << "Enter size of array: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	

	//test data
	/*
	float arr[] = { 52, 34, 12.1, 12, 12, 13, 11 };
	int n = 7;
	*/
	/*
	int n = maxSize;
	float arr[maxSize];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % maxSize;
	}
	*/

	//sort
	//bubbleSort(&arr[0], n);
	mergeSort(&arr[0], n);

	//display the sorted data
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

bool mergeSort(float* arry, int siz)
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