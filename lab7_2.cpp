#include<iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction addFraction(Fraction);
        Fraction subFraction(Fraction);
        Fraction mulFraction(Fraction);
        Fraction divFraction(Fraction);

        int getNum();
        int getDenom();
        void Set(int a, int b);
};

Fraction Fraction :: addFraction(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction :: subFraction(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.denominator - denominator * other.numerator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction :: mulFraction(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction :: divFraction(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;
    return result;
}

int Fraction :: getNum() {
    return numerator;
}

int Fraction :: getDenom() {
    return denominator;
}

void Fraction :: Set(int a, int b) {
    numerator = a;
    denominator = b;
}

int main() {
    Fraction f1, f2, result;

    f1.Set(1, 2);
    f2.Set(1, 4);

    result = f1.addFraction(f2);
    cout << "" << result.getNum() << "/" << result.getDenom() << endl;

    result = f1.subFraction(f2);
    cout << "" << result.getNum() << "/" << result.getDenom() << endl;

    result = f1.mulFraction(f2);
    cout << "" << result.getNum() << "/" << result.getDenom() << endl;

    result = f1.divFraction(f2);
    cout << "" << result.getNum() << "/" << result.getDenom() << endl;

    return 0;
}