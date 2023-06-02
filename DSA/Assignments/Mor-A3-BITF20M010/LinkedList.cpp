// Muhammad Waqas Ud din
// BITF20M013
// IT Morning
#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}
bool LinkedList::search(int key)
{
	Node* curr = head;
	if (head)
	{
		while (curr)
		{
			if (curr->data == key)
				return true;
			else
				curr = curr->next;
		}
	}
	return false;
}
bool LinkedList::insert(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->next = head;
	head = temp;
	return true;
}
int LinkedList::countNodes()
{
	Node* temp = head;
	int count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void LinkedList::display()
{
	if (head)
	{
		Node* temp = head;
		cout << "The list contains following " << countNodes() << " elements: ";
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	else
		cout << "List is empty.\n";
}
bool LinkedList::remove(int val)
{
	if (head)
	{
		Node* curr = head;
		Node* prev = nullptr;
		while (curr != nullptr && curr->data != val)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev == nullptr)//element found at first node
			head = head->next;
		else if (curr == nullptr)//element not found
			return false;
		else
			prev->next = curr->next;
		delete curr;
		curr = nullptr;
		return true;
	}
	else
		return false;
}
void LinkedList::sort()
{
	if (head != NULL && head->next != NULL)
	{
		Node* temp = head; //this pointer will control outer loop
		Node* prevTemp = NULL;//this pointer is used to store position of last value that has been sorted
		while (temp)
		{
			Node* minNode = temp;//this pointer will store the address off minimum node in list		 
			Node* curr = temp->next;//this pointer will control the inner loop	 
			Node* prev = minNode;// this pointer is used to store adress of a node before minimum node
			Node* prevCurr = temp;//this will store the adress of node before the curr node
			while (curr)
			{
				if (curr->data < minNode->data)
				{
					prev = prevCurr;
					minNode = curr;
				}
				prevCurr = prevCurr->next;
				curr = curr->next;
			}
			if (temp != minNode && prevTemp == nullptr)//to store the head
			{
				prev->next = minNode->next;
				head = minNode;
				prevTemp = minNode;
				minNode->next = temp;
			}
			else if (temp != minNode)//replacing the nodes 
			{
				prev->next = minNode->next;
				prevTemp->next = minNode;
				minNode->next = temp;
				prevTemp = minNode;
			}
			else if (temp == minNode)//if there is a number already sorted
			{
				prevTemp = temp;
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}

}
void LinkedList::reverse()
{
	if (head)
	{
		Node* temp = nullptr;
		Node* prev = nullptr;
		Node* curr = head;
		while (curr)
		{
			temp = curr;
			curr = curr->next;
			temp->next = prev;
			prev = temp;
		}
		head = temp;
	}
}
void LinkedList::emptyLinkedList()
{
	Node* temp = head;
	while (temp)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}
