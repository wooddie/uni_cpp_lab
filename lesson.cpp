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
#include <sstream>
#include <limits>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {

        size_t pos = haystack.find(needle);

        if (pos != std::string::npos)
        {
            return pos;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution s1;
    std::string haystack = "sadbutsad";
    std::string needle = "sad";
    int r = s1.strStr(haystack, needle);
    std::cout << r << std::endl;

    haystack = "leetcode";
    needle = "leeto";
    r = s1.strStr(haystack, needle);
    std::cout << r << std::endl;

    return 0;
}