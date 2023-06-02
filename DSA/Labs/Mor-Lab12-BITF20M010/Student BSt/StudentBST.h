#ifndef STUDENTBST_H
#define STUDENTBST_H
#include <iostream>
#include <string>
#include <iomanip>
#include "StudentNode.h"
using namespace std;
class StudentBST
{
private:
	StudentNode* root; // Pointer to the root node of the BST
	void inOrder(StudentNode* s)
	{
		if (s != NULL)
		{
			inOrder(s->left);
			cout << "\nName : "<<setw(7) << s->name << " | ";
			cout << "CGPA : " << setw(4) << s->cgpa << " | ";
			cout << "Roll Number : " << setw(4) << s->rollNo << "\n\n";
			inOrder(s->right);
		}
	}
	void destroy(StudentNode* s)
	{
		if (s != nullptr)
		{
			destroy(s->left);
			destroy(s->right);
			delete s;
			s = nullptr;
		}
	}
	void display(StudentNode* st)
	{
		cout << "Name : " << st->name << endl;
		cout << "Roll Number : " << st->rollNo << endl;
		cout << "CGPA : " << st->rollNo << endl << endl;
	}
	void helperInRangeDisplay(StudentNode* st,int start,int end)
	{
		if (st != NULL)
		{	
			if (st->rollNo >= start && st->rollNo <= end)
			{
				helperInRangeDisplay(st->left, start, end);
				display(st);
				helperInRangeDisplay(st->right, start, end);
			}
			else if (st->rollNo > end && st->left!=NULL)
			{
				helperInRangeDisplay(st->left, start, end);
			}
		}
	}
public:
	StudentBST(); // Default constructor
	~StudentBST();
	bool insert(int rn, string n, double c);
	bool search(int rn);
	void inOrder();
	bool remove(int rn);
	void displayInRange(int rollNoStart, int rollNoEnd);
};
#endif // !STUDENTBST_H
