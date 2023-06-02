#include <iostream>
using namespace std;
int main()
{ 
	float totalSale, annualProfit;
	cout << "please enter the amount of total sales :";
	cin >> totalSale;
	annualProfit = 0.13 * totalSale;
	cout << " the amount of annual profit is :" << annualProfit;
	return 0;
}