//BITF20M010 ALI RAZA
 //ITF20 MORN
// Implementation file for the IntArray class
 #include <iostream>
 #include <cstdlib>   // For the exit function
 #include "intArray.h"
 using namespace std;

//*******
// Constructor for IntArray class. Sets the size of the *
// array and allocates memory for it.                   *
//*******

IntArray::IntArray(int s)
{
	arraySize = s;
	aptr = new int[arraySize];
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

//******
// Copy Constructor for IntArray class.                *
//******

IntArray::IntArray(const IntArray& obj)
{
	arraySize = obj.arraySize;
	aptr = new int[arraySize];
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

//******
// Destructor for IntArray class.                      *
//******

IntArray::~IntArray()
{
	if (arraySize > 0)

		delete[] aptr;

}

//*******
// subscriptError function. Displays an error message and   *
// terminates the program when a subscript is out of range. *
//*******

void IntArray::subscriptError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(0);
}

//*******
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******

int& IntArray::operator[](const int& sub)
{
	if (sub < 0 || sub >= arraySize)
		subscriptError();
	return aptr[sub];
}
const IntArray& IntArray:: operator = (const IntArray& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		if (arraySize > 0)
		{
			delete aptr;
			aptr = NULL;
		}
		aptr = new int[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			aptr[i] = rhs.aptr[i];
		}
		return *this;

	}
}
IntArray IntArray::operator +(int h) const
{
	IntArray sum(arraySize);
	for (int j = 0; j < sum.arraySize; j++)
	{
		*(sum.aptr + j) = *(aptr + j) + h;
	}
	return sum;
}
void IntArray::storeData(const int* data, int n)
 {
 	if(n!=arraySize)
 	{
 		arraySize = n;
 		aptr = nullptr;
 		aptr = new int[n];
 		for(int count = 0; count<n;count++)
 		{
 			aptr[count]=data[count];
		 }
	 }
 }
IntArray::operator double()
{
	double temp;
	double count = 0;
	for(int i = 0; i<arraySize;i++)
	{
		temp+= aptr[i];
		count++;
	}
	return temp/count;
	
}