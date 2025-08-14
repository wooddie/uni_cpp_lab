#include <iostream>
using namespace std;

 class Faculty {
    protected:
        string name;
        int id;
    public:
        void setData(string, int);
        void printData();
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

    Permanent_Faculty p1;
    Visiting_Faculty v1;

    Faculty * f1 = &p1;
    Faculty * f2 = &v1;

    f1->setData("John", 1);
    p1.setValue(2000, 250.50);
    
    f2->setData("Mike", 2);
    v1.setValue(40, 60);

    f1->printData();
    cout << "Permanent_Faculty: " << f1->salary() << endl;

    f2->printData();
    cout << "Visiting_Faculty: " << f2->salary() << endl;

    return 0;
}