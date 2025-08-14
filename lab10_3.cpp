#include <iostream>
using namespace std;

const int MAX = 100;

template <class Type>
class Stack {
    private:
        Type st[MAX];
        int top;
    public:
        Stack() { 
            top = -1;
        }

        void push(Type var) {
            st[++top] = var;
        }

        Type pop() {
            return st[top--];
        }

        Type peak() {
            if (top == -1) {
                return -1;
            }
            return st[top];
        }

        bool empty() {
            if (top >= 0) {
                return false;
            }
            return true;
        }
};

int main() {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << boolalpha << "Is empty? before pop: " << s1.empty() << endl;
    cout << "top before pop(if is empty return -1): " << s1.peak() << endl;

    cout << "1: "<< s1.pop() << endl;
    cout << "2: " << s1.pop() << endl;
    cout << "3: " << s1.pop() << endl;
    cout << boolalpha << "Is empty? after pop: " << s1.empty() << endl;
    cout << "top after pop(if is empty return -1): " << s1.peak() << endl;

    Stack<float> s2;
    s2.push(1.1111F);
    s2.push(2.2222F);
    s2.push(3.3333F);
    s2.push(4.4444F);

    cout << boolalpha << "Is empty? before pop: " << s2.empty() << endl;
    cout << "top before pop(if is empty return -1): " << s2.peak() << endl;
    cout << "1: " << s2.pop() << endl;
    cout << "2: " << s2.pop() << endl;
    cout << "3: " << s2.pop() << endl;
    cout << boolalpha << "Is empty? after pop: " << s2.empty() << endl;
    cout << "top after pop(if is empty return -1): " << s2.peak() << endl;

    return 0;
}