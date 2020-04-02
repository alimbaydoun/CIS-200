#pragma once
#define SIZE 1

// Class for Stack
template < class X >
class Stack {
    X* arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE); // constructor

    void push(X);
    X pop();
    X Top();

    int size();
    bool isEmpty();
    bool isFull();

    // destructor
    ~Stack() {
        delete[] arr;
    }
};