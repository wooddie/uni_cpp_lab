#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollno;
    string name;
    int marks[3];
};

void printFailedStudents(Student student[], int size);

int main() {
    const int studentCount = 10;
    Student students[studentCount];

    for (int i = 0; i < studentCount; i++) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Roll No: ";
        cin >> students[i].rollno;
        cin.ignore();
        cout << "Name: ";
        getline(cin, students[i].name);
        for (int j = 0; j < 3; j++) {
            cout << "Marks in subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
        }
    }

    printFailedStudents(students, studentCount);

    return 0;
}

void printFailedStudents(Student students[], int size) {
    cout << "Students who failed in more than one subject:" << endl;
    for (int i = 0; i < size; i++) {
        int failCount = 0;
        for (int j = 0; j < 3; j++) {
            if (students[i].marks[j] < 50) {
                failCount++;
            }
        }
        if (failCount > 1) {
            cout << "Roll No: " << students[i].rollno << ", Name: " << students[i].name << endl;
        }
    }
}