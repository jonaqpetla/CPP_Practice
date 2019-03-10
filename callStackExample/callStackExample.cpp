// callStackExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void f(char* s)
{
	if (s[0])
		f(s+1);
	else
		return;

	std::cout << s[0];
}

int main()
{
	char maka[] = "haha10";
	int i = atoi(maka);

    std::cout << "Enter string: ";
	char s[100];
	gets_s(s);
	f(s);
	return 0;
}