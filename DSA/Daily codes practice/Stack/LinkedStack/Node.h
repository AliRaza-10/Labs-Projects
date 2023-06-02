#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "LinkedStack.h"
using namespace std;
class Node
{
	friend class LinkedStack;
private:
	int data;
	Node* next;
};
#endif // !NODE_H
