#include <iostream>
using namespace std;

class Rectangle {
    private:
        float height;
        float width;
    public:
        Rectangle() {};
        Rectangle(float h, float w) { height = h, width = w; };
        Rectangle operator+(Rectangle);
        void Show();
};

Rectangle Rectangle :: operator+(Rectangle param) {
    Rectangle result;

    result.height = height + param.height;
    result.width = width + param.width;

    return (result);
}

void Rectangle :: Show() {
    cout << "height: " << height << "; width: " << width << endl;
}

int main() {

    Rectangle r1(12, 2.5);
    Rectangle r2(10, 2.5);

    Rectangle r3 = r1 + r2;
    r3.Show();

    return 0;
}