#include <iostream> 
 using namespace std;
 int main ()
 {
 	int n, deci = 0 , i = 1, reminder;
 	cout << " Please enter any binary number : " ;
 	cin >> n ;
 	cout << endl;
 	while ( n!=0 )
 	{
 		reminder = n % 10;
 		deci = deci + ( reminder * i );
 		i = i*2 ;
 		n = n / 10 ;
 				
	 }
	 cout << " The decimal number is :  " << deci << endl ;
	 return 0;
 }
