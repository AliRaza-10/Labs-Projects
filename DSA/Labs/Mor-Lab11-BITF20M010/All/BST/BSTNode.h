#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
#include "BST.h"
using namespace std;
class BSTNode
{
	friend class BST;
private:
	int data;
	BSTNode* right, * left;
};
#endif // !BSTNODE_H
