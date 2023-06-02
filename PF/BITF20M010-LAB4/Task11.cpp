#include <iostream>
using namespace std;
int main()
{
    int num1, num2, num3;
    cout << " Please enter the first integer: ";
    cin >> num1;
    cout << " Please enter the second integer: ";
    cin >> num2;
    cout << " Please enter the third integer: ";
    cin >> num3;

    if (num1 > num2)
    {
        if (num1 > num3)
        {
            cout << num1 << " is the larger number ";
        }
    }
    if (num2 > num3)
    {
        if (num2 > num1)
        {
            cout << num2 << " is the larger number ";
        }
    }
    if (num3 > num1)
    {
        if (num3 > num2)
        {
            cout << num3 << " is the larger number ";
        }
    }
    return 0;

}