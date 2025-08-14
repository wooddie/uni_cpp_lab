#include<iostream>
using namespace std;

class Complex {
    private:
        float real;
        float imag;
    public:
    Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    Complex addition(Complex);
    Complex subtraction(Complex);
    Complex multiplication(Complex);
    void printing();
};

Complex Complex :: addition(Complex other) {
    Complex result;
    result.real = real + other.real;
    result.imag = imag + other.imag;
    return result;
}

Complex Complex :: subtraction(Complex other) {
    Complex result;
    result.real = real - other.real;
    result.imag = imag - other.imag;
    return result;
}

Complex Complex :: multiplication(Complex other) {
    float r = (real * other.real) - (imag * other.imag);
    float i = (real * other.imag) + (other.real * imag);
    return Complex(r , i);
}

void Complex :: printing() {
    cout << real;
    if (imag >= 0)
        cout << " + " << imag << "i" << endl;
    else
        cout << " - " << -imag << "i" << endl;
}

int main() {
    float r1, i1, r2, i2;

    cout << "Enter real and imaginary part of first complex number:" << endl;
    cin >> r1 >> i1;
    Complex c1(r1, i1);

    cout << "Enter real and imaginary part of second complex number:" << endl;
    cin >> r2 >> i2;
    Complex c2(r2, i2);

    Complex add = c1.addition(c2);
    Complex sub = c1.subtraction(c2);
    Complex mul = c1.multiplication(c2);

    cout << "Sum of two complex numbers is:" << endl;
    add.printing();
    cout << "difference of two complex numbers is:" << endl;
    sub.printing();
    cout << "Product of two complex numbers is:" << endl;
    mul.printing();

    return 0;
}