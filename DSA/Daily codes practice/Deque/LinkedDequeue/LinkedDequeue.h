#ifndef LINKEDDEQUEUE_H
#define LINKEDDEQUEUE_H
#include <iostream>
#include "Node.h"
using namespace std;
class LinkedDequeue
{
private:
	Node* back;
	Node* front;
public:
	LinkedDequeue();
	//~LinkedDequeue();
	bool equeue(int val);
	bool dequeue(int& val);
	void display();
};
#endif // !LINKEDDEQUEUE_H
