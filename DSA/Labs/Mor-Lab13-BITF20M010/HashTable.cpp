#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;
HashTable::HashTable(int size)
{
	S = size;
	n = 0;
	table = new string[size];
	for (int i = 0; i < size; i++)
		table[i] = "EMPTY";
}
HashTable::~HashTable()
{
	if (table)
	{
		delete[]table;
		table = NULL;
	}
}
bool HashTable::isEmpty() // Checks whether the hash table is empty or not
{
	if (n == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool HashTable::isFull() // Checks whether the hash table is full or not
{
	if (n == S)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double HashTable::loadFactor() // Calculates & returns the load factor of the hash table (n/S)
{
	double factor = n / S;
	return factor;
}
int HashTable::linearProbingFunction(int num)
{
	return (num + 1);
}
int HashTable::getHashValue(string name) // Private member function of HashTable class
{
	int temp = 0;
	for (int i = 0; i < name.length(); i++)
	{
		temp += name[i];
	}
	return temp;
}
bool HashTable::insert(string name)
{
	cout << name << "  " << getHashValue(name) << endl;
	int index = getHashValue(name) % S;//geting value to store it in table 
	int start = -999;
	if (table[index] == "EMPTY" || table[index] == "empty")
	{
		n++;
		table[index] = name;
		return true;
	}
	else
	{
		//empty --> it means that value is removed from that slot
		//EMPTY means value is nopt stored yet
		if (table[index] != "EMPTY" && table[index] != "empty")
		{
			start = index;
			index = linearProbingFunction(index);
		}
		while (table[index] != "EMPTY" &&  index != start)//table[index] != "empty" &&
		{
			index = linearProbingFunction(index);
			if (index == S)
				index = 0;//this will move it to 0
		}
		cout << endl;
		if (start == index)//no empty slot found
			return false;
		else
		{
			n++;
			table[index] = name;
			return true;
		}
	}
}
bool HashTable::search(string name)
{
	int start = -99;
	int index = getHashValue(name) % S;
	if (table[index] == name)
		return true;
	else
	{
		start = index;
		index = linearProbingFunction(index);
		while (index != start && table[index] != "EMPTY")//table[index] != "empty" 
		{
			cout << index << "  ";
			index = linearProbingFunction(index);
			if (index == S)
				index = 0;
		}
	}
	if (table[index] == name)
		return true;
	else
		return false;

}
void HashTable::display()
{
	cout << "Total Number of elements : " << S << endl;
	cout << "Number of elements inserted : " << n  << endl << endl;
	int i = 0;
	while (i < S)
	{
		if (table[i] == "EMPTY" || table[i] == "empty")
		{
			cout << "EMPTY" << "\t";
		}
		else
		{
			cout << table[i] << "\t";
		}
		i++;
	}
	cout << endl;
}
bool HashTable::remove(string name)
{
	int index = getHashValue(name) % S;		//working as hash function
	int start = -999;
	if (table[index] == name)
	{
		n--;
		table[index] = "empty";
		return true;
	}
	else
	{
		start = index;
		index = linearProbingFunction(index);
		while (index != start && table[index] != "EMPTY" && table[index]!= name)//table[index] != "empty" 
		{
			cout << index << "  ";
			index = linearProbingFunction(index);
			if (index == S)
				index = 0;
		}
		if (table[index] == name)
		{
			n--;
			table[index] = "empty";
			return true;
		}
		else
			return false;	
	}
}
//Tast 2
bool HashTable::insert(int val)
{
	int index = val % S;
	string str = to_string(val);
	if (table[index] == "EMPTY" || table[index] == "enpty")
	{
		table[index] = str;
		n++;
		return true;
	}
	else
		return false;
}