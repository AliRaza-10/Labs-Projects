// Muhammad Waqas Ud Din
// BITF20M013
// IT-Morning
#include <iostream>
#include "Deque.h"
using namespace std;
Deque::Deque(int n)
{
	arr = new int[n];
	currSize = 0;
	front = 0;
	back = -1;
	maxSize = n;
}
Deque::~Deque()
{
	if (arr) {
		delete[]arr;
		arr = nullptr;
	}
}
bool Deque::isEmpty()
{
	if (currSize == 0)
		return true;
	else
		return false;
}
bool Deque::isFull()
{
	if (currSize == maxSize)
		return true;
	else
		return false;
}
void Deque::display()
{
	int i;
	if (front > back)
	{
		i = (front + 1) % maxSize;
	}
	for (i = front; i <= back; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Deque::makeEmpty()
{
	currSize = 0;
	front = 0;
	back = -1;
}
bool Deque::insertAtFront(int val)
{
	if (!isFull()) {
		front = (front - 1) % maxSize;
		if (front == 0)
		{
			front = back;
		}
		arr[front] = val;
		currSize++;
		return true;
	}
	else
		return false;
}
bool Deque::insertAtBack(int val)
{
	if (isFull())
		return false;
	else {
		back = (back + 1) % maxSize;
		arr[back] = val;
		currSize++;
		return true;
	}
}
bool Deque::removeFromFront(int& val)
{
	if (isEmpty())
		return false;
	else{
		val = arr[front];
		front = (front + 1) % maxSize;
		currSize--;
		return true;
	}
}
bool Deque::removeFromBack(int& val)
{
	if (!isEmpty()){
		val = arr[back];
		back = (back - 1)%maxSize;
		if (back == -1)
			back = 0;
		currSize--;
		return true;
	}
	else
		return false;
}