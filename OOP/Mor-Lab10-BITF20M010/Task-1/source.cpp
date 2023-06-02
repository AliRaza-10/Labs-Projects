#include<iostream>
#include<fstream>
#include<cstring>
#include "stud.h"
using namespace std;
void textToBinary()
{
	int numStudents;
	char ch[31];
	ifstream fin("students.txt");
	if (!fin)
	{
		cout << "File not found";
	}
	else
	{
		fin >> numStudents;
		Student* st = new Student[numStudents];
		for (int i = 0; i < numStudents; i++)
		{
			fin >> st[i].rollNo;
			fin.ignore();
			fin.getline(ch, 31);
			strcpy(st[i].name, ch);
			for (int k = 0; k < 5; k++)
			{
				fin >> st[i].marks[k];
			}
		}
		fin.close();
		ofstream fout("students.dat", ios::binary);
		if (!fout)
		{
			cout << "File not found";
		}
		else
		{
			fout.write(reinterpret_cast<char*>(st), sizeof(Student) * numStudents);
			fout.close();
		}
		delete[]st;
		st = nullptr;
	}
	
}
int main()
{

	textToBinary();
	return 0;
}