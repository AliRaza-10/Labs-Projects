#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 40;
class Student
{
private:
	int rollNo;
	char name[SIZE];
	int numQuizes;
	int* marks;
	int* totMarks;
	void inputMarks();
public:
	Student();//default constructor
	Student(int, char*, int);//overloaded constructor
	~Student();//destructor
	void getInputFromUser();
	void display() const;
	Student(const Student&);
	void storeInFile(ofstream&);
	void readFromFile(ifstream&);
};
	
#endif // !STUDENT_H
