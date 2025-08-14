#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

class Triangle {
private:
    Point vertex1;
    Point vertex2;
    Point vertex3;

public:
    Triangle(Point v1, Point v2, Point v3) : vertex1(v1), vertex2(v2), vertex3(v3) {}

    double computeArea() {
        return 0.5 * abs(vertex1.x * (vertex2.y - vertex3.y) +
                         vertex2.x * (vertex3.y - vertex1.y) +
                         vertex3.x * (vertex1.y - vertex2.y));
    }
};

int main() {
    Point p1(0, 0);
    Point p2(5, 0);
    Point p3(0, 5);

    Triangle triangle(p1, p2, p3);

    cout << "Area of the triangle: " << triangle.computeArea() << endl;

    return 0;
}