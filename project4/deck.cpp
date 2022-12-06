/* 
    Beverly Raudry
    CSCI 31130-001
    Project #4 
    Due: 10/10/19
    Description: This file is the class definition file for the Deck class
*/

#include "card.h"
#include "deck.h"
#include <iostream>
#include <algorithm>
using namespace std;

Deck :: Deck()
{
    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            switch(i)
            {
                case 1: theDeck[index] = Card(j,hearts);
                        break;
                case 2: theDeck[index] = Card(j,spades);
                        break;
                case 3: theDeck[index] = Card(j,diamonds);
                        break;
                case 0: theDeck[index] = Card(j,clubs);
                        break;
                default: break;
            }
            index++;
        }
    }
    topCard = index;
}

Card Deck :: dealCard()
{
    //Remove the top card from the deck and return it
    Card cd = theDeck[topCard - 1];
    topCard = topCard - 1;
    return cd;
}

void Deck :: Shuffle()
{
    //Shuffle the cards in the deck
    random_shuffle (begin(theDeck), end(theDeck));
}

bool Deck :: isEmpty()
{
    //if there are no more cards in the deck, return true
    //else return false
    if (topCard > 0)
        return false;
    else
        return true;
}

ostream& operator << (ostream& os, const Deck& dk)
{
    int index = 51;
    //Display the deck
    for (int i = 0; i < 4; i++)
    {
        for (int j = 12; j >= 0; j--)
        {
            if(j == 0)
                os << dk.theDeck[index] << endl;

            else
                os << dk.theDeck[index] << ' ';

            index--;
        }
    }
    return os;
}
