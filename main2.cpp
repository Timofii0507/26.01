#include <iostream>
#include <Windows.h>
#include "stack.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введіть розмір стеку: ";
    cin >> size;
    try {
        Stack stack(size);
        int choice;
        int value;
        do {
            cout << "Виберіть операцію:\n";
            cout << "1. Додати елемент до стеку\n";
            cout << "2. Вилучити елемент зі стеку\n";
            cout << "3. Показати елемент з вершини стеку\n";
            cout << "0. Вийти\n";
            cout << "Ваш вибір: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Введіть значення елемента: ";
                cin >> value;
                try {
                    stack.push(value);
                    cout << "Елемент " << value << " додано до стеку\n";
                }
                catch (StackException& e) {
                    cout << "Помилка: " << e.what() << endl;
                }
                break;
            case 2:
                try {
                    value = stack.pop();
                    cout << "Елемент " << value << " вилучено зі стеку\n";
                }
                catch (StackException& e) {
                    cout << "Помилка: " << e.what() << endl;
                }
                break;
            case 3:
                try {
                    value = stack.peek();
                    cout << "Елемент з вершини стеку: " << value << endl;
                }
                catch (StackException& e) {
                    cout << "Помилка: " << e.what() << endl;
                }
                break;
            case 0:
                cout << "До побачення!\n";
                break;
            default:
                cout << "Невірний вибір, спробуйте ще раз\n";
                break;
            }
        } while (choice != 0);
    }
    catch (StackException& e) {
        cout << "Помилка: " << e.what() << endl;
    }
    return 0;
}
