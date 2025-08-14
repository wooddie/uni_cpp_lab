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

int persistence(long long n)
{
    int count = 0;

    while (n >= 10)
    {
        long long product = 1;
        while (n > 0)
        {
            product *= n % 10;
            n /= 10;
        }
        n = product;
        count++;
    }

    return count;
}

int main()
{
    std::cout << persistence(39);
    assert(persistence(39) == (3));
    assert(persistence(4) == (0));
    assert(persistence(25) == (2));
    assert(persistence(999) == (4));
    assert(persistence(444) == (3));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}