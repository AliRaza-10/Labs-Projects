#include<iostream>
using namespace std;
int main()
{
	int marks;
	cout << " Please enter the marks: ";
	cin >> marks;
	if (marks < 0)
	{
		cout << " Invalid ";

	}
	if (marks >= 0)
	{
		if (marks <= 100)
		{
			if (marks >= 50)
			{
				cout << " you are pass. ";
			}
			if (marks < 50)
			{
				cout << " you are fail. ";
			}

		}
		if (marks > 100)
		{
			cout << " you get an invalid number. ";
		}
	}

	return 0;
}