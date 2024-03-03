#include <iostream>
#include <string>
#include <stdexcept>
#include <Windows.h>

using namespace std;

int parse_int(string s) {
    if (s.empty()) {
        throw invalid_argument("����� �� ���� ���� �������");
    }
    int result = 0;
    int sign = 1;
    int i = 0;
    if (s[0] == '+' || s[0] == '-') {
        sign = (s[0] == '+') ? 1 : -1;
        i++;
    }
    while (i < s.length()) {
        if (!isdigit(s[i])) {
            throw invalid_argument("����� ������ ���������� �������");
        }
        int digit = s[i] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            throw out_of_range("��������� �������� �� ��� �������� int");
        }
        result = result * 10 + digit;
        i++;
    }
    return result * sign;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    cout << "������ �����, ���� � ������� ����� � ��������� ������ ��������: ";
    cin >> s;
    try {
        int value = parse_int(s);
        cout << "�������� �� ������: " << value << endl;
    }
    catch (exception& e) {
        cout << "�������: " << e.what() << endl;
    }
    return 0;
}
