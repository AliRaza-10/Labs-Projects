//ALI RAZA
// BITF20M010
// IT MORN F20
#include<iostream>
using namespace std;
struct MonthlyBudget
{
	double housing ;
	double utilities ;
	double expense ;
	double transportation ;
	double food ;
	double medical ;
	double insurance ;
	double entertainment;
	double clothing ;
	double miscellaneous;
};
MonthlyBudget getInfo()
{
	
	MonthlyBudget p;
	cout << "Enter amount spent in Housing ";
	cin >> p.housing;
	cout << "Enter amount spent in Utilities ";
	cin >> p.utilities;
	cout << "Enter amount spent in Household Expenses ";
	cin >> p.expense;
	cout << "Enter amount spent in Transportation ";
	cin >> p.transportation;
	cout << "Enter amount spent in Food ";
	cin >> p.food;
	cout << "Enter amount spent in Medical ";
	cin >> p.medical;
	cout << "Enter amount spent in Insurance ";
	cin >> p.insurance;
	cout << "Enter amount spent in Entertainment ";
	cin >> p.entertainment;
	cout << "Enter amount spent in Clothing ";
	cin >> p.clothing;
	cout << "Enter amount spent in Miscellaneous ";
	cin >> p.miscellaneous;
	return p;

}
void display(MonthlyBudget k, MonthlyBudget *m)
{
	double tot1;
	double tot2;
	if (m->housing < k.housing)
	{
		cout << "Your housing expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your housing expenses under the budget"<<endl;
	}
	if (m->utilities < k.utilities)
	{
		cout << "Your Utility expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your Utility expenses under  the budget"<<endl;
	}
	if (m->expense <k.expense)
	{
		cout << "Your household expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your household expenses under the budget"<<endl;
	}
	if (m->transportation < k.transportation)
	{
		cout << "Your transportation expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your Transportation expenses under the budget"<<endl;
	}
	if (m->food < k.food)
	{
		cout << "Your food expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your food expenses under the budget"<<endl;
	}
	if (m->medical < k.medical)
	{
		cout << "Your medical expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your medical expenses under the budget"<<endl;
	}
	if (m->insurance < k.insurance)
	{
		cout << "Your insurance expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your insurance expenses under the budget"<<endl;
	}
	if (m->entertainment < k.entertainment)
	{
		cout << "Your entertainment expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your entertainment expenses under the budget"<<endl;
	}
	if (m->clothing < k.clothing)
	{
		cout << "Your clothing expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your clothing expenses under the budget"<<endl;
	}
	if (m->miscellaneous < k.miscellaneous)
	{
		cout << "Your miscellaneous expenses over the budget"<<endl;
	}
	else
	{
		cout << "Your miscellaneous expenses under the budget"<<endl;
	}
	
	tot1 = m->housing + m->utilities + m->expense + m->transportation + m->food + m->medical + m->insurance + m->entertainment + m->clothing + m->miscellaneous;
	tot2 = k.housing + k.utilities + k.expense + k.transportation + k.food + k.medical + k.insurance + k.entertainment + k.clothing + k.miscellaneous;
	cout << endl;
	if (tot1 < tot2)
	{
		cout << "Your total expenses are over the budget which is " << tot1;
	}
	else
	{
		cout<<"Your total expenses are under the budget which is " << tot2;
	}
}

int main()
{
	MonthlyBudget b,c;
	b.housing = 500.00;
	b.utilities = 150.00;
	b.expense = 65.00;
	b. transportation = 50.00;
	b. food = 250.00;
	b. medical = 30.00;
	b. insurance = 100.00;
	b. entertainment = 150.00;
	b.clothing = 75.00;
	b. miscellaneous = 50.00;
	c =	getInfo();
	display(c,&b );
}
