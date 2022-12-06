/*
    Beverly Raudry
    CSCI 3010-001
    Project #3
    Due: 09/27/19
    Description: This the implementation file for the CruiseShip class
*/

#include "cargoship.h"
#include "ship.h"
#include <iostream>
using namespace std;

//Constructor
CargoShip :: CargoShip(string name, double fuel, int cargoCap, double fbayPerc) : Ship(name, fuel)
{
    //Dynamically allocate the memory to represent the cargo bays and initialize them to zero
    forCB = new double;
    *forCB = 0.0;
    aftCB = new double; 
    *aftCB = 0.0;
    maxCargo = cargoCap;
    cargoPerc = fbayPerc;
}

//Destructor
CargoShip :: ~CargoShip()
{
    //Frees the memory allocated for the cargo bays
    delete forCB;
    delete aftCB;
}

//Prints the ship's name and it's integer parameter, without error checking 
void CargoShip :: fuel(int fuelFlash)
{
    Ship::fuel();
    cout << shipName << ' ' << fuelFlash << endl;
}

//Accepts int representing the tons of cargo to be loaded on the ship
 void CargoShip :: load(int tonCargo)
{
    //A check must be made to ensure that the ship is only loaded up to its cap if not the load the max cap, do not output error.
    if ( tonCargo > maxCargo)
        { tonCargo = maxCargo; }

    //Place percentage of the cargo in the forward bay (as specified in the file) and the remainder in the aft bay
    *forCB = cargoPerc * tonCargo;
    *aftCB = tonCargo - *forCB; 

    //Output the ships name and the forward bay load and the aft bay load, unformatted, in that order, in a single line
    cout << shipName << ' ' << *forCB << ' ' << *aftCB << endl;

}
