#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::~LinkedList()
{
	while (head)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
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
	if (head!=NULL)
	{
		Node* curr = head;
		int i = 0;
		while (curr->next)
		{
			curr = curr->next;
		}
		Node* temp = new Node;
		temp->data = val;
		curr->next = temp;
		temp->next = NULL;
	}
	else
	{
		head = new Node;
		head->data = val;
		head->next = NULL;
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
	Node* prev = head;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	while (prev != curr)
	{
		if (prev->next == curr)
		{
			cout << curr->data << "  ";
			curr = prev;
			prev = head;
		}
		else
		{
			prev = prev->next;
		}
	}
	cout << prev->data;
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

bool LinkedList::removeLastNode(int& val)
{
	if (head)
	{
		if(head->next)
		{
			Node* curr = head;
			Node* prev = NULL;
			while (curr->next)
			{
				prev = curr;
				curr = curr->next;
			}	
			val = curr->data;
			delete curr;
			curr = nullptr;
			prev->next = NULL;
		}
		else
		{
			Node* curr = head;
			val = curr->data;
			delete curr;
			curr = NULL;
			head = NULL;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool LinkedList::removeSecondLastNode(int& val)
{
	if (countNodes() < 2)
	{
		return false;
	}
	else
	{
		Node* prev = NULL;
		Node* curr = head;
		Node* prev1 = NULL;
		while (curr->next)
		{
			prev1 = prev;
			prev = curr;
			curr = curr->next;
		}
		val = prev->data;
		prev1->next = curr;
		delete prev;
		prev = NULL;
		return true;
	}
}
bool LinkedList::sortedUniqueInsert(int val)
{
	Node* temp = head;
	Node* prev = NULL;
	Node* res = new Node;
	res->data = val;
	res->next = NULL;
	while (temp != NULL && temp->data < val)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp != NULL && temp->data == val)
		return false;
	else if (temp != NULL && temp->data < val){
		prev->next = res;
		res->next = temp;
	}
	else if (head == nullptr)
		head = res;
	else if (temp == NULL){
		prev->next = res;
	}
	
	return true;
}

int LinkedList::removeAll(int val)
{
	if (head == NULL)
		return 0;
	else
	{
		Node* curr = head;
		Node* prev = NULL;
		int count = 0;
		while (curr != NULL)
		{
			if (prev == NULL && curr->data == val)
			{
				count++;
				head = curr->next;
				delete curr;
				curr = head;
			}
			else if (curr->data == val)
			{
				count++;
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
		return count;
	}
}
int LinkedList::removerAlternates()
{
	if (head == NULL)
		return 0;
	else
	{
		int count1 = 1, count2 = 0;
		Node* prev = head;
		Node* curr = head->next;
		while (curr != NULL)
		{
			if (count1 == 1)
			{
				prev->next = curr->next;
				prev = prev->next;
				delete curr;
				curr = prev;
				count1 = 0;
				count2++;
			}
			else
			{
				curr = curr->next;
				count1 = 1;
			}
		}
		return count2;
	}
}
void LinkedList::insertTillN(int n)
{
	if (head)
	{
		while (head)
		{
			Node* temp = head->next;
			delete head;
			head = temp;
		}
	}
	head = new Node;
	int i = 1; 
	head->data = i;
	//head->next = NULL;
	i++;
	Node* curr = head;
	
	while (i <= n)
	{
		Node* temp = new Node;
		temp->data = i;
		temp->next = nullptr;
		curr->next = temp;
		curr = temp;
		i++;
	}
}
void LinkedList::unionLists(LinkedList& list1, LinkedList& list2)
{
	if (list1.head == nullptr && list2.head == nullptr)
		head = nullptr;
	else if (list1.head == nullptr)
		head = list2.head;
	else if (list2.head == nullptr)
		head = list1.head;
	else
	{
		Node* c1 = list1.head;
		Node* c2 = list2.head;
		Node* t1 = c1->next;
		Node* t2 = c2->next;
		if (c1->data == c2->data)
		{
			head = c1;
			c1 = t1;
			t1 = t1->next;
			c2 = t2;
			t2 = t2->next;
		}
		else if (c1->data > c2->data)
		{
			head = c2;
			c2 = t2;
			t2 = t2->next;
		}
		else
		{
			head = c1;
			c1 = t1;
			t1 = t1->next;
		}
		Node* temp = head;
		while (c1 != NULL && c2 != NULL)
		{
			if (c1->data == c2->data)
			{
				temp->next = c1;
				c1 = t1;
				if(t1)
					t1 = t1->next;
				c2 = t2;
				if(t2)
					t2 = t2->next;
				temp = temp->next;
			}
			else if(c1->data > c2->data)
			{
				temp->next = c2;
				temp = temp->next;
				c2 = t2;
				if(t2)
					t2 = t2->next;				
			}
			else
			{
				temp->next = c1;
				c1 = t1;
				if(t1)
					t1 = t1->next;
				temp = temp->next;
			}

		}
		if (c1 != NULL)
		{
			temp->next = c1;
		}
		else
			temp->next = c2;
	}
	list1.head = nullptr;
	list2.head = nullptr;
}
int LinkedList::countEvens()
{
	return countEvens(head);
}