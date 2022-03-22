#ifndef PuzzleClass_h
#define PuzzleClass_h
#include <iostream>
#include <vector>

using namespace std;

class Puzzle
{
protected:
	static bool completed;
	string puzzleName; //name of the puzzle
	vector <Puzzle*> Connection; //next puzzle in escape room

public:
	Puzzle(string tempName); //constructor
	void LinkPuzzles(Puzzle *firstPuzzle); //link one puzzle to the next based on what's read from the text file
	void PrintPuzzle(); //prints the puzzle name and the connections to it
	string ReturnPuzzleName(); //return name of puzzle
	void ResetBool();

	static bool ReturnCompleted();
};


#endif // !PuzzleClass_h