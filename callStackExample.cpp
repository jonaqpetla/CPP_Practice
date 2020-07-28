// Beautiful call stack example inspired by Tryst 2019's competition

#include <iostream>

void f(char* s)
{
	if (s[0])
		f(s+1);
	else
		return;

	std::cout << s[0];
}

int main()
{
	char maka[] = "haha10";
	int i = atoi(maka);

    std::cout << "Enter string: ";
	char s[100];
	gets(s);
	f(s);
	return 0;
}