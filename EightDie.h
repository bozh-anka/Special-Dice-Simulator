#pragma once
#include "Die.h"
class EightDie :
    public Die
{
public:
    //functions
    void roll();
    void printRoll();

    //constructor
    EightDie(bool positive);
    EightDie();
};

