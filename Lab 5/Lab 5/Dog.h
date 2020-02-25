#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Dog :public Animal
{
public:
	string getAnimalType();
	void makeNoise();
	void doDoggyThings();
};