#include <iostream>
using namespace std;

class Time {
    private:
        int hour;
        int minute;
        int second;
    public:
        Time() : hour(0), minute(0), second(0) {};
        Time(int h, int m, int s) { hour = h, minute = m, second = s; };
        bool operator==(Time);
        bool operator>(Time);
        bool operator<(Time);
        Time& operator++();
        Time operator++(int);
        void Show_Time();
};

bool Time :: operator==(Time a) {
    if(hour == a.hour && minute == a.minute && second == a.second) {
        return true;
    }
    return false;
}

bool Time :: operator>(Time a) {
    if(hour > a.hour) {
        return true;
    } if(hour == a.hour && minute > a.minute) {
        return true;
    } if(hour == a.hour && minute == a.minute && second > a.second) {
        return true;
    }
    return false;
}

bool Time :: operator<(Time a) {
    if(hour < a.hour) {
        return true;
    } if(hour == a.hour && minute < a.minute) {
        return true;
    } if(hour == a.hour && minute == a.minute && second < a.second) {
        return true;
    }
    return false;
}

Time& Time :: operator++() {
    ++second;
    if (second >= 60) {
        second = 0;
        ++minute;

        if (minute >= 60) {
            minute = 0;
            ++hour;

            if (hour >= 24) {
                hour = 0;
            }
        }
    }
    return *this;
}

Time Time :: operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

void Time :: Show_Time() {
    cout << hour << ":" << minute << ":" << second << endl;
}

int main() {
    Time t1(12, 59, 59);
    Time t2(23, 59, 59);

    t1.Show_Time();
    t2.Show_Time();

    cout << "t1 == t2:" << endl;
    if (t1 == t2) {
        cout << boolalpha << true << endl;
    } else {
        cout << boolalpha << false << endl;
    }

    cout << "t1 > t2:" << endl;
    if (t1 > t2) {
        cout << boolalpha << true << endl;
    } else {
        cout << boolalpha << false << endl;
    }
    
    cout << "t1 < t2:" << endl;
    if (t1 < t2) {
        cout << boolalpha << true << endl;
    } else {
        cout << boolalpha << false << endl;
    }

    cout << "t1++:" << endl;
    t1++;
    t1.Show_Time();

    cout << "++t2:" << endl;
    ++t2;
    t2.Show_Time();

    return 0;
}