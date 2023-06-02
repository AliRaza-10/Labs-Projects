#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "LinkedList.h"
using namespace std;
class LinkedList;
class Node {
	friend class LinkedList;
private:
	int data;
	Node* next;
};
#endif // !NODE_H
