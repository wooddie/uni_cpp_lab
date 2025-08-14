#include <iostream>

using namespace std;

class Emplayee {
private:
    int numberEmplayee;
    float compensation;

public:
    Emplayee() : numberEmplayee(0), compensation(0) {}
    Emplayee(int n, float c) : numberEmplayee(n), compensation(c) {}

    void getInf() {
        cout << "Enter number of employee and compensation: ";
        cin >> numberEmplayee >> compensation;
    }

    void displayInf() {
        cout << "Employee number: " << numberEmplayee << "; Compensation: " << compensation << endl;
    }
};

int main() {
    int numEmployees;

    cout << "Enter the number of employee: ";
    cin >> numEmployees;

    vector <Emplayee> employees(numEmployees);

    for (int i = 0; i < numEmployees; ++i) {
        employees[i].getInf();
    }

    for (int i = 0; i < numEmployees; ++i) {
        employees[i].displayInf();
    }

    return 0;
}