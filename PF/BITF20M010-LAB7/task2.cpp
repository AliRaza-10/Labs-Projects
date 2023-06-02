#include <iostream>
using namespace std;

int leapYear(int numb)
 {
	switch (numb)
	{
	case 1:
		cout << " 31 days \n";
		break;
	case 2:
		cout << " 29 days\n";
		break;
	case 3:
		cout << " 31 days\n";
		break;
	case 4:
		cout << " 30 days\n";
		break;
	case 5:
		cout << " 31 days\n";
		break;
	case 6:
		cout << " 30 days\n";
		break;
	case 7:
		cout << " 31 days\n";
		break;
	case 8:
		cout << " 31 days\n";
		break;
	case 9:
		cout << " 30 days\n";
		break;
	case 10:
		cout << " 31 days\n";
		break;
	case 11:
		cout << " 30 days\n";
		break;
	case 12:
		cout << " 31 days\n";
		break;
	}
}
int main() {
		int month;
		int years;
	cout << "please enter the month: ";
	cin >> month;
	cout << "please enter the year : ";
	cin >> years;

	if (years % 100 == 0) 
	{
		if (years % 400 == 0) 
		{
			leapYear(month);
		}
	}
	else if (years % 4 == 0) 
	{
		leapYear(month);
	}
	else
	{
		switch (month)
		{
		case 1:
			cout << " 31 days"<<endl;
			break;
		case 2:
			cout << " 28 days"<<endl;
			break;
		case 3:
			cout << " 31 days"<<endl;
			break;
		case 4:
			cout << " 30 days"<<endl;
			break;
		case 5:
			cout << " 31 days"<<endl;
			break;
		case 6:
			cout << " 30 days"<<endl;
			break;
		case 7:
			cout << " 31 days"<<endl;
			break;
		case 8:
			cout << " 31 days"<<endl;
			break;
		case 9:
			cout << " 30 days"<<endl;
			break;
		case 10:
			cout << " 31 days"<<endl;
			break;
		case 11:
			cout << " 30 days"<<endl;
			break;
		case 12:
			cout << " 31 days"<<endl;
			break;
		}
	}
}
