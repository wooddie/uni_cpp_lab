#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    float radius;

public:
    Circle() : radius(0) {}

    Circle(float r) : radius(r) {}

    float area() const {
        return M_PI * radius * radius;
    }

    float circum() const {
        return 2 * M_PI * radius;
    }
};

int main() {
    Circle c1(4.4);

    cout << "Area: " << c1.area() << endl;
    cout << "Circum: " << c1.circum() << endl;

    return 0;
}