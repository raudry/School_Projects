/* 
   Beverly Raudry
   CSCI 3110-001
   Project #5
   Due: 10/29/19
   Description: This file is the class definition file for the Maze class.
*/


#include "maze.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
Maze :: Maze(ifstream& inFile)
{
    //Read in the file and store in private members
    inFile >> xplor;
    inFile >> maxRows >> maxCols;

    //Increment by two to take in ocunt the border
    maxRows = maxRows + 2;
    maxCols = maxCols + 2;
    
    //Read in the maze and add borders
    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxCols; j++)
        {
            if(i == 0 || i == (maxRows - 1))
            {
                maze[i][j] = 'X';
            }
            else if (j == 0 || j == (maxCols - 1))
            {
                maze[i][j] = 'X';
            }
            else
                inFile >> maze[i][j];
        }
    }
}

void Maze :: Print()
{
    //Print out maze not including the borders
    for (int i = 1; i < maxRows - 1; i++)
    {
        for (int j = 1; j < maxCols - 1; j++) 
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void Maze :: FindExit(int r, int c, bool& exitFound)
{
    //Create a pair of ints
    pair<int, int> pairDir;

    //Base case; if the exit is found
    if (maze[r][c] == 'E')
    {
        exitFound = true;
        cout << "Maze state: " << endl;
        Print();
        cout << "Exploring " << r << ", " << c << endl;      
    }
    
    //Else if it is not found, explore the area if it is a O
    else if (maze[r][c] != 'X')
    {
        //If place has not been visited
        if (maze[r][c] != '*')
        {
            //Place bread crumb because it has now been visited
            maze[r][c] = '*';
            //Print maze when you place breadcrumb
            cout << "Exploring " << r << ", " << c << endl;
            cout << "Maze state: " << endl;
            Print();
            //Check every direction
            for (int i = 0; i < xplor.length(); i++)
            {
                //Decide which way to go
                pairDir = getMove(xplor[i]);
                //Recursive call that sends in a new row and col based on the
                //pairs returned from getMove added to the original row and coloumn  
                FindExit(r + pairDir.first, c + pairDir.second, exitFound);
            }
        }
    }
}

pair<int, int> Maze :: getMove(char direction)
{
    pair<int, int> moveDir;
    //Return a pair of ints that tells the computer where to move
    switch(direction)
    {
        case 'N': moveDir = make_pair(-1, 0);
                  break;
        case 'S': moveDir = make_pair(1, 0);
                  break;
        case 'E': moveDir = make_pair(0, 1);
                  break;
        case 'W': moveDir = make_pair(0, -1);
                  break;
    }
    return moveDir;
}
