#include <iostream>
using namespace std;
void swap(int& val1, int& val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}
int findLargestIndex(int* arr, int start, int end)
{
	
	if (start <= end)
	{
		int max = findLargestIndex(arr, start + 1, end);
		if (arr[max] > arr[start])
		{
			return max;
		}
		else
		{
			return start;
		}
	}
}

void reverseSubArray(int* arr, int start, int end)
{
	if (start <= end)
	{
		swap(arr[start], arr[end]);
		reverseSubArray(arr, start + 1, end - 1);
	}
}

void pancakeSortIter(int* arr, int start, int end)
{
	int j = end;
	while (j >= start)
	{
		int index = findLargestIndex(arr, start, j);
		reverseSubArray(arr, start, index);
		reverseSubArray(arr, start, j);
		j--;
	}
}

void pancakeSortRec(int* arr, int start, int end)
{
	if (end >= start)
	{
		int index = findLargestIndex(arr, start, end);
		reverseSubArray(arr, start, index);
		reverseSubArray(arr, start, end);
		pancakeSortRec(arr, start, end - 1);
	}
}

bool linearSearch(int* a, int start, int end, int key)
{
	if (start > end)
	{
		return false;
	}
	else if (key == a[start])
	{
		return true;
	}
	else
	{
		return linearSearch(a, start + 1, end, key);
	}
}

bool checkSum(int* arr, int start, int end, int k)
{
	if (start <= end)
	{
		int temp = arr[start];
		int key = k - temp;
		if (linearSearch(arr, start + 1, end, key))
		{
			return true;
		}
		else
		{
			return checkSum(arr, start + 1, end, k);
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	/*int arr[] = { -99,100,13,-12,33,44,2,1,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int start, end;
	int key;
	start = 0;
	end = n - 1;
	key = -111;

	if (checkSum(arr, start, end, key)) {
		cout << "FOUND" << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}
	start = 1;
	end = 4;
	key = -12;
	if (checkSum(arr, start, end, key))
	{
		cout << "FOUND" << endl;
	}
	else
	{
		cout << "NOT FOUND" << endl;
	}
	start = 1;
	end = 4;
	pancakeSortIter(arr, start, end);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;
	start = 0;
	end = n - 1;
	pancakeSortRec(arr, start, end);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";*/
	int n1;
	cout << "Enter the size of Array: ";
	cin >> n1;
	int start1 = 0;
	int end1 = n1 - 1;
	int* arr1 = new int[n1];
	cout << "Enter Values of Array: " << endl;
	for (int i = 0; i < n1; i++)
	{
		cout << "Enter " << i + 1 << " element: ";
		cin >> arr1[i];
	}
	char choice;
	do
	{
		int key;
		cout << "Enter K: ";
		cin >> key;
		bool flag;
		flag = checkSum(arr1, start1, end1, key);
		if (flag == 1)
		{
			cout << "Yes," << key << " can be obtained by adding two elements of the array.";
		}
		else
		{
			cout << "No," << key << " cannot be obtained by adding two elements of the array.";
		}
		cout << endl;
		cout << "Continue (y/n)? ";
		cin >> choice;
	} while (choice == 'y');
	return 0;
}