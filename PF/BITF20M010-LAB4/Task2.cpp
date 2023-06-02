#include<iostream>
using namespace std;
int main()
{
    int number1, number2;
    cout << "please enter the first integer : ";
    cin >> number1;
    cout << "please enter the second integer : ";
    cin >> number2;
    if (number1 > number2)
    {
        cout << number1 << " is larger number";
    }
    if (number2 > number1)
    {
        cout << number2 << " is larger number";
    }
    if (number1 == number2)
    {
        cout << "These numbers are equal";
    }

    return 0;
}




