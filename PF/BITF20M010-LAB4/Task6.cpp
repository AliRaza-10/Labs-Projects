#include <iostream>
using namespace std;
int main()
{
	int num1;
	cout << " Please enter an integer number : ";
	cin >> num1;
	if (num1 % 2 == 0)
	{
		cout << "  The integer is even : ";
	}
	if (num1 % 2 != 0)
	{
		cout << " The interger is odd";
	}

	return 0;
}