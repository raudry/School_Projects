/* 
   Beverly Raudry
   CSCI 3110-001
   Project #3
   Due: 09/27/19
   Description: This file is the class declaration file.
*/

#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "ship.h"
#include <string>
using namespace std;

class CruiseShip : public Ship
{
    private:
        //Variable Definitions
        double Lpercent, UDpercent, LDpercent;
        int Lpass, UDpass, LDpass;
    
    public:
        //Constructor
        //This constructor must pass parametersto the constructor in the base class
        CruiseShip(string, double, double, double, double);
        
        //Overrides the virtual function in the base class
        void sail();

        //Overrides/implements the pure virtual function in the base class
        void load(int);

        using Ship :: fuel;
};

#endif
