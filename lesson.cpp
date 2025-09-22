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
    double hour_in_minute = 0.0;
    std::cout << "Введите временной интервал (в минутах): ";
    std::cin >> hour_in_minute;

    int hours = hour_in_minute / 60;

    double minutes = fmod(hour_in_minute / 60, 1.0);

    std::cout << hour_in_minute << " минут = " << hours << " ч. " << std::ceil(60 * minutes) << " мин." << std::endl;

    return 0;
}