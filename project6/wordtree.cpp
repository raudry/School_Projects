/* 
   Beverly Raudry
   CSCI 3110-001
   Project #6
   Due: 11/07/19
   Description: This file is the class definition file for the WordTree class.
*/

#include "wordtree.h"
#include <iostream>
#include <string>

using namespace std;

WordTree :: WordTree()
{
    //Create and emptry tree
    root = nullptr;
}

WordTree :: ~WordTree()
{
    //Destroys tree
    deleteSubTree(root);
}

void WordTree :: addWord(TreeNode *& nodePtr, string word)
{
    //Is it the first node
    if (root == nullptr)
    {
        //If tree is null, insert the new node as the root node
        TreeNode *newPtr = new TreeNode;
        newPtr -> value = word;
        newPtr -> left = nullptr;
        newPtr -> right = nullptr;
        newPtr -> count = 1;
        root = newPtr;
    }

    //If it is already in the tree, increment the word count
    else if(nodePtr -> value == word)
    {
        nodePtr -> count++;
    }
        //Else, if the word is less than the nodePtr and the left pointer is null, add word
    else if(nodePtr -> value > word)
    {
        if(nodePtr -> left == nullptr)
        {
            TreeNode *newPtr = new TreeNode;
            newPtr -> value = word;
            newPtr -> left = nullptr;
            newPtr -> right = nullptr;
            newPtr -> count = 1;
            nodePtr -> left = newPtr;
        }
        //If not null then keep going down the left of tree
        else
        {
            addWord(nodePtr -> left, word);
        }
    }
    //Else, if the word is greater than nodePtr and the right pointer is null, add word
    else if(nodePtr -> value < word)
    {
        if(nodePtr -> right == nullptr)
        {
            TreeNode *newPtr = new TreeNode;
            newPtr -> value = word;
            newPtr -> left = nullptr;
            newPtr -> right = nullptr;
            newPtr -> count = 1;
            nodePtr -> right = newPtr;
        }
        //If not null then keep going down the right of tree
        else
        {
            addWord(nodePtr -> right, word);
        }
    }
}

void WordTree :: deleteSubTree(TreeNode * nodeptr)
{
    //Start at the root of the tree
    if(root != nullptr)
    {
        //If the left is not null
        if (nodeptr -> left != nullptr)
        {
            //Keep going down left of tree
            deleteSubTree(nodeptr -> left);
            nodeptr -> left = nullptr;
        }
        //If the right is not null
        if (nodeptr -> right != nullptr)
        {   
            //Keep going down the right of tree
            deleteSubTree(nodeptr -> right); 
            nodeptr -> right = nullptr;
        }
        //If nodes right and left pointers are null then delete it
        if (nodeptr -> left == nullptr && nodeptr -> right == nullptr)
        {   
            //If the root and nodePtr are pointing to same thing
            //It is the last node and the tree is not empty
            if(root == nodeptr)
            {
                root = nullptr;
            }
            delete nodeptr; 
        }
    }
}

void WordTree :: getCounts(TreeNode * nodePtr, int max, int & count) const
{
    if(nodePtr != nullptr)
    {
        //Base Case
        if(nodePtr -> left == nullptr && nodePtr -> right == nullptr)
        {
            if(nodePtr -> count >= max)
            {       
                cout << nodePtr -> value << "(" << nodePtr -> count << ")" << endl;
                count += 1;
            }
        }
        else    
        {
            //If it has a right child, traverse to the furthest left child
            if(nodePtr -> left != nullptr)
            {
                getCounts(nodePtr -> left, max, count);
                //When you pop off from calling function with left, you come back here
                if(nodePtr -> count >= max)
                {       
                    cout << nodePtr -> value << "(" << nodePtr -> count << ")" << endl;
                    count++;
                }
            }
            //If it no longer has a left child, go to the right
            if(nodePtr -> right != nullptr)
            {
                if(nodePtr -> left == nullptr)
                {
                    if(nodePtr -> count >= max)
                    {       
                        cout << nodePtr -> value << "(" << nodePtr -> count << ")" << endl;
                        count += 1;
                    }
                }
                getCounts(nodePtr -> right, max, count);
            }
        }
    }
}

//Helper functions
void WordTree :: addWord(string word)
{
    //Call addWord
    addWord(root, word);
}

void WordTree :: findWord(string word)
{
    bool found = 0;
    TreeNode *temp = new TreeNode;
    temp = root;

    //Wile you cannot find the word 
    while(!found && temp != nullptr)
    {
        if (temp -> value == word)
            found = 1;

        else if (temp -> value < word)
            temp = temp -> left;

        else
            temp = temp -> right;
    }
    //If found print out the word and occurences
    if(found)
    {
        cout << "The word '" << word << "' occurs " << temp -> count << " time(s) in the text." << endl;
        cout << endl; 
    }
    //Else print out that it was not found
    else
    {
        cout << "The word '" << word << "' was not found in the text." << endl;
        cout << endl;
    }
}

void WordTree :: getCounts(int threshold)
{
    //Initialize counter 
    int counter = 0;
    //Call getCounts with root, threshold, and counter
    getCounts(root, threshold, counter);
    //Print out of the word was found
    cout << counter << " nodes had words with " << threshold << " or more occurence(s)." << endl;
    cout << endl;
}
