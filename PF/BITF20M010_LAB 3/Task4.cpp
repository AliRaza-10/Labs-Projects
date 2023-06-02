#include <iostream>
using namespace std;
int main()
{
	int numberOfEggs, extraEggs, dozenEggs;

	cout << "Please enter total number of Eggs :";
	cin >> numberOfEggs;

	dozenEggs = numberOfEggs / 12;
	extraEggs = numberOfEggs % 12;

	cout << "total Dozens of Eggs are : " << dozenEggs << endl;
	cout << "total Extra Eggs are : " << extraEggs << endl;

	return 0;
}