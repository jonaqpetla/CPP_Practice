/* Templates may cause code bloating. Although we have reduced code duplication, C++ will generate code
as if template was never used. Some obj files may become unexpectedly large due to this.*/

// C++'s one of the most sophisticated and powerful feature.

// Generic Functions =================================================================
// template <class Type> return_type function_name(parameter_list) or
// template <typename Type> return_type function_name(parameter_list)
// or equivalently, maybe a cleaner version would be
// template <typename Type>
// return_type function_name(parameter_list) {}
// because no value of endl in C++ code. This is all a single line.

// two generic types?
// template <typename type_1, typename type_2> return_type function_name(params)

// a specific version, if provided, will override the generic version
// simple overload or template <> return_type function_name<int (version)>(param_list)

// you can overload generic functions. maybe one accepts one argument, other accepts 3...
template <typename T>
T square(T n, int useless = 10) // some useless int with default value
{
	return n * n;
}

// Generic Classes ======================================================================
// template <class Tname> class class_name {};
// class_name<type_info> instance;

// can provide specific instances, or default type etc, just like functions

template <typename T> class holder
{
	T mem;
public:
	holder(T in) : mem(in) {}
	T get() { return mem; }
	void set(T in);
};

// instead of: void holder::set(T in)
template <typename Type> void holder<Type>::set(Type input)
{
	mem = input;
}

#include <iostream>
using namespace std;

int main()
{
	cout << square(5.5) << endl;
	cout << square(5) << endl;

	holder<int> a(5);
	a.set(6);
	cout << a.get() << endl;

	return 0;
}