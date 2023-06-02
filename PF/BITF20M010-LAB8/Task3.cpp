#include<iostream>
using namespace std;
int main()
{
	int p = 3;
	for(int i = 1; i<8; i+=2) 
	{
		for(int j = 1; j<=p ; j++)
		{
			
			cout<<" ";
		}
		p--;
		for(int k=1; k<=i; k++ )
	    {
	    		cout<<"*";
		}
		cout<<endl;
	}
	int q = 1;
	for(int i = 1; i<=5 ; i+=2)
	{
		
		for(int j = 1; j<=q; j++)
		{
			cout<<" ";
		}
		q++;
		for(int k = 5; k>=i ; k--)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	
	return 0;
	
}

