#include <iostream>
using namespace std;

int numberCalls;
double rateCalls;
int meterCharges;
double telephoneBill;

void countBill() {
    if (numberCalls <= 100) {
        rateCalls = 0.80;
        meterCharges = 250;

        telephoneBill = meterCharges + (numberCalls * rateCalls);
        cout << "Счёт за телефон: " << telephoneBill << endl;
    } else {
        rateCalls = 1.00;
        meterCharges = 350;

        telephoneBill = meterCharges + (numberCalls * rateCalls);
        cout << "Счёт за телефон: " << telephoneBill << endl;
    }
}

int main() {

    cout << "Введите количество звонков: ";
    cin >> numberCalls;

    countBill();

    return 0;
}