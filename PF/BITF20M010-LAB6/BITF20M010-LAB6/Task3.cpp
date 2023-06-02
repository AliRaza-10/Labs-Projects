#include <iostream>

using namespace std;
int main()
{
    int num, n, largest, secondLargest, counter;
    cout <<"How many terms do you want to enter : " ;
    cin >> n;
  
     while(n<2)
    {
        cout << "Invalid " << endl << "Please enter 2 or greater : " ;
        cin >> n ;
    }
    counter = 0 ;
    
    if(n>=2)
    {
        while(counter!=n)
            {
        cout << "Please enter the integer : " ;
        cin >> num;
        counter = counter +1 ;
         if(num > largest)
             {
                 secondLargest = largest;
               largest = num ;
               
              }
             if(num > secondLargest && num < largest)
            {
              secondLargest = num ;
            }
       
            }
    
            
    cout << "largest number  is " << largest << endl << "Second largest is " << secondLargest ;
    }
    return 0;
    
}
