
// ALI RAZA BITF20M010
//FALL 2020 MORNING
#include <iostream>
#include "myString.h"
using namespace std;

// Function 8  Stream insertion operator <<
ostream& operator << (ostream& out, const MyString& s)
{
		out << s.str << endl;
	return out;
}

//Function 18 stream extraction operator >> 
istream& operator >> (istream& in, MyString& p)
{
	if (p.str != nullptr)
	{
		delete[] p.str;
		p.str = nullptr;
	}
	char* c = new char[100];
	in.getline(c,100);
	p.length = strlen(c);
	p.str = new char[p.length + 1];
	strcpy(p.str, c);
	return in;
 }
int main()
{
	class MyString s; //Default Constructor
	char name[15] = "ANNS & Ahmad";
	MyString sr1(name); //Overloaded Constructor
	sr1.display(); // Display
	cout << sr1 ;
	cout<<"Size of String is " << sr1.getLength()<<endl; //getlength
	MyString sr2 = sr1; //copy Contructor
	cout << sr2 ;
	cout<<"Name " << sr2.getName()<<endl; //getlength
	cout<< "Size " << sr2.getLength()<<endl; //getlength
	MyString sr3;
	sr3 = sr1; //Assignment
	cout << sr3;
	cout << "Name " << sr3.getName() << endl;
	cout << "Size " << sr3.getLength() << endl;

	cout << "\n-----------Function 9 + OPERATOR -------------\n\n";
	MyString mstr1("One");
	MyString mstr2("Two");
	MyString mstr3("Three");
	MyString mstr4;
	mstr4 = mstr1 + mstr2 + mstr3;
	cout << mstr1; // should display: One
	cout << mstr2; // should display: Two
	cout << mstr3; // should display: Three
	cout << mstr4; // should display: OneTwoThree

	cout << "\n___working of the relational operators == , <, and <= ____\n\n";
	MyString s1("abc");
	MyString s2("ABC");
	MyString s3("az");
	MyString s4("abc");
	cout << (s1 == s2)<<endl; // should display: 0 (false)
	cout << (s4 == s1)<<endl; // should display: 1 (true)
	cout << (s4 == s4)<<endl; // should display: 1 (true)
	cout << (s1 < s2)<<endl; // should display: 0 (false)
	cout << (s2 < s1)<<endl; // should display: 1 (true)
	cout << (s1 < s3)<<endl; // should display: 1 (true)
	cout << (s1 <= s3)<<endl; // should display: 1 (true)
	cout << (s1 <= s4)<< endl;; // should display: 1 (true)
	cout << (s2 <= s2)<<endl; // should display: 1 (true)
	cout << (s3 < s1)<<endl; // should display: 0 (false)
	cout << (s3 <= s1)<<endl; // should display: 0 (false)
	cout << (s3 <= s3)<<endl; // should display: 1 (true)
	
	cout << "\n-----------Function 13 +=OPERATOR -------------\n\n";
	MyString t1("One");
	MyString t2("Two");
	MyString t3("Three");
	t1 += t2 += t3;
	t1.display(); // should display: OneTwoThree
	t2.display(); // should display: TwoThree
	t3.display(); // should display: Three

	cout << "\n-----------Function 14 setStr -------------\n\n";
	MyString ms1("Hello");
	cout << ms1; // should display: Hello
	ms1.setStr("Welcome to OOP");
	cout << ms1; // should display: Welcome to OOP

	cout << "\n-----------Function 15 conversion operator int-------------\n\n";
	MyString str1("7504");
	MyString str2("56 abc def");
	int i1 = str1; // using the conversion operator int
	int i2 = str2; // using the conversion operator int
	cout << i1<<endl; // should display: 7504
	cout << i2<<endl; // should display: 0
	
	cout << "\n-----------Function 16 conversion operator char*+-------------\n\n";
	MyString st1("Hello World");
	cout <<st1; // should display: Hello World
	char* cp = st1; // using the conversion operator char*
	cout << cp<<endl; // should display: Hello World
	delete[] cp; // Deallocating the dynamically allocated memory
	cp = nullptr;
	cout <<st1; // should still display: Hello World

	cout << "\n-----------Function 17 pre - increment operator ++-------------\n\n";
	//----------pre - increment operator ++---------------
	MyString a2("One !#^; 123 two");
	MyString a3;
	a3 = ++a2;
	a2.display(); // should display: ONE !#^; 123 TWO
	a3.display(); // should display: ONE !#^; 123 TWO

	cout << "\n-------Function 18 stream extraction operator >>------------\n";
	//-----------stream extraction operator >>---------------
	MyString f1("Hello");
	cout << f1; // should display: Hello
	cout << "Enter a MyString: ";
	cin >> f1; // Suppose the user enters: Pakistan Zindabad!!
	cout << f1; // should display: Pakistan Zindabad!!

	return 0;
}