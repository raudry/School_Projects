/*
    Beverly Raudry
    CSCI 3010-001
    Project #3
    Due: 09/27/19
    Description: This the implementation file for the Ship class
*/

#include "ship.h"
#include <iostream>
using namespace std;

//Constructor
Ship :: Ship(string name, double fuel)
{
    shipName = name;
    fuelAmount = fuel;    
}

//Outputs the ships name and fuel load
void Ship :: fuel()
{
    cout << shipName << ' ' << fuelAmount << endl;
}

//Print out the name of the ship followed by the word sailing
void Ship :: sail()
{
    cout << shipName << " sailing" << endl;
}

//Simulates loading the ship with cargo or passengers
void Ship :: load(int num)
{
    
}

