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

int main()
{
    std::unordered_map<char, char> list = {
        {'O', 'A'}, {'H', 'B'}, {'N', 'C'}, {'F', 'D'}, {'U', 'E'}, {'M', 'F'}, {'W', 'G'}, 
        {'S', 'H'}, {'V', 'I'}, {'Z', 'J'}, {'L', 'K'}, {'X', 'L'}, {'E', 'M'}, {'G', 'N'}, 
        {'C', 'O'}, {'P', 'P'}, {'T', 'Q'}, {'A', 'R'}, {'J', 'S'}, {'D', 'T'}, {'Y', 'U'}, 
        {'I', 'V'}, {'R', 'W'}, {'K', 'X'}, {'Q', 'Y'}, {'B', 'Z'}
    };

    std::string str = "pvncNDM{5YH5717Y710G_3I0XY710G_03055505}";
    std::string result;

    for (char c : str) {
        char chr = toupper(c);
        if (list.count(chr)) {
            result += list[chr];
        } else {
            result += c;
        }
    }

    std::cout << result << std::endl;

    return 0;
}