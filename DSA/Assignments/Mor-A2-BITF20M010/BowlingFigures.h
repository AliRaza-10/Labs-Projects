#ifndef BOWLINGFIGURES_H
#define BOWLINGFIGURES_H
#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LENGTH = 25;
struct BowlingFigures 
{
	char name[NAME_LENGTH + 1]; // Name of the bowler
	int wickets; // Wickets taken by the bowler
	int runs; // Runs conceded by the bowler
};

#endif // !BOWLINGFIGURES_H
