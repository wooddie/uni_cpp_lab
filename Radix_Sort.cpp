#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для сортировки массива по заданному разряду
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); 
    int count[10] = {0};

    // Подсчитываем количество чисел по текущему разряду
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Изменяем count[i], чтобы он содержал позицию числа в output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Строим отсортированный массив
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Копируем обратно в исходный массив
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Функция Radix Sort
void radixSort(vector<int>& arr) {
    // Находим максимальное число, чтобы определить число разрядов
    int maxNum = *max_element(arr.begin(), arr.end());

    // Применяем counting sort для каждого разряда (1, 10, 100, ...)
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Функция вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Before sorting: ";
    printArray(arr);

    radixSort(arr);

    cout << "After Radix Sort: ";
    printArray(arr);

    return 0;
}