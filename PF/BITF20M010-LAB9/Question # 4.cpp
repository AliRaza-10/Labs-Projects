#include<iostream>
using namespace std;
int employees();
int days(int missedDays);
double calculateAvrg(int employees, int days);
int main()
{
	int employee=employees();
	int missedDays =days(employee);
	cout<<"Average Number of Days a Complany's Employees absent are = "<<calculateAvrg(employee,missedDays);	
}
int employees()
{
	int numberOfEmployees;
	cout<<"Enter the number of Employees in the Company  : ";
	cin>>numberOfEmployees;
	while(numberOfEmployees<1)
	{
		cout<<"Enter the number of Employees greater than 1 : ";
		cin>>numberOfEmployees;
	}
	return numberOfEmployees;
}
int days(int missedDays)
{	
	int total = 0;
	int days;
	for(int i = 1; i<=missedDays;i++)
	{
		cout<<"Enter the missed days of Employee "<<i<<" ";
		cin>>days;
		while(days<0)
		{
			cout<<"Enter again missed days : ";
			cin>>days;
		}
		total+=days;
	}
	return total;
}
double calculateAvrg(int employees, int days)
{
	double average;
	average = static_cast<double>(days)/(employees);
	return average;
}
