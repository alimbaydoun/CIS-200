#pragma once
#include<stdio.h>
#include<cstddef>

template < class N >
class Node {
public:
    N data;
    Node* next;
};

template < class N >
class Queue {
public:
    Node < N >* front, * rear;
    Queue() {
        front = rear = NULL;

    }

    void insert(N n);
    void deleteitem();
    void display();
    int size();
    ~Queue();
    bool isEmpty();
};