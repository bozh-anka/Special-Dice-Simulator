#pragma once
#include "Die.h"
class SixDie :
    public Die
{
private:
    //no new data members to add
public:

    //Signatures of parent's abstract functions
    void printRoll();
    void roll();

    //constructors
    SixDie(bool positive);
    SixDie();

   
};