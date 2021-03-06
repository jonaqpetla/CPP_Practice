// For more precision, we have to access the OS specific libraries. This is about the C++ standrd

#include <iostream>
#include <chrono>

bool sampleFuntion(int n)
{
	int ctr = 0;
	for (int i = 0; i < n; i++)
	{
		if (n % (i + 1) == 0)
			ctr++;
	}
	return (ctr == 2);
}

class ourTimer
{
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
public:
	ourTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~ourTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> durr = end - start;
		std::cout << "Operation took " << durr.count() << "s \n";
	}
};

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
    std::cout << (sampleFuntion(511203011) ? "Yep. " : "Nope. ");
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> durr = end - start;
	std::cout << durr.count() << " s" << std::endl;

	//object lifetime to automatically time something?
	{
		ourTimer a;
		std::cout << (sampleFuntion(411203011) ? "Yep. " : "Nope. ");
	}

	return 0;
}