// Muhammad Waqas Ud Din
// BITF20M013
// IT MORNING
#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;
Stack::Stack()
{
	stk = nullptr;
	top = -1;
	maxSize = 0;
}
Stack::Stack(int size)
{
	stk = new int[size];
	maxSize = size;
	top = -1;
}
Stack::~Stack()
{
	if (stk) {
		delete []stk;
		stk = nullptr;
	}
}
bool Stack::isEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}
bool Stack::isFull() const
{
	if (top == maxSize - 1)
		return true;
	else
		return false;
}
bool Stack::push(int val)
{
	if (isFull())
		return false;
	else
	{
		top++;
		stk[top] = val;
		return true;
	}
}
bool Stack::pop(int& val)
{
	if (isEmpty())
		return false;
	else
	{
		val = stk[top];
		top--;
		return true;
	}
}
bool Stack::getTop(int& val)
{
	if (isEmpty())
		return false;
	else
	{
		val = stk[top];
		return true;
	}
}
