#pragma once
#include "node_head.h"

template <typename T>
class Linkedlist{
private:
    int size;
    Node<T>* head;
    Node<T>* tail;

public:
    Linkedlist();

    Linkedlist(Node<T>* node);

    int getSize();
    Node<T>* getHead();
    Node<T>* getTail();
    void add(T value);
    void remove(T value);
    T* peek();
    void deleteAll();

};