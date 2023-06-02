#include <iostream>
#include <cstring>
#include <fstream>
#include "Student.h"
using namespace std;
Student::Student()
{
	cout << "Default constructor : \n";
	rollNo = 0;
	strcpy(name, "");
	numQuizes = 0;
	marks = NULL;
	totMarks = NULL;
}
Student::Student(int roll, char* n, int quiz)
{
	//cout << "Overloaded constructor : \n";
	rollNo = roll;
	strcpy(name, n);
	numQuizes = quiz;
	marks = new int[numQuizes];
	for (int i = 0; i < numQuizes; i++)
	{
		marks[i] = 0;
	}
	totMarks = new int[numQuizes];
	for (int i = 0; i < numQuizes; i++)
	{
		totMarks[i] = 0;
	}
}
Student::~Student()
{
	//cout << "Destructor : \n";
	if (marks != NULL)
	{
		delete[]marks;
		marks = NULL;
	}
	if (totMarks != NULL)
	{
		delete[]totMarks;
		totMarks = NULL;
	}
}
void Student::getInputFromUser()
{
	cout << "Enter Roll Number of Students : ";
	cin >> rollNo;
	cout << "Enter name of the student : ";
	cin.ignore();
	cin.getline(name, SIZE);
	cout << "Enter Total number of quizes : ";
	cin >> numQuizes;

	if (totMarks != NULL)
	{
		delete[]totMarks;
		totMarks = NULL;
	}
	totMarks = new int[numQuizes];
	if (marks != NULL)
	{
		delete[]marks;
		marks = NULL;
	}
	marks = new int[numQuizes];
	inputMarks();
}
void Student::inputMarks()
{
	for (int i = 0; i < numQuizes; i++)
	{
		cout << "Enter total marks of quiz # " << i + 1 << " : ";
		cin >> totMarks[i];
		while (totMarks[i]<=0)
		{
			cout << "Enter valid total marks of quiz # " << i + 1 << " : ";
			cin >> totMarks[i];
		}
		cout << "Enter obtained marks of quiz # " << i + 1 << " : ";
		cin >> marks[i];
		while (marks[i] > totMarks[i] || marks[i] < 0)
		{
			cout << "Enter valid obtained marks of quiz # " << i + 1 << " : ";
			cin >> marks[i];
		}
		cout << "\n";
	}
}
void Student::display() const
{
	int max = marks[0], min = marks[0],tot1=0,tot2=0;
	double maxPercentage = 0.0 ,minPercentage=0.0;
	cout << "Roll number of student : " << rollNo << endl;
	cout << "Name of Student : " << name << endl;
	for (int i = 0; i < numQuizes; i++)
	{
		cout << "Marks obtained in quiz # " << i + 1 << " : " << marks[i] << endl;
		if (marks[i] > max)
		{
			max = marks[i];
			tot1 = i;
		}
		
		else if (marks[i] < min)
		{
			min = marks[i];
			tot2 = i;
		}	
	}
	maxPercentage = (static_cast<double>(max) / static_cast<double>(totMarks[tot1])) * 100;
	minPercentage = (static_cast<double>(min) / static_cast<double>(totMarks[tot2])) * 100;
	cout << "Highest percentage in all quizes is : " << maxPercentage << endl;
	cout << "Lowest percentage in all quizes is : " << minPercentage << endl;
}
Student::Student(const Student& orig)
{
	//cout << "Copy Constructor : \n";
	rollNo = orig.rollNo;
	strcpy(name, orig.name);
	numQuizes = orig.numQuizes;
	if (orig.marks != NULL)
	{
		marks = new int[numQuizes];
		for (int i = 0; i < numQuizes; i++)
		{
			marks[i] = orig.marks[i];
		}
	}
	else
	{
		marks = NULL;
		//totMarks = NULL;
	}

	if (orig.totMarks != NULL)
	{
		totMarks = new int[numQuizes];
		for (int i = 0; i < numQuizes; i++)
		{
			totMarks[i] = orig.totMarks[i];
		}
	}
	else
	{
		//marks = NULL;
		totMarks = NULL;
	}
}
void Student::storeInFile(ofstream& fout)
{
	fout << rollNo << endl;
	fout << name << endl;
	fout << numQuizes << endl;
	for (int i = 0; i < numQuizes; i++)
	{
		fout << marks[i] << totMarks[i] << endl;
	}
}
void Student::readFromFile(ifstream& fin)
{
	
}
