#include <iostream>
#include "LinkedDequeue.h"
using namespace std;
int main()
{
	LinkedDequeue d1;
	d1.equeue(5);
	d1.equeue(6);
	d1.equeue(8);
	d1.equeue(1);
	d1.display();
	int val;
	if (d1.dequeue(val))
		cout << "The " << val << " has been removed.\n ";
	else
		cout << "List is empty.\n";
	d1.display();
	return 0;
}