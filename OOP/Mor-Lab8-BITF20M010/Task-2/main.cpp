//ALI RAZA BITF20M010
//MORN FALL 2020
#include <iostream>
#include "Fraction.h"
using namespace std;	
int main()
{
	Fraction f;
	f.setFraction(6,8); //setfraction
	f.display();  //display
	Fraction f1(12,23);
	Fraction f2(7,4);
	Fraction f3;
	Fraction f4;
	//Section 2.4
	cout<<f1.convertToDouble();

	//section 2.5
	f3 = f1+f2;
	f1.display();
	f2.display();
	f3.display();

 	//section 2.6
	f3 = f1+6;
	f1.display();
	f3.display();

	//section 2.7
	f3 = 2+f2;
	f2.display();
	f3.display();

}
