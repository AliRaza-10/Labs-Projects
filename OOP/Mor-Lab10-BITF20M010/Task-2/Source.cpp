#include<iostream>
#include<fstream>
#include<cstring>
#include "student.h"
using namespace std;
void binaryToText()
{
	int numStudents;
	char ch[31];
	ifstream fin("students.dat",ios::binary);
	if (!fin)
	{
		cout << "File not found";
	}
	else
	{
		fin.seekg(0, ios::end);
		int numBytes = fin.tellg();
		int numStudents = numBytes / sizeof(Student);
		fin.seekg(ios::beg);
		fin.close();
		
		ofstream fout("newstudents.txt");
		if (!fout)
			{
				cout << "File not found";
			}
		else
		{
			Student temp;
			fout << numStudents << endl;
			for (int i = 0; i < numStudents; i++)
			{
				ifstream fin("students.dat");
				fin.seekg(sizeof(temp) * i, ios::beg);
				fin.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				fin.close();
				fout << temp.rollNo;
				fout << " ";
				fout << temp.name << endl;
				for (int j = 0; j < 5; j++)
				{
					fout << temp.marks[j] << " ";
				}
				fout << endl;
			}
		}
		fout.close();
	}
}
int main()
{

	binaryToText();
	return 0;
}