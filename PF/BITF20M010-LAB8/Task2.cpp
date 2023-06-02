#include <fstream>
#include <iostream>
using namespace std ;
int main ()
{
	int values , sum = 0,result ;
	ifstream inputFile ;
	ofstream outputFile ;
	
	inputFile.open("D:\\BITF20M010-LAB8\\data.txt");
	outputFile.open("D:\\BITF20M010-LAB8\\sum.txt");
	
	if (inputFile.fail()||outputFile.fail()) 
	{
		cout << "ERROR!! Enter the correct Address";
	}
	else 
	{
		
		while (inputFile >> values)
		{
			cout << values << endl ;
			sum = sum + values ;
			result = sum;
		}
		cout << "Sum of values are =  " << result ;
		outputFile<<"Sum of values are =  " << result ;
	inputFile.close();
	outputFile.close();
	}
		
	return 0;
}
