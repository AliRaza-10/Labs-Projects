#ifndef STUDENTNODE_H
#define STUDENTNODE_H
#include <iostream>
#include <string>
#include "StudentBST.h"
using namespace std;
class StudentNode
{
	friend class StudentBST;
private:
	int rollNo; // Studentís roll number (must be unique)
	string name; // Studentís name
	double cgpa; // Studentís CGPA
	StudentNode* left; // Pointer to the left subtree of a node
	StudentNode* right; // Pointer to the right subtree of a node
};
#endif // !STUDENTNODE_H
