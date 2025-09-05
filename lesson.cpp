#include <numeric>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <map>
#include <iomanip>
#include <cassert>
#include <set>
#include <chrono>
#include <fstream>
#include <ctime>
#include <bitset>

void decode(std::string enc, int step) {
    std::string result;

    for(char c : enc) {
        if(isalpha(c)) {
            if(isupper(c)) {
                char chr = (char)('A' + (c - 'A' + step) % 26);
                result.push_back(chr);
            }
            if(islower(c)) {
                char chr = (char)('a' + (c - 'a' + step) % 26);
                result.push_back(chr);
            }
        } else {
            result.push_back(c);
        }
    }
    std::cout << result << std::endl;
}

int main()
{
    int n = 1;

    while(n < 26) {
        decode("ISDQ{gdkkn_vnqkc}", n);
        n++;
    }


    return 0;
}