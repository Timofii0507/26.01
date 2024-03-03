#include <iostream>
#include <exception>
#include <Windows.h>

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
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int data) {
        try {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            if (head == nullptr) {
                newNode->prev = nullptr;
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
        catch (bad_alloc& e) {
            throw LinkedListException("���� ��������� ���'�� ��� ��������� ������ �����");
        }
    }

    void pop() {
        if (head == nullptr) {
            throw LinkedListException("��������� �������� ����� � ������� ������");
        }
        else {
            Node* temp = tail;
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoublyLinkedList list;
    int choice, data;
    bool exit = false;
    while (!exit) {
        cout << "������� �����:" << endl;
        cout << "1. ������ ����� � ����� ������" << endl;
        cout << "2. �������� ����� � ���� ������" << endl;
        cout << "3. ������� ������ �� �����" << endl;
        cout << "4. ����� � ��������" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������ ��� ��� ������ �����: " << endl;
            cin >> data;
            try {
                list.append(data);
                cout << "����� ������ ������" << endl;
            }
            catch (LinkedListException& e) {
                cout << "�������: " << e.what() << endl;
            }
            break;
        case 2:
            try {
                list.pop();
                cout << "����� ������ ��������" << endl;
            }
            catch (LinkedListException& e) {
                cout << "�������: " << e.what() << endl;
            }
            break;
        case 3:
            list.display();
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "������������ ����, ��������� �� ���" << endl;
            break;
        }
    }
    return 0;
}
