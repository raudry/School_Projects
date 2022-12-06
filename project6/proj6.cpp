/*
    Beverly Raudry
    CSCI 3110-001
    Project #6
    Due: 11/07/19
    Description: This is the client file for the wordTree class.
*/

#include "wordtree.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    //Variables
    string word, findWord;
    char query;
    int maxCount;

    //Instantiate WordTree object
    WordTree tree = WordTree();  
    
    //Read in from the input file
    ifstream myin;
    myin.open("input.txt");
    
    while(myin)
    {
        //Read in a word
        myin >> word;
        //Transform the word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        //Call the helper function passing it the word to be put in tree
        tree.addWord(word);
    }
    
    //Close file
    myin.close();

    //Print that the tree is loaded
    cout << "Word tree built and loaded" << endl;
    cout << endl;
    
    //Read in querie file
    ifstream inFile;
    inFile.open("queries.txt");
    
    //Read in first query
    inFile >> query;
    while(inFile)
    {
        //If the query is C call the getCounts helper function
        if(query == 'C')
        {
            inFile >> maxCount;
            cout << "Finding all the words with " << maxCount << " or more occurences:" << endl;
            cout << endl;
            tree.getCounts(maxCount);
        }
        //Else call the findWord helper function
        else if(query == 'F')
        {
            inFile >> findWord;
            cout << "Searching for occurences of the word '" << findWord << "'" << endl;
            tree.findWord(findWord);
        }
        //Read in next query
        inFile >> query;
    }
    //Close file
    inFile.close();
}
