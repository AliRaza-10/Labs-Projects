#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
struct LetterInfo {
	char letter='\0'; //The letter (alphabet)
	int freq=0; // Frequency of the above letter
};

void insertionSort(LetterInfo* st, int size)
{
	for (int j = 1; j < size; j++)
	{
		LetterInfo key = st[j];
		int i = j - 1;
		while ((i >= 0) && (st[i].freq < key.freq)) 
		{
			st[i + 1] = st[i];
			i--;
		}
		st[i + 1] = key;
	}
}

int main()
{
	int num=0;
	ifstream fin("input.txt");
	if (!fin)
		cout << "File not found.\n";
	else
	{
		LetterInfo arr[26];
		char ch;
		fin.get(ch);
		while (!fin.eof())
		{
			if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			{
				bool flag = false;
				for (int i = 0; i < num; i++)
				{
					if (arr[i].letter == tolower(ch) || arr[i].letter == toupper(ch))
					{
						arr[i].freq++;
						flag = true;
					}
				}
				if (flag == false)
				{
					arr[num].freq++;
					arr[num].letter = ch;
					num++;
				}
			}
			fin.get(ch);
		}
		cout << endl;
		for (int i = 0; i < num; i++)
		{
			cout << arr[i].freq << "   " << arr[i].letter << endl;
		}
		insertionSort(arr, num);
		cout << "After sorting :\n";
		for (int i = 0; i < num; i++)
		{
			cout << arr[i].freq << "   " << arr[i].letter << endl;
		}
		fin.close();
	}
}
