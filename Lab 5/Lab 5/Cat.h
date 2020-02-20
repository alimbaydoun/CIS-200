#ifndef CAT_H
#define CAT_H
#include "Animal.h"

using namespace std;

class Cat : public Animal
{
public:
	string getAnimalType();
	void makeNoise();
	void doKittyThings();
private:
	// Declaring variables

};
#endif