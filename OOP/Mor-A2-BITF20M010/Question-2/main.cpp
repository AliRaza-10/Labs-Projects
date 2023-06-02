// ALI RAZA BITF20M010
// FALL2020 IT MORNING
#include<iostream>
#include<string>
#include "ship.h"
#include "cruiseShip.h"
#include "cargoShip.h"
using namespace std;
int main()
{
	int n, choice, pass, cap;
	string nam, builtYear;
	cout << "How many Ships Object you want to create ";
	cin >> n;
	Ship** s = new Ship * [n];
	CruiseShip* cruShip=nullptr;
	CargoShip* carShip = nullptr;
	int *arr = new int [n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter 1 for CruiseShipe and 2 for CargoShip ";
		cin >> choice;
		while (choice < 1 || choice > 2)
		{
			cout << "Please Enter valid Number (1/2) ";
			cin >> choice;
		}
		arr[i] = choice;
		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter the name of Ship ";
			getline(cin, nam);
			cout << "Enter the built Year ";
			getline(cin, builtYear);
			cout << "Enter the number of Passengers ";
			cin >> pass;
			 cruShip = new CruiseShip(nam, builtYear, pass);
			s[i] = cruShip;
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Enter the name of Ship ";
			getline(cin, nam);
			cout << "Enter the built Year ";
			getline(cin, builtYear);
			cout << "Enter the number of Passengers ";
			cin >> pass;
			cout << "Enter the capacity of Ship ";
			cin >> cap;
			carShip = new CargoShip(nam, builtYear, pass, cap);
			s[i] = carShip;
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		s[i]->display();
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			delete cruShip;
			cruShip = nullptr;
		}
		else if (arr[i] == 2)
		{
			delete carShip;
			carShip = nullptr;
		}
		s[i] = nullptr;
	}
	delete[]arr;
	arr = nullptr;
	delete[]s;
	return 0;
}