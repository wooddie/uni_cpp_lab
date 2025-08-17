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

long long countOnesUpTo (long long n)
{
    if (n == 0)
        return 0;

    long long pos = 0;
    long long temp = n;
    while (temp > 1)
    {
        temp >>= 1;
        pos++;
    }

    long long result = pos * (1LL << (pos - 1));
    long long remaining = n - (1LL << pos);

    result += (remaining + 1);
    result += countOnesUpTo(remaining);

    return result;
};

long long countOnes(int left, int right)
{
    return countOnesUpTo(right) - countOnesUpTo(left - 1);
}

int main()
{
    std::cout << countOnes(4, 7) << std::endl;
    assert(countOnes(4, 7) == (8));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}