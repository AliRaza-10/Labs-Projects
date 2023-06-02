#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::~LinkedList()
{
	//cout << "Destructor Call." << this << endl;
	//int i = 1;
	while (head)
	{
		//cout << "Destructor Call for " << i << " time : " << " \n";
		Node* temp = head->next;
		delete head;
		head = temp;
		//i++;
	}
}
LinkedList::LinkedList(const LinkedList& orig)
{
	if (orig.head == NULL)
		head = NULL;
	else
	{
		head = new Node;
		head->data = (orig.head)->data;
		Node* t1 = (orig.head)->next;
		Node* t2 = head;
		while (t1 != NULL)
		{
			t2->next = new Node;
			t2 = t2->next;
			t2->data = t1->data;
			t1 = t1->next;
		}
		t2->next = NULL;
	}
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	if (this == &rhs)
		return *this;
	else
	{
		if (head != NULL)
		{
			Node* temp = head;
			while (temp)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
		}
		head = new Node;
		if (rhs.head->next)
		{
			head->data = rhs.head->data;
			Node* t1 = rhs.head->next;
			Node* t2 = head;
			while (t1)
			{
				t2->next = new Node;
				t2 = t2->next;
				t2->data = t1->data;
				t1 = t1->next;
			}
			t2->next = NULL;
		}
		else
			head = NULL;
		return *this;
	}
}
void LinkedList::display()
{
	if (head)
	{
		Node* curr = head;
		while (curr)
		{
			cout << curr->data << "  ";
			curr = curr->next;
		}
		cout << endl;
	}
	else
		cout << "List is Empty.\n";
}
bool LinkedList::insertAtStart(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->next = head;
	head = temp;
	return true;
}
bool LinkedList::insertAtEnd(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->next = nullptr;
	Node* curr = head;
	if (head)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = temp;
	}
	else
	{
		head = temp;
	}
	return true;
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
int LinkedList::findMax()
{
	if (head)
	{
		Node* curr = head->next;
		int max = head->data;
		while (curr)
		{
			if (curr->data > max)
				max = curr->data;
			curr = curr->next;
		}
		return max;
	}
	else
	{
		return -999;
	}
}
void LinkedList::displayReverse()
{
	Node* curr = head;
	Node* temp = head;
	while (curr->next)
		curr = curr->next;
	cout << curr->data << "  ";
	while (temp != curr)
	{
		if (temp->next == curr)
		{
			cout << temp->data << "  ";
			curr = temp;
			temp = head;
		}
		else
		{
			temp = temp->next;
		}
	}

	/*Node* curr = head;
	Node* temp = head;
	while (curr->next)
		curr = curr->next;
	while (temp != curr)
	{
		if (curr != temp->next)
		{
			temp = temp->next;
		}
		else
		{
			
		}
	}
	cout << temp->data;*/

	cout << endl;
}

bool LinkedList::unsortedRemove(int val)
{
	Node* curr = head;
	Node* prev = NULL;
	while (curr != NULL && curr->data != val)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		return false;
	else if (curr == head)
		head = head->next;
	else
		prev->next = curr->next;
	delete curr;
	curr = nullptr;
	return true;
}

void LinkedList::recDisplay() const
{
	this->recDisplay(head);
	cout << endl;
}
int LinkedList::findMaxRec()
{
	if (head)
		return findMaxRec(head);
	else
		return -999;
}
int LinkedList::countPositiveRec()
{
	int count = 0;
	count = countPositiveRec(head);
	return count;
}

//Lab 8
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

//Task 1
bool LinkedList::removeKthNode(int k, int& val)
{
	if (head)
	{
		Node* prev = NULL;
		Node* curr = head;
		int count = 1;
		while (curr != NULL && count < k)
		{
			prev = curr;
			curr = curr->next;
			count++;
		}
		if (count < k)// less elements
			return false;
		else if (curr == head)//ist index
			head = head->next;
		else
			prev->next = curr->next;
		val = curr->data;
		delete curr;
		curr = NULL;
		return true;
	}
	else
		return false;
}

//Task 2
void LinkedList::combine(LinkedList& list1, LinkedList& list2)
{
	if (list1.head == NULL && list2.head == NULL)
	{
		head = NULL;
	}
	else if(list1.head == NULL)
	{
		head = list2.head;
		list2.head = NULL;
	}
	else if (list2.head == NULL)
	{
		head = list1.head;
		list1.head = NULL;
	}
	else
	{
		head = list1.head;
		Node* curr = head;
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = list2.head;
		list1.head = NULL;
		list2.head = NULL;
	}
}

//Task 3
void LinkedList::shuffleMerge(LinkedList& list1, LinkedList& list2)
{
	if (list1.head == NULL && list2.head == NULL)
	{
		head = NULL;
	}
	else if (list1.head == NULL)
	{
		head = list2.head;
		list2.head = NULL;
	}
	else if (list2.head == NULL)
	{
		head = list1.head;
		list1.head = NULL;
	}
	else
	{
		/*head = list1.head;
		Node* t1 = list1.head;
		Node* t2 = list2.head;
		Node* curr1 = list1.head;
		Node* curr2 = list2.head;
		while (curr1 != NULL && curr2 != NULL)
		{
			t1 = curr1->next;
			curr1->next = curr2;
			curr1 = t1;
			t2 = curr2->next;
			curr2->next = curr1;
			curr2 = t2;
		}
		list1.head = nullptr;
		list2.head = nullptr;*/

		/*head = list1.head;
		Node* t1 = list1.head->next;
		Node* t2 = list2.head->next;
		Node* curr1 = list1.head;
		Node* curr2 = list2.head;
		while (t1 != NULL && t2 != NULL)
		{
			curr1->next = curr2;
			curr1 = t1;
			curr2->next = curr1;
			curr2 = t2;
			t1 = t1->next;
			t2 = t2->next;
		}
		curr1->next = curr2;
		curr2->next = t1;
		list1.head = nullptr;
		list2.head = nullptr;*/

		head = list1.head;
		Node* t1 = list1.head->next;
		Node* t2 = list2.head->next;
		Node* curr1 = list1.head;
		Node* curr2 = list2.head;
		while ((t1 != NULL) && (t2 != NULL))
		{
			curr1->next = curr2;
			curr1 = t1;
			curr2->next = t1;
			curr2 = t2;
			t1 = t1->next;
			t2 = t2->next;
		}
		curr1->next = curr2;
		curr2->next = t1;
		list1.head = nullptr;
		list2.head = nullptr;

	}
}