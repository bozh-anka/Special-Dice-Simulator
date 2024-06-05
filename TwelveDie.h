#pragma once
#include "Die.h"
class TwelveDie :
    public Die
{
public:

    //Functions are virtual because twelve die is inherited by ForceDie
    virtual void roll();
    virtual void printRoll();

    //constructor
    TwelveDie(bool positive);
    TwelveDie();
};

