// Member initializer list, inheritance, protected, construction order etc.
// clarify virtual class stuff

#include "pch.h"
#include <iostream>

class Base
{
	int a;
public:
	Base(int i) : a(i) { std::cout << "Constructed Base instance." << std::endl;  }
	~Base() { std::cout << "Destroyed Base instance" << std::endl; }
};

class Inherited_1 : public Base
{
	int b;
public:
	Inherited_1(int i, int j) : Base(i), b(j) { std::cout << "Constructing Inherited_1 instance." << std::endl; }
	~Inherited_1() { std::cout << "Destroying Inherited_1 instance." << std::endl; }
};

class Inherited_2 : public Base
{
	int c;
public:
	Inherited_2(int i, int j) : Base(i), c(j) { std::cout << "Constructing Inherited_2 instance." << std::endl; }
	~Inherited_2() { std::cout << "Destroying Inherited_2 instance." << std::endl; }

};

// public and protected of Inherited_1 and Inherited_2 are now private and <as is> in Grand_1
class Grand_1 : private Inherited_1, public Inherited_2
{
	int d;
public:
	Grand_1(int i, int j, int k, int l) : Inherited_1(i, j), Inherited_2(i, k), d(l) { std::cout << "Constructing Grand_1 instance." << std::endl; }
	~Grand_1() { std::cout << "Dectroying Grand_1 instance." << std::endl; }
};

int main()
{
	{
		Grand_1 a(1, 2, 3, 4);
	}

	return 0;
}