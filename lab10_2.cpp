#include <iostream>
using namespace std;

template <class T>
class Calculator {
    private:
        T numOne, numTwo;
    public:
        Calculator(T, T);
        T add();
        T multiply();
};

template <class T>
Calculator<T> :: Calculator(T a, T b) : numOne(a), numTwo(b) {} 

template<class T>
T Calculator<T> :: add() {
    T result;
    result = numOne + numTwo;

    return result;
}

template<class T>
T Calculator<T> :: multiply() {
    T result;
    result = numOne * numTwo;

    return result;
}

int main() {

    Calculator<float> obj1(3.0453 , 2.0123);
    Calculator<int> obj2(3, 2);
    Calculator<double> obj3(3.3, 2.2);

    cout << "FLOAT" << endl;
    cout << "Add: " << obj1.add() << endl;
    cout << "Multiply: " << obj1.multiply() << endl;

    cout << "INTEGER" << endl;
    cout << "Add: " << obj2.add() << endl;
    cout << "Multiply: " << obj2.multiply() << endl;

    cout << "DOUBLE" << endl;
    cout << "Add: " << obj3.add() << endl;
    cout << "Multiply: " << obj3.multiply() << endl;

    return 0;
}