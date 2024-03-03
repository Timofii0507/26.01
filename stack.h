#ifndef STACK_H
#define STACK_H

#include <stdexcept>
using namespace std;

class StackException : public exception {
    string message;
public:
    StackException(string message);
    const char* what() const noexcept;
};

class Stack {
    int* array;
    int size;
    int top;
public:
    Stack(int size);
    ~Stack();
    bool is_empty();
    bool is_full();
    void push(int value);
    int pop();
    int peek();
};

#endif // STACK_H
