/*
    Beverly Raudry
    CSCI 3110-001
    Project #7
    Due: 11/07/19
    Description: This is the declaration and definition file for the priorityqueue class.
*/

#include <iostream>
#include <vector>
#include "card.h"
#include <iomanip>

using namespace std;

template <class T1, class T2>
class PriorityQueue
{
    private:
        //heapUp function
        void heapUp(int index)
        {
            //variable of comparator type
            T2 comp;
            //keeps up with the position of child
            T1 el = heap[index];
            while((index != 0) && (comp.compare(el, heap[(index - 1) / 2])))
            {
                //Swap the el and its parent
                T1 temp = heap[(index - 1) / 2]; 
                heap[(index - 1) / 2] = el; //parent
                heap[index] = temp; //child
                //Change the position 
                index = (index - 1) / 2;
            }
        }
        //heapDown function
        void heapDown(int index)
        {
            //Variables
            T1 swp;    //holds greatest or smallest child
            T1 el = heap[index];    //holds position of element to be swapped
            bool leaf;
            //Determine if the element is a leaf
            if(((2 * index) + 1 <= heapSize - 1) && ((2 * index) + 2  <= heapSize  - 1))
                leaf = false;
            else 
                leaf = true;
            //Hold the values of the left and right child
            T1 leftChild; 
            T1 rightChild;

            while((index == 0) || (leaf == false))
            {  
                T2 comp;
                //Get the values of the left and right child
                leftChild = heap[(2 * index) + 1];
                rightChild = heap[(2 * index) + 2];
                //if the right child is greater
                //set rightChild = to greater variable and change index
                if(comp.compare(leftChild, rightChild) == true)
                {
                    swp = leftChild;
                    index = (2 * index) + 1;                
                }
                //else leftChild = to greater variable and change index
                if(comp.compare(rightChild, leftChild) == true)
                {
                    swp = rightChild;
                    index = (2 * index) + 2;
                }
                //swap with the greater or smallet variable
                if(comp.compare(swp, el))
                {
                    heap[index] = el;
                    heap[(index - 1) / 2] = swp;
                }
                //Check to see if the elemnt has a leaf again sice you changed positions
                if(((2 * index) + 1 <= heapSize - 1) && ((2 * index) + 2  <= heapSize  - 1))
                    leaf = false;
                else 
                    leaf = true;
            }
        }

        vector<T1> heap;

        int heapSize;
        
    public:
        //Constructor
        PriorityQueue()
        {
            heap.resize(50);
            heapSize = 0;
        }

        //Removes the highest priority item
        void dequeue()
        {
            //Get the element from the root
            T1 rootel = heap[0];

            //Print out the element that was extracted
            cout << "Dequeued " << rootel << " ";
               
            //Store the element from the last leaf
            T1 lastel = heap[heapSize - 1];

            //Put the element from the last leaf at the root
            heap[0] = lastel;

            //Removes the last leaf
            heapSize -= 1;

            //call heapDown 
            heapDown(0);       
        }

        //Takes in a parameter: item to be enqueued.Enqueues item and places it at end
        void enqueue(T1 el)
        {
            if(heapSize == 0)
            {
                heap[heapSize] = el;
                heapSize += 1;
            }
            else
            {
                heap[heapSize] = el;
                heapUp(heapSize);
                heapSize += 1;
            }
        }

        //Returns true if the queue is empty
        bool empty()
        {
            if(heapSize == 0)
                return true;
            else 
                return false;
        }

        //Display the items in the heap, from index 0 through number of elements - 1
        void print()
        {
            for(int i = 0; i < heapSize; i++)
                cout << heap[i] << " "; 
            cout << endl;
        }
};

template <class T>
class LessThanComparator
{
    public:
        bool compare(T lhs, T rhs) const
        {   
            if(lhs <= rhs)
                return true;

            else
                return false;
        }
};

template <class T>
class GreaterThanComparator
{
    public:
    bool compare(T lhs, T rhs) const
    {
        if (lhs >= rhs)
            return true;
        else
            return false;
    }
};
