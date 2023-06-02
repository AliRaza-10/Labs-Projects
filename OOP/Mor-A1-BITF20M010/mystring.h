#ifndef MYSTRING_H
#define MYSTRING_H
using namespace std;
class MyString
{
private:
	char* str;;
	int length;

public:
	MyString();
	MyString(const char*);
	~MyString();
	void display()const;
	int getLength()const;
	char* getName()const;
	MyString(const MyString& ); 
	const MyString& operator = (const MyString&);
	friend ostream& operator << (ostream&, const MyString&);
	MyString operator +(const MyString&) const; 
	bool operator == (const MyString& )const;
	bool operator < (const MyString&)const;
	bool operator <= (const MyString&)const;
	const MyString& operator += (const MyString&);
	void setStr(const char*);
	operator int();
	operator char*();
	MyString& operator++();
	friend istream& operator >> (istream&,  MyString&);


};
#endif
