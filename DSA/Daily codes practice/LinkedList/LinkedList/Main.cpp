#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;
int main()
{
	LinkedList list1;
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
	list1.display();


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
}