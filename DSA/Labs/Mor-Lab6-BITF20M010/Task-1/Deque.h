#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
using namespace std;
class Deque
{
private:
	int* arr;
	int currSize, maxSize;
	int front, back;
public:
	Deque(int n);
	~Deque();
	bool isEmpty();
	bool isFull();
	void display();
	void makeEmpty();
	bool insertAtFront(int val);
	bool insertAtBack(int val);
	bool removeFromFront(int& val);
	bool removeFromBack(int& val);
};
#endif // !DEQUE_H
