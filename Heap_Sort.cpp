#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <limits>
#include <map>

#include <iostream>
#include <vector>

using namespace std;

// Функция heapify для преобразования в max-кучу
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Корень
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый потомок больше, чем текущий наибольший
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если самый большой элемент — не корень, меняем местами
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Рекурсивно heapify для поддерева
    }
}

// Функция heapSort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Строим max-кучу (перестраиваем массив)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Извлекаем элементы из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Перемещаем корень (максимум) в конец
        heapify(arr, i, 0); // Восстанавливаем max-кучу на оставшейся части
    }
}

// Вывод массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 5, 2, 8, 7, 3, 1, 4, 6, 9};
    
    cout << "Before sorting: ";
    printArray(arr);

    heapSort(arr);

    cout << "After Heap Sort: ";
    printArray(arr);

    return 0;
}