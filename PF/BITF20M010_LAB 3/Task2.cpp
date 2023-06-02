#include <iostream>
using namespace std;
int main()
{
	float purchaseAmount, federalSalesTax, provincialSalesTax, totalSalesTax, totalSales;
	cout << "please enter the amount of purchase :";
	cin >> purchaseAmount;
	federalSalesTax = 0.06* purchaseAmount;
	provincialSalesTax = 0.04* purchaseAmount;
	totalSalesTax = federalSalesTax + provincialSalesTax;
	totalSales = totalSalesTax * purchaseAmount;
	cout << " the amount of federal sales tax is : " << federalSalesTax << endl;
	cout << " the amount of provincial sales tax is : " << provincialSalesTax << endl;
	cout << " the amount of total sales tax is : " << totalSalesTax << endl;
	cout << " the amount of total sales is : " << totalSales << endl;
	return 0;
}