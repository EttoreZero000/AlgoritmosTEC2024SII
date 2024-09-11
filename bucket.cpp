#include <iostream>
#include <vector>
#include <algorithm>
void insertionSort(std::vector<float>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            --j;
        }
        bucket[j + 1] = key;
    }
}

// Función para realizar el Bucket Sort
void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    if (n <= 0)
        return;

    // Paso 1
    std::vector<std::vector<float>> buckets(n);

    // Paso 2
    for (float value : arr) {
        int bucketIndex = static_cast<int>(value * n); 
        buckets[bucketIndex].push_back(value);
    }

    // Paso 3
    for (auto& bucket : buckets) {
        insertionSort(bucket);
    }

    // Paso 4
    int index = 0;
    for (const auto& bucket : buckets) {
        for (float value : bucket) {
            arr[index++] = value;
        }
    }
}

int main() {
    std::vector<float> arr = {0.78f, 0.17f, 0.39f, 0.26f, 0.72f, 0.94f, 0.21f, 0.12f, 0.23f, 0.68f};

    bucketSort(arr);

    std::cout << "Array ordenado: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
