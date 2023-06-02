// ALI RAZA BITF20M010
// FALL2020 IT MORNING
#include "cargoShip.h"
#include<iostream>
using namespace std;
CargoShip::CargoShip(string n, string y, int p, int c) : Ship(n, y)
{
	cargoCapacity = c;
}
void CargoShip::setCapacity(int c)
{
	cargoCapacity = c;
}
int CargoShip::getCapacity()
{
	return cargoCapacity;
}
void CargoShip::display()
{
	cout << "Ship Name : " << getShipName() << endl;
	cout << "Ship Has Capacity: " << getCapacity() << endl;
}