#include <iostream>
#include <string>
#include <ctime>
#include "HashTable.h"
using namespace std;
void initialize()
{
	srand(time(NULL));
}
int getRandomNumber(int start, int end)
{
	return (rand() % (end - start + 1)) + start;
}
int main()
{
	int s;
	int n;
	bool flag = true;
	HashTable object(200);
	int count = 0;
	initialize();
	while (count < 50 &&flag == true)
	{
		n = getRandomNumber(1, 100);
		flag = object.insert(n);
	}
	//cout << object.loadFactor() << endl;
	object.display();

	//int size = 6;
	//cout << "Enter the size of Hash Table : ";
	//cin >> size;
	//HashTable obj(size);
	//string name;
	/*obj.insert("waqas");
	obj.insert("Ali");
	obj.insert("Usman");
	obj.insert("ABC");
	obj.insert("Usman");
	obj.display();

	obj.remove("waqas");
	obj.display();*/

	/*int choice = 0;
	do
	{
		cout << "\n1. Insert a name\n";
		cout << "2. Search for a name\n";
		cout << "3. Remove a name\n";
		cout << "4. Display the Hash Table\n";
		cout << "5. Display Load Factor of the table\n";
		cout << "6. Exit\n";
		cout << "Enter your choice : ";
		cin >> choice;
		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter Name : ";
			getline(cin,name);
			if (obj.insert(name))
				cout << "\nInsert Successfully.\n\n";
			else
				cout << "\nNot Insert Successfully.\n\n";
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Enter Name : ";
			getline(cin, name);
			if (obj.search(name))
				cout << "\nSearch Successfully.\n\n";
			else
				cout << "\nNot Search Successfully.\n\n";
		}
		else if (choice == 3)
		{
			if (obj.remove(name))
				cout << "\nRemoved Successfully. " << name << endl << endl;
			else
				cout << "\nNot Removed Successfully.\n\n";
		}
		else if (choice == 4)
		{
			obj.display();
		}
		else if (choice == 5)
		{
			cout << "Load Factor : " << obj.loadFactor() << endl;
		}
		else if (choice == 6)
		{
			cout << "BYE BYE!!\n";
		}
		else
			cout << "Invalid choice.\n";
	} while (choice != 6);*/

}