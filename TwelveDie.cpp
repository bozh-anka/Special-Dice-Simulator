#include "TwelveDie.h"
#include <cstdlib>


void TwelveDie::roll()
{
    int roll;
    //seed set to time for alteration 
    srand((int)time(0));

    //calculating doen to range
    roll = 1 + (rand() % 12);

    if (getPositive() == true) {
        //probability for positive force die symbols
        switch (roll) {
        case 1:
            setSymbol3("Advantage");
            setIsDouble(true);
            break;
        case 2:
            setSymbol3("Advantage");
            setIsDouble(true);
            break;
        case 3:
            setSymbol3("Advantage");
            setIsDouble(true);
            break;
        case 4:
            setSymbol2("Triumph");
            break;
        case 5: 
            setSymbol1("Success");
            break;
        case 6:
            setSymbol1("Success");
            setSymbol3("Advantage");
            break;
        case 7:
            setSymbol1("Success");
            break;
        case 8:
            setSymbol1("Success");
            setSymbol3("Advantage");
            break;
        case 9:
            setSymbol1("Success");
            setIsDouble(true);
            break;
        case 10:
            setSymbol1("Success");
            setSymbol3("Advantage");
            break;
        case 11:
            setSymbol1("Success");
            setIsDouble(true);
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
            setIsDouble(true);
            break;
        case 2:
            setSymbol3("Threat");
            break;
        case 3:
            setSymbol3("Threat");
            setIsDouble(true);
            break;
        case 4:
            setSymbol3("Threat");
            break;
        case 5:
            setSymbol1("Failure");
            setSymbol3("Threat");
            break;
        case 6:
            setSymbol1("Failure");
            break;
        case 7:
            setSymbol1("Failure");
            setSymbol3("Threat");
            break;
        case 8:
            setSymbol1("Failure");
            break;
        case 9:
            setSymbol1("Failure");
            setIsDouble(true);
            break;
        case 10:
            setSymbol2("Despair");
            break;
        case 11:
            setSymbol1("Failure");
            setIsDouble(true);
            break;
        default:
            break;
        }
    }
}

void TwelveDie::printRoll()
{
    //Checking value and printing adequetly
    if (getSymbol1() != "null"&& getSymbol3() == "null" && getSymbol2() == "null" && getIsDouble() == true) {
        cout << "Double " << getSymbol1() << " ";
    }
    else if (getSymbol1() != "null") {
        cout << getSymbol1() << " ";
    }
    if (getSymbol1() != "null" && getSymbol3() != "null") {
        cout << "and " << getSymbol3();
    }
    else if (getSymbol3() != "null"&& getSymbol1() == "null" && getSymbol2() == "null" && getIsDouble() == true) {
        cout << "Double " << getSymbol3() << " ";
    }
    else if (getSymbol3() != "null") {
        cout << getSymbol3() << " ";
    }
    else if (getSymbol2() != "null") {
        cout << getSymbol2();
    }
    else if (getSymbol1() == "null" && getSymbol2() == "null" && getSymbol3() == "null") {
        cout << "Blank";
    }
    cout << endl;
}

//constructors
TwelveDie::TwelveDie(bool positive)
{
	setPositive(positive);
    setSides(12);
}

TwelveDie::TwelveDie()
{
    setSides(12);
}
