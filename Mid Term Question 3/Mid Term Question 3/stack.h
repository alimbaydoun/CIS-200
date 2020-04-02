#pragma once
#define SIZE 1

template < class N >

class Stack {
private:
    N* arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);

    int size();
    bool isEmpty();
    bool isFull();

    void push(N);
    N pop();
    N Top();
    
    ~Stack() {
        delete[] arr;
    }
};