// Muhammad Waqas Ud Din
// BITF20M013
// IT MORNING
#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;
const int SIZE = 40;
void addingLargeNumbers(const char* str1, const char* str2)
{
	int size1, size2, size3;//to store sizes of three stacks
	size1 = strlen(str1);
	size2 = strlen(str2);
	size3 = size1;
	if (size3 < size2)
		size3 = size2;
	if (size1 == size2)
		size3 += 1;
	Stack stack1(size1);
	Stack stack2(size2);
	Stack resultStack(size3);
	for (int i = 0; i < size1; i++) {
		stack1.push(str1[i]);
	}
	for (int i = 0; i < size2; i++) {
		stack2.push(str2[i]);
	}
	int temp1=0, temp2=0, carry = 0;
	while (!stack1.isEmpty() || !stack2.isEmpty()){
		temp1 = '0', temp2 = '0';
		stack1.pop(temp1);
		stack2.pop(temp2);
		int totSum = (temp1 - '0') + (temp2 - '0') + carry;
		carry = totSum / 10;
		totSum = totSum % 10;
		resultStack.push(totSum);	
	}
	if (carry != 0)
	{
		resultStack.push(carry);
	}
	for (int i = 0; i<size3; i++) {
		if (resultStack.pop(temp1))
			cout << temp1;
	}
}
int main()
{
	char str1[SIZE + 1];
	char str2[SIZE + 1];
	cout << "Enter 1st Number (Maxsize 40) : ";
	cin >> str1;
	cout << "Enter 2nd Number (Maxsize 40) : ";
	cin >> str2;
	addingLargeNumbers(str1, str2);
}
