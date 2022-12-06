/* 
    Beverly Raudry
    CSCI 31130-001
    Project #7
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
        case 1: face = "A";
                break;
        case 11: face = "J";
                break;
        case 12: face = "Q";
                break;
        case 13: face = "K";
                break;
        default: face = to_string(cd.cardFace);
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

    os << face << suit << '[' << cd.cardFace << ']';
    return os;
}

bool Card :: operator < (const Card& cd) const
{
    //Compare and return true if *this has a lesser face value than cd
    //else return false
    if (this -> cardFace < cd.getFaceValue())
        return true;
    else
        return false;
}

bool Card :: operator > (const Card& cd) const
{
    //Compare and return true if *this has a larger face value than cd
    //else return false
    if (this -> cardFace > cd.getFaceValue())
        return true;
    else
        return false;
}

bool Card :: operator <= (const Card& cd) const
{
    //Compare and return true if *this has a less than or equal to face value than cd
    //else return false
    if (this -> cardFace <= cd.getFaceValue())
        return true;
    else
        return false;
}

bool Card :: operator >= (const Card& cd) const
{
    //Compare and return true if *this has a bigger than or equal to face value than cd
    //else return false
    if (this -> cardFace >= cd.getFaceValue())
        return true;
    else
        return false;
}

bool Card :: operator == (const Card& cd) const
{
    //Compare and return true if *this has the same face value than cd
    //else return false
    if (this -> cardFace == cd.getFaceValue())
        return true;
    else
        return false;
}

//Getters
int Card :: getFaceValue() const
{   return cardFace; }

suit Card :: getSuit() const
{   return cardSuit; }
