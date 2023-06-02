#include<iostream>
#include <string>
using namespace std;
int main()
 {
		
		string name, city, profession, animal, petName,college;
		int age;
		cout << "please enter your name : ";
		getline(cin,name);
		cout << "please enter your city : ";
		getline(cin, city);
		cout << "please enter your age :  ";
		cin >> age;
		cin.ignore();
		cout << "please enter your profession :  ";
		getline(cin, profession);
		cout << "please enter your type of animal : ";
		getline(cin, animal);
		cout << " please enter your pets name: ";
		getline(cin, petName);
		cout << "please enter your college name: ";
		getline(cin, college);
		cout << "There once was a person named " << name << " who lived in" <<city<<"At the age of AGE of ";
		cout << age<<" , " <<name<< " went to college at COLLEGE." << college<<"." <<name<< " graduated and went to work as a";
		cout <<profession<<"Then, " << name<< " adopted "<<animal<<" named " << petName << " they both lived";
		cout << " happily ever after!";
}
