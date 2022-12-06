/*
    Beverly Raudry
    CSCI 3110-001
    Project #7
    Due: 11/19/19
    Description: This is the driver file for the priority queue.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include "priorityqueue.h"
#include "card.h"

using namespace std;

int main()
{
    //Variables
    int seed;
    
    //Insantiate min priorityqueue and max priorityqueue
    PriorityQueue <Card, GreaterThanComparator<Card>> maxHeap;
    PriorityQueue <Card, LessThanComparator<Card>> minHeap;

    //Instantiate two arrays of 13 Cards
    Card spadesArr[13];
    Card heartsArr[13];

    for(int i = 0; i < 13; i++)
    {
        spadesArr[i] = Card(i + 1, spades);
        heartsArr[i] = Card(i + 1, hearts);
    }

    //Reading in the seed
    ifstream myin;
    myin.open("pqseed.txt");
    myin >> seed;
    srand(seed);
    
    myin.close();
    //Shuffle cards
    random_shuffle(begin(spadesArr), end(spadesArr));
    random_shuffle(begin(heartsArr), end(heartsArr));
    
    //Enqueue 13 spades into a max priorityqueue and print out the heap
    for(int i = 0; i < 13; i++)
    {
        maxHeap.enqueue(spadesArr[i]);
        cout << "Enqueued " << spadesArr[i] << " "; 
        maxHeap.print(); 
    }
    cout << endl;
    
    //Dequeue 13 spades out of a max priorityqueue and print out the heap
    for(int i = 0; i < 13; i++)
    {
        maxHeap.dequeue();
        maxHeap.print(); 
        if(maxHeap.empty() == true)
            cout << "Max Heap Empty" << endl;
    }
    cout << endl;

    //Enqueue 13 hearts into a min priorityqueue and print out the heap
    for(int i = 0; i < 13; i++)
    {
        minHeap.enqueue(heartsArr[i]);
        cout << "Enqueued " << heartsArr[i] << " "; 
        minHeap.print(); 
    }
    cout << endl;

    //Dequeue 13 spades out of a max priorityqueue and print out the heap
    for(int i = 0; i < 13; i++)
    {
        minHeap.dequeue();
        minHeap.print(); 
        if(minHeap.empty() == true)
            cout << "Min Heap Empty" << endl;
    }
    cout << endl;
}   
