#ifndef SHIP_H
#define SHIP_H
#include<iostream>
#include<string>
using namespace std;
class Ship
{
private:
	string name;
	string year;
public:
	Ship(string, string);
	void setShipName(string);
	void setShipYear(string);
	string getShipName();
	string getShipYear();
	virtual void display();

};
#endif
