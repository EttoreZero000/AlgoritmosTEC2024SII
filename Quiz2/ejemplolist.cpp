#include <iostream>
#include <list>  // Cambiado a list
#include <algorithm>

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

int main() {
    // Crear una lista de objetos Estudiante
    std::list<Estudiante> estudiantes = {
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
    estudiantes.sort(comparar);  // Cambiado a list.sort()

    std::cout << "\nLista ordenada:\n";
    for (const auto& est : estudiantes)
        est.print();

    return 0;
}
