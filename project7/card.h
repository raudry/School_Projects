/*
    Beverly Raudry
    CSCI 3110-001
    Project #7
    Due: 11/19/19
    Description: This is the declaration file for the card class.
*/

#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

enum suit {hearts, spades, diamonds, clubs};

class Card
{
    public:
        //default constructor - required
        Card();

        //constructor that takes a card's face value (an integer) and its suit
        //card face example: Ace = 1, 2 = 2, 3 = 3, ... Q = 12, K = 13
        Card(int face, suit st);

        //overloas the << operator to display the card
        friend ostream& operator << (ostream& os, const Card& cd);

        //compare and return true if *this has a lesser face value than cd
        //false otherwise
        bool operator < (const Card& cd) const;

        //compare and return true if *this has a less than or equal to face value than cd
        //false otherwise
        bool operator <= (const Card& cd) const;
        
        //compare and return true if *this has a greater than or equal to face value than cd
        //false otherwise
        bool operator >= (const Card& cd) const;

        //compare and return true if *this has a larger face value than cd
        //false otherwise
        bool operator > (const Card& cd) const;

        //compare and return if *this has the same face value as cd
        //false otherwise
        bool operator == (const Card& cd) const;

        //return the face value of the card: Ace: 0, 2: 1, 3: 2, ... Queen: 11, King: 12
        int getFaceValue() const;

        //return the card's suit: clubs, hearts, spades, diamonds
        suit getSuit() const;

    private:
        suit cardSuit;  //card's suit
        int cardFace;   //card's face value
        
};
#endif
