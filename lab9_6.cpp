#include <iostream>
using namespace std;

 class Faculty {
    protected:
        string name;
        int id;
    public:
        void setData(string, int);
        void printData();
        virtual ~Faculty() {}
        virtual float salary(void) = 0;
};

void Faculty :: setData(string a, int b) { name = a; id = b; }

void Faculty :: printData() { cout << "Name: " << name << "; ID: " << id << endl; }

class Permanent_Faculty : public Faculty {
    protected:
        int serviceYear;
        float basicPay;
    public:
        void setValue(int, float);
        float salary(void) override {
            float medical = 0.1 * basicPay;
            float rent = 0.25 * basicPay;

            return (basicPay + medical + rent);
        }
};

void Permanent_Faculty :: setValue(int a, float b) {
    serviceYear = a;
    basicPay = b;
}

class Visiting_Faculty : public Faculty {
    protected:
        int perHourRate;
        int hoursTaught;
    public:
    void setValue(int, int);
        float salary(void) override {
            return (perHourRate * hoursTaught);
        }
};

void Visiting_Faculty :: setValue(int a, int b) {
    perHourRate = a;
    hoursTaught = b;
}

int main() {
    const int MAX = 5;
    Faculty* facultyArray[MAX];
    int choice, count = 0;

    while (count < MAX) {
        cout << "Enter 1 to add Permanent Faculty or 2 to add Visiting Faculty (0 to exit): ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            facultyArray[count] = new Permanent_Faculty;

            string name;
            int id, years;
            float basicPay;

            cout << "Enter data for Permanent Faculty:" << endl;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter years of service: ";
            cin >> years;
            cout << "Enter basic pay: ";
            cin >> basicPay;

            facultyArray[count]->setData(name, id); // Установить общие данные
            static_cast<Permanent_Faculty*>(facultyArray[count])->setValue(years, basicPay);
        } 
        else if (choice == 2) {
            facultyArray[count] = new Visiting_Faculty;

            string name;
            int id, perHourRate, hoursTaught;

            cout << "Enter data for Visiting Faculty:" << endl;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter per hour rate: ";
            cin >> perHourRate;
            cout << "Enter number of hours taught: ";
            cin >> hoursTaught;

            facultyArray[count]->setData(name, id); // Установить общие данные
            static_cast<Visiting_Faculty*>(facultyArray[count])->setValue(perHourRate, hoursTaught);
        } 
        else {
            cout << "Invalid choice. Try again.\n";
            continue;
        }
        count++;
    }

    cout << "\nFaculty Data and Salaries:\n";
    for (int i = 0; i < count; i++) {
        facultyArray[i]->printData();
        cout << "Salary: " << facultyArray[i]->salary() << endl;
    }

    for (int i = 0; i < count; i++) {
        delete facultyArray[i];
    }

    return 0;
}