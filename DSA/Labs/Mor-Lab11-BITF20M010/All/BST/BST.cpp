#include <iostream>
#include "BST.h"
using namespace std;
BST::BST()
{
	root = NULL;
}
BST::BST(const BST& orig)
{
	createCopy(orig.root);
}
BST::~BST()
{
	destroyTree(root);
	root = NULL;
}
const BST& BST::operator=(const BST& rhs)
{
	if (this != &rhs)
	{
		cout << " Assignment operator \n";
		root = assignment(rhs.root);
	}
	return *this;
}
void BST::inOrder()
{
	if (root == NULL)
		cout << " BST is Empty :( \n";
	else
	{
		cout << "In-Order traversal of binary tree is (LNR) : ";
		inOrder(root);
		cout << endl;
	}
}
void BST::postOrder()  // LEFT RIGHT NODE (LRN)
{
	if (root == NULL)
		cout << " BST is Empty :( \n";
	else
	{
		cout << " Post-Order traversal of binary tree is (LRN) : ";
		postorder(root);
		cout << endl;
	}
}
void BST::preOrder()  // NODE LEFT RIGHT (NLR)
{
	if (root == NULL)
		cout << " BST is Empty :( \n";
	else
	{
		cout << " Pre-Order traversal of binary tree is (NLR) : ";
		preorder(root);
		cout << endl;
	}
}
bool BST::search(int key)
{
	BSTNode* temp = root;
	while (temp != NULL)
	{
		if (temp->data == key)
			return true;
		else if (temp->data < key)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return false;
}
bool BST::insert(int val)
{
	BSTNode* temp = root;
	BSTNode* prev = NULL;
	while (temp != NULL)
	{
		prev = temp;
		if (temp->data == val)
			return false;
		else if (temp->data < val)
			temp = temp->right;
		else
			temp = temp->left;
	}
	BSTNode* curr = new BSTNode;
	curr->data = val;
	curr->left = NULL;
	curr->right = NULL;
	cout << "Inserting : " << curr->data << endl;
	if (prev == NULL)
		root = curr;
	else if (val > prev->data)
		prev->right = curr;
	else
		prev->left = curr;
	return true;
}
bool BST::remove(int val)
{
	BSTNode* curr = root;
	BSTNode* prev = NULL;
	while (curr != NULL && curr->data != val)
	{
		prev = curr;
		if (curr->data < val)
			curr = curr->right;
		else
			curr = curr->left;
	}
	if (curr == NULL)
	{
		return false;
	}
	if (curr->left != NULL && curr->right != NULL)
	{
		BSTNode* r = curr->right;
		BSTNode* rp = curr;
		while (r->left)
		{
			rp = r;
			r = r->left;
		}
		curr->data = r->data;
		prev = rp;
		curr = r;
	}
	BSTNode* ch;
	if (curr->left)
		ch = curr->left;
	else
		ch = curr->right;
	if (prev == NULL)
		root = ch;
	else
	{
		if (curr == prev->left)
			prev->left = ch;
		else
			prev->right = ch;
	}
	delete curr;
	curr = NULL;
	return true;
}
int BST::findMin()
{
	BSTNode* temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->data;
}
int BST::findMax()
{
	BSTNode* temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp->data;
}
bool BST::recSearch(int key)
{
	return  recSearch(key, root);
}
int BST::countNodes()
{
	return countNodes(root);
}
int BST::getHeight()
{
	return getHeight(root);
}
void BST::createBalancedTree(int* arr, int start, int end)
{
	if (root != NULL)
	{
		destroyTree(root);
		root = NULL;
	}
	root = createBalancedTreeHelper(arr, start, end);
}
int BST::findMinRec()
{
	return findMinRec(root);
}
int BST::findMaxRec()
{
	return findMaxRec(root);
}