#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	ofstream fileOutput;
	int semester,courses,noOfStudents;
	string name,rollNum;
	fileOutput.open("D:\\BITF20M010-LAB8\\StudentData.txt");
	if(fileOutput.fail())
	{
		cout << "Error! Enter the Correct Address " << endl;
	}
	else
	{
	    fileOutput << "Student Management System: " << endl;
	    fileOutput << "****************************************************************" << endl;
   	    fileOutput << "ROLL no " << "\t" << "Name " << "   \t" << "Semester" << "\t" << "No. of courses " << endl;
	    fileOutput << "****************************************************************" << endl;
	    fileOutput<<endl<<endl;
	    cout<<"Enter the number of students: ";
	    cin >> noOfStudents;
	   while(noOfStudents<2)
	   {
	   	cout<<"Please enter the no 0f students greater than 2! ";
	   	cin>>noOfStudents;
	   }
	   for(int i = 1; i <= noOfStudents ; i++)
	  {
	   cout << "Enter the roll number of "<<i<<" student: " ;
	   cin >> rollNum;
	   cout << "Enter the name of "<<i<<" student: ";
	   cin >> name;
	   cout << "Enter the current semester of "<<i<<" student  : ";
	   cin >> semester;
	   while ( semester < 1 || semester > 8)
       {
       cout << " Error! Enter the semester btw (1-8) : ";
       cin >>semester;
       }
	   cout << "Enter the courses of "<<i<<" student: ";
	   cin >> courses;
	   fileOutput << rollNum<< setw(11) << name <<setw(15) << semester << setw(18) << courses <<endl<<endl;
	  }
	  cout<<"Done!!";
	   fileOutput << "****************************************************************";
	   fileOutput.close();
   }
	
	return 0;
}
