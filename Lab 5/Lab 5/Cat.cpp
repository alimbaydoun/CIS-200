#include<iostream>
#include"Cat.h"

using namespace std;

string Cat::getAnimalType()
{
	return "Cat";
}

void Cat::makeNoise()
{
	cout << "Meeeooow! Feed me! Purr, Purr, Purr." << endl;
}

void Cat::doKittythings()
{
	cout << "I’m tearing up your couch with my claws, and leaving dead mice on your pillow!" << endl;
}