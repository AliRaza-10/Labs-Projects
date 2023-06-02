// ALI RAZA BITF20M010
// FALL2020 IT MORNING
#include "ship.h"
#include<iostream>
#include<string>
using namespace std;
Ship::Ship(string n, string y)
{
	name = n;
	year = y;
}
void Ship::setShipName(string n)
{
	name = n;
}
void Ship::setShipYear(string y)
{
	year = y;
}
string Ship::getShipName()
{
	return name;
}
string Ship::getShipYear()
{
	return year;
}
void Ship::display()
{
	cout << "Ship Name: " << getShipName() << endl;
	cout << "Ship Year: " << getShipYear() << endl;
}