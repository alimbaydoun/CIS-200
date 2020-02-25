#include <iostream>
#include "Cat.h"

using namespace std;

//Precondition: string Cat uses getAnimalType() function
//Postcondition: returns Cat data type
//Description: Cat string returns "Cat"
string Cat::getAnimalType()
{
	return "Cat";
}

//Precondition: Cat function uses makeNoise function
//Postcondition: prints a statement when called upon
//Description: Cat function prints a statement
void Cat::makeNoise()
{
	cout << "Meeeeooow! Feed me Purr,Purr,Purr" << endl;
}

//Precondition: Cat function uses doKittyThings() funtion
//Postcondition: prints a statement when called upon
//Description: Cat function prints statement
void Cat::doKittyThings()
{
	cout << "I'm tearing up your couch with my claws, and leaving dead mice you pillow!" << endl;
}