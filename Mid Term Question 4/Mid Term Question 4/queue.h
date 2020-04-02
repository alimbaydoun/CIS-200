#pragma once
#include <stdio.h>
#include <cstddef>

template <class T>
class Node {
public:
    T data;
    Node* next;
};


template <class T>
class Queue {
public:
    Node<T>* front, * rear;
    Queue() {
        front = rear = NULL;

    }

    void insert(T n);
    void deleteitem();
    void display();
    int size();
    ~Queue();
    bool isEmpty();
};