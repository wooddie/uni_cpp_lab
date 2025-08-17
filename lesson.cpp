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

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

std::string solve(int a, int b)
{
    std::string prime_num;
    int n = 2;

    while (prime_num.size() < a + b)
    {
        if (isPrime(n))
        {
            prime_num += std::to_string(n);
        }
        n++;
    }

    return prime_num.substr(a, b);
}

void doTest(int a, int b, const std::string &expected)
{
    assert(solve(a, b) == (expected));
}

int main()
{
    doTest(2, 2, "57");
    doTest(10, 3, "192");
    doTest(20, 9, "414347535");
    doTest(30, 12, "616771737983");
    doTest(40, 8, "83899710");
    doTest(50, 6, "031071");
    doTest(10000, 5, "02192");
    doTest(20000, 5, "09334");

    std::cout << "All tests passed!" << std::endl;

    return 0;
}