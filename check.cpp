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

std::string caesarEncrypt(const std::string& text, int shift) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((((c - base) + shift) % 26 + 26) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

std::string caesarDecrypt(const std::string& text, int shift) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((((c - base) - shift) % 26 + 26) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

void saveEncryptedPassword(const std::string& encrypted) {
    constexpr const char* VAULT_FILE = "vault.txt";
    std::ofstream out(VAULT_FILE, std::ios::app);
    if (!out) {
        std::cerr << "Не удалось открыть файл для записи.\n";
        return;
    }

    auto current_time = std::chrono::system_clock::now();
    std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_time);

    std::tm now_tm{};

#ifdef _WIN32
    localtime_s(&now_tm, &current_time_t);
#else
    localtime_r(&current_time_t, &now_tm);
#endif

    out << "\n[ " << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " ]" << " Saved " << encrypted << std::endl;
    out.close();
}

void encryptAndSave(const std::string& text, int shift) {
    std::string encrypted = caesarEncrypt(text, shift);
    saveEncryptedPassword(encrypted);
}

int main(int argc, char *argv[]) {

    std::string filename;
    std::string key;
    std::string text;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.find("--file=") == 0) {
            filename = arg.substr(7);
        } else if (arg.find("--key=") == 0) {
            key = arg.substr(6);
        } else {
            std::cerr << "Неизвестный аргумент: " << arg << std::endl;
        }
    }

    if (filename.empty()) {
        std::cerr << "Ошибка: аргумент --file не указан.\n";
        return 1;
    }

    if (key.empty()) {
        std::cerr << "Ошибка: аргумент --key не указан.\n";
        return 1;
    }

    std::cout << "Файл: " << filename << std::endl;
    std::cout << "Ключ: " << key << std::endl;

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 1;
    }

    std::string line;
    int shift = std::stoi(key);

    while (std::getline(inFile, line)) {
        encryptAndSave(line, shift);
    }

    return 0;
}