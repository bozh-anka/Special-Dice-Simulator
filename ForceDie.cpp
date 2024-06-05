#include "ForceDie.h"
#include <cstdlib>


//getter and setter
void ForceDie::setForcePoint(bool forcePoint)
{
    this->forcePoint = forcePoint;
}

bool ForceDie::getForcePoint()
{
    return forcePoint;
}

//new probability
void ForceDie::roll()
{
    int roll;
    //seed set to time for alteration 
    srand((int)time(0));

    //calculating doen to range
    roll = 1 + (rand() % 12);

    switch (roll) {
    case 1:
        setForcePoint(false);
        break;
    case 2:
        setForcePoint(false);
        break;
    case 3:
        setForcePoint(false);
        break;
    case 4:
        setForcePoint(false);
        break;
    case 5:
        setForcePoint(false);
        break;
    case 6:
        setForcePoint(false);
        break;
    case 7:
        setForcePoint(true);
        setIsDouble(true);
        break;
    case 8:
        setForcePoint(true);
        setIsDouble(true);
        break;
    case 9:
        setForcePoint(true);
        setIsDouble(true);
        break;
    case 10:
        setForcePoint(true);
        break;
    case 11:
        setForcePoint(true);
        break;
    case 12:
        setForcePoint(false);
        setIsDouble(true);
        break;
    default:
        break;
    }
}

void ForceDie::printRoll()
{
    if (getIsDouble() == true) {
        cout << "Double ";
    }
    else {
        cout << "One ";
    }

    if (getForcePoint() == true) {
        cout << "positive force point." << endl;
    }else{ 
        cout << "negative force point." << endl;
    }
}

//constructor
ForceDie::ForceDie()
{
    setSides(0);
    //to differenciate from regular d12
}
