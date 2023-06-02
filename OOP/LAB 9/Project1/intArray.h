#ifndef INTARRAY_H
#define INTARRAY_H
using namespace std;
class IntArray
{
private:
	int* aptr;                     // Pointer to the array
	int arraySize;                 // Holds the array size
	void subscriptError();         // Handles invalid subscripts
public:
	IntArray();
	IntArray(int);                 // Constructor
	IntArray(const IntArray&);    // Copy constructor
	~IntArray();                   // Destructor

	int size() const               // Returns the array size
	{
		return arraySize;
	}
	int& operator[](const int&);  // Overloaded [] operator
	const IntArray& operator = (const IntArray&);  //ASSINMENT OPERATOR
	friend ostream& operator <<(ostream&, const IntArray&);
	//IntArray operator + (int)const;
	//void storeData(const int* data, int n);
	//operator double();
	const IntArray& operator += (const IntArray&);
	IntArray& operator++();
	double operator()(int, int)const;
};
#endif
