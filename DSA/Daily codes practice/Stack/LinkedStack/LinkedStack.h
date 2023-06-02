#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include "Node.h"
using namespace std;
class LinkedStack
{
private:
	Node* top;
public:
	LinkedStack();
	bool push(int);
	bool pop(int&);
};
#endif // !LINKEDSTACK_H
