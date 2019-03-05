// PrimeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

bool prime(long);

int main()
{
	int n = 0;
	cout << "Enter number of Primes to find (hard limit of 10000): ";
	cin >> n;

	long primes[10000];
	long j = 1;
	for (int i = 0; i < n; i++)
	{
		while (!prime(j))
			j++;
		primes[i] = j;
		j++;
	}

	for (int i = 0; i < n; i++)
	{
		cout << i+1 << ". " << primes[i] << endl;
	}
}

bool prime(long n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (n % (i + 1) == 0)
			counter++;
		if (counter > 2)
			break;
	}
	if (counter == 2)
		return true;
	else return false;
}