// ALI RAZA BITF20M010
//FALL 2020 MORNING
#include <iostream>
#include "intArray.h"
using namespace std;
ostream & operator <<(ostream& out,const IntArray& s)
{
	for(int i = 0; i<s.arraySize;i++)
	{
		out<<*(s.aptr+i)<<" ";
	}
	return out;
}
int main()
{
	const int SIZE = 5;  // Array size
	IntArray table(SIZE);
	IntArray table1(SIZE);
	IntArray table2(SIZE);
	int data[3] = { 1,2,3 };
	for (int x = 0; x < SIZE; x++)
		table[x] = (x + 1);
	for (int x = 0; x < SIZE; x++)
	{
		table1[x] = (x * 5);
	}
	cout<<table<<endl;
	cout << table1 << endl;
	cout<<table2<<endl;
	table = table1 + 5;
	cout << table<<endl;
	table.storeData(data,3);
	table1.storeData(data,3);
	cout<<table<<endl;
	cout<<table1<<endl;
	IntArray table5(5);
	table5[0]= 58;
	table5[1]= 94;
	table5[2]= 11;
	table5[3]= 10;
	table5[4]= 10;
double avg = table5;
cout<<"Average is "<<avg;

	return 0;
}