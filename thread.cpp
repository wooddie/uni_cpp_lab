#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
using namespace std;

void sortList(vector<int>& list);
void merge(vector<int>& l1, vector<int>& l2);

int main() {
    vector<int> original_list{7, 12, 19, 3, 18, 4, 2, 6, 15, 8};
    vector<int> list_one;
    vector<int> list_two;

    for (int i = 0; i < original_list.size(); i++) {
        if (original_list[i] < 10) {
            list_one.push_back(original_list[i]);
        } else {
            list_two.push_back(original_list[i]);
        }
    }

    thread t1(sortList, ref(list_one));
    thread t2(sortList, ref(list_two));

    t1.join();
    t2.join();

    cout << "Sorted list 1: " << endl;
    for (int num : list_one) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Sorted list 2: " << endl;
        for (int num : list_two) {
        cout << num << " ";
    }
    cout << endl;

    thread t3([&]() { merge(list_one, list_two); });

    t3.join();

    cout << "Sorted List:" << endl;
    for (int num : list_one) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

void sortList(vector<int>& list) {
    sort(list.begin(), list.end());
}

void merge(vector<int>& l1, vector<int>& l2) {
    l1.insert(l1.end(), l2.begin(), l2.end());
}