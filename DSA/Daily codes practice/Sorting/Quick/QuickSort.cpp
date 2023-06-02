#include <iostream>
using namespace std;
void display(int *arr,int start,int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int partition(int* arr, int start, int end)
{
	int i = start;
	int j = end + 1;
	int pivot = arr[start];
	while (i < j)
	{
		do
		{
			i = i+1;
		} while (i < end && arr[i] < pivot);
		do
		{
			j = j-1;
		} while (j > start && arr[j] > pivot);
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[start], arr[j]);
	return j;
}
void quickSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int p = partition(arr, start, end);
		quickSort(arr, start, p-1);
		quickSort(arr, p + 1, end);
	}
}
int main()
{
	int arr[7] = { 8,2,13,5,14,3,7};
	quickSort(arr, 0, 6);
	display(arr, 0, 6);
	int arr1[8] = { 10,8,2,13,5,14,3,7 };
	quickSort(arr1, 0, 7);
	display(arr1, 0, 7);
	return 0;
}