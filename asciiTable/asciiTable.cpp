// asciiTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 128; i++)
	{
		cout << i << "= '" << (char)i << ",\n";
	}
}

