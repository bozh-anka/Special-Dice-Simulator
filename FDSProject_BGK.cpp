// FDSProject_BGK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Die.h"
#include "EightDie.h"
#include"ForceDie.h"
#include "SixDie.h"
#include "TwelveDie.h"
#include <cstdlib>
#include <vector>
#include "Windows.h" //For sleep function


using namespace std;


void cancelSix(vector <SixDie> six) {
	cout << "The d6 result is: ";
	if ((int)six.size()==2) {
		if(six[0].getIsDouble()==true && six[1].getSymbol3()!="null")
		{
			six[0].setIsDouble(false);
			//Double advantage vs threat
			six[0].printRoll();

		}
		else if (six[0].getIsDouble() == false && (six[0].getSymbol3() != "null" && six[0].getSymbol1() == "null" && six[1].getSymbol3() != "null")
			||(six[0].getSymbol3() == "null" && six[0].getSymbol1() != "null" && six[1].getSymbol1() != "null")) 
		{
			//all self cancelling probabilities
			cout << "Blank" << endl;
		}
		else if (six[0].getIsDouble() == false && six[0].getSymbol3() != "null" && six[0].getSymbol1() != "null" && six[1].getSymbol1() != "null") 
		{
			//Success and advantage vs Failure
			six[0].setSymbol1("null");
			cout << six[0].getSymbol3() << endl;
			//six[0].printRoll();
		}
		else if (six[0].getIsDouble() == false && six[0].getSymbol3() != "null" && six[0].getSymbol1() != "null" && six[1].getSymbol3() != "null") 
		{
			//Success and advantage vs  Threat
			six[0].setSymbol3("null");
			//six[0].printRoll();
			cout << six[0].getSymbol1() << endl;
		}
		else {
			//The symbols do not match
			six[0].printRoll();
			cout << " and ";
			six[1].printRoll();
		}
	}
	else if(!six.empty()){
		//only one non blank symbol 
		six[0].printRoll();
	}
	else {
		//blank
		cout << "Blank" << endl;
	}

	
}

void cancelEight(vector <EightDie> eight) {
	cout << "The d8 result is: ";
	if ((int)eight.size() == 2) {

		if ((eight[0].getSymbol1() != "null" && eight[0].getSymbol3() != "null" && eight[1].getSymbol1() != "null" && eight[1].getSymbol3() != "null")) {
		cout << "Blank" << endl;
		}
		else if (eight[0].getIsDouble() == true && eight[0].getSymbol3() != "null" && eight[1].getSymbol3() != "null" && eight[1].getSymbol1() != "null")
		{
			eight[0].setIsDouble(false);
			cout << eight[1].getSymbol1() << " and ";
			eight[0].printRoll();
			//cancels double advantage to single advantage and failure
		} 
		else if (eight[0].getIsDouble() == true && eight[0].getSymbol1() != "null" && eight[1].getSymbol3() != "null" && eight[1].getSymbol1() != "null")
		{
				eight[0].setIsDouble(false);
				cout << eight[1].getSymbol3() << " and ";
				eight[0].printRoll();
				//cancels double Success to single advantage and threat
			}
		else if (eight[0].getIsDouble() == true && eight[0].getSymbol3() != "null" && eight[1].getSymbol3() != "null" && eight[1].getIsDouble() == false)
		{
			eight[0].setIsDouble(false);
			eight[0].printRoll();
			//cancels double advantage to single advantage
		} 
		else if (eight[1].getIsDouble() == true && eight[1].getSymbol3() != "null" && eight[0].getSymbol3() != "null" && eight[0].getIsDouble() == false)
		{
			eight[1].setIsDouble(false);
			eight[1].printRoll();
			//cancels double threat to single threat
		}
		else if (eight[1].getIsDouble() == true && eight[1].getSymbol3() != "null" && eight[0].getSymbol3() != "null" && eight[0].getSymbol1() != "null")
		{
			eight[1].setIsDouble(false);
			cout << eight[0].getSymbol1() << " and ";
			eight[1].printRoll();
			//cancels double threat to single threat and success
		}
		else if (eight[1].getIsDouble() == true && eight[1].getSymbol1() != "null" && eight[0].getSymbol3() != "null" && eight[0].getSymbol1() != "null")
		{
			eight[1].setIsDouble(false);
			cout << eight[0].getSymbol3() << " and ";
			eight[1].printRoll();
			//cancels double failure to single failure and advantage
		}
		else if (eight[0].getIsDouble() == true && eight[0].getSymbol1() !="null" && eight[1].getSymbol1() != "null" && eight[1].getIsDouble() == false)
		{
			eight[0].setIsDouble(false);
			eight[0].printRoll();
			//cancels double success to single success
		}
		else if (eight[1].getIsDouble() == true && eight[1].getSymbol1() != "null" && eight[0].getSymbol1() != "null" && eight[0].getIsDouble() == false) 
		{
			eight[1].setIsDouble(false);
			eight[1].printRoll();
			//cancels double failure to single failure
		}
		else if ((eight[0].getSymbol3() != "null" && eight[0].getSymbol1() == "null" && eight[1].getSymbol3() != "null" && eight[1].getSymbol1() == "null")
			|| (eight[0].getSymbol3() == "null" && eight[0].getSymbol1() != "null" && eight[1].getSymbol3() == "null" && eight[1].getSymbol1() != "null")
			|| (eight[0].getSymbol1() != "null" && eight[0].getSymbol3() != "null" && eight[1].getSymbol1() != "null" && eight[1].getSymbol3() != "null")
			|| (eight[0].getIsDouble() && eight[1].getIsDouble()))
		{
			cout << "Blank" << endl;
			//cancels matching symbols
		}
		else if (eight[0].getSymbol3() != "null" && eight[0].getSymbol1() != "null" && eight[1].getSymbol1() != "null" && eight[1].getSymbol3() == "null")
		{
			cout << eight[0].getSymbol3() << endl;
			//eight[0].setSymbol1("null");
			//eight[0].printRoll();
			//cancelling out one success leaving one advantage
		}
		else if ( eight[0].getSymbol3() != "null" && eight[0].getSymbol1() != "null" && eight[1].getSymbol3() != "null"&& eight[1].getSymbol1() == "null")
		{
			cout << eight[0].getSymbol1() << endl;
			//eight[0].setSymbol3("null");
			//eight[0].printRoll();
			//cancelling out one advantage leaving one success
		}
		else if (eight[1].getSymbol3() != "null" && eight[1].getSymbol1() != "null" && eight[0].getSymbol1() == "null" && eight[0].getSymbol3() != "null")
		{
			cout << eight[1].getSymbol1() << endl;
			//eight[1].setSymbol1("null");
			//eight[1].printRoll();
			//cancelling out one threat leaving one failure
		}
		else if (eight[1].getSymbol3() != "null" && eight[1].getSymbol1() != "null" && eight[0].getSymbol3() == "null" && eight[0].getSymbol1() != "null")
		{
			cout << eight[1].getSymbol3() << endl;
			//eight[1].setSymbol3("null");
			//eight[1].printRoll();
			//cancelling out one failure leaving one threat
			
		}
		else {
			//symbols don't match
			eight[0].printRoll();
			cout << " and ";
			eight[1].printRoll();
		}

	}
	else if (!eight.empty()) {
		//only one non blank
		eight[0].printRoll();
	}
	else {
		//blank
		cout << "Blank" << endl;
	}


}

void cancelTwelve(vector <TwelveDie> twelve) {
	//double advantage and double threat symbol3
	cout << "The d12 result is: ";
	if ((int)twelve.size() == 2) {

		if ((twelve[0].getSymbol1() != "null" && twelve[0].getSymbol3() != "null" && twelve[1].getSymbol1() != "null" && twelve[1].getSymbol3() != "null")) {
			cout << "Blank" << endl;
		}
		else if (twelve[0].getIsDouble() == true && twelve[0].getSymbol3() != "null" && twelve[1].getSymbol3() != "null" && twelve[1].getSymbol1() != "null") {
			twelve[0].setIsDouble(false);
			cout << twelve[1].getSymbol1() << " and ";
			twelve[0].printRoll();
			//cancels double advantage to single advantage
		}
		else if (twelve[0].getIsDouble() == true && twelve[0].getSymbol1() != "null" && twelve[1].getSymbol3() != "null" && twelve[1].getSymbol1() != "null") {
			twelve[0].setIsDouble(false);
			cout << twelve[1].getSymbol3() << " and ";
			twelve[0].printRoll();
			//cancels double Success to single success
		}
		else if (twelve[0].getIsDouble() == true && twelve[0].getSymbol3() != "null" && twelve[1].getSymbol3() != "null" && twelve[1].getIsDouble() == false) {
			twelve[0].setIsDouble(false);
			twelve[0].printRoll();
			//cancels double advantage
		}
		else if (twelve[1].getIsDouble() == true && twelve[1].getSymbol3() != "null" && twelve[0].getSymbol3() != "null" && twelve[0].getIsDouble() == false) {
			twelve[1].setIsDouble(false);
			twelve[1].printRoll();
			//cancels double threat

		}
		else if (twelve[1].getIsDouble() == true && twelve[1].getSymbol3() != "null" && twelve[0].getSymbol3() != "null" && twelve[0].getSymbol1() != "null") {
			twelve[1].setIsDouble(false);
			cout << twelve[0].getSymbol1() << " and ";
			twelve[1].printRoll();
			//cancels double failure to one failure amd advantage
		}
		else if (twelve[1].getIsDouble() == true && twelve[1].getSymbol1() != "null" && twelve[0].getSymbol3() != "null" && twelve[0].getSymbol1() != "null") {
			twelve[1].setIsDouble(false);
			cout << twelve[0].getSymbol3() << " and ";
			twelve[1].printRoll();
			//cancels double threat to one threat and success
		}
		else if (twelve[0].getIsDouble() == true && twelve[0].getSymbol1() != "null" && twelve[1].getSymbol1() != "null" && twelve[1].getIsDouble() == false) {
			twelve[0].setIsDouble(false);
			twelve[0].printRoll();
			//cancels double success to single success
		}
		else if (twelve[1].getIsDouble() == true && twelve[1].getSymbol1() != "null" && twelve[0].getSymbol1() != "null" && twelve[0].getIsDouble() == false) {
			twelve[1].setIsDouble(false);
			twelve[1].printRoll();
			//cancels double failure to single failure
		}
		else if ((twelve[0].getSymbol3() != "null" && twelve[0].getSymbol1() == "null" && twelve[1].getSymbol3() != "null" && twelve[1].getSymbol1() == "null")
			|| (twelve[0].getSymbol3() == "null" && twelve[0].getSymbol1() != "null" && twelve[1].getSymbol3() == "null" && twelve[1].getSymbol1() != "null")
			|| (twelve[0].getSymbol1() != "null" && twelve[0].getSymbol3() != "null" && twelve[1].getSymbol1() != "null" && twelve[1].getSymbol3() != "null")
			|| (twelve[0].getIsDouble() && twelve[1].getIsDouble())
			|| (twelve[0].getSymbol2()!="null" && twelve[1].getSymbol2() != "null")) {
			cout << "Blank" << endl;
			//cancels matching symbols
		}
		else if (twelve[0].getSymbol3() != "null" && twelve[0].getSymbol1() != "null" && twelve[1].getSymbol1() != "null" && twelve[1].getSymbol3() == "null") {
			cout << twelve[0].getSymbol3() << endl;
			//twelve[0].setSymbol1("null");
			//twelve[0].printRoll();
			//cancelling out one success leaving one advantage
		}
		else if (twelve[0].getSymbol3() != "null" && twelve[0].getSymbol1() != "null" && twelve[1].getSymbol3() != "null" && twelve[1].getSymbol1() == "null") {
			cout << twelve[0].getSymbol1() << endl;
			//twelve[0].setSymbol3("null");
			//twelve[0].printRoll();
			//cancelling out one advantage leaving one success
		}
		else if (twelve[1].getSymbol3() != "null" && twelve[1].getSymbol1() != "null" && twelve[0].getSymbol1() == "null" && twelve[0].getSymbol3() != "null") {
			cout << twelve[1].getSymbol1() << endl;
			//twelve[1].setSymbol1("null");
			//twelve[1].printRoll();
			 //cancelling out one threat leaving one failure
		}
		else if (twelve[1].getSymbol3() != "null" && twelve[1].getSymbol1() != "null" && twelve[0].getSymbol3() == "null" && twelve[0].getSymbol1() != "null") {
			cout << twelve[1].getSymbol3() << endl;
			//twelve[1].setSymbol3("null");
			//twelve[1].printRoll();
			//cancelling out one failure leaving one threat
		}
		else {
			//rolls dont cancel
			twelve[0].printRoll();
			cout << " and ";
			twelve[1].printRoll();
		}

	}
	else if (!twelve.empty()) {
		//one non blank
		twelve[0].printRoll();
	}
	else {
		//blank
		cout << "Blank" << endl;
	}

}


vector <SixDie> CleanSix(vector <SixDie> &six) {
	vector <SixDie> cleanSix;

	/*
	debug
		for (int i = 0; i < (int)six.size(); i++) {
		//cout << "six: ";
		six[i].printRoll();
	}*/

	//
	for (int i= 0 ; i < (int)six.size(); i++) {
									//cout << "In the six loop ";
									//cout << six[i].getSymbol1() <<" and " << six[i].getSymbol3() << endl;

		//check if not blank and add to clean vector
		if (six[i].getSymbol1() != "null" || six[i].getSymbol3() != "null" ) {
									//cout << "This six isn't blank: ";
									//six[i].printRoll();
			cleanSix.push_back(six[i]);
			
		}
		
		
		
	} 

	/*
	debug
		for (int i = 0; i < (int)cleanSix.size(); i++) {
		cout << "Clean six pre cancel: ";
		cleanSix[i].printRoll();
	}*/
	


	return cleanSix;
}

vector <EightDie> CleanEight(vector <EightDie> &eight) {
	vector <EightDie> cleanEight;

	/*
	debug
		for (int i = 0; i < (int)eight.size(); i++) {
		//cout << "eight: ";
		eight[i].printRoll();
	}*/


	for (int i= 0 ; i < (int)eight.size(); i++) {
												//	cout << "In the eight loop ";
												//	cout << eight[i].getSymbol1() <<" and " << eight[i].getSymbol3() << endl;

		//check if not blank and add to clean vector
		if (eight[i].getSymbol1() != "null" || eight[i].getSymbol3() != "null" ) {
												//	cout << "This eight isn't blank: ";
												//eight[i].printRoll();
			cleanEight.push_back(eight[i]);
			
		}
		
		
		
	} 

	return cleanEight;
}
vector <TwelveDie> CleanTwelve(vector <TwelveDie>& twelve) {
	vector <TwelveDie> cleanTwelve;

	/*
	debug
		for (int i = 0; i < (int)twelve.size(); i++) {
		//cout << "twelve: ";
		twelve[i].printRoll();
	}*/


	for (int i = 0; i < (int)twelve.size(); i++) {
												//cout << "In the twelve loop ";
												//cout << twelve[i].getSymbol1() << " and " << twelve[i].getSymbol2() <<twelve[i].getSymbol3() << endl;

		//check if not blank and add to clean vector
		if (twelve[i].getSymbol1() != "null"|| twelve[i].getSymbol2() != "null" || twelve[i].getSymbol3() != "null") {
												//	cout << "This twelve isn't balank: ";
												//twelve[i].printRoll();
			cleanTwelve.push_back(twelve[i]);

		}



	} 

	

	return cleanTwelve;
}


void cancelAll(vector <Die*> Pdie, vector <Die*> Ndie) {
	
	//declaring vectors to sort into 
	vector <SixDie> six;
	vector <EightDie> eight;
	vector <TwelveDie> twelve;


	//positive at front, checking sides and adding to corresponding vector
	for (int i = 0; i < (int)Pdie.size(); i++) {
		if (Pdie[i]->getSides() == 6) {
			SixDie X = new SixDie();
			X.setIsDouble(Pdie[i]->getIsDouble());
			X.setPositive(Pdie[i]->getPositive());
			X.setSymbol1(Pdie[i]->getSymbol1());
			X.setSymbol3(Pdie[i]->getSymbol3());
													//Pdie[i]->printRoll();
			six.push_back(X);
			
		}
		else if (Pdie[i]->getSides() == 8) {
			EightDie X = new EightDie();
			X.setIsDouble(Pdie[i]->getIsDouble());
			X.setPositive(Pdie[i]->getPositive());
			X.setSymbol1(Pdie[i]->getSymbol1());
			X.setSymbol3(Pdie[i]->getSymbol3());
												//Pdie[i]->printRoll();
			eight.push_back(X);
			
		}
		else if (Pdie[i]->getSides() == 12) {
			TwelveDie X = new TwelveDie();
			X.setIsDouble(Pdie[i]->getIsDouble());
			X.setPositive(Pdie[i]->getPositive());
			X.setSymbol1(Pdie[i]->getSymbol1());
			X.setSymbol2(Pdie[i]->getSymbol2());
			X.setSymbol3(Pdie[i]->getSymbol3());
												//Pdie[i]->printRoll();
			twelve.push_back(X);
			
		}

		//negative at end
		if (Ndie[i]->getSides() == 6) {
			SixDie X = new SixDie();
			X.setIsDouble(Ndie[i]->getIsDouble());
			X.setPositive(Ndie[i]->getPositive());
			X.setSymbol1(Ndie[i]->getSymbol1());
			X.setSymbol3(Ndie[i]->getSymbol3());
												//Ndie[i]->printRoll();
			six.push_back(X);

		}
		else if (Ndie[i]->getSides() == 8) {
			EightDie X = new EightDie();
			X.setIsDouble(Ndie[i]->getIsDouble());
			X.setPositive(Ndie[i]->getPositive());
			X.setSymbol1(Ndie[i]->getSymbol1());
			X.setSymbol3(Ndie[i]->getSymbol3());
												//Ndie[i]->printRoll();
			eight.push_back(X);

		}
		else if (Ndie[i]->getSides() == 12) {
			TwelveDie X = new TwelveDie();
			X.setIsDouble(Ndie[i]->getIsDouble());
			X.setPositive(Ndie[i]->getPositive());
			X.setSymbol1(Ndie[i]->getSymbol1());
			X.setSymbol2(Ndie[i]->getSymbol2());
			X.setSymbol3(Ndie[i]->getSymbol3());
												//Ndie[i]->printRoll();
			twelve.push_back(X);

		}

	}

	//cleaning vectors and cancelling 
	vector <SixDie> cleanSix =CleanSix(six);
	cancelSix(cleanSix);
	six.clear();
	vector <EightDie> cleanEight = CleanEight(eight);
	cancelEight(cleanEight);
	eight.clear();
	vector <TwelveDie> cleanTwelve = CleanTwelve(twelve);
	cancelTwelve(cleanTwelve);
	twelve.clear();

}


int main()
{
	vector <Die*> die;
	vector <Die*> Ndie;
	vector <ForceDie*> Fdie;
	
	ifstream ins;

	//check if file is open
	ins.open("test.txt");
	if (ins.fail()) {
		//error if not 
		cout << "Error opening file";
		return -1;
	}


	//declaring variables to read from file
	bool b = 0;
	int Froll=1; //how many Force dice to roll
	int Rroll = 1; //how many times to roll and cancel

	//reading from file
	ins >> Froll;
	ins >> Rroll;
	ins >> b;

	//creating die objects
	SixDie s = SixDie(b);
	die.push_back(&s);
	ins >> b;
	SixDie s1 = SixDie(b);
	Ndie.push_back(&s1);
	ins >> b;

	EightDie e = EightDie(b);
	die.push_back(&e);
	ins >> b;
	EightDie e1 = EightDie(b);
	Ndie.push_back(&e1);
	ins >> b;

	TwelveDie t = TwelveDie(b);
	die.push_back(&t);
	ins >> b;
	TwelveDie t1 = TwelveDie(b);
	Ndie.push_back(&t1);


	//creating right number of force die
	for (int i = 0; i < Froll; i++) {
		ForceDie f = ForceDie();
		Fdie.push_back(&f);
	}

	
	cout << "You chose to roll and cancel " << Rroll << " times!" << endl;
	//rolling and cancelling
	cout << endl;
	for (int i = 0; i < Rroll; i++) {
		cout << "The initial rolls are: " << endl;
		for (int i = 0; i < (int)die.size(); i++) {
			die[i]->setSymbol1("null");
			die[i]->setSymbol2("null");
			die[i]->setSymbol3("null");
			die[i]->setIsDouble(false);
			die[i]->roll();
			die[i]->printRoll();
		}

		for (int i = 0; i < (int)Ndie.size(); i++) {
			Ndie[i]->setSymbol1("null");
			Ndie[i]->setSymbol2("null");
			Ndie[i]->setSymbol3("null");
			Ndie[i]->setIsDouble(false);
			Ndie[i]->roll();
			Ndie[i]->printRoll();
		}
		cout << endl;

		cancelAll(die, Ndie);
		cout << endl;
		
		//sleeping until seed changes
		Sleep(600);
	}
		//closing file
		ins.close();

		//rolling force dice
		cout << "Force point die do not cancel or add, the ones you rolled are: " << endl;
		for (int i = 0; i < (int)Fdie.size(); i++) {

			Fdie[i]->roll();

			Fdie[i]->printRoll();
			Sleep(600);
		}
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
