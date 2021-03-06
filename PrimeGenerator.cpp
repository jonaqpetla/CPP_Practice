#include <iostream>
using namespace std;

bool prime(long);

const int MAXSIZE = 100000;

int main()
{
	int n = 0;
	cout << "Enter number of Primes to find (hard limit of " << MAXSIZE << "): ";
	cin >> n;

	long* primes = new long[MAXSIZE];
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

	delete[] primes;

	return 0;
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