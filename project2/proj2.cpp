/*
    Beverly Raudry
    CSCI 3110-001
    Project #2
    Due: 09/17/19
    Description: This is the client file for the GasPump class.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "gaspump.h"

using namespace std;

int main()
{
    //Variable definitions
    string fuelType;
    int seed, totCars, count = 0;
    double tankCap, galPrice, percent, random, purchAmount, remAmount;


    //Array to store percentage values
    double perArr[3];

    //2 Element double array that is passed to dispenseFuel to get the outcome of fueling
    double fuelArr[2];
    //Instantiation of an array of pointers to three GasPump objects.
    GasPump *pumpArr[3];

    //Prepare the file for reading
    ifstream myin;
    myin.open("gas.txt");
    
    //Read from the file
    //Random seed
    myin >> seed;
    //Place seed in srand for random number generator
    srand(seed);
    //Total cars
    myin >> totCars;

    //Loop to read in a GasPump and call the Constructor to set the object values
    for (int i = 0; i < 3; i++)
    {
        myin >> fuelType >> tankCap >> galPrice >> percent;
        pumpArr[i] = new GasPump(fuelType, tankCap, galPrice);
        perArr[i] = percent;
    }

    //Number of vehicles that need to be simulated
    for (int i = 0; i < totCars; i++)
    {
        //Picks a random number which the determines which pump to use
        double random = ((double) rand() + 1) / RAND_MAX;

        //Picks a random purchas ammount
        purchAmount = rand() % 6 * 5 +  30;

        if ((random < perArr[2]))
        {
            //Call DispenseFuel from the correct pump
            pumpArr[2] -> dispenseFuel(fuelArr, purchAmount);
             
            //Output for the correct pump
            cout << i + 1 << ' ' << pumpArr[2] -> getType() 
            << ' ' << fixed << setprecision(2) << pumpArr[2] -> getPrice()
            << ' ' << purchAmount << ' ' << fuelArr[1] 
            << ' ' << fuelArr[0] << ' ' << pumpArr[2] -> getFuel() << endl;
        }

        else if ( (random > perArr[2]) && (random < perArr[0] ) )
        {
            //Call DispenseFuel from the correct pump
            pumpArr[1] -> dispenseFuel(fuelArr, purchAmount);

            //Output for the correct pump
            cout << i + 1 << ' ' << pumpArr[1] -> getType() 
            << ' ' << fixed << setprecision(2) << pumpArr[1] -> getPrice()
            << ' ' << purchAmount << ' ' << fuelArr[1] 
            << ' ' << fuelArr[0] << ' ' << pumpArr[1] -> getFuel() << endl;
        }

        else
        {
            //Call DispenseFuel from the correct pump
            pumpArr[0] -> dispenseFuel(fuelArr, purchAmount);
                 
            //Output for the correct pump
            cout << i + 1 << ' ' << pumpArr[0] -> getType() 
            << ' ' << fixed << setprecision(2) << pumpArr[0] -> getPrice()
            << ' ' << purchAmount << ' ' << fuelArr[1] 
            << ' ' << fuelArr[0] << ' ' << pumpArr[0] -> getFuel() << endl;
                        
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << pumpArr[i] -> getType() << ' ' << pumpArr[i] -> getDispensed()
        << ' ' << pumpArr[i] -> getSales() <<  endl;
    }
}

