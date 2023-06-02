#include<iostream>
using namespace std;
int main()
{
	int  a, b, tmp;
	cout << " Please enter fisrt integer: ";
	cin >> a;

	cout << " Please enter the second integer: ";
	cin >> b;

	cout << " The integers are " << a << " and " << b << endl;
	cout << " After swapping the number are : " << endl;

	tmp = a;
	a = b;
	b = tmp;

	cout << " First integer is: " << a << endl;
	cout << " Second integer is: " << b;

	return 0;

}