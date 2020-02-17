#pragma once
#include<iostream>
using namespace std;

class Vector
{
private:
	int size;           // sets the # of elements used
	int* entries;		// point to array of integers with size entries
							//		e.g. entries = new int[size]
public:
	Vector();           // default constructor
	Vector(int s);      // makes size = s, allocates s space
							//   e.g. entries = new int[size],
							//   makes all entries 0
	Vector(const Vector& other);  // copy constructor, makes a deep copy
	~Vector();					  // default destructor
	void print();				  // Prints out the vector as: [1 2 3]

	void set(int val, int pos);   // if 0 <= pos < size
	Vector operator+(const Vector& other) const;
	Vector operator=(const Vector& other);
														//stores val at pos in entries
														//  otherwise error message
};