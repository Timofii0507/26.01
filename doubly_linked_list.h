#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#pragma once

#include <iostream>
#include <exception>

using namespace std;

class LinkedListException : public exception {
public:
    LinkedListException(const char* message) : exception(message) {}
};

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    void append(int data);
    void pop();
    void display();
};


#endif 