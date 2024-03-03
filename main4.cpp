#include <iostream>
#include <exception>
#include <string>
#include <Windows.h>

using namespace std;

class MyException : public exception {
protected:
    string message;
public:
    MyException(string msg) : message(msg) {}
    virtual const char* what() const noexcept {
        return message.c_str();
    }
};

class MathException : public MyException {
public:
    MathException(string msg) : MyException(msg) {}
};

class DivideByZeroException : public MathException {
public:
    DivideByZeroException(string msg) : MathException(msg) {}
};

class OverflowException : public MathException {
public:
    OverflowException(string msg) : MathException(msg) {}
};

class OutOfMemoryException : public MyException {
public:
    OutOfMemoryException(string msg) : MyException(msg) {}
};

class FileException : public MyException {
public:
    FileException(string msg) : MyException(msg) {}
};

class FileOpenException : public FileException {
public:
    FileOpenException(string msg) : FileException(msg) {}
};

class FileReadException : public FileException {
public:
    FileReadException(string msg) : FileException(msg) {}
};

class FileWriteException : public FileException {
public:
    FileWriteException(string msg) : FileException(msg) {}
};

void testExceptions(int choice) {
    switch (choice) {
    case 1:
        throw DivideByZeroException("ĳ����� �� ����");
        break;
    case 2:
        throw OverflowException("������������");
        break;
    case 3:
        throw OutOfMemoryException("����������� ���'��");
        break;
    case 4:
        throw FileOpenException("������� �������� �����");
        break;
    case 5:
        throw FileReadException("������� ������� �����");
        break;
    case 6:
        throw FileWriteException("������� ������ �����");
        break;
    default:
        break;
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    cout << "������ ��� ���� (1-6): ";
    cin >> choice;

    try {
        testExceptions(choice);
    }
    catch (DivideByZeroException& e) {
        cout << "�������: " << e.what() << endl;
    }
    catch (OverflowException& e) {
        cout << "�������: " << e.what() << endl;
    }
    catch (OutOfMemoryException& e) {
        cout << "�������: " << e.what() << endl;
    }
    catch (FileException& e) {
        cout << "�������: " << e.what() << endl;
    }
    catch (...) {
        cout << "�������: �������� �������" << endl;
    }

    return 0;
}
