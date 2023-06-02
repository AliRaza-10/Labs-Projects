#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;
int main()
{
/*LinkedList list1;
int val;
cout << "enter values : ";
cin >> val;
while(val!=-99)
{
list1.insertAtStart(val);
cin >> val;
}
cout << "List is : ";
list1.display();
int remove = 33;
cout << " you are removing : " << remove << " :\n ";
list1.unsortedRemove(remove);
list1.display();*/


/*LinkedList list;
list.insertAtEnd(4);
list.insertAtEnd(2);
list.insertAtEnd(8);
list.insertAtEnd(1);
list.insertAtEnd(9);
list.insertAtEnd(5);
list.insertAtEnd(4);
list.insertAtEnd(6);
int val;
list.removeKthNode(1, val);
cout <<"The removed element is : " << val << endl;
list.display();


cout << endl;

LinkedList list1;
list1.insertAtEnd(7);
list1.insertAtEnd(3);
list1.insertAtEnd(4);
list1.insertAtEnd(2);
list1.display();
LinkedList list2;
list2.insertAtEnd(5);
list2.insertAtEnd(9);
list2.display();
LinkedList list3;
list3.combine(list1, list2);
list1.display();
list2.display();
list3.display();

cout << endl;

LinkedList list4;
list4.insertAtEnd(2);
list4.insertAtEnd(6);
list4.insertAtEnd(8);
	
list4.display();
LinkedList list5;
list5.insertAtEnd(8);
list5.insertAtEnd(1);
list5.insertAtEnd(3);
list5.display();
LinkedList list6;
list6.shuffleMerge(list4, list5);
list4.display();
list5.display();
list6.display();*/

//LinkedList list7;
//list7.insertAtEnd(2);
////list7.insertAtEnd(6);
////list7.insertAtEnd(8);
//int val;
//list7.removeLastNode(val);
//cout << "Removed val is : " << val << endl;
//list7.display();
//LinkedList list8;
//list8.insertAtEnd(8);
//list8.insertAtEnd(1);
//list8.insertAtEnd(3);
//list8.display();
//int val1;
//list8.removeLastNode(val1);
//cout << "Removed val is : " << val1 << endl;

//list8.display();


//LinkedList list7;
//list7.insertAtEnd(2);
////list7.insertAtEnd(6);
////list7.insertAtEnd(8);
//int val;
//if (list7.removeSecondLastNode(val))
//{
//	cout << "Removed val is : " << val << endl;
//}
//else
//	cout << "List has less than 2 values.\n";

//
//list7.display();
//LinkedList list8;
//list8.insertAtEnd(8);
//list8.insertAtEnd(1);
//list8.insertAtEnd(3);
//list8.insertAtEnd(9);
//list8.display();
//int val1;
//list8.removeSecondLastNode(val1);
//cout << "Removed val is : " << val1 << endl;
//list8.display();


//LinkedList list9;
//list9.insertAtStart(7);
//list9.insertAtStart(5);
//list9.insertAtStart(3);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(1);
//list9.insertAtStart(4);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(7);
//list9.insertAtStart(7);*/
//list9.display();
//int count = list9.removeAll(7);
//cout << "No. of Removed values are : " << count << endl;
//list9.display();


LinkedList list9;
//list9.insertAtStart(7);
//list9.insertAtStart(71);
//list9.insertAtStart(17);
//list9.insertTillN(5);
list9.sortedUniqueInsert(5);
list9.sortedUniqueInsert(8);
list9.sortedUniqueInsert(9);
list9.sortedUniqueInsert(10);

list9.display();

LinkedList list10;
list10.sortedUniqueInsert(1);
list10.sortedUniqueInsert(2);
list10.sortedUniqueInsert(7);
list10.sortedUniqueInsert(11);
list10.display();
LinkedList list11;
list11.unionLists(list9, list10);
list11.display();
 
cout << "Count of even numbers is : " << list11.countEvens() << endl;
//list9.insertAtStart(5);
//cout << list9.removerAlternates();
//list9.insertAtStart(3);
//if (list9.sortedUniqueInsert(3))
//cout << "Successfully.\n";
//else
//cout << "not inserted.\n";
//
//if (list9.sortedUniqueInsert(10))
//cout << "Successfully.\n";
//else
//cout << "not inserted.\n";
//
//if (list9.sortedUniqueInsert(7))
//cout << "Successfully.\n";
//else
//cout << "not inserted.\n";
//
//
//////list9.insertAtEnd(3);
//list9.display();
//list9.displayReverse();
//LinkedList list10;
//list10.insertAtEnd(6);
//list10.insertAtEnd(1);
//list10.insertAtEnd(2);
//list10.insertAtEnd(4);
//list10.insertAtEnd(5);
//list10.insertAtEnd(10);
//list10.insertAtEnd(11);
//list10.display();
//cout << "Count of removed numbers is : " << list10.removerAlternates() << endl;
//list10.display();
}