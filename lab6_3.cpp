#include <iostream>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date() : month(0), day(0), year(0) {}
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    void getDate() {
        while (true) {

            cout << "Enter month, day, year" << endl;
            cin >> month >> day >> year;

            if (month < 1 || month > 12) {
                cout << "Invalid month! Enter a value between 1 and 12." << endl;
                continue;
            }

            int daysInMonth = 31;
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                daysInMonth = 30;
            } else if (month == 2) {
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    daysInMonth = 29;
                } else {
                    daysInMonth = 28;
                }
            }

            if (day < 1 || day > daysInMonth) {
                cout << "Invalid day! Enter a valid day." << endl;
            }
            
            break;
        }
        
    }

    void displayDate() const{
        cout << "Date: " << month << "/" << day << "/" << year << endl;
    }
};

int main() {

    Date myDate;

    myDate.getDate();
    myDate.displayDate();

    return 0;
}