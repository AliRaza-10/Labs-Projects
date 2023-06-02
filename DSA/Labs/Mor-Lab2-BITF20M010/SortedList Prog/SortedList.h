#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <iostream>
using namespace std;
class SortedList
{
private:
	int* arr;
	int maxSize,currSize;
public:
	SortedList(int);
	~SortedList();
	bool insert(int);
	void display() const;
	bool isEmpty() const;
	bool isFull() const;
	bool remove(int, int&);
	bool uniqueInsert(int);
	SortedList(const SortedList&);
	const SortedList& operator=(const SortedList&);
	bool replace(int, int);
	bool binarySearch(int);
	int removeAll(int);
	SortedList intersection(const SortedList&) const;
	bool isSubset(const SortedList&) const;
	SortedList difference(const SortedList&) const;
};
#endif // !SORTEDLIST_H
