#include <iostream>
using namespace std;
void printArray1(int* a, int start, int end)
{
	if (start <= end)
	{
		cout << a[start] << "  ";
		printArray1(a, start + 1, end);
	}
}
//Task no 4
int power(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else
	{
		return (a * power(a, b - 1));
	}
}
//Task no 5
int product(int a, int b)
{
	if (b == 0)
	{
		return 0;
	}
	else
	{
		return a + product(a, b - 1);
	}
}

//Task no 6
//6.1
void printChar(char ch, int n)
{
	if (n>0)
	{
		cout << ch;
		printChar(ch, n - 1);
	}
}
//6.2
void printPattern1(char ch, int n)
{
	if (n > 0)
	{
		printChar(ch, n);
		cout << endl;
		printPattern1(ch, n - 1);
	}
}
//6.3
void printPattern2(char ch, int n)
{
	if (n > 0)
	{
		printPattern2(ch, n - 1);
		printChar(ch, n);
		cout << endl;
	}
}

//Task no 7
int quotient(int num, int den)
{
	if (num == 0)
	{
		return 0;
	}
	else if(num>=den)
	{
		return (1 + quotient((num - den), den));
	}
}

//Task no 8
int findLargest(int* arr, int start, int end)
{
	if (start == end)
	{
		return arr[start];
	}
	else
	{
		int max = findLargest(arr, start + 1, end);
		if (max < arr[start])
		{
			max = arr[start];
			return max;
		}
		else
		{
			return max;
		}
	}
}

//Task no 9
bool areArraysEqual(int* a, int aSize, int* b, int bSize)
{
	if (aSize != bSize)
		return false;
	else if (aSize > 0 && bSize > 0)
	{
		if (a[aSize-1] == b[bSize-1])
		{
			return areArraysEqual(a, aSize - 1, b, bSize - 1);
		}
		else
		{
			return false;
		}
	}
	else
		return true;
}

//Task no 10
/*int countVowels(char* str, int length)
{
	if (length > 0)
	{
		if (tolower(str[length - 1]) == 'a' || tolower(str[length - 1]) == 'e' || tolower(str[length - 1]) == 'i' || tolower(str[length - 1]) == 'o' || tolower(str[length - 1]) == 'u')
		{
			return 1 + countVowels(str, length - 1);
		}
		else
			countVowels(str, length - 1);
	}
	else
		return 0;
}*/
int countVowels(char* str, int length)
{
	if (length > 0)
	{
		if (str[length - 1] == 'a' || str[length - 1] == 'A')
		{
			return 1 + countVowels(str, length - 1);
		}
		else if (str[length - 1] == 'e' || str[length - 1] == 'E')
		{
			return 1 + countVowels(str, length - 1);
		}
		else if (str[length - 1] == 'i' || str[length - 1] == 'I')
		{
			return 1 + countVowels(str, length - 1);
		}
		else if (str[length - 1] == 'o' || str[length - 1] == 'O')
		{
			return 1 + countVowels(str, length - 1);
		}
			else if(str[length - 1] == 'u' || str[length - 1] == 'U')
		{
			return 1 + countVowels(str, length - 1);
		}
		else
			countVowels(str, length - 1);
	}
	else
		return 0;
}
int main()
{
		//Task no 4
	/*cout << power(2, 3) << endl;
	cout << power(2, 0) << endl;
	cout << power(-2, 3) << endl;
	cout << power(-2, 4) << endl;*/

		//Task no 5
	/*cout << product(2, 3) << endl;
	cout << product(-2, 3) << endl;
	cout << product(2, 0) << endl;
	cout << product(0, 3) << endl;
	cout << product(22, 3) << endl;*/

		//Task no 6
		//6.1
	//printChar('W', 5);
		//6.2
	//printPattern1('#', 4);
		//6.3
	//printPattern2('#', 6);

		//Task no 7
	/*cout << quotient(8, 2) << endl; 
	cout << quotient(10, 2) << endl;
	cout << quotient(200, 2) << endl;
	cout << quotient(80, 2) << endl;*/

		//Task no 8
	/*int arr[5] = { 1,2,8,4,5 };
	cout << "Largest number is : " << findLargest(arr, 0, 4) << endl;
	int arr1[5] = { 1,28,6,4,5 };
	cout << "Largest number is : " << findLargest(arr1, 0, 4) << endl;
	int arr2[5] = { 100,28,6,4,5 };
	cout << "Largest number is : " << findLargest(arr2, 0, 4) << endl;*/

		//Task no 9
	/*int arr[5] = { 1,2,8,4,5 };
	int arr1[5] = { 1,2,8,4,5 };
	cout << areArraysEqual(arr, 5, arr1, 5) << endl;
	int arr2[5] = { 1,2,8,4,5 };
	int arr3[7] = { 1,2,8,4,5.6,7 };
	cout << areArraysEqual(arr2, 5, arr3, 7) << endl;
	int arr4[3] = { 1,2,8 };
	int arr5[3] = { 4,2,8 };
	cout << areArraysEqual(arr4, 3, arr5, 3) << endl;*/

		//Task no 10
	char str[15] = "Hamza Ejaz";
	cout << countVowels(str, strlen(str)) << endl;
	return 0;
}