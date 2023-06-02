#include <iostream>
#include "LinkedStack.h"
using namespace std;
LinkedStack::LinkedStack()
{
	top = nullptr;
}
bool LinkedStack::push(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->next = top;
	top = temp;
	return true;
}
bool LinkedStack::pop(int& val)
{
	if (top)
	{
		val = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
		temp = nullptr;
		return true;
	}
	else
		return false;
}
