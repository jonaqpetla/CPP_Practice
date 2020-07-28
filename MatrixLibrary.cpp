//vectors, classes, operator overloading. best practices for vector library

/*targets:
1. Addition, subtraction, multiplication for all matrices of compatible dimensions
2. Rank, a basis for column space
3. Determinant for square matrices
4. Eigenvalues for simple matrices by brute forcing
*/

#include <iostream>
#include <vector>
using namespace std;

class matrix
{
	int m;
	int n;

	//vector <vector <double>>

public:
	matrix()
	{
		m = 0;
		n = 0;
	}

	matrix(int i, int j)
	{
		m = i;
		n = j;
	}
};

int main()
{
	//how to:
	//vector <vector <int>> mat = { {1, 2}, {3, 4} };
	//std::cout <<mat[0][0] << " " << mat[0][1] << std::endl; //prints 1 2
	matrix a = {};

	return 0;
}