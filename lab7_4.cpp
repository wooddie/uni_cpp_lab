#include <iostream>
using namespace std;

class Person {
    public:
        string First_Name;
        string Last_Name;

        void Print_Name() {
            cout << First_Name << " " << Last_Name << endl;
        }
};

class Date {
    public:
        int day;
        int month;
        int year;

        void Print_Date() {
            cout << day << "." << month << "." << year << endl;
        }
};

class BirthdayInfo {
    public:
        Person person;
        Date date;
};

int main() {
    BirthdayInfo b1;

    b1.person.First_Name = "Kanapiya";
    b1.person.Last_Name = "Bazarbayev";
    b1.date.day = 20;
    b1.date.month = 3;
    b1.date.year = 2003;

    b1.person.Print_Name();
    b1.date.Print_Date();

    return 0;
}