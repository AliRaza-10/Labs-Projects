#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include  "StudentMaxHeap.h"
using namespace std;
class Student 
{
	friend class StudentMaxHeap;
private:
	int rollNo; // Studentís roll number
	double cgpa; // Studentís CGPA
public:
	void setData(int r, double c)
	{
		rollNo = r;
		cgpa = c;
	}
	int getRollNo()
	{
		return rollNo;
	}
	double getCGPA()
	{
		return cgpa;
	}
	void displayStudent()
	{
		cout << rollNo << "\t" << cgpa << endl;
	}
};

#endif // !STUDENT_H
