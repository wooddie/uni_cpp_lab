#include <iostream>
using namespace std;

class Base {
    protected:
        float width;
        float height;
    public:
        void setValue(float a, float b) {
            width = a;
            height = b;
        }
};

class Triangle : public Base {
    public:
        float area() {
            return (width * height / 2);
        }
};

class Rectangle : public Base {
    public:
        float area() {
            return (width * height);
        }
};

int main() {

    Rectangle r1;
    Triangle t1;

    r1.setValue(4, 5);
    t1.setValue(5, 4);

    cout << "Area of rectangle: " << r1.area() << endl;
    cout << "Area of triangle: " << t1.area() << endl;

    return 0;
}