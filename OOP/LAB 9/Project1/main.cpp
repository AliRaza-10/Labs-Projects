// ALI RAZA BITF20M010
//FALL 2020 MORNING
#include <iostream>
#include "intArray.h"
using namespace std;
ostream& operator <<(ostream& out, const IntArray& s)
{
	for (int i = 0; i < s.arraySize; i++)
	{
		out << *(s.aptr + i) << " ";
	}
	return out;
}
int main()
{
	//const int SIZE = 5;  // Array size
	//IntArray table(SIZE);
	//IntArray table1(SIZE);
	//IntArray table2(SIZE);
	//int data[3] = { 1,2,3 };
	//for (int x = 0; x < SIZE; x++)
	//	table[x] = (x + 1);
	//for (int x = 0; x < SIZE; x++)
	//{
	//	table1[x] = (x * 5);
	//}
	//cout << table << endl;
	//cout << table1 << endl;
	//cout << table2 << endl;
	//table = table1 + 5;
	//cout << table << endl;
	//table.storeData(data, 3);
	//table1.storeData(data, 3);
	//cout << table << endl;
	//cout << table1 << endl;
	//IntArray table5(5);
	//table5[0] = 58;
	//table5[1] = 94;
	//table5[2] = 11;
	//table5[3] = 10;
	//table5[4] = 10;
	//double avg = table5;
	//cout << "Average is " << avg;
	cout << "Setion1.1\n\n";
	IntArray a1(5);
	IntArray a2(3);
	IntArray a3(2);
	for (int i = 0; i < a1.size(); i++)
		a1[i] = (i + 1); // using the overloaded [] operator of IntArray class
	for (int i = 0; i < a2.size(); i++)
		a2[i] = (i + 1) * 10; // using the overloaded [] operator of IntArray class
	cout << a1<<endl; // should display: 1 2 3 4 5
	cout << a2<<endl; // should display: 10 20 30
	cout << a3<<endl; // should display: 0 0
	a3 += a2 += a1; // Testing the working of += operator (Task 1.1)
	cout << a1<<endl; // should display: 1 2 3 4 5
	cout << a2<<endl; // should display: 10 20 30 1 2 3 4 5
	cout << a3; // should display: 0 0 10 20 30 1 2 3 4 5
	cout << endl;
	cout << "___________\n";
	cout<<"Section1.2\n";
	cout << endl;
	IntArray ma1(5);
	IntArray ma2(2);
	for (int i = 0; i < ma1.size(); i++)
		ma1[i] = (i + 1) * 10; // using the overloaded [] operator of IntArray class
	cout << ma1<<endl; // should display: 10 20 30 40 50
	cout << ma2<<endl; // should display: 0 0
	ma2 = ++ma1; // Testing the working of pre-increment ++ operator (Task 1.2)
	// Note: The above statement also uses the overloaded = operator of IntArray class
	cout << ma1<<endl; // should display: 11 21 31 41 51
	cout << ma2; // should display: 11 21 31 41 51
	cout<<"\n\nSection 1.3\n";
	IntArray list(8);
	int nums[8] = { 14, 49, 35, 17, 23, 7, 85, 25 };
	for (int i = 0; i < list.size(); i++)
		list[i] = nums[i];
	cout << list<<endl; // should display: 14 49 35 17 23 7 85 25
	// Now, testing the working of function call () operator (Task 1.3)
	cout << list(1, 3) << endl; // should display: 33.6667
	cout << list(3, 3) << endl; // should display: 17
	cout << list(0, 7) << endl; // should display: 31.875
	cout << list(2, 6) << endl; // should display: 33.4
	cout << list(3, 1) << endl; // should display: -999
	cout << list(4, 8) << endl; // should display: -999
	cout << list(-5, 3) << endl; // should display: -999
	cout << list(7, 10) << endl; // should display: -999

	return 0;
}