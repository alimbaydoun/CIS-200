#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

using namespace std;

//Precondition: none
//Postcondition: tests functions in Cat.cpp and Dog.cpp
//Description: main function tests the aforementioned subclasses and their methods
int main()
{
    Dog d;
    Cat c;
   
    c.setName("Louis");
    cout << "---------Test For cat Class---------" << endl;
    cout << c.getName() << endl;
    cout << c.getAnimalType() << endl;
   
    c.makeNoise();
   
    c.doKittyThings();

    d.setName("Molly");
    cout << "\n---------Test For cat Class---------" << endl;
    cout << d.getName() << endl;
    cout << d.getAnimalType() << endl;
    
    d.makeNoise();
    d.doDoggyThings();

    return 0;
}