#include <iostream>
#include <string>
#include "StudentBST.h"
using namespace std;
int main()
{
	int val,choice;
	int rNo;
	double cgpa;
	string name;
	StudentBST obj;
	do
	{
		cout << "\n1. Insert a student\n";
		cout << "2. Search a student\n";
		cout << "3. Remove a student\n";
		cout << "4. See the list of all students (sorted by Roll No.)\n";
		cout << "5. Quit\n";
		cout << "Enter your choice :";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nEnter name of student : ";
			cin.ignore();
			getline(cin, name);
			cout << "ENter ROll number : ";
			cin >> rNo;
			cout << "Enter CGPA : ";
			cin >> cgpa;
			obj.insert(rNo, name, cgpa);
		}
		else if (choice == 2)
		{
			cout << "\nENter ROll number you want to search : ";
			cin >> rNo;
			obj.search(rNo);
		}
		else if (choice == 3)
		{
			cout << "\nEnter ROll number you want to remove : ";
			cin >> rNo;
			obj.remove(rNo);
		}
		else if (choice == 4)
		{
			obj.inOrder();
		}
		else
			cout << "Bye Bye!!\n";
	} while (choice < 5);

}