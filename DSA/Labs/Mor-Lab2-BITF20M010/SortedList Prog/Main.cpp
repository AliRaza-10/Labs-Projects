#include <iostream>
#include "SortedList.h"
using namespace std;


//Lab 3 Task 2
int findKthLargest(const int* arr, int n, int k)
{

	int ktMax = 0;
	for (int i = 0; i < n; i++)
	{
		int max = arr[i];
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > arr[i])
			{
				count++;
			}

		}
		if (count == (k - 1))
		{
			ktMax = arr[i];
		}
	}
	return ktMax;
}

int main()
{
	/*int val;
	SortedList l1(10);
	l1.insert(2);
	l1.insert(5);
	l1.insert(6);
	l1.insert(8);
	l1.insert(7);
	if (l1.uniqueInsert(10))
		cout << "Number has inserted successfully.\n";
	else
		cout << "Number already found.\n";
	l1.display();
	if (l1.remove(3, val))
		cout << "Number has been removed and number is : " << val << endl;
	else
		cout << "Index is not true.\n";
	l1.display();*/
	/*const int SIZE = 10;
	int count = 0;
	int arr[SIZE] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < SIZE; i = i + 2)
	{
		cout << arr[i] << "  ";
		count++;
	}
	cout << endl;
	cout << count;*/

	/*SortedList l1(10);
	l1.insert(2);
	l1.insert(4);
	l1.insert(6);
	l1.insert(8);
	l1.insert(10);
	l1.display();

	if (l1.replace(2, 7))
		cout << "Replaced .\n";
	else
		cout << "Not replaced.\n";
	l1.display();*/
	/*if (l1.replace(4, 1))
		cout << "Replaced .\n";
	else
		cout << "Not replaced.\n";*/
	
	/*if (l1.replace(5, 1))
		cout << "Replaced .\n";
	else
		cout << "Not replaced.\n";*/

	//l1.display();

	/*if (l1.binarySearch(5))
		cout << "Number found.\n";
	else
		cout << "Not found.\n";*/


	/*SortedList l1(10);
	l1.insert(2);
	l1.insert(4);
	l1.insert(6);
	l1.insert(8);
	l1.insert(10);
	l1.insert(12);
	l1.insert(11);
	l1.insert(14);
	l1.insert(18);
	l1.display();
	
	SortedList l2(10);
	l2.insert(2);
	l2.insert(8);
	l2.insert(11);
	l2.insert(12);
	l2.insert(14);
	l2.insert(18);
	l2.display();

	SortedList l3 = l1.intersection(l2);
	l3.display();*/


	/*int num;
	int arr[7] = { 22,7,10,13,14,1 };
	num = findKthLargest(arr, 7, 3);
	cout << num;*/


	/*SortedList l3(10);
	l3.insert(2);
	l3.insert(4);
	l3.insert(7);
	l3.insert(12);
	l3.insert(15);
	l3.display();

	SortedList l4(10);
	l4.insert(2);
	l4.insert(3);
	l4.insert(4);
	l4.insert(6);
	l4.insert(7);
	l4.insert(12);
	l4.insert(15);
	l4.insert(16);
	l4.display();

	if (l3.isSubset(l4))
		cout << "List3 is subset of List4.\n";
	else
		cout << "List3 is not subset of List4.\n";*/


	SortedList l3(10);
	l3.insert(2);
	l3.insert(4);
	l3.insert(7);
	l3.insert(12);
	l3.insert(15);
	l3.insert(16);
	l3.display();

	SortedList l4(10);
	l4.insert(4);
	l4.insert(7);
	l4.insert(12);
	l4.insert(15);
	
	l4.display();

	SortedList l5 = l3.difference(l4);
	l5.display();
}