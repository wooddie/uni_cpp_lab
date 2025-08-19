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

std::string caesarEncrypt(const std::string &text, int shift, const char alphabet[], int alphabetSize)
{
    std::string result;

    for (char c : text)
    {
        int index = -1;

        for (int i = 0; i < alphabetSize; i++)
        {
            if (alphabet[i] == toupper(c))
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            int newIndex = (index - shift + alphabetSize) % alphabetSize;
            result += alphabet[newIndex];
        }
        else
        {
            result += c;
        }
    }

    return result;
}

int main()
{

    const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                             'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);

    int i = 0;
    while (i <= 26) {
        std::cout << i << " try : " << "picoCTF{" << caesarEncrypt("dspttjohuifsvcjdpoabrkttds", i, alphabet, alphabetSize) << "}" << std::endl;
        i++;
    }


    return 0;
}