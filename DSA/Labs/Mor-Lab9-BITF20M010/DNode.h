#ifndef DNODE_H
#define DNODE_H
#include <iostream>
#include "CDLLD.h"
using namespace std;
class DNode
{
	friend class CDLLD;
private:
	int data;
	DNode* prev;
	DNode *next;
};
#endif // !DNODE_H
