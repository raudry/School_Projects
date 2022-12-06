/*
    Beverly Raudry
    CSCI 3010-001
    Project #2
    Due: 09/17/19
    Description: This the implementation file for the GasPump class
*/

#include "gaspump.h"
#include <iostream>
using namespace std;

//Constructor

GasPump :: GasPump(string gas, double tank, double gallon)
{
    gasType = gas;
    fuelCap = tank;
    galPrice = gallon;

    //Initialize fuel quantity to max capacity
    fuelAmount = fuelCap;
}

void GasPump :: replenish()
{
    fuelAmount = fuelCap;
}

void GasPump :: dispenseFuel(double *fuelArr, double purchAmount)
{
    //Convert purchase amount to gallons of fuel
    double purchGal = purchAmount / galPrice;
    
    if (fuelAmount < fuelCap * .1)
        takeNext = true;
    else
        takeNext = false;
    //If there is enough fuel, give them how much they want
    if (purchGal < fuelAmount)
    {    
        totDis += purchGal;
        fuelArr[1] = purchAmount;
        totSale += purchAmount;
        fuelArr[0] = purchGal;
        fuelAmount -= purchGal;
    }
    else if (takeNext == true)
    {
        //The vehicle gets the rest of the fuel in the tank
        totDis += fuelAmount;
        fuelArr[1] = 0;
        totSale += fuelAmount / galPrice;
        fuelArr[0] = 0;
        fuelAmount -= fuelAmount;
        replenish();
        takeNext = false;
     }
        //Next car is skipped
     else
     {
        fuelAmount = 0;
        takeNext = true;
     }
}
