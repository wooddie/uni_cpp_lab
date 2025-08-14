#include <iostream>
using namespace std;

class Exam {
    protected:
        string date;
        string time;
        int duration;
        string title;
    public:
        Exam() : date(" "), time(" "), duration(0), title(" ") {};
        Exam(string, string, int, string);
        string getDate();
        string getTime();
        int getDuration();
        string getTitle();
};

Exam :: Exam(string d, string t, int du, string ti) : date(d), time(t), duration(du), title(ti) {};

string Exam :: getDate() {
    return date;
}

string Exam :: getTime() {
    return time;
}

int Exam :: getDuration() {
    return duration;
}

string Exam :: getTitle() {
    return title;
}

class Theory : public Exam {
    protected:
        string teacherName;
    public:
        Theory() : Exam(), teacherName(" ") {};
        Theory(string, string, int, string, string);
        string getTeacherName();
        int theoryAmount();
        void theoryDisplay();
};

Theory :: Theory(string d, string t, int du, string ti, string n) : Exam(d, t, du, ti), teacherName(n) {};

string Theory :: getTeacherName() {
    return teacherName;
}

int Theory :: theoryAmount() {
    return 20 * getDuration();
}

void Theory :: theoryDisplay() {
    cout << "Date: " << getDate() << "; Time: " << getTime() << "; Duration: " << getDuration() << "; Title: " << getTitle()
    << "; Teacher name: " << getTeacherName() << "." << endl;
}

class Practical : public Exam {
    protected:
        string assistantName;
        int laboratoryNumber;
    public:
        Practical() : Exam(), assistantName(" "), laboratoryNumber(0) {};
        Practical(string, string, int, string, string, int);
        string getAssistantName();
        int getLaboratoryNumber();
        int practicalAmount();
        void practicalDisplay();
};

Practical :: Practical(string d, string t, int du, string ti, string a, int l) : Exam(d, t, du, ti), assistantName(a), laboratoryNumber(l) {};

string Practical :: getAssistantName() {
    return assistantName;
}

int Practical :: getLaboratoryNumber() {
    return laboratoryNumber;
}

int Practical :: practicalAmount() {
    return 10 * getDuration();
}

void Practical :: practicalDisplay() {
    cout << "Date: " << getDate() << "; Time: " << getTime() << "; Duration: " << getDuration() << "; Title: " << getTitle()
    << "; Lab number: " << getLaboratoryNumber() << "; Assistant name: " << getAssistantName() << "." << endl;
}

int main() {

    Theory t1 ("21 march", "2 pm", 3, "History", "John");
    t1.theoryDisplay();
    cout << "Theory amount: " << t1.theoryAmount() << endl;

    Practical p1 ("22 march", "3 pm", 4, "math", "Dave", 202);
    p1.practicalDisplay();
    cout << "Pracatical amount: " << p1.practicalAmount() << endl;

    return 0;
}