#include <iostream>
#include "SortedList.h"
using namespace std;
SortedList::SortedList(int size)
{
	maxSize = size;
	currSize = 0;
	arr = new int[maxSize];
}
SortedList::~SortedList()
{
	if (arr)
	{
		delete[]arr;
		arr = NULL;
	}
}
bool SortedList::insert(int val)
{
	if (isFull())
		return false;
	else
	{
		int i = currSize - 1;
		while (i >= 0 && arr[i] > val)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = val;
		currSize++;
		return true;
	}
}
void SortedList::display() const
{
	if (isEmpty())
		cout << "List is empty.\n";
	else
	{
		for (int i = 0; i < currSize; i++)
		{
			cout << arr[i] << "  ";
		}
		cout << endl;
	}
}
bool SortedList::isEmpty() const
{
	if (currSize == 0)
		return true;
	else
		return false;
}
bool SortedList::isFull() const
{
	if (currSize == maxSize)
		return true;
	else
		return false;
}
bool SortedList::remove(int index, int& val)
{
	if (index >= 0 && index < currSize)
	{
		val = arr[index];
		for (int i = index; i < currSize - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		currSize--;
		return true;
	}
	else
	{
		return false;
	}
}
bool SortedList::uniqueInsert(int val)
{
	if (isFull())
		return false;
	else
	{
		int i = currSize - 1;
		while (i >= 0)
		{
			if (arr[i] == val)
				return false;
			i--;
		}
		i = currSize - 1;
		while (i >= 0 && arr[i] > val)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = val;
		currSize++;
		return true;
	}
}
SortedList::SortedList(const SortedList& orig)
{
	maxSize = orig.maxSize;
	currSize = orig.currSize;
	cout << "Copy Constructor.\n";
	//cout << maxSize << "    " << currSize << endl;
	if (orig.arr != NULL)
	{
		arr = new int[maxSize];
		for (int i = 0; i < currSize; i++)
		{
			arr[i] = orig.arr[i];
		}
	}
	else
	{
		arr = NULL;
	}
}
const SortedList& SortedList::operator=(const SortedList& rhs)
{
	cout << "Assignment operator.\n";
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		maxSize = rhs.maxSize;
		currSize = rhs.currSize;
		if (arr != NULL)
		{
			delete[]arr;
			arr = NULL;
		}
		if (rhs.arr != NULL)
		{
			arr = new int[maxSize];
			for (int i = 0; i < currSize; i++)
			{
				arr[i] = rhs.arr[i];
			}
		}
		else
		{
			arr = NULL;
		}
		return *this;
	}
}

//Task 1 
bool SortedList::replace(int index, int newVal)
{
	if (index >= currSize || index < 0)
	{
		return false;
	}
	else
	{
		arr[index] = newVal;
		int i = currSize - 1;
		if (arr[index - 1] > arr[index])
		{
			int j = index;
			while (j > 0)
			{
				if (arr[j-1] > arr[j])
				{
					int temp;
					temp = arr[j-1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
				j--;
			}
		}
		else
		{
			int j = index;
			while (j < currSize-1)
			{
				if (arr[j] > arr[j+1])
				{
					int temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j+1] = temp;
				}
				j++;
			}
		}
		return true;
	}
}

bool SortedList::binarySearch(int val)
{
	int start = 0, end = currSize - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == val)
			return true;
		else if (arr[mid] < val)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
}

int SortedList::removeAll(int val)
{
	int count = 0;
	for (int i = 0; i < currSize; i++)
	{
		if (arr[i] == val)
		{
			for (int j = i; j < currSize - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			count++;
			i--;
			currSize--;
		}
	}
	return count;
}

//Lab 3
SortedList SortedList::intersection(const SortedList& list2) const
{
	int count = 0;
	int i = 0, j = 0, k = 0;
	int curr = currSize;
	if (curr < list2.currSize)
		curr = list2.currSize;
	int max = maxSize;
	if (max > list2.maxSize)
		max = list2.maxSize;
	SortedList list1(max);
	while (i < curr)
	{
		if (arr[i] == list2.arr[j])
		{
			list1.arr[k] = arr[i];
			i++;
			k++;
			j++;
			list1.currSize++;
		}
		else if (arr[i] < list2.arr[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return list1;
}

bool SortedList::isSubset(const SortedList& list2) const
{
	if (isEmpty())
		return true;
	else {
		bool flag = false;
		if (currSize <= list2.currSize) {
			
			int count = 0,i = 0,j = 0;
			while (i < currSize) {
				if (arr[i] == list2.arr[j]) {
					count++;
					i++;
					j++;
				}
				else if (arr[i] < list2.arr[j])
					i++;
				else
					j++;

			}
			if (count == currSize)
				flag = true;
		}
		return flag;
	}
}

SortedList SortedList::difference(const SortedList& list2) const
{
	int i = 0, j = 0, count = 0;
	SortedList list1(currSize);
	while (i < currSize) {
		count = 0;
		int num = arr[i];
		if (arr[i] == list2.arr[j]) {
			i++;
			j++;
		}
		else if (arr[i] > list2.arr[j])
			j++;
		else {
			i++;
			count++;
		}
		if (count == 1)
		{
			list1.insert(num);
		}
	}
	return list1;
}
