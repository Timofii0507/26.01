#include <iostream>
#include <string>
#include <stdexcept>
#include <Windows.h>

using namespace std;

int parse_int(string s) {
    if (s.empty()) {
        throw invalid_argument("Рядок не може бути порожнім");
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
            throw invalid_argument("Рядок містить недопустимі символи");
        }
        int digit = s[i] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            throw out_of_range("Результат виходить за межі діапазону int");
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
    cout << "Введіть рядок, який є записом числа в десятковій системі числення: ";
    cin >> s;
    try {
        int value = parse_int(s);
        cout << "Значення за рядком: " << value << endl;
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }
    return 0;
}
