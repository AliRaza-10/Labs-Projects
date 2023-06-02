#ifndef UnsortedList_h
#define UnsortedList_h
#include <iostream>
#include <fstream>
using namespace std;
class UnsortedList
{
private:
	int* arr;
	int maxSize;
	int currSize;
public:
	UnsortedList(int);
	~UnsortedList();
	bool insert(int);
	void display() const;
	bool isEmpty() const;
	bool isFull() const;
	bool remove(int, int&);
	UnsortedList(const UnsortedList&);
	const UnsortedList& operator=(const UnsortedList&);
	//void writeInFile(ofstream&);
	//void readFromFile(ifstream&);
	bool removeMax(int&);
	void reverse();

	
	void combineList(const UnsortedList&);
	int replaceVal(int, int);
	bool removeMin(int&);
	bool removeLastOccurrence(int);
	int removeAll(int);
	UnsortedList intersection(const UnsortedList& list2) const;
	bool isSubset(const UnsortedList&) const;
	UnsortedList difference(const UnsortedList&) const;
	UnsortedList union1(const UnsortedList&) const;

};
#endif // !UnsortedList_h