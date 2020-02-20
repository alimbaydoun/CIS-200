#include <iostream>
#include "Animal.h"

using namespace std;

string Animal::getName()
{
	return name;
}
void Animal::setName(string str)
{
	this->name = str;
}