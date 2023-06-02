#include<iostream>
using namespace std;
int main()
{
	int length1, length2, length3;
	cout << " please enter the first length of the triangle : ";
	cin >> length1;
	cout << " please enter the second length of the triangle : ";
	cin >> length2;
	cout << " please enter the third length of the triangle : ";
	cin >>length3;
    if (length1 * length1 + length2 * length2 == length3 * length3)
	{		
		cout << " triangle is right triangle. ";
    }
   else if (length1 * length1 + length3 * length3 == length2 * length2)
   {
		cout << " triangle is right triangle. ";
   }
   else if (length2 * length2 + length3 * length3 == length1 * length1)
   {
		cout << " triangle is right triangle. ";
   }
   else
	{
		cout << " triangle is not right triangle. ";
	}
	return 0;
}