#include <iostream>
#include <iomanip>
#include <cmath>
#include "StudentMaxHeap.h"
using namespace std;
StudentMaxHeap::StudentMaxHeap(int size)
{
	maxSize = size;
	currSize = 0;
	st = new Student[maxSize + 1];
}
StudentMaxHeap::~StudentMaxHeap()
{
	if (st)
	{
		delete[]st;
		st = NULL;
	}
}
bool StudentMaxHeap::isEmpty()
{
	if (currSize == 0)
		return true;
	else
		return false;
}
bool StudentMaxHeap::isFull()
{
	if (currSize == maxSize)
		return true;
	else
		return false;
}
void StudentMaxHeap::levelOrder()
{
	if (isEmpty())
		cout << "Heap is Empty.\n";
	else
	{
		for (int i = 1; i <= currSize; i++)
			cout << i << setw(5) << st[i].rollNo << "\t" << st[i].cgpa << endl;
		cout << endl;
	}
}
bool StudentMaxHeap::insert(int rollNo, double cgpa)
{
	if (isFull())
		return false;
	else
	{
		currSize = currSize + 1;
		int i = currSize;
		while (i > 1 && cgpa > st[i / 2].cgpa)
		{
			st[i].cgpa = st[i / 2].cgpa;
			st[i].rollNo = st[i / 2].rollNo;
			i = i / 2;
		}
		if (st[i/2].cgpa == cgpa)
		{
			if (st[i/2].rollNo > rollNo)
			{
				st[i].cgpa = st[i / 2].cgpa;
				st[i].rollNo = st[i / 2].rollNo;
				i = i / 2;
			}
		}
		st[i].cgpa = cgpa;
		st[i].rollNo = rollNo;
		return true;
	}

	// 13 3.6	// 13 3.6
	// 14 3.5	// 13 3.6, 14 3.5
	// 12 3.6	
				// 12 3.6, 13 3.6, 14 3.5

		// 
}
bool StudentMaxHeap::removeBestStudent(int& rollNo, double& cgpa,int indicator)
{
	if (isEmpty())
		return false;
	else
	{
		rollNo = st[1].rollNo;
		cgpa = st[1].cgpa;
		st[1].cgpa = st[currSize].cgpa;
		st[1].rollNo = st[currSize].rollNo;
		currSize--;
		int i = 1,largest,left,right;
		bool flag = true;
		while (flag == true && 2 * i <= currSize)
		{
			left = 2 * i;
			right = 2 * i + 1;
			largest = i;
			if (left <= currSize && st[left].cgpa > st[largest].cgpa)
				largest = left;
			if (right <= currSize && st[right].cgpa > st[largest].cgpa)
				largest = right;
			if (indicator == 1)
			{
				if (st[largest].cgpa == st[right].cgpa && st[right].rollNo > st[largest].rollNo)
					largest = right;
				if (st[largest].cgpa == st[left].cgpa && st[left].rollNo > st[largest].rollNo)
					largest = left;
			}
			else
			{
				if (st[largest].cgpa == st[right].cgpa && st[right].rollNo < st[largest].rollNo)
					largest = right;
				if (st[largest].cgpa == st[left].cgpa && st[left].rollNo < st[largest].rollNo)
					largest = left;
			}
			if (largest == i)
				flag = false;
			else
			{
				int r = st[i].rollNo;
				double c = st[i].cgpa;
				st[i].rollNo = st[largest].rollNo;
				st[i].cgpa = st[largest].cgpa;
				st[largest].rollNo = r;
				st[largest].cgpa = c;
				i = largest;
			}
		}
		return true;
	}
}
int StudentMaxHeap::height()
{
	if (isEmpty())
		return 0;
	else
	{
		return (floor(log2(currSize)) + 1);
	}
}
void StudentMaxHeap::heapify(int i)
{
	int largest, left, right;
	bool flag = true;
	while (flag == true && 2 * i <= currSize)
	{
		left = 2 * i;
		right = 2 * i + 1;
		largest = i;
		if (left <= currSize && st[left].cgpa > st[largest].cgpa)
			largest = left;
		if (right <= currSize && st[right].cgpa > st[largest].cgpa)
			largest = right;
		if (st[largest].cgpa == st[right].cgpa && st[right].rollNo < st[largest].rollNo)
			largest = right;
		if (st[largest].cgpa == st[left].cgpa && st[left].rollNo < st[largest].rollNo)
			largest = left;
		if (largest == i)
			flag = false;
		else
		{
			int r = st[i].rollNo;
			double c = st[i].cgpa;
			st[i].rollNo = st[largest].rollNo;
			st[i].cgpa = st[largest].cgpa;
			st[largest].rollNo = r;
			st[largest].cgpa = c;
			i = largest;
		}
	}
}
void StudentMaxHeap::buildHeap(Student* st1, int n)
{
	if (st)
	{
		delete[]st;
		st = NULL;
	}
	maxSize = n;
	st = new Student[n + 1];
	for (int i = 0; i < n; i++)
	{
		st[i + 1].cgpa = st1[i].cgpa;
		st[i + 1].rollNo = st1[i].rollNo;
	}
	currSize = n;
	for (int i = n / 2; i >= 1; i--)
		heapify(i);
}
void StudentMaxHeap::heapSortAlgo(int& r,double& c)
{
	int i = 1, largest = i, left = 2*i, right = 2* i +1;
	int rem = i;
	if (st[i].rollNo < st[left].rollNo && st[i].cgpa == st[left].cgpa)
		rem = left;
	if (st[rem].rollNo < st[right].rollNo && st[rem].cgpa == st[right].cgpa)
		rem = right;
	if (rem == i)
	{
		r = st[1].rollNo;
		c = st[1].cgpa;
	}
	else
	{
		r = st[rem].rollNo;
		c = st[rem].cgpa;
		st[rem].cgpa = st[i].cgpa;
		st[rem].rollNo = st[i].rollNo;
	}
	st[1].cgpa = st[currSize].cgpa;
	st[1].rollNo = st[currSize].rollNo;
	currSize--;
	bool flag = true;
	while (flag == true && 2 * i <= currSize)
	{
		left = 2 * i;
		right = 2 * i + 1;
		largest = i;
		if (left <= currSize && st[left].cgpa > st[largest].cgpa)
			largest = left;
		if (right <= currSize && st[right].cgpa > st[largest].cgpa)
			largest = right;
		if (st[largest].cgpa == st[right].cgpa && st[right].rollNo < st[largest].rollNo)
			largest = right;
		if (st[largest].cgpa == st[left].cgpa && st[left].rollNo > st[largest].rollNo)
			largest = left;
		if (largest == i)
			flag = false;
		else
		{
			int r = st[i].rollNo;
			double c = st[i].cgpa;
			st[i].rollNo = st[largest].rollNo;
			st[i].cgpa = st[largest].cgpa;
			st[largest].rollNo = r;
			st[largest].cgpa = c;
			i = largest;
		}
	}
}