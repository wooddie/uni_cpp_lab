#include <iostream>

using namespace std;

class Ship {
private:
    int shipNumber;
    int longitude;
    int latitude;

public:
    Ship(int n = 0, int lo = 0, int la = 0) : shipNumber(n), longitude(lo), latitude(la) {}

    void getPosition() {
        while (true) {
            cout << "Enter longitude (between -180 and 180) and latitude (between -90 and 90): ";
            cin >> longitude >> latitude;

            if (longitude < -180 || longitude > 180) {
                cout << "Invalid longitude! Enter a value between -180 and 180." << endl;
                continue;
            }

            if (latitude < -90 || latitude > 90) {
                cout << "Invalid latitude! Enter a value between -90 and 90." << endl;
                continue;
            }

            break;
        }
    }

    void displayData() {
        cout << "Ship number: " << shipNumber << "; longitude: " << longitude << "; latitude: " << latitude << endl;
    }

};

int main() {
    Ship ship1(1);
    Ship ship2(2);
    Ship ship3(3);

    ship1.getPosition();
    ship2.getPosition();
    ship3.getPosition();

    ship1.displayData();
    ship2.displayData();
    ship3.displayData();

    return 0;
}