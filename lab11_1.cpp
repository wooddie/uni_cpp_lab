#include <iostream>
#include <fstream>
using namespace std;

class Tab {
    private:
        string name;
        int age;
    public:
        Tab() : name(""), age(0) {};
        Tab(string, int);
        void create();
};

Tab :: Tab(string n, int a) : name(n), age(a) {};

void Tab :: create() {
    fstream tab;

    tab.open("tab.csv", ios::out | ios::app);

    cout << "Enrer Name and Age:" << endl;

    for(int i = 0; i < 2; i++) {
        cout << "User" << i+1 << endl;
        cin >> name >> age;

        tab << name << "\t" << age << endl;
    }
}

int main() {

    Tab t1;
    t1.create();

    return 0;
}