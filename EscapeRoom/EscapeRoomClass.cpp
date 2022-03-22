#include "EscapeRoomClass.h"
#include <iostream>

using namespace std;

void EscapeRoom::AddPuzzle(Puzzle* newPuzzle)
{
	if (puzzlesInRoom.size() == 0) //first puzzle in room
	{
		currentPuzzle = newPuzzle;
	}
	else
	{
		currentPuzzle->LinkPuzzles(newPuzzle);
		currentPuzzle = newPuzzle;
	}

	puzzlesInRoom.push_back(newPuzzle);
}

void EscapeRoom::PrintRoom()
{
	cout << "<" + escapeRoomName + "> ";

	for (Puzzle* puzzles : puzzlesInRoom)
	{
		string name = puzzles->ReturnPuzzleName();
		cout << "<" + name + "> ";
	}
	cout << endl;
}

EscapeRoom::EscapeRoom(string tempName)
{
	escapeRoomName = tempName;
}