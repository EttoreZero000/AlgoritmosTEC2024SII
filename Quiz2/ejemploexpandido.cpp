#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

// Clase Estudiante
class Estudiante {
public:
    int nota;
    int tamaño;
    int años;

    Estudiante(int n, int t, int a) : nota(n), tamaño(t), años(a) {}

    // Método para imprimir el objeto Estudiante
    void print() const {
        std::cout << "Nota: " << nota << ", Tamaño: " << tamaño << ", Años: " << años << "\n";
    }
};

// Función de comparación personalizada para ordenar
bool comparar(const Estudiante& e1, const Estudiante& e2) {
    if (e1.nota != e2.nota)
        return e1.nota < e2.nota;   // Ordenar por nota
    else if (e1.tamaño != e2.tamaño)
        return e1.tamaño < e2.tamaño;  // Si las notas son iguales, ordenar por tamaño
    else
        return e1.años < e2.años;   // Si las notas y tamaños son iguales, ordenar por años
}

// HeapSort
void heapify(std::vector<Estudiante>& arr, int n, int i, const std::function<bool(const Estudiante&, const Estudiante&)>& comp) {
    int largest = i; // Inicializar el nodo más grande como raíz
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && comp(arr[largest], arr[left]))
        largest = left;

    if (right < n && comp(arr[largest], arr[right]))
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comp);
    }
}

void heapSort(std::vector<Estudiante>& arr, int n, const std::function<bool(const Estudiante&, const Estudiante&)>& comp) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comp);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, comp);
    }
}

// InsertionSort
void insertionSort(std::vector<Estudiante>& arr, int left, int right, const std::function<bool(const Estudiante&, const Estudiante&)>& comp) {
    for (int i = left + 1; i <= right; i++) {
        Estudiante key = arr[i];
        int j = i - 1;

        while (j >= left && comp(key, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// QuickSort
int partition(std::vector<Estudiante>& arr, int low, int high, const std::function<bool(const Estudiante&, const Estudiante&)>& comp) {
    Estudiante pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (comp(arr[j], pivot)) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<Estudiante>& arr, int low, int high, int depthLimit, const std::function<bool(const Estudiante&, const Estudiante&)>& comp) {
    if (low < high) {
        if (depthLimit == 0) {
            heapSort(arr, high - low + 1, comp);
        } else {
            int pivot = partition(arr, low, high, comp);
            quickSort(arr, low, pivot - 1, depthLimit - 1, comp);
            quickSort(arr, pivot + 1, high, depthLimit - 1, comp);
        }
    }
}

// IntroSort
void introSort(std::vector<Estudiante>& arr, int n, const std::function<bool(const Estudiante&, const Estudiante&)>& comp) {
    int depthLimit = 2 * log(n);
    quickSort(arr, 0, n - 1, depthLimit, comp);
    insertionSort(arr, 0, n - 1, comp);
}

int main() {
    // Crear una lista de objetos Estudiante
    std::vector<Estudiante> estudiantes = {
        Estudiante(85, 170, 20),
        Estudiante(90, 175, 22),
        Estudiante(85, 170, 18),
        Estudiante(85, 160, 21),
        Estudiante(90, 175, 21)
    };

    std::cout << "Lista original:\n";
    for (const auto& est : estudiantes)
        est.print();

    // Ordenar los estudiantes utilizando la función comparar
    introSort(estudiantes, estudiantes.size(), comparar);

    std::cout << "\nLista ordenada:\n";
    for (const auto& est : estudiantes)
        est.print();

    return 0;
}
