//LAb10-Task2
#include<iostream>
using namespace std;

int removeNegatives(int arr[], int size, int& newSize)
{
	newSize = size;
	for (int i = 0; i < newSize; i++)
	{
		if (arr[i] < 0)
		{
			for (int j = i; j < newSize - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			i--;
			newSize--;
		}
	}
	return size - newSize;
}

int main()
{
	const int SIZE = 7;
	int newSize, neg = 0;
	int arr[SIZE] = { 11,-15,-2,7,11,6,-8 };
	neg = removeNegatives(arr, SIZE, newSize);
	for (int i = 0; i < newSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << neg << endl;
}
