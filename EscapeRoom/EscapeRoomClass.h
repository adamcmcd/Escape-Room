#ifndef EscapeRoomClass_h
#define EscapeRoomClass_h
#include <iostream>
#include <vector>
#include "PuzzleClass.h"

using namespace std;

class EscapeRoom
{
private:
	string escapeRoomName; //name of escape room
	vector <Puzzle*> puzzlesInRoom;
	Puzzle* currentPuzzle = nullptr;

public:
	void AddPuzzle(Puzzle* newPuzzle); //add puzzle to escape room

	void PrintRoom(); //prints puzzles in escape room
	EscapeRoom(string escapeRoomName); //constructor
};


#endif // !EscapeRoomClass_h