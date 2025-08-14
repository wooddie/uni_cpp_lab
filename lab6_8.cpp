#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class MyString {
private:
    string mystr;

public:
    MyString() : mystr("") {}

    void setString(const string& str) { 
        mystr = str;
    }

    void CountConsonants() {
        int count = 0;
        for (char c : mystr) {
            c = tolower(c);
            if (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l' 
            || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w' 
            || c == 'x' || c == 'y' || c == 'z') {
                count++;
            }
        }
        cout << "Total consonants in the string: " << count << endl;
    }

    void VowelCount() {
        int count = 0;
        for (char c : mystr) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
                count++;
            }
        }
        cout << "Total vowels in the string: " << count << endl;
    }

    void Palindrome() {
        string str1 = mystr;
        reverse(str1.begin(), str1.end());

        if (str1 == mystr) {
            cout << "The string is a palindrome!" << endl;
        } else {
            cout << "The string is NOT a palindrome!" << endl;
        }
    }
};

int main() {
    MyString *str = new MyString();

    string mystr;
    cout << "Enter the string:";
    cin >> mystr;

    str->setString(mystr);
    str->VowelCount();
    str->CountConsonants();
    str->Palindrome();

    delete str;

    return 0;
}