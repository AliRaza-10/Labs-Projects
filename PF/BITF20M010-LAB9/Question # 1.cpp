#include<iostream>
using namespace std;
int main()
{	//	Variable Declaration
	int startValue;
	int endValue;
	// For input 
	cout<<"Enter starting integer : ";
	cin>>startValue;
	cout<<"Enter the ending integer : ";
	cin>>endValue;
	// for calculation 
	for(int i = startValue; i<=endValue;i++)
	{
		for(int j = i;j<=endValue;j++)
		{
			cout<< "("<<i<<" , "<<j<<")"; //For output
		}	
		cout<<endl; 	//for next line
		endValue--;		// Decreement
	}	
}
