#include <iostream>
#include <string>

using namespace std;

int main()
{
    string student,first,last;
    int numOfStudents;

    cout << "please enter the number of students: ";

    while (!(cin >> numOfStudents) || 
        (numOfStudents < 1 || numOfStudents > 25))
        {
            cout << "please enter a number between 1 and 25 : ";
        }
    
    cout << "Enter the name of student No. 1: ";
    cin >> student;

    first = last = student;

    if (student < first)
        first = student;

    if (student > last)
        last = student;

    for (int i = 1; i < numOfStudents; i++)
    {
        cout << "please enter the name of student No. " << (i + 1) << ": ";
        cin >> student;

        if (student < first)
            first = student;

        if (student > last)
            last = student;
    }

    cout << "First student is " << first << endl;

    cout << "Last student is " << last << endl;
    
    return 0;
}
