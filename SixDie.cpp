#include "SixDie.h"
#include "Die.h"
#include <cstdlib> //necessary for random numbers

//functions
void SixDie::roll()
{
    int roll;

    //Setting seed to time so it differs on each run
    srand((int)time(0));

    //calculating down to desired range 
    roll = 1 + (rand() % 6);

    if (getPositive() == true) {
        //probability for positive force die symbols
        switch (roll) {
        case 1:
            setSymbol3("Advantage");
            break;
        case 2:
            setSymbol1("Success");
            break;
        case 3:
            setSymbol3("Advantage");
            setIsDouble(true);
            break;
        case 4:
            setSymbol1("Success");
            setSymbol3("Advantage");
            break;

        default:
            break;
        }

    }
    else {
        //probability for negative force die symbols

        switch (roll) {
        case 1:
            setSymbol3("Threat");
            break;
        case 2:
            setSymbol1("Failure");
            break;
        default:
            break;
        }
    }
}

//constructors 
SixDie::SixDie(bool positive)
{
    setPositive(positive);
    setSides(6);
}

SixDie::SixDie()
{
  
    setSides(6);
}

//function
void SixDie::printRoll()
{
    //Check values and print adequately 
    if (getSymbol1() != "null" && getSymbol3() == "null" && getIsDouble()== true) {
        cout << "Double " << getSymbol1() << " ";
    }
    else if (getSymbol1() != "null") {
        cout << getSymbol1() << " ";
    }
    if (getSymbol1() != "null" && getSymbol3() != "null") {
        cout << "and " << getSymbol3();
    }
    else if (getSymbol3() != "null"&& getSymbol1() == "null" && getIsDouble() == true) {
        cout << "Double " << getSymbol3() << " ";
    }
    else if (getSymbol3() != "null" ) {
        cout << getSymbol3() << " ";
    }
    else if(getSymbol1() == "null" && getSymbol2() == "null" && getSymbol3() == "null") {
        cout << "Blank";
    }
     cout << endl;

}