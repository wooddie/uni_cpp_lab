#include <iostream>
#include <cmath>
using namespace std;

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);

int main() {
    float num1, num2;
    char operation;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите оператор (+, -, *, /, ^): ";
    cin >> operation;
    cout << "Введите второе число: ";
    cin >> num2;

    float result;
    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            if (num2 != 0) {
                result = divide(num1, num2);
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
                return 1;
            }
            break;
        case '^':
            result = power(num1, num2);
            break;
        default:
            cout << "Неверный оператор!" << endl;
            return 1;
    }

    cout << "Результат: " << result << endl;
    return 0;
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

float power(float a, float b) {
    return pow(a, b);
}