/*
    Beverly Raudry
    CSCI 3110-001
    Project #8
    Due: 12/03/19
    Description: This is the driver file for the Graph class.
*/

#include "graph.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    //Variables
    int vertices, edges, sourceVertex, fromV, toV;
    float cost;
    string directed;
    bool isDir;
    ifstream inFile;

    //Read in from file 
    inFile.open("graph.txt");
    //Number of nodes
    inFile >> vertices;
    Graph myGraph = Graph(vertices);
    //Number of edges
    inFile >> edges;
    //Start node
    inFile >> sourceVertex;
    inFile >> fromV;
    while(inFile)
    {
        inFile >> toV;
        inFile >> cost;
        inFile >> directed;
        if(directed == "false")
            isDir = false;
        else
            isDir = true;
        //Call addEdge to add an edge
        myGraph.addEdge(fromV, toV, cost, isDir);        
        inFile >> fromV;
    }
    inFile.close();
    //Call Dijkstras to find shortest path
    myGraph.DijkstraPaths(sourceVertex);
}
