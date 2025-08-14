#include <iostream>
#include <fstream>
using namespace std;

class Student {
    private:
        int age;
        int marks;
    public:
        class InvalidRange {
            private:
                string reason;
                string funcName;
                int invalidValue;
            public:
                InvalidRange(string r, string n, int i) : reason(r), funcName(n), invalidValue(i) {};

                string getFuncName() {
                    return funcName;
                }
                int getInvaildValue() {
                    return invalidValue;
                }

                void display() { cout << "Error: " << reason 
                                      << "\nFunction name: " << getFuncName() 
                                      << "\nInvalid value: " << getInvaildValue() << endl; }
        };

        void setData(int a, int m) {
            if(a < 15 || a > 40) {
                throw InvalidRange("Age must be between 15 and 40", "SetData", a);
            }
            if(m < 0 || m > 100) {
                throw InvalidRange("Marks must be between 0 and 100", "SetData", m);
            }
            age = a;
            marks = m;
        }

        Student(int a, int m) { setData(a, m); }
};

int main() {

    try {
        Student s1(15, 44);

    } catch(Student::InvalidRange& e) {
        cout << "Student 1" << endl;
        e.display();
    }

    try {
        Student s2(14, 66);

    } catch(Student::InvalidRange& e) {
        cout << "Student 2" << endl;
        e.display();
    }
    
    return 0;
}