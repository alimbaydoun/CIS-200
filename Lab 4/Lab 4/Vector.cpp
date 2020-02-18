#include<iostream>
#include<vector>
#include<string>
#include"Vector.h"

using namespace std;

//Precondition: Initialize the vector
//Postcondition: Initialize size
//Description: Initializes size with 0
Vector::Vector()
{
    size = 0;
    
    entries = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        entries[i] = 0;
    }
}

//Precondition: accepts size
//Postcondition: Initializes integer s.
//Description: Initializes entries to 0
Vector::Vector(int s)
{
    size = s;
    
    entries = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        entries[i] = 0;
    }
}

//Precondition: Initializes the vector
//Postcondition: Initializes members of another vecter.
//Description: Initializes the vector with members of another vector.
Vector::Vector(const Vector & other)
{
    this->size = other.size;
    
    this->entries = new int[size];
    
    for (int i = 0; i < size; i++)
    {
       this->entries[i] = other.entries[i];
    }
}

//Precondition: None
//Postcondition: Deletes the vector.
//Description: Vector this points to vector entries
Vector::~Vector()
{
this->entries = NULL;
}

//Precondition: uses the print() function
//Postcondition: Prints the contents of vector.
//Description: Prints the contents of entries
void Vector::print()
{
    cout << endl << "[";
  
    for (int i = 0; i < size; i++)
    {
   
        cout << entries[i] << " ";
    }
   
    cout << "]" << endl;
}

//Precondition: None
//Postcondition: Sets the value val and value pos.
//Description: Sets the value val at specified position if it is valid.
void Vector::set(int val, int pos)
{
    if(pos < size)
    entries[pos] = val;
}

//Precondition: Initializes size + other.size
//Postcondition: Adds the vectors and returns temp.
//Description: Add the vector to other vector and stores in a vector, and will return.
Vector Vector::operator+ (const Vector &other) const
{
    Vector temp(size + other.size);
  
    for(int i = 0; i < size; i++)
        temp.set(entries[i], i);
   
    for(int i = 0; i < other.size; i++)
        temp.set(other.entries[i], size+i);
   
    return temp;      
}

//Precondition: Assigns the operator with Vector & other
//Postcondition: Returns this vector.
//Description: Assigns the values in other to this vector.
Vector Vector::operator= (const Vector & other)
{
   size = other.size;
  
   for(int i = 0; i < size; i++)
       entries[i] = other.entries[i];
  
   return *this;  
}