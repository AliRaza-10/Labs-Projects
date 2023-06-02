//MUHAMMAD WAQAS UD DIN
//BITF20M013
//IT-MORNING
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "BowlingFigures.h"
using namespace std;
BowlingFigures* readFromFile(char* fileName, int& count);//function to read file
void printBowlingFigures(const BowlingFigures* bf, int count);//function to print bowlingfigues
void sortBowlingFigures1(BowlingFigures* bf, int count);//Insertion sort algorithm
void sortBowlingFigures2(BowlingFigures* bf, int count);//Selection Sort algorithm
void sortByName(BowlingFigures* bf, int count);//Bubble sort algorithm
void swap(BowlingFigures& bf1, BowlingFigures& bf2);//function to swap objects
bool checkName(const char* str1, const char* str2);//function to check c string
int main()
{
	char name[16];
	int count;//variable  to store total bowling figures
	cout << "Enter the name of input File : ";
	cin.getline(name, 16);
	BowlingFigures* obj1 = NULL;
	obj1 = readFromFile(name, count);
	cout << "\nFollowing 6 Bowling figures were read from the input file : \n\n";
	printBowlingFigures(obj1, count);
	cout << "\n\t\t---------\n";
	cout << "\t\t   MENU\n";
	cout << "\t\t---------\n";
	cout << "1. Sort BowlingFigures using Insertion sort\n";
	cout << "2. Sort BowlingFigures using Selection sort\n";
	cout << "3. Sort BowlingFigures by Name (using Bubble sort)\n";
	cout << "Quit\n\n";
	char choice;
	cout << "Enter your choice : ";
	cin >> choice;
	do
	{
		switch (choice)
		{
		case '1':
			sortBowlingFigures1(obj1, count);
			cout << "The 6 Bowling figures after sorting using Insertion sort are :\n\n";
			printBowlingFigures(obj1, count);
			break;
		case '2':
			sortBowlingFigures2(obj1, count);
			cout << "The 6 Bowling figures after sorting using Insertion sort are :\n\n";
			printBowlingFigures(obj1, count);
			break;
		case '3':
			sortByName(obj1, count);
			cout << "The 6 Bowling figures after sorting by NAME are:\n\n";
			printBowlingFigures(obj1, count);
			break;
		}
		cout << "\nEnter your choice : ";
		cin >> choice;
	} while (choice != '4');
	delete obj1;
	obj1 = NULL;
	return 0;
}
void swap(BowlingFigures& bf1, BowlingFigures& bf2)
{
	BowlingFigures temp;
	temp = bf1;
	bf1 = bf2;
	bf2 = temp;
}

bool checkName(const char* str1, const char* str2)
{
	for (int i = 0; (i < strlen(str1)) && (i < strlen(str2)); i++){
		if (str1[i] > str2[i])
			return true;
		else if (str1[i] < str2[i])
			return false;
	}
}

BowlingFigures* readFromFile(char* fileName, int& count)
{
	ifstream fin(fileName);
	if (!fin)
	{
		return NULL;
	}
	else
	{
		fin >> count;
		BowlingFigures* obj = new BowlingFigures[count];
		for (int i = 0; i < count; i++) {
			fin.ignore();
			fin.getline(obj[i].name, NAME_LENGTH + 1);
			fin >> obj[i].wickets;
			fin.ignore();
			fin >> obj[i].runs;
		}
		return obj;
	}
}

void printBowlingFigures(const BowlingFigures* bf, int count)
{
	for (int i = 0; i < count; i++) {
		cout << setw(25) << bf[i].name << "  " << bf[i].wickets << "-" << bf[i].runs << endl;
	}
}

void sortBowlingFigures1(BowlingFigures* bf, int count)
{
	for (int i = count- 2; i >=0 ; i--) {
		BowlingFigures key = bf[i];
		int j = i + 1;
		while ((j < count && bf[j].wickets > key.wickets) || (j<count && bf[j].wickets == key.wickets && bf[j].runs < key.runs)){
			bf[j - 1] = bf[j];
			j++;
		}
		bf[j - 1] = key;
	}

}

void sortBowlingFigures2(BowlingFigures* bf, int count)
{
	for (int i = count - 1; i >= 0; i--) {
		int minIndex = i;
		for (int j = i - 1; j >= 0; j--) {
			if ((bf[j].wickets < bf[minIndex].wickets) || (bf[j].wickets == bf[minIndex].wickets && bf[j].runs > bf[minIndex].runs))
				minIndex = j;
		}
		swap(bf[i], bf[minIndex]);
	}
}

void sortByName(BowlingFigures* bf, int count)
{
	for (int i = count - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if(checkName(bf[j].name,bf[j+1].name))
				swap(bf[j], bf[j + 1]);
		}
	}
}

