#include <iostream>
using namespace std;

class Distance {
    private:
        int feet;
        float inches;
    public:
        Distance() {};
        Distance(float f, float i) { feet = f, inches = i; };
        void Get_Data();
        void Show_Data();
        bool operator==(Distance);
        bool operator>=(Distance);
        bool operator<=(Distance);
};

void Distance :: Get_Data() {
    cout << "Enter feet: ";
    cin >> feet;
    cout << "Enter inches: ";
    cin >> inches;
}

void Distance :: Show_Data() {
    cout << "feet: " << feet << "; inches: " << inches << endl;
}

bool Distance :: operator==(Distance a) {
    if(feet == a.feet && inches == a.inches) {
        return true;
    }
    return false;
}

bool Distance :: operator>=(Distance a) {
    if(feet > a.feet || (feet == a.feet && inches >= a.inches)) {
        return true;
    }
    return false;
}

bool Distance :: operator<= (Distance a) {
    if (feet < a.feet || (feet == a.feet && inches <= a.inches)) {
        return true;
    }
    return false;
}

int main() {

    Distance d1, d2;

    cout << "Enter data for first distance:" << endl;
    d1.Get_Data();
    cout << "Enter data for second distance:" << endl;
    d2.Get_Data();

    if (d1 == d2) {
        cout << boolalpha << true << endl;
    } else {
        cout << boolalpha << false << endl;
    }

    if (d1 >= d2) {
        cout << boolalpha << true << endl;
    } else {
        cout << boolalpha << false << endl;
    }

    if (d1 <= d2) {
        cout << boolalpha << true << endl;
    } else {
        cout << boolalpha << false << endl;
    }

    return 0;
}