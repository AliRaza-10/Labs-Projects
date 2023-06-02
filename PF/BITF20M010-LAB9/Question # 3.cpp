#include<iostream>
using namespace std;
int main()
{
	int num, b = 0 , c = 1 , d = 1 ;
	int   g = 2; 
	cout<<"Enter the positive Odd Integer : ";
	cin>>num;
	while(num%2==0 ||num<3)
	{
		cout<<"ERROR!!Please Enter Odd integer ";
		cin>>num;
	}
	int p=num;
	for(int i = 1; i<=num; i++)
	{
		if(i<=(num/2)+1)
		{
			for(int j = 1; j<=(num/2)-b; j++)
			{
				cout<<" ";
			}
			for(int k = 1; k<=d; k++)
			{
				cout<<"*";
			}
			cout<<endl;
			b++;
			d+=2;
		}
		else
		{
			for(int m = 1; m<=c; m++)
			{
				cout<<" ";
			}
			for(int n= 1 ; n<=p-g; n++)
			{
				cout<<"*";
			}
			cout<<endl;
			g+=2;
			c++;
		}
	}
	
	return 0;
	
}
