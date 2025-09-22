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
    std::string line1;
    std::vector<int> vec1;
    std::string line2;
    std::vector<int> vec2;

    std::cout << "Введите элементы первого массива: ";
    std::getline(std::cin, line1);

    std::istringstream iss1(line1);
    double num1;
    while (iss1 >> num1)
    {
        vec1.push_back(num1);
    }

    std::cout << "Введите элементы второго массива: ";
    std::getline(std::cin, line2);

    std::istringstream iss2(line2);
    double num2;
    while (iss2 >> num2)
    {
        vec2.push_back(num2);
    }

    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    std::sort(vec1.begin(), vec1.end());

    std::string result;

    for (auto n : vec1)
    {
        result += std::to_string(n) + " ";
    }

    std::cout << "Массив-результат: " << result << std::endl;

    return 0;
}