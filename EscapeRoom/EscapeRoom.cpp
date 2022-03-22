// EscapeRoom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "EscapeRoomClass.h"
#include "EscapeRoomClass.cpp"
#include "PuzzleClass.h"
#include "PuzzleClass.cpp"

using namespace std;


int main()
{
    string input = ""; //empty string to assign text from text file

    vector <EscapeRoom*> myRooms;
    vector <Puzzle*> myPuzzles;
    EscapeRoom* tempRoom;
    Puzzle* tempPuzzle;

    ifstream file("EscapeRooms.txt"); //opens text file for reading
    if (file) //check if text file has opened properly
    {
        cout << "Reading in from text file..." << endl;
        while (file >> input)
        {
            if (input.back() == ':') //new room
            {
                //instantiate EscapeRoom
                tempRoom = new EscapeRoom(input);
                myRooms.push_back(tempRoom);

                cout << endl << "Adding Room: " + input << endl;
            }
            else //new puzzle
            {
                //instantiate puzzle and add to room
                tempPuzzle = new Puzzle(input);
                myRooms.back()->AddPuzzle(tempPuzzle);
                myPuzzles.push_back(tempPuzzle);
                cout << "Adding Puzzle: " + input << endl;
            }
        }

        //Print escape room function
        cout << endl << "Printing Rooms:" << endl;
        for (EscapeRoom* room : myRooms)
        {
            room->PrintRoom();
        }
        //Print puzzle and connection function
        cout << endl << "Printing Puzzles:" << endl;
        for (Puzzle* puzzle : myPuzzles)
        {
            puzzle->PrintPuzzle();
        }
    }
    else //text file not opened properly
    {
        cout << "file has not opened" << endl;
    }
    file.close();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
