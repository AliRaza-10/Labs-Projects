//ALI RAZA BITF20M010
//MORN FALL 2020
#include<iostream>
#include "Fraction.h"	
using namespace std; 
	Fraction::Fraction(int a , int b)
	{
		num = a;
		den = b;
	}
	Fraction::Fraction()
	{
		num = 1;
		den = 1;
	}
	void Fraction :: setFraction(int a , int b)
	{
		num = a;
		den = b;
	}
	void Fraction::display()const
	{
		cout<<num<<"/"<<den<<endl;
	}
	 double Fraction :: convertToDouble()
	{
		return static_cast<double> (num)/den;
	}
	Fraction Fraction ::operator+ (Fraction t)
	{
		Fraction temp;
		temp.num = (num*t.den) +(t.num*den);
		temp.den = den*t.den;
		return temp; 
	}
	Fraction Fraction:: operator+ (int val)const
	{
		Fraction temp;
		temp.num = num + val;
		temp.den = den+ val;
		return temp;
	}
	Fraction operator+ (int val, const Fraction& p)
	{
		Fraction temp;
		temp.num = val + p.num; ;
		temp.den = val + p.den ;
		return temp;
	}