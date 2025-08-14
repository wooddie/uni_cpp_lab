#include <iostream>
#include <math.h>
using namespace std;

class Point2D {
    protected:
        float x; float y;
    public:
    Point2D() : x(0), y(0) {};
    Point2D(float, float);
    float getX() const { return x; }
    float getY() const { return y; }
    void display_point();
};

Point2D :: Point2D(float xCoor, float yCoor) : x(xCoor), y(yCoor) {};

void Point2D :: display_point() {
    cout << "(x: " << x << ", y: " << y << ")" << endl;
};

class Point3D : public Point2D {
    protected:
        float z;
    public:
        Point3D() : Point2D(), z(0) {};
        Point3D(float, float, float);
        void display_point();
        float getZ() const { return z; }
};

Point3D :: Point3D(float xCoor, float yCoor, float zCoor) : Point2D(xCoor, yCoor), z(zCoor) {};

void Point3D :: display_point() {
    cout << "(x: " << x << ", y: " << y << ", z: " << z << ")" << endl;
}

class Distance_Point : public Point3D {
    protected:
        float dis;
    public:
        float distancePoint(Point3D, Point3D);
};

float Distance_Point::distancePoint(Point3D p1, Point3D p2) {
    dis = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2) + pow(p2.getZ() - p1.getZ(), 2));
    return dis;
}

int main() {

    Point3D p3_1(1, 4, 6);
    Point3D p3_2(2, 3, 7);
    Distance_Point d1;

    cout << "Distance: " << d1.distancePoint(p3_1, p3_2) << endl;

    return 0;
}