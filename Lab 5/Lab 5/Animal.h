#pragma once
#include<string>
#include"Animal.cpp"
using namespace std;

class Animal
{
private:
	string name;
public:
	string getAnimalType;
	string getName;
	void setName();
	void makeNoise();
};