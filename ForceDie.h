#pragma once
#include "TwelveDie.h"
class ForceDie :
    public TwelveDie
{
private:
    bool forcePoint = false; //true for positive/empty false for black/full
public:
    //setter and getter
     void setForcePoint(bool forcePoint);
     bool getForcePoint();

     //functions 
     void roll();
     void printRoll();

     //constructor
     ForceDie();

};

