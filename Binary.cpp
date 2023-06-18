#include <iostream>
#include <string>
using namespace std;

	
// funtion to convert int16_t to binary	
string int16ToBinary(int16_t number)
{
	string res = "";
	for (int i = 15; i >= 0; i--)
	{
		int tmp = ((number >> i) & 1);
		res += to_string(tmp);
	}
	return res;
}

// funtion to covert floating point to binary
string floatToBinary(float number)
{
	uint32_t *p = reinterpret_cast<uint32_t*> (&number);
	string res = "";
	for (int i = 31; i >= 0; i--)
	{
		uint32_t tmp = (*p >> i) & 1;
		res += to_string(tmp);
	}	
	return res;
}	
	
void menu()
{
	int type;
	int a;
	float b;
	string res;
	bool run = 1;
	while (run)
	{
		cout << "Press 1 to convert signed integer 16-bit to binary. \n"
			 << "Press 2 to convert floating point to binary. \n"
			 << "Press 0 to exit. \n"
			 << "Your choice: ";
		cin >> type;
		switch (type)
		{
			case 1:
				{
					cout << "INPUT: ";
					cin >> a;
					res = int16ToBinary(a);
					cout << "OUTPUT: " << res << "\n\n"; 
					break;
				}
			case 2:
				{
					cout << "INPUT: ";
					cin >> b;
					res = floatToBinary(b);
					cout << "OUTPUT: " << res << "\n\n"; 
					break;					
				}
			default: 
			{
				run = 0;
			}
		}
	}
}
	
int main()
{
	
	menu();
	return 0;
}