/* 
   Beverly Raudry
   CSCI 3110-001
   Project #3
   Due: 09/27/19
   Description: This file is the class declaration file.
*/

#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;

class Ship
{
    protected:
        //Variable Definitions
        string shipName;
        double fuelAmount;
    
    public:
        //Constructor
        Ship(string, double);
        
        //Outputs the ships name and fuel load
        void fuel();

        //Prints the ships name followed by the word sailing
        virtual void sail();
        
        //Simulates loading the ship with cargo or passengers
        virtual void load(int) = 0;      
};

#endif
