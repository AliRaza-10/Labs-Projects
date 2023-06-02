#include<iostream>
using namespace std;
int frequent(int[], int, int&, int&);
int main()
{
	int freqNum,freq;
	const int SIZE = 8;
	int number[SIZE]={5,12,6,1,6,4,3,9};
	frequent(number,SIZE,freqNum,freq);
	cout<<"The Most Frequent Number is "<<freqNum<<endl;
	cout<<"The Frequency of the number is "<<freq;
	return 0;
}
int frequent(int array[], int size, int& mostFrequent , int& frequency)
{
	int maximum = 0,counter;
	for(int i = 0; i<size; i++)
	{
		counter = 0;
		for(int j = 0; j<size;j++)
		{
			if(array[i]==array[j])
			{
				counter++;
			}
		}
		if(counter>maximum)
		{
		maximum=counter;
		mostFrequent = array[i];
		frequency=counter;
		}
	}
	return mostFrequent;
	return frequency;
}
