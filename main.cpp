#include <iostream>
using namespace std;

int main() {

    int a , b, c;

    cout << "Enter 3 number: ";

    cin >> a >> b >> c;

    if (a == 0 || b == 0 || c == 0) {
        cout << "They couldnt" << endl;
    } else if (a*a + b*b == c*c) {
        cout << "they could be" << endl;
    } else {
        cout << "err" << endl;
    }

    return 0;
}