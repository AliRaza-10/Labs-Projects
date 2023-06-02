#ifndef CDLLD_H
#define CDLLD_H
#include <iostream>
#include "DNode.h"
using namespace std;
class CDLLD
{
private:
	DNode head;
public:
	CDLLD();
	~CDLLD();
	CDLLD(const CDLLD&);
	CDLLD& operator=(const CDLLD&);
	void display();
	bool insertAtStart(int);
	bool insertAtEnd(int);
	bool sortedInsert(int);
	bool uniqueInsert(int);
	bool sortedRemove(int);
	bool search(int);
	int countNodes();
	bool removeLastNode(int&);
	void combine(CDLLD& list1, CDLLD& list2);
	void shuffleMerge(CDLLD& list1, CDLLD& list2);
	void splitList(CDLLD& leftHalf, CDLLD& rightHalf);
	bool isSorted() const;
	bool removeSecondLastNode(int& val);
	bool removeKthNode(int k, int& val);
	bool sortList();
	//lab 10
	bool merge(CDLLD& list1, CDLLD& list2);
	void mergeSort();
	void reverse();
	void insertionSort();

};
#endif // !CDLLD_H