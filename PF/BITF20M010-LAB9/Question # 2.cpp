#include<iostream>
using namespace std;
int main()
{
	int height , width;
	cout<<"Please enter the height : ";
	cin>>height;
	while(height%2!=0 ||height<4)
	{
		cout<<"ERROR! Enter again Height ";
		cin>>height;	
	}
	cout <<"Please enter the width : ";
	cin >>width;
	while(width%2!=0||width<6)
	{
		cout<<"ERROR! Enter again width ";
		cin>>width;	
	}
	for (int i = 1; i <= height; i++)
	{
		if (i == 1 || i == height)
		{
			for (int j = 1; j <= width; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		
		if ( i > 1 && i < height)
		{
			
			for (int j = 1; j <= width; j++)
			{
				
				if (j == 1 || j == width)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
