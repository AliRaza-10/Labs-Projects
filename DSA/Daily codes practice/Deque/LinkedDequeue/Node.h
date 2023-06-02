#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "LinkedDequeue.h"
using namespace std;
class Node
{
	friend class LinkedDequeue;
private:
	int data;
	Node* next;
};
#endif // !NODE_H
