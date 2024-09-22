#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Funciones auxiliares
void printListaay(const std::vector<int>& lista) {
    for (int num : lista)
        std::cout << num << " ";
    std::cout << std::endl;
}

// Selection Sort
void selectionSort(std::vector<int>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(lista[i], lista[minIdx]);
    }
}

// Bubble Sort
void bubbleSort(std::vector<int>& lista) {
    int n = lista.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                std::swap(lista[j], lista[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Insertion Sort
void insertionSort(std::vector<int>& lista) {
    int n = lista.size();
    for (int i = 1; i < n; i++) {
        int key = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > key) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = key;
    }
}

// Heap Sort
void heapify(std::vector<int>& lista, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && lista[left] > lista[largest])
        largest = left;
    if (right < n && lista[right] > lista[largest])
        largest = right;
    if (largest != i) {
        std::swap(lista[i], lista[largest]);
        heapify(lista, n, largest);
    }
}

void heapSort(std::vector<int>& lista) {
    int n = lista.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(lista, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(lista[0], lista[i]);
        heapify(lista, i, 0);
    }
}

// Quick Sort
int partition(std::vector<int>& lista, int low, int high) {
    int pivot = lista[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (lista[j] < pivot) {
            i++;
            std::swap(lista[i], lista[j]);
        }
    }
    std::swap(lista[i + 1], lista[high]);
    return i + 1;
}

void quickSort(std::vector<int>& lista, int low, int high) {
    if (low < high) {
        int pi = partition(lista, low, high);
        quickSort(lista, low, pi - 1);
        quickSort(lista, pi + 1, high);
    }
}

// Merge Sort
void merge(std::vector<int>& lista, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = lista[left + i];
    for (int j = 0; j < n2; j++) R[j] = lista[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) lista[k++] = L[i++];
        else lista[k++] = R[j++];
    }
    while (i < n1) lista[k++] = L[i++];
    while (j < n2) lista[k++] = R[j++];
}

void mergeSort(std::vector<int>& lista, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(lista, left, mid);
        mergeSort(lista, mid + 1, right);
        merge(lista, left, mid, right);
    }
}

// Bucket Sort
void bucketSort(std::vector<int>& lista, int bucketSize = 5) {
    int minValue = *min_element(lista.begin(), lista.end());
    int maxValue = *max_element(lista.begin(), lista.end());
    
    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    std::vector<std::vector<int>> buckets(bucketCount);
    
    for (int num : lista) {
        int bucketIndex = (num - minValue) / bucketSize;
        buckets[bucketIndex].push_back(num);
    }
    
    lista.clear();
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for (int num : bucket)
            lista.push_back(num);
    }
}

// Radix Sort
int getMax(const std::vector<int>& lista) {
    return *max_element(lista.begin(), lista.end());
}

void countingSort(std::vector<int>& lista, int exp) {
    int n = lista.size();
    std::vector<int> output(n);
    int count[10] = {0};
    
    for (int i = 0; i < n; i++)
        count[(lista[i] / exp) % 10]++;
    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(lista[i] / exp) % 10] - 1] = lista[i];
        count[(lista[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++)
        lista[i] = output[i];
}

void radixSort(std::vector<int>& lista) {
    int max = getMax(lista);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(lista, exp);
}

// Función principal
int main() {
    std::vector<int> lista = {170, 45, 75, 90, 802, 24, 2, 66};
    
    std::cout << "Original Listaay: ";
    printListaay(lista);

    // Selection Sort
    std::vector<int> lista1 = lista;
    selectionSort(lista1);
    std::cout << "Selection Sort: ";
    printListaay(lista1);

    // Bubble Sort
    std::vector<int> lista2 = lista;
    bubbleSort(lista2);
    std::cout << "Bubble Sort: ";
    printListaay(lista2);

    // Insertion Sort
    std::vector<int> lista3 = lista;
    insertionSort(lista3);
    std::cout << "Insertion Sort: ";
    printListaay(lista3);

    // Heap Sort
    std::vector<int> lista4 = lista;
    heapSort(lista4);
    std::cout << "Heap Sort: ";
    printListaay(lista4);

    // Quick Sort
    std::vector<int> lista5 = lista;
    quickSort(lista5, 0, lista5.size() - 1);
    std::cout << "Quick Sort: ";
    printListaay(lista5);

    // Merge Sort
    std::vector<int> lista6 = lista;
    mergeSort(lista6, 0, lista6.size() - 1);
    std::cout << "Merge Sort: ";
    printListaay(lista6);

    // Bucket Sort
    std::vector<int> lista7 = lista;
    bucketSort(lista7);
    std::cout << "Bucket Sort: ";
    printListaay(lista7);

    // Radix Sort
    std::vector<int> lista8 = lista;
    radixSort(lista8);
    std::cout << "Radix Sort: ";
    printListaay(lista8);

    return 0;
}
