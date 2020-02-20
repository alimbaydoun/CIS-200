#ifndef DOG_H
#define DOG_H

using namespace std;

#include "Animal.h"

class Dog :public Animal
{
public:
	string getAnimalType();
	void makeNoise();
	void doDoggyThings();
private:
	// Declaring variables

};
#endif