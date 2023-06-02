#include <iostream>
#include "StudentMaxHeap.h"
#include "Student.h"
using namespace std;
void display(StudentMaxHeap* st, int r, double c)
{
	cout << "Removed student : " << r << "\t" << c << endl;
	st->levelOrder();
}
void heapSort(Student* st, int n) // must be implemented as a global function
{
	StudentMaxHeap mH(n);
	mH.buildHeap(st, n);
	cout << endl;
	mH.levelOrder();
	for (int i = n-1 ;i >=0; i--)
	{
		int r;
		double c;
		mH.heapSortAlgo(r, c);
		st[i].setData(r, c);
	}
}
int main()
{
	StudentMaxHeap obj(10);
	/*obj.insert(13, 3.5);
	obj.insert(15, 3.2);
	obj.insert(17, 3.8);
	obj.insert(31, 3.95);
	obj.insert(32, 3.5);
	obj.insert(12, 3.2);
	obj.insert(10, 3.5);
	obj.insert(9, 4);
	obj.insert(18, 4);
	obj.levelOrder();*/

	
	/*obj.levelOrder();
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
    obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);
	obj.removeBestStudent(rollNo, cgpa);
	display(&s, rollNo, cgpa);*/
	
	
	/*int rollNo;
	double cgpa;
	int choice;
	do
	{
		cout << "\n1. Insert a new student \n";
		cout << "2. Remove(and display) the student with the Max CGPA\n";
		cout << "3. Display the list of students(Level - order traversal)\n";
		cout << "4. Display the height of the heap\n";
		cout << "5. Exit\n";
		cout << "Enter your choice : ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nEnter Roll Number : ";
			cin >> rollNo;
			cout << "Enter CGPA : ";
			cin >> cgpa;
			obj.insert(rollNo, cgpa);
		}
		else if (choice == 2)
		{
			obj.removeBestStudent(rollNo, cgpa);
			cout << "\nRoll Number of Best Student : " << rollNo << endl;
			cout << "CGPA of Best Student : " << cgpa << endl;
		}
		else if (choice == 3)
		{
			cout << "\nLevel order traversal will be :\n";
			obj.levelOrder();
		}
		else if (choice == 4)
			cout << "\nHeight of the tree will be : " << obj.height() << endl;
		else if (choice == 5)
			cout << "BYE BYE!!.\n";
		else
			cout << "\nYou entered wrong choice!! \nEnter agin!!\n ";
	} while (choice != 5);
	*/

	int size = 9;
	Student* st = new Student[size];
	st[0].setData(13, 3.5);
	st[1].setData(15, 3.2);
	st[2].setData(17, 3.8);
	st[3].setData(31, 3.95);
	st[4].setData(32, 3.5);
	st[5].setData(12, 3.2);
	st[6].setData(10, 3.5);
	st[7].setData(9, 4);
	st[8].setData(18, 4);
	for (int i = 0; i < size; i++)
		st[i].displayStudent();
	heapSort(st, size);
	cout << "\nAfter HeapSort.\n";
	for (int i = 0; i < size; i++)
		st[i].displayStudent();

}