#pragma once
#include <iostream>
#include <string>
using namespace std;
//for faster typing 
class Die
{
private:
	bool positive = false;
	//positive or negative die
	bool isDouble = false;
	//is the symbol doubled 
	int sides = 0;
	// necessary for sorting logic

	string symbol1 = "null"; //Success or Failure
	string symbol2 = "null"; //Triumph or despair
	string symbol3 = "null"; //Advantage or threat

	// All 3 are set as null for a default of "Blank"


public:

	//Constructors
	Die(bool positive);
	Die();


	//getters
	bool getIsDouble();
	bool getPositive();
	string getSymbol1();
	string getSymbol2();
	string getSymbol3();
	int getSides();

	//setters
	void setIsDouble(bool isDouble);
	void setPositive(bool positive);
	void setSymbol1(string symbol);
	void setSymbol2(string symbol);
	void setSymbol3(string symbol);
	void setSides(int sides);

	//Virtual functions
	virtual void printRoll() = 0;
	virtual void roll() = 0;

	

};

