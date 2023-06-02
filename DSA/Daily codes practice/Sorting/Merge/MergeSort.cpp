#include <iostream>
using namespace std;
void display(int* arr, int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void merge(int* arr, int leftStart, int leftEnd, int rightStart, int rightEnd)
{
	int size = rightEnd - leftStart + 1;
	int* temp = new int[size];
	int i = leftStart;
	int j = rightStart;
	int k = 0;
	while (i <= leftEnd && j <= rightEnd)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= leftEnd)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= rightEnd)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	k = 0;
	int x = leftStart;
	while (k < size)
	{
		arr[x] = temp[k];
		x++;
		k++;
	}
	delete[]temp;
	temp = NULL;
}
void mergeSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}
int main()
{
	int arr[8] = { 10,8,2,13,5,14,3,7 };
	mergeSort(arr, 0, 7);
	display(arr, 0, 7);
	int arr1[7] = { 8,2,13,5,14,3,7 };
	mergeSort(arr1, 0, 6);
	display(arr1, 0, 6);
	return 0;
}
