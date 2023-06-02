#include<iostream>
using namespace std;
int main()
{
    int booksPurchased;
    cout << "please enter the number of book purchased: ";
    cin >> booksPurchased;

    if (booksPurchased == 0)
    {
        cout << " 0 points earned. ";
    }
    if (booksPurchased == 1)
    {
        cout << " 5 points earned. ";
    }
    if (booksPurchased == 2)
    {
        cout << " 15 points earned. ";
    }

    if (booksPurchased >= 3)
    {
        cout << " 30 points earned. ";
    }
    return 0;
}