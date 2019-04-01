// FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <functional>	// for passing values into a labmda

void printValue(int i)
{
	std::cout << "Value is " << i << std::endl;
}

void function(int val, void (*func)(int))
{
	std::cout << "Doing something..." << std::endl;
	func(val);
}

void newStyleFunction(int val, std::function<void(int)> funky)
{
	std::cout << "Doing something new..." << std::endl;
	funky(val);
}

int main()
{
	auto FunctionPointer_1 = printValue;
	void (*FunctionPointer_2)(int) = printValue;
	function(13, FunctionPointer_1);
	function(52, FunctionPointer_2);
	function(104, printValue);
	function(208, [](int ahem) { std::cout << "Value is " << ahem << std::endl; });
	// the lambda function doesn't need to know any variables, so we don't capture anything.
	// int a = 39;
	// function(416, [&](int ahem) {std::cout << a << " and " << ahem << std::endl; });
	// raw function pointers are not supported by c-style function pointers as shown here.
	// captures everything by reference. '=' means capture everything by value
	// more respectable way: [a, &b](int ahem) { <body> }; pass a by value, b by ref
	int a = 39;
	newStyleFunction(416, [&a](int lulz) {std::cout << a << " and " << lulz << std::endl; });
	return 0;
}