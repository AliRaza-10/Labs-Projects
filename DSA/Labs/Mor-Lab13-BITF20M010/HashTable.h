#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
using namespace std;
class HashTable {
private:
	string* table; // Dynamic array of strings to be used to store names
	int S; // Total number of slots in the table
	int n; // Current number of elements present in the table
public:
	HashTable(int size);
	// Constructor to allocate and initialize an empty hash table of the specified size
	~HashTable(); // Destructor
	bool isEmpty(); // Checks whether the hash table is empty or not
	bool isFull(); // Checks whether the hash table is full or not
	double loadFactor(); // Calculates & returns the load factor of the hash table (n/S)
	int linearProbingFunction(int);
	bool remove(string);
	void display();
	bool search(string);
	bool insert(string);
	int getHashValue(string name); // Private member function of HashTable class
	bool insert(int);
};

#endif // !HASHTABLE_H
