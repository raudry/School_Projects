/* 
   Beverly Raudry
   CSCI 3110-001
   Project #3
   Due: 09/27/19
   Description: This file is the class declaration file.
*/

#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "ship.h"
#include <string>
using namespace std;

class CargoShip : public Ship
{
    private:
        //Variable Definitions
        int maxCargo;
        double cargoPerc;
        //Two double pointer variables to represent tonnage in the forward cargo bay and the aft cargo bay
        double *forCB, *aftCB;
         
    public:
        //Constructor
        //This constructor takes ship name, fual load, cargo cap, and forward bay percent
        CargoShip(string, double, int, double);
        
        //Destructor
        ~CargoShip();

        //Overrides the virtual function in the base class
        void fuel(int);

        //Overrides/implements the pure virtual function in the base class
        void load(int);
};

#endif
