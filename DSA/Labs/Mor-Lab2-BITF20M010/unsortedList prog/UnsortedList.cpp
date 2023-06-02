#include <iostream>
#include "UnsortedList.h"
using namespace std;
UnsortedList::UnsortedList(int m)
{
	maxSize = m;
	currSize = 0;
	arr = new int[maxSize];
}
UnsortedList::~UnsortedList()
{
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
}
bool UnsortedList::insert(int val)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		arr[currSize] = val;
		currSize++;
		return true;
	}
}
void UnsortedList::display() const
{
	if (isEmpty())
	{
		cout << "List is empty.\n";
	}
	else
	{
		for (int i = 0; i < currSize; i++)
		{
			cout << arr[i] << "  ";
		}
		//cout << "=======" << maxSize << "    " << currSize;
		cout << endl;
	}
}
bool UnsortedList::isEmpty() const
{
	if (currSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool UnsortedList::isFull() const
{
	if (currSize == maxSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool UnsortedList::remove(int index, int& val)
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
UnsortedList::UnsortedList(const UnsortedList& orig)
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
const UnsortedList& UnsortedList::operator=(const UnsortedList& rhs)
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
//void UnsortedList::writeInFile(ofstream& fout)
//{
//	fout << maxSize << endl;
//	fout << currSize << endl;
//	for (int i = 0; i < currSize; i++)
//		fout << arr[i] << "   ";
//}
//void UnsortedList::readFromFile(ifstream& fin)
//{
//	fin >> maxSize;
//	fin >> currSize;
//	arr = new int[maxSize];
//	int  n,i=0;
//	//fin >> n;
//	/*while (!(fin.eof()))
//	{
//		arr[i] = n;
//		fin >> n;
//		i++;
//	}*/
//
//	for (int i = 0; i < currSize; i++) {
//		fin >> n;
//		arr[i] = n;
//	}
//}

//Task 2
bool UnsortedList::removeMax(int& maxVal)
{
	if (isEmpty())
		return false;
	else {
		int index = 0;
		maxVal = arr[0];
		for (int i = 1; i < currSize; i++){
			if (arr[i] > maxVal){
				maxVal = arr[i];
				index = i;
			}
		}
		for (int j = index; j < currSize - 1; j++){
			arr[j] = arr[j + 1];
		}
		currSize--;
		//cout << "Index " << index << endl;
		return true;

	}
}

//Task 2
void UnsortedList::reverse()
{
	int start = 0,end =  currSize-1;
	while (start <= end) {
		int temp;
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
//Tssk 2
void UnsortedList::combineList(const UnsortedList& list2)
{
	UnsortedList list1(maxSize);
	list1.currSize = currSize;
	list1.maxSize = maxSize;
	for (int i = 0; i < currSize; i++) {
		list1.arr[i] = arr[i];
	}

	delete[]arr;
	arr = NULL;
	maxSize = list1.maxSize + list2.maxSize;
	currSize = list1.currSize + list2.currSize;
	arr = new int[maxSize];
	int j = 0;
	for (int i = 0; i < currSize ; i++) {
		if (i<(currSize - list2.currSize)){
			arr[i] = list1.arr[i];
		}
		else {
			arr[i] = list2.arr[j];
			j++;
		}
	}
}

int UnsortedList::replaceVal(int oldVal, int newVal)
{
	int count = 0;
	for (int i = 0; i < currSize; i++)
	{
		if (arr[i] = oldVal)
		{
			arr[i] = newVal;
			count++;
		}
	}
	return count;
}
bool UnsortedList::removeMin(int& minVal)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		int mini = 0, i;
		int temp = arr[0];
		for (i = 1; i < currSize; i++)
		{
			if (arr[i] < temp)
			{
				temp = arr[i];
				mini = i;
			}
		}
		for (int i = mini; i < currSize - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		//cout << maxi << endl;
		currSize--;
		return true;

	}
}
bool UnsortedList::removeLastOccurrence(int val)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		int mini = 0, i;
		for (i = 0; i < currSize; i++)
		{
			if (arr[i] == val)
			{
				mini = i;
			}
		}
		for (int i = mini; i < currSize - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		currSize--;
		return true;

	}
}
int UnsortedList::removeAll(int val)
{
	int count = 0;
	int i = 0, j = 0;
	while (i < currSize)
	{
		if (arr[i] == val)
		{
			i++;
			count++;
		}
		else
		{
			arr[j] = arr[i];
			i++;
			j++;

		}
	}
	currSize -= count;
	return count;
}

//Lab 3
UnsortedList UnsortedList::intersection(const UnsortedList& list2) const
{
	int count = 0;

	for (int i = 0; i < currSize; i++) 
	{
		for (int j = 0; j < list2.currSize; j++) 
		{
			if (arr[i] == list2.arr[j]) 
			{
				count++;
			}
		}
	}
	int max = maxSize;
	if (max > list2.maxSize)
	{
		max = list2.maxSize;
	}
	UnsortedList list1(max);
	list1.currSize = count;
	int  k = 0;
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < list2.currSize; j++)
		{
			if (arr[i] == list2.arr[j])
			{
				list1.arr[k] = arr[i];
				k++;
			}
		}
	}
	return list1;
}

bool UnsortedList::isSubset(const UnsortedList& list2) const
{
	if (isEmpty())
		return true;
	else
	{
		bool flag = false;
		if (currSize <= list2.currSize)
		{
			int count = 0;
			for (int i = 0; i < currSize; i++)
			{
				for (int j = 0; j < list2.currSize; j++)
				{
					if (arr[i] == list2.arr[j])
					{
						count++;
					}
				}
			}
			if (count == currSize)
				flag = true;
		}
		return flag;
	}
}

UnsortedList UnsortedList::difference(const UnsortedList& list2) const
{
	UnsortedList list1(currSize);
	for (int i = 0; i < currSize; i++) {
		int count = 0;
		for (int j = 0; j < list2.currSize; j++) {
			if (arr[i] != list2.arr[j]) {
				count++;
			}
		}
		if (count == list2.currSize)
			list1.insert(arr[i]);
	}
	return list1;
}

UnsortedList UnsortedList::union1(const UnsortedList& list2) const
{
	
	int i,size= currSize + list2.currSize;
	UnsortedList list1(size);
	for (i = 0; i < currSize; i++)
	{
		list1.arr[i] = arr[i];
		list1.currSize++;
	}
	for (int j = 0; j < list2.currSize; j++)
	{
		int count = 0;
		for (int k = 0; k < currSize; k++)
		{
			if (list2.arr[j] != arr[k])
			{
				count++;
			}	
		}
		if (count == currSize)
		{
		
			list1.arr[i] = list2.arr[j];
			list1.currSize++;
			i++;
		}
	}
	return list1;
}