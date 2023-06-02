//Muhammad Waqas Ud Din
//Bitf20m013
//IT-Morning
#include <iostream>
#include "PacketManager.h"
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	//Task 1.1
	string name;
	cout << "Enter name of input file : ";
	cin >> name;
	ifstream fin;
	fin.open(name);
	while (fin.fail())
	{
		cout << "ERROR: The file " << name << " does not exist!! ";
		cout << "\n\nRe-enter the file name: ";
		cin >> name;
		fin.open(name);
	}
	if(fin)
	{
		PacketManager obj1(fin);
		cout << "\nPackets originally read from the file are: \n";
		obj1.displayPackets();
		obj1.extractMessage();
		cout << "\nThe order of packets after extracting the message: \n";
		obj1.displayPackets();
		obj1.displayMessage();
		fin.close();
	}
	return 0;
}