#include <iostream>
using namespace std;
int main()
{
	float kilometersDriven, petrolUsed, kmpl;

	cout << "Please enter the distance in kilometers :";
	cin >> kilometersDriven;

	cout << "Please enter the amount of petrol used in liters :";
	cin >> petrolUsed;

	kmpl = kilometersDriven / petrolUsed;
	cout << "the car's KMPL is: " << kmpl;
	return 0;
}