#include<iostream>
#include<vector>
#include<string>
#include"Vector.h"

using namespace std;

//Initializes the vector with 0 size.
Vector::Vector()
{
size = 0;
entries = new int[size];
for (int i = 0; i < size; i++)
{
entries[i] = 0;
}
}

//Initializes the vector with specified size s.
Vector::Vector(int s)
{
size = s;
entries = new int[size];
for (int i = 0; i < size; i++)
{
entries[i] = 0;
}
}

//Initializes the vector with the members of another vector other.
Vector::Vector(const Vector & other)
{
this->size = other.size;
this->entries = new int[size];
for (int i = 0; i < size; i++)
{
this->entries[i] = other.entries[i];
}
}

//Deletes the vector (Destructor).
Vector::~Vector()
{
this->entries = NULL;
}

//Prints the contents of vector.
void Vector::print()
{
cout << endl << "[";
for (int i = 0; i < size; i++)
{
cout << entries[i] << " ";
}
cout << "]" << endl;
}

//Sets the value val at specified position if it is valid.
void Vector::set(int val, int pos)
{
if(pos < size)
    entries[pos] = val;
}

//Add the vector to other vector and stores in a vector, and will return.
Vector Vector::operator+ (const Vector &other) const
{
    Vector temp(size + other.size);
    for(int i = 0; i < size; i++)
        temp.set(entries[i], i);
    for(int i = 0; i < other.size; i++)
        temp.set(other.entries[i], size+i);
    return temp;      
}

//Assigns the values in other to this vector.
Vector Vector::operator= (const Vector & other)
{
   size = other.size;
   for(int i = 0; i < size; i++)
       entries[i] = other.entries[i];
   return *this;  
}