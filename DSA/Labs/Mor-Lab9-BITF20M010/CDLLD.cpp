#include <iostream>
#include "CDLLD.h"
using namespace std;
CDLLD::CDLLD()
{
	head.next = &head;
	head.prev = &head;
}
CDLLD::~CDLLD()
{
	DNode* temp = head.next;
	DNode* curr = temp;
	while (temp != &head)
	{
		curr->next->prev = &head;
		head.next = curr->next;
		temp = temp->next;
		delete curr;
		curr = temp;
	}
	head.next = &head;
	head.prev = &head;
}
CDLLD::CDLLD(const CDLLD& orig)
{
	if (orig.head.next == &orig.head)
	{
		head.next = orig.head.next;
		head.prev = orig.head.next;
	}
	else
	{
		DNode *t1 = orig.head.next;
		DNode* t2 = &head;
		while (t1 != &orig.head)
		{
			t2->next = new DNode;
			t2->next->prev = t2;
			t2 = t2->next;
			t2->data = t1->data;
			t1 = t1->next;
		}
		t1->next = &head;
		head.prev = t2;
	}
}
CDLLD& CDLLD::operator=(const CDLLD& rhs)
{
	if (this != &rhs)
	{
		DNode* temp = head.next;
		DNode* curr = temp;
		while (temp != &head)
		{
			//curr = temp;
			curr->next->prev = &head;
			head.next = curr->next;
			temp = temp->next;
			delete curr;
			curr = temp;
		}
		DNode* t1 = rhs.head.next;
		DNode* t2 = &head;
		while (t1 != &rhs.head)
		{
			t2->next = new DNode;
			t2->next->prev = t2;
			t2 = t2->next;
			t2->data = t1->data;
			t1 = t1->next;
		}
		t1->next = &head;
		head.prev = t2;
	}
	return *this;
}
void CDLLD::display()
{
	DNode* curr = head.next;
	if (curr != &head)
	{
		cout << "list contain following elements :  ";
		while (curr != &head)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	else
		cout << "List is  empty.\n";
}
bool CDLLD::insertAtStart(int val)
{
	DNode* temp = new DNode;
	temp->data = val;
	head.next->prev = temp;
	temp->next = head.next;
	head.next = temp;
	temp->prev = &head;
	return true;
}
bool CDLLD::insertAtEnd(int val)
{
	DNode* temp = new DNode;
	temp->data = val;
	temp->prev = head.prev;
	temp->next = &head;
	head.prev->next = temp;
	head.prev = temp;
	return true;
}
bool CDLLD::sortedInsert(int val)
{
	DNode* temp = new DNode;
	temp->data = val;
	DNode* curr = head.next;
	while (curr != &head && curr->data < val)
		curr = curr->next;
	temp->next = curr;
	temp->prev = curr->prev;
	curr->prev->next = temp;
	curr->prev = temp;
	return true;
}
bool CDLLD::sortedRemove(int val)
{
	DNode* curr = head.next;
	while (curr != &head && curr->data < val)
		curr = curr->next;
	if (curr != &head && curr->data == val)
	{
		curr->next->prev = curr->prev;
		curr->prev->next = curr->next;
		delete curr;
		curr = nullptr;
		return true;
	}
	else
		return false;
}
bool CDLLD::uniqueInsert(int val)
{
	DNode* curr = head.next;
	while (curr != &head && curr->data != val)
	{
		curr = curr->next;
	}
	
	if (curr == &head)
	{
		DNode* temp = new DNode;
		temp->data = val;
		temp->prev = curr->prev;
		curr->prev->next = temp;
		temp->next = curr;
		curr->prev = temp;
		return true;
	}
	else
	{
		return false;
	}
}

bool CDLLD::search(int val)
{
	DNode* curr = head.next;
	while (curr != &head && curr->data != val)
	{
		curr = curr->next;
	}
	if (curr != &head)
		return true;
	else
		return false;
}
int CDLLD::countNodes()
{
	int count = 0;
	DNode* t1 = head.next;
	while (t1 != &head)
	{
		count++;
		t1 = t1->next;
	}
	return count;
}
bool CDLLD::removeLastNode(int& val)
{
	if (head.prev == &head && head.next == &head)
		return false;
	else
	{
		DNode* t1 = head.prev;
		head.prev = t1->prev;
		t1->prev->next = &head;
		val = t1->data;
		delete t1;
		t1 = nullptr;
		return true;
	}
}

void CDLLD::combine(CDLLD& list1, CDLLD& list2)
{
	list1.head.prev->next = list2.head.next;
	list2.head.next->prev = list1.head.prev;
	head.next = list1.head.next;
	list1.head.next->prev = &head;
	head.prev = list2.head.prev;
	list2.head.prev->next = &head;

	list1.head.next = &list1.head;
	list1.head.prev = &list1.head;
	list2.head.next = &list2.head;
	list2.head.prev = &list2.head;
}

void CDLLD::shuffleMerge(CDLLD& list1, CDLLD& list2)
{

	DNode* curr1 = list1.head.next;
	DNode* curr2 = list2.head.next;
	DNode* t1 = curr1->next;
	DNode* t2 = curr2->next;
	while (t1 != &list1.head && t2 != &list2.head)
	{
		curr1->next = curr2;
		curr2->prev = curr1;
		curr2->next = t1;
		t1->prev = curr2;
		curr1 = t1;
		curr2 = t2;
		
		t1 = t1->next;
		t2 = t2->next;
		if (t1 == &list1.head && t2 == &list2.head)
		{
			curr1->next = curr2;
			curr2->prev = curr1;
		}
		/*curr1 = t1;
		curr2 = t2;
		t2 = t2->next;
		t1 = t1->next;
		curr1->next = curr2;
		curr2->prev = curr1;
		curr2->next = t1;
		t1->prev = curr2;*/

	}
	if (list1.head.next == &list1.head && list2.head.next == &list2.head)
	{
		head.next = &head;
		head.prev = &head;
	}
	else
	{
		
		head.next = t1->next;
		t1->next->prev = &head;
		curr2->next = &head;
		head.prev = curr2;

		/*head.next = t1->next;
		t1->next->prev = &head;
		curr2->next = &head;
		head.prev = curr2;*/

		list1.head.next = &list1.head;
		list1.head.prev = &list1.head;
		list2.head.next = &list2.head;
		list2.head.prev = &list2.head;
	}
}

void CDLLD::splitList(CDLLD& leftHalf, CDLLD& rightHalf)
{
	int count = countNodes();
	//cout << count << endl;
	int l1;
	if (count % 2 == 1)
	{
		l1 = (count + 1) / 2;
	}
	else
	{
		l1 = count / 2;
	}
	DNode* curr = head.next;
	int num = 0;
	while (num < l1)
	{
		curr = curr->next;
		num++;
	}
	leftHalf.head.next = head.next;
	head.next->prev = &leftHalf.head;
	curr->prev->next = &leftHalf.head;
	leftHalf.head.prev = curr->prev;

	rightHalf.head.next = curr;
	curr->prev = &rightHalf.head;
	head.prev->next = &rightHalf.head;
	rightHalf.head.prev = head.prev;

	head.next = &head;
	head.prev = &head;
}
bool CDLLD::isSorted() const
{
	DNode* temp = head.next;
	while (temp != &head)
	{
		if (temp->next!= &head && temp->data > temp->next->data)
		{
			return false;
		}
		else
		{
			temp = temp->next;
		}
	}
	return true;
}
bool CDLLD::removeSecondLastNode(int& val)
{
	if (head.next != head.prev)
	{
		DNode* t1 = head.prev->prev;
		if (head.next == t1)
		{
			head.next = t1->next;
			t1->next->prev = &head;
		}
		else
		{
			DNode* t2 = t1->prev;
			t1->next->prev = t2;
			t2->next = t1->next;
		}
		val = t1->data;
		delete t1;
		t1 = NULL;
		return true;
	}
	else
	{
		return false;
	}
}
bool CDLLD::removeKthNode(int k, int& val)
{
	int tot = countNodes();
	if (tot == 0 || tot < k || k == 0)
		return false;
	else
	{
		DNode* t1 = head.next;
		DNode* t2 = t1;
		int count = 0;
		while (count < k)
		{
			count++;
			t2 = t1;
			t1 = t1->next;
		}
		t2->prev->next = t2->next;
		t1->prev = t2->prev;
		val = t2->data;
		delete t2;
		t2 = NULL;
		return true;
	}
}
bool CDLLD::sortList()
{
	
	DNode* temp = head.next;
	DNode* curr = head.next;
	while (temp != &head)
	{
		DNode* minNode = temp;
		curr = temp->next;
		while (curr != &head)
		{
			if (curr->data < minNode->data)
			{
				minNode = curr;
			}
			curr = curr->next;
		}
		if (minNode->data < temp->data)
		{
			minNode->next->prev = minNode->prev;
			minNode->prev->next = minNode->next;
			temp->prev->next = minNode;
			minNode->prev = temp->prev;
			minNode->next = temp;
			temp->prev = minNode;
		}
		else
			temp = temp->next;
	}
	cout << endl;
	return true;


}

bool CDLLD::merge(CDLLD& list1, CDLLD& list2)
{
	if (list1.isSorted() && list2.isSorted())
	{
		DNode* c1 = list1.head.next;
		DNode* c2 = list2.head.next;
		DNode* p = &head;
		DNode* curr1 = &list1.head;
		DNode* curr2 = &list2.head;
		while (c1 != &list1.head && c2 != &list2.head)
		{
			if (c1->data < c2->data)
			{
				if (head.next == &head)
				{
					head.next = c1;
					c1->prev = &head;
					p = c1;
					c1 = c1->next;
				}
				else
				{
					p->next = c1;
					c1->prev = p;
					p = c1;
					c1 = c1->next;
				}
			}
			else if (c1->data > c2->data)
			{
				if (head.next == &head)
				{
					head.next = c2;
					c2->prev = &head;
					p = c2;
					c2 = c2->next;
				}
				else
				{
					p->next = c2;
					c2->prev = p;
					p = c2;
					c2 = c2->next;
				}
			}
			else
			{
				if (head.next == &head)
				{
					head.next = c2;
					c2->prev = &head;
					p = c2;
					c1 = c1->next;
					c2 = c2->next;
				}
				else
				{
					p->next = c2;
					c2->prev = p;
					p = c2;
					c2 = c2->next;
					c1 = c1->next;	
				}
			}
		}
		while (c1 != &list1.head)
		{
			p->next = c1;
			c1->prev = p;
			p = c1;
			c1 = c1->next;
		}
		while (c2 != &list2.head)
		{
			p->next = c2;
			c2->prev = p;
			p = c2;
			c2 = c2->next;
		}
		p->next = &head;

		head.prev = p;
		
		list1.head.next = &list1.head;
		list1.head.prev = &list1.head;
		list2.head.next = &list2.head;
		list2.head.prev = &list2.head;
		return true;
	}
	else
		return false;

}
void CDLLD::mergeSort()
{
	CDLLD l1,l2;
	if (head.next != head.prev)
	{
		splitList(l1, l2);
		l1.mergeSort();
		l2.mergeSort();
		merge(l1, l2);
	}
}
void CDLLD::reverse()
{
	DNode* temp = head.next;
	DNode* curr = &head;
	DNode* last = head.next;
	while (temp != &head)
	{
		curr = temp->next;
		temp->next = temp->prev;
		temp->prev = curr;
		temp = curr;
	}
	head.next = temp->prev;
	head.prev = last;
	cout << head.prev->data << endl;
	cout << head.next->data << endl;
	cout << head.prev->prev->data << endl;
}
void CDLLD::insertionSort()
{
	DNode* temp = head.next;
	DNode* curr = temp->next;
	while (curr != &head)
	{
		int count = 0;
		temp = curr->prev;
		DNode* key = curr;
		DNode* currPrev = curr->prev;
		while (temp != &head && temp->data > key->data)
		{
			count = 1;
			temp = temp->prev;
		}
		if (count == 1)
		{
			curr = curr->next;
			currPrev->next = curr;
			curr->prev = currPrev;
			key->next = temp->next;
			temp->next->prev = key;
			temp->next = key;	
			key->prev = temp;
		}
		else
		{
			curr = curr->next;
		}
	}
}
