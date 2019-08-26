#include <iostream>
using namespace std;

int main()
{
	float f;
	cin >> f;
	int n = *((int*)& f);
	cout << "recovered: " << n << " & the bit pattern is: ";
	//cout << sizeof(float);
	for (int i = 0; i < sizeof(float) * 8; i++)
	{
		cout << ((int)(n >> (sizeof(float) * 8 - i - 1)) & 1) << (!((i + 1) % 4) ? " " : "");
	}

	cout << "\nStored in memory as: \n";
	for (int i = 0; i < sizeof(float); i++)
	{
		char* byteLoc = ((char*)& f) + i;
		cout << (long)byteLoc << " : " << (int)* byteLoc << endl;
		//for(int j = 0; j < 8; j++)
		//    cout << ((int)*(byteLoc) >> (8 - i - 1));
	}

	return 0;
}