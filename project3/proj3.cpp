/*
    Beverly Raudry
    CSCI 3110-001
    Project #3
    Due: 09/27/19
    Description: This is the client file for the GasPump class.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ship.h"
#include "cargoship.h"
#include "cruiseship.h"

using namespace std;

void sailShip(Ship&);

int main()
{
    //Variable declarations for cruiseship
    string cruiseName;
    double cruiseFuel, Lperc, UDperc, LDperc;
    int passengers;

    //Variable declarations for cargoship
    string cargoName;
    double cargoFuel, cargoPerc;
    int cargoCap, cargoTon, fuelFlash;

    //File variable
    ifstream myin;

    //Read in the file
    myin.open("ships.txt");

    myin >> cruiseName >> cruiseFuel >> Lperc >> UDperc >> LDperc >> passengers;
    myin >> cargoName >> cargoFuel >> cargoCap >> cargoPerc >> cargoTon >> fuelFlash;
    

    //Instantiate CruiseShip and CargoShip
    CruiseShip cruise = CruiseShip(cruiseName, cruiseFuel, Lperc, UDperc, LDperc);
    CargoShip cargo = CargoShip(cargoName, cargoFuel, cargoCap, cargoPerc);

    //Invoke CruiseShips fuel function
    cruise.fuel(); 

    //Invoke Cruiseships load function
    cruise.load(passengers);

    //Call sailShip function passing it the CruiseShip object, cruise, as an argument
    sailShip(cruise);

    //Invoke CargoShips fuel function
    cargo.fuel(fuelFlash);

    //Invoke CargoShips load function
    cargo.load(cargoTon);

    //Call sailShip function passing it the CargoShip object, cargo, as the argument
    sailShip(cargo);

}

void sailShip(Ship& shipType)
{
    //Invokes sail function
    shipType.sail();
}
