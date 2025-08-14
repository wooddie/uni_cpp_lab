#include <iostream>
#include <vector>
#include <algorithm>  
#include <chrono>     

using namespace std;
using namespace chrono;

void bubble(vector<int>& v) {
    int n = v.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

vector<int> insertion(vector<int> v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && v[j - 1] > v[j]; j--) {
            swap(v[j - 1], v[j]);
        }
    }
    return v;
}

vector<int> selection(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }
    return v;
}

vector<int> mergeSort(vector<int> v) {
    if (v.size() <= 1) return v;
    
    int mid = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> merged;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i++]);
        } else {
            merged.push_back(right[j++]);
        }
    }

    while (i < left.size()) merged.push_back(left[i++]);
    while (j < right.size()) merged.push_back(right[j++]);

    return merged;
}

vector<int> quicksort(vector<int> v) {
    if (v.size() <= 1) return v;

    int pivot = v[v.size() / 2];
    vector<int> left, middle, right;

    for (int n : v) {
        if (n < pivot) {
            left.push_back(n);
        } else if (n > pivot) {
            right.push_back(n);
        } else {
            middle.push_back(n);
        }
    }
    
    left = quicksort(left);
    right = quicksort(right);

    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

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
vector<int> heapSort(vector<int> arr) {
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

    return arr;
}

void printArray(const vector<int>& v, const string& sortName, int limit = 10) {
    cout << sortName << ": ";
    for (int i = 0; i < min((int)v.size(), limit); i++) {
        cout << v[i] << " ";
    }
    if (v.size() > limit) cout << "...";
    cout << endl;
}

int main() {
    vector<int> arr = {10, 5, 2, 8, 7, 3, 1, 4, 6, 9};

    vector<int> tempArr = arr;
    bubble(tempArr);
    printArray(tempArr, "Bubble Sort");

    printArray(selection(arr), "Selection Sort");
    printArray(insertion(arr), "Insertion Sort");
    printArray(mergeSort(arr), "Merge Sort");
    printArray(quicksort(arr), "Quick Sort");
    printArray(heapSort(arr), "Heap sort");

    sort(arr.begin(), arr.end());
    printArray(arr, "std::sort");

    const int SIZE = 100000;
    vector<int> arr_test(SIZE);
    for (int& num : arr_test) num = rand() % 1000000;

    auto measureTime = [](auto sortingFunc, vector<int> data, const string& name) {
        vector<int> temp = data;
        auto start = high_resolution_clock::now();
        sortingFunc(data);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << name << " Time: " << duration.count() << " ms\n";
    };

    measureTime(bubble, arr_test, "Bubble Sort");
    measureTime(selection, arr_test, "Selection Sort");
    measureTime(insertion, arr_test, "Insertion Sort");
    measureTime(mergeSort, arr_test, "Merge Sort");
    measureTime(quicksort, arr_test, "Quick Sort");
    measureTime(heapSort, arr_test, "Heap Sort");

    auto start = high_resolution_clock::now();
    sort(arr_test.begin(), arr_test.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "std::sort Time: " << duration.count() << " ms\n";

    return 0;
}