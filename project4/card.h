/* 
   Beverly Raudry
   CSCI 3110-001
   Project #4
   Due: 10/13/19
   Description: This file is the class declaration file for the Card class.
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
        //card face example: Ace = 0, 2 =1, 3= 2, ... Q = 11, K = 12
        Card(int face, suit st);

        //overloas the << operator to display the card
        friend ostream& operator << (ostream& os, const Card& cd);

        //compare and return true if *this has a lesser point value than cd
        //false otherwise
        bool operator < (const Card& cd) const;

        //compare and return true if *this has a larger point value than cd
        //false otherwise
        bool operator > (const Card& cd) const;

        //compare and return if *this has the same point value as cd
        //false otherwise
        bool operator == (const Card& cd) const;

        //return the point value of the card: Ace: 15, Faces: 10, Numbers: the number
        int getPointValue() const;

        //return the face value of the card: Ace: 0, 2: 1, 3: 2, ... Queen: 11, King: 12
        int getFaceValue() const;

        //return the card's suit: clubs, hearts, spades, diamonds
        suit getSuit() const;

    private:
        suit cardSuit;  //card's suit
        int cardFace;   //card's face value
        int pointValue; //card's point value (from its face)
        
};
#endif
