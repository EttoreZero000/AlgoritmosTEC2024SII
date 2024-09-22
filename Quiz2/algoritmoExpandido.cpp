#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Funciones auxiliares
void printLista(const std::vector<int>& lista) {
    for (int num : lista)
        std::cout << num << " ";
    std::cout << std::endl;
}

// Función para el comparador
template <typename T>
bool comparadorAscendente(const T& a, const T& b) {
    return a < b;  // Comparador en orden ascendente
}

// Selection Sort
void selectionSort(std::vector<int>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[minIndex])
                minIndex = j;
        }
        std::swap(lista[i], lista[minIndex]);
    }
}

// Bubble Sort
void bubbleSort(std::vector<int>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1])
                std::swap(lista[j], lista[j + 1]);
        }
    }
}

// Insertion Sort
template <typename T, typename Compare>
void insertionSort(std::vector<T>& lista, int left, int right, Compare comp) {
    for (int i = left + 1; i <= right; i++) {
        T key = lista[i];
        int j = i - 1;
        while (j >= left && comp(key, lista[j])) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = key;
    }
}

// Heapify para HeapSort
template <typename T, typename Compare>
void heapify(std::vector<T>& lista, int n, int i, Compare comp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && comp(lista[largest], lista[left]))
        largest = left;
    if (right < n && comp(lista[largest], lista[right]))
        largest = right;
    
    if (largest != i) {
        std::swap(lista[i], lista[largest]);
        heapify(lista, n, largest, comp);
    }
}

// HeapSort
template <typename T, typename Compare>
void heapSort(std::vector<T>& lista, Compare comp) {
    int n = lista.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(lista, n, i, comp);
    for (int i = n - 1; i > 0; i--) {
        std::swap(lista[0], lista[i]);
        heapify(lista, i, 0, comp);
    }
}

// QuickSort
template <typename T, typename Compare>
int partition(std::vector<T>& lista, int low, int high, Compare comp) {
    T pivot = lista[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (comp(lista[j], pivot)) {
            i++;
            std::swap(lista[i], lista[j]);
        }
    }
    std::swap(lista[i + 1], lista[high]);
    return i + 1;
}

template <typename T, typename Compare>
void quickSort(std::vector<T>& lista, int low, int high, Compare comp) {
    if (low < high) {
        int pi = partition(lista, low, high, comp);
        quickSort(lista, low, pi - 1, comp);
        quickSort(lista, pi + 1, high, comp);
    }
}

// MergeSort
template <typename T>
void merge(std::vector<T>& lista, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = lista[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = lista[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            lista[k++] = L[i++];
        else
            lista[k++] = R[j++];
    }

    while (i < n1)
        lista[k++] = L[i++];
    while (j < n2)
        lista[k++] = R[j++];
}

template <typename T>
void mergeSort(std::vector<T>& lista, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(lista, left, mid);
        mergeSort(lista, mid + 1, right);
        merge(lista, left, mid, right);
    }
}

// BucketSort
void bucketSort(std::vector<int>& lista) {
    int max = *max_element(lista.begin(), lista.end());
    int min = *min_element(lista.begin(), lista.end());
    int bucketCount = max - min + 1;
    std::vector<std::vector<int>> buckets(bucketCount);

    for (int num : lista) {
        buckets[num - min].push_back(num);
    }

    int index = 0;
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            lista[index++] = num;
        }
    }
}

// RadixSort
void countingSortForRadix(std::vector<int>& lista, int exp) {
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
    int max = *max_element(lista.begin(), lista.end());
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortForRadix(lista, exp);
}

// IntroSort
template <typename T, typename Compare>
void introSort(std::vector<T>& lista, Compare comp) {
    int depthLimit = 2 * log(lista.size());

    quickSort(lista, 0, lista.size() - 1, comp);
    insertionSort(lista, 0, lista.size() - 1, comp);
}

int main() {
    std::vector<int> lista = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Lista original: ";
    printLista(lista);

    // Selection Sort
    std::vector<int> lista1 = lista;
    selectionSort(lista1);
    std::cout << "Selection Sort: ";
    printLista(lista1);

    // Bubble Sort
    std::vector<int> lista2 = lista;
    bubbleSort(lista2);
    std::cout << "Bubble Sort: ";
    printLista(lista2);

    // Insertion Sort
    std::vector<int> lista3 = lista;
    insertionSort(lista3, 0, lista3.size() - 1, comparadorAscendente<int>);
    std::cout << "Insertion Sort: ";
    printLista(lista3);

    // Heap Sort
    std::vector<int> lista4 = lista;
    heapSort(lista4, comparadorAscendente<int>);
    std::cout << "Heap Sort: ";
    printLista(lista4);

    // Quick Sort
    std::vector<int> lista5 = lista;
    quickSort(lista5, 0, lista5.size() - 1, comparadorAscendente<int>);
    std::cout << "Quick Sort: ";
    printLista(lista5);

    // Merge Sort
    std::vector<int> lista6 = lista;
    mergeSort(lista6, 0, lista6.size() - 1);
    std::cout << "Merge Sort: ";
    printLista(lista6);

    // Bucket Sort
    std::vector<int> lista7 = lista;
    bucketSort(lista7);
    std::cout << "Bucket Sort: ";
    printLista(lista7);

    // Radix Sort
    std::vector<int> lista8 = lista;
    radixSort(lista8);
    std::cout << "Radix Sort: ";
    printLista(lista8);

    // IntroSort
    std::vector<int> lista9 = lista;
    introSort(lista9, comparadorAscendente<int>);
    std::cout << "Intro Sort: ";
    printLista(lista9);

    return 0;
}
