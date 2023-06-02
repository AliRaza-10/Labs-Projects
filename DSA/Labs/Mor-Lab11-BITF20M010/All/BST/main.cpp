#include <iostream>
#include "BST.h"
#include "BSTNode.h"
using namespace std;
int main()
{
	//BST obj;
	//obj.insert(10);
	//obj.insert(1);
	//obj.insert(6);
	//obj.insert(11);
	//obj.insert(14);
	//obj.insert(0);
	//obj.inOrder();
	//obj.remove(1);
	//BST obj1;
	//obj1 = obj;
	//obj1.inOrder();
	////obj.remove(6);
	////obj.remove(10);
	////obj.remove(11);
	//obj.inOrder();
	//obj.preOrder();
	//obj.postOrder();
	//cout << "Min : " << obj.findMin();
	//cout << "\nMax : " << obj.findMax();
	//cout << endl << obj.recSearch(11) << endl;
	//cout << endl << obj.recSearch(111) << endl;
	
	//int choice;
	BST obj;
	//int val;
	/*do
	{
		cout << "1. Insert a value\n";
		cout << "2. Search a value\n";
		cout << "3. Remove a value\n";
		cout << "4. Display values(Pre - order)\n";
		cout << "5. Display values(In - order)\n";
		cout << "6. Display values(Post - order)\n";
		cout << "7. Quit\n";
		cout << "Enter your choice :";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter value : ";
			cin >> val;
			obj.insert(val);
		}
		else if (choice == 2)
		{
			cout << "Enter value you want to search: ";
			cin >> val;
			if (obj.search(val))
				cout << "Search successfully.\n";
			else
				cout << "Value not found.\n";

		}
		else if (choice == 3)
		{
			cout << "Enter value you want to remove: ";
			cin >> val;
			if (obj.remove(val))
				cout << "Removed successfully.\n";
			else
				cout << "Value not found.\n";
		}
		else if (choice == 4)
		{
			obj.preOrder();
		}
		else if (choice == 5)
		{
			obj.inOrder();
		}
		else if (choice == 6)
		{
			obj.postOrder();
		}
		else if (choice == 7)
		{
			cout << "Bye Bye!!\n";
		}
		else
			cout << "You ENtered wrong choice.\n";
	} while (choice != 7);*/

	obj.insert(5);
	obj.insert(3);
	obj.insert(2);
	obj.insert(8);
	obj.insert(7);
	obj.insert(-5);
	obj.insert(10);
	obj.insert(9);
	obj.insert(15);
	obj.insert(12);
	obj.inOrder();
	//cout << "Number of nodes are : " << obj.countNodes() << endl;
	//cout << "Height of tree is : " << obj.getHeight() << endl;
	
	cout << obj.findMinRec() << endl;
	cout << obj.findMaxRec() << endl;

	/*int arr[11];
	int start = 0, end = 10;*/
	/*arr[0] = 7;
	arr[1] = 10;
	arr[2] = 14;
	arr[3] = 20;
	arr[4] = 36;
	arr[5] = 47;
	arr[6] = 55;
	arr[7] = 63;
	arr[8] = 72;
	arr[9] = 86;
	arr[10] = 92;*/
	/*cout << "Enter 10 values : ";
	for (int i = 0; i <= end; i++)
		cin >> arr[i];
	BST obj1;
	obj1.createBalancedTree(arr, start, end);
	cout << "Balanced tree is : \n";
	obj1.inOrder();*/
	return 0;
}