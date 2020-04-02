#include "queue.h"

#include<iostream>

using namespace std;
//Pre:Template class must be created
//Desc:Checks if temp is NUll or if front is NUll
//Post:if temp is NULL temp next is null if front null front equals rear equals temp
template < class T >
void Queue < T > ::insert(T n) {
    Node < T >* temp = new Node < T >;
    if (temp == NULL) {
        temp - > data = n;
        temp - > next = NULL;

    }

    if (front == NULL) {
        front = rear = temp;
    }
    else {
        rear - > next = temp;
        rear = temp;
    }

}
//Pre:Template class must be created
//Desc:Will checks temp data until NULL is not found
//Post:checks if temp is not null
template < class T >
void Queue < T > ::display() {
    if (front == NULL) {
        cout << "Underflow." << endl;

    }
    Node < T >* temp = front;
    //will check until NULL is not found
    while (temp) {
        cout << temp - > data << " ";
        temp = temp - > next;
    }
    cout << endl;
}
//Pre:Template class must be created
//Desc:Returns 0 if front equals NULL and checks temp until NULL is not found and returns size
//Post: Returns 0 if front is null or returns size until temp is null
template < class T >
int Queue < T > ::size() {
    int size = 0;
    if (front == NULL) {

        return 0;
    }
    Node < T >* temp = front;
    //will check until NULL is not found
    while (temp) {
        size++;
        temp = temp - > next;
    }
    return size;
}
//Pre:Template class must be created
//Desc:If front is filled message prints if front equals rear there equal to null else front is set to front this next
//Post:deletes a single node
template < class T >
void Queue < T > ::deleteitem() {
    if (front == NULL) {
        cout << "Filled";
        return;
    }

    if (front == rear) //if only one node is there
        front = rear = NULL;
    else
        front = front - > next;

}
//Pre:Template class must be created
//Desc:Destructor while front is not null temp equals front than front equals front this next than temp is deleted
//Post:Deletes temp and rear equals null
template < class T >
Queue < T > ::~Queue() {
    while (front != NULL) {
        Node < T >* temp = front;
        front = front - > next;
        delete temp;
    }
    rear = NULL;
}
//Pre:Template class must be created
//Desc:Checks if queue is empty
//Post:Returns true id front equals null or false if front is not null
template < class T >
bool Queue < T > ::isEmpty() {
    if (front == NULL)
        return true;
    return false;

}