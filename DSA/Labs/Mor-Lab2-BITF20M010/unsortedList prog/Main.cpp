#include <iostream>
#include "UnsortedList.h"
#include <fstream>
using namespace std;
int main()
{
	/*UnsortedList l1(10);
	for (int i = 0; i < 5; i++)
		l1.insert(i * 2);
	l1.display();*/

	/*int val;
	if (l1.remove(2, val))
		cout << "Number removed successfully and number is " << val << endl;
	else
		cout << "Index is not correct \n";
	l1.display();*/

	/*ofstream fout("file.txt");
	if (!fout)
		cout << "File not created.\n";
	else
	{
		cout << "Written in file.\n";
		l1.writeInFile(fout);
		fout.close();
	}*/

	/*ifstream fin("file.txt");
	if (!fin)
		cout << "File not found\n";
	else
	{
		UnsortedList l4(0);
		l4.readFromFile(fin);
		fin.close();
		l4.display();
	}*/

	//Task 2
	/*UnsortedList l1(7);
	l1.insert(4);
	l1.insert(2);
	l1.insert(3);
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);
	int max;
	if (l1.removeMax(max))
		cout << "Number removed " << max << endl;
	else
		cout << "Not removed List is empty\n";
	l1.display();*/

	//Task 2
	/*UnsortedList l2(7);
	l2.insert(2);
	l2.insert(4);
	l2.insert(6);
	l2.insert(8);
	l2.insert(10);
	l2.insert(12);
	l2.display();
	l2.reverse();
	l2.display();*/

	/*UnsortedList l3(5);
	l3.insert(1);
	l3.insert(2);
	l3.insert(3);
	l3.insert(4);
	l3.display();

	UnsortedList l4(5);
	l4.insert(5);
	l4.insert(6);
	l4.display();

	l3.combineList(l4);
	l3.display();*/


	/*UnsortedList l1(8);
	l1.insert(2);
	l1.insert(4);
	l1.insert(7);
	l1.insert(6);
	l1.insert(5);
	l1.insert(8);

	UnsortedList l2(6);
	l2.insert(4);
	l2.insert(3);
	l2.insert(2);
	l2.insert(1);
	l2.insert(5);

	UnsortedList l3=l1.intersection(l2);
	l3.display();*/

	/*UnsortedList l3(10);
	l3.insert(2);
	l3.insert(4);
	l3.insert(7);
	l3.insert(10);
	l3.insert(5);
	l3.insert(9);

	UnsortedList l4(10);
	l4.insert(2);
	l4.insert(4);
	l4.insert(6);
	l4.insert(7);
	l4.insert(5);
	l4.insert(10);
	l4.insert(9);

	l3.display();
	l4.display();

	if (l3.isSubset(l4))
		cout << "List3 is subest of list4.\n";
	else
		cout << "List3 is not subest of list4.\n";*/

	/*UnsortedList l3(10);
	l3.insert(3);
	l3.insert(9);
	l3.insert(5);
	l3.display();

	UnsortedList l4(10);
	l4.insert(7);
	l4.insert(12);
	l4.insert(10);
	l4.insert(5);
	l4.display();

	UnsortedList l5 = l3.difference(l4);
	l5.display();*/


	/*UnsortedList l3(10);
	l3.insert(3);
	l3.insert(5);
	l3.insert(4);
	l3.insert(9);
	l3.insert(7);
	l3.display();

	UnsortedList l4(10);
	l4.insert(3);
	l4.insert(2);
	l4.insert(7);
	l4.insert(5);
	l4.insert(12);
	l4.insert(10);
	l4.insert(13);
	l4.display();

	UnsortedList l5 = l3.difference(l4);
	l5.display();*/

	UnsortedList l3(10);
	l3.insert(2);
	l3.insert(7);
	l3.insert(4);
	//l3.insert(41);
	l3.display();

	UnsortedList l4(10);
	l4.insert(2);
	l4.insert(7);
	l4.insert(5);
	l4.insert(9);
	l4.insert(42);
	l4.display();

	UnsortedList l5 = l3.union1(l4);
	l5.display();
}

