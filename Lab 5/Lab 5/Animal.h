#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Animal
{
public:
    virtual string getAnimalType() = 0;
    virtual void makeNoise() = 0;
    string getName();
    void setName(string str);

private:
    // Declaring variables
    string name;
};
#endif