#include<iostream>
#include<cstdlib>
#include"stack.h"

using namespace std;

//Precondition:
//Postcondition:
//Description:
template < class N >
void Stack < N > ::push(N n) {
    if (top == (capacity - 1)) 
    {
        N* newp = new N[capacity * 2];
        std::memcpy(newp, arr, sizeof(N) * capacity);
        delete[] arr;
        arr = newp;
        top++;
        arr[top] = n;
        capacity *= 2;
    }
    else {
        top++;
        arr[top] = n;
    }
}

//Precondition:
//Postcondition:
//Description:
template < class N >
bool Stack < N > ::isFull() {
    return top == capacity - 1;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
N Stack < N > ::Top() {
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

//Precondition:
//Postcondition:
//Description:
template < class N >
Stack < N > ::Stack(int size) {
    arr = new N[size];
    capacity = size;
    top = -1;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
bool Stack < N > ::isEmpty() {
    return top == -1;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
int Stack < N > ::size() {
    return top + 1;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
N Stack < N > ::pop() {
   
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
        
    return arr[top--];
}