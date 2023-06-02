#include<iostream>
using namespace std;
int main()
{
	int number1, number2;
	cout << "Please enter the first integer: ";
	cin >> number1;
	cout << " Please enter the second integer: ";
	cin >> number2;
	if (number1 > number2)
	{
		cout << "The larger number is :" << number1 << endl;
	}
	if (number2 > number1)
	{
		cout << "The larger number is :" << number2 << endl;
	}
	return 0;
}