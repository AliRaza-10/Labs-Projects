// Muhammad Waqas Ud Din
// BITF20M013
// IT-Morning
#include <iostream>
using namespace std;
void printZigZag(int* arr, int start, int end)
{
	if (start == end)
	{
		cout << arr[start] << " ";
	}
	else if (start < end)
	{
		cout << arr[start] << " " << arr[end] << " ";
		printZigZag(arr, start + 1, end - 1);
	}
}
void printZigZagUpdated(int* pStart, int* pEnd)
{
	if (pStart == pEnd)
		cout << *pStart << " ";
	else if(pStart < pEnd)
	{
		cout << *pStart << " " << *pEnd << " ";
		printZigZagUpdated(pStart + 1, pEnd - 1);
	}
}
int main()
{
	int arr[5] = { 3,6,2,1,4 };
	printZigZag(arr, 0, 4);
	cout << endl;
	int arr1[6] = { 7,1,9,3,5,2 };
	printZigZag(arr1, 0, 5);
	cout << endl;
	int arr2[6] = { 7,1,9,3,5,2 };
	printZigZagUpdated(&arr2[0], &arr2[5]);
	cout << endl;
	int arr3[5] = { 3,6,2,1,4 };
	printZigZagUpdated(&arr3[0], &arr3[4]);
	return 0;
}