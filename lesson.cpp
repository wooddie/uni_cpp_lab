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
    float n = 0;

    std::cout << "Введите расстояние в верстах: ";
    std::cin >> n;


    std::cout << n << " верст = " << n * 1.0668 << std::endl;

    return 0;
}