/*
    Beverly Raudry
    CSCI 3110-001
    Project #8
    Due: 12/03/19
    Description: This is the declaration file for the Graph class.
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>

using namespace std;

struct PathNode {		// Use to determine shortest path
	double cost;		// Path cost from source vertex to this vertex
	int prev;			// Vertex preceding this vertex in the shortest path
};

struct Edge {			// Represents an edge
	int v1, v2;			// From vertex, To vertex
	double weight;		// Edge weight
	Edge(int vertex1, int vertex2, double wt) :		// Edge constructor: from, to, weight
		v1{vertex1}, v2{vertex2}, weight{wt} {};	// initialized with initialization list
};

class Graph
{
public:
	Graph(int);								// Contructor - Param(s): Number of vertices
	void addEdge(int, int, double, bool);	// Add edge to adjacency list (display as added) - Param(s): From vertex, To vertex, Weight, Directed edge?
	void DijkstraPaths(int);				// Computes/Outputs single source shortest paths - Param: source vertex				
private:
	int numVertices;						// Number of vertices in graph
	vector<list<Edge>> adjacent;	// Adjacency list for vertices
};

#endif
