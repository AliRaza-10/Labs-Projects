#include<iostream>
using namespace std;
int main()
{
	int number, digit1, digit2, digit3, sum;
	cout << " please enter three digit integer : ";
	cin >> number;
	digit3 = number % 10;
	digit1 = number / 10;
	digit1 = digit1 / 10;
	digit2 = number / 10;
	digit2 = digit2 % 10;
	sum = digit1 + digit2 + digit3;
	cout << " sum of digits are : " << sum << endl;

	return 0;
}