#include <iostream>

class StringMod
{
	char* m_buffer;
	unsigned int m_len;
public:
	StringMod(const char* inStream)
	{
		std::cout << "Constructed a StringMod.\n";
		m_len = strlen(inStream);
		m_buffer = new char[m_len + 1];	//for the null termination char
		//a for loop would do, but we have a better solution
		memcpy(m_buffer, inStream, m_len);
		m_buffer[m_len] = 0;
	}

	//comment out this copy constructor to see what happens when we use the default copy constructor
	//default copy constructor does a memcpy
	//StringMod(const StringMod& other) = delete; //will delete the copy constructor. this is what
	//unique_ptr does btw, so you can't copy a unique_ptr.
	StringMod(const StringMod& other)
		:m_len(other.m_len)
	{
		//m_len = other.m_len;	//already did it in initialiser list
		m_buffer = new char[m_len + 1];
		memcpy(m_buffer, other.m_buffer, m_len + 1);

		std::cout << "Called StringMod Copy Constructor.\n";
	}

	~StringMod()
	{
		std::cout << "Called StringMod Destructor.\n";
		delete[] m_buffer;	//because we used new char[]. not deleting it will cause a memory leak
	}

	friend std::ostream& operator<<(std::ostream&, const StringMod&);
};

std::ostream& operator<<(std::ostream& stream, const StringMod& ourString)
{
	stream << ourString.m_buffer;
	return stream;
}

int main()
{
	StringMod a = "Demo string";
	{
		StringMod b = a;	//this had a pointer to the same memory address.
		//doing this throws an error if we haven't modified the copy constructor. 
		//Because we copied a, we also copied the pointer, to the same address
		//so when we destroy b, we destory the memory from a. So now we can't access a outside.
		//We should have done a deep copy instead.
	}
	std::cout << a << std::endl;

	//what happens when we pass something by value? A copy is made, duh.
	//That's a performance overhead.
	//make a habit of passing by const reference

	return 0;
}