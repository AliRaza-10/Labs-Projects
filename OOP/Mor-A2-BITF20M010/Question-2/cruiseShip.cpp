// ALI RAZA BITF20M010
// FALL2020 IT MORNING
#include "cruiseShip.h"
#include<iostream>
#include<string>
using namespace std;
CruiseShip::CruiseShip(string n, string y, int p) :Ship(n, y)
{
	numOfPassengers = p;
}
void CruiseShip::setPassengers(int p)
{
	numOfPassengers = p;
}

int CruiseShip::getPassengers()
{
	return numOfPassengers;
}
void CruiseShip::display()
{
	cout << "Ship Name : " << getShipName() << endl;
	cout << "The Ship Have Passengers : " << getPassengers() << endl;
}