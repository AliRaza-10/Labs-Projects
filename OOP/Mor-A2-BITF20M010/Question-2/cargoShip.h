#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include"ship.h"
#include<iostream>
#include<string>
using namespace std;
class CargoShip :public Ship
{
private:
	int cargoCapacity;
public:
	CargoShip(string, string, int, int);
	void setCapacity(int);
	int getCapacity();
	void display();
};
#endif


