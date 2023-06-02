#ifndef BST_H
#define BST_H
#include <iostream>
#include "BSTNode.h"
using namespace std;
class BST
{
private:
	BSTNode* root;
	void inOrder(BSTNode* rt)
	{
		if (rt != NULL)
		{
			inOrder(rt->left);
			cout << rt->data << "  ";
			inOrder(rt->right);
		}
	}
	void postorder(BSTNode* temp)
	{
		if (temp != NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout << temp->data << ' ';
		}
	}
	void destroyTree(BSTNode* d)
	{
		if (d != 0)
		{
			destroyTree(d->left);
			destroyTree(d->right);
			delete d;
			d = NULL;
		}
	}
	void preorder(BSTNode* temp)
	{
		if (temp != NULL)
		{
			cout << temp->data << ' ';
			preorder(temp->left);
			preorder(temp->right);
		}
	}
	BSTNode* createCopy(BSTNode* orig)
	{
		if (orig == NULL)
			return NULL;
		else
		{
			BSTNode* temp = new BSTNode;
			temp->data = orig->data;
			temp->left = createCopy(orig->left);
			temp->right = createCopy(orig->right);
			return temp;
		}
	}
	BSTNode* assignment(BSTNode* t)
	{
		this->~BST();
		return createCopy(t);
	}
	bool recSearch(int key, BSTNode* temp)
	{
		if (temp != NULL)
		{
			if (temp->data == key)
				return true;
			if (temp->data > key)
				return recSearch(key, temp->left);
			else if (temp->data < key)
				return recSearch(key, temp->right);
		}
		else
			return false;
	}
	int countNodes(BSTNode* b)
	{
		if (b != NULL)
		{
			return 1 + (countNodes(b->left)) + (countNodes(b->right));
		}
		else
			return 0;
	}
	int getHeight(BSTNode* b)
	{
		if (b == NULL)
			return 0;
		else if (b->left == NULL && b->right == NULL)
			return 1;
		else
		{
			int count1 = 1 + getHeight(b->left);
			int count2 = 1 + getHeight(b->right);
			if (count1 > count2)
				return count1;
			else
				return count2;
		}
	}
	BSTNode* createBalancedTreeHelper(int* arr, int start, int end)
	{
		if (start <= end)
		{
			int mid = (start + end) / 2;
			BSTNode* temp = new BSTNode;
			temp->data = arr[mid];
			temp->left = createBalancedTreeHelper(arr, start, mid - 1);
			temp->right = createBalancedTreeHelper(arr, mid + 1, end);
			return temp;
		}
		else
			return NULL;
	}
	
	int findMinRec(BSTNode* t)
	{
		if (t->left == NULL)
		{
			return t->data;
		}
		else
		{
			return findMinRec(t->left);
		}
	}
	int findMaxRec(BSTNode* t)
	{
		if (t->right == NULL)
		{
			return t->data;
		}
		else
		{
			return findMaxRec(t->right);
		}
	}
public:
	BST();
	~BST();
	BST(const BST&);
	const BST& operator=(const BST&);
	void inOrder();
	void postOrder();
	void preOrder();
	bool search(int);
	bool insert(int);
	bool remove(int);
	int findMax();
	int findMin();
	bool recSearch(int);

	int countNodes(); // public (driver function)
	int getHeight(); // public (driver function)
	void createBalancedTree(int* arr, int start, int end);
	int findMinRec();
	int findMaxRec();
};
#endif // !BST_H
