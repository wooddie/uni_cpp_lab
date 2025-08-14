#include <iostream>
using namespace std;

class Rectangle {
    private:
        float height;
        float width;
    public:
        Rectangle() {};
        Rectangle(float h, float w) { height = h, width = w; };

        float Area() {
            return height * width;
        }

        bool operator<(Rectangle);
        void Show();
};

bool Rectangle :: operator<(Rectangle param) {
    if(Area() < param.Area()) {
        return true;
    }
    return false;
}

void Rectangle :: Show() {
    cout << "height: " << height << "; width: " << width << endl;
}

int main() {
    Rectangle r1(3.0, 5.0);
    Rectangle r2(2.0, 5.0);
    r1.Show();
    r2.Show();

    cout << "Area r1: " << r1.Area() << endl;
    cout << "Area r2: " << r2.Area() << endl;

    if (r1.Area() < r2.Area()) {
        cout << boolalpha << true << endl;
    } else {
        cout << boolalpha << false << endl;
    }

    return 0;
}