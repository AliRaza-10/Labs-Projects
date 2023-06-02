//BITF20M010 ALI RAZA
 //ITF20 MORN
#include <iostream>
#include <cstring>
#include<string>
#include "myString.h"
using namespace std;

//  _______Function 1____Default Constructor
MyString::MyString()
{
	length = 0;
	str = new char[length + 1];
	strcpy(str, "");
}

//  _______Function 2____Overloaded Constructor
MyString::MyString(const char* c)
{
	length = strlen(c);
	str = new char[length + 1];
	strcpy(str, c);
}

//  _______Function 3____Destructor
MyString::~MyString()
{
	if (str != nullptr)
	{
		delete []str;
		str = nullptr;
	}
}

//  _______Function 4____Display
void MyString::display()const
{
	cout <<str<<endl;
}

//  _______Function 5____GetLength
int MyString::getLength()const
{
	return  length;
}
char* MyString::getName()const
{
	return str;
}

//  _______Function 6____Copy Constructor
MyString::MyString(const MyString& orig)
{
	length = orig.length;
	str = new char[length + 1];
	strcpy(str, orig.str);
}

//  _______Function 7____Assignment Operator
const MyString& MyString:: operator = (const MyString& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		length = rhs.length;
		if (str != 0)
		{
			delete[]str;
			str = nullptr;
		}
		str = new char[length + 1];
		strcpy(str, rhs.str);
		return *this;

	}
}

//  _______Function 9______ 
MyString MyString :: operator + (const MyString& s)const
{
	MyString temp;
	int size =this->length+s.length;
	temp.length = size;
	//cout <<"This size" << this->length << endl;
	//cout << "S size" << s.length << endl;
	temp.str = new char[temp.length + 1];
	int i = 0;
	for (i; str[i] != '\0'; i++)
	{
		temp.str[i] = str[i];
	}
	for (int j = 0; s.str[j] != '\0'; j++)
	{
		temp.str[i] = s.str[j];
		i++;
	}
	temp.str[i] = '\0';
	return temp;
}

//  _______Function 10______ 
bool MyString::operator == (const MyString& rhs)const
{
 bool status = true;
	int i = 0;
	while (str[i] != '\0'||rhs.str[i]!='\0')
	{
		if (str[i] == rhs.str[i])
		{
			status = true;

		}
		else
		{
			status = false;
			break;
		}
		i++;
	}
	if (status)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
//  _______Function 11______ 
bool MyString::operator < (const MyString& rhs)const
{
		int flag = 0;
		int rhsFlag = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z' || rhs.str[i] >= 'A' && rhs.str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z' || rhs.str[i] >= 'a' && rhs.str[i] <= 'z')
			{
				if (str[i] < rhs.str[i])
				{
					flag = str[i];
					rhsFlag = rhs.str[i];
				}

			}
		}
			if(flag < rhsFlag)
			{
				return true;
			}
			else
			{
				return false;
			}	
}
// _______Function 12______
bool MyString::operator <= (const MyString& rhs)const
{
	int flag = 0;
	int rhsFlag = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && rhs.str[i] >= 'A' && rhs.str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z' && rhs.str[i] >= 'a' && rhs.str[i] <= 'z')
		{
			if (str[i] <= rhs.str[i] || str[i] >= rhs.str[i])
			{
				flag = flag + str[i];
				rhsFlag = rhsFlag + rhs.str[i];
			}

		}
	}
	if (flag <= rhsFlag)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//________Function 13________
const MyString& MyString:: operator += (const MyString& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	else
	{
		MyString temp;
		temp = str;
		temp.length = length;
		delete[]str;
		str = nullptr;
		int size = length + ref.length;
		length = size;
		str = new char[length + 1];
		int i;
		for (i = 0; i < temp.length; i++)
		{
			str[i] = temp.str[i];
		}
		for (int j = 0; ref.str[j] != '\0'; j++)
		{
			str[i] = ref.str[j];
			i++;
		}
		str[i] ='\0';
		return *this;

	}
	
}

//________Function 14________
void MyString::setStr(const char* s)
{
	delete[]str;
	str = nullptr;
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
}

//________Function 15________
MyString::operator int()
{
	int sum = 0;
	int flag = 0;
	for (int i = 0 ; i < length; i++)
	{
		if( str[i] >= '0' && str[i] <= '9')
		{
			str[i]  -= 48;
			sum = (sum*10)+str[i];
		}
		else
		{
			sum=0;
			break;
		}
	}
	
	return sum;
	
}

//________Function 16________
MyString::operator char*()
{
	char* c = nullptr;
	c = new char[length+1];
	strcpy(c,str);
	return c;
}

//________ Function 17------
MyString& MyString:: operator++()
{
	for (int i = 0; i <= str[i]; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
	}
	return *this;
}
