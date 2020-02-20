#include <iostream>
#include "Dog.h"

using namespace std;

string Dog::getAnimalType()
{
	return "Dog";
}
void Dog::makeNoise()
{
	cout << "Woof! Woof! Squirrel!" << endl;
}
void Dog::doDoggyThings()
{
	cout << "I'm digging a hole and burying my bone so the squirrels can't get it!" << endl;
}