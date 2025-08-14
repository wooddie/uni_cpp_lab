#include <iostream>
using namespace std;

class Person {
    protected:
        string name;
    public:
        Person() : name(" ") {};
        Person(string);
        string get_name();
};

Person :: Person(string firstN) : name(firstN) {}

string Person :: get_name() {
    return name;
}

class Employee : public Person {
    protected:
        double salary;
        int year;
        string insurance;
    public:
        Employee() : Person(), salary(0.0), year(0), insurance(" ") {};
        Employee(string, double, int, string);
        void display();
};

Employee :: Employee(string n, double s, int y, string i) : Person(n), salary(s), year(y), insurance(i) {};

void Employee :: display() {
    cout << "Name: " << get_name() << ", salary: " << salary << ", year: " << year << ", insurance: " << insurance << endl;
}

int main() {
    Person p1("John");
    Employee e1(p1.get_name(), 2.555, 2012, "AB123456C");

    e1.display();

    return 0;
}