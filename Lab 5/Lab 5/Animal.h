#pragma once
#include <iostream>

using namespace std;

class Animal
{
private:
    string name;
public:
    virtual string getAnimalType() = 0;
    virtual void makeNoise() = 0;
    string getName();
    void setName(string a);
};