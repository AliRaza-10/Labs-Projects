#include <iostream>

using namespace std;

int main()
{
    int num,i,decNum,value,endLimit;
endLimit = -1;
    value = 0;
    i=1;
   
    while(num!=endLimit)
    {
        cout<<"Enter a base-7 digit:";
        cin>>num;
        if(num!=endLimit)
        {
            decNum=num*i;
            i*=7;
            value+=decNum;
        }
    }
    cout<<"The euivalent number in base-10 is : "
        <<value;
    return 0;
}
