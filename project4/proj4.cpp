/*
    Beverly Raudry
    CSCI 3110-001
    Project #4
    Due: 10/10/19
    Description: This is the client file for the Card, Player, and Deck classes.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "deck.h"
#include "card.h"
#include "player.h"

using namespace std;

int main()
{
    //Instantiation 
    Deck dk = Deck();
    Player player1, player2;
    Card p1Card, p2Card;

    //Variable definitions
    string P1, P2;
    int seed;

    //Open file
    ifstream myin;
    myin.open("cardgame.txt");

    myin >> P1;
    myin >> P2;
    myin >> seed;
    
    cout << dk << endl;
   
    srand(seed);
    dk.Shuffle();

    cout << dk << endl;

    player1 = Player(P1);
    player2 = Player(P2);    


    for (int i = 0; i < 3; i++)
    {
        player1.drawCard(dk);
        player2.drawCard(dk);
    }

    bool isEmpty1 = false;
    bool isEmpty2 = false;
    
    //How many games have been played
    int gamesPlayed = 1;   
       
    while (isEmpty1 == false && isEmpty2 == false)///for (int i = 1; i < 27; i++)
    {
        //Pre-play cout statement
        cout << gamesPlayed << ") " << player1.getName() << " " << player1 << '(' << player1.getScore() << ')' << " - " 
        << player2.getName() << " " << player2 << '(' << player2.getScore() << ')' << endl;

        //Returns the card they are going to play
        p1Card = player1.playCard();
        p2Card = player2.playCard();
        
        //Post-Play cout statement
        //Player one wins
        if (p1Card.getPointValue() > p2Card.getPointValue())
        {
            //Add the score to player 1
            player1.addScore(p1Card);
            player1.addScore(p2Card);

            cout << gamesPlayed << ") " << player1.getName() << "* " << player1 << '(' << player1.getScore() << ')' << " - " 
            << player2.getName() << " " << player2 << '(' << player2.getScore() << ')' << endl;
            cout << endl;

        }
        //Player two wins
        else if (p1Card.getPointValue() < p2Card.getPointValue())
        {
            //Add the score to player 2
            player2.addScore(p1Card);
            player2.addScore(p2Card);

            cout << gamesPlayed << ") " << player1.getName() << " " << player1 << '(' << player1.getScore() << ')' << " - " 
            << player2.getName() << "* " << player2 << '(' << player2.getScore() << ')' << endl;
            cout << endl;

        }

        //Draw, nobody won.
        else
        {
            cout << gamesPlayed << ") " << player1.getName() << " " << player1 << '(' << player1.getScore() << ')' << " - " 
            << player2.getName() << " " << player2 << '(' << player2.getScore() << ')' << endl;
            cout << endl;
        }
       
        //Each player draws another card
        player1.drawCard(dk);
        player2.drawCard(dk);
        
        //Number of games played gets incremented
        gamesPlayed++;
        
        isEmpty1 = player1.emptyHand();
        isEmpty2 = player2.emptyHand();

    }

    //Print out the player that won, or tie
    if (player1.getScore() > player2.getScore())
        cout << "Winner " << player1.getName() << " " << player1.getScore() << endl;
    else if (player2.getScore() > player1.getScore())
        cout << "Winner " << player2.getName() << " " << player2.getScore() << endl;
    else
        cout << "Tie " << player1.getScore() << endl;
        
    myin.close();

}


