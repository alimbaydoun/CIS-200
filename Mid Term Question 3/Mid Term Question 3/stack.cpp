#include <iostream>

#include <cstdlib>

#include "stack.h"

using namespace std;

// define default capacity of Stack

// Constructor to initialize Stack
template < class X >
Stack < X > ::Stack(int size) {
    arr = new X[size];
    capacity = size;
    top = -1;
}

// function to add an element x in the Stack
template < class X >
void Stack < X > ::push(X x) {
    if (top == (capacity - 1)) //If the top reaches to the maximum stack size
    {
        X* newp = new X[capacity * 2];
        std::memcpy(newp, arr, sizeof(X) * capacity);
        delete[] arr;
        arr = newp;
        top++;
        arr[top] = x;
        capacity *= 2;
    }
    else {
        top++;
        arr[top] = x;
    }
}

// function to pop top element from the Stack
template < class X >
X Stack < X > ::pop() {
    // check for Stack underflow
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    // decrease Stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

// function to return top element in a Stack
template < class X >
X Stack < X > ::Top() {
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to return the size of the Stack
template < class X >
int Stack < X > ::size() {
    return top + 1;
}

// Utility function to check if the Stack is empty or not
template < class X >
bool Stack < X > ::isEmpty() {
    return top == -1; // or return size() == 0;
}

// Utility function to check if the Stack is full or not
template < class X >
bool Stack < X > ::isFull() {
    return top == capacity - 1; // or return size() == capacity;
}