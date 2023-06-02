#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    ifstream inputFile;
    ofstream outputFile;
    double sum = 0, count = 0, number,avrg;
    inputFile.open("D:\\BITF20M010-LAB8\\Random.txt");
    if (inputFile.fail())
    {
        cout << "Error!!Please enter correct Address.";
    }
    else 
    {
        while(inputFile >> number)
        {
            sum += number;
            count++;
        }
         avrg = sum / count;
        cout << "The number of numbers in the file are = " << count << endl;
        cout << "The sum of all numbers in the file are = " << sum << endl;
        cout << "The average of all numbers in the file are = " << avrg; 
        inputFile.close();
    }
   
    return 0;
}
