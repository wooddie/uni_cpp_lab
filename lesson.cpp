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
    std::cout << "Введите цену 1 кг яблок: ";
    double price = 0;
    std::cin >> price;

    std::cout << "Вес       Стоимость" << std::endl;
    double weight = 100.0;

    while (weight <= 1000)
    {
        double newPrice = (price / 1000) * weight;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << weight << "      " << newPrice << std::endl;
        weight += 100;
    }

    return 0;
}