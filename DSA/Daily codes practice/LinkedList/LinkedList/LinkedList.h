#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList
{
private:
	Node* head;
	void recDisplay(Node* temp) const
	{
		if (temp)
		{
			cout << temp->data << " ";
			recDisplay(temp->next);
		}
	}
	int findMaxRec(Node* temp)
	{
		if (temp->next)
		{
			int max = findMaxRec(temp->next);
			if (temp->data > max)
				return temp->data;
			else
				return max;
		}
		else
			return temp->data;
	}
	int countPositiveRec(Node* temp)
	{
		if (temp)
		{
			if (temp->data > 0)
			{
				//int count = countPositiveRec(temp->next);
				return (1 + countPositiveRec(temp->next));
			}
			else
				return countPositiveRec(temp->next);
		}
		else
			return 0;
	}

public:
	LinkedList();
	~LinkedList();
	void display();
	LinkedList(const LinkedList& orig);
	const LinkedList& operator=(const LinkedList& rhs);
	bool insertAtStart(int);
	bool insertAtEnd(int);
	bool search(int);
	int findMax();
	void displayReverse();
	void recDisplay() const;
	int findMaxRec();
	int countPositiveRec();
	bool unsortedRemove(int val);
	//Lab 8
	int countNodes();
	bool removeKthNode(int k, int& val);
	void combine(LinkedList& list1, LinkedList& list2);
	void shuffleMerge(LinkedList& list1, LinkedList& list2);
};
#endif // !LINKEDLIST_H
