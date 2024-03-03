#include "stack.h"

StackException::StackException(string message) {
    this->message = message;
}

const char* StackException::what() const noexcept {
    return message.c_str();
}

Stack::Stack(int size) {
    if (size <= 0) {
        throw StackException("Розмір стеку має бути додатнім");
    }
    try {
        array = new int[size];
    }
    catch (bad_alloc& e) {
        throw StackException("Не вдалося виділити пам'ять для стеку");
    }
    this->size = size;
    top = -1;
}

Stack::~Stack() {
    delete[] array;
}

bool Stack::is_empty() {
    return top == -1;
}

bool Stack::is_full() {
    return top == size - 1;
}

void Stack::push(int value) {
    if (is_full()) {
        throw StackException("Стек переповнений");
    }
    top++;
    array[top] = value;
}

int Stack::pop() {
    if (is_empty()) {
        throw StackException("Стек порожній");
    }
    int value = array[top];
    top--;
    return value;
}

int Stack::peek() {
    if (is_empty()) {
        throw StackException("Стек порожній");
    }
    return array[top];
}
