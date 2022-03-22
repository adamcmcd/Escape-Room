#include "PuzzleClass.h"
#include <iostream>

using namespace std;

bool Puzzle::completed = false;

Puzzle::Puzzle(string tempName)
{
	puzzleName = tempName;
}

void Puzzle::LinkPuzzles(Puzzle* firstPuzzle)
{
	Connection.push_back(firstPuzzle);
}

void Puzzle::PrintPuzzle()
{
	cout << endl << "Puzzle Name: " + puzzleName << endl;
	for (Puzzle* connect : Connection)
	{
		bool tempCompleted = connect->ReturnCompleted;
		if (tempCompleted) //check puzzle hasnt already been completed
		{
			string name = connect->ReturnPuzzleName();
			cout << "Connection: " + name << endl;
			completed = true; //this puzzle has no been completed
		}
	}
}

string Puzzle::ReturnPuzzleName()
{
	return puzzleName;
}

void Puzzle::ResetBool()
{
	completed = true;
}

bool Puzzle::ReturnCompleted()
{
	return completed;
}