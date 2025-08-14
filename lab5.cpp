#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
 
int main() {

    string line;
 
    ifstream in("lab5.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();

    return 0;
}