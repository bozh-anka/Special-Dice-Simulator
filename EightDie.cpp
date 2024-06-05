#include "EightDie.h"
#include <cstdlib>


//defining function
void EightDie::roll()
{
    //seed set to time for alteration on each run
    srand((int)time(0));

    //calculating down to desired range
    int roll = (rand() % 8) + 1;

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
        case 5:
            setSymbol3("Advantage");
            break;
        case 6:
            setSymbol3("Advantage");
            break;
        case 7:
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
            break;
        case 2:
            setSymbol1("Failure");
            break;
        case 3:
            setSymbol3("Threat");
            break;
        case 4:
            setSymbol3("Threat");
            break;
        case 5:
            setSymbol1("Failure");
            setIsDouble(true);
            break;
        case 6: 
            setSymbol3("Threat");
            setIsDouble(true);
            break;
        case 7:
            setSymbol1("Failure");
            setSymbol3("Threat");
            break;
        default:
            break;
        }
    }
}

void EightDie::printRoll()
{
    //Checking values and printing adequetly 
    if (getSymbol1() != "null" && getSymbol3() == "null" && getIsDouble() == true) {
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
    else if (getSymbol3() != "null") {
        cout << getSymbol3() << " ";
    }
    else if (getSymbol1() == "null" && getSymbol2() == "null" && getSymbol3() == "null") {
        cout << "Blank";
    }
    cout << endl;
}

//constructors
EightDie::EightDie(bool positive)
{
	setPositive(positive);
    setSides(8);
}

EightDie::EightDie()
{ 
    setSides(8);
}


