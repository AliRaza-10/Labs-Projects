// ALI RAZA
// BITF20M010
// IT MORN F20
#include<iostream>
#include<string>
using namespace std;
struct Account
{
	string name;
	string address;
	string  city;
	string state;
	string zip;
	double balance;
	string lastPayment;
};
int main()
{
	int j, k;
	int SIZE;
	cout << "Enter size of array ";
	cin >> SIZE;
	Account *array = new Account[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter the Name " << i + 1 << " ";
		cin >> array[i].name;
		cout << "Enter the Adress " << i + 1 << " ";
		cin >> array[i].address;
		cout << "Enter the City " << i + 1 << " ";
		cin >> array[i].city;
		cout << "Enter the State " << i + 1 << " ";
		cin >> array[i].state;
		cout << " Enter the Zip " << i + 1 << " ";
		cin >> array[i].zip;
		cout << "Enter  the date of last Balance " << i + 1 << " ";
		cin >> array[i].balance;
		while (array[i].balance <= 0)
		{
			cout << "Error!!Enter the Balance again " << i + 1 << " ";
			cin >> array[i].balance;

		}
		cout << "Enter the date of  last Payemnt ";
		cin >> array[i].lastPayment;
	}
	cout << endl;
	int userSelection;
	do
	{
		cout << " ---Selection____" << endl;
		cout << " 1- View data of one Customer " << endl;
		cout << " 2 - View data of all Customers " << endl;
		cout << " 3 - Edit data of any Customer " << endl;
		cout << " 4 - Quit!!! " << endl;
		cin >> userSelection;
		switch (userSelection)
		{
		case 1:
			cout << " Which one customer you want to view data ";
			cin >> j;
			if (j < SIZE)
			{
				cout << "Customer # " << j + 1 << endl;
				cout << "Name " << array[j].name << endl;
				cout << "Address" << array[j].address << endl;
				cout << "City " << array[j].city << endl;
				cout << "State " << array[j].state << endl;
				cout << "Zip " << array[j].zip << endl;
				cout << "Balance " << array[j].balance << endl;
				cout << "Last Payment " << array[j].lastPayment << endl;
			}
			else
			{
				cout << "Data not found"<<endl;
			}
			break;

		case 2:
			for (int i = 0; i < SIZE; i++)
			{
				cout << " Customer # " << i + 1 << endl << endl;
				cout << "Name " << array[i].name << endl;
				cout << "Address " << array[i].address << endl;
				cout << "City " << array[i].city << endl;
				cout << "State" << array[i].state << endl;
				cout << "Zip " << array[i].zip << endl;
				cout << "Balance " << array[i].balance << endl;
				cout << "Last Payment" << array[i].lastPayment << endl;
			}
			break;
		case 3:
			cout << " Which one customer you want to change  data ";
			cin >> k;
			if (k < SIZE)
			{
				cout << "Enter the Name " << k + 1 << " ";
				cin >> array[k].name;
				cout << "Enter the Adress " << k + 1 << " ";
				cin >> array[k].address;
				cout << "Enter the City " << k + 1 << " ";
				cin >> array[k].city;
				cout << "Enter the State " << k + 1 << " ";
				cin >> array[k].state;
				cout << " Enter the Zip " << k + 1 << " ";
				cin >> array[k].zip;
				cout << "Enter  the date of last Balance " << k + 1 << " ";
				cin >> array[k].balance;
				while (array[k].balance <= 0)
				{
					cout << "Error!!Enter the Balance again " << k + 1 << " ";
					cin >> array[k].balance;

				}
				cout << "Enter the date of  last Payemnt ";
				cin >> array[k].lastPayment;
			}
			else
			{
				cout << "Customer data not found";
			}
			break;
		case 4:
			cout << "Quit the program"<<endl;
			break;

		}

	} while (userSelection !=4);
	delete[]array;
	array = NULL;

	return 0;
}