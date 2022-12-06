/* 
   Beverly Raudry
   CSCI 3110-001
   Project #5
   Due: 10/29/19
   Description: This file is the class declaration file for the Maze class.
*/

#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <string>

using namespace std;

class Maze
{
    public:
        //Constructor: takes file object and reads maze map from file
        Maze(ifstream&);

        //Displays the maze and its state
        void Print();

        //Recursive function that finds the exit(ints: row, then column)
        void FindExit(int, int, bool&);

    private:
        //2D array that holds maze - outer columns and rows not traversable
        char maze[10][10];

        //Maximum number of ows - excludes outer walls
        int maxRows;

        //Maximum number of columns - excludes outer walls
        int maxCols;

        //4-element string dictating order of maze exploration:
        //N = North, S = South, E = East, W = West
        string xplor;

        //Return a pair (row, then column offset) from these values: (-1, 0 1)
        pair<int, int> getMove(char);

};

#endif
