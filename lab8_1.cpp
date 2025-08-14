#include <iostream>
using namespace std;

class Vector {
    public:
        float x, y;
        Vector() {};
        Vector(float a, float b) { x = a, y = b; }
        Vector operator+(Vector);
        Vector operator*(Vector);
};

Vector Vector :: operator+(Vector param) {
    Vector result;

    result.x = x + param.x;
    result.y = y + param.y;

    return (result);
}

Vector Vector :: operator*(Vector param) {
    Vector result;

    result.x = x * param.x;
    result.y = y * param.y;

    return (result);
}

int main() {
    Vector v1(1, 2);
    Vector v2(3, 4);

    Vector v3;
    v3 = v1 + v2;
    
    Vector v4;
    v4 = v1 * v2;

    cout << "subtraction: x = " << v3.x << "; y = " << v3.y << endl;
    cout << "multiplication: x = " << v4.x << "; y = " << v4.y << endl;

    return 0;
}