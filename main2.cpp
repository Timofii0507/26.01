#include <iostream>
#include <Windows.h>
#include "stack.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "������ ����� �����: ";
    cin >> size;
    try {
        Stack stack(size);
        int choice;
        int value;
        do {
            cout << "������� ��������:\n";
            cout << "1. ������ ������� �� �����\n";
            cout << "2. �������� ������� � �����\n";
            cout << "3. �������� ������� � ������� �����\n";
            cout << "0. �����\n";
            cout << "��� ����: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "������ �������� ��������: ";
                cin >> value;
                try {
                    stack.push(value);
                    cout << "������� " << value << " ������ �� �����\n";
                }
                catch (StackException& e) {
                    cout << "�������: " << e.what() << endl;
                }
                break;
            case 2:
                try {
                    value = stack.pop();
                    cout << "������� " << value << " �������� � �����\n";
                }
                catch (StackException& e) {
                    cout << "�������: " << e.what() << endl;
                }
                break;
            case 3:
                try {
                    value = stack.peek();
                    cout << "������� � ������� �����: " << value << endl;
                }
                catch (StackException& e) {
                    cout << "�������: " << e.what() << endl;
                }
                break;
            case 0:
                cout << "�� ���������!\n";
                break;
            default:
                cout << "������� ����, ��������� �� ���\n";
                break;
            }
        } while (choice != 0);
    }
    catch (StackException& e) {
        cout << "�������: " << e.what() << endl;
    }
    return 0;
}
