// I guess we know about vectors and function pointers
// pair, vector, set, multiset, map

// c++ stl is super useful, because implementing a functionality
// every time you need them is wasteful, and stl saves you time.
// can't finish competitve programming tasks without stl - you'll run out of time

// stl separates algorithms from objects, allowing code resuse
// every object has to offer the common interface i.e. iterators
// iterators behave like pointers.

// This is only an intro, a soft landing
// the big cheat-sheet is in quick_starts project.

#include <iostream>

#include <vector>
#include <set>
#include <map>

#include <algorithm>
//using namespace std;    // stl is in std. "Standard" template library

int main()
{
	// sorting a VECTOR of structs
	std::vector<int> A = { 4, 2, 3, 4 };
	A.push_back(5);
	// A.begin() returns an iterator - &A[0]. 
	// A.end() returns &A[n] which is right outside A. Don'r dereference it

	for (auto i = A.begin(); i < A.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	// sort
	std::sort(A.begin(), A.end());
	// sort is also overloaded with sort(begin, end, comparator function)

	// is an element present?
	std::cout << std::binary_search(A.begin(), A.end(), 3);
	std::cout << std::endl;

	// lower_bound() returns an iterator pointing to the first occurence 
	// (Greater than or EQUAL to) of what we're searching
	std::vector<int>::iterator it_1 = std::lower_bound(A.begin(), A.end(), 4);
	std::cout << *it_1;
	std::cout << std::endl;
	// upper bound returns to the location of the first element 
	// GREATER THAN what we're searching
	std::vector<int>::iterator it_2 = std::upper_bound(A.begin(), A.end(), 4); //points to 5
	std::cout << "Count is " << it_2 - it_1;
	std::cout << std::endl;
	// 4 need not have been inside the vector. these just return 
	// the first iterator satisfying >= or > conditions


	//maintaining a SET of structs
	// insert in log(N) time, maintain a sorted vector of unique elements
	std::set<int> B = { 4, 2, 3, 4 }; // {2, 3, 4}
	B.insert(5);
	for (auto x : B)     // the other style of for loop
		std::cout << x << " ";
	std::cout << std::endl;

	auto it_3 = B.find(3);
	if (it_3 == B.end())
		std::cout << "Element not found. ";
	else std::cout << *it_3;

	// because the class itself maintins a sorted array, 
	// lower bound and upper bound are already exposed
	auto it_4 = B.lower_bound(3);
	auto it_5 = B.upper_bound(3);
	auto it_6 = B.upper_bound(6);
	std::cout << *it_4 << " " << *it_5 << " " << (it_6 == B.end());
	std::cout << std::endl;


	// MAP
	std::map<int, int> C;
	C[1] = 200;
	C[2] = 500;
	C[3] = 1000;
	std::cout << C[3] << " ";
	std::map<char, int> D;
	const char* me = "Jonaq Niveer Sarma";
	for (int i = 0; me[i] != '\0'; i++)
		D[me[i]]++;
	std::cout << "\'a \'occurs " << D['a'] << " times in " << me << std::endl;

	// C.find(key) and C.erase(key)

	// PAIRS
	std::set< std::pair<int, int> > E;
	E.insert({ 1, 2 });
	E.insert({ -1,3 });
	std::cout << E.begin()->first << " " << E.begin()->second;
	// E[0] doesn't work. operator[] is left undefined.

	// unordered_set, tuples, dequeue ...
	// Everything else is in quck_starts.

	return 0;
}