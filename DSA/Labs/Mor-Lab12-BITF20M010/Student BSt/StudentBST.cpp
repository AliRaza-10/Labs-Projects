#include <iostream>
#include <string>
#include "StudentBST.h"
using namespace std;
StudentBST::StudentBST()
{
	root = NULL;
}
StudentBST::~StudentBST()
{
	destroy(root);
}
bool StudentBST::insert(int rn, string n, double c)
{
	StudentNode* curr = root;
	StudentNode* prev = NULL;
	while (curr != nullptr)
	{
		prev = curr;
		if (curr->rollNo == rn)
			return false;
		else if (curr->rollNo > rn)
			curr = curr->left;
		else
			curr = curr->right;
	}
	StudentNode* temp = new StudentNode;
	temp->rollNo = rn;
	temp->name = n;
	temp->cgpa = c;
	temp->left = nullptr;
	temp->right = nullptr;
	if (prev == NULL)
		root = temp;
	else
	{
		if (prev->rollNo > rn)
			prev->left = temp;
		else
			prev->right = temp;
	}
	return true;
}
bool StudentBST::search(int rn)
{
	StudentNode* curr = root;
	//StudentNode* prev = NULL;
	while (curr != nullptr && curr->rollNo!=rn)
	{
		if (curr->rollNo > rn)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr == NULL)
	{
		cout << "\nData Not found.\n\n";
		return false;
	}
	else
	{
		cout << "\nName : " << setw(10) << curr->name << " | ";
		cout << "CGPA : " <<setw(4) << curr->cgpa << " | ";
		cout << "Roll Number : " << setw(4) << curr->rollNo << "\n\n";
		return true;
	}
}
void StudentBST::inOrder()
{
	if (root == NULL)
		cout << "Student BST is empty.\n";
	inOrder(root);
}
bool StudentBST::remove(int rn)
{
	StudentNode* curr = root;
	StudentNode* prev = NULL;
	while (curr != nullptr && curr->rollNo != rn)
	{
		prev = curr;
		if (curr->rollNo > rn)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr == NULL)
		return false;
	if (curr->left != NULL && curr->right != NULL)
	{
		StudentNode* suc = curr->left;
		StudentNode* sucPrev = curr;
		while (suc->right)
		{
			sucPrev = suc;
			suc = suc->right;
		}
		curr->rollNo = suc->rollNo;
		curr->name = suc->name;
		curr->cgpa = suc->cgpa;
		curr = suc;
		prev = sucPrev;
	}
	StudentNode* temp = nullptr;
	if (curr->right)
		temp = curr->right;
	else
		temp = curr->left;
	if (prev == nullptr)
		root = temp;
	else
	{
		if (curr == prev->right)
			prev->right = temp;
		else
			prev->left = temp;
		
	}
	delete curr;
	curr = NULL;
	return true;
}
void StudentBST::displayInRange(int rollNoStart, int rollNoEnd)
{
	//cout << "Waqas";
	if (root == NULL)
		cout << "BST is empty .\n";
	else
		helperInRangeDisplay(root, rollNoStart, rollNoEnd);
}
