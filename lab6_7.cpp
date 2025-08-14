#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(float r, float m) : real(r), imag(m) {}

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex subtract(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex multiply(const Complex& other) const {
        float r = real * other.real - imag * other.imag;
        float m = real * other.imag + imag * other.real;
        return Complex(r, m);
    }

    Complex divide(const Complex& other) const {
        float denominator = other.real * other.real + other.imag * other.imag;
        float r = (real * other.real + imag * other.imag) / denominator;
        float m = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, m);
    }

    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i" << endl;
        else
            cout << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "Первое число: ";
    c1.display();

    cout << "Второе число: ";
    c2.display();

    Complex sum = c1.add(c2);
    cout << "Сумма: ";
    sum.display();

    Complex difference = c1.subtract(c2);
    cout << "Разность: ";
    difference.display();

    Complex product = c1.multiply(c2);
    cout << "Произведение: ";
    product.display();

    Complex quotient = c1.divide(c2);
    cout << "Частное: ";
    quotient.display();

    return 0;
}