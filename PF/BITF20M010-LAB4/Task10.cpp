#include <iostream>
using namespace std;
int main()
{
	int num1, digit1, digit2, digit3, actual, reverse;
	cout << " Please enter a 3-digit positive integer number: ";
	cin >> num1;
	actual = num1;
	digit3 = num1 % 10;
	num1 = num1 / 10;
	digit2 = num1 % 10;
	num1 = num1 / 10;
	digit1 = num1 % 10;
	reverse = digit3;
	reverse = reverse * 10 + digit2;
	reverse = reverse * 10 + digit1;
	cout << " The actual input number " << actual;
	cout << " Its reverse is " << reverse;
	return 0;
}