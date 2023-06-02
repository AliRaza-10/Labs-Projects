#include<iostream>
using namespace std;
// function prototypes
bool isValid (int num, int start , int end);
int getlength();
int getwidth();
void calculateArea (int length,int width, int& area);
void displayArea (int area);
int main()
{
	int area;
	int l=getlength();
	int w =getwidth();
	calculateArea(l,w,area);
	displayArea(area);
}
bool isValid (int num, int start , int end)	//function definition
{
	if( num >= start && num <= end )
	return 1;
	else
	return 0; 
	
}
int getlength()	//function definition
{
	int length;   // variable declaration
	cout<<"Enter the Length of Rectangle from range (5-500) : ";
	cin>>length;
	while(!(isValid(length,5,500)))
	{
		cout <<"Enter the length again in range of (5-500) : "  ;
		cin >> length ;
		
	}
	return length;	
}
int getwidth()	//function definition
{
	int width;	// variable declaration
	cout<<"Enter the Width of Rectangle from range (8-200) : ";
	cin>>width;
   	while(!(isValid(width,8,200)))
     {
     	cout << "Enter the width again in range (8-200) : " ;
     	cin >>width ;
	 }
	return width;
}
void calculateArea (int length,int width, int& area)
{
	area = length*width;	 
	
}
void displayArea (int area)
{
	cout<<"Area of Rectangle are "<<area;
}
