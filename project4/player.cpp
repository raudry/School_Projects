/* 
    Beverly Raudry
    CSCI 31130-001
    Project #4 
    Due: 10/10/19
    Description: This file is the class definition file for the Player class
*/

#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

//Constructor - defaults to "unknown" if not supplied
Player :: Player(string pname)
{
    name = pname;
    score = 0;
    //My cards have not been played yet
    for (int i = 0; i < Max_Cards; i++)
        //hasPlayed[i] == false: means that there is not a card in that slot
        hasPlayed[i] = false;
}

Card Player :: playCard()
{
    //Play the card with the highest value
    Card cd;
    int maxIndex;

    //Pick one of the cards to be the first card
    if(hasPlayed[0] == true)
    {
        cd = hand[0];
        maxIndex = 0;
    }
    else if(hasPlayed[1] == true)
    {
        cd = hand[1];
        maxIndex = 1;
    }
    else
    {
        cd = hand[2];
        maxIndex = 2;
    }

    //Check all three cards
    for(int i = 0; i < Max_Cards; i++)
    {
        if (hasPlayed[i] == true)
        {
        //If one of them is higher than the first card that was chose, then make that one the new max
        if(i > 0)
        {
            //If one of them is greater than the first one     
            if (cd.getPointValue() < hand[i].getPointValue())
            {
                cd = hand[i];
                maxIndex = i;
            }
            //If they have the same point values
            else if (cd.getPointValue() == hand[i].getPointValue())
            {
                //The one with the highest face value gets picked
                if (cd.getFaceValue() < hand[i].getFaceValue())
                {
                    cd = hand[i];
                    maxIndex = i;
                }
                else if (cd.getSuit() > hand[i].getSuit())
                {
                    cd = hand[i];
                    maxIndex = i;
                }
            }
        }
        }
    }
    //Set the card that was played to false, because there is now not a card in that slot
    hasPlayed[maxIndex] = false;   
    return cd;
}

void Player :: drawCard(Deck& dk)
{
    //Draw the top card from the deck to replace played card in hand
    //Check to see if there are cards left in the deck
    bool isEmpty = dk.isEmpty();
    //Is there a card in hand
    bool inHand = false;
    //Index for where to put the card
    int count = 0;
    
    //If there are still cards in deck
    if(isEmpty == false)
    {
        //While we search for where to put the card
        while(inHand == false)
        {
            //If the card has been played
            if (hasPlayed[count] == false)
            {
                //Place card in hand
                hand[count] = dk.dealCard();
                //Set the hasPlayed back to true
                hasPlayed[count] = true;
                //The player now has another card in hand so break out
                inHand = true;
            }
            count++;
        }
    }
}

bool Player :: emptyHand() const
{
    //the hand is not empty
    bool isEmpty;

    //If all the cards are missing then the hand is empty
    if (hasPlayed[0] == false && hasPlayed[1] == false && hasPlayed[2] == false)
        isEmpty = true;
    else
        isEmpty = false;

    return isEmpty;
}

void Player :: addScore(Card acard)
{
    //Add the point value of the card to the player's score
    score += acard.getPointValue();
}

int Player :: getScore() const
{
    //return the score the player has earned so far
    return score;
}

string Player :: getName() const
{
    //return the name of the player
    return name;
}

ostream& operator << (ostream& os, const Player& pr)
{
    Card tempCard;
    //cout << cards in players hand or ___ if no card

    for(int i = 0; i < pr.Max_Cards; i++)
    {
        tempCard = pr.hand[i];
        //If there are cards in the hand
        if (pr.hasPlayed[i] == true)
        {
            //tempCard = pr.hand[i];
            if (i < 2)
            {
                os << tempCard << " ";
            }
            else 
               os << tempCard;
       }
       else
           os << "_____ ";
    }

    return os;
}
