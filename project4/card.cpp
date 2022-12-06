/* 
    Beverly Raudry
    CSCI 31130-001
    Project #4 
    Due: 10/10/19
    Description: This file is the class definition file for the Card class
*/

#include "card.h"
#include <iostream>
using namespace std;

//Constructor
Card :: Card()
{}

Card :: Card(int face, suit st)
{
    cardSuit = st;
    cardFace = face;
    switch (cardFace)
    {
        case 0: pointValue = 15;
                break;
        case 10: pointValue = 10;
                break;
        case 11: pointValue = 10;
                break;
        case 12: pointValue = 10;
                break;
        default: pointValue = face + 1;
                break; 
    }  
}

//Operator overloaders
ostream& operator << (ostream& os, const Card& cd)
{
    //Variable definitions
    char suit;
    string face;

    //Display the card
    switch (cd.cardFace)
    {
        case 0: face = "A";
                break;
        case 10: face = "J";
                break;
        case 11: face = "Q";
                break;
        case 12: face = "K";
                break;
        default: face = to_string(cd.cardFace + 1);
                break; 
    }
    switch (cd.cardSuit)
    {
        case 0: suit = 'H';
                break;
        case 1: suit = 'S';
                break;
        case 2: suit = 'D';
                break;
        case 3: suit = 'C';
                break;
        default: break;
    }

    os << face << suit << '[' << cd.pointValue << ']';
    return os;
}

bool Card :: operator < (const Card& cd) const
{
    //Compare and return true if *this has a lesser point value than cd
    //else return false
    if (this -> pointValue < cd.getPointValue())
        return true;
    else
        return false;

}

bool Card :: operator > (const Card& cd) const
{
    //Compare and return true if *this has a larger point value than cd
    //else return false
    if (this -> pointValue > cd.getPointValue())
        return true;
    else
        return false;
}

bool Card :: operator == (const Card& cd) const
{
    //Compare and return true if *this has the same point value than cd
    //else return false
    if (this -> pointValue == cd.getPointValue())
        return true;
    else
        return false;
}

//Getters
int Card :: getPointValue() const
{   return pointValue; }

int Card :: getFaceValue() const
{   return cardFace; }

suit Card :: getSuit() const
{   return cardSuit; }
