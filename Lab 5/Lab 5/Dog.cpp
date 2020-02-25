#include <iostream>
#include "Dog.h"

using namespace std;

//Precondition: string Dog uses getAnimalType() function
//Postcondition: returns dog data type
//Description: Dog string returns "Dog"
string Dog::getAnimalType()
{
	return "Dog";
}
//Precondition: Dog function uses makeNoise function
//Postcondition: prints a statement when called upon
//Description: Dog function prints a statement
void Dog::makeNoise()
{
	cout << "Woof! Woof! Squirrel!" << endl;
}

//Precondition: Dog function uses doDoggyThings() funtion
//Postcondition: prints a statement when called upon
//Description: Dog function prints statement
void Dog::doDoggyThings()
{
	cout << "I'm digging a hole and burying my bone so the squirrels can't get it!" << endl;
}