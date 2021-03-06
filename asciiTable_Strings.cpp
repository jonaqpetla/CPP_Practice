// just a simple table of ascii number - char pairs
// also the basics of string library

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//ascii table for quick use: 
	for (int i = 1; i < 200; i++)
	{
		cout << i << " = '" << (char)i << "',";
		if (i % 8) cout << " ";	// fit more into the screen :P
		else cout << "\n";
	}

	//String part: works like a vertor
	cout << "\n\nEnter a string, no limits on length: \n";
	string s;
	//cin >> s;
	getline(cin, s);
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (i % 2)
			s[i] = toupper(s[i]);
		else s[i] = tolower(s[i]);
	}
	s.append("Huh?\n");	//string
	s.push_back('A');	//character
	s += "ppend"; //String
	s = s.substr(0, len);
	cout << "String: " << s << " \nwith capacity: " << s.capacity();
	
	/*
	//c style strings: char* 's
	char s0[80] = {0};	// "" initialisation
	const char* s1 = "Some const char*";
	const char* s2 = "Some other string literal";
	///* Stuff working with char* only:
	cout <<	strcat_s(s0, s1);
	cout <<	strcpy_s(s0, s2);
	cout << strlen(s0);
	cout << strcmp(s0, s2);  // 0 means equal, s1-s2 lexicographically.
	*/
}
