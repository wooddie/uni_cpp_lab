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

int main()
{
    int n = 0;
    std::cout << "Введите количество чисел последовательности: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    std::vector<double> vec;

    while (vec.size() < n)
    {
        std::cout << "Введите последовательность чисел через пробел: ";
        std::getline(std::cin, line);

        std::istringstream iss(line);
        double num;
        while (iss >> num)
        {
            vec.push_back(num);
        }
    }

    if (vec.size() > n)
    {
        vec.resize(n);
    }

    double sum = 0;
    for (double n : vec)
    {
        sum += n;
    }

    double min_value = *std::min_element(vec.begin(), vec.end());
    double max_value = *std::max_element(vec.begin(), vec.end());

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Среднее арифметическое: " << sum / vec.size() << std::endl;
    std::cout << "Минимальное число: " << min_value << std::endl;
    std::cout << "Максимальное число: " << max_value << std::endl;

    return 0;
}