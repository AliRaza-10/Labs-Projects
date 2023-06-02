#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "ship.h"
#include<iostream>
#include<string>
using namespace std;
class CruiseShip :public Ship
{
private:
	int numOfPassengers;
public:
	CruiseShip(string, string, int);
	void setPassengers(int);
	int getPassengers();
	void display();
};
#endif

