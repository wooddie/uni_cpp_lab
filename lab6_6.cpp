#include <iostream>
#include <cmath>

using namespace std;

class Sphere {
private:
    float radius;

public:
    Sphere() : radius(0) {}

    void setRadius(float r) {
        if (r > 0) {
            radius = r;
        } else {
            cout << "Radius must be positive!" << endl;
        }
    }

    double getRadius() const {
        return radius;
    }

    float area() const {
        return 4 * M_PI * radius * radius;
    }
};

int main() {
    Sphere mySphere;

    float r;
    cout << "Enter the radius of the sphere: ";
    cin >> r;

    mySphere.setRadius(r);
    cout << "The radius of the sphere is: " << mySphere.getRadius() << endl;
    cout << "Area: " << mySphere.area() << endl;

    return 0;
}