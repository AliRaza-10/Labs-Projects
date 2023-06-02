#include <iostream>
#include "LinkedStack.h"
using namespace std;
int main()
{
	LinkedStack stk1;
	stk1.push(10);
	stk1.push(20);
	stk1.push(30);
	int val;
	if (stk1.pop(val))
	{
		cout << val << "   ";

	}
	else
	{
		cout << "List is empty.\n";
	}

	if (stk1.pop(val))
	{
		cout << val << "   ";

	}
	else
		cout << "List is empty.\n";

	if (stk1.pop(val))
	{
		cout << val << "   ";

	}
	else
		cout << "List is empty.\n";

	if (stk1.pop(val))
	{
		cout << val << "   ";

	}
	else
		cout << "List is empty.\n";

}