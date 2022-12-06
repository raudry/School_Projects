/* 
   Beverly Raudry
   CSCI 3110-001
   Project #2
   Due: 09/17/19
   Description: This file is the class declaration file.
*/

#ifndef GASPUMP_H
#define GASPUMP_H
#include <string>
using namespace std;

//GasPump class declaration.
class GasPump
{
    private:
        //Variable declarations
        string gasType;
        double fuelAmount, fuelCap, galPrice, totDis, totSale;
        bool takeNext;
        //Replenishes the fuel pumps underground tank
        void replenish();

    public:
        
        //Constructor
        GasPump(string, double, double);

        //Returns string for fuel type
        string getType() const
        { return gasType; }
        
        //Returns pumps fuel price per gallon
        double getPrice() const
        { return galPrice; }

        //Returns pumps fuel on hand
        double getFuel() const
        { return fuelAmount; }

        //Return total amount of fuel dispensed on all purchases
        double getDispensed() const
        { return totDis; }

        //Returns total revenue collected on all purchases
        double getSales() const
        { return totSale; }

        //Controls fueling of vehicles
        void dispenseFuel(double *fuelArr, double);
};
#endif
