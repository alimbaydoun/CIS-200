#include <iostream>
#include "Animal.h"

using namespace std;

//Precondition: gets the name for string Animal
//Postcondition: returns string name
//Description: string Animal uses getName() to return string name from Animal.h
string Animal::getName()
{
	return name;
}

//Precondition: points name and sets it to string a
//Postcondition: points name and sets it to string a
//Description: points name and sets it to string a
void Animal::setName(string a)
{
	this->name = a;
}