#include <iostream>
using namespace std;

template <class Type>
Type findAverage(Type* array, int size) {
    Type sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

template <class Type>
tuple<Type, int, Type, int> minMax(Type* array, int size) {
    Type max = array[0];
    Type min = array[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
        if (array[i] < min) {
            min = array[i];
            minIndex = i;
        }
    }
    return make_tuple(max, maxIndex, min, minIndex);
}

int main() {

    int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float floatArr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    cout << "Integer Average: " << findAverage(intArr, 10) << endl;
    cout << "FLoat Average: " << findAverage(floatArr, 10) << endl;

    auto integerRes = minMax(intArr, 10);
    auto floatRes = minMax(floatArr, 10);

    cout << "Integer: Max - " << get<0>(integerRes) 
         << "; Index - " << get<1>(integerRes) 
         << "/ Min - " << get<2>(integerRes) 
         << "; Index - " << get<3>(integerRes) << endl;
    
    cout << "Float: Max - " << get<0>(floatRes) 
         << "; Index - " << get<1>(floatRes)
         << "/ Min - " << get<2>(floatRes)
         << "; Index - " << get<3>(floatRes) << endl;

    return 0;
}