// Incomplete base converter - doesn't handle decimals properly 

#include <iostream>
#include <string>
using namespace std;

//we'll use strings
//haven't implemented decimal places. yolo.

char intToChar(int);
int charToInt(char);
int pow(int, int);

int main()
{
	cout << "Decimal places not implemented. Sorry :P\n";
	int src, tgt;
	cout << "Source Base: ";
	cin >> src;
	cout << "Target Base: ";
	cin >> tgt;

	string input;
    cout << "Enter number: ";
	cin >> input;

	int len = input.length();

	//convert to decimal
	int dec = 0;
	for (int i = 0; i < len; i++)
	{
		dec += charToInt(input[len - 1 - i])*pow(src, i);
	}

	//convert to base
	input =	"";
	while (dec > 0)
	{
		input = intToChar(dec%tgt) + input;
		dec /= tgt;
	}
	cout << "Answer: " << input;
	return 0;
}

char intToChar(int n)
{
	if (0 <= n && n <= 9)
		return n + 48;
	else if (n >= 10)
		return n + 55;
	else return 48;
}

int charToInt(char a)
{
	//if integers 0-9
	if ((int)a <= 57 && (int)a >= 48)
		return (int)a - 48;
	//if lower case values a-z
	else if((int)a <= 122 && (int)a >= 97)
		return (int)a - 87;
	//if upper case values A-Z
	else if ((int)a <= 90 && (int)a >= 65)
		return (int)a - 55;
	else return 0;
}

int pow(int i, int j)
{
	int temp = 1;
	for (int k = 0; k < j; k++)
	{
		temp *= i;
	}
	return temp;
}