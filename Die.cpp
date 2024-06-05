#include "Die.h"
#include <iostream>
using namespace std;
//for faster typing

//Setting default values 
Die::Die(bool positive)
{
	this->positive = positive;
	this->symbol1 = "null";
	this->symbol2 = "null";
	this->symbol3 = "null";
	this->sides = 0;
	this->isDouble = false;
}

Die::Die()
{
	this->positive = false;
	this->isDouble = false;
	this->symbol1 = "null";
	this->symbol2 = "null";
	this->symbol3 = "null";
	this->sides = 0;
	this->isDouble = false;
}

//definging getters
bool Die::getIsDouble()
{
	return isDouble;
}

bool Die::getPositive()
{
	return positive;
}

string Die::getSymbol1()
{
	return symbol1;
}

string Die::getSymbol2()
{
	return symbol2;
}

string Die::getSymbol3()
{
	return symbol3;
}

int Die::getSides()
{
	return sides;
}

//defining setters
void Die::setIsDouble(bool isDouble)
{
	this->isDouble = isDouble;
}

void Die::setPositive(bool positive)
{
	if (getSymbol1() != "null" && getSymbol3() != "null") {
		this->positive = false;
	}else 
	{
		this->positive = positive;
	}
	
}

//ensuring correct values
void Die::setSymbol1(string symbol)
{
	if ((symbol == "Success" || symbol == "Failure") && symbol2 == "null") {
		this->symbol1 = symbol;
	}

}

void Die::setSymbol2(string symbol)
{
	if ((symbol == "Triumph" || symbol == "Despair")&& symbol1== "null" && symbol3 == "null") {
		this->symbol2 = symbol;
	}

}

void Die::setSymbol3(string symbol)
{
	if ((symbol == "Advantage" || symbol == "Threat")&& symbol2 =="null") {
		this->symbol3 = symbol;
	}
}

void Die::setSides(int sides)
{ 
	if (sides == 6 || sides == 8 || sides == 12 || sides == 0) {
		this->sides = sides;
	}
}


