#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstring>
using namespace std;
class Stack
{
private:
	int* stk;
	int maxSize;
	int top;
public:
	Stack();
	Stack(int);
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(int);
	bool pop(int&);
	bool getTop(int&);
};

#endif // !STACK_H
