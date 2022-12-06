/*
    Beverly Raudry
    CSCI 3110-001
    Project #4
    Due: 10/10/19
    Description: This is the client file for the Maze class.
*/

#include "maze.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool exitFound = false;

    //Read from the file and call the constructor
    ifstream myin;

    myin.open("maze.txt");
 
    Maze myMaze = Maze(myin);
    
    //Print out initial maze
    cout << "Maze state:" << endl;
    myMaze.Print();
    cout << "Starting position: 1,1" << endl;

    myMaze.FindExit(1, 1, exitFound);

    if (exitFound == true)
        cout << "Found exit!" << endl;

    else
        cout << "No exit!" << endl;
}
