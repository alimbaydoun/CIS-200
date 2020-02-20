#include <iostream>
#include "Cat.h"

using namespace std;

string Cat::getAnimalType()
{
	return "Cat";
}
void Cat::makeNoise()
{
	cout << "Meeeeooow! Feed me Purr,Purr,Purr" << endl;
}
void Cat::doKittyThings()
{
	cout << "I'm tearing up your couch with my claws, and leaving dead mice you pillow!" << endl;
}