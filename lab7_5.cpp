#include <iostream>
using namespace std;

class Point {
    private:
        int x;
        int y;
    public:
        Point(int, int);
        void Display_Point();
};

Point :: Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

void Point :: Display_Point() {
    cout << "Point x: " << x << "; Point y: " << y << endl;
}

class Circle {
    private:
        float radius;
        Point point;
    public:
        Circle(float, Point);
        void Display_Circle();
        float getRadius();
};

Circle :: Circle(float r, Point p) : radius(r), point(p) {}

void Circle :: Display_Circle() {
    cout << "Radius: " << radius << endl;
}

float Circle :: getRadius() {
    return radius;
}

class Cylinder {
    private:
        int height;
        Circle circle;
    public:
        Cylinder(int, Circle);
        float Volume_Cylinder();
        void Display_Cylinder();
};

Cylinder :: Cylinder(int h, Circle c) : height(h), circle(c) {}

float Cylinder :: Volume_Cylinder() {
    float p = 3.14;
    float r = circle.getRadius();

    return p * (r * r) * height;
}

void Cylinder :: Display_Cylinder() {
    cout << "Height: " << height << endl;
}

int main() {
    Point p1(1, 2);
    Circle c1(3.0 , p1);
    Cylinder cl1(6, c1);

    p1.Display_Point();
    c1.Display_Circle();
    cl1.Display_Cylinder();
    cout << "Volume of cylinder is: " << cl1.Volume_Cylinder() << endl;

    return 0;
}