/*
    Beverly Raudry
    CSCI 3110-001
    Project #8
    Due: 12/03/19
    Description: This is the definition file for the graph class.
*/

#include "graph.h"
#include <iostream>
#include <limits>
#include <list>
#include <set>

using namespace std;

Graph :: Graph(int vNum)
{
    numVertices = vNum;
    adjacent.resize(vNum);
}

void Graph :: addEdge(int v1, int v2, double weight, bool edge)
{
    //Passing variables to the Edge constructor
    Edge myEdge = Edge(v1, v2, weight);
    adjacent[v1].push_back(myEdge);    
    
    //Print statement
    cout << "Edge " << v1 << ", " << v2 << ", " << weight << endl;
}

void Graph :: DijkstraPaths(int sourceV)
{
    //Create a pathNode array
    PathNode pathArr[numVertices];
    for(int i = 0; i < numVertices; i++)
    {
            //If it is the sourceVertex, set it equal to 0
            if(i  == sourceV)
                pathArr[i].cost = 0;
            else
                pathArr[i].cost = numeric_limits<double> :: infinity();

            pathArr[i].prev = -1;
    }

    //Create openlist
    set<pair<double, int>> openlist; // Holds the cost(double) and the vertex ID(int)
    //Insert into openlist
    openlist.insert(make_pair(0,sourceV));
    
    //while(openlist.empty() == false)
    //{
        bool found;
        pair<double, int> firstItem = *(openlist.begin());
        //Created a list of edges
        list<Edge> edges = adjacent[firstItem.second];
        //Erase from openlist
        openlist.erase(openlist.begin());
        //Update it
        //openlist.find(make_pair(*(openlist.begin()).first, *(openlist.begin()).second));
        
        //Add to openlist
        list<Edge> :: iterator edgeIt;
        for(edgeIt = edges.begin(); edgeIt != edges.end(); ++edgeIt)
        {
            openlist.insert(make_pair(edgeIt -> weight, edgeIt -> v2));
            cout << "Cost: " << edgeIt -> weight << endl;
            cout << "Vertex Id: " << edgeIt -> v2 << endl;

        }
        
        //Update pathnode
        for(auto const &x : openlist)
        {
            if(pathArr[x.second].cost == infinity())
            {
                pathArr[x.second].cost = pathArr[firstItem.second].cost + x.first;
                pathArr[x.second].prev = firstItem.second;
            }
        }
}
