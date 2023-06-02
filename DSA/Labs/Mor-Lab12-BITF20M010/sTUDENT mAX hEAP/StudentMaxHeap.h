#ifndef STUDENTMAXHEAP_H
#define STUDENTMAXHEAP_H
#include <iostream>
#include  "Student.h"
using namespace std;
class StudentMaxHeap
{
private:
	Student* st;
	int maxSize, currSize;
public:
	StudentMaxHeap(int size); // Constructor
	~StudentMaxHeap(); // Destructor
	bool isEmpty(); // Checks whether the heap is empty or not
	bool isFull(); // Checks whether the heap is full or not
	bool insert(int rollNo, double cgpa);
	bool removeBestStudent(int& rollNo, double& cgpa, int);
	void levelOrder();
	int height();
	void heapify(int i);
	void buildHeap(Student* st, int n);
	void heapSortAlgo(int&,double&);
};
#endif // !STUDENTMAXHEAP_H