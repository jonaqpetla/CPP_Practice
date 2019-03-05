// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

bool sort(int*, int);

int main()
{
	int i[] = { 18, 45, 5, 3, 4, 1, 2, 4 };

	const int len = sizeof(i)/sizeof(int);

	sort(&i[0], len);

	/*
	int k = 0;
	for (int j = 0; j < 5; j++)
	{
		cout << (++k) << endl;
	}
	*/

	return 0;
}

bool sort(int* arr, int siz)
{
	/*
	//Bubble Sort
	for (int i = 0; i < siz; i++)
	{
		for (int j = 0; j < siz - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	*/

	//Merge sort
	if (siz > 1)
	{
		//divide into two groups, sort the two
		sort(arr, siz / 2);
		sort(arr + siz / 2, siz - siz / 2);
		//merge the two sorted parts
		//int temp[siz];
		int temp[50];	//use only the first siz locations
		int finger[2] = { 0, 0 };
		for (int i = 0; i < siz; i++)
		{
			//careful about the overflows
			if (finger[0] >= siz/2 || (*(arr + finger[0]) > *(arr + siz / 2 + finger[1]) && finger[1] < siz - siz/2))
			{
				temp[i] = *(arr + siz / 2 + finger[1]);
				finger[1]++;
			}
			else
			{
				temp[i] = *(arr + finger[0]);
				finger[0]++;
			}
		}

		//overwrite the part in the array
		for (int i = 0; i < siz; i++)
		{
			*(arr + i) = temp[i];
		}
	}

	//return arr;
	return true;
}