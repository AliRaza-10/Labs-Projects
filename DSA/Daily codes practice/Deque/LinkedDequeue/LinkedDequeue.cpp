#include <iostream>
#include "LinkedDequeue.h"
using namespace std;
LinkedDequeue::LinkedDequeue()
{
	back = NULL;
	front = nullptr;
}
bool LinkedDequeue::equeue(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->next = nullptr;
	if (back == nullptr)
	{
		back = temp;
		front = temp;
	}
	else
	{
		back->next = temp;
		back = temp;
	}
	return true;
}
bool LinkedDequeue::dequeue(int& val)
{
	if (back)
	{
		val = front->data;
		Node* temp = front;
		front = front->next;
		if (front == nullptr)
			back = nullptr;
		delete temp;
		temp = nullptr;
		return true;
	}
	else
		return false;
}
void LinkedDequeue::display()
{
	if (front)
	{
		Node* curr = front;
		while(curr)
		{
			cout << curr->data << "  ";
			curr = curr->next;
		}
		cout << endl;
	}
	else
		cout << "Queue is empty.\n";
}
