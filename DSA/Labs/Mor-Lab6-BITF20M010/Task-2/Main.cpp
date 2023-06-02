// Muhammad Waqas Ud Din
// BITF20M013
// IT-Morning
#include <iostream>
using namespace std;
int findLargestIndex(int* arr, int start, int end)
{
	if (start == end)
	{
		return end;
	}
	else
	{
		int maxIndex = findLargestIndex(arr, start + 1, end);
		if (arr[start] > arr[maxIndex])
		{
			maxIndex = start;
			return maxIndex;
		}
		else
		{
			return maxIndex;
		}
	}
}
int main()
{
	int arr[6] = { 3,5,1,3,-5,10 };
	cout << (findLargestIndex(arr, 0, 5)) << endl;
	int arr1[8] = { 3,5,11,3,-5,10,0,2 };
	cout << (findLargestIndex(arr1, 0, 7)) << endl;
	return 0;
}