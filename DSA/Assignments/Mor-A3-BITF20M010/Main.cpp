// Muhammad Waqas Ud din
// BITF20M013
// IT Morning
#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList list1;
	int choice;
	cout << "\t1. Insert values\n";
	cout << "\t2. Remove a values\n";
	cout << "\t3. Search s values\n";
	cout << "\t4. Display the Linked List\n";
	cout << "\t5. Sort the Linked List\n";
	cout << "\t6. Reverse the Linked List\n";
	cout << "\t7. Empty the Linked List\n";
	cout << "\t8. Exit\n";
	do
	{
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int val;
			cout << "Enter the values to be inserted: ";
			
			do
			{
				cin >> val;
				list1.insert(val);
			} while (getchar() != '\n');
			break;
		case 2:
			int rem;
			cout << "Enter the value to be removed: ";
			cin >> rem;
			if (list1.remove(rem))
				cout << rem << " has been removed from the list\n";
			else
				cout << "ERROR: " << rem << " is not found in the linked list \n";
			break;
		case 3:
			int key;
			cout << "Enter the value to be searched: ";
			cin >> key;
			if (list1.search(key))
				cout << "The number " << key << " is present in the Linked List!\n";
			else
				cout << "The number " << key << " is not present in the Linked List!\n";
			break;
		case 4:
			list1.display();
			break;
		case 5:
			list1.sort();
			cout << "The list has been sorted!\n";
			list1.display();
			break;
		case 6:
			list1.reverse();
			cout << "The list has been reversed!\n";
			list1.display();
			break;
		case 7:
			list1.emptyLinkedList();
			cout << "All the values have been removed from the linked list!\n";
			break;
		case 8:
			cout << "Bye bye!!\n";
			break;
		default:
			cout << "\nEnter valid choice.";
			break;
		}
	} while (choice != 8);
	return 0;
}