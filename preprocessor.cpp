#include <iostream>
using namespace std;

#define SAYBYE(x) std::cout << "Goodbye!" << x <<std::endl 

int main()
{
	cout << "Hello World! \n";
	int a, b = 0;
	cout << "Enter two numbers to add: ______ \rEnter two numbers to add: ";
	cin >> a >> b;
	cout << a + b << endl;

	SAYBYE(" See you!\n");

	return 0;
}