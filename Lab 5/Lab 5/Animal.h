#pragma once
#include<iostream>
#include<string>
#include"Dog.h"
#include"Cat.h"
using namespace std;

class Animal
{
private:
	string name;
public:
	virtual string getAnimalType()=0;
	string getName();
	void setName(string n);
	virtual void makeNoise()=0;
};