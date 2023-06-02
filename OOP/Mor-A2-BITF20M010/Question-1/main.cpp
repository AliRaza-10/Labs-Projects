// ALI RAZA BITF20M010
//FALL 2020 MORNING
#include <iostream>
#include<fstream>
using namespace std;
int main()
{
	string fileName;
	fstream file;
	int total = 0;
	cout << "Enter the name of file  ";
	cin >> fileName;
	file.open(fileName,ios::out|ios::binary);
	if(!file)
	{
		cout << "Address not found ";
	}
	else
	{
		int num;
		cout << " Enter the Integer ";
		cin >> num;
		do
		{
			file.write(reinterpret_cast<char*>(&num), sizeof(num));
			cout << " Enter the Integer ";
			cin >> num;
			total++;
		} while (num!=0);
		cout << total << " integers stored in " << fileName << endl;
		file.close();
		cout << "Enter the name of input file  ";
		cin >> fileName;
		file.open(fileName, ios::in | ios::out | ios::binary);
		 file.seekg(0, ios::end);
		int numBytes = file.tellg();
		int number = numBytes / sizeof(int);
		char again,choice;
		int userSelection;
		do
		{
			cout << "Enter the position of number you want to access ";
			cin >>	userSelection;
			while (userSelection <= 0 || userSelection > number)
			{
				cout << "ERROR!! THE file have not this number ";
				cout << "Enter the position of number you want to access ";
				cin >> userSelection;
			}
			file.seekg(ios::beg);
			file.seekg(sizeof(int) * (userSelection - 1), ios::beg);
			 file.read(reinterpret_cast<char*>(&num), sizeof(num));
			 cout <<"Integer # "<< userSelection <<" is "<< num << endl;
			cout << "Do you want to edit this number ";
			cin >> again;
			if (again == 'Y' || again == 'y')
			{
				cout << "Enter New Integer ";
				cin >> num;
				file.seekp(sizeof(int) * (userSelection - 1), ios::beg);
				file.write(reinterpret_cast<char*>(&num), sizeof(num));
			}
			cout << " Quit(Y/N) ";
			cin >> choice;
		} while (choice=='N'||choice=='n');
		file.close();
	}
	
}
