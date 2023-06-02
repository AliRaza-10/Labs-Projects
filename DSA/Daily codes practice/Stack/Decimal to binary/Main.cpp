#include <iostream>
#include "Stack.h"
#include <iomanip>
using namespace std;
void decimalToBinary(int num)
{
	Stack stk(ceil(log2(num + 1)));
	cout << num << "   : ";
	for (int i = num; i > 0; i = i / 2)
	{
		stk.push(num % 2);
		num = num / 2;
	}
	//cout << "\nThe value in binary !!!!\n";
	int size = stk.getMaxSize();
	for (int j = 0; j < size; j++)
	{
		int v;
		stk.pop(v);
		cout << v << " ";
	}
	cout << endl;
}
int sumOdd(int num)
{
	if (num >= -9 && num <= 9)
	{
		int temp = num % 2;
		if (temp == 1)
		{
			return (num%10);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		int temp = num % 2;
		if (temp == 1)
		{
			return (num%10) + sumOdd(num/10);
		}
		else
		{
			return sumOdd(num / 10);
		}
	}
}
int sumEven(int num)
{
	if (num >= -9 && num <= 9)
	{
		int temp = num % 2;
		if (temp == 0)
		{
			return (num % 10);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		int temp = num % 2;
		if (temp == 0)
		{
			return (num % 10) + sumEven(num / 10);
		}
		else
		{
			return sumEven(num / 10);
		}
	}
}
int main()
{
	/*decimalToBinary(1);
	decimalToBinary(2);
	decimalToBinary(3);
	decimalToBinary(4);
	decimalToBinary(5);
	decimalToBinary(6);
	decimalToBinary(7);
	decimalToBinary(8);
	decimalToBinary(9);
	decimalToBinary(10);*/
	//cout << sumOdd(12356) << endl;
	//cout << sumEven(12356) << endl;
	cout << (-1 % 2);
	return 0;
}