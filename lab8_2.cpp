#include <iostream>
using namespace std;

class Complex {
    private:
        float re, im;
    public:
    Complex() { re = im = 1; }
    Complex(float a, float b) { re = a, im = b; };
    Complex operator-(Complex c);
    Complex operator*(Complex d);
    void Show() {
        cout << "real: " << re << ", imag: " << im << endl;
    }
};

Complex Complex :: operator-(Complex c) {
    Complex result;

    result.re = re - c.re;
    result.im = im - c.im;

    return (result);
}

Complex Complex :: operator*(Complex d) {
    Complex result;

    result.re = re * d.re;
    result.im = im * d.im;

    return (result);
}

int main() {
    Complex c1(2.2 , 3.0);
    Complex c2(1.0, -4.0);

    Complex c3 = c1 - c2;
    Complex c4 = c1 * c2;

    c3.Show();
    c4.Show();

    return 0;
}