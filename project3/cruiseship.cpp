/*
    Beverly Raudry
    CSCI 3010-001
    Project #3
    Due: 09/27/19
    Description: This the implementation file for the CruiseShip class
*/

#include "cruiseship.h"
#include "ship.h"
#include <iostream>
using namespace std;

//Constructor
CruiseShip :: CruiseShip(string name, double fuel, double firstDeck, double secondDeck, double thirdDeck) : Ship(name, fuel)
{
    //Percentage of passengers
    Lpercent = firstDeck;
    UDpercent = secondDeck;
    LDpercent = thirdDeck;    
}

//Prints the ship's name and the number of passengers in Luxury, UD, and LD
void CruiseShip :: sail()
{
    cout << shipName << ' ' << Lpass << ' ' << UDpass << ' ' << LDpass << endl;
}

//Accepts an int representing the number of passengers as a paramter
//Distrubutes those passengers among the three cabins
 void CruiseShip :: load(int totPass)
{
    //Number of passengers
    Lpass = Lpercent * totPass;
    UDpass = UDpercent * totPass;
    LDpass = LDpercent * totPass;
}

