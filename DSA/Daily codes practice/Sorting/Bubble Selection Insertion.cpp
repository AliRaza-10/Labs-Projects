#include <iostream>
#include <chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void displayArray(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void bubbleSort(int* arr, int n)
{
	for (int i = n - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void selectionSort(int* arr,int n)
{
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}
void insertionSort(int* arr, int n)
{
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main()
{
	const int SIZE = 10;
	int *arr = new int[SIZE];
	auto start = high_resolution_clock::now();
	for(int i = 0;i<SIZE;i++)
	{
		arr[i] = 1;
	}
	auto start = high_resolution_clock::now();
	insertionSort(arr, SIZE);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end-start);
	cout<<duration.count();
	//bubbleSort(arr, SIZE);
	//selectionSort(arr, SIZE);
	//int arr[SIZE] = { 41,62,18,10,23,4,5,1,6,41 };
	
	
	
	return 0;
}
