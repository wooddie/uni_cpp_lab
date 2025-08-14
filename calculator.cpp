#include <iostream>
#include <cmath>
using namespace std;

double num1 , num2;
int choice;

void addition() {
    cout << "Ответ: " << num1 + num2 << endl;
}

void subtraction() {
    cout << "Ответ: " << num1 - num2 << endl;
}

void multiplication() {
    cout << "Ответ: " << num1 * num2 << endl;
}

void division() {
    if (num2 != 0) {
        cout << "Ответ: " << num1 / num2 << endl;
    } else {
        cout << "Деление на 0!" << endl;
    }
}

void remainder() {
    if (num2 != 0) {
        if (floor(num1) == num1 && floor(num2) == num2) {
            cout << "Ответ: " << static_cast<int>(num1) % static_cast<int>(num2) << endl;
        } else {
            cout << "Ответ: " << fmod(num1, num2) << endl;
        }
    } else {
        cout << "Деление на 0!" << endl;
    }
}

int main() {

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    cout << "Выберите опцию:" << endl;
    cout << "1: +" << endl;
    cout << "2: -" << endl;
    cout << "3: *" << endl;
    cout << "4: /" << endl;
    cout << "5: %" << endl;
    cout << "Ваш Выбор: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        addition();
        break;

    case 2:
        subtraction();
        break;

    case 3:
        multiplication();
        break;

    case 4:
        division();
        break;

    case 5:
        remainder();
        break;

    default:
        cout << "Error!" << endl;
        break;
    }

    return 0;
}