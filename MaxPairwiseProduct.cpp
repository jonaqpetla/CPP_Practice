#include <iostream>

// take a bunch of numbers, calculate the max pairwise product
// like sorting, but not really. We'll do it in one pass

int main()
{
	int storage[1000];
	int n = 0;
	std::cout << "Number of numbers: ";
	std::cin >> n;
	std::cout << "Numbers: ";
	for (int i = 0; i < n; i++)
	{
		std::cin >> storage[i];
	}

	int relevant[4];	//min, sec min, sec max, max numbers we've found so far
	if (storage[0] <= storage[1])
	{

		relevant[0] = relevant[2] = storage[0];
		relevant[1] = relevant[3] = storage[1];
	}
	else
	{
		relevant[0] = relevant[2] = storage[1];
		relevant[1] = relevant[3] = storage[0];
	}

	for (int i = 2; i < n; i++)
	{
		if (storage[i] >= relevant[3] || storage[i] > relevant[2])
		{
			relevant[2] = relevant[3];
			relevant[3] = storage[i];
		}
		else if (storage[i] <= relevant[0] || storage[i] < relevant[1])
		{
			relevant[1] = relevant[0];
			relevant[0] = storage[i];
		}
	}

	int max = relevant[2] * relevant[3];
	if (max < relevant[0] * relevant[1])
		max = relevant[0] * relevant[1];

	std::cout << "Answer: " << max << std::endl;
	return 0;
}