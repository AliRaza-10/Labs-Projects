#include <iostream>
using namespace std;
int main()
{
 int num=0;
 int i=1;
 int value=0;
 int rem=0;
 cout<<"Please enter number in base 10 :";
 cin>>num;
 
 while(num>0)
 {
 rem=num%9;
 value=value+(rem*i);
 num=num/9;
 i*=10;
 
 }
 cout<<" Number in base 9 is = "<<value <<endl;
}
