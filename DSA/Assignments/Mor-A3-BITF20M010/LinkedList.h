#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList {
private:
	Node* head;
public:
	LinkedList(); // Default constructor
	~LinkedList(); // Destructor
	bool insert(int val);//insert value at start
	bool search(int);//searching the key value
	int countNodes();
	void display();//display the linked list
	bool remove(int val);//remove first occurance of the key
	void sort();//selection sort
	void reverse();//reverse the linked list
	void emptyLinkedList();//empty the linked list
};
#endif // !LINKEDLIST_H
