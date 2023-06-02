#include<iostream>
using namespace std;
int main()
{
    int num1, num2, sum, product, difference, quotient, remainder;
    cout << "please enter the first integer : ";
    cin >> num1;
    cout << "please enter the second integer : ";
    cin >> num2;
    sum = num1 + num2;
    product = num1 * num2;
    difference = num1 - num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    cout << " sum is : " << sum<<endl;
    cout << " product is : " << product << endl;
    cout << " difference is : " << difference << endl;
    cout << " quotient is : " << quotient << endl;
    cout << " remainder is : " << remainder << endl;
    return 0;
}