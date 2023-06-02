//ALI RAZA
//BITF20M010
//BS IT MORNING F20
#include<iostream>
#include<string>
using namespace std;
struct Employee
{
	int idNumber;
	string name;
	double salary;
};
int main()
{
	int n;
	int flag = 1;
	int k=0;
	std::cout << "Enter positive Integer ";
	cin >> n;
	Employee* ptr = new Employee[n];
	cout << "Enter the Id Number for Employee # 1" << " ";
	cin >> ptr[0].idNumber;
	cout << "Enter the Name of Employee # 1 " << " ";
	cin >> ptr[0].name;
	cout << "Enter the Salary of Employee # 1 " << " ";
	cin >> ptr[0].salary;
	cout << ptr[0].name << " has Id Number " << ptr[0].idNumber << " with Salary " << ptr[0].salary << endl;
for (int i = 1 ; i < n; i++)
{

	cout << "Enter the Id Number for Employee # " << i + 1 << " ";
	cin >> ptr[i].idNumber;
	while(k<i)
	{
		if (ptr[i].idNumber == ptr[k].idNumber)
		{
			cout << "You already Enter this Id Number!!Enter again Id number ";
			cin >> ptr[i].idNumber;
		}
		k++;
	}
	cout << "Enter the Name of Employee " << i + 1 << " ";
	cin >> ptr[i].name;
	cout << "Enter the Salary of Employee " << i + 1 << " ";
	cin >> ptr[i].salary;

	cout << ptr[i].name << " has Id Number " << ptr[i].idNumber << " with Salary " << ptr[i].salary << endl;
}
cout<<"----------------------------------------------";
cout << endl;
int choice=0, number, start, end;
cout << "___Select the ONE ___" << endl;
cout << " 1 - Search for ID " << endl;
cout << " 2 - Search for Salary " << endl;
cin >> choice;

switch (choice)
{
case 1:
	cout << " Enter the number for Id Search ";
	cin >> number;
	for (int i = 0; i < n; i++)
	{
		if (number == ptr[i].idNumber)
		{
			cout <<"Id Number " << ptr[i].idNumber <<endl;
			cout <<" Name "<< ptr[i].name<< endl;
			cout <<" Salary "<< ptr[i].salary << endl;
			flag++;
			
		}

	}
	if(flag==1)
	{
			cout << "Your Id Not Matched ";
	}
	break;
case 2:
	cout << " Enter the starting value ";
	cin >> start;
	cout << " Enter the ending value ";
	cin >> end;
	for (int i = 0; i < n; i++)
	{
		if (ptr[i].salary >= start && ptr[i].salary <= end)
		{
			cout <<"Id Number " << ptr[i].idNumber <<endl;
			cout <<" Name "<< ptr[i].name<< endl;
			cout <<" Salary "<< ptr[i].salary << endl;
			flag = 0;
		}

	}
	if(flag)
		{
			cout << " Error!! you entered salary out of range ";
		}
	break;
default:
	cout << "Error!! Please enter 1-2";
	break;
}
	//DEALLOCATION
			delete[]ptr;
			ptr=NULL;
	}



