#include <iostream>
using namespace std;

const int memoSize = 100;
unsigned long long memo[memoSize];

unsigned long long fib(int n)
{
	if (n <= 1)
		return n;
	else if (memo[n] != 0)
		return memo[n];
	else
	{
		memo[n] = fib(n - 1) + fib(n - 2);
		return memo[n];
	}
}

int main()
{
	int n = 0;
	cout << "Enter number (<=93 because of limits on unsigned long long): ";
	cin >> n;

	for (int i = 0; i < memoSize; i++)
	{
		memo[i] = 0;
	}

	cout << "Fib(" << n << ") = " << fib(n);

	return 0;
}
