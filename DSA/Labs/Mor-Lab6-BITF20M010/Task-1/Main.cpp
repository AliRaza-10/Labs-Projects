// Muhammad Waqas Ud Din
// BITF20M013
// IT-Morning
#include <iostream>
#include "Deque.h"
using namespace std; 
int main()
{
	int size;
	cout << "Enter the size of Deque : ";
	cin >> size;
	Deque d1(size);
	int choice;
	cout << "1. Insert value at Front\n";
	cout << "2. Insert value at Back\n";
	cout << "3. Remove value from Front\n";
	cout << "4. Remove value from Back\n";
	cout << "5. Display the Deque\n";
	cout << "6. Make the Deque Empty\n";
	cout << "7. Exit\n";
	cout << "Enter your choice : ";
	cin >> choice;
	do
	{
		int val=0;
		if (choice == 1)
		{
			if (!d1.isFull())
			{
				cout << "Enter value you want to insert : ";
				cin >> val;
				d1.insertAtFront(val);
			}
			else
			{
				cout << "List is full.\n";
			}
		}
		else if (choice == 2)
		{
			if (!d1.isFull())
			{
				cout << "Enter value you want to insert : ";
				cin >> val;
				d1.insertAtBack(val);
			}
			else
			{
				cout << "list is full.\n";
			}
		}
		else if (choice == 3)
		{
			if (!d1.isEmpty())
			{
				d1.removeFromFront(val);
				cout << "The value is : " << val << endl;
			}
			else
			{
				cout << "List is empty.\n";
			}

		}
		else if (choice == 4)
		{
			if (!d1.isEmpty())
			{
				d1.removeFromBack(val);
				cout << "The value is : " << val << endl;
			}
			else
			{
				cout << "List is empty.\n";
			}
		}
		else if (choice == 5)
		{
			d1.display();
		}
		else if (choice == 6)
		{
			d1.makeEmpty();
		}	
		cout << "Enter your choice : ";
		cin >> choice;
	}while (choice != 7);
	
	return 0;
}