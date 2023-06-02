#include <iostream>
using namespace std;
int main()
{
	float radius1, radius2, area1, area2;
	cout << " Please enter the radius of the first circle:";
	cin >> radius1;
	cout << " Please enter the radius of the second circle:";
	cin >> radius2;
	area1 = 3.14 * radius1 * radius1;
	area2 = 3.14 * radius2 * radius2;
	if (area1 > area2)
	{
		cout << " Area of the first circle is greater than the second circle";
	}
	if (area2 > area1)
	{
		cout << " Area of the second circle is greater than the first circle";
	}
	if (area2 == area1)
	{
		cout << " Area of both circle are the same";
	}
	return 0;
}