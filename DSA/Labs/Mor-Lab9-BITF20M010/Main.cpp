#include <iostream>
#include "CDLLD.h"
using namespace std;
int main()
{
	/*CDLLD obj1;
	obj1.insertAtEnd(1);
	obj1.insertAtEnd(4);
	obj1.insertAtEnd(6);
	obj1.insertAtEnd(13);
	obj1.sortedInsert(36);
	obj1.sortedInsert(11);
	obj1.sortedInsert(112);
	obj1.display();*/

	/*bool flag = obj1.sortedRemove(11);
	if (flag == true)
		cout << "Successfully removed.\n";
	else
		cout << "Not found.\n";
	obj1.display();*/

	/*CDLLD *obj2 = new CDLLD;
	obj2->insertAtStart(2);
	obj2->insertAtStart(6);
	obj2->insertAtStart(1);
	obj2->insertAtEnd(11);
	obj2->insertAtEnd(15);
	obj2->display();
	cout << "No of nodes = " << obj2->countNodes() << endl;
	
	obj2->insertAtEnd(111);
	obj2->insertAtEnd(155);
	obj2->display();
	cout << "No of nodes = " << obj2->countNodes() << endl;

	int val;
	bool flag = obj2->removeLastNode(val);
	if (flag == true)
		cout << "Successfully remove ." << val << endl;
	else
		cout << "Cannot remove\n";
	obj2->display();*/

	/*bool flag = obj2->uniqueInsert(16);
	if (flag == true)
		cout << "Successfully inserted.\n";
	else
		cout << "Duplicate number.\n";

	flag = obj2->uniqueInsert(2);
	if (flag == true)
		cout << "Successfully inserted.\n";
	else
		cout << "Duplicate number.\n";
	flag = obj2->uniqueInsert(1);
	if (flag == true)
		cout << "Successfully inserted.\n";
	else
		cout << "Duplicate number.\n";
	flag = obj2->uniqueInsert(100);
	if (flag == true)
		cout << "Successfully inserted.\n";
	else
		cout << "Duplicate number.\n";
	obj2->display();*/

	/*bool flag1 = obj2->search(1);
	if (flag1 == true)
		cout << "Successfully found.\n";
	else
		cout << "Not found.\n";
	flag1 = obj2->search(2);
	if (flag1 == true)
		cout << "Successfully found.\n";
	else
		cout << "Not found.\n";
	flag1 = obj2->search(15);
	if (flag1 == true)
		cout << "Successfully found.\n";
	else
		cout << "Not found.\n";*/
	//CDLLD *obj3 = obj2;
	//obj3->display();

	/*CDLLD* obj4 = new CDLLD;
	obj4->insertAtEnd(10);
	obj4->insertAtEnd(20);
	cout << "Before Assignment operator ---> ";
	obj4->display();
	obj4 = obj2;
	cout << "After Assignment operator ---> ";
	obj4->display();
	delete obj2;
	obj2 = nullptr;
	cout << "The end";*/

	/*CDLLD obj1;
	obj1.insertAtEnd(1);
	obj1.insertAtEnd(2);
	obj1.insertAtEnd(3);
	obj1.insertAtEnd(4);
	obj1.insertAtEnd(5);
	bool flag = obj1.isSorted();
	if (flag == true)
		cout << "List is Sorted .\n";
	else
		cout << "List is not sorted.\n";

	CDLLD obj2;
	obj2.insertAtEnd(1);
	obj2.insertAtEnd(2);
	obj2.insertAtEnd(1);
	obj2.insertAtEnd(4);
	obj2.insertAtEnd(5);
	flag = obj2.isSorted();
	if (flag == true)
		cout << "List is Sorted .\n";
	else
		cout << "List is not sorted.\n";

	CDLLD obj3;
	obj3.insertAtEnd(1);
	flag = obj3.isSorted();
	if (flag == true)
		cout << "List is Sorted .\n";
	else
		cout << "List is not sorted.\n";

	CDLLD obj4;
	flag = obj4.isSorted();
	if (flag == true)
		cout << "List is Sorted .\n";
	else
		cout << "List is not sorted.\n";*/

	//CDLLD obj5;
	//obj5.insertAtEnd(1);
	////obj5.insertAtEnd(2);
	//obj5.display();
	//int val;
	//bool flag = obj5.removeSecondLastNode(val);
	//if (flag == true)
	//cout << "Value removed successfully ----> " << val << endl;
	//else
	//	cout << "Value cannot be removed.\n";
	//obj5.display();


//CDLLD list;
//list.insertAtEnd(4);
//list.insertAtEnd(2);
//list.insertAtEnd(5);
//list.insertAtEnd(6);
//list.insertAtEnd(9);
//int val;
//
//bool flag = list.removeKthNode(3, val);;
//if (flag == true)
//cout << "Value removed successfully ----> " << val << endl;
//else
//	cout << "Value cannot be removed.\n";
//list.display();


//CDLLD list1;
//list1.insertAtEnd(-99);
//list1.insertAtEnd(4);
//list1.insertAtEnd(1);
//list1.insertAtEnd(-120);
//list1.insertAtEnd(7);
//int val,k = 0;
//list1.display();
//cout << "After Sorting : ";
//list1.sortList();
//list1.display();
//bool flag = list1.removeKthNode(k, val);;
//if (flag == true)
//cout << "Value removed successfully from position "  << k << " and the value is : " << val << endl;
//else
//cout << "Value cannot be removed.\n";
//list1.display();
//
//cout << "\n";
//CDLLD list2;
//list2.insertAtEnd(4);
//list2.insertAtEnd(2);
//list2.insertAtEnd(5);
//list2.insertAtEnd(6);
//list2.insertAtEnd(9);
////int val, k = 4;
//k = 4;
//list1.display();
//flag = list2.removeKthNode(k, val);;
//if (flag == true)
//cout << "Value removed successfully from position " << k << " and the value is : " << val << endl;
//else
//cout << "Value cannot be removed.\n";
//list2.display();

//CDLLD list1,list2;
//list2.insertAtEnd(4);
//list2.insertAtEnd(7);
//list2.insertAtEnd(10);
//list2.insertAtEnd(12);
//
//list1.insertAtEnd(1);
//list1.insertAtEnd(3);
//list1.insertAtEnd(6);
//list1.insertAtEnd(9);
//list1.insertAtEnd(15);
//CDLLD list3;
//list1.display();
//list2.display();
//list3.merge(list1, list2);
//list3.display();


//CDLLD list4;
//list4.insertAtEnd(2);
//list4.insertAtEnd(5);
//list4.insertAtEnd(7);
//list4.insertAtEnd(1);
//list4.insertAtEnd(9);
//list4.insertAtEnd(1);
//list4.insertAtEnd(1);
//list4.insertAtEnd(9);
//list4.display();
//list4.insertionSort();
//list4.display();

CDLLD l1;
l1.insertAtEnd(1);
l1.insertAtEnd(2);
l1.insertAtEnd(3);
l1.insertAtEnd(4);
l1.display();

CDLLD l2;
l2.insertAtEnd(5);
l2.insertAtEnd(6);
l2.insertAtEnd(7);
l2.insertAtEnd(8);
l2.display();
CDLLD l3;
l3.shuffleMerge(l1, l2);
l3.display();

}