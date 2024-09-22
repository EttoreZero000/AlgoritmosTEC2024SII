//Creado por Hector Leiva Gamboa
//Version g++.exe (Rev3, Built by MSYS2 project) 13.2.0
//Fecha de creacion 19/09/2024
//Creado en Visual Studio Code

#include <iostream> //Imprimir
#include <vector> //Crear lista vectores
#include <string> //Crear atributos
#include <algorithm> //Me orgia
#include <stdexcept> // Para lanzar excepciones
#include "clase.h" //Clase

// Funcion para ordenarlos de todo es mi favorita.
bool comparadorAscendente(const Veterinaria& a, const Veterinaria& b) {
    if (a.getEspecie() == b.getEspecie()) {
        return a.getID() < b.getID();
    }
    return a.getEspecie() < b.getEspecie();
}
//bucketSort es la mejor, para cagarse en todo
std::vector<Veterinaria> bucketSort(const std::vector<Veterinaria>& lista) {
    std::vector<Veterinaria> sortedList = lista;

    // Encontrar el rango mínimo y máximo de los IDs
    std::string minID = sortedList[0].getID();
    std::string maxID = sortedList[0].getID();

    for (const auto& vet : sortedList) {
        if (vet.getID() < minID) {
            minID = vet.getID();
        }
        if (vet.getID() > maxID) {
            maxID = vet.getID();
        }
    }

    // Calcular el número de buckets basado en el rango
    int bucketCount = 36; // Puedes ajustar esto según sea necesario
    std::vector<std::vector<Veterinaria>> buckets(bucketCount);

    // Función para mapear un carácter a un índice de cubeta
    auto charToBucketIndex = [](char c) -> int {
        if (isdigit(c)) return c - '0';     
        return c - 'A' + 10;                
    };

    // Distribuir los elementos en los buckets basados en el primer carácter del ID
    for (const auto& vet : sortedList) {
        char firstChar = vet.getID()[0];
        int bucketIndex = charToBucketIndex(firstChar);
        buckets[bucketIndex].push_back(vet);
    }

    // Reunir los elementos de los buckets en sortedList
    sortedList.clear();
    for (auto& bucket : buckets) {
        if (!bucket.empty()) {
            // Ordenar cada bucket
            std::sort(bucket.begin(), bucket.end(), comparadorAscendente);
            // Agregar el contenido del bucket a la lista ordenada
            sortedList.insert(sortedList.end(), bucket.begin(), bucket.end());
        }
    }

    return sortedList;
}



int main() {
    try {
        Veterinaria m1("Abeja", "ABGD000001");
        Veterinaria m2("Gato", "GTGD000003");
        Veterinaria m3("Abeja", "ABGD000002");
        Veterinaria m4("Gato", "GTGD000010");
        Veterinaria m5("Abeja", "ABGD000005");
        Veterinaria m6("Perro", "PGGD000002");
        Veterinaria m7("Avestruz", "AVJO000001");
        Veterinaria m8("Zorro", "ZOJO000001");
        Veterinaria m9("Zorro", "ZOJO000010");

        std::vector<Veterinaria> lista = {m1, m2, m3, m4, m5, m6, m7, m8, m9};

        std::cout << "Lista original:\n";
        for (const auto& lis : lista)
            lis.print();
        // Aqui se ordenada toda la mierda
        std::vector<Veterinaria> sortedList = bucketSort(lista);

        std::cout << "\nLista ordenada por especie e ID:\n";
        for (const auto& lis : sortedList)
            lis.print();
    } catch (const std::invalid_argument& e) { //Capturar errores
        std::cerr << e.what() << '\n';
    }

    std::cin.get();
    return 0;
}
