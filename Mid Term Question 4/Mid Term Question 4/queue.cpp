#include"queue.h"
#include<iostream>

using namespace std;

//Precondition:
//Postcondition:
//Description:
template < class N >
void Queue < N > ::insert(N n) {
    Node < N >* temp = new Node < N >;
    if (temp == NULL) {
        temp -> data = n;
        temp -> next = NULL;
    }

    if (front == NULL) {
        front = rear = temp;
    }
    else {
        rear -> next = temp;
        rear = temp;
    }
}

//Precondition:
//Postcondition:
//Description:
template < class N >
void Queue < N > ::deleteitem() {
    if (front == NULL) {
        cout << "Filled";
        return;
    }

    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
Queue < N > ::~Queue() {
    while (front != NULL) {
        Node < N >* temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
bool Queue < N > ::isEmpty() {
    if (front == NULL)
        return true;
    return false;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
void Queue < N > ::display() {
    if (front == NULL) {
        cout << "Underflow." << endl;

    }
    Node < N >* temp = front;

    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//Precondition:
//Postcondition:
//Description:
template < class N >
int Queue < N > ::size() {
    int size = 0;
    if (front == NULL) {

        return 0;
    }
    Node < N >* temp = front;

    while (temp) {
        size++;
        temp = temp -> next;
    }
    return size;
}