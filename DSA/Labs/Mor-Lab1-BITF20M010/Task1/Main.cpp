#include <iostream>
#include <cstring>
#include <fstream>
#include "Student.h"
using namespace std;
void printStudent(Student st)
{
	st.display();
}

int main()
{
	//char name[SIZE] = "Waqas";
	//Student st1;
	//st1.getInputFromUser();
	//cout << endl;
	//st1.display();
	//printStudent(st1);
	int n;
	cout << "Enter number of student : ";
	cin >> n;
	Student* st = new Student[n];
	for (int i = 0; i < n; i++)
	{
		st[i].getInputFromUser();
	}
	ofstream fout;
	fout.open("data.txt");
	if (!fout)
	{
		cout << "File not created \n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			st[i].storeInFile(fout);
		}
		fout.close();
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		st[i].display();
	}
	ifstream fin;
	fin.open("data.txt");
	if (!fin)
	{
		cout << "File not found.\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			st[i].readFromFile(fin);
		}
	}
	delete[]st;
	st = NULL;
	return 0;
}