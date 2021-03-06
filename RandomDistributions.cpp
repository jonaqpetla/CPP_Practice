/*
1. Rand()
2. Gaussian
3. Time seeded random
4. Random Permutation (fast)
*/

#include <iostream>
#include <random>
#include <string>

int main()
{
	const int nrolls = 10000;  // number of experiments
	const int nstars = 100;    // maximum number of stars to distribute

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(10.0, 2.0);

	int p[20] = {};

	for (int i = 0; i < nrolls; ++i) {
		double number = distribution(generator);		//the only relevant line.
		if ((number >= 0.0) && (number < 20.0)) ++p[int(number)];	//for visualisation
	}

	std::cout << "normal_distribution (5.0,2.0):" << std::endl;

	for (int i = 0; i < 20; ++i) {
		std::cout << i << "-" << (i + 1) << ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}

	return 0;
}